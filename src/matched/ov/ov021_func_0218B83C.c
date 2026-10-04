/*
 * function: func_0218B83C
 * address:  0x0218B83C
 * packet:   pkt_ov021_0218B83C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0218BCF4  0x0218BCF4  thumb
 *   func_0218C124  0x0218C124  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj12562.h"

extern void func_0218BCF4(char *p);
extern void func_0218C124(char *p, char *q);

void func_0218B83C(char *p)
{
    int i;
    unsigned u;

    func_0218BCF4(p + 8);
    for (i = 0; i < 7; i++) {
        char *q = *(char **)(p + 0x1DC + i * 4);
        if (q != 0)
            func_0218C124(p, q + 0xC);
    }
    for (u = 0; u < ((struct Obj12562 *)p)->f1D4; u++)
        func_0218C124(p, *(char * *)&((struct Obj12562 *)p)->f1D8 + u * 0x18);
}
