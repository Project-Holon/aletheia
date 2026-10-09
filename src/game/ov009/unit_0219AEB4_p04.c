/*
 * file:     unit_0219AEB4_p04.c
 * unit:     yes
 * function: qr2_register_publicaddress_callback
 * address:  0x0219B1AC
 * packet:   pkt_ov009_0219B1AC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_register_publicaddress_callback (qr2.o)
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   g_021A7484     0x021A7484  data
 *   current_rec    0x021A6600  data
 */

struct qr2_implementation_s {
    char _pad0[0xa8];
    void (*pa_callback)(unsigned int, unsigned short, void *);
};

extern void gsDebugFormat(int cat, int type, int level, char *fmt);
extern char g_021A7484[];
extern struct qr2_implementation_s *current_rec;

void qr2_register_publicaddress_callback(
    struct qr2_implementation_s *qrec,
    void (*pacallback)(unsigned int, unsigned short, void *))
{
    gsDebugFormat(3, 4, 0x40, g_021A7484);
    if (qrec == 0)
        qrec = current_rec;
    qrec->pa_callback = pacallback;
}
