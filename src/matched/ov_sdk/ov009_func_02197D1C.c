/*
 * function: gti2ConnectionCompare
 * address:  0x02197D1C
 * packet:   pkt_ov009_02197D1C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2ConnectionCompare (gt2socket.o)
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct GTI2Connection {
    u32 ip;
    u16 port;
};

static int gti2ConnectionCompare(void *elem1, void *elem2)
{
    struct GTI2Connection *connection1 = *(struct GTI2Connection **)elem1;
    struct GTI2Connection *connection2 = *(struct GTI2Connection **)elem2;

    return connection1->ip != connection2->ip
        ? connection1->ip - connection2->ip
        : (short)(connection1->port - connection2->port);
}
