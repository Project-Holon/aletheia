/*
 * function: func_0205C2E4
 * address:  0x0205C2E4
 * packet:   pkt_0205C2E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_SetError (dwc_ac.o)
 */

typedef unsigned char u8;

typedef struct {
    u8 pad[0xa];
    u8 phase;
    u8 phaseError;
    int error;
} ACHOLD;

extern ACHOLD *DWCi_AC_GetMemPtr(int name);
extern u8 DWCi_AC_GetPhase(void);

void func_0205C2E4(int error)
{
    ACHOLD *hd = DWCi_AC_GetMemPtr(1);
    hd->error = error;
    hd->phase = DWCi_AC_GetPhase();
}

