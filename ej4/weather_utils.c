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
    for (int years = 0; years < max_years; ++years){
        for (int months = 0; months < max_months; ++months){
            for (int days = 0; days < max_days; ++days){
                res = min(res, array[years][months][days]._min_temp);
            }
        }
    }

    return res;
}

void max_temp_by_year(WeatherTable array, int output[], int max_years, int max_months, int max_days){
    int max_temp = INT_MIN;
    
    for (int years = 0; years < max_years; ++years){
        max_temp = INT_MIN;

        for (int months = 0; months < max_months; ++months){
            for (int days = 0; days < max_days; ++days){
                max_temp = max(max_temp, array[years][months][days]._max_temp);
            }
        }
        output[years] = max_temp;
    }

}

void max_rainfall_month_by_year(WeatherTable array, unsigned int output[], int max_years, int max_months, int max_days){
    month_t max_month;
    unsigned int monthly_rain = 0u;
    unsigned int max_rain = 0u;

    for (int years = 0; years < max_years; ++years){
        max_rain = 0u ;                                                      //cada vez que cambiamos de año, la max precipitacion es 0

        for (int months = 0; months < max_months; ++months){      
            monthly_rain = 0;                                               //idem pero con la precipitacion mensual
            
            for (int days = 0; days < max_days; ++days){
                monthly_rain = monthly_rain + array[years][months][days]._rainfall;     //suma las precipitaciones de ese mes
            }

            if (monthly_rain > max_rain){                                   //si la precipitacion mensual es mayor al maximo anual hasta el momento, guardamos ese mes en max_month
                max_month = months;
            }
        }
        output[years] = max_month;                                      //guardamos los valores en el output
    }
}