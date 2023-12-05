
#include <iostream>
#include "Service.h"
#include <fstream>
#include <sstream>

// Constructor to initialize data members
Service::Service(const std::string &id, const std::string &n, const std::string &pr)
    : ID(id), Name(n), Price(pr) 
{}

// Function to display service details
 void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->ID << "\t" << temp->serviceName << "\t" << temp->priceRange << std::endl;
            temp = temp->next;
        }
    }
bool editData(const std::string& id, const std::string& newName, const std::string& newRange) {
        Node* temp = head;
        while (temp) {
            if (temp->ID == id) {
                temp->serviceName = newName;
                temp->priceRange = newRange;
                return true;
            }
            temp = temp->next;
        }
        return false; // Không tìm thấy ID
    }
    
void updateFile(const std::string& filename, LinkedList& list) {
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    Node* temp = list.begin();
    while (temp) {
        outputFile << temp->ID << "\t" << temp->serviceName << "\t" << temp->priceRange << "\n";
        temp = temp->next;
    }

    outputFile.close();
}
