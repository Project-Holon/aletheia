/*
 * function: func_021D5D68
 * address:  0x021D5D68
 * packet:   pkt_ov093_021D5D68
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef signed char s8;
int func_021D5D68(s8 *p)
{
    if (p[0xfc] < 6) return 1;
    if (p[0xfd] < 6) return 1;
    if (p[0xfe] < 6) return 1;
    if (p[0xff] < 6) return 1;
    if (p[0x100] < 6) return 1;
    if (p[0x101] < 6) return 1;
    if (p[0x102] < 6) return 1;
    return 0;
}
