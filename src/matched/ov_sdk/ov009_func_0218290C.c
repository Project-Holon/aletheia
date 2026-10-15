/*
 * function: gsiXmlUtilParseValue
 * address:  0x0218290C
 * packet:   pkt_ov009_0218290C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiXmlUtilParseValue (gsxml)
 *
 * symbols:
 *   gsiXmlUtilSkipWhiteSpace  0x02181E28 arm ov009
 *   gsiXmlUtilDecodeString    0x0218263C arm ov009
 */

struct GSIXmlString
{
    char * string;  /* 0x00 */
    int length;     /* 0x04 */
};

extern int gsiXmlUtilSkipWhiteSpace(void *stream, char *buffer, int len, int *pos);
extern int gsiXmlUtilDecodeString(char *buffer, int *len);

int gsiXmlUtilParseValue(void *stream, char *buffer, int len, int *pos, struct GSIXmlString *strOut)
{
    char *strStart = 0;

    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    if (buffer[*pos] != '<')
    {
        strStart = &buffer[*pos];
        strOut->string = strStart;
    }
    while (*pos < len)
    {
        if (buffer[*pos] == '<')
            return gsiXmlUtilDecodeString(strStart, &strOut->length) != 0;
        (*pos)++;
        strOut->length++;
    }
    return 0;
}
