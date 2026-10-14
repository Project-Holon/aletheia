/*
 * function: ZUKAN_DETAIL_GRAPHIC_ExitActorSystem
 * address:  0x021BD07C
 * packet:   pkt_021BD07C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *   (none)
 *
 * Calls the ARM9 functions at 0x0204B1CC and 0x0204A5AC, then 0x02082BCC(p, 0, 4).
 */
#include "../include/Obj18205.h"

struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *, int, int);

void ZUKAN_DETAIL_GRAPHIC_ExitActorSystem(char *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj18205 *)p)->f0));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}
