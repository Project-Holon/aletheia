/*
 * function: ghiCleanupConnections
 * address:  0x021C0FB0
 * packet:   pkt_ov114_021C0FB0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiCleanupConnections (ghttpconnection)
 *
 * symbols:
 *   ghiEnumConnections      0x021C0DF8  arm
 *   gsifree                 0x0217EAE0  arm
 *   ghiFreeConnection       0x021C0D40  arm
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
extern void ghiEnumConnections(int (*callback)(GHIConnection *));
extern void gsifree(void *ptr);
extern int ghiFreeConnection(GHIConnection *connection);

void ghiCleanupConnections(void)
{
    int i;

    if (ghiConnectionsLen.connections == 0)
        return;
    ghiEnumConnections(ghiFreeConnection);
    for (i = 0; i < ghiConnectionsLen.length; i++)
        gsifree(ghiConnectionsLen.connections[i]);
    gsifree(ghiConnectionsLen.connections);
    ghiConnectionsLen.connections = 0;
    ghiConnectionsLen.length = 0;
    ghiConnectionsLen.numConnections = 0;
}
