/*
 * function: OPTION_MENU_UpdateList
 * address:  0x021BA7C0
 * packet:   pkt_ov068_021BA7C0
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0/1/2 test on OPTION_MENU_TakeLastChanged's result is a switch with three empty
 * labels: `r == 0 || r == 1 || r == 2` folds to one unsigned `cmp #2`.
 *
 * symbols:
 *   OPTION_MENU_GetInputCommand  0x021BA190  thumb  ov068
 *   OPTION_MENU_GetInputPoint  0x021BA194  thumb  ov068
 *   func_02040804  0x02040804  arm
 *   OPTION_MENU_DrawList  0x021BAA0C  thumb  ov068
 *   func_020061E4  0x020061E4  thumb
 *   OPTION_MENU_GetRowAtTouch  0x021BAD38  thumb  ov068
 *   OPTION_MENU_SelectChoiceAtTouch  0x021BAC70  thumb  ov068
 *   OPTION_MENU_RestartScreenBlink  0x021B9964  thumb  ov068
 *   func_020355C4  0x020355C4  arm
 *   func_020355D8  0x020355D8  arm
 *   OPTION_MENU_StepSelectedSetting  0x021BAD14  thumb  ov068
 *   OPTION_MENU_TakeLastChanged  0x021BB0D8  thumb  ov068
 *   OPTION_MENU_GetTextWait  0x021BB0D0  thumb  ov068
 *   func_02040588  0x02040588  arm
 *   OPTION_MENU_PrintText  0x021BA278  thumb  ov068
 *   OPTION_MENU_IsTextDone  0x021BA31C  thumb  ov068
 *   OPTION_MENU_ShiftInputTrail  0x021BAD58  thumb  ov068
 *   gOptionMenuSettingRows     0x021BB570  data  a4
 */
#include "../include/Obj00103.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int OPTION_MENU_GetInputCommand(const int *p);
extern void OPTION_MENU_GetInputPoint(const u8 *p, int which, int *out);
extern u32 func_02040804(u32 layer);
extern void OPTION_MENU_DrawList(u8 *p, int flag);
extern void func_020061E4(u32 id);
extern int  OPTION_MENU_GetRowAtTouch(u8 *p, int *pos);
extern void OPTION_MENU_SelectChoiceAtTouch(u8 *p, void *b);
extern void OPTION_MENU_RestartScreenBlink(char *p);
extern u8 func_020355C4(void);
extern void func_020355D8(u8 v);
extern void OPTION_MENU_StepSelectedSetting(u8 *p, u32 v);
extern int  OPTION_MENU_TakeLastChanged(void *p);
extern u32  OPTION_MENU_GetTextWait(void *p);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void OPTION_MENU_PrintText(u8 *p, u32 a, u32 b, u32 c);
extern int OPTION_MENU_IsTextDone(u8 *p);
extern void OPTION_MENU_ShiftInputTrail(void *p);
extern const u16 gOptionMenuSettingRows[][4];

void OPTION_MENU_UpdateList(u8 *p, void *a1, void *a2, void *a3, void *a4)
{
    int pos[2];
    int r;
    int s;
    u32 t;

    r = OPTION_MENU_GetInputCommand(a1);
    func_02040804(((struct Obj00103 *)p)->f2);
    switch (r) {
    case 14:
        ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 > 6 ? 6 : (((struct Obj00103 *)p)->f4 < 0 ? 0 : ((struct Obj00103 *)p)->f4);
        OPTION_MENU_DrawList(p, 1);
        ((struct Obj00103 *)p)->f50 = 1;
        break;
    case 10:
        if ((((struct Obj00103 *)p)->f38)++ < 10)
            break;
    case 4:
        ((struct Obj00103 *)p)->f38 = 0;
        ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 == 0 ? 6 : ((struct Obj00103 *)p)->f4 - 1;
        ((struct Obj00103 *)p)->f50 = 1;
        func_020061E4(0x548);
        OPTION_MENU_DrawList(p, 1);
        OPTION_MENU_RestartScreenBlink(a3);
        break;
    case 11:
        if ((((struct Obj00103 *)p)->f38)++ < 10)
            break;
    case 5:
        ((struct Obj00103 *)p)->f38 = 0;
        if (((struct Obj00103 *)p)->f4 == 6)
            ((struct Obj00103 *)p)->f4 = 0;
        else
            (((struct Obj00103 *)p)->f4)++;
        ((struct Obj00103 *)p)->f50 = 1;
        func_020061E4(0x548);
        OPTION_MENU_DrawList(p, 1);
        OPTION_MENU_RestartScreenBlink(a3);
        break;
    case 3:
        OPTION_MENU_GetInputPoint(a1, 0, pos);
        if (pos[1] < 0x18 || pos[1] > 0xA8)
            break;
        ((struct Obj00103 *)p)->f4 = OPTION_MENU_GetRowAtTouch(p, pos);
        OPTION_MENU_SelectChoiceAtTouch(p, pos);
        OPTION_MENU_DrawList(p, 0);
        OPTION_MENU_RestartScreenBlink(a3);
        ((struct Obj00103 *)p)->f50 = 1;
        if (func_020355C4() == 0)
            func_020355D8(1);
        break;
    case 6:
        if (((struct Obj00103 *)p)->f4 < 5) {
            func_020061E4(0x548);
            OPTION_MENU_StepSelectedSetting(p, 1);
            OPTION_MENU_DrawList(p, 1);
            OPTION_MENU_RestartScreenBlink(a3);
        } else if (((struct Obj00103 *)p)->f4 == 5) {
            (((struct Obj00103 *)p)->f4)++;
            func_020061E4(0x548);
            ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 > 6 ? 6 : (((struct Obj00103 *)p)->f4 < 0 ? 0 : ((struct Obj00103 *)p)->f4);
        }
        break;
    case 7:
        if (((struct Obj00103 *)p)->f4 < 5) {
            func_020061E4(0x548);
            OPTION_MENU_StepSelectedSetting(p, -1);
            OPTION_MENU_DrawList(p, 1);
            OPTION_MENU_RestartScreenBlink(a3);
        } else if (((struct Obj00103 *)p)->f4 == 6) {
            (((struct Obj00103 *)p)->f4)--;
            func_020061E4(0x548);
            ((struct Obj00103 *)p)->f4 = ((struct Obj00103 *)p)->f4 > 6 ? 6 : (((struct Obj00103 *)p)->f4 < 0 ? 0 : ((struct Obj00103 *)p)->f4);
        }
        break;
    case 12:
        OPTION_MENU_DrawList(p, 1);
        break;
    case 8:
    case 9:
        OPTION_MENU_DrawList(p, 0);
        break;
    }
    switch (OPTION_MENU_TakeLastChanged(p + 0x44)) {
    case 0:
    case 1:
    case 2:
        ((struct Obj00103 *)p)->f50 = 1;
        break;
    }
    if (((struct Obj00103 *)p)->f50) {
        if (((struct Obj00103 *)p)->f4 >= 0 && ((struct Obj00103 *)p)->f4 < 5) {
            if (((struct Obj00103 *)p)->f4 == 0) {
                s = 1;
                t = OPTION_MENU_GetTextWait(p + 0x44);
            } else {
                s = 0;
                t = 0;
            }
            func_02040588(4, 1);
            OPTION_MENU_PrintText(a2, gOptionMenuSettingRows[((struct Obj00103 *)p)->f4][0], t, s);
        } else {
            func_02040588(4, 0);
        }
        ((struct Obj00103 *)p)->f50 = 0;
    }
    OPTION_MENU_IsTextDone(a2);
    OPTION_MENU_ShiftInputTrail(p);
}
