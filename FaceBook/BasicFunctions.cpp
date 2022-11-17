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

void readString(char* &str) {
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

void performUserSelection(FaceBook &faceBook) {

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            faceBook.adduser();
        case 2:
            faceBook.addFanPage();
        case 3:
            faceBook.addStatus();
        case 4:
            faceBook.showStatus();
        case 5:
            faceBook.show10status();
        case 6:
            faceBook.friendship();
        case 7:
            faceBook.friendship(REMOVE);
        case 8:
            faceBook.AddOrRemoveFanPage();
        case 9:
            faceBook.AddOrRemoveFanPage(DISLIKE);
        case 10:
            faceBook.ShowAllEntities();
        case 11:
            faceBook.ShowMembers();
        case 12:
            faceBook.Exit();
        default:
            faceBook.PrintWrongSelection();
            break;
    }
}

int findMemberByName(Member* &membersList , int &membersLogSize ,char* &name) {
    for (int i = 0; i <membersLogSize; ++i) {
        if (!strcmp(membersList[i].getName() , name))
            return i;
    }
    return NOT_FOUND;
}

int findFanPageByName(FanPage* &fanPageList , int& fanPageLogSize ,char* &name) {
    for (int i = 0; i < fanPageLogSize; ++i) {
        if (!strcmp(fanPageList[i].getName() , name))
            return i;
    }
    return NOT_FOUND;
}

void AddFanPageToList (FanPage* &fanPageList , int& fanPageLogSize , int& fanPagePhySize, char* &name) {
    if (fanPageLogSize == fanPagePhySize) {
        fanPagePhySize *= 2;
        fanPageList = (FanPage*)realloc(fanPageList, sizeof(FanPage) * fanPagePhySize);
        checkMemoryAllocation(fanPageList);
    }
    fanPageList[fanPageLogSize++] = FanPage(name);
}

void AddMemberToList (Member* &membersList , int &membersLogSize , int& membersPhySize ,char* &name ,  char* &birthDate) {
    if (membersLogSize == membersPhySize) {
        membersPhySize *= 2;
        membersList = (Member*)realloc(membersList, sizeof(Member) * membersPhySize);
        checkMemoryAllocation(membersList);
    }
    membersList[membersLogSize++] = Member(name , birthDate);
}

void PrintChoices() {
    cout << "1-for member" << endl;
    cout << "2-for fan page" << endl;
    cout << "3-return to main page" << endl;
}