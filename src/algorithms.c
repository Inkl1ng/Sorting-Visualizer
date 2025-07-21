#include "algorithms.h"

#include <stdbool.h>

#include <raylib.h>

static struct {
        int num_sorted;
} selection_state;

void sort(seconds delay, enum algorithm algorithm, struct elements e)
{
        switch (algorithm) {
        case SELECTION:
                step_selection_sort(e);
                break;
        }

        WaitTime(delay);
}

void reset_algorithms()
{
        selection_state.num_sorted = 0;
}

void step_selection_sort(struct elements e)
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
