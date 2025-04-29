//
// Created by Mark Edmunds on 3/9/25.
//

#ifndef ZOOMANAGER_H
#define ZOOMANAGER_H

#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include "Hyena.h"
#include "Lion.h"
#include "Tiger.h"
#include "Bear.h"


namespace zooManager {
    class ZooManager {
    protected:

    public:
        std::vector<animal::Hyena> hyenaEnclosure;
        std::vector<animal::Lion> lionEnclosure;
        std::vector<animal::Tiger> tigerEnclosure;
        std::vector<animal::Bear> bearEnclosure;
        // used animal names
        std::set<std::string> usedAnimalNames;
        // Default constructor
        ZooManager();
        // Constructor
        ZooManager(std::vector<animal::Hyena> hyenaEnclosure, std::vector<animal::Lion> lionEnclosure,
                   std::vector<animal::Tiger> tigerEnclosure, std::vector<animal::Bear> bearEnclosure,
                   std::set<std::string>usedAnimalNames);

        // Destructor
        virtual ~ZooManager() = default;

        // Method to add an animal to the zoo
        void addAnimal(const std::string &species, const std::string &name, int age);

        // Method to display all animals in the zoo
        void displayAnimals();

        // Method to remove an animal from the zoo
        void removeAnimal(const std::string &name);

        // Method to generate a report of all animals in the zoo
        void generateReport();
        // Method to count the number of animals in the zoo
        std::map<std::string, int> countAnimals();
        // generate a unique ID for each animal
        std::string genUniqueID(const std::string &species, int count);

        std::string genBirthDate(const std::string &birthSeason, const int &age);

        // Method to process animals
        template<class T>
        void processAnimals( T &animal) {
            std::string species = animal.getSpecies();
            std::map<std::string, int> animalCount = countAnimals();
            if (species == "Hyena") {
                int hyenaCount = animalCount.at("Hyena");
                // set the ID of the animal by calling the genUniqueID method
                // set the ID of the animal
                std::string id = genUniqueID(species, hyenaCount);
                animal.setID(id);
                // Add the animal to the hyena enclosure
                hyenaEnclosure.push_back(dynamic_cast<const animal::Hyena&>(animal));
            } else if (species == "Bear") {
                int bearCount = animalCount.at("Bear");
                // set the ID of the animal
                std::string id = genUniqueID(species, bearCount);
                animal.setID(id);
                // Add the animal to the bear enclosure
                bearEnclosure.push_back(dynamic_cast<const animal::Bear&>(animal));
            } else if (species == "Lion") {
                int lionCount = animalCount.at("Lion");
                // set the ID of the animal
                std::string id = genUniqueID(species, lionCount);
                animal.setID(id);
                // Add the animal to the lion enclosure
                lionEnclosure.push_back(dynamic_cast<const animal::Lion&>(animal));
            } else if (species == "Tiger") {
                int tigerCount = animalCount.at("Tiger");
                // set the ID of the animal
                std::string id = genUniqueID(species, tigerCount);
                animal.setID(id);
                // Add the animal to the tiger enclosure
                tigerEnclosure.push_back(dynamic_cast<const animal::Tiger&>(animal));
            } else {
                std::cerr << "Unknown species: " << species << std::endl;
            }
        }
    };
} // zooManager




#endif //ZOOMANAGER_H
