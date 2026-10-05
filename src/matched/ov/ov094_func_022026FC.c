/*
 * function: func_022026FC
 * address:  0x022026FC
 * packet:   pkt_ov094_022026FC
 * region:   ov094
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * notes:    tests a 2-bit field at bits 15..16 of the word at +0x68, returns 1 if nonzero. Witness for calls in ov098 func_021B6578 (2026-10-05, lane W-B).
 */

struct W { unsigned char pad[0x68]; unsigned int pad15 : 15; unsigned int f : 2; };

int func_022026FC(struct W *p)
{
    if (p->f) return 1;
    return 0;
}
