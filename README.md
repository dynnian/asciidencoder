# asciidencoder

## Table of Contents

- [Introduction](#introduction)
- [Building](#building)
- [Usage](#usage)
- [Options](#options)
- [Examples](#examples)
- [Notes](#notes)

## Introduction

**ascii-dencoder** is a command-line utility designed to convert strings into their corresponding ASCII codes and vice versa: from ASCII codes to characters. This tool is particularly useful for developers, students, and hobbyists involved in fields requiring ASCII manipulation or understanding.

## Building

This tool is provided as source code and can be built using `make`. By just
typing make in the terminal within the code's directory:

```bash
make
```

You should now have an executable named `ascii-dencoder`. Optionally, you can
copy it to a location in your PATH for easier access.

## Usage

To use `ascii-dencoder`, run the executable from the command line with the
appropriate options.

```bash
./ascii-dencoder [OPTIONS] <value>
```

## Options

**ascii-dencoder** accepts the following options:

- `-s`, `--string <value>`:
  - Convert the input string to its ASCII codes.

- `-c`, `--code <value>`:
  - Convert the input ASCII code to its corresponding character.

- `-h`, `--help`:
  - Display the help message and exit.

- `-v`, `--version`:
  - Display the program version and exit.

## Examples

1. Convert a string to ASCII codes:

    ```bash
    ./ascii-dencoder -s "hello"
    ```

    Output:
    
    ```
    The ASCII code of the character 'h' is 104
    The ASCII code of the character 'e' is 101
    The ASCII code of the character 'l' is 108
    The ASCII code of the character 'l' is 108
    The ASCII code of the character 'o' is 111
    ```

2. Convert an ASCII code to a character:

    ```bash
    ./ascii-dencoder -c 104
    ```
    
    Output:
    ```
    The ASCII character for code '104' is 'h'
    ```

3. Display help message:

    ```bash
    ./ascii-dencoder -h
    ```

This will display detailed usage instructions and available options.

4. Display version:

    ```bash
    ./ascii-dencoder -v
    ```

This will show the current version of the program.

## Notes

- The ASCII code conversion accepts numbers between 0 and 255.
- Ensure proper usage of command-line arguments to avoid unexpected behavior.
- This tool is straightforward and does not handle complex text encoding
  scenarios beyond basic ASCII.
