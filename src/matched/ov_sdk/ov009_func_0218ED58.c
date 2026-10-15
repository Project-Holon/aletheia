/*
 * function: gpiCheckTimedOutPeerOperations
 * address:  0x0218ED58
 * packet:   pkt_ov009_0218ED58
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      gpiCheckTimedOutPeerOperations (libdwcgsgp.TWL.HYB.a(gpipeer.o))
 *
 * symbols:
 *   current_time  0x0217F264  arm  ov009
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   gpiAddCallback  0x02189DFC  arm  ov009
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gpiPeerRemoveOp  0x0218F900  arm  ov009
 *   g_021A4F30  0x021A4F30  data
 */

struct GPICallback {
    void *callback;
    void *param;
};

struct GPIPeerOp {
    int type;
    void *param;
    void *callback;
    struct GPIPeerOp *pnext;
    int state;
    unsigned int timeout;
};

struct GPIPeer {
    char pad0[0x10];
    int profile;
    char pad1[0x30];
    struct GPIPeerOp *first;
    struct GPIPeerOp *last;
};

struct GetBuddyStatusInfoKeysArg {
    int profileid;
    int a;
    int b;
    int c;
};

extern unsigned int current_time(void);
extern void *gsimalloc(unsigned long size);
extern int gpiAddCallback(void **connection, struct GPICallback callback, void *arg, void *operation, int type);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void gpiPeerRemoveOp(struct GPIPeer *peer, struct GPIPeerOp *operation);
extern char g_021A4F30[];

void gpiCheckTimedOutPeerOperations(void **connection, struct GPIPeer *peer)
{
    struct GetBuddyStatusInfoKeysArg *arg;
    struct GPICallback callback;
    struct GPIPeerOp *anIterator = peer->first;

    if (peer == 0)
        return;
    for (; anIterator != 0 && anIterator != peer->last; anIterator = anIterator->pnext) {
        if (anIterator->type == 2)
            continue;
        if (current_time() <= anIterator->timeout)
            continue;
        if (anIterator->callback == 0)
            continue;
        if (anIterator->state == 0x68) {
            arg = (struct GetBuddyStatusInfoKeysArg *)gsimalloc(sizeof(struct GetBuddyStatusInfoKeysArg));
            callback.callback = anIterator->callback;
            callback.param = anIterator->param;
            arg->a = 0;
            arg->c = 0;
            arg->b = 0;
            arg->profileid = peer->profile;
            gpiAddCallback(connection, callback, arg, 0, 0);
        }
        gsDebugFormat(1, (char *)4, 8, g_021A4F30);
        gpiPeerRemoveOp(peer, anIterator);
    }
}
