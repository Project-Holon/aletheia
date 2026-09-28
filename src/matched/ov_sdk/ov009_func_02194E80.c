/*
 * function: func_02194E80
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
 *   func_02092364 0x02092364  arm
 */

typedef struct {
    char *buffer;
    int size;
    int length;
} GTI2Buffer;

extern void func_02092364(void *dst, const void *src, int n);

void func_02194E80(GTI2Buffer *buffer, int start, int shortenBy)
{
    if (start == -1)
        start = buffer->length - shortenBy;
    func_02092364(buffer->buffer + start, buffer->buffer + start + shortenBy,
                  buffer->length - start - shortenBy);
    buffer->length -= shortenBy;
}
