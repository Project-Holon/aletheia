/*
 * function: func_02157D68
 * address: 0x02157D68
 * packet: pkt_ov010_02157D68
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_020399A8 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02157960 0x02157960 thumb ov010
 *   func_02157D0C 0x02157D0C thumb ov010
 */
typedef unsigned char u8;
extern int func_0203D1B4(void);
extern int func_020399A8(void);
extern void func_02039C68(int, int, u8);
extern void func_02157960(int, int, int);
extern void func_02157D0C(int *p);
void func_02157D68(int *p) { if (func_0203D1B4() > 1) { func_02039C68(func_020399A8(), 0x17, (u8)p[0]); func_02157960((int)p, (int)func_02157D0C, 0x1af); } }
