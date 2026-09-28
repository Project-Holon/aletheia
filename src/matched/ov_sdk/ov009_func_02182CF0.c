/*
 * function: func_02182CF0
 * address:  0x02182CF0
 * packet:   pkt_ov009_02182CF0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlWriteIntElement (gsxml)
 *
 * symbols:
 *   sprintf                0x02094530 arm
 *   gsXmlWriteOpenTag      0x021829AC arm ov009
 *   gsiXmlUtilWriteString  0x0218325C arm ov009
 *   gsXmlWriteCloseTag     0x02182A2C arm ov009
 *   g_021A3F54             0x021A3F54 data
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

extern int sprintf(char *buf, const char *fmt, ...);
extern char g_021A3F54[];

int func_02182CF0(void *stream, char *namespaceName, char *tag, unsigned int value)
{
    char buf[32];
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;

    sprintf(buf, g_021A3F54, value);
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteString(writer, buf)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}
