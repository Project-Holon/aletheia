/*
 * function: func_021C2284
 * address:  0x021C2284
 * packet:   pkt_ov114_021C2284
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghttpRequestThink (ghttpmain)
 *
 * symbols:
 *   ghiRequestToConnection  0x021C0DA4 arm ov114
 *   ghiProcessConnection    0x021C1DEC arm ov114
 */

typedef struct GHIConnection GHIConnection;

extern GHIConnection *ghiRequestToConnection(int request);
extern int ghiProcessConnection(GHIConnection *connection);

int func_021C2284(int request)
{
    GHIConnection *connection = ghiRequestToConnection(request);
    if (connection == 0)
        return 0;
    ghiProcessConnection(connection);
    return 1;
}
