/*
 * function: func_021FC61C
 * address:  0x021FC61C
 * packet:   pkt_021FC61C
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021F96B0  0x021F96B0  thumb
 *
 * Addresses are Black-image addresses.
 */

extern int func_0201134C(int);
extern void func_021F96B0(char *p, int a);

int func_021FC61C(int a, char **pp)
{
    char *p = *pp;
    int x = func_0201134C(*(int *)(pp + 1));

    func_021F96B0(*(void **)(p + 0x34), x);
    return 0;
}
