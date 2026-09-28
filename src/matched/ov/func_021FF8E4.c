/*
 * function: func_021FF8E4
 * address:  0x021FF8E4
 * packet:   pkt_021FF8E4
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 0x021FF8E0 is an unlabelled two-byte `bx lr` leaf reached through the pool
 * word 0x021FF8E1 (thumb bit set); now matched as src/matched/func_021FF8E0.c.
 *
 * symbols:
 *   func_021D730C  0x021D730C  thumb  ov125
 *   func_021FFB68  0x021FFB68  thumb  ov186
 *   func_021FF8E0  0x021FF8E0  thumb  ov186
 */

extern int  func_021D730C(int);
extern void func_021FFB68(void *, void *);
extern void func_021FF8E0(void);

void func_021FF8E4(void *p, int a1, int a2)
{
    if (func_021D730C(a2) != 0)
        func_021FFB68(p, (void *)func_021FF8E0);
}
