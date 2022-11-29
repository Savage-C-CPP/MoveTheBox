#ifndef _ROAD_HPP_
#define _ROAD_HPP_

#include "ICell.hpp"
#include <list>

class Road : public ICell
{
public:
    unsigned int index;
    Road();
    Road(int x, int y);
    ~Road();

    void AddAdjecent(Road *r);
    bool IsAdjecent(int x, int y);
    bool IsAdjecent(Road r2);
    Road *GetAdjecent(int x, int y);
    void SetEntity(void* entity);
    void* GetEntity();
    void RemoveEntity();
    bool HasEntity();

private:
    static unsigned int index_counter;
    typename std::list<Road *>::iterator it;
    std::list<Road *> adjecent;
    bool has_entity = false;
    void *entity = nullptr;
};

#endif // _ROAD_HPP_
