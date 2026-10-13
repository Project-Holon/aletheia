/*
 * function: TR_AI_CmdLoadItem
 * address:  0x021893DC
 * packet:   pkt_ov096_021893DC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj13658.h"

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
struct QI;
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);

int TR_AI_CmdLoadItem(struct Cursor *a, int b) {
    int t;
    u8 s;
    t = VM_GetU32(a);
    s = TR_AI_GetPosition((u8 *)b, t);
    t = BTL_POKEPARAM_GetItem((struct QI *)TR_AI_GetPoke((u8 *)b, s));
    ((struct Obj13658 *)b)->f38 = t;
    return ((struct Obj13658 *)b)->fC4;
}
