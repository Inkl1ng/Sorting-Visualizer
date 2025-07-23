#include "algorithms.h"

#include <stdbool.h>

#include <raylib.h>

static enum algorithm selected_algorithm;

static struct {
        int num_sorted;
} selection_state;

static void step_selection_sort(struct elements e)
{
        int smallest_value = e.data[selection_state.num_sorted];
        int smallest_index = selection_state.num_sorted;
        for (int i = selection_state.num_sorted; i < e.size; ++i) {
                if (e.data[i] < smallest_value) {
                        smallest_value = e.data[i];
                        smallest_index = i;
                }
        }

        int temp = e.data[selection_state.num_sorted];
        e.data[selection_state.num_sorted] = e.data[smallest_index];
        e.data[smallest_index] = temp;

        ++selection_state.num_sorted;
}

static struct {
        int farthest_sorted;
} insertion_state;

static void step_insertion_sort(struct elements e)
{
        int target_index = insertion_state.farthest_sorted + 1;
        int swap_index   = target_index - 1;

        while (e.data[target_index] < e.data[swap_index]) {
                int temp = e.data[swap_index];
                e.data[swap_index] = e.data[target_index];
                e.data[target_index] = temp;
                        
                --target_index;
                --swap_index;
        }

        ++insertion_state.farthest_sorted;
}

void sort(seconds delay, struct elements e)
{
        step(e);
        WaitTime(delay);
}

void step(struct elements e)
{
        switch (selected_algorithm) {
        case SELECTION: step_selection_sort(e); break;
        case INSERTION: step_insertion_sort(e); break;
        }
}

void reset_algorithms()
{
        selection_state.num_sorted = 0;

        insertion_state.farthest_sorted = 0;
}

void select_algorithm(enum algorithm selection)
{
        selected_algorithm = selection;
}
