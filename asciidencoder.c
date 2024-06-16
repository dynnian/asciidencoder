/*
 * asciidencoder.c
 *
 * Copyright 2024 Clay Gomera
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * SPDX-License-Identifier: GPL-3.0-only
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <getopt.h>

#define VERSION 0.1
#define NAME "asciidencoder"

void stringToAscii(char* input);
void asciiToCharacter(char *input);
void displayHelp();
void displayVersion();

int main(int argc, char **argv) {
    setlocale(LC_ALL, "");

    int option;
    int s_flag = 0, c_flag = 0;
    char *s_value = NULL, *c_value = NULL;

    static const char* short_options = "s:c:hv";
    static struct option long_options[] = {
        {"string",      required_argument, NULL,    's'},
        {"code",        required_argument, NULL,    'c'},
        {"help",        no_argument,       0,       'h'},
        {"version",     no_argument,       0,       'v'},
        {NULL, 0, NULL, 0}
    };

    while ((option = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
        switch (option) {
            case 's':
                s_flag = 1;
                s_value = optarg;
                break;
            case 'c':
                c_flag = 1;
                c_value = optarg;
                break;
            case 'h':
                displayHelp();
                return 0;
            case 'v':
                displayVersion();
                return 0;
            case '?':
            default:
                fprintf(stderr, "Use '-h, --help' for help.\n");
                return EXIT_FAILURE;
        }
    }

    if (s_flag && c_flag) {
        fprintf(stderr, "Use only one option at a time.\n");
        displayHelp();
        return EXIT_FAILURE;
    }

    // Check if no valid option was provided and display the help message
    if (!s_flag && !c_flag) {
        fprintf(stderr, "No valid options provided.\n");
        displayHelp();
        return EXIT_FAILURE;
    }

    // Check which arguments are present
    if (s_flag) {
        stringToAscii(s_value);
    }
    else if (c_flag) {
        asciiToCharacter(c_value);
    }

    return EXIT_SUCCESS;
}

void stringToAscii(char *input) {
    input[strlen(input)] = '\0';

    for (int i = 0; i < strlen(input); i++) {
        printf("The ASCII code of the character '%c' is %d\n", input[i], (unsigned char)input[i]);
    }
}

// Function to convert an Extended ASCII code to its corresponding character.
void asciiToCharacter(char *input) {
    int charCode = atoi(input);
    if (charCode < 0 || charCode > 255) {
        printf("Invalid ASCII code. Must be between 0 and 255.\n");
    } else {
        printf("The ASCII character for code '%d' is '%c'\n", charCode, (char)charCode);
    }
}

// Function to display the help message
void displayHelp() {
    printf("Usage: %s [OPTIONS] [VALUE]\n", NAME);
    printf("ASCII Decoder & Encoder.\n\n");
    printf("Options:\n");
    printf("\t-s, --string\tGive ASCII codes for each character in the input string.\n");
    printf("\t-c, --code\tGive ASCII character for input code.\n");
    printf("\t-h, --help\tDisplay this help message and exit.\n");
    printf("\t-v, --version\tDisplay version and exit.\n");
}

// Function to display the version information
void displayVersion() {
    printf("%s v%.1f\n", NAME, VERSION);
}

