#include "Tiger.h"
#include <iostream>
#include <random>

namespace animal {
    Tiger::Tiger(const std::string &id,const std::string &name, int age, int weight, const std::string &species, const std::string &origin, const std::string &birthSeason, const std::string &color) : Animal(id,name, age, weight, "Tiger", origin, birthSeason, color) {}

    void Tiger::countStripes() {
        int stripes;
        std::cout << "How many stripes does the tiger have?" << std::endl;
        std::cin >> stripes;
        std::cout << "The tiger has " << stripes << " stripes" << std::endl;
    }

    std::string Tiger::generateName() {
        static std::random_device rd;
        static std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(0, 9);
        int randomIndex = distribution(generator);
        if (animalNames.size() > 1 && animalNames[3].size() >= randomIndex) {
            return animalNames[3][randomIndex];
        } else {
            return "DefaultTigerName";
        }
    }
} // animal