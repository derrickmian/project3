g++ -std=c++11 -c main.cpp functions.cpp -I -lcgicc
g++ -std=c++11 -o wordSearch.cgi main.o functions.o -I -lcgicc 
chmod 705 wordSearch.cgi