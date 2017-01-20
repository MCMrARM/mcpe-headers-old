#pragma once

enum class BlockEntityType : int {
    None,
    Furnace = 1,
    Chest = 2,
    NetherReactor = 3,
    Sign = 4,
    MobSpawner = 5,
    Skull = 6,
    FlowerPot = 7,
    BrewingStand = 8,
    EnchantTable = 9, 
    DaylightDetector = 10,
    NoteBlock = 11,
    Comparator = 12,
    Dispenser = 13,
    Dropper = 14,
    Hopper = 15,
    Cauldron = 16,
    ItemFrame = 17,
    PistonArm = 18,
    MovingBlock = 19,
    Chalkboard = 20,
    Beacon = 21,
    EndPortal = 22,
    EnderChest = 23,
    EndGateway = 24,
    StructureBlock = 32,
};

enum class BlockEntityRendererId : int {
    DEFAULT,
    SIGN,
    //TODO: Need more research
};