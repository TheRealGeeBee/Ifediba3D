#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <regex>
using namespace std;

string username, password;
string name, email;
string countryName, businessName, stateOrRegion; //stateOrRegion defines where business is located in the country

bool isStrongPassword(const std::string& password) {
    //This function validates that the password created by user meet some standards described in this function.
    bool hasUppercase = false;
    bool hasLowercase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    // Check the length of the password
    if (password.length() < 8) {
        return false;
    }

    // Check each character in the password
    for (char c : password) {
        if (std::isupper(c)) {
            hasUppercase = true;
        } else if (std::islower(c)) {
            hasLowercase = true;
        } else if (std::isdigit(c)) {
            hasDigit = true;
        } else {
            hasSpecialChar = true;
        }
    }

    // Check if all the requirements are met
    return hasUppercase && hasLowercase && hasDigit && hasSpecialChar;
}

bool isValidEmail(const std::string& email) {
    // Checks if email user provided follows the conventional pattern. Returns true or false
    const regex emailPattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(email, emailPattern);
}
void endFunction() {
    //Used to terminate other functions
cout << "\n\t\t\t\t\tProgram Terminated...\n";
}
void userDashBoard() {
    //This bears the code for the main user dashboard
 int userChoice,new_count;
cout << "\n\t\t\t\t\t*************DASHBOARD PAGE*************** " <<endl;

cout << "\n\t\t\t\t\tSelect what you want to do today\n\n\t\t\t\t\t\t\t[1] Create\n\t\t\t\t\t\t\t[2] My Works\n\t\t\t\t\t\t\t[3] My Inventories\n\t\t\t\t\t\t\t[4] Exit Application\n";

cin >> userChoice;

if (userChoice == 1) {
    cout << "\n\t\t\t\t\tThis feature is not available for this software version\n";
    endFunction();
    }
else if (userChoice == 2){
    cout << "\n\t\t\t\t\tNo Work To Show Here...\n";
    return;
    }
else if (userChoice == 3){
    cout << "\n\t\t\t\t\tYou have not added any inventory.\n";
    return;
    }
else if (userChoice==4){
        cout << "\n\t\t\t\t\t\t"<<username <<", you have closed the application successfully" << endl;
}
else {
        while (userChoice > 4 || userChoice == 0) {
    cout << "You entered an invalid input...\n";
    cout << "\n\t\t\t\t\tSelect what you want to do today\n\n\t\t\t\t\t\t\t[1] Create\n\t\t\t\t\t\t\t[2] My Works\n\t\t\t\t\t\t\t[3] My Inventories\n\t\t\t\t\t\t\t[4] Exit Application\n";

cin >> userChoice;
}
}
}


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
    string password;
    string name;
    string email;
};

bool signUp(const string& username, const vector<string>& existingUsernames) {
    // Check if the username is already taken
    if (find(existingUsernames.begin(), existingUsernames.end(), username) != existingUsernames.end()) {
        return true;
    } else {
        return false;
    }
}

bool createUser(const User& user) {
    // Validate user input and save the user to a file or database
    // Return true if the user is successfully created, false otherwise
    // You may want to perform validations, check for duplicate usernames or emails, etc.
    // Save the user data to a file or database for future logins
    // Return true if the user is successfully created, false otherwise
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << user.username << "|" << user.password << "|" << user.name << "|" << user.email << "\n";
        file.close();
        return true;
    }
    return false;
}

bool validateUser(const string& username, const string& password) {
    // Check if the username and password match the stored credentials
    ifstream file("users.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string storedUsername, storedPassword;
            if (std::getline(iss, storedUsername, '|') && getline(iss, storedPassword, '|')) {
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
    std::cout << "\n\t\t\t\t\tWelcome, " << username << "!\n" << std::endl;
    userDashBoard(); //Calls user dashboard
}

void signIn() {
    cout << "\n\n\t\t*************LOGIN PAGE*************" << endl;
    int user_choice, counter = 0;
    cout << "\nEnter business name: ";
    cin.ignore();
    getline(cin, businessName);
    cout << "\nWho are you to "<< businessName <<"?\n\t[1] I Own This Business\n\t[2] Marketing Manager\n\t";
    cin >> user_choice;
    if (user_choice==1) {
        cout << businessName <<"'s Owner's Login\n";
    }
    else if (user_choice == 2) {
        cout << businessName << "'s Marketing Manager's Login\n";
    }
    else {
        cout << "\nYou are not affiliated with this business\n";
        endFunction();
        return;
    }
    cin.ignore();
    while (counter <= 4) {
    std::cout << "\nEnter username: ";
    getline(cin,username);
    std::cout << "\nEnter password: ";
    std::getline(cin,password);
    if (validateUser(username, password)) {
        std::cout << "\nLogin successful!\n" << endl;
        displayDashboard(username);
        break;
    } else {
        std::cout << "\nInvalid username or password. Please try again." << std::endl;
    }
    counter += 1;
    }
}
/*if (counter > 4) {
    cout << "\nToo many login attempts. Exiting the application.";
    endFunction();
}
*/

int main() {
    // Sample code to demonstrate user registration, login, and dashboard functionality

    std::cout << "\nWelcome to Ifediba3D: Automate Your Small Business\n" << std::endl;

    int choice;
        std::cout << "1. Sign Up" << std::endl;
        std::cout << "\n2. Log In" << std::endl;
        std::cout << "\n0. Exit" << std::endl;
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        switch (choice){

        case 1: {
            std::vector<std::string> existingUsernames = getUsernamesFromFile("users.txt");
            std::cout << "\nEnter username: ";
            cin.ignore();
            getline(cin,username);
            bool isUsernameTaken = signUp(username, existingUsernames);//Remember to talk about me in the slide
            while (isUsernameTaken == true) {
                std::cout << "\nUsername already taken. Please enter a different username: ";
                getline(cin,username);
                isUsernameTaken = signUp(username, existingUsernames);
            }
            std::cout << "\nEnter password: ";
            getline(cin,password);
            if (isStrongPassword(password)) {
            std::cout << "\nEnter name: ";
            getline(cin,name);
            cout << "\nEnter name of small business: ";
            getline(cin,businessName);
            cout << "\nEnter country where business is domiciled: ";
            getline(cin,countryName);
            cout << "\nEnter state/region where business is located: ";
            getline(cin,stateOrRegion);
            cout << "\nEnter email: ";
            getline(cin,email);


            if (isValidEmail(email)) {
            // Email is valid, proceed with sign-up process
                User newUser{ username, password, name, email };
                if (createUser(newUser)) {
                    std::cout << "\nUser created successfully!" << std::endl;
                    signIn();  // Automatically sign in the user after successful registration
                    }
                else {
                    std::cout << "\nFailed to create account. Please try again." << std::endl;
                    }
                }
            else {
                std::cout << "\nInvalid email address. Please try again.\n" << std::endl;
                //std::cout << "\nEnter email: ";
                //getline(cin,email);
                }
                break;
        }
        else {
            std::cout << "\nPassword must be at least 8 characters long and contain uppercase and lowercase letters, numbers, and special characters." << std::endl;
            return 0;
        // Prompt the user to enter a strong password

        }
        }

        case 2:
            {
        signIn();
        break;
        }
        case 0:
            {
        cout << "\nYou have successfully exited the software";
        return 0;
        }
        default:
            {
        cout << "\nInvalid choice. Please try again." << endl;
        }
        }

    //std::cout << "Thank you for using Ifediba3D: Automate Your Small Business!" << std::endl;

    return 0;
}
