/*
 * function: func_021841E0
 * address: 0x021841E0
 * packet: pkt_ov023_021841E0
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203A574 0x0203A574 arm
 *   d_02186A6C 0x02186A6C data ov023 a4
 */
typedef unsigned int u32;
extern char d_02186A6C[];
extern void func_0203A574(u32 a, u32 b, u32 c, u32 d);
void func_021841E0(u32 a)
{
    func_0203A574(0x2900, (u32)d_02186A6C, 8, a);
}
