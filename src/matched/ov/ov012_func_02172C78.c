/*
 * function: func_02172C78
 * address: 0x02172C78
 * packet: pkt_ov012_02172C78
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: existing matched follower ov012_func_02172C98.c
 * symbols:
 *   func_0203D0FC 0x0203D0FC arm
 */
typedef unsigned char u8;
extern void func_0203D0FC(int a);
int func_02172C78(void *a, void *b, u8 *p) { if (p[0x3560] >= 2) { p[0x3560] = 3; func_0203D0FC(0); return 1; } return 0; }
