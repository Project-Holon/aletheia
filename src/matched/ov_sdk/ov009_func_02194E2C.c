/*
 * function: gti2BufferWriteData
 * address:  0x02194E2C
 * packet:   pkt_ov009_02194E2C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2BufferWriteData (gt2buffer.o)
 *
 * symbols:
 *   strlen  0x0209477C arm
 *   memcpy  0x02092344 arm
 */

struct GTI2Buffer;

extern unsigned int strlen(const char *s);
extern void *memcpy(void *dest, const void *src, unsigned int n);

struct GTI2Buffer {
    unsigned char *data;
    int size;
    int position;
};

void gti2BufferWriteData(struct GTI2Buffer *buffer, unsigned char *data, int len)
{
    if ((data == 0) || (len == 0))
        return;
    if (len == -1)
        len = strlen((char *)data);
    memcpy(buffer->data + buffer->position, data, len);
    buffer->position += len;
}
