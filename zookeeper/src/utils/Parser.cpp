//
// Created by Mark Edmunds on 4/2/25.
//
#include "Parser.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <iostream>

std::vector<std::vector<std::string>> parseFile(const std::string& filename) {
    std::vector<std::vector<std::string>> data;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        line.erase(std::remove(line.begin(), line.end(), '\r'), line.end());
        std::vector<std::string> row;
        std::string cell;
        std::istringstream lineStream(line);
        while (std::getline(lineStream, cell, ',')) {
            row.push_back(cell);
        }
        data.push_back(row);
    }
    file.close();
    return data;
}

std::string splitString(const std::string& str, char delimiter, int index) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        // strip leading and trailing whitespace
        token.erase(0, token.find_first_not_of(' '));
        // add token to the vector
        tokens.push_back(token);
    }
    return tokens.size() > index ? tokens[index] : "";
}

std::vector<std::vector<std::string>> parseAnimalNames(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::vector<std::string>> animalGroups;
    std::vector<std::string> currentGroup;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return {};
    }

    while (std::getline(file, line)) {
        while (!line.empty() && std::isspace(line.back())) line.pop_back();
        while (!line.empty() && std::isspace(line.front())) line.erase(line.begin());

        std::string lowerLine = line;
        std::transform(lowerLine.begin(), lowerLine.end(), lowerLine.begin(), ::tolower);

        if (lowerLine.find(" names:") != std::string::npos) {
            if (!currentGroup.empty()) {
                animalGroups.push_back(currentGroup);
                currentGroup.clear();
            }
        } else if (!line.empty()) {
            std::stringstream ss(line);
            std::string name;
            while (std::getline(ss, name, ',')) {
                while (!name.empty() && std::isspace(name.back())) name.pop_back();
                while (!name.empty() && std::isspace(name.front())) name.erase(name.begin());
                currentGroup.push_back(name);
            }
        }
    }

    if (!currentGroup.empty()) {
        animalGroups.push_back(currentGroup);
    }

    return animalGroups;
}