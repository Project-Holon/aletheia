/*
 * function: gsXmlWriteHexBinaryElement
 * address:  0x02182E90
 * packet:   pkt_ov009_02182E90
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlWriteHexBinaryElement (gsxml)
 *
 * symbols:
 *   gsXmlWriteOpenTag    0x021829AC arm ov009
 *   sprintf              0x02094530 arm
 *   gsiXmlUtilWriteChar  0x02183210 arm ov009
 *   gsXmlWriteCloseTag   0x02182A2C arm ov009
 *   gGsXmlHex2Format           0x021A3F5C data
 */

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);

extern int sprintf(char *buf, const char *fmt, ...);
extern int gsiXmlUtilWriteChar(struct GSIXmlStreamWriter *stream, char ch);
extern char gGsXmlHex2Format[];

int gsXmlWriteHexBinaryElement(void *stream, char *namespaceName, char *tag, unsigned char *data, int len)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    int pos = 0;
    char hex[3];

    hex[2] = 0;
    if (!gsXmlWriteOpenTag(writer, namespaceName, tag))
        return 0;
    for (pos = 0; pos < len; )
    {
        sprintf(hex, gGsXmlHex2Format, data[pos]);
        pos++;
        if (!gsiXmlUtilWriteChar(writer, hex[0]))
            return 0;
        if (!gsiXmlUtilWriteChar(writer, hex[1]))
            return 0;
    }
    if (!gsXmlWriteCloseTag(writer, namespaceName, tag))
        return 0;
    return 1;
}
