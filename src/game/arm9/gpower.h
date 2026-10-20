#ifndef GAME_ARM9_GPOWER_H
#define GAME_ARM9_GPOWER_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gpower.c, prototypes copied from their definitions. */

struct GPowerData;
typedef struct GPowerData GPowerData;

#include "../types.h"

void GPOWER_Init(void);
void GPOWER_CountDownTimers(void);
void GPOWER_ClearAll(void);
void GPOWER_Activate(int powerId, const GPowerData *table, int select);
u8 GPOWER_GetActiveIdOfSameType(int powerId, const GPowerData *table);
u8 GPOWER_GetActiveIdByType(int type);
u32 GPOWER_GetMinutesLeftByType(u32 type);
int GPOWER_GetSelectedMinutesLeft(void);
u8 GPOWER_GetExpiringPowerId(void);
void GPOWER_ClearByPowerId(int powerId, const GPowerData *table);
void GPOWER_ClearType(int type);
GPowerData *GPOWER_LoadPowerTable(u32 heapId);
void GPOWER_FreePowerTable(GPowerData *table);
unsigned int GPOWER_GetPowerType(const GPowerData *table, int powerId);
unsigned int GPOWER_GetPowerCost(const GPowerData *table, int powerId);
void GPOWER_NotifyTimerUpdate(void);
u32 GPOWER_ApplyEncountRate(u32 rate);
u32 GPOWER_ApplyHatchRate(u32 steps);
int GPOWER_ApplyFriendshipBonus(int friendship);
u32 GPOWER_ApplyShopPrice(u32 price);
u32 GPOWER_UseHpRestore(void *party);
u32 GPOWER_UsePpRestore(void *party);
u32 GPOWER_ApplyExpRate(u32 exp);
u32 GPOWER_ApplyPrizeMoney(u32 money);
s32 GPOWER_ApplyCaptureRate(s32 rate);
u32 GPOWER_GetSpecialPowerId(void);
/* END mkheaders: generated region */

typedef struct GPowerData GPowerData;

#endif
