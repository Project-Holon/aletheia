/*
 * function: gti2SetPendingAck
 * address:  0x02196920
 * packet:   pkt_ov009_02196920
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2SetPendingAck (gt2message.o)
 *
 * symbols:
 *   current_time  0x0217f264 arm
 */

struct GTI2Connection {
    unsigned char pad0[0x90];
    int field_90;
    unsigned int field_94;
};

extern unsigned int current_time(void);

static void gti2SetPendingAck(struct GTI2Connection * connection)
{
    if (connection->field_90)
        return;
    connection->field_90 = 1;
    connection->field_94 = current_time();
}
