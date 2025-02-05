#include <iostream>

void printCenteredTriangle(int baseWidth) {
    int maxWidth = baseWidth * 2 - 1; // Full width needed for centering

    for (int i = 1; i <= baseWidth; i++) {
        int numCount = i; // Number of numbers in the row
        int spaceCount = (maxWidth - (numCount * 2 - 1)) / 2; // Center alignment spaces

        // Print leading spaces for centering
        for (int j = 0; j < spaceCount; j++) {
            std::cout << " ";
        }

        // Print numbers
        for (int j = 1; j <= numCount; j++) {
            std::cout << j<< " ";
        }

        std::cout << std::endl;
    }
}

int main() {
    int baseWidth;
    std::cout << "Enter the base width of the triangle: ";
    std::cin >> baseWidth;

    printCenteredTriangle(baseWidth);

    return 0;
}
