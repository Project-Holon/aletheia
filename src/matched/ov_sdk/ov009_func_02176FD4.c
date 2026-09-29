/*
 * function: func_02176FD4
 * address:  0x02176FD4
 * packet:   pkt_ov009_02176FD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_SendReliableBitmap (dwc_transport.o)
 *
 * Closed (w5_nm): the bit is the conditional expression
 * `(aid != 0) ? (1 << aid) : 1`, which keeps the two constant 1s in separate
 * registers (r7 for the zero case, r8 for the shift); the statement form with
 * a later `if (aid == 0) aidbit = 1;` shared one register.
 *
 * symbols:
 *   DWC_GetMyAID                   0x0216B838  arm ov009
 *   DWC_SendReliable               0x02176E90  arm ov009
 */

extern unsigned char DWC_GetMyAID(void);
extern int DWC_SendReliable(unsigned char aid, void *buffer, int size);

unsigned long func_02176FD4(unsigned long bitmap, void *buffer, int size)
{
    unsigned long aidbit;
    unsigned char aid;

    for (aid = 0; aid < 32; aid++) {
        aidbit = (aid != 0) ? (1 << aid) : 1;
        if ((bitmap & aidbit) == 0)
            continue;
        if (aid == DWC_GetMyAID())
            continue;
        if (DWC_SendReliable(aid, buffer, size) == 0)
            bitmap &= ~aidbit;
    }
    return bitmap;
}
