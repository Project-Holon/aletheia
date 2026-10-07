/*
 * file:     unit_0217F2C8_p02.c
 * unit:     yes
 * function: func_0217F7AC, func_0217F7D0, func_0217F824, func_0217F8B4, func_0217FA90, func_0217FBC8
 * address:  0x0217F7AC
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217F774  0x0217F774  arm  ov009
 *   _u32_div_f     0x0209C2B0  arm
 *   func_020923B0  0x020923B0  arm
 *   g_021A19FC     0x021A19FC  data
 *   g_021A19FF     0x021A19FF  data
 *   g_021A1A02     0x021A1A02  data
 */
#define GSI_MIN(a, b) ((a) < (b) ? (a) : (b))
typedef unsigned char u8;

typedef unsigned int   u32;

extern int func_0217F774(void);
extern void *func_020923B0(void *p, int c, u32 n);
unsigned int func_0217F7AC(unsigned int min, unsigned int max);
void func_0217F7D0(char *quart, char *trip, int inlen);
void func_0217F824(const char *src, u8 *dst, int n);
void func_0217F8B4(const char *input, char *output, int inlen, int *outlen, int encodingType);
void func_0217FA90(const char *input, char *output, int inlen, int encodingType);
int func_0217FBC8(char *input, int encodingType);
extern char g_021A19FC[];
extern char g_021A19FF[];
extern char g_021A1A02[];


/*
 * Util_RandInt: longrand() modulo (max-min), offset by min.  max==min returns
 * min without touching the RNG.
 *
 * The `% range` result is bound to a local before adding min: that is what
 * makes the compiler keep min in a callee-saved register and emit the direct
 * `add r0, r1, r5` return instead of a branch plus `mov r0, r5` (and it drops
 * the four-byte conditional-pop epilogue).  The modulo is unsigned (u32),
 * so it calls the runtime division entry at 0x0209C2B0.
 */
unsigned int func_0217F7AC(unsigned int min, unsigned int max)
{
    unsigned int range = max - min;
    unsigned int r;

    if (range == 0)
        return min;
    r = func_0217F774() % range;
    return r + min;
}

/*
 * QuartToTrip: pack up to four signed bytes into three (6-6-6-6 base64
 * bit groups folded into 6-6-2+6 layout).  `char` is signed under the pinned
 * flags, so the loads are ldrsb and the shifts arithmetic.
 */
void func_0217F7D0(char *quart, char *trip, int inlen)
{
    if (inlen >= 2)
        trip[0] = (char)(quart[0] << 2 | quart[1] >> 4);
    if (inlen >= 3)
        trip[1] = (char)((quart[1] & 0x0F) << 4 | quart[2] >> 2);
    if (inlen >= 4)
        trip[2] = (char)((quart[2] & 0x3) << 6 | quart[3]);
}


/*
 * Pack up to three input bytes into four 6-bit values (the base64 index
 * order).  The source bytes go through a local three-byte buffer, padded
 * with zeros before the shift network runs.
 */
void func_0217F824(const char *src, u8 *dst, int n)
{
    unsigned char buf[4];
    int i;

    for (i = 0; i < n; i++)
        buf[i] = src[i];
    for (; i < 3; i++)
        buf[i] = 0;
    dst[0] = buf[0] >> 2;
    dst[1] = ((buf[0] & 3) << 4) | (buf[1] >> 4);
    dst[2] = ((buf[1] & 0xf) << 2) | (buf[2] >> 6);
    dst[3] = buf[2] & 0x3f;
}


/*
 * B64Decode: GameSpy base64 decoder.  Decode characters into 4-byte groups,
 * run QuartToTrip over each full group, pad and convert the tail, and publish
 * the output length.  encodingType 1 selects the alternate table, 2 the
 * URL-safe table, otherwise the default.
 */
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


/*
 * B64Encode: GameSpy base64 encoder.  TripToQuart every 3 input bytes, then
 * walk the output backwards mapping each 6-bit group to its character,
 * padding the tail with encoding[2].  encodingType 1 selects the alternate
 * table, 2 the URL-safe table, otherwise the default.
 */
void func_0217FA90(const char *input, char *output, int inlen, int encodingType)
{
    const char *encoding;
    char *holdout = output;
    char *lastchar;
    int todo = inlen;

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

    while (todo > 0) {
        func_0217F824(input, (u8 *)output, GSI_MIN(todo, 3));
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


/*
 * sdk:      B64DecodeLen (gsplatformutil.o)
 */
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
