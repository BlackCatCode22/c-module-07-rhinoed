#include "Bear.h"
#include <iostream>
#include <string>
#include <random>

namespace animal {
    Bear::Bear(const std::string &id,const std::string &name, int age, int weight, const std::string &species, const std::string &origin, const std::string &birthSeason, const std::string &color) : Animal(id,name, age, weight, "Bear", origin, birthSeason, color) {}

    void Bear::hibernate() {
        std::cout << name << ", the bear is going into hibernation." << "\n";
    }

    std::string Bear::generateName() {
        static std::random_device rd;
        static std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(0, 9);
        int randomIndex = distribution(generator);
        if (animalNames.size() > 2 && animalNames[2].size() >= randomIndex) {
            return animalNames[2][randomIndex];
        } else {
            return "DefaultBearName";
        }
    }
} // animal