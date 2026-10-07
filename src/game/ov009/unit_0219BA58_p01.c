/*
 * file:     unit_0219BA58_p01.c
 * unit:     yes
 * function: func_0219BA58, func_0219BA84
 * address:  0x0219BA58
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
struct SOCSockAddrIn;
struct qr2_implementation_s {
    char _pad0[0xac];
    void (*cc_callback)(int, struct SOCSockAddrIn *, void *);
    char _pad1[0x114 - 0xb0];
    void *udata;
};

struct qr2_buffer_s {
    char buffer[1400];
    int len;
};

typedef struct {
    char b[4];
} key4_t;



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


static void qr_add_packet_header(struct qr2_buffer_s *buf, char ptype,
                                 char *reqkey)
{
    buf->buffer[0] = ptype;
    *(key4_t *)&buf->buffer[1] = *(key4_t *)reqkey;
    buf->len = 5;
}
