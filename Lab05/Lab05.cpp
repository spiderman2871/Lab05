// Lab05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

const std::vector<char> cypher = {'V','F','X','B','L','I','T','Z','J','R','P','H','D','K','N','O','W','S','G','U','Y','Q','M','A','C','E'};

void translateText(std::vector<int>& input) {

    for (size_t i = 0; i < input.size(); ++i) {

        int c = input[i];

        if (c >= 65 && c <= 90) {
            input[i] = cypher[c - 65];
        }

        else if (c >= 97 && c <= 122) {
            int upperCase = c - 32;
            char upperCaseCode = cypher[upperCase - 65];
            input[i] = upperCaseCode + 32;
        }
    }
}

int main() {

    std::vector<int> text;
    char ch;
    int count = 0;

    std::cout << "Enter message here: ";

    while (count < 128 && std::cin.get(ch) && ch != '\n') {
        text.push_back(static_cast<int>(ch));
        count++;
    }

    translateText(text);
    std::cout << "Encoded message: ";

    for (int c : text) {
        std::cout << static_cast<char>(c);
    }

    std::cout << std::endl;
    return 0;

}

