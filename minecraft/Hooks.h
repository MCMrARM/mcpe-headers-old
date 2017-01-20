#pragma once

#include <string>

#include <tml/mod.h>
#include <minecraft/gamemode/GameMode.h>

#define UseItemHook(args...) TInstanceHook(bool, _ZN8GameMode9useItemOnER6PlayerP12ItemInstanceRK8BlockPosaRK4Vec3, GameMode, args)
#define BlockInitHook() THook(void, _ZN5Block10initBlocksEv)
#define InitItemsHook() THook(void, _ZN4Item14initClientDataEv)
#define GetVersionHook() THook(std::string, _ZNK20MinecraftScreenModel16getVersionStringEv)
