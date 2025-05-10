# Mathematical Array Operations Program

## Overview
This C++ console application, created by Adrian Lesniak, performs mathematical operations on arrays as per specified tasks. It includes summing positive elements, averaging negative ones, finding minimums, searching random numbers, calculating standard deviation, and analyzing point distribution in coordinate quadrants. The program features a menu-driven interface, Windows-specific colored output, and utilities from `utils.h`.

## Features
- **Task 2.1**:
  - Reads 10 integers into array `Y`.
  - `suma_elementow`: Sums elements > 0.
  - `srednia`: Averages elements < 0.
- **Task 2.2**:
  - Reads 10 integers into array `A`.
  - `element_minimalny`: Finds minimum element and its occurrences.
- **Task 2.3**:
  - Fills 15-element array `X` with random numbers (5–30).
  - `szukaj`: Counts occurrences of a user-specified number.
- **Task 2.4**:
  - `calculate`: Computes standard deviation for 15 random numbers (5–30).
- **Task 2.5**:
  - Fills two n-element arrays `XX`, `YY` with random numbers (-10 to 10).
  - `cwiartki`: Counts points in each coordinate quadrant, stores in array `C`.
- **Interface**:
  - `displayHeader`: Shows program title, author, and task descriptions.
  - `showMenu`: Lists options (1–5 for tasks, 6 to exit).
  - Colored output (blue, yellow, green, red, white) via `utils.h` functions.
- **Utilities** (from `utils.h`):
  - `clearScreen`, `setColor`, `drawLine`, `Colors` enum for console management.
- **Main Program**:
  - Loops until exit (6), handles user input, and displays results in `main`.

## Requirements
- C++ compiler (e.g., g++, MSVC) with C++11 or later
- Windows OS (for `<conio.h>`, `_getch`, assumed `utils.h` Windows console functions)
- Standard C++ libraries: `<iostream>`, `<cstdlib>`, `<ctime>`, `<cmath>`, `<fstream>`
- Header: `utils.h` (defines `clearScreen`, `setColor`, `drawLine`, `Colors`)
- Operating system: Windows (due to console functions)

## Setup
1. Clone the repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```
2. Ensure `utils.h` is in the project directory with required definitions (e.g., `clearScreen`, `setColor`, `Colors`).
3. Save the provided code as `array_operations.cpp`.
4. Compile the program:
   ```bash
   g++ array_operations.cpp -o array_operations
   ```
5. Run the program:
   ```bash
   .\array_operations
   ```

## Usage
1. Compile and run the program using the steps above.
2. **Interface**:
   - Displays header with task descriptions and menu:
     1. Positive sum, negative average
     2. Minimum element and occurrences
     3. Random number search
     4. Standard deviation
     5. Coordinate quadrant analysis
     6. Exit
3. **Input**:
   - Select 1–6 via keyboard.
   - For Task 2.1/2.2: Enter 10 integers.
   - For Task 2.3: Enter a number to search.
   - For Task 2.5: Enter array size `n`.
   - Invalid inputs may require re-entry.
4. **Output**:
   - Task 2.1: Sum of positive numbers, average of negative numbers.
   - Task 2.2: Minimum element and its count.
   - Task 2.3: Number of occurrences of the searched number.
   - Task 2.4: Standard deviation of random array.
   - Task 2.5: Point coordinates (`XX`, `YY`) and quadrant counts in array `C`.
   - Results printed in `main`, arrays in respective functions.
5. **Actions**:
   - Press any key to return to menu after each task.
   - Select 6 to exit.

## File Structure
- `array_operations.cpp`: Main program file with all task implementations.
- `utils.h`: Header for utility functions (e.g., `clearScreen`, `setColor`, assumed).
- `README.md`: This file, providing project documentation.

## Notes
- Windows-specific due to `<conio.h>` and `_getch`; adapt for cross-platform (e.g., ANSI colors, `system("clear")`).
- Requires `utils.h` with functions like `clearScreen`, `setColor`, `Colors` enum.
- Random numbers generated with `rand()`, seeded by `srand(time(NULL))`.
- No file output implemented; consider adding for results persistence.
- Extend by adding input validation, file logging, or more array operations.
- No external dependencies beyond standard C++ libraries.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make changes and commit (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-branch`).
5. Open a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact
For questions or feedback, open an issue on GitHub or contact the repository owner.