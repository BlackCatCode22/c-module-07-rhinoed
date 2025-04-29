#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <vector>


using namespace std;

namespace animal {

    class Animal {

    protected:
        // Class properties
        string id;
        string name;
        int age;
        int weight;
        string species;
        string origin;
        string birthSeason;
        string color;


    public:
        static std::vector<std::vector<std::string>> animalNames;
        // Class constructor
        Animal(const string &id,const string &name, int age, int weight, const string &species, const string &origin,
               const string &birthSeason,
               const string &color);
        // Class destructor
        virtual ~Animal() = default;



        // getters and setters
        std::string getID() const;
        void setID(const string &id);
        int getAge() const;
        void setAge(const int age);
        string getSpecies() const;
        string getColor() const;
        void setSpecies(const string& species);
        string getName() const;
        void setName(const string& name);
        string getOrigin() const;
        void setOrigin(const string& origin);
        std::vector<std::vector<std::string>> getAnimalNames() const;
        void setAnimalNames(const std::vector<std::vector<std::string>>& animalNames);
        std::string getBirthSeason() const;
        // Class methods
        void displayInfo() const;

    };

} // animal

#endif //ANIMAL_H