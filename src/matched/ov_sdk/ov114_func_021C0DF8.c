/*
 * function: ghiEnumConnections
 * address:  0x021C0DF8
 * packet:   pkt_ov114_021C0DF8
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiEnumConnections (ghttpconnection)
 *
 * symbols:
 *   ghiLock                 0x021C0370  arm
 *   ghiUnlock               0x021C0374  arm
 *   ghiConnectionsLen       0x021D3B30  data
 */

typedef struct GHIConnection {
    int inUse;
    int index;
} GHIConnection;

typedef struct {
    int length;
    int numConnections;
    int nextUniqueID;
    GHIConnection **connections;
} GHIGlobals;

extern GHIGlobals ghiConnectionsLen;
extern void ghiLock(void);
extern void ghiUnlock(void);

void ghiEnumConnections(int (*callback)(GHIConnection *))
{
    int i;

    if (ghiConnectionsLen.numConnections <= 0)
        return;
    ghiLock();
    for (i = 0; i < ghiConnectionsLen.length; i++)
    {
        GHIConnection *connection = ghiConnectionsLen.connections[i];
        if (connection->inUse != 0)
            callback(connection);
    }
    ghiUnlock();
}
