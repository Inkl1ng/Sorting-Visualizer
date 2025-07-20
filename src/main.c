#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <raylib.h>

#include "algorithms.h"
#include "elements.h"

#define WINDOW_WIDTH  800
#define WINDOW_HEIGHT 800

#define PADDING 5

#define DEFAULT_NUM_ELEMENTS  10
#define DEFAULT_DELAY_SECONDS 0.25

void draw_elements(int* elements, int num_elements);

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
                        sort( DEFAULT_DELAY_SECONDS, SELECTION, elements);
                }

                BeginDrawing();

                ClearBackground(BLACK);
                
                draw_elements(elements.data, elements.size);

                EndDrawing();
        }

        CloseWindow();

        return 0;
}

void draw_elements(int* elements, int num_elements)
{
        float size = (WINDOW_WIDTH - ( 2 * PADDING)) / (float)num_elements;
        for (int i = 0; i < num_elements; ++i) {
                float height = size * (elements[i] + 1);
                Rectangle rect = {
                        .x = PADDING + (size * i),
                        .y = WINDOW_HEIGHT - PADDING - height,
                        .width = size,
                        .height = height
                };
                DrawRectangleRec(rect, BLUE);
        }
}
