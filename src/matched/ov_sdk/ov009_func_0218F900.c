/*
 * function: gpiPeerRemoveOp
 * address:  0x0218F900
 * packet:   pkt_ov009_0218F900
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiPeerRemoveOp (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   gGpiPeerDebugOpNotRemoved  0x021A5170  data
 *   gGpiPeerDebugOpRemoveNotInList  0x021A518C  data
 *   gGpiPeerDebugOpRemoved  0x021A51B8  data
 */

struct GPIPeerOp {
    char pad0[0xc];
    struct GPIPeerOp *pnext;
};

struct GPIPeer {
    char pad0[0x40];
    struct GPIPeerOp *head;
    struct GPIPeerOp *first;
    struct GPIPeerOp *last;
};

extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void gsifree(void *ptr);
extern char gGpiPeerDebugOpNotRemoved[];
extern char gGpiPeerDebugOpRemoveNotInList[];
extern char gGpiPeerDebugOpRemoved[];

void gpiPeerRemoveOp(struct GPIPeer *peer, struct GPIPeerOp *operation)
{
    struct GPIPeerOp *aPrevOp;

    if (peer == 0 || operation == 0) {
        gsDebugFormat(1, (char *)4, 2, gGpiPeerDebugOpNotRemoved);
        return;
    }
    if (peer->head == 0) {
        gsDebugFormat(1, (char *)4, 2, gGpiPeerDebugOpNotRemoved);
        return;
    }
    if (peer->first == peer->last && peer->first == operation) {
        struct GPIPeerOp *pnext = operation->pnext;

        peer->last = pnext;
        peer->first = pnext;
        peer->head = pnext;
    } else if (peer->first == operation) {
        peer->first = peer->first->pnext;
        peer->head = peer->first;
    } else {
        aPrevOp = peer->first;
        while (aPrevOp->pnext != operation) {
            if (aPrevOp->pnext == 0) {
                gsDebugFormat(1, (char *)4, 1, gGpiPeerDebugOpRemoveNotInList);
                return;
            }
            aPrevOp = aPrevOp->pnext;
        }
        aPrevOp->pnext = operation->pnext;
    }
    gsDebugFormat(1, (char *)4, 8, gGpiPeerDebugOpRemoved);
    gsifree(operation);
}
