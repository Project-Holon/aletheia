/*
 * function: C_GEAR_OnCommDisconnect
 * address:  0x021F24C0
 * packet:   pkt_ov029_021F24C0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_StopFade  0x021F0FF0  thumb  ov029
 *   C_GEAR_StartFlashFade  0x021F0E70  thumb  ov029
 *   C_GEAR_DrawEmptyBoard  0x021F1010  thumb  ov029
 *   TCB_Main  0x02030D28  arm
 */
#include "../include/Obj00106.h"

extern void C_GEAR_StopFade(char *p);
extern void C_GEAR_StartFlashFade(char *p);
extern void C_GEAR_DrawEmptyBoard(void *p);
struct Ctx;
extern void TCB_Main(struct Ctx *c);

void C_GEAR_OnCommDisconnect(char *p)
{
    C_GEAR_StopFade(p);
    if (*(int *)&((struct Obj00106 *)p)->f204 != 0)
        TCB_Main((struct Ctx *)(*(int *)&((struct Obj00106 *)p)->f204));
    C_GEAR_StartFlashFade(p);
    C_GEAR_DrawEmptyBoard(p);
    if (*(int *)&((struct Obj00106 *)p)->f204 != 0)
        TCB_Main((struct Ctx *)(*(int *)&((struct Obj00106 *)p)->f204));
    ((struct Obj00106 *)p)->f451 = 1;
}
