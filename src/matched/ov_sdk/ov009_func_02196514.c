/*
 * function: gti2HandleClose
 * address:  0x02196514
 * packet:   pkt_ov009_02196514
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gti2HandleClose (gt2message.o)
 *
 * Closed (w4_nm): the callee takes enum parameters (DWARF: enum result, enum
 * reason), so the reason is spelled as an enum conditional, and the exit is
 * goto-shaped (`if (!x) return 0; return 1;`), which gives the moveq/movne
 * order of the object.
 *
 * symbols:
 *   gti2SendClosed        0x02197bb8 arm ov009
 *   gti2ConnectionError   0x02195ec4 arm ov009
 */

typedef int GT2Bool;
typedef enum { GT2Success, GT2OutOfMemory, GT2Rejected } GT2Result;
typedef enum { GT2LocalClose, GT2RemoteClose } GT2CloseReason;

struct GTI2Connection {
    unsigned char pad0[0xc];
    int state;
};

extern GT2Bool gti2SendClosed(struct GTI2Connection *connection);
extern GT2Bool gti2ConnectionError(struct GTI2Connection *connection, GT2Result result, GT2CloseReason reason);

static GT2Bool gti2HandleClose(struct GTI2Connection *connection)
{
    if (!gti2SendClosed(connection))
        return 0;
    if (!gti2ConnectionError(connection, GT2Rejected,
                             (connection->state == 6) ? GT2LocalClose : GT2RemoteClose))
        return 0;
    return 1;
}
