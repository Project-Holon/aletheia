/*
 * function: gsXmlReadChildAsStringNT
 * address:  0x0218372C
 * packet:   pkt_ov009_0218372C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlReadChildAsStringNT (gsxml.o)
 *
 * symbols:
 *   gsXmlReadChildAsString           0x02183670 arm
 *   strncpy                          0x02094860 arm
 */

extern int gsXmlReadChildAsString(void *stream, char *matchtag, char **valueOut, int *valueLen);
extern char *strncpy(char *dest, const char *src, unsigned int n);

int gsXmlReadChildAsStringNT(void *stream, char *matchtag, char *valueOut, int maxLen)
{
    char * strValue = 0;
    int strLen = 0;
    int count;

    if (gsXmlReadChildAsString(stream, matchtag, &strValue, &strLen) == 0)
    {
        valueOut[0] = 0;
        return 0;
    }
    count = (maxLen < strLen) ? maxLen : strLen;
    strncpy(valueOut, strValue, count);
    count = (maxLen - 1 < strLen) ? maxLen - 1 : strLen;
    valueOut[count] = 0;
    return 1;
}
