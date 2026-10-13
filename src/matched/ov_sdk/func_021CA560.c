/*
 * function: func_021CA560
 * address:  0x021CA560
 * packet:   pkt_021CA560
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021CA560   0x021CA560  arm
 *   DWCi_WINlGet   0x021D1568  arm
 *   DWCi_SNDlPlay   0x021CFFAC  arm
 *   DWCi_WINlEnd   0x021D1524  arm
 *   DWCi_SCREENlSetPalette   0x021CE818  arm
 *   DWCi_ChangeScene   0x021C0E40  arm
 *
 * Gate on the driver state, then reset the shared block and hand the next state off.
 * Addresses are Black-image addresses.
 */

extern signed char DWCi_WINlGet(void);
extern void DWCi_SNDlPlay(unsigned int v);
extern void DWCi_WINlEnd(void);
extern void DWCi_SCREENlSetPalette(unsigned int v);
extern void DWCi_ChangeScene(unsigned int v);

void func_021CA560(void)
{
    unsigned char *g = (unsigned char *)0x021DE5EC;

    if (DWCi_WINlGet() != 0)
        return;
    DWCi_SNDlPlay(6);
    DWCi_WINlEnd();
    DWCi_SCREENlSetPalette(*(int *)(*(int *)(g + 8) + 0xc));
    DWCi_ChangeScene(0x021CA5A0);
}

