/*
 * function: ghiCallProgressCallback
 * address:  0x021C02C8
 * packet:   pkt_ov114_021C02C8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiCallProgressCallback (ghttpcallbacks)
 *
 * symbols:
 *   (none)
 */

typedef struct GHIConnection {
    char pad0[4];
    int request;
    char pad1[8];
    int state;
    char pad2[0x30];
    void (*progressCallback)(int, int, char *, int, int, int, int);
    char pad3[4];
    void *param;
    char pad4[0xD8];
    int downloadedBytes;
    int totalSize;
} GHIConnection;

void ghiCallProgressCallback(GHIConnection *connection, char *buffer, int bufferLen)
{
    if (connection->progressCallback != 0)
        connection->progressCallback(connection->request, connection->state, buffer, bufferLen, connection->downloadedBytes, connection->totalSize, (int)connection->param);
}
