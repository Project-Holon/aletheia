/*
 * file:     c_gear_power_onoff.c
 * unit:     yes
 * function: C_GEAR_POWER_ONOFF_Create, C_GEAR_POWER_ONOFF_Delete, C_GEAR_POWER_ONOFF_Update, C_GEAR_POWER_ONOFF_InitScreen, C_GEAR_POWER_ONOFF_ExitScreen, C_GEAR_POWER_ONOFF_InitBgs, C_GEAR_POWER_ONOFF_ExitBgs, C_GEAR_POWER_ONOFF_CreateTaskMenuRes, C_GEAR_POWER_ONOFF_DeleteTaskMenuRes, C_GEAR_POWER_ONOFF_InitWindows, C_GEAR_POWER_ONOFF_ExitWindows, C_GEAR_POWER_ONOFF_PrintMessage, C_GEAR_POWER_ONOFF_ResetAndPrintMessage, C_GEAR_POWER_ONOFF_OpenYesNoMenu, C_GEAR_POWER_ONOFF_CloseMenu, C_GEAR_POWER_ONOFF_UpdateMenu, C_GEAR_POWER_ONOFF_GetMenuResult, C_GEAR_POWER_ONOFF_IsMenuDecided, C_GEAR_POWER_ONOFF_StepTurnOn, C_GEAR_POWER_ONOFF_StepTurnOff
 * address:  0x021EFEC0
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   sCGearPowerOnOffFileName    0x021F0678 data ov035 a1
 *   func_02012138 0x02012138 thumb
 *   func_0202EB44 0x0202EB44 thumb
 *   func_0201214C 0x0201214C thumb
 *   func_020307B0 0x020307B0 arm
 *   sPowerOnOffTable 0x021F0640 data ov035 a4
 *   FIELD_SUBSCREEN_SetPanelResult 0x021A0FA0 thumb ov021
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045B38 0x02045B38 arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   FIELD_SUBSCREEN_LoadBackdrop 0x021A12D4 thumb ov021
 *   FIELD_SUBSCREEN_ResumeField 0x021A0FB4 thumb ov021
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_020409B4 0x020409B4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_020120F4 0x020120F4 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   sBgCharFileIds    0x021F05B0 data a4
 *   sBgPaletteFileIds    0x021F05BC data ov035 a4
 *   sBgTemplate5    0x021F05C8 data ov035 a4
 *   sBgTemplate4    0x021F05E8 data ov035 a4
 *   sBgTemplate6    0x021F0608 data ov035 a4
 *   func_0203FB44 0x0203FB44 arm
 *   sub_020403F4  0x020403F4 arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   func_02049B40 0x02049B40 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_SetDispHeight 0x02045790 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   TCBL_Create 0x0203101C arm
 *   func_02028590 0x02028590 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_0201F614 0x0201F614 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   func_0201F79C 0x0201F79C thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   d_021F064C    0x021F064C data ov035 a4
 *   APP_TASKMENU_OpenMenuFastDecide 0x0202784C thumb
 *   APP_TASKMENU_SetDisableKey 0x02027CD8 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   func_02012204 0x02012204 thumb
 *   GAME_COMM_GetKind 0x02026454 thumb
 *   GAME_COMM_RequestExitNoCallback 0x02026400 thumb
 *   GAMESYSTEM_SetAlwaysNetFlag 0x02012158 thumb
 *   GAMESYSTEM_TryStartAutoComm 0x020121CC thumb
 */
#include "c_gear_power_onoff_types.h"

struct GameData;
struct MyStatus;
struct BgTemplate;
struct TaskMenuInit;
struct PrintStream;
struct SaveControl;
struct ArcHandle;
struct CharBuf;
struct Task;

typedef signed short s16;

struct BgTemplate {
    u32 scrollX;
    u32 scrollY;
    u32 bufSize;
    u32 baseTile;
    u8 screenSize;
    u8 colorMode;
    u8 screenBase;
    u8 charBase;
    u32 extPaletteSlot;
    u8 priority;
    u8 areaOver;
    u8 dummy;
    u8 mosaicFlag;
    u32 mosaic;
};

/*
 * Static data of the panel: the three scene step functions, followed by the
 * init block of the yes/no task menu that C_GEAR_POWER_ONOFF_OpenYesNoMenu
 * fills in before opening it.
 */
typedef struct CGearPowerOnOffTable {
    int (*sceneStep[3])(CGearPowerOnOffWork *);
    int menuHeapId;
    u8 menuHeader[0x10];
    struct Strbuf *yesLabel;
    u8 menuMiddle[0x8];
    struct Strbuf *noLabel;
} CGearPowerOnOffTable;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_02012138(const void *gameSystem);
extern int func_0202EB44(void);
extern u32 func_0201214C(const void *gameSystem);
extern u32 func_020307B0(void *p);
extern void FIELD_SUBSCREEN_SetPanelResult(FieldSubscreen *subscreen, int mode);
extern u32 PRINTSYS_QUE_Main(struct PrintQue *printQue);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, unsigned int heapId);
extern void func_0201DD68(void);
extern struct MsgBank *func_02045B38(unsigned int resident, unsigned int arcId, unsigned int fileId, unsigned int heapId);
extern struct PrintQue *PRINTSYS_QUE_Create(unsigned int heapId);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void FIELD_SUBSCREEN_LoadBackdrop(FieldSubscreen *subscreen, u32 heapId);
extern void FIELD_SUBSCREEN_ResumeField(FieldSubscreen *subscreen, u32 heapId);
extern void PRINTSYS_QUE_Clear(struct PrintQue *printQue);
extern void PRINTSYS_QUE_Delete(struct PrintQue *printQue);
extern u32 MSGDATA_Delete(struct MsgBank *bank);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_020409B4(u32 layer);
extern struct ArcHandle *func_020490F4(unsigned int id, unsigned int heap);
extern struct GameData *func_020120F4(const void *gameSystem);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern u8 func_02008550(const struct MyStatus *myStatus);
extern void func_02049B68(struct ArcHandle *arc, u32 fileId, u32 bgId, u32 offset, u32 compressed, u32 heapId);
extern u32 func_02049740(struct ArcHandle *arc, u32 fileId, u32 layer, u32 ofs, u32 size, u32 heap);
extern void func_02049990(struct ArcHandle *arc, u32 fileId, u32 layer, u32 ofs, u32 chrOfs, u32 a5, u32 a6,
    u32 heap);
extern void ARC_TOOL_DeleteHandle(struct ArcHandle *arc);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern void sub_020403F4(u32 i);
extern void *APP_TASKMENU_RES_Create(u16 a0, u16 a1, struct GfFont *font, struct PrintQue *printQue, u16 heap);
extern u32 APP_TASKMENU_RES_Delete(void *taskMenuRes);
extern void func_02049B40(int, int, int, int, int, int);
extern void *func_0201F5DC(u32 layer, unsigned int a1, unsigned int a2, unsigned int a3);
extern struct BmpWin *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_SetDispHeight(struct BmpWin *window, u8 v);
extern void *BMP_WIN_GetBmp(struct BmpWin *window);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct BmpWin *window);
extern void BMP_WIN_MakeScreen(struct BmpWin *window);
extern void *TCBL_Create(int, int, int, int);
extern void *func_02028590(int, int, int, int);
extern void PRINTSYS_PrintStreamDelete(void *printStream);
extern void STRBUF_Delete(struct Strbuf *text);
extern int APP_KEYCURSOR_Delete(void *keyCursor);
extern void TCBL_Destroy(void *tcbl);
extern u32 BMP_WIN_Delete(struct BmpWin *window);
extern void func_0201F614(int, unsigned int);
extern struct Strbuf *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_Print(void *bitmap, s16 x, s16 y, struct Strbuf *msg, struct GfFont *font);
extern void func_0201F79C(struct BmpWin *window, u32 kind, void *menuWork, u32 pal);
extern void func_0201F7A8(struct BmpWin *window, u32 kind);
extern void *APP_TASKMENU_OpenMenuFastDecide(void *menuInit, void *taskMenuRes);
extern int APP_TASKMENU_SetDisableKey(void *taskMenu, int a1);
extern void APP_TASKMENU_CloseMenu(void *taskMenu);
extern void APP_TASKMENU_UpdateMenu(void *taskMenu);
extern u8 APP_TASKMENU_GetCursorPos(void *taskMenu);
extern u32 APP_TASKMENU_IsFinish(void *taskMenu);
extern u32 WIPE_SYS_EndCheck(void);
extern int TOUCHPANEL_GetTrg(void);
extern u32 func_02012204(const void *gameSystem);
extern u32 GAME_COMM_GetKind(void *beacon);
extern void GAME_COMM_RequestExitNoCallback(void *beacon);
extern void GAMESYSTEM_SetAlwaysNetFlag(void *gameSystem, unsigned int v);
extern u32 GAMESYSTEM_TryStartAutoComm(void *gameSystem);
CGearPowerOnOffWork *C_GEAR_POWER_ONOFF_Create(FieldSubscreen *subscreen, void *gameSystem, u16 heapId);
void C_GEAR_POWER_ONOFF_Delete(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_Update(CGearPowerOnOffWork *work, int isInitialUpdate);
void C_GEAR_POWER_ONOFF_InitScreen(CGearPowerOnOffWork *work, u16 heapId);
void C_GEAR_POWER_ONOFF_ExitScreen(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_InitBgs(CGearPowerOnOffWork *work, u32 heapId);
void C_GEAR_POWER_ONOFF_ExitBgs(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_CreateTaskMenuRes(CGearPowerOnOffWork *work, u16 heapId);
void C_GEAR_POWER_ONOFF_DeleteTaskMenuRes(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_InitWindows(CGearPowerOnOffWork *work, int heapId);
void C_GEAR_POWER_ONOFF_ExitWindows(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_PrintMessage(CGearPowerOnOffWork *work, struct BmpWin *window, int msgId);
void C_GEAR_POWER_ONOFF_ResetAndPrintMessage(CGearPowerOnOffWork *work, struct BmpWin *window, int msgId, int height);
void C_GEAR_POWER_ONOFF_OpenYesNoMenu(CGearPowerOnOffWork *work, int heapId);
void C_GEAR_POWER_ONOFF_CloseMenu(CGearPowerOnOffWork *work);
void C_GEAR_POWER_ONOFF_UpdateMenu(CGearPowerOnOffWork *work);
u8 C_GEAR_POWER_ONOFF_GetMenuResult(CGearPowerOnOffWork *work);
u32 C_GEAR_POWER_ONOFF_IsMenuDecided(CGearPowerOnOffWork *work);
int C_GEAR_POWER_ONOFF_StepTurnOn(CGearPowerOnOffWork *work);
int C_GEAR_POWER_ONOFF_StepTurnOff(CGearPowerOnOffWork *work);
extern char sCGearPowerOnOffFileName[];
extern CGearPowerOnOffTable sPowerOnOffTable;
extern const u32 sBgCharFileIds[];
extern const u32 sBgPaletteFileIds[];
extern const struct BgTemplate sBgTemplate5;
extern const struct BgTemplate sBgTemplate4;
extern const struct BgTemplate sBgTemplate6;



CGearPowerOnOffWork *C_GEAR_POWER_ONOFF_Create(FieldSubscreen *subscreen, void *gameSystem, u16 heapId)
{
    CGearPowerOnOffWork *work = func_02030734(heapId, 0x50, 1, sCGearPowerOnOffFileName, 0x12D);
    work->gameSystem = gameSystem;
    work->beacon = func_02012138(gameSystem);
    work->subscreen = subscreen;
    work->heapId = heapId;
    C_GEAR_POWER_ONOFF_InitScreen(work, heapId);
    if (func_0202EB44() == 0)
        work->scene = C_GEAR_POWER_ONOFF_SCENE_UNAVAILABLE;
    else if (func_0201214C(gameSystem) == 1)
        work->scene = C_GEAR_POWER_ONOFF_SCENE_TURN_OFF;
    else
        work->scene = C_GEAR_POWER_ONOFF_SCENE_TURN_ON;
    C_GEAR_POWER_ONOFF_Update(work, 1);
    return work;
}


void C_GEAR_POWER_ONOFF_Delete(CGearPowerOnOffWork *work) { C_GEAR_POWER_ONOFF_ExitScreen(work); func_020307B0(work); }


void C_GEAR_POWER_ONOFF_Update(CGearPowerOnOffWork *work, int isInitialUpdate) { if(work->closeRequested==0) { if(sPowerOnOffTable.sceneStep[work->scene](work)) { FIELD_SUBSCREEN_SetPanelResult(work->subscreen,14); work->closeRequested=1; } } PRINTSYS_QUE_Main(work->printQue); }



void C_GEAR_POWER_ONOFF_InitScreen(CGearPowerOnOffWork *work, u16 heapId)
{
    work->font = GF_FONT_Create(0x17, 0, 0, 0, heapId);
    func_0201DD68();
    work->msgBank = func_02045B38(0, 2, 0x16, heapId);
    work->printQue = PRINTSYS_QUE_Create(heapId);
    C_GEAR_POWER_ONOFF_InitBgs(work, heapId);
    C_GEAR_POWER_ONOFF_CreateTaskMenuRes(work, heapId);
    C_GEAR_POWER_ONOFF_InitWindows(work, heapId);
    GFL_NET_RestartWithDefaultTimeout(0, heapId);
    FIELD_SUBSCREEN_LoadBackdrop(work->subscreen, heapId);
}


void C_GEAR_POWER_ONOFF_ExitScreen(CGearPowerOnOffWork *work) { FIELD_SUBSCREEN_ResumeField(work->subscreen,work->heapId); C_GEAR_POWER_ONOFF_ExitWindows(work); C_GEAR_POWER_ONOFF_DeleteTaskMenuRes(work); C_GEAR_POWER_ONOFF_ExitBgs(work); PRINTSYS_QUE_Clear(work->printQue); PRINTSYS_QUE_Delete(work->printQue); MSGDATA_Delete(work->msgBank); GF_FONT_Delete(work->font); }




void C_GEAR_POWER_ONOFF_InitBgs(CGearPowerOnOffWork *work, u32 heapId)
{
    int i;
    struct ArcHandle *arc;
    u32 charAlloc;

    for (i = 4; i <= 7; i++)
        func_02040588((u8)i, 0);
    func_0203FCA0(6, &sBgTemplate6, 0);
    func_020414EC(6);
    func_020409B4(6);
    func_02040588((u8)6, 1);
    func_0203FCA0(5, &sBgTemplate5, 0);
    func_020414EC(5);
    func_020409B4(5);
    func_02040588((u8)5, 1);
    func_0203FCA0(4, &sBgTemplate4, 0);
    func_020414EC(4);
    func_020409B4(4);
    func_02040588((u8)4, 1);
    arc = func_020490F4(0x1E, heapId);
    i = func_02008550(func_02012944(func_020120F4(work->gameSystem)));
    func_02049B68(arc, sBgPaletteFileIds[i], 4, 0, 1, heapId);
    charAlloc = func_02049740(arc, sBgCharFileIds[i], 6, 0, 0, heapId);
    work->bgCharAlloc = charAlloc;
    func_02049990(arc, 3, 6, 0, (u16)charAlloc, 0, 0, heapId);
    ARC_TOOL_DeleteHandle(arc);
}




void C_GEAR_POWER_ONOFF_ExitBgs(CGearPowerOnOffWork *work)
{
    unsigned int charAlloc = work->bgCharAlloc;
    func_0203FB44(6, (unsigned short)charAlloc, (unsigned short)(charAlloc >> 16));
    sub_020403F4(6);
    sub_020403F4(5);
    sub_020403F4(4);
    func_02040588(6, 0);
    func_02040588(5, 0);
    func_02040588(4, 0);
}



void C_GEAR_POWER_ONOFF_CreateTaskMenuRes(CGearPowerOnOffWork *work, u16 heapId)
{
    work->taskMenuRes = APP_TASKMENU_RES_Create(4, 3, work->font, work->printQue, heapId);
}




void C_GEAR_POWER_ONOFF_DeleteTaskMenuRes(CGearPowerOnOffWork *work)
{
    APP_TASKMENU_RES_Delete(work->taskMenuRes);
}




void C_GEAR_POWER_ONOFF_InitWindows(CGearPowerOnOffWork *work, int heapId)
{
    func_02049B40(0x17, 5, 4, 0x20, 0x20, heapId);
    work->bmpMenuWork = func_0201F5DC(5, 2, 0, heapId);
    work->messageWindow = BMP_WIN_Create(5, 1, 1, 0x1E, 6, 1, 1);
    work->menuWindow = BMP_WIN_Create(5, 1, 0xD, 0x1E, 0xA, 1, 1);
    BMP_WIN_SetDispHeight(work->messageWindow, 4);
    BMP_Clear(BMP_WIN_GetBmp(work->messageWindow), 0xF);
    BMP_WIN_TransferChars(work->messageWindow);
    BMP_WIN_MakeScreen(work->messageWindow);
    BMP_Clear(BMP_WIN_GetBmp(work->menuWindow), 0xF);
    BMP_WIN_TransferChars(work->menuWindow);
    BMP_WIN_MakeScreen(work->menuWindow);
    work->tcbl = TCBL_Create(heapId, heapId, 1, 4);
    work->keyCursor = func_02028590(0xF, 0, 1, heapId);
}



/*
 * interface: 0201F614 forwards r0 and splits packed r1 into two halfwords;
 *            02028604 uses only r0; legacy trailing inputs are unread.
 * 2026-10-05 (D8 lane 15): 0201F614 now filed EXACT as src/matched/arm9/func_0201F614.c (u16 lo, u16 hi split of r1).
 * Re-run after the integrator regenerates the layout; expected EXACT.
 */
void C_GEAR_POWER_ONOFF_ExitWindows(CGearPowerOnOffWork *work)
{
    if (work->printStream) {
        PRINTSYS_PrintStreamDelete(work->printStream);
        work->printStream = 0;
        STRBUF_Delete(work->streamMessage);
        work->streamMessage = 0;
    }
    APP_KEYCURSOR_Delete(work->keyCursor);
    TCBL_Destroy(work->tcbl);
    BMP_WIN_Delete(work->menuWindow);
    BMP_WIN_Delete(work->messageWindow);
    func_0201F614(5, (unsigned int)work->bmpMenuWork);
}




void C_GEAR_POWER_ONOFF_PrintMessage(CGearPowerOnOffWork *work, struct BmpWin *window, int msgId)
{
    struct Strbuf *msg = func_02045EC0(work->msgBank, msgId);
    PRINTSYS_Print(BMP_WIN_GetBmp(window), 0, 0, msg, work->font);
    func_0201F79C(window, 0, work->bmpMenuWork, 2);
    BMP_WIN_TransferChars(window);
    STRBUF_Delete(msg);
}




void C_GEAR_POWER_ONOFF_ResetAndPrintMessage(CGearPowerOnOffWork *work, struct BmpWin *window, int msgId, int height)
{
    struct Strbuf *msg = func_02045EC0(work->msgBank, msgId);

    BMP_WIN_SetDispHeight(window, height);
    BMP_Clear(BMP_WIN_GetBmp(window), 15);
    func_0201F7A8(window, 2);
    BMP_WIN_MakeScreen(window);
    PRINTSYS_Print(BMP_WIN_GetBmp(window), 0, 0, msg, work->font);
    func_0201F79C(window, 0, work->bmpMenuWork, 2);
    BMP_WIN_TransferChars(window);
    STRBUF_Delete(msg);
}




void C_GEAR_POWER_ONOFF_OpenYesNoMenu(CGearPowerOnOffWork *work, int heapId)
{
    CGearPowerOnOffTable *table = &sPowerOnOffTable;

    table->menuHeapId = heapId;
    table->yesLabel = func_02045EC0(work->msgBank, 5);
    table->noLabel = func_02045EC0(work->msgBank, 6);
    work->taskMenu = APP_TASKMENU_OpenMenuFastDecide(&table->menuHeapId, work->taskMenuRes);
    APP_TASKMENU_SetDisableKey(work->taskMenu, 1);
    STRBUF_Delete(table->yesLabel);
    STRBUF_Delete(table->noLabel);
}



void C_GEAR_POWER_ONOFF_CloseMenu(CGearPowerOnOffWork *work)
{
    if (work->taskMenu != 0) {
        APP_TASKMENU_CloseMenu(work->taskMenu);
        work->taskMenu = 0;
    }
}



/*
 * extent: followers 021F0364 and 021F0370 already filed separately.
 */
void C_GEAR_POWER_ONOFF_UpdateMenu(CGearPowerOnOffWork *work)
{
    if (work->taskMenu != 0)
        APP_TASKMENU_UpdateMenu(work->taskMenu);
}




/*
 * Unlabelled tail-call leaf of C_GEAR_POWER_ONOFF_StepTurnOff (reads the menu handle at +0x44).
 */
u8 C_GEAR_POWER_ONOFF_GetMenuResult(CGearPowerOnOffWork *work)
{
    return APP_TASKMENU_GetCursorPos(work->taskMenu);
}




u32 C_GEAR_POWER_ONOFF_IsMenuDecided(CGearPowerOnOffWork *work)
{
    return APP_TASKMENU_IsFinish(work->taskMenu);
}




int C_GEAR_POWER_ONOFF_StepTurnOn(CGearPowerOnOffWork *work)
{
    u16 nextStep;

    switch (work->step) {
    case 0:
        C_GEAR_POWER_ONOFF_PrintMessage(work, work->messageWindow, 0);
        C_GEAR_POWER_ONOFF_PrintMessage(work, work->menuWindow, 3);
        C_GEAR_POWER_ONOFF_OpenYesNoMenu(work, work->heapId);
        (work->step)++;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1)
            (work->step)++;
        break;
    case 2:
        if (C_GEAR_POWER_ONOFF_IsMenuDecided(work) != 0) {
            if (C_GEAR_POWER_ONOFF_GetMenuResult(work) == 0) {
                GAMESYSTEM_SetAlwaysNetFlag(work->gameSystem, 1);
                GAMESYSTEM_TryStartAutoComm(work->gameSystem);
                nextStep = 3;
            } else {
                nextStep = 5;
            }
            work->step = nextStep;
            C_GEAR_POWER_ONOFF_CloseMenu(work);
        }
        break;
    case 3:
        C_GEAR_POWER_ONOFF_ResetAndPrintMessage(work, work->messageWindow, 1, 6);
        (work->step)++;
        break;
    case 4:
        if (TOUCHPANEL_GetTrg() != 0 || func_02012204(work->gameSystem) != 0)
            (work->step)++;
        break;
    case 5:
        if (func_02012204(work->gameSystem) != 0) {
            if (GAME_COMM_GetKind(work->beacon))
                GAME_COMM_RequestExitNoCallback(work->beacon);
            work->step = 6;
            break;
        }
        return 1;
    case 6:
        if (GAME_COMM_GetKind(work->beacon) == 0)
            return 1;
        break;
    }
    C_GEAR_POWER_ONOFF_UpdateMenu(work);
    return 0;
}




int C_GEAR_POWER_ONOFF_StepTurnOff(CGearPowerOnOffWork *work)
{
    u16 closeComm;

    switch (work->step) {
    case 0:
        C_GEAR_POWER_ONOFF_PrintMessage(work, work->messageWindow, 2);
        C_GEAR_POWER_ONOFF_PrintMessage(work, work->menuWindow, 3);
        C_GEAR_POWER_ONOFF_OpenYesNoMenu(work, work->heapId);
        (work->step)++;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1)
            (work->step)++;
        break;
    case 2:
        if (C_GEAR_POWER_ONOFF_IsMenuDecided(work) != 0 || func_02012204(work->gameSystem) == 1) {
            if (C_GEAR_POWER_ONOFF_GetMenuResult(work) == 0 || func_02012204(work->gameSystem) == 1) {
                if (GAME_COMM_GetKind(work->beacon))
                    GAME_COMM_RequestExitNoCallback(work->beacon);
                closeComm = 1;
            } else {
                closeComm = 0;
            }
            work->closeComm = closeComm;
            work->step = 3;
            C_GEAR_POWER_ONOFF_CloseMenu(work);
        }
        break;
    case 3:
        if (work->closeComm != 0) {
            if (GAME_COMM_GetKind(work->beacon) != 0)
                break;
            GAMESYSTEM_SetAlwaysNetFlag(work->gameSystem, 0);
        }
        (work->step)++;
        break;
    case 4:
        return 1;
    }
    C_GEAR_POWER_ONOFF_UpdateMenu(work);
    return 0;
}
