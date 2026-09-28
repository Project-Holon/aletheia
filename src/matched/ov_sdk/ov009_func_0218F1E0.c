/*
 * function: gpiPeerGetSig
 * address:  0x0218F1E0
 * packet:   pkt_ov009_0218F1E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiPeerGetSig (gpipeer.o)
 *
 * symbols:
 *   gpiAddOperation  0x0218E114  arm
 *   gpiSendGetInfo   0x0218D40C  arm
 */

struct GPIOperation_s {
    char pad0[0x18];
    int  field18;    /* +0x18 */
};

struct GPIPeer_s {
    int  state;      /* +0x00 */
    int  initiated;  /* +0x04 */
    char pad08[0x10 - 0x08];
    int  profile;    /* +0x10 */
};

extern int gpiAddOperation(void **connection, int type, void *data,
                           struct GPIOperation_s **op, int blocking,
                           void (*callback)(void **, void *, void *),
                           void *param);
extern int gpiSendGetInfo(void **connection, int profileid, int operationid);

int gpiPeerGetSig(void **connection, struct GPIPeer_s *peer)
{
    struct GPIOperation_s *operation;
    int result;

    result = gpiAddOperation(connection, 2, 0, &operation, 0, 0, 0);
    if (result != 0)
        return result;
    result = gpiSendGetInfo(connection, peer->profile, operation->field18);
    if (result == 0) {
        peer->state = 0x65;
        return 0;
    }
    return result;
}
