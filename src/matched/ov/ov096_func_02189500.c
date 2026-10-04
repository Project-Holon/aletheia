/*
 * function: func_02189500
 * address:  0x02189500
 * packet:   pkt_ov096_02189500
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0218A378  0x0218A378  thumb  ov096
 */
#include "../include/Obj07923.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0218A378(int, u16, int);

int func_02189500(int a, int b) {
    int t;
    if (((struct Obj07923 *)b)->f38 != 0) {
        t = func_0218A378(b, (u16)((struct Obj07923 *)b)->f38, 3);
    } else {
        t = 0;
    }
    ((struct Obj07923 *)b)->f38 = t;
    return ((struct Obj07923 *)b)->fC4;
}
