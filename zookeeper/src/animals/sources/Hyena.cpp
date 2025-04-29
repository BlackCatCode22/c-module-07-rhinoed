#include "Hyena.h"
#include <iostream>
#include <random>

namespace animal {
    Hyena::Hyena(const std::string &id,const std::string &name, int age, int weight, const std::string &species, const std::string &origin, const std::string &birthSeason, const std::string &color) : Animal(id,name, age, weight, "Hyena", origin, birthSeason, color) {}

    void Hyena::laugh() {
        std::cout << name << ", the hyena says Hahaha" << std::endl;
    }

    std::string Hyena::generateName() {
        static std::random_device rd;
        static std::mt19937 generator(rd());
        std::uniform_int_distribution<int> distribution(0, 10);
        int randomIndex = distribution(generator);
        if (Animal::animalNames.size() > 1 && Animal::animalNames[0].size() >= randomIndex) {
            return Animal::animalNames[0][randomIndex];
        } else {
            return "Hyena Name";
        }
    }
} // animal