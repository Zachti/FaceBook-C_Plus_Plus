#include "Status.h"
#include "FaceBook.h"

Status::Status(char* Content) {
    content = (char*) malloc(strlen(Content)+1);
    strcpy(content,Content);
}

Status::~Status() {
    free(content);
}