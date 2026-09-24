/*
 * function: func_0216CAD4
 * address:  0x0216CAD4
 * packet:   pkt_0216CAD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocked:   wild=4
 *
 * The record's far field (0x7CC) and the arm9 probe result are the last
 * two arguments of the four-argument overlay call.
 *
 * symbols:
 *   func_021CBD84   0x021CBD84  thumb
 *   func_0216CAA8   0x0216CAA8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021CBD84(void *);
extern void func_0216CAA8(void *, void *, int, int);

void func_0216CAD4(void *a0, void *a1, void *a2)
{
    int v = func_021CBD84(a0);

    func_0216CAA8(a1, a2, *(int *)((char *)a0 + 0x7CC), v);
}

