/*
 * function: func_021FBD10
 * address:  0x021FBD10
 * packet:   pkt_ov094_021FBD10
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: stores one argument at 0x1e4, waits on func_021FC9D0, and suspends.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_020113D0 0x020113D0 thumb
 *   func_021FC9D0 0x021FC9D0 thumb ov094
 */
extern int func_0201134C(void *);
extern void func_020113D0(char *p, int val);
extern int func_021FC9D0(void *a, char *s);

int func_021FBD10(void *a, char *s)
{
    *(int *)(s + 0x1e4) = func_0201134C(a);
    func_020113D0(a, (int)func_021FC9D0);
    *(int *)(s + 0x23c) = 1;
    return 1;
}
