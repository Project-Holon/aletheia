/*
 * function: func_021D572C
 * address:  0x021D572C
 * packet:   pkt_ov118_021D572C
 * region:   ov118
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

typedef unsigned int u32;
typedef unsigned char u8;

extern void func_020307B0(u32);

void func_021D572C(u8 *p, int idx)
{
    if (*(u32 *)(p + 0x85C) != 0) {
        func_020307B0(*(u32 *)(p + 0x85C));
        *(u32 *)(p + 0x85C) = 0;
    }
}
