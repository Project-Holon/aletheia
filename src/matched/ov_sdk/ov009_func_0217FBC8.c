/*
 * function: B64DecodeLen
 * address:  0x0217FBC8
 * packet:   pkt_ov009_0217FBC8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      B64DecodeLen (gsplatformutil.o)
 *
 * symbols:
 *   gGsB64CharsAlt                     0x021A1A02  data
 *   gGsB64CharsUrl                     0x021A19FF  data
 *   gGsB64CharsDefault                     0x021A19FC  data
 */

extern char gGsB64CharsAlt[3];
extern char gGsB64CharsUrl[3];
extern char gGsB64CharsDefault[3];

int B64DecodeLen(char *input, int encodingType)
{
    char *encoding;
    char *holdin = input;
    int len;

    switch (encodingType) {
    case 1:
        encoding = gGsB64CharsAlt;
        break;
    case 2:
        encoding = gGsB64CharsUrl;
        break;
    default:
        encoding = gGsB64CharsDefault;
        break;
    }
    while (*input != 0) {
        if (*input == encoding[2]) {
            len = input - holdin;
            return (len / 4) * 3 + (len - 1) % 4;
        }
        input++;
    }
    len = input - holdin;
    return (len / 4) * 3;
}
