/*
 * function: func_021DE2F0
 * address:  0x021DE2F0
 * packet:   pkt_021DE2F0
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021DEE84  0x021DEE84  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021DEE84(void *);
extern void func_020307B0(void *);

void func_021DE2F0(u8 *p)
{
    func_021DEE84(p);
    func_020307B0(p);
}
