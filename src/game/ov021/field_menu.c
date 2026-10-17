/*
 * file:     field_menu.c
 * unit:     yes
 * function: FIELD_MENU_Create, FIELD_MENU_NotifyParentOnExit, FIELD_MENU_Delete, FIELD_MENU_ShowBgLayers, FIELD_MENU_Update, FIELD_MENU_UpdateActorsForScroll, FIELD_MENU_ApplyBgScroll, FIELD_MENU_LoadGraphics, FIELD_MENU_LoadFrameBg, FIELD_MENU_GetLayoutType, FIELD_MENU_CountLayoutButtons, FIELD_MENU_CreateItems, FIELD_MENU_ColorTask, FIELD_MENU_SetScrolledOut, FIELD_MENU_GetSelectedButtonId, FIELD_MENU_SelectButton, FIELD_MENU_GetSlotIndex, FIELD_MENU_MoveCursor, FIELD_MENU_HandleKeys, FIELD_MENU_HandleTouch, FIELD_MENU_PlaceCursor, FIELD_MENU_StartLeave, FIELD_MENU_UpdateSelection, FIELD_MENU_CreateItem, FIELD_MENU_DeleteItem, FIELD_MENU_ShowItemWindow, FIELD_MENU_LoadScreen
 * address:  0x021A836C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Holds the former field_menu_p01.c (0x021A87A8..0x021A92A4, the tail of field_menu.c).
 * The file ends at 0x021A92A4; field_encount.c starts at 0x021A9350.
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   gFieldMenuFileName     0x021DDF94  data  ov021  a1
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   ICA_ANIME_GetField114  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   UI_GetInputMode  0x020355C4  arm
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   FIELD_MENU_ColorTask  0x021A8D40  thumb  ov021
 *   PRINTSYS_QUE_Create  0x0201C440  thumb
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   FIELD_MENU_GetLayoutType  0x021A8B18  thumb  ov021
 *   FIELD_MENU_LoadGraphics  0x021A8874  thumb  ov021
 *   FIELD_MENU_CreateItems  0x021A8BB8  thumb  ov021
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   BG_SYS_SetPlaneVisible  0x02040588  arm
 *   FIELD_MENU_UpdateSelection  0x021A90E0  thumb  ov021
 *   FIELD_MENU_SetScrolledOut  0x021A8DD8  thumb  ov021
 *   GAME_DATA_GetFrameRate  0x020129C4  thumb
 *   FIELD_MENU_SelectButton  0x021A8E20  thumb  ov021
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   FIELD_SUBSCREEN_ResumeField  0x021A0FB4  thumb
 *   FIELD_MENU_DeleteItem  0x021A926C  thumb  ov021
 *   TCB_DeleteTask  0x02030EAC  arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_DeleteRenderer  0x0204B084  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   BG_SYS_FillScrollArea  0x02040618  arm
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   BG_SYS_PushTile  0x020409B4  arm
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 *   FIELD_SUBSCREEN_LoadBackdrop  0x021A12D4  thumb  ov021
 *   FIELD_MENU_ShowItemWindow  0x021A9294  thumb  ov021
 *   FIELD_MENU_UpdateActorsForScroll  0x021A87A8  thumb  ov021
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   FIELD_MENU_HandleKeys  0x021A8EEC  thumb  ov021
 *   FIELD_MENU_HandleTouch  0x021A8FFC  thumb  ov021
 *   CLACT_IsActorAnimActive  0x0204B98C  arm
 *   FIELD_MENU_PlaceCursor  0x021A9080  thumb  ov021
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   FIELD_SUBSCREEN_SetPanelResult  0x021A0FA0  thumb  ov021
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   CLACT_SetSurfacePos  0x0204B09C  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   BG_SYS_ResetSlot  0x02041EE4  arm
 *   GXx_SetMasterBrightness_  0x0207D534  arm
 *   gFieldMenuBgTemplate5     0x021D8BBC  data  a4
 *   gFieldMenuBgTemplate6     0x021D8B5C  data  a4
 *   gFieldMenuBgTemplate7     0x021D8B7C  data  a4
 *   gFieldMenuScreenIds     0x021D8B44  data  a4
 *   gFieldMenuSurfaceRect     0x021D8C1C  data  a4
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole  0x02049B68  arm
 *   ARC_UTIL_UploadBgCharFromHandle  0x02049658  arm
 *   ARC_UTIL_UploadBgPaletteFromHandle  0x020498F4  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetMoveKindPaletteFileId  0x02027614  thumb
 *   APP_ICON_GetMoveKindAnimFileId  0x02027618  thumb
 *   APP_ICON_GetStatusCellFileId  0x0202761C  thumb
 *   APP_ICON_GetStatusPaletteFileId  0x02027620  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   CLACT_CreateRenderer  0x0204B034  arm
 *   CLACT_SetUnitRenderer  0x0204B258  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnimSpeed  0x0204B954  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorBgPriority  0x0204B84C  arm
 *   ZONEDATA_IsZone1A6  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   ZONEDATA_IsZone34  0x02013D20  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   gFieldMenuLayouts  0x021D8D24  data  a4
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   gFieldMenuDefaultName     0x021D8C0C  data  ov021  a2
 *   STRBUF_Create  0x020457B0  arm
 *   MYSTATUS_IsNameEmpty  0x020084BC  thumb
 *   MYSTATUS_GetName  0x020084F4  thumb
 *   STRBUF_SetString  0x02045924  arm
 *   gFieldMenuMsgIds     0x021D8B34  data  a2
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   gFieldMenuIconRes     0x021D8CAC  data  ov021  a4
 *   MYSTATUS_GetOutfitVariant  0x02008550  thumb
 *   gFieldMenuWindowPos     0x021D8B18  data  ov021  a1
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   GF_STANDARD_Get_F684  0x0203F684  arm
 *   GXS_LoadOBJPltt  0x0207E5D0  arm
 *   gFieldMenuCursorMoves     0x021D8C4C  data  ov021  a1
 *   gFieldMenuSlotCol     0x021D8B26  data  ov021  a1
 *   gFieldMenuSlotRow     0x021D8B27  data  ov021  a1
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetRepeat  0x0203633C  arm
 *   func_020355D8  0x020355D8  arm
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   gFieldMenuTouchTable     0x021D8C2C  data  ov021  a1
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   CLACT_CreateAffineActor  0x0204B324  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   APP_ICON_GetStatusAnimFileId  0x02027624  thumb
 *   APP_ICON_GetStatusFrameFileId  0x02027628  thumb
 *   APP_ICON_GetStatusDataFileId  0x0202762C  thumb
 *   ARC_UTIL_LoadPaletteDataFromHandle  0x02049EF4  arm
 *   BG_SYS_DrawTileEx  0x020410D0  arm
 *   BG_SYS_SetFlagField06  0x02041B6C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

extern void GFL_USE_PlaySeDefaultVolume(u32 seId);

/* ------------------------------------------------------------------------ */
/* Field menu (field_menu.c, 0x021A836C..0x021A92A4)                        */
/* ------------------------------------------------------------------------ */

#define FIELD_MENU_ITEM_MAX 7

/* Slot of the back button; it is the last of the seven slots and has no icon. */
#define FIELD_MENU_ITEM_BACK 6

/* FieldMenuItem.buttonId values with a known meaning. */
#define FIELD_MENU_BUTTON_PLAYER 4 /* the trainer name button */
#define FIELD_MENU_BUTTON_EMPTY 7  /* slot without a button */

/* One icon slot: text window, icon resources and the actor that shows it. */
typedef struct FieldMenuItem {
    int inUse;
    void *bmpWin;
    int buttonId;
    void *charRes;
    void *cellRes;
    u8 cursorX;
    u8 cursorY;
    u8 reserved16[2];
    void *actor;
} FieldMenuItem;

/* Work of the sub screen menu (0x138 bytes). */
typedef struct FieldMenu {
    u16 heapId;
    u16 subHeapId;
    void *fieldMap;
    void *parent;
    int state;
    u32 mapInfo;
    void *eventWork;
    void *myStatus;
    u16 zoneId;
    u8 cursorCol;
    u8 cursorRow;
    u8 pressFrames;
    u8 layoutType;
    u8 reserved22[0x24 - 0x22];
    int cursorDirty;
    int exitRequested;
    int keyCursorActive;
    int chosenButton;
    FieldMenuItem items[FIELD_MENU_ITEM_MAX];
    FieldMenuItem *selectedItem;
    s16 scrollY;
    u8 reservedFE[0x100 - 0xFE];
    int scrollDirty;
    void *palRes;
    void *charRes;
    void *cellRes;
    void *palResB;
    void *charResB;
    void *cellResB;
    void *clactUnit;
    void *clactSurface;
    void *cursorActor;
    void *backActor;
    void *printQue;
    void *colorTask;
    u32 colorPhase;
} FieldMenu;

/* Values of FieldMenu.state */
#define FIELD_MENU_STATE_SLIDE_IN 0
#define FIELD_MENU_STATE_WAIT_PRINT 1
#define FIELD_MENU_STATE_WAIT_WIPE 2
#define FIELD_MENU_STATE_IDLE 3
#define FIELD_MENU_STATE_BACK_ANIM 4
#define FIELD_MENU_STATE_DECIDE 5
#define FIELD_MENU_STATE_PRESS_ANIM 6
#define FIELD_MENU_STATE_NOTIFY_CLOSE 7
#define FIELD_MENU_STATE_NOTIFY_SELECT 8
#define FIELD_MENU_STATE_SLIDE_OUT 9
#define FIELD_MENU_STATE_DONE 10

/* Mode numbers the menu hands to its parent when it ends. */
#define FIELD_MENU_NEXT_SELECT 3
#define FIELD_MENU_NEXT_CLOSE 4

#define FIELD_MENU_SCROLL_STEP 0x40
#define FIELD_MENU_SCROLL_HIDDEN 0xC0

/* Layer 6 sits 5 pixels higher than layer 5 (the icon layer). */
#define FIELD_MENU_LAYER6_OFFSET 5

/* Actors whose screen Y is at or past these limits are hidden while scrolling. */
#define FIELD_MENU_ICON_CULL_Y 0xD0
#define FIELD_MENU_CURSOR_CULL_Y 0xD6

#define SE_FIELD_MENU_SLIDE_IN 0x554
#define SE_FIELD_MENU_CLOSE 0x556
#define SE_FIELD_MENU_PRESS 0x54C
#define SE_FIELD_MENU_MOVE 0x548

/* Bits of the pad words returned by KEY_GetTrg (pressed) and KEY_GetRepeat (repeat). */
#define FIELD_MENU_PAD_A 0x0001
#define FIELD_MENU_PAD_B 0x0002
#define FIELD_MENU_PAD_RIGHT 0x0010
#define FIELD_MENU_PAD_LEFT 0x0020
#define FIELD_MENU_PAD_UP 0x0040
#define FIELD_MENU_PAD_DOWN 0x0080
#define FIELD_MENU_PAD_X 0x0400

/* Position on the sub screen, in pixels. */
typedef struct FieldMenuScreenPos {
    s16 x;
    s16 y;
} FieldMenuScreenPos;

/* Position and display flags for an actor added by CLACT_CreateActor. */
typedef struct FieldMenuActorPos {
    s16 x;
    s16 y;
    s16 z;
    u8 flip;
    u8 palOffset;
} FieldMenuActorPos;

/* Setup record for an actor added by CLACT_CreateAffineActor. */
typedef struct FieldMenuActorSetup {
    u16 x;
    u16 y;
    u16 z;
    u8 flip;
    u8 palOffset;
    u16 bgPriority;
    u16 reserved0A;
    u32 scaleX;
    u32 scaleY;
    u16 rotation;
    u16 drawArea;
} FieldMenuActorSetup;

/* Rectangle of the actor surface (4 words). */
typedef struct FieldMenuSurfaceRect {
    u32 x;
    u32 y;
    u32 width;
    u32 height;
} FieldMenuSurfaceRect;

/* Ids of the icon resources of one button (gFieldMenuIconRes, per button id). */
typedef struct FieldMenuIconRes {
    int charId;
    int cellId;
    int animId;
} FieldMenuIconRes;

/* Tile position of the text window of one slot (gFieldMenuWindowPos, per slot). */
typedef struct FieldMenuWindowPos {
    u8 tileX;
    u8 tileY;
} FieldMenuWindowPos;

/* Name shown on the player button when the trainer has no name (7 characters). */
typedef struct FieldMenuName {
    u16 chars[7];
} FieldMenuName;

/* Touch rectangles of the seven slots for TOUCHPANEL_HitTrg. */
typedef struct FieldMenuTouchTable {
    u8 rects[32];
} FieldMenuTouchTable;

/* Header and tile map of a loaded screen file. */
typedef struct FieldMenuScreenData {
    u8 header[0xC];
    u16 tiles[0x300];
} FieldMenuScreenData;

/* Everything FIELD_MENU_CreateItem needs to build one slot. */
typedef struct FieldMenuItemInit {
    int buttonId;
    u8 cursorX;
    u8 cursorY;
    u8 winTileX;
    u8 winTileY;
    u8 iconX;
    u8 iconY;
    u8 reserved0A[2];
    void *text;
    void *arcHandle;
    u32 charId;
    u32 cellId;
    u32 animId;
} FieldMenuItemInit;

struct BgTemplate;
struct BigObj;

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern void *FIELDMAP_GetGameSystem(void *fieldMap);
extern void *ICA_ANIME_GetField1C(void *gameSystem);
extern void *ICA_ANIME_GetField114(void *gameSystem);
extern u16 GAME_DATA_GetPlayerZoneId(void *playerWork);
extern void *GAME_DATA_GetEventWork(void *gameData);
extern void *GAME_DATA_GetMyStatus(void *gameData);
extern u32 FIELDMAP_GetMsgBg(void *fieldMap);
extern u8 UI_GetInputMode(void);
extern void *GFL_USE_AddMainTask(void *callback, void *work, int priority);
extern void *PRINTSYS_QUE_Create(u32 heapId);
extern void *ARC_TOOL_CreateHandle(u32 arcId, u32 heapId);
extern void ARC_TOOL_DeleteHandle(void *arcHandle);
extern u32 BG_SYS_SetPlaneVisible(u8 layer, u8 visible);
extern u8 GAME_DATA_GetFrameRate(void *gameData);
extern void CLACT_SetActorDrawEnable(void *actor, u32 drawEnable);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void FIELD_SUBSCREEN_ResumeField(void *parent, u32 heapId);
extern void TCB_DeleteTask(void *tcb);
extern void CLACT_DeleteActor(void *actor);
extern void CLACT_DeleteRenderer(void *surface);
extern u32 CLACT_DeleteUnit(void *unit);
extern void CLACT_ReleaseCellAnim(void *cellRes);
extern void CLACT_ReleaseCharacter(void *charRes);
extern void CLACT_ReleasePalette(void *palRes);
extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);
extern void BG_SYS_FreeLayerBuf(u32 layer);
extern void PRINTSYS_QUE_Clear(void *printQue);
extern void PRINTSYS_QUE_Delete(void *printQue);
extern u32 GFL_HEAP_Free(void *p);
extern void BG_SYS_PushTile(u32 layer);
extern u32 PRINTSYS_QUE_IsFinished(void *printQue);
extern void FIELD_SUBSCREEN_LoadBackdrop(void *parent, u32 heapId);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 CLACT_IsActorAnimActive(void *actor);
extern void CLACT_SetActorAnimSeq(void *actor, u16 animSeq);
extern void FIELD_SUBSCREEN_SetPanelResult(void *parent, int mode);
extern u32 PRINTSYS_QUE_Main(void *printQue);
extern void CLACT_SetSurfacePos(void *surface, int a, FieldMenuScreenPos *offset);
extern void CLACT_GetActorSurfacePos(void *actor, FieldMenuScreenPos *out, u16 space);
extern void BG_SYS_ResetSlot(u32 layer, u32 type, u32 value);
extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *template, u32 type);
extern void BG_SYS_ClearSlot(u32 layer);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *arcHandle, u32 b, u32 c, u32 d, u32 e, u32 heapId);
extern void ARC_UTIL_UploadBgCharFromHandle(void *arcHandle, u32 a, u32 b, u32 c, u32 d, u32 e, u32 heapId);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *arcHandle, u32 b, u32 c, u32 d, u32 e, u32 f, u16 heapId);
extern void *CLACT_RegisterPaletteEx(void *arcHandle, u32 b, u32 c, u32 d, u16 e, u16 f, u16 heapId);
extern void *CLACT_RegisterCharacter(void *arcHandle, u32 b, u32 c, u32 d, u16 heapId);
extern void *CLACT_RegisterCellAnim(void *arcHandle, u32 first, u32 second, u32 heapId);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
extern void *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *CLACT_CreateRenderer(FieldMenuSurfaceRect *rect, u32 a1, u32 heapId);
extern void CLACT_SetUnitRenderer(void *unit, void *surface);
extern void *CLACT_CreateActor(void *unit, void *charRes, void *palRes, void *cellRes, const FieldMenuActorPos *pos, u16 space, u16 heapId);
extern void CLACT_SetActorAutoAnimSpeed(void *actor, u32 scale);
extern void CLACT_SetActorAutoAnim(void *actor, u32 value);
extern void CLACT_SetActorBgPriority(void *actor, int value);
extern u32 ZONEDATA_IsZone1A6(u32 zoneId);
extern u32 ZONEDATA_IsZone96Pair(u16 zoneId);
extern u32 ZONEDATA_IsZone34(u16 zoneId);
extern int GAME_DATA_GetIntrudeCount(void *gameData);
extern u32 ZONEDATA_CheckEventFlag(void *eventWork, s32 flagId);
extern void *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *STRBUF_Create(u32 capacity, u32 heapId);
extern int MYSTATUS_IsNameEmpty(const void *myStatus);
extern const void *MYSTATUS_GetName(const void *myStatus);
extern void STRBUF_SetString(void *strbuf, const void *src);
extern void *MSGDATA_AllocString(void *msgBank, u32 index);
extern u8 MYSTATUS_GetOutfitVariant(const void *myStatus);
extern void STRBUF_Delete(void *strbuf);
extern u32 MSGDATA_Delete(void *msgBank);
extern short GF_STANDARD_Get_F684(unsigned short x);
extern void GXS_LoadOBJPltt(void *src, u32 off, u32 n);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetRepeat(void);
extern void func_020355D8(u8 v);
extern int TOUCHPANEL_HitTrg(const void *touchTable);
extern void CLACT_AddActorSurfacePos(void *actor, const FieldMenuScreenPos *delta, u32 which);
extern u32 FIELD_MSGBG_GetFont(u32 mapInfo);
extern void *BMP_WIN_Create(u32 layer, u32 x, u32 y, u32 tiles, u8 c, u8 d, u8 slot);
extern void BMP_WIN_MakeScreen(void *bmpWin);
extern void *BMP_WIN_GetBmp(void *bmpWin);
extern void BMP_Clear(void *buf, u8 value);
extern void PRINTSYS_PrintQueColor(void *printQue, void *buf, u32 b, u32 c, void *text, u32 e, u16 f);
extern void *CLACT_CreateAffineActor(void *unit, void *charRes, void *palRes, void *cellRes, const FieldMenuActorSetup *setup, u16 space, u16 heapId);
extern unsigned int BMP_WIN_Delete(void *bmpWin);
extern void BMP_WIN_TransferChars(void *bmpWin);
extern u32 APP_ICON_GetStatusAnimFileId(void);
extern u32 APP_ICON_GetStatusFrameFileId(void);
extern u32 APP_ICON_GetStatusDataFileId(void);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *arcHandle, u32 a, u32 b, void **out, u32 heapId);
extern void BG_SYS_DrawTileEx(u32 layer, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void BG_SYS_SetFlagField06(u8 layer);

extern const struct BgTemplate gFieldMenuBgTemplate5;
extern const struct BgTemplate gFieldMenuBgTemplate6;
extern const struct BgTemplate gFieldMenuBgTemplate7;
extern const u32 gFieldMenuScreenIds[];
extern const FieldMenuSurfaceRect gFieldMenuSurfaceRect;
extern const int gFieldMenuLayouts[][FIELD_MENU_ITEM_MAX];
extern const FieldMenuName gFieldMenuDefaultName;
extern const u16 gFieldMenuMsgIds[];
extern const FieldMenuIconRes gFieldMenuIconRes[];
extern const FieldMenuWindowPos gFieldMenuWindowPos[];
extern u8 gFieldMenuCursorMoves[][8][4];
extern u8 gFieldMenuSlotCol[];
extern u8 gFieldMenuSlotRow[];
extern FieldMenuTouchTable gFieldMenuTouchTable;
extern char gFieldMenuFileName[];

FieldMenu *FIELD_MENU_Create(u16 heapId, u16 subHeapId, void *parent, void *fieldMap, int slideIn);
void FIELD_MENU_NotifyParentOnExit(FieldMenu *menu);
void FIELD_MENU_Delete(FieldMenu *menu);
int FIELD_MENU_ShowBgLayers(void);
u32 FIELD_MENU_Update(FieldMenu *menu);
void FIELD_MENU_UpdateActorsForScroll(FieldMenu *menu);
void FIELD_MENU_ApplyBgScroll(FieldMenu *menu);
void FIELD_MENU_LoadGraphics(FieldMenu *menu, void *arcHandle, int layoutType, u32 mapInfo);
void FIELD_MENU_LoadFrameBg(int heapId, int hideFrame);
u32 FIELD_MENU_GetLayoutType(void *gameData, void *eventWork, u32 zoneId);
int FIELD_MENU_CountLayoutButtons(int layoutType);
void FIELD_MENU_CreateItems(FieldMenu *menu, void *arcHandle, int layoutType);
void FIELD_MENU_ColorTask(void *taskHandle, FieldMenu *menu);
void FIELD_MENU_SetScrolledOut(FieldMenu *menu);
int FIELD_MENU_GetSelectedButtonId(FieldMenu *menu);
void FIELD_MENU_SelectButton(FieldMenu *menu, u32 buttonId);
int FIELD_MENU_GetSlotIndex(u32 col, u32 row);
u32 FIELD_MENU_MoveCursor(FieldMenu *menu, u32 dir);
void FIELD_MENU_HandleKeys(FieldMenu *menu);
void FIELD_MENU_HandleTouch(FieldMenu *menu);
void FIELD_MENU_PlaceCursor(FieldMenu *menu, s16 x, s16 y);
void FIELD_MENU_StartLeave(FieldMenu *menu, int back);
void FIELD_MENU_UpdateSelection(FieldMenu *menu);
void FIELD_MENU_CreateItem(FieldMenu *menu, FieldMenuItem *item, const FieldMenuItemInit *init);
void FIELD_MENU_DeleteItem(FieldMenu *menu, FieldMenuItem *item);
void FIELD_MENU_ShowItemWindow(FieldMenu *menu, FieldMenuItem *item);
void FIELD_MENU_LoadScreen(u32 heapId, u32 layer);

/*
 * 0x021DDF94 is the "field_menu.c" file-name string; 0x134 is its line.
 */
FieldMenu *FIELD_MENU_Create(u16 heapId, u16 subHeapId, void *parent, void *fieldMap, int slideIn)
{
    FieldMenu *menu;
    void *gameSystem;
    void *gameData;
    void *arcHandle;
    u32 layoutType;

    menu = GFL_HEAP_Alloc(heapId, 0x138, 0, gFieldMenuFileName, 0x134);
    gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    menu->heapId = heapId;
    menu->subHeapId = subHeapId;
    menu->fieldMap = fieldMap;
    menu->parent = parent;
    menu->state = FIELD_MENU_STATE_WAIT_PRINT;
    menu->zoneId = GAME_DATA_GetPlayerZoneId(ICA_ANIME_GetField114(gameSystem));
    menu->eventWork = GAME_DATA_GetEventWork(gameData);
    menu->myStatus = GAME_DATA_GetMyStatus(gameData);
    menu->mapInfo = FIELDMAP_GetMsgBg(fieldMap);
    menu->cursorCol = 0;
    menu->cursorRow = 0;
    menu->cursorDirty = menu->keyCursorActive = UI_GetInputMode() ^ 1;
    menu->selectedItem = 0;
    menu->colorTask = GFL_USE_AddMainTask(FIELD_MENU_ColorTask, menu, 0);
    menu->printQue = PRINTSYS_QUE_Create(menu->heapId);
    menu->scrollDirty = 0;
    menu->scrollY = 0;
    arcHandle = ARC_TOOL_CreateHandle(0x47, menu->subHeapId);
    layoutType = FIELD_MENU_GetLayoutType(gameData, menu->eventWork, menu->zoneId);
    menu->layoutType = layoutType;
    FIELD_MENU_LoadGraphics(menu, arcHandle, layoutType, menu->mapInfo);
    FIELD_MENU_CreateItems(menu, arcHandle, layoutType);
    ARC_TOOL_DeleteHandle(arcHandle);
    BG_SYS_SetPlaneVisible(1, 1);
    if (slideIn == 1) {
        menu->cursorCol = 0;
        menu->cursorRow = 0;
        menu->cursorDirty = 1;
        FIELD_MENU_UpdateSelection(menu);
        FIELD_MENU_SetScrolledOut(menu);
    } else {
        FIELD_MENU_SelectButton(menu, GAME_DATA_GetFrameRate(gameData));
        menu->cursorDirty = 1;
        if (menu->keyCursorActive != 0) {
            CLACT_SetActorDrawEnable(menu->cursorActor, 1);
        } else {
            CLACT_SetActorDrawEnable(menu->cursorActor, 0);
        }
    }
    GFL_NET_RestartWithDefaultTimeout(0, menu->subHeapId);
    return menu;
}

/* Tells the parent the menu is leaving when the player asked to close it. */
void FIELD_MENU_NotifyParentOnExit(FieldMenu *menu)
{
    if (menu->exitRequested == 1) {
        FIELD_SUBSCREEN_ResumeField(menu->parent, menu->heapId);
    }
}

void FIELD_MENU_Delete(FieldMenu *menu)
{
    u8 i;

    for (i = 0; i < FIELD_MENU_ITEM_MAX; i++) {
        FIELD_MENU_DeleteItem(menu, &menu->items[i]);
    }
    FIELD_MENU_NotifyParentOnExit(menu);
    TCB_DeleteTask(menu->colorTask);
    CLACT_DeleteActor(menu->backActor);
    CLACT_DeleteActor(menu->cursorActor);
    CLACT_DeleteRenderer(menu->clactSurface);
    CLACT_DeleteUnit(menu->clactUnit);
    CLACT_ReleaseCellAnim(menu->cellRes);
    CLACT_ReleaseCharacter(menu->charRes);
    CLACT_ReleasePalette(menu->palRes);
    CLACT_ReleaseCellAnim(menu->cellResB);
    CLACT_ReleaseCharacter(menu->charResB);
    CLACT_ReleasePalette(menu->palResB);
    BG_SYS_FillScrollArea(6, 3, 0);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(6);
    PRINTSYS_QUE_Clear(menu->printQue);
    PRINTSYS_QUE_Delete(menu->printQue);
    GFL_HEAP_Free(menu);
}

/* Shows the menu BG layers again after a slide or a wipe. */
int FIELD_MENU_ShowBgLayers(void)
{
    BG_SYS_PushTile(6);
    BG_SYS_SetPlaneVisible(4, 1);
    BG_SYS_SetPlaneVisible(5, 1);
    BG_SYS_SetPlaneVisible(6, 1);
    return BG_SYS_SetPlaneVisible(7, 1);
}

/* Per-frame update; returns the print queue state for the parent's main. */
u32 FIELD_MENU_Update(FieldMenu *menu)
{
    u8 i;
    s16 scrollY;
    FieldMenuItem *item;

    switch (menu->state) {
    case FIELD_MENU_STATE_WAIT_PRINT:
        if (PRINTSYS_QUE_IsFinished(menu->printQue) == 1) {
            FIELD_SUBSCREEN_LoadBackdrop(menu->parent, menu->subHeapId);
            for (i = 0; i < FIELD_MENU_ITEM_MAX; i++) {
                FIELD_MENU_ShowItemWindow(menu, &menu->items[i]);
            }
            if (menu->scrollY != 0) {
                GFL_USE_PlaySeDefaultVolume(SE_FIELD_MENU_SLIDE_IN);
                menu->state = FIELD_MENU_STATE_SLIDE_IN;
            } else {
                menu->state = FIELD_MENU_STATE_WAIT_WIPE;
                FIELD_MENU_ShowBgLayers();
            }
        }
        break;
    case FIELD_MENU_STATE_SLIDE_IN:
        scrollY = menu->scrollY;
        if (scrollY < FIELD_MENU_SCROLL_STEP) {
            menu->scrollY = 0;
            menu->state = FIELD_MENU_STATE_IDLE;
            FIELD_MENU_ShowBgLayers();
        } else {
            menu->scrollY = scrollY - FIELD_MENU_SCROLL_STEP;
            FIELD_MENU_UpdateActorsForScroll(menu);
        }
        menu->scrollDirty = 1;
        break;
    case FIELD_MENU_STATE_WAIT_WIPE:
        if (WIPE_SYS_EndCheck() == 1) {
            FIELD_SUBSCREEN_LoadBackdrop(menu->parent, menu->subHeapId);
            menu->state = FIELD_MENU_STATE_IDLE;
        }
        break;
    case FIELD_MENU_STATE_IDLE:
        FIELD_MENU_HandleKeys(menu);
        FIELD_MENU_HandleTouch(menu);
        FIELD_MENU_UpdateSelection(menu);
        break;
    case FIELD_MENU_STATE_BACK_ANIM:
        if (CLACT_IsActorAnimActive(menu->backActor) != 0) {
            break;
        }
        menu->state = FIELD_MENU_STATE_DECIDE;
        BG_SYS_SetPlaneVisible(5, 1);
        BG_SYS_SetPlaneVisible(6, 1);
        BG_SYS_SetPlaneVisible(7, 1);
        BG_SYS_SetPlaneVisible(4, 1);
        break;
    case FIELD_MENU_STATE_DECIDE:
        if (menu->exitRequested == 1 || menu->cursorRow == 3) {
            menu->state = FIELD_MENU_STATE_SLIDE_OUT;
            GFL_USE_PlaySeDefaultVolume(SE_FIELD_MENU_CLOSE);
            BG_SYS_SetPlaneVisible(4, 0);
            BG_SYS_SetPlaneVisible(5, 1);
            BG_SYS_SetPlaneVisible(6, 1);
            BG_SYS_SetPlaneVisible(7, 1);
            CLACT_SetActorDrawEnable(menu->backActor, 0);
        } else {
            item = menu->selectedItem;
            if (item->actor != 0) {
                menu->pressFrames = 0;
                FIELD_MENU_PlaceCursor(menu, item->cursorX, item->cursorY);
                CLACT_SetActorAnimSeq(menu->cursorActor, 1);
                CLACT_SetActorDrawEnable(menu->cursorActor, 1);
                menu->state = FIELD_MENU_STATE_PRESS_ANIM;
                GFL_USE_PlaySeDefaultVolume(SE_FIELD_MENU_PRESS);
            } else {
                menu->state = FIELD_MENU_STATE_NOTIFY_SELECT;
            }
        }
        break;
    case FIELD_MENU_STATE_PRESS_ANIM:
        menu->pressFrames++;
        if (CLACT_IsActorAnimActive(menu->cursorActor) == 0) {
            menu->state = FIELD_MENU_STATE_NOTIFY_SELECT;
        }
        break;
    case FIELD_MENU_STATE_NOTIFY_CLOSE:
        FIELD_SUBSCREEN_SetPanelResult(menu->parent, FIELD_MENU_NEXT_CLOSE);
        menu->state = FIELD_MENU_STATE_DONE;
        break;
    case FIELD_MENU_STATE_NOTIFY_SELECT:
        FIELD_SUBSCREEN_SetPanelResult(menu->parent, FIELD_MENU_NEXT_SELECT);
        menu->state = FIELD_MENU_STATE_DONE;
        break;
    case FIELD_MENU_STATE_SLIDE_OUT:
        if (menu->scrollY + FIELD_MENU_SCROLL_STEP > FIELD_MENU_SCROLL_HIDDEN) {
            menu->scrollY = FIELD_MENU_SCROLL_HIDDEN;
            menu->state = FIELD_MENU_STATE_NOTIFY_CLOSE;
        } else {
            menu->scrollY += FIELD_MENU_SCROLL_STEP;
            FIELD_MENU_UpdateActorsForScroll(menu);
        }
        menu->scrollDirty = 1;
        break;
    }
    return PRINTSYS_QUE_Main(menu->printQue);
}

/*
 * Moves the icon surface to the current scroll and hides the icons and the
 * cursor that have slid below the visible part of the screen.
 */
void FIELD_MENU_UpdateActorsForScroll(FieldMenu *menu)
{
    FieldMenuScreenPos surfaceOffset;
    FieldMenuScreenPos iconPos;
    FieldMenuScreenPos cursorPos;
    u8 i;

    surfaceOffset.x = 0;
    surfaceOffset.y = -menu->scrollY;
    CLACT_SetSurfacePos(menu->clactSurface, 0, &surfaceOffset);
    for (i = 0; i < FIELD_MENU_ITEM_MAX; i++) {
        if (menu->items[i].actor != 0 && menu->items[i].buttonId != FIELD_MENU_BUTTON_EMPTY) {
            CLACT_GetActorSurfacePos(menu->items[i].actor, &iconPos, 0);
            if (iconPos.y < FIELD_MENU_ICON_CULL_Y) {
                CLACT_SetActorDrawEnable(menu->items[i].actor, 1);
            } else {
                CLACT_SetActorDrawEnable(menu->items[i].actor, 0);
            }
        }
    }
    CLACT_GetActorSurfacePos(menu->cursorActor, &cursorPos, 0);
    if (menu->keyCursorActive != 0 && cursorPos.y < FIELD_MENU_CURSOR_CULL_Y) {
        CLACT_SetActorDrawEnable(menu->cursorActor, 1);
    } else {
        CLACT_SetActorDrawEnable(menu->cursorActor, 0);
    }
}

/* Applies the scroll to the BG layers 5 and 6 when it changed. */
void FIELD_MENU_ApplyBgScroll(FieldMenu *menu)
{
    if (menu->scrollDirty == 1) {
        BG_SYS_ResetSlot(5, 3, -menu->scrollY);
        BG_SYS_ResetSlot(6, 3, -FIELD_MENU_LAYER6_OFFSET - menu->scrollY);
        menu->scrollDirty = 0;
    }
}

/*
 * Sets up the BG layers 5 to 7, loads the screen, palette, icon and cursor
 * resources and creates the cursor and back button actors.
 */
void FIELD_MENU_LoadGraphics(FieldMenu *menu, void *arcHandle, int layoutType, u32 mapInfo)
{
    void *commonArc;
    u32 cellId;
    FieldMenuActorPos pos;
    FieldMenuSurfaceRect surfaceRect;

    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
    BG_SYS_InitBgLayer(5, &gFieldMenuBgTemplate5, 0);
    BG_SYS_SetPlaneVisible(5, 1);
    BG_SYS_ClearSlot(5);
    BG_SYS_InitBgLayer(6, &gFieldMenuBgTemplate6, 0);
    BG_SYS_SetPlaneVisible(6, 1);
    BG_SYS_ClearSlot(6);
    BG_SYS_InitBgLayer(7, &gFieldMenuBgTemplate7, 0);
    BG_SYS_SetPlaneVisible(7, 1);
    BG_SYS_ClearSlot(7);
    BG_SYS_FillScrollArea(6, 3, -FIELD_MENU_LAYER6_OFFSET);
    ARC_UTIL_UploadPaletteFromHandleWhole(arcHandle, 0, 4, 0, 0, menu->subHeapId);
    ARC_UTIL_UploadBgCharFromHandle(arcHandle, 2, 5, 0, 0, 0, menu->subHeapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arcHandle, gFieldMenuScreenIds[layoutType], 5, 0, 0, 0, menu->subHeapId);
    ARC_UTIL_UploadBgPaletteFromHandle(arcHandle, 0xE, 7, 0, 0, 0, menu->subHeapId);
    menu->palRes = CLACT_RegisterPaletteEx(arcHandle, 1, 1, 0, 0, 0xB, menu->heapId);
    menu->charRes = CLACT_RegisterCharacter(arcHandle, 0xD, 0, 1, menu->heapId);
    menu->cellRes = CLACT_RegisterCellAnim(arcHandle, 0x1C, 0x26, menu->heapId);
    commonArc = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), menu->subHeapId);
    menu->palResB = CLACT_RegisterPaletteEx(commonArc, APP_ICON_GetMoveKindPaletteFileId(), 1, 0x160, 0, 2, menu->heapId);
    menu->charResB = CLACT_RegisterCharacter(commonArc, APP_ICON_GetMoveKindAnimFileId(), 0, 1, menu->heapId);
    cellId = APP_ICON_GetStatusCellFileId(0);
    menu->cellResB = CLACT_RegisterCellAnim(commonArc, cellId, APP_ICON_GetStatusPaletteFileId(0), menu->heapId);
    ARC_TOOL_DeleteHandle(commonArc);
    BG_SYS_PushTile(5);
    menu->clactUnit = CLACT_CreateUnit(8, 0, menu->heapId);
    surfaceRect = gFieldMenuSurfaceRect;
    menu->clactSurface = CLACT_CreateRenderer(&surfaceRect, 1, menu->heapId);
    CLACT_SetUnitRenderer(menu->clactUnit, menu->clactSurface);
    pos.x = 0x40;
    pos.y = 0x2C;
    pos.z = 0;
    pos.flip = 0;
    pos.palOffset = 0;
    menu->cursorActor = CLACT_CreateActor(menu->clactUnit, menu->charRes, menu->palRes, menu->cellRes, &pos, 0, menu->heapId);
    CLACT_SetActorAutoAnimSpeed(menu->cursorActor, 0x1000);
    CLACT_SetActorAutoAnim(menu->cursorActor, 1);
    CLACT_SetActorBgPriority(menu->cursorActor, 2);
    pos.x = 0xE0;
    pos.y = 0xA8;
    menu->backActor = CLACT_CreateActor(menu->clactUnit, menu->charResB, menu->palResB, menu->cellResB, &pos, 0, menu->heapId);
    CLACT_SetActorAutoAnimSpeed(menu->backActor, 0x1000);
    CLACT_SetActorAutoAnim(menu->backActor, 1);
    CLACT_SetActorDrawEnable(menu->backActor, 1);
    CLACT_SetActorAutoAnimSpeed(menu->backActor, 0x2000);
}

/* Loads the frame screen into the given layer; hideFrame turns layer 4 off. */
void FIELD_MENU_LoadFrameBg(int heapId, int hideFrame)
{
    FIELD_MENU_LoadScreen(heapId, 4);
    if (hideFrame != 0) {
        BG_SYS_SetPlaneVisible(4, 0);
    }
}

/*
 * Picks the button layout from the story progress: 1 in the early-game
 * zones, 4 and 5 for the two special states, then 3 and 2 until the two
 * event flags are set; 0 is the full layout.
 */
u32 FIELD_MENU_GetLayoutType(void *gameData, void *eventWork, u32 zoneId)
{
    u32 layoutType = 0;

    if (ZONEDATA_IsZone1A6((u16)zoneId) || ZONEDATA_IsZone96Pair(zoneId)) {
        layoutType = 1;
    } else if (ZONEDATA_IsZone34(zoneId)) {
        layoutType = 4;
    } else if (GAME_DATA_GetIntrudeCount(gameData)) {
        layoutType = 5;
    } else if (!ZONEDATA_CheckEventFlag(eventWork, 0x961)) {
        layoutType = 3;
    } else if (!ZONEDATA_CheckEventFlag(eventWork, 0x962)) {
        layoutType = 2;
    }
    return layoutType;
}

/* Counts the slots of a layout that hold a button. */
int FIELD_MENU_CountLayoutButtons(int layoutType)
{
    int i;
    int count;

    i = 0;
    count = 0;
    for (; gFieldMenuLayouts[layoutType][i] != 0; i++) {
        if (gFieldMenuLayouts[layoutType][i] != FIELD_MENU_BUTTON_EMPTY) {
            count++;
        }
    }
    return count;
}

/* Builds the seven slots of the layout from the button table and the message bank. */
void FIELD_MENU_CreateItems(FieldMenu *menu, void *arcHandle, int layoutType)
{
    void *msgBank;
    u8 i;
    u8 j;
    int buttonId;
    const int *layoutRow;
    FieldMenuItemInit init;
    FieldMenuName nameBuf;
    FieldMenuName defaultName;

    msgBank = MSGDATA_CreateFromArchive(0, 2, 0x22, menu->subHeapId);
    for (i = 0; i < FIELD_MENU_ITEM_MAX; i++) {
        menu->items[i].inUse = 0;
    }
    j = 0;
    layoutRow = gFieldMenuLayouts[layoutType];
    defaultName = gFieldMenuDefaultName;
    for (; j < FIELD_MENU_ITEM_MAX; j++) {
        buttonId = layoutRow[j];
        if (buttonId == FIELD_MENU_BUTTON_PLAYER) {
            init.text = STRBUF_Create(0x10, menu->subHeapId);
            if (MYSTATUS_IsNameEmpty(menu->myStatus) == 0) {
                STRBUF_SetString(init.text, MYSTATUS_GetName(menu->myStatus));
            } else {
                nameBuf = defaultName;
                STRBUF_SetString(init.text, nameBuf.chars);
            }
        } else {
            init.text = MSGDATA_AllocString(msgBank, gFieldMenuMsgIds[buttonId]);
        }
        init.buttonId = buttonId;
        if (j != FIELD_MENU_ITEM_BACK) {
            init.cursorX = (j % 2) * 128 + 0x40;
            init.cursorY = (j / 2) * 0x30 + 0x2C;
            init.iconX = init.cursorX - 0x20;
            init.iconY = init.cursorY;
            init.arcHandle = arcHandle;
            init.charId = gFieldMenuIconRes[buttonId].charId;
            init.cellId = gFieldMenuIconRes[buttonId].cellId;
            init.animId = gFieldMenuIconRes[buttonId].animId;
            if (buttonId == 3 && MYSTATUS_GetOutfitVariant(menu->myStatus) == 1) {
                init.charId = 7;
                init.cellId = 0x16;
                init.animId = 0x20;
            }
            if (buttonId == 2 && MYSTATUS_GetOutfitVariant(menu->myStatus) == 1) {
                init.charId = 0xC;
                init.cellId = 0x1B;
                init.animId = 0x25;
            }
        } else {
            init.cursorX = 0x80;
            init.cursorY = 0xB4;
            init.iconX = 0;
            init.iconY = 0;
            init.arcHandle = 0;
            init.charId = 0;
            init.cellId = 0;
            init.animId = 0;
        }
        init.winTileX = gFieldMenuWindowPos[j].tileX;
        init.winTileY = gFieldMenuWindowPos[j].tileY;
        FIELD_MENU_CreateItem(menu, &menu->items[j], &init);
        STRBUF_Delete(init.text);
    }
    MSGDATA_Delete(msgBank);
}

/* Task proc: cycles two palette colors of the menu with a sine of the phase counter. */
void FIELD_MENU_ColorTask(void *taskHandle, FieldMenu *menu)
{
    s32 wave = GF_STANDARD_Get_F684((u16)menu->colorPhase) + 0x1000;
    u16 colors[2];

    colors[1] = (wave * 8 / 0x2000 + 9) | ((0x1F << 10) | ((wave * 5 / 0x2000 + 0x12) << 5));
    GXS_LoadOBJPltt(&colors[1], 0x142, 2);
    colors[0] = (wave * 0x1F / 0x2000) |
                (((wave * 6 / 0x2000 + 0x19) << 10) | ((wave * 13 / 0x2000 + 0x12) << 5));
    GXS_LoadOBJPltt(&colors[0], 0x15E, 2);
    menu->colorPhase += 6;
}

/* Puts the menu in its fully scrolled-out state. */
void FIELD_MENU_SetScrolledOut(FieldMenu *menu)
{
    FieldMenuScreenPos offset;

    menu->scrollY = FIELD_MENU_SCROLL_HIDDEN;
    BG_SYS_FillScrollArea(5, 3, -FIELD_MENU_SCROLL_HIDDEN);
    BG_SYS_FillScrollArea(6, 3, -(FIELD_MENU_SCROLL_HIDDEN + FIELD_MENU_LAYER6_OFFSET));
    offset.x = 0;
    offset.y = FIELD_MENU_SCROLL_HIDDEN;
    CLACT_SetSurfacePos(menu->clactSurface, 0, &offset);
}

/* Returns the button id of the selected slot, or 0 when none is selected. */
int FIELD_MENU_GetSelectedButtonId(FieldMenu *menu)
{
    FieldMenuItem *item = menu->selectedItem;

    if (item == 0) {
        return 0;
    }
    return item->buttonId;
}

/* Moves the cursor to the slot that holds the given button. */
void FIELD_MENU_SelectButton(FieldMenu *menu, u32 buttonId)
{
    u8 i;
    FieldMenuItem *items;

    for (i = 0, items = menu->items; i < FIELD_MENU_ITEM_MAX; i++) {
        if (menu->items[i].inUse == 1 && buttonId == menu->items[i].buttonId) {
            menu->cursorCol = i % 2;
            menu->cursorRow = i / 2;
            menu->cursorDirty = 1;
            FIELD_MENU_PlaceCursor(menu, items[menu->cursorCol + menu->cursorRow * 2].cursorX, items[menu->cursorCol + menu->cursorRow * 2].cursorY);
        }
    }
}

/* Slot index of a cursor position: two columns per row. */
int FIELD_MENU_GetSlotIndex(u32 col, u32 row)
{
    return (col + (row << 1));
}

/*
 * Moves the cursor one step in a direction (0 up, 1 down, 2 left, 3 right)
 * using the transition tables of the layout; returns 1 when it moved.
 */
u32 FIELD_MENU_MoveCursor(FieldMenu *menu, u32 dir)
{
    u32 index = FIELD_MENU_GetSlotIndex(menu->cursorCol, menu->cursorRow);
    u32 target = gFieldMenuCursorMoves[FIELD_MENU_CountLayoutButtons(menu->layoutType) - 4][index][dir];

    if (index != target) {
        if (target == 0xFF) {
            menu->cursorRow = 2;
            return 1;
        }
        if (target == 0xFE) {
            menu->cursorRow = 1;
            return 1;
        }
        if (target != FIELD_MENU_ITEM_BACK) {
            menu->cursorCol = gFieldMenuSlotCol[target * 2];
        }
        menu->cursorRow = gFieldMenuSlotRow[target * 2];
        return 1;
    }
    return 0;
}

/* Key input: moves the cursor, or selects the slot under it, or closes the menu. */
void FIELD_MENU_HandleKeys(FieldMenu *menu)
{
    u32 pressed;
    u32 repeated;

    pressed = KEY_GetTrg();
    repeated = KEY_GetRepeat();
    if (menu->keyCursorActive == 0 && (pressed | repeated) != 0) {
        if ((pressed & FIELD_MENU_PAD_B) || (pressed & FIELD_MENU_PAD_X)) {
            FIELD_MENU_StartLeave(menu, 1);
            return;
        }
        GFL_USE_PlaySeDefaultVolume(SE_FIELD_MENU_MOVE);
        menu->keyCursorActive = 1;
        menu->selectedItem = 0;
        menu->cursorDirty = 1;
        CLACT_SetActorDrawEnable(menu->cursorActor, 1);
        return;
    }
    if (repeated & FIELD_MENU_PAD_UP) {
        if (FIELD_MENU_MoveCursor(menu, 0) != 0) {
            menu->cursorDirty = 1;
            GFL_USE_PlaySeDefaultVolume(SE_FIELD_MENU_MOVE);
        }
    } else if (repeated & FIELD_MENU_PAD_DOWN) {
        if (FIELD_MENU_MoveCursor(menu, 1) != 0) {
            menu->cursorDirty = 1;
            GFL_USE_PlaySeDefaultVolume(SE_FIELD_MENU_MOVE);
        }
    } else if (repeated & FIELD_MENU_PAD_LEFT) {
        if (FIELD_MENU_MoveCursor(menu, 2) != 0) {
            menu->cursorDirty = 1;
            GFL_USE_PlaySeDefaultVolume(SE_FIELD_MENU_MOVE);
        }
    } else if (repeated & FIELD_MENU_PAD_RIGHT) {
        if (FIELD_MENU_MoveCursor(menu, 3) != 0) {
            menu->cursorDirty = 1;
            GFL_USE_PlaySeDefaultVolume(SE_FIELD_MENU_MOVE);
        }
    } else if ((pressed & FIELD_MENU_PAD_B) || (pressed & FIELD_MENU_PAD_X)) {
        FIELD_MENU_StartLeave(menu, 1);
    } else if (pressed & FIELD_MENU_PAD_A) {
        if (menu->items[FIELD_MENU_GetSlotIndex(menu->cursorCol, menu->cursorRow)].buttonId != FIELD_MENU_BUTTON_EMPTY) {
            FIELD_MENU_StartLeave(menu, 0);
            func_020355D8(0);
        }
    }
}

/* Touch input: a tap on a slot moves the cursor there and selects it. */
void FIELD_MENU_HandleTouch(FieldMenu *menu)
{
    FieldMenuTouchTable touchTable = gFieldMenuTouchTable;
    int hitSlot = TOUCHPANEL_HitTrg(&touchTable);
    u32 zero;

    if (hitSlot != -1 && menu->items[hitSlot].buttonId != FIELD_MENU_BUTTON_EMPTY) {
        menu->cursorCol = hitSlot % 2;
        menu->cursorRow = hitSlot / 2;
        zero = 0;
        menu->keyCursorActive = zero;
        CLACT_SetActorDrawEnable(menu->cursorActor, 0);
        if (hitSlot == FIELD_MENU_ITEM_BACK) {
            FIELD_MENU_StartLeave(menu, 1);
            return;
        }
        menu->cursorDirty = 1;
        FIELD_MENU_StartLeave(menu, zero);
        func_020355D8(1);
    }
}

/* Moves the cursor actor to a position and restarts the color phase. */
void FIELD_MENU_PlaceCursor(FieldMenu *menu, s16 x, s16 y)
{
    FieldMenuScreenPos pos;

    pos.x = x;
    pos.y = y;
    CLACT_AddActorSurfacePos(menu->cursorActor, &pos, 0);
    menu->colorPhase = 0;
}

/* Starts leaving the menu: back = 1 plays the back button, else the slot is chosen. */
void FIELD_MENU_StartLeave(FieldMenu *menu, int back)
{
    if (back == 1) {
        menu->exitRequested = 1;
        menu->state = FIELD_MENU_STATE_BACK_ANIM;
        CLACT_SetActorAnimSeq(menu->backActor, 8);
    } else {
        menu->exitRequested = 0;
        menu->state = FIELD_MENU_STATE_DECIDE;
        menu->chosenButton = menu->items[FIELD_MENU_GetSlotIndex(menu->cursorCol, menu->cursorRow)].buttonId;
    }
}

/* Applies a cursor move: selects the new slot and swaps the highlighted icon animation. */
void FIELD_MENU_UpdateSelection(FieldMenu *menu)
{
    FieldMenuItem *previous;

    if (menu->cursorDirty == 1) {
        previous = menu->selectedItem;
        menu->selectedItem = &menu->items[menu->cursorCol + menu->cursorRow * 2];
        CLACT_SetActorAnimSeq(menu->cursorActor, 0);
        FIELD_MENU_PlaceCursor(menu, menu->selectedItem->cursorX, menu->selectedItem->cursorY);
        if (menu->selectedItem->actor != 0 && menu->keyCursorActive == 1) {
            CLACT_SetActorAnimSeq(menu->selectedItem->actor, 1);
        }
        if (previous != 0 && previous->actor != 0) {
            CLACT_SetActorAnimSeq(previous->actor, 0);
        }
        menu->cursorDirty = 0;
    }
}

/* Creates one slot: its text window, icon resources and icon actor. */
void FIELD_MENU_CreateItem(FieldMenu *menu, FieldMenuItem *item, const FieldMenuItemInit *init)
{
    FieldMenuActorSetup setup;
    u32 textColor;

    textColor = FIELD_MSGBG_GetFont(FIELDMAP_GetMsgBg(menu->fieldMap));
    item->inUse = 1;
    item->buttonId = init->buttonId;
    item->cursorX = init->cursorX;
    item->cursorY = init->cursorY;
    item->bmpWin = BMP_WIN_Create(6, init->winTileX, init->winTileY, 8, 2, 0xD, 1);
    BMP_WIN_MakeScreen(item->bmpWin);
    BMP_Clear(BMP_WIN_GetBmp(item->bmpWin), 0);
    PRINTSYS_PrintQueColor(menu->printQue, BMP_WIN_GetBmp(item->bmpWin), 2, 1, init->text, textColor, 0x440);
    if (init->arcHandle != 0) {
        item->charRes = CLACT_RegisterCharacter(init->arcHandle, init->charId, 0, 1, menu->heapId);
        item->cellRes = CLACT_RegisterCellAnim(init->arcHandle, init->cellId, init->animId, menu->heapId);
        setup.x = init->iconX;
        setup.y = init->iconY;
        setup.z = 0;
        setup.flip = 0;
        setup.palOffset = 0;
        setup.bgPriority = 0;
        setup.reserved0A = 0;
        setup.scaleX = 0x1000;
        setup.scaleY = 0x1000;
        setup.rotation = 0;
        setup.drawArea = 2;
        item->actor = CLACT_CreateAffineActor(menu->clactUnit, item->charRes, menu->palRes, item->cellRes, &setup, 0, menu->heapId);
        CLACT_SetActorAutoAnimSpeed(item->actor, 0x1000);
        CLACT_SetActorAutoAnim(item->actor, 1);
        CLACT_SetActorAnimSeq(item->actor, 0);
        if (item->buttonId == FIELD_MENU_BUTTON_EMPTY) {
            CLACT_SetActorDrawEnable(item->actor, 0);
        } else {
            CLACT_SetActorDrawEnable(item->actor, 1);
        }
    } else {
        item->actor = 0;
    }
}

/* Frees the window and the icon resources of one slot. */
void FIELD_MENU_DeleteItem(FieldMenu *menu, FieldMenuItem *item)
{
    if (item->inUse == 1) {
        BMP_WIN_Delete(item->bmpWin);
        if (item->actor != 0) {
            CLACT_DeleteActor(item->actor);
            CLACT_ReleaseCellAnim(item->cellRes);
            CLACT_ReleaseCharacter(item->charRes);
        }
    }
}

/* Pushes the slot window to the screen once its text is printed. */
void FIELD_MENU_ShowItemWindow(FieldMenu *menu, FieldMenuItem *item)
{
    if (item->inUse == 1) {
        BMP_WIN_TransferChars(item->bmpWin);
    }
}

/*
 * Loads the frame screen file and writes it to a BG layer with palette 3 and
 * tile base 0x80.
 * 0x021A8E14 is not a function: it lies inside FIELD_MENU_GetSelectedButtonId (bytes
 * 0x021A8E10..0x021A8E1F), the listing has no label there and nothing calls it.
 * The old src/matched func_021A8E14 (an SDK signature hit on EL_GetLibSize)
 * matched the tail of FIELD_MENU_GetSelectedButtonId.
 */
void FIELD_MENU_LoadScreen(u32 heapId, u32 layer)
{
    FieldMenuScreenData *screen;
    void *screenBuf;
    int i;
    u16 *tiles;
    void *arcHandle;

    arcHandle = ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), heapId);
    ARC_UTIL_UploadPaletteFromHandleWhole(arcHandle, APP_ICON_GetStatusAnimFileId(), 4, 0x60, 0x20, heapId);
    ARC_UTIL_UploadBgCharFromHandle(arcHandle, APP_ICON_GetStatusFrameFileId(), layer, 0x80, 0, 0, heapId);
    screenBuf = ARC_UTIL_LoadPaletteDataFromHandle(arcHandle, APP_ICON_GetStatusDataFileId(), 0, (void **)&screen, heapId);
    ARC_TOOL_DeleteHandle(arcHandle);
    tiles = screen->tiles;
    for (i = 0; i < 0x300; i++) {
        tiles[i] = (tiles[i] + 0x80) | 0x3000;
    }
    BG_SYS_DrawTileEx((u8)layer, 0, 0x15, 0x20, 3, (u32)screen->tiles, 0, 0x15, 0x20, 0x18);
    BG_SYS_SetFlagField06(layer);
    GFL_HEAP_Free(screenBuf);
}
