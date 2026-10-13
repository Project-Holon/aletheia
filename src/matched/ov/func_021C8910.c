/*
 * function: BTL_SERVER_FLOW_GetLockStateThunk
 * address:  0x021C8910
 * packet:   pkt_021C8910
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetLockState   0x021C88E4  thumb ov093
 *   BTL_SERVER_FLOW_GetLockStateThunk   0x021C8910  thumb ov093
 *
 * tail-call thunk to BTL_SERVER_FLOW_GetLockState
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern int BTL_SERVER_FLOW_GetLockState(u8 *p);

int BTL_SERVER_FLOW_GetLockStateThunk(u8 *p)
{
    return BTL_SERVER_FLOW_GetLockState(p);
}
