/*
 * function: func_021BB9E8
 * address: 0x021BB9E8
 * packet: pkt_ov110_021BB9E8
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after return.
 * lever: bind the step arithmetic to a local before the outer call; the
 * inline argument form adds a saved register and changes scheduling.
 * symbols:
 *   func_02040804 0x02040804 arm
 *   func_021BC78C 0x021BC78C thumb ov110
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 func_02040804(unsigned);
extern void func_021BC78C(u8 *,int,int,int,int);
void func_021BB9E8(u8 *p,u32 unused) { int step=-192-func_02040804(6); func_021BC78C(p+56,6,1,step,8); }
