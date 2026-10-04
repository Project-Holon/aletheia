/*
 * function: func_021BFBFC
 * address:  0x021BFBFC
 * packet:   pkt_ov217_021BFBFC
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C10C8 0x021C10C8 thumb ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14746.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021C10C8(u32 a0);
void func_021BFBFC(char *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        *(u32 *)(p + i * 4 + 0x2bc) = func_021C10C8(((struct Obj14746 *)p)->f4);
        *(u32 *)(p + i * 4 + 0x2c4) = func_021C10C8(((struct Obj14746 *)p)->f4);
    }
}
