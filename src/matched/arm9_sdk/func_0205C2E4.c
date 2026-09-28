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
 *
 * symbols:
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   DWCi_AC_GetPhase                 0x0205c2c4 arm
 */

typedef struct tagACHOLD {
    void *(*alloc)(unsigned long, long);
    void (*free)(unsigned long, void *, long);
    unsigned char allocState;
    unsigned char phase;
    unsigned char phaseError;
    unsigned char findAP : 4;
    unsigned char ipCollision : 4;
    int error;
    int errorTest;
} tagACHOLD;

extern void *func_0205C214(unsigned long name);

extern unsigned char DWCi_AC_GetPhase(void);

void func_0205C2E4(int error)
{
    tagACHOLD *hd = (tagACHOLD *)func_0205C214(1);

    hd->error = error;
    hd->phaseError = DWCi_AC_GetPhase();
}
