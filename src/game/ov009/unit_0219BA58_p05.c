/*
 * file:     unit_0219BA58_p05.c
 * unit:     yes
 * function: qr_build_query_reply
 * address:  0x0219BE80
 * packet:   pkt_ov009_0219BE80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr_build_query_reply (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   qr_build_partial_query_reply  0x0219BC2C arm
 */

struct qr2_buffer_s {
    unsigned char buffer[1400];
    int len;
};

struct qr2_implementation_s;

extern void qr_build_partial_query_reply(struct qr2_implementation_s *qrec,
    struct qr2_buffer_s *buf, int keytype, int keycount, unsigned char *keys);

static void qr_build_query_reply(struct qr2_implementation_s *qrec,
    struct qr2_buffer_s *buf, int serverkeycount, unsigned char *serverkeys,
    int playerkeycount, unsigned char *playerkeys,
    int teamkeycount, unsigned char *teamkeys)
{
    qr_build_partial_query_reply(qrec, buf, 0, serverkeycount, serverkeys);
    qr_build_partial_query_reply(qrec, buf, 1, playerkeycount, playerkeys);
    qr_build_partial_query_reply(qrec, buf, 2, teamkeycount, teamkeys);
}
