/*
 * function: ghiDoSocketInit
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
 *   gsDebugFormat  0x0217D254  arm   ov009
 *   ghiCallProgressCallback  0x021C02C8  arm   ov114
 *   SocketStartUp  0x0217F25C  arm   ov009
 *   ghiParseURL  0x021C3A38  arm   ov114
 *   ghttpSetRequestEncryptionEngine  0x021C109C  arm   ov114
 *   sGhttpSocketInitialization     0x021CEFF8  data
 *   sGhttpEncryptionEngineNotSetFor     0x021CF010  data
 *   sGhttpEncryptionEngineSetForUnsecured     0x021CF050  data
 *   sGhttpInitializingSslEngine     0x021CF090  data
 *   sGhttpFailedToInitializeSslEngine     0x021CF0AC  data
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

extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void ghiCallProgressCallback(GHIConnection *, char *, int);
extern void SocketStartUp();
extern GHIBool ghiParseURL(GHIConnection *);
extern int ghttpSetRequestEncryptionEngine(int, int);
extern char sGhttpSocketInitialization[];
extern char sGhttpEncryptionEngineNotSetFor[];
extern char sGhttpEncryptionEngineSetForUnsecured[];
extern char sGhttpInitializingSslEngine[];
extern char sGhttpFailedToInitializeSslEngine[];

void ghiDoSocketInit(GHIConnection *connection)
{
    int aResult;

    gsDebugFormat(8, (char *)3, 16, sGhttpSocketInitialization);
    ghiCallProgressCallback(connection, 0, 0);
    SocketStartUp();
    if (ghiParseURL(connection) == GHI_FALSE) {
        connection->f124 = 1;
        connection->f40 = 3;
        return;
    }
    if (connection->protocol == 1 && connection->f198 == 0) {
        gsDebugFormat(8, 0, 2, sGhttpEncryptionEngineNotSetFor);
        ghttpSetRequestEncryptionEngine(connection->request, 5);
    } else if (connection->protocol != 1 && connection->f198 != 0) {
        ghttpSetRequestEncryptionEngine(connection->request, 0);
        gsDebugFormat(8, 0, 2, sGhttpEncryptionEngineSetForUnsecured);
    }
    if (connection->protocol == 1 && connection->f19C == 0) {
        gsDebugFormat(8, (char *)3, 15, sGhttpInitializingSslEngine);
        aResult = connection->f1B4(connection, &connection->f194);
        if (aResult == 3) {
            gsDebugFormat(8, (char *)3, 2, sGhttpFailedToInitializeSslEngine);
            connection->f124 = 1;
            connection->f40 = 17;
            return;
        }
    }
    connection->f10 = 1;
    ghiCallProgressCallback(connection, 0, 0);
}
