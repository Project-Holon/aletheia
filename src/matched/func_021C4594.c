/*
 * function: func_021C4594
 * address:  0x021C4594
 * packet:   pkt_021C4594
 * region:   ov127
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204ADA4  0x0204ADA4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_0204ADA4(void *);

void func_021C4594(u8 *p)
{
    func_0204ADA4(*(void **)(p + 0x2f4));
    *(u32 *)(p + 0x2f4) = (u32)-1;
}
