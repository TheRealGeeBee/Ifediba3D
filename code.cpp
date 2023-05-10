#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

string username, password;

std::vector<std::string> getUsernamesFromFile(const std::string& filename) {
    std::vector<std::string> usernames;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string username;
        while (std::getline(file, username)) {
            usernames.push_back(username);
        }
        file.close();
    }
    return usernames;
}

struct User {
    string username;
    std::string password;
    std::string name;
    std::string email;
    // Add other user information fields as needed
};

bool signUp(const std::string& username, const std::vector<std::string>& existingUsernames) {
    // Check if the username is already taken
    if (std::find(existingUsernames.begin(), existingUsernames.end(), username) != existingUsernames.end()) {
        return true;
    }
    
        else {
            return false;
        }
    
}
bool createUser(const User& user) {
    // Validate user input and save the user to a file or database
    // Return true if the user is successfully created, false otherwise
    // You may want to perform validations, check for duplicate usernames or emails, etc.
    // Save the user data to a file or database for future logins
    // Return true if the user is successfully created, false otherwise
    std::ofstream file("users.txt", std::ios::app);
    if (file.is_open()) {
        file << user.username << "|" << user.password << "|" << user.name << "|" << user.email << "\n";
        file.close();
        return true;
    }
    return false;
}

bool validateUser(const std::string& username, const std::string& password) {
    // Check if the username and password match the stored credentials
    std::ifstream file("users.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string storedUsername, storedPassword;
            if (std::getline(iss, storedUsername, '|') && std::getline(iss, storedPassword, '|')) {
                if (storedUsername == username && storedPassword == password) {
                    file.close();
                    return true;
                }
            }
        }
        file.close();
    }
    return false;
}

void displayDashboard(const std::string& username) {
    // Display the user's dashboard
    std::cout << "Welcome, " << username << "!" << std::endl;
    // Implement the functionality to display the user's dashboard, including various sections and options
}

int main() {
    // Sample code to demonstrate user registration, login, and dashboard functionality

    std::cout << "Welcome to Ifediba3D: Automate Your Small Business" << std::endl;

    int choice;
    do {
        std::cout << "1. Sign Up" << std::endl;
        std::cout << "2. Log In" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::vector<std::string> existingUsernames = getUsernamesFromFile("users.txt");
            std::string username, password, name, email;
            std::cout << "Enter username: ";
            std::cin >> username;
            bool value = signUp(username, existingUsernames);
            while (value == true) {
                std::cout << "Enter username: ";
            std::cin >> username;
            bool value = signUp(username, existingUsernames);
                }
            std::cout << "Enter password: ";
            std::cin >> password;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter email: ";
            std::cin >> email;

            User newUser{ username, password, name, email };
            if (createUser(newUser)) {
                std::cout << "User created successfully!" << std::endl;
                
                cout << "\t\tLOGIN PAGE" << endl;
                std::cout << "Enter username: ";
                std::cin >> username;
                std::cout << "Enter password: ";
                std::cin >> password;        
                if (validateUser(username, password)) {
                std::cout << "Login successful!" << std::endl;
                displayDashboard(username);
                break;
            // Implement the functionality to display the user's dashboard
    
        }
        else {
            std::cout << "Invalid username or password. Please try again." << std::endl;
        }
            } else {
                std::cout << "Failed to create user. Please try again." << std::endl;
}
}
else if (choice == 0) {
    cout << "\nYou have successfully exited the software";
    return 0;
}
} while (choice != 2);

//std::cout << "Thank you for using Ifediba3D: Automate Your Small Business!" << std::endl;
if (choice == 2) {
std::cout << "Enter username: ";
std::cin >> username;
std::cout << "Enter password: ";
std::cin >> password;        
    if (validateUser(username, password)) {
            std::cout << "Login successful!" << std::endl;
            displayDashboard(username);
            // Implement the functionality to display the user's dashboard
        } else {
            std::cout << "Invalid username or password. Please try again." << std::endl;
        }
    }



        if (validateUser(username, password)) {
            std::cout << "Login successful!" << std::endl;
            displayDashboard(username);
            // Implement the functionality to display the user's dashboard
        } else {
            std::cout << "Invalid username or password. Please try again." << std::endl;
        }
    }
 //while (choice != 0);




                
               
