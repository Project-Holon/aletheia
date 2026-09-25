/*
 * function: func_021FC5BC
 * address:  0x021FC5BC
 * packet:   pkt_021FC5BC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021F9680  0x021F9680  thumb
 *
 * Addresses are Black-image addresses.
 */

extern int func_0201134C(int);
extern void func_021F9680(void *, int);

int func_021FC5BC(int a, char **pp)
{
    char *p = *pp;
    int x = func_0201134C(*(int *)(pp + 1));

    func_021F9680(*(void **)(p + 0x34), (unsigned short)x);
    return 0;
}
