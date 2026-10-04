/*
 * function: func_021DE5C0
 * address:  0x021DE5C0
 * packet:   pkt_021DE5C0
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F7A8  0x0201F7A8  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj23734.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0201F7A8(void *desc, u32 kind);

void func_021DE5C0(u8 *p)
{
    func_0201F7A8(((struct Obj23734 *)p)->fD4, 0);
}
