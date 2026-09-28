/*
 * function: MD5_memcpy
 * address:  0x021BC52C
 * packet:   pkt_ov016_021BBC8C
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol MD5_memcpy (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BC52C.c \
 *       --func MD5_memcpy --addr 0x021BC52C --region ov016 --cc ../2.0/sp1p2 --thumb
 */
void MD5_memcpy(unsigned char *output, unsigned char *input, unsigned int len)
{
    unsigned int i;

    for (i = 0; i < len; i++)
        output[i] = input[i];
}
