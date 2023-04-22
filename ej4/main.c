/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "weather_utils.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load climate data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>\n\n"
           "Those elements must be integers and will be copied into the multidimensional integer array 'a'.\n"
           "The dimensions of the array are given by the macro tclimate.\n"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return An string containing read filepath
 */
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

static void dump_max(int a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%i, ", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

static void dump_rain(unsigned int a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%u, ", a[j]+1);
    }
    printf("\"");
    printf("\n\n");
}
/**
 * @brief Main program function
 *
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 *
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */
int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array with the type of tclimate */
    WeatherTable array;

    /*create a variable to save the min_temp*/
    int min_temp_h;

    /*create an array to save the max_temp*/
    int maxtemp[YEARS];

    /*create an array to save the months by year with max rain*/    
    unsigned int rainmonths[YEARS];

    /* parse the file to fill the array and obtain the actual length */
    array_from_file(array, filepath);

    /*gets the min_temp*/
    min_temp_h = min_temp(array, YEARS, 12, DAYS);

    /*gets the maxtemp by year*/
    max_temp_by_year(array, maxtemp, YEARS, 12, DAYS);

    /*gets the most rainy month by year*/
    max_rainfall_month_by_year(array, rainmonths, YEARS, 12, DAYS);

    /* show the results in the screen */
    printf("The minimum historical temperature is %i\n", min_temp_h);
    printf("The maximum temperatures by year:\n");
    dump_max(maxtemp, YEARS);
    printf("The month with the maximum amounth of rains by year:\n");
    dump_rain(rainmonths, YEARS);

    return (EXIT_SUCCESS);
}
