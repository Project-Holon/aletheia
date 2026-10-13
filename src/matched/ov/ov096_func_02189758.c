/*
 * function: TR_AI_CmdJumpIfItemEquals
 * address:  0x02189758
 * packet:   pkt_ov096_02189758
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   VM_Jump  0x020113B0  thumb
 *   TR_AI_GetPosition  0x0218A160  thumb  ov096
 *   TR_AI_GetPoke  0x0218A2FC  thumb  ov096
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 */
#include "../include/Obj00005.h"
#include "../include/Obj21970.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
struct Cur;
struct QI;
extern void VM_Jump(struct Cur *c, u32 v);
extern u8 TR_AI_GetPosition(u8 *p, int k);
extern u8 *TR_AI_GetPoke(u8 *p, u8 i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);

int TR_AI_CmdJumpIfItemEquals(struct Cursor *a, int b) {
    int r0;
    int r6;
    int r7;
    u8 *t;
    u8 s;
    r0 = VM_GetU32(a);
    r6 = VM_GetU32(a);
    r7 = VM_GetU32(a);
    s = TR_AI_GetPosition((u8 *)b, r0);
    t = TR_AI_GetPoke((u8 *)b, s);
    if (r6 == BTL_POKEPARAM_GetItem((struct QI *)t)) {
        VM_Jump((struct Cur *)a, *(int *)&((struct Obj00005 *)a)->f14 + r7);
    }
    return ((struct Obj21970 *)b)->fC4;
}
