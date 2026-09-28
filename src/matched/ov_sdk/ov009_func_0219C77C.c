/*
 * function: qr2_expire_ip_verify
 * address:  0x0219C77C
 * packet:   pkt_ov009_0219C77C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_expire_ip_verify (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   current_time  0x0217F264 arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct ipv_entry
{
    u32 f0;
    u32 pad0;
    u32 f8;
    u32 pad1;
};

struct qr2_implementation_s
{
    u8 pad0[0x120];
    struct ipv_entry entries[0xc8];
};

extern unsigned int current_time(void);

void qr2_expire_ip_verify(struct qr2_implementation_s *qrec)
{
    int i = 0;
    unsigned int now = current_time();

    for (; i < 0xc8; i++) {
        if (qrec->entries[i].f0 != 0 &&
            now - qrec->entries[i].f8 > 0xfa0)
            qrec->entries[i].f0 = 0;
    }
}
