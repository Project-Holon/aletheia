/*
 * function: func_021FC5A0
 * address:  0x021FC5A0
 * packet:   pkt_021FC5A0
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_021F9664  0x021F9664  thumb
 *
 * Addresses are Black-image addresses.
 */

extern int func_0201134C(int);
extern void func_021F9664(char *p, int a);

int func_021FC5A0(int a, char **pp)
{
    char *p = *pp;
    int x = func_0201134C(*(int *)(pp + 1));

    func_021F9664(*(void **)(p + 0x34), (unsigned short)x);
    return 0;
}
