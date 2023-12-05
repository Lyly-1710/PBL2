#include <iostream>
#include "Service.cpp"
#include "LinkedList.cpp"

using namespace std;
int main()
{
std::ifstream inputFile("Service.txt"); // Replace "services.txt" with your actual file name
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string ID, Name, Price;
        if (iss >> ID >> Name >> Price) {
            Service Service(ID, Name, Price);
            Service.display();
        }
    }

    inputFile.close();
}
