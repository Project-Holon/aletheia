/*
 * function: func_021B7D6C
 * address: 0x021B7D6C
 * packet: pkt_ov071_021B7D6C
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02041300 0x02041300 arm
 *   d_021BA928 0x021BA928 data a4
 */

typedef unsigned char u8;
extern const char d_021BA928[];
extern void func_0203FCA0(unsigned,const void *,unsigned);
extern void func_02041300(unsigned,int,int,int,u8,u8,u8);
void func_021B7D6C(void) { func_0203FCA0(2,d_021BA928,0); func_02041300(2,0,0,0,0x20,0x20,0x11); }
