/*
 * function: MBPi_CheckAllReboot
 * address:  0x021D2420
 * packet:   pkt_021D2420
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MBPi_CheckAllReboot 0x021D2420 arm
 *   DWCi_DwcMoveidMB_EndToIdle  0x021F5F74  arm
 *
 * Guard on the kind and the paired words of the object at 0x021DE65C.
 * Addresses are Black-image addresses.
 */

extern void DWCi_DwcMoveidMB_EndToIdle(void);

void MBPi_CheckAllReboot(void)
{
    unsigned short *p = *(unsigned short **)0x021DE65C;

    if (p[0] != 4)
        return;
    if (p[1] != p[6])
        return;
    DWCi_DwcMoveidMB_EndToIdle();
}
