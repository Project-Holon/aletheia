/*
 * function: func_021F5BCC
 * address: 0x021F5BCC
 * packet: pkt_ov081_021F5BCC
 * region: ov081
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: declare index before bound to put index in r3 and bound in r4.
 */
#include "../include/Obj20798.h"
typedef unsigned short u16;
typedef unsigned int u32;
int func_021F5BCC(int a, u32 p) {
    int i;
    int n = ((struct Obj20798 *)p)->f182;
    for (i=0; i<n; i++) {
        if (a == *(u16 *)(p+i*2+0xC0)) return 1;
    }
    return 0;
}
