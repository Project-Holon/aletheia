/*
 * function: B64Decode
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
 *   QuartToTrip  0x0217F7D0  arm  ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 *   gGsB64CharsDefault     0x021A19FC  data
 *   gGsB64CharsUrl     0x021A19FF  data
 *   gGsB64CharsAlt     0x021A1A02  data
 */

extern void QuartToTrip(char *quart, char *trip, int inlen);
typedef unsigned int   u32;
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);
extern char gGsB64CharsDefault[];
extern char gGsB64CharsUrl[];
extern char gGsB64CharsAlt[];

void B64Decode(const char *input, char *output, int inlen, int *outlen, int encodingType)
{
    const char *encoding;
    int readpos = 0;
    int writepos = 0;
    char block[4];

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
            QuartToTrip(block, &output[writepos], 4);
            writepos += 3;
        }
        readpos++;
    }

    if (readpos != 0 && readpos % 4 != 0) {
        MSL_C_LIB_MemsetPtr(&block[readpos % 4], encoding[2], 4 - readpos % 4);
        QuartToTrip(block, &output[writepos], readpos % 4);
        if (readpos % 4 == 3)
            writepos += 2;
        else
            writepos += 1;
    }

    if (outlen)
        *outlen = writepos;
}
