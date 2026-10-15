/*
 * function: B64Encode
 * address:  0x0217FA90
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * B64Encode: GameSpy base64 encoder.  TripToQuart every 3 input bytes, then
 * walk the output backwards mapping each 6-bit group to its character,
 * padding the tail with encoding[2].  encodingType 1 selects the alternate
 * table, 2 the URL-safe table, otherwise the default.
 *
 * symbols:
 *   TripToQuart  0x0217F824  arm  ov009
 *   gGsB64CharsDefault     0x021A19FC  data
 *   gGsB64CharsUrl     0x021A19FF  data
 *   gGsB64CharsAlt     0x021A1A02  data
 */

#define GSI_MIN(a, b) ((a) < (b) ? (a) : (b))

typedef unsigned char  u8;
extern void TripToQuart(const char *src, u8 *dst, int n);
extern char gGsB64CharsDefault[];
extern char gGsB64CharsUrl[];
extern char gGsB64CharsAlt[];

void B64Encode(const char *input, char *output, int inlen, int encodingType)
{
    const char *encoding;
    char *holdout = output;
    char *lastchar;
    int todo = inlen;

    switch (encodingType) {
    case 1:
        encoding = gGsB64CharsAlt;
        break;
    case 2:
        encoding = gGsB64CharsUrl;
        break;
    default:
        encoding = gGsB64CharsDefault;
    }

    while (todo > 0) {
        TripToQuart(input, (u8 *)output, GSI_MIN(todo, 3));
        output += 4;
        input += 3;
        todo -= 3;
    }
    lastchar = output;
    if (inlen % 3 == 1)
        lastchar -= 2;
    else if (inlen % 3 == 2)
        lastchar -= 1;
    *output = 0;
    while (output > holdout) {
        output--;
        if (output >= lastchar)
            *output = encoding[2];
        else if (*output <= 25)
            *output = (char)(*output + 65);
        else if (*output <= 51)
            *output = (char)(*output + 71);
        else if (*output <= 61)
            *output = (char)(*output + 48 - 52);
        else if (*output == 62)
            *output = encoding[0];
        else if (*output == 63)
            *output = encoding[1];
    }
}
