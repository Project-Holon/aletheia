/*
 * function: func_021C987C
 * address: 0x021C987C
 * packet: pkt_ov128_021C987C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C6DD8 0x021C6DD8 thumb ov128
 *   func_021C9CCC 0x021C9CCC thumb ov128
 *   func_021C9BC4 0x021C9BC4 thumb ov128
 *   func_02041300 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02041090 0x02041090 arm
 *   func_021C6B38 0x021C6B38 thumb ov128
 *   func_021CA4C8 0x021CA4C8 thumb ov128
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021C6DD8(u8 *p, u32 a);
extern void func_021C9CCC(void *,u8 *);
extern void func_021C9BC4(u32 p);
extern void func_02041300(u32,int,int,int,u8,u8,u8);
extern void func_02041B6C(u32);
extern void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5);
extern void func_021C6B38(u8 *p);
extern void func_021CA4C8(void *);
void func_021C987C(u8 *p,u8 *q)
{
    u16 *t;
    func_021C6DD8(q,0);
    func_021C9CCC(p,q);
    func_021C9BC4((u32)p);
    func_02041300(2,0,0,0,32,32,0);
    func_02041B6C(2);
    t=*(u16 **)(p+0x10c);
    func_02041090(0,(u32)((u8 *)t+12),0,0,(u32)t[0]>>3,(u32)t[1]>>3);
    func_02041B6C(0);
    func_021C6B38(q);
    func_021CA4C8(p);
}
