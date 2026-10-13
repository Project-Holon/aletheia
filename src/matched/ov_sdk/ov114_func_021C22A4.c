/*
 * function: ghttpCancelRequest
 * address:  0x021C22A4
 * packet:   pkt_ov114_021C22A4
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghttpCancelRequest (ghttpmain)
 *
 * symbols:
 *   ghiRequestToConnection  0x021C0DA4 arm ov114
 *   ghiCloseConnection      0x021C0B4C arm ov114
 */

typedef struct GHIConnection {
    char pad0[0x10];
    int state;
    char pad1[0x2C];
    int completed;
    char pad2[0xE0];
    int cancelled;
} GHIConnection;

extern GHIConnection *ghiRequestToConnection(int request);
extern int ghiCloseConnection(GHIConnection *connection);

void ghttpCancelRequest(int request)
{
    GHIConnection *connection = ghiRequestToConnection(request);
    if (connection == 0)
        return;
    connection->completed = 18;
    connection->state = 11;
    connection->cancelled = 1;
    ghiCloseConnection(connection);
}
