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
        char memberName;
        char memberStreetAddress;
        char memberCity;
        char memberState;
        int memberZipCode;
    };
    newMember newestMember;
    newMember *memberPointer;
    vector<newMember> memberContainer;
    string verifyMember(int ID);
    void memberController(vector<newMember> &memberContainer, struct newMember *newestMember);
    void printMemberList();    
    Member(void) {};
    Member(int &ID, const char &name, const char &streetAddress, const char &city, const char &state, int &zipCode) {
        memberPointer = &newestMember;
        (*memberPointer).memberID = ID;
        (*memberPointer).memberName = name;
        (*memberPointer).memberStreetAddress = streetAddress;
        (*memberPointer).memberCity = city;
        (*memberPointer).memberState = state;
        (*memberPointer).memberZipCode = zipCode;
        memberController(memberContainer,memberPointer);
    }
};

string Member::verifyMember(int ID) {
    for(int i = 0; i < memberContainer.size(); i++) {
        if(memberContainer.empty()) {
            cout << "Unfortunately there are no members as of this time in the system to verify!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
        else if(memberContainer[i].memberID == ID) {
            cout << "Validated!\n";
            //need to add other options such as if they are valid but owe money
        }
        else {
            cout << "Error: Member was not found with the associated ID!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
    }
}

void Member::memberController(vector<newMember> &container, struct newMember *newestMember) {
    container.push_back(*newestMember);
}

void Member::printMemberList() {
    for(int i = 0; i < memberContainer.size(); i++) {
        if(memberContainer.empty()) {
            cout << "Unfortunately there are no members as of this time in the system!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
        else {
            for(int i = 0; i < memberContainer.size(); i++) {
              cout << memberContainer[i].memberID << "#" << memberContainer[i].memberName << "#"
                      << memberContainer[i].memberStreetAddress << "#" << memberContainer[i].memberCity 
                       << "#" << memberContainer[i].memberState << "#" << memberContainer[i].memberZipCode << "#";
              cout << endl;
            }
        }
    }
}

class Provider {
public:
    struct newProvider {
        int providerID;
        char providerName;
        char providerStreetAddress;
        char providerCity;
        char providerState;
        int providerZipCode;
    };
    newProvider newestProvider;
    newProvider *providerPointer;
    vector<newProvider> providerContainer;
    string verifyProvider(int ID);
    void providerController(vector<newProvider> &providerContainer, struct newProvider *newestProvider);
    void printProviderList();
    Provider(void) {};
    Provider(int &ID, char name, char streetAddress, char city, char state, int &zipCode) {
        providerPointer = &newestProvider;
        (*providerPointer).providerID = ID;
        (*providerPointer).providerName = name;
        (*providerPointer).providerStreetAddress = streetAddress;
        (*providerPointer).providerCity = city;
        (*providerPointer).providerState = state;
        (*providerPointer).providerZipCode = zipCode;
        providerController(providerContainer, providerPointer);
    }
};

string Provider::verifyProvider(int ID) {
     for(int i = 0; i < providerContainer.size(); i++) {
        if(providerContainer.empty()) {
            cout << "Unfortunately there are no providers as of this time in the system to verify!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
        else if(providerContainer[i].providerID == ID) {
            cout << "Validated!\n";
            //need to add other options such as if they are valid but owe money
        }
        else {
            cout << "Error: Provider was not found with the associated ID!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
    } 
}

void Provider::providerController(vector<newProvider> &container, struct newProvider *newestProvider) {
    container.push_back(*newestProvider);
}

void Provider::printProviderList() {
    for(int i = 0; i < providerContainer.size(); i++) {
        if(providerContainer.empty()) {
            cout << "Unfortunately there are no providers as of this time in the system!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
        else {
            for(int i = 0; i < providerContainer.size(); i++) {
                cout << providerContainer[i].providerID << "#" << providerContainer[i].providerName << "#"
                        << providerContainer[i].providerStreetAddress << "#" << providerContainer[i].providerCity 
                        << "#" << providerContainer[i].providerState << "#" << providerContainer[i].providerZipCode << "#";
                cout << endl;
            }
        }
    }
}

class Claim {
public:
    //need to change the claim structure after passing the date + time variable as one instead of separately
    struct newClaim {
        string currentDateAndTime;
        string dateServiceProvided;
        string comments;
    };
    newClaim newestClaim;
    Claim(void) {};
    Claim(string &dateAndTime, string &dateProvided, string &Comments) {
        newestClaim.currentDateAndTime = dateAndTime;
        newestClaim.dateServiceProvided = dateProvided;
        newestClaim.comments = Comments;
    }
    void submitClaim(int providerID, int memberID, string dateAndTime, string dateProvided, string Comments);
};

void Claim::submitClaim(int providerID, int memberID, string dateAndTime, string dateProvided, string Comments) {
    //need to add the functionality for the provider to submit a claim
}

class Service: public Claim, public Provider {
public:
    struct newService {
        int serviceCode;
        char name;
        double fee;
    };
    newService newestService;
    newService *servicePointer;
    vector<newService> providerDirectory;
    double lookUpFeeToBePaid(int serviceCode);
    void printProviderDirectory(vector<newService> providerDirectoryContainer);
    void createProviderDirectory(vector<newService> providerDirectoryContainer, struct newService *servicePointer);
    Service(void) {};
    Service(int &code, char serviceName, double &Fee) {
        servicePointer = &newestService;
        (*servicePointer).serviceCode = code;
        (*servicePointer).name = serviceName;
        (*servicePointer).fee = Fee;
        createProviderDirectory(providerDirectory, servicePointer);
    }
};

double Service::lookUpFeeToBePaid(int serviceCode) {
    for(int i = 0; i < providerDirectory.size(); i++) {
        if(providerDirectory.empty()) {
            cout << "There are no services listed in the provider directory at this time!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
        else if(providerDirectory[i].serviceCode = serviceCode) {
            cout << "The fee that is associated with the specific service code you entered is $"
                    << providerDirectory[i].fee;
            cout << endl;
        }
        else {
            cout << "There are no services listed in the provider directory at this time with the "
                    << "corresponding service code of " << serviceCode << endl;
            cout << "Please verify you have entered the service code correctly and try again!\n";
        }
    }
}

void Service::createProviderDirectory(vector<newService> providerDirectory, struct newService *servicePointer) {
    providerDirectory.push_back(*servicePointer);
}
void Service::printProviderDirectory(vector<newService> providerDirectory) {
    for(int i = 0; i < providerDirectory.size(); i++) {
        if(providerDirectory.empty()) {
            cout << "Unfortunately there are no providers as of this time in the system!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
        else {
            for(int i = 0; i < providerDirectory.size(); i++) {
                cout << providerDirectory[i].serviceCode << "#" << providerDirectory[i].name << "#"
                        << "$" << providerDirectory[i].fee;
                cout << endl;
            }
        }
    }
}

class Operator: public Member, public Service {
public:
    void addMember(int ID, const char *name, const char *streetAddress, const char *city, const char *state, int zipCode);
    void deleteMember(int ID);
    void updateMember(int ID, char name, char streetAddress, char city, char state, int zipCode);
    void addProvider(int ID, const char *name, const char *streetAddress, const char *city, const char *state, int zipCode);
    void deleteProvider(int ID);
    void updateProvider(int ID, char name, char streetAddress, char city, char state, int zipCode);
    void addService(int code, const char *name, double fee);
    void deleteService(int code);
    void updateService(int code, char name, double fee);
};

void Operator::addMember(int ID, const char *name, const char *streetAddress, const char *city, const char *state, int zipCode) {
    Member* newMember = new Member(ID, *name, *streetAddress, *city, *state, zipCode);
}

void Operator::deleteMember(int ID) {
    for(int i = 0; i < memberContainer.size(); i++) {
        if(memberContainer.empty()) {
            cout << "There are currently no members to delete in the system!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
        else if(memberContainer[i].memberID = ID) {
            cout << "There member will now be deleted!\n";
            memberContainer.erase(memberContainer.begin() + i);
        }
        else {
            cout << "There were no current members with the ID of " << ID << " to delete from the system!\n";
            cout << "Please check to ensure that you have entered the correct ID of the member you are trying to delete!\n";
        }
    }
}

void Operator::updateMember(int ID, char name, char streetAddress, char city, char state, int zipCode) {
    int memberID;
    cout << "\nPlease enter the ID of the member you are would like to update: ";
    cin >> memberID;
    /*now cycle through the member container to find the specified member
    once found the operator is asked which information he/she would like to update
    if no ID matches the one given to the function an error message is returned*/
}


void Operator::addProvider(int ID, const char *name, const char *streetAddress, const char *city, const char *state, int zipCode) {
    Provider* newProvider = new Provider(ID, *name, *streetAddress, *city, *state, zipCode);
}

void Operator::deleteProvider(int ID) {
    for(int i = 0; i < providerContainer.size(); i++) {
        if(providerContainer.empty()) {
            cout << "There are currently no providers to delete in the system!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
        else if(providerContainer[i].providerID = ID) {
            cout << "There member will now be deleted!\n";
            providerContainer.erase(providerContainer.begin() + i);
        }
        else {
            cout << "There were no current providers with the ID of " << ID << " to delete from the system!\n";
            cout << "Please check to ensure that you have entered the correct ID of the provider you are trying to delete!\n";
        }
    }
}

void Operator::updateProvider(int ID, char name, char streetAddress, char city, char state, int zipCode) {
    int providerID;
    cout << "\nPlease enter the ID of the provider you would like to update: ";
    cin >> providerID;
    /*now cycle through the provider container to find the specified provider
    once found the operator is asked which information he/she would like to update
    if no ID matches the one given to the function an error message is returned*/
}

void Operator::addService(int code, const char *name, double fee) {
    Service* newService = new Service(code, *name, fee);
}

void Operator::deleteService(int code) {
    for(int i = 0; i < providerDirectory.size(); i++) {
        if(providerDirectory.empty()) {
            cout << "There are currently no providers to delete in the system!\n";
            cout << "The program will now exit!\n";
            exit(0);
        }
        else if(providerDirectory[i].serviceCode = code) {
            cout << "There member will now be deleted!\n";
            providerDirectory.erase(providerDirectory.begin() + i);
        }
        else {
            cout << "There were no current services with the service code of " << code << " to delete from the system!\n";
            cout << "Please check to ensure that you have entered the correct service code of the service you are trying to delete!\n";
        }
    }
}

void Operator::updateService(int code, char name, double fee) {
    //find the specified service by code then check the directory to see what needs to be changed
}

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

class Terminal: public Operator {
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
    char *name, *streetAddress, *city, *state;
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
    newOperator.addProvider(6, "Carrel", "1200 Murchison Rd", "Fayetteville", "NC", 28301);
    newOperator.addService(883948, "Aerobics exercises", 10.20);
    newOperator.addService(11, "Aversion Therapy", 30.00);
    newOperator.addService(555, "Chocolates in excess", 100.00);
    newOperator.addService(598470, "Dietician Session", 20.50);
    newOperator.addService(22, "Yoga", 12.50);
    
    Terminal newUserInterface;
    newOperator.printMemberList();
    //newUserInterface.userInterface();
    return 0;
}

