/*
 * function: ITEMMENU_TaskListInput
 * address:  0x021B66FC
 * packet:   pkt_ov070_021B66FC
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BLINK_PALANM_Update  0x0202EA40  thumb
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   ITEMMENU_GetCursorIndex  0x021B61B8  thumb  ov070
 *   ITEMMENU_HandleScrollbarTouch  0x021B63F8  thumb  ov070
 *   ITEMMENU_MoveSlot  0x021B624C  thumb  ov070
 *   ITEMMENU_RedrawList  0x021B6138  thumb  ov070
 *   TOUCHPANEL_GetCont  0x02035C38  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_02007CC8  0x02007CC8  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   ITEMMENU_UpdateSideButtonsForMode  0x021BB5DC  thumb  ov070
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   ITEMMENU_ReturnToBagMain  0x021B8AF4  thumb  ov070
 *   KEY_GetTrg  0x020362DC  arm
 *   ITEMMENU_StartSideButtonPress  0x021B8C1C  thumb  ov070
 *   ITEMMENU_TaskFinishClose  0x021B66E8  thumb  ov070
 *   ITEMMENU_IsBackButtonTouched  0x021B66B8  thumb  ov070
 *   ITEMMENU_HandleListTouch  0x021B65E8  thumb  ov070
 *   ITEMMENU_MoveCursorToRow  0x021BA6A4  thumb  ov070
 *   ITEMMENU_HandleMoveModeKeys  0x021B64A0  thumb  ov070
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef unsigned short u16;
struct Obj;
struct PrintSys;
struct Row;
typedef signed int     s32;
extern s32 BLINK_PALANM_Update(struct Row *p);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);
extern int ITEMMENU_GetCursorIndex(u8 *p);
extern u32  ITEMMENU_HandleScrollbarTouch(u8 *p);
extern void ITEMMENU_MoveSlot(void *o, int a, int b);
extern void ITEMMENU_RedrawList(char *p);
extern int  TOUCHPANEL_GetCont(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void func_02007CC8(u8 *base, void *buf, u32 id, int save);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void ITEMMENU_UpdateSideButtonsForMode(int p, int mode);
extern void ITEMMENU_SetCursorActive(struct Obj *o, int flag);
extern void ITEMMENU_ReturnToBagMain(void *o);
extern u32  KEY_GetTrg(void);
extern void ITEMMENU_StartSideButtonPress(int p, int a, int b);
extern void ITEMMENU_TaskFinishClose(int p);
extern int  ITEMMENU_IsBackButtonTouched(void);
extern int  ITEMMENU_HandleListTouch(u8 *p);
extern void ITEMMENU_MoveCursorToRow(char *p);
extern int  ITEMMENU_HandleMoveModeKeys(void *o);

void ITEMMENU_TaskListInput(u8 *p)
{
    int a;

    BLINK_PALANM_Update((struct Row *)(*(u32 *)&((struct Obj00002 *)p)->f850));
    if (PRINTSYS_QUE_IsFinished((const struct PrintSys *)(*(u32 *)&((struct Obj00002 *)p)->f50C)) == 0)
        return;
    a = ITEMMENU_GetCursorIndex(p);
    if (ITEMMENU_HandleScrollbarTouch(p)) {
        ITEMMENU_MoveSlot(p, a, ITEMMENU_GetCursorIndex(p));
        *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
        ITEMMENU_RedrawList((char *)p);
        return;
    }
    if (TOUCHPANEL_GetCont() == 0) {
        ((struct Obj00002 *)p)->f85C = 0;
        if (((struct Obj00002 *)p)->f860 == 1) {
            GFL_USE_PlaySeDefaultVolume(0x54C);
            ((struct Obj00002 *)p)->f860 = 0;
            func_02007CC8(((struct Obj00002 *)p)->f18, p + 0x20, *(u32 *)&((struct Obj00002 *)p)->f80C, 0);
            CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)&((struct Obj00002 *)p)->f6A4), 1);
            ITEMMENU_UpdateSideButtonsForMode((int)p, 1);
            ((struct Obj00002 *)p)->f81C = 0;
            ITEMMENU_SetCursorActive((struct Obj *)p, 0);
            ITEMMENU_ReturnToBagMain(p);
            return;
        }
    }
    if (((struct Obj00002 *)p)->f85C == 1)
        return;
    if (KEY_GetTrg() & 5) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        func_02007CC8(((struct Obj00002 *)p)->f18, p + 0x20, *(u32 *)&((struct Obj00002 *)p)->f80C, 0);
        CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)&((struct Obj00002 *)p)->f6A4), 1);
        ITEMMENU_UpdateSideButtonsForMode((int)p, 1);
        ((struct Obj00002 *)p)->f81C = 0;
        ITEMMENU_SetCursorActive((struct Obj *)p, 1);
        ITEMMENU_ReturnToBagMain(p);
        return;
    }
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)&((struct Obj00002 *)p)->f6A4), 1);
        ((struct Obj00002 *)p)->f81C = 0;
        ITEMMENU_SetCursorActive((struct Obj *)p, 1);
        *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
        ITEMMENU_RedrawList((char *)p);
        ITEMMENU_StartSideButtonPress((int)p, 4, (int)((void *)ITEMMENU_TaskFinishClose));
        return;
    }
    if (ITEMMENU_IsBackButtonTouched() == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        CLACT_SetActorAnimSeq((struct Obj *)(*(u32 *)&((struct Obj00002 *)p)->f6A4), 1);
        ((struct Obj00002 *)p)->f81C = 0;
        ITEMMENU_SetCursorActive((struct Obj *)p, 0);
        *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
        ITEMMENU_RedrawList((char *)p);
        ITEMMENU_StartSideButtonPress((int)p, 4, (int)((void *)ITEMMENU_TaskFinishClose));
        return;
    }
    if (ITEMMENU_HandleListTouch(p)) {
        ((struct Obj00002 *)p)->f860 = 1;
        ITEMMENU_MoveCursorToRow((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
        ITEMMENU_RedrawList((char *)p);
        return;
    }
    if (ITEMMENU_HandleMoveModeKeys(p)) {
        ITEMMENU_MoveCursorToRow((char *)p);
        GFL_USE_PlaySeDefaultVolume(0x548);
        *(u32 *)&((struct Obj00002 *)p)->f818 = 0xFFFF;
        ITEMMENU_RedrawList((char *)p);
    }
}
