/*
 * function: MD5_memset
 * address:  0x021BC544
 * packet:   pkt_ov016_021BBC8C
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MD5_memset   0x021BC544  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), static MD5_memset (RFC 1321
 * reference MD5; name and prototype from the vendor object's DWARF).
 * atermset.o's .comment stamp is "Metrowerks C/C++ for ARM 3.0.0.126", the
 * ../2.0/sp1p2 front end. Under dsi/1.1p1 the same source compiles to 20
 * bytes (indexed strb [r0, r3] instead of the pointer walk); sp1p2 gives
 * the image's 22. EXACT* only for the two bytes of alignment padding.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BC544.c \
 *       --func MD5_memset --addr 0x021BC544 --region ov016 --cc dsi/../2.0/sp1p2 --thumb
 */

void MD5_memset(unsigned char *output, int value, unsigned int len)
{
    unsigned int i;

    for (i = 0; i < len; i++)
        ((char *)output)[i] = (char)value;
}
