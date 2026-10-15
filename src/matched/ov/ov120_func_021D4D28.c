/*
 * function: GTSNEGO_DISP_HandleConfirmKeys
 * address: 0x021D4D28
 * packet: pkt_ov120_021D4D28
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GTSNEGO_DISP_GetTouchbar 0x021D6988 thumb ov120
 *   GTSNEGO_MSG_UpdatePrintStream 0x021D7AF4 thumb ov120
 *   TOUCHBAR_IsBusy 0x021B6498 thumb ov067
 *   GTSNEGO_MSG_UpdateButtons 0x021D7C10 thumb ov120
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355C4 0x020355C4 arm
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   func_020355D8 0x020355D8 arm
 *   GTSNEGO_DISP_MoveCursorVertical 0x021D4474 thumb ov120
 *   GTSNEGO_MSG_SetCursorAnimSeq 0x021D6A9C thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_OnConfirmDone 0x021D4CC4 thumb ov120
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   d_021D88D0 0x021D88D0 data a4
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   func_02040588 0x02040588 arm
 *   GTSNEGO_MSG_DeleteButtonsKeep 0x021D7EC4 thumb ov120
 *   GTSNEGO_DISP_ResetActors 0x021D68C4 thumb ov120
 *   func_02041B6C 0x02041B6C arm
 *   GTSNEGO_DISP_ShowPartySelect 0x021D588C thumb ov120
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb  arm9
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj00495.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 GTSNEGO_DISP_GetTouchbar(u8 *p);
extern int GTSNEGO_MSG_UpdatePrintStream(char *p);
extern int TOUCHBAR_IsBusy(u8 *);
extern int GTSNEGO_MSG_UpdateButtons(char *p);
extern u32 KEY_GetTrg(void);
extern u8 func_020355C4(void);
extern void GTSNEGO_DISP_SetCursorState(u8 *p, void *q, u32 n);
extern void func_020355D8(u8 v);
struct S;
extern void GTSNEGO_DISP_MoveCursorVertical(int n, char *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int GTSNEGO_MSG_SetCursorAnimSeq(u8 *p, u32 n);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_OnConfirmDone(u8 *);
extern int TOUCHPANEL_HitTrg(const void *p);
extern const u32 d_021D88D0[];
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GTSNEGO_MSG_DeleteButtonsKeep(u8 *p);
extern void GTSNEGO_DISP_ResetActors(u8 *);
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_02041B6C(u32);
extern void GTSNEGO_DISP_ShowPartySelect(u8 *);
void GTSNEGO_DISP_HandleConfirmKeys(u8 *p)
{
    int changed = 0;
    int done = 0;
    u8 *q = (u8 *)GTSNEGO_DISP_GetTouchbar(((struct Obj00495 *)p)->f3C);
    if (GTSNEGO_MSG_UpdatePrintStream(((struct Obj00495 *)p)->f40)) {
        if (TOUCHBAR_IsBusy(q) == 0) {
            GTSNEGO_MSG_UpdateButtons((char *)(*(int *)&((struct Obj00495 *)p)->f40));
            if (KEY_GetTrg() != 0 && func_020355C4() == 1) {
                GTSNEGO_DISP_SetCursorState(((struct Obj00495 *)p)->f3C, ((struct Obj00495 *)p)->f34, ((struct Obj00495 *)p)->f160);
                func_020355D8(changed);
                return;
            }
            if (KEY_GetTrg() == 0x20) GTSNEGO_DISP_MoveCursorVertical(0, (char *)p);
            if (KEY_GetTrg() == 0x10) GTSNEGO_DISP_MoveCursorVertical(1, (char *)p);
            if (KEY_GetTrg() == 0x40) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed = 1;
                if (((struct Obj00495 *)p)->f160 != 2) --((struct Obj00495 *)p)->f160;
            }
            if (KEY_GetTrg() == 0x80) {
                GFL_USE_PlaySeDefaultVolume(0x548);
                changed = 1;
                if (((struct Obj00495 *)p)->f160 != 5) ++((struct Obj00495 *)p)->f160;
            }
            if (KEY_GetTrg() == 1 && ((struct Obj00495 *)p)->f160 == 5) {
                GFL_USE_PlaySeDefaultVolume(0x54c);
                GTSNEGO_MSG_SetCursorAnimSeq(((struct Obj00495 *)p)->f3C, ((struct Obj00495 *)p)->f160);
                APP_TASKMENU_WIN_SetDecide(((struct Obj00495 *)p)->f34, 1);
                GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_OnConfirmDone, 0x4ca);
                return;
            }
            if (changed)
                GTSNEGO_DISP_SetCursorState(((struct Obj00495 *)p)->f3C, ((struct Obj00495 *)p)->f34, ((struct Obj00495 *)p)->f160);
            if (TOUCHPANEL_HitTrg(d_021D88D0) == 0) {
                func_020355D8(1);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                APP_TASKMENU_WIN_SetDecide(((struct Obj00495 *)p)->f34, 1);
                GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_OnConfirmDone, 0x4f2);
                return;
            }
        }
        TOUCHBAR_Update((struct S *)GTSNEGO_DISP_GetTouchbar(((struct Obj00495 *)p)->f3C));
        if (TOUCHBAR_GetPressedButtonIdIfDone((u8 *)GTSNEGO_DISP_GetTouchbar(((struct Obj00495 *)p)->f3C)) == 1) done = 1;
        if (done) {
            int zero = 0;
            func_02040588(4, 0);
            GTSNEGO_DISP_SetCursorState(((struct Obj00495 *)p)->f3C, ((struct Obj00495 *)p)->f34, 9);
            GTSNEGO_MSG_DeleteButtonsKeep(((struct Obj00495 *)p)->f40);
            GTSNEGO_DISP_ResetActors(*(u8 * *)&((struct Obj00495 *)p)->f3C);
            APP_TASKMENU_WIN_Delete(((struct Obj00495 *)p)->f34);
            *(int *)&((struct Obj00495 *)p)->f34 = zero;
            func_02041B6C(5);
            GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_ShowPartySelect, 0x50b);
        }
    }
}
