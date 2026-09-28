/*
 * function: gsiXmlUtilGrowBuffer
 * address:  0x02183490
 * packet:   pkt_ov009_02183490
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gsiXmlUtilGrowBuffer (gsxml.o)
 *
 * symbols:
 *   gsirealloc                       0x0217eac8 arm
 */

struct GSIXmlStreamWriter
{
    char * buffer;  /* 0x00 */
    int position;   /* 0x04 */
    int capacity;   /* 0x08 */
};

extern void *gsirealloc(void *ptr, unsigned long size);

static int gsiXmlUtilGrowBuffer(struct GSIXmlStreamWriter *stream)
{
    int newCapacity;
    void *newBuf;

    newCapacity = stream->capacity + 0x400;
    newBuf = gsirealloc(stream->buffer, newCapacity);
    if (newBuf == 0)
        return 0;
    stream->capacity = newCapacity;
    if (newBuf != stream->buffer)
        stream->buffer = newBuf;
    return 1;
}
