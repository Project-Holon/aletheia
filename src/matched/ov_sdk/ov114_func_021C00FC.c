/*
 * function: func_021C00FC
 * address:  0x021C00FC
 * packet:   pkt_ov114_021C00FC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiResetBuffer (ghttpbuffer)
 *
 * symbols:
 *   (none)
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

void func_021C00FC(GHIBuffer *buffer)
{
    buffer->length = 0;
    buffer->pos = 0;
    if (buffer->fixed == 0)
        buffer->data[0] = 0;
}
