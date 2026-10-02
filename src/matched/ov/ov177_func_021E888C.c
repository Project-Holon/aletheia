/*
 * function: func_021E888C
 * address:  0x021E888C
 * packet:   pkt_ov177_021E888C
 * region:   ov177
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E88B0  0x021E88B0  thumb  ov177
 */

typedef struct {
    char           pad0[0x1c];
    unsigned int f1c;
} S;

extern void func_021E88B0(S *, int, unsigned char, int, int, int);

void func_021E888C(S *p, int a)
{
    int v = (p->f1c & 0x7f) << 1;

    func_021E88B0(p, 0x13, 0x11 - v, 0xc, v, a);
}
