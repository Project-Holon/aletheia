/*
 * function: func_021BEFD4
 * address:  0x021BEFD4
 * packet:   pkt_ov217_021BEFD4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BEFC0 0x021BEFC0 thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25923.h"

typedef unsigned int u32;
typedef unsigned char u8;
extern void func_021BEFC0(void *p, u8 i);
void func_021BEFD4(char *p)
{
    int i;
    int n;
    n = ((struct Obj25923 *)p)->f2FC;
    for (i = 0; i < n; i++) {
        func_021BEFC0(p, (u8)i);
    }
}
