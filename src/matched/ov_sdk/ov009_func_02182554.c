/*
 * function: gsiXmlUtilParseString
 * address:  0x02182554
 * packet:   pkt_ov009_02182554
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiXmlUtilParseString (libdwcgscommon.TWL.HYB.a(gsxml.o))
 *
 * symbols:
 *   gsiXmlUtilSkipWhiteSpace  0x02181E28 arm ov009
 *   gsiXmlUtilDecodeString    0x0218263C arm ov009
 *
 * Parses one quoted string literal out of an XML buffer: consumes the opening
 * quote, scans to the matching one, and decodes the body in place.
 *
 * Two spelling details carry the whole 232 bytes:
 *
 *  1. The scan loop is a `while` with the SAME test written as an explicit `if`
 *     in front of it.  mwcc rotates the while into a bottom-edge loop and keeps
 *     the `if` as well, which is why the image tests `buffer[*pos] != startCh`
 *     twice (`bne` into the loop at +0068 and a same-flags `beq` out of it at
 *     +0084).  Without the `if` the function is 8 bytes short.
 *  2. `strStart` is taken BEFORE `strOut->length = 0`, so the register that the
 *     `(*pos)++` already produced stays live for the `add r4, r8, r2` and the
 *     two length/quote tests re-read `*pos` into a fresh register (`ldr r3,
 *     [r6]` / `ldr r3, [r6]` in the loop).  With the store first the compiler
 *     reloads into the same register and both tests read through the computed
 *     strStart pointer instead, which is 7 register-field bytes out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02182554.c \
 *       --func gsiXmlUtilParseString --addr 0x02182554 --region ov009 --arm --lang c99 --cc 1.1p1 --diff
 */

struct GSIXmlString
{
    char * string;  /* 0x00 */
    int length;     /* 0x04 */
};

extern int gsiXmlUtilSkipWhiteSpace(void *stream, char *buffer, int len, int *pos);
extern int gsiXmlUtilDecodeString(char *buffer, int *len);

int gsiXmlUtilParseString(void *stream, char *buffer, int len, int *pos, struct GSIXmlString *strOut)
{
    char *strStart;
    char startCh;

    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    startCh = buffer[*pos];
    if (startCh != '"' && startCh != '\'')
        return 0;
    (*pos)++;
    strStart = &buffer[*pos];
    strOut->length = 0;
    if (*pos >= len)
        return 0;
    if (buffer[*pos] == startCh)
    {
        strOut->string = strStart;
        (*pos)++;
        return 1;
    }
    if (buffer[*pos] != startCh)
    {
        while (buffer[*pos] != startCh)
        {
            if (*pos >= len)
                return 0;
            (*pos)++;
            strOut->length++;
        }
    }
    (*pos)++;
    if (!gsiXmlUtilDecodeString(strStart, &strOut->length))
        return 0;
    strOut->string = strStart;
    return 1;
}
