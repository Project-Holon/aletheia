/*
 * function: gti2AllocateBuffer
 * address:  0x02194DA8
 * packet:   pkt_ov009_02194DA8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2AllocateBuffer (gt2buffer.o)
 *
 * symbols:
 *   gsimalloc 0x0217EAB0  arm
 */

typedef struct {
    char *buffer;
    int size;
    int length;
} GTI2Buffer;

extern void *gsimalloc(unsigned long size);

int gti2AllocateBuffer(GTI2Buffer *buffer, int size)
{
    buffer->buffer = gsimalloc(size);
    if (buffer->buffer == 0)
        return 0;
    buffer->size = size;
    return 1;
}
