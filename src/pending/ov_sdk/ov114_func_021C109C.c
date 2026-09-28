/*
 * function: func_021C109C
 * address:  0x021C109C
 * packet:   pkt_ov114_021C109C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      ghttpSetRequestEncryptionEngine (ghttpencryption)
 *
 * symbols:
 *   ghiRequestToConnection      0x021C0DA4 arm ov114
 *   strncmp                     0x020949F4 arm
 *   g_021CE74C                  0x021CE74C data
 *   ghiEncryptorSslInitFunc     0x021C1920 arm ov114
 *   ghiEncryptorSslStartFunc    0x021C1A78 arm ov114
 *   ghiEncryptorSslCleanupFunc  0x021C1C98 arm ov114
 *   ghiEncryptorSslEncryptFunc  0x021C1C88 arm ov114
 *   ghiEncryptorSslDecryptFunc  0x021C1C90 arm ov114
 *
 * note: byte-correct; blocked: callees ghiEncryptorSslEncryptFunc 0x021C1C88 and ghiEncryptorSslDecryptFunc 0x021C1C90 (two 8-byte 'mov r0,#3; bx lr' stubs) have no catalog row and no witness, so their two ABS32 pool words cannot be attested; next pass: attest the stubs or match them
 */

typedef struct GHIConnection {
    char pad0[0x14];
    char *URL;
    char pad1[0x17C];
    int encryptorInited;
    int encryptorEngine;
    int f19c;
    int f1a0;
    int f1a4;
    int f1a8;
    int f1ac;
    int f1b0;
    int (*initFunc)();
    int (*cleanupFunc)();
    int (*startFunc)();
    int (*encryptFunc)();
    int (*decryptFunc)();
    int f1c8;
} GHIConnection;

extern GHIConnection *ghiRequestToConnection(int request);
extern int strncmp(const char *a, const char *b, unsigned int n);
extern int ghiEncryptorSslInitFunc();
extern int ghiEncryptorSslStartFunc();
extern int ghiEncryptorSslCleanupFunc();
extern int ghiEncryptorSslEncryptFunc();
extern int ghiEncryptorSslDecryptFunc();
extern char g_021CE74C[];

int func_021C109C(int request, int engine)
{
    GHIConnection *connection;

    connection = ghiRequestToConnection(request);
    if (connection == 0)
        return 0;
    if (engine == 5)
        engine = 4;
    if (connection->encryptorEngine == engine)
        return 1;
    if (connection->encryptorInited != 0 && connection->encryptorEngine != engine)
        return 0;
    if (engine == 0)
    {
        if (strncmp(connection->URL, g_021CE74C, 8) == 0)
            return 0;
    }
    connection->encryptorEngine = engine;
    if (engine == 0)
    {
        connection->encryptorInited = 0;
        return 1;
    }
    connection->encryptorInited = 0;
    connection->initFunc = ghiEncryptorSslInitFunc;
    connection->startFunc = ghiEncryptorSslStartFunc;
    connection->cleanupFunc = ghiEncryptorSslCleanupFunc;
    connection->encryptFunc = ghiEncryptorSslEncryptFunc;
    connection->decryptFunc = ghiEncryptorSslDecryptFunc;
    connection->f19c = 0;
    connection->f1a0 = 0;
    connection->f1a4 = 0;
    connection->f1a8 = 1;
    connection->f1ac = 0;
    connection->f1b0 = 0;
    connection->f1c8 = 1;
    return 1;
}
