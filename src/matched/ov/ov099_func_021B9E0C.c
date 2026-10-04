/*
 * function: func_021B9E0C
 * address:  0x021B9E0C
 * packet:   pkt_ov099_021B9E0C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049B40  0x02049B40  arm
 *   func_02040EBC  0x02040EBC  arm
 *   func_02049624  0x02049624  arm
 */
typedef unsigned int u32;
typedef unsigned short u16;

extern u32 func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02040EBC(u32 a, u32 b);
extern u32 func_02049624(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

void func_021B9E0C(u32 a, u32 b, u32 c, u32 d)
{
    u32 z = 0;
    func_02049B40(d, 7, 0, 0, 0x100, b);
    func_02040EBC(0, 0);
    func_02049624(d, 0x10, 0, 0, z, z, b);
}
