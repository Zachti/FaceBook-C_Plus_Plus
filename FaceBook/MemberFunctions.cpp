#include "Status.h"
#include "FanPage.h"
#include "Member.h"
#include "FaceBook.h"
#include "BasicFunctions.h"


Member::Member(char *Name, BirthDate birthDate1) {
    name = (char*) malloc(strlen(Name)+1);
    strcpy(name, Name);
    birthDate = birthDate1;
    friendsArr = (Member*)malloc(sizeof(Member));
    checkMemoryAllocation(friendsArr);
    funPagesArr = (FanPage *)malloc(sizeof(FanPage));
    checkMemoryAllocation(funPagesArr);
    BulletinBoard = (Status*)malloc(sizeof (Status));
    checkMemoryAllocation(BulletinBoard);
    friendsNum = EMPTY;
    maxFriendsNum = BASIC_SIZE;
    funPagesNum = EMPTY;
    maxFunPagesNum = BASIC_SIZE;
    statusesNum = EMPTY;
    maxStatusesNum = BASIC_SIZE;
}

void Member::addFunPage(FanPage& funPage){
    if (funPagesNum == maxFunPagesNum) {
        maxFunPagesNum *= 2;
        funPagesArr = (FanPage*) realloc(funPagesArr, (sizeof(FanPage) * maxFunPagesNum));
        checkMemoryAllocation(funPagesArr);
    }
    funPagesArr[funPagesNum++] = funPage;
    funPage.addFriend(this);
}

void Member::removeFunPage(FanPage &funPage){
    for (int i = 0; i < funPagesNum; i++) {
        if (strcmp(funPagesArr[i].getName(), funPage.getName()) == 0) {
            swap(funPagesArr[i], funPagesArr[funPagesNum - 1]);
        }
        funPagesNum--;
    }
    funPage.removeFriend(this);
}

void Member::printFunPages() const{
    cout << "Your liked fun pages are: " << endl;
    for (int i = 0; i < funPagesNum; ++i) {
        cout << funPagesArr[i].getName() << endl;
    }
}

void Member::addStatus(Status &status){
    if (statusesNum == maxStatusesNum) {
        maxStatusesNum *= 2;
        BulletinBoard = (Status *) realloc(BulletinBoard, (sizeof(Status) * maxStatusesNum));
        checkMemoryAllocation(BulletinBoard);
    }
    BulletinBoard[statusesNum++] = status;
}

void Member::addFriend(Member &member){
    if (this->checkIfWeAreFriends(member.getName())){
        return;
    }

    if (friendsNum == maxFriendsNum) {
        maxFriendsNum *= 2;
        friendsArr = (Member *) realloc(friendsArr, (sizeof(Member) * maxFriendsNum));
        checkMemoryAllocation(friendsArr);
    }
    friendsArr[friendsNum++] = member;
    member.addFriend(*this);
}

void Member::removeFriend(Member &member){
    if (!(this->checkIfWeAreFriends(member.getName()))){
        return;
    }

    for (int i = 0; i < friendsNum; i++) {
        if (!strcmp(friendsArr[i].name, member.name)) {
            swap(friendsArr[i], friendsArr[friendsNum - 1]);
        }
        friendsNum--;
    }
    member.removeFriend(*this);
}

void Member::printLastFriendsStatuses() {
    for (int i = 0; i<friendsNum ; i++) {
        cout << "The 10 most recent Statuses of " << friendsArr[i].getName() <<": " << endl;
        Status* temp = friendsArr[i].getBulletinBoard();
        for (int j = friendsArr[i].getStatusNum() - LAST_TEN; j < friendsArr[i].getStatusNum(); j++) {
            cout << temp[j].getContent();
        }
    }
}

void Member::printAllStatuses() {
    for (int i = 0; i < statusesNum; i++) {
        cout << BulletinBoard[i].getContent();
    }
}

bool Member::checkIfWeAreFriends(char* Name) {
    for (int i = 0; i < friendsNum; i++) {
        if (!strcmp(friendsArr[i].getName(), Name)) {
            return true;
        }
    }
    return false;
}

Member::~Member() {
    free(name);
    free(friendsArr);
    free(funPagesArr);
    free(BulletinBoard);
}




