/*
 * function: procCancel
 * address:  0x021C4E98
 * packet:   pkt_021C4E98
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   procCancel 0x021C4E98 arm
 *   DWCi_ChangeScene  0x021C0E40  arm
 *   DWCi_SNDlPlay  0x021CFFAC  arm
 *   DWCi_SNDlStop  0x021D0014  arm
 *
 * Tear down the sequence and post the event at 0x021C4C60.
 * Addresses are Black-image addresses.
 */

extern void DWCi_SNDlStop(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);

void procCancel(void)
{
    DWCi_SNDlStop();
    DWCi_SNDlPlay(7);
    *(unsigned char *)0x021DE5CC = 0;
    DWCi_ChangeScene((unsigned int)((void *)0x021C4C60));
}
