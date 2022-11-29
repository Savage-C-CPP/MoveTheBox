#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "Entity.hpp"

class Player : public Entity
{
public:
    Player();
    virtual ~Player();

    virtual void SetPivot(Road *r);
    virtual MoveStatus MoveUp();
    virtual MoveStatus MoveRight();
    virtual MoveStatus MoveDown();
    virtual MoveStatus MoveLeft();
};

#endif // _PLAYER_HPP_
