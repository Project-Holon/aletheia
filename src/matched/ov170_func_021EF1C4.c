/*
 * function: func_021EF1C4
 * address:  0x021EF1C4
 * packet:   pkt_ov170_021EF1C4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02035BA4 0x02035BA4 arm
 *   d_021F0040 0x021F0040 data
 */

extern int func_02035BA4(const void *p);
extern const unsigned char d_021F0040[];

int func_021EF1C4(void)
{
    return func_02035BA4(d_021F0040);
}
