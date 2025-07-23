#ifndef SRC_ALGORITHMS_H
#define SRC_ALGORITHMS_H

#include <stdbool.h>

#include "elements.h"
#include "statistics.h"

enum algorithm {
        SELECTION,
        INSERTION
};

void sort(seconds delay, struct elements e);
void step(struct elements e);

void reset_algorithms(); // should be called before any sorting
void select_algorithm(enum algorithm selection);

#endif
