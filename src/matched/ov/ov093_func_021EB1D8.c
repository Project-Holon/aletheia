/*
 * function: func_021EB1D8
 * address:  0x021EB1D8
 * packet:   pkt_ov093_021EB1D8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_02049740  0x02049740  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020490F4(unsigned int id, u16 heap);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern void func_02049238(void *h);

u16 func_021EB1D8(u8 *a, u32 id, u32 b, u32 c)
{
    void *h = func_020490F4(id, (*(u16 *)(a + 0x13c) & 0x7fff) | 0x8000);
    u32 r = func_02049740(h, b, c, 0, 0, (u16)((*(u16 *)(a + 0x13c) & 0x7fff) | 0x8000));

    func_02049238(h);
    return (u16)r;
}
