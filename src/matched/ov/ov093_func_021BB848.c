/*
 * function: func_021BB848
 * address: 0x021BB848
 * packet: pkt_ov093_021BB848
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9B94 0x021B9B94 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_021B9B94(void *);
void func_021BB848(u8 *p, void *q, int v) { *(void **)(p+4) = q; p[8] = func_021B9B94(q); p[9] = v; }
