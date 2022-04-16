#include <stdio.h>
#include <stdlib.h>


float descuento(int porcentaje, float precioVuelo)
{
    float porcentajeDescuento;
    float descuentoTotal;
                                                                            //Funcion descuento del 10%
    porcentajeDescuento = (precioVuelo*porcentaje) / 100;
    descuentoTotal = precioVuelo-porcentajeDescuento;

    return descuentoTotal;
}

float interes(int interesValor, float precioVuelo)
{
    float porcentajeInteres;
    float precioConInteres;
                                                                            //Funcion interes del 25%
    porcentajeInteres = (precioVuelo*interesValor)/100;
    precioConInteres = precioVuelo+porcentajeInteres;

    return precioConInteres;
}

float pasajeBTC(float bitcoin, float precioVuelo)
{

    float valorBitcoin;                                                      //Pasaje del precio del vuelo al valor del bitcoin

    valorBitcoin = precioVuelo / bitcoin;

    return valorBitcoin;
}

float valorUnitario(float precioVuelo, float kilometros)
{
    float precioUnitario;

    precioUnitario = precioVuelo/kilometros;                                   //Promedio entre el precio del vuelo y los kilometros ingresados

    return precioUnitario;
}

float diferenciaDeValores(float aerolineas, float latam)
{
    float diferenciaIngresada;

    if(aerolineas > latam)
    {                                                                           //Diferencia del valor del precio de Aerolineas y Latam
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
