/*
 * function: Encode
 * address:  0x021BC4D4
 * packet:   pkt_ov016_021BBC8C
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol Encode (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BC4D4.c \
 *       --func Encode --addr 0x021BC4D4 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef unsigned long UINT4;

void Encode(unsigned char *output, UINT4 *input, unsigned int len)
{
    unsigned int i, j;

    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[j] = (unsigned char)(input[i] & 0xff);
        output[j + 1] = (unsigned char)((input[i] >> 8) & 0xff);
        output[j + 2] = (unsigned char)((input[i] >> 16) & 0xff);
        output[j + 3] = (unsigned char)((input[i] >> 24) & 0xff);
    }
}
