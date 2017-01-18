#pragma once
#include "Item.h"

class BlockItem : public Item 
{
public:
    BlockItem(const std::string&, int);

    virtual ~BlockItem();
    virtual bool useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float);
    virtual std::string buildDescriptionName(ItemInstance const&) const;
    virtual bool isEmissive(int) const;
    virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
    virtual float getIconYOffset() const;
};