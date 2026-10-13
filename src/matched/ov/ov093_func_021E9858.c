/*
 * function: BTLV_CORE_ReopenMoveMenu
 * address:  0x021E9858
 * packet:   pkt_ov093_021E9858
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9874  0x021E9874  thumb  ov093
 *   BTLV_CORE_SetStep  0x021E9728  thumb  ov093
 *   BTLV_CORE_StepMoveMenu  0x021E9884  thumb  ov093
 */
#include "../include/Obj21554.h"
typedef unsigned int u32;

extern void func_021E9874(void *p);
struct QU;
extern void BTLV_CORE_SetStep(struct QU *p, u32 v);
extern int BTLV_CORE_StepMoveMenu(void *p);

void BTLV_CORE_ReopenMoveMenu(char *p)
{
    func_021E9874(((struct Obj21554 *)p)->f180);
    BTLV_CORE_SetStep((struct QU *)p, (u32)BTLV_CORE_StepMoveMenu);
}
