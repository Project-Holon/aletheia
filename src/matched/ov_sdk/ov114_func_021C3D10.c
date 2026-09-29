/*
 * function: func_021C3D10
 * address:  0x021C3D10
 * packet:   pkt_ov114_021C3D10
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoHostLookup (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_0217ED38  0x0217ED38  arm   ov009
 *   func_0217F150  0x0217F150  arm   ov009
 *   func_021C02C8  0x021C02C8  arm   ov114
 *   g_021CF0D0     0x021CF0D0  data  ov114
 *   g_021CF0E0     0x021CF0E0  data  ov114
 *   g_021D3B2C     0x021D3B2C  data  ov114
 */

typedef struct GHIConnection {
    unsigned char pad0[0x10];
    int f10;
    int f14;
    char *f18;
    unsigned int f1C;
    unsigned char pad1[0x40 - 0x20];
    int f40;
    unsigned char pad2[0x124 - 0x44];
    int f124;
    unsigned char pad3[0x18C - 0x128];
    char *f18C;
    unsigned char pad4[0x1CC - 0x190];
    void *f1CC;
} GHIConnection;

extern void func_0217D254(int, int, unsigned char, const char *, ...);
extern unsigned int func_0217ED38(char *);
extern int func_0217F150(char *, void **);
extern void func_021C02C8(GHIConnection *, char *, int);
extern char g_021CF0D0[];
extern char g_021CF0E0[];
extern char *g_021D3B2C;

void func_021C3D10(GHIConnection *connection)
{
    char *server;

    if (connection->f1CC != 0) {
        connection->f10 = 2;
        func_021C02C8(connection, 0, 0);
        return;
    }
    func_0217D254(8, 3, 16, g_021CF0D0);
    server = connection->f18C;
    if (server == 0) {
        server = g_021D3B2C;
        if (server == 0)
            server = connection->f18;
    }
    connection->f1C = func_0217ED38(server);
    if (connection->f1C == (unsigned int)-1) {
        if (func_0217F150(server, &connection->f1CC) == -1) {
            func_0217D254(8, 3, 1, g_021CF0E0);
            connection->f1CC = 0;
            connection->f124 = 1;
            connection->f40 = 4;
            return;
        }
    }
    if (connection->f1C == (unsigned int)-1) {
        connection->f10 = 2;
        func_021C02C8(connection, 0, 0);
        return;
    }
    connection->f10 = 3;
    func_021C02C8(connection, 0, 0);
}
