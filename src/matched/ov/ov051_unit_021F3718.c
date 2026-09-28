/*
 * unit:     yes
 * function: func_021F3718, func_021F3724
 * address:  0x021F3718
 * packet:   pkt_ov051_021F3718
 * region:   ov051
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two accessors over the result of func_021F36F8.
 *
 * symbols:
 *   func_021F36F8  0x021F36F8  thumb  ov051
 */

int func_021F3718(void)
{
    void *func_021F36F8(void);
    return *(int *)((char *)func_021F36F8() + 8);
}

int func_021F3724(void)
{
    void *func_021F36F8(void);
    return *(int *)((char *)func_021F36F8() + 4);
}
