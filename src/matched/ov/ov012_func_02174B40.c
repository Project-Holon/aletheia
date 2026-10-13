/*
 * function: func_02174B40
 * address: 0x02174B40
 * packet: pkt_ov012_02174B40
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203A574 0x0203A574 arm
 *   gColosseumCommandTable 0x02175588 data a4
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_0203A574(u32,u32,u32,u32);
extern u32 gColosseumCommandTable[];
void func_02174B40(u32 p)
{
    func_0203A574(0x1500, (u32)gColosseumCommandTable, 14, p);
}
