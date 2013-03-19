/* 
maxwell
maxwell: lista de funções
Autor: Pericles Lopes Machado
*/


#ifndef maxwell_FUNCTION_LIST_H
#define maxwell_FUNCTION_LIST_H

#include <time.h>

double random(double* v){ return rand();}
double seed(double* v){ srand((int)v[0]); return 0;}
double times(double* v){ return (double)time(NULL);}

double round(double* v){return round(v[0]);}
double floor(double* v){return floor(v[0]);}
double ceil(double* v){return ceil(v[0]);}

double sin(double* v){return sin(v[0]);}
double cos(double* v){return cos(v[0]);}
double tan(double* v){return tan(v[0]);}

double mod(double* v){return fmod(v[0],v[1]);}
double add(double* v){return v[0]+v[1];}
double sub(double* v){return v[0]-v[1];}
double mul(double* v){return v[0]*v[1];}
double div(double* v){return v[0]/v[1];}
double not_(double* v){return (cmp(v[0],0)==0)?1:0;}
double neg_(double* v){return -v[0];}
double and_(double* v){return (cmp(v[0],1)==0)&&(cmp(v[1],1)==0);}
double or_(double* v){return (cmp(v[0],1)==0)||(cmp(v[1],1)==0);}
double eq_(double* v){return cmp(v[0],v[1])==0;}
double diff_(double* v){return cmp(v[0],v[1])!=0;}
double leq_(double* v){return cmp(v[0],v[1])<=0;}
double geq_(double* v){return cmp(v[0],v[1])>=0;}
double le_(double* v){return cmp(v[0],v[1])<0;}
double ge_(double* v){return cmp(v[0],v[1])>0;}
double pow_(double* v){ return pow(v[0],v[1]); }

void init_main(){
	//Inicializando lista de funcoes binarias
	fdL[2]['+']=add; fdL[2]['-']=sub; fdL[2]['*']=mul; fdL[2]['/']=div;
	fdL[2]['^']=pow_; fdL[2][AND]=and_; fdL[2][OR]=or_; fdL[2][LEQ]=leq_;
	fdL[2][GEQ]=geq_; fdL[2]['<']=le_; fdL[2]['>']=ge_; fdL[2][EQ]=eq_;
	fdL[2][DIFF]=diff_; fdL[2]['%']=mod;
	
	//Inicializando lista de funcoes unarias
	fdL[1][NEG]=neg_;  fdL[1][NOT]=not_;

	//Funcoes built-in 
	fdL[0][665]=random; func_id["rand"]=665; is_bultin_func["rand"]=true; func_narg["rand"]=0;
	fdL[0][673]=times; func_id["time"]=673; is_bultin_func["time"]=true; func_narg["time"]=0;
	
	//Funcoes built-in unarias
	fdL[1][666]=sin; func_id["sin"]=666; is_bultin_func["sin"]=true; func_narg["sin"]=1;
	fdL[1][667]=cos; func_id["cos"]=667; is_bultin_func["cos"]=true; func_narg["cos"]=1;
	fdL[1][668]=tan; func_id["tan"]=668; is_bultin_func["tan"]=true; func_narg["tan"]=1;
	fdL[1][672]=seed; func_id["seed"]=672; is_bultin_func["seed"]=true; func_narg["seed"]=1;
	
	fdL[1][669]=floor; func_id["floor"]=669; is_bultin_func["floor"]=true; func_narg["floor"]=1;
	fdL[1][670]=ceil; func_id["ceil"]=670; is_bultin_func["ceil"]=true; func_narg["ceil"]=1;
	fdL[1][671]=round; func_id["round"]=671; is_bultin_func["round"]=true; func_narg["round"]=1;
}
#endif

