/*
 * function: func_021B8B5C
 * address: 0x021B8B5C
 * packet: pkt_ov106_021B8B5C
 * region: ov106
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02041090 0x02041090 arm
 *   func_020413B0 0x020413B0 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02041090(u32,u32,u32,u8,u8,u8);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
void func_021B8B5C(u8 *p, u32 a, int b, u8 c) {
    if(a>=4) p+=192;
    func_02041090(a,(u32)p,0,b,32,3);
    func_020413B0(a,0,b,32,3,c);
}
