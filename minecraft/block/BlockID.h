#pragma once

enum class BlockProperty;

struct BlockID {

    unsigned char id;

    BlockID(unsigned char id) : id(id) { }
    BlockID(BlockID const& b) : BlockID(b.id) { }

    bool operator==(BlockID const& b) { return id == b.id; }
    bool operator!=(BlockID const& b) { return !(*this == b); }

    bool hasProperty(BlockProperty) const;

    static BlockID AIR;

};
