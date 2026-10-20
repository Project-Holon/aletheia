/*
 * file:     btl_rec_sel.c
 * unit:     yes
 * function: BTL_REC_SEL_Create, BTL_REC_SEL_Delete, BTL_REC_SEL_Main, BTL_REC_SEL_StartFade, BTL_REC_SEL_StartEntryA, BTL_REC_SEL_SetEntryA, BTL_REC_SEL_StartEntryB, BTL_REC_SEL_SetEntryB, BTL_REC_SEL_VBlank, BTL_REC_SEL_InitWindows, BTL_REC_SEL_DeleteWindows, BTL_REC_SEL_MainTcbl, BTL_REC_SEL_DrawWindow, BTL_REC_SEL_DrawWindowBorder, BTL_REC_SEL_ClearWindowWhite, BTL_REC_SEL_ClearWindowClear, BTL_REC_SEL_PrintEntry, BTL_REC_SEL_WaitPrint, BTL_REC_SEL_PrintStep, BTL_REC_SEL_PrintQueEntry, BTL_REC_SEL_TryShowEntry, BTL_REC_SEL_InitPalette, BTL_REC_SEL_Noop, BTL_REC_SEL_CreateYesNo, BTL_REC_SEL_CreateWindows, BTL_REC_SEL_DeleteWindowList, BTL_REC_SEL_TickTimer, BTL_REC_SEL_ShowWindows, BTL_REC_SEL_PrintList, BTL_REC_SEL_ClearList, BTL_REC_SEL_StartTimer, BTL_REC_SEL_ResetTimer, BTL_REC_SEL_DrawCounter, BTL_REC_SEL_InitCells, BTL_REC_SEL_DeleteCellActors, BTL_REC_SEL_CreateActor, BTL_REC_SEL_DeleteActor, BTL_REC_SEL_SetMode, BTL_REC_SEL_InitBgRun, BTL_REC_SEL_DeleteBgRun, BTL_REC_SEL_InitBgGfx1, BTL_REC_SEL_InitBgGfx2, BTL_REC_SEL_InitBgGfx3, BTL_REC_SEL_ClearLayer, BTL_REC_SEL_InitSubBg, BTL_REC_SEL_DeleteSubBg, BTL_REC_SEL_CreateUiActor, BTL_REC_SEL_DeleteUiActor, BTL_REC_SEL_InitPalanm, BTL_REC_SEL_DeletePalanm, BTL_REC_SEL_FadeMain, BTL_REC_SEL_TransferPalettes, BTL_REC_SEL_InitG3dDisplay
 * address:  0x021B95A0
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BTL_REC_SEL_GRAPHIC_Create 0x021BB178 thumb ov214
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   GAME_DATA_GetMyItem 0x0201292C thumb
 *   MYITEM_SAVEDATA_HasItem 0x02007F68 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   BG_SYS_SetPriority 0x0204047C arm
 *   BG_SYS_LoadPlttEntry 0x02040EBC arm
 *   FADE_Start 0x0204E720 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   ov67_id 0x00000043 data a1
 *   MSGDATA_Delete 0x02045C04 arm
 *   TCB_DeleteTask 0x02030EAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BTL_REC_SEL_GRAPHIC_Delete 0x021BB220 thumb ov214
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ov067_id 0x00000043 data
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   KEY_GetTrg 0x020362DC arm
 *   FADE_IsActive 0x0204E804 arm
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 *   BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 *   UI_SetInputMode 0x020355D8 arm
 *   BATTLE_REC_VerifyAndCloseSave 0x0200B5CC thumb
 *   BATTLE_REC_LoadAlloc 0x0200B5A4 thumb
 *   BATTLE_REC_GetHeaderOf 0x0200B934 thumb
 *   BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 *   BATTLE_REC_Delete 0x0200B438 thumb
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   TIME_ICON_Create 0x0202EE30 thumb
 *   BATTLE_REC_BeginSave 0x0200B6E0 thumb
 *   BATTLE_REC_DecodeWork 0x0200B490 thumb
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BTL_REC_SEL_GRAPHIC_Draw 0x021BB27C thumb ov214
 *   BTL_REC_SEL_GRAPHIC_Draw3d 0x021BB290 thumb ov214
 *   BTL_REC_SEL_GRAPHIC_DrawEnd 0x021BB29C thumb ov214
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_LoadPltt 0x02040E78 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   d_021BB658 0x021BB658 data a1
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Main 0x020310C4 arm
 *   UI_GetFrameRate 0x02035630 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BG_SYS_CreateRun 0x0203FA08 arm
 *   BMP_MENU_CreateYesNo 0x0201FDA0 thumb
 *   d_021BB480 0x021BB480 data a1
 *   _u32_div_f 0x0209C2B0 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   BTL_REC_SEL_GRAPHIC_GetCamera 0x021BB2A8 thumb ov214
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorDrawPriority 0x0204B800 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   UI_SCENE_LoadActorGfx 0x021B6208 thumb ov067
 *   UI_SCENE_CreateActor 0x021B629C thumb ov067
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   UI_SCENE_FreeActorGfx 0x021B6284 thumb ov067
 *   d_021BB4C4 0x021BB4C4 data a1
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   ARC_UTIL_UploadBgPaletteFromArchive 0x0204989C arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BG_SYS_ClearLayerEx 0x02041570 arm
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GXS_SetGraphicsMode 0x0207D518 arm
 *   BG_SYS_ClearSubBgPlanes 0x02043558 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   d_021BB498 0x021BB498 data a4
 *   d_021BB640 0x021BB640 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   TCB_GetTaskOffset 0x02030CB0 arm
 *   TCB_Init 0x02030CBC arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_SetAutoTransfer 0x02021EE4 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   TCB_Noop 0x02030DA4 arm
 *   TCB_Main 0x02030D28 arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   rects 0x021BB568 data a4
 */

#define REG3D (*(volatile u16 *)REG_DISP3DCNT_ADDR)
struct ProcSystem;
struct ClactActor;
struct BigObj;
struct GfFont;
struct MsgBank;
struct BtlRecSelRec;
struct Node;
struct PrintSys;
struct Proc;
struct BattleRec;
struct Big;
struct Entry;
struct Link;
struct ObjC4;
struct BtlRecSel;
struct CharBuf;
struct Descriptor;
struct Tcbl;
struct Rec3;
struct S02031140;
struct U16Vec;
struct Cfg;
struct WinDat;
struct BmpMenu;
struct WordSet;
struct Sub0200852CObj;
struct BtlRecSelMgr;
struct Ctx;
struct PaletteFade;
struct PalAnmObj;
struct S02021D50;
#include "../arm9/arc_tool.h"
#include "../sdk_ioreg.h"
#include "../arm9/arc_util.h"
#include "../arm9/bmp_menu.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/msgdata.h"
#include "../arm9/mystatus.h"
#include "../arm9/tcb_list.h"
#include "../arm9/tcbl.h"
#include "../arm9/ui.h"
#include "../types.h"

struct ActorGfxDesc;
struct ActorGfxSet;
#include "../arm9/clact.h"
#include "../arm9/bg_sys_types.h"

struct Palette {u16 a,b,c;};

typedef struct {u8 a,b,c,d,e,f;} BtlRecSelRec;

typedef struct {BtlRecSelRec r[4];} Table;

/* one cell of the two by six record-select grid (40 bytes) */
struct BtlRecSelCell {
    u32 gfxId0, gfxId1, gfxId2, gfxId3;
    u8 uiSceneWork[16];
    u32 actor;
    u8 x, y, flag, order;
};

/* the yes/no menu configuration at 0x80, handed to BMP_MENU_CreateYesNo as a WinDat */
struct BtlRecSelYesNo { u8 a, b, c, d; u16 e; };

struct BtlRecSel {
    u16 heap, pad02;
    void *graphic;               /* 0x04 record-select graphic object */
    u32 font;                    /* 0x08 GF_FONT handle (word-sized) */
    void *printQue[4];           /* 0x0C four print queues */
    u32 nextState;               /* 0x1C */
    u32 fadeType, fadeStart, fadeEnd, fadeSpeed;  /* 0x20 FADE_Start arguments */
    u32 fadeInstant;             /* 0x30 */
    u32 nextStateA, entryA, flag3C;   /* 0x34 */
    u32 nextStateB, entryB;      /* 0x40 */
    u32 menuMode;                /* 0x48 */
    u32 task;                    /* 0x4C */
    int itemCount, exitRequest;  /* 0x50 */
    struct MsgBank *msgBank;     /* 0x58 */
    void *printStream;           /* 0x5C */
    int streamWait, waitTimer;   /* 0x60 */
    struct Tcbl *tcbl;           /* 0x68 */
    void *win1, *win0;           /* 0x6C, 0x70 */
    u32 frameRun;                /* 0x74 */
    void *strbuf;                /* 0x78 */
    u32 windowShown;             /* 0x7C */
    struct BtlRecSelYesNo yesNo; /* 0x80 */
    u16 pad86;
    struct BmpMenu *yesNoMenu;   /* 0x88 */
    void *winHandles[4];         /* 0x8C four window descriptors */
    int winShown[4];             /* 0x9C */
    u32 timerA, timerB;          /* 0xAC */
    int busy, menuOpen;          /* 0xB4 */
    int lastMode;                /* 0xBC */
    u16 lastValue, padC2;        /* 0xC0 */
    struct BtlRecSelCell cells[2][6];     /* 0xC4 */
    u32 msgIndex, mode;          /* 0x2A4 */
    u32 battleRec;               /* 0x2AC */
    u32 headerParam;             /* 0x2B0 */
    u32 saveState;               /* 0x2B4 */
    u16 saveArg0, saveArg1;      /* 0x2B8 */
    u32 saveStatus;              /* 0x2BC */
    u32 bgRunMain;               /* 0x2C0 */
    u8 uiSceneWork[16];          /* 0x2C4 */
    void *actor;                 /* 0x2D4 */
    void *tcb;                   /* 0x2D8 */
    void *palBuf;                /* 0x2DC */
    void *palanm;                /* 0x2E0 */
    u32 fadeRequest, fadeState;  /* 0x2E4 */
    void *timeIcon;              /* 0x2EC */
};

/* the record-select manager that owns one work record */
struct BtlRecSelMgr {
    void *gameData;              /* 0x00 */
    int recordExists;            /* 0x04 */
    int isWifi;                  /* 0x08 */
    int isMulti;                 /* 0x0C */
    u32 saveParam0, saveParam1;  /* 0x10 */
};

typedef struct {int mode;u32 flag04;int flag08,gfxKind,gfxIndex,gfxExtra0,gfxExtra1;u8 paletteSlot,flag1d,shading;} In;

typedef struct {u8 a,b;} BtlRecSelPair;

struct Rect {u16 h[4];};

#include "../sdk_gx.h"

extern int GF_OVERLAY_Load(int);
extern void GFL_HEAP_CreateChildHeap(u32,u32,u32);
extern void *PROCSYS_AllocProcWork(struct Proc *proc, unsigned int size, unsigned int heapId);
extern void MI_CpuFill8(void*,u32,u32);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_SetPriority(int idx, unsigned short val);
extern void BG_SYS_LoadPlttEntry(u32,u32);
extern void FADE_Start(u32,int,int,int);
extern char *BTL_REC_SEL_GRAPHIC_Create(u32,u32);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
struct PrintQueue;
extern struct PrintQueue *PRINTSYS_QUE_Create(unsigned int heap);
struct GameData;
extern void *GAME_DATA_GetMyItem(struct GameData *gd);
struct MyItem;
extern u32 MYITEM_SAVEDATA_HasItem(struct MyItem *bag, unsigned short itemId, unsigned short quantity, unsigned short heapId);
struct TcbTask;
extern struct TcbTask *GFL_USE_AddMainTask(void(*)(void*),void*,u32);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void GFL_NET_RefreshWmIconAtTopRight(u32,u32);
extern unsigned int MSGDATA_Delete(struct MsgBank *bank);
struct TcbTask;
extern void TCB_DeleteTask(struct TcbTask *task);
extern void PRINTSYS_QUE_Clear(struct PrintQueue *queue);
extern void PRINTSYS_QUE_Delete(struct PrintQueue *queue);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern void BTL_REC_SEL_GRAPHIC_Delete(char *p);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void GF_OVERLAY_Unload(int handle);
struct SaveControl;
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gd);
extern u32 KEY_GetTrg(void);
extern int FADE_IsActive(void);
extern u32 BATTLE_REC_VerifyAndCloseSave(struct SaveControl *save, unsigned int heap, unsigned int *result, unsigned int id);
struct BattleRecSave;
extern struct BattleRecSave *BATTLE_REC_LoadAlloc(struct SaveControl *save, unsigned int heap, unsigned int *result, unsigned int id);
struct BattleRecHeader;
extern struct BattleRecHeader *BATTLE_REC_GetHeaderOf(struct BattleRecSave *rec);
extern unsigned long long BATTLE_REC_GetHeaderParam(struct BattleRecHeader *head, int param, int index);
extern void BTL_REC_SEL_SetEntryA(void*,char*,u32,u32,u32),BATTLE_REC_Delete(void*);
struct TcbList;
extern struct TcbList *GFL_USE_GetMainTaskList(void);
struct BmpWin;
struct TimeIcon;
extern struct TimeIcon *TIME_ICON_Create(struct TcbList *taskList, struct BmpWin *refWin, unsigned char fillColor, unsigned char waitInterval, unsigned short heapId);
extern u32 BATTLE_REC_BeginSave(struct GameData *gameData, unsigned short heap, unsigned int modeIndex, unsigned int battleCount, unsigned int id, unsigned short *seq, unsigned short *subSeq);
extern void BATTLE_REC_DecodeWork(void),TIME_ICON_Delete(u8*),GFL_USE_PlaySeDefaultVolume(u32);
struct GFLNetHandle;
extern struct GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct GFLNetHandle *handle, unsigned int timingLow, unsigned int timingHigh);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct GFLNetHandle *handle, unsigned int timingLow, unsigned int timingHigh);
extern u32 PRINTSYS_QUE_Main(struct PrintQueue *queue);
extern void BTL_REC_SEL_GRAPHIC_Draw(u8*),BTL_REC_SEL_GRAPHIC_Draw3d(u8*),BTL_REC_SEL_GRAPHIC_DrawEnd(char*);
extern void *GFL_HEAP_Alloc(u32,u32,int,const char*,u16);
extern void BG_SYS_LoadPltt(u32,void*,u32,u32);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32,u32,u32,u32,u32,u16);
extern struct BmpWin *BMP_WIN_Create(unsigned int bgLayer, unsigned int posX, unsigned int posY, unsigned char width, unsigned char height, unsigned char palette, unsigned char allocDir);
struct Bmp;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
extern void BMP_Clear(struct Bmp *bmp, unsigned char value);
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void *BMP_MENUWORK_LoadFrameGfx(unsigned int layer, unsigned int palSlot, unsigned int frameId, unsigned short heapId);
struct TcblSystem;
extern struct TcblSystem *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void BG_SYS_MarkTileDirty(u32);
struct TextPrinter;
extern void PRINTSYS_PrintStreamDelete(struct TextPrinter *printer);
struct Strbuf;
extern void STRBUF_Delete(struct Strbuf *strbuf);
extern void TCBL_Destroy(struct TcblSystem *tcbl);
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
extern u8 UI_GetFrameRate(void);
extern void BMP_MENUWORK_DrawWindow(struct BmpWin *win, int commitMode, unsigned short tileBase, unsigned int palette);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern void BMP_MENUWORK_DrawWindowBorder(struct BmpWin *desc, unsigned int commitMode);
extern unsigned char BMP_WIN_GetBgLayer(struct BmpWin *win);
extern signed char MSG_SPEED_GetWait(void);
extern struct TextPrinter *PRINTSYS_PrintStream(struct BmpWin *,unsigned,unsigned,struct Strbuf *,struct GfFont *,unsigned,struct Tcbl *,unsigned,u16,u16);
extern unsigned PRINTSYS_PrintStreamGetState(struct TextPrinter *printer);
extern void PRINTSYS_PrintStreamShortWait(struct TextPrinter *printer, int wait);
extern void PRINTSYS_PrintStreamReleasePause(struct TextPrinter *printer);
extern unsigned int KEY_GetCont(void);
extern int TOUCHPANEL_GetCont(void);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintQue(struct PrintQueue *queue, struct Bmp *bmp, unsigned int x, short y, struct Strbuf *str, struct GfFont *font);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);
extern unsigned BG_SYS_CreateRun(unsigned,unsigned,unsigned);
extern struct BmpMenu *BMP_MENU_CreateYesNo(const struct WinDat *,u16,u8,u8,u16);
extern void PRINTSYS_PrintQueColor(struct PrintQueue *, struct Bmp *, unsigned, unsigned, struct Strbuf *, struct GfFont *, int);
extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(unsigned short heapId);
extern u32 WORDSET_Delete(struct WordSet *p);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *words, struct Strbuf *dst, struct Strbuf *src);
extern u32 BTL_REC_SEL_GRAPHIC_GetCamera(u8 *);
extern int POKE_TOOL_GetIconPaletteArcId(void);
extern u32 POKE_TOOL_CalcGraphicIndex(u32,u32,u32,u32);
extern int POKE_TOOL_GetIconCellArcId(void);
extern int POKE_TOOL_GetIconCellEntryId(void);
extern void UI_SCENE_LoadActorGfx(struct ActorGfxSet *,struct ActorGfxDesc *,void *,u16);
extern struct Actor *UI_SCENE_CreateActor(struct ActorGfxSet *,void *,u16,u16,u8,u16);
struct Actor;
extern u32 POKE_TOOL_CalcIconPalette(u32,u32,u32,u32);
extern void UI_SCENE_FreeActorGfx(struct ActorGfxSet *p);
extern unsigned int ARC_UTIL_RegisterObjCharFromHandle(void *, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short);
extern void ARC_TOOL_DeleteHandle(void *);
extern void ARC_UTIL_UploadBgPaletteFromArchive(u32 archiveID, u32 memberIdx, u32 channel, u32 offset, u32 size, u32 heapID, u16 flags);
extern void BG_SYS_ChangeScroll(u32,u32,u32);
extern void BG_SYS_ChangeScrollImmediate(u32,u32,u32);
extern void BG_SYS_ClearLayerEx(int channel, u16 val);
struct MyStatus;
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gd);
extern void BG_SYS_ClearSubPlanes(void);
extern void GXS_SetGraphicsMode(u32);
extern void BG_SYS_ClearSubBgPlanes(void);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *,u32,u32,u32,u32,u32,u16);
extern void BG_SYS_PushTile(u32);
extern void BG_SYS_FreeLayerBuf(u8);
extern u32 TCB_GetTaskOffset(u32);
struct TcbSystem;
extern struct TcbSystem *TCB_Init(unsigned int capacity, struct TcbSystem *sys);
extern struct PaletteFade *PALANM_Create(u32);
extern void PALANM_SetAutoTransfer(struct PaletteFade *o, int v);
extern void PALANM_AllocSlotBuffers(struct PaletteFade *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PaletteFade *slots, u32 bank, u32 off, u32 size);
extern void PALANM_FreeSlotBuffers(struct PaletteFade *,u32);
extern u32 PALANM_Delete(struct PaletteFade *);
extern void TCB_Main(struct TcbSystem *sys);
extern u32 PALANM_GetFadeRequestBits(const struct PaletteFade *);
extern int PALANM_RequestFade(struct PaletteFade *,u16,u32,s16,u8,u8,u16,void *);
extern void PALANM_TransferPalettes(struct PaletteFade *);
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16,int,int,int,int);
struct G3dLight;
extern void G3D_SYSTEM_SetLight(unsigned int lightIdx, struct G3dLight *light);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
int BTL_REC_SEL_Create(void *manager,char *state,char * const obj);
int BTL_REC_SEL_Delete(void *owner,int unused,int state,char *p);
int BTL_REC_SEL_Main(void *unused,u32 *state,const char *obj,char *p);
void BTL_REC_SEL_StartFade(char *a, int b, char *c, int d, int e, int f, int g, int h, int i);
void BTL_REC_SEL_StartEntryA(unsigned *out,void *a,char *p,unsigned b,unsigned c,unsigned d);
void BTL_REC_SEL_SetEntryA(void *unused,char *p,unsigned a,unsigned b,unsigned c);
void BTL_REC_SEL_StartEntryB(int *out, int a, int b, int c, int d);
void BTL_REC_SEL_SetEntryB(int unused, char *b, int c, int d);
void BTL_REC_SEL_VBlank(void *unused, char *p);
void BTL_REC_SEL_InitWindows(void *unused, struct BtlRecSel *p);
void BTL_REC_SEL_DeleteWindows(int unused,char*p);
void BTL_REC_SEL_MainTcbl(int unused,char *p);
void BTL_REC_SEL_DrawWindow(int unused,char *p);
void BTL_REC_SEL_DrawWindowBorder(int unused,char *p);
void BTL_REC_SEL_ClearWindowWhite(int unused, char *p);
void BTL_REC_SEL_ClearWindowClear(int unused,char *p);
void BTL_REC_SEL_PrintEntry(int unused,char*p,unsigned entry,int v);
int BTL_REC_SEL_WaitPrint(int a,char *p);
int BTL_REC_SEL_PrintStep(int unused,char*p);
void BTL_REC_SEL_PrintQueEntry(void*obj,char*p,unsigned entry);
u32 BTL_REC_SEL_TryShowEntry(int unused,u8 *p);
void BTL_REC_SEL_InitPalette(int unused,char*p);
void BTL_REC_SEL_Noop(int unused, char *p);
void BTL_REC_SEL_CreateYesNo(int unused,u8 *p);
void BTL_REC_SEL_CreateWindows(int unused,char*p);
void BTL_REC_SEL_DeleteWindowList(int unused, char *p);
void BTL_REC_SEL_TickTimer(struct BtlRecSelMgr *obj,char*p);
void BTL_REC_SEL_ShowWindows(void *unused,struct BtlRecSel *p);
void BTL_REC_SEL_PrintList(void*obj,char*p);
void BTL_REC_SEL_ClearList(int unused,char*p);
void BTL_REC_SEL_StartTimer(void *obj, char *p, u32 v);
void BTL_REC_SEL_ResetTimer(void*obj,char*p);
void BTL_REC_SEL_DrawCounter(struct BtlRecSelMgr *obj, struct BtlRecSel *e, unsigned int v);
void BTL_REC_SEL_InitCells(void *unused,struct BtlRecSel *p);
void BTL_REC_SEL_DeleteCellActors(int unused, int base);
int BTL_REC_SEL_CreateActor(int a,u16 b,int c,u8 d,u32 e,u32 f,u32 g,u32 h,void*x,u8 i,u8 j,u8 k,u8 l,u8 m);
void BTL_REC_SEL_DeleteActor(void*p,void*actor);
void BTL_REC_SEL_SetMode(int unused,char*p);
void BTL_REC_SEL_InitBgRun(int unused, char *p);
void BTL_REC_SEL_DeleteBgRun(int unused,u8 *p);
void BTL_REC_SEL_InitBgGfx1(int unused,u8 *p);
void BTL_REC_SEL_InitBgGfx2(int unused,u8 *p);
void BTL_REC_SEL_InitBgGfx3(int unused,u8 *p);
void BTL_REC_SEL_ClearLayer(void *work, char *unused);
void BTL_REC_SEL_InitSubBg(void **a,char *p);
void BTL_REC_SEL_DeleteSubBg(int unused, char *p);
void BTL_REC_SEL_CreateUiActor(int unused,u8 *p);
void BTL_REC_SEL_DeleteUiActor(int unused,u8 *p);
void BTL_REC_SEL_InitPalanm(int unused,char *p);
void BTL_REC_SEL_DeletePalanm(int unused,u8 *p);
void BTL_REC_SEL_FadeMain(void *unused,struct BtlRecSel *p);
void BTL_REC_SEL_TransferPalettes(char *p);
void BTL_REC_SEL_InitG3dDisplay(void);
extern u8 ov67_id[];
extern const char ov067_id[];
extern const char d_021BB658[];
extern const Table d_021BB480;
extern const BtlRecSelPair d_021BB4C4[];
extern const u32 d_021BB498[][11];
extern u32 d_021BB640[][3];
extern const struct Rect rects[];

int BTL_REC_SEL_Create(void *manager,char *state,char * const mgr)
{
    char *work;
    u8 layer;
    enum {K=3} k;
    GF_OVERLAY_Load((sptr)ov67_id);
    GFL_HEAP_CreateChildHeap(1,0x75,0x50000);
    work=PROCSYS_AllocProcWork(manager,0x2f0,0x75);
    MI_CpuFill8(work,0,0x2f0);
    ((struct BtlRecSel *)work)->heap=0x75;
    for(layer=0;layer<=7;layer++)BG_SYS_SetPlaneVisible(layer,0);
    *(void* *)&((struct BtlRecSel *)work)->graphic=BTL_REC_SEL_GRAPHIC_Create(1,((struct BtlRecSel *)work)->heap);
    *(void* *)&((struct BtlRecSel *)work)->font=GF_FONT_Create(23,0,0,0,((struct BtlRecSel *)work)->heap);
    ((struct BtlRecSel *)work)->printQue[0]=(void *)PRINTSYS_QUE_Create((unsigned int)(u32)((struct BtlRecSel *)work)->heap);
    ((struct BtlRecSel *)work)->printQue[1]=(void *)PRINTSYS_QUE_Create((unsigned int)(u32)((struct BtlRecSel *)work)->heap);
    ((struct BtlRecSel *)work)->printQue[2]=(void *)PRINTSYS_QUE_Create((unsigned int)(u32)((struct BtlRecSel *)work)->heap);
    ((struct BtlRecSel *)work)->printQue[3]=(void *)PRINTSYS_QUE_Create((unsigned int)(u32)((struct BtlRecSel *)work)->heap);
    ((struct BtlRecSel *)work)->itemCount=MYITEM_SAVEDATA_HasItem(GAME_DATA_GetMyItem(*(void* *)&((struct BtlRecSelMgr *)mgr)->gameData),0x1d1,1,((struct BtlRecSel *)work)->heap);
    ((struct BtlRecSel *)work)->exitRequest=0;
    ((struct BtlRecSel *)work)->task=(uptr)GFL_USE_AddMainTask((void (*)(void *))BTL_REC_SEL_VBlank,work,(unsigned int)1);
    *(void* *)&((struct BtlRecSel *)work)->msgBank=MSGDATA_CreateFromArchive(0,2,19,((struct BtlRecSel *)work)->heap);
    BTL_REC_SEL_InitBgRun((sptr)mgr,work);BTL_REC_SEL_ClearLayer(mgr,work);BTL_REC_SEL_InitSubBg((void **)mgr,work);
    BTL_REC_SEL_InitWindows(mgr,(struct BtlRecSel *)work);BTL_REC_SEL_DrawWindow((sptr)mgr,work);BTL_REC_SEL_InitPalette((sptr)mgr,work);BTL_REC_SEL_CreateWindows((sptr)mgr,work);
    BG_SYS_SetPriority(2,2);k=K;BG_SYS_SetPriority(k,1);BG_SYS_SetPriority(1,0);
    BG_SYS_SetPlaneVisible(2,1);BG_SYS_SetPlaneVisible(3,1);BG_SYS_SetPlaneVisible(1,1);
    BG_SYS_LoadPlttEntry(0,0);BG_SYS_LoadPlttEntry(4,0);FADE_Start(3,16,16,0);
    if(((struct BtlRecSel *)work)->itemCount){
        if(((struct BtlRecSelMgr *)mgr)->isMulti){
          if(((struct BtlRecSelMgr *)mgr)->recordExists){
            BTL_REC_SEL_StartFade(state,(sptr)mgr,work,2,k,16,0,2,0);
            BTL_REC_SEL_SetEntryA(mgr,work,5,0,1);BTL_REC_SEL_StartTimer(mgr,work,60);
            if(((struct BtlRecSelMgr *)mgr)->isWifi)BTL_REC_SEL_InitBgGfx1((sptr)mgr,(u8 *)work);
            ((struct BtlRecSel *)work)->busy=1;
          }else {BTL_REC_SEL_StartFade(state,(sptr)mgr,work,15,k,16,0,2,0);}
        }else {common:BTL_REC_SEL_StartFade(state,(sptr)mgr,work,15,k,16,0,2,0);}
    }else if(((struct BtlRecSelMgr *)mgr)->isWifi){BTL_REC_SEL_StartFade(state,(sptr)mgr,work,15,k,16,0,2,0);}
    else ((struct BtlRecSel *)work)->exitRequest=1;
    BTL_REC_SEL_CreateUiActor((sptr)mgr,(u8 *)work);BTL_REC_SEL_InitPalanm((sptr)mgr,work);BTL_REC_SEL_DeleteUiActor((sptr)mgr,(u8 *)work);
    GFL_NET_RefreshWmIconAtTopRight(1,((struct BtlRecSel *)work)->heap);
    return 1;
}

int BTL_REC_SEL_Delete(void *mgr,int unused,int state,char *work)
{
    BTL_REC_SEL_DeletePalanm(state,(u8 *)work);
    BTL_REC_SEL_DeleteWindowList(state,work);
    BTL_REC_SEL_Noop(state,work);
    BTL_REC_SEL_DeleteWindows(state,work);
    BTL_REC_SEL_DeleteSubBg(state,work);
    BTL_REC_SEL_DeleteBgRun(state,(u8 *)work);
    MSGDATA_Delete((struct MsgBank *)(*(struct BtlRecSelRec * *)&((struct BtlRecSel *)work)->msgBank));
    TCB_DeleteTask((struct TcbTask *)(((struct BtlRecSel *)work)->task));
    PRINTSYS_QUE_Clear((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[3]));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[3]));
    PRINTSYS_QUE_Clear((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[2]));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[2]));
    PRINTSYS_QUE_Clear((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[1]));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[1]));
    PRINTSYS_QUE_Clear((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[0]));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[0]));
    GF_FONT_Delete((void *)((struct BtlRecSel *)work)->font);
    BTL_REC_SEL_GRAPHIC_Delete(*(char * *)&((struct BtlRecSel *)work)->graphic);
    PROCSYS_FreeProcWork(mgr);
    GFL_HEAP_DeleteChecked(117);
    GF_OVERLAY_Unload((sptr)ov067_id);
    return 1;
}

/*
 * note 2026-10-05: no default label (the dispatch bhi lands on case 3's own break stub);
 * the finish call (18,3,0,16,2,0) is written inline in case 15 and again in case 17, never by goto;
 * case 5 writes its own cancel copy (no goto into case 6); side and index are int; c = 0 is set
 * before the first BATTLE_REC_GetHeaderParam call; case 12 stores p+0x64 = 120 in both arms.
 * GAME_DATA_GetSaveControl 0x02012EBC thumb
 * KEY_GetTrg 0x020362DC arm
 * FADE_Start 0x0204E720 arm
 * FADE_IsActive 0x0204E804 arm
 * BTL_REC_SEL_PrintEntry 0x021BA108 thumb ov214
 * BTL_REC_SEL_WaitPrint 0x021BA16C thumb ov214
 * BTL_REC_SEL_CreateYesNo 0x021BA3A0 thumb ov214
 * BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 * BMP_MENU_DeleteYesNo 0x0201FEF4 thumb
 * UI_SetInputMode 0x020355D8 arm
 * BATTLE_REC_VerifyAndCloseSave 0x0200B5CC thumb
 * BTL_REC_SEL_StartFade 0x021B9EB8 thumb ov214
 * BTL_REC_SEL_ResetTimer 0x021BA6F0 thumb ov214
 * BTL_REC_SEL_StartEntryA 0x021B9ED4 thumb ov214
 * BATTLE_REC_LoadAlloc 0x0200B5A4 thumb
 * BTL_REC_SEL_ClearLayer 0x021BAD08 thumb ov214
 * BTL_REC_SEL_ClearWindowWhite 0x021BA0B0 thumb ov214
 * BATTLE_REC_GetHeaderOf 0x0200B934 thumb
 * BATTLE_REC_GetHeaderParam 0x0200B98C thumb
 * BTL_REC_SEL_SetMode 0x021BABB8 thumb ov214
 * BTL_REC_SEL_PrintList 0x021BA5C8 thumb ov214
 * BTL_REC_SEL_InitCells 0x021BA8DC thumb ov214
 * BTL_REC_SEL_InitBgGfx2 0x021BAC90 thumb ov214
 * BTL_REC_SEL_InitBgGfx3 0x021BACCC thumb ov214
 * BTL_REC_SEL_SetEntryA 0x021B9EF0 thumb ov214
 * BATTLE_REC_Delete 0x0200B438 thumb
 * BTL_REC_SEL_ClearList 0x021BA650 thumb ov214
 * BTL_REC_SEL_DeleteCellActors 0x021BAAB0 thumb ov214
 * BTL_REC_SEL_ClearWindowClear 0x021BA0DC thumb ov214
 * BTL_REC_SEL_DrawWindowBorder 0x021BA0A4 thumb ov214
 * BTL_REC_SEL_PrintQueEntry 0x021BA254 thumb ov214
 * BTL_REC_SEL_TryShowEntry 0x021BA2B8 thumb ov214
 * GFL_USE_GetMainTaskList 0x020056BC thumb
 * TIME_ICON_Create 0x0202EE30 thumb
 * BATTLE_REC_BeginSave 0x0200B6E0 thumb
 * BATTLE_REC_DecodeWork 0x0200B490 thumb
 * TIME_ICON_Delete 0x0202F038 thumb
 * GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 * BTL_REC_SEL_StartEntryB 0x021B9EFC thumb ov214
 * GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 * GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 * GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 * GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 * BTL_REC_SEL_MainTcbl 0x021BA058 thumb ov214
 * BTL_REC_SEL_TickTimer 0x021BA45C thumb ov214
 * BTL_REC_SEL_ShowWindows 0x021BA4E8 thumb ov214
 * BTL_REC_SEL_FadeMain 0x021BAF64 thumb ov214
 * PRINTSYS_QUE_Main 0x0201C4E4 thumb
 * BTL_REC_SEL_GRAPHIC_Draw 0x021BB27C thumb ov214
 * BTL_REC_SEL_GRAPHIC_Draw3d 0x021BB290 thumb ov214
 * BTL_REC_SEL_GRAPHIC_DrawEnd 0x021BB29C thumb ov214
 */
int BTL_REC_SEL_Main(void *unused,u32 *state,const char *mgr,char *work)
{
    void *owner,*record;
    u32 result;
    int done;
    int side,index;
    long slot;
    u32 status0,status1,gfxId0,gfxId1,gfxId2;
    uptr addr;
    owner=GAME_DATA_GetSaveControl(((struct BtlRecSelMgr *)mgr)->gameData);
    KEY_GetTrg();
    switch(*state){
    case 0:
        if((((struct BtlRecSel *)work)->exitRequest)){*state=18;break;}
        if((((struct BtlRecSel *)work)->fadeInstant)==1){if((((struct BtlRecSel *)work)->fadeStart)==0)(((struct BtlRecSel *)work)->fadeRequest)=2;else (((struct BtlRecSel *)work)->fadeRequest)=1;}
        else FADE_Start((((struct BtlRecSel *)work)->fadeType),(((struct BtlRecSel *)work)->fadeStart),(((struct BtlRecSel *)work)->fadeEnd),(((struct BtlRecSel *)work)->fadeSpeed));
        *state=1;break;
    case 1:
        done=0;
        if((((struct BtlRecSel *)work)->fadeInstant)==1){if((((struct BtlRecSel *)work)->fadeState)==0||(((struct BtlRecSel *)work)->fadeState)==2)done=1;}
        else if(!FADE_IsActive())done=1;
        if(done){(((struct BtlRecSel *)work)->busy)=0;*state=(((struct BtlRecSel *)work)->nextState);}break;
    case 2:BTL_REC_SEL_PrintEntry((sptr)mgr,work,(((struct BtlRecSel *)work)->entryA),0);*state=3;break;
    case 3:
        if(!BTL_REC_SEL_WaitPrint((sptr)mgr,work))break;
        BTL_REC_SEL_CreateYesNo((sptr)mgr,(u8 *)work);*state=(((struct BtlRecSel *)work)->nextStateA);break;
    case 4:BTL_REC_SEL_PrintEntry((sptr)mgr,work,(((struct BtlRecSel *)work)->entryB),0);*state=(((struct BtlRecSel *)work)->nextStateB);break;
    case 5:
        result=BMP_MENU_ProcessYesNo((struct BmpMenu *)(((struct BtlRecSel *)work)->yesNoMenu));
        if(result!=0xffffffff){
            UI_SetInputMode(0);
            if(result==0){
                if(BATTLE_REC_VerifyAndCloseSave(owner,((struct BtlRecSel *)work)->heap,&status0,0)){
                    (((struct BtlRecSel *)work)->busy)=1;BTL_REC_SEL_StartFade((char*)state,(sptr)mgr,work,8,1,0,16,-2,1);break;
                }else{BTL_REC_SEL_ResetTimer((void*)mgr,work);*state=10;}
            }else BTL_REC_SEL_StartEntryA(state,(void*)mgr,work,6,3,1);
        }else if((((struct BtlRecSel *)work)->menuOpen)){BMP_MENU_DeleteYesNo((void*)(((struct BtlRecSel *)work)->yesNoMenu));*state=15;}
        break;
    case 6:
        result=BMP_MENU_ProcessYesNo((struct BmpMenu *)(((struct BtlRecSel *)work)->yesNoMenu));
        if(result!=0xffffffff){
            UI_SetInputMode(0);
            if(result==0){BTL_REC_SEL_ResetTimer((void*)mgr,work);*state=15;}
            else BTL_REC_SEL_StartEntryA(state,(void*)mgr,work,5,0,1);
        }else if((((struct BtlRecSel *)work)->menuOpen)){BMP_MENU_DeleteYesNo((void*)(((struct BtlRecSel *)work)->yesNoMenu));*state=15;}
        break;
    case 7:
        result=BMP_MENU_ProcessYesNo((struct BmpMenu *)(((struct BtlRecSel *)work)->yesNoMenu));
        if(result!=0xffffffff){
            UI_SetInputMode(0);
            if(result==0)(((struct BtlRecSel *)work)->menuMode)=10;else (((struct BtlRecSel *)work)->menuMode)=15;
            BTL_REC_SEL_ResetTimer((void*)mgr,work);
            BTL_REC_SEL_StartFade((char*)state,(sptr)mgr,work,9,1,0,16,-2,1);break;
        }else if((((struct BtlRecSel *)work)->menuOpen)){
            BMP_MENU_DeleteYesNo((void*)(((struct BtlRecSel *)work)->yesNoMenu));(((struct BtlRecSel *)work)->menuMode)=15;
            BTL_REC_SEL_StartFade((char*)state,(sptr)mgr,work,9,1,0,16,-2,1);break;
        }
        break;
    case 8:
        (((struct BtlRecSel *)work)->battleRec)=(uptr)BATTLE_REC_LoadAlloc(owner,((struct BtlRecSel *)work)->heap,&status1,0);
        BTL_REC_SEL_ClearLayer((void*)mgr,work);BTL_REC_SEL_ClearWindowWhite((sptr)mgr,work);
        if(status1==1){
            record=BATTLE_REC_GetHeaderOf((void*)(((struct BtlRecSel *)work)->battleRec));
            (((struct BtlRecSel *)work)->headerParam)=BATTLE_REC_GetHeaderParam(record,3,0);
            BTL_REC_SEL_SetMode((sptr)mgr,work);
            for(slot=0;slot<12;slot++){
                gfxId1=0;gfxId2=0;gfxId0=BATTLE_REC_GetHeaderParam(record,0,slot);
                if(gfxId0){gfxId1=BATTLE_REC_GetHeaderParam(record,1,slot);gfxId2=BATTLE_REC_GetHeaderParam(record,6,slot);}
                if((((struct BtlRecSel *)work)->mode)){
                    if(slot<6){
                        addr=(uptr)work+(u32)(slot%6)*40;
                        *(u32*)(addr+0x1b4)=gfxId0;*(u32*)(addr+0x1b8)=gfxId1;*(u32*)(addr+0x1bc)=gfxId2;
                    }else{
                        addr=(uptr)work+(u32)(slot%6)*40;
                        *(u32*)(addr+0xc4)=gfxId0;*(u32*)(addr+0xc8)=gfxId1;*(u32*)(addr+0xcc)=gfxId2;
                    }
                }else{
                    if(slot<3){side=1;index=slot;}
                    else if(slot<6){side=0;index=slot-3;}
                    else if(slot<9){side=1;index=slot-3;}
                    else{side=0;index=slot-6;}
                    addr=(uptr)work+(u32)side*240+(u32)index*40;
                    *(u32*)(addr+0xc4)=gfxId0;*(u32*)(addr+0xc8)=gfxId1;*(u32*)(addr+0xcc)=gfxId2;
                }
            }
            BTL_REC_SEL_PrintList((void*)mgr,work);BTL_REC_SEL_InitCells((void*)mgr,(struct BtlRecSel *)work);
            if((((struct BtlRecSel *)work)->mode))BTL_REC_SEL_InitBgGfx2((sptr)mgr,(u8 *)work);else BTL_REC_SEL_InitBgGfx3((sptr)mgr,(u8 *)work);
            BTL_REC_SEL_StartFade((char*)state,(sptr)mgr,work,2,1,16,0,-2,1);
            BTL_REC_SEL_SetEntryA((void*)mgr,work,7,6,0);
        }else BTL_REC_SEL_StartFade((char*)state,(sptr)mgr,work,10,1,16,0,-2,1);
        BATTLE_REC_Delete((void*)(((struct BtlRecSel *)work)->battleRec));break;
    case 9:
        BTL_REC_SEL_ClearList((sptr)mgr,work);BTL_REC_SEL_DeleteCellActors((sptr)mgr,(sptr)work);BTL_REC_SEL_ClearLayer((void*)mgr,work);
        BTL_REC_SEL_StartFade((char*)state,(sptr)mgr,work,(((struct BtlRecSel *)work)->menuMode),1,16,0,-2,1);
        BTL_REC_SEL_ClearWindowWhite((sptr)mgr,work);
        if((((struct BtlRecSel *)work)->menuMode)==15 && (((struct BtlRecSel *)work)->itemCount) && (*(u32*)(mgr+4)) && !(*(u32*)(mgr+8))){BTL_REC_SEL_ClearWindowClear((sptr)mgr,work);BTL_REC_SEL_DrawWindowBorder((sptr)mgr,work);}
        BTL_REC_SEL_ResetTimer((void*)mgr,work);break;
    case 10:BTL_REC_SEL_PrintQueEntry((void*)mgr,work,9);*state=11;break;
    case 11:
        if(BTL_REC_SEL_TryShowEntry((sptr)mgr,(u8 *)work)){
            (((struct BtlRecSel *)work)->timeIcon)=TIME_ICON_Create((void *)GFL_USE_GetMainTaskList(),(void*)(((struct BtlRecSel *)work)->win1),15,16,((struct BtlRecSel *)work)->heap);
            (((struct BtlRecSel *)work)->saveState)=0;((struct BtlRecSel *)work)->saveArg0=0;((struct BtlRecSel *)work)->saveArg1=0;(((struct BtlRecSel *)work)->saveStatus)=0;
            *state=12;
        }break;
    case 12:
        if((((struct BtlRecSel *)work)->saveStatus)!=2 && (((struct BtlRecSel *)work)->saveStatus)!=3)(((struct BtlRecSel *)work)->saveStatus)=BATTLE_REC_BeginSave(((struct BtlRecSelMgr *)mgr)->gameData,((struct BtlRecSel *)work)->heap,(((struct BtlRecSelMgr *)mgr)->saveParam0),(((struct BtlRecSelMgr *)mgr)->saveParam1),0,&((struct BtlRecSel *)work)->saveArg0,&((struct BtlRecSel *)work)->saveArg1);
        if((u32)((((struct BtlRecSel *)work)->saveStatus)-2)<=1){
            BATTLE_REC_DecodeWork();TIME_ICON_Delete((u8*)(((struct BtlRecSel *)work)->timeIcon));
            if((((struct BtlRecSel *)work)->saveStatus)==2){GFL_USE_PlaySeDefaultVolume(0x558);BTL_REC_SEL_StartEntryB((int*)state,(sptr)mgr,(sptr)work,13,10);(((struct BtlRecSel *)work)->waitTimer)=120;}
            else if((((struct BtlRecSel *)work)->saveStatus)==3){BTL_REC_SEL_StartEntryB((int*)state,(sptr)mgr,(sptr)work,14,11);(((struct BtlRecSel *)work)->waitTimer)=120;}
        }break;
    case 13:if(BTL_REC_SEL_WaitPrint((sptr)mgr,work))*state=15;break;
    case 14:if(BTL_REC_SEL_WaitPrint((sptr)mgr,work))*state=15;break;
    case 15:
        if((((struct BtlRecSel *)work)->itemCount)){
            if((((struct BtlRecSelMgr *)mgr)->isMulti)){
                if((*(u32*)(mgr+4))){
                    if((*(u32*)(mgr+8)))gfxId0=12;
                    else{BTL_REC_SEL_StartFade((char*)state,(sptr)mgr,work,18,3,0,16,2,0);break;}
                }else if((*(u32*)(mgr+8)))gfxId0=13;else gfxId0=14;
            }else gfxId0=15;
        }else if((*(u32*)(mgr+8)))gfxId0=12;else{*state=18;break;}
        if((*(u32*)(mgr+8)))BTL_REC_SEL_PrintQueEntry((void*)mgr,work,gfxId0);else BTL_REC_SEL_PrintEntry((sptr)mgr,work,gfxId0,1);
        *state=16;break;
    case 16:
        done=0;
        if((*(u32*)(mgr+8))){if(BTL_REC_SEL_TryShowEntry((sptr)mgr,(u8 *)work))done=1;}
        else if(BTL_REC_SEL_WaitPrint((sptr)mgr,work))done=1;
        if(done){
            if((*(u32*)(mgr+8))){
                GFL_NET_HANDLE_SetTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),150,43);
                (((struct BtlRecSel *)work)->timeIcon)=TIME_ICON_Create((void *)GFL_USE_GetMainTaskList(),(void*)(((struct BtlRecSel *)work)->win1),15,16,((struct BtlRecSel *)work)->heap);
            }
            *state=17;
        }break;
    case 17:
        done=1;
        if((*(u32*)(mgr+8))){
            if(!GFL_NET_ERR_GetErrorLevel())done=GFL_NET_HANDLE_IsTimingSyncRange((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(),150,43);
            if(done)TIME_ICON_Delete((u8*)(((struct BtlRecSel *)work)->timeIcon));
        }
        if(done)BTL_REC_SEL_StartFade((char*)state,(sptr)mgr,work,18,3,0,16,2,0);
        break;
    case 18:return 1;
    }
    BTL_REC_SEL_MainTcbl((sptr)mgr,work);BTL_REC_SEL_TickTimer((void*)mgr,work);BTL_REC_SEL_ShowWindows((void*)mgr,(struct BtlRecSel *)work);BTL_REC_SEL_FadeMain((void*)mgr,(struct BtlRecSel *)work);
    PRINTSYS_QUE_Main((void*)(((struct BtlRecSel *)work)->printQue[0]));PRINTSYS_QUE_Main((void*)(((struct BtlRecSel *)work)->printQue[1]));PRINTSYS_QUE_Main((void*)(((struct BtlRecSel *)work)->printQue[2]));PRINTSYS_QUE_Main((void*)(((struct BtlRecSel *)work)->printQue[3]));
    BTL_REC_SEL_GRAPHIC_Draw((u8*)(((struct BtlRecSel *)work)->graphic));BTL_REC_SEL_GRAPHIC_Draw3d((u8*)(((struct BtlRecSel *)work)->graphic));BTL_REC_SEL_GRAPHIC_DrawEnd((char*)(((struct BtlRecSel *)work)->graphic));
    return 0;
}

void BTL_REC_SEL_StartFade(char *state, int unused, char *work, int nextState, int fadeType, int fadeStart, int fadeEnd, int fadeSpeed, int fadeInstant)
{
    (*(int *)state) = 0;
    ((struct BtlRecSel *)work)->nextState = nextState;
    ((struct BtlRecSel *)work)->fadeType = fadeType;
    ((struct BtlRecSel *)work)->fadeStart = fadeStart;
    ((struct BtlRecSel *)work)->fadeEnd = fadeEnd;
    ((struct BtlRecSel *)work)->fadeSpeed = fadeSpeed;
    ((struct BtlRecSel *)work)->fadeInstant = fadeInstant;
}

void BTL_REC_SEL_StartEntryA(unsigned *state,void *unused,char *work,unsigned nextStateA,unsigned entryA,unsigned flag3C){*state=2;BTL_REC_SEL_SetEntryA(unused,work,nextStateA,entryA,flag3C);}

void BTL_REC_SEL_SetEntryA(void *unused,char *work,unsigned nextStateA,unsigned entryA,unsigned flag3C){((struct BtlRecSel *)work)->nextStateA=nextStateA;((struct BtlRecSel *)work)->entryA=entryA;((struct BtlRecSel *)work)->flag3C=flag3C;}

void BTL_REC_SEL_StartEntryB(int *state, int unused, int work, int nextStateB, int entryB)
{
    *state = 4;
    BTL_REC_SEL_SetEntryB(unused, (char *)work, nextStateB, entryB);
}

void BTL_REC_SEL_SetEntryB(int unused, char *work, int nextStateB, int entryB)
{
    ((struct BtlRecSel *)work)->nextStateB = nextStateB;
    ((struct BtlRecSel *)work)->entryB = entryB;
}

/*
 * blocker-leaf: sole callback blocker of ov214 021B95A0; no existing source/unit/shard, parent ownership cleared.
 */
void BTL_REC_SEL_VBlank(void *unused, char *work)
{
    BTL_REC_SEL_TransferPalettes(work);
}

static inline void init_palette(struct Palette *pal)
{
    pal->a=0x294b; pal->b=0x5694; pal->c=0x7fff;
}

void BTL_REC_SEL_InitWindows(void *unused, struct BtlRecSel *work)
{
    struct Palette *pal = GFL_HEAP_Alloc(work->heap,6,1,d_021BB658,0x5e9);
    init_palette(pal);
    BG_SYS_LoadPltt(2,pal,6,0x13a);
    GFL_HEAP_Free(pal);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17,5,0,0x180,0x20,work->heap);
    work->win0=(void *)BMP_WIN_Create(1,0,0,1,1,9,0);
    BMP_Clear(BMP_WIN_GetBmp(work->win0),0);
    BMP_WIN_TransferChars(work->win0);
    work->win1=(void *)BMP_WIN_Create(1,1,0x13,0x1e,4,0xc,0);
    BMP_Clear(BMP_WIN_GetBmp(work->win1),0xf);
    BMP_WIN_TransferChars(work->win1);
    work->frameRun=(uptr)BMP_MENUWORK_LoadFrameGfx((unsigned int)1,0xa,0,work->heap);
    work->tcbl=(struct Tcbl *)TCBL_Create(work->heap,work->heap,1,0);
    GF_FONT_SetTextColor(1,2,0xf);
    BG_SYS_MarkTileDirty(1);
    work->printStream=0;
    work->streamWait=0;
    work->waitTimer=0;
    work->strbuf=0;
}

void BTL_REC_SEL_DeleteWindows(int unused,char*work)
{
    if(*(void* *)&((struct BtlRecSel *)work)->printStream)PRINTSYS_PrintStreamDelete(*(void* *)&((struct BtlRecSel *)work)->printStream);
    if(*(void* *)&((struct BtlRecSel *)work)->strbuf)STRBUF_Delete(*(void* *)&((struct BtlRecSel *)work)->strbuf);
    TCBL_Destroy(*(void* *)&((struct BtlRecSel *)work)->tcbl);
    BG_SYS_FreeTileRun(1,(u16)(((struct BtlRecSel *)work)->frameRun),(u16)(((struct BtlRecSel *)work)->frameRun>>16));
    BMP_WIN_Delete(*(void* *)&((struct BtlRecSel *)work)->win1);
    BMP_WIN_Delete(*(void* *)&((struct BtlRecSel *)work)->win0);
}

/*
 * Tail: two zero alignment bytes at 021BA072.
 */
void BTL_REC_SEL_MainTcbl(int unused,char *work){TCBL_Main(*(struct TcblSystem * *)&((struct BtlRecSel *)work)->tcbl);if(UI_GetFrameRate()==30)TCBL_Main(*(struct TcblSystem * *)&((struct BtlRecSel *)work)->tcbl);}

/*
 * Parameter evidence: original narrows third input to u16 before BMP_MENUWORK_DrawWindow.
 */
void BTL_REC_SEL_DrawWindow(int unused,char *work){struct Descriptor *d;BMP_MENUWORK_DrawWindow((struct BmpWin *)(((struct BtlRecSel *)work)->win1),1,(unsigned short)(((struct BtlRecSel *)work)->frameRun),10);d=*(struct Descriptor * *)&((struct BtlRecSel *)work)->win1;BMP_WIN_TransferChars((struct BmpWin *)d);BMP_WIN_MakeScreen((struct BmpWin *)d);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));}

void BTL_REC_SEL_DrawWindowBorder(int unused,char *work){BMP_MENUWORK_DrawWindowBorder(((struct BtlRecSel *)work)->win1,(int)1);}

void BTL_REC_SEL_ClearWindowWhite(int unused, char *work)
{
    struct Descriptor *d;
    BMP_Clear(BMP_WIN_GetBmp(((struct BtlRecSel *)work)->win1), 15);
    d = ((struct BtlRecSel *)work)->win1;
    BMP_WIN_TransferChars((struct BmpWin *)d);
    BMP_WIN_MakeScreen((struct BmpWin *)d);
    BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));
}

/*
 * Tail: two zero alignment bytes at 021BA106.
 */
void BTL_REC_SEL_ClearWindowClear(int unused,char *work){struct Descriptor *d;BMP_Clear(BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct BtlRecSel *)work)->win1)),0);d=*(struct Descriptor * *)&((struct BtlRecSel *)work)->win1;BMP_WIN_TransferChars((struct BmpWin *)d);BMP_WIN_MakeScreen((struct BmpWin *)d);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));}

/*
 * note: 0201CCE4's r0 remains live and is stored at +5c after the call;
 * its caller declaration returns that word despite the own source's void.
 * extent-tail: 021BA16A alignment padding (two zero bytes).
 */
void BTL_REC_SEL_PrintEntry(int unused,char*work,unsigned entry,int v)
{
    int waitTime;
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct BtlRecSel *)work)->win1),15);
    if(*(void* *)&((struct BtlRecSel *)work)->printStream)PRINTSYS_PrintStreamDelete(*(void* *)&((struct BtlRecSel *)work)->printStream);
    if(*(void* *)&((struct BtlRecSel *)work)->strbuf)STRBUF_Delete(*(void* *)&((struct BtlRecSel *)work)->strbuf);
    *(void* *)&((struct BtlRecSel *)work)->strbuf=MSGDATA_AllocString(*(void* *)&((struct BtlRecSel *)work)->msgBank,entry);
    waitTime=MSG_SPEED_GetWait();
    *(void* *)&((struct BtlRecSel *)work)->printStream=PRINTSYS_PrintStream((struct BmpWin *)(*(unsigned *)&((struct BtlRecSel *)work)->win1),0,0,(struct Strbuf *)(*(unsigned *)&((struct BtlRecSel *)work)->strbuf),(struct GfFont *)(((struct BtlRecSel *)work)->font),waitTime,((struct BtlRecSel *)work)->tcbl,2,((struct BtlRecSel *)work)->heap,15);
    ((struct BtlRecSel *)work)->streamWait=v;
}

int BTL_REC_SEL_WaitPrint(int a,char *work){int result=BTL_REC_SEL_PrintStep(a,work);if(result==0){if(UI_GetFrameRate()==30)result=BTL_REC_SEL_PrintStep(a,work);}return result;}

int BTL_REC_SEL_PrintStep(int unused,char*work)
{
    int result=0;
    switch(PRINTSYS_PrintStreamGetState(*(void* *)&((struct BtlRecSel *)work)->printStream)){
    case 0:
        if((KEY_GetCont()&3)||TOUCHPANEL_GetCont()){
            PRINTSYS_PrintStreamShortWait(*(void* *)&((struct BtlRecSel *)work)->printStream,0);
            if(KEY_GetCont()&3)UI_SetInputMode(0);else UI_SetInputMode(1);
        }
        break;
    case 1:
        if((KEY_GetTrg()&3)||TOUCHPANEL_GetTrg()){
            GFL_USE_PlaySeDefaultVolume(0x547);
            PRINTSYS_PrintStreamReleasePause(*(void* *)&((struct BtlRecSel *)work)->printStream);
            if(KEY_GetTrg()&3)UI_SetInputMode(0);else UI_SetInputMode(1);
        }
        break;
    case 2:
        if(((struct BtlRecSel *)work)->waitTimer)--((struct BtlRecSel *)work)->waitTimer;
        else if(((struct BtlRecSel *)work)->streamWait){
            if((KEY_GetTrg()&3)||TOUCHPANEL_GetTrg()){
                if(KEY_GetTrg()&3)UI_SetInputMode(0);else UI_SetInputMode(1);
                ((struct BtlRecSel *)work)->streamWait=0;
                result=1;
            }
        }else result=1;
        break;
    }
    return result;
}

void BTL_REC_SEL_PrintQueEntry(void*mgr,char*work,unsigned entry)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct BtlRecSel *)work)->win1),15);
    if(*(void* *)&((struct BtlRecSel *)work)->printStream)PRINTSYS_PrintStreamDelete(*(void* *)&((struct BtlRecSel *)work)->printStream);
    *(int *)&((struct BtlRecSel *)work)->printStream=0;
    if(*(void* *)&((struct BtlRecSel *)work)->strbuf)STRBUF_Delete(*(void* *)&((struct BtlRecSel *)work)->strbuf);
    *(void* *)&((struct BtlRecSel *)work)->strbuf=MSGDATA_AllocString(*(void* *)&((struct BtlRecSel *)work)->msgBank,entry);
    *(int *)&((struct BtlRecSel *)work)->windowShown=0;
    PRINTSYS_PrintQue(*(void* *)&((struct BtlRecSel *)work)->printQue[0],BMP_WIN_GetBmp(*(void* *)&((struct BtlRecSel *)work)->win1),0,0,*(void* *)&((struct BtlRecSel *)work)->strbuf,(struct GfFont *)(((struct BtlRecSel *)work)->font));
    BTL_REC_SEL_TryShowEntry((sptr)mgr,(u8 *)work);
}

u32 BTL_REC_SEL_TryShowEntry(int unused,u8 *work){struct Descriptor *d;if(((struct BtlRecSel *)work)->windowShown==0){if(PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)(*(struct PrintSys * *)&((struct BtlRecSel *)work)->printQue[0]),BMP_WIN_GetBmp((struct BmpWin *)(*(struct Descriptor * *)&((struct BtlRecSel *)work)->win1)))==0){d=*(struct Descriptor * *)&((struct BtlRecSel *)work)->win1;BMP_WIN_TransferChars((struct BmpWin *)d);BMP_WIN_MakeScreen((struct BmpWin *)d);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));((struct BtlRecSel *)work)->windowShown=1;}}return ((struct BtlRecSel *)work)->windowShown;}

void BTL_REC_SEL_InitPalette(int unused,char*work)
{
    unsigned off;
    u16*colors;
    off=BG_SYS_CreateRun(1,0x500,1);
    BG_SYS_FreeTileRun(1,off,0x500);
    ARC_UTIL_UploadPaletteFromArchiveWhole(0x17,5,0,0x160,0x20,((struct BtlRecSel *)work)->heap);
    colors=GFL_HEAP_Alloc(((struct BtlRecSel *)work)->heap,6,1,d_021BB658,0x6f9);
    colors[0]=0x294b;colors[1]=0x5694;colors[2]=0x7fff;
    BG_SYS_LoadPltt(2,colors,6,0x17a);
    GFL_HEAP_Free(colors);
    ((struct BtlRecSel *)work)->yesNo.a=1;((struct BtlRecSel *)work)->yesNo.b=0x18;((struct BtlRecSel *)work)->yesNo.c=0xd;((struct BtlRecSel *)work)->yesNo.d=0xb;
    ((struct BtlRecSel *)work)->yesNo.e=off;
}

void BTL_REC_SEL_Noop(int unused, char *work){}

void BTL_REC_SEL_CreateYesNo(int unused,u8 *work){*(struct BmpMenu * *)&((struct BtlRecSel *)work)->yesNoMenu=BMP_MENU_CreateYesNo((const struct WinDat *)&((struct BtlRecSel *)work)->yesNo,((struct BtlRecSel *)work)->frameRun,10,0,((struct BtlRecSel *)work)->heap);}

void BTL_REC_SEL_CreateWindows(int unused,char*work)
{
    Table t=d_021BB480;
    u8 idx;
    for(idx=0;idx<4;idx++){
        ((struct BtlRecSel *)work)->winHandles[idx]=(void *)BMP_WIN_Create(t.r[idx].a,t.r[idx].b,t.r[idx].c,t.r[idx].d,t.r[idx].e,9,t.r[idx].f);
        BMP_Clear(BMP_WIN_GetBmp(((struct BtlRecSel *)work)->winHandles[idx]),0);
        ((struct BtlRecSel *)work)->winShown[idx]=1;
    }
    ((struct BtlRecSel *)work)->lastMode=0;
    ((struct BtlRecSel *)work)->lastValue=0;
}

void BTL_REC_SEL_DeleteWindowList(int unused, char *work)
{
    unsigned char i;
    for (i = 0; i < 4; i++)
    {
        BMP_WIN_Delete(((struct BtlRecSel *)work)->winHandles[i]);
    }
}

/*
 * note: BA794's third argument is narrowed at 021BA49A..A0; caller
 * extern uses u16 despite its own source's unsigned parameter.
 */
void BTL_REC_SEL_TickTimer(struct BtlRecSelMgr *mgr,char*work)
{
    unsigned threshold;
    if(UI_GetFrameRate()==30)threshold=30;else threshold=60;
    if(mgr->isWifi && !((struct BtlRecSel *)work)->busy && (((struct BtlRecSel *)work)->timerA>=threshold || *(int *)&((struct BtlRecSel *)work)->timerB)){
        BTL_REC_SEL_DrawCounter(mgr,(struct BtlRecSel *)work,(u16)(((struct BtlRecSel *)work)->timerA/threshold));
        if(((struct BtlRecSel *)work)->timerA>=threshold){
            --((struct BtlRecSel *)work)->timerA;
            if(((struct BtlRecSel *)work)->timerA==threshold-1)((struct BtlRecSel *)work)->menuOpen=1;
        }else{
            --((struct BtlRecSel *)work)->timerB;
            if(!((struct BtlRecSel *)work)->timerB)BTL_REC_SEL_ResetTimer(mgr,work);
        }
    }
}

/*
 * extent: two bytes zero alignment at 021BA5C6.
 * lever: indexed struct members keep the fixed field offset inside the loop;
 *   raw pointer form was DIFF236/217, integer form DIFF222/66.
 */
void BTL_REC_SEL_ShowWindows(void *unused,struct BtlRecSel *work)
{
    u8 idx;
    struct Descriptor *d;
    for (idx=0;idx<=1;idx++) {
        if (work->winShown[idx]==0) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)(*(struct PrintSys * *)&((struct BtlRecSel *)work)->printQue[1]),BMP_WIN_GetBmp(work->winHandles[idx]))==0) {
                d=work->winHandles[idx];
                BMP_WIN_TransferChars((struct BmpWin *)d);
                BMP_WIN_MakeScreen((struct BmpWin *)d);
                BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));
                work->winShown[idx]=1;
            }
        }
    }
    if (((struct BtlRecSel *)work)->winShown[2]==0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)(*(struct PrintSys * *)&((struct BtlRecSel *)work)->printQue[2]),BMP_WIN_GetBmp(work->winHandles[2]))==0) {
            d=work->winHandles[2];
            BMP_WIN_TransferChars((struct BmpWin *)d);
            BMP_WIN_MakeScreen((struct BmpWin *)d);
            BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));
            ((struct BtlRecSel *)work)->winShown[2]=1;
        }
    }
    if (((struct BtlRecSel *)work)->winShown[3]==0) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)(*(struct PrintSys * *)&((struct BtlRecSel *)work)->printQue[3]),BMP_WIN_GetBmp(work->winHandles[3]))==0) {
            d=work->winHandles[3];
            BMP_WIN_TransferChars((struct BmpWin *)d);
            BMP_WIN_MakeScreen((struct BmpWin *)d);
            BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer((struct BmpWin *)d));
            ((struct BtlRecSel *)work)->winShown[3]=1;
        }
    }
}

void BTL_REC_SEL_PrintList(void*mgr,char*work)
{
    void*h;
    h=MSGDATA_AllocString(*(void* *)&((struct BtlRecSel *)work)->msgBank,19);
    PRINTSYS_PrintQueColor(*(void* *)&((struct BtlRecSel *)work)->printQue[1],BMP_WIN_GetBmp(*(void* *)&((struct BtlRecSel *)work)->winHandles[0]),4,1,h,(struct GfFont *)(((struct BtlRecSel *)work)->font),0x440);
    STRBUF_Delete(h);
    ((struct BtlRecSel *)work)->winShown[0]=0;
    h=MSGDATA_AllocString(*(void* *)&((struct BtlRecSel *)work)->msgBank,((struct BtlRecSel *)work)->msgIndex);
    PRINTSYS_PrintQueColor(*(void* *)&((struct BtlRecSel *)work)->printQue[1],BMP_WIN_GetBmp(*(void* *)&((struct BtlRecSel *)work)->winHandles[1]),4,1,h,(struct GfFont *)(((struct BtlRecSel *)work)->font),0x440);
    STRBUF_Delete(h);
    ((struct BtlRecSel *)work)->winShown[1]=0;
    BTL_REC_SEL_ShowWindows(mgr,(struct BtlRecSel *)work);
}

void BTL_REC_SEL_ClearList(int unused,char*work)
{
    u8 idx;
    void*h;
    for(idx=0;idx<=1;idx++){
        PRINTSYS_QUE_Clear((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[1]));
        BMP_Clear(BMP_WIN_GetBmp(((struct BtlRecSel *)work)->winHandles[idx]),0);
        h=((struct BtlRecSel *)work)->winHandles[idx];
        BMP_WIN_TransferChars(h);
        BMP_WIN_MakeScreen(h);
        BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(h));
        ((struct BtlRecSel *)work)->winShown[idx]=1;
    }
}

void BTL_REC_SEL_StartTimer(void *mgr, char *work, u32 v)
{
    u32 threshold;
    if (UI_GetFrameRate() == 30) threshold = 30;
    else threshold = 60;
    ((struct BtlRecSel *)work)->timerA = threshold * (v + 1) - 1;
    ((struct BtlRecSel *)work)->timerB = threshold >> 1;
    ((struct BtlRecSel *)work)->busy = 0;
    ((struct BtlRecSel *)work)->menuOpen = 0;
    ((struct BtlRecSel *)work)->lastMode = 0;
    ((struct BtlRecSel *)work)->lastValue = 0;
    BTL_REC_SEL_DrawCounter(mgr, (struct BtlRecSel *)work, v);
}

void BTL_REC_SEL_ResetTimer(void*mgr,char*work)
{
    void*h;
    *(int *)&((struct BtlRecSel *)work)->timerA=0;
    *(int *)&((struct BtlRecSel *)work)->timerB=0;
    PRINTSYS_QUE_Clear((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[2]));
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct BtlRecSel *)work)->winHandles[2]),0);
    h=*(void* *)&((struct BtlRecSel *)work)->winHandles[2];
    BMP_WIN_TransferChars(h);BMP_WIN_MakeScreen(h);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(h));
    ((struct BtlRecSel *)work)->winShown[2]=1;
    PRINTSYS_QUE_Clear((struct PrintQueue *)(((struct BtlRecSel *)work)->printQue[3]));
    BMP_Clear(BMP_WIN_GetBmp(*(void* *)&((struct BtlRecSel *)work)->winHandles[3]),0);
    h=*(void* *)&((struct BtlRecSel *)work)->winHandles[3];
    BMP_WIN_TransferChars(h);BMP_WIN_MakeScreen(h);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(h));
    ((struct BtlRecSel *)work)->winShown[3]=1;
    if(((struct BtlRecSel *)work)->flag3C)BTL_REC_SEL_ClearLayer(mgr,work);
    ((struct BtlRecSel *)work)->lastMode=0;
    ((struct BtlRecSel *)work)->lastValue=0;
}

void BTL_REC_SEL_DrawCounter(struct BtlRecSelMgr *mgr, struct BtlRecSel *e, unsigned int v)
{
    int mode;
    int colorFlag;
    sptr win;
    sptr strbuf1;
    sptr bmp1;
    sptr font;
    sptr strbuf2;
    sptr buf;
    sptr bmp2;

    if (mgr->isWifi == 0)
        return;

    if (v > 0xa) {
        colorFlag = 0x440;
        mode = 1;
    } else {
        colorFlag = 0xc80;
        mode = 2;
    }

    if (mode != e->lastMode) {
        win = (sptr)BMP_WIN_GetBmp(e->winHandles[2]);
        BMP_Clear((struct Bmp *)win, 0);
        win = (sptr)BMP_WIN_GetBmp(e->winHandles[3]);
        BMP_Clear((struct Bmp *)win, 0);
    } else if (v != e->lastValue) {
        win = (sptr)BMP_WIN_GetBmp(e->winHandles[3]);
        BMP_Clear((struct Bmp *)win, 0);
    }

    if (mode != e->lastMode) {
        PRINTSYS_QUE_Clear(e->printQue[2]);
        strbuf1 = (sptr)MSGDATA_AllocString(e->msgBank, 0x10);
        bmp1 = (sptr)BMP_WIN_GetBmp(e->winHandles[2]);
        PRINTSYS_PrintQueColor(e->printQue[2], (struct Bmp *)bmp1, 4, 1, (struct Strbuf *)strbuf1, (struct GfFont *)e->font, colorFlag);
        e->winShown[2] = 0;
        STRBUF_Delete((struct Strbuf *)strbuf1);
    }

    if (mode != e->lastMode || v != e->lastValue) {
        font = (sptr)WORDSET_CreateDefault(e->heap);
        strbuf2 = (sptr)MSGDATA_AllocString(e->msgBank, 0x12);
        buf = (sptr)STRBUF_Create(8, e->heap);
        PRINTSYS_QUE_Clear(e->printQue[3]);
        WORDSET_SetSlotNumber((struct WordSet *)font, 1, v, 2, 2, 1);
        WORDSET_CopyTaggedText((struct WordSet *)font, (void *)buf, (void *)strbuf2);
        bmp2 = (sptr)BMP_WIN_GetBmp(e->winHandles[3]);
        PRINTSYS_PrintQueColor(e->printQue[3], (struct Bmp *)bmp2, 2, 2, (struct Strbuf *)buf, (struct GfFont *)e->font, colorFlag);
        e->winShown[3] = 0;
        STRBUF_Delete((struct Strbuf *)buf);
        STRBUF_Delete((struct Strbuf *)strbuf2);
        WORDSET_Delete((struct WordSet *)font);
    }

    e->lastMode = mode;
    e->lastValue = v;
    BTL_REC_SEL_ShowWindows(mgr, (struct BtlRecSel *)e);
}

/*
 * layout: two rows of six 0x28-byte cells, observed nested-loop bounds.
 * prototypes: BAB0C owning matched source; B2A8 own same-region getter.
 * extent: 466-byte function followed by two zero alignment bytes at 021BAAAE.
 * lever: order-byte store inside each branch preserves original address CSE
 * and shared-tail layout; factoring it outside produced 430 bytes / DIFF316.
 */
void BTL_REC_SEL_InitCells(void *unused,struct BtlRecSel *work)
{
    int handle=BTL_REC_SEL_GRAPHIC_GetCamera(work->graphic);
    u8 side,slot;
    for(side=0;side<2;side++) for(slot=0;slot<6;slot++) {
        work->cells[side][slot].gfxId3=0;
        work->cells[side][slot].flag=1;
    }
    for(side=0;side<2;side++) for(slot=0;slot<6;slot++) {
        if(work->mode) {
            if(side==0) { work->cells[side][slot].x=100+24*slot; work->cells[side][slot].y=64; work->cells[side][slot].order=6-slot; }
            else { work->cells[side][slot].x=36+24*slot; work->cells[side][slot].y=112; work->cells[side][slot].order=6-slot; }
        } else {
            if(side==0) {
                if(slot<3) { work->cells[side][slot].x=172+24*slot; work->cells[side][slot].y=64; work->cells[side][slot].order=6-slot; }
                else { work->cells[side][slot].x=172+24*(slot-3); work->cells[side][slot].y=88; work->cells[side][slot].order=6-slot; }
            } else {
                if(slot<3) { work->cells[side][slot].x=36+24*slot; work->cells[side][slot].y=88; work->cells[side][slot].order=6-slot; }
                else { work->cells[side][slot].x=36+24*(slot-3); work->cells[side][slot].y=112; work->cells[side][slot].order=6-slot; }
            }
        }
    }
    for(side=0;side<2;side++) for(slot=0;slot<6;slot++) {
        if(work->cells[side][slot].gfxId0) {
            work->cells[side][slot].actor=BTL_REC_SEL_CreateActor(handle,work->heap,0,0,
                work->cells[side][slot].gfxId0,work->cells[side][slot].gfxId1,work->cells[side][slot].gfxId2,work->cells[side][slot].gfxId3,
                work->cells[side][slot].uiSceneWork,work->cells[side][slot].x,work->cells[side][slot].y,
                work->cells[side][slot].flag,1,work->cells[side][slot].order);
        }
    }
}

void BTL_REC_SEL_DeleteCellActors(int unused, int workAddr)
{
    struct BtlRecSel *w = (struct BtlRecSel *)workAddr;
    unsigned char j, i;

    for (j = 0; j < 2; j++) {
        for (i = 0; i < 6; i++) {
            if (w->cells[j][i].gfxId0 != 0) {
                BTL_REC_SEL_DeleteActor(w->cells[j][i].uiSceneWork, (void *)w->cells[j][i].actor);
            }
        }
    }
}

int BTL_REC_SEL_CreateActor(int sceneId,u16 heap,int mode,u8 shade,u32 gfxId0,u32 gfxId1,u32 gfxId2,u32 gfxId3,void*sceneWork,u8 x,u8 y,u8 flag,u8 bgPriority,u8 drawPriority)
{
    In info;
    sptr actorHandle;
    info.mode=mode;
    info.flag04=1;
    info.flag08=7;
    info.gfxKind=POKE_TOOL_GetIconPaletteArcId();
    info.gfxIndex=POKE_TOOL_CalcGraphicIndex(gfxId0,gfxId1,gfxId2,gfxId3);
    info.gfxExtra0=POKE_TOOL_GetIconCellArcId();
    info.gfxExtra1=POKE_TOOL_GetIconCellEntryId();
    info.paletteSlot=shade;
    info.flag1d=0;
    info.shading=3;
    UI_SCENE_LoadActorGfx(sceneWork,(struct ActorGfxDesc *)(&info),(void *)sceneId,heap);
    actorHandle=(sptr)UI_SCENE_CreateActor(sceneWork,(void *)sceneId,x,y,flag,heap);
    CLACT_SetActorBgPriority((struct ClactActor *)actorHandle,bgPriority);
    CLACT_SetActorDrawPriority((struct ClactActor *)actorHandle,drawPriority);
    CLACT_SetActorAutoAnim((struct ClactActor *)actorHandle,1);
    CLACT_SetActorPaletteOffset((struct ClactActor *)actorHandle,POKE_TOOL_CalcIconPalette(gfxId0,gfxId1,gfxId2,gfxId3),0);
    return actorHandle;
}

/*
 * function_starts: 0x021BABB8
 * note: Cleared BABB8 follower occupies 60 bytes through BABF4. The pools
 * at BABEC/BABF0 point to the two fields of the same byte-pair table.
 */
void BTL_REC_SEL_DeleteActor(void*scene,void*actor)
{
    CLACT_DeleteActor(actor);
    UI_SCENE_FreeActorGfx(scene);
}

void BTL_REC_SEL_SetMode(int unused,char*work)
{
    u8 tableIndex=((struct BtlRecSel *)work)->headerParam;
    if(tableIndex>=0x29)tableIndex=0;
    ((struct BtlRecSel *)work)->msgIndex=d_021BB4C4[tableIndex].a;
    if(d_021BB4C4[tableIndex].b==0)((struct BtlRecSel *)work)->mode=1;
    else ((struct BtlRecSel *)work)->mode=0;
}

void BTL_REC_SEL_InitBgRun(int unused, char *work)
{
    void *h = ARC_TOOL_CreateHandle(188, ((struct BtlRecSel *)work)->heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(h, 0, 0, 0, 320, ((struct BtlRecSel *)work)->heap);
    ((struct BtlRecSel *)work)->bgRunMain = ARC_UTIL_RegisterObjCharFromHandle(h, 1, 2, 0, 0, ((struct BtlRecSel *)work)->heap);
    ARC_TOOL_DeleteHandle(h);
}

void BTL_REC_SEL_DeleteBgRun(int unused,u8 *work){u32 v=((struct BtlRecSel *)work)->bgRunMain;BG_SYS_FreeTileRun(2,(u16)v,(u16)(v>>16));}

void BTL_REC_SEL_InitBgGfx1(int unused,u8 *work){ARC_UTIL_UploadBgPaletteFromArchive(188,2,2,(u16)(((struct BtlRecSel *)work)->bgRunMain),0,0,((struct BtlRecSel *)work)->heap);BG_SYS_MarkTileDirty(2);BG_SYS_ChangeScroll(3,3,0);}

void BTL_REC_SEL_InitBgGfx2(int unused,u8 *work){enum{K=2}k=K;ARC_UTIL_UploadBgPaletteFromArchive(188,3,k,(u16)(((struct BtlRecSel *)work)->bgRunMain),0,0,((struct BtlRecSel *)work)->heap);BG_SYS_MarkTileDirty(2);k-=10;BG_SYS_ChangeScrollImmediate(3,3,k);}

void BTL_REC_SEL_InitBgGfx3(int unused,u8 *work){enum{K=3}k;ARC_UTIL_UploadBgPaletteFromArchive(188,4,2,(u16)(((struct BtlRecSel *)work)->bgRunMain),0,0,((struct BtlRecSel *)work)->heap);BG_SYS_MarkTileDirty(2);k=K;BG_SYS_ChangeScrollImmediate(3,3,k-11);}

void BTL_REC_SEL_ClearLayer(void *work, char *unused){BG_SYS_ClearLayerEx(2,0);}

void BTL_REC_SEL_InitSubBg(void **mgrRef,char *work)
{
    u8 gender;
    int rowIndex,which;
    const u32 *row;
    u32 layer;
    u16 heap;
    void *arc;
    gender=(u8)(u32)MYSTATUS_GetSex((struct MyStatus *)GAME_DATA_GetMyStatus(*mgrRef));
    *(volatile u16 *)0x04001050=0;
    *(volatile u32 *)0x04001000 &=0xFFFF1FFF;
    *(volatile u32 *)0x04001000 |=0x10000;
    BG_SYS_ClearSubPlanes();
    GXS_SetGraphicsMode(0);
    BG_SYS_ClearSubBgPlanes();
    for (rowIndex=0;rowIndex<1U;rowIndex++) {
        row=d_021BB498[rowIndex];
        layer=row[0];
        BG_SYS_InitBgLayer((u8)layer,(const struct BgTemplate *)(row+1),(u8)row[9]);
        BG_SYS_FreeSlot(layer);
        BG_SYS_SetPlaneVisible(layer,row[10]);
    }
    BG_SYS_SetSubPlaneVisible(16,1);
    heap=((struct BtlRecSel *)work)->heap;
    which=1;
    if (gender!=1) which=0;
    arc=ARC_TOOL_CreateHandle(30,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,d_021BB640[which][0],4,0,0,heap);
    ARC_UTIL_UploadBgCharFromHandle(arc,d_021BB640[which][1],4,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,d_021BB640[which][2],4,0,0,0,heap);
    ARC_TOOL_DeleteHandle(arc);
    BG_SYS_PushTile(4);
}

static inline void GXS_SetVisibleWnd(int window){*(volatile u32 *)REG_DB_DISPCNT_ADDR=(*(volatile u32 *)REG_DB_DISPCNT_ADDR&~0xe000u)|(window<<13);}

/*
 * volatile: hardware registers 0x04001050 (021BAE30), 0x04001000 read/write (021BAE34/021BAE3A).
 */
void BTL_REC_SEL_DeleteSubBg(int unused, char *work){int i;for(i=0;i<1u;i++)BG_SYS_FreeLayerBuf(d_021BB498[i][0]);*(volatile u16 *)REG_DB_BLDCNT_ADDR=0;GXS_SetVisibleWnd(0);}

void BTL_REC_SEL_CreateUiActor(int unused,u8 *work){*(int *)&((struct BtlRecSel *)work)->actor=BTL_REC_SEL_CreateActor(BTL_REC_SEL_GRAPHIC_GetCamera(*(u8 * *)&((struct BtlRecSel *)work)->graphic),((struct BtlRecSel *)work)->heap,0,0,1,0,0,0,((struct BtlRecSel *)work)->uiSceneWork,0,0,0,1,1);}

void BTL_REC_SEL_DeleteUiActor(int unused,u8 *work){BTL_REC_SEL_DeleteActor(((struct BtlRecSel *)work)->uiSceneWork,((struct BtlRecSel *)work)->actor);}

void BTL_REC_SEL_InitPalanm(int unused,char *work)
{
    ((struct BtlRecSel *)work)->palBuf=GFL_HEAP_Alloc(((struct BtlRecSel *)work)->heap,TCB_GetTaskOffset(2),1,d_021BB658,2403);
    ((struct BtlRecSel *)work)->tcb=TCB_Init(2,((struct BtlRecSel *)work)->palBuf);
    ((struct BtlRecSel *)work)->palanm=PALANM_Create(((struct BtlRecSel *)work)->heap);
    PALANM_SetAutoTransfer(((struct BtlRecSel *)work)->palanm,1);
    PALANM_AllocSlotBuffers(((struct BtlRecSel *)work)->palanm,0,448,((struct BtlRecSel *)work)->heap);
    PALANM_AllocSlotBuffers(((struct BtlRecSel *)work)->palanm,2,448,((struct BtlRecSel *)work)->heap);
    PALANM_CopyHwPaletteToSlot(((struct BtlRecSel *)work)->palanm,0,0,448);
    PALANM_CopyHwPaletteToSlot(((struct BtlRecSel *)work)->palanm,2,0,448);
    ((struct BtlRecSel *)work)->fadeState=2;
    ((struct BtlRecSel *)work)->fadeRequest=0;
}

void BTL_REC_SEL_DeletePalanm(int unused,u8 *work){PALANM_FreeSlotBuffers(*(struct PaletteFade * *)&((struct BtlRecSel *)work)->palanm,0);PALANM_FreeSlotBuffers(*(struct PaletteFade * *)&((struct BtlRecSel *)work)->palanm,2);PALANM_Delete(((struct BtlRecSel *)work)->palanm);TCB_Noop(((struct BtlRecSel *)work)->tcb);GFL_HEAP_Free(((struct BtlRecSel *)work)->palBuf);}

/*
 * prototype: 0202173C's third parameter is widened to the observed full-word
 *   caller payload; own u16 declaration inserted four extra truncation pairs.
 *   Both fixed-flag TU runs preserve its low-halfword colour; widening gives EXACT368.
 * extent: lead and tail-call follower 021BB0C4.
 */
void BTL_REC_SEL_FadeMain(void *unused,struct BtlRecSel *work)
{
    u32 mask;
    u8 bit;
    TCB_Main(work->tcb);
    if (PALANM_GetFadeRequestBits(work->palanm)!=0) return;
    switch (work->fadeState) {
    case 1: work->fadeState=2; break;
    case 3: work->fadeState=0; break;
    }
    switch (work->fadeRequest) {
    case 1:
        if (work->fadeState==1) return;
        mask=0;
        for (bit=0;bit<14;bit++) mask|=(u16)(1<<bit);
        PALANM_RequestFade((struct PaletteFade *)work->palanm,1,mask,-2,16,0,0,work->tcb);
        mask=0;
        for (bit=0;bit<14;bit++) mask|=(u16)(1<<bit);
        PALANM_RequestFade((struct PaletteFade *)work->palanm,4,mask,-2,16,0,0,work->tcb);
        work->fadeState=1;
        work->fadeRequest=0;
        return;
    case 2:
        if (work->fadeState==3) break;
        mask=0;
        for (bit=0;bit<14;bit++) mask|=(u16)(1<<bit);
        PALANM_RequestFade((struct PaletteFade *)work->palanm,1,mask,-2,0,16,0,work->tcb);
        mask=0;
        for (bit=0;bit<14;bit++) mask|=(u16)(1<<bit);
        PALANM_RequestFade((struct PaletteFade *)work->palanm,4,mask,-2,0,16,0,work->tcb);
        work->fadeState=3;
        work->fadeRequest=0;
        break;
    }
}

void BTL_REC_SEL_TransferPalettes(char *work)
{
    PALANM_TransferPalettes(*(struct PaletteFade * *)&((struct BtlRecSel *)work)->palanm);
}

static inline void G2_SetBG0Priority(int priority)
{
    *(volatile u16 *)0x04000008=(u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}

static inline void G3X_SetShading(GXShading shading)
{
    REG3D=(u16)((REG3D & ~(2|0x3000)) | (shading<<1));
}

static inline void G3X_AntiAlias(int enable)
{
    if(enable) REG3D=(u16)((REG3D & ~0x3000)|16);
    else REG3D &= (u16)~(16|0x3000);
}

static inline void G3X_AlphaTest(int enable,int ref)
{
    if(enable) { REG3D=(u16)((REG3D & ~0x3000)|4); *(volatile u16 *)REG_ALPHA_TEST_REF_ADDR=(u16)ref; }
    else REG3D &= (u16)~(4|0x3000);
}

static inline void G3X_AlphaBlend(int enable)
{
    if(enable) REG3D=(u16)((REG3D & ~0x3000)|8);
    else REG3D &= (u16)~(8|0x3000);
}

static inline void G3X_EdgeMarking(int enable)
{
    if(enable) REG3D=(u16)((REG3D & ~0x3000)|32);
    else REG3D &= (u16)~(32|0x3000);
}

void BTL_REC_SEL_InitG3dDisplay(void)
{
    u32 light;
    BG_SYS_SetMainPlaneVisible(1,1);
    G2_SetBG0Priority(0);
    G3X_SetShading(GX_SHADING_HIGHLIGHT);
    G3X_AntiAlias(0);
    G3X_AlphaTest(0,0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,32767,63,0);
    *(volatile u32 *)0x04000580=0xBFFF0000;
    for(light=0;light<4;light++) G3D_SYSTEM_SetLight((u8)light,(struct G3dLight *)(&rects[light]));
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
