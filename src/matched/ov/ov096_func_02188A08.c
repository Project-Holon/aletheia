/*
 * function: TR_AI_CompareSideEffect
 * address:  0x02188A08
 * packet:   pkt_ov096_02188A08
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_Compare  0x0218A0F4  thumb  ov096
 *   BTL_SERVER_FLOW_GetSideEffectEntry  0x021C82D0  thumb  ov093
 */
#include "../include/Obj21934.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern int TR_AI_Compare(u8 *a, int op, int x, int y, int z);
extern int BTL_SERVER_FLOW_GetSideEffectEntry(int unused, unsigned int v, int k);

int TR_AI_CompareSideEffect(struct Cursor *a, int b, int c)
{
    int t0;
    int t1;
    int t2;
    int r;

    t0 = VM_GetU32(a);
    t1 = VM_GetU32(a);
    t2 = VM_GetU32(a);
    r = TR_AI_GetPosition((u8 *)b, t0);
    r = BTL_SERVER_FLOW_GetSideEffectEntry(((struct Obj21934 *)b)->fB4, r, t1);
    return TR_AI_Compare((u8 *)a, c, r != 0, 1, t2);
}
