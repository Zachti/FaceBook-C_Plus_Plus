#include "Status.h"
#include "FanPage.h"
#include "Member.h"
#include "FaceBook.h"
#include "BasicFunctions.h"


Member::Member(char* &Name, char* &BirthDate) {
    name = (char*) malloc(strlen(Name)+1);
    strcpy(name, Name);
    strcpy(birthDate , BirthDate);
    friendsArr = (Member*)malloc(sizeof(Member));
    checkMemoryAllocation(friendsArr);
    fanPagesArr = (FanPage *)malloc(sizeof(FanPage));
    checkMemoryAllocation(fanPagesArr);
    BulletinBoard = (Status*)malloc(sizeof (Status));
    checkMemoryAllocation(BulletinBoard);
    friendsLogSize = fanPagesLogSize =  bulletinBoardLogSize =  EMPTY;
    friendsPhySize = fanPagesPhySize = bulletinBoardPhySize = BASIC_SIZE;
}

void Member::addFanPage(FanPage& fanPage){
    if (fanPagesLogSize == fanPagesPhySize) {
        fanPagesPhySize *= 2;
        fanPagesArr = (FanPage*) realloc(fanPagesArr, (sizeof(FanPage) * fanPagesPhySize));
        checkMemoryAllocation(fanPagesArr);
    }
    fanPagesArr[fanPagesLogSize++] = fanPage;
    fanPage.addFriend(this);
}

void Member::removeFanPage(FanPage &fanPage){
    for (int i = 0; i < fanPagesLogSize; i++) {
        if (strcmp(fanPagesArr[i].getName(), fanPage.getName()) == 0) {
            swap(fanPagesArr[i], fanPagesArr[fanPagesLogSize - 1]);
        }
        fanPagesLogSize--;
    }
    fanPage.removeFriend(this);
}

void Member::printFanPages() const{
    cout << "Your liked fan pages are: " << endl;
    for (int i = 0; i < fanPagesLogSize; ++i) {
        cout << fanPagesArr[i].getName() << endl;
    }
}

void Member::addStatus(Status &status){
    if (bulletinBoardLogSize == bulletinBoardPhySize) {
        bulletinBoardPhySize *= 2;
        BulletinBoard = (Status *) realloc(BulletinBoard, (sizeof(Status) * bulletinBoardPhySize));
        checkMemoryAllocation(BulletinBoard);
    }
    BulletinBoard[bulletinBoardLogSize++] = status;
}

void Member::addFriend(Member &member){
    if (this->checkIfWeAreFriends(member.getName())){
        return;
    }

    if (friendsLogSize == friendsPhySize) {
        friendsPhySize *= 2;
        friendsArr = (Member *) realloc(friendsArr, (sizeof(Member) * friendsPhySize));
        checkMemoryAllocation(friendsArr);
    }
    friendsArr[friendsLogSize++] = member;
    member.addFriend(*this);
}

void Member::removeFriend(Member &member){
    if (!(this->checkIfWeAreFriends(member.getName()))){
        return;
    }

    for (int i = 0; i < friendsLogSize; i++) {
        if (!strcmp(friendsArr[i].name, member.name)) {
            swap(friendsArr[i], friendsArr[friendsLogSize - 1]);
        }
        friendsLogSize--;
    }
    member.removeFriend(*this);
}

void Member::printLastFriendsStatuses() {
    for (int i = 0; i<friendsLogSize ; i++) {
        cout << "The 10 most recent Statuses of " << friendsArr[i].getName() <<": " << endl;
        Status* temp = friendsArr[i].getBulletinBoard();
        for (int j = friendsArr[i].getStatusNum() - LAST_TEN; j < friendsArr[i].getStatusNum(); j++) {
            cout << temp[j].getContent();
        }
    }
}

void Member::printAllStatuses() {
    for (int i = 0; i < bulletinBoardLogSize; i++) {
        cout << BulletinBoard[i].getContent();
    }
}

bool Member::checkIfWeAreFriends(char* Name) {
    for (int i = 0; i < friendsLogSize; i++) {
        if (!strcmp(friendsArr[i].getName(), Name)) {
            return true;
        }
    }
    return false;
}

Member::~Member() {
    free(name);
    free(friendsArr);
    free(fanPagesArr);
    free(BulletinBoard);
}




