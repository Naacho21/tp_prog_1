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
	setbuf(stdout, NULL);

    int opcion = 0;
    float aerolineas;
    float latam;
    float kilometros;
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
    int banderaValidacionKm = 0;                                      //declaro e inicializo las banderas
    int banderaValidacionVuelo = 0;
    int banderaValidacionCalculos = 0;
    int banderaValidacionInforme = 0;

    do
    {

        switch(menu())
        {
            case 1: opcionUno(kilometros);
            		banderaValidacionKm++;
                    break;
            case 2:
                    if(banderaValidacionKm > 0)
                    {
                       opcionDos(&aerolineas, &latam);
                        banderaValidacionVuelo++;
                    }
                    else
                    {
                        if(banderaValidacionKm == 0)
                        {
                            printf("Error. No se puede ingresar la aerolinea correspondiente sin antes haber ingresado los kilometros.");

                        }
                    }
                            break;
            case 3:  if(banderaValidacionVuelo > 0)
            {

                opcionTres(bitcoin, interesValor, porcentaje, aerolineas, latam, kilometros, &descuentoAerolineas,
                               &interesAerolineas, &valorBitcoinAerolineas, &precioUnitarioAerolineas, &descuentoLatam,
                               &interesLatam, &valorBitcoinLatam, &precioUnitarioLatam, &diferenciaIngresadaTotal);

                banderaValidacionCalculos++;
            }
            else
            {
                if(banderaValidacionVuelo == 0)
                {
                    printf("Error. No se pueden realizar los calculos correspondientes por que faltan ingresar datos.");

                }

            }

                            break;
            case 4: if(banderaValidacionCalculos > 0)
            {
                informarResultados(descuentoAerolineas, interesAerolineas, valorBitcoinAerolineas,
                                        precioUnitarioAerolineas, descuentoLatam, interesLatam, valorBitcoinLatam,
                                        precioUnitarioLatam, diferenciaIngresadaTotal);
                banderaValidacionInforme++;
            }
            else
            {
                if(banderaValidacionCalculos == 0)
                {
                    printf("Error. No se pueden informar sobre los costos cuando falta el ingreso de datos.");

                }
            }

                            break;
            case 5:
            {
                cargaForzadaDeDatos(&kilometros, &aerolineas, &latam, porcentaje, bitcoin, interesValor);
            }

            				break;
        }

    }while(opcion != 6);

    printf("Fin del programa!.");

    return opcion;
}



