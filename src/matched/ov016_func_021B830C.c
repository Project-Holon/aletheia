/*
 * function: AOSS_Htons
 * address:  0x021B830C
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_Htons (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B830C.c \
 *       --func AOSS_Htons --addr 0x021B830C --region ov016 --cc ../2.0/sp1p2 --thumb
 */

unsigned short AOSS_Htons(unsigned short hostshort)
{
    return ((hostshort >> 8) & 0xff) | ((hostshort << 8) & 0xff00);
}
