#pragma once
// I am well aware that this is bad practice, having implementations in a header file

#include "definitions.h"
#include <string>

#include <mata/nfa/nfa.hh>
#include <mata/nfa/builder.hh>

#include <set>
#include <queue>


using Symbol = char; // Use char for DNA nucleotides {A, C, G, T}

struct Path {
    mata::nfa::State state;
    std::string word;
};


inline ALL_KMERS generate_kmers(const mata::nfa::Nfa& automaton, const int min_k, const int max_k) {
    ALL_KMERS all_kmers;
    for (int k = min_k; k <= max_k; ++k) {
        std::set<std::string> kmers;
        std::queue<Path> q;

        for (mata::nfa::State init : automaton.initial) {
            q.push({init, ""});
        }

        while (!q.empty()) {
            Path current = q.front();
            q.pop();

            if (current.word.length() == k) {
                if (automaton.final.contains(current.state)) {
                    kmers.insert(current.word);
                }
                continue;
            }

            // All transitions from the current state
            for (const auto& trans : automaton.delta[current.state]) {
                const mata::Symbol symbol = trans.symbol; // Access the symbol (label)
                for (const mata::nfa::State target : trans.targets) { // Iterate over target states
                    const std::string next_word = current.word + static_cast<char>(symbol);
                    q.push({target, next_word});
                }
            }
        }
        all_kmers.push_back(kmers);
    }
    return all_kmers;
}


inline mata::nfa::Nfa build_simple_nfa(const int num_of_states) {
    if (num_of_states < 1) {
        throw std::invalid_argument("Number of states must be at least 1");
    }

    mata::nfa::Nfa aut(num_of_states);

    aut.initial = {0};           // Start at state 0
    aut.final = {static_cast<unsigned long>(num_of_states - 1)}; // Only last state is final

    constexpr char nucleotides[] = {'A', 'T', 'G', 'C'};

    // For each state except the last, add transitions on all nucleotides to next state
    for (int i = 0; i < num_of_states - 1; ++i) {
        for (char n : nucleotides) {
            aut.delta.add(i, n, i + 1);
        }
    }

    // Add self-loops on the last state for all nucleotides
    for (const char n : nucleotides) {
        aut.delta.add(num_of_states - 1, n, num_of_states - 1);
    }

    return aut;
}


inline ALL_KMERS use_base_impl(const int num_of_states, const int min_k, const int max_k) {

    const auto nfa = build_simple_nfa(num_of_states);

    return generate_kmers(nfa, min_k, max_k);
}