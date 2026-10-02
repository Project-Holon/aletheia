/*
 * function: func_021F535C
 * address:  0x021F535C
 * packet:   pkt_021F535C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F624C  0x021F624C  thumb  ov112
 */

void func_021F624C(char *p, int *q);

void func_021F535C(int *p, int *q)
{
    func_021F624C(*(char **)((char *)p + 8), q);
}
