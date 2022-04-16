#include <stdio.h>
#include <stdlib.h>

#include "calculos.h"

int menu()
{
    int opcion;

    printf("  *** Menu de Opciones *** \n"
           "1-Ingrese Kilometros\n"
           "2-Ingrese el precio del vuelo\n"
           "3-Calculo de costos\n"                       //Menu de opciones, ingresar una opcion
           "4-Informe de resultados\n"
           "5-Carga forzada de datos\n"
           "6-Salir");

    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int opcionUno(float kilometros, int* banderaValidacionKm)
{
                                       //Se ingresan los kilometros

    printf("Ingrese kilometros: \n");
    scanf("%f.02", &kilometros);

                                                        //si kilometros es menor a 0, se invalida y repite
    while(kilometros<0)
    {
        printf("Error. Reingrese los kilometros: \n");
        scanf("%f.02", &kilometros);
    }

    banderaValidacionKm++;

    return kilometros;
}

int opcionDos(float precioIngresado, int* banderaValidacionVuelo)
{
    int eleccionDeVuelo;
    float precioVuelo;
    int banderaVuelo = 5;

                                                    //Se elige la aerolinea de vuelo, solo 5 intentos
    do
    {
        if(banderaVuelo < 5)
        {
            printf("Error. Intente reingresar la opcion de nuevo. Le quedan %d intentos\n", banderaVuelo);
        }

        printf("Elige una aerolinea de vuelo(Aerolíneas = 1, Latam = 2): \n");
        scanf("%d", &eleccionDeVuelo);

        switch(eleccionDeVuelo)
        {
            case 1:    printf("Ingrese el precio del vuelo de Aerolineas: \n");
                        scanf("%f", &precioVuelo);
            break;

            case 2:   printf("Ingrese el precio del vuelo de Latam: \n");
                        scanf("%f", &precioVuelo);
            break;
        }

        banderaVuelo--;

    }while(eleccionDeVuelo!=1 || eleccionDeVuelo!=2 || banderaVuelo>5);

    banderaValidacionVuelo++;
    precioVuelo = precioIngresado;

    return eleccionDeVuelo;
}

void opcionTres(int* banderaValidacionCalculos, float bitcoin, int interesValor, int porcentaje, float aerolineas, float latam, float kilometros, float* descuentoAerolineas,
               float* interesAerolineas, float* valorBitcoinAerolineas, float* precioUnitarioAerolineas, float* descuentoLatam,
               float* interesLatam, float* valorBitcoinLatam, float* precioUnitarioLatam, float* diferenciaIngresadaTotal)
{

    *descuentoAerolineas = descuento(porcentaje, aerolineas);                     //AEROLINEAS
    *interesAerolineas = interes(interesValor, aerolineas);
    *valorBitcoinAerolineas = pasajeBTC(bitcoin, aerolineas);
    *precioUnitarioAerolineas = valorUnitario(kilometros, aerolineas);

    *descuentoLatam = descuento(porcentaje, latam);                     //LATAM
    *interesLatam = interes(interesValor, latam);
    *valorBitcoinLatam = pasajeBTC(bitcoin, latam);
    *precioUnitarioLatam = valorUnitario(kilometros, latam);
                                                           //aerolineas y latam
    *diferenciaIngresadaTotal = diferenciaDeValores(aerolineas, latam);

    printf("Costos:\n"
           "a) Tarjeta de débito \n"
           "b) de crédito \n"
           "c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n"
           "d) Mostrar precio por km (precio unitario)\n"
           "e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas)\n");

    banderaValidacionCalculos++;

}

void informarResultados(int* banderaValidacionInforme, float descuentoAerolineas, float interesAerolineas, float valorBitcoinAerolineas,
                        float precioUnitarioAerolineas, float descuentoLatam, float interesLatam, float valorBitcoinLatam,
                        float precioUnitarioLatam, float diferenciaIngresadaTotal)
{
    printf("Aerolineas:\n"
            "a) Precio con tarjeta de débito: $%.2f\n"
            "b) Precio con tarjeta de crédito: $%.2f\n"
            "c) Precio pagando con bitcoin : $%.2f\n"
            "d) Precio unitario: $%.2f\n"

            "Latam: \n"                                                   //Se informan los calculos correspondientes a Aerolineas o Latam
            "a) Precio con tarjeta de débito: $%.2f\n"
            "b) Precio con tarjeta de crédito: $%.2f\n"
            "c) Precio pagando con bitcoin: $%.2f\n"
            "d) Precio unitario: $%.2f\n"

            "La diferencia de precio es: $%.2f\n", descuentoAerolineas, interesAerolineas, valorBitcoinAerolineas,
                    precioUnitarioAerolineas, descuentoLatam, interesLatam, valorBitcoinLatam, precioUnitarioLatam,
                    diferenciaIngresadaTotal);

    banderaValidacionInforme++;


}

void cargaForzadaDeDatos(float kilometros, int porcentaje, float bitcoin, int interesValor, float latam, float aerolineas)
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

    kilometros = 7090;
    aerolineas = 162965;                               //Ingreso los datos pre-cargados
    latam = 159339;


    descuentoAerolineas = descuento(porcentaje, aerolineas);
    interesAerolineas = interes(interesValor, aerolineas);
    valorBitcoinAerolineas = pasajeBTC(bitcoin, aerolineas);
    precioUnitarioAerolineas = valorUnitario(kilometros, aerolineas);

    descuentoLatam = descuento(porcentaje, latam);
    interesLatam = interes(interesValor, latam);
    valorBitcoinLatam = pasajeBTC(bitcoin, latam);
    precioUnitarioLatam = valorUnitario(kilometros, latam);

    diferenciaIngresadaTotal = diferenciaDeValores(aerolineas, latam);

   printf("Aerolineas:\n"
                    "a) Precio con tarjeta de débito: $%.2f\n"
                    "b) Precio con tarjeta de crédito: $%.2f\n"
                    "c) Precio pagando con bitcoin : $%.2f\n"
                    "d) Precio unitario: $%.2f\n"
                "Latam: \n"                                                     //con los datos pre-cargados se hacen los calculos correspondientes
                    "a) Precio con tarjeta de débito: $%.2f\n"
                    "b) Precio con tarjeta de crédito: $%.2f\n"
                    "c) Precio pagando con bitcoin: $%.2f\n"
                    "d) Precio unitario: $%.2f\n"
                    "La diferencia de precio es: $%.2f\n", descuentoAerolineas, interesAerolineas, valorBitcoinAerolineas,
                    precioUnitarioAerolineas, descuentoLatam, interesLatam, valorBitcoinLatam, precioUnitarioLatam,
                    diferenciaIngresadaTotal);


}
