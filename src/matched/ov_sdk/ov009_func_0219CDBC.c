/*
 * function: func_0219CDBC
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
 *   func_0219BA84  0x0219BA84  arm  ov009
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
extern void func_0219BA84(struct qr2_buffer_s *buf, char ptype, char *reqkey);
extern int func_0217ECA4(int sock, char *buf, int len, int flags, void *addr, int tolen);
extern unsigned int func_0217F264(void);
extern void func_0217D254(int cat, int type, int level, const char *fmt, ...);

void func_0219CDBC(qr2_implementation_s *qrec)
{
    struct qr2_buffer_s buf;

    buf.len = 0;
    func_0219BA84(&buf, 8, qrec->instance_key);
    func_0217ECA4(qrec->hbsock, buf.buffer, buf.len, 0, qrec->hbaddr, 8);
    qrec->lastheartbeat = func_0217F264();
    func_0217D254(3, 0, 0x10, g_021A7A9C, buf);
}
