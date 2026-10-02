/*
 * function: func_0215A760
 * address: 0x0215A760
 * packet: pkt_ov010_0215A760
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: original narrows r1/r2 by shift pairs; u16 extern preserves this.
 * symbols:
 *   func_02045B38 0x02045B38 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern void *func_02045B38(unsigned, u16, u16, unsigned);
void func_0215A760(u8 *a, unsigned b, unsigned c) {
 *(void **)(a + 20) = func_02045B38(0, b, c, *(u16 *)a);
 *(u16 *)(a + 24) = c;
}
