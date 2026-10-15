/*
 * function: SHINKA_DEMO_GRAPHIC_ExitClact
 * address:  0x02205BAC
 * packet:   pkt_02205BAC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj24953.h"

typedef unsigned int   u32;
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(int);
extern void MI_CpuFill8(void *, int, int);

void SHINKA_DEMO_GRAPHIC_ExitClact(char *a)
{
    CLACT_ExitSystem(CLACT_DeleteUnit((struct Bank *)(((struct Obj24953 *)a)->f0)));
    MI_CpuFill8(a, 0, 4);
}