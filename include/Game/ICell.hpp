#ifndef _ICELL_HPP_
#define _ICELL_HPP_

#include "Coordinate.hpp"

class ICell
{
public:
    Coordinate crd;

protected:
    const int width = 80;
    const int height = 80;
};

#endif // _ICELL_HPP_
