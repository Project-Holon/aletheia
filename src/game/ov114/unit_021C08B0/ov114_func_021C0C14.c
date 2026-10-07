/*
 * function: ghiFreeConnectionData
 * address:  0x021C0C14
 * packet:   pkt_ov114_021C0C14
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiFreeConnectionData (ghttpconnection)
 *
 * Note: the second `connection->field2c = 0` below is deliberate. The original
 * object zeroes offset 0x2c twice and never clears the freed 0x130 pointer; the
 * duplicate store is required to reproduce its bytes exactly.
 *
 * symbols:
 *   ghiLock                 0x021C0370  arm
 *   gsifree                 0x0217EAE0  arm
 *   ghiFreeBuffer           0x021BFCB4  arm  ov114
 *   ghiPostCleanupState     0x021C2BB0  arm  ov114
 *   ghiUnlock               0x021C0374  arm
 *   ghiConnectionsLen       0x021D3B30  data
 */

typedef struct {
    char x[0x24];
} GHIBuffer;

typedef struct GHIConnection {
    int inUse;
    int index;
    char pad_08[0xc];
    void *field14;
    void *field18;
    char pad_1c[8];
    void *field24;
    char pad_28[4];
    void *field2c;
    char pad_30[4];
    void *field34;
    char pad_38[0x20];
    GHIBuffer buffer58;
    GHIBuffer buffer7c;
    GHIBuffer buffera0;
    GHIBuffer bufferc4;
    GHIBuffer buffere8;
    char pad_10c[0x24];
    void *field130;
    char pad_134[0x30];
    void *field164;
    void *field168;
    char pad_16c[0x20];
    void *field18c;
    char pad_190[4];
    int field194;
    char pad_198[4];
    void *field19c;
    char pad_1a0[0x18];
    void (*field1b8)(struct GHIConnection *connection, int *field194);
    char pad_1bc[0x14];
    int field1d0;
} GHIConnection;

typedef struct {
    int length;
    int numConnections;
    int nextUniqueID;
    GHIConnection **connections;
} GHIGlobals;

extern GHIGlobals ghiConnectionsLen;
extern void ghiLock(void);
extern void gsifree(void *ptr);
extern void ghiFreeBuffer(GHIBuffer *buffer);
extern void ghiPostCleanupState(GHIConnection *connection);
extern void ghiUnlock(void);

int ghiFreeConnectionData(GHIConnection *connection)
{
    if (connection == 0)
        return 0;
    if (connection->inUse == 0)
        return 0;
    if (connection->index < 0)
        return 0;
    if (connection->index >= ghiConnectionsLen.length)
        return 0;
    ghiLock();
    gsifree(connection->field14);
    connection->field14 = 0;
    gsifree(connection->field34);
    connection->field34 = 0;
    gsifree(connection->field18);
    connection->field18 = 0;
    gsifree(connection->field24);
    connection->field24 = 0;
    gsifree(connection->field2c);
    connection->field2c = 0;
    gsifree(connection->field130);
    connection->field2c = 0;
    gsifree(connection->field18c);
    connection->field18c = 0;
    ghiFreeBuffer(&connection->buffer58);
    ghiFreeBuffer(&connection->buffer7c);
    ghiFreeBuffer(&connection->buffera0);
    ghiFreeBuffer(&connection->bufferc4);
    ghiFreeBuffer(&connection->buffere8);
    if (connection->field168 != 0)
        ghiPostCleanupState(connection);
    if (connection->field19c != 0)
    {
        if (connection->field1b8 != 0)
            connection->field1b8(connection, &connection->field194);
        connection->field19c = 0;
    }
    connection->field1d0 = 0;
    connection->inUse = 0;
    ghiConnectionsLen.numConnections--;
    ghiUnlock();
    return 1;
}
