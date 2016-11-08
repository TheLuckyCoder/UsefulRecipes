#pragma once

#include <string>
#include <vector>
#include <memory>

#include "mcpe/client/renderer/texture/TextureUVCoordinateSet.h"
#include "mcpe/util/Color.h"
#include "mcpe/util/BlockID.h"
#include "mcpe/util/AABB.h"
#include "material/Material.h"
#include "BlockShape.h"
#include "mcpe/blockentity/BlockEntityType.h"
#include "mcpe/item/CreativeItemCategory.h"
#include "BlockSoundType.h"
struct Material;
struct BlockEntity;
struct Container;
struct FullBlock;
struct BlockPos;
struct BlockSource;
struct Entity;
struct Mob;
struct Player;
struct ItemInstance;
struct Random;
struct Vec3;
struct Brightness;
struct Color;

typedef unsigned char uchar;

class Block
{
public:
	class SoundType
	{
	public:
		float volume; // 0
		float pitch; // 4
		std::string stepSound; // 8
		std::string breakSound; // 12
		std::string placeSound; // 16

		SoundType(const std::string&, float, float);
		SoundType(const std::string&, const std::string&, float, float);
		SoundType(const std::string&, const std::string&, const std::string&, float, float);
		
		~SoundType();
		
		float getVolume() const;
		float getPitch() const;
		std::string getStepSound() const;
		std::string getBreakSound() const;
		std::string getPlaceSound() const;
	};


	uint8_t blockId; // 4
	std::string name; // 12
	bool replaceable;
	int renderLayer; // 52
	bool canBuildOver; // 49
	BlockShape blockShape; // 56
	int properties; // 60
	BlockEntityType blockEntityType; // 64
	bool animates; // 68
	float thickness; // 72
	bool slippery; // 76
	bool instaTicks; // 77
	float gravity; // 80
	Material &material; // 84
	Color mapColor; // 88
	float friction; // 104
	bool heavy; // 108
	float hardness; // 112
	float explosionResistance; // 116
	CreativeItemCategory creativeCategory; // 120
	AABB hitbox; // 124
	char filler[24];


	static std::vector<std::unique_ptr<Block>> mOwnedBlocks;
	static Block* mBlocks[256];
	static bool mSolid[256];
	static float mTranslucency[256];
	static uint8_t mLightBlock[256];
	static int mLightEmission[256];
	static bool mShouldTick[256];

	Block(const std::string&, int, const Material&);

	/* vtable */
	virtual ~Block();
	virtual void tick(BlockSource&, BlockPos const&, Random&);
	virtual const AABB& getCollisionShape(AABB&, BlockSource&, BlockPos const&, Entity*);
	virtual bool isObstructingChests(BlockSource&, BlockPos const&);
	virtual void randomlyModifyPosition(BlockPos const&, int&) const;
	virtual void randomlyModifyPosition(BlockPos const&) const;
	virtual bool addAABBs(BlockSource&, BlockPos const&, AABB const*, std::vector<AABB, std::allocator<AABB> >&);
	virtual const AABB& getAABB(BlockSource&, BlockPos const&, AABB&, int, bool, int);
	virtual bool addCollisionShapes(BlockSource&, BlockPos const&, AABB const*, std::vector<AABB, std::allocator<AABB> >&, Entity*);
	virtual bool isCropBlock() const;
	virtual bool isContainerBlock() const;
	virtual bool isCraftingBlock() const;
	virtual bool isInteractiveBlock() const;
	virtual bool isWaterBlocking() const;
	virtual bool isHurtableBlock() const;
	virtual bool isFenceBlock() const;
	virtual bool isStairBlock() const;
	virtual bool isRailBlock() const;
	virtual bool isRedstoneBlock() const;
	virtual bool isSignalSource() const;
	virtual int getDirectSignal(BlockSource&, BlockPos const&, int);
	virtual bool waterSpreadCausesSpawn() const;
	virtual void handleRain(BlockSource&, BlockPos const&, float) const;
	virtual float getThickness() const;
	virtual bool checkIsPathable(Entity&, BlockPos const&, BlockPos const&);
	virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char);
	virtual void onPlace(BlockSource&, BlockPos const&);
	virtual void onRemove(BlockSource&, BlockPos const&);
	virtual void onExploded(BlockSource&, BlockPos const&, Entity*);
	virtual void onStepOn(Entity&, BlockPos const&);
	virtual void onFallOn(BlockSource&, BlockPos const&, Entity*, float);
	virtual void onRedstoneUpdate(BlockSource&, BlockPos const&, int, bool);
	virtual void onMove(BlockSource&, BlockPos const&, BlockPos const&);
	virtual bool detachesOnPistonMove(BlockSource&, BlockPos const&);
	virtual void onLoaded(BlockSource&, BlockPos const&);
	virtual void getRedstoneProperty(BlockSource&, BlockPos const&);
	virtual void updateEntityAfterFallOn(Entity&);
	virtual void onFertilized(BlockSource&, BlockPos const&, Player*);
	virtual bool mayConsumeFertilizer(BlockSource&);
	virtual bool mayPick();
	virtual bool mayPick(BlockSource&, int, bool);
	virtual bool mayPlace(BlockSource&, BlockPos const&, signed char);
	virtual bool mayPlace(BlockSource&, BlockPos const&);
	virtual bool mayPlaceOn(Block const&);
	virtual void tryToPlace(BlockSource&, BlockPos const&, unsigned char);
	virtual void destroy(BlockSource&, BlockPos const&, int, Entity*);
	virtual void playerWillDestroy(Player&, BlockPos const&, int);
	virtual void neighborChanged(BlockSource&, BlockPos const&, BlockPos const&);
	virtual void getSecondPart(BlockSource&, BlockPos const&, BlockPos&);
	virtual int getResource(Random&, int, int);
	virtual int getResourceCount(Random&, int, int);
	virtual ItemInstance& asItemInstance(BlockSource&, BlockPos const&, int) const;
	virtual float getDestroyProgress(Player&);
	virtual void spawnResources(BlockSource&, BlockPos const&, int, float, int);
	virtual void spawnBurnResources(BlockSource&, float, float, float);
	//virtual float getExplosionResistance(Entity*);
	virtual void clip(BlockSource&, BlockPos const&, Vec3 const&, Vec3 const&, bool, int);
	virtual bool use(Player&, BlockPos const&);
	virtual int getPlacementDataValue(Mob&, BlockPos const&, signed char, Vec3 const&, int);
	virtual void calcVariant(BlockSource&, BlockPos const&, unsigned char) const;
	virtual bool isAttachedTo(BlockSource&, BlockPos const&, BlockPos&);
	virtual void attack(Player*, BlockPos const&);
	virtual void handleEntityInside(BlockSource&, BlockPos const&, Entity*, Vec3&);
	virtual bool entityInside(BlockSource&, BlockPos const&, Entity&);
	virtual void playerDestroy(Player*, BlockPos const&, int);
	virtual bool canSurvive(BlockSource&, BlockPos const&);
	virtual int getExperienceDrop(Random&) const;
	virtual bool canBeBuiltOver(BlockSource&, BlockPos const&) const;
	virtual void triggerEvent(BlockSource&, BlockPos const&, int, int);
	virtual void getMobToSpawn(BlockSource&, BlockPos const&) const;
	virtual Color getMapColor(BlockSource &,BlockPos const&) const;
	virtual Color getMapColor() const;
	virtual bool shouldStopFalling(Entity&);
	virtual float calcGroundFriction(Mob&, BlockPos const&) const;
	virtual bool canHaveExtraData() const;
	virtual bool hasComparatorSignal();
	virtual int getComparatorSignal(BlockSource&, BlockPos const&, signed char, int);
	virtual bool shouldRenderFace(BlockSource&, BlockPos const&, signed char, AABB const&) const;
	virtual int getIconYOffset() const;
	virtual std::string buildDescriptionName(unsigned char) const;
	virtual int getColor(int) const;
	virtual int getColor(BlockSource&, BlockPos const&) const;
	virtual int getColor(BlockSource&, BlockPos const&, unsigned char) const;
	virtual int getColorForParticle(BlockSource&, BlockPos const&, int) const;
	virtual bool isSeasonTinted(BlockSource&, BlockPos const&) const;
	virtual void prepareRender(BlockSource&, BlockPos const&);
	virtual void onGraphicsModeChanged(bool, bool, bool);
	virtual int getRenderLayer(BlockSource&, BlockPos const&) const;
	virtual int getExtraRenderLayers();
	virtual const AABB& getVisualShape(BlockSource&, BlockPos const&, AABB&, bool);
	virtual const AABB& getVisualShape(unsigned char, AABB&, bool);
	virtual int getVariant(int) const;
	virtual void getMappedFace(signed char, int) const;
	virtual bool animateTick(BlockSource&, BlockPos const&, Random&);
	virtual std::string getDebugText(std::vector<std::string, std::allocator<std::string> >&);
	virtual Block* init();
	virtual bool canBeSilkTouched() const;
	virtual ItemInstance getSilkTouchItemInstance(unsigned char);
	//there are some bugs in the vtable list.so deleted the "virtual" of them↓ 
	void setVisualShape(AABB const&);
	void setVisualShape(Vec3 const&, Vec3 const&);
	Block* setLightBlock(Brightness);
	Block* setLightEmission(float);
	Block* setExplodeable(float);
	Block* setDestroyTime(float);
	Block* setFriction(float);
	Block* setTicking(bool);
	Block* setMapColor(Color const&);
	void addProperty(BlockProperty);
	virtual int getSpawnResourcesAuxValue(unsigned char);

	const std::string& getDescriptionId() const;
	void addAABB(const AABB&, const AABB*, std::vector<AABB, std::allocator<AABB>>&);
	void popResource(BlockSource&, const BlockPos&, const ItemInstance&);
	Block* setCategory(CreativeItemCategory);
	void setSolid(bool);
	bool isSolid() const;
	bool hasProperty(BlockProperty) const;
	CreativeItemCategory getCreativeCategory();
	float getFriction();
	
	static void initBlocks();
	static void teardownBlocks();

	static Block* mAir; // 0
	static Block* mStone; // 1
	static Block* mGrass; // 2
	static Block* mDirt; // 3
	static Block* mCobblestone; // 4
	static Block* mWoodPlanks; // 5
	static Block* mSapling; // 6
	static Block* mBedrock; // 7
	static Block* mFlowingWater; // 8
	static Block* mStillWater; // 9
	static Block* mFlowingLava; // 10
	static Block* mStillLava; // 11
	static Block* mSand; // 12
	static Block* mGravel; // 13
	static Block* mGoldOre; // 14
	static Block* mIronOre; // 15
	static Block* mCoalOre; // 16
	static Block* mLog; // 17
	static Block* mLeaves; // 18
	static Block* mSponge; // 19
	static Block* mGlass; // 20
	static Block* mLapisOre; // 21
	static Block* mLapisBlock; // 22
	static Block* mDispenser; // 23
	static Block* mSandStone; // 24
	static Block* mNote; // 25
	static Block* mBed; // 26
	static Block* mGoldenRail; // 27
	static Block* mDetectorRail; // 28
	static Block* mStickyPiston; // 29
	static Block* mWeb; // 30
	static Block* mTallgrass; // 31
	static Block* mDeadBush; // 32
	static Block* mPiston; // 33
	static Block* mPistonArm; // 34
	static Block* mWool; // 35
	static Block* mYellowFlower; // 37
	static Block* mRedFlower; // 38
	static Block* mBrownMushroom; // 39
	static Block* mRedMushroom; // 40
	static Block* mGoldBlock; // 41
	static Block* mIronBlock; // 42
	static Block* mDoubleStoneSlab; // 43
	static Block* mStoneSlab; // 44
	static Block* mBrick; // 45
	static Block* mTNT; // 46
	static Block* mBookshelf; // 47
	static Block* mMossyCobblestone; // 48
	static Block* mObsidian; // 49
	static Block* mTorch; // 50
	static Block* mFire; // 51
	static Block* mMobSpawner; // 52
	static Block* mOakStairs; // 53
	static Block* mChest; // 54
	static Block* mRedStoneDust; // 55
	static Block* mDiamondOre; // 56
	static Block* mDiamondBlock; // 57
	static Block* mWorkBench; // 58
	static Block* mWheatCrop; // 59
	static Block* mFarmland; // 60
	static Block* mFurnace; // 61
	static Block* mLitFurnace; // 62
	static Block* mSign; // 63
	static Block* mWoodenDoor; // 64
	static Block* mLadder; // 65
	static Block* mRail; // 66
	static Block* mStoneStairs; // 67
	static Block* mWallSign; // 68
	static Block* mLever; // 69
	static Block* mStonePressurePlate; // 70
	static Block* mIronDoor; // 71
	static Block* mWoodPressurePlate; // 72
	static Block* mRedStoneOre; // 73
	static Block* mLitRedStoneOre; // 74
	static Block* mUnlitRedStoneTorch; // 75
	static Block* mLitRedStoneTorch; // 76
	static Block* mStoneButton; // 77
	static Block* mTopSnow; // 78
	static Block* mIce; // 79
	static Block* mSnow; // 80
	static Block* mCactus; // 81
	static Block* mClay; // 82
	static Block* mReeds; // 83
	static Block* mFence; // 85
	static Block* mPumpkin; // 86
	static Block* mNetherrack; // 87
	static Block* mSoulSand; // 88
	static Block* mGlowStone; // 89
	static Block* mPortal; // 90
	static Block* mLitPumpkin; // 91
	static Block* mCake; // 92
	static Block* mUnpoweredRepeater; // 93
	static Block* mPoweredRepeater; // 94
	static Block* mInvisibleBedrock; // 95
	static Block* mTrapdoor; // 96
	static Block* mMonsterStoneEgg; // 97
	static Block* mStoneBrick; // 98
	static Block* mBrownMushroomBlock; // 99
	static Block* mRedMushroomBlock; // 100
	static Block* mIronFence; // 101
	static Block* mGlassPane; // 102
	static Block* mMelon; // 103
	static Block* mPumpkinStem; // 104
	static Block* mMelonStem; // 105
	static Block* mVine; // 106
	static Block* mFenceGateOak; // 107
	static Block* mBrickStairs; // 108
	static Block* mStoneBrickStairs; // 109
	static Block* mMycelium; // 110
	static Block* mWaterlily; // 111
	static Block* mNetherBrick; // 112
	static Block* mNetherFence; // 113
	static Block* mNetherBrickStairs; // 114
	static Block* mNetherWart; // 115
	static Block* mEnchantingTable; // 116
	static Block* mBrewingStand; // 117
	static Block* mCauldron; // 118
	static Block* mEndPortalFrame; // 120
	static Block* mEndStone; // 121
	static Block* mUnlitRedStoneLamp; // 123
	static Block* mLitRedStoneLamp; // 124
	static Block* mActivatorRail; // 126
	static Block* mCocoa; // 127
	static Block* mSandStoneStairs; // 128
	static Block* mEmeraldOre; // 129
	static Block* mTripwireHook; // 131
	static Block* mTripwire; // 132
	static Block* mEmeraldBlock; // 133
	static Block* mSpruceStairs; // 134
	static Block* mBirchStairs; // 135
	static Block* mJungleStairs; // 136
	static Block* mCobblestoneWall; // 139
	static Block* mFlowerPot; // 140
	static Block* mCarrotCrop; // 141
	static Block* mPotatoCrop; // 142
	static Block* mWoodButton; // 143
	static Block* mSkull; // 144
	static Block* mAnvil; // 145
	static Block* mTrappedChest; // 146
	static Block* mLightWeightedPressurePlate; // 147
	static Block* mHeavyWeightedPressurePlate; // 148
	static Block* mUnpoweredComparator; // 149
	static Block* mPoweredComparator; // 150
	static Block* mDaylightDetector; // 151
	static Block* mRedstoneBlock; // 152
	static Block* mQuartzOre; // 153
	static Block* mHopper; // 154
	static Block* mQuartzBlock; // 155
	static Block* mQuartzStairs; // 156
	static Block* mDoubleWoodenSlab; // 157
	static Block* mWoodenSlab; // 158
	static Block* mStainedClay; // 159
	static Block* mLeaves2; // 161
	static Block* mLog2; // 162
	static Block* mAcaciaStairs; // 163
	static Block* mDarkOakStairs; // 164
	static Block* mSlimeBlock; // 165
	static Block* mIronTrapdoor; // 167
	static Block* mHayBlock; // 170
	static Block* mWoolCarpet; // 171
	static Block* mHardenedClay; // 172
	static Block* mCoalBlock; // 173
	static Block* mPackedIce; // 174
	static Block* mDoublePlant; // 175
	static Block* mDaylightDetectorInverted; // 178
	static Block* mRedSandstone; // 179
	static Block* mRedSandstoneStairs; // 180
	static Block* mDoubleStoneSlab2; // 181
	static Block* mStoneSlab2; // 182
	static Block* mSpuceFenceGate; // 183
	static Block* mBirchFenceGate; // 184
	static Block* mJungleFenceGate; // 185
	static Block* mDarkOakFenceGate; // 186
	static Block* mAcaciaFenceGate; // 187
	static Block* mWoodenDoorSpruce; // 193
	static Block* mWoodenDoorBirch; // 194
	static Block* mWoodenDoorJungle; // 195
	static Block* mWoodenDoorAcacia; // 196
	static Block* mWoodenDoorDarkOak; // 197
	static Block* mGrassPathBlock; // 198
	static Block* mItemFrame; // 199
	static Block* mPodzol; // 243
	static Block* mBeetrootCrop; // 244
	static Block* mStonecutterBench; // 245
	static Block* mGlowingObsidian; // 246
	static Block* mNetherReactor; // 247
	static Block* mInfoUpdateGame1; // 248
	static Block* mInfoUpdateGame2; // 249
	static Block* mObserver; // 251
	static Block* mInfoReserved6; // 255
};
struct FireBlock : public Block
{
	static bool canBurn(BlockSource&,BlockPos const&);
	void setFlammable(BlockID,int,int);
};
struct FlowerPotBlock : public Block
{
	static bool isSupportedBlock(Block*,short);
};
struct LeafBlock : public Block
{
	void playerDestroy(Player *,BlockPos const&,int);
};
