/*
 * function: func_021FB524
 * address:  0x021FB524
 * packet:   pkt_ov094_021FB524
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: no-op that skips 5 arguments.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 */
extern int func_0201134C(void *);

int func_021FB524(void *a, char *s)
{
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    func_0201134C(a);
    return *(int *)(s + 0x23c);
}
