/*
 * function: C_GEAR_StepIntroEnd
 * address:  0x021F21B4
 * packet:   pkt_ov029_021F21B4
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   C_GEAR_StepIntroTiles  0x021F1060  thumb  ov029
 *   C_GEAR_InitTabTimersPowerOff  0x021F0300  thumb  ov029
 *   C_GEAR_ChangeStep  0x021EFEF8  thumb  ov029
 *   C_GEAR_StepIdle  0x021F2180  thumb  ov029
 */
#include "../include/Obj00042.h"

typedef unsigned char  u8;
extern int C_GEAR_StepIntroTiles(u8 *p);
extern void C_GEAR_InitTabTimersPowerOff(u8 *p);
extern void C_GEAR_ChangeStep(char *p, void (*f)(void), int line);
extern void C_GEAR_StepIdle(char *p);

void C_GEAR_StepIntroEnd(char *p)
{
    void (*f)(int);

    if (C_GEAR_StepIntroTiles((u8 *)p) == 0) {
        f = *(void (**)(int))(p + 0x1fc);
        if (f)
            f(*(int *)&((struct Obj00042 *)p)->f200);
        *(int *)&((struct Obj00042 *)p)->f1FC = 0;
        *(int *)&((struct Obj00042 *)p)->f200 = 0;
        return;
    }
    C_GEAR_InitTabTimersPowerOff((u8 *)p);
    C_GEAR_ChangeStep(p, (void *)C_GEAR_StepIdle, 0xF92);
}
