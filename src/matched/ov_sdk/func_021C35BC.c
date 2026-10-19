/*
 * function: endScene2
 * address:  0x021C35BC
 * packet:   pkt_021C2528
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   endScene2   0x021C35BC  arm
 *   OS_SpinWaitSysCycles  0x02087A04  arm  arm9
 *   PM_ForceToPowerOff  0x0208BEA4  arm  arm9
 *   DWCi_EFFlCheck  0x021D5580  arm
 *
 * Bail out on two DWCi_EFFlCheck probes, then arm timer 0x800000 and kick PM_ForceToPowerOff.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/endScene2.c \
 *       --func endScene2 --addr 0x021C35BC --region ov016 --cc dsi/1.1p1 --arm
 */

extern int DWCi_EFFlCheck(int);
extern void OS_SpinWaitSysCycles(int);
extern void PM_ForceToPowerOff(void);

void endScene2(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    OS_SpinWaitSysCycles(0x800000);
    PM_ForceToPowerOff();
}
