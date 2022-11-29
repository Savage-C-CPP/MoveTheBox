#ifndef _ENTITY_HPP_
#define _ENTITY_HPP_

#include "ICell.hpp"
#include "Road.hpp"

typedef int MoveStatus;

class Entity : public ICell
{
public:
    virtual void SetPivot(Road *r) = 0;
    virtual MoveStatus MoveUp() = 0;
    virtual MoveStatus MoveRight() = 0;
    virtual MoveStatus MoveDown() = 0;
    virtual MoveStatus MoveLeft() = 0;

    Road *pivot;

    enum
    {
        MOVE_SUCCESS,
        MOVE_FAILURE
    };
};

#endif // _ENTITY_HPP_
