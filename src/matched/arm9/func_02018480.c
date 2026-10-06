/*
 * function: func_02018480
 * address:  0x02018480
 * packet:   pkt_02018480
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Eight byte thunk (pool word and bx) that forwards both arguments to
 * func_02018488. Witness for the ov093 caller func_021BCFAC.
 *
 * symbols:
 *   func_02018480  0x02018480  thumb
 *   func_02018488  0x02018488  thumb
 */

typedef unsigned int   u32;
extern u32 func_02018488(void *p, void *mail);

int func_02018480(void *p, int q)
{
    return func_02018488(p, (void *)q);
}
