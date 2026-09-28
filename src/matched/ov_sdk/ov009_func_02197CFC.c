/*
 * function: gti2ConnectionHash
 * address:  0x02197CFC
 * packet:   pkt_ov009_02197CFC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * sdk:      gti2ConnectionHash (gt2socket.o)
 *
 * symbols:
 *   _u32_div_f  0x0209C2B0  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct GTI2Connection {
    u32 ip;
    u16 port;
};

extern u32 _u32_div_f(u32 a, u32 b);

static int gti2ConnectionHash(void *elem, int numBuckets)
{
    struct GTI2Connection *connection = *(struct GTI2Connection **)elem;

    return (connection->ip * connection->port) % (u32)numBuckets;
}
