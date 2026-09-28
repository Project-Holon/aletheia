/*
 * function: func_021EF248
 * address:  0x021EF248
 * packet:   pkt_ov170_021EF248
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02035BA4 0x02035BA4 arm
 *   d_021F002C 0x021F002C data a4
 */

extern int func_02035BA4(const void *p);
extern const unsigned char d_021F002C[];

int func_021EF248(void)
{
    if (func_02035BA4(d_021F002C) != -1)
        return 1;
    return 0;
}
