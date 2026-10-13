/*
 * file:     unit_021DDBA4.c
 * unit:     yes
 * function: BTL_ITEM_WeakenDamageGround, BTL_ITEM_GetWeakenDamageFlyingHandlers, BTL_ITEM_WeakenDamageFlying, BTL_ITEM_GetWeakenDamagePsychicHandlers
 * address:  0x021DDBA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   BTL_HANDLER_ITEM_WeakenHitOfType   0x021DDCD8  thumb
 *   gBtlItemWeakenDamageFlyingHandlers     0x021F17DC  data   ov093  a4
 *   gBtlItemWeakenDamagePsychicHandlers     0x021F172C  data   ov093  a4
 */
#include "unit_021DD588_types.h"

extern int BTL_HANDLER_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int moveType, int ignoreAffinity);

extern int gBtlItemWeakenDamageFlyingHandlers[];
extern int gBtlItemWeakenDamagePsychicHandlers[];

void BTL_ITEM_WeakenDamageGround(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_WeakenDamageFlying(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ITEM_GetWeakenDamageFlyingHandlers(int *handlerCount);
int *BTL_ITEM_GetWeakenDamagePsychicHandlers(int *handlerCount);

void BTL_ITEM_WeakenDamageGround(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_GROUND, 0);
}

int *BTL_ITEM_GetWeakenDamageFlyingHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageFlyingHandlers;
}

void BTL_ITEM_WeakenDamageFlying(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_FLYING, 0);
}

int *BTL_ITEM_GetWeakenDamagePsychicHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamagePsychicHandlers;
}
