/*
 * function: func_021C3BAC
 * address:  0x021C3BAC
 * packet:   pkt_ov114_021C3BAC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoSocketInit (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_021C02C8  0x021C02C8  arm   ov114
 *   func_0217F25C  0x0217F25C  arm   ov009
 *   func_021C3A38  0x021C3A38  arm   ov114
 *   func_021C109C  0x021C109C  arm   ov114
 *   g_021CEFF8     0x021CEFF8  data
 *   g_021CF010     0x021CF010  data
 *   g_021CF050     0x021CF050  data
 *   g_021CF090     0x021CF090  data
 *   g_021CF0AC     0x021CF0AC  data
 */

typedef enum { GHI_FALSE, GHI_TRUE } GHIBool;

typedef struct GHIConnection {
    unsigned char pad0[4];
    int request;
    unsigned char pad1[0x10 - 0x8];
    int f10;
    unsigned char pad2[0x28 - 0x14];
    int protocol;
    unsigned char pad3[0x40 - 0x2C];
    int f40;
    unsigned char pad4[0x124 - 0x44];
    int f124;
    unsigned char pad5[0x194 - 0x128];
    int f194;
    int f198;
    int f19C;
    unsigned char pad6[0x1B4 - 0x1A0];
    int (*f1B4)(struct GHIConnection *, int *);
} GHIConnection;

extern void func_0217D254(int, int, unsigned char, const char *, ...);
extern void func_021C02C8(GHIConnection *, char *, int);
extern void func_0217F25C();
extern GHIBool func_021C3A38(GHIConnection *);
extern int func_021C109C(int, int);
extern char g_021CEFF8[];
extern char g_021CF010[];
extern char g_021CF050[];
extern char g_021CF090[];
extern char g_021CF0AC[];

void func_021C3BAC(GHIConnection *connection)
{
    int aResult;

    func_0217D254(8, 3, 16, g_021CEFF8);
    func_021C02C8(connection, 0, 0);
    func_0217F25C();
    if (func_021C3A38(connection) == GHI_FALSE) {
        connection->f124 = 1;
        connection->f40 = 3;
        return;
    }
    if (connection->protocol == 1 && connection->f198 == 0) {
        func_0217D254(8, 0, 2, g_021CF010);
        func_021C109C(connection->request, 5);
    } else if (connection->protocol != 1 && connection->f198 != 0) {
        func_021C109C(connection->request, 0);
        func_0217D254(8, 0, 2, g_021CF050);
    }
    if (connection->protocol == 1 && connection->f19C == 0) {
        func_0217D254(8, 3, 15, g_021CF090);
        aResult = connection->f1B4(connection, &connection->f194);
        if (aResult == 3) {
            func_0217D254(8, 3, 2, g_021CF0AC);
            connection->f124 = 1;
            connection->f40 = 17;
            return;
        }
    }
    connection->f10 = 1;
    func_021C02C8(connection, 0, 0);
}
