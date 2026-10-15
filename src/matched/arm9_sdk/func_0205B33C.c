/*
 * function: DWCi_AC_ConnectAP
 * address:  0x0205B33C
 * packet:   pkt_0205B33C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_ConnectAP (connect.o)
 *
 * symbols:
 *   DWCi_AC_GetPhase 0x0205C2C4 arm
 *   DWCi_AC_GetMemPtr 0x0205C214 arm
 *   ConnectStart 0x0205B37C arm
 *   ConnectAP 0x0205B488 arm
 */

typedef struct ACWORK ACWORK;

extern unsigned char DWCi_AC_GetPhase(void);
extern void *DWCi_AC_GetMemPtr(unsigned long name);
extern unsigned char ConnectStart(ACWORK *wk);
extern unsigned char ConnectAP(ACWORK *wk);

unsigned char DWCi_AC_ConnectAP(void)
{
    ACWORK *wk;
    unsigned char phase;

    phase = DWCi_AC_GetPhase();
    wk = DWCi_AC_GetMemPtr(0x10);
    switch (phase) {
    case 7:
        phase = ConnectStart(wk);
        break;
    case 8:
        phase = ConnectAP(wk);
        break;
    }
    return phase;
}
