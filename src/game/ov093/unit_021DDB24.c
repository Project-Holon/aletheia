/*
 * file:     unit_021DDB24.c
 * unit:     yes
 * function: BTL_ITEM_WeakenDamageGrass, BTL_ITEM_GetWeakenDamageIceHandlers, BTL_ITEM_WeakenDamageIce, BTL_ITEM_GetWeakenDamageFightingHandlers
 * address:  0x021DDB24
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
 *   gBtlItemWeakenDamageIceHandlers     0x021F17AC  data   ov093  a4
 *   gBtlItemWeakenDamageFightingHandlers     0x021F171C  data   ov093  a4
 */
#include "unit_021DD588_types.h"

extern int BTL_HANDLER_ITEM_WeakenHitOfType(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int moveType, int ignoreAffinity);

extern int gBtlItemWeakenDamageIceHandlers[];
extern int gBtlItemWeakenDamageFightingHandlers[];

void BTL_ITEM_WeakenDamageGrass(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
void BTL_ITEM_WeakenDamageIce(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *BTL_ITEM_GetWeakenDamageIceHandlers(int *handlerCount);
int *BTL_ITEM_GetWeakenDamageFightingHandlers(int *handlerCount);

void BTL_ITEM_WeakenDamageGrass(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_GRASS, 0);
}

int *BTL_ITEM_GetWeakenDamageIceHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageIceHandlers;
}

void BTL_ITEM_WeakenDamageIce(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    BTL_HANDLER_ITEM_WeakenHitOfType(factor, server, pokeId, work, POKETYPE_ICE, 0);
}

int *BTL_ITEM_GetWeakenDamageFightingHandlers(int *handlerCount)
{
    *handlerCount = 2;
    return gBtlItemWeakenDamageFightingHandlers;
}
