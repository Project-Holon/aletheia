/*
 * function: func_0215FA00
 * address: 0x0215FA00
 * packet: pkt_ov010_0215FA00
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034AC4 0x02034AC4 arm
 *   func_02183B6C 0x02183B6C thumb ov020
 *   ov020_id 0x14 data a1
 */

typedef unsigned int u32;
extern unsigned char ov020_id[];
typedef signed int     s32;
extern int func_02034AC4(s32 handle);
extern void func_02183B6C(int a, int *p);
void func_0215FA00(void *p, void *q) { func_02034AC4((u32)ov020_id); func_02183B6C((int)p,q); }
