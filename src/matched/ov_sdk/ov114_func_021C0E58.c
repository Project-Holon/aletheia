/*
 * function: ghiRedirectConnection
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
 *   gsDebugFormat  0x0217d254  arm   ov009
 *   gsiCancelResolvingHostname  0x0217f1c0  arm   ov009
 *   shutdown  0x0217eb9c  arm   ov009
 *   func_0217EB40  0x0217eb40  arm   ov009
 *   gsifree  0x0217eae0  arm   ov009
 *   ghiResetBuffer  0x021c00fc  arm   ov114
 *   strncmp  0x020949f4  arm
 *   sGhttpRedirectingConnection     0x021ce648  data  ov114
 *   sGhttpCancellingThreadAndFreeingMemory     0x021ce620  data  ov114
 *   sGhttpHttps2     0x021ce660  data
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

extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void gsiCancelResolvingHostname(void *);
extern int shutdown(int, int);
extern int func_0217EB40(int, int *);
extern void gsifree(void *);
extern void ghiResetBuffer(GHIBuffer *);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern int strncmp(const u8 *s1, const u8 *s2, u32 n);
extern char sGhttpRedirectingConnection[];
extern char sGhttpCancellingThreadAndFreeingMemory[];
extern char sGhttpHttps2[];

void ghiRedirectConnection(GHIConnection *connection)
{
    gsDebugFormat(8, (char *)3, 0x10, sGhttpRedirectingConnection);
    if (connection->f1cc != 0) {
        gsDebugFormat(8, (char *)3, 0x10, sGhttpCancellingThreadAndFreeingMemory);
        gsiCancelResolvingHostname(connection->f1cc);
        connection->f1cc = 0;
    }
    shutdown(connection->f50, 2);
    if (func_0217EB40(connection->f50, &connection->f1c8) == 0)
        return;
    gsifree(connection->f14);
    connection->f14 = connection->f130;
    connection->f130 = 0;
    gsifree(connection->f18);
    connection->f18 = 0;
    connection->f1c = 0;
    connection->f20 = 0;
    gsifree(connection->f24);
    connection->f24 = 0;
    connection->f10 = 0;
    connection->f50 = -1;
    ghiResetBuffer(&connection->buf58);
    ghiResetBuffer(&connection->buf7c);
    ghiResetBuffer(&connection->bufa0);
    ghiResetBuffer(&connection->bufc4);
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
        if (strncmp((const u8 *)sGhttpHttps2, (const u8 *)connection->f14, 8) != 0) {
            connection->f198 = 0;
            connection->f194 = 0;
        }
    }
    connection->f134++;
}
