/*
 * file:     unit_0218F884.c
 * unit:     yes
 * function: func_0218F884, func_0218F900
 * address:  0x0218F884
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm
 *   g_021A513C     0x021A513C  data
 *   g_021A5158     0x021A5158  data
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   g_021A5170  0x021A5170  data
 *   g_021A518C  0x021A518C  data
 *   g_021A51B8  0x021A51B8  data
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

extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr, ...);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217EAE0(void *ptr);
void gpiPeerAddOp(struct GPIPeer_s *peer, struct _GPIPeerOp *operation);
void func_0218F900(struct GPIPeer *peer, struct GPIPeerOp *operation);
extern char g_021A513C[];
extern char g_021A5158[];
extern char g_021A5170[];
extern char g_021A518C[];
extern char g_021A51B8[];


void gpiPeerAddOp(struct GPIPeer_s *peer, struct _GPIPeerOp *operation)
{
    if (peer == 0 || operation == 0) {
        gsDebugFormat(1, 4, 2, g_021A513C);
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
    gsDebugFormat(1, 4, 8, g_021A5158);
}


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
