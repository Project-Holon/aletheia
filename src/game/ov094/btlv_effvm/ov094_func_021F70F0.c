/*
 * function: func_021F70F0
 * address:  0x021F70F0
 * packet:   pkt_ov094_021F70F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Copies the light at word 1's vectors at +0x20 and +0x38 out to b and c.
 *
 * symbols:
 *   func_02048AE8 0x02048AE8 arm
 *   func_02048B30 0x02048B30 arm
 */
extern void func_02048AE8(void *, void *);
extern void func_02048B30(void *, int);

void func_021F70F0(void **p, void *b, int c)
{
    func_02048AE8(p[1], b);
    func_02048B30(p[1], c);
}
