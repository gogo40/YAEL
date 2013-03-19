/* 
maxwell
fun��es uteis maxwell_db
Autor: P�ricles Lopes Machado
*/

#include "maxwell_db.h"

/*
Formato de arquivo name.sago:

Numero de classes:NC
Segue-se NC defini��es de classes:{
	Nome da classe:name_class   numero campos:n
	Segue-se n defini��es dos campos da classe:{
		Nome do campo numero:name_field  linhas do campo:m dim do campo: nx ny nz tam 
		Segue-se m linhas com as defini��es de cada linha do campo name_field:{
			numero_colunas: p
			em seguida temos os p valores da linha em quest�o
		}
	}
}

Numero de Objetos:NO
Segue-se NO defini��es de objetos:{
	Nome do objeto: name_obj Nome da classe do objeto: name_class 3 doubles: x, y, z
}
*/
	
void loadFile(const char* fname, map<string,sclass>& maxwellClass, map<string,bool>& isclass, 
				map<string,sobj>& maxwellObj, map<string,bool>& isobj, string& __path
			)
{
	
	ifstream* f = new ifstream((__path+"/"+fname).c_str());
	ifstream* P = new ifstream(fname);
	
	if(f->fail()){
		if(P->fail()){
			cerr<<"Falha ao abrir:"<<fname<<endl;
			cout<<"Caminho:"<<__path<<endl;
			exit(-1);
			return;
		}else f=P;
	}
	
	int NC, i, j, k, l, n, m, p;
	sclass* v; sobj* w; Matrix* pm;
	double val; string name;

	int nx, ny, nz, tam, ini_p;
	//Ler numero de classe
	(*f)>>NC;
	for(i=0;i<NC;i++){
		//Ler nome da classe e numero de campos
		(*f)>>name>>n;
		isclass[name]=true;
		v=&maxwellClass[name];
		
		for(j=0;j<n;j++){
			//Ler campo j da classe i  e numero de linhas do campo j
			(*f)>>name>>m>>nx>>ny>>nz>>tam>>ini_p;
			pm=new Matrix(m);
			for(k=0;k<m;k++){
				//Ler numero de colunas do campo p
				(*f)>>p;
				(*pm)[k]=new Vector(p);
				
				for(l=0;l<p;l++){
					(*f)>>val;
					(*(*pm)[k])[l]=val;
				}
			}
			v->field[name].first= pm;
			v->field[name].second=new sf(nx,ny,nz,tam,ini_p);
		}
	}
	
	//Ler numero de objetos
	(*f)>>NC;
	for(i=0;i<NC;i++){
		//Ler nome do objeto , pai, x, y, z
		(*f)>>name;
		isobj[name]=true; w=&maxwellObj[name];
		(*f)>> w->pai >> w->x >> w->y >>w->z;
	}
	
	f->close();
}

void saveFile(const char* fname, 
				map<string,sclass>& maxwellClass,  
				map<string,sobj>& maxwellObj
			)
{
	ofstream f(fname);
	
	if(f.fail()){
		cerr<<"Falha ao abrir:"<<fname<<endl;
		exit(-1);
		return;
	}
	
	f<<maxwellClass.size()<<endl;
	
	int i, j;
	int nx, ny, nz, tam;
	Matrix* m;
	sf* s;
	
	for(map<string, sclass>::iterator it=maxwellClass.begin();
		it!=maxwellClass.end();it++){
		
		f<<it->first<<" "<<it->second.field.size()<<endl;
		
		for(map<string, pair<Matrix*,sf*> >::iterator it2=it->second.field.begin(); 
		    it2!= it->second.field.end();it2++){
			m=it2->second.first;
			s=it2->second.second;
			f<<it2->first<<" "<<m->size()<<" "<<s->nx<<" "<<s->ny<<" "<<s->nz<<" "<<s->tam<<" "<<s->ini_p<<endl;

			for(i=0;i<m->size();i++){
				f<<(*m)[i]->size();
				for(j=0;j<(*m)[i]->size();j++)
					f<<" "<<(*(*m)[i])[j];
				f<<endl;
			}
		}
		
	}
	
	f<<maxwellObj.size()<<endl;
	for(map<string,sobj>::iterator it=maxwellObj.begin();
		it!=maxwellObj.end(); it++){
		f<<it->first<<" "<<it->second.pai<<" "<<
			it->second.x<<" "<<it->second.y<<" "<<it->second.z<<endl;
	}
	f.close();
}

