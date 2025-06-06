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

void print_usage(const char* prog_name) {
    std::cerr << "Usage: " << prog_name << " <num_of_states> <min_k> <max_k>\n"
              << "  num_of_states: integer >= 1\n"
              << "  min_k: integer >= 1\n"
              << "  max_k: integer >= min_k\n\n"
              << "Example:\n"
              << "  " << prog_name << " 5 5 10\n";
}

int main(const int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Error: Incorrect number of arguments.\n";
        print_usage(argv[0]);
        return 1;
    }

    int num_of_states_for_automaton = 0;
    int min_k = 0;
    int max_k = 0;

    try {
        num_of_states_for_automaton = std::stoi(argv[1]);
        min_k = std::stoi(argv[2]);
        max_k = std::stoi(argv[3]);
    } catch (const std::exception& e) {
        std::cerr << "Error: Arguments must be integers.\n";
        print_usage(argv[0]);
        return 1;
    }

    if (num_of_states_for_automaton < 1) {
        std::cerr << "Error: num_of_states must be >= 1.\n";
        return 1;
    }
    if (min_k < 1) {
        std::cerr << "Error: min_k must be >= 1.\n";
        return 1;
    }
    if (max_k < min_k) {
        std::cerr << "Error: max_k must be >= min_k.\n";
        return 1;
    }

    try {
        const auto all_kmers = use_base_impl(num_of_states_for_automaton, min_k, max_k);
        print_all_kmers(all_kmers);
    } catch (const std::exception& e) {
        std::cerr << "Error during k-mer generation: " << e.what() << "\n";
        return 1;
    }

}