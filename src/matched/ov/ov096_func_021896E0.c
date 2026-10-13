/*
 * function: func_021896E0
 * address:  0x021896E0
 * packet:   pkt_ov096_021896E0
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A220  0x0218A220  thumb  ov096
 *   VM_GetU32  0x0201134C  thumb
 */
#include "../include/Obj13665.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern u8 func_0218A160(u8 *p, int k);
extern int func_0218A220(u8 *p, int k, int slot);

int func_021896E0(struct Cursor *a, int b) {
    int r;
    int r2;
    int t;
    r = VM_GetU32(a);
    r2 = VM_GetU32(a);
    t = func_0218A160((u8 *)b, r);
    t = func_0218A220((u8 *)b, r, t);
    if (t == r2) {
        t = 1;
    } else {
        t = 0;
    }
    ((struct Obj13665 *)b)->f38 = t;
    return ((struct Obj13665 *)b)->fC4;
}
