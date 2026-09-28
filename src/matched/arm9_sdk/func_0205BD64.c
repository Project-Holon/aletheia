/*
 * function: func_0205BD64
 * address:  0x0205BD64
 * packet:   pkt_0205BD64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_AC_GetStatus (dwc_ac.o)
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef unsigned long long u64;
typedef int BOOL;

extern u8 DWCi_AC_GetPhase(void);
extern int DWCi_AC_GetResult(void);

int func_0205BD64(void)
{
    u8 phase = DWCi_AC_GetPhase();

    if (phase <= 1) return 0;
    if (phase < 7) return 1;
    if (phase == 9) return 4;
    if (phase < 0xa) return 2;
    if (phase == 0xb) return 4;
    if (phase < 0x10) return 3;
    if (phase == 0x10) return 5;
    if (phase == 0x11) return 4;
    return DWCi_AC_GetResult();
}
