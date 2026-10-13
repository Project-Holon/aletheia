/*
 * function: ghiAppendIntToBuffer
 * address:  0x021C00C0
 * packet:   pkt_ov114_021C00C0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiAppendIntToBuffer (ghttpbuffer)
 *
 * symbols:
 *   OS_SPrintf             0x02084F40 arm
 *   ghiAppendDataToBuffer  0x021BFCEC arm ov114
 *   sGhttpIntFormatBuffer             0x021CE594 data
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
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern char sGhttpIntFormatBuffer[];

int ghiAppendIntToBuffer(GHIBuffer *buffer, int i)
{
    char intValue[16];
    OS_SPrintf(intValue, sGhttpIntFormatBuffer, i);
    return ghiAppendDataToBuffer(buffer, intValue, 0);
}
