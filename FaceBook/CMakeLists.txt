cmake_minimum_required(VERSION 3.20)
project(FaceBook)

set(CMAKE_CXX_STANDARD 14)
set(Headers FanPage.h Member.h Status.h BasicFunctions.h)
set(CPP)
add_executable(FaceBook main.cpp MemberFunctions.cpp cpp StatusFunctions.cpp FaceBook.cpp BasicFunctions.cpp FanPageFunctions.cpp)
