#pragma once

#include "../PathfinderMob.h"

// Size : 3224
class Monster : public PathfinderMob
{
public:
	char filler1[20]; // 3204

public:
	Monster(BlockSource &);
	virtual ~Monster();
	virtual void normalTick();
	virtual bool isSurfaceMob() const;
	virtual void hurt(EntityDamageSource &, int);
	virtual void readAdditionalSaveData(const CompoundTag *);
	virtual void addAdditionalSaveData(CompoundTag*);
	virtual bool canSpawn();
	virtual void doHurtTarget(Entity *);
	virtual void getWalkTargetValue(const BlockPos &);
	virtual void findAttackTarget();
	virtual void checkHurtTarget(Entity *, float);
	virtual void getAttackDamage(Entity *);
	virtual void getAttackTime();
	void setNightly();
};
