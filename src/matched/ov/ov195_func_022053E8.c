/*
 * function: SHINKA_DEMO_AdvanceText
 * address:  0x022053E8
 * packet:   pkt_022053E8
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   KEY_GetCont  0x0203630C  arm
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   TOUCHPANEL_GetTrg  0x02035C60  arm
 *   UI_SetInputMode  0x020355D8  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   PRINTSYS_PrintStreamGetState  0x0201CE30  thumb  arm9
 *   PRINTSYS_PrintStreamReleasePause  0x0201CE38  thumb  arm9
 *   PRINTSYS_PrintStreamShortWait  0x0201CE5C  thumb  arm9
 *
 * The `(x & 3) != 0 ? 0 : 1` call arguments must be written as an explicit
 * if/else. The ternary makes mwccarm pick the opposite branch polarity and
 * then colour the pointer r5/result r4 the other way; the if/else gives the
 * original pointer r4 / result r5 split and the shared return. See
 * docs/idioms/a-ternary-constant-call-argument-takes-the-opposite-branch-polarity.md.
 */
#include "../include/Obj10819.h"

typedef unsigned int u32;

typedef signed int     s32;
struct Rec;
extern u32 PRINTSYS_PrintStreamGetState(void *p);
extern void PRINTSYS_PrintStreamShortWait(struct Rec *p, s32 v);
extern void PRINTSYS_PrintStreamReleasePause(void *p);
typedef unsigned char  u8;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern u32 KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern void UI_SetInputMode(u8 v);

int SHINKA_DEMO_AdvanceText(char *a)
{
    int r = 0;

    switch (PRINTSYS_PrintStreamGetState((void *)(((struct Obj10819 *)a)->f64))) {
    case 0:
        if ((KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
            PRINTSYS_PrintStreamShortWait((struct Rec *)(((struct Obj10819 *)a)->f64), 0);
            if ((KEY_GetCont() & 3) != 0)
                UI_SetInputMode(0);
            else
                UI_SetInputMode(1);
        }
        break;
    case 1:
        if ((KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
            GFL_USE_PlaySeDefaultVolume(0x547);
            PRINTSYS_PrintStreamReleasePause((void *)(((struct Obj10819 *)a)->f64));
            if ((KEY_GetTrg() & 3) != 0)
                UI_SetInputMode(0);
            else
                UI_SetInputMode(1);
        }
        break;
    case 2:
        r = 1;
        break;
    }
    return r;
}
