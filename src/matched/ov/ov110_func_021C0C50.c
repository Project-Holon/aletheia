/*
 * function: func_021C0C50
 * address: 0x021C0C50
 * packet: pkt_ov110_021C0C50
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C0C64 0x021C0C64 thumb ov110
 *   func_021C09E0 0x021C09E0 thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021C0C64(u8 *,int);
extern void func_021C09E0(u8 *);
void func_021C0C50(u8 *p) { func_021C0C64(p,1); func_021C09E0(p+0x24); }
