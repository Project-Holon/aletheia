/*
 * function: func_02189D28
 * address:  0x02189D28
 * packet:   pkt_ov009_02189D28
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiClipBufferToPosition (gpibuffer.o)
 *
 * symbols:
 *   func_02092364  0x02092364  arm  
 */

typedef struct GPIBuffer {
    char *buffer;
    int size;
    int len;
    int pos;
} GPIBuffer;

extern void *func_02092364(void *dst, const void *src, unsigned int n);

int func_02189D28(void **unused, GPIBuffer *buffer)
{
    if (buffer == 0 || buffer->buffer == 0 || buffer->pos == 0)
        return 0;
    buffer->len -= buffer->pos;
    if (buffer->len != 0)
        func_02092364(buffer->buffer, buffer->buffer + buffer->pos, buffer->len);
    buffer->buffer[buffer->len] = 0;
    buffer->pos = 0;
    return 0;
}
