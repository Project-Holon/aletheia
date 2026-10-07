/*
 * function: func_021C3E10
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
 *   func_0217F1CC  0x0217F1CC  arm   ov009
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_021C02C8  0x021C02C8  arm   ov114
 *   g_021CF0F8     0x021CF0F8  data  ov114
 *   g_021CF114     0x021CF114  data  ov114
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

extern int func_0217F1CC(int *p);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_021C02C8(GHIConnection *, char *, int);
extern char g_021CF0F8[];
extern char g_021CF114[];

void func_021C3E10(GHIConnection *connection)
{
    connection->f1C = func_0217F1CC(connection->f1CC);
    if (connection->f1C == (unsigned int)-1) {
        func_0217D254(8, (char *)3, 1, g_021CF0F8);
        connection->f1CC = 0;
        connection->f124 = 1;
        connection->f40 = 4;
        return;
    }
    if (connection->f1C == 0) {
        connection->f10 = 2;
        func_021C02C8(connection, 0, 0);
        return;
    }
    connection->f1CC = 0;
    func_0217D254(8, (char *)3, 16, g_021CF114);
    connection->f10 = 3;
    func_021C02C8(connection, 0, 0);
}
