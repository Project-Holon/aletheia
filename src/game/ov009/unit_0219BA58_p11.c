/*
 * file:     unit_0219BA58_p11.c
 * unit:     yes
 * function: qr2_check_ip_verify, qr2_expire_ip_verify
 * address:  0x0219C724
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   current_time  0x0217F264 arm
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

struct qr2_implementation_s_0219C724 {
    unsigned char pad0[0x11c];
    struct qr2_ipverify_info_s ipverify[200];
};

typedef unsigned char u8;

typedef unsigned int u32;

struct ipv_entry
{
    u32 f0;
    u32 pad0;
    u32 f8;
    u32 pad1;
};

struct qr2_implementation_s_0219C77C
{
    u8 pad0[0x120];
    struct ipv_entry entries[0xc8];
};

extern unsigned int current_time(void);


static int qr2_check_ip_verify(struct qr2_implementation_s_0219C724 *qrec,
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


void qr2_expire_ip_verify(struct qr2_implementation_s_0219C77C *qrec)
{
    int i = 0;
    unsigned int now = current_time();

    for (; i < 0xc8; i++) {
        if (qrec->entries[i].f0 != 0 &&
            now - qrec->entries[i].f8 > 0xfa0)
            qrec->entries[i].f0 = 0;
    }
}
