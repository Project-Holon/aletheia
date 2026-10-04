/*
 * function: func_0218ED58
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
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02189DFC  0x02189DFC  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0218F900  0x0218F900  arm  ov009
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

extern unsigned int func_0217F264(void);
extern void *func_0217EAB0(unsigned long size);
extern int func_02189DFC(void **connection, struct GPICallback callback, void *arg, void *operation, int type);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0218F900(struct GPIPeer *peer, struct GPIPeerOp *operation);
extern char g_021A4F30[];

void func_0218ED58(void **connection, struct GPIPeer *peer)
{
    struct GetBuddyStatusInfoKeysArg *arg;
    struct GPICallback callback;
    struct GPIPeerOp *anIterator = peer->first;

    if (peer == 0)
        return;
    for (; anIterator != 0 && anIterator != peer->last; anIterator = anIterator->pnext) {
        if (anIterator->type == 2)
            continue;
        if (func_0217F264() <= anIterator->timeout)
            continue;
        if (anIterator->callback == 0)
            continue;
        if (anIterator->state == 0x68) {
            arg = (struct GetBuddyStatusInfoKeysArg *)func_0217EAB0(sizeof(struct GetBuddyStatusInfoKeysArg));
            callback.callback = anIterator->callback;
            callback.param = anIterator->param;
            arg->a = 0;
            arg->c = 0;
            arg->b = 0;
            arg->profileid = peer->profile;
            func_02189DFC(connection, callback, arg, 0, 0);
        }
        func_0217D254(1, (char *)4, 8, g_021A4F30);
        func_0218F900(peer, anIterator);
    }
}
