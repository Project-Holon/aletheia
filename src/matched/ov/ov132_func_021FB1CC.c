/*
 * function: func_021FB1CC
 * address:  0x021FB1CC
 * packet:   pkt_021FB1CC
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F9D80  0x021F9D80  thumb
 *   func_021F9AD8  0x021F9AD8  thumb
 *
 * Addresses are Black-image addresses.
 */

extern void func_021F9D80(char *p);
extern void func_021F9AD8(void *, int, int);

int func_021FB1CC(int a, char **pp)
{
    char *p = *pp;

    func_021F9D80(*(void **)(p + 0x34));
    func_021F9AD8(*(void **)(p + 0x34), 0, 0);
    return 0;
}
