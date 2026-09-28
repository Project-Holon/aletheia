/*
 * function: NatNegCompletedCallback
 * address:  0x0219BA58
 * packet:   pkt_ov009_0219BA58
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NatNegCompletedCallback (qr2.o)
 */

struct SOCSockAddrIn;

struct qr2_implementation_s {
    char _pad0[0xac];
    void (*cc_callback)(int, struct SOCSockAddrIn *, void *);
    char _pad1[0x114 - 0xb0];
    void *udata;
};

static void NatNegCompletedCallback(int result, int gamesocket,
                                    struct SOCSockAddrIn *remoteaddr,
                                    void *userdata)
{
    struct qr2_implementation_s *qrec = userdata;

    if (qrec->cc_callback == 0)
        return;
    if (result != 0)
        return;
    qrec->cc_callback(gamesocket, remoteaddr, qrec->udata);
}
