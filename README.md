# Sort Analysis

[![MIT license](https://img.shields.io/badge/License-MIT-blue.svg?style=for-the-badge)](LICENSE)
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

[![Open Source Love svg1](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badges/)
[![Run Super-Linter](https://github.com/JakubKorytko/sort-analysis/actions/workflows/super-linter.yml/badge.svg)](https://github.com/JakubKorytko/sort-analysis/actions/workflows/super-linter.yml)
[![Run make targets to check for errors](https://github.com/JakubKorytko/sort-analysis/actions/workflows/make.yml/badge.svg)](https://github.com/JakubKorytko/sort-analysis/actions/workflows/make.yml)

## Table of Contents

- [Sort Analysis](#sort-analysis)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
  - [Data file](#data-file)
  - [Text coloring](#text-coloring)
  - [Usage](#usage)
    - [Menu](#menu)
    - [Available algorithms](#available-algorithms)
      - [Group 1](#group-1)
      - [Group 2](#group-2)
  - [Tools](#tools)
    - [Generate](#generate)
    - [Results](#results)
  - [Contributing](#contributing)
  - [Contact](#contact)
  - [License](#license)

## Introduction

Sort Analysis is a C-based project that analyzes the performance of various sorting algorithms.
This repository contains implementations of classic sorting algorithms
and tools to generate data and analyze their efficiency.
The project focuses on providing insights into the runtime behavior of sorting algorithms
for different input sizes.

The whole project was done according to the [instructions](docs/Instructions.pdf).

In addition, a [report](docs/Report.pdf) consisting of sorting time comparisons,
a summary with pros and cons, block diagrams, etc. was created.

You can find both the report and the instructions in the [docs](./docs/) folder of the repository.

**Note:** If you want to edit the project files, make sure to set the include paths in your IDE to the [headers](./headers/) directory or change the `#include` directives in the source files accordingly. The project will compile without them, but the IDE will show include errors.

The headers directory structure mirrors the source directory structure.

## Prerequisites

Before you begin, make sure you have the following prerequisites installed on your system:

- [GNU Make 4.4.1 or later](https://www.gnu.org/software/make/)
- [GNU GCC 11.4 or later](https://gcc.gnu.org)

## Installation

1. Clone this repository to your local machine using Git,
or download the ZIP file and extract it to a directory of your choice:

    ```bash
    git clone https://github.com/JakubKorytko/sort-analysis.git
    ```

1. Change to the project directory:

    ```bash
    cd sort-analysis
    ```

1. Compile the program and generate or provide the [data file](#data-file):

    - If you want to generate [data file](#data-file) using the program:

        - Compile the program & [the tools](#tools) with:

            ```bash
            make
            ```

        - Generate the data file (to check what parameters you can pass, see the [section below](#generate)):

            ```bash
            tools/out/generate
            ```

            You may need to enclose the command in quotes:

            ```bash
            "tools/out/generate"
            ```

    - If you want to provide your own [data file](#data-file):

        - Compile only the program (you won't be able to use [the tools](#tools)):

            ```bash
            make sort
            ```

        - Remember to provide the data file. See the [section below](#data-file) for details on what it should contain,.

    The compiled executable named `sort`
    will be placed in the root directory of the project.

## Data file

The application expects a data file named `data` (without extension) in the root directory of the project. The results tool doesn't require a data file to have a specific name, but you must provide it as a command-line argument (see the [section below](#results)).

The file should contain a list of integers separated by a single space or a newline character.
For example:

```text
-11 23 3 0 -45 6 9 10 234 9
```

You can generate a data file using the [generate tool](#generate) or provide your own.

## Text coloring

The program uses ANSI escape codes to color the output text. If your terminal doesn't support them, you can disable the coloring by setting the `ENABLE_COLORING` environment variable to `false` before running the program:

Unix-like systems:

```bash
export ENABLE_COLORING=false
```

Windows:

```bash
set ENABLE_COLORING=false
```

If you want this setting to be permanent, add the environment variable to your shell's configuration file or change the `ENABLE_COLORING` variable in the [Makefile](Makefile).

You can also change the `is_coloring_enabled` function in the [print.c](src/utils/print.c) file to always return `false`.

## Usage

After running the program, you will be asked to enter the number of elements to sort.
If the data file has been provided, the program will read the data from it.
Otherwise, it will throw an error and exit.
If you specify a number that is greater than the number of elements in the data file,
unexpected behavior may occur.
Most likely, the array will be filled with zeros,
but this is not guaranteed. Avoid doing this.

The array will be displayed for you to check if the data has been read correctly. After pressing `ENTER`, the menu will be displayed.

### Menu

The application has a interactive menu, that takes input (number) from the user and performs the action associated with the number. The menu has the following options:

- 3 options (1-3) to sort the array using the algorithms of the [first group](#group-1)
- 3 options (4-6) to sort the array using the algorithms of the [second group](#group-2)
- Option 7 to display the array
- Option 8 to execute all algorithms one by one
- Option 9 to restart the program and specify a new number of elements to sort
- Option 0 to exit the program

Options 1-6 and 8 will always sort the array, display the sorted array and the time it took to sort it in milliseconds.

### Available algorithms

#### Group 1

- [Insertion sort](./src/algorithms/insertion_sort.c)
- [Selection sort](./src/algorithms/selection_sort.c)
- [Bubble sort](./src/algorithms/bubble_sort.c)

#### Group 2

- [Quicksort](./src/algorithms/quick_sort.c)
- [Shellsort](./src/algorithms/shell_sort.c)
- [Heapsort](./src/algorithms/heap_sort.c)

## Tools

### Generate

To generate a [data file](#data-file) you can use the `generate` tool. It is a standalone program that doesn't require compiling the main program. To use it, follow these steps (you should be in the root directory of the project for each step):

1. Run the following command (if you have run `make` before, you can skip this step):

    ```bash
    make generate
    ```

    This will compile the `generate` tool and place the executable in the `tools/out` directory.

1. The syntax of the command is:

    ```bash
    tools/out/generate <number_of_elements> <filename>
    ```

    where:

    - `<number_of_elements>` - specifies how many numbers do you want to generate, *(default: 100000)*
    - `<filename>` - [data file](#data-file) name, *(default: data)*

    You can also run the tool without any arguments. In this case, the default values will be used. The `<` and `>` characters are not part of the command and are used as placeholders. You should replace them with the actual values. Remember to use the default filename if you want to use the [data file](#data-file) with the main program (leave it empty or use `data`).

### Results

To save the results of the running time of the algorithms in `.txt` files, you can use the `results` tool. It is a standalone program that doesn't require the main program to be compiled. To use it, follow these steps (you should be in the root directory of the project for each step):

1. Run the following command (if you have run `make` before, you can skip this step):

    ```bash
    make results
    ```

    This will compile the `results` tool and place the executable in the `tools/out` directory.

1. The syntax of the command is:

    ```bash
    tools/out/results <number_of_calls> <data_filename> <algorithms_indices_from_the_array>
    ```

    where:

    - `<number_of_calls>` - specifies the number of calls to the sorting algorithms, where each subsequent call performs a sort on the number of elements specified by the sequence:
        `1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000...`, *(default: 5)*

        For example:

        `tools/out/results 1 <...>` - sorts 1000 numbers  
        `tools/out/results 2 <...>` - sorts 1000 numbers and 2000 numbers

        When using the command for **N** calls, the time of each algorithm call will be saved to the result files, separately for each of the 3 tests.

    - `<data_filename>` - generated (or provided) [data file](#data-file) name, *(default: data)*
    - `<algorithms_indices_from_the_array>` (separated by whitespace, between 0 and 5):
        - `0` – Insertion sort
        - `1` – Selection sort
        - `2` – Bubble sort
        - `3` - Quicksort
        - `4` - Shellsort
        - `5` - Heapsort  
        *(default: 0 1 2 3 4 5)*

        For example:

        `tools/out/results <...> 1 2` - runs Selection sort & Bubble sort

    After running the command from the project root directory, the results should appear in the `results/` subdirectory.

## Contributing

If you find issues or have suggestions for improvements,
feel free to open an issue or submit a pull request.
Contributions are welcome!

## Contact

If you have any questions, feel free to contact me at <jakub@korytko.me>.

## License

This project is released under the MIT License.
See the [LICENSE](LICENSE) file for details.
