/*
 ============================================================================
 Name        : tp.c
 Author      : Ignacio Ayuza
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
{
    int opcion=0;
    float precioIngresado = 0;
    float aerolineas;
    float latam;
    float kilometros = 0;
    int porcentaje = 10;
    int interesValor = 25;
    float bitcoin = 4606954.55;
    float descuentoAerolineas;
    float interesAerolineas;
    float valorBitcoinAerolineas;
    float precioUnitarioAerolineas;
    float descuentoLatam;
    float interesLatam;
    float valorBitcoinLatam;
    float precioUnitarioLatam;
    float diferenciaIngresadaTotal;
    int banderaValidacionKm = 0;
    int banderaValidacionVuelo = 0;
    int banderaValidacionCalculos = 0;
    int banderaValidacionInforme = 0;

    do
    {
        switch(menu())
        {
            case 1: opcionUno(kilometros, &banderaValidacionKm);

                    break;
            case 2:
                    if(banderaValidacionKm>0)
                    {
                        switch(opcionDos(precioIngresado, &banderaValidacionVuelo))
                        {
                            case 1: aerolineas=precioIngresado;
                            break;
                            case 2: latam=precioIngresado;
                            break;
                        }

                    }
                    else
                    {
                        if(banderaValidacionKm<0)
                        {
                            printf("Error. No se puede ingresar la aerolinea correspondiente sin antes haber ingresado los kilometros.");

                        }
                    }
                            break;
            case 3:  if(banderaValidacionVuelo>0)
            {

                opcionTres(&banderaValidacionCalculos, bitcoin, interesValor, porcentaje, aerolineas, latam, kilometros, &descuentoAerolineas,
                               &interesAerolineas, &valorBitcoinAerolineas, &precioUnitarioAerolineas, &descuentoLatam,
                               &interesLatam, &valorBitcoinLatam, &precioUnitarioLatam, &diferenciaIngresadaTotal);
            }
            else
            {
                if(banderaValidacionVuelo<0)
                {
                    printf("Error. No se pueden realizar los calculos correspondientes por que faltan ingresar datos.");

                }

            }

                            break;
            case 4: if(banderaValidacionCalculos>0)
            {
                informarResultados(&banderaValidacionInforme, descuentoAerolineas, interesAerolineas, valorBitcoinAerolineas,
                                        precioUnitarioAerolineas, descuentoLatam, interesLatam, valorBitcoinLatam,
                                        precioUnitarioLatam, diferenciaIngresadaTotal);
            }
            else
            {
                if(banderaValidacionCalculos<0)
                {
                    printf("Error. No se pueden informar sobre los costos cuando falta el ingreso de datos.");

                }
            }

                            break;
            case 5: if(banderaValidacionInforme>0)
            {
                cargaForzadaDeDatos(kilometros, porcentaje, bitcoin, interesValor, latam,
                                        aerolineas);
            }
            else
            {
                if(banderaValidacionInforme<0)
                {
                    printf("Error. No se puede mostrar la carga forzada cuando faltan ingresar datos.");
                }

            }

                            break;
        }

    }while(opcion != 6);

    return opcion;
}



