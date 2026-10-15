/*
 * function: WIFIBATTLEMATCH_SYS_HandleStartCommand
 * address: 0x0221303C
 * packet: pkt_ov199_0221303C
 * region: ov199
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   WIFIBATTLEMATCH_SYS_SetStep 0x02213808 thumb ov199
 *   WIFIBATTLEMATCH_SYS_SetStepDone 0x0221380C thumb ov199
 */
#include "../include/Obj14575.h"
#include "../include/Obj25293.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void WIFIBATTLEMATCH_SYS_SetStep(char *, int);
extern void WIFIBATTLEMATCH_SYS_SetStepDone(unsigned char *p);
int WIFIBATTLEMATCH_SYS_HandleStartCommand(char *p, char *q, char *work)
{
    int mode = ((struct Obj25293 *)q)->f1C;
    func_020307B0(q);
    switch (mode) {
    case 0:
        ((struct Obj14575 *)work)->f20 = 0;
        WIFIBATTLEMATCH_SYS_SetStep(p, 1);
        break;
    case 1:
        if (((struct Obj14575 *)work)->fC == 0) WIFIBATTLEMATCH_SYS_SetStep(p, 0);
        else WIFIBATTLEMATCH_SYS_SetStepDone((unsigned char *)p);
        break;
    }
    return 1;
}
