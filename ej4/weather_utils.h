#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include "array_helpers.h"


int min_temp (WeatherTable array, int max_years, int max_months, int max_days);
/*
    gets the historical minimum temp
*/

void max_temp_by_year(WeatherTable array, int output[], int max_years, int max_months, int max_days);
/*
    gets the max temp by year and returns it in the output[YEARS] array
*/

void max_rainfall_month_by_year(WeatherTable array, unsigned int output[], int max_years, int max_months, int max_days);
/*
    gets the mont with max rain by year and returns it in the output[YEARS] array
*/
#endif