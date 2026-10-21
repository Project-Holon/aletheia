/*
 * file:     pmsiv_menu.c
 * unit:     yes
 * function: PMSIV_MENU_Create, PMSIV_MENU_Delete, PMSIV_MENU_Update, PMSIV_MENU_HideAll, PMSIV_MENU_ShowEditEntries, PMSIV_MENU_ShowWordEntries, PMSIV_MENU_ShowOnlyBackButton, PMSIV_MENU_UpdateItemHighlight, PMSIV_MENU_UpdateEntryPalette, PMSIV_MENU_UpdateEntryPalettes, PMSIV_MENU_PressEntry2, PMSIV_MENU_IsEntry2Done, PMSIV_MENU_PressBackItem, PMSIV_MENU_IsBackItemDone, PMSIV_MENU_FinishBackItem, PMSIV_MENU_PressEntry1, PMSIV_MENU_IsEntry1Done, PMSIV_MENU_PressEntry0, PMSIV_MENU_IsEntry0Done, PMSIV_MENU_StartPress, PMSIV_MENU_SelectItem, PMSIV_MENU_IsPressDone, PMSIV_MENU_FinishPress, PMSIV_MENU_SetActiveEntry, PMSIV_MENU_SetDecideEntry, PMSIV_MENU_IsEntryFinished, PMSIV_MENU_PressBackButton, PMSIV_MENU_IsBackButtonDone, PMSIV_MENU_CreateItems, PMSIV_MENU_DeleteItems, PMSIV_MENU_SetItemAnim, PMSIV_MENU_CreateExtraItems, PMSIV_MENU_DeleteExtraItems, PMSIV_MENU_CreateBackButton, PMSIV_MENU_ShowBackButton, PMSIV_MENU_ShowListEntries, PMSIV_MENU_LoadBlendColors, PMSIV_MENU_Reserved, PMSIV_MENU_UpdateBlend, PMSIV_MENU_StartItemBlend, PMSIV_MENU_StopItemBlend
 * address:  0x021BC990
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from pms_input_view.c, unit_021BB224.c, unit_021BB240.c, unit_021BB250.c, unit_021BB260.c, unit_021BB270.c, pmsiv_category.c, unit_021BBE80.c, pmsiv_menu.c, pmsiv_wordwin.c, pms_select_graphic.c, PMS_SELECT_GRAPHIC_ReadPointer.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   PMS_INPUT_GetUiInputModePtr 0x021BF6D4 thumb ov110
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   PMSIV_MENU_Delete 0x021BCA30 thumb ov110
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   PMSIV_MENU_Update 0x021BCA84 thumb ov110
 *   NNS_GfdRegisterNewVramTransferTask 0x02061CA4 arm
 *   PMS_INPUT_HasInitialSentence 0x021BF7C4 thumb ov110
 *   PMS_INPUT_GetInputMode 0x021BF6D8 thumb ov110
 *   PMSIV_MENU_Create 0x021BC990 thumb ov110
 *   PMSIV_MENU_ShowEditEntries 0x021BCB50 thumb ov110
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   PMSIV_MENU_UpdateItemHighlight 0x021BCCA8 thumb ov110
 *   PMSIV_MENU_UpdateEntryPalette 0x021BCD44 thumb ov110
 *   PMSIV_MENU_SetActiveEntry 0x021BCF7C thumb ov110
 *   PMSIV_MENU_ShowWordEntries 0x021BCC58 thumb ov110
 *   PMS_INPUT_GetBrowseMode 0x021BF6DC thumb ov110
 *   PMSIV_MENU_StartPress 0x021BCEE4 thumb ov110
 *   PMSIV_MENU_IsPressDone 0x021BCF38 thumb ov110
 *   PMSIV_MENU_FinishPress 0x021BCF70 thumb ov110
 *   PMSIV_MENU_PressBackButton 0x021BD000 thumb ov110
 *   PMSIV_MENU_IsBackButtonDone 0x021BD028 thumb ov110
 *   PMSIV_MENU_ShowOnlyBackButton 0x021BCC88 thumb ov110
 *   PMS_INPUT_GetInitialCount 0x021BF7FC thumb ov110
 *   PMSIV_MENU_SetDecideEntry 0x021BCFBC thumb ov110
 *   PMSIV_MENU_UpdateEntryPalettes 0x021BCD80 thumb ov110
 *   PMSIV_MENU_IsEntryFinished 0x021BCFF0 thumb ov110
 *   PMSIV_MENU_SelectItem 0x021BCF18 thumb ov110
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   PMS_INPUT_VIEW_GetFont 0x021BAC44 thumb ov110
 *   PMS_INPUT_VIEW_GetUiRes 0x021BAC64 thumb ov110
 *   PMS_INPUT_VIEW_CreateActor 0x021BAC78 thumb ov110
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   PMS_INPUT_VIEW_GetPrintQue 0x021BAC4C thumb ov110
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   PMS_INPUT_GetSentenceType 0x021BF6E4 thumb ov110
 *   gPmsivMenuHeapSite 0x021C3C68 data
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   APP_TASKMENU_WIN_ChangePalette 0x020282AC thumb
 *   gPmsivMenuItemAnimSeq 0x021C38DF data a1
 *   gPmsivMenuItemOrder 0x021C38D4 data a1
 *   PMS_INPUT_CanConfirm 0x021BF824 thumb ov110
 *   PMS_INPUT_GetSearchState 0x021BF808 thumb ov110
 *   APP_TASKMENU_WIN_ResetDecide 0x020282A4 thumb
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   gPmsivMenuExtraItems 0x021C38D9 data a1
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PMS_INPUT_VIEW_GetClactUnit 0x021BAC40 thumb ov110
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   APP_TASKMENU_RES_Create  0x02027F60  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb  arm9
 */

#include "pmsiv_menu_shared_types.h"

#define PMSIV_MENU_HEAP_ID 42

struct Unit;
struct MsgData;
struct Strbuf;
struct GfFont;
struct PrintQue;

typedef struct { u8 header[12]; u8 *colors; } PaletteFile;

#include "../arm9/gfl_heap_wrap.h"
#include "pms_input.h"
#include "../arm9/arc_tool.h"
struct MsgBank;
#include "../arm9/msgdata.h"
#include "../arm9/strbuf.h"
struct ClactActor;
#include "../arm9/clact.h"
#include "pms_input_view.h"
struct PrintQueue;
struct GFont;
struct TaskMenuRes;
#include "../arm9/app_taskmenu.h"
#include "../arm9/arc_util.h"
struct TaskMenuWin;
#include "../arm9/bg_sys.h"
struct TaskMenuItem;
#include "../arm9/app_icon.h"
#include "../arm9/mi_memory.h"
#include "../arm9/nns_gfd_vram_transfer.h"
extern short FX_SinCosTable_[];

struct PmsivMenuActorSetup { u16 x, y, z; u8 priority, mode; };

struct PmsivMenu *PMSIV_MENU_Create(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData);
void PMSIV_MENU_Delete(struct PmsivMenu *menu);
void PMSIV_MENU_Update(struct PmsivMenu *menu);
void PMSIV_MENU_HideAll(struct PmsivMenu *menu);
void PMSIV_MENU_ShowEditEntries(struct PmsivMenu *menu);
void PMSIV_MENU_ShowWordEntries(struct PmsivMenu *menu);
void PMSIV_MENU_ShowOnlyBackButton(struct PmsivMenu *menu);
void PMSIV_MENU_UpdateItemHighlight(struct PmsivMenu *menu);
void PMSIV_MENU_UpdateEntryPalette(struct PmsivMenu *menu);
void PMSIV_MENU_UpdateEntryPalettes(struct PmsivMenu *menu);
void PMSIV_MENU_PressEntry2(struct PmsivMenu *menu);
int PMSIV_MENU_IsEntry2Done(struct PmsivMenu *menu);
void PMSIV_MENU_PressBackItem(struct PmsivMenu *menu);
int PMSIV_MENU_IsBackItemDone(struct PmsivMenu *menu);
void PMSIV_MENU_FinishBackItem(struct PmsivMenu *menu);
void PMSIV_MENU_PressEntry1(struct PmsivMenu *menu);
int PMSIV_MENU_IsEntry1Done(struct PmsivMenu *menu);
void PMSIV_MENU_PressEntry0(struct PmsivMenu *menu);
int PMSIV_MENU_IsEntry0Done(struct PmsivMenu *menu);
void PMSIV_MENU_StartPress(struct PmsivMenu *menu, u32 mode);
void PMSIV_MENU_SelectItem(struct PmsivMenu *menu, int mode);
int PMSIV_MENU_IsPressDone(struct PmsivMenu *menu, u32 mode);
void PMSIV_MENU_FinishPress(struct PmsivMenu *menu, int i);
void PMSIV_MENU_SetActiveEntry(struct PmsivMenu *menu, int n, int v);
void PMSIV_MENU_SetDecideEntry(struct PmsivMenu *menu, u32 index, int value);
u32 PMSIV_MENU_IsEntryFinished(struct PmsivMenu *menu, u32 index);
int PMSIV_MENU_PressBackButton(struct PmsivMenu *menu);
int PMSIV_MENU_IsBackButtonDone(struct PmsivMenu *menu);
void PMSIV_MENU_CreateItems(struct PmsivMenu *menu);
void PMSIV_MENU_DeleteItems(struct PmsivMenu *menu);
void PMSIV_MENU_SetItemAnim(struct PmsivMenu *menu, int i, int flag);
void PMSIV_MENU_CreateExtraItems(struct PmsivMenu *menu);
void PMSIV_MENU_DeleteExtraItems(struct PmsivMenu *menu);
void PMSIV_MENU_CreateBackButton(struct PmsivMenu *menu);
void PMSIV_MENU_ShowBackButton(struct PmsivMenu *menu);
void PMSIV_MENU_ShowListEntries(struct PmsivMenu *menu);
void PMSIV_MENU_LoadBlendColors(struct PmsivMenu *menu);
void PMSIV_MENU_Reserved(struct PmsivMenu *menu);
void PMSIV_MENU_UpdateBlend(struct PmsivMenu *menu);
void PMSIV_MENU_StartItemBlend(struct PmsivMenu *menu, int i);
void PMSIV_MENU_StopItemBlend(struct PmsivMenu *menu, int i);

extern const char gPmsivMenuHeapSite[];
extern const u8 gPmsivMenuItemAnimSeq[],gPmsivMenuItemOrder[];
extern const u8 gPmsivMenuExtraItems[];

struct PmsivMenu *PMSIV_MENU_Create(struct PmsInputView *view, struct PmsInput *input, struct PmsInputData *wordData)
{
    struct PmsivMenu *menu;
    int i;
    struct GfFont *font;
    menu=GFL_HEAP_Alloc(PMSIV_MENU_HEAP_ID,sizeof(struct PmsivMenu),1,gPmsivMenuHeapSite,309);
    menu->view=view; menu->input=input; menu->wordData=wordData;
    menu->uiInputMode=PMS_INPUT_GetUiInputModePtr(input);
    menu->msgData=(struct MsgData *)MSGDATA_CreateFromArchive(0,2,146,PMSIV_MENU_HEAP_ID);
    for (i=0;i<PMSIV_MENU_TEXT_COUNT;i++) {
        font=PMS_INPUT_VIEW_GetFont(menu->view);
        menu->taskMenuRes[i]=(struct AppTaskMenuRes *)APP_TASKMENU_RES_Create(0,8,(struct GFont *)font,(struct PrintQueue *)(PMS_INPUT_VIEW_GetPrintQue(menu->view)),PMSIV_MENU_HEAP_ID);
    }
    ARC_UTIL_UploadPaletteFromArchiveWhole(43,9,0,448,64,PMSIV_MENU_HEAP_ID);
    PMSIV_MENU_CreateBackButton(menu);PMSIV_MENU_CreateItems(menu);PMSIV_MENU_CreateExtraItems(menu);PMSIV_MENU_LoadBlendColors(menu);
    return menu;
}

/*
 * extent: two bytes zero alignment padding after return.
 */
void PMSIV_MENU_Delete(struct PmsivMenu *menu)
{
    int i;
    PMSIV_MENU_HideAll(menu);
    CLACT_DeleteActor((struct ClactActor *)menu->backButton);
    CLACT_ReleasePalette(menu->backPalette);
    CLACT_ReleaseCharacter(menu->backCharacter);
    CLACT_ReleaseCellAnim(menu->backCellAnim);
    for (i=0;i<PMSIV_MENU_TEXT_COUNT;i++) APP_TASKMENU_RES_Delete((struct TaskMenuRes *)menu->taskMenuRes[i]);
    PMSIV_MENU_Reserved(menu); PMSIV_MENU_DeleteExtraItems(menu); PMSIV_MENU_DeleteItems(menu);
    MSGDATA_Delete((struct MsgBank *)menu->msgData);
    GFL_HEAP_Free(menu);
}

void PMSIV_MENU_Update(struct PmsivMenu *menu)
{
    int i;
    for (i=0;i<PMSIV_MENU_TEXT_COUNT;i++) if (menu->taskMenuWin[i]) APP_TASKMENU_WIN_Update((struct TaskMenuWin *)menu->taskMenuWin[i]);
    switch (menu->backButtonState) {
    case 0: break;
    case 1: menu->backButtonState=2;
    case 2: if (!CLACT_IsActorAnimActive((struct ClactActor *)menu->backButton)) menu->backButtonState=3; break;
    case 3: menu->backButtonState=0; break;
    }
    PMSIV_MENU_UpdateBlend(menu);
}

void PMSIV_MENU_HideAll(struct PmsivMenu *menu) {
    int i;
    for(i=0;i<PMSIV_MENU_TEXT_COUNT;i++) {
        if(menu->entries[i].text) { STRBUF_Delete(menu->entries[i].text); menu->entries[i].text=0; }
        if(menu->taskMenuWin[i]) { APP_TASKMENU_WIN_Delete((TaskMenuWin *)menu->taskMenuWin[i]); menu->taskMenuWin[i]=0; }
    }
    for(i=0;i<PMSIV_MENU_ITEM_COUNT;i++) CLACT_SetActorDrawEnable((struct ClactActor *)menu->items[i], 0);
    for(i=0;i<PMSIV_MENU_EXTRA_COUNT;i++) CLACT_SetActorDrawEnable((struct ClactActor *)menu->extraItems[i], 0);
    BG_SYS_PushTile(0);
    CLACT_SetActorDrawEnable((struct ClactActor *)menu->backButton, 0);
}

/*
 * lever: counter initialized before record-base assignment; existing
 *   a-loop-counter-zero-before-an-offset-assignment-schedules-before-its-spill.
 * evidence: own CAD8 establishes entries[3], taskMenuWin[3], items[8], extraItems[2]
 *   and their offsets. Both loops use indices0..1; all selected fields are
 *   in those arrays. Stores/pointers keep original call order and word width.
 * abi: F7C4 own void thunk tail-forwards input00 to ARM9 24158; full
 *   8-byte target returns byte03 bit2 (0/1), consumed by original CB50.
 *   27FEC fourth argument explicitly truncated to u8 by original caller.
 */
void PMSIV_MENU_ShowEditEntries(struct PmsivMenu *menu)
{
    int i;
    struct PmsivMenuEntry *entries;
    PMSIV_MENU_HideAll(menu);
    i=0;
    entries=menu->entries;
    for(;i<2;i++) {
        menu->entries[i].text=MSGDATA_AllocString((struct MsgBank *)menu->msgData,i+14);
        menu->entries[i].color=0x39e3;
        menu->entries[i].selected=(i==1);
        menu->taskMenuWin[i]=(struct AppTaskMenuWin *)APP_TASKMENU_WIN_Create((struct TaskMenuRes *)menu->taskMenuRes[i],(struct TaskMenuItem *)(&entries[i]),23,(u8)(i*3+18),9,PMSIV_MENU_HEAP_ID);
        APP_TASKMENU_WIN_ChangePalette((struct TaskMenuWin *)menu->taskMenuWin[i],(struct TaskMenuRes *)menu->taskMenuRes[i],8,0x3545,0x7b2c);
    }
    PMSIV_MENU_UpdateEntryPalette(menu);
    BG_SYS_PushTile(0);
    if(PMS_INPUT_HasInitialSentence(menu->input)==0 && PMS_INPUT_GetInputMode(menu->input)==2) {
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->items[0], 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->items[1], 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->items[2], 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->items[3], 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->items[4], 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->items[5], 1);
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->items[6], 1);
        for(i=0;i<2;i++) CLACT_SetActorDrawEnable((struct ClactActor *)menu->extraItems[i], 1);
    }
    PMSIV_MENU_UpdateItemHighlight(menu);
}

void PMSIV_MENU_ShowWordEntries(struct PmsivMenu *menu)
{
    PMSIV_MENU_HideAll(menu);
    CLACT_SetActorDrawEnable((struct ClactActor *)menu->items[7], 1);
    if (PMS_INPUT_GetBrowseMode(menu->input) == 0) PMSIV_MENU_ShowBackButton(menu);
    else PMSIV_MENU_ShowListEntries(menu);
}

void PMSIV_MENU_ShowOnlyBackButton(struct PmsivMenu *menu)
{
    PMSIV_MENU_HideAll(menu);
    CLACT_SetActorDrawEnable((struct ClactActor *)menu->backButton, 1);
    CLACT_SetActorAnimSeq((struct ClactActor *)menu->backButton, 1);
    menu->backButtonState = 0;
}

void PMSIV_MENU_UpdateItemHighlight(struct PmsivMenu *menu) {
    int old,new;
    int selected;
    int i;
    int state;
    old=-1; new=-1;
    selected=PMS_INPUT_GetSentenceType(menu->input);
    for(i=1;i<=5;i++) {
        state=CLACT_GetActorAnimSeq((struct ClactActor *)menu->items[i]);
        if(state==gPmsivMenuItemAnimSeq[i*2+1]) { old=i; break; }
    }
    for(i=0;i<5;i++) {
        if(i==selected) { new=gPmsivMenuItemOrder[i]; break; }
    }
    if(old>=0 && old!=new) PMSIV_MENU_StopItemBlend(menu,old);
    for(i=0;i<5;i++) PMSIV_MENU_SetItemAnim(menu,gPmsivMenuItemOrder[i],i==selected);
    if(new>=0 && old!=new) PMSIV_MENU_StartItemBlend(menu,new);
}

/*
 * Reads r0 after BF824 and supplies p+4; preserve return and visible argument.
 */
void PMSIV_MENU_UpdateEntryPalette(struct PmsivMenu *menu)
{
    if (PMS_INPUT_CanConfirm(menu->input) != 0) {
        APP_TASKMENU_WIN_ChangePalette((struct TaskMenuWin *)menu->taskMenuWin[0], (struct TaskMenuRes *)menu->taskMenuRes[0], 8, 0x3545, 0x7b2c);
    } else {
        APP_TASKMENU_WIN_ChangePalette((struct TaskMenuWin *)menu->taskMenuWin[0], (struct TaskMenuRes *)menu->taskMenuRes[0], 14, 0x3545, 0x7b2c);
    }
}

void PMSIV_MENU_UpdateEntryPalettes(struct PmsivMenu *menu) {
    if (PMS_INPUT_GetInitialCount(menu->input))
        APP_TASKMENU_WIN_ChangePalette((struct TaskMenuWin *)menu->taskMenuWin[0],(struct TaskMenuRes *)menu->taskMenuRes[0],8,0x3545,0x7b2c);
    else
        APP_TASKMENU_WIN_ChangePalette((struct TaskMenuWin *)menu->taskMenuWin[0],(struct TaskMenuRes *)menu->taskMenuRes[0],14,0x3545,0x7b2c);
    if (PMS_INPUT_GetSearchState(menu->input))
        APP_TASKMENU_WIN_ChangePalette((struct TaskMenuWin *)menu->taskMenuWin[1],(struct TaskMenuRes *)menu->taskMenuRes[1],8,0x3545,0x7b2c);
    else
        APP_TASKMENU_WIN_ChangePalette((struct TaskMenuWin *)menu->taskMenuWin[1],(struct TaskMenuRes *)menu->taskMenuRes[1],14,0x3545,0x7b2c);
}

void PMSIV_MENU_PressEntry2(struct PmsivMenu *menu)
{
    if (PMS_INPUT_GetBrowseMode(menu->input) == 1) PMSIV_MENU_SetDecideEntry(menu, 2, 1);
}

int PMSIV_MENU_IsEntry2Done(struct PmsivMenu *menu) {
    if (PMS_INPUT_GetBrowseMode(menu->input)==1) {
        if (PMSIV_MENU_IsEntryFinished(menu,2)) return 1;
        return 0;
    }
    return 1;
}

void PMSIV_MENU_PressBackItem(struct PmsivMenu *menu) {
    PMSIV_MENU_SetItemAnim(menu,7,1);
}

int PMSIV_MENU_IsBackItemDone(struct PmsivMenu *menu) {
    if (CLACT_IsActorAnimActive((struct ClactActor *)menu->items[7])==0) return 1;
    return 0;
}

void PMSIV_MENU_FinishBackItem(struct PmsivMenu *menu) {
    PMSIV_MENU_SetItemAnim(menu, 7, 0);
}

/*
 * Extent ends in two-byte alignment padding at 0x021BCE6E.
 */
void PMSIV_MENU_PressEntry1(struct PmsivMenu *menu) {
    if (PMS_INPUT_GetBrowseMode(menu->input)==1) PMSIV_MENU_SetDecideEntry(menu,1,1);
}

int PMSIV_MENU_IsEntry1Done(struct PmsivMenu *menu) {
    int result;
    if (PMS_INPUT_GetBrowseMode(menu->input)==1) {
        result=1;
        if (PMSIV_MENU_IsEntryFinished(menu,1)) {
            APP_TASKMENU_WIN_ResetDecide((struct TaskMenuWin *)menu->taskMenuWin[1]);
            return result;
        }
    } else {
        return 1;
    }
    return 0;
}

/*
 * Extent ends in two-byte alignment padding at 0x021BCEBA.
 */
void PMSIV_MENU_PressEntry0(struct PmsivMenu *menu) {
    if (PMS_INPUT_GetBrowseMode(menu->input)==1) PMSIV_MENU_SetDecideEntry(menu,0,1);
}

static inline int Check(struct PmsivMenu *menu, int zero)
{
    u32 value;
    value = PMSIV_MENU_IsEntryFinished(menu, zero);
    menu = 0;
    if (value) menu = (struct PmsivMenu *)1;
    return (sptr)menu;
}

/*
 * extent: 38-byte function followed by two zero alignment bytes.
 * lever: inline helper reuses its dying pointer for the zero/one result;
 *   zero assignment remains explicit, and the allocator shares r4.
 */
int PMSIV_MENU_IsEntry0Done(struct PmsivMenu *menu)
{
    if (PMS_INPUT_GetBrowseMode(menu->input)==1) {
        return Check(menu, 0);
    }
    return 1;
}

/*
 * Extent ends in two-byte alignment padding at 0x021BCF16.
 */
void PMSIV_MENU_StartPress(struct PmsivMenu *menu, u32 mode) {
    switch(mode) {
    case 0: PMSIV_MENU_PressEntry2(menu); break;
    case 1: PMSIV_MENU_PressBackItem(menu); break;
    case 2: PMSIV_MENU_PressEntry1(menu); break;
    case 3: PMSIV_MENU_PressEntry0(menu); break;
    }
}

void PMSIV_MENU_SelectItem(struct PmsivMenu *menu, int mode) {
    switch(mode) {
    case 0: PMSIV_MENU_SetItemAnim(menu,0,1); break;
    case 1: PMSIV_MENU_SetItemAnim(menu,6,1); break;
    }
}

int PMSIV_MENU_IsPressDone(struct PmsivMenu *menu, u32 mode) {
    switch(mode) {
    case 0: return PMSIV_MENU_IsEntry2Done(menu);
    case 1: return PMSIV_MENU_IsBackItemDone(menu);
    case 2: return PMSIV_MENU_IsEntry1Done(menu);
    case 3: return PMSIV_MENU_IsEntry0Done(menu);
    }
    return 1;
}

void PMSIV_MENU_FinishPress(struct PmsivMenu *menu, int i) {
    if (i == 1) {
        PMSIV_MENU_FinishBackItem(menu);
    }
}

/*
 * extent: two zero padding bytes at 0x021BCFBA.
 */
void PMSIV_MENU_SetActiveEntry(struct PmsivMenu *menu, int n, int v) {
    int i;
    struct AppTaskMenuWin **a = menu->taskMenuWin;
    if (a[n]) {
        for (i = 0; i < PMSIV_MENU_TEXT_COUNT; i++) {
            if (menu->taskMenuWin[i]) APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)menu->taskMenuWin[i], 0);
        }
        APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)a[n], v);
    }
}

void PMSIV_MENU_SetDecideEntry(struct PmsivMenu *menu, u32 index, int value) {
    int i;
    for(i=0;i<PMSIV_MENU_TEXT_COUNT;i++) {
        if (menu->taskMenuWin[i]) APP_TASKMENU_WIN_SetActive((struct TaskMenuWin *)menu->taskMenuWin[i],0);
    }
    if (menu->taskMenuWin[index]) APP_TASKMENU_WIN_SetDecide((struct TaskMenuWin *)menu->taskMenuWin[index],value);
}

u32 PMSIV_MENU_IsEntryFinished(struct PmsivMenu *menu, u32 index) {
    return APP_TASKMENU_WIN_IsFinish((struct TaskMenuWin *)menu->taskMenuWin[index]);
}

/*
 * Extent ends in two-byte alignment padding at 0x021BD026.
 */
int PMSIV_MENU_PressBackButton(struct PmsivMenu *menu) {
    if (CLACT_GetActorDrawEnable((struct ClactActor *)menu->backButton) && menu->backButtonState==0) {
        CLACT_SetActorAnimSeq((struct ClactActor *)menu->backButton, 9);
        menu->backButtonState=1;
        return 1;
    }
    return 0;
}

int PMSIV_MENU_IsBackButtonDone(struct PmsivMenu *menu)
{
    if(CLACT_GetActorDrawEnable((struct ClactActor *)menu->backButton) && menu->backButtonState!=3) return 0;
    return 1;
}

void PMSIV_MENU_CreateItems(struct PmsivMenu *menu) {
    void *handle;
    int i;
    short x;
    handle=ARC_TOOL_CreateHandle(43,PMSIV_MENU_HEAP_ID);
    PMS_INPUT_VIEW_GetUiRes(menu->view, &menu->itemRes, 0, 0);
    menu->itemRes.character=CLACT_RegisterCharacter(handle,13,0,0,PMSIV_MENU_HEAP_ID);
    menu->itemRes.cellAnim=CLACT_RegisterCellAnim(handle,35,41,PMSIV_MENU_HEAP_ID);
    ARC_TOOL_DeleteHandle(handle);
    for(i=0;i<PMSIV_MENU_ITEM_COUNT;i++) {
        x=24*i;
        if(i==7) x=0;
        menu->items[i]=PMS_INPUT_VIEW_CreateActor(menu->view, &menu->itemRes, (int)x, (int)168, (int)0, 1);
        PMSIV_MENU_SetItemAnim(menu,i,0);
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->items[i], 0);
    }
}

void PMSIV_MENU_DeleteItems(struct PmsivMenu *menu)
{
    int i;
    for(i=0;i<PMSIV_MENU_ITEM_COUNT;i++) CLACT_DeleteActor((struct ClactActor *)menu->items[i]);
    CLACT_ReleaseCharacter(menu->itemRes.character);
    CLACT_ReleaseCellAnim(menu->itemRes.cellAnim);
}

/*
 * lever: integer table-base arithmetic forms table+i*2 before adding flag;
 * gPmsivMenuItemAnimSeq[i*2+flag] combined the two indices first (11 concrete bytes differed).
 */
void PMSIV_MENU_SetItemAnim(struct PmsivMenu *menu,int i,int flag)
{
    CLACT_SetActorAnimSeq((struct ClactActor *)menu->items[i], *(u8 *)((uptr)gPmsivMenuItemAnimSeq+i*2+flag));
}

void PMSIV_MENU_CreateExtraItems(struct PmsivMenu *menu) {
    u8 i;
    for(i=0;i<PMSIV_MENU_EXTRA_COUNT;i++) {
        menu->extraItems[i]=PMS_INPUT_VIEW_CreateActor(menu->view, &menu->itemRes, (int)(gPmsivMenuExtraItems[3*i]), (int)(gPmsivMenuExtraItems[3*i+1]), (int)0, 1);
        CLACT_SetActorAnimSeq((struct ClactActor *)menu->extraItems[i], gPmsivMenuExtraItems[3*i+2]);
        CLACT_SetActorDrawEnable((struct ClactActor *)menu->extraItems[i], 0);
    }
}

void PMSIV_MENU_DeleteExtraItems(struct PmsivMenu *menu)
{
    u8 i;
    for(i=0;i<PMSIV_MENU_EXTRA_COUNT;i++) CLACT_DeleteActor((struct ClactActor *)menu->extraItems[i]);
}

void PMSIV_MENU_CreateBackButton(struct PmsivMenu *menu) {
    void *handle;
    int cellFileId;
    struct PmsivMenuActorSetup setup;
    handle=ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(),PMSIV_MENU_HEAP_ID);
    menu->backPalette=CLACT_RegisterPaletteEx(handle,APP_ICON_GetMoveKindPaletteFileId(),0,384,0,3,PMSIV_MENU_HEAP_ID);
    menu->backCharacter=CLACT_RegisterCharacter(handle,APP_ICON_GetMoveKindAnimFileId(),0,0,PMSIV_MENU_HEAP_ID);
    cellFileId=APP_ICON_GetStatusCellFileId(1);
    menu->backCellAnim=CLACT_RegisterCellAnim(handle,cellFileId,APP_ICON_GetStatusPaletteFileId(1),PMSIV_MENU_HEAP_ID);
    ARC_TOOL_DeleteHandle(handle);
    MI_CpuFill8(&setup,0,8);
    setup.x=232; setup.y=168; setup.z=1; setup.priority=0; setup.mode=3;
    menu->backButton=CLACT_CreateActor((struct Unit *)PMS_INPUT_VIEW_GetClactUnit(menu->view),menu->backCharacter,menu->backPalette,menu->backCellAnim,(const struct ActorInitParam *)&setup,0,PMSIV_MENU_HEAP_ID);
    CLACT_SetActorAutoAnim((struct ClactActor *)menu->backButton,1);
    CLACT_SetActorDrawEnable((struct ClactActor *)menu->backButton, 0);
    menu->backButtonState=0;
}

/*
 * Extent remainder: two-byte zero alignment padding.
 */
void PMSIV_MENU_ShowBackButton(struct PmsivMenu *menu)
{
    CLACT_SetActorDrawEnable((struct ClactActor *)menu->backButton, 1);
    CLACT_SetActorAnimSeq((struct ClactActor *)menu->backButton, 1);
    menu->backButtonState=0;
}

void PMSIV_MENU_ShowListEntries(struct PmsivMenu *menu) {
    int i;
    for(i=0;i<PMSIV_MENU_TEXT_COUNT;i++) {
        menu->entries[i].text=MSGDATA_AllocString((struct MsgBank *)menu->msgData,i+18);
        menu->entries[i].color=0x39e3;
        menu->entries[i].selected=i==2;
        menu->taskMenuWin[i]=(struct AppTaskMenuWin *)APP_TASKMENU_WIN_Create((struct TaskMenuRes *)menu->taskMenuRes[i],(struct TaskMenuItem *)(&menu->entries[i]),(u8)(5+9*i),(int)21,9,PMSIV_MENU_HEAP_ID);
        APP_TASKMENU_WIN_ChangePalette((struct TaskMenuWin *)menu->taskMenuWin[i],(struct TaskMenuRes *)menu->taskMenuRes[i],8,0x3545,0x7b2c);
    }
    PMSIV_MENU_UpdateEntryPalettes(menu);
    BG_SYS_PushTile(0);
}

/*
 * extent: two zero padding bytes at 0x021BD342.
 */
void PMSIV_MENU_LoadBlendColors(struct PmsivMenu *menu) {
    PaletteFile *file;
    void *handle;
    u8 *data;
    handle = ARC_UTIL_LoadPaletteBlockFromArchive(43, 7, (&file), PMSIV_MENU_HEAP_ID);
    data = file->colors;
    MI_CpuCopy8(data + 0x96, menu->baseColors, 10);
    MI_CpuCopy8(data + 0x76, menu->targetColors, 10);
    GFL_HEAP_Free(handle);
    MI_CpuCopy8(menu->baseColors, menu->blendColors, 10);
    menu->blendPhase = 0;
}

void PMSIV_MENU_Reserved(struct PmsivMenu *menu) { }

static inline void lerp(u16 *p, int n, u16 a, u16 b)
{
 u8 r,g,blue; int dr,dg,db;
 g=(a&0x3E0)>>5;
 r=a&31;
 blue=(a&0x7C00)>>10;
 db=((u8)((b&0x7C00)>>10)-blue)*n>>12;
 dr=((u8)(b&31)-r)*n>>12;
 dg=((u8)((b&0x3E0)>>5)-g)*n>>12;
 *p=(u8)(r+dr)|((u8)(g+dg)<<5)|((u8)(blue+db)<<10);
}

/*
 * lever: the RGB555 lerp is a static inline helper (u16 colour params, as ov105 IRC_RESULT_BlendPaletteEntry)
 */
void PMSIV_MENU_UpdateBlend(struct PmsivMenu *menu)
{
    int j;
    short t;
    u8 i;
    if (menu->blendPhase + 0x400 >= 0x10000)
        menu->blendPhase = menu->blendPhase - 0xFC00;
    else
        menu->blendPhase = menu->blendPhase + 0x400;
    j = menu->blendPhase >> 4;
    t = (FX_SinCosTable_[j * 2 + 1] + 0x1000) / 2;
    for (i = 0; i < PMSIV_MENU_BLEND_COLORS; i++) {
        lerp(&menu->blendColors[i], t, menu->baseColors[i], menu->targetColors[i]);
    }
    NNS_GfdRegisterNewVramTransferTask(14, (unsigned int)0x56, menu->blendColors, 10);
}

void PMSIV_MENU_StartItemBlend(struct PmsivMenu *menu,int i)
{
    CLACT_SetActorPaletteOffset((struct ClactActor *)menu->items[i],2,1);
    MI_CpuCopy8(menu->baseColors,menu->blendColors,10);
    menu->blendPhase=0;
}

void PMSIV_MENU_StopItemBlend(struct PmsivMenu *menu,int i)
{
    CLACT_SetActorPaletteOffset((struct ClactActor *)menu->items[i],6,1);
}
