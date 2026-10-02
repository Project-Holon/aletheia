/*
 * function: func_02157AC8
 * address: 0x02157AC8
 * packet: pkt_ov010_02157AC8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02157960 0x02157960 thumb ov010
 *   func_02157A78 0x02157A78 thumb ov010
 */
typedef unsigned char u8;
extern int func_020399A8(void);
extern void func_02039C68(int, int, u8);
extern void func_02157960(int, int, int);
extern void func_02157A78(void);
void func_02157AC8(int *p) { int k = 0x23; func_02039C68(func_020399A8(), k, (u8)p[0]); func_02157960((int)p, (int)func_02157A78, k + 0xfc); }
