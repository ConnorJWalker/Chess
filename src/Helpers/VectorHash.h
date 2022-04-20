#pragma once
#include <cstddef>
#include <unordered_set>
#include <SFML/System/Vector2.hpp>

namespace std {
    template<class T>
    struct hash<sf::Vector2<T>> {
        size_t operator ()(sf::Vector2<T> const& vec) const {
            size_t x = std::hash<T>()(vec.x);
            size_t y = std::hash<T>()(vec.y);

            return x ^ y + 0x9e3779b9 + (x << 6) + (x >> 2);
        }
    };
}