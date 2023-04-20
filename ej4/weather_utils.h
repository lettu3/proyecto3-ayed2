#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include "array_helpers.h"
#include "weather.h"

int min (int x, int y);

int min_temp (WeatherTable array, int max_years, int max_months, int max_days);

void max_temp_by_year(WeatherTable array, int output[], int max_years, int max_months, int max_days);

void max_rainfall_month_by_year(WeatherTable array, int output[], int max_years, int max_months, int max_days);

#endif