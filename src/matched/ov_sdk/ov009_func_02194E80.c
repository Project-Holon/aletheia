/*
 * function: gti2BufferShorten
 * address:  0x02194E80
 * packet:   pkt_ov009_02194E80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2BufferShorten (gt2buffer.o)
 *
 * symbols:
 *   memmove 0x02092364  arm
 */

typedef struct {
    char *buffer;
    int size;
    int length;
} GTI2Buffer;

extern void *memmove(void *dest, const void *src, unsigned int n);

void gti2BufferShorten(GTI2Buffer *buffer, int start, int shortenBy)
{
    if (start == -1)
        start = buffer->length - shortenBy;
    memmove(buffer->buffer + start, buffer->buffer + start + shortenBy,
                  buffer->length - start - shortenBy);
    buffer->length -= shortenBy;
}
