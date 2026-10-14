/*
 * function: BR_GRAPHIC_ExitActors
 * address:  0x021FC5E0
 * packet:   pkt_021FC5E0
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   MI_CpuFill8  0x02082BCC  arm
 */
#include "../include/Obj24836.h"

struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *, int, int);

void BR_GRAPHIC_ExitActors(void *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj24836 *)p)->f0));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}
