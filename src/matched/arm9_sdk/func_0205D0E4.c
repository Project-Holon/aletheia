/*
 * function: func_0205D0E4
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

extern void *func_0205C214(unsigned long name);

extern int func_0205B1E4(unsigned char *phase);

unsigned char func_0205D0E4(void)
{
    tagACHOLD *hd = (tagACHOLD *)func_0205C214(1);

    if (func_0205B1E4(&hd->phaseError) == 1) {
        return 0x12;
    }
    return 0x11;
}
