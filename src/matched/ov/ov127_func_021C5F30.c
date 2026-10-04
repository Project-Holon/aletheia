/*
 * function: func_021C5F30
 * address:  0x021C5F30
 * packet:   pkt_021C5F30
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23061.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_020307B0(void *);

void func_021C5F30(u8 *p)
{
    func_020307B0(((struct Obj23061 *)p)->f0);
    func_020307B0(p);
}
