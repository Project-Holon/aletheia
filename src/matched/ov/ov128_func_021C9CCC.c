/*
 * function: func_021C9CCC
 * address: 0x021C9CCC
 * packet: pkt_ov128_021C9CCC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020410D0 0x020410D0 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020410D0(u32,u32,u32,u32,u8,void *,u8,u8,u8,u8);
extern void func_02041B6C(u32);
void func_021C9CCC(void *unused,u8 *p)
{
    u16 *q = *(u16 **)(p+0x178);
    func_020410D0(2,0,20,32,4,(u8 *)q+12,0,28,(u32)q[0]>>3,(u32)q[1]>>3);
    func_02041B6C(2);
}
