/*
 * function: func_02182C10
 * address:  0x02182C10
 * packet:   pkt_ov009_02182C10
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsXmlWriteUnicodeStringElement (gsxml)
 *
 * symbols:
 *   gsUnicodeStringLen            0x0218198C arm ov009
 *   gsXmlWriteOpenTag             0x021829AC arm ov009
 *   gsiXmlUtilWriteUnicodeString  0x021832DC arm ov009
 *   gsXmlWriteCloseTag            0x02182A2C arm ov009
 */

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern int gsXmlWriteOpenTag(void *stream, char *namespaceName, char *tag);
extern int gsXmlWriteCloseTag(void *stream, char *namespaceName, char *tag);

extern int gsUnicodeStringLen(unsigned short *str);
extern int gsiXmlUtilWriteUnicodeString(struct GSIXmlStreamWriter *stream, unsigned short *str);

int func_02182C10(void *stream, char *namespaceName, char *tag, unsigned short *value)
{
    struct GSIXmlStreamWriter *writer = (struct GSIXmlStreamWriter *)stream;
    int len = gsUnicodeStringLen(value);
    int i;

    for (i = 0; i < len; i++)
    {
        if (value[i] < 0x20)
        {
            if (value[i] != 9 && value[i] != 10 && value[i] != 13)
                return 0;
        }
        else if (value[i] > 0xD7FF && value[i] < 0xE000)
            return 0;
        else if (value[i] > 0xFFFD)
            return 0;
    }
    if (!(gsXmlWriteOpenTag(writer, namespaceName, tag)
        && gsiXmlUtilWriteUnicodeString(writer, value)
        && gsXmlWriteCloseTag(writer, namespaceName, tag)))
        return 0;
    return 1;
}
