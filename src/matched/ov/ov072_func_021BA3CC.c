/*
 * function: func_021BA3CC
 * address: 0x021BA3CC
 * packet: pkt_ov072_021BA3CC
 * region: ov072
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B404 0x0204B404 arm
 */
extern void func_0204B404(void *, void *, int);
void func_021BA3CC(char *p, int *q) {
    *(short *)(p + 8) = q[0];
    *(short *)(p + 10) = q[1];
    func_0204B404(*(void **)p, p + 8, 0);
}
