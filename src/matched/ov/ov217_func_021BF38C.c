/*
 * function: func_021BF38C
 * address:  0x021BF38C
 * packet:   pkt_ov217_021BF38C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF810 0x021BF810 thumb ov217
 *   func_021C0FF8 0x021C0FF8 thumb ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021BF810(void *p);
extern void func_021C0FF8(u8 *p, int visible);
void func_021BF38C(char *p)
{
    if (func_021BF810(p) == 0) {
        func_021C0FF8((u8 *)(*(u32 *)(p + 0x360)), 1);
    } else {
        func_021C0FF8((u8 *)(*(u32 *)(p + 0x360)), 0);
    }
}
