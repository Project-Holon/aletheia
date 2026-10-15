/*
 * function: B64EncodeStream
 * address:  0x0217FC70
 * packet:   pkt_ov009_0217FC70
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      B64EncodeStream (libdwcgscommon.TWL.HYB.a(gsplatformutil.o))
 *
 * symbols:
 *   TripToQuart  0x0217F824  arm  ov009
 *   gGsB64CharsAlt  0x021A1A02  data
 *   gGsB64CharsUrl  0x021A19FF  data
 *   gGsB64CharsDefault  0x021A19FC  data
 */

typedef struct {
    char *data;
    int len;
    int mode;
} B64StreamData;

typedef unsigned char  u8;
extern void TripToQuart(const char *src, u8 *dst, int n);
extern char gGsB64CharsAlt[3];
extern char gGsB64CharsUrl[3];
extern char gGsB64CharsDefault[3];

int B64EncodeStream(B64StreamData *data, char *output)
{
    int i;
    char *encoding;
    char c;

    if (data->len <= 0)
        return 0;

    switch (data->mode) {
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

    TripToQuart(data->data, (u8 *)output, data->len >= 3 ? 3 : data->len);
    data->data += 3;
    data->len -= 3;

    for (i = 0; i < 4; i++) {
        c = output[i];
        if (c <= 25)
            output[i] = c + 'A';
        else if (c <= 51)
            output[i] = c + 'G';
        else if (c <= 61)
            output[i] = c - 4;
        else if (c == 62)
            output[i] = encoding[0];
        else if (c == 63)
            output[i] = encoding[1];
    }
    if (data->len < 0) {
        output[3] = encoding[2];
        if (data->len == -2)
            output[2] = encoding[2];
    }
    return 1;
}
