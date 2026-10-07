/*
 * file:     unit_021C3A38_p01.c
 * unit:     yes
 * function: func_021C4B18, func_021C4BD8
 * address:  0x021C4B18
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
 *   func_021BFCEC  0x021BFCEC  arm  ov114
 *   func_021C02C8  0x021C02C8  arm  ov114
 *   STD_TSScanf  0x0208CF34  arm
 *   g_021CF248   0x021CF248  data
 */
typedef struct GHIBuffer {
    void *f0;
    char *f4;
    int f8;
    int fC;
} GHIBuffer;

typedef struct GHIConnection_021C4B18 {
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
} GHIConnection_021C4B18;

typedef struct
{
    char pad[0x13c];
    char chunkHeader[16];
} GHIConnection_021C4BD8;

extern int func_021BFCEC(GHIBuffer *, char *, int);
extern void func_021C02C8(GHIConnection_021C4B18 *, char *, int);
extern int STD_TSScanf(char *src, char *fmt, ...);
int func_021C4B18(GHIConnection_021C4B18 *connection, char *data, int len);
int func_021C4BD8(GHIConnection_021C4BD8 *connection);
extern char g_021CF248[];


/*
 * sdk:      ghiDeliverIncomingFileData (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 */
int func_021C4B18(GHIConnection_021C4B18 *connection, char *data, int len)
{
    char *buffer = 0;
    int bufferLen = 0;

    connection->f128 += len;
    if (connection->f128 == connection->f12C || connection->f158 != 0)
        connection->f124 = 1;

    if (connection->fC == 0) {
        if (func_021BFCEC(&connection->buf, data, len) == 0)
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
    func_021C02C8(connection, buffer, bufferLen);
    return 1;
}


/*
 * sdk:      ghiParseChunkSize (ghttpprocess.o)
 */
int func_021C4BD8(GHIConnection_021C4BD8 *connection)
{
    int num;
    if (STD_TSScanf(connection->chunkHeader, g_021CF248, &num) != 1)
        return -1;
    return num;
}
