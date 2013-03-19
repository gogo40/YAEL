/* 
maxwell
Interpretador de intruções maxwell_db
Autor: Péricles Lopes Machado
*/

#include "maxwell_db.h"


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
){
	double v;
	int i;
	bool isbreak, iscontinue;
	iToken* ip;
	ip=&(*in)[0];
	v=0; i=0; isbreak=iscontinue=false;
	for(;;){
		if(i==in->size()) return 0;
		ip=&(*in)[i];
		switch(ip->tk){
		
			case BREAK:
				isbreak=true;
				i+=ip->next;
			break;
			
			case CONTINUE:
				iscontinue=true;
				i+=ip->next;
			break;
			
			case IF:
				v=eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.ifelse->expr);
				if(cmp(v,0)==0 || isbreak || iscontinue) i+=ip->lval.ifelse->false_next;
				else i+=ip->next;
			break;
			
			case WHILE:
				v=eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.while_->expr);
				if(cmp(v,0)==0 || isbreak){ i+=ip->lval.while_->false_next; isbreak=iscontinue=false;  }
				else { i+=ip->next;iscontinue=false;}
			break;
			
			case END_WHILE:
				i+=ip->next;
				ip=&(*in)[i];
				v=eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.while_->expr);
				if(cmp(v,0)==0 ||isbreak) { i+=ip->lval.while_->false_next; isbreak=iscontinue=false; }
				else { i+=ip->next; iscontinue=false;}
			break;
			
			case END_FOR:
				if(iscontinue){
					i--;
					ip=&(*in)[i];
					eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.expr);
					i++;
					ip=&(*in)[i];
				}
				i+=ip->next;
				ip=&(*in)[i];
				v=eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.while_->expr);
				if(cmp(v,0)==0 ||isbreak) { i+=ip->lval.while_->false_next; isbreak=iscontinue=false; }
				else { i+=ip->next; iscontinue=false;}
			break;
			
			case EXPR:
				if(!(isbreak||iscontinue))
					eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.expr);
				i+=ip->next;
			break;
			
			case BUILD_OBJ:
				if(!(isbreak||iscontinue)){
					build_o(ip->lval.obj,var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect);
				}
				i+=ip->next;
			break;
			
			case PRINT:
				if(!(isbreak||iscontinue)){
					printf("%lf",eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.expr));
					fprintf(pout,"%lf",eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.expr));
				}
				i+=ip->next;
			break;
			
			case PRINTS:
				if(!(isbreak||iscontinue)){
					printf("%s",ip->lval.str->c_str());
					fprintf(pout,"%s",ip->lval.str->c_str());
				}
				i+=ip->next;
			break;
			
			case ECHO_:
				if(!(isbreak||iscontinue)){
					printf("%lf\n",eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.expr));
					fprintf(pout,"%lf\n",eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.expr));
				}
				i+=ip->next;
			break;
			
			case ECHOS:
				if(!(isbreak||iscontinue)){
					printf("%s\n",ip->lval.str->c_str());
					fprintf(pout,"%s\n",ip->lval.str->c_str());
				}
				i+=ip->next;
			break;
			
			case RETURN:
				if(!(isbreak||iscontinue)){
					v=eval(var, isvar, isclass, isobj, maxwellClass, maxwellObj, vect_l,isvect,ip->lval.expr);
					return v;
				}
				i+=ip->next;
			break;
			
		}
	}
}

