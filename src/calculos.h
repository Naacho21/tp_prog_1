/*
 * calculos.h
 *
 *  Created on: 15 abr. 2022
 *      Author: ignac
 */

#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED
#include "calculos.c"

float descuento(int porcentaje, float precioVuelo);

float interes(int interesValor, float precioVuelo);                         //guardo las funciones de calculos.c

float pasajeBTC(float bitcoin, float precioVuelo);

float valorUnitario(float precioVuelo, float kilometros);

float diferenciaDeValores(float aerolineas, float latam);

#endif // CALCULOS_H_INCLUDED
