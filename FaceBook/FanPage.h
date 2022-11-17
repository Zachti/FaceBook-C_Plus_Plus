
#ifndef FACEBOOK_FAN_PAGE_H
#define FACEBOOK_FAN_PAGE_H
class Member;
class Status;

class FanPage{
    char* name;
    Member** friendsArr;
    int friendsLogSize;
    int friendsPhySize;
    Status* BulletinBoard;
    int bulletinBoardLogSize;
    int bulletinBoardPhySize;
public:
    explicit FanPage(char *Name);
    char* getName() const {return name;};
    int getFriendsNum() const {return friendsLogSize;};
    Member* getFriendsArr() const {return *friendsArr;};
    void addFriend(Member* member);
    void removeFriend(Member* member);
    void addStatus(Status &status);
    void printAllStatuses();
    ~FanPage();
};

#endif //FACEBOOK_FAN_PAGE_H
