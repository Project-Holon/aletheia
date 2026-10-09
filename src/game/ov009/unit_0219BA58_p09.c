/*
 * file:     unit_0219BA58_p09.c
 * unit:     yes
 * function: qr_got_recent_message
 * address:  0x0219C554
 * packet:   pkt_ov009_0219C554
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr_got_recent_message (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 */

struct qr2_implementation_s {
    unsigned char pad0[0xe0];
    int client_message_keys[10];
    int cur_message_key;
};

static int qr_got_recent_message(struct qr2_implementation_s *qrec, int msgkey)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (msgkey == qrec->client_message_keys[i])
            return 1;
    }
    qrec->cur_message_key = (qrec->cur_message_key + 1) % 10;
    qrec->client_message_keys[qrec->cur_message_key] = msgkey;
    return 0;
}
