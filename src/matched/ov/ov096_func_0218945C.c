/*
 * function: func_0218945C
 * address:  0x0218945C
 * packet:   pkt_ov096_0218945C
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_0201134C  0x0201134C  thumb
 */
#include "../include/Obj13661.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
struct UtilWork;
extern int func_021D5BDC(struct UtilWork *p, u32 n);

int func_0218945C(int a, int b) {
    int t;
    u8 s;
    int r;
    t = func_0201134C(a);
    s = func_0218A160((u8 *)b, t);
    t = (int)func_0218A2FC((u8 *)b, s);
    r = 0;
    if (func_021D5BDC((struct UtilWork *)t, 0) == 0) {
        r = 1;
    }
    ((struct Obj13661 *)b)->f38 = r;
    return ((struct Obj13661 *)b)->fC4;
}
