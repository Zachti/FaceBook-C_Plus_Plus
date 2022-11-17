
#ifndef FACEBOOK_BASIC_FUNCTIONS_H
#define FACEBOOK_BASIC_FUNCTIONS_H
void PrintExitLine();
void checkMemoryAllocation(void* ptr);
void readString(char* &str);
void PrintChoices();
void performUserSelection(FaceBook &faceBook);
int findMemberByName(Member* &membersList , int &membersLogSize ,char* &name);
int findFanPageByName(FanPage* &funPageList , int& funPageLogSize ,char* &name);
void AddFanPageToList (FanPage* &funPageList , int& funPageLogSize , int& funPagePhySize, char* &name);
void AddMemberToList (Member* &membersList , int &membersLogSize , int& membersPhySize ,char* &name ,  char* &birthDate);
#endif //FACEBOOK_BASIC_FUNCTIONS_H
