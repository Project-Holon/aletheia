/*
 * function: func_02172CAC
 * address: 0x02172CAC
 * packet: pkt_ov012_02172CAC
 * region: ov012
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CEAC 0x0203CEAC arm
 *   func_02172D14 0x02172D14 thumb ov012
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_0203CEAC(void *cb);
extern void func_02172D14(u8 *p);
int func_02172CAC(void *a, void *b, u8 *p) { *(u32 *)(p + 0x356c) = 1; if (p[0x3560] < 3) return 0; p[0x3560] = 4; if (func_0203CEAC(func_02172D14) == 0) func_02172D14(p); return 1; }
