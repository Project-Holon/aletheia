#ifndef GAME_OV095_BTL_POKESET_H
#define GAME_OV095_BTL_POKESET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_pokeset.c, prototypes copied from their definitions. */

struct BtlPokeParam;
struct BtlServerFlow;

#include "../ov095/btl_pokeset_types.h"
#include "../types.h"

void BTL_POKESET_Clear(BtlPokeSet *p);
void BTL_POKESET_Add(BtlPokeSet *p, struct BtlPokeParam *id);
void BTL_POKESET_AddWithDamage(BtlPokeSet *p, struct BtlPokeParam *id, u16 amt, int flag);
void BTL_POKESET_Remove(BtlPokeSet *p, struct BtlPokeParam *id);
struct BtlPokeParam *BTL_POKESET_Get(BtlPokeSet *p, u32 i);
void BTL_POKESET_SeekStart(BtlPokeSet *p);
struct BtlPokeParam *BTL_POKESET_SeekNext(BtlPokeSet *p);
int BTL_POKESET_GetTotalDamage(BtlPokeSet *p, struct BtlPokeParam *id, u32 *out);
int BTL_POKESET_GetPlainDamage(BtlPokeSet *p, struct BtlPokeParam *id, u32 *out);
u32 BTL_POKESET_GetCount(BtlPokeSet *p);
int BTL_POKESET_GetCountMax(BtlPokeSet *p);
void BTL_POKESET_SetEmptyMarked(BtlPokeSet *p, u8 v);
int BTL_POKESET_IsRemovedAll(BtlPokeSet *p);
int BTL_POKESET_CopyAlive(BtlPokeSet *p, BtlPokeSet *q);
int BTL_POKESET_CopyFriends(BtlPokeSet *p, struct BtlPokeParam *a, BtlPokeSet *q);
int BTL_POKESET_CopyEnemies(BtlPokeSet *p, struct BtlPokeParam *a, BtlPokeSet *q);
void BTL_POKESET_RemoveFainted(BtlPokeSet *p);
void BTL_POKESET_SortBySpeed(BtlPokeSet *p, struct BtlServerFlow *flow);
/* END mkheaders: generated region */

#endif
