#include <stdio.h>
#include <string.h>
#include <ctype.h>

void analizarDigito (char numero[]);

int main(){
	char numero[50]; 
	printf("Por favor ingrese un numero: "); 
	scanf("%s", numero); 
	
	analizarDigito(numero); 
	
	return 0;
}
	

void derivar (char entero[], char decimale[], char signo){
	printf("F -> Es . En\n");
	
	if (signo=='+' || signo=='-'){
		printf("-> SEn . En\n");
		printf("-> %cEn . En\n", signo);
	}else{
		printf("-> SEn . En\n");
		printf("-> En . En\n");
	}
	printf("-> %cDR . En\n", signo);
	
	for (int i=0; entero[i]!='\0'; i++){
		printf("-> %c", signo);
		for (int j=0; j<=i; j++){
			printf("%c", entero[j]);
		}
		printf("R . En\n");
		
		if (entero[i+1]!='\0'){
			printf("-> %c", signo); 
			for(int j=0; j<=i; j++){
				printf("%c", entero[j]);
			}
			printf("DR . En\n");
		}
	}
	printf("-> %c%s . En\n", signo, entero);
	printf("-> %c%s . DR\n", signo, entero);
	
	char aux[50]="";
	int indice=0;
	
	for (int i=0; decimale[i]!='\0'; i++){
		aux[indice++]=decimale[i];
		aux[indice]='\0'; 
		printf("-> %c%s . %sR\n", signo, entero, aux);
		
		if (decimale[i+1] != '\0'){
			printf("-> %c%s . %sDR\n", signo, entero, aux);
		}
	}
	printf("-> %c%s . %s\n", signo, entero, decimale);
}

void analizarDigito (char numero[]){
	char entero[50]= ""; 
	char decimal[50]= ""; 
	char signo= '\0';
	int i=0, j=0, k=0; 
	
	if (numero[i]=='+' || numero[i]=='-'){
		signo=numero[i]; 
		i++;
	}else{ 
		signo='+'; 
	}
	
	while (numero[i]!='.' && numero[i]!='\0'){
		entero[j++]=numero[i++]; 
	}
	entero[j]='\0'; 
	
	if (numero[i]=='.'){
		i++;
		while (numero[i]!='\0'){
			decimal[k++]=numero[i++];
		}
	}
	decimal[k]='\0';
	
	derivar(entero, decimal, signo); 
}
	
			 
	
		
		
	
	
	
	
