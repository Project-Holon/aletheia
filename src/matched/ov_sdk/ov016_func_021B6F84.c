/*
 * function: aoss_check_str
 * address:  0x021B6F84
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol aoss_check_str (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B6F84.c \
 *       --func aoss_check_str --addr 0x021B6F84 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

int aoss_check_str(char *ptr, int count)
{
    int i;
    unsigned char str;

    for (i = 0; i < count; i++) {
        str = *ptr++;
        if (str < 0x20 || str > 0x7f)
            return -1;
    }
    return 0;
}
