
#ifndef FACEBOOK_STATUS_H
#define FACEBOOK_STATUS_H
class Status {
    char* content;
public:
    Status(char* Content);
    char* getContent() {return content;};
    ~Status();
};
#endif //FACEBOOK_STATUS_H
