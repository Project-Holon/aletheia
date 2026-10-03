/*
 * function: func_021BAE94
 * address: 0x021BAE94
 * packet: pkt_ov110_021BAE94
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB658 0x021BB658 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BCF7C 0x021BCF7C thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_021BB6A0 0x021BB6A0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021BB658(u8 *,int);
extern u8 func_021BF6DC(u8 *);
extern void func_021BCF7C(u8 *,int,int);
extern u16 func_021BF724(u8 *);
extern void func_021BB6A0(u8 *,unsigned);
void func_021BAE94(u8 *p,u8 *q) { func_021BB658(*(u8 **)(p+0x58),1); if(**(int **)(p+0x78)==1) { if(func_021BF6DC(q)==1) func_021BCF7C(*(u8 **)(p+0x64),0,0); } else func_021BB6A0(*(u8 **)(p+0x58),func_021BF724(*(u8 **)(p+0x18))); }
