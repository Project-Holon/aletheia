/*
 * function: func_021BCB70
 * address:  0x021BCB70
 * packet:   pkt_021BCB70
 * region:   ov216
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8   0x02082BCC arm
 */
#include "../include/Obj14717.h"

extern void CLACT_DeleteRenderer(void *);
struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *, int, int);

void func_021BCB70(char *p)
{
    CLACT_DeleteRenderer(((struct Obj14717 *)p)->f4);
    CLACT_DeleteUnit(((struct Obj14717 *)p)->f0);
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 8);
}
