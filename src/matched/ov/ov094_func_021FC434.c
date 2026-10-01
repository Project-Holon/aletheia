/*
 * function: func_021FC434
 * address:  0x021FC434
 * packet:   pkt_ov094_021FC434
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: passes one argument to func_021F8934.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F8934 0x021F8934 thumb ov094
 */
extern int func_0201134C(void *);
extern void func_021F8934(int);

int func_021FC434(void *a, char *s)
{
    func_021F8934(func_0201134C(a));
    return *(int *)(s + 0x23c);
}
