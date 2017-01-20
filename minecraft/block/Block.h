#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include "BlockID.h"
#include "Material.h"
#include "../math/AABB.h"
#include "../util/Color.h"

class BlockSource;
class BlockPos;
class Entity;
class Mob;
class Player;
class Random;
class ItemInstance;
class Container;
class Brightness;
enum class BlockProperty;
enum class BlockSupportType;
enum class BlockRenderLayer;
enum class BlockEntityType;
enum class CreativeItemCategory;
enum class EntityType;

class Block {

public:

    /* 0x04 */ unsigned char id;
    /* 0x08 */ std::string descriptionId;
    /* 0x0c */ std::string nameId;
    /* 0x10 */ bool fancy;
    /* 0x11 */ bool canBuildOver;
    /* 0x14 */ BlockRenderLayer renderLayer;
    /* 0x18 */ int properties;
    /* 0x1c */ BlockEntityType blockEntityType;
    /* 0x20 */ bool animates;
    /* 0x24 */ int unknown2;
    /* 0x28 */ float thickness;
    /* 0x2c */ bool slideable;
    /* 0x2d */ bool instatick;
    /* 0x30 */ float gravity;
    /* 0x34 */ Material* material;
    /* 0x38 */ Color mapColor;
    /* 0x48 */ float friction;
    /* 0x4c */ bool heavy;
    /* 0x50 */ float destroyTime;
    /* 0x54 */ float blastResistance;
    /* 0x58 */ CreativeItemCategory category;
    /* 0x5c */ AABB aabb;
    /* size = 0x78 */

    // virtual
    virtual ~Block();
    virtual void tick(BlockSource&, BlockPos const&, Random&) const;
    virtual bool getCollisionShape(AABB&, BlockSource&, BlockPos const&, Entity*) const;
    virtual bool isObstructingChests(BlockSource&, BlockPos const&) const;
    virtual Vec3 randomlyModifyPosition(BlockPos const&, int&) const;
    virtual Vec3 randomlyModifyPosition(BlockPos const&) const;
    virtual void addAABBs(BlockSource&, BlockPos const&, AABB const*, std::vector<AABB, std::allocator<AABB>>&) const;
    virtual void getAABB(BlockSource&, BlockPos const&, AABB&, int, bool, int) const;
    virtual void addCollisionShapes(BlockSource&, BlockPos const&, AABB const*, std::vector<AABB, std::allocator<AABB>>&, Entity*) const;
    virtual bool canProvideSupport(BlockSource&, BlockPos const&, signed char, BlockSupportType) const;
    virtual bool isInfiniburnBlock(int) const;
    virtual bool isCropBlock() const;
    virtual bool isContainerBlock() const;
    virtual bool isCraftingBlock() const;
    virtual bool isInteractiveBlock() const;
    virtual bool isWaterBlocking() const;
    virtual bool isHurtableBlock() const;
    virtual bool isFenceBlock() const;
    virtual bool isStairBlock() const;
    virtual bool isRailBlock() const;
    virtual bool canHurtAndBreakItem() const;
    virtual bool isRedstoneBlock() const;
    virtual bool isSignalSource() const;
    virtual int getDirectSignal(BlockSource&, BlockPos const&, int) const;
    virtual bool waterSpreadCausesSpawn() const;
    virtual void handleRain(BlockSource&, BlockPos const&, float) const;
    virtual float getThickness() const;
    virtual bool checkIsPathable(Entity&, BlockPos const&, BlockPos const&) const;
    virtual bool dispense(BlockSource&, Container&, int, Vec3 const&, signed char) const;
    virtual void onPlace(BlockSource&, BlockPos const&) const;
    virtual void onRemove(BlockSource&, BlockPos const&) const;
    virtual void onExploded(BlockSource&, BlockPos const&, Entity*) const;
    virtual void onStepOn(Entity&, BlockPos const&) const;
    virtual void onFallOn(BlockSource&, BlockPos const&, Entity*, float) const;
    virtual void onRedstoneUpdate(BlockSource&, BlockPos const&, int, bool) const;
    virtual void onMove(BlockSource&, BlockPos const&, BlockPos const&) const;
    virtual bool detachesOnPistonMove(BlockSource&, BlockPos const&) const;
    virtual void onLoaded(BlockSource&, BlockPos const&) const;
    virtual int getRedstoneProperty(BlockSource&, BlockPos const&) const;
    virtual void updateEntityAfterFallOn(Entity&) const;
    virtual bool onFertilized(BlockSource&, BlockPos const&, Entity*) const;
    virtual bool mayConsumeFertilizer(BlockSource&) const;
    virtual bool mayPick() const;
    virtual bool mayPick(BlockSource&, int, bool) const;
    virtual bool mayPlace(BlockSource&, BlockPos const&, signed char) const;
    virtual bool mayPlace(BlockSource&, BlockPos const&) const;
    virtual bool mayPlaceOn(Block const&) const;
    virtual bool tryToPlace(BlockSource&, BlockPos const&, unsigned char) const;
    virtual bool breaksFallingBlocks(int) const;
    virtual void destroy(BlockSource&, BlockPos const&, int, Entity*) const;
    virtual bool playerWillDestroy(Player&, BlockPos const&, int) const;
    virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&) const;
    virtual bool getSecondPart(BlockSource&, BlockPos const&, BlockPos&) const;
    virtual unsigned char getResource(Random&, int, int) const;
    virtual int getResourceCount(Random&, int, int) const;
    virtual ItemInstance asItemInstance(BlockSource&, BlockPos const&, int) const;
    virtual bool spawnResources(BlockSource&, BlockPos const&, int, float, int) const;
    virtual bool spawnBurnResources(BlockSource&, float, float, float);
    virtual float getExplosionResistance(Entity*) const;
    virtual void clip(BlockSource&, BlockPos const&, Vec3 const&, Vec3 const&, bool, int) const;
    virtual bool use(Player&, BlockPos const&) const;
    virtual int getPlacementDataValue(Entity&, BlockPos const&, signed char, Vec3 const&, int) const;
    virtual int calcVariant(BlockSource&, BlockPos const&, unsigned char) const;
    virtual bool isAttachedTo(BlockSource&, BlockPos const&, BlockPos&) const;
    virtual bool attack(Player*, BlockPos const&) const;
    virtual void handleEntityInside(BlockSource&, BlockPos const&, Entity*, Vec3&) const;
    virtual void entityInside(BlockSource&, BlockPos const&, Entity&) const;
    virtual void playerDestroy(Player*, BlockPos const&, int) const;
    virtual bool canSurvive(BlockSource&, BlockPos const&) const;
    virtual int getExperienceDrop(Random&) const;
    virtual bool canBeBuiltOver(BlockSource&, BlockPos const&) const;
    virtual void triggerEvent(BlockSource&, BlockPos const&, int, int) const;
    virtual void* getMobToSpawn(BlockSource&, BlockPos const&) const;
    virtual Color getMapColor(BlockSource&, BlockPos const&) const;
    virtual Color getMapColor() const;
    virtual bool shouldStopFalling(Entity&) const;
    virtual float calcGroundFriction(Mob&, BlockPos const&) const;
    virtual bool canHaveExtraData() const;
    virtual bool hasComparatorSignal() const;
    virtual int getComparatorSignal(BlockSource&, BlockPos const&, signed char, int) const;
    virtual bool shouldRenderFace(BlockSource&, BlockPos const&, signed char, AABB const&) const;
    virtual int getIconYOffset() const;
    virtual std::string buildDescriptionName(unsigned char) const;
    virtual unsigned int getColor(int) const;
    virtual unsigned int getColor(BlockSource&, BlockPos const&) const;
    virtual unsigned int getColor(BlockSource&, BlockPos const&, unsigned char) const;
    virtual unsigned int getColorForParticle(BlockSource&, BlockPos const&, int) const;
    virtual bool isSeasonTinted(BlockSource&, BlockPos const&) const;
    virtual void onGraphicsModeChanged(bool, bool, bool);
    virtual BlockRenderLayer getRenderLayer(BlockSource&, BlockPos const&) const;
    virtual void* getExtraRenderLayers() const;
    virtual AABB const& getVisualShape(BlockSource&, BlockPos const&, AABB&, bool) const;
    virtual AABB const& getVisualShape(unsigned char, AABB&, bool) const;
    virtual int getVariant(int) const;
    virtual signed char getMappedFace(signed char, int) const;
    virtual void animateTick(BlockSource&, BlockPos const&, Random&) const;
    virtual void init();
    virtual bool canBeSilkTouched() const;
    virtual ItemInstance getSilkTouchItemInstance(unsigned char) const;
    virtual void setVisualShape(AABB const&);
    virtual void setVisualShape(Vec3 const&, Vec3 const&);
    virtual void setLightBlock(Brightness);
    virtual void setLightEmission(float);
    virtual void setExplodeable(float);
    virtual void setDestroyTime(float);
    virtual void setFriction(float);
    virtual void setBlockProperty(BlockProperty);
    virtual void setTicking(bool);
    virtual void setMapColor(Color const&);
    virtual void addProperty(BlockProperty);
    virtual int getSpawnResourcesAuxValue(unsigned char) const;

    // non virtual
    Block(std::string const&, int, Material const&);
    void setCategory(CreativeItemCategory);
    void setNameId(std::string const&);
    void setSolid(bool);
    bool canSlide() const;
    bool canInstatick() const;
    CreativeItemCategory getCreativeCategory() const;
    float getGravity() const;
    Material* getMaterial() const;
    float getFriction() const;
    float getDestroySpeed() const;
    bool isType(Block const*) const;
    void clip(BlockSource&, BlockPos const&, Vec3 const&, Vec3 const&, bool, int, AABB const&) const;
    void popResource(BlockSource&, BlockPos const&, ItemInstance const&) const;
    bool hasProperty(BlockProperty) const;
    bool isSolid() const;
    bool addAABB(AABB const&, AABB const*, std::vector<AABB, std::allocator<AABB>>&) const;
    bool pushesOutItems() const;
    void setPushesOutItems(bool);
    bool isUnbreakable() const;
    bool isHeavy() const;
    std::string const& getDescriptionId() const;
    bool isAlphaTested() const;
    bool isSolidBlockingBlock() const;
    BlockEntityType getBlockEntityType() const;
    bool hasBlockEntity() const;
    BlockRenderLayer getRenderLayer() const;
    int getProperties() const;
    float getShadeBrightness() const;
    Brightness getLightEmission(BlockID);
    void getDebugText(std::vector<std::string, std::allocator<std::string>>&) const;
    bool canGrowChorus() const;
    void* getTypeToSpawn(BlockSource&, EntityType, BlockPos const&) const;
    void* getMobToSpawn(BlockSource&, BlockPos const&, std::map<EntityType, int, std::less<EntityType>, std::allocator<std::pair<EntityType const, int>>>, bool&) const;
    void* getPlacementFacingAll(Entity&, BlockPos const&, float);
    void* getPlacementFacingAllExceptAxisY(Entity&, BlockPos const&, float);

    static void initBlocks();
    static void teardownBlocks();
    static Block* lookupByName(std::string const&, bool);
    static void* transformToValidBlockId(BlockID);
    static void* transformToValidBlockId(BlockID, BlockPos const&);
    static void DEPRECATEDcallOnGraphicsModeChanged(bool, bool, bool);

    // static fields
    static float SIZE_OFFSET;
    static std::string BLOCK_DESCRIPTION_PREFIX;
    static Block* mBlocks[];
    static std::unordered_map<std::string, Block*> mBlockLookupMap;
    static std::vector<std::unique_ptr<Block>> mOwnedBlocks;
    static bool mPushesOutItems[];
    static bool mSolid[];
    static bool mShouldTick[];
    static Brightness mLightBlock[];
    static Brightness mLightEmission[];
    static float mTranslucency[];
    static Block* mAir;
    static Block* mStone;
    static Block* mGrass;
    static Block* mDirt;
    static Block* mCobblestone;
    static Block* mWoodPlanks;
    static Block* mSapling;
    static Block* mBedrock;
    static Block* mFlowingWater;
    static Block* mStillWater;
    static Block* mFlowingLava;
    static Block* mStillLava;
    static Block* mSand;
    static Block* mGravel;
    static Block* mGoldOre;
    static Block* mIronOre;
    static Block* mCoalOre;
    static Block* mLog;
    static Block* mLeaves;
    static Block* mBorder;
    static Block* mAllow;
    static Block* mDeny;
    static Block* mSponge;
    static Block* mGlass;
    static Block* mLapisOre;
    static Block* mLapisBlock;
    static Block* mDispenser;
    static Block* mSandStone;
    static Block* mNote;
    static Block* mBed;
    static Block* mGoldenRail;
    static Block* mDetectorRail;
    static Block* mWeb;
    static Block* mTallgrass;
    static Block* mDeadBush;
    static Block* mPiston;
    static Block* mStickyPiston;
    static Block* mPistonArm;
    static Block* mMovingBlock;
    static Block* mObserver;
    static Block* mWool;
    static Block* mYellowFlower;
    static Block* mRedFlower;
    static Block* mBrownMushroom;
    static Block* mRedMushroom;
    static Block* mGoldBlock;
    static Block* mIronBlock;
    static Block* mDoubleStoneSlab;
    static Block* mStoneSlab;
    static Block* mBrick;
    static Block* mTNT;
    static Block* mBookshelf;
    static Block* mMossyCobblestone;
    static Block* mObsidian;
    static Block* mTorch;
    static Block* mMobSpawner;
    static Block* mOakStairs;
    static Block* mChest;
    static Block* mRedStoneDust;
    static Block* mDiamondOre;
    static Block* mDiamondBlock;
    static Block* mWorkBench;
    static Block* mWheatCrop;
    static Block* mFarmland;
    static Block* mFurnace;
    static Block* mLitFurnace;
    static Block* mSign;
    static Block* mWoodenDoor;
    static Block* mLadder;
    static Block* mRail;
    static Block* mStoneStairs;
    static Block* mWallSign;
    static Block* mLever;
    static Block* mStonePressurePlate;
    static Block* mIronDoor;
    static Block* mWoodPressurePlate;
    static Block* mRedStoneOre;
    static Block* mLitRedStoneOre;
    static Block* mUnlitRedStoneTorch;
    static Block* mLitRedStoneTorch;
    static Block* mStoneButton;
    static Block* mTopSnow;
    static Block* mIce;
    static Block* mSnow;
    static Block* mCactus;
    static Block* mClay;
    static Block* mReeds;
    static Block* mFence;
    static Block* mNetherFence;
    static Block* mPumpkin;
    static Block* mNetherrack;
    static Block* mSoulSand;
    static Block* mGlowStone;
    static Block* mPortal;
    static Block* mLitPumpkin;
    static Block* mCake;
    static Block* mUnpoweredRepeater;
    static Block* mPoweredRepeater;
    static Block* mInvisibleBedrock;
    static Block* mTrapdoor;
    static Block* mMonsterStoneEgg;
    static Block* mStoneBrick;
    static Block* mBrownMushroomBlock;
    static Block* mRedMushroomBlock;
    static Block* mIronFence;
    static Block* mGlassPane;
    static Block* mMelon;
    static Block* mPumpkinStem;
    static Block* mMelonStem;
    static Block* mVine;
    static Block* mFenceGateOak;
    static Block* mBrickStairs;
    static Block* mMycelium;
    static Block* mWaterlily;
    static Block* mBrewingStand;
    static Block* mCauldron;
    static Block* mEndPortal;
    static Block* mEndPortalFrame;
    static Block* mEndBrick;
    static Block* mEndStone;
    static Block* mEndRod;
    static Block* mUnlitRedStoneLamp;
    static Block* mLitRedStoneLamp;
    static Block* mCocoa;
    static Block* mEmeraldOre;
    static Block* mEmeraldBlock;
    static Block* mSpruceStairs;
    static Block* mBirchStairs;
    static Block* mJungleStairs;
    static Block* mBeacon;
    static Block* mWoodButton;
    static Block* mAcaciaStairs;
    static Block* mDarkOakStairs;
    static Block* mStoneBrickStairs;
    static Block* mNetherBrick;
    static Block* mNetherBrickStairs;
    static Block* mNetherWart;
    static Block* mEnchantingTable;
    static Block* mDropper;
    static Block* mActivatorRail;
    static Block* mSandstoneStairs;
    static Block* mTripwireHook;
    static Block* mTripwire;
    static Block* mCobblestoneWall;
    static Block* mFlowerPot;
    static Block* mCarrotCrop;
    static Block* mPotatoCrop;
    static Block* mSkull;
    static Block* mAnvil;
    static Block* mTrappedChest;
    static Block* mLightWeightedPressurePlate;
    static Block* mHeavyWeightedPressurePlate;
    static Block* mUnpoweredComparator;
    static Block* mPoweredComparator;
    static Block* mDaylightDetector;
    static Block* mRedstoneBlock;
    static Block* mQuartzOre;
    static Block* mHopper;
    static Block* mQuartzBlock;
    static Block* mQuartzStairs;
    static Block* mPurpurBlock;
    static Block* mPurpurStairs;
    static Block* mChorusPlantBlock;
    static Block* mChorusFlowerBlock;
    static Block* mWoodenDoorSpruce;
    static Block* mWoodenDoorBirch;
    static Block* mWoodenDoorJungle;
    static Block* mWoodenDoorAcacia;
    static Block* mWoodenDoorDarkOak;
    static Block* mDoubleWoodenSlab;
    static Block* mWoodenSlab;
    static Block* mStainedClay;
    static Block* mLeaves2;
    static Block* mLog2;
    static Block* mSlimeBlock;
    static Block* mIronTrapdoor;
    static Block* mHayBlock;
    static Block* mWoolCarpet;
    static Block* mCoalBlock;
    static Block* mHardenedClay;
    static Block* mPackedIce;
    static Block* mDoublePlant;
    static Block* mDaylightDetectorInverted;
    static Block* mRedSandstone;
    static Block* mRedSandstoneStairs;
    static Block* mDoubleStoneSlab2;
    static Block* mStoneSlab2;
    static Block* mSpuceFenceGate;
    static Block* mBirchFenceGate;
    static Block* mJungleFenceGate;
    static Block* mDarkOakFenceGate;
    static Block* mAcaciaFenceGate;
    static Block* mDragonEgg;
    static Block* mGrassPathBlock;
    static Block* mItemFrame;
    static Block* mStructureBlock;
    static Block* mStructureVoid;
    static Block* mPodzol;
    static Block* mBeetrootCrop;
    static Block* mStonecutterBench;
    static Block* mGlowingObsidian;
    static Block* mNetherReactor;
    static Block* mInfoUpdateGame1;
    static Block* mInfoUpdateGame2;
    static Block* mInfoReserved6;
    static Block* mFire;
    static Block* mEnderChest;
    static Block* mEndGateway;
    static Block* mStainedGlass;
    static Block* mStainedGlassPane;
    static Block* mPrismarine;
    static Block* mSeaLantern;
    static Block* mCameraBlock;
    static Block* mChalkboard;

};
