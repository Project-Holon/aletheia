/*
 * function: ghiAppendHeaderToBuffer
 * address:  0x021BFF7C
 * packet:   pkt_ov114_021BFF7C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiAppendHeaderToBuffer (ghttpbuffer)
 *
 * symbols:
 *   ghiAppendDataToBuffer  0x021BFCEC arm ov114
 *   sGhttpHeaderSeparator             0x021CE58C data
 *   sGhttpLineEndBuffer             0x021CE590 data
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

extern int ghiAppendDataToBuffer(GHIBuffer *buffer, char *data, int dataLen);
extern char sGhttpHeaderSeparator[];
extern char sGhttpLineEndBuffer[];

int ghiAppendHeaderToBuffer(GHIBuffer *buffer, char *name, char *value)
{
    if (ghiAppendDataToBuffer(buffer, name, 0) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, sGhttpHeaderSeparator, 2) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, value, 0) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, sGhttpLineEndBuffer, 2) == 0)
        return 0;
    return 1;
}
