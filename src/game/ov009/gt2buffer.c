/*
 * file:     gt2buffer.c
 * unit:     yes
 * function: gti2AllocateBuffer, gti2GetBufferFreeSpace, gti2BufferWriteByte, gti2BufferWriteUShort, gti2BufferWriteData, gti2BufferShorten
 * address:  0x02194DA8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gsimalloc 0x0217EAB0  arm
 *   strlen  0x0209477C arm
 *   memcpy  0x02092344 arm
 *   memmove 0x02092364  arm
 */
#include "gt2main_types.h"

#include "gsmemory.h"
#include "../arm9/msl_string_str.h"
#include "../arm9/msl_string_mem.h"
int gti2AllocateBuffer(GTI2Buffer *buffer, int size);
int gti2GetBufferFreeSpace(const int *p);
void gti2BufferWriteByte(int *p, int v);
void gti2BufferWriteUShort(int *p, int v);
void gti2BufferWriteData(GTI2Buffer *buffer, unsigned char *data, int len);
void gti2BufferShorten(GTI2Buffer *buffer, int start, int shortenBy);


/*
 * sdk:      gti2AllocateBuffer (gt2buffer.o)
 */
int gti2AllocateBuffer(GTI2Buffer *buffer, int size)
{
    buffer->buffer = gsimalloc(size);
    if (buffer->buffer == 0)
        return 0;
    buffer->size = (int)size;
    return 1;
}

/*
 * Difference of the words at +4 and +8.
 */
int gti2GetBufferFreeSpace(const int *p)
{
    return p[1] - p[2];
}

/*
 * Appends a byte through the count at +8 of the object.
 */
void gti2BufferWriteByte(int *p, int v)
{
    int n = p[2];

    p[2] = n + 1;
    *(char *)(p[0] + n) = v;
}

/*
 * Appends a 16-bit big-endian value to the byte buffer at *p, advancing the
 * length word at +8 for each half.
 */
void gti2BufferWriteUShort(int *p, int v)
{
    ((unsigned char *)p[0])[p[2]++] = v >> 8;
    ((unsigned char *)p[0])[p[2]++] = v;
}


void gti2BufferWriteData(GTI2Buffer *buffer, unsigned char *data, int len)
{
    if ((data == 0) || (len == 0))
        return;
    if (len == -1)
        len = strlen((const char *)data);
    memcpy(buffer->buffer + buffer->len, data, len);
    buffer->len += len;
}


/*
 * sdk:      gti2BufferShorten (gt2buffer.o)
 */
void gti2BufferShorten(GTI2Buffer *buffer, int start, int shortenBy)
{
    if (start == -1)
        start = buffer->len - shortenBy;
    memmove(buffer->buffer + start, buffer->buffer + start + shortenBy,
                  buffer->len - start - shortenBy);
    buffer->len -= shortenBy;
}
