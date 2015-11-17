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
        int memberID;
        string memberName;
        string memberStreetAddress;
        string memberCity;
        string memberState;
        int memberZipCode;
    };
    newMember newestMember;
    vector<newMember> memberContainer;
    string verifyMember(int ID);
    void memberController(vector<newMember> &memberContainer, struct newMember newestMember);
    Member(void) {};
    Member(int &ID, string &name, string &streetAddress, string &city, string &state, int &zipCode) {
        newestMember.memberID = ID;
        newestMember.memberName = name;
        newestMember.memberStreetAddress = streetAddress;
        newestMember.memberCity = city;
        newestMember.memberState = state;
        newestMember.memberZipCode = zipCode;
        memberController(memberContainer,newestMember);
    }
};

string Member::verifyMember(int ID) {
    //verify the memberID that was entered is an actual member for ChocAn
    // if it found the program displays the member's status
    //if it is not found the program displays an error message
}

void Member::memberController(vector<newMember> &container, struct newMember newestMember) {
    container.push_back(newestMember);
}

class Provider {
public:
    struct newProvider {
        int providerID;
        string providerName;
        string providerStreetAddress;
        string providerCity;
        string providerState;
        int providerZipCode;
    };
    newProvider newestProvider;
    vector<newProvider> providerContainer;
    string verifyProvider(int ID);
    void providerController(vector<newProvider> &providerContainer, struct newProvider newestProvider);
    Provider(void) {};
    Provider(int &ID, string &name, string &streetAddress, string &city, string &state, int &zipCode) {
        newestProvider.providerID = ID;
        newestProvider.providerName = name;
        newestProvider.providerStreetAddress = streetAddress;
        newestProvider.providerCity = city;
        newestProvider.providerState = state;
        newestProvider.providerZipCode = zipCode;
        providerController(providerContainer, newestProvider);
    }
};

string Provider::verifyProvider(int ID) {
    //verify the providerID that was entered is an actual provider for ChocAn
    //if it is found allow the program to continue
    //if it is not found the program will return an error message   
}

void Provider::providerController(vector<newProvider> &container, struct newProvider newestProvider) {
    container.push_back(newestProvider);
}

class Service {
public:
    struct newService {
        int serviceCode;
        string name;
        double fee;
    };
    newService newestFee;
    vector<newService> providerDirectoryContainer;
    Service(void) {};
    Service(int &code, string &serviceName, double &Fee) {
        newestFee.serviceCode = code;
        newestFee.name = serviceName;
        newestFee.fee = Fee;
        providerDirectoryContainer.push_back(newestFee);
    }
    double lookUpFeeToBePaid(int serviceCode);
    void printProviderDirectory(vector<newService> providerDirectoryContainer);
};

double Service::lookUpFeeToBePaid(int serviceCode) {
    //search the provider Directory for the fee associated with the service code passed to the function
}

void Service::printProviderDirectory(vector<newService> providerDirectoryContainer) {
    //print the contents of the provider directory container to a file
}

class Operator {
public:
    void addMember(int ID, string name, string streetAddress, string city, string state, int zipCode);
    void deleteMember(int ID);
    void updateMember(int ID, string name, string streetAddress, string city, string state, int zipCode);
    void addProvider(int ID, string name, string streetAddress, string city, string state, int zipCode);
    void deleteProvider(int ID);
    void updateProvider(int ID, string name, string streetAddress, string city, string state, int zipCode);
    void addService(int code, string name, double fee);
    void deleteService(int code);
    void updateService(int code, string name, double fee);
};

void Operator::addMember(int ID, string name, string streetAddress, string city, string state, int zipCode) {
    Member* newMember = new Member(ID, name, streetAddress, city, state, zipCode);
}

void Operator::deleteMember(int ID) {
    //find member by ID provided and delete them from the vector
}

void Operator::updateMember(int ID, string name, string streetAddress, string city, string state, int zipCode) {
    int memberID;
    cout << "\nPlease enter the ID of the member you are would like to update: ";
    cin >> memberID;
    /*now cycle through the member container to find the specified member
    once found the operator is asked which information he/she would like to update
    if no ID matches the one given to the function an error message is returned*/
}

void Operator::addProvider(int ID, string name, string streetAddress, string city, string state, int zipCode) {
    Provider* newProvider = new Provider(ID, name, streetAddress, city, state, zipCode);
}

void Operator::deleteProvider(int ID) {
    //find provider by ID provided and delete them from the vector
}

void Operator::updateProvider(int ID, string name, string streetAddress, string city, string state, int zipCode) {
    int providerID;
    cout << "\nPlease enter the ID of the provider you would like to update: ";
    cin >> providerID;
    /*now cycle through the provider container to find the specified provider
    once found the operator is asked which information he/she would like to update
    if no ID matches the one given to the function an error message is returned*/
}

void Operator::addService(int code, string name, double fee) {
    Service* newService = new Service(code, name, fee);
}

void Operator::deleteService(int code) {
    //find the service by code and delete from the provider directory
}

void Operator::updateService(int code, string name, double fee) {
    //find the specified service by code then check the directory to see what needs to be changed
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
    //also need to somehow keep track of which providers are entering in the claims in order to keep track for reports
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

class Terminal {
public:
    int providerID; 
    int memberID;
    string currentDate;
    string currentTime;
    string dateServiceProvided;
    int serviceCode;
    string comments;
    
    void userInterface(void);
};

void Terminal::userInterface(void) {
    Provider newProvider;
    Member newMember;
    Service newService;
    
    cout << "\nPlease enter your provider number: ";
    cin >> providerID;
    newProvider.verifyProvider(providerID);
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
    newService.lookUpFeeToBePaid(serviceCode);
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
    newOperator.addMember(1, "Adam Blerk", "2932 Circle Drive", "Port Shepstone", "NY", 12345);
    newOperator.addMember(3, "Brian Macbeth", "100 Macbeth's Castle", "Inverness", "SL", 52561);
    newOperator.addMember(5, "Cathy Montague", "101 Montague Place", "Verona", "IT", 10002);
    newOperator.addMember(7, "Debbie Capulet", "212 Capulet Drive", "Verona", "IL", 20101);
    newOperator.addProvider(2, "Alexander", "123 Owen Street", "Fayetteville", "NC", 28303);
    //newOperator.addProvider(4, "Berry", "xxxxx", "yyyyy", "SC", 23456, "I");
    newOperator.addProvider(6, "Carrel", "1200 Murchison Rd", "Fayetteville", "NC", 28301);
    newOperator.addService(883948, "Aerobics exercises", 10.20);
    newOperator.addService(11, "Aversion Therapy", 30.00);
    newOperator.addService(555, "Chocolates in excess", 100.00);
    newOperator.addService(598470, "Dietician Session", 20.50);
    newOperator.addService(22, "Yoga", 12.50);
    
    Terminal newUserInterface;
    newUserInterface.userInterface();
    return 0;
}

