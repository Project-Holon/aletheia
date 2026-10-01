/*
 * function: func_021F70F0
 * address:  0x021F70F0
 * packet:   pkt_ov094_021F70F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resets the handle at word 1, then sets its value from the third argument.
 *
 * symbols:
 *   func_02048AE8 0x02048AE8 arm
 *   func_02048B30 0x02048B30 arm
 */
extern void func_02048AE8(void *);
extern void func_02048B30(void *, int);

void func_021F70F0(void **p, int b, int c)
{
    func_02048AE8(p[1]);
    func_02048B30(p[1], c);
}
