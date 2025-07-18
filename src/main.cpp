#include <algorithm>
#include <array>
#include <iostream>
#include <random>

#include <raylib.h>

constexpr int window_width { 800 };
constexpr int window_height { 800 };

constexpr int num_elements { 10 };
constexpr int padding { 5 };
constexpr float element_width { (window_width - (2 * padding)) / (static_cast<float>(num_elements)) };

void print_elements(const std::array<int, num_elements>& elements);
void draw_elements(const std::array<int, num_elements>& elements);
void shuffle_elements(std::array<int, num_elements>& elements);

void sort_step(std::array<int, num_elements>& elements);

size_t biggest_index {};
size_t elements_sorted { 0 };

int main()
{
    std::array<int, num_elements> elements {};
    for (size_t i { 0 }; i < elements.size(); ++i) {
        elements[i] = i;
    }

    print_elements(elements);
    InitWindow(window_width, window_height, "Sorting Visualizer");

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_S)) {
            std::mt19937 mt { std::random_device{}() };
            std::shuffle(elements.begin(), elements.end(), mt);
        }
        if (IsKeyPressed(KEY_A)) {
            sort_step(elements);
        }

        BeginDrawing();

        ClearBackground(BLACK);

        draw_elements(elements);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void print_elements(const std::array<int, num_elements>& elements)
{
    for (auto i : elements) {
        std::cout << i << ' ';
    }

    std::cout << '\n';
}

void draw_elements(const std::array<int, num_elements>& elements)
{
    for (size_t i { 0 }; i < elements.size(); ++i) {
        Rectangle rect {};
        rect.width = element_width;
        rect.height = element_width * (elements[i] + 1);
        rect.x = padding + (element_width * i);
        rect.y = window_height - padding - rect.height;
        DrawRectangleRec(rect, BLUE);
    }

}

void shuffle_elements(std::array<int, num_elements>& elements)
{
    std::mt19937 mt { std::random_device{}() };
    std::shuffle(elements.begin(), elements.end(), mt);
}

void sort_step(std::array<int, num_elements>& elements)
{
    int biggest { -1 };
    for (size_t i { 0 }; i < elements.size() - elements_sorted; ++i) {
        if (elements[i] > biggest) {
            biggest = elements[i];
            biggest_index = i;
        }
    }

    size_t swap_index { elements.size() - 1 - elements_sorted };
    elements[biggest_index] = elements[swap_index];
    elements[swap_index] = biggest;

    ++elements_sorted;
}
