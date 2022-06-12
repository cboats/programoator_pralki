#!/bin/bash

g++ -c komora.cpp
g++ -c komoraPralki.cpp
g++ -c komoraPlyn.cpp
g++ -c pranie.cpp
g++ -c pralka.cpp
g++ -c terminalSerwisanta.cpp
g++ -c terminalUzytkownika.cpp
g++ -c pralkaMain.cpp

g++ -o pralkaMain komora.o komoraPralki.o komoraPlyn.o pranie.o pralka.o terminalSerwisanta.o terminalUzytkownika.o pralkaMain.o
chmod 755 komora.o komoraPralki.o komoraPlyn.o pranie.o pralka.o terminalSerwisanta.o terminalUzytkownika.o pralkaMain.o

exit 0
