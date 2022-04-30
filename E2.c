#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){	
	int i;
	char *v[5];//vector de punteros 
	char *buff;
	buff=(char*)malloc(50*sizeof(char));
	
	printf("por favor ingrese 5 nombres\n");
	for( i=0;i<=4;i++){
		gets(buff);//tomo por pantalla
		v[i]=(char*)malloc((strlen(buff)+1)*sizeof(char));// tb se debe contar el \0
		//por cada puntero debo reservar memoria
		strcpy(v[i],buff);		
	}
	for( i=0 ;i<=4;i++){
		puts(v[i]);
	}
	for( i=0 ;i<=4;i++){
		free(v[i]);
	}
		
//deberia liberar por cada puntero
	free(buff);
	return 0;
}


/*
	char *ptr=null; 
	char *nombre1;
	ptr=(char*)malloc(tamañopuntero*sizeof(char));
	//malloc manda un puntero de tipo void, pero con el casteo transformo a char
	nombre1=(char*)malloc((strlen(ptr)+1)*sizeof(char));
	strcpy(nombre1,ptr);//forma de copiar sin que se pierda la memoria reservada
	//comandos 
	
		puts(cadena) -- escribe el contenido del puntero o variable
		gets(frase)  captura la cadena completa 
	
*/

