/*
 * function: ghiParseChunkSize
 * address:  0x021C4BD8
 * packet:   pkt_ov114_021C4BD8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiParseChunkSize (ghttpprocess.o)
 *
 * symbols:
 *   STD_TSScanf  0x0208CF34  arm
 *   sGhttpChunkSizeFormat   0x021CF248  data
 */

extern int STD_TSScanf(char *src, char *fmt, ...);
extern char sGhttpChunkSizeFormat[];

typedef struct
{
    char pad[0x13c];
    char chunkHeader[16];
} GHIConnection;

int ghiParseChunkSize(GHIConnection *connection)
{
    int num;
    if (STD_TSScanf(connection->chunkHeader, sGhttpChunkSizeFormat, &num) != 1)
        return -1;
    return num;
}
