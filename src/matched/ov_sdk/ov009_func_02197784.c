/*
 * function: gti2SendAccept
 * address:  0x02197784
 * packet:   pkt_ov009_02197784
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SendAccept (gt2message.o)
 *
 * symbols:
 *   gti2BeginReliableMessage  0x02197458 arm
 *   gti2EndReliableMessage    0x0219754C arm
 */

struct GTI2Connection;
struct GTI2Socket;

extern int gti2BeginReliableMessage(struct GTI2Connection *connection, int type,
                                    int len, int *overflow);
extern int gti2EndReliableMessage(struct GTI2Connection *connection);

struct GTI2Socket {
    char pad00[0x44];
    int field_44;
};

struct GTI2Connection {
    char pad00[8];
    struct GTI2Socket *socket;
};

int gti2SendAccept(struct GTI2Connection *connection)
{
    int overflow;

    if (!gti2BeginReliableMessage(connection, 4,
                                  connection->socket->field_44 + 7, &overflow))
        return 0;
    if (overflow)
        return 1;
    return gti2EndReliableMessage(connection) != 0;
}
