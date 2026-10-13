/*
 * file:     unit_021DB9AC.c
 * unit:     yes
 * function: func_021DB9AC, func_021DB9B8, func_021DB9D0, func_021DB9DC, func_021DBA00, func_021DBA0C, func_021DBA74, func_021DBA80, func_021DBAE4
 * address:  0x021DB9AC
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
 *   d_021F06F8 0x021F06F8 data a4
 *   func_021D76BC   0x021D76BC  thumb
 *   func_021D775C   0x021D775C  thumb
 *   d_021F06E8 0x021F06E8 data a4
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021C7D00  0x021C7D00  thumb  ov093
 *   func_021C7F68  0x021C7F68  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   d_021F06F0     0x021F06F0  data   ov093  a4
 *   func_021C8234  0x021C8234  thumb  ov093
 *   d_021F06E0     0x021F06E0  data   ov093  a4
 *   d_021F06D8     0x021F06D8  data   ov093  a4
 */
#include "unit_021DB0E4_types.h"

/* Ability handlers: Magic Guard, Stench, Shadow Tag, Arena Trap, and the table getter of Magnet Pull. */

#define ABILITY_SHADOW_TAG 0x17
#define STENCH_FLINCH_CHANCE 10
#define OPPONENT_ID_BUFFER_SIZE 4

const BtlEventHandler *func_021DB9AC(int *handlerCount);
void func_021DB9B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DB9D0(int *handlerCount);
void func_021DB9DC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DBA00(int *handlerCount);
void func_021DBA0C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DBA74(int *handlerCount);
void func_021DBA80(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId);
const BtlEventHandler *func_021DBAE4(int *handlerCount);
extern const BtlEventHandler d_021F06F8[];
extern const BtlEventHandler d_021F06E8[];
extern const BtlEventHandler d_021F06F0[];
extern const BtlEventHandler d_021F06E0[];
extern const BtlEventHandler d_021F06D8[];

const BtlEventHandler *func_021DB9AC(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F06F8;
}


/* Magic Guard: when the holder is the target, clear the effect flag. */
void func_021DB9B8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_DEFENDER_ID))
        func_021D76BC(BTL_EVAR_EFFECT_FLAG, 0);
}


const BtlEventHandler *func_021DB9D0(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F06F0;
}


/* Stench: when the holder attacks and the move has no flinch chance of its own, give it the Stench chance. */
void func_021DB9DC(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    if (pokeId == func_021D775C(BTL_EVAR_ATTACKER_ID) && (unsigned char)func_021D775C(BTL_EVAR_FLINCH_BASE_CHANCE) == 0)
        func_021D76BC(BTL_EVAR_FLINCH_CHANCE, STENCH_FLINCH_CHANCE);
}


const BtlEventHandler *func_021DBA00(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F06E8;
}


/* Shadow Tag: opposing pokes cannot escape, unless one of them has Shadow Tag too. */
void func_021DBA0C(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 opponentIds[OPPONENT_ID_BUFFER_SIZE];
    u32 opponentCount;
    u8 i;

    if (func_021B9A24((u8)func_021D775C(BTL_EVAR_POKE_ID), pokeId) == 0) {
        opponentCount = func_021C7F68(flow, (u16)(func_021C7D00(flow, pokeId) | 0x100), opponentIds);
        for (i = 0; i < opponentCount; i++) {
            if (func_021D59B4(func_021C7CF4(flow, opponentIds[i]), BPP_VALUE_CURRENT_ABILITY) == ABILITY_SHADOW_TAG)
                return;
        }
        func_021D76BC(BTL_EVAR_PREVENT_FLAG, 1);
    }
}


const BtlEventHandler *func_021DBA74(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F06E0;
}


/* Arena Trap: opposing pokes cannot escape while one of them passes the ground check. */
void func_021DBA80(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId)
{
    u8 opponentIds[OPPONENT_ID_BUFFER_SIZE];
    u32 opponentCount;
    u8 i;

    if (func_021B9A24((u8)func_021D775C(BTL_EVAR_POKE_ID), pokeId) == 0) {
        opponentCount = func_021C7F68(flow, (u16)(func_021C7D00(flow, pokeId) | 0x100), opponentIds);
        for (i = 0; i < opponentCount; i++) {
            if (func_021C8234(flow, opponentIds[i]) == 0) {
                func_021D76BC(BTL_EVAR_PREVENT_FLAG, 1);
                return;
            }
        }
    }
}


const BtlEventHandler *func_021DBAE4(int *handlerCount)
{
    *handlerCount = 1;
    return d_021F06D8;
}
