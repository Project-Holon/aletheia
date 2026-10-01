/*
 * function: func_021FB624
 * address:  0x021FB624
 * packet:   pkt_ov094_021FB624
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: passes two arguments to func_021F839C.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F839C 0x021F839C thumb ov094
 */
extern int func_0201134C(void *);
extern void func_021F839C(int, int);

int func_021FB624(void *a, char *s)
{
    int x = func_0201134C(a);
    func_021F839C(x, func_0201134C(a));
    return *(int *)(s + 0x23c);
}
