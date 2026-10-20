#ifndef GAME_OV095_BTL_SICK_H
#define GAME_OV095_BTL_SICK_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of btl_sick.c, prototypes copied from their definitions. */

struct BtlPokeParam;
struct BtlServerFlow;

#include "../ov093/btl_pokeparam_types.h"
#include "../ov093/hand_common_types.h"
#include "../types.h"

void BTL_SICK_ProcAddedOrTurnEnd(struct BtlPokeParam *bpp, int sickKind, union SickCont cont, int isAdded);
void BTL_SICK_ProcTurnEnd(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId, int sickKind);
int BTL_SICK_BuildDamageMessage(BtlStrParam *message, struct BtlPokeParam *bpp, int sickKind);
int BTL_SICK_GetDamageStringId(int sickKind);
void BTL_SICK_TickPerishSong(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_ApplyLeechSeed(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_RecoverHpIngrain(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_ApplyBindDamage(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_RecoverHpAquaRing(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_EndEncoreWhenPpEmpty(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId);
void BTL_SICK_OnAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, int pokeId, int sickKind, union SickCont cont);
void BTL_SICK_StartYawnSleep(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
void BTL_SICK_ApplyPerishFaint(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
void BTL_SICK_ShowPerishCount(struct BtlServerFlow *flow, struct BtlPokeParam *bpp, u8 count);
void BTL_SICK_OnHealBlockAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
void BTL_SICK_OnItemBlockAdded(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
int BTL_SICK_GetCureStringId(unsigned int sickKind, union SickCont cont);
void BTL_SICK_BuildCureMessage(int sickKind, union SickCont cont, struct BtlPokeParam *bpp, BtlStrParam *message);
int BTL_SICK_GetAddStringId(u32 sickKind, int hasArg);
int BTL_SICK_BuildAddMessage(int sickKind, union SickCont cont, struct BtlPokeParam *bpp, u8 argValue, BtlStrParam *message);
void BTL_SICK_OverrideGroundImmunity(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
void BTL_SICK_ForceGroundedByTrap(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
void BTL_SICK_ForceGroundedOrFloating(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
void BTL_SICK_ShowIngrainRoots(struct BtlServerFlow *flow, struct BtlPokeParam *bpp);
/* END mkheaders: generated region */

#endif
