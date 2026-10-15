/*
 * function: DWCi_AC_Error
 * address:  0x0205D0E4
 * packet:   pkt_0205D0E4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_AC_Error (error.o)
 *
 * symbols:
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   DWCi_AC_CloseNetwork             0x0205b1e4 arm
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

extern void *DWCi_AC_GetMemPtr(unsigned long name);

extern int DWCi_AC_CloseNetwork(unsigned char *phase);

unsigned char DWCi_AC_Error(void)
{
    tagACHOLD *hd = (tagACHOLD *)DWCi_AC_GetMemPtr(1);

    if (DWCi_AC_CloseNetwork(&hd->phaseError) == 1) {
        return 0x12;
    }
    return 0x11;
}
