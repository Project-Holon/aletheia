/*
 * function: func_021C31CC
 * address:  0x021C31CC
 * packet:   pkt_021C31CC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   (none)
 *
 * Hands the element at +0x5C a 0x80 pair and a 0x1000 pair and marks +0x60.
 *
 * BLOCKED.  MATCH*: all 58 concrete bytes equal (the 60-byte listing extent is
 * 58 plus two padding bytes), including the two `movs` that the original keeps
 * in r4 for the +0x60 store.  The only miss is the wildcarded call at +0x30,
 * which targets 0204B5AC: an ARM routine the ARM9 listing prints as a pool word
 * after a `bx lr` (0xE5912000 at that address), so no func_ label, no pool word
 * holding the address, no runtime/sdk table entry and no layout object.  Same
 * class as func_021BDCDC's 0204047C; the source is not the problem.
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
