/*
 * function: func_021C3B68
 * address: 0x021C3B68
 * packet: pkt_ov093_021C3B68
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021C3B8C 0x021C3B8C thumb ov093
 *   func_021C3BB8 0x021C3BB8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021C3B8C(void *, u32, u32);
extern void func_021C3BB8(u8 *p, u32 a, u32 b);
int func_021C3B68(u8 *p, int a, u8 b)
{
    if (func_021C3B8C(p, a, b)) {
        func_021C3BB8(p, a, b);
        return 1;
    }
    return 0;
}
