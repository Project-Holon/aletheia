/*
 * function: func_02160238
 * address:  0x02160238
 * packet:   pkt_ov009_02160238
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      parse_time (libssl.TWL.HYB.a(ssl.o))
 *
 * symbols:
 *   (none)
 */

static unsigned long func_02160238(unsigned char *s, int type)
{
    unsigned long year;

    year = s[0] * 10 + s[1] - 528;
    s += 2;
    if (type == 0x17) {
        if (year < 50)
            year += 2000;
        else
            year += 1900;
    } else {
        year = year * 100 + (s[0] * 10 + s[1] - 528);
        s += 2;
    }
    return (year << 16) + ((s[0] * 10 + s[1] - 528) << 8) + (s[2] * 10 + s[3] - 528);
}
