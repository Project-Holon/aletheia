/*
 * function: gsiXmlUtilWriteUnicodeString
 * address:  0x021832DC
 * packet:   pkt_ov009_021832DC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiXmlUtilWriteUnicodeString (gsxml)
 *
 * symbols:
 *   gsUnicodeStringLen            0x0218198C arm ov009
 *   _UCS2CharToUTF8String         0x021801C0 arm ov009
 *   gsiXmlUtilWriteXmlSafeString  0x0218335C arm ov009
 */

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern int gsUnicodeStringLen(unsigned short *str);
extern int _UCS2CharToUTF8String(unsigned short theUCS2Char, char *theUTF8String);
extern int gsiXmlUtilWriteXmlSafeString(struct GSIXmlStreamWriter *stream, char *str);

int gsiXmlUtilWriteUnicodeString(struct GSIXmlStreamWriter *stream, unsigned short *str)
{
    int strLen;
    int pos;
    int utf8Len;
    char utf8String[4] = {0, 0, 0, 0};

    strLen = gsUnicodeStringLen(str);
    utf8String[3] = 0;
    for (pos = 0; pos < strLen; pos++)
    {
        utf8Len = _UCS2CharToUTF8String(str[pos], utf8String);
        utf8String[utf8Len] = 0;
        if (!gsiXmlUtilWriteXmlSafeString(stream, utf8String))
            return 0;
    }
    return 1;
}
