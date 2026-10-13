/*
 * function: C_GEAR_StepIdle
 * address: 0x021F2180
 * packet: pkt_ov029_021F2180
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   C_GEAR_IsIdleForInput 0x021F0D48 thumb ov029
 *   C_GEAR_RunFrame 0x021F2130 thumb ov029
 */
#include "../include/Obj00042.h"
extern int C_GEAR_IsIdleForInput(char *p);
extern void C_GEAR_RunFrame(char *p);
void C_GEAR_StepIdle(char *p)
{
    if (*(void (**)(void *))(p + 0x1fc) != 0)
        (*(void (**)(void *))(p + 0x1fc))(((struct Obj00042 *)p)->f200);
    *(void (**)(void *))(p + 0x1fc) = 0;
    ((struct Obj00042 *)p)->f200 = 0;
    if (C_GEAR_IsIdleForInput(p))
        C_GEAR_RunFrame(p);
}
