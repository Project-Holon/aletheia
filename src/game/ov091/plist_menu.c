/*
 * file:     plist_menu.c
 * unit:     yes
 * function: PLIST_MENU_Create, PLIST_MENU_Delete, PLIST_MENU_Open, PLIST_MENU_OpenFixed, PLIST_MENU_Close, PLIST_MENU_Update, PLIST_MENU_GetSelectedCommand, PLIST_MENU_BuildCommandList, PLIST_MENU_CreateCommandLabel, PLIST_MENU_CreateButtonWindow, PLIST_MENU_DeleteTaskMenuWin, PLIST_MENU_UpdateTaskMenuWin, PLIST_MENU_SetTaskMenuWinActive, PLIST_MENU_ButtonWinSetDecide, PLIST_MENU_GetItemUseKind, PLIST_MENU_IsSpecialItemKind, PLIST_MENU_ItemRestoresHp, PLIST_MENU_FindItemTarget, PLIST_MENU_GetItemUseMessage, PLIST_MENU_ApplyArceusPlateForm, PLIST_MENU_ApplyGenesectDriveForm, PLIST_MENU_ShowItemUsedThenClose, PLIST_MENU_ShowItemUsedThenContinue, PLIST_MENU_StartItemUse, PLIST_MENU_ShowHpRestored, PLIST_MENU_ShowItemResult, PLIST_MENU_UseItemOnFoundTarget, PLIST_MENU_BeginLevelUpMoveWait, PLIST_MENU_BeginExitWait, PLIST_MENU_UpdateLevelUp, PLIST_MENU_HasMonParam, PLIST_MENU_ShowMonMessage, PLIST_MENU_ShowMonValueMessage, PLIST_MENU_InitTimer, PLIST_MENU_ExitTimer, PLIST_MENU_UpdateTimer, PLIST_MENU_CreateBank, PLIST_MENU_DeleteBank, PLIST_MENU_LoadResources, PLIST_MENU_Nop
 * address:  0x021BBA8C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 *   func_020355D8  0x020355D8  arm
 *   UI_GetInputMode  0x020355C4  arm
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   SHINKA_CHECK_CheckEvolution 0x0201B2B0 thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   POKE_TOOL_CalcLevel  0x02018430  thumb
 *   BMP_FillRect  0x02043AF4  arm
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm
 *   ARC_UTIL_LoadBgCharDataFromArchive  0x02049DB4  arm
 *   gPlistMenuAllocSite     0x021BED38  data  ov091  a1
 *   APP_TASKMENU_OpenMenu  0x02027778  thumb
 *   gPlistMenuFixedItems     0x021BEC80  data  a4
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_UpdateMenu  0x02027974  thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   gPlistMenuLabelMsgIds     0x021BEC8C  data  ov091  a4
 *   APP_TASKMENU_WIN_Create  0x02027FEC  thumb
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb
 *   APP_TASKMENU_WIN_SetDecide  0x0202822C  thumb
 *   FILE_UTIL_CreateArcTool0F34 0x02020F34 thumb
 *   FILE_UTIL_Get_1014 0x02021014 thumb
 *   FILE_UTIL_Get_0FE4 0x02020FE4 thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKE_TOOL_GetPlateTypeForwarder 0x02019CF8 thumb
 *   POKE_TOOL_ChangeForm 0x02017988 thumb
 *   POKE_TOOL_GetBoxParamIndex  0x02019D00  thumb
 *   GAME_BEACON_SetPokeLevelUp 0x02027268 thumb
 *   gPlistStatParamIds 0x021BECE4 data ov091 a2
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   GF_FONT_MeasureWidestLine 0x0201D304 thumb
 *   POKE_TOOL_GetLevelUpMove 0x02018328 thumb
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   APP_ICON_GetItemCellFileId 0x02027694 thumb
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   APP_ICON_GetItemPaletteFileId 0x02027698 thumb
 *   APP_ICON_GetItemAnimFileId 0x0202769C thumb
 *   APP_ICON_GetItemFrameFileId 0x020276A0 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   POKELIST_ShowMessage  0x021B9788  thumb
 *   POKELIST_GetFieldMoveMenuIndex  0x021B99E4  thumb
 *   POKELIST_CloseMessageToList  0x021B9E20  thumb
 *   POKELIST_EndMessageToExit  0x021B9E3C  thumb
 *   POKELIST_CloseMessageIfItemInBag  0x021B9E44  thumb
 *   POKELIST_OpenGiveUpMoveMenu  0x021B9EB0  thumb
 *   POKELIST_ForceSelectionEnd  0x021BA4F8  thumb
 *   PLIST_PLATE_SetPalette  0x021BB050  thumb
 *   PLIST_PLATE_Redraw  0x021BB2C0  thumb
 *   PLIST_PLATE_GetLabelState  0x021BB43C  thumb
 *   PLIST_PLATE_GetHp  0x021BB464  thumb
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb
 *   PLIST_MESSAGE_CreateWordSet  0x021BB97C  thumb
 *   PLIST_MESSAGE_DestroyWordSet  0x021BB98C  thumb
 *   PLIST_MESSAGE_SetWordSetPokemon  0x021BB99C  thumb
 *   PLIST_MESSAGE_SetWordSetItem  0x021BB9AC  thumb
 *   PLIST_MESSAGE_SetWordSetMove  0x021BB9CC  thumb
 *   PLIST_MESSAGE_SetWordSetValue  0x021BB9DC  thumb
 *   PLIST_MESSAGE_SetWordSetNumber  0x021BB9EC  thumb
 *   PLIST_MESSAGE_DrawKeyCursorMark  0x021BBA70  thumb
 *   PLIST_BATTLE_CreateTeamPanel  0x021BD05C  thumb
 *   PLIST_BATTLE_DeleteTeamPanel  0x021BD18C  thumb
 *   PLIST_BATTLE_UpdateTeamPanel  0x021BD1BC  thumb
 *   PLIST_BATTLE_PrintOpponentMessage  0x021BD504  thumb
 *   PLIST_BATTLE_CreateTimerWindows  0x021BD59C  thumb
 *   PLIST_BATTLE_DeleteTimerWindows  0x021BD61C  thumb
 *   PLIST_BATTLE_UpdateTimer  0x021BD634  thumb
 *   PLIST_DEMO_CheckItemUsable  0x021BDD78  thumb
 *   PLIST_DEMO_UseItemOnMon  0x021BE2B4  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
typedef signed int s32;

#include "pokelist_types.h"
#include "plist_menu_types.h"

struct MsgBank;
struct Descriptor;
struct WordSet;
struct Strbuf;
struct TaskMenu;
struct Bank;

/* Palette RAM slot the timer palette is copied to. */
#define TIMER_PALETTE_DST ((void *)0x05000440)

#define MENU_APPEND(v) do { menu->ids[menu->count] = (v); menu->count++; } while (0)
#define ITEM_PARAM(k) FILE_UTIL_Get_1014(itemData, (k))
#define ITEM_DONE(k) {GFL_HEAP_Free(itemData);return(k);}
#define DESC ((struct Descriptor *)work->descriptor)

extern void GFL_USE_PlaySeDefaultVolume(u32 id);
extern void BG_SYS_SetFlagField06(u32 bit);
extern void func_020355D8(int mode);
extern u8 UI_GetInputMode(void);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 param, u32 extra);
extern u32 GFL_HEAP_Free(void *p);
extern void *POKEPARTY_GetMember(void *party, u32 index);
extern unsigned KEY_GetTrg(void);
extern int TOUCHPANEL_GetTrg(void);
extern u32 SHINKA_CHECK_CheckEvolution(void *party, void *mon, u32 a, u32 b, u8 season, u32 *out, u16 heapId);
extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *printSys, void *bmp, short x, short y, struct Strbuf *str, void *font, u16 flags);
extern void STRBUF_Delete(struct Strbuf *str);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, struct Strbuf *dst, struct Strbuf *src);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern u32 BMP_WIN_Create(int,u8,u8,int,u8,u8,u8);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern u32 PRINTSYS_QUE_IsExistTarget(void *printSys, void *bmp);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void ARC_TOOL_DeleteHandle(void *a);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 POKE_TOOL_CalcLevel(void *p);
extern void BMP_FillRect(void *bmp, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BMP_Clear(void *charBuf, u8 value);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern u32 APP_ICON_GetArchiveId(void);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *ARC_UTIL_LoadBgCharDataFromArchive(u32 a0, u32 a1, u32 a2, void **out, u16 a4);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(const PlistTaskMenuTemplate *tmpl, void *arg1);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
void APP_TASKMENU_UpdateMenu(struct TaskMenu *m);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(const struct TaskMenu *m);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 APP_TASKMENU_WIN_Create(u32 a0, const PlistMenuEntry *entry, u32 a2, u32 a3, u8 a4, u16 a5);
extern void APP_TASKMENU_WIN_Delete(void *win);
extern void APP_TASKMENU_WIN_Update(void *win);
extern void APP_TASKMENU_WIN_SetActive(void *win, u32 a);
void APP_TASKMENU_WIN_SetDecide(void *win, int v);
extern void *FILE_UTIL_CreateArcTool0F34(u32 item, u32 which, u32 heap);
extern u32 FILE_UTIL_Get_1014(void *itemData, u32 param);
extern unsigned int FILE_UTIL_Get_0FE4(u32 itemId, unsigned int param, unsigned int heapId);
extern u32 POKEPARTY_GetCount(void *party);
extern unsigned int POKE_TOOL_GetPlateTypeForwarder(unsigned int item);
extern u32 POKE_TOOL_ChangeForm(void *mon, u32 form);
extern u32 POKE_TOOL_GetBoxParamIndex(u32 id);
extern void GAME_BEACON_SetPokeLevelUp(int);
extern u32 GF_FONT_MeasureWidestLine(struct Strbuf *s, void *font, u32 b);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u16 POKE_TOOL_GetLevelUpMove(void *p, u32 *idx, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 APP_ICON_GetItemCellFileId(void);
extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern u32 APP_ICON_GetItemPaletteFileId(void);
extern u32 APP_ICON_GetItemAnimFileId(u32);
extern u32 APP_ICON_GetItemFrameFileId(u32);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void MIi_CpuCopy16(void *, void *, unsigned long);

void POKELIST_ShowMessage(PokelistWork *work, int msgId, int waitInput, PokelistFn callback);
int POKELIST_GetFieldMoveMenuIndex(void *mon, int i);
void POKELIST_CloseMessageToList(PokelistWork *work);
void POKELIST_EndMessageToExit(PokelistWork *work);
void POKELIST_CloseMessageIfItemInBag(PokelistWork *work);
void POKELIST_OpenGiveUpMoveMenu(PokelistWork *work);
void POKELIST_ForceSelectionEnd(PokelistWork *work);
void PLIST_PLATE_SetPalette(PokelistWork *work, u8 *plate, int k);
void PLIST_PLATE_Redraw(PokelistWork *work, u8 *plate);
int PLIST_PLATE_GetLabelState(int *plate);
unsigned short PLIST_PLATE_GetHp(PokelistWork *work, unsigned short *plate);
void PLIST_MESSAGE_CloseWindow(PokelistWork *work, u32 *window);
void PLIST_MESSAGE_CreateWordSet(PokelistWork *work, u32 window);
void PLIST_MESSAGE_DestroyWordSet(PokelistWork *work, u32 window);
void PLIST_MESSAGE_SetWordSetPokemon(PokelistWork *work, u32 window, int slot, u32 value);
void PLIST_MESSAGE_SetWordSetItem(PokelistWork *work, u32 window, int slot, int value);
void PLIST_MESSAGE_SetWordSetMove(PokelistWork *work, u32 window, int slot, int value);
void PLIST_MESSAGE_SetWordSetValue(PokelistWork *work, u32 window, int slot, int value);
void PLIST_MESSAGE_SetWordSetNumber(PokelistWork *work, u32 window, int slot, int value, unsigned char digits);
void PLIST_MESSAGE_DrawKeyCursorMark(PokelistWork *work, u32 window);
PlistMenu *PLIST_MENU_Create(PokelistWork *work);
void PLIST_MENU_Delete(PokelistWork *work, PlistMenu *menu);
void PLIST_MENU_Open(PokelistWork *work, PlistMenu *menu, int *items);
void PLIST_MENU_OpenFixed(PokelistWork *work, PlistMenu *menu);
void PLIST_MENU_Close(PokelistWork *work, PlistMenu *menu);
void PLIST_MENU_Update(PokelistWork *work, PlistMenu *menu);
unsigned int PLIST_MENU_GetSelectedCommand(PokelistWork *work, PlistMenu *menu);
void PLIST_MENU_BuildCommandList(PokelistWork *work, PlistMenu *menu, int *items);
struct Strbuf *PLIST_MENU_CreateCommandLabel(PokelistWork *work, PlistMenu *menu, int id);
int PLIST_MENU_CreateButtonWindow(PokelistWork *work, int unused, int id, int x, u8 y, int disabled);
void PLIST_MENU_DeleteTaskMenuWin(void *win);
void PLIST_MENU_UpdateTaskMenuWin(void *win);
void PLIST_MENU_SetTaskMenuWinActive(void *win, int active);
void PLIST_MENU_ButtonWinSetDecide(void *win, int value);
int PLIST_MENU_GetItemUseKind(int itemId);
int PLIST_MENU_IsSpecialItemKind(PokelistWork *work, int itemId);
int PLIST_MENU_ItemRestoresHp(PokelistWork *work, u32 itemId);
int PLIST_MENU_FindItemTarget(PokelistWork *work);
int PLIST_MENU_GetItemUseMessage(PokelistWork *work, int itemId);
void PLIST_MENU_ApplyArceusPlateForm(void *unused, void *mon, int itemId);
void PLIST_MENU_ApplyGenesectDriveForm(int unused, void *mon, int itemId);
void PLIST_MENU_ShowItemUsedThenClose(PokelistWork *work);
void PLIST_MENU_ShowItemUsedThenContinue(PokelistWork *work);
int PLIST_MENU_StartItemUse(PokelistWork *work, int v);
void PLIST_MENU_ShowHpRestored(PokelistWork *work);
void PLIST_MENU_ShowItemResult(PokelistWork *work);
void PLIST_MENU_UseItemOnFoundTarget(PokelistWork *work);
void PLIST_MENU_BeginLevelUpMoveWait(PokelistWork *work);
void PLIST_MENU_BeginExitWait(PokelistWork *work);
void PLIST_MENU_UpdateLevelUp(PokelistWork *work);
int PLIST_MENU_HasMonParam(void *mon, int param, int unused);
void PLIST_MENU_ShowMonMessage(PokelistWork *work, int msgId);
void PLIST_MENU_ShowMonValueMessage(PokelistWork *work, int msgId, int value);
void PLIST_MENU_InitTimer(PokelistWork *work);
void PLIST_MENU_ExitTimer(PokelistWork *work);
void PLIST_MENU_UpdateTimer(PokelistWork *work);
void PLIST_MENU_CreateBank(PokelistWork *work);
void PLIST_MENU_DeleteBank(PokelistWork *work);
void PLIST_MENU_LoadResources(PokelistWork *work);
void PLIST_MENU_Nop(PokelistWork *work);
int PLIST_BATTLE_CreateTeamPanel(PokelistWork *work, PokelistRivalEntry *entry, u8 x, u8 y, u8 w);
void PLIST_BATTLE_DeleteTeamPanel(PokelistWork *work, int digit);
void PLIST_BATTLE_UpdateTeamPanel(PokelistWork *work, int digit);
void PLIST_BATTLE_PrintOpponentMessage(PokelistWork *work);
void PLIST_BATTLE_CreateTimerWindows(PokelistWork *work);
void PLIST_BATTLE_DeleteTimerWindows(PokelistWork *work);
void PLIST_BATTLE_UpdateTimer(PokelistWork *work);
int PLIST_DEMO_CheckItemUsable(void *mon, u32 itemId, int slot, u32 heap);
int PLIST_DEMO_UseItemOnMon(void *mon, u16 item, u16 moveSlot, u16 arg, int heap);

extern const char gPlistMenuAllocSite[];
extern PlistMenuItemList gPlistMenuFixedItems;
extern int gPlistMenuLabelMsgIds[];
extern u16 gPlistStatParamIds[];

PlistMenu *PLIST_MENU_Create(PokelistWork *work)
{
    PlistMenu *menu;

    menu = GFL_HEAP_Alloc(work->heapId, sizeof(PlistMenu), 0, gPlistMenuAllocSite, 0x63);
    ARC_UTIL_UploadPaletteFromArchiveWhole(APP_ICON_GetArchiveId(), 0x1f, 0, 0x20, 0x40, work->heapId);
    menu->windowRes = ARC_UTIL_LoadBgCharDataFromArchive(APP_ICON_GetArchiveId(), 0x20, 0, (void **)&menu->windowOut, work->heapId);
    return menu;
}

void PLIST_MENU_Delete(PokelistWork *work, PlistMenu *menu)
{
    GFL_HEAP_Free(menu->windowRes);
    GFL_HEAP_Free(menu);
}

void PLIST_MENU_Open(PokelistWork *work, PlistMenu *menu, int *items)
{
    PlistTaskMenuTemplate tmpl;

    PLIST_MENU_BuildCommandList(work, menu, items);
    tmpl.heapId = work->heapId;
    tmpl.count = menu->count;
    tmpl.entries = menu->entries;
    tmpl.kind = 1;
    tmpl.x = 0x20;
    tmpl.y = 0x18;
    tmpl.width = 0xd;
    tmpl.bgFrame = 3;
    func_020355D8(work->touchMode);
    menu->taskMenu = APP_TASKMENU_OpenMenu(&tmpl, (void *)work->taskMenu);
}

void PLIST_MENU_OpenFixed(PokelistWork *work, PlistMenu *menu)
{
    PlistTaskMenuTemplate tmpl;
    PlistMenuItemList list = gPlistMenuFixedItems;

    PLIST_MENU_BuildCommandList(work, menu, list.item);
    tmpl.heapId = work->heapId;
    tmpl.count = menu->count;
    tmpl.entries = menu->entries;
    tmpl.kind = 1;
    tmpl.x = 0x20;
    tmpl.y = 0x12;
    tmpl.width = 8;
    tmpl.bgFrame = 3;
    func_020355D8(work->touchMode);
    menu->taskMenu = APP_TASKMENU_OpenMenu(&tmpl, (void *)work->taskMenu);
}

void PLIST_MENU_Close(PokelistWork *work, PlistMenu *menu)
{
    u8 i;

    APP_TASKMENU_CloseMenu(menu->taskMenu);
    for (i = 0; i < menu->count; i++)
        STRBUF_Delete(menu->entries[i].label);
    work->touchMode = UI_GetInputMode();
}

void PLIST_MENU_Update(PokelistWork *work, PlistMenu *menu)
{
    APP_TASKMENU_UpdateMenu(menu->taskMenu);
}

unsigned int PLIST_MENU_GetSelectedCommand(PokelistWork *work, PlistMenu *menu)
{
    if (APP_TASKMENU_IsFinish(menu->taskMenu) == 0)
        return 23;
    return menu->ids[APP_TASKMENU_GetCursorPos(menu->taskMenu)];
}

void PLIST_MENU_BuildCommandList(PokelistWork *work, PlistMenu *menu, int *items)
{
    int n, i;
    u8 j;
    int v;
    n = 0;
    while (items[n] != 16) {
        n++;
        if (n >= 8)
            break;
    }
    menu->count = 0;
    for (i = 0; i < n; i++) {
        switch (items[i]) {
        case 0: MENU_APPEND(0); break;
        case 1:
            for (j = 0; j < 4; j++) {
                if (POKELIST_GetFieldMoveMenuIndex((void *)work->selectedMon, j))
                    MENU_APPEND(j + 16);
            }
            break;
        case 2:
            for (j = 0; j < 4; j++) {
                if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, j + 0x36, 0))
                    MENU_APPEND(j + 16);
            }
            break;
        case 3: MENU_APPEND(3); break;
        case 4: MENU_APPEND(4); break;
        case 5: MENU_APPEND(5); break;
        case 6: MENU_APPEND(6); break;
        case 7: MENU_APPEND(7); break;
        case 8:
            v = PLIST_PLATE_GetLabelState((int *)work->plates[work->selectedSlot]);
            if (v == 6)
                MENU_APPEND(20);
            else if (v <= 5)
                MENU_APPEND(21);
            break;
        case 9: MENU_APPEND(9); break;
        case 10: MENU_APPEND(10); break;
        case 11: MENU_APPEND(11); break;
        case 12: MENU_APPEND(12); break;
        case 13: MENU_APPEND(13); break;
        case 14: MENU_APPEND(14); break;
        case 15: MENU_APPEND(15); break;
        }
    }
    for (n = 0; n < menu->count; n++) {
        menu->entries[n].label = PLIST_MENU_CreateCommandLabel(work, menu, menu->ids[n]);
        if (menu->ids[n] >= 16 && menu->ids[n] <= 19 && work->arg->mode != 5)
            menu->entries[n].color = 0x35e0;
        else
            menu->entries[n].color = 0x39e0;
        if (menu->ids[n] == 6)
            menu->entries[n].disabled = 1;
        else
            menu->entries[n].disabled = 0;
    }
}

struct Strbuf *PLIST_MENU_CreateCommandLabel(PokelistWork *work, PlistMenu *menu, int id)
{
    int r;
    int h;
    if (id >= 0x10 && id <= 0x13) {
        r = POKE_TOOL_GetPartyValue((void *)work->selectedMon, id + 0x26, 0);
        h = (int)MSGDATA_CreateFromArchive(0, 2, 0xcb, work->heapId);
        r = (int)MSGDATA_AllocString((struct MsgBank *)h, r);
        MSGDATA_Delete((struct MsgBank *)h);
    } else {
        r = (int)MSGDATA_AllocString(work->msgBank, gPlistMenuLabelMsgIds[id]);
    }
    return (struct Strbuf *)r;
}

int PLIST_MENU_CreateButtonWindow(PokelistWork *work, int unused, int id, int x, u8 y, int disabled)
{
    PlistMenuEntry entry;
    int r;
    entry.label = MSGDATA_AllocString(work->msgBank, id);
    entry.color = 0x39e3;
    if (disabled == 0) {
        entry.disabled = 0;
    } else {
        entry.disabled = 1;
    }
    r = APP_TASKMENU_WIN_Create(work->taskMenu, &entry, x, y, 10, work->heapId);
    STRBUF_Delete(entry.label);
    return r;
}

/*
 * Three null-guarded wrappers, each into an ARM9 routine.
 */
void PLIST_MENU_DeleteTaskMenuWin(void *win)
{
    if (win != 0)
        APP_TASKMENU_WIN_Delete(win);
}

void PLIST_MENU_UpdateTaskMenuWin(void *win)
{
    if (win != 0)
        APP_TASKMENU_WIN_Update(win);
}

void PLIST_MENU_SetTaskMenuWinActive(void *win, int active)
{
    if (win != 0)
        APP_TASKMENU_WIN_SetActive(win, active);
}

/*
 * (no witness at all), and no branch outside this 12-byte range reaches it,
 * so the `bl` site cannot be resolved.  All bytes are correct.
 *
 * DUPLICATE: src/matched/PLIST_MENU_ButtonWinSetDecide.c (packet pkt_021BBE68) is the
 * promoted EXACT entry for this address; this copy shares the same packet
 * and is left parked so the address is not sharded twice.
 */
void PLIST_MENU_ButtonWinSetDecide(void *win, int value)
{
    if (win) {
        APP_TASKMENU_WIN_SetDecide(win, value);
    }
}

/*
 * extent: 774 bytes of code; final two zero bytes align the next function.
 */
int PLIST_MENU_GetItemUseKind(int itemId)
{
    void *itemData = FILE_UTIL_CreateArcTool0F34(itemId, 0, 23);
    int statusMask;
    int amount;
    if (ITEM_PARAM(14) != 1) ITEM_DONE(29);
    if (ITEM_PARAM(30) != 0 || ITEM_PARAM(31) != 0 || ITEM_PARAM(32) != 0 || ITEM_PARAM(33) != 0 || ITEM_PARAM(34) != 0 || ITEM_PARAM(35) != 0 || ITEM_PARAM(36) != 0) ITEM_DONE(0);
    if (ITEM_PARAM(27) != 0) ITEM_DONE(1);
    if (ITEM_PARAM(28) != 0) ITEM_DONE(2);
    statusMask = ITEM_PARAM(18);
    statusMask += ITEM_PARAM(19) * 2;
    statusMask += ITEM_PARAM(20) * 4;
    statusMask += ITEM_PARAM(21) * 8;
    statusMask += ITEM_PARAM(22) * 16;
    statusMask += ITEM_PARAM(23) * 32;
    switch (statusMask) {
    case 1: ITEM_DONE(3);
    case 2: ITEM_DONE(4);
    case 4: ITEM_DONE(5);
    case 8: ITEM_DONE(6);
    case 16: ITEM_DONE(7);
    case 32: ITEM_DONE(8);
    case 63:
        if (ITEM_PARAM(41) != 0) ITEM_DONE(11);
        ITEM_DONE(9);
    }
    if (ITEM_PARAM(24) != 0) ITEM_DONE(10);
    if (ITEM_PARAM(41) != 0) ITEM_DONE(11);
    if (ITEM_PARAM(26) != 0) ITEM_DONE(12);
    amount = ITEM_PARAM(52);
    if (amount > 0) ITEM_DONE(13);
    if (amount < 0) ITEM_DONE(19);
    amount = ITEM_PARAM(53);
    if (amount > 0) ITEM_DONE(14);
    if (amount < 0) ITEM_DONE(20);
    amount = ITEM_PARAM(54);
    if (amount > 0) ITEM_DONE(15);
    if (amount < 0) ITEM_DONE(21);
    amount = ITEM_PARAM(55);
    if (amount > 0) ITEM_DONE(16);
    if (amount < 0) ITEM_DONE(22);
    amount = ITEM_PARAM(56);
    if (amount > 0) ITEM_DONE(17);
    if (amount < 0) ITEM_DONE(23);
    amount = ITEM_PARAM(57);
    if (amount > 0) ITEM_DONE(18);
    if (amount < 0) ITEM_DONE(24);
    if (ITEM_PARAM(29) != 0) ITEM_DONE(25);
    if (ITEM_PARAM(37) != 0) ITEM_DONE(26);
    if (ITEM_PARAM(38) != 0) ITEM_DONE(27);
    if (ITEM_PARAM(39) != 0 || ITEM_PARAM(40) != 0) ITEM_DONE(28);
    ITEM_DONE(29);
}

int PLIST_MENU_IsSpecialItemKind(PokelistWork *work, int itemId)
{
    switch (PLIST_MENU_GetItemUseKind(itemId)) {
    case 26: return 1;
    case 27: return 1;
    case 28:
        if (FILE_UTIL_Get_0FE4(itemId, 39, work->heapId))
            return 1;
        break;
    }
    return 0;
}

int PLIST_MENU_ItemRestoresHp(PokelistWork *work, u32 itemId)
{
    if (FILE_UTIL_Get_0FE4(itemId, 27, work->heapId))
        return 1;
    return 0;
}

int PLIST_MENU_FindItemTarget(PokelistWork *work)
{
    u8 count;
    u8 i;
    count = POKEPARTY_GetCount(work->arg->party);
    for (i = 0; i < count; i++) {
        void *mon = POKEPARTY_GetMember(work->arg->party, i);
        if (PLIST_DEMO_CheckItemUsable(mon, work->arg->itemId, 0, work->heapId) == 1)
            return i;
    }
    return -1;
}

int PLIST_MENU_GetItemUseMessage(PokelistWork *work, int itemId)
{
    switch (PLIST_MENU_GetItemUseKind(itemId)) {
    case 26:
    case 27:
        return 22;
    case 28:
        return 21;
    default:
        return 21;
    }
}

/*
 * 2026-10-05 (D8 lane 15): the leaf POKE_TOOL_GetPlateTypeForwarder is now filed EXACT in src/matched/arm9, so every
 * relocation resolves and this file is EXACT.
 */
void PLIST_MENU_ApplyArceusPlateForm(void *unused, void *mon, int itemId)
{
    u32 form = 0;
    int plateForm;
    if (POKE_TOOL_GetPartyValue(mon, 5, 0) == 0x1ED) {
        form = POKE_TOOL_GetPartyValue(mon, 0x6F, form);
        plateForm = POKE_TOOL_GetPlateTypeForwarder(itemId);
        if (form != plateForm)
            POKE_TOOL_ChangeForm(mon, plateForm);
    }
}

void PLIST_MENU_ApplyGenesectDriveForm(int unused, void *mon, int itemId)
{
    int form = 0;
    int driveForm;
    if (POKE_TOOL_GetPartyValue(mon, 5, 0) == 0x289) {
        form = POKE_TOOL_GetPartyValue(mon, 0x6f, form);
        driveForm = POKE_TOOL_GetBoxParamIndex(itemId);
        if (form != driveForm) {
            POKE_TOOL_ChangeForm(mon, (u16)driveForm);
        }
    }
}

void PLIST_MENU_ShowItemUsedThenClose(PokelistWork *work)
{
    work->arg->exitCode = 10;
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetItem(work, work->messageWindow, 0, work->arg->itemId);
    POKELIST_ShowMessage(work, 0x51, 1, POKELIST_EndMessageToExit);
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
}

void PLIST_MENU_ShowItemUsedThenContinue(PokelistWork *work)
{
    work->arg->exitCode = 10;
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetItem(work, work->messageWindow, 0, work->arg->itemId);
    POKELIST_ShowMessage(work, 0x51, 1, POKELIST_CloseMessageToList);
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
}

int PLIST_MENU_StartItemUse(PokelistWork *work, int v)
{
    int n = PLIST_MENU_GetItemUseKind(work->arg->itemId);
    int level;
    struct Strbuf *msg;
    u8 i;
    u16 z;
    switch (n) {
    case 0: case 8: case 10: case 25: case 29: break;
    case 1: {
        int row = work->selectedSlot;
        work->phase = 10;
        work->displayHp = PLIST_PLATE_GetHp(work, (unsigned short *)work->plates[row]);
        work->phaseCallback = PLIST_MENU_ShowItemResult;
        break;
    }
    case 2:
        level = POKE_TOOL_CalcLevel((void *)work->selectedMon);
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
        PLIST_MESSAGE_SetWordSetNumber(work, work->messageWindow, 1, (u16)(level + 1), 3);
        POKELIST_ShowMessage(work, 0x9d, 1, PLIST_MENU_BeginLevelUpMoveWait);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        msg = STRBUF_Create(12, work->heapId);
        POKE_TOOL_GetPartyValue((void *)work->selectedMon, 0x73, (u32)msg);
        GAME_BEACON_SetPokeLevelUp((int)msg);
        STRBUF_Delete(msg);
        for (i = 0; i < 6; i++) {
            work->levelUpMoveStat[i] = POKE_TOOL_GetPartyValue((void *)work->selectedMon, gPlistStatParamIds[i], 0);
        }
        break;
    case 3: PLIST_MENU_ShowMonMessage(work, 0x47); break;
    case 4: PLIST_MENU_ShowMonMessage(work, 0x2d); break;
    case 5: PLIST_MENU_ShowMonMessage(work, 0x2f); break;
    case 6: PLIST_MENU_ShowMonMessage(work, 0x30); break;
    case 7: PLIST_MENU_ShowMonMessage(work, 0x2e); break;
    case 9: PLIST_MENU_ShowMonMessage(work, 0x33); break;
    case 11: case 12: {
        int row = work->selectedSlot;
        work->phase = 10;
        work->displayHp = PLIST_PLATE_GetHp(work, (unsigned short *)work->plates[row]);
        work->phaseCallback = PLIST_MENU_ShowHpRestored;
        break;
    }
    case 13: case 14: case 15: case 16: case 17: case 18:
        PLIST_MENU_ShowMonValueMessage(work, 0x37, (u16)(n - 13)); break;
    case 19: case 20: case 21: case 22: case 23: case 24:
        z = n - 19;
        if (PLIST_MENU_HasMonParam((void *)work->selectedMon, z + 13, work->arg->itemId) == 0) PLIST_MENU_ShowMonValueMessage(work, 0x55, z);
        else if (POKE_TOOL_GetPartyValue((void *)work->selectedMon, 9, 0) == 255) PLIST_MENU_ShowMonValueMessage(work, 0x54, z);
        else PLIST_MENU_ShowMonValueMessage(work, 0x53, z);
        break;
    case 26: case 27:
        PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
        PLIST_MESSAGE_SetWordSetMove(work, work->messageWindow, 0, (u16)v);
        POKELIST_ShowMessage(work, 0x34, 1, POKELIST_CloseMessageIfItemInBag);
        PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        break;
    case 28: PLIST_MENU_ShowMonMessage(work, 0x31); break;
    }
    return n;
}

void PLIST_MENU_ShowHpRestored(PokelistWork *work)
{
    u16 h;
    u16 v;
    h = PLIST_PLATE_GetHp(work, (unsigned short *)work->plates[work->selectedSlot]);
    work->arg->exitCode = 10;
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
    v = work->displayHp;
    if (v != 0) {
        PLIST_MESSAGE_SetWordSetNumber(work, work->messageWindow, 1, (u16)(h - v), (int)3);
        POKELIST_ShowMessage(work, 0x2c, 1, POKELIST_CloseMessageIfItemInBag);
    } else {
        POKELIST_ShowMessage(work, 0x32, 1, POKELIST_CloseMessageIfItemInBag);
    }
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
}

void PLIST_MENU_ShowItemResult(PokelistWork *work)
{
    work->arg->exitCode = 10;
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
    if (PLIST_MENU_FindItemTarget(work) != -1) {
        POKELIST_ShowMessage(work, 0x32, 1, PLIST_MENU_UseItemOnFoundTarget);
    } else {
        POKELIST_ShowMessage(work, 0x32, 1, POKELIST_EndMessageToExit);
    }
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
}

void PLIST_MENU_UseItemOnFoundTarget(PokelistWork *work)
{
    int n = PLIST_MENU_FindItemTarget(work);
    PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
    PLIST_PLATE_SetPalette(work, (u8 *)work->plates[work->selectedSlot], 3);
    work->selectedSlot = n;
    work->selectedMon = (int)POKEPARTY_GetMember(work->arg->party, n);
    PLIST_MENU_StartItemUse(work, 0);
    PLIST_DEMO_UseItemOnMon((void *)work->selectedMon,
                  work->arg->itemId, 0,
                  work->arg->itemUseParam, work->heapId);
    PLIST_PLATE_Redraw(work, (u8 *)work->plates[work->selectedSlot]);
    GFL_USE_PlaySeDefaultVolume(0x56f);
}

void PLIST_MENU_BeginLevelUpMoveWait(PokelistWork *work)
{
    work->phase = 0xd;
    work->inputStage = 0;
    work->arg->levelUpCursor = 0;
    PLIST_MESSAGE_DrawKeyCursorMark(work, work->messageWindow);
}

void PLIST_MENU_BeginExitWait(PokelistWork *work)
{
    work->phase = 0xd;
    work->inputStage = 6;
}

void PLIST_MENU_UpdateLevelUp(PokelistWork *work)
{
    u8 i, j, x;
    u32 result;
    struct Descriptor *desc;
    switch (work->inputStage) {
    case 0: {
        u8 flag;
        u32 delta;
        struct Strbuf *msg, *numStr;
        struct WordSet *wordSet;
        int y;
        u16 width;
        flag = 0;
        work->descriptor = BMP_WIN_Create((int)0, (u8)1, (u8)1, (int)14, 12, 14, 1);
        BMP_MENUWORK_DrawWindow(DESC, 1, 1, 12);
        BMP_Clear(BMP_WIN_GetBmp(DESC), 15);
        desc = DESC; BMP_WIN_TransferChars(desc); BMP_WIN_MakeScreen(desc); BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(desc));
        for (i = 0; i < 6; i++) {
            delta = POKE_TOOL_GetPartyValue((void *)work->selectedMon, gPlistStatParamIds[i], 0) - work->levelUpMoveStat[i];
            if (delta >= 10) flag = 1;
            msg = MSGDATA_AllocString(work->msgBank, i + 0x95); y = i << 4;
            PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(DESC), 0, (s16)(i << 4), msg, work->fontMain, 0x440);
            STRBUF_Delete(msg);
            msg = MSGDATA_AllocString(work->msgBank, 0x9c); numStr = STRBUF_Create(0x20, work->heapId); wordSet = WORDSET_CreateDefault(work->heapId);
            WORDSET_SetSlotNumber(wordSet, 0, delta, 3, 0, 1); WORDSET_CopyTaggedText(wordSet, numStr, msg);
            width = GF_FONT_MeasureWidestLine(numStr, work->fontMain, 0);
            PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(DESC), (s16)(104 - width), (s16)y, numStr, work->fontMain, 0x440);
            STRBUF_Delete(msg); STRBUF_Delete(numStr); WORDSET_DeleteStrbufED04(wordSet);
        }
        for (j = 0; j < 6; j++) {
            x = flag == 1 ? 72 : 80;
            msg = MSGDATA_AllocString(work->msgBank, 0x9b);
            PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(DESC), x, (s16)(j << 4), msg, work->fontMain, 0x440);
            STRBUF_Delete(msg);
        }
        work->inputStage = 1; break;
    }
    case 1:
        if (PRINTSYS_QUE_IsExistTarget(work->printSys, BMP_WIN_GetBmp(DESC)) == 0) {
            desc = DESC; BMP_WIN_TransferChars(desc); BMP_WIN_MakeScreen(desc); BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(desc)); work->inputStage = 2;
        } break;
    case 2:
        if ((KEY_GetTrg() & 1) || (KEY_GetTrg() & 2) || TOUCHPANEL_GetTrg() == 1) { GFL_USE_PlaySeDefaultVolume(0x547); work->inputStage = 3; }
        break;
    case 3: {
        u16 width;
        u32 delta;
        struct Strbuf *msg, *numStr;
        struct WordSet *wordSet;
        BMP_FillRect(BMP_WIN_GetBmp(DESC), 0x50, 0, 0x20, 0x60, 15);
        for (i = 0; i < 6; i++) {
            delta = POKE_TOOL_GetPartyValue((void *)work->selectedMon, gPlistStatParamIds[i], 0);
            msg = MSGDATA_AllocString(work->msgBank, 0x9c); numStr = STRBUF_Create(0x20, work->heapId); wordSet = WORDSET_CreateDefault(work->heapId);
            WORDSET_SetSlotNumber(wordSet, 0, delta, 3, 0, 1); WORDSET_CopyTaggedText(wordSet, numStr, msg);
            width = GF_FONT_MeasureWidestLine(numStr, work->fontMain, 0);
            PRINTSYS_PrintQueColor(work->printSys, BMP_WIN_GetBmp(DESC), (s16)(104 - width), (s16)(i << 4), numStr, work->fontMain, 0x440);
            STRBUF_Delete(msg); STRBUF_Delete(numStr); WORDSET_DeleteStrbufED04(wordSet);
        }
        work->inputStage = 4; break;
    }
    case 4:
        if (PRINTSYS_QUE_IsExistTarget(work->printSys, BMP_WIN_GetBmp(DESC)) == 0) {
            desc = DESC; BMP_WIN_TransferChars(desc); BMP_WIN_MakeScreen(desc); BG_SYS_SetFlagField06(BMP_WIN_GetBgLayer(desc)); work->inputStage = 5;
        } break;
    case 5:
        if ((KEY_GetTrg() & 1) || (KEY_GetTrg() & 2) || TOUCHPANEL_GetTrg() == 1) {
            work->inputStage = 6; GFL_USE_PlaySeDefaultVolume(0x547); BMP_WIN_ClearScreen(DESC); BMP_MENUWORK_DrawWindowBorder(DESC, 1); BMP_WIN_Delete(DESC); work->descriptor = 0;
        } break;
    case 6:
        result = POKE_TOOL_GetLevelUpMove((void *)work->selectedMon, &work->arg->levelUpCursor, work->heapId); PLIST_MESSAGE_CloseWindow(work, (u32 *)work->messageWindow);
        if (result == 0) { work->inputStage = 7; return; }
        if (result == 0xfffe) { work->inputStage = 7; return; }
        if (result & 0x8000) {
            work->arg->moveId = result - 0x8000;
            PLIST_MESSAGE_CreateWordSet(work, work->messageWindow); PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
            PLIST_MESSAGE_SetWordSetMove(work, work->messageWindow, 1, work->arg->moveId);
            POKELIST_ShowMessage(work, 0x20, 0, POKELIST_OpenGiveUpMoveMenu); PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        } else {
            PLIST_MESSAGE_CreateWordSet(work, work->messageWindow); PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
            PLIST_MESSAGE_SetWordSetMove(work, work->messageWindow, 1, result);
            POKELIST_ShowMessage(work, 0x29, 1, PLIST_MENU_BeginExitWait); PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
        } break;
    case 7:
        POKE_TOOL_GetPartyValue((void *)work->selectedMon, 5, 0);
        if (SHINKA_CHECK_CheckEvolution(work->arg->party, (void *)work->selectedMon, 0, work->arg->itemUseParam, work->arg->season, 0, work->heapId) != 0) {
            work->phase = 19; work->arg->selectedIndex = work->selectedSlot; work->arg->exitCode = 9;
        } else {
            work->arg->mode = 5; work->arg->selectedIndex = work->selectedSlot; work->arg->exitCode = 10; POKELIST_CloseMessageIfItemInBag(work);
        } break;
    }
}

int PLIST_MENU_HasMonParam(void *mon, int param, int unused)
{
    int r = 0;
    if (POKE_TOOL_GetPartyValue(mon, param, 0))
        r = 1;
    return r;
}

void PLIST_MENU_ShowMonMessage(PokelistWork *work, int msgId)
{
    work->arg->exitCode = 10;
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
    POKELIST_ShowMessage(work, msgId, 1, POKELIST_CloseMessageIfItemInBag);
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
}

void PLIST_MENU_ShowMonValueMessage(PokelistWork *work, int msgId, int value)
{
    work->arg->exitCode = 10;
    PLIST_MESSAGE_CreateWordSet(work, work->messageWindow);
    PLIST_MESSAGE_SetWordSetPokemon(work, work->messageWindow, 0, work->selectedMon);
    PLIST_MESSAGE_SetWordSetValue(work, work->messageWindow, 1, value);
    POKELIST_ShowMessage(work, msgId, 1, POKELIST_CloseMessageIfItemInBag);
    PLIST_MESSAGE_DestroyWordSet(work, work->messageWindow);
}

void PLIST_MENU_InitTimer(PokelistWork *work)
{
    PokelistArg *arg;
    PLIST_MENU_CreateBank(work);
    PLIST_MENU_LoadResources(work);
    arg = work->arg;
    if (arg->timerShown == 1) {
        switch (arg->battleKind) {
        case 1:
            work->timerDigit[1] = PLIST_BATTLE_CreateTeamPanel(work, &arg->entries[1], 10, 0, 2);
            break;
        case 2:
            work->timerDigit[0] = PLIST_BATTLE_CreateTeamPanel(work, &arg->entries[0], 0, 0, 0);
            work->timerDigit[1] = PLIST_BATTLE_CreateTeamPanel(work, &work->arg->entries[1], 0xb, 0, 0);
            work->timerDigit[2] = PLIST_BATTLE_CreateTeamPanel(work, &work->arg->entries[2], 0x16, 0, 0);
            break;
        }
    }
    arg = work->arg;
    work->timerShown = arg->timerExpired;
    work->shownSeconds = 0;
    if (arg->timerRunning == 1) {
        PLIST_BATTLE_CreateTimerWindows(work);
    }
    work->timerPalPhase = 0;
}

void PLIST_MENU_ExitTimer(PokelistWork *work)
{
    if (work->arg->timerRunning == 1)
        PLIST_BATTLE_DeleteTimerWindows(work);
    if (work->arg->timerShown == 1) {
        switch (work->arg->battleKind) {
        case 1:
            PLIST_BATTLE_DeleteTeamPanel(work, work->timerDigit[1]);
            break;
        case 2:
            PLIST_BATTLE_DeleteTeamPanel(work, work->timerDigit[0]);
            PLIST_BATTLE_DeleteTeamPanel(work, work->timerDigit[1]);
            PLIST_BATTLE_DeleteTeamPanel(work, work->timerDigit[2]);
            break;
        }
    }
    PLIST_MENU_Nop(work);
    PLIST_MENU_DeleteBank(work);
}

void PLIST_MENU_UpdateTimer(PokelistWork *work)
{
    if (work->arg->timerShown == 1) {
        switch (work->arg->battleKind) {
        case 1:
            PLIST_BATTLE_UpdateTeamPanel(work, work->timerDigit[1]);
            break;
        case 2:
            PLIST_BATTLE_UpdateTeamPanel(work, work->timerDigit[0]);
            PLIST_BATTLE_UpdateTeamPanel(work, work->timerDigit[1]);
            PLIST_BATTLE_UpdateTeamPanel(work, work->timerDigit[2]);
            break;
        }
    }
    if (work->timerShown != work->arg->timerExpired && work->phase == 2) {
        PLIST_BATTLE_PrintOpponentMessage(work);
        work->timerShown = work->arg->timerExpired;
    }
    if (work->arg->timerRunning == 1)
        PLIST_BATTLE_UpdateTimer(work);
    if (work->arg->closeRequested == 1)
        POKELIST_ForceSelectionEnd(work);
}

void PLIST_MENU_CreateBank(PokelistWork *work)
{
    work->actorSystem = CLACT_CreateUnit(36, 8, work->heapId);
}

void PLIST_MENU_DeleteBank(PokelistWork *work)
{
    CLACT_DeleteUnit(work->actorSystem);
}

void PLIST_MENU_LoadResources(PokelistWork *work)
{
    void *h, *h2;
    h = ARC_TOOL_CreateHandle(0x4c, work->heapId);
    ARC_UTIL_UploadPaletteFromHandle(h, 1, 4, 0x20, 0x20, 0x20, work->heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 0, 4, 0x1a0, 0x20, work->heapId);
    ARC_UTIL_UploadBgCharFromHandle(h, 9, 6, 0, 0, 0, work->heapId);
    if (work->arg->timerShown == 1) {
        switch (work->arg->battleKind) {
        case 1: ARC_UTIL_UploadBgPaletteFromHandle(h, 0x11, 6, 0, 0, 0, work->heapId); break;
        case 2: ARC_UTIL_UploadBgPaletteFromHandle(h, 0x10, 6, 0, 0, 0, work->heapId); break;
        }
    }
    ARC_TOOL_DeleteHandle(h);
    h2 = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), work->heapId);
    work->charRes[3] = CLACT_RegisterPalette(h, APP_ICON_GetItemCellFileId(), 1, 0x60, work->heapId);
    work->palRes[4] = CLACT_RegisterCharacter(h, APP_ICON_GetItemPaletteFileId(), 0, 1, work->heapId);
    work->cellRes[4] = CLACT_RegisterCellAnim(h, APP_ICON_GetItemAnimFileId(2), APP_ICON_GetItemFrameFileId(2), work->heapId);
    if (work->arg->timerRunning == 1) {
        ARC_UTIL_UploadPaletteFromHandleWhole(h, APP_ICON_GetStatusAnimFileId(), 4, 0x40, 0x20, work->heapId);
        ARC_UTIL_UploadBgCharFromHandle(h, APP_ICON_GetStatusFrameFileId(), 5, 0, 0, 0, work->heapId);
        ARC_UTIL_UploadBgPaletteFromHandle(h, APP_ICON_GetStatusDataFileId(), 5, 0, 0, 0, work->heapId);
        BG_SYS_FillTileMap(5, 0, 0, 0x20, 0x20, 2);
        BG_SYS_SetFlagField06(5);
    }
    ARC_TOOL_DeleteHandle(h2);
    h = ARC_TOOL_CreateHandle(7, work->heapId);
    work->charRes[7] = CLACT_RegisterPaletteCompressed(h, POKE_TOOL_GetIconPaletteArcId(), 1, 0xc0, work->heapId);
    ARC_TOOL_DeleteHandle(h);
    /* stand-in: with the timer palette inside a padding view, &tail->timerPalette is
       work + 0x1EC + 0x22 and the compiler does not fold it; it is &work->timerPalette
       (0x20E) once pokelist_types.h names that field. */
    MIi_CpuCopy16(TIMER_PALETTE_DST, (u8 *)work + 0x20e, 0x20);
}

/*
 * note:     listing extent (4) runs 2 bytes past the compiled function (2);
 *           trailing alignment padding, no byte difference.
 */
void PLIST_MENU_Nop(PokelistWork *work)
{
}
