/*
 * function: func_021F2AB8
 * address:  0x021F2AB8
 * packet:   pkt_ov029_021F2AB8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, sole blocker of ov021 func_0218A6E8.
 */

int func_021F2AB8(char *p)
{
    if (p == 0)
        return 0;
    if (*(int *)(p + 0x218) == 5)
        return 1;
    return 0;
}
