/*
 * function: aoss_get_bin
 * address:  0x021B75FC
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol aoss_get_bin (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B75FC.c \
 *       --func aoss_get_bin --addr 0x021B75FC --region ov016 --cc ../2.0/sp1p2 --thumb
 */

unsigned long aoss_get_bin(void *ptr, int num)
{
    unsigned long ret = 0;
    int i;
    unsigned char *p = (unsigned char *)ptr + (num - 1);

    for (i = 0; i < num; i++) {
        ret = (ret << 8) + *p--;
    }
    return ret;
}
