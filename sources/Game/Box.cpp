#include "Box.hpp"

Box::Box() { pivot = nullptr; };

Box::~Box(){};

void Box::SetPivot(Road *r)
{
    pivot = r;
    void *e = static_cast<void *>(this);
    pivot->SetEntity(e);
    crd = pivot->crd;
}

MoveStatus Box::MoveUp()
{
    Coordinate to(crd.x, crd.y - ICell::height);
    if (pivot->IsAdjecent(to.x, to.y))
    {
        const auto adj = pivot->GetAdjecent(to.x, to.y);
        if (adj->HasEntity())
            return MOVE_FAILURE;

        SetPivot(adj);
        return MOVE_SUCCESS;
    }
    else
        return MOVE_FAILURE;
};

MoveStatus Box::MoveRight()
{
    Coordinate to(this->crd.x + ICell::width, this->crd.y);
    if (pivot->IsAdjecent(to.x, to.y))
    {
        const auto adj = pivot->GetAdjecent(to.x, to.y);
        if (adj->HasEntity())
            return MOVE_FAILURE;

        SetPivot(adj);
        return MOVE_SUCCESS;
    }
    else
        return MOVE_FAILURE;
};

MoveStatus Box::MoveDown()
{
    Coordinate to(this->crd.x, this->crd.y + ICell::height);
    if (pivot->IsAdjecent(to.x, to.y))
    {
        const auto adj = pivot->GetAdjecent(to.x, to.y);
        if (adj->HasEntity())
            return MOVE_FAILURE;

        SetPivot(adj);
        return MOVE_SUCCESS;
    }
    else
        return MOVE_FAILURE;
};

MoveStatus Box::MoveLeft()
{
    Coordinate to(this->crd.x - ICell::width, this->crd.y);
    if (pivot->IsAdjecent(to.x, to.y))
    {
        const auto adj = pivot->GetAdjecent(to.x, to.y);
        if (adj->HasEntity())
            return MOVE_FAILURE;

        SetPivot(adj);
        return MOVE_SUCCESS;
    }
    else
        return MOVE_FAILURE;
};
