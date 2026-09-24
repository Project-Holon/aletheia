/*
 * function: func_021C31CC
 * address:  0x021C31CC
 * packet:   pkt_021C31CC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)

 * Hands the element at +0x5C a 0x80 pair and a 0x1000 pair and marks +0x60.
 */


extern void func_0204B404(int, unsigned short *, int);
extern void func_0204B5AC(int, unsigned int *);

void func_021C31CC(int unused, char *q)
{
    struct {
        unsigned int w[2];
        unsigned short h[2];
    } buf;

    buf.h[0] = 0x80;
    buf.h[1] = 0x80;
    buf.w[0] = 0x1000;
    buf.w[1] = 0x1000;
    func_0204B404(*(int *)(q + *(int *)(q + 0x5c) * 4 + 0x54), buf.h, 1);
    func_0204B5AC(*(int *)(q + *(int *)(q + 0x5c) * 4 + 0x54), buf.w);
    *(int *)(q + 0x60) = 1;
}

