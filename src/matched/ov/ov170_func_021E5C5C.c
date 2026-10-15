/*
 * function: BOX2_SEQ_StateScrollBox
 * address:  0x021E5C5C
 * packet:   pkt_ov170_021E5C5C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_UI_PlaceCursorAtMon 0x021EE544 thumb
 *   BOX2_UI_ToggleSlotPair 0x021ED888 thumb
 *   BOX2_SEQ_ShowWindowObject 0x021EBA5C thumb
 *   BOX2_MAIN_RefreshCursorBox 0x021DD14C thumb
 *   BOX2_SEQ_SetSeqThird 0x021E8FC0 thumb
 *   BOX2_MAIN_SceneApplyScroll 0x021E066C thumb
 *   func_020307B0 0x020307B0 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   BOX2_UI_CloseBar 0x021EF36C thumb
 *   BOX2_MAIN_IsWindowBusy 0x021E01B0 thumb
 *   BOX2_SEQ_Create 0x021EA1C0 thumb
 *   BOX2_MAIN_SceneOpenBox 0x021E087C thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_SetSlotDim 0x021ED6E4 thumb
 *   BOX2_MAIN_Check09E0 0x021E09E0 thumb
 *   BOX2_MAIN_UpdateBoxSlots 0x021DD530 thumb
 *   BOX2_SEQ_Delete 0x021EA1E8 thumb
 *   BOX2_MAIN_ResetBoxView 0x021DF040 thumb
 *   BOX2_SEQ_SetSlotActors 0x021ECB20 thumb
 *   BOX2_UI_DeleteSlotObjects 0x021EE038 thumb
 *   BOX2_UI_MoveCursor 0x021EE364 thumb
 *   BOX2_MAIN_ChangeBoxFormPreserve 0x021DEFEC thumb
 *
 * Eight-step machine on the work word at 0xA194 for the party swap:
 * fade, take the slot (from the held box slot at 0xA17E if any), fade
 * back and restore the box view.
 */

struct WinMgr;
extern void BOX2_UI_PlaceCursorAtMon(char *p, unsigned int i);
extern void BOX2_UI_ToggleSlotPair(char *w, int a);
extern void BOX2_SEQ_ShowWindowObject(char *w, int v);
extern void BOX2_MAIN_RefreshCursorBox(char *p);
extern int BOX2_SEQ_SetSeqThird(char *p, int a, int b);
extern int BOX2_MAIN_SceneApplyScroll(char *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
extern void GFL_USE_PlaySeDefaultVolume(unsigned se);
extern void BOX2_UI_CloseBar(struct WinMgr *mgr);
extern int BOX2_MAIN_IsWindowBusy(unsigned char *p);
extern void BOX2_SEQ_Create(void *p);
extern int BOX2_MAIN_SceneOpenBox(unsigned char *p);
extern void BOX2_SEQ_SetActorDrawEnable(char *w, int i, int v);
extern void BOX2_SEQ_SetSlotDim(char **p, int v);
extern int BOX2_MAIN_Check09E0(char *p);
extern void BOX2_MAIN_UpdateBoxSlots(unsigned char *p);
extern void BOX2_SEQ_Delete(char *p);
extern void BOX2_MAIN_ResetBoxView(char *p);
extern void BOX2_SEQ_SetSlotActors(char *p, int f, int c);
extern void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c);
extern void BOX2_UI_MoveCursor(char **p, int idx, int v);
extern void BOX2_MAIN_ChangeBoxFormPreserve(char *p, int b);

#define WORK(p) (*(char **)((p) + 0x2C))
#define MGR(p) (*(struct WinMgr **)(WORK(p) + 0x74))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
#define HELD(p) (*(unsigned char *)(WORK(p) + 0xA17E))

int BOX2_SEQ_StateScrollBox(unsigned char *p)
{
    switch (STEP(p)) {
    case 0:
        if (HELD(p) == 0xFF) {
            BOX2_UI_PlaceCursorAtMon((char *)p, p[0x16]);
            STEP(p) = 1;
        } else {
            BOX2_UI_PlaceCursorAtMon((char *)p, HELD(p));
            STEP(p) = 4;
        }
        BOX2_UI_ToggleSlotPair(WORK(p), 0);
        BOX2_SEQ_ShowWindowObject(WORK(p), 0x18);
        BOX2_MAIN_RefreshCursorBox((char *)p);
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_SceneApplyScroll, 0x36);
    case 1:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_UI_CloseBar(MGR(p));
        STEP(p) = 2;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowBusy, 0x36);
    case 2:
        BOX2_SEQ_Create(p);
        STEP(p) = 6;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_SceneOpenBox, 0x36);
    case 3:
        GFL_USE_PlaySeDefaultVolume(0x669);
        BOX2_SEQ_SetActorDrawEnable(WORK(p), 4, 0);
        BOX2_UI_CloseBar(MGR(p));
        STEP(p) = 7;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_IsWindowBusy, 0x36);
    case 4:
        func_020307B0(*(void **)(WORK(p) + 0x60));
        BOX2_SEQ_Create(p);
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        STEP(p) = 5;
        return BOX2_SEQ_SetSeqThird((char *)p, (int)BOX2_MAIN_Check09E0, 0x36);
    case 5:
        BOX2_MAIN_UpdateBoxSlots(p);
        BOX2_SEQ_Delete((char *)p);
        BOX2_MAIN_ResetBoxView((char *)p);
        BOX2_SEQ_SetSlotActors((char *)p, 1, 1);
        BOX2_SEQ_SetSlotActors((char *)p, 2, 0);
        STEP(p) = 3;
        break;
    case 6:
        BOX2_SEQ_Delete((char *)p);
    case 7:
        p[0x18] = 0;
        BOX2_SEQ_SetSlotDim((char **)p, 0);
        BOX2_UI_DeleteSlotObjects((char *)p, 0, 0, 1);
        BOX2_UI_MoveCursor((char **)p, 0, p[0x16] - 0x1E);
        BOX2_MAIN_ChangeBoxFormPreserve((char *)p, p[0x16]);
        STEP(p) = 0;
        return 0x31;
    }
    return 0x36;
}
