/*
 * function: DWCi_IPTlCheckFold
 * address:  0x021D6BC8
 * packet:   pkt_ov016_021D6BC8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_IPTlCheckFold (libdwcutil.TWL.HYB.a input.o)
 *
 * symbols:
 *   PM_SetLCDPower 0x0208C64C  arm
 *   OS_WaitVBlankIntr  0x02087AE4  arm
 *   GX_DispOn  0x0207D46C  arm
 *   GX_DispOff  0x0207D42C  arm
 *   gInputStatics     0x021DE688  data
 */

extern int PM_SetLCDPower(int sw);
extern void OS_WaitVBlankIntr(void);
extern void GX_DispOn(void);
extern void GX_DispOff(void);
extern unsigned char gInputStatics;

void DWCi_IPTlCheckFold(void)
{
    if (gInputStatics) {
        if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
            return;
        if (PM_SetLCDPower(1)) {
            OS_WaitVBlankIntr();
            GX_DispOn();
            *(volatile unsigned int *)0x04001000 |= 0x10000;
            OS_WaitVBlankIntr();
            gInputStatics = 0;
        }
    } else {
        if (!((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15))
            return;
        OS_WaitVBlankIntr();
        GX_DispOff();
        *(volatile unsigned int *)0x04001000 &= ~0x10000;
        OS_WaitVBlankIntr();
        if (PM_SetLCDPower(0))
            gInputStatics = 1;
    }
}
