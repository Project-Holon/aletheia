/*
 * file:     hand_waza_021e3190.c
 * unit:     yes
 * function: HAND_WAZA_JudgmentOnWazaTypeCheck, HAND_WAZA_AddTechnoBlast
 * address:  0x021E3190
 * packet:   pkt_ov093_021E3190
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CanUseHeldItem  0x021C824C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 *   gTechnoBlastHandlers  0x021F271C  data   a4
 */
#include "hand_waza_021e2988_types.h"

extern int BTL_EVENT_GetVar(int varId);
extern int BTL_SERVER_FLOW_CanUseHeldItem(struct BtlSvFlow *flow, int pokeId);
extern struct BtlPokeParam *BTL_SERVER_FLOW_GetPokeParam(struct BtlSvFlow *flow, int pokeId);
extern u16 BTL_POKEPARAM_GetItem(struct BtlPokeParam *poke);
extern int BTL_EVENT_OverwriteVar(int varId, u32 value);

BtlEventHandler *HAND_WAZA_AddTechnoBlast(int *handlerCount);

extern BtlEventHandler gTechnoBlastHandlers[];

/* Judgment: the type follows the plate that the user holds. */
void HAND_WAZA_JudgmentOnWazaTypeCheck(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    if (pokeId == BTL_EVENT_GetVar(BTL_EVAR_POKE_ID)) {
        if (BTL_SERVER_FLOW_CanUseHeldItem(flow, pokeId) != 0) {
            u16 itemId = (u16)(int)BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(flow, pokeId));
            int type = POKETYPE_NORMAL;
            switch (itemId) {
            case ITEM_FLAME_PLATE: type = POKETYPE_FIRE; break;
            case ITEM_SPLASH_PLATE: type = POKETYPE_WATER; break;
            case ITEM_ZAP_PLATE: type = POKETYPE_ELECTRIC; break;
            case ITEM_MEADOW_PLATE: type = POKETYPE_GRASS; break;
            case ITEM_ICICLE_PLATE: type = POKETYPE_ICE; break;
            case ITEM_FIST_PLATE: type = POKETYPE_FIGHTING; break;
            case ITEM_TOXIC_PLATE: type = POKETYPE_POISON; break;
            case ITEM_EARTH_PLATE: type = POKETYPE_GROUND; break;
            case ITEM_SKY_PLATE: type = POKETYPE_FLYING; break;
            case ITEM_MIND_PLATE: type = POKETYPE_PSYCHIC; break;
            case ITEM_INSECT_PLATE: type = POKETYPE_BUG; break;
            case ITEM_STONE_PLATE: type = POKETYPE_ROCK; break;
            case ITEM_SPOOKY_PLATE: type = POKETYPE_GHOST; break;
            case ITEM_DRACO_PLATE: type = POKETYPE_DRAGON; break;
            case ITEM_DREAD_PLATE: type = POKETYPE_DARK; break;
            case ITEM_IRON_PLATE: type = POKETYPE_STEEL; break;
            }
            BTL_EVENT_OverwriteVar(BTL_EVAR_MOVE_TYPE, type);
        }
    }
}

/* Techno Blast. */
BtlEventHandler *HAND_WAZA_AddTechnoBlast(int *handlerCount)
{
    *handlerCount = 1;
    return gTechnoBlastHandlers;
}
