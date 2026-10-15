/*
 * function: gpiPeerAddOp
 * address:  0x0218F884
 * packet:   pkt_ov009_0218F884
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiPeerAddOp (gpipeer.o)
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm
 *   gGpiPeerDebugOpNotAdded     0x021A513C  data
 *   gGpiPeerDebugOpAdded     0x021A5158  data
 */

struct _GPIPeerOp {
    int state;       /* +0x00 */
    void *userData;  /* +0x04 */
    void (*callback)(void **, void *, void *); /* +0x08 */
    struct _GPIPeerOp *next;  /* +0x0c */
    int type;        /* +0x10 */
    unsigned int timeout;     /* +0x14 */
};

struct _GPIPeerOpQueue {
    struct _GPIPeerOp *first;  /* +0x40 */
    struct _GPIPeerOp *last;   /* +0x44 */
    struct _GPIPeerOp *cur;    /* +0x48 */
};

struct GPIPeer_s {
    char pad0[0x40];
    struct _GPIPeerOpQueue peerOpQueue;  /* +0x40 */
};

extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr, ...);
extern char gGpiPeerDebugOpNotAdded[];
extern char gGpiPeerDebugOpAdded[];

void gpiPeerAddOp(struct GPIPeer_s *peer, struct _GPIPeerOp *operation)
{
    if (peer == 0 || operation == 0) {
        gsDebugFormat(1, 4, 2, gGpiPeerDebugOpNotAdded);
        return;
    }
    if (peer->peerOpQueue.first == 0) {
        peer->peerOpQueue.last = operation;
        peer->peerOpQueue.cur = operation;
        peer->peerOpQueue.first = operation;
    } else {
        if (peer->peerOpQueue.last == peer->peerOpQueue.cur) {
            peer->peerOpQueue.last->next = operation;
            peer->peerOpQueue.cur = operation;
        } else {
            peer->peerOpQueue.cur->next = operation;
            peer->peerOpQueue.cur = operation;
        }
    }
    gsDebugFormat(1, 4, 8, gGpiPeerDebugOpAdded);
}
