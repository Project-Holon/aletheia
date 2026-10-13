/*
 * function: TR_AI_CmdLoadFasterCount
 * address:  0x02189A6C
 * packet:   pkt_ov096_02189A6C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   BTL_SERVER_FLOW_CountFasterPokes  0x021C81D0  thumb  ov093
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj10190.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern u16 BTL_SERVER_FLOW_CountFasterPokes(u8 *p, u8 *a, u32 y);

int TR_AI_CmdLoadFasterCount(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = TR_AI_GetPosition((u8 *)b, t);
    t = BTL_SERVER_FLOW_CountFasterPokes((u8 *)(((struct Obj10190 *)b)->fB4), TR_AI_GetPoke((u8 *)b, s), 1);
    ((struct Obj10190 *)b)->f38 = t;
    return ((struct Obj10190 *)b)->fC4;
}
