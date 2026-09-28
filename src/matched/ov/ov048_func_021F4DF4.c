/*
 * function: func_021F4DF4
 * address:  0x021F4DF4
 * packet:   pkt_ov048_021F4DF4
 * region:   ov048
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sentinel-0x1ab test on four consecutive words; then a value match.
 */

int func_021F4DF4(int *p, int v)
{
    if (p[5] == 0x1ab && p[6] == 0x1ab && p[7] == 0x1ab && p[8] == 0x1ab)
        return 1;
    if (p[5] == v || p[6] == v || p[7] == v || p[8] == v)
        return 1;
    return 0;
}
