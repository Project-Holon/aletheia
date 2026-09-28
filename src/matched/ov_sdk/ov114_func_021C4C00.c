/*
 * function: func_021C4C00
 * address:  0x021C4C00
 * packet:   pkt_ov114_021C4C00
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiAppendToChunkHeaderBuffer (ghttpprocess.o)
 *
 * symbols:
 *   memcpy  0x02092344  arm
 */

extern void *memcpy(void *dst, const void *src, unsigned int n);

typedef struct
{
    char pad[0x13c];
    char chunkHeader[12];
    int chunkHeaderLen;
} GHIConnection;

void func_021C4C00(GHIConnection *connection, char *data, int len)
{
    int n;
    if (len == 0 || connection->chunkHeaderLen >= 10)
        return;
    n = 10 - connection->chunkHeaderLen;
    if (n >= len)
        n = len;
    memcpy(connection->chunkHeader + connection->chunkHeaderLen, data, n);
    connection->chunkHeaderLen += n;
    connection->chunkHeader[connection->chunkHeaderLen] = 0;
}
