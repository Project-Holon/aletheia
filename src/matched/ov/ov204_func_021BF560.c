/*
 * function: func_021BF560
 * address: 0x021BF560
 * packet: pkt_ov204_021BF560
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020056BC 0x020056BC thumb
 *   func_0202EF98 0x0202EF98 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020056BC(void);
extern void func_0202EF98(u8 *,u32,u32,u8,u8);
void func_021BF560(u8 *p)
{
    func_0202EF98(*(u8 **)(p+68),func_020056BC(),*(u32 *)(p+28),15,16);
}
