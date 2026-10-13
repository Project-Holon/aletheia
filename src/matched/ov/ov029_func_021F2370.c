/*
 * function: C_GEAR_StepClose
 * address:  0x021F2370
 * packet:   pkt_ov029_021F2370
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_StartFlashFade  0x021F0E70  thumb  ov029
 *   C_GEAR_SetAllActorsVisible  0x021F1A64  thumb  ov029
 *   C_GEAR_SetTileMarkersVisible  0x021F1A44  thumb  ov029
 *   C_GEAR_DeleteSplashActors  0x021F1BBC  thumb  ov029
 *   C_GEAR_DrawEmptyBoard  0x021F1010  thumb  ov029
 *   C_GEAR_ResetTabPalettes  0x021F0370  thumb  ov029
 *   C_GEAR_ChangeStep  0x021EFEF8  thumb  ov029
 *   C_GEAR_StepIntroEnd  0x021F21B4  thumb  ov029
 */
#include "../include/Obj00106.h"

extern void C_GEAR_StartFlashFade(char *p);
extern void C_GEAR_SetAllActorsVisible(char *p, int a);
extern void C_GEAR_SetTileMarkersVisible(char *p, int a);
extern void C_GEAR_DeleteSplashActors(char *p);
extern void C_GEAR_DrawEmptyBoard(void *p);
extern void C_GEAR_ResetTabPalettes(void *p);
extern void C_GEAR_ChangeStep(char *p, void (*f)(void), int a);
extern void C_GEAR_StepIntroEnd(char *p);

void C_GEAR_StepClose(char *p)
{
    if (((struct Obj00106 *)p)->f456 == 0) {
        C_GEAR_StartFlashFade(p);
        C_GEAR_SetAllActorsVisible(p, 1);
        C_GEAR_SetTileMarkersVisible(p, 0);
        C_GEAR_DeleteSplashActors(p);
        C_GEAR_DrawEmptyBoard(p);
        C_GEAR_ResetTabPalettes(p);
    }
    ((struct Obj00106 *)p)->f456 += 1;
    if (((struct Obj00106 *)p)->f456 >= 0x10) {
        ((struct Obj00106 *)p)->f456 = 0;
        C_GEAR_ChangeStep(p, (void (*)(void))C_GEAR_StepIntroEnd, 0x1041);
    }
}
