/* 
yael
Lexer yael_lexer
Autor: Péricles Lopes Machado
*/
DIGIT    [0-9]
ID       [a-zA-Z_][_A-Za-z0-9]*

%%

{DIGIT}+("."{DIGIT}*)?(("e"|"E")("+"|"-")?{DIGIT}+)?    {
				sscanf(yytext,"%lf",&yylval.val);
				//intf("NUM=%lf\n",yylval.val);
				return NUM;
			}

"\""[^\"]*"\"" {  yylval.str=new string(yytext+1); 
					(*yylval.str)[yylval.str->size()-1]='\0'; 
					return STRING; 
				}

"\'"[^\']*"\'" {  yylval.str=new string(yytext+1); 
					(*yylval.str)[yylval.str->size()-1]='\0'; 
					return STRING; 
				}

do		{ return DO; }
for		{ return FOR; }
if		{ return IF; }
else 	{ return ELSE; }
while 	{ return WHILE; }
using 	  { return USE; }
"return" { return RETURN; }
exec { return EXEC; }
"<>"    { return READ; }
print { return PRINT; }
echo  { return ECHO_; }
real { return REAL; }
vector { return VECTOR; }
function { return FUNCTION; }
break { return BREAK; }
continue { return CONTINUE; }
class     { return CLASS; }

"and"|"&&"    { return AND; }
"or"|"||"     { return OR; }
"not"|"!"|"~" { return NOT; }

"<="      	  { return LEQ; }
">="		  { return GEQ; }
"!="		  { return DIFF; }
"=="		  { return EQ; }
"+="		  { return ADD_ATR; }
"-="		  { return SUB_ATR; }
"*="		  { return MUL_ATR; }
"/="		  { return DIV_ATR; }
"%="		  { return MOD_ATR; }
"^="		  { return POW_ATR; }
"++"		  { return INC; }
"--"		  { return DEC; }
 
"+"|"-"|"*"|"/"|"^"|","|";"|"{"|"}"|"["|"]"|":"|"<"|">"|"("|")"|"="|"?"|"%"   { return yytext[0]; }

"//"[^\n]*      {/* eat up one-line comments */ }

"#"[^\n]*       {/* eat up one-line comments */  }

[ |\t|\n]   { /* eat up whitespace */  if(yytext[0]=='\n'){ nlines++; } }

{ID}		{	yylval.str=new string(yytext);
				if(isvect[yytext]) return VECTOR_ID;
				if(is_bultin_func[yytext]) return BUILT_IN_FUNC;
				if(isclass[yytext]) return CLASS_ID;
				if(isobj[yytext]) return OBJ_ID;
				if(isvar[yytext]) return VAR;
				return ID;
			}

.          {  }

%%
