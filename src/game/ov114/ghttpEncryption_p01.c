/*
 * file:     ghttpEncryption_p01.c
 * unit:     yes
 * function: func_021C109C, func_021C1184
 * address:  0x021C109C
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   g_021CE758    0x021CE758  data  a4
 *   g_021CE75C    0x021CE75C  data  a4
 *   g_021CE7B0    0x021CE7B0  data  a4
 *   d_021CE6AE    0x021CE6AE  data  a1
 *   func_020948E0 0x020948E0  arm
 *   func_021C137C 0x021C137C  arm
 *   func_0217D254 0x0217D254  arm
 */
#include "ghttp_types.h"


extern GHIConnection *ghiRequestToConnection(int request);
extern int strncmp(const char *a, const char *b, unsigned int n);
extern int ghiEncryptorSslInitFunc(GHIConnection *connection, GHIEncryptor *encryptor);
extern int ghiEncryptorSslStartFunc(GHIConnection *connection, GHIEncryptor *encryptor);
extern void ghiEncryptorSslCleanupFunc(GHIConnection *connection, void *encryptor);
extern int ghiEncryptorSslEncryptFunc(GHIConnection *connection, void *encryptor, const char *plainText, int plainTextLen, char *cipherText, int *cipherTextLen);
extern int ghiEncryptorSslDecryptFunc(GHIConnection *connection, void *encryptor, char *readPos, int *readLen, char *writePos, int *writeLen);
extern int func_020948E0(const char *s1, const char *s2);
extern int func_021C137C(char *url, void *theRootCAList);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
int func_021C109C(int request, int engine);
int func_021C1184(int ctx, int arg);
extern char g_021CE74C[];
extern char g_021CE758[];
extern char g_021CE75C[];
extern char g_021CE7B0[];
extern char d_021CE6AE[];


/*
 * sdk:      ghttpSetRequestEncryptionEngine (ghttpencryption)
 *
 * note: byte-correct; blocked: callees ghiEncryptorSslEncryptFunc 0x021C1C88 and ghiEncryptorSslDecryptFunc 0x021C1C90 (two 8-byte 'mov r0,#3; bx lr' stubs) were the blockers; both now have catalog rows and matched bodies (w3_tools, 2026-09-29)
 */
int func_021C109C(int request, int engine)
{
    GHIConnection *connection;

    connection = ghiRequestToConnection(request);
    if (connection == 0)
        return 0;
    if (engine == 5)
        engine = 4;
    if (connection->encryptor.engine == engine)
        return 1;
    if (connection->encryptor.mInterface != 0 && connection->encryptor.engine != engine)
        return 0;
    if (engine == 0)
    {
        if (strncmp(connection->URL, g_021CE74C, 8) == 0)
            return 0;
    }
    connection->encryptor.engine = engine;
    if (engine == 0)
    {
        connection->encryptor.mInterface = 0;
        return 1;
    }
    connection->encryptor.mInterface = 0;
    connection->encryptor.initFunc = ghiEncryptorSslInitFunc;
    connection->encryptor.startFunc = ghiEncryptorSslStartFunc;
    connection->encryptor.cleanupFunc = ghiEncryptorSslCleanupFunc;
    connection->encryptor.encryptFunc = ghiEncryptorSslEncryptFunc;
    connection->encryptor.decryptFunc = ghiEncryptorSslDecryptFunc;
    connection->encryptor.field_08 = 0;
    connection->encryptor.initialized = 0;
    connection->encryptor.sessionEstablished = 0;
    connection->encryptor.encryptOnBuffer = 1;
    connection->encryptor.encryptOnSend = 0;
    connection->encryptor.handshaking = 0;
    connection->handleStatus = 1;
    return 1;
}


int func_021C1184(int ctx, int arg)
{
    if (arg != 0 && ctx != 0) {
        if (func_020948E0((const char *)ctx, g_021CE758) != 0)
            goto done;
    }
    func_0217D254(8, (char *)4, 1, g_021CE75C, g_021CE7B0, d_021CE6AE, 0x74, ctx, arg);
    return 0;
done:
    return func_021C137C((char *)ctx, (void *)arg);
}
