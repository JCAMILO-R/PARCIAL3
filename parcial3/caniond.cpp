#include "caniond.h"



CanionD::CanionD(double _d, double _Hd)
{
    d=_d;//distancia de separacion
    Hd=_Hd;//altura del canion defensivo
    Xd =d;//posicion del canion defensivo
    Yd = Hd;//altura del canion defensivo
    d0 = 0.025*d; //radio de impacto
}
