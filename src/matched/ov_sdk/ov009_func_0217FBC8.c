/*
 * function: func_0217FBC8
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
 *   g_021A1A02                     0x021A1A02  data
 *   g_021A19FF                     0x021A19FF  data
 *   g_021A19FC                     0x021A19FC  data
 */

extern char g_021A1A02[3];
extern char g_021A19FF[3];
extern char g_021A19FC[3];

int func_0217FBC8(char *input, int encodingType)
{
    char *encoding;
    char *holdin = input;
    int len;

    switch (encodingType) {
    case 1:
        encoding = g_021A1A02;
        break;
    case 2:
        encoding = g_021A19FF;
        break;
    default:
        encoding = g_021A19FC;
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
