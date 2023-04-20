#include "weather_utils.h"
#include "array_helpers.h"
#include "weather.h"
#include <limits.h>

int min(int x, int y){
    int r;

    if (x > y){
        r = y;
    }
    else{
        r = x;
    }

    return r;
}

int max (int x, int y){
    int r;
    if(x > y){
        r = x;
    }
    else{
        r = y;
    }
    return r;
}

int min_temp ( WeatherTable array, int max_years, int max_months, int max_days){
    int res = INT_MAX;
    for (unsigned int years = 0u; years < max_years; ++years){
        for (unsigned int months = 0u; months < max_months; ++months){
            for (unsigned int days = 0u; days < max_days; ++days){
                res = min(res, array[years][months][days]._min_temp);
            }
        }
    }

    return res;
}

void max_temp_by_year(WeatherTable array, int output[], int max_years, int max_months, int max_days){
    int max_temp = INT_MIN;

    for (unsigned int years = 0u; years < max_years; ++years){
        for (unsigned int months = 0u; months < max_months; ++months){
            for (unsigned int days = 0u; days < max_days; ++days){
                max_temp = max(max_temp, array[years][months][days]._max_temp);        
            }
        }
        output[years] = max_temp;
    }

}

void max_rainfall_month_by_year(WeatherTable array, int output[], int max_years, int max_months, int max_days){

}