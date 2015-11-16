/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File: CSC 470 Project
 * Author: Josh
 *
 * Created on November 12, 2015, 5:50 PM
 */

#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Member {
public:
    struct newMember {
        string memberName;
        int memberID;
        string memberStreetAddress;
        string memberCity;
        string memberState;
        int memberZipCode;
    };
    vector<newMember> memberContainer;
    newMember newestMember;
    Member(void) {};
    Member(string &name, int &ID, string &streetAddress, string &city, string &state, int &zipCode) {
        newestMember.memberName = name;
        newestMember.memberID = ID;
        newestMember.memberStreetAddress = streetAddress;
        newestMember.memberCity = city;
        newestMember.memberState = state;
        newestMember.memberZipCode = zipCode;
        memberContainer.push_back(newestMember);
    }
    string verifyMember(int ID);
};

string Member::verifyMember(int ID) {
    //verify the memberID that was entered is an actual member for ChocAn
    // if it found the program displays the member's status
    //if it is not found the program displays an error message
}

class Provider {
public:
    struct newProvider {
        string providerName;
        int providerID;
        string providerStreetAddress;
        string providerCity;
        string providerState;
        int providerZipCode;
    };
    vector<newProvider> providerContainer;
    newProvider newestProvider;
    Provider(void) {};
    Provider(string &name, int &ID, string &streetAddress, string &city, string &state, int &zipCode) {
        newestProvider.providerName = name;
        newestProvider.providerID = ID;
        newestProvider.providerStreetAddress = streetAddress;
        newestProvider.providerCity = city;
        newestProvider.providerState = state;
        newestProvider.providerZipCode = zipCode;
        providerContainer.push_back(newestProvider);
    }
    string verifyProvider(int ID);
};

string Provider::verifyProvider(int ID) {
    //verify the providerID that was entered is an actual provider for ChocAn
    //if it is found allow the program to continue
    //if it is not found the program will return an error message   
}

class Operator {
public:
    void addMember(string name, int ID, string streetAddress, string city, string state, int zipCode);
    void deleteMember(int ID);
    void updateMember(int ID);
    void addProvider(string name, int ID, string streetAddress, string city, string state, int zipCode);
    void deleteProvider(int ID);
    void updateProvider(int ID);
};

void Operator::addMember(string name, int ID, string streetAddress, string city, string state, int zipCode) {
    Member* newMember = new Member(name, ID, streetAddress, city, state, zipCode);
}

void Operator::deleteMember(int ID) {
    //find member by ID provided and delete them from the vector
}

void Operator::updateMember(int ID) {
    int memberID;
    cout << "\nPlease enter the ID of the member you are would like to update: ";
    cin >> memberID;
    /*now cycle through the member container to find the specified member
    once found the operator is asked which information he/she would like to update
    if no ID matches the one given to the function an error message is returned*/
}

void Operator::addProvider(string name, int ID, string streetAddress, string city, string state, int zipCode) {
    Provider* newProvider = new Provider(name, ID, streetAddress, city, state, zipCode);
}

void Operator::deleteProvider(int ID) {
    //find provider by ID provided and delete them from the vector
}

void Operator::updateProvider(int ID) {
    int providerID;
    cout << "\nPlease enter the ID of the provider you would like to update: ";
    cin >> providerID;
    /*now cycle through the provider container to find the specified provider
    once found the operator is asked which information he/she would like to update
    if no ID matches the one given to the function an error message is returned*/
}

class Fee {
public:
    struct newFee {
        int serviceCode;
        double fee;
        string name;
    };
    newFee newestFee;
    vector<newFee> providerDirectoryContainer;
    Fee() {};
    Fee(int code, double Fee, string feeName) {
        newestFee.serviceCode = code;
        newestFee.fee = Fee;
        newestFee.name = feeName;
        providerDirectoryContainer.push_back(newestFee);
    }
    double providerDirectory(int serviceCode);
};

double Fee::providerDirectory(int serviceCode) {
    //search the provider Directory for the fee associated with the service code passed to the function
}

class Claim {
public:
    struct newClaim {
        string currentDate;
        string currentTime;
        string dateServiceProvided;
    };
    newClaim newestClaim;
    Claim(void) {};
    Claim(string &cDate, string &cTime, string &dateProvided) {
        newestClaim.currentDate = cDate;
        newestClaim.currentTime = cTime;
        newestClaim.dateServiceProvided = dateProvided;
    }
};

class Report {
public:
    void printMemberReport();
    void printProviderReport();
    void printManagerReport();
};

void Report::printMemberReport() {
    //need to generate the code to print the member report every Friday or upon request
}

void Report::printProviderReport() {
    //need to generate the code to print the provider report every Friday or upon request
}

void Report::printManagerReport() {
    //need to generate the code to print the manager report every Friday or upon request
}

class UserInterface {
public:
    int providerNumber; 
    int memberID;
    string currentDate;
    string currentTime;
    string dateServiceProvided;
    int serviceCode;
    string comments;
    
    void userInterface(void);
};

void UserInterface::userInterface(void) {
    Provider newProvider;
    Member newMember;
    Fee newFee;
    
    cout << "\nPlease enter your provider number: ";
    cin >> providerNumber;
    newProvider.verifyProvider(providerNumber);
    cout << "\nNow enter the member's identification number: ";
    cin >> memberID;
    newMember.verifyMember(memberID);
    cout << "\nIn order to be billed for your services you must first re-enter the member's identification number: ";
    cin >> memberID;
    newMember.verifyMember(memberID);
    cout << "\nNow, enter the date the service was provided to the member in the format MM-DD-YYYY: ";
    cin >> dateServiceProvided;
    cout << "\nEnter the six-digit service code corresponding to the service that was provided: ";
    cin >> serviceCode;
    newFee.providerDirectory(serviceCode);
    cout << "\nEnter any additional comments about the service provided to the member: ";
    cin >> comments;
    //retrieve current date and time and pass to the claim class as well as the comments
    Claim newClaim(currentDate, currentTime, dateServiceProvided);
}
/*
 * 
 */
int main(void) {
    Operator newOperator;
    newOperator.addMember("Timothy Hobbs", 100000000, "1456 Dove Drive", "Fayetteville", "NC", 28314);
    newOperator.addMember("Tom Jones", 100000001, "3875 Hopeless Lane", "Asheville", "NC", 28801);
    newOperator.addMember("Jerry Pete", 100000002, "2145 Butter wood Circle", "Hope Mills", "NC", 28348);
    newOperator.addMember("Michael Black", 100000003, "5421 Timothy Street", "Aberdeen", "NC", 28315);
    newOperator.addProvider("Pete White", 000000001, "7856 Candle Lane", "Fayetteville", "NC", 28314);
    newOperator.addProvider("Clinton Thomas", 000000002, "1234 Murray Drive", "Asheville", "NC", 28801);
    newOperator.addProvider("Diana Sawyer", 000000003, "6873 Thomas Court", "Aberdeen", "NC", 28315);
    newOperator.addProvider("Tammy Smith", 000000004, "5893 Main Street", "Hope Mills", "NC", 28348);
    
    //Need to generate code for handling the input text files
    //provider text file
    //member text file
    //provider directory text file so on and so forth
    
    UserInterface newUserInterface;
    newUserInterface.userInterface();
    return 0;
}

