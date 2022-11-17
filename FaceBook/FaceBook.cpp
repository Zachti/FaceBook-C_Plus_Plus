#include "Status.h"
#include "FanPage.h"
#include "Member.h"
#include "FaceBook.h"
#include "BasicFunctions.h"

FaceBook::FaceBook(){
    membersListSize = fanPageListSize = EMPTY;
    maxMembersListSize = maxFanPageListSize = BASIC_SIZE;
    membersList = (Member*)malloc(sizeof(Member));
    checkMemoryAllocation(membersList);
    fanPageList = (FanPage*)malloc(sizeof(FanPage));
    checkMemoryAllocation(fanPageList);
}

void FaceBook::printMenu(){
    cout << "This is our menu - " << endl;
    cout << "To add a friend press 1" << endl;
    cout << "To add a fun page press 2" << endl;
    cout << "To add a status to friend or fun page press 3" << endl;
    cout << "To see a friend's or fun page's status press 4" << endl;
    cout << "To see a specific friend's last 10 statuses press 5" << endl;
    cout << "To make a friendship with another user press 6" << endl;
    cout << "To cancel a friendship with another user press 7" << endl;
    cout << "To add a new fun page press 8" << endl;
    cout << "To remove a liked fun page press 9" << endl;
    cout << "To see all the users that currently registered in our system press 10" << endl;
    cout << "To see all the friends of specific user or fun page press 11" << endl;
    cout << "To exit from our system press 12" << endl;
    cout << "Please enter your choice: " << endl;
}

void FaceBook::PerformOptionOne(){
    char* name = nullptr;
    int choice;
    BirthDate birthDate = {0,MONTH::JAN,0};
    cout << "Please enter your user name: " << endl;
    readString(name);
    while(findMemberByName(membersList , membersListSize ,name) != NOT_FOUND) {
        cout << "Sorry! that name is already used." << endl;
        cout << "Please enter your fun page name: " << endl;
        readString(name);
    }
    cout << "Please enter your birth day: " << endl;
    cin >> birthDate.BirthDay;
    cout << "Please enter your birth month: " << endl;
    cin >> choice;
    birthDate.BirthMonth = (MONTH)choice;
    cout << "Please enter your birth year: " << endl;
    cin >> birthDate.BirthYear;
    AddMemberToList(membersList , membersListSize , maxMembersListSize , name , birthDate);


}

void FaceBook::PerformOptionTwo(){
    char* name = nullptr;
    cout << "Please enter your fun page name: " << endl;
    readString(name);
    while(findFunPageByName(fanPageList , fanPageListSize ,name) != NOT_FOUND) {
        cout << "Sorry! that name is already used." << endl;
        cout << "Please enter your fun page name: " << endl;
        readString(name);
    }
    AddFunPageToList(fanPageList , fanPageListSize ,maxFanPageListSize ,name);
    cout << "Your fun page has been created!" << endl;
    PrintExitLine();
}

void FaceBook::PerformOptionThree() {
    int index , choice;
    char* content = nullptr, *friendName = nullptr, *funPageName = nullptr;
    cout << "Do you wish to add status to a friend or fun page?" <<endl;
    cout << "enter 1 for a friend or 0 for fun page" << endl;
    cin >> choice;
    if (choice == 1){
        cout << "Please enter the name of the friend: " << endl;
        readString(friendName);
        index = findMemberByName(membersList , membersListSize ,friendName);
        if(index == NOT_FOUND) {
            cout << "Sorry! this member is not exist in our system";
            PrintExitLine();
        } else {
            cout << "Please enter the content of the status: " << endl;
            readString(content);
            Status status = {content};
            membersList[index].addStatus(status);
            PrintExitLine();
        }
    }
    else if (choice == 0) {
        cout << "Please enter the name of the fun page: " << endl;
        readString(funPageName);
        index = findFunPageByName(fanPageList , fanPageListSize ,funPageName);
        if(index == NOT_FOUND) {
            cout << "Sorry! this fun page is not exist in our system";
            PrintExitLine();
        } else {
            cout << "Please enter the content of the status: " << endl;
            readString(content);
            Status status = {content};
            fanPageList[index].addStatus(status);
            PrintExitLine();
        }
    }
    else {
        PrintWrongChoice();
        PrintExitLine();
    }
}

void FaceBook::PerformOptionFour(){
    int choice , index;
    char *friendName = nullptr, *funPageName = nullptr;
    cout << "Do you wish to see all of the statuses of a friend or a fun page?" <<endl;
    cout << "enter 1 for a friend or 0 for fun page" << endl;
    cin >> choice;
    if (choice == 1){
        cout << "Please enter the name of the friend: " << endl;
        readString(friendName);
        index = findMemberByName(membersList , membersListSize ,friendName);
        if(index == NOT_FOUND) {
            cout << "Sorry! this member is not exist in our system";
            PrintExitLine();
        } else {
            cout << "Here are all of the statuses of: " << membersList[index].getName() << " - " << endl;
            membersList[index].printAllStatuses();
            PrintExitLine();
        }
    }
    else if (choice == 0) {
        cout << "Please enter the name of the fun page: " << endl;
        readString(funPageName);
        index = findFunPageByName(fanPageList , fanPageListSize ,funPageName);
        if(index == NOT_FOUND) {
            cout << "Sorry! this fun page is not exist in our system";
            PrintExitLine();
        } else {
            cout << "Here are all of the statuses of: " << fanPageList[index].getName() << " - " << endl;
            fanPageList[index].printAllStatuses();
            PrintExitLine();
        }
    }
    else {
        PrintWrongChoice();
        PrintExitLine();
    }
}

void FaceBook::PerformOptionFive() {
    char *friendName = nullptr , *userName = nullptr;
    int index1 , index2;
    cout << "Please enter your name: " << endl;
    readString(userName);
    cout << "please enter your friend name: " << endl;
    readString(friendName);
    index1 = findMemberByName(membersList , membersListSize ,userName);
    index2 = findMemberByName(membersList , membersListSize ,friendName);
    if (index1 != NOT_FOUND && index2 != NOT_FOUND) {
        if (membersList[index1].checkIfWeAreFriends(membersList[index2].getName())) {
            membersList[index2].printLastFriendsStatuses();
        } else {
            cout << "Sorry! you are not friends , please add " << membersList[index2].getName() << " as a friend first!"
                 << endl;
            PrintExitLine();
        }
    } else {
        if (index2 != NOT_FOUND)
            cout << "The first user name is not exist in our system!" << endl;
        if (index1 != NOT_FOUND)
            cout << "The second user page is not exist in our system!" << endl;
        PrintExitLine();
    }
}

void FaceBook::PerformOptionSix() {
    char *userName = nullptr, *friendName = nullptr;
    int index1, index2;
    cout << "Please enter your name: " << endl;
    readString(userName);
    cout << "please enter your friend name: " << endl;
    readString(friendName);
    index1 = findMemberByName(membersList , membersListSize ,userName);
    index2 = findMemberByName(membersList , membersListSize ,friendName);
    if (index1 != NOT_FOUND && index2 != NOT_FOUND) {
        if (membersList[index1].checkIfWeAreFriends(membersList[index2].getName())) {
            cout << "You are already friends!" << endl;
            PrintExitLine();
        } else {
            membersList[index1].addFriend(membersList[index2]);
            cout << "You are friends now!" << endl;
            PrintExitLine();
        }
    } else {
        if (index1 != NOT_FOUND)
            cout << "The user name is not exist in our system!" << endl;
        if (index2 != NOT_FOUND)
            cout << "The fun page is not exist in our system!" << endl;
        PrintExitLine();
    }
}

void FaceBook::PerformOptionSeven() {
    char *userName = nullptr, *friendName = nullptr;
    int index1, index2;
    cout << "Please enter your name: " << endl;
    readString(userName);
    cout << "please enter your friend's name: " << endl;
    readString(friendName);
    index1 = findMemberByName(membersList , membersListSize ,userName);
    index2 = findMemberByName(membersList , membersListSize ,friendName);
    if (index1 != NOT_FOUND && index2 != NOT_FOUND) {
        if (membersList[index1].checkIfWeAreFriends(membersList[index2].getName())) {
            membersList[index1].removeFriend(membersList[index2]);
            cout << "You are not friends now!" << endl;
            PrintExitLine();
        }
        else {
            cout << "You are not even friends!" << endl;
            PrintExitLine();
        }
    } else {
        if (index2 != NOT_FOUND)
            cout << "The first user name is not exist in our system!" << endl;
        if (index1 != NOT_FOUND)
            cout << "This second user name is not exist in our system!" << endl;
        PrintExitLine();
    }
}

void FaceBook::PerformOptionEight() {
    char *userName = nullptr, *funPageName = nullptr;
    int index1 , index2;
    cout << "Please enter your name: " << endl;
    readString(userName);
    cout << "please enter the fun page name: " << endl;
    readString(funPageName);
    index1 = findMemberByName(membersList , membersListSize ,userName);
    index2 = findFunPageByName(fanPageList , fanPageListSize ,funPageName);
    if (index1 != NOT_FOUND && index2 != NOT_FOUND) {
        membersList[index1].addFunPage(fanPageList[index2]);
        cout << "You are connected to this fun page now!" << endl;
        PrintExitLine();
    }
    else {
        if (index2 != NOT_FOUND)
            cout << "The user name is not exist in our system!" << endl;
        if (index1 != NOT_FOUND)
            cout << "This fun page is not exist in our system!" << endl;
        PrintExitLine();
    }
}

void FaceBook::PerformOptionNine(){
    char *userName = nullptr, *funPageName = nullptr;
    int index1 , index2;
    cout << "Please enter your name: " << endl;
    readString(userName);
    cout << "please enter the fun page name: " << endl;
    readString(funPageName);
    index1 = findMemberByName(membersList , membersListSize ,userName);
    index2 = findFunPageByName(fanPageList , fanPageListSize ,funPageName);
    if (index1 != NOT_FOUND && index2 != NOT_FOUND) {
        membersList[index1].removeFunPage(fanPageList[index2]);
        cout << "You have been removed now from this fun page!" << endl;
        PrintExitLine();
    }
    else {
        if (index2 != NOT_FOUND)
            cout << "The user name is not exist in our system!" << endl;
        if (index1 != NOT_FOUND)
            cout << "This fun page is not exist in our system!" << endl;
        PrintExitLine();
    }
}

void FaceBook::PerformOptionTen() {
    cout << "This are all the members that sign in the system: " << endl;
    for (int i = 0; i < membersListSize; ++i) {
        cout << membersList[i].getName() << endl;
    }
    cout << "This are all the fun pages that sign in the system: " << endl;
    for (int i = 0; i < fanPageListSize; ++i) {
        cout << fanPageList[i].getName() << endl;
    }
    PrintExitLine();
}

void FaceBook::PerformOptionEleven() {
    int index , choice;
    char *memberName = nullptr, *funPageName = nullptr;
    cout << "Do you wish to see all the friends of a member or a fun page?" <<endl;
    cout << "enter 1 for a member or 0 for a fun page" << endl;
    cin >> choice;
    if (choice == 1){
        cout << "Please enter the name of the member: " << endl;
        readString(memberName);
        index = findMemberByName(membersList , membersListSize ,memberName);
        if(index == NOT_FOUND) {
            cout << "Sorry! this member is not exist in our system";
            PrintExitLine();
        }
        else {
            cout << "This are all the friends of " << membersList[index].getName() << ": " <<endl;
            for (int i = 0; i < membersList[index].getFriendsNum(); ++i) {
                cout <<  membersList[index].getFriendsArr()[i].getName();
            }
            cout << "This are all the connected fun pages of " << membersList[index].getName() << ": " <<endl;
            membersList[index].printFunPages();
            PrintExitLine();
        }
    }
    else if (choice == 0) {
        cout << "Please enter the name of the fun page: " << endl;
        readString(funPageName);
        index = findFunPageByName(fanPageList , fanPageListSize ,funPageName);
        if(index == NOT_FOUND) {
            cout << "Sorry! this fun page is not exist in our system";
            PrintExitLine();
        }
        else {
            cout << "This are all the members that connect to" << fanPageList[index].getName() <<": " << endl;
            for (int i = 0; i < fanPageList[index].getFriendsNum(); ++i) {
                cout <<  fanPageList[index].getFriendsArr()[i].getName();
            }
            PrintExitLine();
        }
    }
    else {
        PrintWrongChoice();
        PrintExitLine();
    }
}

void FaceBook::PerformOptionTwelve() {
cout << "See you next time! bye!" << endl;
ActiveFaceBook = false;
}

void FaceBook::PrintWrongSelection() const {
    cout <<"You have entered a wrong number" << endl;
    cout <<"Please try again." << endl;
}

FaceBook::~FaceBook(){
    free(membersList);
    free(fanPageList);
}



