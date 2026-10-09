/*
 * file:     unit_0219AEB4_p03.c
 * unit:     yes
 * function: qr2_register_clientmessage_callback
 * address:  0x0219B170
 * packet:   pkt_ov009_0219B170
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_register_clientmessage_callback (qr2.o)
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   g_021A745C     0x021A745C  data
 *   current_rec    0x021A6600  data
 */

struct qr2_implementation_s {
    char _pad0[0xa4];
    void (*cm_callback)(char *, int, void *);
};

extern void gsDebugFormat(int cat, int type, int level, char *fmt);
extern char g_021A745C[];
extern struct qr2_implementation_s *current_rec;

void qr2_register_clientmessage_callback(struct qr2_implementation_s *qrec,
                                         void (*cmcallback)(char *, int, void *))
{
    gsDebugFormat(3, 4, 0x40, g_021A745C);
    if (qrec == 0)
        qrec = current_rec;
    qrec->cm_callback = cmcallback;
}
