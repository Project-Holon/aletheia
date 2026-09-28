/*
 * function: gsiXmlUtilWriteChar
 * address:  0x02183210
 * packet:   pkt_ov009_02183210
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiXmlUtilWriteChar (gsxml.o)
 *
 * symbols:
 *   gsiXmlUtilGrowBuffer             0x02183490 arm
 */

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern int gsiXmlUtilGrowBuffer(struct GSIXmlStreamWriter *stream);

static int gsiXmlUtilWriteChar(struct GSIXmlStreamWriter *stream, char ch)
{
    if (stream->position >= stream->capacity)
    {
        if (gsiXmlUtilGrowBuffer(stream) == 0)
            return 0;
    }
    stream->buffer[stream->position] = ch;
    stream->position++;
    return 1;
}
