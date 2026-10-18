/*
 * function: ITEMMENU_HandleTouchTarget
 * address:  0x021B83B8
 * packet:   pkt_ov070_021B83B8
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Touch-button dispatch of the list screen: buttons 0-4 pick a pocket tab
 * through the table d_021BB984, 5/6 step the tab, 7-10 are the sort,
 * select, exit and back buttons, 11-16 pick a list row, 17+ pick a slot.
 * Touch twin of ITEMMENU_TaskBagMain's key handling.
 *
 * symbols:
 *   ITEMMENU_GetItemCount  0x021B61C8  thumb  ov070
 *   ITEMMENU_SetCursorActive  0x021B80C4  thumb  ov070
 *   ITEMMENU_StartPocketTabPress  0x021B8CE4  thumb  ov070
 *   ITEMMENU_ReturnToBagMainAlias  0x021B8F90  thumb  ov070
 *   ITEMMENU_ShowInputGuardError  0x021B8080  thumb  ov070
 *   ITEMMENU_RedrawList  0x021B6138  thumb  ov070
 *   ITEMMENU_SetTask  0x021B6100  thumb  ov070
 *   ITEMMENU_TaskInputGuardMessage  0x021B8EA8  thumb  ov070
 *   ITEMMENU_IsBrowseMode  0x021B811C  thumb  ov070
 *   ITEMMENU_TogglePocketSortFlag  0x021B81B8  thumb  ov070
 *   ITEMMENU_StartSideButtonPress  0x021B8C1C  thumb  ov070
 *   UI_SetInputMode  0x020355D8  arm
 *   ITEMMENU_TaskBagMain  0x021B7250  thumb  ov070
 *   ITEMMENU_GetCursorIndex  0x021B61B8  thumb  ov070
 *   ITEMMENU_MoveSlot  0x021B624C  thumb  ov070
 *   ITEMMENU_DrawMoveInfo  0x021B9850  thumb  ov070
 *   ITEMMENU_TaskSelectItemFlash  0x021B8B7C  thumb  ov070
 *   ITEMMENU_ToggleRegisteredItem  0x021B8134  thumb  ov070
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   ITEMMENU_SwitchPocketCursor  0x021B6288  thumb  ov070
 *   ITEMMENU_RefreshInputGuard  0x021B80BC  thumb  ov070
 *   d_021BB984     0x021BB984  data  a4
 */

typedef unsigned int u32;

typedef struct Obj Obj;

struct Obj {
    unsigned char pad000[0x10];
    int f010;
    unsigned char pad014[0x4F8 - 0x14];
    void (*f4F8)(Obj *o);
    unsigned char pad4FC[0x80C - 0x4FC];
    int f80C;
    int f810;
    unsigned char pad814[0x818 - 0x814];
    int f818;
    unsigned char pad81C[0x844 - 0x81C];
    int f844;
    unsigned char pad848[0x84C - 0x848];
    int f84C;
};

typedef struct TabTbl {
    int v[5];
} TabTbl;

extern const TabTbl d_021BB984;

extern int ITEMMENU_GetItemCount(unsigned char *p);
typedef unsigned char  u8;
extern void ITEMMENU_SetCursorActive(struct Obj *o, int flag);
extern void ITEMMENU_StartPocketTabPress(int p, int u, int a, int b);
extern void ITEMMENU_ReturnToBagMainAlias(void *o);
extern void ITEMMENU_ShowInputGuardError(u8 *p);
extern void ITEMMENU_RedrawList(char *p);
extern void ITEMMENU_SetTask(char *p, int k);
extern void ITEMMENU_TaskInputGuardMessage(int p);
extern int ITEMMENU_IsBrowseMode(u8 *p);
extern void ITEMMENU_TogglePocketSortFlag(u8 *p);
extern void ITEMMENU_StartSideButtonPress(int p, int a, int b);
extern void UI_SetInputMode(u8 v);
extern void ITEMMENU_TaskBagMain(Obj *o);
extern int ITEMMENU_GetCursorIndex(u8 *p);
extern void ITEMMENU_MoveSlot(void *o, int a, int b);
extern void ITEMMENU_DrawMoveInfo(char *p);
extern void ITEMMENU_TaskSelectItemFlash(int p);
extern int ITEMMENU_ToggleRegisteredItem(struct Obj *o, int k);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int se);
extern void ITEMMENU_SwitchPocketCursor(struct Obj *o, int a, int b);
extern void ITEMMENU_RefreshInputGuard(void *p);

void ITEMMENU_HandleTouchTarget(u32 idx, int flag, Obj *o)
{
    int tab;
    int count;
    int v;
    int saved;
    int cur;
    TabTbl t;

    tab = -1;
    count = ITEMMENU_GetItemCount((unsigned char *)o);
    if (flag != 0)
        return;
    if (idx < 5) {
        t = d_021BB984;
        if (o->f80C != t.v[idx]) {
            tab = t.v[idx];
            ITEMMENU_SetCursorActive(o, 0);
        }
    } else if (idx == 5) {
        ITEMMENU_SetCursorActive(o, 0);
        v = o->f80C;
        o->f80C = v - 1;
        if (o->f80C < 0)
            o->f80C = 4;
        ITEMMENU_StartPocketTabPress((int)o, v, 0, (int)((void *)ITEMMENU_ReturnToBagMainAlias));
        return;
    } else if (idx == 6) {
        ITEMMENU_SetCursorActive(o, 0);
        v = o->f80C;
        o->f80C = v + 1;
        if (o->f80C >= 5)
            o->f80C = 0;
        ITEMMENU_StartPocketTabPress((int)o, v, 1, (int)((void *)ITEMMENU_ReturnToBagMainAlias));
        return;
    } else if (idx == 7) {
        if (o->f80C != 2 && o->f80C != 3 && ITEMMENU_GetItemCount((unsigned char *)o) > 1) {
            ITEMMENU_ShowInputGuardError((u8 *)o);
            ITEMMENU_SetCursorActive(o, 0);
            o->f818 = 0xFFFF;
            ITEMMENU_RedrawList((char *)o);
            ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskInputGuardMessage));
        }
    } else if (idx == 8) {
        if (ITEMMENU_IsBrowseMode((u8 *)o) == 1) {
            ITEMMENU_TogglePocketSortFlag((u8 *)o);
            ITEMMENU_SetCursorActive(o, 0);
            o->f818 = 0xFFFF;
            ITEMMENU_RedrawList((char *)o);
        }
    } else if (idx == 9) {
        if (o->f010 != 2) {
            o->f844 = 0;
            o->f84C = 0;
            ITEMMENU_StartSideButtonPress((int)o, 3, 0);
            UI_SetInputMode(1);
        }
    } else if (idx == 10) {
        o->f844 = 1;
        o->f84C = 0;
        ITEMMENU_StartSideButtonPress((int)o, 4, 0);
        UI_SetInputMode(1);
    } else if (idx >= 11 && idx < 17) {
        if (o->f4F8 != ITEMMENU_TaskBagMain)
            return;
        saved = o->f810;
        cur = ITEMMENU_GetCursorIndex((u8 *)o);
        if (ITEMMENU_GetItemCount((unsigned char *)o) == 0)
            return;
        if (o->f810 != idx - 11) {
            o->f810 = idx - 11;
            if (count <= ITEMMENU_GetCursorIndex((u8 *)o)) {
                o->f810 = saved;
                return;
            }
        }
        ITEMMENU_MoveSlot(o, cur, ITEMMENU_GetCursorIndex((u8 *)o));
        ITEMMENU_SetCursorActive(o, 0);
        o->f818 = 0xFFFF;
        ITEMMENU_RedrawList((char *)o);
        ITEMMENU_DrawMoveInfo((char *)o);
        ITEMMENU_SetTask((char *)o, (int)((void *)ITEMMENU_TaskSelectItemFlash));
        return;
    } else if (idx >= 17) {
        if (ITEMMENU_IsBrowseMode((u8 *)o) == 1 && ITEMMENU_ToggleRegisteredItem(o, idx - 17) == 1) {
            ITEMMENU_SetCursorActive(o, 0);
            ITEMMENU_RedrawList((char *)o);
        }
    }
    if (tab != -1) {
        v = o->f80C;
        o->f80C = tab;
        GFL_USE_PlaySeDefaultVolume(0x7D9);
        ITEMMENU_SwitchPocketCursor(o, v, o->f80C);
        ITEMMENU_RefreshInputGuard(o);
        ITEMMENU_SetCursorActive(o, 0);
        o->f818 = 0xFFFF;
        ITEMMENU_RedrawList((char *)o);
    }
}
