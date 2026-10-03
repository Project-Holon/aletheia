/*
 * function: func_021BACDC
 * address: 0x021BACDC
 * packet: pkt_ov110_021BACDC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BFD94 0x021BFD94 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct { short x,y; } Vec2;
extern unsigned func_021BFD94(u8 *,Vec2 *);
int func_021BACDC(u8 *p,int unused,unsigned n) { Vec2 pos; if(func_021BFD94(*(u8 **)(p+0x5c),&pos)==0) return 3; if(n<(unsigned)pos.y) return 1; if(n>(unsigned)pos.y) return 2; if(n==(unsigned)pos.y) return 0; return 3; }
