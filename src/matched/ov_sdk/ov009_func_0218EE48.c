/*
 * function: gpiProcessPeer
 * address:  0x0218EE48
 * packet:   pkt_ov009_0218EE48
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiProcessPeer (gpipeer.o)
 *
 * symbols:
 *   gpiProcessPeerInitiatingConnection  0x0218E3B0  arm
 *   gpiProcessPeerAcceptingConnection   0x0218E6DC  arm
 *   gpiProcessPeerConnected             0x0218E9E8  arm
 *   gpiCheckTimedOutPeerOperations      0x0218ED58  arm
 */

struct GPIPeer_s {
    int  state;      /* +0x00 */
    int  initiated;  /* +0x04 */
};

extern int  gpiProcessPeerInitiatingConnection(void **connection, struct GPIPeer_s *peer);
extern int  gpiProcessPeerAcceptingConnection(void **connection, struct GPIPeer_s *peer);
extern int  gpiProcessPeerConnected(void **connection, struct GPIPeer_s *peer);
extern void gpiCheckTimedOutPeerOperations(void **connection, struct GPIPeer_s *peer);

static int gpiProcessPeer(void **connection, struct GPIPeer_s *peer)
{
    int result = 0;

    if (peer->state == 100)
        return 3;
    if (peer->state != 0x69) {
        if (peer->initiated != 0)
            result = gpiProcessPeerInitiatingConnection(connection, peer);
        else
            result = gpiProcessPeerAcceptingConnection(connection, peer);
    }
    if (result == 0 && peer->state == 0x69) {
        result = gpiProcessPeerConnected(connection, peer);
        gpiCheckTimedOutPeerOperations(connection, peer);
    }
    return result;
}
