/*
 * function: func_021BFDEC
 * address:  0x021BFDEC
 * packet:   pkt_ov114_021BFDEC
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiEncryptDataToBuffer (ghttpbuffer.o)
 *
 * symbols:
 *   func_021BFCEC                    0x021bfcec arm  ov114
 *   func_0209477C                    0x0209477c arm
 *   func_021BFB90                    0x021bfb90 arm  ov114
 *   func_0217D254                    0x0217d254 arm  ov009
 *   g_021CE54C                       0x021ce54c data ov114
 */

struct GHIConnection;

typedef int (*GHIEncryptFunc)(struct GHIConnection *connection, void *encryptor,
                              const char *plainText, int plainTextLen,
                              char *cipherText, int *cipherTextLen);

typedef struct GHIEncryptor {
    int field0;                 /* +0x00 */
    int engine;                 /* +0x04 */
    char pad8[0x10 - 0x08];
    int sessionEstablished;     /* +0x10 */
    char pad14[0x2c - 0x14];
    GHIEncryptFunc encryptFunc; /* +0x2c */
} GHIEncryptor;

typedef struct GHIConnection {
    char pad0[0x194];
    GHIEncryptor encryptor;     /* +0x194 */
} GHIConnection;

typedef struct GHIBuffer {
    GHIConnection *connection;  /* +0x00 */
    char *data;                 /* +0x04 */
    int size;                   /* +0x08 */
    int len;                    /* +0x0c */
    int pos;                    /* +0x10 */
    int sizeIncrement;          /* +0x14 */
    int fixed;                  /* +0x18 */
    int dontFree;               /* +0x1c */
    int readOnly;               /* +0x20 */
} GHIBuffer;

extern int func_021BFCEC(GHIBuffer *buffer, const char *data, int dataLen);
extern int func_0209477C(const char *s);
extern int func_021BFB90(GHIBuffer *buffer, int sizeIncrement);
extern void func_0217D254(int theCat, int theType, unsigned char theLevel,
                          const char *theTokenStr, ...);
extern char g_021CE54C[];

int func_021BFDEC(GHIBuffer *buffer, const char *data, int dataLen)
{
    int result;
    int bufSpace = 0;
    int pos = 0;

    if (buffer == 0)
        return 0;
    if (data == 0)
        return 0;
    if (dataLen < 0)
        return 0;
    if (buffer->readOnly)
        return 0;

    if (buffer->connection->encryptor.engine == 0 ||
        buffer->connection->encryptor.sessionEstablished == 0)
        return func_021BFCEC(buffer, data, dataLen);

    if (dataLen == 0)
        dataLen = func_0209477C(data);
    if (dataLen == 0)
        return 1;

    bufSpace = buffer->size - buffer->len;
    do {
        int fragmentLen = dataLen;
        if (fragmentLen >= 0x3f01)
            fragmentLen = 0x3f01;
        result = buffer->connection->encryptor.encryptFunc(
            buffer->connection, &buffer->connection->encryptor,
            data + pos, dataLen, buffer->data + buffer->len, &bufSpace);
        if (result == 2) {
            if (func_021BFB90(buffer, buffer->sizeIncrement) == 0)
                return 0;
            bufSpace = buffer->size - buffer->len;
        } else if (result == 1) {
            pos += fragmentLen;
            buffer->len = buffer->size - bufSpace;
        } else {
            func_0217D254(8, 4, 2, g_021CE54C, result);
            return 0;
        }
    } while (pos < dataLen);
    return 1;
}
