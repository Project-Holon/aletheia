/*
 * function: func_021DE6DC
 * address:  0x021DE6DC
 * packet:   pkt_021DE6DC
 * region:   ov137
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

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_020307B0(void *);

void func_021DE6DC(u8 *p)
{
    func_020307B0(*(void **)(p + 0x110));
}
