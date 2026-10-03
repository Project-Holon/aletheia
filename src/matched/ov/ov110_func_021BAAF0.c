/*
 * function: func_021BAAF0
 * address: 0x021BAAF0
 * packet: pkt_ov110_021BAAF0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF7AC 0x021BF7AC thumb ov110
 *   func_021BFA40 0x021BFA40 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_021BF7AC(u8 *);
extern void func_021BFA40(u8 *,unsigned);
extern void func_021B9CBC(u8 *);
void func_021BAAF0(int a,u8 *p) { u8 *q; q=*(u8 **)p; func_021BFA40(*(u8 **)(q+0x5c),func_021BF7AC(*(u8 **)(q+0x18))); func_021B9CBC(p); }
