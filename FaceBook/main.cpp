#include "FaceBook.h"
#include "BasicFunctions.h"

int main() {
    FaceBook faceBook;
    FaceBook::printIntro();
    while(faceBook.getActiveFaceBook()) {
        FaceBook::printMenu();
        performUserSelection(faceBook);
    }
}
