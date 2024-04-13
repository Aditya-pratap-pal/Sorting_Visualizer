#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

// Function to swap two elements in the array
void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Bubble sort algorithm with visualization
void bubbleSort(sf::RenderWindow& window, vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(arr, i - 1, i);
                swapped = true;

                // Redraw the bars
                window.clear();
                for (int j = 0; j < n; j++) {
                    sf::RectangleShape bar(sf::Vector2f(5, arr[j]));
                    bar.setPosition(j * 5, 600 - arr[j]);
                    window.draw(bar);
                }
                window.display();
                std::this_thread::sleep_for(std::chrono::milliseconds(5));
            }
        }
    } while (swapped);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sorting Visualizer");
    window.setFramerateLimit(60);

    // Initialize random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(50, 550);

    vector<int> arr;
    for (int i = 0; i < 160; i++) {
        arr.push_back(distribution(gen));
    }

    // Perform sorting
    bubbleSort(window, arr);

    // Keep the window open until it is closed
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}
