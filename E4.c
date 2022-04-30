#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){	
	int i;
	char **v;
	char *buff;
	int cantNomb;
	buff=(char*)malloc(50*sizeof(char));
	
	printf("por favor ingrese la cantidad de nombres");

	scanf("%d",&cantNomb);
	fflush(stdin);
	
	v=(char**)malloc((cantNomb)*sizeof(char*));
	
	for( i=0;i<cantNomb;i++){
		printf("ingrese el nombre num : %d ",i+1);
		gets(buff);
		v[i]=(char*)malloc((strlen(buff)+1)*sizeof(char));
		strcpy(v[i],buff);			
	}
	
	for( i=0;i<cantNomb;i++){
		printf("%d: ",i+1);
		puts(v[i]);		
	}
	for(i=cantNomb-1;i>=0;i--){
		free(v[i]);
		//de esta manera no pierdo el puntero que debo liberar
	}	
	free(buff);

	return 0;
}

