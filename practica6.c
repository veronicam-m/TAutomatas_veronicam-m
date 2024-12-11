#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
int expresionValida(const char *cadena);
int expresionRegular(const char *cadena);
int enteroSigno(const char *str);

int main(){
	int opcion;
	char cadena[100];
	char str[100];
	do{
		printf(" \nPOR FAVOR, SELECCIONE EL TIPO DE EXPRESION QUE DESEE VALIDAR:\n");
		printf(" 1. L=(ab)+ c(de)*\n 2. L=(ab)+ c*(de)*\n 3. E=(+|-|e)D+\n 4.SALIR\n Opcion: ");
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				printf(" Ingrese una cadena: ");
				scanf("%s", cadena);
				if(expresionRegular(cadena)){
					printf(" \nLa cadena:%s es valida para la expresion L=(ab)+ c(de)*\n",cadena);
				}else{
					printf(" \nLa cadena:%s no es valida para la expresion L=(ab)+ c(de)*\n",cadena);
				}
				break;
			case 2:
				printf(" Ingrese una cadena: ");
				scanf("%s", cadena);
				if(expresionValida(cadena)){
					printf(" \nLa cadena:%s es valida para la expresion L=(ab)+ c*(de)*\n",cadena);
				}else{
					printf(" \nLa cadena:%s no es valida para la expresion L=(ab)+ c*(de)*\n",cadena);
				}
				break;
			case 3:
				printf(" Por favor ingrese la cadena numerica que desee validar: ");
				scanf(" %s", str);
				if(enteroSigno(str)){
					printf(" %s, es un entero con signo valido.\n", str);
				}else{
					printf(" %s, no es un entero con signo valido.\n", str);
				}
				break; 
			default:
				printf("Opcion no valida");
				break;
			}
		}while(opcion!=4);
		return 0;
	}

			
	

int expresionValida(const char *cadena){
	int i=0; 
	while(cadena[i]=='a' && cadena[i+1]=='b'){
		i+=2;
	}
	if(i==0){
		return 0;
	}
	while(cadena[i]=='c'){
		i++;
	}
	while(cadena[i]=='d' && cadena[i+1]=='e'){
		i+=2; 
	}
	return cadena[i]=='\0';
}

int expresionRegular(const char *cadena){
    int i=0;
    while(cadena[i]=='a' && cadena[i+1]=='b'){
        i+=2;
    }
    if(i==0){
        return 0;
    }
    while(cadena[i]=='c'){
        i++;
    }
    while(cadena[i]=='d' && cadena[i+1]=='e'){
        i+=2;
    }
    return cadena[i]=='\0';
}

int enteroSigno(const char *str){
    if (*str=='\0') {
        return FALSE;
    }
    if (*str=='+' || *str=='-'){
        str++;
    }
    if (!isdigit(*str)){
        return FALSE;
    }
    while (*str){
        if (!isdigit(*str)){
            return FALSE;
        }
        str++;
    }
    return TRUE;
}



	
	


	

