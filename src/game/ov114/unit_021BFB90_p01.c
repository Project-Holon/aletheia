/*
 * file:     unit_021BFB90_p01.c
 * unit:     yes
 * function: func_021BFC54, func_021BFCB4, func_021BFCEC
 * address:  0x021BFC54
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gsifree                 0x0217EAE0  arm
 *   memset                  0x020923B0  arm
 *   strlen           0x0209477c arm
 *   ghiResizeBuffer  0x021bfb90 arm  ov114
 *   memcpy           0x02092344 arm
 */
typedef struct {
    char pad0[4];
    void *data;
    char pad1[0x14];
    int field1c;
    char pad2[4];
} GHIBuffer_021BFCB4;

typedef struct Base {
    unsigned char pad0[0x40];
    int f40;
    unsigned char pad1[0x124 - 0x44];
    int f124;
} Base;

typedef struct GHIBuffer_021BFCEC {
    Base *f0;
    char *f4;
    int f8;
    int fC;
    int f10;
    int f14;
    int f18;
    int f1C;
    int f20;
} GHIBuffer_021BFCEC;

extern void gsifree(void *ptr);
extern void *memset(void *dst, int c, unsigned int n);
extern unsigned int strlen(const char *);
extern void *memcpy(void *, const void *, unsigned int);
extern int func_021BFB90(GHIBuffer_021BFCEC *, int);
int func_021BFC54(int a, int *out, char *buf, int n);
void ghiFreeBuffer(GHIBuffer_021BFCB4 *buffer);
int func_021BFCEC(GHIBuffer_021BFCEC *buffer, char *data, int dataLen);

int func_021BFC54(int a, int *out, char *buf, int n)
{
    if (a == 0)
        return 0;
    if (out == 0)
        return 0;
    if (buf == 0)
        return 0;
    if (n <= 0)
        return 0;
    out[0] = a;
    out[1] = (int)buf;
    out[2] = n;
    out[3] = 0;
    out[4] = 0;
    out[5] = 0;
    out[6] = 1;
    out[7] = 1;
    out[8] = 0;
    *buf = 0;
    return 1;
}


void ghiFreeBuffer(GHIBuffer_021BFCB4 *buffer)
{
    if (buffer == 0 || buffer->data == 0)
        return;
    if (buffer->field1c == 0)
        gsifree(buffer->data);
    memset(buffer, 0, sizeof(GHIBuffer_021BFCB4));
}


int func_021BFCEC(GHIBuffer_021BFCEC *buffer, char *data, int dataLen)
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
