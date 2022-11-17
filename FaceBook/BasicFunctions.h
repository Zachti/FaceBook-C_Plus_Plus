
#ifndef FACEBOOK_BASIC_FUNCTIONS_H
#define FACEBOOK_BASIC_FUNCTIONS_H
void PrintExitLine();
void checkMemoryAllocation(void* ptr);
void readString(char* str);
void PrintWrongChoice();
void performUserSelection(FaceBook &faceBook);
int findMemberByName(Member* &membersList , int &membersListSize , const char* name);
int findFunPageByName(FanPage* &funPageList , int& funPageListSize , const char* name);
void AddFunPageToList (FanPage* &funPageList , int& funPageListSize , int& maxFunPageListSize, char* &name);
void AddMemberToList (Member* &membersList , int &membersListSize , int& maxMembersListSize ,char* &name ,  BirthDate &birthDate);
#endif //FACEBOOK_BASIC_FUNCTIONS_H
