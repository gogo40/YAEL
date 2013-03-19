/* 
yael
Parser yael_parser
Autor: Pericles Lopes Machado
*/

%{

#include "yael.h"

FILE* plog;
FILE* pout;

static char buffer[256];
string __path;

int nerrors, nlines;

map<string,bool> isvect;
map<string,vect> vect_l;

map<string,bool> isfunction;
map<string,function> function_l; 

map<string,int>  func_narg;
map<string,int>  func_id;
map<string,bool> is_bultin_func;

map<string, double> var;
map<string, bool> isvar;

map<string, bool> isclass;
map<string, bool> isobj;
map<string, sclass> yaelClass;
map<string, sobj> yaelObj;

inline
double eval(Tokens* in){
	return eval(&var, &isvar, &isclass, &isobj, &yaelClass, &yaelObj, &vect_l, &isvect, in);
}

inline
double interp(iTokens* in){
	return interp(&var, &isvar, &isclass, &isobj, &yaelClass, &yaelObj,&vect_l,&isvect, in);
}

void build_o(build_obj* in){
	string out;
	out=*in->obj_;
	if(in->isv){
		sprintf(buffer,"%.0lf",eval(in->i));
		out= out +"[" +buffer + "]";
	}
	
	isobj[out]=true;
	yaelObj[out].pai=*in->class_;
	yaelObj[out].x=eval(in->x);
	yaelObj[out].y=eval(in->y);
	yaelObj[out].z=eval(in->z);
}

void build_o(build_obj* in,
map<string, double>* var,
map<string, bool>* isvar,
map<string, bool>* isclass,
map<string, bool>* isobj,
map<string, sclass>* yaelClass,
map<string, sobj>* yaelObj,
map<string,vect>* vect_l,
map<string,bool>* isvect){
	string out;
	out=*in->obj_;
	if(in->isv){
		sprintf(buffer,"%.0lf",eval(var, isvar, isclass, isobj, yaelClass, yaelObj, vect_l, isvect, in->i));
		out= out +"[" +buffer + "]";
	}
	
	(*isobj)[out]=true;
	(*yaelObj)[out].pai=*in->class_;
	 

	(*yaelObj)[out].x=eval(var, isvar, isclass, isobj, yaelClass, yaelObj, vect_l, isvect, in->x);
	(*yaelObj)[out].y=eval(var, isvar, isclass, isobj, yaelClass, yaelObj, vect_l, isvect, in->y);
	(*yaelObj)[out].z=eval(var, isvar, isclass, isobj, yaelClass, yaelObj, vect_l, isvect, in->z);
}

typedef vector<string> vs;
typedef vector<int> vi;

typedef pair<vs*,vi*> func_arg;

%}

%union{
	double val;
	string* str;
	sfields* sf;
	Matrix* valM;
	Vector* valV;
	Tokens* tk;
	iTokens* itk;
	vs* vS;
	vi* vI;
	func_arg* fa;
	build_obj* bobj;
}

%token ECHO_
%token ECHOS
%token PRINT
%token PRINTS
%token EXEC
%token END_
%token RETURN
%token EXPR
%token BUILD_OBJ

%token FUNCTION
%token FUNCTION_CALL
%token DO
%token FOR
%token IF
%token ELSE
%token WHILE
%token END_WHILE
%token END_FOR

%token<str> STRING

%token READ
%token REAL
%token VECTOR
%token<str> VECTOR_ID
%token VECTOR_ID_POS
%token VECTOR_ID_ATTR
%token VECTOR_POS
%token<str> VAR
%token<val> NUM
%token<str> ID
%token<str> CLASS_ID
%token<str> OBJ_ID
%token<str> BUILT_IN_FUNC
%token NEG
%token CLASS
%token USE
%token DIFF
%token EQ
%token LEQ
%token GEQ
%token OR
%token AND
%token NOT
%token INC
%token DEC
%token BREAK
%token CONTINUE

%type<itk> do_while_cond
%type<itk> for_cond
%type<itk> while_cond
%type<itk> if_else_cond
%type<itk> cmd_interp
%type<bobj> build_yael_obj
%type<vS> class_father;
%type<fa> list_name_args;
%type<sf> class_fields;
%type<valM> value
%type<tk> exp
%type<tk> for_exp
%type<tk> l_exp
%type<tk> list_arg
%type<valM> matrix_expr
%type<valM> matrix_num
%type<valV> list_expr
%type<valV> list_num
%type<vI> dim_list

%left OR
%left AND
%right NOT

%nonassoc ECHO_ PRINT
%nonassoc EQ DIFF '>' '<' LEQ GEQ 

%right '=' ADD_ATR SUB_ATR MUL_ATR DIV_ATR MOD_ATR POW_ATR
%left INC DEC
%left POS_INC PRE_INC POS_DEC PRE_DEC
%left '-' '+'
%left '*' '/'
%left '%'
%left LE
%left LN
%left NEG /* negation--unary minus */
%right '^' /* exponentiation */

%left BUILT_IN_FUNC

%%

////////////////////////////////////////////////////
//Regras raizes///////////////////////////////////////
////////////////////////////////////////////////////
init:  
init class_def ';'
| init USE ID ';' 
{ 
	if(nerrors==0){
		printf("Usando: %s\n",$3->c_str()); 
		fprintf(plog,"Usando: %s\n",$3->c_str()); 

		//printf("size= %d\n",yaelClass.size());
		loadFile((*$3+".mo").c_str(),yaelClass,isclass,yaelObj,isobj,__path);
		//printf("size= %d\n",yaelClass.size());
		delete $3; 
	}
}
| class_def ';'
| USE  ID  ';' 
{ 
	if(nerrors==0){
		printf("Usando: %s\n",$2->c_str());
		fprintf(plog,"Usando: %s\n",$2->c_str());	
		//printf("size= %d\n",yaelClass.size());
		loadFile((*$2+".mo").c_str(),yaelClass,isclass,yaelObj,isobj,__path); 
		//printf("size= %d\n",yaelClass.size());
		delete $2; 
	}
}
| init EXEC '{' cmd_interp '}' 
{  if(nerrors==0){ interp($4); } vect_l.clear(); isvect.clear(); isvar.clear(); var.clear(); delete $4;  }
| EXEC '{' cmd_interp '}' 
{  if(nerrors==0){ interp($3); } vect_l.clear(); isvect.clear(); isvar.clear(); var.clear(); delete $3;  }
|
FUNCTION ID '(' list_name_args ')' '{' cmd_interp '}'
{
	function* f;
		
	f=&function_l[*$2];
	f->rt=0;
	f->narg=$4->first->size();
	f->args_name=$4->first;
	f->args_t=$4->second;
	f->var=var;
	f->vect_l=vect_l;
	f->f=$7;
	isfunction[*$2]=true;
		
	delete $2; delete $4;
	var.clear(); isvar.clear(); vect_l.clear(); isvect.clear();
}
|
init FUNCTION ID '(' list_name_args ')' '{' cmd_interp '}'
{
	function* f;

	f=&function_l[*$3];
	f->rt=0;
	f->narg=$5->first->size();
	f->args_name=$5->first;
	f->args_t=$5->second;
	f->var=var;
	f->vect_l=vect_l;
	f->f=$8;
	isfunction[*$3]=true;

	delete $3; delete $5;
	var.clear(); isvar.clear(); vect_l.clear(); isvect.clear();
} 
| 
error      { } 
;

list_name_args:
list_name_args ',' REAL ID
{
	$$=$1; 
	$$->first->push_back(*$4); delete $4;
	$$->second->push_back(0);
}
|
list_name_args ',' VECTOR ID
{
	$$=$1; 
	$$->first->push_back(*$4); delete $4;
	$$->second->push_back(1);
}
|
REAL ID
{
	$$=new func_arg(); $$->first=new vs();  $$->second=new vi(); 
	$$->first->push_back(*$2); delete $2;
	$$->second->push_back(0);
}
|
VECTOR ID
{
	$$=new func_arg(); $$->first=new vs();  $$->second=new vi(); 
	$$->first->push_back(*$2); delete $2;
	$$->second->push_back(1);
}
|
{  $$=new func_arg(); $$->first=new vs();  $$->second=new vi();  }
;

////////////////////////////////////////////////////
//Regras de defini��o de classe//////////////////////////
////////////////////////////////////////////////////
class_def: 
CLASS  ID '{' class_fields '}'  
{ 
	isclass[*$2]=true;
	yaelClass[*$2].add_fields($4->first,$4->second);
	delete $2;  
	delete $4;
}
|
CLASS  ID ':' class_father '{' class_fields '}'  
{ 
	isclass[*$2]=true;
	yaelClass[*$2].add_fields($6->first,$6->second);
	
	delete $6;
	
	/*Adiciona campos herdados*/
	sclass* p=&yaelClass[*$2];
	for(int i=0;i<$4->size();i++){
		sclass* c;
		map<string,pair<Matrix*,sf*> >::iterator it;
		
		c=&yaelClass[(*$4)[i]];
		it=c->field.begin();
		
		for(;it!=c->field.end();it++){
			pair<Matrix*,sf*>* it2;
			Matrix* m;
			
			it2=&p->field[it->first];
			(*it2).second=it->second.second;
			m=it->second.first;
			
			if(it2->first==0) it2->first=new Matrix();
			
			for(int k=0;k<m->size();k++){	
				it2->first->push_back((*m)[k]);
			}
		}
	}
	delete $4;
	delete $2;  
}
;	

////////////////////////////////////////////////////
//Regras de heran�a de classes///////////////////////////
////////////////////////////////////////////////////
class_father:
CLASS_ID
{
	$$=new vs();
	$$->push_back(*$1);
	delete $1;
}
| 
class_father ',' CLASS_ID 
{
	$$=$1;
	$$->push_back(*$3);
	delete $3;
}
;

////////////////////////////////////////////////////
//Regras para defini��es de campos da classe///////////////
////////////////////////////////////////////////////
class_fields:
class_fields ID '(' NUM ',' NUM ',' NUM ',' NUM ')' '=' value ';'
{ 
	$1->first.push_back(*$2); 
	delete $2; 
	$1->second.push_back(pair<Matrix*,sf*> ($13, new sf((int)($4),(int)($6),(int)($8),(int)($10)) ));
	$$=$1;
}
| ID '(' NUM ',' NUM ',' NUM ',' NUM ')' '=' value';'           
{ 
	$$=new sfields();
	$$->first.push_back(*$1); 
	delete $1; 
	$$->second.push_back(pair<Matrix*,sf*> ($12, new sf((int)($3),(int)($5),(int)($7),(int)($9)) )); 
}
|class_fields ID '(' NUM ',' NUM ',' NUM ',' NUM ',' NUM ')' '=' value ';'
{ 
	$1->first.push_back(*$2); 
	delete $2; 
	$1->second.push_back(pair<Matrix*,sf*> ($15, new sf((int)($4),(int)($6),(int)($8),(int)($10),(int)$12) ));
	$$=$1;
}
| ID '(' NUM ',' NUM ',' NUM ',' NUM ',' NUM ')' '=' value';'           
{ 
	$$=new sfields();
	$$->first.push_back(*$1); 
	delete $1; 
	$$->second.push_back(pair<Matrix*,sf*> ($14, new sf((int)($3),(int)($5),(int)($7),(int)($9),(int)($11)) )); 
}
;

////////////////////////////////////////////////////
//Regra para defini��o da matriz que define um campo///////
////////////////////////////////////////////////////
value: 
  '[' matrix_expr ']'            
{ $$=$2; }
| '[' matrix_num ']'  %prec LN 
{  $$=$2; }
;

//////////////////////////////////////////////
//Regras que definem uma matriz de express�es///////
//////////////////////////////////////////////
matrix_expr:  
matrix_expr ';' list_expr    
{ $1->push_back($3); $$=$1; }
| list_expr                    
{ $$=new Matrix(); $$->push_back($1);}
;

list_expr:  
list_expr ',' exp   
{$1->push_back(eval($3)); $$=$1; delete $3;}
| exp					
{ $$=new Vector(); $$->push_back(eval($1)); delete $1; }
;
   
//////////////////////////////////////////////
//Regras que definem uma matriz de numeros/////////
//////////////////////////////////////////////
matrix_num:  
matrix_num  ';' list_num            
{ $1->push_back($3); $$=$1; }
| list_num                           
{ $$=new Matrix(); $$->push_back($1); }
;

list_num: 
list_num NUM  
{  $1->push_back($2); $$=$1; }
| NUM			
{  $$=new Vector(); $$->push_back($1); }
;

////////////////////////////////////////////////////////////////
//Regras que definem um conjunto de comandos a serem interpretados///////
///////////////////////////////////////////////////////////////
cmd_interp:
BREAK ';'
{ $$=new iTokens(); $$->push_back(iToken(BREAK));}
|
cmd_interp BREAK ';'
{ $$=$1; $$->push_back(iToken(BREAK)); }
|
CONTINUE ';'
{ $$=new iTokens(); $$->push_back(iToken(CONTINUE));}
|
cmd_interp CONTINUE ';'
{ $$=$1; $$->push_back(iToken(CONTINUE)); }
|
exp ';'
{ $$=new iTokens(); $$->push_back(iToken(EXPR,$1));}
|
cmd_interp exp ';'
{ $$=$1; $$->push_back(iToken(EXPR,$2)); }
|
RETURN exp ';'
{ $$=new iTokens(); $$->push_back(iToken(RETURN,$2));}
|
cmd_interp RETURN exp ';'
{ $$=$1; $$->push_back(iToken(RETURN,$3)); }
|
ECHO_ STRING ';'
{ $$=new iTokens(); $$->push_back(iToken(ECHOS,$2)); }
|
cmd_interp ECHO_ STRING ';'
{ $$=$1; $$->push_back(iToken(ECHOS,$3)); }
|
ECHO_ exp ';'
{ $$=new iTokens(); $$->push_back(iToken(ECHO_,$2)); }
|
cmd_interp ECHO_ exp ';'
{ $$=$1; $$->push_back(iToken(ECHO_,$3)); }
|
PRINT STRING ';'
{ $$=new iTokens(); $$->push_back(iToken(PRINTS,$2)); }
|
cmd_interp PRINT STRING ';'
{ 	$$=$1; $$->push_back(iToken(PRINTS,$3)); }
|
PRINT exp ';'
{ $$=new iTokens(); $$->push_back(iToken(PRINT,$2));}
|
cmd_interp PRINT exp ';'
{ $$=$1; $$->push_back(iToken(PRINT,$3)); }
|
build_yael_obj ';'
{ $$=new iTokens(); $$->push_back(iToken(BUILD_OBJ,$1)); }
|
cmd_interp build_yael_obj ';'
{ $$=$1; $$->push_back(iToken(BUILD_OBJ,$2)); }
|
if_else_cond
{ $$=$1; }
|
cmd_interp if_else_cond
{ $$=$1; append($$,$2); delete $2; }
|
while_cond
{ $$=$1; }
|
cmd_interp while_cond
{ $$=$1; append($$,$2); delete $2; }
|
for_cond
{ $$=$1; }
|
cmd_interp for_cond
{ $$=$1; append($$,$2); delete $2; }
|
do_while_cond
{ $$=$1; }
|
cmd_interp do_while_cond
{ $$=$1; append($$,$2); delete $2; }
|
VECTOR ID '(' dim_list ')' ';'
{ $$=new iTokens(); isvect[*$2]=true; vect_l[*$2]=vect($4);  delete $2; }
|
cmd_interp VECTOR ID '(' dim_list ')' ';'
{ $$=$1; isvect[*$3]=true; vect_l[*$3]=vect($5);  delete $3; }
;

dim_list:
dim_list',' NUM
{ $$=$1; $$->push_back((int)($3)); }
| 
NUM
{ $$=new vi(); $$->push_back((int)($1)); }
;

///////////////////////////////////////
//Estrutura do{cmds} while(cond);
///////////////////////////////////////
do_while_cond:
DO '{' cmd_interp '}' WHILE '(' exp ')' ';'
{
	$$=$3;
	while_ctrl* while_=new while_ctrl();
	
	while_->expr=$7;
	while_->false_next=1;
	
	$$->push_back(iToken(WHILE,while_));
	(*$$)[$$->size()-1].next=-((int)($3->size()-1));
}
;

///////////////////////////////////////
//Estrutura for(cond1;cond2;cond3){cmds}////
//////////////////////////////////////
for_cond:
FOR '(' for_exp ';' for_exp ';' for_exp ')' '{' cmd_interp '}'
{
	$$=new iTokens();
	$$->push_back(iToken(EXPR,$3));
	$10->push_back(iToken(EXPR,$7));
	
	while_ctrl* while_=new while_ctrl();
	
	while_->expr=$5;
	while_->false_next=2+$10->size();
	$$->push_back(iToken(WHILE,while_));
	$10->push_back( iToken(END_FOR,-((int)$10->size() + 1 )) );
	append($$,$10);
	
	delete $10;
}
;

for_exp:
{$$=new Tokens(); $$->push_back(Token(NUM,1.0));}
|exp
{$$=$1;}
;

///////////////////////////////////////
//Estrutura while(cond){cmds}//////////////
///////////////////////////////////////
while_cond:
WHILE '(' exp ')' '{' cmd_interp '}'
{
	$$=new iTokens();
	while_ctrl* while_=new while_ctrl();
	
	while_->expr=$3;
	while_->false_next=2+$6->size();
	$$->push_back(iToken(WHILE,while_));
	$6->push_back(iToken(END_WHILE,-((int)$6->size() + 1 )));
	append($$,$6);
	
	delete $6;
}
;

//////////////////////////////////////
//Estrutura if (cond) {cmds} [else {cmds}]?//
/////////////////////////////////////
if_else_cond:
IF '(' exp ')' '{' cmd_interp '}'
{ 
	$$=new iTokens(); 
	if_else_ctrl* ifelse=new if_else_ctrl();
	
	ifelse->expr=$3;
	ifelse->false_next=1+$6->size();
	$$->push_back(iToken(IF,ifelse));
	append($$,$6);
	
	delete $6;
}
|
IF '(' exp ')' '{' cmd_interp '}' ELSE '{' cmd_interp '}'
{ 
	$$=new iTokens(); 
	if_else_ctrl* ifelse=new if_else_ctrl();
	
	ifelse->expr=$3;
	ifelse->false_next=1+$6->size();
	$$->push_back(iToken(IF,ifelse)); 
	append($$,$6);
	
	(*$$)[$$->size()-1].next=1+$10->size();
	append($$,$10);
	
	delete $6; delete $10;
}
;

//////////////////////////////////////
//Defini��es para constu��o de objetos yael//
//////////////////////////////////////
build_yael_obj:
CLASS_ID ID '(' exp ',' exp ',' exp ')' 
{ $$=new build_obj($1,$2,$4,$6,$8); }
|
CLASS_ID ID '[' exp ']' '(' exp ',' exp ',' exp ')' 
{ $$=new build_obj($1,$2,$7,$9,$11,true,$4); }
;

///////////////////////////////////
//Regras que definem express�es///////
//////////////////////////////////
l_exp:
l_exp ',' exp
{$$=$1; append($$,$3); delete $3; }
|
exp
{ $$=$1; }
;

exp:
VECTOR_ID
{ $$=new Tokens(); $$->push_back(Token(VECTOR_ID,$1));}
|
VECTOR_ID '[' l_exp ']'
{ $$=$3; $$->push_back(Token(VECTOR_ID_POS,new vect_pos($1,0))); }
|
ID '[' l_exp ']'
{ $$=$3; $$->push_back(Token(VECTOR_ID_POS,new vect_pos($1,0))); }
|
READ
{ $$=new Tokens(); $$->push_back(Token(READ,0)); }
|
VAR
{ $$=new Tokens(); $$->push_back(Token(VAR,$1)); }
|
ID
{ $$=new Tokens(); $$->push_back(Token(ID,$1)); }
|
NUM 
{ $$ = new Tokens(); $$->push_back(Token(NUM,$1));}
| 
exp '+' exp 
{ $$ = $1; append($$,$3); $$->push_back(Token('+',2)); delete $3; }
| 
exp '-' exp 
{ $$ = $1; append($$,$3); $$->push_back(Token('-',2)); delete $3; }
| 
exp '*' exp 
{ $$ = $1; append($$,$3); $$->push_back(Token('*',2)); delete $3; }
| 
exp '/' exp 
{ $$ = $1; append($$,$3); $$->push_back(Token('/',2)); delete $3; }
| 
exp '%' exp 
{ $$ = $1; append($$,$3); $$->push_back(Token('%',2)); delete $3; }
| 
'-' exp %prec NEG 
{ $$ = $2; $$->push_back(Token(NEG,1)); }
| 
exp '^' exp 
{ $$ = $1; append($$,$3); $$->push_back(Token('^',2)); delete $3; }
| 
'(' exp ')' 
{ $$ = $2; }
| 
exp '=' exp
{ $$=$1; append($$,$3); $$->push_back(Token('=',2)); delete $3; }
| 
exp ADD_ATR exp
{ $$=$1; append($$,$3); $$->push_back(Token(ADD_ATR,2)); delete $3; }
|
exp SUB_ATR exp
{ $$=$1; append($$,$3); $$->push_back(Token(SUB_ATR,2)); delete $3; }
|
exp MUL_ATR exp
{ $$=$1; append($$,$3); $$->push_back(Token(MUL_ATR,2)); delete $3; }
|
exp DIV_ATR exp
{ $$=$1; append($$,$3); $$->push_back(Token(DIV_ATR,2)); delete $3; }
|
exp MOD_ATR exp
{ $$=$1; append($$,$3); $$->push_back(Token(MOD_ATR,2)); delete $3; }
|
exp POW_ATR exp
{ $$=$1; append($$,$3); $$->push_back(Token(POW_ATR,2)); delete $3; }
|
exp AND exp
{ $$=$1; append($$,$3); $$->push_back(Token(AND,2)); delete $3; }
| 
exp OR exp
{ $$=$1; append($$,$3); $$->push_back(Token(OR,2)); delete $3; }
| 
NOT exp
{ $$ = $2; $$->push_back(Token(NOT,1)); }
|
INC exp
{ $$=$2; $$->push_back(Token(PRE_INC,1));}
|
exp INC
{ $$=$1; $$->push_back(Token(POS_INC,1)); }
|
DEC exp
{ $$=$2; $$->push_back(Token(PRE_DEC,1)); }
|
exp DEC
{ $$=$1; $$->push_back(Token(POS_DEC,1)); }
|
exp LEQ exp
{ $$=$1; append($$,$3); $$->push_back(Token(LEQ,2)); delete $3; }
|
exp GEQ exp
{ $$=$1; append($$,$3); $$->push_back(Token(GEQ,2)); delete $3; }
|
exp EQ exp
{ $$=$1; append($$,$3); $$->push_back(Token(EQ,2)); delete $3; }
|
exp '<' exp
{ $$=$1; append($$,$3); $$->push_back(Token('<',2)); delete $3; }
|
exp '>' exp
{  $$=$1; append($$,$3); $$->push_back(Token('>',2)); delete $3; }
|
exp DIFF exp
{ $$=$1; append($$,$3); $$->push_back(Token(DIFF,2)); delete $3; }
|
BUILT_IN_FUNC '(' list_arg ')'
{ $$=$3; $$->push_back(Token(func_id[*$1],func_narg[*$1])); delete $1; }
|
ID '(' list_arg ')'
{ $$=$3; $$->push_back(Token(FUNCTION_CALL,$1)); }
;

list_arg:
exp ',' list_arg 
{ $$=$1; append($$,$3);}
|
{ $$=new Tokens(); }
|
exp
{ $$=$1; }
;

%%

#include "lex.yy.c"

#include "yael_function_list.h"
#include "yael_eval.cpp"
#include "yael_interp.cpp"

char* __yy_file_name;

void
yyerror (char const *s)
{
	fprintf (stderr, "%s:%d: %s\n", __yy_file_name,nlines, s);
	fprintf (plog, "%s:%d: %s\n", __yy_file_name,nlines, s);
	nerrors++;
}

void init(){
	nlines=1; nerrors=0;
	//setOutput("yael_out");
	plog=fopen((__path+"/yael_log").c_str(),"w+");
	pout=fopen((__path+"/yael_out").c_str(),"w+");
}

int main(int argc, char** argv )
{
	++argv, --argc; 
	if(argc<1){
		printf("Formato do comando: %s  <file_in>\n",argv[-1]);
		printf("<file_in> = 1 arquivo de entrada\n");
		return 0;
	}
	srand(time(NULL));
	init_main();
	
	string file_in("");
	
	for(int i=0;i<argc;i++){ if(i>0) file_in+=string(" "); file_in+=argv[i]; }
	
	FILE* f=fopen( file_in.c_str(), "r" );
	if(!f){
		printf("Falha ao abrir:%s %s\n",file_in.c_str(),argv[0]);
		return -1;
	}
	
	__yy_file_name=(char*)malloc((file_in.size()+1)*sizeof(char));
	for(int i=0;i<file_in.size();i++) __yy_file_name[i]=file_in[i];
	__yy_file_name[file_in.size()]=0;
	
	int p, l;
		
	__path="";
	for(l=file_in.size()-1;l>-1&&(file_in[l]!='/'&&file_in[l]!='\\');l--);
	for(int k=0;k<file_in.size()&&k<l;k++) __path+=file_in[k];
	//__path+="/";
	printf("Caminho:%s\n",__path.c_str());
	
	yyin = f;
	init();
	yyparse();
	
	string out("");
		
	if(nerrors==0){
		int len=file_in.size();
		
		for(p=len-1;p>-1 && file_in[p]!='.';p--);
		
		for(int k=0;k<file_in.size()&& k<p;k++) out+=file_in[k];
		out+=".mo";
		
		saveFile(out.c_str(),yaelClass,yaelObj);
		fprintf (stderr,"Script compilado com sucesso!\n");
		fprintf (plog, "Script compilado com sucesso!\n");
	}else{
		fprintf (stderr, "%s: Foram encontrados %d erros sint�ticos\n", __yy_file_name,nerrors);
		fprintf (plog, "%s: Foram encontrados %d erros sint�ticos\n", __yy_file_name,nerrors);
	}

	if(nerrors==0) saveFile(out.c_str(),yaelClass,yaelObj);
	
	fclose(plog);
	fclose(pout);
	return 0;
}

