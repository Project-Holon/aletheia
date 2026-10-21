#ifndef GAME_OV091_PLIST_DEMO_H
#define GAME_OV091_PLIST_DEMO_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of plist_demo.c, prototypes copied from their definitions. */

struct PokemonParam;

#include "../ov091/pokelist_types.h"
#include "../types.h"

void PLIST_DEMO_CreateParticles(PokelistWork *work);
void PLIST_DEMO_DeleteParticles(PokelistWork *work);
int PLIST_DEMO_CheckGiratinaToOrigin(PokelistWork *work, void *unused);
void PLIST_DEMO_ApplyGiratinaOriginForm(PokelistWork *work, void *mon);
int PLIST_DEMO_CheckGiratinaToAltered(PokelistWork *work, void *unused);
void PLIST_DEMO_ApplyGiratinaAlteredForm(PokelistWork *work, void *mon);
int PLIST_DEMO_CanUseGracidea(PokelistWork *work, void *unused);
void PLIST_DEMO_ApplyShayminSkyForm(PokelistWork *work, void *mon);
int PLIST_DEMO_CheckItemUsable(void *mon, u32 itemId, int moveSlot, u32 heapId);
int PLIST_DEMO_UseItemOnMon(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);
int PLIST_DEMO_RaiseMovePpUps(void *mon, int moveSlot, int ups);
void PLIST_DEMO_RestoreHp(void *mon, u32 hp, u32 maxHp, u32 amount);
int PLIST_DEMO_AddEv(int ev, int otherEvTotal, int delta, int ignoreCap);
int PLIST_DEMO_FriendshipItemApplies(void *mon, void *itemRec);
int PLIST_DEMO_ApplyFriendshipItem(struct PokemonParam *mon, int friendship, int delta, int item, u16 zoneId, int heapId);
/* END mkheaders: generated region */

#endif
