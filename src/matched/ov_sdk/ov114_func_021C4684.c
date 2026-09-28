/*
 * function: func_021C4684
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
 *   func_0217ED64  0x0217ED64  arm   ov009
 *   func_021C3834  0x021C3834  arm   ov114
 *   func_021C2BB0  0x021C2BB0  arm   ov114
 *   func_021C02C8  0x021C02C8  arm   ov114
 *   func_021C0318  0x021C0318  arm   ov114
 *   g_021CF1F8     0x021CF1F8  data  ov114
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

extern void func_0217D254(int, int, unsigned char, const char *, ...);
extern int func_0217ED64(int, int *, int *, int *);
extern int func_021C3834(GHIConnection *);
extern void func_021C2BB0(GHIConnection *);
extern void func_021C02C8(GHIConnection *, char *, int);
extern void func_021C0318(GHIConnection *);
extern char g_021CF1F8[];

void func_021C4684(GHIConnection *connection)
{
    int result;
    int oldBytesPosted;
    int rcode;
    int readFlag;

    func_0217D254(8, 3, 16, g_021CF1F8);
    oldBytesPosted = connection->f170;
    result = func_021C3834(connection);
    if (result == 0) {
        readFlag = 0;
        func_021C2BB0(connection);
        rcode = func_0217ED64(connection->f50, &readFlag, 0, 0);
        if (rcode != 1)
            return;
        if (readFlag == 0)
            return;
        connection->f10 = 8;
        func_021C02C8(connection, 0, 0);
        return;
    }
    if (result == 3) {
        connection->f180 = 0;
        return;
    }
    if (oldBytesPosted != connection->f170)
        func_021C0318(connection);
    if (result != 1)
        return;
    func_021C2BB0(connection);
    connection->f184 = 1;
    connection->f10 = 7;
    func_021C02C8(connection, 0, 0);
}
