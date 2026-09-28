/*
 * function: PutHex
 * address:  0x021BC5D4
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol PutHex (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BC5D4.c \
 *       --func PutHex --addr 0x021BC5D4 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
int PutHex(char *lpwrite, char ch)
{
    char *lpw;
    int i;
    int val;

    lpw = lpwrite;
    val = ((unsigned char)ch & 0xF0) >> 4;
    for (i = 0; i < 2; i++) {
        if (val <= 9)
            val += '0';
        else
            val += 'A' - 10;
        *lpw++ = val;
        val = (unsigned char)ch & 0x0F;
    }
    *lpw = 0;
    return lpw - lpwrite;
}
