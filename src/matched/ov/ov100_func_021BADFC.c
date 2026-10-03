/*
 * function: func_021BADFC
 * address: 0x021BADFC
 * packet: pkt_ov100_021BADFC
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA290 0x021BA290 thumb ov100
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021BADB0 0x021BADB0 thumb ov100
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BA290(int,int),func_021B95B8(u8 *,u32);
extern void func_021BADB0(int);
void func_021BADFC(int p) { func_021BA290(p,0); func_021B95B8((u8 *)p,(u32)func_021BADB0); }
