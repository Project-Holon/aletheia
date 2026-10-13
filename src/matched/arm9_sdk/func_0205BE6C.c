/*
 * function: DWC_AC_Destroy
 * address:  0x0205BE6C
 * packet:   pkt_0205BE6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_AC_Destroy (dwc_ac.o)
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef long s32;
typedef unsigned long long u64;
typedef int BOOL;

extern u8 DWCi_AC_GetPhase(void);
extern void DWCi_AC_FreeAll(void);
extern int DWCi_AC_CloseNetwork(u8 *phase);
extern void DWCi_AC_SetPhase(u8 phase);

BOOL DWC_AC_Destroy(void)
{
    u8 phase = DWCi_AC_GetPhase();

    if (phase == 0 || phase == 0x12) {
        DWCi_AC_FreeAll();
        return 1;
    }
    DWCi_AC_CloseNetwork(&phase);
    DWCi_AC_SetPhase(phase);
    return 0;
}
