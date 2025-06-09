# 🔢🔬📊 ArrayMaster Pro: Advanced Array Operations Suite 
_A C++ console application for performing diverse mathematical and statistical operations on arrays, featuring a task-driven menu and colorful UI._

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![C++](https://img.shields.io/badge/Language-C%2B%2B%2011%2B-blue.svg)](https://isocpp.org/)
[![Platform: Windows](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)

## 📋 Table of Contents
1.  [Overview](#-overview)
2.  [Key Features & Tasks](#-key-features--tasks)
3.  [Screenshots](#-screenshots)
4.  [System Requirements](#-system-requirements)
5.  [Installation and Setup](#️-installation-and-setup)
6.  [Usage Guide](#️-usage-guide)
7.  [File Structure](#-file-structure)
8.  [Technical Notes](#-technical-notes)
9.  [Contributing](#-contributing)
10. [License](#-license)
11. [Contact](#-contact)

## 📄 Overview

**ArrayMaster Pro**, created by Adrian Lesniak, is a comprehensive C++ console application designed to execute a variety of mathematical and analytical operations on integer arrays. The program is structured around specific tasks, allowing users to: sum positive elements and average negative ones; find minimum elements and their frequencies; search for occurrences of a random number; calculate standard deviation; and analyze the distribution of 2D points across coordinate quadrants. It features a clear, menu-driven interface with colorful output (enhanced on Windows via the user-provided `utils.h` header) to guide the user through each operation.

![Demo GIF](screenshots/1.gif)

## ✨ Key Features & Tasks

The application is organized into distinct tasks, each performing specific array operations:

*   🎯 **Task 2.1: Positive Sum & Negative Average**
    *   Reads 10 integers into an array `Y`.
    *   `suma_elementow`: Calculates and displays the sum of all elements greater than 0.
    *   `srednia`: Calculates and displays the average of all elements less than 0.
*   📉 **Task 2.2: Minimum Element Analysis**
    *   Reads 10 integers into an array `A`.
    *   `element_minimalny`: Finds the minimum element in the array and counts its occurrences.
*   🔍 **Task 2.3: Random Number Search**
    *   Fills a 15-element array `X` with random numbers (range: 5–30).
    *   `szukaj`: Prompts the user for a number and counts its occurrences within array `X`.
*   📊 **Task 2.4: Standard Deviation Calculation**
    *   `calculate`: Generates an array of 15 random numbers (range: 5–30) and computes its standard deviation.
*   🗺️ **Task 2.5: Coordinate Quadrant Analysis**
    *   Fills two n-element arrays, `XX` (x-coordinates) and `YY` (y-coordinates), with random numbers (range: -10 to 10).
    *   `cwiartki`: Counts how many (x, y) points fall into each of the four coordinate quadrants (I, II, III, IV) and stores these counts in an array `C`.
*   🖥️ **User Interface & Utilities**:
    *   `displayHeader`: Shows a program title, author information, and brief descriptions of each task.
    *   `showMenu`: Presents a clear, numbered list of options (1–5 for tasks, 6 to exit).
    *   **Colorful Output**: Utilizes various colors (blue, yellow, green, red, white) for different UI elements, managed by functions and an `Colors` enum likely defined in `utils.h`.
    *   **Console Management Utilities** (from `utils.h`): Functions like `clearScreen`, `setColor`, and `drawLine` for a structured and visually appealing console experience.

## 🖼️ Screenshots


_Screenshots showcasing the main menu, input prompts for various tasks, and example outputs for each analytical function._

<p align="center">
  <img src="screenshots\1.jpg" width="300"/>
  <img src="screenshots\2.jpg" width="300"/>
  <img src="screenshots\3.jpg" width="300"/>
  <img src="screenshots\4.jpg" width="300"/>
  <img src="screenshots\5.jpg" width="300"/>
  <img src="screenshots\6.jpg" width="300"/>
  <img src="screenshots\7.jpg" width="300"/>
  <img src="screenshots\8.jpg" width="300"/>
  <img src="screenshots\9.jpg" width="300"/>
</p>


## ⚙️ System Requirements

*   **Operating System**: Windows (due to dependencies like `<conio.h>` for `_getch` and assumptions about Windows-specific console functions in `utils.h`).
*   **C++ Compiler**: A C++ compiler supporting C++11 or later (e.g., g++, MSVC).
*   **Standard C++ Libraries**: `<iostream>`, `<vector>` (if used for dynamic arrays, though description implies fixed-size for some tasks), `<cstdlib>`, `<ctime>`, `<cmath>`, `<fstream>` (if file logging/output were to be added).
*   📄 **`utils.h` Header File (User-Provided)**: This project **critically requires** a header file named `utils.h`. **This file is not included in the repository and must be created by the user.** It must define utility functions like `clearScreen`, `setColor`, `drawLine`, and an `Colors` enum (or similar constants) for console management. See "Installation and Setup" for an example.

## 🛠️ Installation and Setup

1.  **Clone the Repository**:
    ```bash
    git clone <repository-url>
    cd <repository-directory>
    ```
    (Replace `<repository-url>` and `<repository-directory>` with your specific details)

2.  **Create `utils.h`**:
    Before compiling, you **must** create `utils.h` in the project directory. This file is essential for console appearance and basic utilities.
    **Example structure for `utils.h`:**
    ```cpp
    #ifndef UTILS_H
    #define UTILS_H

    #include <iostream>
    #include <string>
    #ifdef _WIN32
    #include <windows.h> // For SetConsoleTextAttribute, system("cls")
    #include <conio.h>   // For _getch()
    #endif

    // Example Colors Enum (match names/values to your main.cpp usage)
    enum Colors {
        BLUE = 9,
        YELLOW = 14,
        GREEN = 10,
        RED = 12,
        WHITE = 15, // Or 7 for standard white
        DEFAULT_COLOR = 7
        // Add other colors as needed
    };

    // Function Declarations (implement in utils.cpp or as inline)
    void clearScreen();
    void setColor(Colors color); // Or void setColor(int color);
    void drawLine(char c = '-', int length = 70);
    void waitForKeyPress(const std::string& message = "Press any key to return to the menu...");
    // Potentially:
    // void logMessage(const std::string& message, const std::string& filePath = "app.log");

    #endif // UTILS_H
    ```
    *You must implement these functions (likely in a `utils.cpp` file compiled with `array_operations.cpp`) and ensure the `Colors` enum/constants match those used in your main program.*

3.  **Save Main Code**:
    Ensure your main program code is saved as `array_operations.cpp` in the project directory.

4.  **Compile the Program**:
    Open a terminal (Command Prompt, PowerShell, etc.) in the project directory.
    **Example using g++ (MinGW):**
    ```bash
    g++ array_operations.cpp utils.cpp -o array_operations.exe -std=c++11 -static-libgcc -static-libstdc++
    ```
    *(This assumes you have `utils.cpp` for implementations. If `utils.h` only contains inline functions/macros, you might omit `utils.cpp` from the command).*

5.  **Run the Program**:
    ```bash
    .\array_operations.exe
    ```
    (or `array_operations.exe` in CMD)

## 💡 Usage Guide

1.  Compile and run `array_operations.exe` as detailed above.
2.  **Interface**:
    *   The program will first display a header with task descriptions.
    *   A menu will then appear with options:
        1.  Positive sum, negative average (Task 2.1)
        2.  Minimum element and occurrences (Task 2.2)
        3.  Random number search (Task 2.3)
        4.  Standard deviation (Task 2.4)
        5.  Coordinate quadrant analysis (Task 2.5)
        6.  Exit
3.  **Input**:
    *   Select a menu option (1–6) by typing the number and pressing Enter.
    *   **For Task 2.1 / Task 2.2**: You will be prompted to enter 10 integer values.
    *   **For Task 2.3**: You will be asked to enter a number (between 5 and 30) to search for in the randomly generated array.
    *   **For Task 2.5**: You will need to input the desired size `n` for the coordinate arrays `XX` and `YY`.
    *   The program may prompt for re-entry if invalid input is detected (e.g., non-numeric characters when numbers are expected).
4.  **Output**:
    *   **Task 2.1**: Displays the sum of positive numbers and the average of negative numbers.
    *   **Task 2.2**: Shows the minimum element found and how many times it appeared.
    *   **Task 2.3**: Reports the number of times the searched number was found in the random array.
    *   **Task 2.4**: Outputs the calculated standard deviation of the generated random array.
    *   **Task 2.5**: Lists the generated (x, y) point coordinates and the final counts of points in each of the four quadrants (stored in array `C`).
    *   Results for each task are typically printed directly to the console within `main` or the respective task functions.
5.  **Actions**:
    *   After each task completes and displays its results, press any key to return to the main menu.
    *   Select option `6` to exit the application.

## 🗂️ File Structure

*   `array_operations.cpp`: The main C++ source file containing all task implementations and the main program loop.
*   `utils.h`: (User-provided) Header file for console utility functions (e.g., `clearScreen`, `setColor`, `drawLine`, `Colors` enum).
*   `utils.cpp`: (User-provided, optional if `utils.h` is header-only) Implementation file for utilities defined in `utils.h`.
*   `README.md`: This documentation file.

## 📝 Technical Notes

*   **Windows Specifics**: The project relies on Windows-specific headers like `<conio.h>` for `_getch()` and assumes `utils.h` will use Windows API calls for console color and screen clearing. For cross-platform compatibility, these would need alternatives (e.g., ANSI escape codes for colors, `system("cls")` or `system("clear")` for screen clearing, or a library like ncurses).
*   **Random Number Generation**: Uses `rand()` and `srand(time(NULL))` for generating pseudo-random numbers. For more robust randomness, consider C++11 `<random>` utilities.
*   **Array Sizes**: Some tasks use fixed-size arrays (e.g., 10 or 15 elements). Task 2.5 allows user-defined size `n`.
*   **No File Output for Results**: The current description indicates results are printed to the console. Consider adding functionality to save task outputs to a file for persistence.
*   **Potential Enhancements**: Input validation could be further strengthened. Adding file logging for operations (beyond just errors if `utils.h` supports it) or more sophisticated array operations could extend the program's utility.

## 🤝 Contributing

Contributions to **ArrayMaster Pro** are welcome! If you have ideas to add more array tasks, improve existing algorithms, enhance cross-platform compatibility, or refine the user interface:

1.  Fork the repository.
2.  Create a new branch for your feature (`git checkout -b feature/YourAwesomeFeature`).
3.  Make your changes and commit them (`git commit -m 'Add some AwesomeFeature'`).
4.  Push to the branch (`git push origin feature/YourAwesomeFeature`).
5.  Open a Pull Request.

Please ensure your code is well-commented and adheres to good C++ practices.

## 📃 License

This project is licensed under the **MIT License**.
(If you have a `LICENSE` file in your repository, refer to it: `See the LICENSE file for details.`)

## 📧 Contact

Created by **Adrian Lesniak**.
For questions, feedback, or issues, please open an issue on the GitHub repository or contact the repository owner.

---
🛠️ _Unlocking the power of arrays, one operation at a time!_
