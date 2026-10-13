/*
 * function: C_GEAR_StepOpen
 * address:  0x021F21F8
 * packet:   pkt_ov029_021F21F8
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   C_GEAR_DrawEmptyBoard  0x021F1010  thumb  ov029
 *   C_GEAR_ResetTabPalettes  0x021F0370  thumb  ov029
 *   C_GEAR_SetAllActorsVisible  0x021F1A64  thumb  ov029
 *   C_GEAR_IsIdleForInput  0x021F0D48  thumb  ov029
 *   C_GEAR_CreateSplashActors  0x021F1B50  thumb  ov029
 *   C_GEAR_SetSplashActorsVisible  0x021F1B30  thumb  ov029
 *   C_GEAR_IsSplashDone  0x021F1BE4  thumb  ov029
 *   C_GEAR_StartFadeOut  0x021F0F70  thumb  ov029
 *   func_021F2BF0  0x021F2BF0  thumb  ov029
 *   C_GEAR_StopFade  0x021F0FF0  thumb  ov029
 *   C_GEAR_DeleteSplashActors  0x021F1BBC  thumb  ov029
 *   C_GEAR_StartFlashFade  0x021F0E70  thumb  ov029
 *   C_GEAR_StepOutroTiles  0x021F11B4  thumb  ov029
 *   C_GEAR_ResetAllTiles  0x021F122C  thumb  ov029
 *   C_GEAR_SetTileMarkersVisible  0x021F1A44  thumb  ov029
 *   C_GEAR_ChangeStep  0x021EFEF8  thumb  ov029
 *   C_GEAR_StepIntroEnd  0x021F21B4  thumb  ov029
 *   C_GEAR_StopTileFlashes  0x021F0AA0  thumb  ov029
 */
#include "../include/Obj00106.h"

typedef unsigned char u8;

extern void C_GEAR_DrawEmptyBoard(void *p);
extern void C_GEAR_ResetTabPalettes(void *p);
extern void C_GEAR_SetAllActorsVisible(char *p, int a);
extern int C_GEAR_IsIdleForInput(char *p);
extern void C_GEAR_CreateSplashActors(char *p);
extern void C_GEAR_SetSplashActorsVisible(char *p, int a);
extern int C_GEAR_IsSplashDone(char *p);
extern void C_GEAR_StartFadeOut(char *p);
extern int func_021F2BF0(char *p);
extern void C_GEAR_StopFade(char *p);
extern void C_GEAR_DeleteSplashActors(char *p);
extern void C_GEAR_StartFlashFade(char *p);
extern int C_GEAR_StepOutroTiles(char *p);
extern void C_GEAR_ResetAllTiles(char *p);
extern void C_GEAR_SetTileMarkersVisible(char *p, int a);
extern void C_GEAR_ChangeStep(char *p, void (*f)(void), int a);
extern void C_GEAR_StepIntroEnd(char *p);
extern void C_GEAR_StopTileFlashes(char *p);

void C_GEAR_StepOpen(char *p)
{
    switch (((struct Obj00106 *)p)->f455) {
    case 0:
        C_GEAR_DrawEmptyBoard(p);
        C_GEAR_ResetTabPalettes(p);
        C_GEAR_SetAllActorsVisible(p, 0);
        (((struct Obj00106 *)p)->f455)++;
        return;
    case 1:
        if (C_GEAR_IsIdleForInput(p)) {
            C_GEAR_CreateSplashActors(p);
            C_GEAR_SetSplashActorsVisible(p, 1);
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 2:
        if (C_GEAR_IsSplashDone(p)) {
            C_GEAR_StartFadeOut(p);
            ((struct Obj00106 *)p)->f456 = 0;
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 3:
        if (func_021F2BF0(p)) {
            C_GEAR_StopFade(p);
            ((struct Obj00106 *)p)->f455 = 7;
            return;
        }
        if (((struct Obj00106 *)p)->f456 < 8) {
            (((struct Obj00106 *)p)->f456)++;
            return;
        }
        C_GEAR_SetSplashActorsVisible(p, 0);
        C_GEAR_DeleteSplashActors(p);
        C_GEAR_StartFlashFade(p);
        (((struct Obj00106 *)p)->f455)++;
        ((struct Obj00106 *)p)->f456 = 0;
        return;
    case 4:
        if (func_021F2BF0(p)) {
            ((struct Obj00106 *)p)->f455 = 7;
            return;
        }
        if (C_GEAR_StepOutroTiles(p) == 1) {
            ((struct Obj00106 *)p)->f456 = 0;
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 5:
        if (func_021F2BF0(p)) {
            ((struct Obj00106 *)p)->f455 = 7;
            return;
        }
        (((struct Obj00106 *)p)->f456)++;
        if (((struct Obj00106 *)p)->f456 >= 8) {
            C_GEAR_ResetAllTiles(p);
            ((struct Obj00106 *)p)->f456 = 0;
            (((struct Obj00106 *)p)->f455)++;
            return;
        }
        break;
    case 6:
        (((struct Obj00106 *)p)->f456)++;
        if (((struct Obj00106 *)p)->f456 >= 8) {
            C_GEAR_SetAllActorsVisible(p, 1);
            C_GEAR_SetTileMarkersVisible(p, 0);
            C_GEAR_ChangeStep(p, (void (*)(void))C_GEAR_StepIntroEnd, 0x100b);
            return;
        }
        break;
    case 7:
        C_GEAR_DeleteSplashActors(p);
        C_GEAR_StartFlashFade(p);
        C_GEAR_StopTileFlashes(p);
        C_GEAR_ResetAllTiles(p);
        ((struct Obj00106 *)p)->f456 = 8;
        ((struct Obj00106 *)p)->f455 = 6;
        break;
    }
}
