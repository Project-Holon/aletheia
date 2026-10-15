/*
 * file:     manual_common.c
 * unit:     yes
 * function: MANUAL_COMMON_CreateMenuTable, MANUAL_COMMON_DeleteMenuTable, MANUAL_COMMON_GetEntryValue0, MANUAL_COMMON_GetEntryValue1, MANUAL_COMMON_GetEntryValue2, MANUAL_COMMON_GetEntryValue3, MANUAL_COMMON_GetEntryPair0, MANUAL_COMMON_GetEntryPair1, MANUAL_COMMON_GetEntryCount, MANUAL_COMMON_GetGroupValue0, MANUAL_COMMON_GetGroupValue1, MANUAL_COMMON_GetGroupValue2, MANUAL_COMMON_GetGroupCount, MANUAL_COMMON_CheckUnlocked, MANUAL_COMMON_GetSaveValue, MANUAL_COMMON_SetSaveValue, MANUAL_COMMON_IsValidKey, MANUAL_COMMON_GetDefaultId, MANUAL_COMMON_GetGroupEntry, MANUAL_COMMON_GetGroupOffset, MANUAL_COMMON_GetEntry, MANUAL_COMMON_GetEntryOffset, MANUAL_COMMON_CreateData, MANUAL_COMMON_DeleteData, MANUAL_COMMON_DrawData, MANUAL_COMMON_SetScreenId, MANUAL_COMMON_InitDisplay, MANUAL_COMMON_DataNoop, MANUAL_COMMON_CreateTouchbar, MANUAL_COMMON_DeleteTouchbar, MANUAL_COMMON_UpdateTouchbar, MANUAL_COMMON_SetTouchbarState, MANUAL_COMMON_SetTouchbarSelection, MANUAL_COMMON_GetTouchbarSelected, MANUAL_COMMON_GetTouchbarPressed, MANUAL_COMMON_TouchbarTaskNoop, MANUAL_COMMON_CreateTouchbarWidget, MANUAL_COMMON_TouchbarNoop, MANUAL_COMMON_CreateTouchbarSlots, MANUAL_COMMON_DeleteTouchbarSlots, MANUAL_COMMON_UpdateTouchbarSlots, MANUAL_COMMON_DrawTouchbarIdle, MANUAL_COMMON_DrawTouchbarStart, MANUAL_COMMON_DrawTouchbarEnd, MANUAL_COMMON_DrawTouchbarContinue, MANUAL_COMMON_LoadTouchbarActors, MANUAL_COMMON_DeleteTouchbarActors, MANUAL_COMMON_UpdateTouchbarActors, MANUAL_COMMON_ResetTouchbar, MANUAL_COMMON_CreateListWork, MANUAL_COMMON_DeleteListWork, MANUAL_COMMON_UpdateListWork, MANUAL_COMMON_ListWorkTaskNoop, MANUAL_COMMON_LoadListWorkAssets, MANUAL_COMMON_CreateListWorkMenu, MANUAL_COMMON_SetListWorkBgMode, MANUAL_COMMON_DeleteListWorkAssets, MANUAL_COMMON_DeleteListWorkMenu, MANUAL_COMMON_UpdateListWorkInput, MANUAL_COMMON_UpdateListWorkDrag, MANUAL_COMMON_BuildListRects, MANUAL_COMMON_GetCursorIndex, MANUAL_COMMON_GetLastVisible, MANUAL_COMMON_GetVisibleCount, MANUAL_COMMON_GetScrollTop, MANUAL_COMMON_RebuildListWindows, MANUAL_COMMON_HitToIndex, MANUAL_COMMON_IndexToY, MANUAL_COMMON_CreateDialog, MANUAL_COMMON_DeleteDialog, MANUAL_COMMON_UpdateDialog, MANUAL_COMMON_DialogTaskNoop, MANUAL_COMMON_LoadDialogAssets, MANUAL_COMMON_CreateDialogWindows, MANUAL_COMMON_SetDialogBgMode, MANUAL_COMMON_DeleteDialogStep, MANUAL_COMMON_DeleteDialogWindows, MANUAL_COMMON_UpdateDialogInput
 * address:  0x021B9B3C
 * region:   ov225
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
 *   ARC_UTIL_LoadHandleMemberWithSize 0x0204A39C arm
 *   gManualCommonTableAllocFile 0x021BBFF4 data ov225 a1
 *   func_020307B0 0x020307B0 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02009210 0x02009210 thumb
 *   func_020090E0 0x020090E0 thumb
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   MISC_SAVEDATA_GetBlock44  0x0200ED48  thumb
 *   func_0200EDEC  0x0200EDEC  thumb
 *   func_0200EE14 0x0200EE14 thumb
 *   MANUAL_GRAPHIC_CreateScreen 0x021B9900 thumb ov225
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromArchive 0x02049B90 arm
 *   gManualCommonDataAllocFile 0x021BC004 data ov225 a1
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MANUAL_GRAPHIC_DeleteScreen 0x021B99A0 thumb ov225
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   MANUAL_GRAPHIC_DrawScreen 0x021B99F4 thumb ov225
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   GX_LoadBG2Scr 0x0207EB78 arm
 *   func_02040588 0x02040588 arm
 *   ov067_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   gManualCommonTouchbarAllocFile 0x021BC014 data a1
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   func_02034A5C 0x02034A5C arm
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   gManualCommonTouchbarButtonIds 0x021BBF2C data a4
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   gManualCommonTouchbarBgTable 0x021BBF4C data a4
 *   MI_CpuFill8 0x02082BCC arm
 *   MANUAL_GRAPHIC_GetClactUnit 0x021B9A08 thumb ov225
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   gManualCommonSlotRecords 0x021BBF00 data a1
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02045EC0 0x02045EC0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   gManualCommonActorEntries 0x021BBF14 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   KEY_GetRepeat 0x0203633C arm
 *   func_020355D8 0x020355D8 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   gManualCommonListWorkAllocFile 0x021BC028 data ov225 a1
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   APP_TASKMENU_WIN_IsFinish 0x02028230 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 *   gManualCommonListHeadPos 0x021BBF8C data ov225 a2
 *   gManualCommonListRowPos 0x021BBF94 data ov225 a2
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   func_02061CA4 0x02061CA4 arm
 *   func_020355C4 0x020355C4 arm
 *   APP_TASKMENU_WIN_SetActive 0x02028218 thumb
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   KEY_GetTrg 0x020362DC arm
 *   APP_TASKMENU_WIN_SetDecide 0x0202822C thumb
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   APP_TASKMENU_WIN_ClearScreen 0x0202843C thumb
 *   APP_TASKMENU_WIN_DeleteNoClear 0x0202815C thumb
 *   APP_TASKMENU_WIN_CreateExNoScreen 0x0202804C thumb
 *   APP_TASKMENU_WIN_Create 0x02027FEC thumb
 *   gManualCommonDialogAllocFile 0x021BC038 data a1
 *   gManualCommonDialogHitRects 0x021BBF9C data a4
 *   gManualGraphicMainBgLayerTable  0x021BBE4C  data
 */

struct Big;
struct Sub02009210Obj;
struct Sub020090B0Obj;
struct BigObj;
struct GfFont;
struct MsgBank;
struct Rec;
struct PrintSys;
struct Node;
struct Obj;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct U16Vec;
struct WordSet;
struct Actor;
struct TaskMenuState;
struct ManualMenuTable;
struct ManualTouchbar;
struct ManualListBuffer;
struct ManualRes;
typedef struct S S;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed int s32;
typedef short s16;

/* Manual data object built by MANUAL_COMMON_CreateData (0x38). */
struct ManualData {
    void *owner;                     /* 0x00 save control object */
    u16 heap;                        /* 0x04 */
    u16 pad06;                       /* 0x06 */
    void *screen;                    /* 0x08 graphic screen */
    u32 font;                        /* 0x0C */
    u32 printQue0;                   /* 0x10 */
    u32 printQue1;                   /* 0x14 */
    u32 printQue2;                   /* 0x18 */
    void *bank0;                     /* 0x1C */
    void *bank1;                     /* 0x20 */
    void *arc0;                      /* 0x24 */
    void *arc1;                      /* 0x28 */
    void *assets;                    /* 0x2C archive table */
    u16 id;                          /* 0x30 */
    u16 pad32;                       /* 0x32 */
    void *group;                     /* 0x34 */
};

/* Archive table object returned by MANUAL_COMMON_CreateMenuTable (0x10). */
struct ManualMenuTable {
    u32 base0;      /* 0x00 group table base */
    u32 offsets0;   /* 0x04 group offset array */
    u32 base1;      /* 0x08 entry table base */
    u32 offsets1;   /* 0x0C entry offset array */
};

/* Touch bar object built by MANUAL_COMMON_CreateTouchbar (0x4C). */
struct ManualTouchbar {
    void *owner;                /* 0x00 */
    void *touchbar;             /* 0x04 TOUCHBAR handle */
    u32 mode;                   /* 0x08 */
    u8 selectX;                 /* 0x0C */
    u8 selectY;                 /* 0x0D */
    u8 pad0E[6];                /* 0x0E */
    void *bmp0;                 /* 0x14 */
    u32 pad18;                  /* 0x18 */
    u32 bmp0Dirty;              /* 0x1C */
    u32 pressState;             /* 0x20 */
    int pressedId;              /* 0x24 */
    int releasedId;             /* 0x28 */
    u32 animPalette;            /* 0x2C */
    u32 animCharacter;          /* 0x30 */
    u32 animCell;               /* 0x34 */
    void *actor0;               /* 0x38 */
    void *actor1;               /* 0x3C */
    u8 focusIndex;              /* 0x40 */
    u8 pad41[3];                /* 0x41 */
    u32 animState;              /* 0x44 */
    void *task;                 /* 0x48 */
};

/* List work object built by MANUAL_COMMON_CreateListWork (0x98). */
struct ManualListWork {
    char *owner;                /* 0x00 list state */
    struct ManualData *data;    /* 0x04 */
    void *resource;             /* 0x08 taskmenu resource */
    void *win[8];               /* 0x0C */
    u32 slotFlag[8];            /* 0x2C */
    u16 field4C;                /* 0x4C */
    u16 pad4E;                  /* 0x4E */
    u32 reg0;                   /* 0x50 */
    u32 reg1;                   /* 0x54 */
    u32 reg2;                   /* 0x58 */
    void *actor;                /* 0x5C */
    void *actorList[8];         /* 0x60 */
    void *task;                 /* 0x80 */
    u32 state;                  /* 0x84 */
    u32 dragging;               /* 0x88 */
    u32 dirty;                  /* 0x8C */
    signed char timer;          /* 0x90 */
    u8 pad91[3];                /* 0x91 */
    u32 listReady;              /* 0x94 */
};

/* Confirm dialog object built by MANUAL_COMMON_CreateDialog (0x20). */
struct ManualDialog {
    char *owner;                     /* 0x00 selection buffer */
    struct ManualData *data;         /* 0x04 */
    void *resource;                  /* 0x08 taskmenu resource */
    void *win[2];                    /* 0x0C */
    void *task;                      /* 0x14 */
    u32 state;                       /* 0x18 */
    signed char timer;               /* 0x1C */
    u8 pad1D[3];                     /* 0x1D */
};

/* List state region at ManualListWork.owner (0x14). */
struct ManualListState {
    u32 ready;      /* 0x00 */
    u16 count;      /* 0x04 */
    u16 pad06;      /* 0x06 */
    void *data;     /* 0x08 entry table */
    u16 top;        /* 0x0C */
    u16 selected;   /* 0x0E */
    u32 mode;       /* 0x10 */
};

/* Selection region at ManualWork+0x14 passed to MANUAL_COMMON_CreateDialog (0x8). */
struct ManualListBuffer {
    u8 selected;    /* 0x00 */
    u8 pad01[3];    /* 0x01 */
    u32 choice;     /* 0x04 */
};

/* Argument block for TOUCHBAR_Create. */
typedef struct {u8 *bgTable;u32 layer;int clactUnit;u32 cellW,cellH,flags;int reserved18,reserved1C;} ManualTouchbarArgs;

struct ManualBgTable {u32 words[16];};
struct ManualEntryRecord {unsigned word[7];};
struct ManualBmpParams {u8 layer,baseX,baseY,tiles,palette,mode,slot,pad7,pad8;};
struct ManualActorEntry { u32 first; u16 normal,pad6; u8 left,right,top,bottom; u32 active,mask,sound,last; };
struct ManualClactPos { s16 x; s16 y; };
struct ManualPoint {short x,y;};
struct ManualQuad { short x,y,z,w; };
struct ManualTaskEntry {void *resource;u16 tag,pad;u32 flags;};

typedef char ManualData_size[sizeof(struct ManualData)==0x38?1:-1];
typedef char ManualMenuTable_size[sizeof(struct ManualMenuTable)==0x10?1:-1];
typedef char ManualTouchbar_size[sizeof(struct ManualTouchbar)==0x4C?1:-1];
typedef char ManualListWork_size[sizeof(struct ManualListWork)==0x98?1:-1];
typedef char ManualDialog_size[sizeof(struct ManualDialog)==0x20?1:-1];
typedef char ManualListState_size[sizeof(struct ManualListState)==0x14?1:-1];
typedef char ManualListBuffer_size[sizeof(struct ManualListBuffer)==0x8?1:-1];


extern void *func_02030734(u32, u32, int, const char *, u16);
extern void *ARC_UTIL_LoadHandleMemberWithSize(void *, int, int, u32, u32 *);
extern u32 func_020307B0(void *p);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern struct Sub02009210Obj *func_02009210(void *);
extern u8 func_020090E0(const struct Sub020090B0Obj *);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern unsigned ZONEDATA_CheckEventFlag(void *,int);
extern void *MISC_SAVEDATA_GetBlock44(void *p);
extern int func_0200EDEC(char *obj, int i);
extern void func_0200EE14(char *obj, int i);
extern void *MANUAL_GRAPHIC_CreateScreen(u32,u32);
extern struct GfFont *GF_FONT_Create(int,int,int,int,u32);
extern u32 PRINTSYS_QUE_Create(void *);
extern struct MsgBank *func_02045B38(u32,u32,u32,u32);
extern void *func_020490F4(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromArchive(u32,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern unsigned int GF_FONT_Delete(void *ptr);
extern void MANUAL_GRAPHIC_DeleteScreen(char *);
extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);
extern void MANUAL_GRAPHIC_DrawScreen(char *);
extern void DWCi_ScreenDC_FlushRange(const void *,unsigned);
extern void GX_LoadBG2Scr(const void *,unsigned,unsigned);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int func_02034AC4(int);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_02030EAC(struct Node *n);
extern void TOUCHBAR_Delete(unsigned char *);
extern void func_02034A5C(int);
extern void TOUCHBAR_Update(struct S *p);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(u8 *);
extern int TOUCHBAR_GetPressedButtonIdIfDone(u8 *);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned);
extern void MI_CpuFill8(void *,u8,u32);
extern u32 MANUAL_GRAPHIC_GetClactUnit(const u8 *p);
extern struct ManualRes *TOUCHBAR_Create(ManualTouchbarArgs *,int);
extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,u8,u8,u8);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *,u8);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void PRINTSYS_QUE_Clear(struct PrintSys *),BMP_WIN_Delete(struct Descriptor *);
extern unsigned PRINTSYS_QUE_IsExistTarget(struct PrintSys *,void *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern void *func_02045EC0(struct MsgBank *,unsigned);
extern void PRINTSYS_PrintQueColor(void *,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void STRBUF_Delete(struct U16Vec *);
extern struct WordSet *WORDSET_CreateDefault(u32);
extern struct U16Vec *STRBUF_Create(u32,u32);
extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);
extern void WORDSET_CopyTaggedText(struct WordSet *,void *,void *);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 APP_ICON_GetArchiveId(void);
extern u32 APP_ICON_GetMoveKindPaletteFileId(void);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern u32 APP_ICON_GetMoveKindAnimFileId(void);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern u32 APP_ICON_GetStatusCellFileId(u32);
extern u32 APP_ICON_GetStatusPaletteFileId(u32);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorAutoAnim(struct Obj *,u32);
extern void CLACT_DeleteActor(struct Obj *);
extern void CLACT_ReleaseCellAnim(u32);
extern void CLACT_ReleaseCharacter(u32);
extern void CLACT_ReleasePalette(u32);
extern u32 CLACT_GetActorDrawEnable(struct Obj *);
extern u32 KEY_GetRepeat(void);
extern void func_020355D8(u8);
extern u32 TOUCHPANEL_GetPointTrg(u32 *,u32 *);
extern void CLACT_SetActorAnimSeq(struct Obj *,u16);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern u32 CLACT_IsActorAnimActive(struct Actor *);
extern void BG_SYS_ResetSlot(u32, u32, u32);
extern void CLACT_AddActorSurfacePos(struct Obj *, const struct ManualClactPos *, u32);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern u32 APP_TASKMENU_WIN_IsFinish(u8 *);
extern void func_02049B68(void *,u32,u32,u32,u32,u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *,u32,u32,u32,u32,u32,u32,u16);
extern void BG_SYS_FreeSlot(unsigned);
extern struct ManualRes *APP_TASKMENU_RES_Create(u16, u16, unsigned, unsigned, u16);
extern int func_02061CA4(void *, unsigned, void *, int);
extern u8 func_020355C4(void);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *, unsigned);
extern void BG_SYS_SetFlagField06(u32);
extern void APP_TASKMENU_WIN_Delete(u8 *);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern int TOUCHPANEL_HitTrg(const void *);
extern void APP_TASKMENU_WIN_SetDecide(char *p, int v);
extern void APP_TASKMENU_WIN_ClearScreen(u8 *);
extern void APP_TASKMENU_WIN_DeleteNoClear(void);
extern u32 *APP_TASKMENU_WIN_CreateExNoScreen(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5, u32 a6, u32 a7, u16 a8);
extern u32 APP_TASKMENU_WIN_Create(u32 a0, u32 a1, u32 a2, u32 a3, u8 a4, u16 a5);
void *MANUAL_COMMON_CreateMenuTable(void *narc, u32 heap);
void MANUAL_COMMON_DeleteMenuTable(char *p);
u16 MANUAL_COMMON_GetEntryValue0(char *p,int index);
u16 MANUAL_COMMON_GetEntryValue1(char *p,int index);
u16 MANUAL_COMMON_GetEntryValue2(char *p,int index);
u16 MANUAL_COMMON_GetEntryValue3(char *p,int index);
u16 MANUAL_COMMON_GetEntryPair0(char *p, int idx, int c);
u16 MANUAL_COMMON_GetEntryPair1(char *p, int idx, int c);
u16 MANUAL_COMMON_GetEntryCount(const char *p);
u16 MANUAL_COMMON_GetGroupValue0(char *p,int index);
u16 MANUAL_COMMON_GetGroupValue1(char *p,int index);
u16 MANUAL_COMMON_GetGroupValue2(char *p, int idx, int c);
u16 MANUAL_COMMON_GetGroupCount(const char *p);
int MANUAL_COMMON_CheckUnlocked(void *unused,int kind,void *save);
int MANUAL_COMMON_GetSaveValue(void *unused, int b, int c);
void MANUAL_COMMON_SetSaveValue(void *unused,int code,struct Big *save);
int MANUAL_COMMON_IsValidKey(unsigned unused,unsigned key);
int MANUAL_COMMON_GetDefaultId(void *a0);
int MANUAL_COMMON_GetGroupEntry(char *p, int idx);
unsigned short MANUAL_COMMON_GetGroupOffset(char *p,unsigned i);
int MANUAL_COMMON_GetEntry(char *p, int idx);
unsigned short MANUAL_COMMON_GetEntryOffset(char *p,unsigned i);
void *MANUAL_COMMON_CreateData(void *owner,u16 heap);
void MANUAL_COMMON_DeleteData(char *p);
void MANUAL_COMMON_DrawData(char *p);
void MANUAL_COMMON_SetScreenId(char *p,unsigned id);
void MANUAL_COMMON_InitDisplay(void *a0);
void MANUAL_COMMON_DataNoop(void *a0);
void *MANUAL_COMMON_CreateTouchbar(char *owner);
void MANUAL_COMMON_DeleteTouchbar(char *p);
void MANUAL_COMMON_UpdateTouchbar(char *p);
void MANUAL_COMMON_SetTouchbarState(char *p,unsigned state);
void MANUAL_COMMON_SetTouchbarSelection(char *p,unsigned b,unsigned c);
unsigned MANUAL_COMMON_GetTouchbarSelected(char *p);
unsigned MANUAL_COMMON_GetTouchbarPressed(char *p);
void MANUAL_COMMON_TouchbarTaskNoop(void *task,void *data);
void MANUAL_COMMON_CreateTouchbarWidget(char *p);
void MANUAL_COMMON_TouchbarNoop(void *a0);
void MANUAL_COMMON_CreateTouchbarSlots(char *p);
void MANUAL_COMMON_DeleteTouchbarSlots(char *p);
void MANUAL_COMMON_UpdateTouchbarSlots(char *p);
void MANUAL_COMMON_DrawTouchbarIdle(char *p);
void MANUAL_COMMON_DrawTouchbarStart(char *p);
void MANUAL_COMMON_DrawTouchbarEnd(char *p);
void MANUAL_COMMON_DrawTouchbarContinue(char *p);
void MANUAL_COMMON_LoadTouchbarActors(char *p);
void MANUAL_COMMON_DeleteTouchbarActors(char *p);
void MANUAL_COMMON_UpdateTouchbarActors(char *p);
void MANUAL_COMMON_ResetTouchbar(char *p);
void *MANUAL_COMMON_CreateListWork(char *owner, struct ManualData *data);
void MANUAL_COMMON_DeleteListWork(char *p);
int MANUAL_COMMON_UpdateListWork(char *p);
void MANUAL_COMMON_ListWorkTaskNoop(void);
void MANUAL_COMMON_LoadListWorkAssets(char *p);
void MANUAL_COMMON_CreateListWorkMenu(char *p);
void MANUAL_COMMON_SetListWorkBgMode(struct ManualListWork *a0);
void MANUAL_COMMON_DeleteListWorkAssets(char *p);
void MANUAL_COMMON_DeleteListWorkMenu(char *p);
int MANUAL_COMMON_UpdateListWorkInput(char *p);
int MANUAL_COMMON_UpdateListWorkDrag(char *p);
void MANUAL_COMMON_BuildListRects(u8 *p);
u16 MANUAL_COMMON_GetCursorIndex(u16 **p);
u16 MANUAL_COMMON_GetLastVisible(u16 **p);
u16 MANUAL_COMMON_GetVisibleCount(u16 **p);
u16 MANUAL_COMMON_GetScrollTop(u16 **p);
void MANUAL_COMMON_RebuildListWindows(char *p);
u16 MANUAL_COMMON_HitToIndex(void *p, u16 count, u16 value);
u16 MANUAL_COMMON_IndexToY(void *p, u16 count, u16 index);
char *MANUAL_COMMON_CreateDialog(char *p, char *data);
void MANUAL_COMMON_DeleteDialog(char *p);
int MANUAL_COMMON_UpdateDialog(char *p);
void MANUAL_COMMON_DialogTaskNoop(void *p);
void MANUAL_COMMON_LoadDialogAssets(char *p);
void MANUAL_COMMON_CreateDialogWindows(char *p);
void MANUAL_COMMON_SetDialogBgMode(char *a0);
void MANUAL_COMMON_DeleteDialogStep(char *p);
void MANUAL_COMMON_DeleteDialogWindows(char *p);
int MANUAL_COMMON_UpdateDialogInput(char *p);
extern char gManualCommonTableAllocFile[];
extern const char gManualCommonDataAllocFile[];
extern const char ov067_id[];
extern const char gManualCommonTouchbarAllocFile[];
extern const struct ManualEntryRecord gManualCommonTouchbarButtonIds[];
extern const struct ManualBgTable gManualCommonTouchbarBgTable;
extern const struct ManualBmpParams gManualCommonSlotRecords[];
extern const struct ManualActorEntry gManualCommonActorEntries[];
extern const char gManualCommonListWorkAllocFile[];
extern const struct ManualQuad gManualCommonListHeadPos,gManualCommonListRowPos;
extern const char gManualCommonDialogAllocFile[];
extern const u8 gManualCommonDialogHitRects[];



void *MANUAL_COMMON_CreateMenuTable(void *narc, u32 heap)
{
    void **table = func_02030734(heap, 16, 1, gManualCommonTableAllocFile, 0x9c);
    u32 size;
    table[0] = ARC_UTIL_LoadHandleMemberWithSize(narc, 11, 0, heap, &size);
    table[1] = ARC_UTIL_LoadHandleMemberWithSize(narc, 12, 0, heap, &size);
    table[2] = ARC_UTIL_LoadHandleMemberWithSize(narc, 9, 0, heap, &size);
    table[3] = ARC_UTIL_LoadHandleMemberWithSize(narc, 10, 0, heap, &size);
    return table;
}



void MANUAL_COMMON_DeleteMenuTable(char *table) {func_020307B0((void *)((struct ManualMenuTable *)table)->offsets1);func_020307B0((void *)((struct ManualMenuTable *)table)->base1);func_020307B0((void *)((struct ManualMenuTable *)table)->offsets0);func_020307B0((void *)((struct ManualMenuTable *)table)->base0);func_020307B0(table);}



u16 MANUAL_COMMON_GetEntryValue0(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetGroupEntry(table,index)+6);}



u16 MANUAL_COMMON_GetEntryValue1(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetGroupEntry(table,index)+8);}



u16 MANUAL_COMMON_GetEntryValue2(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetGroupEntry(table,index)+10);}



u16 MANUAL_COMMON_GetEntryValue3(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetGroupEntry(table,index)+12);}




/*
 * Addresses are Black-image addresses.
 */
u16 MANUAL_COMMON_GetEntryPair0(char *table, int idx, int pair)
{
    return ((u16 *)MANUAL_COMMON_GetGroupEntry(table, idx))[(pair << 1) + 7];
}




u16 MANUAL_COMMON_GetEntryPair1(char *table, int idx, int pair)
{
    return ((u16 *)MANUAL_COMMON_GetGroupEntry(table, idx))[(pair << 1) + 8];
}



u16 MANUAL_COMMON_GetEntryCount(const char *table) {return **(u16 * *)&((struct ManualMenuTable *)table)->offsets0;}



u16 MANUAL_COMMON_GetGroupValue0(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetEntry(table,index)+2);}



u16 MANUAL_COMMON_GetGroupValue1(char *table,int index) {return *(u16 *)(MANUAL_COMMON_GetEntry(table,index)+4);}




u16 MANUAL_COMMON_GetGroupValue2(char *table, int idx, int index2)
{
    return ((u16 *)MANUAL_COMMON_GetEntry(table, idx))[index2 + 3];
}



u16 MANUAL_COMMON_GetGroupCount(const char *table) {return **(u16 * *)&((struct ManualMenuTable *)table)->offsets1;}



int MANUAL_COMMON_CheckUnlocked(void *unused,int kind,void *save)
{
    int result=0;
    switch(kind) {
    case 0:result=1;break;
    case 1:
        if(func_020090E0((const struct Sub020090B0Obj *)func_02009210(GAME_DATA_GetSaveControl((struct Big *)save)))!=0)result=1;
        break;
    case 2:
        if(ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork(save),2400)!=0)result=1;
        break;
    }
    return result;
}




int MANUAL_COMMON_GetSaveValue(void *unused, int id, int save)
{
    return func_0200EDEC(MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl((struct Big *)save)), id);
}



void MANUAL_COMMON_SetSaveValue(void *unused,int value,struct Big *save) {func_0200EE14(MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl(save)),value);}



int MANUAL_COMMON_IsValidKey(unsigned unused,unsigned key) {if(key!=65535)return 1;return 0;}



int MANUAL_COMMON_GetDefaultId(void *unused){return 0x48;}




int MANUAL_COMMON_GetGroupEntry(char *table, int idx)
{
    return MANUAL_COMMON_GetGroupOffset(table, idx) + ((struct ManualMenuTable *)table)->base0;
}



unsigned short MANUAL_COMMON_GetGroupOffset(char *table,unsigned index){return *(unsigned short *)(((struct ManualMenuTable *)table)->offsets0+index*2+2);}




int MANUAL_COMMON_GetEntry(char *table, int idx)
{
    return MANUAL_COMMON_GetEntryOffset(table, idx) + ((struct ManualMenuTable *)table)->base1;
}



unsigned short MANUAL_COMMON_GetEntryOffset(char *table,unsigned index){return *(unsigned short *)(((struct ManualMenuTable *)table)->offsets1+index*2+2);}



void *MANUAL_COMMON_CreateData(void *owner,u16 heap)
{
    struct ManualData *data=func_02030734(heap,0x38,1,gManualCommonDataAllocFile,0x4b);
    data->owner=owner; data->heap=heap;
    data->screen=MANUAL_GRAPHIC_CreateScreen(1,data->heap);
    data->font=(u32)GF_FONT_Create(23,0,0,0,data->heap);
    data->printQue0=(u32)PRINTSYS_QUE_Create((void *)(u32)data->heap);
    data->printQue1=(u32)PRINTSYS_QUE_Create((void *)(u32)data->heap);
    data->printQue2=(u32)PRINTSYS_QUE_Create((void *)(u32)data->heap);
    data->bank0=func_02045B38(0,2,61,data->heap);
    data->bank1=func_02045B38(0,2,62,data->heap);
    data->arc0=func_020490F4(223,data->heap);
    data->arc1=func_020490F4(231,data->heap);
    ARC_UTIL_UploadPaletteFromArchive(23,5,4,0,64,32,data->heap);
    data->assets=MANUAL_COMMON_CreateMenuTable(data->arc0,data->heap);
    MANUAL_COMMON_InitDisplay(data);
    data->id=65535;
    MANUAL_COMMON_SetScreenId((char *)data,MANUAL_COMMON_GetDefaultId(data->assets));
    data->group=MANUAL_COMMON_CreateTouchbar((char *)data);
    return data;
}



void MANUAL_COMMON_DeleteData(char *data)
{
    MANUAL_COMMON_DeleteTouchbar(((struct ManualData *)data)->group);MANUAL_COMMON_SetScreenId(data,0xffff);MANUAL_COMMON_DataNoop(data);
    MANUAL_COMMON_DeleteMenuTable(((struct ManualData *)data)->assets);ARC_TOOL_DeleteHandle(((struct ManualData *)data)->arc0);ARC_TOOL_DeleteHandle(((struct ManualData *)data)->arc1);
    MSGDATA_Delete(*(struct Rec * *)&((struct ManualData *)data)->bank0);MSGDATA_Delete(*(struct Rec * *)&((struct ManualData *)data)->bank1);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)data)->printQue0);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct ManualData *)data)->printQue0);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)data)->printQue1);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct ManualData *)data)->printQue1);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)data)->printQue2);PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct ManualData *)data)->printQue2);
    GF_FONT_Delete((void *)((struct ManualData *)data)->font);MANUAL_GRAPHIC_DeleteScreen(*(char * *)&((struct ManualData *)data)->screen);func_020307B0(data);
}



void MANUAL_COMMON_DrawData(char *data){PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct ManualData *)data)->printQue0);PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct ManualData *)data)->printQue1);PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct ManualData *)data)->printQue2);MANUAL_GRAPHIC_DrawScreen(*(char * *)&((struct ManualData *)data)->screen);}



void MANUAL_COMMON_SetScreenId(char *data,unsigned id)
{
    if(((struct ManualData *)data)->id!=id) {
        unsigned size;
        void *buf;
        ((struct ManualData *)data)->id=id;
        if(((struct ManualData *)data)->id==0xffff) {
            buf=func_02030734(((struct ManualData *)data)->heap,0x18000,1,gManualCommonDataAllocFile,245);
            size=0x18000;
        } else {
            buf=ARC_UTIL_LoadHandleMemberWithSize(((struct ManualData *)data)->arc1,((struct ManualData *)data)->id,1,((struct ManualData *)data)->heap,&size);
        }
        DWCi_ScreenDC_FlushRange(buf,size);GX_LoadBG2Scr(buf,0,0x18000);func_020307B0(buf);
    }
}



/*
 * volatile: 021B9EEC,021B9EF8 re-read 0400000C;021B9F02 read 04000008.
 */
void MANUAL_COMMON_InitDisplay(void *unused){*(volatile unsigned short *)0x0400000C=(*(volatile unsigned short *)0x0400000C&0x43)|0x4084;*(volatile unsigned short *)0x0400000C=(unsigned short)(*(volatile unsigned short *)0x0400000C&~3);*(volatile unsigned short *)0x04000008&=~0x40;func_02040588(2,1);}



void MANUAL_COMMON_DataNoop(void *unused){}



void *MANUAL_COMMON_CreateTouchbar(char *owner)
{
    char *touchbar;
    func_02034AC4((int)ov067_id);
    touchbar=func_02030734(((struct ManualData *)owner)->heap,0x4c,1,gManualCommonTouchbarAllocFile,235);
    ((struct ManualTouchbar *)touchbar)->owner=owner;MANUAL_COMMON_CreateTouchbarWidget(touchbar);MANUAL_COMMON_TouchbarNoop(touchbar);MANUAL_COMMON_CreateTouchbarSlots(touchbar);MANUAL_COMMON_LoadTouchbarActors(touchbar);
    ((struct ManualTouchbar *)touchbar)->mode=4;touchbar[0xc]=0;touchbar[0xd]=0;MANUAL_COMMON_SetTouchbarState(touchbar,0);MANUAL_COMMON_ResetTouchbar(touchbar);
    ((struct ManualTouchbar *)touchbar)->task=func_020056A0((unsigned)MANUAL_COMMON_TouchbarTaskNoop,(unsigned)touchbar,1);
    return touchbar;
}



void MANUAL_COMMON_DeleteTouchbar(char *touchbar){func_02030EAC(((struct ManualTouchbar *)touchbar)->task);MANUAL_COMMON_DeleteTouchbarActors(touchbar);MANUAL_COMMON_DeleteTouchbarSlots(touchbar);TOUCHBAR_Delete(*(unsigned char * *)&((struct ManualTouchbar *)touchbar)->touchbar);func_020307B0(touchbar);func_02034A5C((int)ov067_id);}



void MANUAL_COMMON_UpdateTouchbar(char *touchbar)
{
    ((struct ManualTouchbar *)touchbar)->pressedId=-1;((struct ManualTouchbar *)touchbar)->releasedId=-1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
    if(((struct ManualTouchbar *)touchbar)->pressState==1) {((struct ManualTouchbar *)touchbar)->pressState=0;return;}
    if(((struct ManualTouchbar *)touchbar)->pressState==0 || ((struct ManualTouchbar *)touchbar)->pressState==2) {
        TOUCHBAR_Update(*(S * *)&((struct ManualTouchbar *)touchbar)->touchbar);
        if(((struct ManualTouchbar *)touchbar)->pressState==0) {
            int result=TOUCHBAR_GetPressedButtonIdIfPressing(*(u8 * *)&((struct ManualTouchbar *)touchbar)->touchbar);
            if(result!=-1) {((struct ManualTouchbar *)touchbar)->pressState=2;((struct ManualTouchbar *)touchbar)->pressedId=result;}
        } else {
            int result=TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct ManualTouchbar *)touchbar)->touchbar);
            if(result!=-1) {((struct ManualTouchbar *)touchbar)->pressState=1;((struct ManualTouchbar *)touchbar)->releasedId=result;}
        }
    }
    if(((struct ManualTouchbar *)touchbar)->pressState==0 || ((struct ManualTouchbar *)touchbar)->pressState==3) {
        MANUAL_COMMON_UpdateTouchbarActors(touchbar);
        if(((struct ManualTouchbar *)touchbar)->pressState==0) {
            if(((struct ManualTouchbar *)touchbar)->animState==1) {((struct ManualTouchbar *)touchbar)->pressState=3;*(unsigned *)&((struct ManualTouchbar *)touchbar)->pressedId=gManualCommonTouchbarButtonIds[*(u8 *)(touchbar+0x40)].word[0];}
        } else {
            if(((struct ManualTouchbar *)touchbar)->animState==3) {((struct ManualTouchbar *)touchbar)->pressState=1;*(unsigned *)&((struct ManualTouchbar *)touchbar)->releasedId=gManualCommonTouchbarButtonIds[*(u8 *)(touchbar+0x40)].word[0];}
        }
    }
}



void MANUAL_COMMON_SetTouchbarState(char *touchbar,unsigned state)
{
    if(((struct ManualTouchbar *)touchbar)->mode==state)return;
    switch(((struct ManualTouchbar *)touchbar)->mode) {
    case 0:TOUCHBAR_SetButtonVisible(((struct ManualTouchbar *)touchbar)->touchbar,0,0);break;
    case 3:CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor0,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor1,0);break;
    case 1:case 2:case 4:break;
    }
    ((struct ManualTouchbar *)touchbar)->mode=state;MANUAL_COMMON_ResetTouchbar(touchbar);
    switch(((struct ManualTouchbar *)touchbar)->mode) {
    case 0:TOUCHBAR_SetButtonVisible(((struct ManualTouchbar *)touchbar)->touchbar,0,1);MANUAL_COMMON_DrawTouchbarIdle(touchbar);break;
    case 1:MANUAL_COMMON_DrawTouchbarStart(touchbar);break;
    case 2:MANUAL_COMMON_DrawTouchbarEnd(touchbar);break;
    case 3:case 4:break;
    }
}



/*
 * trailing: 021BA152..021BA154 zero alignment padding, inspected in full show.
 */
void MANUAL_COMMON_SetTouchbarSelection(char *touchbar,unsigned count,unsigned selected)
{
    touchbar[0xc]=count;touchbar[0xd]=selected;
    if(((struct ManualTouchbar *)touchbar)->mode==3) {
        if(((struct ManualTouchbar *)touchbar)->selectX<=1) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor0,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor1,0);MANUAL_COMMON_DrawTouchbarIdle(touchbar);return;
        }
        if(((struct ManualTouchbar *)touchbar)->selectY==0) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor0,0);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor1,1);
        } else if(((struct ManualTouchbar *)touchbar)->selectY==count-1) {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor0,1);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor1,0);
        } else {
            CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor0,1);CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)touchbar)->actor1,1);
        }
        MANUAL_COMMON_DrawTouchbarContinue(touchbar);
    }
}



unsigned MANUAL_COMMON_GetTouchbarSelected(char *touchbar){return ((struct ManualTouchbar *)touchbar)->releasedId;}



unsigned MANUAL_COMMON_GetTouchbarPressed(char *touchbar){return ((struct ManualTouchbar *)touchbar)->pressedId;}



void MANUAL_COMMON_TouchbarTaskNoop(void *task,void *data)
{
}



/*
 * lever: args before gManualGraphicMainBgLayerTable declaration puts the 64-byte copy at sp+0.
 */
void MANUAL_COMMON_CreateTouchbarWidget(char *touchbar)
{
    ManualTouchbarArgs args;
    struct ManualBgTable gManualGraphicMainBgLayerTable=gManualCommonTouchbarBgTable;
    MI_CpuFill8(&args,0,sizeof(args));
    args.bgTable=(u8 *)&gManualGraphicMainBgLayerTable;args.layer=2;
    args.clactUnit=(int)MANUAL_GRAPHIC_GetClactUnit(((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->screen);
    args.cellW=6;args.cellH=3;args.flags=1;args.reserved18=0;
    *(struct ManualRes * *)&((struct ManualTouchbar *)touchbar)->touchbar=TOUCHBAR_Create(&args,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    TOUCHBAR_SetButtonVisible(((struct ManualTouchbar *)touchbar)->touchbar,0,0);
}



void MANUAL_COMMON_TouchbarNoop(void *unused){}



void MANUAL_COMMON_CreateTouchbarSlots(char *touchbar)
{
    u8 i;
    for(i=0;i<2;i++) {
        const struct ManualBmpParams *t=&gManualCommonSlotRecords[i];
        *(unsigned *)(touchbar+i*4+0x10)=BMP_WIN_Create(t->layer,t->baseX,t->baseY,t->tiles,t->palette,t->mode,t->slot);
        BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor **)(touchbar+i*4+0x10)),0);
        BMP_WIN_TransferChars(*(struct Descriptor **)(touchbar+i*4+0x10));
        *(unsigned *)(touchbar+i*4+0x18)=0;
    }
}



void MANUAL_COMMON_DeleteTouchbarSlots(char *touchbar){unsigned char i;PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2);for(i=0;i<2;i++){*(unsigned *)((unsigned)touchbar+i*4+24)=0;BMP_WIN_Delete(*(struct Descriptor **)((unsigned)touchbar+i*4+16));}}



void MANUAL_COMMON_UpdateTouchbarSlots(char *touchbar)
{
    u8 i;
    for(i=0;i<2;i++) {
        if(*(unsigned *)(touchbar+i*4+0x18)!=0) {
            if(PRINTSYS_QUE_IsExistTarget(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2,BMP_WIN_GetBmp(*(struct Descriptor **)(touchbar+i*4+0x10)))==0) {
                struct Descriptor *d=*(struct Descriptor **)(touchbar+i*4+0x10);
                BMP_WIN_TransferChars(d);BMP_WIN_MakeScreen((struct Cfg *)d);
                func_02041B6C(BMP_WIN_GetBgLayer(d));
                *(unsigned *)(touchbar+i*4+0x18)=0;
            }
        }
    }
}



void MANUAL_COMMON_DrawTouchbarIdle(char *touchbar){PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2);BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0);BMP_WIN_TransferChars(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0);((struct ManualTouchbar *)touchbar)->bmp0Dirty=0;}



void MANUAL_COMMON_DrawTouchbarStart(char *touchbar)
{
    void *s;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->bank0,2);
    PRINTSYS_PrintQueColor((void *)((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2,(unsigned)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0,4,(unsigned)s,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->font,0x3c40);
    STRBUF_Delete(s);((struct ManualTouchbar *)touchbar)->bmp0Dirty=1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
}



void MANUAL_COMMON_DrawTouchbarEnd(char *touchbar)
{
    void *s;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0);
    s=func_02045EC0(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->bank0,3);
    PRINTSYS_PrintQueColor((void *)((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2,(unsigned)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0,4,(unsigned)s,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->font,0x3c40);
    STRBUF_Delete(s);((struct ManualTouchbar *)touchbar)->bmp0Dirty=1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
}



/*
 * extent: 178 compiled bytes followed by two zero alignment bytes at 021BA41A.
 */
void MANUAL_COMMON_DrawTouchbarContinue(char *touchbar)
{
    struct WordSet *words;
    struct U16Vec *str;
    void *slot;
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2);
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),0);
    words=WORDSET_CreateDefault(((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    slot=func_02045EC0(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->bank0,4);
    str=STRBUF_Create(16,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    WORDSET_SetSlotNumber(words,0,((struct ManualTouchbar *)touchbar)->selectY+1,1,0,1);
    WORDSET_SetSlotNumber(words,1,((struct ManualTouchbar *)touchbar)->selectX,1,0,1);
    WORDSET_CopyTaggedText(words,str,slot);
    PRINTSYS_PrintQueColor((void *)((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->printQue2,(u32)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct ManualTouchbar *)touchbar)->bmp0),32,4,(u32)str,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->font,0x3c40);
    STRBUF_Delete(str);STRBUF_Delete(slot);WORDSET_DeleteStrbufED04(words);
    ((struct ManualTouchbar *)touchbar)->bmp0Dirty=1;MANUAL_COMMON_UpdateTouchbarSlots(touchbar);
}



void MANUAL_COMMON_LoadTouchbarActors(char *touchbar)
{
    u8 i;
    void *loader;
    u32 first;
    loader=func_020490F4(APP_ICON_GetArchiveId(),((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    *(int *)&((struct ManualTouchbar *)touchbar)->animCharacter=CLACT_RegisterPaletteEx((void *)((u32)loader),APP_ICON_GetMoveKindPaletteFileId(),1,128,0,3,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    *(int *)&((struct ManualTouchbar *)touchbar)->animPalette=CLACT_RegisterCharacter((void *)((u32)loader),APP_ICON_GetMoveKindAnimFileId(),0,1,((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    first=APP_ICON_GetStatusCellFileId(0);
    *(int *)&((struct ManualTouchbar *)touchbar)->animCell=CLACT_RegisterCellAnim((void *)((u32)loader),first,APP_ICON_GetStatusPaletteFileId(0),((struct ManualData *)(*(char * *)&((struct ManualTouchbar *)touchbar)->owner))->heap);
    ARC_TOOL_DeleteHandle(loader);
    for(i=0;i<2;i++) {
        char *parent=*(char * *)&((struct ManualTouchbar *)touchbar)->owner;
        char *dest=touchbar+i*4;
        *(struct Obj * *)&((struct ManualTouchbar *)dest)->actor0=CLACT_CreateActor((void *)MANUAL_GRAPHIC_GetClactUnit(((struct ManualData *)parent)->screen),((struct ManualTouchbar *)touchbar)->animPalette,((struct ManualTouchbar *)touchbar)->animCharacter,((struct ManualTouchbar *)touchbar)->animCell,&gManualCommonActorEntries[i],1,((struct ManualData *)parent)->heap);
        CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct ManualTouchbar *)dest)->actor0,0);
        CLACT_SetActorAutoAnim(*(struct Obj * *)&((struct ManualTouchbar *)dest)->actor0,1);
    }
}



void MANUAL_COMMON_DeleteTouchbarActors(char *touchbar) { u8 i; for(i=0;i<2;i++) CLACT_DeleteActor(*(struct Obj **)(touchbar+i*4+0x38)); CLACT_ReleaseCellAnim(((struct ManualTouchbar *)touchbar)->animCell); CLACT_ReleaseCharacter(((struct ManualTouchbar *)touchbar)->animPalette); CLACT_ReleasePalette(((struct ManualTouchbar *)touchbar)->animCharacter); }



void MANUAL_COMMON_UpdateTouchbarActors(char *touchbar)
{
 u8 i;
 u32 found,x,y;
 const struct ManualActorEntry *row;
 switch(((struct ManualTouchbar *)touchbar)->animState) {
 case 0:
  found=0;
  for(i=0;i<2;i++) {
   if(CLACT_GetActorDrawEnable(*(struct Obj **)(touchbar+i*4+0x38))) {
    row=&gManualCommonActorEntries[i];
    if(KEY_GetRepeat()&row->mask) {
     ((struct ManualTouchbar *)touchbar)->focusIndex=i;
     func_020355D8(0);
     found=1;
     break;
    }
    if(TOUCHPANEL_GetPointTrg(&x,&y)) {
     if(row->left<=x && x<=row->right && row->top<=y && y<=row->bottom) {
      ((struct ManualTouchbar *)touchbar)->focusIndex=i;
      found=1;
      func_020355D8(1);
      break;
     }
    }
   }
  }
  if(found) {
   CLACT_SetActorAnimSeq(*(struct Obj **)(touchbar+((struct ManualTouchbar *)touchbar)->focusIndex*4+0x38),gManualCommonActorEntries[*(u8 *)(touchbar+0x40)].active);
   if(gManualCommonActorEntries[*(u8 *)(touchbar+0x40)].sound) GFL_USE_PlaySeDefaultVolume(gManualCommonActorEntries[*(u8 *)(touchbar+0x40)].sound);
   ((struct ManualTouchbar *)touchbar)->animState=1;
  }
  break;
 case 1: ((struct ManualTouchbar *)touchbar)->animState=2; break;
 case 2:
  if(!CLACT_IsActorAnimActive(*(struct Actor **)(touchbar+((struct ManualTouchbar *)touchbar)->focusIndex*4+0x38))) {
   CLACT_SetActorAnimSeq(*(struct Obj **)(touchbar+((struct ManualTouchbar *)touchbar)->focusIndex*4+0x38),gManualCommonActorEntries[*(u8 *)(touchbar+0x40)].normal);
   ((struct ManualTouchbar *)touchbar)->animState=3;
  }
  break;
 case 3: ((struct ManualTouchbar *)touchbar)->animState=0; ((struct ManualTouchbar *)touchbar)->focusIndex=255; break;
 }
}




void MANUAL_COMMON_ResetTouchbar(char *touchbar)
{
    int z = 0;
    int m = z - 1;
    *(int *)(touchbar + 0x20) = z;
    *(int *)(touchbar + 0x24) = m;
    *(int *)(touchbar + 0x28) = m;
    *(u8 *)(touchbar + 0x40) = 0xFF;
    *(int *)(touchbar + 0x44) = z;
}



void *MANUAL_COMMON_CreateListWork(char *owner, struct ManualData *data)
{
  struct ManualListWork *work;
  struct ManualClactPos pos;
  u8 index;
  u32 flag;
  u32 state;
  int count;
  s16 y;
  int mode;
  work = func_02030734(data->heap, 0x98, 1, gManualCommonListWorkAllocFile, 0xdf);
  work->owner = owner;
  *((u32 *) (owner + 0x10)) = 0;
  work->data = data;
  index = 0;
  do
  {
    work->win[index] = 0;
    work->slotFlag[index] = 0;
    index++;
  }
  while (index < 8);
  work->listReady = 0;
  MANUAL_COMMON_LoadListWorkAssets((char *)work);
  MANUAL_COMMON_SetListWorkBgMode(work);
  BG_SYS_ResetSlot(5, 3, 12);
  flag = 0;
  if ((*((u16 *) (work->owner + 4))) > 6)
    flag = 1;
  CLACT_SetActorDrawEnable(work->actor, flag);
  count = MANUAL_COMMON_GetScrollTop((u16 **) work);
  count = count + 1;
  y = MANUAL_COMMON_IndexToY(work, count, *((u16 *) (work->owner + 0xc)));
  pos.x = 240;
  pos.y = y;
  CLACT_AddActorSurfacePos(work->actor, (const struct ManualClactPos *)&pos, 1);
  work->task = func_020056A0((u32) MANUAL_COMMON_ListWorkTaskNoop, (u32) work, 1);
  work->state = 0;
  work->dragging = 0;
  work->dirty = 0;
  work->timer = -1;
  mode = *((int *) work->owner);
  state = 2;
  if (mode == 0)
    state = 1;
  else
    if (mode == 1)
    state = 2;
  MANUAL_COMMON_SetTouchbarState(*((char **) (((char *) work->data) + 0x34)), state);
  return work;
}




void MANUAL_COMMON_DeleteListWork(char *work)
{
    func_02030EAC(((struct ManualListWork *)work)->task);
    BG_SYS_ResetSlot(5, 3, 0);
    func_020307B0(work);
}



/*
 * extent: lead 308 bytes; empty callback at 021BA894 and two zero alignment bytes.
 * arity: 02028178 retains original r1 payload despite unused input in its body.
 */
int MANUAL_COMMON_UpdateListWork(char *work)
{
 u8 i;
 int result=0;
 unsigned selected;
 if(!PRINTSYS_QUE_IsFinished(*(const struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->printQue1)) return 0;
 if(((struct ManualListWork *)work)->timer==0) result=1;
 else if(((struct ManualListWork *)work)->timer>0) {
  if(((struct ManualListWork *)work)->timer==1) MANUAL_COMMON_DeleteListWorkAssets(work);
  (((struct ManualListWork *)work)->timer)--;
 }
 if(((struct ManualListWork *)work)->state!=1) {
  for(i=0;i<8;i++) {
   if(*(u8 **)(work+i*4+0xc) && *(void **)(work+i*4+0x2c))
    APP_TASKMENU_WIN_Update(*(u8 **)(work+i*4+0xc));
  }
 }
 if(((struct ManualListWork *)work)->state==0 || ((struct ManualListWork *)work)->state==2) {
  if(MANUAL_COMMON_UpdateListWorkDrag(work)) ((struct ManualListWork *)work)->state=2;
  else ((struct ManualListWork *)work)->state=0;
 }
 if(((struct ManualListWork *)work)->state==0 || ((struct ManualListWork *)work)->state==3) {
  MANUAL_COMMON_UpdateTouchbar(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->group);
  if(((struct ManualListWork *)work)->state==0) {
   if(MANUAL_COMMON_GetTouchbarPressed(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->group)!=(unsigned)-1) ((struct ManualListWork *)work)->state=3;
  } else {
   selected=MANUAL_COMMON_GetTouchbarSelected(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->group);
   if(selected!=(unsigned)-1) {
    if(selected==1) ((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->owner))->printQue0=0;
    ((struct ManualListWork *)work)->state=1;
    ((struct ManualListWork *)work)->timer=1;
   }
  }
 }
 if(((struct ManualListWork *)work)->state==0 || ((struct ManualListWork *)work)->state==4) {
  if(((struct ManualListWork *)work)->state==0) {
   if(MANUAL_COMMON_UpdateListWorkInput(work)) ((struct ManualListWork *)work)->state=4;
  } else {
   if(APP_TASKMENU_WIN_IsFinish(*(u8 **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc))) {
    ((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->owner))->printQue0=1;
    ((struct ManualListWork *)work)->state=1;
    ((struct ManualListWork *)work)->timer=1;
   }
  }
 }
 return result;
}




void MANUAL_COMMON_ListWorkTaskNoop(void) {}



/*
 * Lever: index before 0x60 keeps field offset in immediate; distinct loop
 * parent local restores r7 parent / r6 destination allocation.
 */
void MANUAL_COMMON_LoadListWorkAssets(char *work)
{
    struct ManualQuad quad[2];
    u8 i;
    char *parent;
    func_02049B68(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc0,0,4,0,0x40,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    func_02049658(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc0,2,4,0,0,0,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    ARC_UTIL_UploadBgPaletteAddFromHandleExt(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc0,5,4,0,0,0,0,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    *(int *)&((struct ManualListWork *)work)->reg1=CLACT_RegisterPaletteEx(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc0,1,1,0,0,1,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    *(int *)&((struct ManualListWork *)work)->reg0=CLACT_RegisterCharacter(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc0,3,0,1,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    *(int *)&((struct ManualListWork *)work)->reg2=CLACT_RegisterCellAnim(((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->arc0,7,8,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    quad[1]=gManualCommonListHeadPos;
    parent=*(char * *)&((struct ManualListWork *)work)->data;
    ((struct ManualListWork *)work)->actor=CLACT_CreateActor((void *)MANUAL_GRAPHIC_GetClactUnit(((struct ManualData *)parent)->screen),((struct ManualListWork *)work)->reg0,((struct ManualListWork *)work)->reg1,((struct ManualListWork *)work)->reg2,&quad[1],1,((struct ManualData *)parent)->heap);
    CLACT_SetActorDrawEnable(((struct ManualListWork *)work)->actor,0);
    CLACT_SetActorAutoAnim(((struct ManualListWork *)work)->actor,1);
    quad[0]=gManualCommonListRowPos;
    for(i=0;i<8;i++) {
        char *loopparent;
        quad[0].y=i*24-8;
        loopparent=*(char * *)&((struct ManualListWork *)work)->data;
        *(void **)(work+i*4+0x60)=CLACT_CreateActor((void *)MANUAL_GRAPHIC_GetClactUnit(((struct ManualData *)loopparent)->screen),((struct ManualListWork *)work)->reg0,((struct ManualListWork *)work)->reg1,((struct ManualListWork *)work)->reg2,&quad[0],1,((struct ManualData *)loopparent)->heap);
        CLACT_SetActorDrawEnable(*(void **)(work+i*4+0x60),0);
        CLACT_SetActorAutoAnim(*(void **)(work+i*4+0x60),1);
    }
    MANUAL_COMMON_CreateListWorkMenu(work);
}



void MANUAL_COMMON_CreateListWorkMenu(char *work)
{
    BG_SYS_FreeSlot(5);
    *(struct ManualRes * *)&((struct ManualListWork *)work)->resource = APP_TASKMENU_RES_Create(5, 4, ((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->font, ((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->printQue1, ((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
    ((struct ManualListWork *)work)->field4C = 0x1ce7;
    func_02061CA4((void *)31, 154, work + 0x4c, 2);
    func_02061CA4((void *)31, 186, work + 0x4c, 2);
    MANUAL_COMMON_RebuildListWindows(work);
    if (func_020355C4() == 0) {
        APP_TASKMENU_WIN_SetActive(*(struct Obj **)(work + MANUAL_COMMON_GetCursorIndex((u16 **)work) * 4 + 0xc), 1);
        ((struct ManualListWork *)work)->dirty = 0;
    }
}




void MANUAL_COMMON_SetListWorkBgMode(struct ManualListWork *work) { BG_SYS_SetFlagField06(4); }



void MANUAL_COMMON_DeleteListWorkAssets(char *work) { u8 i; MANUAL_COMMON_DeleteListWorkMenu(work); for(i=0;i<8;i++) CLACT_DeleteActor(*(struct Obj **)(work+i*4+0x60)); CLACT_DeleteActor(*(struct Obj * *)&((struct ManualListWork *)work)->actor); CLACT_ReleaseCellAnim(((struct ManualListWork *)work)->reg2); CLACT_ReleaseCharacter(((struct ManualListWork *)work)->reg0); CLACT_ReleasePalette(((struct ManualListWork *)work)->reg1); }



void MANUAL_COMMON_DeleteListWorkMenu(char *work) { u8 i; PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->printQue1); for(i=0;i<8;i++) if(*(u8 **)(work+i*4+12)) APP_TASKMENU_WIN_Delete(*(u8 **)(work+i*4+12)); APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct ManualListWork *)work)->resource); BG_SYS_SetFlagField06(5); }



int MANUAL_COMMON_UpdateListWorkInput(char *work)
{
    u8 rect[28];
    struct ManualPoint delta[4];
    int hit;
    u16 count,last,y;
    MANUAL_COMMON_BuildListRects(rect);
    hit=TOUCHPANEL_HitTrg(rect);
    count=MANUAL_COMMON_GetVisibleCount((u16 **)work);
    last=MANUAL_COMMON_GetLastVisible((u16 **)work);
    if(func_020355C4()==0) {
        if(hit>=0 && hit<count) {
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),0);
        }
    } else {
        if(KEY_GetTrg()!=0 && !(KEY_GetTrg()&2)) {
            func_020355D8(0);
            APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),1);
            ((struct ManualListWork *)work)->dirty=0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 0;
        }
    }
    if(func_020355C4()==0) {
        if(KEY_GetTrg()&1) {
            APP_TASKMENU_WIN_SetDecide(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return 1;
        }
        if((*(struct ManualListState **)work)->count>1) {
            if(KEY_GetRepeat()&0x40) {
                APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),0);
                if((*(struct ManualListState **)work)->selected>(*(struct ManualListState **)work)->top) (*(struct ManualListState **)work)->selected--;
                else if((*(struct ManualListState **)work)->count<=6) (*(struct ManualListState **)work)->selected=(*(struct ManualListState **)work)->count-1;
                else {
                    if((*(struct ManualListState **)work)->selected!=0) {
                        (*(struct ManualListState **)work)->top--;
                        (*(struct ManualListState **)work)->selected--;
                    } else {
                        (*(struct ManualListState **)work)->top=MANUAL_COMMON_GetScrollTop((u16 **)work);
                        (*(struct ManualListState **)work)->selected=(*(struct ManualListState **)work)->count-1;
                    }
                    MANUAL_COMMON_RebuildListWindows(work);
                    y=MANUAL_COMMON_IndexToY(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(*(struct ManualListState **)work)->top);
                    delta[3].x=240;
                    delta[3].y=y;
                    CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct ManualListWork *)work)->actor, (const struct ManualClactPos *)(&delta[3]), 1);
                }
                APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),1);
                ((struct ManualListWork *)work)->dirty=0;
                GFL_USE_PlaySeDefaultVolume(0x548);
            } else if(KEY_GetRepeat()&0x80) {
                APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),0);
                if((*(struct ManualListState **)work)->selected<last) (*(struct ManualListState **)work)->selected++;
                else if((*(struct ManualListState **)work)->count<=6) (*(struct ManualListState **)work)->selected=0;
                else {
                    if((*(struct ManualListState **)work)->selected<(*(struct ManualListState **)work)->count-1) {
                        (*(struct ManualListState **)work)->top++;
                        (*(struct ManualListState **)work)->selected++;
                    } else {(*(struct ManualListState **)work)->top=0;(*(struct ManualListState **)work)->selected=0;}
                    MANUAL_COMMON_RebuildListWindows(work);
                    y=MANUAL_COMMON_IndexToY(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(*(struct ManualListState **)work)->top);
                    delta[2].x=240;
                    delta[2].y=y;
                    CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct ManualListWork *)work)->actor, (const struct ManualClactPos *)(&delta[2]), 1);
                }
                APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),1);
                ((struct ManualListWork *)work)->dirty=0;
                GFL_USE_PlaySeDefaultVolume(0x548);
            } else if(KEY_GetRepeat()&0x220) {
                if((*(struct ManualListState **)work)->selected!=0) {
                    APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),0);
                    if((*(struct ManualListState **)work)->count<=6) (*(struct ManualListState **)work)->selected=0;
                    else {
                        if((*(struct ManualListState **)work)->top>=6) {(*(struct ManualListState **)work)->top-=6;(*(struct ManualListState **)work)->selected-=6;}
                        else {(*(struct ManualListState **)work)->top=0;if((*(struct ManualListState **)work)->selected>=6) (*(struct ManualListState **)work)->selected-=6;else (*(struct ManualListState **)work)->selected=0;}
                        MANUAL_COMMON_RebuildListWindows(work);
                        y=MANUAL_COMMON_IndexToY(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(*(struct ManualListState **)work)->top);
                        delta[1].x=240;
                        delta[1].y=y;
                        CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct ManualListWork *)work)->actor, (const struct ManualClactPos *)(&delta[1]), 1);
                    }
                    APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),1);
                    ((struct ManualListWork *)work)->dirty=0;
                    GFL_USE_PlaySeDefaultVolume(0x548);
                }
            } else if(KEY_GetRepeat()&0x110) {
                if((*(struct ManualListState **)work)->selected<(*(struct ManualListState **)work)->count-1) {
                    APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),0);
                    if((*(struct ManualListState **)work)->count<=6) (*(struct ManualListState **)work)->selected=(*(struct ManualListState **)work)->count-1;
                    else {
                        (*(struct ManualListState **)work)->top+=6;
                        if((*(struct ManualListState **)work)->top>MANUAL_COMMON_GetScrollTop((u16 **)work)) (*(struct ManualListState **)work)->top=MANUAL_COMMON_GetScrollTop((u16 **)work);
                        (*(struct ManualListState **)work)->selected+=6;
                        if((*(struct ManualListState **)work)->selected>=(*(struct ManualListState **)work)->count) (*(struct ManualListState **)work)->selected=(*(struct ManualListState **)work)->count-1;
                        MANUAL_COMMON_RebuildListWindows(work);
                        y=MANUAL_COMMON_IndexToY(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(*(struct ManualListState **)work)->top);
                        delta[0].x=240;
                        delta[0].y=y;
                        CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct ManualListWork *)work)->actor, (const struct ManualClactPos *)(&delta[0]), 1);
                    }
                    APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),1);
                    ((struct ManualListWork *)work)->dirty=0;
                    GFL_USE_PlaySeDefaultVolume(0x548);
                }
            }
        }
    } else if(hit>=0 && hit<count) {
        (*(struct ManualListState **)work)->selected=(*(struct ManualListState **)work)->top+hit;
        APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),1);
        ((struct ManualListWork *)work)->dirty=0;
        APP_TASKMENU_WIN_SetDecide(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),1);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return 1;
    }
    return 0;
}



/*
 * Lever: initialise offset after cursor clear, letting zero schedule at
 * that call's argument setup rather than before the touch-mode setter.
 */
int MANUAL_COMMON_UpdateListWorkDrag(char *work)
{
    u32 dragx,dragy;
    struct ManualPoint drag;
    u32 clickx,clicky;
    struct ManualPoint click;
    if(CLACT_GetActorDrawEnable(*(struct Obj * *)&((struct ManualListWork *)work)->actor)==0) return 0;
    if(((struct ManualListWork *)work)->dragging) {
        if(TOUCHPANEL_GetPointCont(&dragx,&dragy)) {
            int offset;
            u16 selection,end;
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),0);
            offset=0;
            drag.x=240;
            if(dragy>=8) offset=dragy-8;
            drag.y=offset;
            if(drag.y<17) drag.y=17;
            else if(drag.y>135) drag.y=135;
            CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct ManualListWork *)work)->actor, (const struct ManualClactPos *)&drag, 1);
            selection=MANUAL_COMMON_HitToIndex(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(u16)dragy);
            if(selection!=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top) {
                ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top=selection;
                end=MANUAL_COMMON_GetLastVisible((u16 **)work);
                if(((struct ManualListWork *)work)->dirty || ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected<((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top || end<((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected) {
                    ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top;
                    ((struct ManualListWork *)work)->dirty=1;
                }
                MANUAL_COMMON_RebuildListWindows(work);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        } else ((struct ManualListWork *)work)->dragging=0;
        return 1;
    } else {
        if(TOUCHPANEL_GetPointTrg(&clickx,&clicky) && clickx>=240 && clickx<=247 && clicky>=17 && clicky<=150) {
            int offset;
            u16 selection,end;
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(work+MANUAL_COMMON_GetCursorIndex((u16 **)work)*4+0xc),0);
            offset=0;
            GFL_USE_PlaySeDefaultVolume(0x548);
            ((struct ManualListWork *)work)->dragging=1;
            click.x=240;
            if(clicky>=8) offset=clicky-8;
            click.y=offset;
            if(click.y<17) click.y=17;
            else if(click.y>135) click.y=135;
            CLACT_AddActorSurfacePos(*(struct Obj * *)&((struct ManualListWork *)work)->actor, (const struct ManualClactPos *)&click, 1);
            selection=MANUAL_COMMON_HitToIndex(work,(u16)(MANUAL_COMMON_GetScrollTop((u16 **)work)+1),(u16)clicky);
            if(selection!=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top) {
                ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top=selection;
                end=MANUAL_COMMON_GetLastVisible((u16 **)work);
                if(((struct ManualListWork *)work)->dirty || ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected<((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top || end<((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected) {
                    ((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->selected=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top;
                    ((struct ManualListWork *)work)->dirty=1;
                }
                MANUAL_COMMON_RebuildListWindows(work);
            }
        }
        if(((struct ManualListWork *)work)->dragging) return 1;
        return 0;
    }
}



void MANUAL_COMMON_BuildListRects(u8 *rect) { u8 i; for(i=0;i<6;i++) { rect[i*4]=i*24+12; rect[i*4+1]=(i+1)*24+11; rect[i*4+2]=16; rect[i*4+3]=239; } rect[24]=255; rect[25]=0; rect[26]=0; rect[27]=0; }




u16 MANUAL_COMMON_GetCursorIndex(u16 **work)
{
    u16 *state = *work;
    return (u16)(state[7] - state[6] + 1);
}




u16 MANUAL_COMMON_GetLastVisible(u16 **work)
{
    u16 *state = *work;
    u16 limit = (u16)(state[6] + 5);
    u16 count = state[2];
    if (limit < count)
        return limit;
    return (u16)(count - 1);
}




u16 MANUAL_COMMON_GetVisibleCount(u16 **work)
{
    return (u16)(MANUAL_COMMON_GetLastVisible(work) - (*work)[6] + 1);
}




u16 MANUAL_COMMON_GetScrollTop(u16 **work)
{
    u16 count = (*work)[2];
    if (count <= 6)
        return 0;
    return (u16)(count - 6);
}



void MANUAL_COMMON_RebuildListWindows(char *work)
{
    struct ManualTaskEntry entry;
    u8 first,last,i;
    u16 index,end;
    first=0;
    index=(u16)(((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top-1);
    if (((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top==0) {
        if (*(u8 * *)&((struct ManualListWork *)work)->win[0]) {
            APP_TASKMENU_WIN_ClearScreen(*(u8 * *)&((struct ManualListWork *)work)->win[0]);
            ((struct ManualListWork *)work)->slotFlag[0]=0;
        }
        index=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->top;
        first=1;
        CLACT_SetActorDrawEnable(((struct ManualListWork *)work)->actorList[0],0);
    }
    end=(u16)(MANUAL_COMMON_GetLastVisible((u16 **)work)+1);
    if (end>=((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->count) end--;
    last=(u8)(first+end-index);
    for(i=last+1;i<=7;i++) {
        if (*(u8 **)(work+i*4+0xc)) {
            APP_TASKMENU_WIN_ClearScreen(*(u8 **)(work+i*4+0xc));
            *(u32 *)(work+i*4+0x2c)=0;
        }
        CLACT_SetActorDrawEnable(*(void **)(work+i*4+0x60),0);
    }
    for(i=first;i<=last;i++) {
        if (*(u8 **)(work+i*4+0xc)) APP_TASKMENU_WIN_DeleteNoClear();
        entry.resource=func_02045EC0(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->bank1,*(u16 *)(*(char * *)&((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->data+index*8+2));
        if(i==0 || i==7) entry.tag=0x3da3; else entry.tag=0x39e3;
        entry.flags=0;
        if(((struct ManualListWork *)work)->listReady)
            *(u32 **)(work+i*4+0xc)=APP_TASKMENU_WIN_CreateExNoScreen(*(u32 *)&((struct ManualListWork *)work)->resource,(u32)&entry,2,(u8)(i*3),28,3,0,0,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
        else
            *(u32 *)(work+i*4+0xc)=APP_TASKMENU_WIN_Create(*(u32 *)&((struct ManualListWork *)work)->resource,(u32)&entry,2,(u8)(i*3),28,((struct ManualData *)(*(char * *)&((struct ManualListWork *)work)->data))->heap);
        APP_TASKMENU_WIN_Update(*(u8 **)(work+i*4+0xc));
        *(u32 *)(work+i*4+0x2c)=1;
        STRBUF_Delete(entry.resource);
        if (*(u32 *)(*(char * *)&((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->data+index*8+4)==0)
            CLACT_SetActorDrawEnable(*(void **)(work+i*4+0x60),0);
        else if (*(u32 *)(*(char * *)&((struct ManualListState *)(*(char * *)&((struct ManualListWork *)work)->owner))->data+index*8+4)==1)
            CLACT_SetActorDrawEnable(*(void **)(work+i*4+0x60),1);
        index++;
    }
    ((struct ManualListWork *)work)->listReady=1;
}



u16 MANUAL_COMMON_HitToIndex(void *unused, u16 count, u16 value)
{
    u16 index, upper, lower;
    if (count <= 1) index = 0;
    else if (value < 25) index = 0;
    else if (value >= 144) index = count - 1;
    else {
        for (index = 0; index < count; index++) {
            upper = (119 * (index + 1)) / count + 25;
            lower = (119 * index) / count + 25;
            if (lower <= value && value < upper) break;
        }
    }
    if (index >= count) index = 0;
    return index;
}



/*
 * lever: narrow the average to u16 before subtracting 8; minimum clamp returns directly.
 * extent: 90 compiled bytes followed by two zero alignment bytes at 021BB2B2.
 */
u16 MANUAL_COMMON_IndexToY(void *unused, u16 count, u16 index)
{
    u16 result, low, high;
    if (index == 0) result = 17;
    else if (index == count - 1) result = 135;
    else {
        low = (119 * index) / count + 25;
        high = (119 * (index + 1)) / count + 25;
        result = (low + high) / 2;
        result -= 8;
    }
    if (result < 17) return 17;
    if (result > 135) result = 135;
    return result;
}



char *MANUAL_COMMON_CreateDialog(char *owner, char *data)
{
    char *dialog;
    dialog = func_02030734(((struct ManualData *)data)->heap, 32, 1, gManualCommonDialogAllocFile, 157);
    *(char * *)&((struct ManualDialog *)dialog)->owner = owner;
    ((struct ManualListBuffer *)owner)->choice = 1;
    *(char * *)&((struct ManualDialog *)dialog)->data = data;
    MANUAL_COMMON_LoadDialogAssets(dialog);
    MANUAL_COMMON_SetDialogBgMode(dialog);
    ((struct ManualDialog *)dialog)->task = func_020056A0((unsigned)MANUAL_COMMON_DialogTaskNoop, (unsigned)dialog, 1);
    ((struct ManualDialog *)dialog)->state = 0;
    dialog[0x1c] = -1;
    MANUAL_COMMON_SetTouchbarState(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->group, 0);
    return dialog;
}




void MANUAL_COMMON_DeleteDialog(char *dialog)
{
    func_02030EAC((struct Node *)(((struct ManualDialog *)dialog)->task));
    func_020307B0(dialog);
}



/*
 * Tail: 021BB3FA alignment, existing matched follower 021BB3FC.
 * Lever: switch body order 1 then 0 preserves the shared store block.
 */
int MANUAL_COMMON_UpdateDialog(char *dialog)
{
    int done = 0;
    u8 i;
    if (((struct ManualDialog *)dialog)->timer==0) done=1;
    else if (((struct ManualDialog *)dialog)->timer>0) {
        if (((struct ManualDialog *)dialog)->timer==1) MANUAL_COMMON_DeleteDialogStep(dialog);
        --((struct ManualDialog *)dialog)->timer;
    }
    if (((struct ManualDialog *)dialog)->state==0 || ((struct ManualDialog *)dialog)->state==2) {
        MANUAL_COMMON_UpdateTouchbar(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->group);
        if (((struct ManualDialog *)dialog)->state==0) {
            if (MANUAL_COMMON_GetTouchbarPressed(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->group)!=-1)
                ((struct ManualDialog *)dialog)->state=2;
        } else {
            int result=MANUAL_COMMON_GetTouchbarSelected(*(char * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->group);
            if (result!=-1) {
                switch (result) {
                case 1: ((struct ManualListBuffer *)(*(char * *)&((struct ManualDialog *)dialog)->owner))->choice=1; break;
                case 0: ((struct ManualListBuffer *)(*(char * *)&((struct ManualDialog *)dialog)->owner))->choice=0; break;
                }
                ((struct ManualDialog *)dialog)->state=1;
                ((struct ManualDialog *)dialog)->timer=1;
            }
        }
    }
    if (((struct ManualDialog *)dialog)->state==0 || ((struct ManualDialog *)dialog)->state==3) {
        for (i=0;i<2;i++) APP_TASKMENU_WIN_Update((u8 *)(*(char **)(dialog+0xc+i*4)));
        if (((struct ManualDialog *)dialog)->state==0) {
            if (MANUAL_COMMON_UpdateDialogInput(dialog)) ((struct ManualDialog *)dialog)->state=3;
        } else {
            if (APP_TASKMENU_WIN_IsFinish((u8 *)(*(char **)(dialog+0xc+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4)))) {
                unsigned value;
                if (**(u8 * *)&((struct ManualDialog *)dialog)->owner==0) value=2;
                else if (**(u8 * *)&((struct ManualDialog *)dialog)->owner==1) value=3;
                else goto finish;
                ((struct ManualListBuffer *)(*(char * *)&((struct ManualDialog *)dialog)->owner))->choice=value;
finish:
                ((struct ManualDialog *)dialog)->state=1;
                ((struct ManualDialog *)dialog)->timer=1;
            }
        }
    }
    return done;
}



void MANUAL_COMMON_DialogTaskNoop(void *unused)
{
}



/*
 * extent: 86 compiled bytes followed by two zero alignment bytes at 021BB456.
 */
void MANUAL_COMMON_LoadDialogAssets(char *dialog)
{
    func_02049B68((void *)(((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->arc0), 0, 4, 0, 64, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->heap);
    func_02049658((void *)(((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->arc0), 2, 4, 0, 0, 0, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->heap);
    ARC_UTIL_UploadBgPaletteAddFromHandleExt((void *)(((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->arc0), 4, 4, 0, 0, 0, 0, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->heap);
    MANUAL_COMMON_CreateDialogWindows(dialog);
}



void MANUAL_COMMON_CreateDialogWindows(char *dialog)
{
    struct ManualTaskEntry entries[2];
    u8 i;
    *(struct ManualRes * *)&((struct ManualDialog *)dialog)->resource = APP_TASKMENU_RES_Create(5, 4, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->font, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->printQue1, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->heap);
    entries[0].resource = func_02045EC0(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->bank0, 0);
    entries[0].tag = 0x39e3;
    entries[0].flags = 0;
    entries[1].resource = func_02045EC0(*(struct MsgBank * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->bank0, 1);
    entries[1].tag = 0x39e3;
    entries[1].flags = 0;
    for (i = 0; i < 2; i++) {
        *(unsigned *)(dialog + i * 4 + 0xc) = APP_TASKMENU_WIN_Create(*(unsigned *)&((struct ManualDialog *)dialog)->resource, (unsigned)&entries[i], 1, (u8)((i + 1) * 3), 30, ((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->heap);
        STRBUF_Delete(entries[i].resource);
    }
    if (func_020355C4() == 0) APP_TASKMENU_WIN_SetActive(*(struct Obj **)(dialog + *(u8 *)*(char * *)&((struct ManualDialog *)dialog)->owner * 4 + 0xc), 1);
}



void MANUAL_COMMON_SetDialogBgMode(char *dialog) { BG_SYS_SetFlagField06(4); }



void MANUAL_COMMON_DeleteDialogStep(char *dialog) { MANUAL_COMMON_DeleteDialogWindows(dialog); }



void MANUAL_COMMON_DeleteDialogWindows(char *dialog) { u8 i; PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct ManualData *)(*(char * *)&((struct ManualDialog *)dialog)->data))->printQue1); for(i=0;i<2;i++) APP_TASKMENU_WIN_Delete(*(u8 **)(dialog+i*4+12)); APP_TASKMENU_RES_Delete(*(struct TaskMenuState * *)&((struct ManualDialog *)dialog)->resource); BG_SYS_SetFlagField06(5); }



/*
 * Lever: unhinted BF9C data uses this function's own overlay region.
 */
int MANUAL_COMMON_UpdateDialogInput(char *dialog)
{
    int hit=TOUCHPANEL_HitTrg(gManualCommonDialogHitRects);
    if(func_020355C4()==0) {
        if(hit>=0 && hit<=1) {
            func_020355D8(1);
            APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),0);
        }
    } else {
        if(KEY_GetTrg()!=0 && !(KEY_GetTrg()&0x402)) {
            func_020355D8(0);
            APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x548);
            return 0;
        }
    }
    if(func_020355C4()==0) {
        if(KEY_GetTrg()&1) {
            APP_TASKMENU_WIN_SetDecide(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            return 1;
        } else if(KEY_GetRepeat()&0x40) {
            APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),0);
            if(**(u8 * *)&((struct ManualDialog *)dialog)->owner==0) **(u8 * *)&((struct ManualDialog *)dialog)->owner=1; else **(u8 * *)&((struct ManualDialog *)dialog)->owner=0;
            APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x548);
        } else if(KEY_GetRepeat()&0x80) {
            APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),0);
            if(**(u8 * *)&((struct ManualDialog *)dialog)->owner==1) **(u8 * *)&((struct ManualDialog *)dialog)->owner=0; else **(u8 * *)&((struct ManualDialog *)dialog)->owner=1;
            APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),1);
            GFL_USE_PlaySeDefaultVolume(0x548);
        } else if(KEY_GetRepeat()&0x220) {
            if(**(u8 * *)&((struct ManualDialog *)dialog)->owner==1) {
                APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),0);
                **(u8 * *)&((struct ManualDialog *)dialog)->owner=0;
                APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),1);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        } else if(KEY_GetRepeat()&0x110) {
            if(**(u8 * *)&((struct ManualDialog *)dialog)->owner==0) {
                APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),0);
                **(u8 * *)&((struct ManualDialog *)dialog)->owner=1;
                APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),1);
                GFL_USE_PlaySeDefaultVolume(0x548);
            }
        }
    } else if(hit>=0 && hit<=1) {
        **(u8 * *)&((struct ManualDialog *)dialog)->owner=hit;
        APP_TASKMENU_WIN_SetActive(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),1);
        APP_TASKMENU_WIN_SetDecide(*(void **)(dialog+**(u8 * *)&((struct ManualDialog *)dialog)->owner*4+0xc),1);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        return 1;
    }
    return 0;
}
