/*
 * calculos.h
 *
 *  Created on: 15 abr. 2022
 *      Author: ignac
 */

#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED



float descuento(int porcentaje, float precioVuelo);

/**
	 * Descripcion: Funcion de descuento del 10%
	 *
	 * parametro: int porcentaje
	 * parametro: float precioVuelo
	 *
	 * return float
	 */

float interes(int interesValor, float precioVuelo);

/**
	 * Descripcion: Funcion de interes del 25%
	 *
	 * parametro: int interesValor
	 * parametro. float precioVuelo
	 *
	 * return float
	 */


float pasajeBTC(float bitcoin, float precioVuelo);

/**
	 * Descripcion: Pasaje del precio del vuelo al valor del bitcoin
	 *
	 * parametro: float bitcoin
	 * parametro: float precioVuelo
	 *
	 * return float
	 */

float valorUnitario(float precioVuelo, float kilometros);

/**
	 *Descripcion: Promedio entre el precio del vuelo y los kilometros ingresados
	 *
	 * parametro: float precioVuelo
	 * parametro: float kilometros
	 *
	 * return float
	 */

float diferenciaDeValores(float aerolineas, float latam);

/**
	 * Descrpcion: Diferencia del valor del precio de Aerolineas y Latam
	 *
	 * parametro: float aerolineas
	 * parametro: float latam
	 *
	 * return float
	 */

#endif // CALCULOS_H_INCLUDED
