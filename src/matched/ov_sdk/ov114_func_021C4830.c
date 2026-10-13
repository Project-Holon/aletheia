/*
 * function: ghiParseStatus
 * address:  0x021C4830
 * packet:   pkt_ov114_021C4830
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiParseStatus (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   STD_TSScanf  0x0208CF34  arm
 *   sGhttpHttp4   0x021CF210  data
 *   g_020A61DC   0x020A61DC  data
 */

typedef struct GHIConnection {
    unsigned char pad0[0x40];
    int f40;
    unsigned char pad1[0xA4 - 0x44];
    char *fA4;
    unsigned char pad2[0x110 - 0xA8];
    int f110;
    int f114;
    int f118;
    int f11C;
    unsigned char pad3[0x124 - 0x120];
    int f124;
} GHIConnection;

extern int STD_TSScanf(char *src, char *fmt, ...);
extern char sGhttpHttp4[];
extern const unsigned short g_020A61DC[];

static inline int isspace(int c) { return ((c < 0 || c >= 0x80) ? 0 : (g_020A61DC[c] & 0x100)); }

int ghiParseStatus(GHIConnection *connection)
{
    int majorVersion;
    int minorVersion;
    int statusCode;
    int statusStringIndex;
    int rcode;
    char c;

    rcode = STD_TSScanf(connection->fA4, sGhttpHttp4, &majorVersion, &minorVersion,
                        &statusCode, &statusStringIndex);
    if (rcode != 3 || majorVersion < 1 || statusCode < 100 || statusCode >= 600) {
        connection->f124 = 1;
        connection->f40 = 7;
        return 0;
    }
    while ((c = connection->fA4[statusStringIndex]) != 0 && isspace(c))
        statusStringIndex++;
    connection->f110 = majorVersion;
    connection->f114 = minorVersion;
    connection->f118 = statusCode;
    connection->f11C = statusStringIndex;
    return 1;
}
