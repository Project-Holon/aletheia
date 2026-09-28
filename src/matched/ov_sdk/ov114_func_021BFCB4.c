/*
 * function: ghiFreeBuffer
 * address:  0x021BFCB4
 * packet:   pkt_ov114_021BFCB4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiFreeBuffer (ghttpbuffer)
 *
 * symbols:
 *   gsifree                 0x0217EAE0  arm
 *   memset                  0x020923B0  arm
 */

typedef struct {
    char pad0[4];
    void *data;
    char pad1[0x14];
    int field1c;
    char pad2[4];
} GHIBuffer;

extern void gsifree(void *ptr);
extern void *memset(void *dst, int c, unsigned int n);

void ghiFreeBuffer(GHIBuffer *buffer)
{
    if (buffer == 0 || buffer->data == 0)
        return;
    if (buffer->field1c == 0)
        gsifree(buffer->data);
    memset(buffer, 0, sizeof(GHIBuffer));
}
