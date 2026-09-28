/*
 * function: gti2SocketConnectionsThink
 * address:  0x02198570
 * packet:   pkt_ov009_02198570
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SocketConnectionsThink (gt2socket.o)
 *
 * symbols:
 *   current_time                    0x0217F264  arm  ov009
 *   TableMapSafe2                   0x021848E4  arm  ov009
 *   gti2SocketConnectionsThinkMap   0x02198518  arm  ov009
 */

struct GTI2Socket {
    char _pad0[0xc];
    struct HashImplementation *connections;
};

extern unsigned int current_time(void);
extern int TableMapSafe2(struct HashImplementation *table,
                         int (*fn)(void *, void *), void *data);
extern int gti2SocketConnectionsThinkMap(void *elem, void *clientData);

int gti2SocketConnectionsThink(struct GTI2Socket *socket)
{
    unsigned int now = current_time();

    if (TableMapSafe2(socket->connections, gti2SocketConnectionsThinkMap, &now))
        return 0;
    return 1;
}
