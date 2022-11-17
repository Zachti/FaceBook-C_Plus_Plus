cmake_minimum_required(VERSION 3.20)
project(FaceBook_C_)

set(CMAKE_CXX_STANDARD 14)

include_directories(FaceBook)

add_executable(FaceBook_C_
        FaceBook/BasicFunctions.cpp
        FaceBook/BasicFunctions.h
        FaceBook/FaceBook.cpp
        FaceBook/FaceBook.h
        FaceBook/FanPage.h
        FaceBook/FanPageFunctions.cpp
        FaceBook/main.cpp
        FaceBook/Member.h
        FaceBook/MemberFunctions.cpp
        FaceBook/Status.h
        FaceBook/StatusFunctions.cpp)
