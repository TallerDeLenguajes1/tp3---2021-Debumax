#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Producto {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef TProductos;

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int Cantprod; // (aleatorio entre 1 y 5)
TProductos *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
}typedef Tclientes;

char *TiposProductos[]={"Galleta","Snack","Cigarrillos","Caramelos","Bebidas"};


void cargaClientes(Tclientes *clientes,int cantClientes);
void mostrarDatosClientes(Tclientes *clientes ,int  cantClientes);


int main(){
	
	int cantClientes;
	int i,c,p ;
	
	printf("ingrese la cantidad de clientes\n");
	scanf("%d",&cantClientes);
	fflush(stdin);
	
	Tclientes clientes[cantClientes];
	cargaClientes(clientes,cantClientes);
	mostrarDatosClientes(clientes, cantClientes);

	return 0;
}
	
void cargaClientes(Tclientes *clientes,int cantClientes){
	int i;
	int j;
	
	for(i=0;i<cantClientes;i++){
		clientes[i].ClienteID=i;
		char *buff;
		buff=(char*)malloc(50*sizeof(char));
		printf("ingrese el nombre del cliente\n");
		gets(buff);
		clientes[i].NombreCliente=(char*)malloc(strlen(buff+1)*sizeof(char));//reservo memoria porque es un puntero
		strcpy(clientes[i].NombreCliente,buff);
		free(buff);
				
		clientes[i].Cantprod=rand()%5+1;
		clientes[i].Productos=(TProductos*)malloc(clientes[i].Cantprod*sizeof(TProductos));//resrevo memoria xq es puntero

		for (j=0;j<clientes[i].Cantprod;j++){
			clientes[i].Productos[j].ProductoID=j;
			clientes[i].Productos[j].Cantidad=rand()%10+1;
			int ind=rand()%5;
			clientes[i].Productos[j].TipoProducto=TiposProductos[ind];//direccion de memoria del elemento
			clientes[i].Productos[j].PrecioUnitario=rand()%90+10;
			
			
		}
	}
}	




void mostrarDatosClientes(Tclientes *clientes ,int  cantClientes){
	int i,j;
	for(i=0;i<cantClientes;i++){
		printf("cliente Id: %d\n",clientes[i].ClienteID);
		printf("nombre cliente: %s\n",clientes[i].NombreCliente);
		printf("cantidad de productos: %d\n",clientes[i].Cantprod);
		
		for(j=0;j<clientes[i].Cantprod;j++){
			printf("\n");
			printf("     id poducto: %d\n",clientes[i].Productos[j].ProductoID);
			printf("     cantidad del producto: %d\n",clientes[i].Productos[j].Cantidad);
			printf("     tipo de prodcuto: %s\n",clientes[i].Productos[j].TipoProducto);
			printf("     precio: %f\n",clientes[i].Productos[j].PrecioUnitario);
			printf("\n");
			printf("****\n");
			printf("\n");
		
		}
		printf("----------------\n");
	}
	printf("\n");
}



