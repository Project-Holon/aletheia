/*
 * function: func_0205B33C
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
 *   func_0205B37C 0x0205B37C arm
 *   func_0205B488 0x0205B488 arm
 */

typedef struct ACWORK ACWORK;

extern unsigned char DWCi_AC_GetPhase(void);
extern void *DWCi_AC_GetMemPtr(unsigned long name);
extern unsigned char func_0205B37C(ACWORK *wk);
extern unsigned char func_0205B488(ACWORK *wk);

unsigned char func_0205B33C(void)
{
    ACWORK *wk;
    unsigned char phase;

    phase = DWCi_AC_GetPhase();
    wk = DWCi_AC_GetMemPtr(0x10);
    switch (phase) {
    case 7:
        phase = func_0205B37C(wk);
        break;
    case 8:
        phase = func_0205B488(wk);
        break;
    }
    return phase;
}
