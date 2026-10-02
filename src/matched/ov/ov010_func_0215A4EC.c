/*
 * function: func_0215A4EC
 * address: 0x0215A4EC
 * packet: pkt_ov010_0215A4EC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: original narrows r1 by shift pairs; u16 extern preserves this.
 * symbols:
 *   func_02014314 0x02014314 thumb
 */
typedef unsigned short u16;
extern void func_02014314(char *, u16);
void func_0215A4EC(char *a, unsigned b) { func_02014314(a, b + 1420); }
