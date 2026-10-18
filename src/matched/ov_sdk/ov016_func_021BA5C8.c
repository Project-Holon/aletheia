/*
 * function: AsciiToHex
 * address:  0x021BA5C8
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol AsciiToHex (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BA5C8.c \
 *       --func AsciiToHex --addr 0x021BA5C8 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
int AsciiToHex(unsigned char *byDest, char *szStr, int nLen)
{
    int ch;
    int b;
    int i;

    b = 0;
    for (i = 0; i < nLen; i++) {
        ch = szStr[i];
        switch (ch) {
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            b += ch - '0';
            break;
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f':
            b += ch - 'a' + 10;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F':
            b += ch - 'A' + 10;
            break;
        default:
            return 0;
        }
        if (i % 2 == 0) {
            b <<= 4;
        } else {
            byDest[i / 2] = b;
            b = 0;
        }
    }
    return 1;
}
