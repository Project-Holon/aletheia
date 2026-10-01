/*
 * function: func_021FBE28
 * address:  0x021FBE28
 * packet:   pkt_ov094_021FBE28
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: relative jump when func_021F7F1C(x) equals y.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F7F1C 0x021F7F1C thumb ov094
 *   func_020113B0 0x020113B0 thumb
 */
extern int func_0201134C(void *);
extern int func_021F7F1C(int);
extern void func_020113B0(void *, int);

int func_021FBE28(char *a, char *s)
{
    int x = func_0201134C(a);
    int y = func_0201134C(a);
    int off = func_0201134C(a);

    if (y == func_021F7F1C(x))
        func_020113B0(a, *(int *)(a + 0x14) + off);
    return *(int *)(s + 0x23c);
}
