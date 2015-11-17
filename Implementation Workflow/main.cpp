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
#include <iomanip>
#include <ctime>

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
    //need to change the claim structure after passing the date + time variable as one instead of separately
    struct newClaim {
        string currentDateAndTime;
        string dateServiceProvided;
        string comments;
        int providerID, memberID;
    };
    newClaim newestClaim;
    Claim(void) {};
    Claim(int &providerID, int &memberID, string &dateAndTime, string &dateProvided, string &Comments) {
        newestClaim.providerID = providerID;
        newestClaim.memberID = memberID;
        newestClaim.currentDateAndTime = dateAndTime;
        newestClaim.dateServiceProvided = dateProvided;
        newestClaim.comments = Comments;
    }
    void submitClaim(int &providerID, int &memberID, string &dateAndTime, string &dateProvided, string &Comments);
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
    string currentDateAndTime;
    string dateServiceProvided;
    int serviceCode;
    string comments;
    
    void userInterface(void);
};

void Terminal::userInterface(void) {
    Provider newProvider;
    Member newMember;
    Service newService;
    Claim newClaim;
    Operator newOperator;
    char choice, operatorChoice, memberChoice, providerChoice, serviceChoice;
    int ID, zipCode, code;
    string name, streetAddress, city, state;
    double fee;
    
    cout << "Welcome to the Chocoholics Anonymous Terminal!\n";
    cout << "Are you a provider(p or P) or an operator(o or O): ";
    cin >> choice;
    while(toupper(choice) != 'P' && (toupper(choice) != 'O')) {
        cout << "Error you entered an incorrect response!\n";
        cout << "Please enter provider(p or P) or an operator(o or O): ";
        cin >> choice;
    }
    if (toupper(choice) == 'P') {
      cout << "Please enter your provider ID: ";  
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
      //then i need to combine them into one variable of type char[19] or string with length 19
      //newClaim.submitClaim(&providerID, &memberID, &currentDateAndTime, &dateServiceProvided, &comments);
    }
    else {
        cout << "Hello Operator! What would you like to do?\n";
        cout << "Would you like to do something with a member(m or M), provider(p or P), or a service(s or S): ";
        cin >> operatorChoice;
        while(toupper(operatorChoice) != 'M' && toupper(operatorChoice) != 'P' && toupper(operatorChoice) != 'S') {
            cout << "Error! You entered an incorrect response!\n";
            cout << "Please enter member(m or M), provider(p or P), or a service(s or S): ";
            cin >> operatorChoice;
        }
        if (toupper(operatorChoice) == 'M') {
            cout << "\nWould you like to add(a or A) a new member, delete(d or D) a current member, or update(u or U) a current member: ";
            cin >> memberChoice;
            while(toupper(memberChoice) != 'A' && toupper(memberChoice) != 'D' && toupper(memberChoice) != 'U') {
                cout << "Error! You entered an incorrect response!\n";
                cout << "Please enter add(a or A), delete(d or D), update(u or U): ";
                cin >> memberChoice;
            }
            if (toupper(memberChoice)  == 'A') {
                cout << "Please enter the information for the new member!\n";
                cout << "What is the new member's first and last name? E.g. First Last: ";
                cin >> name;
                cout << "\nWhat is the new member's ID: ";
                cin >> ID;
                cout << "\nWhat is the new member's street address: ";
                cin >> streetAddress;
                cout << "\nWhat is the new member's city: ";
                cin >> city;
                cout << "\nWhat is the new member's state: ";
                cin >> state;
                cout << "\nWhat is the new member's zip code: ";
                cin >> zipCode;
                cout << "The new member will now be added!\n";
                newOperator.addMember(ID, name, streetAddress, city, state, zipCode);
            }
            else if (toupper(memberChoice) == 'D') {
                cout << "Please enter the member ID for the member you would like to delete: ";
                cin >> ID;
                cout << "\nThank you the member will now be deleted!\n";
                newOperator.deleteMember(ID);
            }
            else {
                cout << "Please enter the the member's ID you would like to update: ";
                cin >> ID;
                //Now I must finish this in order to update a member in the system
            }
        }
        else if (toupper(operatorChoice == 'P')) {
            cout << "\nWould you like to add(a or A) a new provider, delete(d or D) a current provider, or update(u or U) a current provider: ";
            cin >> providerChoice;
            while(toupper(providerChoice) != 'A' && toupper(providerChoice) != 'D' && toupper(providerChoice) != 'U') {
                cout << "Error! You entered an incorrect response!\n";
                cout << "Please enter add(a or A), delete(d or D), update(u or U): ";
                cin >> providerChoice;
            }
            if (toupper(providerChoice)  == 'A') {
                cout << "Please enter the information for the new provider!\n";
                cout << "What is the new Provider first and last name? E.g. First Last: ";
                cin >> name;
                cout << "\nWhat is the new Provider ID: ";
                cin >> ID;
                cout << "\nWhat is the new Provider street address: ";
                cin >> streetAddress;
                cout << "\nWhat is the new Provider city: ";
                cin >> city;
                cout << "\nWhat is the new Provider state: ";
                cin >> state;
                cout << "\nWhat is the new Provider zip code: ";
                cin >> zipCode;
                cout << "The new Provider will now be added!\n";
                newOperator.addProvider(ID, name, streetAddress, city, state, zipCode);
            }
            else if (toupper(providerChoice) == 'D') {
                cout << "Please enter the member ID for the member you would like to delete: ";
                cin >> ID;
                cout << "\nThank you the member will now be deleted!\n";
                newOperator.deleteProvider(ID);
            }
            else {
                cout << "Please enter the the Provider ID you would like to update: ";
                cin >> ID;
                //Now I must finish this in order to update a provider in the system
            }  
        }
        else {
            cout << "\nWould you like to add(a or A) a new service, delete(d or D) a current service, or update(u or U) a current service: ";
            cin >> serviceChoice;
            while(toupper(serviceChoice) != 'A' && toupper(serviceChoice) != 'D' && toupper(serviceChoice) != 'U') {
                cout << "Error! You entered an incorrect response!\n";
                cout << "Please enter add(a or A), delete(d or D), update(u or U): ";
                cin >> serviceChoice;
            }
            if (toupper(serviceChoice)  == 'A') {
                cout << "Please enter the information for the new service!\n";
                cout << "What is the service code: ";
                cin >> code;
                cout << "What is the name of the service: ";
                cin >> name;
                cout << "What is the fee for the service: ";
                cin >> fee;
                newOperator.addService(code, name, fee);
            }
            else if (toupper(serviceChoice) == 'D') {
                cout << "Please enter the service code for the service you would like to delete: ";
                cin >> ID;
                cout << "\nThank you the service will now be deleted!\n";
                newOperator.deleteService(code);
            }
            else {
                cout << "Please enter the the service code you would like to update: ";
                cin >> code;
                //Now I must finish this in order to update a service in the system
            }
        }
    }
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

