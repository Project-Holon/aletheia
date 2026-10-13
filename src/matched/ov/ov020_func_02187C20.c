/*
 * function: EL_SCOREBOARD_EnterState
 * address:  0x02187C20
 * packet:   pkt_ov020_02187C20
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EL_SCOREBOARD_SetupDisplay  0x02187860  thumb  ov020
 *   func_0202E8A4  0x0202E8A4  thumb
 *   EL_SCOREBOARD_LoadSeasonGraphics  0x0218794C  thumb  ov020
 *   func_02040588  0x02040588  arm
 *   func_0207D534  0x0207D534  arm
 *   func_0207D658  0x0207D658  arm
 *   EL_SCOREBOARD_GetFadeInDuration  0x02187D40  thumb  ov020
 *   EL_SCOREBOARD_GetHoldDuration  0x02187D74  thumb  ov020
 *   EL_SCOREBOARD_GetFadeOutDuration  0x02187D54  thumb  ov020
 *   EL_SCOREBOARD_GetMode  0x02187D20  thumb  ov020
 *   FIELDMAP_ResetBgAffineShowMsg  0x02188DB0  thumb  ov021
 *   EL_SCOREBOARD_CallFinishCallback  0x02187D94  thumb  ov020
 */
#include "../include/Obj01207.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef signed int     s32;
typedef unsigned int   u32;
void EL_SCOREBOARD_SetupDisplay(char *p);
u8 func_0202E8A4(u8 x);
void EL_SCOREBOARD_LoadSeasonGraphics(int a, int b);
void func_02040588(unsigned char which, unsigned char enable);
void func_0207D534(volatile u16 *reg, int brightness);
void func_0207D658(u32 addr, int plane, int brightness);
int EL_SCOREBOARD_GetFadeInDuration(char *p);
int EL_SCOREBOARD_GetHoldDuration(char *p);
int EL_SCOREBOARD_GetFadeOutDuration(char *p);
u32 EL_SCOREBOARD_GetMode(char *p);
void FIELDMAP_ResetBgAffineShowMsg(u8 *a);
void EL_SCOREBOARD_CallFinishCallback(void *o);

void EL_SCOREBOARD_EnterState(char *o, int *p, int st)
{
    switch (st) {
    case 0:
        EL_SCOREBOARD_SetupDisplay(o);
        break;
    case 1:
        ((struct Obj01207 *)o)->f15 = func_0202E8A4(((struct Obj01207 *)o)->f15);
        EL_SCOREBOARD_LoadSeasonGraphics(((struct Obj01207 *)o)->f15, ((struct Obj01207 *)o)->f8);
        break;
    case 2:
        func_02040588(3, 1);
        func_02040588(0, 0);
        func_0207D534((volatile u16 *)0x0400006C, 0);
        func_0207D658(0x04000050, 8, -16);
        ((struct Obj01207 *)o)->f1C = EL_SCOREBOARD_GetFadeInDuration(o);
        break;
    case 3:
        ((struct Obj01207 *)o)->f1C = EL_SCOREBOARD_GetHoldDuration(o);
        break;
    case 4:
        ((struct Obj01207 *)o)->f1C = EL_SCOREBOARD_GetFadeOutDuration(o);
        if (EL_SCOREBOARD_GetMode(o) == 0 && ((struct Obj01207 *)o)->f15 == ((struct Obj01207 *)o)->f14) {
            FIELDMAP_ResetBgAffineShowMsg((u8 *)(((struct Obj01207 *)o)->f4));
            func_02040588(3, 1);
            EL_SCOREBOARD_CallFinishCallback(o);
        }
        break;
    case 5:
        break;
    }
    *p = st;
    *(int *)&((struct Obj01207 *)o)->f18 = 0;
}
