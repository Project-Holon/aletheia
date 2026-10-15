/*
 * function: SUBWAY_MAP_GRAPHIC_DeleteClactUnit
 * address:  0x021B9B50
 * packet:   pkt_021B9B50
 * region:   ov224
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26111.h"

struct Bank;
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void MI_CpuFill8(void *, int, int);

void SUBWAY_MAP_GRAPHIC_DeleteClactUnit(char *p)
{
    CLACT_DeleteUnit((struct Bank *)(((struct Obj26111 *)p)->f0));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}
