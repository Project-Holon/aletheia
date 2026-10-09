/*
 * file:     unit_0217FC70.c
 * function: func_0217FC70
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
 *   func_0217F824  0x0217F824  arm  ov009
 *   g_021A1A02  0x021A1A02  data
 *   g_021A19FF  0x021A19FF  data
 *   g_021A19FC  0x021A19FC  data
 */

typedef struct {
    char *data;
    int len;
    int mode;
} B64StreamData;

typedef unsigned char  u8;
extern void func_0217F824(const char *src, u8 *dst, int n);
extern char g_021A1A02[3];
extern char g_021A19FF[3];
extern char g_021A19FC[3];

int func_0217FC70(B64StreamData *data, char *output)
{
    int i;
    char *encoding;
    char c;

    if (data->len <= 0)
        return 0;

    switch (data->mode) {
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

    func_0217F824(data->data, (u8 *)output, data->len >= 3 ? 3 : data->len);
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
