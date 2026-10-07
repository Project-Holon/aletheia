/*
 * function: ghiFreeConnection
 * address:  0x021C0D40
 * packet:   pkt_ov114_021C0D40
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiFreeConnection (ghttpconnection)
 *
 * symbols:
 *   ghiCloseConnection      0x021C0B4C  arm
 *   ghiFreeConnectionData   0x021C0C14  arm
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
extern int ghiCloseConnection(GHIConnection *connection);
extern int ghiFreeConnectionData(GHIConnection *connection);

int ghiFreeConnection(GHIConnection *connection)
{
    if (connection == 0)
        return 0;
    if (connection->inUse == 0)
        return 0;
    if (connection->index < 0)
        return 0;
    if (connection->index >= ghiConnectionsLen.length)
        return 0;
    if (ghiCloseConnection(connection) != 1)
        return 0;
    return ghiFreeConnectionData(connection);
}
