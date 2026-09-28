/*
 * function: DWC_AC_GetStatus
 * address:  0x0205BD64
 * packet:   pkt_0205A2DC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * TwlDWC libdwcac dwc_ac.o.
 */
extern unsigned char DWCi_AC_GetPhase(void);
extern int DWCi_AC_GetResult(void);

int func_0205BD64(void)
{
    unsigned char phase = DWCi_AC_GetPhase();

    if (phase <= 1) return 0;
    if (phase < 7) return 1;
    if (phase == 9) return 4;
    if (phase < 10) return 2;
    if (phase == 11) return 4;
    if (phase < 16) return 3;
    if (phase == 16) return 5;
    if (phase == 17) return 4;
    return DWCi_AC_GetResult();
}
