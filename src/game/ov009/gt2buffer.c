/*
 * file:     gt2buffer.c
 * unit:     yes
 * function: func_02194DA8, func_02194DD4, func_02194DE4, func_02194DFC, func_02194E2C, func_02194E80
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
 *   func_0217EAB0 0x0217EAB0  arm
 *   strlen  0x0209477C arm
 *   memcpy  0x02092344 arm
 *   memmove 0x02092364  arm
 */
struct GTI2Buffer;
typedef struct {
    char *buffer;
    int size;
    int length;
} GTI2Buffer;

struct GTI2Buffer {
    unsigned char *data;
    int size;
    int position;
};

extern void *func_0217EAB0(unsigned long size);
extern unsigned int strlen(const char *s);
extern void *memcpy(void *dest, const void *src, unsigned int n);
extern void *memmove(void *dest, const void *src, unsigned int n);
int func_02194DA8(GTI2Buffer *buffer, int size);
int func_02194DD4(const int *p);
void func_02194DE4(int *p, int v);
void func_02194DFC(int *p, int v);
void gti2BufferWriteData(struct GTI2Buffer *buffer, unsigned char *data, int len);
void func_02194E80(GTI2Buffer *buffer, int start, int shortenBy);


/*
 * sdk:      gti2AllocateBuffer (gt2buffer.o)
 */
int func_02194DA8(GTI2Buffer *buffer, int size)
{
    buffer->buffer = func_0217EAB0(size);
    if (buffer->buffer == 0)
        return 0;
    buffer->size = size;
    return 1;
}

/*
 * Difference of the words at +4 and +8.
 */
int func_02194DD4(const int *p)
{
    return p[1] - p[2];
}

/*
 * Appends a byte through the count at +8 of the object.
 */
void func_02194DE4(int *p, int v)
{
    int n = p[2];

    p[2] = n + 1;
    *(char *)(p[0] + n) = v;
}

/*
 * Appends a 16-bit big-endian value to the byte buffer at *p, advancing the
 * length word at +8 for each half.
 */
void func_02194DFC(int *p, int v)
{
    ((unsigned char *)p[0])[p[2]++] = v >> 8;
    ((unsigned char *)p[0])[p[2]++] = v;
}


void gti2BufferWriteData(struct GTI2Buffer *buffer, unsigned char *data, int len)
{
    if ((data == 0) || (len == 0))
        return;
    if (len == -1)
        len = strlen((char *)data);
    memcpy(buffer->data + buffer->position, data, len);
    buffer->position += len;
}


/*
 * sdk:      gti2BufferShorten (gt2buffer.o)
 */
void func_02194E80(GTI2Buffer *buffer, int start, int shortenBy)
{
    if (start == -1)
        start = buffer->length - shortenBy;
    memmove(buffer->buffer + start, buffer->buffer + start + shortenBy,
                  buffer->length - start - shortenBy);
    buffer->length -= shortenBy;
}
