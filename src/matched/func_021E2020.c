/*
 * function: func_021E2020
 * address:  0x021E2020
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Query the current mode; when it is 1 return the 0xA188 word of
 *   the p+0x2c object, else 2.
 */


extern int func_020221A4(char *);
int func_021E2020(char *p)
{
    if (func_020221A4(p) == 1)
        return *(int *)(*(int *)(p + 0x2c) + 0xA188);
    return 2;
}
