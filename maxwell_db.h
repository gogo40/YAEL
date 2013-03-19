/* 
maxwell
funções uteis maxwell_db
Autor: Péricles Lopes Machado
*/

#ifndef maxwell_DB_H
#define maxwell_DB_H

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include <iostream>
#include <fstream>

const double EPS = 1e-10;

inline int cmp(double x, double y=0, double tol=EPS){
	return (x<=y+tol)?(x+tol<y)?-1:0:1;
}

using namespace std;

typedef vector<double> Vector;
typedef vector<Vector*> Matrix;

typedef double (*pfd) (double*);

static map<int,pfd> fdL[3];//Lista de funções de double de até 2 argumentos

struct vect{
	int DIM;//Numero de dimensoes do vetor
	vector<double>* values;//Valores do vetor
	vector<int>* sizes;//tamanho de cada dimensão
	
	vect(){DIM=0; values=0; sizes=0; }
	vect(vector<int>* s){
		int n;
		sizes=s; DIM=s->size();
		n=1;
		for(int i=0;i<DIM;i++) n*=(*sizes)[i];
		values=new vector<double>(n);
	}
};

//Posição no vetor
struct vect_pos{
	string* n;
	int pos;
	
	vect_pos(){n=0; pos=0;}
	vect_pos(string* n, int pos):n(n),pos(pos){}
};

//Campo de uma classe
struct sf{
	int nx, ny, nz;
	int tam;
	int ini_p;//posicao de inicio de posicao espacial
	sf(int nx=0, int ny=0, int nz=0, int tam=0,int ini_p=0):nx(nx),ny(ny),nz(nz),tam(tam),ini_p(ini_p){}
};

//Uma classe maxwell
struct sclass{
		void add_fields(vector<string>& fname, vector< pair<Matrix*,sf*> >& v){
			for(int i=0;i<fname.size();i++) field[fname[i]]=v[i];
		}
		map<string,pair<Matrix*,sf*> > field;
};

//Um objeto sabs
struct sobj{
	string pai;
	double x, y, z;
};

//Um token para expressoes maxwell
struct Token{
	int tk;
	union l{ string* name; double value; int narg; vect_pos* vp; };
	l lval;
	
	Token(int tk=0, double value=0):tk(tk){lval.value=value;}
	Token(int tk, string* name):tk(tk){lval.name=name;}
	Token(int tk, int narg):tk(tk){ lval.narg=narg;}
	Token(int tk, vect_pos* v):tk(tk){ lval.vp=v; }
};

//Vetor de tokens maxwell
typedef vector<Token> Tokens;

struct build_obj{
//CLASS_NAME OBJ_NAME (X,Y,Z)
//ou
//CLASS_NAME OBJ_NAME[i] (X,Y,Z)
	string* class_, * obj_;
	Tokens* x, *y, *z;
	bool isv;//eh vetor
	Tokens* i;
	
	build_obj(string* class_=0, string* obj_=0,
			  Tokens* x=0, Tokens* y=0, Tokens* z=0,
			  bool isv=false, Tokens* i=0)
	:class_(class_),obj_(obj_),x(x),y(y),z(z),isv(isv),i(i){}
	
};

struct if_else_ctrl{
//if(cond)  {cmds} [else {cmds }] 
	Tokens* expr;
	int false_next;
	
	if_else_ctrl(Tokens* expr=0, int false_next=0): expr(expr),false_next(false_next){}
};

struct while_ctrl{
//while(cond)  {cmds} 
	Tokens* expr;
	int false_next;
	
	while_ctrl(Tokens* expr=0, int false_next=0): expr(expr),false_next(false_next){}
};

struct iToken{
	int tk;
	/*
	Tipos de tokens de interpreção:
	tipo: expr,  token : EXPR ou ECHO ou PRINT ou RETURN [ok];
	
	[ expr; ECHO expr; PRINT expr;  RETURN expr;]	[ok]
	
	[ECHOS]
	ECHO string [ok]
	
	[PRINTS]
	PRINT string [ok]
	
	Tipo: build_obj, token : BUILD_OBJ [ok]
	
	[ build_obj; ] [ok]
	
	Tipo estrutura de controle:
	if_else_ctrl;[ok]
	
	for_ctrl;
	while_ctrl;
	do_while_ctrl;
	*/
	union l{ 
		Tokens* expr;
		string* str;
		build_obj* obj;
		if_else_ctrl* ifelse;
		while_ctrl* while_;
	};
	l lval;
	int next;
	
	iToken(int tk=0): tk(tk){next=1;}
	iToken(int tk,int next):tk(tk),next(next){}
	iToken(int tk, Tokens* expr):tk(tk){lval.expr=expr;next=1;}
	iToken(int tk, string* str):tk(tk){lval.str=str;next=1;}
	iToken(int tk, build_obj* obj):tk(tk){lval.obj=obj;next=1;}
	iToken(int tk, if_else_ctrl* ifelse):tk(tk){ lval.ifelse=ifelse; next=1;}
	iToken(int tk, while_ctrl* while_):tk(tk){ lval.while_=while_; next=1;}
};

//Vetor de tokens de interpretacao
typedef vector<iToken> iTokens;


struct function{
	iTokens* f;
	int narg;
	int rt;//Tipo de retorno 1- para vetor, 0 para numero
	
	vector<string>* args_name;//Nome dos argumentos
	vector<int>* args_t;//Tipo dos argumentos  1 para vetor,  0 para numero

	map<string, double> var;
	map<string, vect> vect_l;
};

struct ret_type{
	int type;
	double v;
	vect* vet;
};

//Avaliador de expressões maxwell
double eval(
map<string, double>* var,
map<string, bool>* isvar,
map<string, bool>* isclass,
map<string, bool>* isobj,
map<string, sclass>* maxwellClass,
map<string, sobj>* maxwellObj,
map<string,vect>* vect_l,
map<string,bool>* isvect,
Tokens* in
);

double eval(Tokens* in);

//Interpretador de comandos
double interp(
map<string, double>* var,
map<string, bool>* isvar,
map<string, bool>* isclass,
map<string, bool>* isobj,
map<string, sclass>* maxwellClass,
map<string, sobj>* maxwellObj,
map<string,vect>* vect_l,
map<string,bool>* isvect,
iTokens* in
);

//Define arquivo onde jogar a saida do interpretador
void setOutput(const char* fname);

double interp(iTokens* in);

//Controi objeto
void build_o(build_obj* in);

void build_o(build_obj* in,
map<string, double>* var,
map<string, bool>* isvar,
map<string, bool>* isclass,
map<string, bool>* isobj,
map<string, sclass>* maxwellClass,
map<string, sobj>* maxwellObj,
map<string,vect>* vect_l,
map<string,bool>* isvect);

inline void append(Tokens* a, Tokens* b){
	for(Tokens::iterator it=b->begin(); it!=b->end(); it++)
		a->push_back(*it);
}

inline void append(iTokens* a, iTokens* b){
	for(iTokens::iterator it=b->begin(); it!=b->end(); it++)
		a->push_back(*it);
}

inline
ostream& operator<<(ostream& out, const Matrix& m){
	out<<"{\n";
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i]->size();j++)
			out<<" "<<(*m[i])[j];
		out<<";\n";
	}
	out<<"};\n";
	return out;
}


inline
ostream& operator<<(ostream& out, sclass& s){
	map<string,pair<Matrix*,sf*> >::iterator f;
	for(f=s.field.begin(); f!=s.field.end(); f++){
		printf("field: %s\n",f->first.c_str());
		printf("value:\n");
		printf("______________\n");
		cout<< * (f->second.first);
		printf("______________\n");
	}
	return out;
}

typedef pair<vector<string>, vector<pair<Matrix*,sf*> > > sfields;

extern "C"{
	void yyerror (char const *);
	int yylex();
	int yyparse();
};

void loadFile(const char* fname, 
				map<string,sclass>& maxwellClass, map<string,bool>& isclass, 
				map<string,sobj>& maxwellObj, map<string,bool>& isobj, string& __path
			);

void saveFile(const char* fname, 
				map<string,sclass>& maxwellClass,  
				map<string,sobj>& maxwellObj
			);
#endif

