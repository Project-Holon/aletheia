/*
 * function: ghiDeliverIncomingFileData
 * address:  0x021C4B18
 * packet:   pkt_ov114_021C4B18
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDeliverIncomingFileData (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   ghiAppendDataToBuffer  0x021BFCEC  arm  ov114
 *   ghiCallProgressCallback  0x021C02C8  arm  ov114
 */

typedef struct GHIBuffer {
    void *f0;
    char *f4;
    int f8;
    int fC;
} GHIBuffer;

typedef struct GHIConnection {
    unsigned char pad0[0xC];
    int fC;
    unsigned char pad1[0x40 - 0x10];
    int f40;
    unsigned char pad2[0xE8 - 0x44];
    GHIBuffer buf;
    unsigned char pad3[0x124 - 0xF8];
    int f124;
    int f128;
    int f12C;
    unsigned char pad4[0x158 - 0x130];
    int f158;
} GHIConnection;

extern int ghiAppendDataToBuffer(GHIBuffer *, char *, int);
extern void ghiCallProgressCallback(GHIConnection *, char *, int);

int ghiDeliverIncomingFileData(GHIConnection *connection, char *data, int len)
{
    char *buffer = 0;
    int bufferLen = 0;

    connection->f128 += len;
    if (connection->f128 == connection->f12C || connection->f158 != 0)
        connection->f124 = 1;

    if (connection->fC == 0) {
        if (ghiAppendDataToBuffer(&connection->buf, data, len) == 0)
            return 0;
        buffer = connection->buf.f4;
        bufferLen = connection->buf.fC;
    } else if (connection->fC == 1) {
        if (len != 0) {
            connection->f124 = 1;
            connection->f40 = 13;
            return 0;
        }
        buffer = data;
        bufferLen = len;
    } else if (connection->fC == 2) {
        buffer = data;
        bufferLen = len;
    }
    ghiCallProgressCallback(connection, buffer, bufferLen);
    return 1;
}
