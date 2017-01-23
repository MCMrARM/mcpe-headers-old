#pragma once

#include <memory>

class IntArrayTag;

class BoundingBox {

public:  
    
    float minX;
    float minY;
    float minZ;
    float maxX;
    float maxY;
    float maxZ;

    void orientBox(int, int, int, int, int, int, int, int, int, int);
    std::unique_ptr<IntArrayTag> createTag() const;
};