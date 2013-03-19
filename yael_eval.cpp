/* 
yeal
Avaliação de expressões yael
Autor: Péricles Lopes Machado
*/

#include "yael.h"
	
double eval(
map<string, double>* var,
map<string, bool>* isvar,
map<string, bool>* isclass,
map<string, bool>* isobj,
map<string, sclass>* yaelClass,
map<string, sobj>* yaelObj,
map<string,vect>* vect_l,
map<string,bool>* isvect,
Tokens* in
)
{
	map<string,double> fvar;
	map<string,vect>* fvect;
	function* f;
	double args[30], v;
	stack<Token> Q;
	int n, p;
	vect* vec;
	Token t;
	string* id;
	
	for(Tokens::iterator it=in->begin(); it!=in->end(); it++){
		switch(it->tk){
		
			case NUM: case VAR: case ID: case VECTOR_POS: case VECTOR_ID:
				Q.push(*it);
			break;
			
			case VECTOR_ID_POS:
				
				vec=&(*vect_l)[ *(it->lval.vp->n) ];
				n=vec->DIM-1;
				while(n>-1){
					if(Q.top().tk==NUM) args[n]=Q.top().lval.value;
					else if(Q.top().tk==VECTOR_POS)
					args[n]=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
					else args[n]=(*var)[*Q.top().lval.name];
					n--;
					Q.pop();
				}
				
				p=(int)(args[0]);
				for(int i=1;i<vec->DIM;i++) p=p*( (*vec->sizes)[i])+((int)(args[i]));
				
				it->lval.vp->pos=p;
				Q.push(Token(VECTOR_POS,it->lval.vp));
				
			break;
			
			case POS_INC:
				if(Q.top().tk==ID || Q.top().tk==VAR) v=(*var)[*Q.top().lval.name]++;
				else v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos]++;
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			case PRE_INC:
				if(Q.top().tk==ID || Q.top().tk==VAR) v=++(*var)[*Q.top().lval.name];
				else v=++(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			case POS_DEC:
				if(Q.top().tk==ID || Q.top().tk==VAR) v=(*var)[*Q.top().lval.name]--;
				else v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos]--;
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			case PRE_DEC:
				if(Q.top().tk==ID || Q.top().tk==VAR) v=--(*var)[*Q.top().lval.name];
				else v=--(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
				
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			case READ:
				scanf("%lf",&v);
				Q.push(Token(NUM,v));
			break;
			
			case '=':
				if(Q.top().tk==NUM) v=Q.top().lval.value;
				else if(Q.top().tk==VECTOR_POS)
				v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
				else v=(*var)[*Q.top().lval.name];
				
				Q.pop();
				
				if(Q.top().tk==ID || Q.top().tk==VAR){
					id=Q.top().lval.name; 
					if(Q.top().tk==ID) (*isvar)[*id]=true;
					(*var)[*id]=v;
				}else{
					id=Q.top().lval.vp->n;
					p=Q.top().lval.vp->pos;
					(*(*vect_l)[*id].values) [p]=v;
				}
				
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			case ADD_ATR:
				if(Q.top().tk==NUM) v=Q.top().lval.value;
				else if(Q.top().tk==VECTOR_POS)
				v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
				else v=(*var)[*Q.top().lval.name];
				
				Q.pop();
				
				if(Q.top().tk==ID || Q.top().tk==VAR){
					id=Q.top().lval.name; 
					if(Q.top().tk==ID) (*isvar)[*id]=true;
					v=((*var)[*id]+=v);
				}else{
					id=Q.top().lval.vp->n;
					p=Q.top().lval.vp->pos;
					v=((*(*vect_l)[*id].values) [p]+=v);
				}
				
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			case SUB_ATR:
				if(Q.top().tk==NUM) v=Q.top().lval.value;
				else if(Q.top().tk==VECTOR_POS)
				v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
				else v=(*var)[*Q.top().lval.name];
				
				Q.pop();
				
				if(Q.top().tk==ID || Q.top().tk==VAR){
					id=Q.top().lval.name; 
					if(Q.top().tk==ID) (*isvar)[*id]=true;
					v=((*var)[*id]-=v);
				}else{
					id=Q.top().lval.vp->n;
					p=Q.top().lval.vp->pos;
					v=((*(*vect_l)[*id].values) [p]-=v);
				}
				
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			case MOD_ATR:
				if(Q.top().tk==NUM) v=Q.top().lval.value;
				else if(Q.top().tk==VECTOR_POS)
				v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
				else v=(*var)[*Q.top().lval.name];
				
				Q.pop();
				
				if(Q.top().tk==ID || Q.top().tk==VAR){
					id=Q.top().lval.name; 
					if(Q.top().tk==ID) (*isvar)[*id]=true;
					v=fmod((*var)[*id],v);
					(*var)[*id]=v;
				}else{
					id=Q.top().lval.vp->n;
					p=Q.top().lval.vp->pos;
					v=fmod((*(*vect_l)[*id].values) [p],v);
					(*(*vect_l)[*id].values) [p]=v;
				}
				
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			case MUL_ATR:
				if(Q.top().tk==NUM) v=Q.top().lval.value;
				else if(Q.top().tk==VECTOR_POS)
				v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
				else v=(*var)[*Q.top().lval.name];
				
				Q.pop();
				
				if(Q.top().tk==ID || Q.top().tk==VAR){
					id=Q.top().lval.name; 
					if(Q.top().tk==ID) (*isvar)[*id]=true;
					v=((*var)[*id]*=v);
				}else{
					id=Q.top().lval.vp->n;
					p=Q.top().lval.vp->pos;
					v=((*(*vect_l)[*id].values) [p]*=v);
				}
				
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			case DIV_ATR:
				if(Q.top().tk==NUM) v=Q.top().lval.value;
				else if(Q.top().tk==VECTOR_POS)
				v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
				else v=(*var)[*Q.top().lval.name];
				
				Q.pop();
				
				if(Q.top().tk==ID || Q.top().tk==VAR){
					id=Q.top().lval.name; 
					if(Q.top().tk==ID) (*isvar)[*id]=true;
					v=((*var)[*id]/=v);
				}else{
					id=Q.top().lval.vp->n;
					p=Q.top().lval.vp->pos;
					v=((*(*vect_l)[*id].values) [p]/=v);
				}
				
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			case FUNCTION_CALL:
				f=&function_l[*it->lval.name];
				n=f->narg-1;
				while(n>-1){
					if((*f->args_t)[n]==1){
						f->vect_l[(*f->args_name)[n]]=(*vect_l)[*Q.top().lval.name];
					}else{
						if(Q.top().tk==NUM) v=Q.top().lval.value;
						else if(Q.top().tk==VECTOR_POS)
						v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
						else v=(*var)[*Q.top().lval.name];
						f->var[(*f->args_name)[n]]=v;
					}
					n--;
					Q.pop();
				}
				fvar=f->var;
				fvect=&f->vect_l;
				v=interp(&fvar, isvar, isclass, isobj, yaelClass, yaelObj,fvect,isvect, f->f);
				Q.push(Token(NUM,v));
			break;
			
			case POW_ATR:
				if(Q.top().tk==NUM) v=Q.top().lval.value;
				else if(Q.top().tk==VECTOR_POS)
				v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
				else v=(*var)[*Q.top().lval.name];
				
				Q.pop();
				
				if(Q.top().tk==ID || Q.top().tk==VAR){
					id=Q.top().lval.name; 
					if(Q.top().tk==ID) (*isvar)[*id]=true;
					v=pow((*var)[*id],v);
					(*var)[*id]=v;
				}else{
					id=Q.top().lval.vp->n;
					p=Q.top().lval.vp->pos;
					v=pow((*(*vect_l)[*id].values) [p],v);
					(*(*vect_l)[*id].values) [p]=v;
				}
				
				Q.pop();
				Q.push(Token(NUM,v));
			break;
			
			//Operacoes algebricas
			default:
				n=it->lval.narg-1;
				while(n>-1){
					if(Q.top().tk==NUM) v=Q.top().lval.value;
					else if(Q.top().tk==VECTOR_POS)
					v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
					else v=(*var)[*Q.top().lval.name];
					args[n]=v;
					Q.pop();
					n--;
				}
				
				Q.push(Token(NUM,fdL[it->lval.narg][it->tk](args)));
			break;
			
		}
	}
	
	if(Q.top().tk==NUM) v=Q.top().lval.value;
	else if(Q.top().tk==VECTOR_POS)
	v=(*(*vect_l)[*Q.top().lval.vp->n].values) [Q.top().lval.vp->pos];
	else v=(*var)[*Q.top().lval.name];
	Q.pop();
	
	if(!Q.empty()) printf("Warning: stack non-empty!!\n");
	return v;
}

