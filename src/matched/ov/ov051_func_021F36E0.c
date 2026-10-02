/*
 * unit:     yes
 * function: func_021F36E0, func_021F36EC
 * address:  0x021F36E0
 * packet:   pkt_ov051_021F36E0
 * region:   ov051
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two accessors over the result of func_021F36C0.
 *
 * symbols:
 *   func_021F36C0  0x021F36C0  thumb  ov051
 */

int func_021F36E0(int a)
{
    void *func_021F36C0(int a);
    return *(int *)((char *)func_021F36C0(a) + 8);
}

int func_021F36EC(int a)
{
    void *func_021F36C0(int a);
    return *(int *)((char *)func_021F36C0(a) + 4);
}
