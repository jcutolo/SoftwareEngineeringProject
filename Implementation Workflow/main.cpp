/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Josh
 *
 * Created on November 12, 2015, 5:50 PM
 */

#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

class Member {
public:
    struct newMember {
        string memberName[25];
        int memberID;
        string memberStreetAddress[25];
        string memberCity[14];
        string memberState[2];
        int memberZipCode;
    };
    vector<newMember> memberContainer;
    Member(string name, int ID, string streetAddress, string city, string state, int zipCode) {
        newMember.memberName = name;
        newMember.memberID = ID;
        newMember.memberStreetAddress = streetAddress;
        newMember.memberCity = city;
        newMember.memberState = state;
        newMember.memberZipCode = zipCode;
        memberContainer.push_back(newMember);
    }
};

class Provider {
public:
    struct newProvider {
        string providerName[25];
        int providerID;
        string providerStreetAddress[25];
        string providerCity[14];
        string providerState[2];
        int providerZipCode;
    };
    vector<newProvider> providerContainer;
    Provider(string name, int ID, string streetAddress, string city, string state, int zipCode) {
        newProvider.providerName = name;
        newProvider.providerID = ID;
        newProvider.providerStreetAddress = streetAddress;
        newProvider.providerCity = city;
        newProvider.providerState = state;
        newProvider.providerZipCode = zipCode;
        providerContainer.push_back(newProvider);
    }
};

class Operator {
public:
    void addMember(string name, int ID, string streetAddress, string city, string state, int zipCode) {
        Member newMember = new Member(name, ID, streetAddress, city, state, zipCode);
    }
    void deleteMember(int ID) {
        //cycle through the member container to delete the specified member by their ID
        //if no ID matches the ID given an error message is returned
    }
    void updateMember() {
        int memberID;
        cout << "\nPlease enter the ID of the member you are would like to update: ";
        cin >> memberID;
        //now cycle through the member container to find the specified member
        //once found the operator is asked which information he/she would like to update
        //if no ID matches the one given to the function an error message is returned
    }
    void addProvider(string name, int ID, string streetAddress, string city, string state, int zipCode) {
        Provider newProvider = new Provider(name, ID, streetAddress, city, state, zipCode);
    }
    void deleteProvider(int ID) {
        //cycle through the provider container to delete the specified provider by their ID
        //if no ID matches the ID given an error message is returned    
    }
    void updateProvider(int ID) {
        int providerID;
        cout << "\nPlease enter the ID of the provider you would like to update: ";
        cin >> providerID;
        //now cycle through the provider container to find the specified provider
        //once found the operator is asked which information he/she would like to update
        //if no ID matches the one given to the function an error message is returned
    }
};

class Fee {
public:
    int serviceCode;
    double fee;
    string name[30];
    //need to add a providerDirectory of the services with codes, fees, and their names
};

class Claim {
public:
    string currentDate[10];
    string currentTime[8];
    string dateServiceProvided[10];
    // need to add a function to allow the provider to enter in the correct information for a claim
};

class Report {
public:
    string type;
    void printMemberReport(string type);
    void printProviderReport(string type);
    void printManagerReport(string type);
    // need to add a function that will allow the data center to print the specified reports each week or upon request
};
//need to place this function in the correct spot either the provider class or the providerController class
string verifyProvider(int providerID) {
    //verify the providerID that was entered is an actual provider for ChocAn
    //if it is found allow the program to continue
    //if it is not found the program will return an error message
}

//need to place this function in the correct spot either the member class or the memberController class
string verifyMember(int memberID) {
    //verify the memberID that was entered is an actual member for ChocAn
    // if it found the program displays the member's status
    //if it is not found the program displays an error message
}

void userInterface() {
    int providerNumber; 
    int memberID;
    string currentDate[10];
    string currentTime[8];
    string dateServiceProvided[10];
    int serviceCode;
    string comments[100];
    
    cout << "Please enter your provider number: ";
    cin >> providerNumber;
    //verifyProvider(providerNumber);
    cout << "\nNow enter the member's identification number: ";
    cin >> memberID;
    //verifyMember(memberID);
    cout << "\nIn order to be billed for your services you must first re-enter the member's identification number: ";
    cin >> memberID;
    //verifyMember(memberID);
    cout << "\nEnter the six-digit service code corresponding to the service that was provided: ";
    cin >> serviceCode;
    //ProviderDirectory(serviceCode);
    cout << "\nEnter any additional comments about the service provided to the member: ";
    cin >> comments;
    //Send the comments and any other information to a specific function to hold
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
    
    userInterface();
    return 0;
}

