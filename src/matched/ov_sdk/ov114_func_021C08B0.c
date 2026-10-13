/*
 * function: ghiFindFreeSlot
 * address:  0x021C08B0
 * packet:   pkt_ov114_021C08B0
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiFindFreeSlot (ghttpconnection)
 *
 * symbols:
 *   gsirealloc         0x0217EAC8 arm ov009
 *   gsimalloc          0x0217EAB0 arm ov009
 *   gsifree            0x0217EAE0 arm ov009
 *   ghiConnectionsLen  0x021D3B30 data
 */

typedef struct GHIConnection {
    int inUse;
    char pad0[0x1D0];
} GHIConnection;

typedef struct {
    int length;
    int numConnections;
    int nextUniqueID;
    GHIConnection **connections;
} GHIGlobals;

extern GHIGlobals ghiConnectionsLen;
extern void *gsirealloc(void *ptr, unsigned long size);
extern void *gsimalloc(unsigned long size);
extern void gsifree(void *ptr);

int ghiFindFreeSlot(void)
{
    int newLen;
    GHIConnection **tempPtr;
    int i;
    int len;

    for (i = 0; i < ghiConnectionsLen.length; i++)
    {
        if (ghiConnectionsLen.connections[i]->inUse == 0)
            return i;
    }
    len = ghiConnectionsLen.length;
    newLen = len + 4;
    tempPtr = (GHIConnection **)gsirealloc(ghiConnectionsLen.connections, newLen * sizeof(GHIConnection *));
    if (tempPtr == 0)
        return -1;
    ghiConnectionsLen.connections = tempPtr;
    for (i = len; i < newLen; i++)
    {
        ghiConnectionsLen.connections[i] = (GHIConnection *)gsimalloc(sizeof(GHIConnection));
        if (ghiConnectionsLen.connections[i] == 0)
        {
            for (i--; i >= len; i--)
                gsifree(ghiConnectionsLen.connections[i]);
            return -1;
        }
        ghiConnectionsLen.connections[i]->inUse = 0;
    }
    ghiConnectionsLen.length = newLen;
    return len;
}
