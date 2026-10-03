/*
 * function: func_021B6A4C
 * address: 0x021B6A4C
 * packet: pkt_ov101_021B6A4C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6A3C 0x021B6A3C thumb ov101
 *   func_021B6A7C 0x021B6A7C thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B6A3C(u8 *,u32);
extern void func_021B6A7C(u8 *,u16 *);
void func_021B6A4C(u8 *p,u16 *state) { if(*state==0) func_021B6A3C(p,(u32)func_021B6A7C); }
