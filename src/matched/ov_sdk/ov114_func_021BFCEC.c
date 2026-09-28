/*
 * function: func_021BFCEC
 * address:  0x021BFCEC
 * packet:   pkt_ov114_021BFCEC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiAppendDataToBuffer (libdwcgsghttp.TWL.HYB.a ghttpbuffer.o)
 *
 * symbols:
 *   strlen           0x0209477c arm
 *   ghiResizeBuffer  0x021bfb90 arm  ov114
 *   memcpy           0x02092344 arm
 */

typedef struct Base {
    unsigned char pad0[0x40];
    int f40;
    unsigned char pad1[0x124 - 0x44];
    int f124;
} Base;

typedef struct GHIBuffer {
    Base *f0;
    char *f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
} GHIBuffer;

extern unsigned int strlen(const char *);
extern void *memcpy(void *, const void *, unsigned int);
extern int func_021BFB90(GHIBuffer *, int);

int func_021BFCEC(GHIBuffer *buffer, char *data, int dataLen)
{
    int newLen;
    if (buffer == 0)
        return 0;
    if (data == 0)
        return 0;
    if (dataLen < 0)
        return 0;
    if (buffer->f20 != 0)
        return 0;
    if (dataLen == 0)
        dataLen = strlen(data);
    newLen = buffer->fC + dataLen;
    while (newLen >= buffer->f8) {
        if (buffer->f18 != 0) {
            buffer->f0->f124 = 1;
            buffer->f0->f40 = 2;
            return 0;
        }
        if (func_021BFB90(buffer, buffer->f14) == 0) {
            buffer->f0->f124 = 1;
            buffer->f0->f40 = 1;
            return 0;
        }
    }
    memcpy(buffer->f4 + buffer->fC, data, dataLen);
    buffer->fC = newLen;
    buffer->f4[newLen] = 0;
    return 1;
}
