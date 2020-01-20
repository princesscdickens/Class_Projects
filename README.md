# Class_Projects
GOT is a text-based command-line game based on the popular television series (Game of Thrones) I made as my final project for an introductory course in C++. 

To compile:
1. Open the Terminal and navigate to where all the game files are stored. 
2. Type in the following command:
c++ -o file_name_executable Game.cpp City.cpp  GOT_game_driver.cpp Hero.cpp Place.cpp Playerscore.cpp Warrior.cpp 

If you try to compile and get an error "fatal error: 'bits/stdc++.h' file not found"
1. Create this directory:
 mkdir -p /usr/local/include/bits
2. Inside that directory, save this header file:
 stdc++.h (In repository)

To run:
Make sure you're in the same directory as the executable "run_game" and type in:
./file_name_executable
