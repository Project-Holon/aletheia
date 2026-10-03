/*
 * function: func_021BAB70
 * address: 0x021BAB70
 * packet: pkt_ov110_021BAB70
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BBB84 0x021BBB84 thumb ov110
 *   func_021BBC10 0x021BBC10 thumb ov110
 *   func_021B9CBC 0x021B9CBC thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 func_021BF724(u8 *);
extern void func_021BBB84(u8 *,unsigned);
extern int func_021BBC10(u8 *);
extern void func_021B9CBC(u8 *);
void func_021BAB70(int a,u8 *p) { u8 *q; q=*(u8 **)p; switch(*(int *)(p+0x14)) { case 0: func_021BBB84(*(u8 **)(q+0x58),func_021BF724(*(u8 **)(q+0x18))); (*(int *)(p+0x14))++; break; case 1: if(func_021BBC10(*(u8 **)(q+0x58))) func_021B9CBC(p); break; } }
