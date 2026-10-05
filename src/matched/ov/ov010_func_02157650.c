/*
 * function: func_02157650
 * address:  0x02157650
 * packet:   pkt_ov010_02157650
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled leaf after func_02157450's pool: store v into *p only while
 * *p still holds the unset sentinel 0x29, so the first call wins.
 */

void func_02157650(int *p, int v)
{
    if (*p == 0x29)
        *p = v;
}
