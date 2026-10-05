/*
 * function: func_021C9E54
 * address:  0x021C9E54
 * packet:   pkt_021C9E54
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23109.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_020307B0(void *);

void func_021C9E54(u8 *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        func_020307B0(((struct Obj23109 *)p)->f0);
        p += 8;
    }
}
