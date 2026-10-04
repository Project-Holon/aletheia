/*
 * function: func_0218F900
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
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   g_021A5170  0x021A5170  data
 *   g_021A518C  0x021A518C  data
 *   g_021A51B8  0x021A51B8  data
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

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217EAE0(void *ptr);
extern char g_021A5170[];
extern char g_021A518C[];
extern char g_021A51B8[];

void func_0218F900(struct GPIPeer *peer, struct GPIPeerOp *operation)
{
    struct GPIPeerOp *aPrevOp;

    if (peer == 0 || operation == 0) {
        func_0217D254(1, (char *)4, 2, g_021A5170);
        return;
    }
    if (peer->head == 0) {
        func_0217D254(1, (char *)4, 2, g_021A5170);
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
                func_0217D254(1, (char *)4, 1, g_021A518C);
                return;
            }
            aPrevOp = aPrevOp->pnext;
        }
        aPrevOp->pnext = operation->pnext;
    }
    func_0217D254(1, (char *)4, 8, g_021A51B8);
    func_0217EAE0(operation);
}
