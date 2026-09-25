/*
 * function: func_021DF050
 * address:  0x021DF050
 * packet:   pkt_021DF050
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02039338  0x02039338  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02039338(void);

int func_021DF050(u8 *p)
{
    func_02039338();
    *(u32 *)p = 0x1b;
    return 0;
}
