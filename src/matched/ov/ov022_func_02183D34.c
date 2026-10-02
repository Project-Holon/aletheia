/*
 * function: func_02183D34
 * address: 0x02183D34
 * packet: pkt_ov022_02183D34
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Callee's filed definition says void; original caller reads r0 at
 * 02183D42, and ov012 callee leaves func_0203D4D0 result live.
 * symbols:
 *   func_02173F20 0x02173F20 thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02173F20(void *, u32);
void func_02183D34(u8 *p)
{
    if (p[12] != 0 && func_02173F20(p, p[12]) == 1) p[12] = 0;
}
