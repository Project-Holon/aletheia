/*
 * function: AddKey
 * address:  0x021B8118
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AddKey (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8118.c \
 *       --func AddKey --addr 0x021B8118 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

void AddKey(char *Key, unsigned char *mac, int maclen)
{
    int i, size;

    size = maclen / 2;
    for (i = 0; i < size; i++) {
        mac[size + i] ^= Key[i];
    }
}
