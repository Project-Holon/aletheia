/*
 * file:     unit_021D8B50.c
 * unit:     yes
 * function: func_021D8B50, func_021D8B84, func_021D8BB4, func_021D8C00, func_021D8C0C, func_021D8C30, func_021D8C3C, func_021D8C4C, func_021D8C58, func_021D8C68, func_021D8C74, func_021D8C84, func_021D8C90, func_021D8CA0, func_021D8CAC, func_021D8CF4, func_021D8D34
 * address:  0x021D8B50
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
 *   d_021F07C0 0x021F07C0 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021D7AD4 0x021D7AD4 thumb ov093
 *   func_021D7704 0x021D7704 thumb ov093
 *   d_021F07B8 0x021F07B8 data a4
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D76BC   0x021D76BC  thumb ov093
 *   d_021F0698     0x021F0698  data   ov093  a4
 *   func_021D7B60  0x021D7B60  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D62A8  0x021D62A8  thumb  ov093
 *   WAZA_TOOL_GetDamageType  0x0201C1E8  thumb
 *   d_021F07D8     0x021F07D8  data   ov093  a4
 *   d_021F06B0     0x021F06B0  data   ov093  a4
 *   d_021F0610     0x021F0610  data   ov093  a4
 *   d_021F0648     0x021F0648  data   ov093  a4
 *   d_021F0640     0x021F0640  data   ov093  a4
 *   d_021F0638     0x021F0638  data   ov093  a4
 */
#include "unit_021D8434_types.h"

void func_021D8B50(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *func_021D8B78(int *packedInfo);
void func_021D8B84(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
void *func_021D8BA8(int *packedInfo);
void func_021D8BB4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D8C00(int *packedInfo);
void func_021D8C0C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D8C30(int *packedInfo);
void func_021D8C3C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D8C4C(int *packedInfo);
void func_021D8C58(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D8C68(int *packedInfo);
void func_021D8C74(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D8C84(int *packedInfo);
void func_021D8C90(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D8CA0(int *packedInfo);
void func_021D8CAC(struct BtlSvFlow *flow, int pokeId, int moveType);
void func_021D8CF4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
int *func_021D8D34(int *packedInfo);
extern unsigned char d_021F07C0[];
extern unsigned int d_021F07B8;
extern int d_021F0698[];
extern int d_021F07D8[];
extern int d_021F06B0[];
extern int d_021F0610[];
extern int d_021F0648[];
extern int d_021F0640[];
extern int d_021F0638[];

/* Filter and Solid Rock: moves that are super effective against the owner do 0.75 times damage. */
void func_021D8B50(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID) && func_021D7AD4(func_021D775C(BTL_EVAR_TYPE_AFFINITY)) == BTL_AFFINITY_SUPER_EFFECTIVE)
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_0_75);
}

/* Filter and Solid Rock: handler table. */
void *func_021D8B78(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F07C0;
}

/* Sniper: critical hits of the owner do 1.5 times damage again. */
void func_021D8B84(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && func_021D775C(BTL_EVAR_CRITICAL_FLAG))
        func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_1_5);
}

/* Sniper: handler table. */
void *func_021D8BA8(int *packedInfo) { *packedInfo = 1; return &d_021F07B8; }

/* Speed Boost: raises the speed of the owner by one rank at the end of the turn. */
void func_021D8BB4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    BtlRankCmd *cmd;

    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021D5BDC(func_021C7CF4(flow, pokeId), 0) != 0) {
            cmd = func_021C88A4(flow, 14, pokeId);
            cmd->header |= BTL_CMD_FLAG_FROM_ABILITY;
            cmd->statId = 5;
            cmd->targetCount = 1;
            cmd->targets[0] = pokeId;
            cmd->amount = 1;
            func_021C88C8(flow, cmd);
        }
    }
}

/* Speed Boost: handler table. */
int *func_021D8C00(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F0698;
}

/* Adaptability: moves of the owner that get the same type bonus do twice the damage. */
void func_021D8C0C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_POKE_ID)) {
        if (func_021D775C(BTL_EVAR_SAME_TYPE_FLAG) != 0)
            func_021D76BC(BTL_EVAR_RATIO, BTL_RATIO_2_0);
    }
}

/* Adaptability: handler table. */
int *func_021D8C30(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F07D8;
}

/* Blaze. */
void func_021D8C3C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021D8CAC(flow, pokeId, POKETYPE_FIRE);
}

/* Blaze: handler table. */
int *func_021D8C4C(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F06B0;
}

/* Torrent. */
void func_021D8C58(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021D8CAC(flow, pokeId, POKETYPE_WATER);
}

/* Torrent: handler table. */
int *func_021D8C68(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F0610;
}

/* Overgrow. */
void func_021D8C74(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021D8CAC(flow, pokeId, POKETYPE_GRASS);
}

/* Overgrow: handler table. */
int *func_021D8C84(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F0648;
}

/* Swarm. */
void func_021D8C90(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    func_021D8CAC(flow, pokeId, POKETYPE_BUG);
}

/* Swarm: handler table. */
int *func_021D8CA0(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F0640;
}

/* Blaze, Torrent, Overgrow and Swarm: moves of the given type do 1.5 times damage when the owner has a third of its HP or less. */
void func_021D8CAC(struct BtlSvFlow *flow, int pokeId, int moveType)
{
    struct BtlPokeParam *bpp;
    u32 hpThreshold;

    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        bpp = func_021C7CF4(flow, pokeId);
        hpThreshold = func_021D7B60(bpp, 3);
        if (func_021D59B4(bpp, 13) <= hpThreshold) {
            if (moveType == func_021D775C(BTL_EVAR_MOVE_TYPE))
                func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_1_5);
        }
    }
}

/* Guts: physical moves of an owner with a status condition do 1.5 times damage. */
void func_021D8CF4(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID)) {
        if (func_021D62A8(func_021C7CF4(flow, pokeId)) != 0) {
            if (WAZA_TOOL_GetDamageType((u16)func_021D775C(BTL_EVAR_MOVE_ID)) == WAZA_DAMAGE_PHYSICAL)
                func_021D7704(BTL_EVAR_RATIO, BTL_RATIO_1_5);
        }
    }
}

/* Guts: handler table. */
int *func_021D8D34(int *packedInfo)
{
    *packedInfo = 1;
    return d_021F0638;
}
