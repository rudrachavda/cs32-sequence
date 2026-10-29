// ============================================================================
// CS32 P01 Part 2: the growth-factor experiment
//
// Implement measure_growth below. Then run   make experiment && ./experiment
// to see your results as a table.
// ============================================================================

#include "growth_experiment.h"
#include "Vector.h"

using std::size_t;

// Sets Vector<int>::growth_factor to factor, then push_backs n ints into an
// empty Vector<int>, watching what happens, and returns the GrowthStats (see
// growth_experiment.h for what each field means). Before returning, puts
// growth_factor back to the value it had when measure_growth was called.
//
// Measure by watching a real Vector<int>: push_back the elements one at a time
// and use size() and capacity() to see when the buffer grows and how many
// elements it had to copy. Do not compute the answers from the growth formula
// alone.
GrowthStats measure_growth(double factor, size_t n) {
    double original_factor = Vector<int>::growth_factor;

    Vector<int>::growth_factor = factor;

    GrowthStats stats;
    stats.reallocations=0;
    stats.elements_copied=0;
    stats.final_capacity=0;

    Vector<int> v;

    for (size_t i=0; i<n; ++i) {
        size_t old_capacity = v.capacity();
        size_t old_size = v.size();

        v.push_back(0);

        if (v.capacity() != old_capacity) {
            stats.reallocations++;
            stats.elements_copied += old_size;
        }
    }

    stats.final_capacity = v.capacity();

    Vector<int>::growth_factor = original_factor;

    return stats;
}
