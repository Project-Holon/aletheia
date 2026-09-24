/*
 * function: func_021EC08C
 * address:  0x021EC08C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Stage two shorts on the stack and hand the 0x9E74 array slot to the
 *   SDK call.  Two spellings (array and struct) both give the image's
 *   store order, because the index term is computed between the stores.
 */

extern void func_0204B404(int, void *, int);
extern void func_0204B404(int, void *, int);
void func_021EC08C(char *p, int i, unsigned short a, unsigned short b, unsigned short c)
{
    unsigned short t[2];
    t[0] = a;
    t[1] = b;
    func_0204B404(*(int *)(p + i * 4 + 0x9E74), t, c);
}

