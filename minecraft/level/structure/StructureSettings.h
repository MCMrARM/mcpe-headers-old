#pragma once

#include "../../math/BoundingBox.h"
#include "../ChunkPos.h"

class Block;
class Random;

enum class Mirror : int;
enum class Rotation : short;

class StructureSettings {

public: 
 
    /* 0x00 */ float integrity;
    /* 0x04 */ unsigned int seed;
    /* 0x08 */ Mirror mirror;
    /* 0x0C */ Rortation rotation;
    /* 0x0E */ bool ignoringEntities;
    /* 0x0F */ bool ignoringStructure;
    /* 0x10 */ Block* ignoreBlock;
    /* 0x14 */ ChunkPos pos;
    /* 0x1C */ BoundingBox bb;
    /* size = 0x34 */

    // non virtual
    StructureSettings(Mirror, Rotation, bool, Block const*, BoundingBox const&);
    StructureSettings();
    void setRotation(Rotation);
    void setIntegrity(float);
    void setIgnoreBlock(Block const*);
    void setSeed(unsigned int);
    void setMirror(Mirror);
    void setIgnoreEntities(bool);
    void setChunkPos(ChunkPos const&);
    void setBoundingBox(BoundingBox const&);
    void isIgnoreStructureBlocks() const;
    void isIgnoreBlock();
    void isIgnoreEntities();
    void getBoundingBox();
    void getIgnoreBlock() const;
    void getRotation() const;
    void getIntegrity() const;
    void getSeed() const;
    void getMirror() const;
    void getChunkPos() const;
    void updateBoundingBoxFromChunkPos();
    void _calculateBoundingBox(ChunkPos const&);
    void ignoreStructureBlocks(bool);
    void retrieveRandom(Random&) const;
};