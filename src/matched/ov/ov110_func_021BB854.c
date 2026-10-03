/*
 * function: func_021BB854
 * address: 0x021BB854
 * packet: pkt_ov110_021BB854
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BC898 0x021BC898 thumb ov110
 *   func_02040588 0x02040588 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int func_021BC898(u8 *p);
extern void func_02040588(u32,u32);
int func_021BB854(u8 *p) { if (func_021BC898(p+24)!=0) { func_02040588(1,0); return 1; } return 0; }
