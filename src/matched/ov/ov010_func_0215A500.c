/*
 * function: func_0215A500
 * address: 0x0215A500
 * packet: pkt_ov010_0215A500
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interface: original narrows r1 by shift pairs; u16 extern preserves this.
 * symbols:
 *   func_0201433C 0x0201433C thumb
 */
typedef unsigned short u16;
extern void func_0201433C(char *a0, int a1);
void func_0215A500(char *a, unsigned b) { func_0201433C(a, (u16)(b + 1420)); }
