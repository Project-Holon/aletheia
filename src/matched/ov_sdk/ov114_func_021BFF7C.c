/*
 * function: func_021BFF7C
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
 *   g_021CE58C             0x021CE58C data
 *   g_021CE590             0x021CE590 data
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
extern char g_021CE58C[];
extern char g_021CE590[];

int func_021BFF7C(GHIBuffer *buffer, char *name, char *value)
{
    if (ghiAppendDataToBuffer(buffer, name, 0) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, g_021CE58C, 2) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, value, 0) == 0)
        return 0;
    if (ghiAppendDataToBuffer(buffer, g_021CE590, 2) == 0)
        return 0;
    return 1;
}
