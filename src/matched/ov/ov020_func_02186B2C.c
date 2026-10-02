/*
 * function: func_02186B2C
 * address: 0x02186B2C
 * packet: pkt_ov020_02186B2C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Lever: unsigned index scaling retains separate source/destination multiplies.
 * symbols:
 *   func_02082D44 0x02082D44 arm
 */

typedef unsigned int u32;
extern void func_02082D44(const void *src, void *dst, u32 size);
char *func_02186B2C(char *p, char *src) { int i; for (i = 9; i > 0; i--) func_02082D44(p + (u32)(i - 1) * 24, p + (u32)i * 24, 24); func_02082D44(src, p, 24); return p; }
