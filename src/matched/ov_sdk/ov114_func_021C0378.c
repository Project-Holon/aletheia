/*
 * function: func_021C0378
 * address:  0x021C0378
 * packet:   pkt_ov114_021C0378
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDecryptReceivedData (libdwcgsghttp.TWL.HYB.a ghttpcommon.o)
 *
 * symbols:
 *   func_021BFB90  0x021bfb90  arm   ov114
 *   func_0217D254  0x0217d254  arm   ov009
 *   func_021C00FC  0x021c00fc  arm   ov114
 *   func_02092364  0x02092364  arm
 *   g_021CE5B4     0x021ce5b4  data  ov114
 */

struct GHIConnection;

typedef int (*GHIDecryptFunc)(struct GHIConnection *connection, void *encryptor,
                              char *readPos, int *readLen,
                              char *writePos, int *writeLen);

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
    char pad0[0xa0];
    GHIBuffer decodedBuffer;
    GHIBuffer recvBuffer;
    char pad1[0x194 - 0xe8];
    char encryptor[0x1c4 - 0x194];
    GHIDecryptFunc decryptFunc;
} GHIConnection;

extern int func_021BFB90(GHIBuffer *, int);
extern void func_0217D254(int, int, unsigned char, const char *, ...);
extern void func_021C00FC(GHIBuffer *);
extern void *func_02092364(void *, const void *, unsigned int);
extern char g_021CE5B4[];

int func_021C0378(GHIConnection *connection)
{
    int aResult;
    char *aReadPos;
    char *aWritePos;
    int aReadLen = 0;
    int aWriteLen = 0;
    int bytesToKeep;

    for (;;) {
        aReadPos = connection->recvBuffer.data + connection->recvBuffer.pos;
        aReadLen = connection->recvBuffer.len - connection->recvBuffer.pos;
        aWritePos = connection->decodedBuffer.data + connection->decodedBuffer.len;
        aWriteLen = connection->decodedBuffer.size - connection->decodedBuffer.len;
        aResult = connection->decryptFunc(connection, connection->encryptor,
                                          aReadPos, &aReadLen, aWritePos, &aWriteLen);
        if (aResult == 2) {
            if (func_021BFB90(&connection->decodedBuffer, connection->decodedBuffer.sizeIncrement) == 0)
                return 0;
        } else if (aResult == 3) {
            return 0;
        }
        if (aResult == 2 && aWriteLen == 0)
            continue;
        if (aReadLen > connection->recvBuffer.len) {
            func_0217D254(8, 4, 1, g_021CE5B4, aReadLen, connection->recvBuffer.len);
            return 0;
        }
        connection->recvBuffer.pos += aReadLen;
        connection->decodedBuffer.len += aWriteLen;
        if (aWriteLen <= 0)
            break;
    }
    if (connection->recvBuffer.pos > 0xff) {
        bytesToKeep = connection->recvBuffer.len - connection->recvBuffer.pos;
        if (bytesToKeep == 0) {
            func_021C00FC(&connection->recvBuffer);
        } else {
            func_02092364(connection->recvBuffer.data, connection->recvBuffer.data + connection->recvBuffer.pos, bytesToKeep);
            connection->recvBuffer.pos = 0;
            connection->recvBuffer.len = bytesToKeep;
        }
    }
    return 1;
}
