/*
 * function: TR_AI_CmdCompareStat15
 * address:  0x021895C4
 * packet:   pkt_ov096_021895C4
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   VM_GetU32  0x0201134C  thumb
 *   TR_AI_Compare  0x0218A0F4  thumb  ov096
 *   BTL_POKEPARAM_GetValue  0x021D59B4  thumb  ov093
 *   d_0218A580     0x0218A580  data   ov096  a4
 */
#include "../include/Obj10184.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct { int a, b, c; } Tri;

extern const Tri d_0218A580;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int TR_AI_Compare(u8 *a, int op, int x, int y, int z);
extern int BTL_POKEPARAM_GetValue(u8 *p, int k);

int TR_AI_CmdCompareStat15(struct Cursor *a, int b) {
    int r6;
    int r7;
    int x;
    int y;
    Tri t;
    r6 = VM_GetU32(a);
    r7 = VM_GetU32(a);
    t = d_0218A580;
    x = BTL_POKEPARAM_GetValue(*(u8 * *)&((struct Obj10184 *)b)->fBC, 15);
    y = BTL_POKEPARAM_GetValue(*(u8 * *)&((struct Obj10184 *)b)->fC0, 15);
    TR_AI_Compare((u8 *)a, ((int *)&t)[r6], x, y, r7);
    return ((struct Obj10184 *)b)->fC4;
}
