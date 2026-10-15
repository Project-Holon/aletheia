/*
 * function: GTSNEGO_DISP_HandlePartyInput
 * address: 0x021D5AD4
 * packet: pkt_ov120_021D5AD4
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_GetTouchbar 0x021D6988 thumb ov120
 *   GTSNEGO_MSG_UpdatePrintStream 0x021D7AF4 thumb ov120
 *   GTSNEGO_MSG_PrintWindow 0x021D79F4 thumb ov120
 *   TOUCHBAR_IsBusy 0x021B6498 thumb ov067
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   GTSNEGO_DISP_SelectParty 0x021D593C thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_OnPartySelected 0x021D5980 thumb ov120
 *   GTSNEGO_DISP_OpenPartyMenu 0x021D5A84 thumb ov120
 *   GTSNEGO_MSG_UpdateButtons 0x021D7C10 thumb ov120
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj01400.h"
typedef unsigned char u8;
extern unsigned int GTSNEGO_DISP_GetTouchbar(u8 *p);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int GTSNEGO_MSG_UpdatePrintStream(char *p);
extern void GTSNEGO_MSG_PrintWindow(u8 *p, u16 n);
extern int TOUCHBAR_IsBusy(u8 *);
extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern int GTSNEGO_DISP_SelectParty(u8 *, int);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_OnPartySelected(u8 *);
extern void GTSNEGO_DISP_OpenPartyMenu(u8 *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GTSNEGO_MSG_UpdateButtons(char *p);
struct S;
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
void GTSNEGO_DISP_HandlePartyInput(u8 *p)
{
    int changed = 0;
    u8 *q = (u8 *)GTSNEGO_DISP_GetTouchbar(((struct Obj01400 *)p)->f3C);
    if (GTSNEGO_MSG_UpdatePrintStream(((struct Obj01400 *)p)->f40)) {
        if (TOUCHBAR_IsBusy(q) == 0) {
            if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
                GTSNEGO_DISP_SetCursorState(((struct Obj01400 *)p)->f3C, 0, ((struct Obj01400 *)p)->f15C);
                func_020355D8(changed);
                return;
            }
            if (KEY_GetTrg() == 1) {
                if (((struct Obj01400 *)p)->f184 == 0) {
                    GTSNEGO_DISP_SelectParty(p, ((struct Obj01400 *)p)->f15C);
                    GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_OnPartySelected, 0x8f4);
                    return;
                }
                GFL_USE_PlaySeDefaultVolume(0x551);
            }
            if (KEY_GetTrg() == 0x40) {
                changed = 1;
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((struct Obj01400 *)p)->f15C = 0;
            }
            if (KEY_GetTrg() == 0x80) {
                changed = 1;
                GFL_USE_PlaySeDefaultVolume(0x548);
                ((struct Obj01400 *)p)->f15C = 1;
            }
            if (changed)
                GTSNEGO_DISP_SetCursorState(((struct Obj01400 *)p)->f3C, 0, ((struct Obj01400 *)p)->f15C);
            GTSNEGO_MSG_UpdateButtons((char *)(*(int *)&((struct Obj01400 *)p)->f40));
        }
        TOUCHBAR_Update((struct S *)GTSNEGO_DISP_GetTouchbar(((struct Obj01400 *)p)->f3C));
        if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)GTSNEGO_DISP_GetTouchbar(((struct Obj01400 *)p)->f3C)) == 1) {
            ((struct Obj01400 *)p)->f14 = 1;
            GTSNEGO_MSG_PrintWindow(((struct Obj01400 *)p)->f40, 0x2a);
            if (func_020355C4() == 1)
                GTSNEGO_DISP_SetCursorState(((struct Obj01400 *)p)->f3C, 0, 9);
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_OpenPartyMenu, 0x916);
        }
    }
}
