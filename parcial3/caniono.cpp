#include "caniono.h"



CanionO::CanionO(double _d, double _Ho)
{
    d =_d;//distancia de separacion
    Ho =_Ho;//algura del canion Ofensivo
    Xo =0;//posicion del canion Ofensivo
    Yo = Ho;//altura del canion Ofensivo
    d0 = 0.05*d;//radio de impacto
}
