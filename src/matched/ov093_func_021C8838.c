/*
 * function: func_021C8838
 * address:  0x021C8838
 * packet:   pkt_ov093_021C8838
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Named by the parked ov093 files (func_021DF0C4 / func_021DFABC /
 * func_021E7388).  Low byte of the +2 halfword <- (u8)a; +0 halfword <- b;
 * then bits 8..14 of the +2 halfword are cleared.  `(u8)(u16)a` and the
 * `(int)` cast before `~0x7F00` are both load-bearing: the first gives the
 * double narrowing, the second keeps the mask sign-extended (0xFFFF80FF) so
 * the pooled word matches.
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_021C8838(void *p, int a, int b)
{
    u16 *h = (u16 *)((u8 *)p + 2);
    u8 av = (u8)(u16)a;

    *h = (*h & ~0xff) | av;
    *(u16 *)p = (u16)b;
    *h = (u16)((int)*h & ~0x7F00);
}
