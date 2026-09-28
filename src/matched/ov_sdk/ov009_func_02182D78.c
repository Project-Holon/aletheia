/*
 * function: func_02182D78
 * address:  0x02182D78
 * packet:   pkt_ov009_02182D78
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlWriteInt64Element (gsxml)
 *
 * symbols:
 *   gsiInt64ToString       0x0217F130 arm ov009
 *   gsXmlWriteOpenTag      0x021829AC arm ov009
 *   gsiXmlUtilWriteString  0x0218325C arm ov009
 *   gsXmlWriteCloseTag     0x02182A2C arm ov009
 */

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);
extern int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str);

extern void gsiInt64ToString(char *theNumberStr, long long theNumber);

int func_02182D78(void *stream, char *namespaceName, char *tag, long long value)
{
    char buf[33];
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;

    gsiInt64ToString(buf, value);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, buf)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}
