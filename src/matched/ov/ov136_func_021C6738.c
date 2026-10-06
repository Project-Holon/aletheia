/*
 * function: func_021C6738
 * address:  0x021C6738
 * packet:   pkt_ov136_021C6738
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4         0x020490F4  arm
 */
#include "../include/Obj23595.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
void func_021C6738(u8 *p)
{
    ((struct Obj23595 *)p)->f290 = func_020490F4(7, 0x66);
}
