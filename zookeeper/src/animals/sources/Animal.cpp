// Animal.cpp
#include "Animal.h"
#include <string>
#include <iostream>
#include "Parser.h"

using namespace std;

namespace animal {
    std::vector<std::vector<std::string>> Animal::animalNames = parseAnimalNames("../data/animalNames.txt");

    // Constructor
    Animal::Animal(
        const string &id,
        const string &name,
        int age, int weight,
        const string &species,
        const string &origin,
        const string &birthSeason,
        const string &color
    )
        : id(id), name(name),
          age(age), weight(weight),
          species(species),
          origin(origin),
          birthSeason(birthSeason),
          color(color) {
    }

    // Getters
    std::string Animal::getID() const {
        return id;
    }

    int Animal::getAge() const {
        return age;
    }

    std::string Animal::getSpecies() const {
        return species;
    }

    std::string Animal::getName() const {
        return name;
    }

    std::string Animal::getColor() const {
        return color;
    }

    string Animal::getOrigin() const {
        return origin;
    }

    std::vector<std::vector<std::string>> Animal::getAnimalNames() const {
        return animalNames;
    }

    // Setters
    void Animal::setID(const std::string &id) {
        this->id = id;
    }

    void Animal::setAge(int age) {
        this->age = age;
    }

    void Animal::setSpecies(const std::string &species) {
        this->species = species;
    }

    void Animal::setName(const std::string &name) {
        this->name = name;
    }

    void Animal::setOrigin(const string &origin) {
        this->origin = origin;
    }

    void Animal::setAnimalNames(const std::vector<std::vector<std::string>>& animalNames) {
        this->animalNames = animalNames;
    }

    std::string Animal::getBirthSeason() const {
        return birthSeason;
    }

    // Display Method
    void Animal::displayInfo() const {
        std::cout << "\nName: " << name << "\nAge: " << age  << "\nWeight: " << weight  << "\nOrigin: " << origin << "\nBirth Season: " << birthSeason << "\nColor: " << color <<"\n";
    }
} // animal