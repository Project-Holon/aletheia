/*
 * function: AOSS_Memcmp
 * address:  0x021B8210
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_Memcmp (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8210.c \
 *       --func AOSS_Memcmp --addr 0x021B8210 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

int AOSS_Memcmp(void *s1, void *s2, int n)
{
    unsigned char *c1 = s1;
    unsigned char *c2 = s2;
    int diff = 0;

    while (n-- > 0 && (diff = *c1 - *c2) == 0) {
        c1++;
        c2++;
    }
    return diff;
}
