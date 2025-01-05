#include "euler.hpp"

using namespace std;
using namespace euler;

int days_since_1900(int year) {
    int total_days = 0;

    for (int i=1900; i < year; i++) {
        int days_per_year = 365;
        if (i%4==0) {
            if (i%100==0) {
                if (i%400==0) {
                    days_per_year=366;
                } else {
                    days_per_year=365;
                }
            } else {
                days_per_year = 366;
            }
        }
        total_days += days_per_year;
    }

    int day_of_week = (total_days + 1) % 7;
    return day_of_week;
}

vector<int> day_of_first(int year) {
    auto starting_day = days_since_1900(year);

    std::vector<int> sundays;

    map<int, int> days_in_year{
        {1, 31},
        {2, 28},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
    };
    // is year a leap year
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                days_in_year[2] = 29;
            } else {
                days_in_year[2] = 28;
            }
        } else {
            days_in_year[2] = 29;
        }
    }

    int cumulative_days = starting_day;
    if (starting_day == 0) {
        sundays.push_back(1);
    }
    for (const auto& [k, v]: days_in_year) {
        cumulative_days += v;
        cumulative_days %=  7;
        if (cumulative_days == 0) {
            sundays.push_back(k+1);
        }
    }
    return sundays;
}

int sundays_since(int year) {
    int total_sundays = 0;
    for (int i = 1901; i <= year; i++) {
        total_sundays += day_of_first(i).size();
    }
    return total_sundays;
}

int main(int, char**) {
    auto [result, duration] = euler::ntime(sundays_since, 2000);
    cout << "Total sundays since 1901: " << result << "\n";
    cout << "Duration (ns): " << duration << "\n";
    return 0;
}
