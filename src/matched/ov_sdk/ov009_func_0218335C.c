/*
 * function: gsiXmlUtilWriteXmlSafeString
 * address:  0x0218335C
 * packet:   pkt_ov009_0218335C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiXmlUtilWriteXmlSafeString (libdwcgscommon.TWL.HYB.a gsxml.o)
 *
 * symbols:
 *   strlen         0x0209477c  arm
 *   gsiXmlUtilWriteString  0x0218325c  arm   ov009
 *   sprintf        0x02094530  arm
 *   gsiXmlUtilWriteChar  0x02183210  arm   ov009
 *   gGsXmlEntityApos     0x021a3f2c  data
 *   gGsXmlEntityAmp     0x021a3f1c  data
 *   gGsXmlEntityQuot     0x021a3f24  data
 *   gGsXmlEntityLt     0x021a3f34  data
 *   gGsXmlEntityGt     0x021a3f3c  data
 *   gGsXmlEntitySpace     0x021a3f84  data
 *   gGsXmlEntityByteFormat     0x021a3f8c  data
 */

extern unsigned int strlen(const char *);
extern int sprintf(char *, const char *, ...);
extern int gsiXmlUtilWriteString(void *, char *);
extern int gsiXmlUtilWriteChar(void *, char);
extern char gGsXmlEntityAmp[];
extern char gGsXmlEntityQuot[];
extern char gGsXmlEntityApos[];
extern char gGsXmlEntityLt[];
extern char gGsXmlEntityGt[];
extern char gGsXmlEntitySpace[];
extern char gGsXmlEntityByteFormat[];

int gsiXmlUtilWriteXmlSafeString(void *stream, char *str)
{
    int strLen;
    int pos;
    int result;
    char numeric[7];

    strLen = strlen(str);
    for (pos = 0; pos < strLen; pos++) {
        char c = str[pos];
        if (c == '&') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntityAmp);
        } else if (c == '\'') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntityApos);
        } else if (c == '"') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntityQuot);
        } else if (c == '<') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntityLt);
        } else if (c == '>') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntityGt);
        } else if (c == ' ') {
            result = gsiXmlUtilWriteString(stream, gGsXmlEntitySpace);
        } else if (c < ' ' || (unsigned char)c > 0x7f) {
            sprintf(numeric, gGsXmlEntityByteFormat, (unsigned char)c);
            numeric[6] = 0;
            result = gsiXmlUtilWriteString(stream, numeric);
        } else {
            result = gsiXmlUtilWriteChar(stream, c);
        }
        if (!result)
            return 0;
    }
    return 1;
}
