/*
 * function: func_021897CC
 * address:  0x021897CC
 * packet:   pkt_ov096_021897CC
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_021C82D0  0x021C82D0  thumb  ov093
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj10186.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern int func_021C82D0(int unused, unsigned int v, int k);

int func_021897CC(struct Cursor *a, int b) {
    int r6;
    int r4;
    int t;
    r6 = VM_GetU32(a);
    r4 = VM_GetU32(a);
    t = func_0218A160((u8 *)b, r6);
    t = func_021C82D0(((struct Obj10186 *)b)->fB4, t, r4);
    ((struct Obj10186 *)b)->f38 = t;
    return ((struct Obj10186 *)b)->fC4;
}
