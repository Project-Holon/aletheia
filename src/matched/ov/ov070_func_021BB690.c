/*
 * function: func_021BB690
 * address: 0x021BB690
 * packet: pkt_ov070_021BB690
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: expand q at the first call but retain q for the second call.
 * symbols:
 *   func_0204B454 0x0204B454 arm
 *   func_0204B404 0x0204B404 arm
 *   d_021BBBCC 0x021BBBCC data a4
 */
extern void func_0204B454(int, void *, int);
extern void func_0204B404(int, void *, int);
extern short d_021BBBCC[];
int func_021BB690(const char *p)
{
    unsigned i;
    short v[2];
    const char *q;
    int off;
    for (i = 0; i < 5; i++) {
        off = i * 4;
        q = p + off;
        func_0204B454(*((int *)((p + off) + 0x6AC)), v, 0xFFFF);
        if (v[0] == *((short *)(((char *)d_021BBBCC) + off))) {
            return 0;
        }
        v[0] = v[0] + 4;
        func_0204B404(*((int *)(q + 0x6AC)), v, 0xFFFF);
    }
    return 1;
}
