/*
 * function: func_02189694
 * address:  0x02189694
 * packet:   pkt_ov096_02189694
 * region:   ov096
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0218A160  0x0218A160  thumb  ov096
 *   func_0218A2FC  0x0218A2FC  thumb  ov096
 *   func_021D57FC  0x021D57FC  thumb  ov093
 *   func_021E8CFC  0x021E8CFC  thumb  ov093
 *   func_021E8D04  0x021E8D04  thumb  ov093
 */
#include "../include/Obj13664.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_0201134C(int);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern u16 func_021D57FC(void *);
extern u8 func_021E8CFC(int);
extern int func_021E8D04(int x);

int func_02189694(int a, int b) {
    int r;
    u8 k;
    int t;
    int p;
    u8 s;
    r = func_0201134C(a);
    k = func_0201134C(a);
    s = func_0218A160((u8 *)b, r);
    p = func_021D57FC(func_0218A2FC((u8 *)b, s));
    if (k == func_021E8CFC(p) || k == func_021E8D04(p)) {
        t = 1;
    } else {
        t = 0;
    }
    ((struct Obj13664 *)b)->f38 = t;
    return ((struct Obj13664 *)b)->fC4;
}
