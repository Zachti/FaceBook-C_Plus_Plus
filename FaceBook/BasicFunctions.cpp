#include "FaceBook.h"

void PrintExitLine() {
    cout << "You will return to the main menu now";
}

void checkMemoryAllocation(void* ptr) {
    if (ptr == nullptr) {
        printf("Memory allocation error");
        exit(1);
    }
}

void readString(char* str) {
    int phySize = 1 , logSize = 0;
    char c;
    str = (char*) malloc(phySize);
    checkMemoryAllocation(str);
    cin >> c;
    while(c != '\n') {
        if (logSize == phySize){
            phySize *= 2;
            str = (char*) realloc(str , phySize);
            checkMemoryAllocation(str);
        }
        str[logSize++] = c;
        cin >> c;
    }
    str[logSize++] = '\0';
    if (logSize < phySize) {
        str = (char*) realloc(str , logSize);
        checkMemoryAllocation(str);
    }
}

void PrintWrongChoice() {
    cout << "Wrong choice!" << endl;
}

void performUserSelection(FaceBook &faceBook) {

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            faceBook.PerformOptionOne();
            break;
        case 2:
            faceBook.PerformOptionTwo();
            break;

        case 3:
            faceBook.PerformOptionThree();
            break;

        case 4:
            faceBook.PerformOptionFour();
            break;

        case 5:
            faceBook.PerformOptionFive();
            break;

        case 6:
            faceBook.PerformOptionSix();
            break;

        case 7:
            faceBook.PerformOptionSeven();
            break;

        case 8:
            faceBook.PerformOptionEight();
            break;

        case 9:
            faceBook.PerformOptionNine();
            break;

        case 10:
            faceBook.PerformOptionTen();
            break;

        case 11:
            faceBook.PerformOptionEleven();
            break;

        case 12:
            faceBook.PerformOptionTwelve();
            break;

        default:
            faceBook.PrintWrongSelection();
            break;
    }
}

int findMemberByName(Member* &membersList , int &membersListSize , const char* name) {
    for (int i = 0; i <membersListSize; ++i) {
        if (!strcmp(membersList[i].getName() , name))
            return i;
    }
    return NOT_FOUND;
}

int findFunPageByName(FanPage* &funPageList , int& funPageListSize , const char* name) {
    for (int i = 0; i < funPageListSize; ++i) {
        if (!strcmp(funPageList[i].getName() , name))
            return i;
    }
    return NOT_FOUND;
}

void AddFunPageToList (FanPage* &funPageList , int& funPageListSize , int& maxFunPageListSize, char* &name) {
    if (funPageListSize == maxFunPageListSize) {
        maxFunPageListSize *= 2;
        funPageList = (FanPage*)realloc(funPageList, sizeof(FanPage) * maxFunPageListSize);
        checkMemoryAllocation(funPageList);
    }
    funPageList[funPageListSize++] = FanPage(name);
}

void AddMemberToList (Member* &membersList , int &membersListSize , int& maxMembersListSize ,char* &name ,  BirthDate &birthDate) {
    if (membersListSize == maxMembersListSize) {
        maxMembersListSize *= 2;
        membersList = (Member*)realloc(membersList, sizeof(Member) * maxMembersListSize);
        checkMemoryAllocation(membersList);
    }
    membersList[membersListSize++] = Member(name , birthDate);
}
