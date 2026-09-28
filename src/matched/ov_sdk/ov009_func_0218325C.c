/*
 * function: gsiXmlUtilWriteString
 * address:  0x0218325C
 * packet:   pkt_ov009_0218325C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiXmlUtilWriteString (gsxml.o)
 *
 * symbols:
 *   strlen                           0x0209477c arm
 *   gsiXmlUtilGrowBuffer             0x02183490 arm
 *   strcpy                           0x02094798 arm
 */

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern unsigned int strlen(const char *s);
extern char *strcpy(char *dest, const char *src);
extern int gsiXmlUtilGrowBuffer(struct GSIXmlStreamWriter *stream);

static int gsiXmlUtilWriteString(struct GSIXmlStreamWriter *stream, char *str)
{
    int strLen;

    strLen = strlen(str);
    if (strLen == 0)
        return 1;
    while (stream->capacity - stream->position <= strLen)
    {
        if (gsiXmlUtilGrowBuffer(stream) == 0)
            return 0;
    }
    strcpy(stream->buffer + stream->position, str);
    stream->position += strLen;
    return 1;
}
