/*
 * function: func_0217F8B4
 * address:  0x0217F8B4
 * packet:   pkt_0219091C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * B64Decode: GameSpy base64 decoder.  Decode characters into 4-byte groups,
 * run QuartToTrip over each full group, pad and convert the tail, and publish
 * the output length.  encodingType 1 selects the alternate table, 2 the
 * URL-safe table, otherwise the default.
 *
 * symbols:
 *   func_0217F7D0  0x0217F7D0  arm  ov009
 *   func_020923B0  0x020923B0  arm
 *   g_021A19FC     0x021A19FC  data
 *   g_021A19FF     0x021A19FF  data
 *   g_021A1A02     0x021A1A02  data
 */

extern void func_0217F7D0(char *quart, char *trip, int inlen);
typedef unsigned int   u32;
extern void *func_020923B0(void *p, int c, u32 n);
extern char g_021A19FC[];
extern char g_021A19FF[];
extern char g_021A1A02[];

void func_0217F8B4(const char *input, char *output, int inlen, int *outlen, int encodingType)
{
    const char *encoding;
    int readpos = 0;
    int writepos = 0;
    char block[4];

    switch (encodingType) {
    case 1:
        encoding = g_021A1A02;
        break;
    case 2:
        encoding = g_021A19FF;
        break;
    default:
        encoding = g_021A19FC;
    }

    if (inlen <= 0) {
        if (outlen)
            *outlen = 0;
        output[0] = 0;
        return;
    }

    while (readpos < inlen && input[readpos] != encoding[2]) {
        if (input[readpos] >= '0' && input[readpos] <= '9')
            block[readpos % 4] = (char)(input[readpos] - 48 + 52);
        else if (input[readpos] >= 'a' && input[readpos] <= 'z')
            block[readpos % 4] = (char)(input[readpos] - 71);
        else if (input[readpos] >= 'A' && input[readpos] <= 'Z')
            block[readpos % 4] = (char)(input[readpos] - 65);
        else if (input[readpos] == encoding[0])
            block[readpos % 4] = 62;
        else if (input[readpos] == encoding[1])
            block[readpos % 4] = 63;
        else if (input[readpos] == encoding[2])
            break;
        else if (input[readpos] == '\0')
            break;
        else {
            if (outlen)
                *outlen = 0;
            output[0] = 0;
            return;
        }

        if (readpos % 4 == 3) {
            func_0217F7D0(block, &output[writepos], 4);
            writepos += 3;
        }
        readpos++;
    }

    if (readpos != 0 && readpos % 4 != 0) {
        func_020923B0(&block[readpos % 4], encoding[2], 4 - readpos % 4);
        func_0217F7D0(block, &output[writepos], readpos % 4);
        if (readpos % 4 == 3)
            writepos += 2;
        else
            writepos += 1;
    }

    if (outlen)
        *outlen = writepos;
}
