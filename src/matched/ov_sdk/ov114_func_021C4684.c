/*
 * function: ghiDoPosting
 * address:  0x021C4684
 * packet:   pkt_ov114_021C4684
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoPosting (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm   ov009
 *   GSISocketSelect  0x0217ED64  arm   ov009
 *   ghiPostDoPosting  0x021C3834  arm   ov114
 *   ghiPostCleanupState  0x021C2BB0  arm   ov114
 *   ghiCallProgressCallback  0x021C02C8  arm   ov114
 *   ghiCallPostCallback  0x021C0318  arm   ov114
 *   sGhttpPosting     0x021CF1F8  data  ov114
 */

typedef struct GHIConnection {
    unsigned char pad0[0x10];
    int f10;
    unsigned char pad1[0x50 - 0x14];
    int f50;
    unsigned char pad2[0x170 - 0x54];
    int f170;
    unsigned char pad3[0x180 - 0x174];
    int f180;
    int f184;
} GHIConnection;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int GSISocketSelect(int, int *, int *, int *);
extern int ghiPostDoPosting(GHIConnection *);
extern void ghiPostCleanupState(GHIConnection *);
extern void ghiCallProgressCallback(GHIConnection *, char *, int);
extern void ghiCallPostCallback(GHIConnection *);
extern char sGhttpPosting[];

void ghiDoPosting(GHIConnection *connection)
{
    int result;
    int oldBytesPosted;
    int rcode;
    int readFlag;

    func_0217D254(8, (char *)3, 16, sGhttpPosting);
    oldBytesPosted = connection->f170;
    result = ghiPostDoPosting(connection);
    if (result == 0) {
        readFlag = 0;
        ghiPostCleanupState(connection);
        rcode = GSISocketSelect(connection->f50, &readFlag, 0, 0);
        if (rcode != 1)
            return;
        if (readFlag == 0)
            return;
        connection->f10 = 8;
        ghiCallProgressCallback(connection, 0, 0);
        return;
    }
    if (result == 3) {
        connection->f180 = 0;
        return;
    }
    if (oldBytesPosted != connection->f170)
        ghiCallPostCallback(connection);
    if (result != 1)
        return;
    ghiPostCleanupState(connection);
    connection->f184 = 1;
    connection->f10 = 7;
    ghiCallProgressCallback(connection, 0, 0);
}
