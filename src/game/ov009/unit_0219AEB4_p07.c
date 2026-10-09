/*
 * file:     unit_0219AEB4_p07.c
 * unit:     yes
 * function: qr2_send_statechanged
 * address:  0x0219B490
 * packet:   pkt_ov009_0219B490
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_send_statechanged (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   gsDebugFormat  0x0217D254 arm
 *   current_time   0x0217F264 arm
 *   send_heartbeat 0x0219CE58 arm
 *   g_021A75F0     0x021A75F0 data
 *   current_rec    0x021A6600 data
 *   g_021A760C     0x021A760C data
 *   g_021A7644     0x021A7644 data
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct qr2_implementation_s
{
    u8 pad0[0xb4];
    u32 f_b4;                /* +0xb4 */
    u8 pad1[0xbc - 0xb8];
    u32 f_bc;                /* +0xbc */
    u8 pad2[0xc4 - 0xc0];
    u32 f_c4;                /* +0xc4 */
};

extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, char *theTokenStr, ...);
extern unsigned int current_time(void);
extern void send_heartbeat(struct qr2_implementation_s *qrec, int statechanged);
extern char g_021A75F0[];
extern struct qr2_implementation_s * current_rec;
extern char g_021A760C[];
extern char g_021A7644[];

void qr2_send_statechanged(struct qr2_implementation_s *qrec)
{
    gsDebugFormat(3, 4, 0x40, g_021A75F0);
    if (qrec == 0)
        qrec = current_rec;
    if (qrec->f_c4 == 0) {
        gsDebugFormat(3, 4, 4, g_021A760C);
        return;
    }
    if (current_time() - qrec->f_b4 < 0x2710) {
        gsDebugFormat(3, 4, 8, g_021A7644);
        qrec->f_bc = 1;
        return;
    }
    send_heartbeat(qrec, 1);
    qrec->f_bc = 0;
}
