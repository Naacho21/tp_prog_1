#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "calculosAux.h"

int menu()
{
	int opcion;

    printf("  *** Menu de Opciones *** \n"
           "1-Ingrese Kilometros\n"
           "2-Ingrese el precio del vuelo\n"
           "3-Calculo de costos\n"                       //Menu de opciones, ingresar una opcion
           "4-Informe de resultados\n"
           "5-Carga forzada de datos\n"
           "6-Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    fflush(stdin);

    return opcion;
}

int opcionUno(float kilometros)
{
	float auxKilometros = 0;
	int banderaKm = 0;
                                                        //si kilometros es menor a 0, se invalida y repite
    do
    {
    	printf("Ingrese kilometros: \n");
    	fflush(stdin);
    	scanf("%f", &auxKilometros);

    	if(auxKilometros < 0)
    	{
    		printf("Error. Los kilometros ingresados no son validos.");
    		banderaKm = 1;
    	}
    	else
    	{
    		banderaKm = 0;
    		auxKilometros = kilometros;
    	}

    }while(banderaKm == 1);

    return kilometros;
}

int opcionDos(float* aerolineas, float* latam)
{
	int todoOk = 0;
    int eleccionDeVuelo;
    float precioVueloAerolineas;
    float precioVueloLatam;
    int banderaVuelo = 5;
    int bandera = 0;

    banderaVuelo = banderaVuelo +1;


    do
    {
        printf("Elige una aerolinea de vuelo(Aerolíneas = 1, Latam = 2): \n");
        scanf("%d", &eleccionDeVuelo);

        	if(eleccionDeVuelo > 2)
                {
                    printf("Error. Intente reingresar la opcion de nuevo. Le quedan %d intentos\n", banderaVuelo);
                    banderaVuelo = banderaVuelo - 1;
                }

        switch(eleccionDeVuelo )
        {
            case 1:    printf("Ingrese el precio del vuelo de Aerolineas: \n");
            			fflush(stdin);
                        scanf("%f", &precioVueloAerolineas);
                        bandera = 1;
            break;

            case 2:   printf("Ingrese el precio del vuelo de Latam: \n");
            			fflush(stdin);
            			scanf("%f", &precioVueloLatam);
            			bandera = 1;
            break;

        }

        if(bandera == 1)
        {
        	*aerolineas = precioVueloAerolineas;
        	*latam = precioVueloLatam;
        	todoOk = 1;
        }



    }while(bandera!=1);


    return todoOk;
}

void opcionTres(float bitcoin, int interesValor, int porcentaje, float aerolineas, float latam, float kilometros, float* descuentoAerolineas,
               float* interesAerolineas, float* valorBitcoinAerolineas, float* precioUnitarioAerolineas, float* descuentoLatam,
               float* interesLatam, float* valorBitcoinLatam, float* precioUnitarioLatam, float* diferenciaIngresadaTotal)
{


    *descuentoAerolineas = descuento(porcentaje, aerolineas);                     //AEROLINEAS
    *interesAerolineas = interes(interesValor, aerolineas);
    *valorBitcoinAerolineas = pasajeBTC(bitcoin, aerolineas);
    *precioUnitarioAerolineas = valorUnitario(aerolineas, kilometros);

    *descuentoLatam = descuento(porcentaje, latam);                     //LATAM
    *interesLatam = interes(interesValor, latam);
    *valorBitcoinLatam = pasajeBTC(bitcoin, latam);
    *precioUnitarioLatam = valorUnitario(latam, kilometros);

    																	//aerolineas y latam
    *diferenciaIngresadaTotal = diferenciaDeValores(aerolineas, latam);


    printf("Costos realizados:\n"
           "a) Tarjeta de débito \n"
           "b) de crédito \n"
           "c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
           "d) Mostrar precio por km (precio unitario)\n"
           "e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n\n");

    system("pause");



}

void informarResultados(float descuentoAerolineas, float interesAerolineas, float valorBitcoinAerolineas,
                        float precioUnitarioAerolineas, float descuentoLatam, float interesLatam, float valorBitcoinLatam,
                        float precioUnitarioLatam, float diferenciaIngresadaTotal)
{

    printf("Aerolineas:\n"
            "a) Precio con tarjeta de débito: $%.2f\n"
            "b) Precio con tarjeta de crédito: $%.2f\n"
            "c) Precio pagando con bitcoin : %.2f BTC\n"
            "d) Precio unitario: $%.2f\n"

            "Latam: \n"
            "a) Precio con tarjeta de débito: $%.2f\n"
            "b) Precio con tarjeta de crédito: $%.2f\n"
            "c) Precio pagando con bitcoin: %.2f BTC\n"
            "d) Precio unitario: $%.2f\n"

            "La diferencia de precio es: $%.2f\n", descuentoAerolineas, interesAerolineas, valorBitcoinAerolineas,
                    precioUnitarioAerolineas, descuentoLatam, interesLatam, valorBitcoinLatam, precioUnitarioLatam,
                    diferenciaIngresadaTotal);

    system("pause");


}

void cargaForzadaDeDatos (float* kilometros, float* aerolineas, float* latam, int porcentaje, float bitcoin, int interesValor)
{

    float descuentoAerolineas;
    float interesAerolineas;
    float valorBitcoinAerolineas;
    float precioUnitarioAerolineas;
    float descuentoLatam;
    float interesLatam;
    float valorBitcoinLatam;
    float precioUnitarioLatam;
    float diferenciaIngresadaTotal;
    float auxKilometros;
    float auxAerolineas;
    float auxLatam;

    *kilometros = 7090;
    *aerolineas = 162965;
    *latam = 159339;


    auxKilometros = *kilometros;
    auxAerolineas = *aerolineas;
    auxLatam = *latam;

    descuentoAerolineas = descuento(porcentaje, auxAerolineas);
    interesAerolineas = interes(interesValor, auxAerolineas);
    valorBitcoinAerolineas = pasajeBTC(bitcoin, auxAerolineas);
    precioUnitarioAerolineas = valorUnitario (auxAerolineas, auxKilometros);

    descuentoLatam = descuento(porcentaje, auxLatam);
    interesLatam = interes(interesValor, auxLatam);
    valorBitcoinLatam = pasajeBTC(bitcoin, auxLatam);
    precioUnitarioLatam = valorUnitario (auxLatam, auxKilometros);

    diferenciaIngresadaTotal = diferenciaDeValores(auxAerolineas, auxLatam);

   printf("Aerolineas:\n"
                    "a) Precio con tarjeta de débito: $%.2f\n"
                    "b) Precio con tarjeta de crédito: $%.2f\n"
                    "c) Precio pagando con bitcoin : %.2f BTC\n"
                    "d) Precio unitario: $%.2f\n"
                "Latam: \n"
                    "a) Precio con tarjeta de débito: $%.2f\n"
                    "b) Precio con tarjeta de crédito: $%.2f\n"
                    "c) Precio pagando con bitcoin: %.2f BTC\n"
                    "d) Precio unitario: $%.2f\n"
                    "La diferencia de precio es: $%.2f\n", descuentoAerolineas, interesAerolineas, valorBitcoinAerolineas,
                    precioUnitarioAerolineas, descuentoLatam, interesLatam, valorBitcoinLatam, precioUnitarioLatam,
                    diferenciaIngresadaTotal);

   system("pause");


}
