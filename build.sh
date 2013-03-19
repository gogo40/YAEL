flex lexer.l
bison parser.y

g++ -O2 -c yael_util.cpp 
g++ -O2 -o yaelc parser.tab.c yael_util.o -lfl -lm 
g++ -O2 -o yael yael_gen.cpp yael_util.o -lm #-DWIN

