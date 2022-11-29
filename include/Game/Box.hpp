#ifndef _BOX_HPP_
#define _BOX_HPP_

#include "Entity.hpp"
#include "Road.hpp"

class Box : public Entity
{
public:
    Box();
    virtual ~Box();

    virtual void SetPivot(Road *r);
    virtual MoveStatus MoveUp();
    virtual MoveStatus MoveRight();
    virtual MoveStatus MoveDown();
    virtual MoveStatus MoveLeft();
};

#endif // _BOX_HPP_
