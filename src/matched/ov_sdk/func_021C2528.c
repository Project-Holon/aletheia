/*
 * function: func_021C2528
 * address:  0x021C2528
 * packet:   pkt_021C2528
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C2528   0x021C2528  arm
 *   OS_SpinWaitSysCycles  0x02087A04  arm  arm9
 *   PM_ForceToPowerOff  0x0208BEA4  arm  arm9
 *   DWCi_EFFlCheck  0x021D5580  arm
 *
 * Bail out on two DWCi_EFFlCheck probes, then arm timer 0x800000 and kick PM_ForceToPowerOff.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C2528.c \
 *       --func func_021C2528 --addr 0x021C2528 --region ov016 --cc dsi/1.1p1 --arm
 */

extern int DWCi_EFFlCheck(int);
extern void OS_SpinWaitSysCycles(int);
extern void PM_ForceToPowerOff(void);

void func_021C2528(void)
{
    if (DWCi_EFFlCheck(1))
        return;
    if (DWCi_EFFlCheck(0))
        return;
    OS_SpinWaitSysCycles(0x800000);
    PM_ForceToPowerOff();
}
