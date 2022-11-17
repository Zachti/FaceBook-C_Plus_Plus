#include "Status.h"
#include "FanPage.h"
#include "Member.h"
#include "FaceBook.h"
#include "BasicFunctions.h"

FaceBook::FaceBook(){
    membersLogSize = fanPageLogSize = EMPTY;
    membersPhySize = fanPagePhySize = BASIC_SIZE;
    membersList = (Member*)malloc(sizeof(Member));
    checkMemoryAllocation(membersList);
    fanPageList = (FanPage*)malloc(sizeof(FanPage));
    checkMemoryAllocation(fanPageList);
}

void FaceBook::printMenu(){
    cout << "This is our menu - " << endl;
    cout << "To add a friend press -  1" << endl;
    cout << "To add a fan page press - 2" << endl;
    cout << "To add a status to friend or fan page press - 3" << endl;
    cout << "To see a friend's or fan page's status press - 4" << endl;
    cout << "To see a specific friend's last 10 statuses press - 5" << endl;
    cout << "To make a friendship with another user press - 6" << endl;
    cout << "To cancel a friendship with another user press - 7" << endl;
    cout << "To add a new fan page press - 8" << endl;
    cout << "To remove a liked fan page press - 9" << endl;
    cout << "To see all the users that currently registered in our system press - 10" << endl;
    cout << "To see all the friends of specific user or fan page press - 11" << endl;
    cout << "To exit from our system press - 12" << endl;
    cout << "Please enter your choice: " << endl;
}

void FaceBook::adduser(){
    char* name = nullptr;
    int choice;
    char* birthDate;
    cout << "Please enter your user name: " << endl;
    readString(name);
    while(findMemberByName(membersList , membersLogSize ,name) != NOT_FOUND) {
        cout << "Sorry! that name is already used." << endl;
        cout << "Please enter another user name or return to the main menu: " << endl;
        cout << "press 1 to insert another fan page or 0 to return to the main menu" << endl;
        cin >> choice;
        if (choice == 0) {
            PrintExitLine();
            return;
        }
        cout << "Please enter your fan page name: " << endl;
        readString(name);
    }
    birthDate = (char*)malloc(sizeof(char) * DATE);
    cout << "Please enter your date of birth.format:(dd/mm/yyyy)" << endl;
    cin.getline(birthDate , DATE -1) ;
    birthDate[DATE - 1] = '\0';
    AddMemberToList(membersList , membersLogSize , membersPhySize , name , birthDate);
    PrintExitLine();
}

void FaceBook::addFanPage(){
    int choice;
    char* name = nullptr;
    cout << "Please enter your fan page name: " << endl;
    readString(name);
    while(findFanPageByName(fanPageList , fanPageLogSize ,name) != NOT_FOUND) {
        cout << "Sorry! that name is already used." << endl;
        cout << "Please enter another fan page name or return to the main menu: " << endl;
        cout << "press 1 to insert another fan page or 0 to return to the main menu" << endl;
        cin >> choice;
        if (choice == 0) {
            PrintExitLine();
            return;
        }
        cout << "Please enter your fan page name: " << endl;
        readString(name);
    }
    AddFanPageToList(fanPageList , fanPageLogSize ,fanPagePhySize ,name);
    cout << "Your fan page has been created!" << endl;
    PrintExitLine();
}

void FaceBook::addStatus() {
    int index , choice = 0, returnToMenuChoice;
    char* content = nullptr, *friendName = nullptr, *fanPageName = nullptr;
    while (choice != MEMBER && choice != FAN_PAGE && choice != RETURN_MAIN_PAGE)
    {
        cout << "Do you wish to add status to a friend or fan page?" <<endl;
        PrintChoices();
        cin >> choice;
    }
    if (choice == MEMBER){
        if (membersLogSize == 0)
        {
            cout << "There are no users" << endl;
            PrintExitLine();
            return;
        } else {
            cout << "Please enter the name of the friend: " << endl;
            readString(friendName);
            index = findMemberByName(membersList, membersLogSize, friendName);
            while (index == NOT_FOUND) {
                cout << "Sorry! this user is not exist in our system";
                cout << "Please enter another user name or return to the main menu: " << endl;
                cout << "press 1 to insert another user name or 0 to return to the main menu" << endl;
                cin >> returnToMenuChoice;
                if (returnToMenuChoice == 0) {
                    PrintExitLine();
                    return;
                }
                cout << "Please enter the name of the friend: " << endl;
                readString(friendName);
                index = findMemberByName(membersList, membersLogSize, friendName);
            }
                cout << "Please enter the content of the status: " << endl;
                readString(content);
                Status status = Status(content);
                membersList[index].addStatus(status);
                PrintExitLine();
        }
    }
    else if (choice == FAN_PAGE) {
        if (fanPageLogSize == 0) {
            cout << "There are no fan pages" << endl;
            PrintExitLine();
            return;
        } else {
            cout << "Please enter the name of the fan page: " << endl;
            readString(fanPageName);
            index = findFanPageByName(fanPageList, fanPageLogSize, fanPageName);
            while (index == NOT_FOUND) {
                cout << "Sorry! this fan page is not exist in our system";
                cout << "Please enter another fan page name or return to the main menu: " << endl;
                cout << "press 1 to insert another fan page name or 0 to return to the main menu" << endl;
                cin >> returnToMenuChoice;
                if (returnToMenuChoice == 0) {
                    PrintExitLine();
                    return;
                }
                cout << "Please enter the name of the fan page: " << endl;
                readString(fanPageName);
                index = findFanPageByName(fanPageList, fanPageLogSize, fanPageName);
            }
                cout << "Please enter the content of the status: " << endl;
                readString(content);
                Status status = Status(content);
                fanPageList[index].addStatus(status);
                PrintExitLine();
        }
    }
    else {
        PrintExitLine();
    }
}

void FaceBook::showStatus(){
    int choice = 0 , index , returnToMenuChoice;
    char *friendName = nullptr, *fanPageName = nullptr;
    while (choice != MEMBER && choice != FAN_PAGE && choice != RETURN_MAIN_PAGE)
    {
        cout << "Do you wish to see all of the statuses of a friend or a fan page?" <<endl;
        PrintChoices();
        cin >> choice;
    }
    if (choice == MEMBER){
        if (membersLogSize == 0)
        {
            cout << "There are no users" << endl;
            PrintExitLine();
            return;
        }
        cout << "Please enter the name of the friend: " << endl;
        readString(friendName);
        index = findMemberByName(membersList , membersLogSize ,friendName);
        while(index == NOT_FOUND) {
            cout << "Sorry! this user is not exist in our system";
            cout << "Please enter another user name or return to the main menu: " << endl;
            cout << "press 1 to insert another user name or 0 to return to the main menu" << endl;
            cin >> returnToMenuChoice;
            if (returnToMenuChoice == 0) {
                PrintExitLine();
                return;
            }
            cout << "Please enter the name of the friend: " << endl;
            readString(friendName);
            index = findMemberByName(membersList , membersLogSize ,friendName);
        }
            cout << "Here are all of the statuses of: " << membersList[index].getName() << " - " << endl;
            membersList[index].printAllStatuses();
    }
    else if (choice == FAN_PAGE) {
        if (fanPageLogSize == 0)
        {
            cout << "There are no fan pages" << endl;
            PrintExitLine();
            return;
        }
        cout << "Please enter the name of the fan page: " << endl;
        readString(fanPageName);
        index = findFanPageByName(fanPageList , fanPageLogSize ,fanPageName);
        while(index == NOT_FOUND) {
            cout << "Sorry! this fan page is not exist in our system";
            cout << "Please enter another fan page name or return to the main menu: " << endl;
            cout << "press 1 to insert another fan page or 0 to return to the main menu" << endl;
            cin >> returnToMenuChoice;
            if (returnToMenuChoice == 0) {
                PrintExitLine();
                return;
            }
            cout << "Please enter the name of the fan page: " << endl;
            readString(fanPageName);
            index = findFanPageByName(fanPageList , fanPageLogSize ,fanPageName);
            }
            cout << "Here are all of the statuses of: " << fanPageList[index].getName() << " - " << endl;
            fanPageList[index].printAllStatuses();
    }
        PrintExitLine();
}

void FaceBook::show10status() {
    char *friendName = nullptr, *userName = nullptr;
    int index1, index2, choice;
    if (membersLogSize == 0) {
        cout << "There are no users" << endl;
        PrintExitLine();
        return;
    }
    cout << "Please enter your name: " << endl;
    readString(userName);
    index1 = findMemberByName(membersList, membersLogSize, userName);
    while (index1 == NOT_FOUND) {
        cout << "Sorry! you are not registered in our system!" << endl;
        cout << "Please register first or try another user name" << endl;
        cout << "press 1 to insert another user name or 0 to return to the main menu" << endl;
        cin >> choice;
        if (choice == 0) {
            PrintExitLine();
            return;
        }
    }
    cout << "please enter your friend name: " << endl;
    readString(friendName);
    index2 = findMemberByName(membersList, membersLogSize, friendName);
    while (index2 == NOT_FOUND) {
        cout << "Sorry! your friend is not registered in our system!" << endl;
        cout << "Please try another user name or return to the main menu" << endl;
        cout << "press 1 to insert another user name or 0 to return to the main menu" << endl;
        cin >> choice;
        if (choice == 0) {
            PrintExitLine();
            return;
        }
    }
    if (membersList[index1].checkIfWeAreFriends(membersList[index2].getName())) {
        membersList[index2].printLastFriendsStatuses();
    } else {
        cout << "Sorry! you are not friends , please add " << membersList[index2].getName() << " as a friend first!"
             << endl;
    }
    PrintExitLine();
}

void FaceBook::friendship(int remove) {
    char *userName = nullptr, *friendName = nullptr;
    int index1, index2, choice;
    if (membersLogSize <= 1) {
        cout << "not enough users" << endl;
        return;
    }
    cout << "Please enter your name: " << endl;
    readString(userName);
    index1 = findMemberByName(membersList, membersLogSize, userName);
    while (index1 == NOT_FOUND) {
        cout << "Sorry! you are not registered in our system!" << endl;
        cout << "Please register first or try another user name" << endl;
        cout << "press 1 to insert another user name or 0 to return to the main menu" << endl;
        cin >> choice;
        if (choice == 0) {
            PrintExitLine();
            return;
        }
    }
    cout << "please enter the other user name: " << endl;
    readString(friendName);
    index2 = findMemberByName(membersList, membersLogSize, friendName);
    while (index2 == NOT_FOUND) {
        cout << "Sorry! the other user name is not registered in our system!" << endl;
        cout << "Please try another user name or return to the main menu" << endl;
        cout << "press 1 to insert another user name or 0 to return to the main menu" << endl;
        cin >> choice;
        if (choice == 0) {
            PrintExitLine();
            return;
        }
    }
    if (remove == REMOVE) {
        if (membersList[index1].checkIfWeAreFriends(membersList[index2].getName())) {
            membersList[index1].removeFriend(membersList[index2]);
            cout << "You are not friends now!" << endl;
        } else {
            cout << "You are not even friends!" << endl;
        }
    } else {
        if (membersList[index1].checkIfWeAreFriends(membersList[index2].getName())) {
            cout << "You are already friends!" << endl;
        } else {
            membersList[index1].addFriend(membersList[index2]);
            cout << "You are friends now!" << endl;
        }
    }
    PrintExitLine();
}

void FaceBook::AddOrRemoveFanPage(int dislike) {
    char *userName = nullptr, *fanPageName = nullptr;
    int index1 , index2 , choice;
    if (fanPageLogSize == 0 || membersLogSize == 0)
    {
        cout << "not enough users or fan pages" << endl;
        return;
    }
    cout << "Please enter your name: " << endl;
    readString(userName);
    index1 = findMemberByName(membersList , membersLogSize ,userName);
    while (index1 == NOT_FOUND) {
        cout << "Sorry! you are not registered in our system!" << endl;
        cout << "Please register first or try another user name" << endl;
        cout << "press 1 to insert another user name or 0 to return to the main menu" << endl;
        cin >> choice;
        if (choice == 0) {
            PrintExitLine();
            return;
        }
    }
    cout << "please enter the fan page name: " << endl;
    readString(fanPageName);
    index2 = findFanPageByName(fanPageList , fanPageLogSize ,fanPageName);
        while (index2 == NOT_FOUND) {
            cout << "Sorry! this fan page is not registered in our system!" << endl;
            cout << "Please try another fan page name or return to the main menu" << endl;
            cout << "press 1 to insert another fan page name or 0 to return to the main menu" << endl;
            cin >> choice;
            if (choice == 0) {
                PrintExitLine();
                return;
            }
        }
    if (dislike == DISLIKE) {
        membersList[index1].removeFanPage(fanPageList[index2]);
        cout << "Your like have been removed now from this fan page!" << endl;
        PrintExitLine();
    } else {
        membersList[index1].addFanPage(fanPageList[index2]);
        cout << "You are connected to this fan page now!" << endl;
        PrintExitLine();
    }
}

void FaceBook::ShowAllEntities() {
    cout << "This are all the users that sign in to our system: " << endl;
    for (int i = 0; i < membersLogSize; ++i) {
        cout << membersList[i].getName() << endl;
    }
    cout << "This are all the fan pages that sign in to our system: " << endl;
    for (int i = 0; i < fanPageLogSize; ++i) {
        cout << fanPageList[i].getName() << endl;
    }
    PrintExitLine();
}

void FaceBook::ShowMembers() {
    int index , choice = 0, returnToMenuChoice;
    char *memberName = nullptr, *fanPageName = nullptr;
    while (choice != MEMBER && choice != FAN_PAGE && choice != RETURN_MAIN_PAGE)
    {
        PrintChoices();
        cin >> choice;
    }
    if (choice == MEMBER) {
        cout << "Please enter the name of the user: " << endl;
        readString(memberName);
        index = findMemberByName(membersList, membersLogSize, memberName);
        while (index == NOT_FOUND) {
            cout << "Sorry! this user is not exist in our system";
            cout << "Please try another user name or return to the main menu" << endl;
            cout << "press 1 to insert another user name or 0 to return to the main menu" << endl;
            cin >> returnToMenuChoice;
            if (returnToMenuChoice == 0) {
                PrintExitLine();
                return;
            }
        }
        cout << "This are all the friends of " << membersList[index].getName() << ": " << endl;
        for (int i = 0; i < membersList[index].getFriendsNum(); ++i) {
            cout << membersList[index].getFriendsArr()[i].getName();
        }
    } else if (choice == FAN_PAGE) {
        cout << "Please enter the name of the fan page: " << endl;
        readString(fanPageName);
        index = findFanPageByName(fanPageList, fanPageLogSize, fanPageName);
        while (index == NOT_FOUND) {
            cout << "Sorry! this fan page is not registered in our system!" << endl;
            cout << "Please try another fan page name or return to the main menu" << endl;
            cout << "press 1 to insert another page name or 0 to return to the main menu" << endl;
            cin >> returnToMenuChoice;
            if (returnToMenuChoice == 0) {
                PrintExitLine();
                return;
            }
        }
        cout << "This are all the users that connect to" << fanPageList[index].getName() << ": " << endl;
        for (int i = 0; i < fanPageList[index].getFriendsNum(); ++i) {
            cout << fanPageList[index].getFriendsArr()[i].getName();
        }
    }
    PrintExitLine();
}

void FaceBook::Exit() {
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



