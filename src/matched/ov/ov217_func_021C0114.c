/*
 * function: func_021C0114
 * address:  0x021C0114
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: forwards arg(s) 7, 1, 0 to func_02040DA8.
 *
 * symbols:
 *   func_02040DA8  0x02040DA8  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02040DA8(u32, u32, u32);

void func_021C0114(void)
{
    func_02040DA8(7, 1, 0);
}

