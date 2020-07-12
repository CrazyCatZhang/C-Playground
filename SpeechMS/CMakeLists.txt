cmake_minimum_required(VERSION 3.16)
project(SpeechMS)

set(CMAKE_CXX_STANDARD 20)

add_executable(SpeechMS main.cpp SpeakerManager.cpp SpeakerManager.h Competitor.h)