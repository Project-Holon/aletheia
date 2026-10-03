/*
 * function: func_021B64F0
 * address: 0x021B64F0
 * packet: pkt_ov101_021B64F0
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two zero alignment bytes.
 * symbols:
 *   func_0203A574 0x0203A574 arm
 */
typedef unsigned int u32;
extern void func_0203A574(u32,u32,u32,u32);
void func_021B64F0(u32 p,u32 a,u32 b,u32 c,u32 d) {
    if(*(u32 *)(p+0x78)==0) func_0203A574(a,b,c,d);
}
