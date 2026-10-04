/*
 * function: func_0216CAD4
 * address:  0x0216CAD4
 * packet:   pkt_0216CAD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * unblocked: func_021CBD84 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021CBD84; the `ov021` token then resolves the site as
 *   `matched, overlay`.
 *
 * The record's far field (0x7CC) and the arm9 probe result are the last
 * two arguments of the four-argument overlay call.
 *
 * symbols:
 *   func_021CBD84   0x021CBD84  thumb  ov021
 *   func_0216CAA8   0x0216CAA8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_021CBD84(void *a);
extern void *func_0216CAA8(void *a, void *b, void *c, void *d);

void func_0216CAD4(void *a0, void *a1, void *a2)
{
    int v = (int)func_021CBD84(a0);

    func_0216CAA8(a1, a2, (void *)(*(int *)((char *)a0 + 0x7CC)), (void *)v);
}

