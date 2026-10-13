/*
 * function: func_021BE0C4
 * address:  0x021BE0C4
 * packet:   pkt_021BE0C4
 * region:   ov203
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
#include "../include/Obj25312.h"

typedef unsigned int   u32;
struct Bank;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(int);
extern void MI_CpuFill8(void *, int, int);

void func_021BE0C4(char *a)
{
    CLACT_ExitSystem(CLACT_DeleteUnit((struct Bank *)(((struct Obj25312 *)a)->f0)));
    MI_CpuFill8(a, 0, 4);
}