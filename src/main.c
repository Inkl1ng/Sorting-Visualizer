#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include <raylib.h>

#include "algorithms.h"
#include "elements.h"
#include "ui.h"

#define DEFAULT_NUM_ELEMENTS  10
#define DEFAULT_DELAY_SECONDS 0.75

bool sorting = false;

int main(int argc, char** argv)
{
        srand(time(NULL));

        // initial reset
        reset_algorithms();

        struct elements elements;

        if (argc == 1) {
                elements.size = DEFAULT_NUM_ELEMENTS;
        }
        else {
                elements.size = atoi(argv[1]);
        }

        elements.data = malloc(sizeof(int) * elements.size);
        reset_elements(elements);

        InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Sorting Visualizer");
    
        while (!WindowShouldClose()) {
                if (IsKeyPressed(KEY_S) && !sorting) {
                        shuffle_elements(elements);
                }
                if (IsKeyPressed(KEY_R) && !sorting) {
                        reset_elements(elements);
                }
                if (IsKeyPressed(KEY_A)) {
                        sorting = !sorting;
                }

                if (is_sorted(elements)) {
                        sorting = false;
                        reset_algorithms();
                }

                if (sorting) {
                        sort(DEFAULT_DELAY_SECONDS, SELECTION, elements);
                }

                draw_ui(elements, sorting);
        }

        CloseWindow();

        return 0;
}
