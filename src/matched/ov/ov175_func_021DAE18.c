/*
 * function: func_021DAE18
 * address:  0x021DAE18
 * packet:   pkt_021DAE18
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_ScDestroyReport  0x021DF458  arm
 *   DWC_ScShutdown       0x021DEF58  arm
 *
 * Report teardown: when the state word at +0x170 is 1, destroys the report once the +0x12c step is past 0x13, shuts the storage client down once the +0x12c step is 4 or more, and clears the state word.
 */
#include "../include/Obj03320.h"
#include "../include/Obj24331.h"

typedef unsigned char u8;
typedef unsigned long u32;

extern void DWC_ScDestroyReport(u32 report);
extern void DWC_ScShutdown(void);

void func_021DAE18(char *obj)
{
    if (((struct Obj03320 *)obj)->f170 == 1) {
        if (((struct Obj03320 *)obj)->f12C > 0x13)
            DWC_ScDestroyReport(((struct Obj24331 *)(*(char * *)&((struct Obj03320 *)obj)->f1464))->f8);
        if (((struct Obj03320 *)obj)->f12C >= 4)
            DWC_ScShutdown();
        ((struct Obj03320 *)obj)->f170 = 0;
    }
}
