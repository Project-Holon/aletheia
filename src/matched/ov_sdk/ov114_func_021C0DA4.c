/*
 * function: ghiRequestToConnection
 * address:  0x021C0DA4
 * packet:   pkt_ov114_021C0DA4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiRequestToConnection (ghttpconnection)
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

GHIConnection *ghiRequestToConnection(int request)
{
    GHIConnection *connection;

    ghiLock();
    if (request < 0 || request >= ghiConnectionsLen.length)
    {
        ghiUnlock();
        return 0;
    }
    connection = ghiConnectionsLen.connections[request];
    if (connection->inUse == 0)
        connection = 0;
    ghiUnlock();
    return connection;
}
