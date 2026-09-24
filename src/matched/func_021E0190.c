/*
 * function: func_021E0190
 * address:  0x021E0190
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EF5C4  0x021EF5C4  thumb  ov170
 *
 * 1 when the p+0x2c+0x74 object is live.
 */


extern int func_021EF5C4(int);
int func_021E0190(char *p)
{
    if (func_021EF5C4(*(int *)(*(int *)(p + 0x2c) + 0x74)) != 0)
        return 1;
    return 0;
}
