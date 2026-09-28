/*
 * function: Rotate
 * address:  0x021B813C
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   AOSS_Memcpy  0x021B8230  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol Rotate (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B813C.c \
 *       --func Rotate --addr 0x021B813C --region ov016 --cc ../2.0/sp1p2 --thumb
 */

extern void *AOSS_Memcpy(void *dest, void *src, int n);

void Rotate(unsigned char *mac, int maclen, char *wBuff)
{
    int size;

    size = maclen / 2;
    AOSS_Memcpy(wBuff, mac + size, size);
    AOSS_Memcpy(wBuff + size, mac, size);
    AOSS_Memcpy(mac, wBuff, maclen);
}
