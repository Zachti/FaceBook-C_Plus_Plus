#include "Status.h"
#include "FanPage.h"
#include "Member.h"
#include "FaceBook.h"
#include "BasicFunctions.h"

FanPage::FanPage(char *Name) {
    name = (char*) malloc(strlen(Name)+1);
    strcpy(name,Name);
    friendsArr = (Member**)malloc(sizeof(Member*));
    checkMemoryAllocation(friendsArr);
    BulletinBoard =(Status*) malloc(sizeof(Status));
    checkMemoryAllocation(BulletinBoard);
    friendsLogSize = bulletinBoardLogSize = EMPTY;
    friendsPhySize = bulletinBoardPhySize = BASIC_SIZE;
}

void FanPage::addFriend(Member* member){
    if (friendsLogSize == friendsPhySize) {
        friendsPhySize *= 2;
        friendsArr = (Member**) realloc(friendsArr, (sizeof(Member*) * friendsPhySize));
        checkMemoryAllocation(friendsArr);
    }
    friendsArr[friendsLogSize] = (Member*)malloc(sizeof(Member));
    checkMemoryAllocation(friendsArr[friendsLogSize]);
    friendsArr[friendsLogSize++] = member;
}

void  FanPage::removeFriend(Member* member){
    for (int i = 0; i < friendsLogSize; i++) {
        if (strcmp(friendsArr[i]->getName(), member->getName()) == 0) {
            swap(*friendsArr[i], *friendsArr[friendsLogSize - 1]);
            free(friendsArr[friendsLogSize - 1]);
        }
        friendsLogSize--;
    }
}

void FanPage::addStatus(Status &status){
    if (bulletinBoardLogSize == bulletinBoardPhySize) {
        bulletinBoardPhySize *= 2;
        BulletinBoard = (Status *)realloc(BulletinBoard, (sizeof(Status) * bulletinBoardPhySize));
        checkMemoryAllocation(BulletinBoard);
    }
    BulletinBoard[bulletinBoardLogSize++] = status;
}

void FanPage::printAllStatuses() {
    for (int i = 0; i < bulletinBoardLogSize; i++) {
        cout << BulletinBoard[i].getContent();
    }
}

FanPage::~FanPage() {
    free(name);
    free(BulletinBoard);
    for (int i = 0; i < friendsLogSize; ++i) {
        free(friendsArr[i]);
    }
    free(friendsArr);
}

