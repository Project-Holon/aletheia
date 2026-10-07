/*
 * function: qr2_check_ip_verify
 * address:  0x0219C724
 * packet:   pkt_ov009_0219C724
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_check_ip_verify (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 */

struct SOCInAddr {
    unsigned int addr;
};

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    struct SOCInAddr addr;
};

struct qr2_ipverify_info_s {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int ip;
    unsigned int ipverify;
    unsigned int time;
};

struct qr2_implementation_s {
    unsigned char pad0[0x11c];
    struct qr2_ipverify_info_s ipverify[200];
};

static int qr2_check_ip_verify(struct qr2_implementation_s *qrec,
    struct SOCSockAddrIn *sender, unsigned int ipverify)
{
    int i;

    for (i = 0; i < 200; i++) {
        if (sender->addr.addr == qrec->ipverify[i].ip &&
            sender->port == qrec->ipverify[i].port &&
            ipverify == qrec->ipverify[i].ipverify) {
            qrec->ipverify[i].ip = 0;
            qrec->ipverify[i].port = 0;
            return 1;
        }
    }
    return 0;
}
