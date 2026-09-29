/*
 * function: func_02184180
 * address:  0x02184180
 * packet:   pkt_ov022_02184180
 * region:   ov022
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf; callers in ov023 (func_02186170, func_02185EA0).
 */

char *func_02184180(unsigned char *p, int i)
{
    int m;

    m = 1 << i;
    if (!(p[0xe] & m) || !(p[1] & m))
        return 0;
    return (char *)p + 0x2c + i * 0x28;
}
