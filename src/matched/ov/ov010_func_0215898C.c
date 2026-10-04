/*
 * function: func_0215898C
 * address: 0x0215898C
 * packet: pkt_ov010_0215898C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021589DC 0x021589DC thumb ov010
 *   func_021588A4 0x021588A4 thumb ov010
 */
extern int func_021589DC(int a0);
extern void func_021588A4(void *, int);
void func_0215898C(int a, int b) {
    void *p = (void *)func_021589DC(a);
    if (p != 0) func_021588A4(p, b);
}
