/*
 * function: AOSS_Ntohl
 * address:  0x021B8324
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_Ntohl (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8324.c \
 *       --func AOSS_Ntohl --addr 0x021B8324 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

unsigned long AOSS_Ntohl(unsigned long netlong)
{
    return ((netlong >> 24) & 0xff) | ((netlong >> 8) & 0xff00) |
           ((netlong << 8) & 0xff0000) | ((netlong << 24) & 0xff000000);
}
