/*
 * file:     unit_021C08B0_p02.c
 * unit:     yes
 * function: func_021C0DA4, func_021C0DF8
 * address:  0x021C0DA4
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

extern void ghiLock(void);
extern void ghiUnlock(void);
GHIConnection *ghiRequestToConnection(int request);
void ghiEnumConnections(int (*callback)(GHIConnection *));
extern GHIGlobals ghiConnectionsLen;


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
