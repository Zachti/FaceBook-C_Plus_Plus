#include "Status.h"
#include "FanPage.h"
#include "Member.h"
#include "FaceBook.h"
#include "BasicFunctions.h"

FanPage::FanPage(char *Name) {
    name = (char*) malloc(strlen(Name)+1);
    strcpy(name,Name);
    friendsNum = EMPTY;
    maxFriendsNum = BASIC_SIZE;
    friendsArr = (Member**)malloc(sizeof(Member*));
    checkMemoryAllocation(friendsArr);
    statusesNum = EMPTY;
    maxStatusesNum = BASIC_SIZE;
    BulletinBoard =(Status*) malloc(sizeof(Status));
    checkMemoryAllocation(BulletinBoard);
}

void FanPage::addFriend(Member* member){
    if (friendsNum == maxFriendsNum) {
        maxFriendsNum *= 2;
        friendsArr = (Member**) realloc(friendsArr, (sizeof(Member*) * maxFriendsNum));
        checkMemoryAllocation(friendsArr);
    }
    friendsArr[friendsNum] = (Member*)malloc(sizeof(Member));
    checkMemoryAllocation(friendsArr[friendsNum]);
    friendsArr[friendsNum++] = member;
}

void  FanPage::removeFriend(Member* member){
    for (int i = 0; i < friendsNum; i++) {
        if (strcmp(friendsArr[i]->getName(), member->getName()) == 0) {
            swap(*friendsArr[i], *friendsArr[friendsNum - 1]);
            free(friendsArr[friendsNum - 1]);
        }
        friendsNum--;
    }
}

void FanPage::addStatus(Status &status){
    if (statusesNum == maxStatusesNum) {
        maxStatusesNum *= 2;
        BulletinBoard = (Status *)realloc(BulletinBoard, (sizeof(Status) * maxStatusesNum));
        checkMemoryAllocation(BulletinBoard);
    }
    BulletinBoard[statusesNum++] = status;
}

void FanPage::printAllStatuses() {
    for (int i = 0; i < statusesNum; i++) {
        cout << BulletinBoard[i].getContent();
    }
}

FanPage::~FanPage() {
    free(name);
    free(BulletinBoard);
    for (int i = 0; i < friendsNum; ++i) {
        free(friendsArr[i]);
    }
    free(friendsArr);
}

