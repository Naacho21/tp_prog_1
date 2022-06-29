#include <stdio.h>
#include <stdlib.h>

#include "calculosAux.h"
#include "menu.h"

float descuento(int porcentaje, float precioVuelo)
{

    float porcentajeDescuento;
    float descuentoTotal;

    porcentajeDescuento = precioVuelo * porcentaje / 100;
    descuentoTotal = precioVuelo-porcentajeDescuento;

    return descuentoTotal;
}

float interes(int interesValor, float precioVuelo)
{

    float porcentajeInteres;
    float precioConInteres;

    porcentajeInteres = precioVuelo * interesValor /100;
    precioConInteres = precioVuelo+porcentajeInteres;

    return precioConInteres;
}

float pasajeBTC(float bitcoin, float precioVuelo)
{

    float valorBitcoin;
    valorBitcoin = precioVuelo / bitcoin;

    return valorBitcoin;
}

float valorUnitario(float precioVuelo, float kilometros)
{

    float precioUnitario;

    precioUnitario = precioVuelo/kilometros;
    return precioUnitario;
}

float diferenciaDeValores(float aerolineas, float latam)
{

    float diferenciaIngresada;

    if(aerolineas > latam)
    {
        diferenciaIngresada = aerolineas-latam;
    }
    else
    {
        if(aerolineas < latam)
        {
            diferenciaIngresada = latam-aerolineas;
        }
    }
    return diferenciaIngresada;
}
