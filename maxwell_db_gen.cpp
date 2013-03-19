/* 
maxwell
gerador de entradas pro maxwell do maxwell_db
Autor: P�ricles Lopes Machado
*/

#include "maxwell_db.h"
#include <string.h>

int main(int argc, char** argv)
{
	argc--; argv++;
	if(argc<1){
		printf("Formato: %s <file_in>\n",argv[-1]);
		printf("<file_in>:1  arquivo de entrada\n");
		return 0;
	}

	map<string, sf> field;
	map<string, ofstream*> files;
	Matrix* m; sf* s;
	int dx, dy, dz, i, j, k, l;
	ofstream* out;
	string file_in("");
	
	for(int nn=0;nn<argc;nn++){
		int len=strlen(argv[nn]);
		
		if(nn>0) file_in+=string(" ");
		file_in+=string(argv[nn]);
	}
	
	map<string, bool> isobj;
	map<string, sobj> maxwellObj;
	map<string, bool> isclass;
	map<string, sclass> maxwellClass;
	string ___path("");
	___path="";
	for(l=file_in.size()-1;l>-1&&(file_in[l]!='/'&&file_in[l]!='\\');l--);
	for(int k=0;k<file_in.size()&&k<l;k++) ___path+=file_in[k];
	printf("Caminho:%s\n",___path.c_str());
	
	loadFile(file_in.c_str(),maxwellClass, isclass,maxwellObj,isobj,___path);
	
	for(map<string,sclass>::iterator it=maxwellClass.begin();
		it!=maxwellClass.end();it++)
		for(map<string,pair<Matrix*,sf*> >::iterator p=it->second.field.begin();
			p!=it->second.field.end();p++)
			if(files.find(p->first) == files.end()){
				files[p->first]= new ofstream((___path+"/"+p->first+".in").c_str());
				field[p->first]= *(p->second.second);
			}
	
	for(map<string,sobj>::iterator it=maxwellObj.begin();
		it!=maxwellObj.end();it++){
		
		sclass* pai=&maxwellClass[it->second.pai];
		dx=(int)(it->second.x); 
		dy=(int)(it->second.y); 
		dz=(int)(it->second.z);
		
		for(map<string,pair<Matrix*,sf*> >::iterator p=pai->field.begin();
			p!=pai->field.end();p++){
			
			m=p->second.first; s=p->second.second;
			out=files[p->first];
			
			for(i=0;i< m->size();i++){
				for(j=0;j<(*m)[i]->size()&& j<s->ini_p;j++ ) 
					(*out)<<(* (*m)[i])[j]<<" ";

				for(k=0;k<s->nx && j< (*m)[i]->size();k++, j++){
					if( (* (*m)[i])[j] != 0) (*out)<< (* (*m)[i])[j] + dx<<" ";
					else (*out)<< (* (*m)[i])[j] <<" ";
				}
				for(k=0;k<s->ny && j< (*m)[i]->size();k++, j++){
					if((* (*m)[i])[j] != 0) (*out)<< (* (*m)[i])[j] + dy<<" ";
					else (*out)<< (* (*m)[i])[j] <<" ";
				}
				for(k=0;k<s->nz && j< (*m)[i]->size();k++, j++){
					if((* (*m)[i])[j] != 0)  (*out)<< (* (*m)[i])[j] + dz<<" ";
					else (*out)<< (* (*m)[i])[j] <<" ";
				}

				for(;j<(*m)[i]->size()&& j<s->tam;j++ ) (*out)<<(* (*m)[i])[j]<<" ";
				for(;j<(*m)[i]->size();j++) (*out)<<0<<" ";
				
				(*out)<<endl;
			}
		}
	}
	
	map<string,sf>::iterator ps=field.begin();
	for(map<string, ofstream*>::iterator it=files.begin();
		it!=files.end();it++,ps++){
		out=it->second;
		s=&(ps->second);
			
		(*out)<<"-1";
		for(i=1;i<s->tam;i++) (*out)<<" 0";
		(*out)<<endl;
			
		it->second->close();
		delete it->second;
	}
		
	return 0;
}

