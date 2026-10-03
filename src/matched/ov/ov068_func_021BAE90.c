/*
 * function: func_021BAE90
 * address: 0x021BAE90
 * packet: pkt_ov068_021BAE90
 * region: ov068
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent follower 021BAEBC is already filed separately.
 * symbols:
 *   func_0207D658 0x0207D658 arm
 *   func_02040588 0x02040588 arm
 *   func_021BA278 0x021BA278 thumb ov068
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0207D658(u32, int, int);
typedef unsigned char  u8;
extern void func_02040588(u32 which, u32 enable);
extern void func_021BA278(u8 *p, u32 a, u32 b, u32 c);
void func_021BAE90(void *p, u32 value)
{
    func_0207D658(0x04000050, 23, 8);
    func_02040588(3, 1);
    func_021BA278(p, 33, value, 0);
}
