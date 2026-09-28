/*
 * function: qr_add_packet_header
 * address:  0x0219BA84
 * packet:   pkt_ov009_0219BA84
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr_add_packet_header (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * The original copies the four reqkey bytes into buffer[1..4] with the
 * ldrb/strb load-pair-then-store-pair shape of a 1-aligned four-byte
 * aggregate copy.  Modelled as a { char b[4]; } aggregate.
 *
 * symbols:
 */

struct qr2_buffer_s {
    char buffer[1400];
    int len;
};

typedef struct {
    char b[4];
} key4_t;

static void qr_add_packet_header(struct qr2_buffer_s *buf, char ptype,
                                 char *reqkey)
{
    buf->buffer[0] = ptype;
    *(key4_t *)&buf->buffer[1] = *(key4_t *)reqkey;
    buf->len = 5;
}
