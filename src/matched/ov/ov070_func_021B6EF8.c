/*
 * function: ITEMMENU_HandleActionMenuChoice
 * address:  0x021B6EF8
 * packet:   pkt_ov070_021B6EF8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The switch arms are in the original's layout order (0,1,3,4-5,2,8,9,6,7);
 * the table entry at 0x021BB9C8 is gItemMenuUseRanges[i].fn, one extern through
 * its field (the pool word is the symbol + 4).
 *
 * symbols:
 *   ITEMMENU_IsMessageFinished  0x021BADF0  thumb  ov070
 *   APP_TASKMENU_IsFinish  0x020279E8  thumb
 *   APP_TASKMENU_GetCursorPos  0x02027A04  thumb
 *   ITEMMENU_SetBackButtonAnim  0x021BB580  thumb  ov070
 *   GAME_BEACON_SetItemUse  0x02027324  thumb
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskUseNoticeMessage  0x021B7640  thumb  ov070
 *   FILE_UTIL_Get_0FE4  0x02020FE4  thumb
 *   ITEMMENU_FindUseRange  0x021B6EC8  thumb  ov070
 *   gItemMenuUseRanges     0x021BB9C4  data  a4
 *   ITEMMENU_GetFieldUseKind  0x021B690C  thumb  ov070
 *   ITEMMENU_UseRepel  0x021B6934  thumb  ov070
 *   ITEMMENU_ShowKeyItemRefusal  0x021B6A78  thumb  ov070
 *   func_02028754  0x02028754  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   ITEMMENU_ShowMessageThenWait  0x021B6AD8  thumb  ov070
 *   ITEMMENU_TaskTossAskQuantity  0x021B7804  thumb  ov070
 *   ITEMMENU_IsBrowseMode  0x021B811C  thumb  ov070
 *   ITEMMENU_ToggleRegisteredItem  0x021B8134  thumb  ov070
 *   ITEMMENU_RedrawList  0x021B6138  thumb  ov070
 *   ITEMMENU_UpdateSideButtons  0x021BB3F4  thumb  ov070
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   ITEMMENU_ReturnToBagMain  0x021B8AF4  thumb  ov070
 *   func_020355C4  0x020355C4  arm
 *   ITEMMENU_HideMoveInfo  0x021B9AAC  thumb  ov070
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   ITEMMENU_ClearMessageWindow  0x021BA9AC  thumb  ov070
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 */
#include "../include/Obj00002.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct RangeEnt {
    u16 lo;
    u16 n;
    void (*fn)(void *);
} RangeEnt;

extern const RangeEnt gItemMenuUseRanges[8];

struct MsgBank;
struct WordSet;
extern int ITEMMENU_IsMessageFinished(int p);
struct Obj;
struct TaskMenu;
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const u8 *p);
extern void ITEMMENU_SetBackButtonAnim(char *p, int v);
extern void GAME_BEACON_SetItemUse(u16 id);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskUseNoticeMessage(struct Obj *o);
extern u32  FILE_UTIL_Get_0FE4(u16 a, u32 sel, u32 id);
extern int  ITEMMENU_FindUseRange(u16 id);
extern int  ITEMMENU_GetFieldUseKind(u16 id);
extern void ITEMMENU_UseRepel(u8 *p);
extern void ITEMMENU_ShowKeyItemRefusal(u8 *p);
extern u32 func_02028754(struct Obj *obj, u32 n);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void ITEMMENU_ShowMessageThenWait(int p);
extern void ITEMMENU_TaskTossAskQuantity(struct Obj *o);
extern int ITEMMENU_IsBrowseMode(u8 *p);
extern int ITEMMENU_ToggleRegisteredItem(struct Obj *o, int k);
extern void ITEMMENU_RedrawList(char *p);
extern void ITEMMENU_UpdateSideButtons(int p, int mode);
extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);
extern void ITEMMENU_ReturnToBagMain(void *o);
extern u8 func_020355C4(void);
extern void ITEMMENU_HideMoveInfo(char *p);
extern void ITEMMENU_SetCursorActive(struct Obj *o, int flag);
extern void ITEMMENU_ClearMessageWindow(char *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

void ITEMMENU_HandleActionMenuChoice(u8 *p)
{
    int flag = 0;
    u32 x;
    int r;

    if (ITEMMENU_IsMessageFinished((int)p) == 0)
        return;
    if (APP_TASKMENU_IsFinish(((struct Obj00002 *)p)->f77C)) {
        x = *(u32 *)(p + 0x828 + APP_TASKMENU_GetCursorPos(((struct Obj00002 *)p)->f77C) * 4);
        ((struct Obj00002 *)p)->f848 = x;
        switch (x) {
        case 0:
            ITEMMENU_SetBackButtonAnim((char *)p, 0);
            if (*(u32 *)&((struct Obj00002 *)p)->f80C != 4)
                GAME_BEACON_SetItemUse(((struct Obj00002 *)p)->f84C);
            if (*(u32 *)&((struct Obj00002 *)p)->f80C == 2) {
                ITEMMENU_SetTask((char *)p, (int)((void *)ITEMMENU_TaskUseNoticeMessage));
            } else if (FILE_UTIL_Get_0FE4(((struct Obj00002 *)p)->f84C, 0x1D, ((struct Obj00002 *)p)->f544) == 1) {
                ((struct Obj00002 *)p)->f844 = 0xC;
                ITEMMENU_SetTask((char *)p, 0);
            } else if (ITEMMENU_FindUseRange(((struct Obj00002 *)p)->f84C) >= 0) {
                gItemMenuUseRanges[ITEMMENU_FindUseRange(*(u32 *)(p + 0x84C))].fn(p);
            } else {
                r = ITEMMENU_GetFieldUseKind(((struct Obj00002 *)p)->f84C);
                if (r == 1) {
                    ITEMMENU_SetTask((char *)p, (int)((void *)ITEMMENU_UseRepel));
                } else if (r == 2) {
                    ITEMMENU_SetTask((char *)p, (int)((void *)ITEMMENU_ShowKeyItemRefusal));
                } else {
                    ((struct Obj00002 *)p)->f844 = 5;
                    ITEMMENU_SetTask((char *)p, 0);
                }
            }
            break;
        case 1:
            ITEMMENU_SetBackButtonAnim((char *)p, 0);
            if (func_02028754(((struct Obj00002 *)p)->fC, 0)) {
                ((struct Obj00002 *)p)->f844 = 0xB;
                ITEMMENU_SetTask((char *)p, 0);
            } else {
                MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00002 *)p)->f51C), 0x39, (void *)(((struct Obj00002 *)p)->f524));
                func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), 0, (void *)(((struct Obj00002 *)p)->f8));
                func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00002 *)p)->f520), (void *)(*(u32 *)&((struct Obj00002 *)p)->f528), (void *)(((struct Obj00002 *)p)->f524));
                ITEMMENU_SetTask((char *)p, (int)((void *)ITEMMENU_ShowMessageThenWait));
            }
            break;
        case 3:
            ITEMMENU_SetTask((char *)p, (int)((void *)ITEMMENU_TaskTossAskQuantity));
            break;
        case 4:
        case 5:
            if (ITEMMENU_IsBrowseMode(p) == 1) {
                ITEMMENU_ToggleRegisteredItem((struct Obj *)p, *(u32 *)&((struct Obj00002 *)p)->f810);
                ITEMMENU_RedrawList((char *)p);
                ITEMMENU_UpdateSideButtons((int)p, 1);
                CLACT_SetActorAutoAnim(((struct Obj00002 *)p)->f6A8, 1);
                ITEMMENU_ReturnToBagMain(p);
            }
            break;
        case 2:
            ITEMMENU_SetBackButtonAnim((char *)p, 0);
            if ((int)((struct Obj00002 *)p)->f84C >= 0x89 && (int)((struct Obj00002 *)p)->f84C <= 0x94) {
                ((struct Obj00002 *)p)->f844 = 0x13;
                ITEMMENU_SetTask((char *)p, 0);
            }
            break;
        case 8:
            if (func_020355C4() == 1)
                ITEMMENU_HideMoveInfo((char *)p);
            ITEMMENU_SetCursorActive((struct Obj *)p, func_020355C4() == 0);
            ITEMMENU_UpdateSideButtons((int)p, 1);
            CLACT_SetActorAutoAnim(((struct Obj00002 *)p)->f6A8, 1);
            ITEMMENU_ReturnToBagMain(p);
            break;
        case 9:
            ((struct Obj00002 *)p)->f844 = 1;
            ITEMMENU_SetTask((char *)p, 0);
            break;
        case 6:
            ((struct Obj00002 *)p)->f844 = 2;
            ITEMMENU_SetBackButtonAnim((char *)p, 0);
            ITEMMENU_SetTask((char *)p, 0);
            break;
        case 7:
            break;
        }
        flag = 1;
    }
    if (flag) {
        ITEMMENU_ClearMessageWindow((char *)p);
        APP_TASKMENU_CloseMenu(((struct Obj00002 *)p)->f77C);
        *(u32 *)&((struct Obj00002 *)p)->f77C = 0;
    }
}
