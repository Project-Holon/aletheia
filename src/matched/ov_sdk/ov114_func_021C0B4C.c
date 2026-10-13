/*
 * function: ghiCloseConnection
 * address:  0x021C0B4C
 * packet:   pkt_ov114_021C0B4C
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiCloseConnection (ghttpconnection)
 *
 * symbols:
 *   ghiLock                     0x021C0370  arm
 *   gsDebugFormat               0x0217D254  arm
 *   gsiCancelResolvingHostname  0x0217F1C0  arm
 *   shutdown                    0x0217EB9C  arm
 *   closesocketsure             0x0217EB40  arm
 *   ghiUnlock                   0x021C0374  arm
 *   ghiConnectionsLen           0x021D3B30  data
 *   sGhttpCancellingThreadAndFreeingMemory                  0x021CE620  data
 */

typedef struct GHIConnection {
    int inUse;
    int index;
    char pad1[0x48];
    int socket;
    char pad2[0x174];
    int field1c8;
    void *field1cc;
} GHIConnection;

typedef struct {
    int length;
    int numConnections;
    int nextUniqueID;
    GHIConnection **connections;
} GHIGlobals;

extern GHIGlobals ghiConnectionsLen;
extern void ghiLock(void);
extern void gsDebugFormat(int cat, int type, unsigned int level, char *tokenStr);
extern void gsiCancelResolvingHostname(void *host);
extern int shutdown(int sock, int how);
extern int closesocketsure(int sock, int *notInCloseSocket);
extern void ghiUnlock(void);
extern char sGhttpCancellingThreadAndFreeingMemory[];

int ghiCloseConnection(GHIConnection *connection)
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
    if (connection->field1cc != 0)
    {
        gsDebugFormat(8, 3, 0x10, sGhttpCancellingThreadAndFreeingMemory);
        gsiCancelResolvingHostname(connection->field1cc);
        connection->field1cc = 0;
    }
    if (connection->socket != -1)
    {
        shutdown(connection->socket, 2);
        if (closesocketsure(connection->socket, &connection->field1c8) == 0)
        {
            ghiUnlock();
            return 0;
        }
        connection->socket = -1;
    }
    ghiUnlock();
    return 1;
}
