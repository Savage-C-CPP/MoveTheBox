#include "Player.hpp"

Player::Player(){};

Player::~Player(){};

void Player::SetPivot(Road *r)
{
    pivot = r;
    void *e = static_cast<void *>(this);
    pivot->SetEntity(e);
    crd = pivot->crd;
}

MoveStatus Player::MoveUp()
{
    Coordinate to(crd.x, crd.y - ICell::height);
    if (pivot->IsAdjecent(to.x, to.y))
    {
        const auto adj = pivot->GetAdjecent(to.x, to.y);
        if (adj->HasEntity())
        {
            auto e = static_cast<Entity *>(adj->GetEntity());
            if (e->MoveUp() == MOVE_FAILURE)
                return MOVE_FAILURE;
        }

        SetPivot(adj);
        return MOVE_SUCCESS;
    }
    else
        return MOVE_FAILURE;
};

MoveStatus Player::MoveRight()
{
    Coordinate to(this->crd.x + ICell::width, this->crd.y);
    if (pivot->IsAdjecent(to.x, to.y))
    {
        const auto adj = pivot->GetAdjecent(to.x, to.y);
        if (adj->HasEntity())
        {
            auto e = static_cast<Entity *>(adj->GetEntity());
            if (e->MoveRight() == MOVE_FAILURE)
                return MOVE_FAILURE;
        }

        SetPivot(adj);
        return MOVE_SUCCESS;
    }
    else
        return MOVE_FAILURE;
};

MoveStatus Player::MoveDown()
{
    Coordinate to(this->crd.x, this->crd.y + ICell::height);
    if (pivot->IsAdjecent(to.x, to.y))
    {
        const auto adj = pivot->GetAdjecent(to.x, to.y);
        if (adj->HasEntity())
        {
            auto e = static_cast<Entity *>(adj->GetEntity());
            if (e->MoveDown() == MOVE_FAILURE)
                return MOVE_FAILURE;
        }

        SetPivot(adj);
        return MOVE_SUCCESS;
    }
    else
        return MOVE_FAILURE;
};

MoveStatus Player::MoveLeft()
{
    Coordinate to(this->crd.x - ICell::width, this->crd.y);
    if (pivot->IsAdjecent(to.x, to.y))
    {
        const auto adj = pivot->GetAdjecent(to.x, to.y);
        if (adj->HasEntity())
        {
            auto e = static_cast<Entity *>(adj->GetEntity());
            if (e->MoveLeft() == MOVE_FAILURE)
                return MOVE_FAILURE;
        }

        SetPivot(adj);
        return MOVE_SUCCESS;
    }
    else
        return MOVE_FAILURE;
};
