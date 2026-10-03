/*
 * function: func_02173F9C
 * address: 0x02173F9C
 * packet: pkt_ov011_02173F9C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02175B34 0x02175B34 thumb ov011
 *   func_0203D378 0x0203D378 arm
 *   func_021759C0 0x021759C0 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
u8 *func_02175B34(u8 *p);
u32 func_0203D378(void);
void func_021759C0(u8 *a, u8 b);

void func_02173F9C(int a, int b, void *c, u8 *d)
{
    func_02175B34(d + 0x1ac);
    if (func_0203D378()) func_021759C0(d + 0x1ac, a);
}
