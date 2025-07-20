#ifndef SRC_ALGORITHMS_H
#define SRC_ALGORITHMS_H

#include <stdbool.h>

#include "elements.h"

enum algorithm {
        SELECTION
};

typedef float seconds;

void sort(seconds delay, enum algorithm algorithm, struct elements e);

void reset_algorithms(); // should be called before any sorting

void step_selection_sort(struct elements e);

#endif
