/*
 * function: ghiDoWaiting
 * address:  0x021C4764
 * packet:   pkt_ov114_021C4764
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoWaiting (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_0217ED64  0x0217ED64  arm   ov009
 *   func_0217ED54  0x0217ED54  arm   ov009
 *   ghiCallProgressCallback  0x021C02C8  arm   ov114
 *   sGhttpWaiting     0x021CF204  data  ov114
 */

typedef struct GHIConnection {
    unsigned char pad0[0x10];
    int f10;
    unsigned char pad1[0x40 - 0x14];
    int f40;
    unsigned char pad2[0x50 - 0x44];
    int f50;
    int f54;
    unsigned char pad3[0x124 - 0x58];
    int f124;
} GHIConnection;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_0217ED64(int, int *, int *, int *);
extern int func_0217ED54(int sock);
extern void ghiCallProgressCallback(GHIConnection *, char *, int);
extern char sGhttpWaiting[];

void ghiDoWaiting(GHIConnection *connection)
{
    int rcode;
    int readFlag;
    int exceptFlag;

    func_0217D254(8, (char *)3, 16, sGhttpWaiting);
    rcode = func_0217ED64(connection->f50, &readFlag, 0, &exceptFlag);
    if (rcode == -1 || (rcode == 1 && exceptFlag)) {
        connection->f124 = 1;
        connection->f40 = 5;
        if (rcode == -1)
            connection->f54 = func_0217ED54(connection->f50);
        else
            connection->f54 = 0;
        return;
    }
    if (rcode != 1)
        return;
    if (readFlag == 0)
        return;
    connection->f10 = 8;
    ghiCallProgressCallback(connection, 0, 0);
}
