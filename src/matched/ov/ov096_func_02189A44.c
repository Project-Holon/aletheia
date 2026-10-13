/*
 * function: func_02189A44
 * address:  0x02189A44
 * packet:   pkt_ov096_02189A44
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0218A378  0x0218A378  thumb  ov096
 *   BTL_POKEPARAM_GetLastUsedMoveId  0x021D67A8  thumb  ov093
 */
#include "../include/Obj10189.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0218A378(int, int, int);
struct QL;
extern u16 BTL_POKEPARAM_GetLastUsedMoveId(struct QL *p);

int func_02189A44(int a, int b) {
    int t;
    t = BTL_POKEPARAM_GetLastUsedMoveId((struct QL *)(*(u8 * *)&((struct Obj10189 *)b)->fC0));
    if (t != 0) {
        t = func_0218A378(b, t, 2);
    } else {
        t = 0;
    }
    ((struct Obj10189 *)b)->f38 = t;
    return ((struct Obj10189 *)b)->fC4;
}
