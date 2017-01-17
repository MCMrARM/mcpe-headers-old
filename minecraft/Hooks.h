#pragma once

#include <tml/mod.h>
#include <minecraft/gamemode/GameMode.h>

#define UseItemHook(args...) TInstanceHook(bool, _ZN8GameMode9useItemOnER6PlayerP12ItemInstanceRK8BlockPosaRK4Vec3, GameMode, args)
