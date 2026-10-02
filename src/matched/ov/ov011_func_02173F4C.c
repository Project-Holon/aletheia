/*
 * function: func_02173F4C
 * address: 0x02173F4C
 * packet: pkt_ov011_02173F4C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02175B34 0x02175B34 thumb ov011
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_021759B0 0x021759B0 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
void *func_02175B34(u8 *a);
int func_0203EFC8(const void *a, const void *b, u32 n);
void func_021759B0(u8 *a);

void func_02173F4C(int a, int b, void *c, u8 *d)
{
    void *p;
    p = func_02175B34(d + 0x1ac);
    if (p != 0 && func_0203EFC8(p, c, 0x34) == 0) func_021759B0(d + 0x1ac);
}
