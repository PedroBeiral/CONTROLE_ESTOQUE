#ifndef DATE_HPP
#define DATE_HPP

#include <string>
#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

public:
    Date(int day, int month, int year);
    Date(const std::string& dateStr); // "DD/MM/YYYY"

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    std::string toString() const;
    bool isValid() const;
    bool isBefore(const Date& other) const;

    static Date today();
};

#endif // DATE_HPP
