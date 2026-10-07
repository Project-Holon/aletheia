/*
 * function: func_021BFB90
 * address:  0x021BFB90
 * packet:   pkt_ov114_021BFB90
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiResizeBuffer (ghttpbuffer)
 *
 * symbols:
 *   gsirealloc  0x0217EAC8 arm ov009
 */

typedef struct {
    char pad0[4];
    char *data;
    int size;
    int length;
    int pos;
    char pad1[12];
    int fixed;
    char pad2[4];
} GHIBuffer;

extern void *gsirealloc(void *ptr, unsigned long size);

int func_021BFB90(GHIBuffer *buffer, int sizeIncrement)
{
    int newSize;
    char *tempPtr;
    if (buffer == 0)
        return 0;
    if (sizeIncrement <= 0)
        return 0;
    newSize = buffer->size + sizeIncrement;
    tempPtr = gsirealloc(buffer->data, newSize);
    if (tempPtr == 0)
        return 0;
    buffer->data = tempPtr;
    buffer->size = newSize;
    return 1;
}
