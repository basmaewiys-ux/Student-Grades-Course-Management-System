#ifndef UTILS_H
#define UTILS_H
#include <string>
#include <vector>

int getIntInput(const std::string& prompt);
double getDoubleInput(const std::string& prompt);

template <typename T>
T findMax(const std::vector<T>& items) {
    if (items.empty()) return T();
    T maxVal = items[0];
    for (const auto& item : items) {
        if (item > maxVal) maxVal = item;
    }
    return maxVal;
}
#endif