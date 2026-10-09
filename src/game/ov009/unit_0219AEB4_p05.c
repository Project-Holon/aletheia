/*
 * file:     unit_0219AEB4_p05.c
 * unit:     yes
 * function: qr2_think
 * address:  0x0219B1E8
 * packet:   pkt_ov009_0219B1E8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_think (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   qr2_check_send_heartbeat  0x0219B350 arm
 *   qr2_check_queries         0x0219B228 arm
 *   qr2_expire_ip_verify      0x0219C77C arm
 *   NNThink                   0x0219A4A4 arm
 *   current_rec               0x021A6600 data
 */

typedef unsigned char u8;
typedef unsigned long u32;

struct qr2_implementation_s
{
    u8 pad0[0xc4];
    u32 f_c4;
};

extern void qr2_check_send_heartbeat(struct qr2_implementation_s *qrec);
extern void qr2_check_queries(struct qr2_implementation_s *qrec);
extern void qr2_expire_ip_verify(struct qr2_implementation_s *qrec);
extern void NNThink(void);
extern struct qr2_implementation_s * current_rec;

void qr2_think(struct qr2_implementation_s *qrec)
{
    if (qrec == 0)
        qrec = current_rec;
    if (qrec->f_c4 != 0)
        qr2_check_send_heartbeat(qrec);
    qr2_check_queries(qrec);
    qr2_expire_ip_verify(qrec);
    NNThink();
}
