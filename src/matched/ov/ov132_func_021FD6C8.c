/*
 * function: func_021FD6C8
 * address:  0x021FD6C8
 * packet:   pkt_021FD6C8
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FCEA8  0x021FCEA8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23291.h"
#include "../include/Obj23292.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021FCEA8(int unused, int kind, u32 value, u32 id);

void func_021FD6C8(u8 *p)
{
    void *q = ((struct Obj23291 *)p)->f140;
    func_021FCEA8((int)p, 4, (u32)(((struct Obj23292 *)q)->f20), 0xff);
}
