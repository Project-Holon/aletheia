/*
 * function: TR_AI_CmdLoadItemEffect
 * address:  0x02189400
 * packet:   pkt_ov096_02189400
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   TR_AI_GetItemField  0x0218A3F4  thumb  ov096
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj13659.h"

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
extern int TR_AI_GetItemField(int a, int b, int c);
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);

int TR_AI_CmdLoadItemEffect(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = TR_AI_GetPosition((u8 *)b, t);
    t = BTL_POKEPARAM_GetItem((struct QI *)TR_AI_GetPoke((u8 *)b, s));
    t = TR_AI_GetItemField(b, (u16)t, 1);
    ((struct Obj13659 *)b)->f38 = t;
    return ((struct Obj13659 *)b)->fC4;
}
