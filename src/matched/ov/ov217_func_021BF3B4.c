/*
 * function: func_021BF3B4
 * address:  0x021BF3B4
 * packet:   pkt_ov217_021BF3B4
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C0FF8 0x021C0FF8 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void func_021C0FF8(u32 a, u32 b);
void func_021BF3B4(char *p)
{
    if (*(u32 *)(p + 0x3d0) != 0) {
        func_021C0FF8(*(u32 *)(p + 0x364), 1);
    } else {
        func_021C0FF8(*(u32 *)(p + 0x364), 0);
    }
}
