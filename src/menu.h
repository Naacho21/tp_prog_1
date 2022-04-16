#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "menu.c"

                                                            //guardo las funciones de menu.c
int menu();

int opcionUno(float kilometros, int* banderaValidacionKm);

int opcionDos(float precioIngresado, int* banderaValidacionVuelo);

void opcionTres(int* banderaValidacionCalculos, float bitcoin, int interesValor, int porcentaje, float aerolineas, float latam, float kilometros, float* descuentoAerolineas,
               float* interesAerolineas, float* valorBitcoinAerolineas, float* precioUnitarioAerolineas, float* descuentoLatam,
               float* interesLatam, float* valorBitcoinLatam, float* precioUnitarioLatam, float* diferenciaIngresadaTotal);

void informarResultados(int* banderaValidacionInforme, float descuentoaAerolineas, float interesAerolineas, float valorBitcoinAerolineas,
                        float precioUnitarioAerolineas, float descuentoLatam, float interesLatam, float valorBitcoinLatam,
                        float precioUnitarioLatam, float diferenciaIngresadaTotal);

void cargaForzadaDeDatos(float kilometros, int porcentaje, float bitcoin, int interesValor, float latam, float aerolineas);



#endif // MENU_H_INCLUDED

