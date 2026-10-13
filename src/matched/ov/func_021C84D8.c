/*
 * function: BTL_SERVER_FLOW_GetBattleResult
 * address:  0x021C84D8
 * packet:   pkt_021C84D8
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_CheckBattleOutcome   0x021CC668  thumb ov093
 *   BTL_SERVER_FLOW_GetBattleResult   0x021C84D8  thumb ov093
 *
 * tail-call thunk to BTL_SERVER_FLOW_CheckBattleOutcome
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_SERVER_FLOW_CheckBattleOutcome(u8 *p);

int BTL_SERVER_FLOW_GetBattleResult(u8 *p)
{
    return BTL_SERVER_FLOW_CheckBattleOutcome(p);
}
