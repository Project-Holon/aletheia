/*
 * function: func_021C0E58
 * address:  0x021C0E58
 * packet:   pkt_ov114_021C0E58
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiRedirectConnection (libdwcgsghttp.TWL.HYB.a ghttpconnection.o)
 *
 * symbols:
 *   func_0217D254  0x0217d254  arm   ov009
 *   func_0217F1C0  0x0217f1c0  arm   ov009
 *   func_0217EB9C  0x0217eb9c  arm   ov009
 *   func_0217EB40  0x0217eb40  arm   ov009
 *   func_0217EAE0  0x0217eae0  arm   ov009
 *   func_021C00FC  0x021c00fc  arm   ov114
 *   func_020949F4  0x020949f4  arm
 *   g_021CE648     0x021ce648  data  ov114
 *   g_021CE620     0x021ce620  data  ov114
 *   g_021CE660     0x021ce660  data
 */

struct GHIConnection;

typedef void (*GHICleanupFunc)(struct GHIConnection *, void *);

typedef struct GHIBuffer {
    struct GHIConnection *connection;
    char *data;
    int size;
    int len;
    int pos;
    int sizeIncrement;
    int fixed;
    int dontFree;
    int readOnly;
} GHIBuffer;

typedef struct GHIConnection {
    char pad0[0x10];
    int f10;
    char *f14;
    char *f18;
    int f1c;
    unsigned short f20;
    char pad1[2];
    char *f24;
    char pad2[0x50 - 0x28];
    int f50;
    char pad3[0x58 - 0x54];
    GHIBuffer buf58;
    GHIBuffer buf7c;
    GHIBuffer bufa0;
    GHIBuffer bufc4;
    char pad4[0x110 - 0xe8];
    int f110;
    int f114;
    int f118;
    int f11c;
    int f120;
    char pad5[0x130 - 0x124];
    char *f130;
    int f134;
    char pad6[0x158 - 0x138];
    int f158;
    char pad7[0x194 - 0x15c];
    int f194;
    int f198;
    int f19c;
    char pad8[0x1b8 - 0x1a0];
    GHICleanupFunc f1b8;
    char pad9[0x1c8 - 0x1bc];
    int f1c8;
    void *f1cc;
} GHIConnection;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217F1C0(void *);
extern int func_0217EB9C(int, int);
extern int func_0217EB40(int, int *);
extern void func_0217EAE0(void *);
extern void func_021C00FC(GHIBuffer *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern char g_021CE648[];
extern char g_021CE620[];
extern char g_021CE660[];

void func_021C0E58(GHIConnection *connection)
{
    func_0217D254(8, (char *)3, 0x10, g_021CE648);
    if (connection->f1cc != 0) {
        func_0217D254(8, (char *)3, 0x10, g_021CE620);
        func_0217F1C0(connection->f1cc);
        connection->f1cc = 0;
    }
    func_0217EB9C(connection->f50, 2);
    if (func_0217EB40(connection->f50, &connection->f1c8) == 0)
        return;
    func_0217EAE0(connection->f14);
    connection->f14 = connection->f130;
    connection->f130 = 0;
    func_0217EAE0(connection->f18);
    connection->f18 = 0;
    connection->f1c = 0;
    connection->f20 = 0;
    func_0217EAE0(connection->f24);
    connection->f24 = 0;
    connection->f10 = 0;
    connection->f50 = -1;
    func_021C00FC(&connection->buf58);
    func_021C00FC(&connection->buf7c);
    func_021C00FC(&connection->bufa0);
    func_021C00FC(&connection->bufc4);
    connection->f110 = 0;
    connection->f114 = 0;
    connection->f118 = 0;
    connection->f11c = 0;
    connection->f120 = 0;
    connection->f158 = 0;
    if (connection->f19c != 0) {
        if (connection->f1b8 != 0)
            connection->f1b8(connection, &connection->f194);
        connection->f19c = 0;
        if (func_020949F4((const u8 *)g_021CE660, (const u8 *)connection->f14, 8) != 0) {
            connection->f198 = 0;
            connection->f194 = 0;
        }
    }
    connection->f134++;
}
