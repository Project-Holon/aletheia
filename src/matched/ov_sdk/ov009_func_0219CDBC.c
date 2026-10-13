/*
 * function: send_keepalive
 * address:  0x0219CDBC
 * packet:   pkt_ov009_0219CDBC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_keepalive (qr2.o)
 *
 * symbols:
 *   qr_add_packet_header  0x0219BA84  arm  ov009
 *   func_0217ECA4  0x0217ECA4  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   g_021A7A9C  0x021A7A9C  data
 */

struct qr2_buffer_s {
    char buffer[1400];
    int len;
};

typedef struct qr2_implementation_s {
    int hbsock;
    unsigned char pad4[0x80];
    char instance_key[4];
    unsigned char pad88[0x30];
    unsigned int lastheartbeat;
    unsigned char padBC[0x18];
    unsigned char hbaddr[8];
} qr2_implementation_s;

extern char g_021A7A9C[];
extern void qr_add_packet_header(struct qr2_buffer_s *buf, char ptype, char *reqkey);
struct SOCSockAddr;
extern int func_0217ECA4(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
extern unsigned int func_0217F264(void);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);

void send_keepalive(qr2_implementation_s *qrec)
{
    struct qr2_buffer_s buf;

    buf.len = 0;
    qr_add_packet_header(&buf, 8, qrec->instance_key);
    func_0217ECA4(qrec->hbsock, buf.buffer, buf.len, 0, (struct SOCSockAddr *)qrec->hbaddr, 8);
    qrec->lastheartbeat = func_0217F264();
    func_0217D254(3, 0, 0x10, g_021A7A9C, buf);
}
