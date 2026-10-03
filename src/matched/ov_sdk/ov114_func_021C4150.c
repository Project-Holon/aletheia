/*
 * function: func_021C4150
 * address:  0x021C4150
 * packet:   pkt_ov114_021C4150
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiDoSecuringSession (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_021C02C8  0x021C02C8  arm  ov114
 *   func_021C011C  0x021C011C  arm  ov114
 *   func_021C00FC  0x021C00FC  arm  ov114
 *   func_021C04D4  0x021C04D4  arm  ov114
 *   func_021BFCEC  0x021BFCEC  arm  ov114
 *   func_021C0378  0x021C0378  arm  ov114
 *   g_021CF138     0x021CF138  data
 */

typedef struct GHIConnection GHIConnection;

typedef struct {
    void *connection;
    char *data;
    int size;
    int len;
    int pos;
    char pad14[0x10];
} GHIBuffer;

typedef struct GHIEncryptor {
    char pad00[0x0C];
    int initialized;            /* 0x0C */
    int sessionEstablished;     /* 0x10 */
    char pad14[0x08];
    int handshaking;            /* 0x1C */
    char pad20[0x08];
    int (*processFunc)(GHIConnection *connection, struct GHIEncryptor *encryptor); /* 0x28 */
} GHIEncryptor;

struct GHIConnection {
    char pad000[0x10];
    int state;                  /* 0x010 */
    char pad014[0x2C];
    int result;                 /* 0x040 */
    char pad044[0x14];
    GHIBuffer sendBuffer;       /* 0x058 */
    char pad07C[0x48];
    GHIBuffer decodeBuffer;     /* 0x0C4 */
    char pad0E8[0x3C];
    int completed;              /* 0x124 */
    char pad128[0x6C];
    GHIEncryptor encryptor;     /* 0x194 */
};

extern void func_0217D254(int cat, int type, int level, const char *fmt, ...);
extern void func_021C02C8(struct GHIConnection *connection, char *buffer, int bufferLen);
extern int func_021C011C(struct GHIConnection *connection);
extern void func_021C00FC(GHIBuffer *buffer);
extern int func_021C04D4(struct GHIConnection *connection, char *buffer, int *bufferLen);
extern int func_021BFCEC(GHIBuffer *buffer, char *data, int dataLen);
extern int func_021C0378(struct GHIConnection *connection);
extern char g_021CF138[];

void func_021C4150(GHIConnection *connection)
{
    int bufferLen;
    char buffer[1025];
    int result;

    if (!connection->encryptor.initialized)
    {
        func_0217D254(8, 3, 0x10, g_021CF138);
        if (connection->encryptor.processFunc != 0)
        {
            if (connection->encryptor.processFunc(connection, &connection->encryptor) == 3)
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        if (connection->encryptor.sessionEstablished)
        {
            connection->state = 5;
            func_021C02C8(connection, 0, 0);
            return;
        }
    }

    if (connection->encryptor.handshaking)
    {
        if (connection->encryptor.processFunc != 0)
        {
            if (connection->encryptor.processFunc(connection, &connection->encryptor) == 3)
            {
                connection->completed = 1;
                connection->result = 0x11;
                return;
            }
        }
        if (!connection->encryptor.sessionEstablished)
            return;
        connection->state = 5;
        func_021C02C8(connection, 0, 0);
        return;
    }

    if (connection->sendBuffer.pos < connection->sendBuffer.len)
    {
        if (!func_021C011C(connection))
            return;
        if (connection->sendBuffer.pos < connection->sendBuffer.len)
            return;
        func_021C00FC(&connection->sendBuffer);
    }

    bufferLen = sizeof(buffer);
    result = func_021C04D4(connection, buffer, &bufferLen);
    if (result == 2 || result == 3)
    {
        connection->completed = 1;
        connection->result = 0x11;
        return;
    }
    if (result != 0)
        return;
    if (!func_021BFCEC(&connection->decodeBuffer, buffer, bufferLen))
        return;
    if (!func_021C0378(connection))
    {
        connection->completed = 1;
        connection->result = 0x11;
        return;
    }
    if (!connection->encryptor.sessionEstablished)
        return;
    connection->state = 5;
    func_021C02C8(connection, 0, 0);
}
