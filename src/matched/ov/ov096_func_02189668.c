/*
 * function: func_02189668
 * address:  0x02189668
 * packet:   pkt_ov096_02189668
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A0F4  0x0218A0F4  thumb  ov096
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj10185.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int func_0218A0F4(u8 *a, int op, int x, int y, int z);

int func_02189668(struct Cursor *a, int b) {
    int r;
    r = VM_GetU32(a);
    func_0218A0F4((u8 *)a, 2, ((u8 *)b)[0x94] & 1, ((u8 *)b)[0x95] & 1, r);
    return ((struct Obj10185 *)b)->fC4;
}
