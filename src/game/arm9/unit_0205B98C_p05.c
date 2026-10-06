/*
 * file:     unit_0205B98C_p05.c
 * unit:     yes
 * function: func_0205C2E4, func_0205C308
 * address:  0x0205C2E4
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   DWCi_AC_GetMemPtr                0x0205c214 arm
 *   DWCi_AC_GetPhase                 0x0205c2c4 arm
 *   s_ac_work  0x02146AC0  data  a4
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

typedef struct {
    unsigned char pad[12];
    void *fieldC;
} ACWORK;

extern void *func_0205C214(unsigned long name);
extern unsigned char DWCi_AC_GetPhase(void);
void func_0205C2E4(int error);
int DWCi_AC_GetError(void);


/*
 * sdk:      DWCi_AC_SetError (dwc_ac.o)
 */
void func_0205C2E4(int error)
{
    tagACHOLD *hd = (tagACHOLD *)func_0205C214(1);

    hd->error = error;
    hd->phaseError = DWCi_AC_GetPhase();
}


static ACWORK s_ac_work;


int DWCi_AC_GetError(void)
{
    return *(int *)((char *)s_ac_work.fieldC + 12);
}
