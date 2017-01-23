#pragma once

class ChunkPos {

public:

    int x;
    int z;
    /* size = 0x08 */

    // non virtuals
    ChunkPos(BlockPos const&);
    ChunkPos(Vec3 const&);
    double distanceToSqr(Entity const&) const;
    void getMiddleBlockPosition(int) const;

    // static
    static ChunkPos INVALID;
};