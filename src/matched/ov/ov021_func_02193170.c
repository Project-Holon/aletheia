/*
 * function: func_02193170
 * address:  0x02193170
 * packet:   pkt_ov021_02193170
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F548  0x0201F548  thumb  arm9
 *   func_02049B90  0x02049B90  arm  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern u32 func_0201F548(u32 a);
extern void func_02049B90(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

void func_02193170(u32 heap)
{
    func_02049B90(5, func_0201F548(0), 0, 0, 0x140, 0x20, heap);
}
