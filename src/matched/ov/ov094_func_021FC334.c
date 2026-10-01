/*
 * function: func_021FC334
 * address:  0x021FC334
 * packet:   pkt_ov094_021FC334
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: jumps the reader by a relative offset.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_020113B0 0x020113B0 thumb
 */
extern int func_0201134C(void *);
extern void func_020113B0(void *, int);

int func_021FC334(char *a, char *s)
{
    int off = func_0201134C(a);
    func_020113B0(a, *(int *)(a + 0x14) + off);
    return *(int *)(s + 0x23c);
}
