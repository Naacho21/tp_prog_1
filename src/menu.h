#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

                                                        //Guardo las funciones de menu.c
int menu();

int opcionUno(float kilometros, int* banderaValidacionKm);

/**
      *Descripcion: Se ingresan los kilometros
      *
      *parametro: float kilometros
      *parametro: int* banderaValidacionKm
      *
      * return float
      */


int opcionDos(float precioIngresado, int* banderaValidacionVuelo);

/**
	 * Descripcion: Se elige la aerolinea de vuelo, solo 5 intentos
	 *
	 * parametro: float precioIngresado
	 * parametro: int* banderaValidacionVuelo
	 *
	 *return int

	 */


void opcionTres(int* banderaValidacionCalculos, float bitcoin, int interesValor, int porcentaje, float aerolineas, float latam, float kilometros, float* descuentoAerolineas,
               float* interesAerolineas, float* valorBitcoinAerolineas, float* precioUnitarioAerolineas, float* descuentoLatam,
               float* interesLatam, float* valorBitcoinLatam, float* precioUnitarioLatam, float* diferenciaIngresadaTotal);

/**
	 * Descripcion: Se realizan los calculos correspondientes ya sea para Aerolineas o Latam
	 * parametro: int* banderaValidacionCalculos
	 * parametro: float bitcoin
	 * parametro: int interesValor
	 * parametro: int porcentaje
	 * parametro: float aerolineas
	 * parametro: float latam
	 * parametro: float kilometros
	 * parametro: float* descuentoAerolineas
	 * parametro: float* interesAerolineas
	 * parametro: float* valorBitcoinAerolineas
	 * parametro: float* precioUnitarioAerolineas
	 * parametro: float* descuentoLatam
	 * parametro: float* interesLatam
	 * parametro: float* valorBitcoinLatam
	 * parametro: float* precioUnitarioLatam
	 * parametro: float* diferenciaIngresadaTotal
	 *
	 * return void
	 */



void informarResultados(int* banderaValidacionInforme, float descuentoaAerolineas, float interesAerolineas, float valorBitcoinAerolineas,
                        float precioUnitarioAerolineas, float descuentoLatam, float interesLatam, float valorBitcoinLatam,
                        float precioUnitarioLatam, float diferenciaIngresadaTotal);

/**
	 * Descripcion: Se muestran los calculos correspondientes realizados en la pantalla
	 *
	 * parametro: int* banderaValidacionInforme
	 * parametro: float* descuentoAerolineas
	 * parametro: float* interesAerolineas
	 * parametro: float* valorBitcoinAerolineas
	 * parametro: float* precioUnitarioAerolineas
	 * parametro: float* descuentoLatam
	 * parametro: float* interesLatam
	 * parametro: float* valorBitcoinLatam
	 * parametro: float* precioUnitarioLatam
	 * parametro: float* diferenciaIngresadaTotal
	 *
	 * return void
	 */


void cargaForzadaDeDatos(float kilometros, int porcentaje, float bitcoin, int interesValor, float latam, float aerolineas); //Se muestran los datos ya pre-establecidos (hardcoeados)

/**
	 * Descripcion: //Ingreso los datos pre-cargados (hardocodeados)
	 *
	 *parametro: float kilometros
	 *parametro: int porcentaje
	 *parametro: float bitcoin
	 *parametro: int interesValor
	 *parametro: latam
	 *parametro: aerolineas
	 *
	 *return void
	 */

#endif // MENU_H_INCLUDED

