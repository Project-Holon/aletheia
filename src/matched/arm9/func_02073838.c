/*
 * function: func_02073838
 * address:  0x02073838
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */
#include "../include/Obj08946.h"

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;


extern int func_0207292C(int mask);
int func_02073838(u8 *o, int n, u8 *src) {

    u32 m = 0;
    int i;
    for (i = 0; i < n; i++) {
        o[0x54 + i] = src[i];
        m |= 1u << src[i];
    }
    if (func_0207292C(m) == 0) return 0;
    ((struct Obj08946 *)o)->f50 = n;
    ((struct Obj08946 *)o)->f4C = m;
    return 1;
}
