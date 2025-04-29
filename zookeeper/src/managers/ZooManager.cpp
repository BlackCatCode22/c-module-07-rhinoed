//
// Created by Mark Edmunds on 3/9/25.
//

#include "ZooManager.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <ostream>
#include <iomanip>
#include <sstream>
#include "Animal.h"


namespace zooManager {
    ZooManager::ZooManager() {};

    ZooManager::ZooManager(std::vector<animal::Hyena> hyenaEnclosure, std::vector<animal::Lion> lionEnclosure, std::vector<animal::Tiger> tigerEnclosure, std::vector<animal::Bear> bearEnclosure, std::set<std::string> usedAnimalNames) {}

    void ZooManager::addAnimal(const std::string &species, const std::string &name, int age) {
        // TODO: Implement this function
    }

    void ZooManager::displayAnimals() {
        // Display all animals in the zoo
        std::map<std::string, int> animalCount = countAnimals();
        std::cout << "\nHyena Enclosure ("<< animalCount["Hyena"] << "):" << "\n";
        for (const auto &hyena : hyenaEnclosure) {
            hyena.displayInfo();
        }
        std::cout << "\nLion Enclosure ("<< animalCount["Lion"] << "):" << "\n";
        for (const auto &lion : lionEnclosure) {

            lion.displayInfo();
        }
        std::cout << "\nTiger Enclosure ("<< animalCount["Tiger"] << "):" << "\n";
        for (const auto &tiger : tigerEnclosure) {
            tiger.displayInfo();
        }
        std::cout << "\nBear Enclosure ("<< animalCount["Bear"] << "):" << "\n";
        for (const auto &bear : bearEnclosure) {
            bear.displayInfo();
        }
    }



    void ZooManager::removeAnimal(const std::string &name) {
        // TODO: Implement this function
    }

    void ZooManager::generateReport() {
        // Open a file for writing
        std::string filename = "../data/zooReport.txt";
        std::ofstream file(filename);
        // Write the report to the file
        file << "*******************************\n";
        file << "********* Zoo Report **********\n";
        file << "*******************************\n";
        file << "\n\n";
        file << "\nHyena Enclosure (" << hyenaEnclosure.size() << "):\n\n";
        for (const auto &hyena : hyenaEnclosure) {
            file << hyena.getID() << "; " << hyena.getName() << "; " << hyena.getAge() << "; " << hyena.getColor() << "; " << hyena.getOrigin() << "; " << genBirthDate(hyena.getBirthSeason(), hyena.getAge()) << "\n";
        }
        file << "\nLion Enclosure (" << lionEnclosure.size() << "):\n\n";
        for (const auto &lion : lionEnclosure) {
            file << lion.getID() << "; " << lion.getName() << "; " << lion.getAge() << "; " << lion.getColor() << "; " << lion.getOrigin() << "; " << genBirthDate(lion.getBirthSeason(), lion.getAge()) << "\n";
        }
        file << "\nTiger Enclosure (" << tigerEnclosure.size() << "):\n\n";
        for (const auto &tiger : tigerEnclosure) {
            file << tiger.getID() << "; " << tiger.getName() << "; " << tiger.getAge() << "; " << tiger.getColor() << "; " << tiger.getOrigin() << "; " << genBirthDate(tiger.getBirthSeason(), tiger.getAge()) << "\n";
        }
        file << "\nBear Enclosure (" << bearEnclosure.size() << "):\n\n";
        for (const auto &bear : bearEnclosure) {
            file << bear.getID() << "; " << bear.getName() << "; " << bear.getAge() << "; " << bear.getColor() << "; " << bear.getOrigin() << "; " << genBirthDate(bear.getBirthSeason(), bear.getAge()) << "\n";
        }
        file << std::endl;
        // Close the file
        file.close();
    }

    std::map<std::string, int> ZooManager::countAnimals() {
        std::map<std::string,int> animalCount;
        animalCount["Hyena"] = static_cast<int>(hyenaEnclosure.size());
        animalCount["Lion"] = static_cast<int>(lionEnclosure.size());
        animalCount["Tiger"] = static_cast<int>(tigerEnclosure.size());
        animalCount["Bear"] = static_cast<int>(bearEnclosure.size());
        return animalCount;
    }
    // Generate Unique ID for the animal called from the zooManager
    std::string ZooManager::genUniqueID(const std::string &species, int count) {
        std::ostringstream animalID;
        animalID << std::setw(2) << std::setfill('0') << count + 1;

        if (species == "Hyena") {
            return "Hy" + animalID.str();
        } else if (species == "Lion") {
            return "Li" + animalID.str();
        } else if (species == "Tiger") {
            return "Ti" + animalID.str();
        } else if (species == "Bear") {
            return "Be" + animalID.str();
        } else {
            // Handle unknown species
            return "Unknown" + animalID.str();
        }
    }
    // Generate a birthdate for the animal based on the birth season spring being the 21st of March, summer the 21st of June, autumn the 21st of September and winter the 21st of December and unknown being January 1st
    std::string ZooManager::genBirthDate(const std::string &birthSeason, const int &age) {
        // Get the current date
        std::time_t now = std::time(0);
        std::tm *ltm = std::localtime(&now);
        // Get the current year
        int year = 1900 + ltm->tm_year;
        // Subtract the age from the year
        year -= age;

        std::ostringstream date;
        if (birthSeason == "spring") {
            date << year << "-03-21";
        } else if (birthSeason == "summer") {
            date << year << "-06-21";
        } else if (birthSeason == "fall") {
            date << year << "-09-21";
        } else if (birthSeason == "winter") {
            date << year << "-12-21";
        } else {
            date << year << "-01-01";
        }
        return date.str();
    }
}// zooManager