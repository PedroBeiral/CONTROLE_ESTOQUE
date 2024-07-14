#include "Date.hpp"
#include <sstream>
#include <ctime>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

Date::Date(const std::string& dateStr) {
    std::stringstream ss(dateStr);
    char delimiter;
    ss >> day >> delimiter >> month >> delimiter >> year;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

std::string Date::toString() const {
    std::stringstream ss;
    ss << (day < 10 ? "0" : "") << day << '/'
       << (month < 10 ? "0" : "") << month << '/'
       << year;
    return ss.str();
}

bool Date::isValid() const {
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    if (month == 2) {
        bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        return day <= (leap ? 29 : 28);
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }
    return true;
}

bool Date::isBefore(const Date& other) const {
    if (year < other.year) return true;
    if (year > other.year) return false;
    if (month < other.month) return true;
    if (month > other.month) return false;
    return day < other.day;
}

Date Date::today() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    return Date(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
}
