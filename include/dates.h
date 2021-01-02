//
// Created by kostas on 26/12/20.
//

#ifndef CPP_COOKBOOK_DATES_H
#define CPP_COOKBOOK_DATES_H
#include <ctime>
#include <ostream>
#include <locale>
#include <cstring>
/**
 *
 * @param day of month
 * @param month of year [1..12]
 * @param year after 1900
 * @return a time object, NULL on error;
 */
std::time_t dateToTime(int day, int month, int year){
    if (year < 1900){
        return NULL;
    }
    std::tm tmp = tm();
    tmp.tm_mday =  day;
    tmp.tm_mon = month-1;
    tmp.tm_year = year - 1900;
    return std::mktime(&tmp);
}

std::ostream& formatDateTime(std::ostream& out, const std::tm& t, const char* fmt){
    // get locale
    const auto& dateWriter = std::use_facet<std::time_put<char>>(out.getloc());
    int n =std::strlen(fmt);
    if (dateWriter.put(out, out, ' ', &t, fmt, fmt+n).failed()){
        throw std::runtime_error("Failure to format date and time");
    }
    return out;
}



#endif //CPP_COOKBOOK_DATES_H
