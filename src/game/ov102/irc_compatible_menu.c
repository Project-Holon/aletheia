/*
 * file:     irc_compatible_menu.c
 * unit:     yes
 * function: IRC_COMPATIBLE_MENU_ProcInit, IRC_COMPATIBLE_MENU_ProcExit, IRC_COMPATIBLE_MENU_ProcMain, IRC_COMPATIBLE_MENU_InitDisplay, IRC_COMPATIBLE_MENU_ExitDisplay, IRC_COMPATIBLE_MENU_DrawSprites, IRC_COMPATIBLE_MENU_GetSprite, IRC_COMPATIBLE_MENU_GetSpriteUnit, IRC_COMPATIBLE_MENU_VBlankTask, IRC_COMPATIBLE_MENU_InitBackgrounds, IRC_COMPATIBLE_MENU_ExitBackgrounds, IRC_COMPATIBLE_MENU_BackgroundVBlank, IRC_COMPATIBLE_MENU_InitSprites, IRC_COMPATIBLE_MENU_ExitSprites, IRC_COMPATIBLE_MENU_DrawSpriteSystem, IRC_COMPATIBLE_MENU_VBlankSpriteSystem, IRC_COMPATIBLE_MENU_SpriteSetGetActor, IRC_COMPATIBLE_MENU_SpriteSetGetUnit, IRC_COMPATIBLE_MENU_InitText, IRC_COMPATIBLE_MENU_ExitText, IRC_COMPATIBLE_MENU_UpdateTextQueue, IRC_COMPATIBLE_MENU_TextGetFont, IRC_COMPATIBLE_MENU_TextGetPrintQueue, IRC_COMPATIBLE_MENU_TextGetMsgData, IRC_COMPATIBLE_MENU_InitTitleWindow, IRC_COMPATIBLE_MENU_InitWindow, IRC_COMPATIBLE_MENU_ExitWindow, IRC_COMPATIBLE_MENU_UpdateWindow, IRC_COMPATIBLE_MENU_PrintMessage, IRC_COMPATIBLE_MENU_PrintMessageCentered, IRC_COMPATIBLE_MENU_SetHandler, IRC_COMPATIBLE_MENU_SetFinished, IRC_COMPATIBLE_MENU_HandleStartTests, IRC_COMPATIBLE_MENU_HandleChoice, IRC_COMPATIBLE_MENU_HandleFinish, IRC_COMPATIBLE_MENU_HandleOpen, IRC_COMPATIBLE_MENU_HandleQuit, IRC_COMPATIBLE_MENU_HandleCheckLink, IRC_COMPATIBLE_MENU_UpdateScene, IRC_COMPATIBLE_MENU_InitButtons, IRC_COMPATIBLE_MENU_ExitButtons, IRC_COMPATIBLE_MENU_UpdateButtons, IRC_COMPATIBLE_MENU_SetButtonsEnabled, IRC_COMPATIBLE_MENU_IsButtonPressed, IRC_COMPATIBLE_MENU_PollChoice, IRC_COMPATIBLE_MENU_ResetButtonPalettes, IRC_COMPATIBLE_MENU_ButtonCallback, IRC_COMPATIBLE_MENU_InitScrollEffect, IRC_COMPATIBLE_MENU_ExitScrollEffect, IRC_COMPATIBLE_MENU_UpdateScrollEffect, IRC_COMPATIBLE_MENU_StartScrollEffect, IRC_COMPATIBLE_MENU_InitFloater, IRC_COMPATIBLE_MENU_ExitFloater, IRC_COMPATIBLE_MENU_UpdateFloater, IRC_COMPATIBLE_MENU_ResetFloaterPath, IRC_COMPATIBLE_MENU_InitFloaters, IRC_COMPATIBLE_MENU_ExitFloaters, IRC_COMPATIBLE_MENU_UpdateFloaters, IRC_COMPATIBLE_MENU_InitLinearStep, IRC_COMPATIBLE_MENU_StepLinear
 * address:  0x021B7560
 * region:   ov102
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BG_SYS_SetScrollY 0x02041F6C arm
 *   BG_SYS_SetAffine 0x02041FB0 arm
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SAVE_CONTROL_Get 0x020070A4 thumb
 *   IRC_RANKING_GetFromSave 0x0200A8A0 thumb
 *   IRC_APPBAR_Create 0x021B70DC thumb ov101
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   COMPATIBLE_IRC_SYS_SetOwnValue 0x021B63CC thumb ov101
 *   IRC_COMPATIBLE_MENU_ButtonRows 0x021B8AD4 data a4
 *   IRC_APPBAR_Delete 0x021B71C0 thumb ov101
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   IRC_COMPATIBLE_MENU_VramBankConfig 0x021B8B2C data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   GF_FONT_MeasureWidestLine 0x0201D304 thumb
 *   GF_FONT_CountLines 0x0201D42C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   IRC_APPBAR_Reset 0x021B7264 thumb ov101
 *   IRC_APPBAR_SetActive 0x021B72A0 thumb ov101
 *   IRC_APPBAR_SetLabel 0x021B72A8 thumb ov101
 *   COMPATIBLE_IRC_SYS_ResetStep 0x021B63BC thumb ov101
 *   COMPATIBLE_IRC_SYS_StepStartSession 0x021B6150 thumb ov101
 *   COMPATIBLE_IRC_SYS_StepConnectChild 0x021B6254 thumb ov101
 *   COMPATIBLE_IRC_SYS_StepSyncTiming 0x021B62AC thumb ov101
 *   COMPATIBLE_IRC_SYS_StepSendProfile 0x021B6568 thumb ov101
 *   COMPATIBLE_IRC_SYS_GetPartnerProfile 0x021B657C thumb ov101
 *   COMPATIBLE_IRC_SYS_StepShareValue 0x021B630C thumb ov101
 *   COMPATIBLE_IRC_SYS_SendProfileRequest 0x021B6518 thumb ov101
 *   COMPATIBLE_IRC_SYS_PollProfileRequest 0x021B652C thumb ov101
 *   COMPATIBLE_IRC_SYS_SendProfileAck 0x021B6540 thumb ov101
 *   COMPATIBLE_IRC_SYS_PollProfileAck 0x021B6554 thumb ov101
 *   COMPATIBLE_IRC_SYS_SendOwnValue 0x021B6424 thumb ov101
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   MISC_SAVEDATA_InsertRecentValue 0x0200ED54 thumb
 *   OS_GetTick 0x020870D0 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   IRC_APPBAR_IsPressed 0x021B7254 thumb ov101
 *   COMPATIBLE_IRC_SYS_ClearValues 0x021B63C4 thumb ov101
 *   COMPATIBLE_IRC_SYS_StepShutdown 0x021B61E8 thumb ov101
 *   COMPATIBLE_IRC_SYS_IsPartnerReady 0x021B62FC thumb ov101
 *   IRC_APPBAR_Update 0x021B71E4 thumb ov101
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   IRC_COMPATIBLE_MENU_StepLinear 0x021B8A90 thumb ov102
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   GFL_USE_GetRandomBelow  0x02005728  thumb
 *   CLACT_SetActorAnimFrame  0x0204B8C4  arm
 *   _u32_div_f 0x0209C2B0 arm
 *   IRC_RANKING_GetEntryCount  0x0200A8AC  thumb
 *   IRC_RANKING_GetEntryGender  0x0200A8F8  thumb
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   IRC_COMPATIBLE_MENU_BgLayerIds 0x021B8AEC data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   gClActorInitParam 0x020A1448 data a4
 *   IRC_COMPATIBLE_MENU_BgDisplayConfig 0x021B8AC4 data a4
 *   IRC_COMPATIBLE_MENU_BgTemplates 0x021B8B5C data a4
 *   IRC_COMPATIBLE_MENU_BgLayerTypes 0x021B8B0C data a4
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   BMP_WIN_Init  0x02045088  arm  arm9
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   BG_SYS_Create  0x0203F8F4  arm  arm9
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm  arm9
 *   BG_SYS_Init  0x02040C14  arm  arm9
 *   GF_FONT_InitTextColor  0x0201DD60  thumb  arm9
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm  arm9
 *   BG_SYS_FreeSlot  0x020414AC  arm  arm9
 *   BG_SYS_SetPlaneVisible  0x02040588  arm  arm9
 *   MSGDATA_CreateFromArchive  0x02045B38  arm  arm9
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm  arm9
 *   ARC_UTIL_RegisterObjCharFromHandle  0x02049740  arm  arm9
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm  arm9
 *   ARC_UTIL_UploadPaletteFromArchiveWhole  0x02049B40  arm  arm9
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm  arm9
 */
#include "irc_screen_types.h"
#include "../ov101/irc_appbar.h"

/* Number of sprite slots the screen reserves (slot 30 stays unused). */
#define IRC_MENU_SPRITE_COUNT 32
/* The sprite of the animated figure on the menu. */
#define IRC_MENU_SPRITE_FIGURE 31
/* Number of floating sprites the floater system can run. */
#define IRC_MENU_FLOATER_MAX 30

struct IrcMenuWork;

enum {
    IRC_MENU_CHOICE_RUN_TESTS = 0,
    IRC_MENU_CHOICE_HELP = 1,
    IRC_MENU_CHOICE_QUIT = 2
};

enum {
    IRC_MENU_MODE_FIRST_ENTRY = 0,
    IRC_MENU_MODE_NORMAL = 1,
    IRC_MENU_MODE_BACK_FROM_HELP = 2
};


typedef void (*IrcMenuHandler)(struct IrcMenuWork *work, u16 *state);

/* Sprite set of the menu: the shared resources and one actor per slot (144 bytes). */
typedef struct IrcMenuSprites {
    IrcSpriteResources res;
    void *actors[IRC_MENU_SPRITE_COUNT];
} IrcMenuSprites;

/* Background setup: the loaded character range and the task that runs the BG vblank. */
typedef struct IrcBgSetup {
    u32 charRange;           /* offset in the low half, size in the high half */
    u32 vblankTask;
} IrcBgSetup;

/* One row of the button table: text id, cell position and size, window palette. */
typedef struct IrcButtonRow {
    u16 msgId;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 palette;
} IrcButtonRow;

/* Touch buttons made of one BMP window each (60 bytes). */
typedef struct IrcButtons {
    void *buttonMan;                 /* 0x00 */
    void *windows[4];                /* 0x04 */
    u8 bounds[20];                   /* 0x14 touch rectangles: top, bottom, left, right, end mark 255 */
    const IrcButtonRow *rows;        /* 0x28 */
    u16 count;                       /* 0x2C */
    u16 bgLayer;                     /* 0x2E */
    u16 selected;                    /* 0x30 button the callback reported */
    u16 done;                        /* 0x32 set when a press finished its blink */
    u16 phase;                       /* 0x34 0 waiting, 1 blinking the pressed button */
    u16 timer;                       /* 0x36 */
    u32 enabled;                     /* 0x38 */
} IrcButtons;

/* Fixed point (20.12) walk from start to target in duration steps (24 bytes). */
typedef struct IrcLinearStep {
    int value;                       /* 0x00 current value */
    int start;                       /* 0x04 */
    int target;                      /* 0x08 */
    int step;                        /* 0x0C change per step */
    int counter;                     /* 0x10 */
    int duration;                    /* 0x14 */
} IrcLinearStep;

/* Background scroll effect: a linear step plus an active flag (28 bytes). */
typedef struct IrcScrollEffect {
    IrcLinearStep step;
    u32 active;                      /* 0x18 */
} IrcScrollEffect;

/* One floating sprite that moves from the bottom of the screen to the top (28 bytes). */
typedef struct IrcFloater {
    int endX;                        /* 0x00 */
    int endY;                        /* 0x04 */
    int startX;                      /* 0x08 */
    int startY;                      /* 0x0C */
    u32 step;                        /* 0x10 */
    u32 duration;                    /* 0x14 */
    void *actor;                     /* 0x18 */
} IrcFloater;

typedef struct IrcFloaters {
    IrcFloater floater[IRC_MENU_FLOATER_MAX];
    u32 tick;                        /* 0x348 */
    u16 activeCount;                 /* 0x34C floaters released so far */
    u16 totalCount;                  /* 0x34E */
} IrcFloaters;

/* Work area of the menu step (0x4A4 bytes). */
typedef struct IrcMenuWork {
    IrcMenuSprites sprites;          /* 0x000 */
    u32 vblankTask;                  /* 0x090 */
    IrcBgSetup bg;                   /* 0x094 */
    IrcTextSystem text;              /* 0x09C */
    IrcWindow title;                 /* 0x0AC */
    IrcButtons buttons;              /* 0x0C0 */
    IrcScrollEffect scroll;          /* 0x0FC */
    IrcFloaters floaters;            /* 0x118 */
    IrcAppBar *appBar;        /* 0x468 */
    IrcWindow bottomWin;             /* 0x46C */
    IrcMenuHandler handler;          /* 0x480 */
    u16 handlerState;                /* 0x484 */
    u16 ticks;                       /* 0x486 */
    u32 finished;                    /* 0x488 */
    IrcMenuArgs *args;               /* 0x48C */
    u32 startTime;                   /* 0x490 time of entry in milliseconds */
    u32 choice;                      /* 0x494 button the player pressed */
    u32 elapsed;                     /* 0x498 milliseconds since entry */
    u32 counter;                     /* 0x49C frames waited before the exit */
    u32 flag;                        /* 0x4A0 set while the profile exchange runs */
} IrcMenuWork;

extern void GFL_HEAP_CreateChildHeap(u32 parentId, u32 heapId, u32 size);
extern void *PROCSYS_AllocProcWork(void *proc, u32 size, u32 heapId);
extern void MI_CpuFill8(void *dest, int value, u32 size);
extern u32 GAMESYSTEM_GetGameComm(void *gameSystem);
extern void BMP_MENUWORK_DrawWindow(void *bmpWin, int commitMode, int tileBase, int palette);
extern void BG_SYS_SetScrollY(u32 which, u32 op, u32 value);
extern void BG_SYS_SetAffine(u32 which, u32 op, u16 value);
extern void *GAMESYSTEM_GetGameData(void *gameSystem);
extern void *GAME_DATA_GetSaveControl(void *gameData);
extern void *SAVE_CONTROL_Get(void);
extern void *IRC_RANKING_GetFromSave(void *saveControl);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void COMPATIBLE_IRC_SYS_SetOwnValue(IrcSys *sys, int value);
extern void PROCSYS_FreeProcWork(void *proc);
extern void GFL_HEAP_DeleteChecked(unsigned heapId);
extern void FADE_Start(u32, int, int, int);
extern int FADE_IsActive(void);
extern void CLACT_SetActorAutoAnim(void *actor, u32 enable);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 bgmId, u16 volume);
extern void BG_SYS_ClearGraphicsMemory(unsigned);
extern void BMP_SetDisplaySwap(unsigned);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_SetVramBanks(const void *config);
extern unsigned GFL_USE_AddMainTask(void (*task)(unsigned, void *), void *work, unsigned priority);
extern void TCB_DeleteTask(unsigned task);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void BG_SYS_SetGraphicsMode(const void *config);
extern void BG_SYS_InitBgLayer(u32 bgId, const void *template, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(u8, u8);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *, u32, u32, u32, u32, u16);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *, u32, u32, u32, u32, u32, u16);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *, u32, u32, u32, u32, u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_SetTileUnit(unsigned, unsigned, unsigned);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const void *config, u32 arg, u32 heapId);
extern void *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(void *unit);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern int CLACT_RegisterPalette(void *, u32, u32, u32, u16);
extern int CLACT_RegisterCharacter(void *, u32, u32, u32, u16);
extern int CLACT_RegisterCellAnim(void *, u32, u32, u32);
extern void *CLACT_CreateActor(void *, u32, u32, u32, const void *, u16, u16);
extern void CLACT_SetActorDrawEnable(void *, unsigned int);
extern void CLACT_SetActorBgPriority(void *, u32);
extern void CLACT_DeleteActor(void *actor);
extern void CLACT_ReleasePalette(unsigned);
extern void CLACT_ReleaseCharacter(unsigned);
extern void CLACT_ReleaseCellAnim(unsigned);
extern u32 CLACT_DeleteUnit(void *unit);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void GF_FONT_InitTextColor(void);
extern void *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
extern void *PRINTSYS_QUE_Create(u32 heapId);
extern void *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *WORDSET_CreateDefault(u32 heap);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern void WORDSET_DeleteStrbufED04(void *wordSet);
extern void MSGDATA_Delete(void *msgData);
extern void PRINTSYS_QUE_Delete(void *printQueue);
extern void GF_FONT_Delete(void *font);
extern u32 PRINTSYS_QUE_Main(void *printQueue);
extern void *BMP_WIN_Create(u32 bgLayer, u32 x, u32 y, u32 width, u8 height, u8 palette, u8 charBase);
extern void *STRBUF_Create(u32 capacity, u32 heapId);
extern void *BMP_WIN_GetBmp(void *bmpWin);
extern void BMP_Clear(void *bmp, u8 value);
extern void BMP_WIN_TransferChars(void *bmpWin);
extern void BMP_WIN_MakeScreen(void *bmpWin);
extern u8 BMP_WIN_GetBgLayer(void *bmpWin);
extern void BG_SYS_PushTile(u32 bgLayer);
extern void STRBUF_Delete(void *strBuf);
extern void BMP_WIN_Delete(void *bmpWin);
extern int PRINTSYS_QUE_IsExistTarget(void *printQueue, void *bmp);
extern void MSGDATA_ReadString(void *msgData, u32 msgId, void *dest);
extern void PRINTSYS_PrintQue(void *printQueue, void *bmp, u32 x, u32 y, void *strBuf, void *font);
extern u8 BMP_WIN_GetWidth(void *bmpWin);
extern u8 BMP_WIN_GetHeight(void *bmpWin);
extern u32 GF_FONT_MeasureWidestLine(void *strBuf, void *font, u32 margin);
extern u32 GF_FONT_CountLines(void *strBuf, void *font);
extern void PRINTSYS_QUE_Clear(void *printQueue);
extern void PRINTSYS_PrintQueColor(void *printQueue, void *bmp, u32 x, u32 y, void *strBuf, void *font, u16 color);
extern void COMPATIBLE_IRC_SYS_ResetStep(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_StepStartSession(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_StepConnectChild(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_StepSyncTiming(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_StepShareValue(IrcSys *sys, int value);
extern int COMPATIBLE_IRC_SYS_StepSendProfile(IrcSys *sys, void *gameSystem);
extern int COMPATIBLE_IRC_SYS_SendProfileRequest(IrcSys *sys, u32 elapsed, u32 choice);
extern void COMPATIBLE_IRC_SYS_GetPartnerProfile(IrcSys *sys, IrcCompatibleProfile *out);
extern int COMPATIBLE_IRC_SYS_PollProfileRequest(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_SendProfileAck(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_PollProfileAck(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_SendOwnValue(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(IrcSys *sys);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern void *MISC_SAVEDATA_GetBlock44(void *saveControl);
extern u32 MYSTATUS_GetId(const u8 *myStatus);
extern void MISC_SAVEDATA_InsertRecentValue(void *saveData, u32 value);
extern unsigned long long OS_GetTick(void);
extern u32 _u32_div_f(u32, u32);
extern void COMPATIBLE_IRC_SYS_ClearValues(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_StepShutdown(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_IsPartnerReady(IrcSys *sys);
extern void *BUTTON_MAN_Create(u8 *bounds, void (*callback)(u16, int, struct IrcButtons *), struct IrcButtons *userData, u32 heapId);
extern void *MSGDATA_AllocString(void *msgData, u32 msgId);
extern void GF_FONT_SetTextColor(u32, u32, u32);
extern void PRINTSYS_Print(void *bmp, s16 x, s16 y, void *strBuf, void *font);
extern void GF_FONT_SetDefaultTextColor(void);
extern void BUTTON_MAN_Delete(void *buttonMan);
extern int BUTTON_MAN_UpdateSlots(void *buttonMan);
extern void BG_SYS_FillTileMap(u8 bgLayer, u8 x, u8 y, u8 width, u8 height, u8 palette);
extern void BG_SYS_ResetSlot(u32 which, u32 op, u32 value);
extern void CLACT_SetActorAnimSeq(void *actor, int seq);
extern void CLACT_AddActorSurfacePos(void *actor, const void *delta, u32 which);
extern u32 GFL_USE_GetRandomBelow(u32 range);
extern void CLACT_SetActorAnimFrame(void *actor, u32 frame);
extern s32 IRC_RANKING_GetEntryCount(void *records);
extern u32 IRC_RANKING_GetEntryGender(void *records, u32 index);

extern u32 IRC_COMPATIBLE_MENU_ButtonRows[];
extern unsigned IRC_COMPATIBLE_MENU_VramBankConfig[];
extern u32 IRC_COMPATIBLE_MENU_BgDisplayConfig[], IRC_COMPATIBLE_MENU_BgLayerIds[], IRC_COMPATIBLE_MENU_BgLayerTypes[];
extern const u32 IRC_COMPATIBLE_MENU_BgTemplates[][8];
extern char gClActorInitParam[];

int IRC_COMPATIBLE_MENU_ProcInit(void *proc, int unused, IrcMenuArgs *args);
int IRC_COMPATIBLE_MENU_ProcExit(void *proc, int unused, int unused2, IrcMenuWork *work);
int IRC_COMPATIBLE_MENU_ProcMain(void *unused, u32 *state, int unused2, IrcMenuWork *work);
void IRC_COMPATIBLE_MENU_InitDisplay(IrcMenuWork *work, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitDisplay(IrcMenuWork *work);
void IRC_COMPATIBLE_MENU_DrawSprites(IrcMenuWork *work);
void *IRC_COMPATIBLE_MENU_GetSprite(IrcMenuWork *work, int index);
void *IRC_COMPATIBLE_MENU_GetSpriteUnit(IrcMenuWork *work);
void IRC_COMPATIBLE_MENU_VBlankTask(unsigned taskId, void *work);
void IRC_COMPATIBLE_MENU_InitBackgrounds(IrcBgSetup *bg, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitBackgrounds(IrcBgSetup *bg);
void IRC_COMPATIBLE_MENU_BackgroundVBlank(unsigned taskId, void *work);
void IRC_COMPATIBLE_MENU_InitSprites(IrcMenuSprites *sprites, const void *config, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitSprites(IrcMenuSprites *sprites);
void IRC_COMPATIBLE_MENU_DrawSpriteSystem(void);
void IRC_COMPATIBLE_MENU_VBlankSpriteSystem(void *sprites);
void *IRC_COMPATIBLE_MENU_SpriteSetGetActor(IrcMenuSprites *sprites, int index);
void *IRC_COMPATIBLE_MENU_SpriteSetGetUnit(IrcMenuSprites *sprites);
void IRC_COMPATIBLE_MENU_InitText(IrcTextSystem *text, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitText(IrcTextSystem *text);
void IRC_COMPATIBLE_MENU_UpdateTextQueue(IrcTextSystem *text);
void *IRC_COMPATIBLE_MENU_TextGetFont(IrcTextSystem *text);
void *IRC_COMPATIBLE_MENU_TextGetPrintQueue(IrcTextSystem *text);
void *IRC_COMPATIBLE_MENU_TextGetMsgData(IrcTextSystem *text);
void IRC_COMPATIBLE_MENU_InitTitleWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 heapId);
void IRC_COMPATIBLE_MENU_InitWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 fillColor, u8 charBase, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitWindow(IrcWindow *win);
int IRC_COMPATIBLE_MENU_UpdateWindow(IrcWindow *win, IrcTextSystem *text);
void IRC_COMPATIBLE_MENU_PrintMessage(IrcWindow *win, IrcTextSystem *text, int msgId, int x, s16 y);
void IRC_COMPATIBLE_MENU_PrintMessageCentered(IrcWindow *win, IrcTextSystem *text, int msgId);
void IRC_COMPATIBLE_MENU_SetHandler(IrcMenuWork *work, IrcMenuHandler handler);
void IRC_COMPATIBLE_MENU_SetFinished(IrcMenuWork *work);
void IRC_COMPATIBLE_MENU_HandleStartTests(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_HandleChoice(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_HandleFinish(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_HandleOpen(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_HandleQuit(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_HandleCheckLink(IrcMenuWork *work, u16 *state);
void IRC_COMPATIBLE_MENU_UpdateScene(IrcMenuWork *work);
void IRC_COMPATIBLE_MENU_InitButtons(IrcButtons *buttons, int bgLayer, const IrcButtonRow *rows, int count, IrcTextSystem *text, u16 heapId);
void IRC_COMPATIBLE_MENU_ExitButtons(IrcButtons *buttons);
void IRC_COMPATIBLE_MENU_UpdateButtons(IrcButtons *buttons);

void IRC_COMPATIBLE_MENU_SetButtonsEnabled(IrcButtons *buttons, u32 enabled);
int IRC_COMPATIBLE_MENU_IsButtonPressed(IrcButtons *buttons);
int IRC_COMPATIBLE_MENU_PollChoice(IrcButtons *buttons, int *out);
void IRC_COMPATIBLE_MENU_ResetButtonPalettes(IrcButtons *buttons);
void IRC_COMPATIBLE_MENU_ButtonCallback(u16 value, int flag, IrcButtons *buttons);
void IRC_COMPATIBLE_MENU_InitScrollEffect(IrcScrollEffect *effect, u32 unused);
void IRC_COMPATIBLE_MENU_ExitScrollEffect(IrcScrollEffect *effect);
void IRC_COMPATIBLE_MENU_UpdateScrollEffect(IrcScrollEffect *effect);
void IRC_COMPATIBLE_MENU_StartScrollEffect(IrcScrollEffect *effect);
void IRC_COMPATIBLE_MENU_InitFloater(IrcFloater *floater, void *actor, int isSpecial, int unused);
void IRC_COMPATIBLE_MENU_ExitFloater(IrcFloater *floater);
void IRC_COMPATIBLE_MENU_UpdateFloater(IrcFloater *floater);
void IRC_COMPATIBLE_MENU_ResetFloaterPath(IrcFloater *floater);
void IRC_COMPATIBLE_MENU_InitFloaters(IrcFloaters *floaters, IrcMenuWork *work, void *records, int unused);
void IRC_COMPATIBLE_MENU_ExitFloaters(IrcFloaters *floaters);
void IRC_COMPATIBLE_MENU_UpdateFloaters(IrcFloaters *floaters);
void IRC_COMPATIBLE_MENU_InitLinearStep(IrcLinearStep *step, int start, int target, int duration);
int IRC_COMPATIBLE_MENU_StepLinear(IrcLinearStep *step);

int IRC_COMPATIBLE_MENU_ProcInit(void *proc, int unused, IrcMenuArgs *args)
{
    IrcMenuWork *work;
    void *saveData;
    void *unit;
    void *font, *printQueue;
    GFL_HEAP_CreateChildHeap(1, 59, 0x40000);
    work = PROCSYS_AllocProcWork(proc, 0x4a4, 59);
    MI_CpuFill8(work, 0, 0x4a4);
    work->args = args;
    IRC_COMPATIBLE_MENU_InitText(&work->text, 59);
    IRC_COMPATIBLE_MENU_InitDisplay(work, 59);
    IRC_COMPATIBLE_MENU_InitBackgrounds(&work->bg, 59);
    if (work->args->gameSystem) GAMESYSTEM_GetGameComm(work->args->gameSystem);
    IRC_COMPATIBLE_MENU_InitButtons(&work->buttons, 2, (const IrcButtonRow *)IRC_COMPATIBLE_MENU_ButtonRows, 2, &work->text, 59);
    IRC_COMPATIBLE_MENU_InitTitleWindow(&work->title, 5, 1, 18, 30, 5, 8, 59);
    BMP_MENUWORK_DrawWindow(work->title.bmpWin, 0, (u16)work->bg.charRange, 6);
    IRC_COMPATIBLE_MENU_PrintMessage(&work->title, &work->text, 5, 0, 0);
    IRC_COMPATIBLE_MENU_InitWindow(&work->bottomWin, 7, 6, 3, 20, 5, 8, 1, 1, 59);
    IRC_COMPATIBLE_MENU_PrintMessageCentered(&work->bottomWin, &work->text, 10);
    BG_SYS_SetScrollY(7, 3, 0x1000);
    BG_SYS_SetScrollY(7, 6, 0x1000);
    BG_SYS_SetAffine(7, 9, 128);
    BG_SYS_SetAffine(7, 12, 40);
    IRC_COMPATIBLE_MENU_InitScrollEffect(&work->scroll, 59);
    saveData = work->args->gameSystem;
    if (saveData) saveData = GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(saveData));
    else saveData = SAVE_CONTROL_Get();
    IRC_COMPATIBLE_MENU_InitFloaters(&work->floaters, work, IRC_RANKING_GetFromSave(saveData), 59);
    unit = IRC_COMPATIBLE_MENU_GetSpriteUnit(work);
    font = IRC_COMPATIBLE_MENU_TextGetFont(&work->text);
    printQueue = IRC_COMPATIBLE_MENU_TextGetPrintQueue(&work->text);
    work->appBar = IRC_APPBAR_Create(2, unit, 0, 14, 0, 2, font, printQueue, 59);
    switch (work->args->mode) {
    case IRC_MENU_MODE_FIRST_ENTRY: IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleChoice); break;
    case IRC_MENU_MODE_NORMAL: IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleOpen); break;
    case IRC_MENU_MODE_BACK_FROM_HELP: IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleChoice); break;
    }
    GFL_USE_CancelChangeAndStopBgm();
    COMPATIBLE_IRC_SYS_SetOwnValue(work->args->view, 0);
    return 1;
}

int IRC_COMPATIBLE_MENU_ProcExit(void *proc, int unused, int unused2, IrcMenuWork *work)
{
    IRC_APPBAR_Delete(work->appBar);
    IRC_COMPATIBLE_MENU_ExitFloaters(&work->floaters);
    IRC_COMPATIBLE_MENU_ExitScrollEffect(&work->scroll);
    IRC_COMPATIBLE_MENU_ExitButtons(&work->buttons);
    IRC_COMPATIBLE_MENU_ExitWindow(&work->bottomWin);
    IRC_COMPATIBLE_MENU_ExitWindow(&work->title);
    IRC_COMPATIBLE_MENU_ExitBackgrounds(&work->bg);
    IRC_COMPATIBLE_MENU_ExitDisplay(work);
    IRC_COMPATIBLE_MENU_ExitText(&work->text);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x3b);
    return 1;
}

int IRC_COMPATIBLE_MENU_ProcMain(void *unused, u32 *state, int unused2, IrcMenuWork *work)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        FADE_Start(3, 16, 0, 0);
        *state = 2;
        break;
    case 2:
        if (FADE_IsActive() == 0) {
            CLACT_SetActorAutoAnim(IRC_COMPATIBLE_MENU_GetSprite(work, IRC_MENU_SPRITE_FIGURE), 1);
            IRC_COMPATIBLE_MENU_StartScrollEffect(&work->scroll);
            GFL_USE_CancelChangeAndPlayBgm(0x52a, 0xffff);
            *state = 3;
        }
        break;
    case 3:
        IRC_COMPATIBLE_MENU_UpdateFloaters(&work->floaters);
        IRC_COMPATIBLE_MENU_UpdateScrollEffect(&work->scroll);
        work->handler(work, &work->handlerState);
        if (work->finished != 0) *state = 4;
        break;
    case 4:
        FADE_Start(3, 0, 16, 0);
        *state = 5;
        break;
    case 5:
        if (FADE_IsActive() == 0) *state = 6;
        break;
    case 6:
        return 1;
    }
    IRC_COMPATIBLE_MENU_UpdateScene(work);
    return 0;
}

/*
 * volatile: 0x021B787A and 0x021B7884 read display registers for update.
 */
void IRC_COMPATIBLE_MENU_InitDisplay(IrcMenuWork *work, u16 heapId)
{
    MI_CpuFill8(work, 0, 0x94);
    REG_BLDCNT_MAIN = 0;
    REG_BLDCNT_SUB = 0;
    REG_DISPCNT_MAIN &= ~0xe000;
    REG_DISPCNT_SUB &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BMP_SetDisplaySwap(0);
    BG_SYS_ResetSubDisplay();
    BG_SYS_SetVramBanks(IRC_COMPATIBLE_MENU_VramBankConfig);
    IRC_COMPATIBLE_MENU_InitSprites(&work->sprites, IRC_COMPATIBLE_MENU_VramBankConfig, heapId);
    work->vblankTask = GFL_USE_AddMainTask(IRC_COMPATIBLE_MENU_VBlankTask, work, 0);
}

void IRC_COMPATIBLE_MENU_ExitDisplay(IrcMenuWork *work)
{
    TCB_DeleteTask(work->vblankTask);
    IRC_COMPATIBLE_MENU_ExitSprites(&work->sprites);
}

/*
 * evidence: IRC_COMPATIBLE_MENU_DrawSpriteSystem is ov102's own code ("ldr r3, =0x0204A600; bx r3"
 * after the pop at 0x021B7C00), inside ov102's window, so only ov102 can be
 * resident there when this pool word is used.  Its start is seeded in
 * layout/function_starts.txt from this pointer word, the only reference;
 * it attests as sole-ref/code from ov102's own listing.  The old hint ov021
 * named a different overlay's function mapped over the same address.
 */
void IRC_COMPATIBLE_MENU_DrawSprites(IrcMenuWork *work) { IRC_COMPATIBLE_MENU_DrawSpriteSystem(); }

void *IRC_COMPATIBLE_MENU_GetSprite(IrcMenuWork *work, int index) { return IRC_COMPATIBLE_MENU_SpriteSetGetActor(&work->sprites, index); }

void *IRC_COMPATIBLE_MENU_GetSpriteUnit(IrcMenuWork *work) { return IRC_COMPATIBLE_MENU_SpriteSetGetUnit(&work->sprites); }

void IRC_COMPATIBLE_MENU_VBlankTask(unsigned taskId, void *work) { IRC_COMPATIBLE_MENU_VBlankSpriteSystem(work); }

void IRC_COMPATIBLE_MENU_InitBackgrounds(IrcBgSetup *bg, u16 heapId)
{
    int i;
    u32 layer;
    void *arc;
    BG_SYS_Create(heapId);
    BMP_WIN_Init(heapId);
    BG_SYS_SetGraphicsMode(IRC_COMPATIBLE_MENU_BgDisplayConfig);
    for (i = 0; i < 8; i++) {
        layer = IRC_COMPATIBLE_MENU_BgLayerIds[i];
        BG_SYS_InitBgLayer((u8)layer, IRC_COMPATIBLE_MENU_BgTemplates[i], (u8)IRC_COMPATIBLE_MENU_BgLayerTypes[i]);
        BG_SYS_FreeSlot(layer);
        BG_SYS_SetPlaneVisible(layer, 1);
    }
    arc = ARC_TOOL_CreateHandle(94, heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 1, 0, 0, 0, heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc, 1, 4, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, 0, 3, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, 0, 6, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, 48, 4, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arc, 42, 2, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 4, 3, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 4, 6, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 44, 4, 0, 0, 0, heapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arc, 43, 2, 0, 0, 0, heapId);
    BG_SYS_Init(5, 0, 1, 0);
    bg->charRange = ARC_UTIL_RegisterObjCharFromHandle(arc, 49, 5, 0, 0, heapId);
    ARC_TOOL_DeleteHandle(arc);
    bg->vblankTask = GFL_USE_AddMainTask(IRC_COMPATIBLE_MENU_BackgroundVBlank, bg, 0);
}

/*
 * note: Packed word supplies low/high halfwords, not duplicate low halves. Includes tail-call follower 021B7AAC.
 */
void IRC_COMPATIBLE_MENU_ExitBackgrounds(IrcBgSetup *bg)
{
    int i;
    unsigned range;
    TCB_DeleteTask(bg->vblankTask);
    range = bg->charRange;
    BG_SYS_DeleteHalf(5, (u16)range, (u16)(range >> 16));
    BG_SYS_SetTileUnit(5, 1, 0);
    for (i = 0; i < 8; i++) BG_SYS_FreeLayerBuf((u8)IRC_COMPATIBLE_MENU_BgLayerIds[i]);
    BMP_WIN_Exit();
    BG_SYS_Delete();
}

void IRC_COMPATIBLE_MENU_BackgroundVBlank(unsigned taskId, void *work) { BG_SYS_Update(); }

/*
 * declaration: 0204ABF0 forwards the live result of int-returning 0204AC18; 0204B294 forwards the pointer result of 0204CFDC. Its fifth word is copied unchanged as 0204CFDC's request pointer.
 */
void IRC_COMPATIBLE_MENU_InitSprites(IrcMenuSprites *sprites, const void *config, u16 heapId)
{
    void *arc;
    int i;
    u16 position[4];
    MI_CpuFill8(sprites, 0, 0x90);
    CLACT_InitSystem(gClActorInitParam, (u32)config, heapId);
    sprites->res.unit = CLACT_CreateUnit(128, 0, heapId);
    CLACT_SetUnitDefaultRenderer(sprites->res.unit);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    arc = ARC_TOOL_CreateHandle(94, heapId);
    sprites->res.palette = CLACT_RegisterPalette(arc, 12, 1, 0, heapId);
    sprites->res.characters = CLACT_RegisterCharacter(arc, 11, 0, 1, heapId);
    sprites->res.cellAnim = CLACT_RegisterCellAnim(arc, 10, 9, heapId);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(position, 0, 8);
    for (i = 0; i < IRC_MENU_FLOATER_MAX; i++) {
        sprites->actors[i] = CLACT_CreateActor(sprites->res.unit, sprites->res.characters, sprites->res.palette, sprites->res.cellAnim, position, 1, heapId);
        CLACT_SetActorDrawEnable(sprites->actors[i], 0);
        CLACT_SetActorBgPriority(sprites->actors[i], 3);
        CLACT_SetActorAutoAnim(sprites->actors[i], 1);
    }
    position[0] = 129;
    position[1] = 104;
    position[2] = 15;
    sprites->actors[IRC_MENU_SPRITE_FIGURE] = CLACT_CreateActor(sprites->res.unit, sprites->res.characters, sprites->res.palette, sprites->res.cellAnim, position, 1, heapId);
    CLACT_SetActorDrawEnable(sprites->actors[IRC_MENU_SPRITE_FIGURE], 1);
    CLACT_SetActorBgPriority(sprites->actors[IRC_MENU_SPRITE_FIGURE], 2);
    CLACT_SetActorAutoAnim(sprites->actors[IRC_MENU_SPRITE_FIGURE], 0);
}

void IRC_COMPATIBLE_MENU_ExitSprites(IrcMenuSprites *sprites)
{
    int i;
    for (i = 0; i < IRC_MENU_SPRITE_COUNT; i++) {
        if (sprites->actors[i]) CLACT_DeleteActor(sprites->actors[i]);
    }
    CLACT_ReleasePalette(sprites->res.palette);
    CLACT_ReleaseCharacter(sprites->res.characters);
    CLACT_ReleaseCellAnim(sprites->res.cellAnim);
    CLACT_DeleteUnit(sprites->res.unit);
    CLACT_ExitSystem();
    MI_CpuFill8(sprites, 0, 0x90);
}

void IRC_COMPATIBLE_MENU_DrawSpriteSystem(void) { CLACT_DrawSystem(); }

void IRC_COMPATIBLE_MENU_VBlankSpriteSystem(void *sprites) { CLACT_VBlankSystem(); }

void *IRC_COMPATIBLE_MENU_SpriteSetGetActor(IrcMenuSprites *sprites, int index)
{
    return sprites->actors[index];
}

void *IRC_COMPATIBLE_MENU_SpriteSetGetUnit(IrcMenuSprites *sprites) { return sprites->res.unit; }

void IRC_COMPATIBLE_MENU_InitText(IrcTextSystem *text, u16 heapId)
{
    MI_CpuFill8(text, 0, 0x10);
    GF_FONT_InitTextColor();
    text->font = GF_FONT_Create(0x17, 0, 0, 0, heapId);
    text->printQueue = PRINTSYS_QUE_Create(heapId);
    text->msgData = MSGDATA_CreateFromArchive(0, 2, 0x31, heapId);
    text->wordSet = WORDSET_CreateDefault(heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 4, 0, 0x20, heapId);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17, 5, 0, 0, 0x20, heapId);
}

void IRC_COMPATIBLE_MENU_ExitText(IrcTextSystem *text)
{
    WORDSET_DeleteStrbufED04(text->wordSet);
    MSGDATA_Delete(text->msgData);
    PRINTSYS_QUE_Delete(text->printQueue);
    GF_FONT_Delete(text->font);
    MI_CpuFill8(text, 0, 16);
}

void IRC_COMPATIBLE_MENU_UpdateTextQueue(IrcTextSystem *text) { PRINTSYS_QUE_Main(text->printQueue); }

/*
 * three getters at +0, +8, +4.
 */
void *IRC_COMPATIBLE_MENU_TextGetFont(IrcTextSystem *text)
{
    return text->font;
}

void *IRC_COMPATIBLE_MENU_TextGetPrintQueue(IrcTextSystem *text)
{
    return text->printQueue;
}

void *IRC_COMPATIBLE_MENU_TextGetMsgData(IrcTextSystem *text)
{
    return text->msgData;
}

/*
 * lever: sibling of IRC_COMPATIBLE_MENU_InitWindow (same window builder, slot 1, chr 0xF); narrow u8 y parameter places its reload immediately before the call.
 */
void IRC_COMPATIBLE_MENU_InitTitleWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 heapId)
{
    void *bmpWin;
    MI_CpuFill8(win, 0, 20);
    win->fillColor = 0xF;
    win->bmpWin = BMP_WIN_Create(bgLayer, x, y, width, height, palette, 1);
    win->strBuf = STRBUF_Create(255, heapId);
    win->printWin = win->bmpWin;
    win->printPending = 0;
    BMP_Clear(BMP_WIN_GetBmp(win->bmpWin), win->fillColor);
    bmpWin = win->bmpWin;
    BMP_WIN_TransferChars(bmpWin);
    BMP_WIN_MakeScreen(bmpWin);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(bmpWin));
}

void IRC_COMPATIBLE_MENU_InitWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 fillColor, u8 charBase, u16 heapId)
{
    void *bmpWin;
    MI_CpuFill8(win, 0, 20);
    win->fillColor = fillColor;
    win->bmpWin = BMP_WIN_Create(bgLayer, x, y, width, height, palette, charBase);
    win->strBuf = STRBUF_Create(255, heapId);
    win->printWin = win->bmpWin;
    win->printPending = 0;
    BMP_Clear(BMP_WIN_GetBmp(win->bmpWin), win->fillColor);
    bmpWin = win->bmpWin;
    BMP_WIN_TransferChars(bmpWin);
    BMP_WIN_MakeScreen(bmpWin);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(bmpWin));
}

void IRC_COMPATIBLE_MENU_ExitWindow(IrcWindow *win)
{
    STRBUF_Delete(win->strBuf);
    BMP_WIN_Delete(win->bmpWin);
    MI_CpuFill8(win, 0, 20);
}

int IRC_COMPATIBLE_MENU_UpdateWindow(IrcWindow *win, IrcTextSystem *text)
{
    void *printQueue = text->printQueue;
    if (win->printPending) {
        if (!PRINTSYS_QUE_IsExistTarget(printQueue, BMP_WIN_GetBmp(win->printWin))) {
            BMP_WIN_TransferChars(win->printWin);
            win->printPending = 0;
        }
    }
    if (!win->printPending) return 1;
    return 0;
}

void IRC_COMPATIBLE_MENU_PrintMessage(IrcWindow *win, IrcTextSystem *text, int msgId, int x, s16 y)
{
    void *msgData, *printQueue, *font;
    msgData = IRC_COMPATIBLE_MENU_TextGetMsgData(text);
    printQueue = IRC_COMPATIBLE_MENU_TextGetPrintQueue(text);
    font = IRC_COMPATIBLE_MENU_TextGetFont(text);
    BMP_Clear(BMP_WIN_GetBmp(win->bmpWin), win->fillColor);
    MSGDATA_ReadString(msgData, msgId, win->strBuf);
    PRINTSYS_PrintQue(printQueue, BMP_WIN_GetBmp(win->printWin), (s16)x, (s16)y, win->strBuf, font);
    win->printPending = 1;
}

void IRC_COMPATIBLE_MENU_PrintMessageCentered(IrcWindow *win, IrcTextSystem *text, int msgId)
{
    void *msgData, *printQueue, *font;
    u16 x, y;
    msgData = IRC_COMPATIBLE_MENU_TextGetMsgData(text);
    printQueue = IRC_COMPATIBLE_MENU_TextGetPrintQueue(text);
    font = IRC_COMPATIBLE_MENU_TextGetFont(text);
    BMP_Clear(BMP_WIN_GetBmp(win->bmpWin), win->fillColor);
    MSGDATA_ReadString(msgData, msgId, win->strBuf);
    x = BMP_WIN_GetWidth(win->bmpWin) * 4;
    y = BMP_WIN_GetHeight(win->bmpWin) * 4;
    x -= (u16)(GF_FONT_MeasureWidestLine(win->strBuf, font, 0) >> 1);
    y -= (u16)(GF_FONT_CountLines(win->strBuf, font) >> 1);
    PRINTSYS_QUE_Clear(printQueue);
    PRINTSYS_PrintQueColor(printQueue, BMP_WIN_GetBmp(win->printWin), (s16)x, (s16)y, win->strBuf, font, 0x3dc1);
    win->printPending = 1;
}

void IRC_COMPATIBLE_MENU_SetHandler(IrcMenuWork *work, IrcMenuHandler handler)
{
    work->handler = handler;
    work->handlerState = 0;
}

void IRC_COMPATIBLE_MENU_SetFinished(IrcMenuWork *work) { work->finished = 1; }

void IRC_COMPATIBLE_MENU_HandleStartTests(IrcMenuWork *work, u16 *state)
{
    void *saveData;
    if (*state < 14 && IRC_APPBAR_GetResult(work->appBar) == 1) {
        COMPATIBLE_IRC_SYS_ResetStep(work->args->view);
        IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleOpen);
        IRC_APPBAR_Reset(work->appBar);
        IRC_APPBAR_SetLabel(work->appBar, 0);
        BG_SYS_PushTile(0);
        IRC_COMPATIBLE_MENU_PrintMessage(&work->title, &work->text, 5, 0, 0);
        IRC_COMPATIBLE_MENU_ResetButtonPalettes(&work->buttons);
        return;
    }
    switch (*state) {
    case 0: COMPATIBLE_IRC_SYS_ResetStep(work->args->view); *state = 1; break;
    case 1:
        if (COMPATIBLE_IRC_SYS_StepStartSession(work->args->view)) { GFL_USE_PlaySeDefaultVolume(1620); IRC_APPBAR_SetActive(work->appBar, 1); *state = 2; }
        break;
    case 2: if (COMPATIBLE_IRC_SYS_StepConnectChild(work->args->view)) *state = 3; break;
    case 3: IRC_COMPATIBLE_MENU_PrintMessage(&work->title, &work->text, 4, 0, 0); *state = 4; break;
    case 4: if (COMPATIBLE_IRC_SYS_StepSyncTiming(work->args->view)) *state = 5; break;
    case 5:
        if (COMPATIBLE_IRC_SYS_StepSendProfile(work->args->view, work->args->gameSystem)) {
            COMPATIBLE_IRC_SYS_GetPartnerProfile(work->args->view, work->args->profile);
            if (work->args->gameSystem) {
                saveData = MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(work->args->gameSystem)));
                MISC_SAVEDATA_InsertRecentValue(saveData, MYSTATUS_GetId(work->args->profile->myStatus));
            }
            *state = 6;
        }
        break;
    case 6: if (COMPATIBLE_IRC_SYS_StepShareValue(work->args->view, 0)) *state = 8; break;
    case 8:
        work->flag = 1;
        if (COMPATIBLE_IRC_SYS_SendProfileRequest(work->args->view, work->elapsed, work->choice)) *state = 9;
        break;
    case 9: if (COMPATIBLE_IRC_SYS_PollProfileRequest(work->args->view)) *state = 10; break;
    case 10: if (COMPATIBLE_IRC_SYS_SendProfileAck(work->args->view)) *state = 11; break;
    case 11: if (COMPATIBLE_IRC_SYS_PollProfileAck(work->args->view)) *state = 12; break;
    case 12: COMPATIBLE_IRC_SYS_SetOwnValue(work->args->view, 1); if (COMPATIBLE_IRC_SYS_SendOwnValue(work->args->view)) *state = 13; break;
    case 13: if (COMPATIBLE_IRC_SYS_StepShareValue(work->args->view, 1)) { IRC_APPBAR_SetActive(work->appBar, 0); *state = 14; } break;
    case 14:
        if (work->ticks >= 60) { GFL_USE_PlaySeDefaultVolume(1611); IRC_COMPATIBLE_MENU_PrintMessage(&work->title, &work->text, 2, 0, 0); *state = 15; }
        break;
    case 15:
        if (work->counter++ >= 30) { work->args->choice = 0; IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleFinish); }
        return;
    }
    if (*state >= 3 && *state <= 14 && work->ticks <= 60) work->ticks++;
    if (*state < 12 && COMPATIBLE_IRC_SYS_GetValueDifference(work->args->view)) IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleCheckLink);
}

void IRC_COMPATIBLE_MENU_HandleChoice(IrcMenuWork *work, u16 *state)
{
    switch (*state) {
    case 0:
        work->choice = 2;
        work->flag = 0;
        work->startTime = _u32_div_f((u32)OS_GetTick() << 6, 33514);
        *state = 1;
        break;
    case 1:
        IRC_COMPATIBLE_MENU_UpdateButtons(&work->buttons);
        if (IRC_COMPATIBLE_MENU_IsButtonPressed(&work->buttons)) IRC_APPBAR_SetActive(work->appBar, 0);
        if (IRC_COMPATIBLE_MENU_PollChoice(&work->buttons, (int *)&work->choice)) {
            switch (work->choice) {
            case 0: *state = 2; break;
            case 1:
                work->args->choice = 1;
                IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleFinish);
                break;
            }
        }
        work->elapsed = _u32_div_f((u32)OS_GetTick() << 6, 33514) - work->startTime;
        if (IRC_APPBAR_IsPressed(work->appBar)) IRC_COMPATIBLE_MENU_SetButtonsEnabled(&work->buttons, 0);
        if (IRC_APPBAR_GetResult(work->appBar) == 1) {
            COMPATIBLE_IRC_SYS_ResetStep(work->args->view);
            IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleQuit);
        }
        break;
    case 2:
        IRC_COMPATIBLE_MENU_PrintMessage(&work->title, &work->text, 3, 0, 0);
        IRC_APPBAR_SetLabel(work->appBar, 1);
        IRC_APPBAR_SetActive(work->appBar, 0);
        IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleStartTests);
        break;
    }
}

void IRC_COMPATIBLE_MENU_HandleFinish(IrcMenuWork *work, u16 *state)
{
    switch (*state) {
    case 0:
        if (work->args->choice == 1) {
            if ((work->ticks)++ > 10) {
                work->ticks = 0;
                *state = 1;
            }
        } else {
            *state = 1;
        }
        break;
    case 1:
        IRC_COMPATIBLE_MENU_SetFinished(work);
        break;
    }
}

void IRC_COMPATIBLE_MENU_HandleOpen(IrcMenuWork *work, u16 *state)
{
    switch (*state) {
    case 0:
        IRC_COMPATIBLE_MENU_PrintMessage(&work->title, &work->text, 5, 0, 0);
        COMPATIBLE_IRC_SYS_ClearValues(work->args->view);
        COMPATIBLE_IRC_SYS_ResetStep(work->args->view);
        *state = 1;
        break;
    case 1:
        if (COMPATIBLE_IRC_SYS_StepShutdown(work->args->view))
            *state = 2;
        break;
    case 2:
        IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleChoice);
        break;
    }
}

void IRC_COMPATIBLE_MENU_HandleQuit(IrcMenuWork *work, u16 *state)
{
    switch (*state) {
    case 0:
        *state = 1;
        COMPATIBLE_IRC_SYS_ClearValues(work->args->view);
        COMPATIBLE_IRC_SYS_ResetStep(work->args->view);
        break;
    case 1:
        if (COMPATIBLE_IRC_SYS_StepShutdown(work->args->view))
            *state = 2;
        break;
    case 2:
        work->args->choice = 2;
        IRC_COMPATIBLE_MENU_SetFinished(work);
        break;
    }
}

void IRC_COMPATIBLE_MENU_HandleCheckLink(IrcMenuWork *work, u16 *state)
{
    COMPATIBLE_IRC_SYS_GetValueDifference(work->args->view);
    if (COMPATIBLE_IRC_SYS_IsPartnerReady(work->args->view)) {
        COMPATIBLE_IRC_SYS_SetOwnValue(work->args->view, 1);
        work->args->choice = 0;
        IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleFinish);
    } else {
        IRC_COMPATIBLE_MENU_SetHandler(work, IRC_COMPATIBLE_MENU_HandleChoice);
    }
}

void IRC_COMPATIBLE_MENU_UpdateScene(IrcMenuWork *work)
{
    IRC_COMPATIBLE_MENU_UpdateTextQueue(&work->text);
    IRC_COMPATIBLE_MENU_UpdateWindow(&work->title, &work->text);
    IRC_COMPATIBLE_MENU_UpdateWindow(&work->bottomWin, &work->text);
    IRC_APPBAR_Update(work->appBar);
    IRC_COMPATIBLE_MENU_DrawSprites(work);
}

/*
 * note: Separate fifth object pointer and sixth u16 heap reproduce the incoming pointer home store and halfword slot at +4; byte-correct caller 021B7560 supplies the same two slots. Struct-typed state and const Row input preserve loads across bounds stores.
 */
void IRC_COMPATIBLE_MENU_InitButtons(IrcButtons *buttons, int bgLayer, const IrcButtonRow *rows, int count, IrcTextSystem *text, u16 heapId)
{
    int i;
    const IrcButtonRow *row;
    void *bmpWin;
    u32 width, height;
    void *label, *bmp;
    MI_CpuFill8(buttons, 0, 60);
    buttons->count = count;
    buttons->rows = rows;
    buttons->bgLayer = bgLayer;
    buttons->enabled = 1;
    for (i = 0; i < buttons->count; i++) {
        row = rows + i;
        buttons->bounds[i * 4] = row->y * 8 + 1;
        buttons->bounds[i * 4 + 1] = (row->y + row->height) * 8 - 1;
        buttons->bounds[i * 4 + 2] = row->x * 8 + 1;
        buttons->bounds[i * 4 + 3] = (row->x + row->width) * 8 - 1;
    }
    buttons->bounds[i * 4] = 255;
    buttons->buttonMan = BUTTON_MAN_Create(buttons->bounds, IRC_COMPATIBLE_MENU_ButtonCallback, buttons, heapId);
    for (i = 0; i < buttons->count; i++) {
        row = rows + i;
        buttons->windows[i] = BMP_WIN_Create(bgLayer, (u8)(row->x + 4), (u8)(row->y + 1), (u8)(row->width - 8), row->height - 2, row->palette, 1);
        BMP_Clear(BMP_WIN_GetBmp(buttons->windows[i]), 4);
        bmpWin = buttons->windows[i];
        BMP_WIN_TransferChars(bmpWin);
        BMP_WIN_MakeScreen(bmpWin);
        BG_SYS_PushTile(BMP_WIN_GetBgLayer(bmpWin));
        label = MSGDATA_AllocString(IRC_COMPATIBLE_MENU_TextGetMsgData(text), rows[i].msgId);
        GF_FONT_SetTextColor(15, 14, 4);
        width = GF_FONT_MeasureWidestLine(label, IRC_COMPATIBLE_MENU_TextGetFont(text), 0);
        height = GF_FONT_CountLines(label, IRC_COMPATIBLE_MENU_TextGetFont(text));
        bmp = BMP_WIN_GetBmp(buttons->windows[i]);
        PRINTSYS_Print(bmp, (row->width - 8) * 4 - (width >> 1), (row->height - 2) * 4 - (height >> 1), label, IRC_COMPATIBLE_MENU_TextGetFont(text));
        STRBUF_Delete(label);
        BMP_WIN_TransferChars(buttons->windows[i]);
    }
    GF_FONT_SetDefaultTextColor();
}

void IRC_COMPATIBLE_MENU_ExitButtons(IrcButtons *buttons)
{
    int i;
    for (i = 0; i < buttons->count; i++) BMP_WIN_Delete(buttons->windows[i]);
    BUTTON_MAN_Delete(buttons->buttonMan);
    MI_CpuFill8(buttons, 0, 60);
}

#pragma opt_propagation off
void IRC_COMPATIBLE_MENU_UpdateButtons(IrcButtons *buttons)
{
    switch (buttons->phase) {
    case 0:
        buttons->done = 0;
        if (BUTTON_MAN_UpdateSlots(buttons->buttonMan) && buttons->enabled) {
            GFL_USE_PlaySeDefaultVolume(1352);
            buttons->timer = 0;
            buttons->phase = 1;
        }
        break;
    case 1: {
        u8 blinkPalette;
        u8 bgLayer;
        u8 x, y, width, height;
        u8 blink;
        const IrcButtonRow *row;
        u16 i;
        int offset;
        const IrcButtonRow *rows;
        u8 pressedPalette;
        blink = (u8)((buttons->timer / 4) % 2);
        bgLayer = BMP_WIN_GetBgLayer(buttons->windows[buttons->selected]);
        i = buttons->selected;
        offset = i * 12;
        rows = buttons->rows;
        row = (const IrcButtonRow *)((u8 *)rows + offset);
        x = row->x; y = row->y; width = row->width; height = row->height;
        switch (i) {
        case 0: pressedPalette = 12; blinkPalette = 11; break;
        case 1: pressedPalette = 9; blinkPalette = 4; break;
        }
        if (blink == 0) {
            BG_SYS_FillTileMap(bgLayer, x, y, width, height, blinkPalette);
            BG_SYS_PushTile(bgLayer);
        } else {
            BG_SYS_FillTileMap(bgLayer, x, y, width, height, pressedPalette);
            BG_SYS_PushTile(bgLayer);
        }
        (buttons->timer)++;
        if (buttons->timer >= 16) {
            buttons->done = 1;
            buttons->phase = 0;
        }
        break;
    }
    }
}

#pragma opt_propagation reset

void IRC_COMPATIBLE_MENU_SetButtonsEnabled(IrcButtons *buttons, u32 enabled) { buttons->enabled = enabled; }

/*
 * note: 2026-10-05 wave P27: u16 field at +0x34 tested for non-zero. 14 B compiled, 2 B trailing pad. Twin shape in ov068 021BA6B8 area (ldrh #0x34 callers).
 */
int IRC_COMPATIBLE_MENU_IsButtonPressed(IrcButtons *buttons)
{
    return buttons->phase != 0;
}

int IRC_COMPATIBLE_MENU_PollChoice(IrcButtons *buttons, int *out)
{
    if (buttons->done) {
        if (out) *out = buttons->selected;
        return 1;
    }
    return 0;
}

void IRC_COMPATIBLE_MENU_ResetButtonPalettes(IrcButtons *buttons)
{
    int i;
    u8 bgLayer;
    u8 palette;
    u8 x, y, width, height;
    const u16 *row;
    buttons->phase = 0;
    buttons->done = 0;
    for (i = 0; i < buttons->count; i++) {
        bgLayer = BMP_WIN_GetBgLayer(buttons->windows[i]);
        row = (const u16 *)((const u8 *)buttons->rows + i * 12);
        x = row[1];
        y = row[2];
        width = row[3];
        height = row[4];
        switch (i) {
        case 0: palette = 11; break;
        case 1: palette = 4; break;
        }
        BG_SYS_FillTileMap(bgLayer, x, y, width, height, palette);
        BG_SYS_PushTile(bgLayer);
    }
}

/*
 * extent: includes the 8-byte setter follower at 021B8794.
 */
void IRC_COMPATIBLE_MENU_ButtonCallback(u16 value, int flag, IrcButtons *buttons)
{
    if (flag == 0) buttons->selected = value;
}

void IRC_COMPATIBLE_MENU_InitScrollEffect(IrcScrollEffect *effect, u32 unused)
{
    MI_CpuFill8(effect, 0, 28);
    BG_SYS_ResetSlot(4, 3, 88);
    BG_SYS_ResetSlot(7, 3, 88);
}

void IRC_COMPATIBLE_MENU_ExitScrollEffect(IrcScrollEffect *effect) { MI_CpuFill8(effect, 0, 28); }

void IRC_COMPATIBLE_MENU_UpdateScrollEffect(IrcScrollEffect *effect)
{
    if (effect->active) {
        if (IRC_COMPATIBLE_MENU_StepLinear(&effect->step)) effect->active = 0;
        BG_SYS_ResetSlot(4, 3, 88 - effect->step.value);
        BG_SYS_ResetSlot(7, 3, 88 - effect->step.value);
    }
}

void IRC_COMPATIBLE_MENU_StartScrollEffect(IrcScrollEffect *effect)
{
    effect->active = 1;
    IRC_COMPATIBLE_MENU_InitLinearStep(&effect->step, 0, 0x58, 0x78);
}

void IRC_COMPATIBLE_MENU_InitFloater(IrcFloater *floater, void *actor, int isSpecial, int unused)
{
    u16 offset[2];
    MI_CpuFill8(floater, 0, 0x1c);
    floater->actor = actor;
    CLACT_SetActorAnimSeq(floater->actor, isSpecial != 0 ? 0xd : 0xc);
    IRC_COMPATIBLE_MENU_ResetFloaterPath(floater);
    offset[0] = (u16)floater->startX;
    offset[1] = (u16)floater->startY;
    CLACT_AddActorSurfacePos(floater->actor, offset, 1);
    CLACT_SetActorDrawEnable(floater->actor, 1);
    CLACT_SetActorAnimFrame(floater->actor, GFL_USE_GetRandomBelow(0x2000));
}

void IRC_COMPATIBLE_MENU_ExitFloater(IrcFloater *floater) { MI_CpuFill8(floater, 0, 0x1c); }

/*
 * extent: two trailing zero padding bytes at 021B88F6.
 * lever: sign declared before start fixes r6/r7; diff * counter avoids a move.
 */
void IRC_COMPATIBLE_MENU_UpdateFloater(IrcFloater *floater)
{
    u16 position[2];
    int sign;
    int startX, diffX, magnitudeX, startY, diffY, magnitudeY;
    s8 signY;
    startX = floater->startX;
    diffX = floater->endX - startX;
    magnitudeX = diffX < 0 ? -diffX : diffX;
    sign = (s8)(diffX / magnitudeX);
    if (diffX < 0) diffX = -diffX;
    position[0] = startX + sign * (((u32)diffX * floater->step) / floater->duration);
    startY = floater->startY;
    diffY = floater->endY - startY;
    magnitudeY = diffY < 0 ? -diffY : diffY;
    signY = diffY / magnitudeY;
    if (diffY < 0) diffY = -diffY;
    position[1] = startY + signY * (((u32)diffY * floater->step) / floater->duration);
    CLACT_AddActorSurfacePos(floater->actor, position, 1);
    if ((floater->step)++ > floater->duration) IRC_COMPATIBLE_MENU_ResetFloaterPath(floater);
}

void IRC_COMPATIBLE_MENU_ResetFloaterPath(IrcFloater *floater)
{
    floater->startX = GFL_USE_GetRandomBelow(256);
    floater->startY = 208;
    floater->endX = floater->startX + GFL_USE_GetRandomBelow(184) - 92;
    floater->endY = 184 - 200;
    floater->step = 0;
    floater->duration = GFL_USE_GetRandomBelow(360) + 240;
}

/*
 * Clears 0x350 bytes, stores the record count (0x1e or from 0x0200A8AC) at +0x34e,
 * then initialises count records of 0x1c bytes through IRC_COMPATIBLE_MENU_InitFloater.
 * Note 2026-10-05: IRC_COMPATIBLE_MENU_InitFloater is matched with three parameters, but this caller
 * loads d into r3 before the call, so the original call site passes four. The older
 * draft that declared three arguments dropped that load (DIFF 109/128).
 */
void IRC_COMPATIBLE_MENU_InitFloaters(IrcFloaters *floaters, IrcMenuWork *work, void *records, int unused)
{
    int i;
    MI_CpuFill8(floaters, 0, 0x350);
    if (records == 0)
        floaters->totalCount = 0x1e;
    else
        floaters->totalCount = IRC_RANKING_GetEntryCount(records);
    for (i = 0; i < floaters->totalCount; i++) {
        void *actor = IRC_COMPATIBLE_MENU_GetSprite(work, i);
        u32 isSpecial;
        if (records == 0)
            isSpecial = GFL_USE_GetRandomBelow(2);
        else
            isSpecial = (IRC_RANKING_GetEntryGender(records, i) == 1);
        IRC_COMPATIBLE_MENU_InitFloater(&floaters->floater[i], actor, isSpecial, unused);
    }
}

void IRC_COMPATIBLE_MENU_ExitFloaters(IrcFloaters *floaters)
{
    int i;
    for (i = 0; i < floaters->totalCount; i++) IRC_COMPATIBLE_MENU_ExitFloater(&floaters->floater[i]);
    MI_CpuFill8(floaters, 0, 848);
}

/*
 * extent: two trailing zero padding bytes at 021B8A3E.
 */
void IRC_COMPATIBLE_MENU_UpdateFloaters(IrcFloaters *floaters)
{
    int i;
    for (i = 0; i < floaters->activeCount; i++)
        IRC_COMPATIBLE_MENU_UpdateFloater(&floaters->floater[i]);
    if ((floaters->tick)++ > 30) {
        floaters->tick = 0;
        if (floaters->activeCount < floaters->totalCount)
            (floaters->activeCount)++;
    }
}

/*
 * extent: two trailing zero padding bytes at 021B8A8E.
 */
void IRC_COMPATIBLE_MENU_InitLinearStep(IrcLinearStep *step, int start, int target, int duration)
{
    int delta;
    float scaled;
    step->value = start;
    step->start = start;
    step->target = target;
    step->duration = duration;
    if (duration) {
        delta = target - start;
        if (delta > 0)
            scaled = 0.5f + (float)(delta << 12);
        else
            scaled = (float)(delta << 12) - 0.5f;
        step->step = (int)scaled / duration;
        step->counter = 0;
    } else {
        step->counter = duration - 2;
    }
}

/*
 * Step the counter up to the duration, recomputing the value from the start,
 * the step and the counter; when it has caught up, set the value to the target.
 * Returns 1 when the target is reached.
 */
int IRC_COMPATIBLE_MENU_StepLinear(IrcLinearStep *step)
{
    if (step->counter < step->duration - 1) {
        step->counter = step->counter + 1;
        step->value = step->start + ((step->step * step->counter) >> 12);
        return 0;
    }
    step->value = step->target;
    return 1;
}
