/*
 * function: func_02182554
 * address:  0x02182554
 * packet:   pkt_ov009_02182554
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      gsiXmlUtilParseString (gsxml)
 *
 * symbols:
 *   gsiXmlUtilSkipWhiteSpace  0x02181E28 arm ov009
 *   gsiXmlUtilDecodeString    0x0218263C arm ov009
 *
 * note: near miss, 78 bytes differ: original reloads *pos into r3 before each buffer[*pos] read in the peeled first iteration (ldrsb r0,[r8,r3]) and its scan loop tests buffer[*pos] after pos++/length++ with a separate empty-string exit that sets strOut->string without decoding; C form here CSEs the read through r4 and orders the loop tail differently
 */

struct GSIXmlString
{
    char * string;  /* 0x00 */
    int length;     /* 0x04 */
};

extern int gsiXmlUtilSkipWhiteSpace(void *stream, char *buffer, int len, int *pos);
extern int gsiXmlUtilDecodeString(char *buffer, int *len);

int func_02182554(void *stream, char *buffer, int len, int *pos, struct GSIXmlString *strOut)
{
    char *strStart;
    char startCh;

    if (!gsiXmlUtilSkipWhiteSpace(stream, buffer, len, pos))
        return 0;
    startCh = buffer[*pos];
    if (startCh != '"' && startCh != '\'')
        return 0;
    (*pos)++;
    strOut->length = 0;
    strStart = &buffer[*pos];
    if (*pos >= len)
        return 0;
    if (buffer[*pos] == startCh)
    {
        strOut->string = strStart;
        (*pos)++;
        return 1;
    }
    for (;;)
    {
        if (*pos >= len)
            return 0;
        (*pos)++;
        strOut->length++;
        if (buffer[*pos] == startCh)
            break;
    }
    (*pos)++;
    if (!gsiXmlUtilDecodeString(strStart, &strOut->length))
        return 0;
    strOut->string = strStart;
    return 1;
}
