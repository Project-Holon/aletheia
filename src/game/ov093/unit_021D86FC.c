/*
 * file:     unit_021D86FC.c
 * unit:     yes
 * function: func_021D86FC, func_021D8734, func_021D8760, func_021D8794
 * address:  0x021D86FC
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
 *   d_021F07C8 0x021F07C8 data ov093 a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   d_021F0740 0x021F0740 data ov093 a4
 *   func_021C8288 0x021C8288 thumb ov093
 *   d_021F05D8 0x021F05D8 data a4
 */
#include "unit_021D8434_types.h"

void func_021D86FC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
u8 *func_021D8728(u32 *packedInfo);
void func_021D8734(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void func_021D8760(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
u8 *func_021D8788(u32 *packedInfo);
void func_021D8794(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
u8 *func_021D87BC(u32 *packedInfo);
extern u8 d_021F07C8[];
extern u8 d_021F0740[];
extern u8 d_021F05D8[];

/* Thick Fat: halves the attack power of fire and ice moves against the owner. */
void func_021D86FC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 moveType;

    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID)) {
        moveType = func_021D775C(BTL_EVAR_MOVE_TYPE);
        if (moveType == POKETYPE_ICE || moveType == POKETYPE_FIRE)
            func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_5);
    }
}

/* Huge Power and Pure Power: handler table. */
u8 *func_021D8728(u32 *packedInfo)
{
    *packedInfo = 1;
    return d_021F07C8;
}

/* Huge Power and Pure Power: doubles the attack power of physical moves. */
void func_021D8734(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (WAZA_TOOL_GetDamageType((u16)func_021D775C(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
            func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Swift Swim: doubles the speed in rain. */
void func_021D8760(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021C8288(flow) == BTL_WEATHER_RAIN)
            func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Swift Swim: handler table. */
u8 *func_021D8788(u32 *packedInfo)
{
    *packedInfo = 1;
    return d_021F0740;
}

/* Chlorophyll: doubles the speed in sun. */
void func_021D8794(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021C8288(flow) == BTL_WEATHER_SUN)
            func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Chlorophyll: handler table. */
u8 *func_021D87BC(u32 *packedInfo)
{
    *packedInfo = 1;
    return d_021F05D8;
}
