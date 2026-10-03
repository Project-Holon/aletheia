/*
 * unit: yes
 * function: func_021BCDFC, func_021BCE24
 * address: 0x021BCDFC
 * packet: pkt_ov110_021BCDFC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BCFF0 0x021BCFF0 thumb ov110
 *   func_021BD0F8 0x021BD0F8 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 func_021BF6DC(u8 *);
extern u32 func_021BCFF0(char *,u32);
extern void func_021BD0F8(void *,int,int);
int func_021BCDFC(char *p) { if (func_021BF6DC(*(u8 **)(p+4))==1) { if (func_021BCFF0(p,2)) return 1; return 0; } return 1; }
void func_021BCE24(void *p) { func_021BD0F8(p,7,1); }
