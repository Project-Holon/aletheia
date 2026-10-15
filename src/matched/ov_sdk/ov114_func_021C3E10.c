/*
 * function: ghiDoLookupPending
 * address:  0x021C3E10
 * packet:   pkt_ov114_021C3E10
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoLookupPending (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   gsiGetResolvedIP  0x0217F1CC  arm   ov009
 *   gsDebugFormat  0x0217D254  arm   ov009
 *   ghiCallProgressCallback  0x021C02C8  arm   ov114
 *   sGhttpErrorResolvingHostname     0x021CF0F8  data  ov114
 *   sGhttpDnsLookupComplete     0x021CF114  data  ov114
 */

typedef struct GHIConnection {
    unsigned char pad0[0x10];
    int f10;
    int f14;
    int f18;
    unsigned int f1C;
    unsigned char pad1[0x40 - 0x20];
    int f40;
    unsigned char pad2[0x124 - 0x44];
    int f124;
    unsigned char pad3[0x1CC - 0x128];
    void *f1CC;
} GHIConnection;

extern int gsiGetResolvedIP(int *p);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void ghiCallProgressCallback(GHIConnection *, char *, int);
extern char sGhttpErrorResolvingHostname[];
extern char sGhttpDnsLookupComplete[];

void ghiDoLookupPending(GHIConnection *connection)
{
    connection->f1C = gsiGetResolvedIP(connection->f1CC);
    if (connection->f1C == (unsigned int)-1) {
        gsDebugFormat(8, (char *)3, 1, sGhttpErrorResolvingHostname);
        connection->f1CC = 0;
        connection->f124 = 1;
        connection->f40 = 4;
        return;
    }
    if (connection->f1C == 0) {
        connection->f10 = 2;
        ghiCallProgressCallback(connection, 0, 0);
        return;
    }
    connection->f1CC = 0;
    gsDebugFormat(8, (char *)3, 16, sGhttpDnsLookupComplete);
    connection->f10 = 3;
    ghiCallProgressCallback(connection, 0, 0);
}
