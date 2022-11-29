#include "Road.hpp"

unsigned int Road::index_counter = 0;

Road::Road()
{
    index = Road::index_counter++;
};

Road::~Road()
{
}

Road::Road(int x, int y)
{
    index = Road::index_counter++;
    crd.x = x;
    crd.y = y;
};

// TODO: Check geometry of the road befor connection. Ex: r(0, 0) can connect with (r0, 80), but can't with r(80, 80)
void Road::AddAdjecent(Road *r)
{
    adjecent.push_back(r);
    r->adjecent.push_back(this);
};

bool Road::IsAdjecent(int x, int y)
{
    for (it = adjecent.begin(); it != adjecent.end(); ++it)
    {
        const auto r = *it;
        if (r->crd.x == x && r->crd.y == y)
            return true;
    }
    return false;
};

bool Road::IsAdjecent(Road r2)
{
    for (it = adjecent.begin(); it != adjecent.end(); ++it)
    {
        const auto r1 = *it;
        if (r1->crd.x == r2.crd.x && r1->crd.y == r2.crd.y)
            return true;
    }
    return false;
};

Road *Road::GetAdjecent(int x, int y)
{
    for (it = adjecent.begin(); it != adjecent.end(); ++it)
    {
        const auto adj = *it;
        if (adj->crd.x == x && adj->crd.y == y)
            return adj;
    }
    return nullptr;
}

void Road::SetEntity(void *e)
{
    has_entity = true;
    entity = e;
}

void *Road::GetEntity()
{
    return entity;
}

void Road::RemoveEntity()
{
    has_entity = false;
    entity = nullptr;
}

bool Road::HasEntity()
{
    return has_entity;
}
