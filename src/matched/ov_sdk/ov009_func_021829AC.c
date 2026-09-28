/*
 * function: func_021829AC
 * address:  0x021829AC
 * packet:   pkt_ov009_021829AC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlWriteOpenTag (gsxml)
 *
 * symbols:
 *   gsiXmlUtilWriteChar    0x02183210 arm ov009
 *   gsiXmlUtilWriteString  0x0218325C arm ov009
 */

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern int gsiXmlUtilWriteChar(struct GSIXmlStreamWriter *stream, char ch);
extern int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str);

int func_021829AC(void *stream, char *namespaceName, char *tag)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    if (!(gsiXmlUtilWriteChar(writer, '<')
        && gsiXmlUtilWriteString(writer, namespaceName)
        && gsiXmlUtilWriteChar(writer, ':')
        && gsiXmlUtilWriteString(writer, tag)
        && gsiXmlUtilWriteChar(writer, '>')))
        return 0;
    return 1;
}
