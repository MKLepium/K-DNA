#include "base_impl.h"
#include "definitions.h"


void print_all_kmers(const ALL_KMERS &all_kmers) {
    for (size_t k = 0; k < all_kmers.size(); ++k) {

        std::cout << "k = " << k << ":\n";
        for (const std::string& kmer : all_kmers[k]) {
            std::cout << kmer << "\n";
        }
        std::cout << std::endl;
    }
}


int main() {
    constexpr int num_of_states_for_automaton = 5;
    constexpr int min_k = 5;
    constexpr int max_k = 10;


    const auto all_kmers = use_base_impl(num_of_states_for_automaton, min_k, max_k);
    print_all_kmers(all_kmers);

    return 0;
}