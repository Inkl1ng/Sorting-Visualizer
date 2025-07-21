#include "ui.h"

#include <raylib.h>

#define HEADER_HEIGHT 100

// defines area on the window given to the sorting stuff

#define SORTING_WINDOW_WIDTH  WINDOW_WIDTH
#define SORTING_WINDOW_HEIGHT WINDOW_HEIGHT - HEADER_HEIGHT

Camera2D sorting_camera = {
        .offset   = { .x = 0.f, .y = HEADER_HEIGHT },
        .target   = { .x = 0.f, .y = 0.f },
        .rotation = 0.f,
        .zoom     = 1.f
};

static void draw_elements(struct elements e)
{
        float size = (SORTING_WINDOW_WIDTH - ( 2 * PADDING)) / (float)e.size;
        for (int i = 0; i < e.size; ++i) {
                float height = size * (e.data[i] + 1);
                Rectangle rect = {
                        .x      = PADDING + (size * i),
                        .y      = SORTING_WINDOW_HEIGHT - PADDING - height,
                        .width  = size,
                        .height = height
                };
                DrawRectangleRec(rect, BLUE);
        }
}

static void draw_sorting_indicator(bool sorting)
{
        Rectangle rect = {
                .x      = 0.f,
                .y      = 0.f,
                .width  = SORTING_WINDOW_WIDTH,
                .height = SORTING_WINDOW_HEIGHT
        };
        
        if (sorting) {
                DrawRectangleLinesEx(rect, PADDING, GREEN);
        }
        else {
                DrawRectangleLinesEx(rect, PADDING, RED);
        }
}

void draw_ui(struct elements e, bool sorting)
{
        BeginDrawing();

                ClearBackground(BLACK);

                BeginMode2D(sorting_camera);

                        draw_elements(e);
                        draw_sorting_indicator(sorting);

                EndMode2D();

        EndDrawing();
}
