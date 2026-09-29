/*
 * function: func_021D6BC8
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
 *   func_02087AE4  0x02087AE4  arm
 *   func_0207D46C  0x0207D46C  arm
 *   func_0207D42C  0x0207D42C  arm
 *   g_021DE688     0x021DE688  data
 */

extern int PM_SetLCDPower(int sw);
extern void func_02087AE4(void);
extern void func_0207D46C(void);
extern void func_0207D42C(void);
extern unsigned char g_021DE688;

void func_021D6BC8(void)
{
    if (g_021DE688) {
        if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
            return;
        if (PM_SetLCDPower(1)) {
            func_02087AE4();
            func_0207D46C();
            *(volatile unsigned int *)0x04001000 |= 0x10000;
            func_02087AE4();
            g_021DE688 = 0;
        }
    } else {
        if (!((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15))
            return;
        func_02087AE4();
        func_0207D42C();
        *(volatile unsigned int *)0x04001000 &= ~0x10000;
        func_02087AE4();
        if (PM_SetLCDPower(0))
            g_021DE688 = 1;
    }
}
