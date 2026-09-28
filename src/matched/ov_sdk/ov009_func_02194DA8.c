/*
 * function: func_02194DA8
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
 *   func_0217EAB0 0x0217EAB0  arm
 */

typedef struct {
    char *buffer;
    int size;
    int length;
} GTI2Buffer;

extern void *func_0217EAB0(unsigned long size);

int func_02194DA8(GTI2Buffer *buffer, int size)
{
    buffer->buffer = func_0217EAB0(size);
    if (buffer->buffer == 0)
        return 0;
    buffer->size = size;
    return 1;
}
