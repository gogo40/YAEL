flex lexer.l
bison parser.y

g++ -O2 -c maxwell_db_util.cpp 
g++ -O2 -o maxwell_dbc parser.tab.c maxwell_db_util.o -lfl -lm 
g++ -O2 -o maxwell_db maxwell_db_gen.cpp maxwell_db_util.o -lm #-DWIN

