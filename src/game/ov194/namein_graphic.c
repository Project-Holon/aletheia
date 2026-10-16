/*
 * file:     namein_graphic.c
 * unit:     yes
 * function: NAMEIN_GRAPHIC_SymbolGetValue, NAMEIN_GRAPHIC_InitGrid, NAMEIN_GRAPHIC_DeleteGrid, NAMEIN_GRAPHIC_UpdateGrid, NAMEIN_GRAPHIC_GetGridAction, NAMEIN_GRAPHIC_GetGridIndex, NAMEIN_GRAPHIC_IsGridDrawDone, NAMEIN_GRAPHIC_GetGridMode, NAMEIN_GRAPHIC_GridIndex, NAMEIN_GRAPHIC_SetGridMode, NAMEIN_GRAPHIC_AnimateGrid, NAMEIN_GRAPHIC_SwitchGridMode, NAMEIN_GRAPHIC_SetGridSelection, NAMEIN_GRAPHIC_KanaKeyMove, NAMEIN_GRAPHIC_KanaKeyAction, NAMEIN_GRAPHIC_KanaTouch, NAMEIN_GRAPHIC_ApplyKanaAction, NAMEIN_GRAPHIC_SymbolKeyMove, NAMEIN_GRAPHIC_SymbolKeyAction, NAMEIN_GRAPHIC_SymbolTouch, NAMEIN_GRAPHIC_ApplySymbolAction, NAMEIN_GRAPHIC_InitMsgBox, NAMEIN_GRAPHIC_DeleteMsgBox, NAMEIN_GRAPHIC_PrintMsg, NAMEIN_GRAPHIC_PrintPokeMsg, NAMEIN_GRAPHIC_PrintMonMsg, NAMEIN_GRAPHIC_IsMsgDrawDone, NAMEIN_GRAPHIC_InitTcbl, NAMEIN_GRAPHIC_DeleteTcbl, NAMEIN_GRAPHIC_PrintNameStream, NAMEIN_GRAPHIC_InitIconActor, NAMEIN_GRAPHIC_DeleteIconActor, NAMEIN_GRAPHIC_UpdateIconTouch, NAMEIN_GRAPHIC_FlushIconOam, NAMEIN_GRAPHIC_IsIconAnimDone, NAMEIN_GRAPHIC_StartIconAnim, NAMEIN_GRAPHIC_StepIconAnim, NAMEIN_GRAPHIC_GetIconMode, NAMEIN_GRAPHIC_IsPointInRect, NAMEIN_GRAPHIC_GetNameForAction, NAMEIN_GRAPHIC_CommitName, NAMEIN_GRAPHIC_IsNameValid, NAMEIN_GRAPHIC_InitCallback, NAMEIN_GRAPHIC_ClearCallback, NAMEIN_GRAPHIC_RunCallback, NAMEIN_GRAPHIC_GetCallbackState, NAMEIN_GRAPHIC_SetCallback, NAMEIN_GRAPHIC_FinishCallback, NAMEIN_GRAPHIC_CallbackWaitDraw, NAMEIN_GRAPHIC_CallbackFadeIn, NAMEIN_GRAPHIC_CallbackFadeOut, NAMEIN_GRAPHIC_CallbackWaitPrint, NAMEIN_GRAPHIC_CallbackGridAction, NAMEIN_GRAPHIC_CallbackFinish, NAMEIN_GRAPHIC_CallbackPauseSave, NAMEIN_GRAPHIC_CreateDisplay, NAMEIN_GRAPHIC_DeleteDisplay, NAMEIN_GRAPHIC_DrawDisplay, NAMEIN_GRAPHIC_GetDisplayHandle, NAMEIN_GRAPHIC_DisplayMainTask, NAMEIN_GRAPHIC_InitBg, NAMEIN_GRAPHIC_ExitBg, NAMEIN_GRAPHIC_Empty, NAMEIN_GRAPHIC_ResetBg, NAMEIN_GRAPHIC_InitClact, NAMEIN_GRAPHIC_ExitClact, NAMEIN_GRAPHIC_DrawClact, NAMEIN_GRAPHIC_VBlankClact, NAMEIN_GRAPHIC_LoadWord
 * address:  0x021F2F8C
 * region:   ov194
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from namein_graphic_p03.c by tools/splitfile.py.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   ARC_UTIL_LoadPaletteDataFromArchive 0x02049EB4 arm
 *   BG_SYS_DecodeTile 0x02040AE0 arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   NAMEIN_GRAPHIC_InitCursor 0x021F19A0 thumb ov194
 *   NAMEIN_GRAPHIC_InitPicker 0x021F256C thumb ov194
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   NAMEIN_GRAPHIC_DrawCellTips 0x021F26F0 thumb ov194
 *   UI_GetInputMode 0x020355C4 arm
 *   NAMEIN_GRAPHIC_PickerGetBox 0x021F2818 thumb ov194
 *   NAMEIN_GRAPHIC_SetupCursor 0x021F1A1C thumb ov194
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   NAMEIN_GRAPHIC_ClearPicker 0x021F2608 thumb ov194
 *   NAMEIN_GRAPHIC_ClearCursor 0x021F1A10 thumb ov194
 *   NAMEIN_GRAPHIC_IsFieldFull 0x021F23E4 thumb ov194
 *   NAMEIN_GRAPHIC_FindCellByValue 0x021F2828 thumb ov194
 *   NAMEIN_GRAPHIC_UpdateCursor 0x021F1BFC thumb ov194
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   func_02040804 0x02040804 arm
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   BMP_Clear 0x02043B5C arm
 *   NAMEIN_GRAPHIC_ConvertCellMode 0x021F2884 thumb ov194
 *   NAMEIN_GRAPHIC_LoadGrid 0x021F25F8 thumb ov194
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   NAMEIN_GRAPHIC_PickerMove 0x021F26E0 thumb ov194
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   NAMEIN_GRAPHIC_FindCellAtPoint 0x021F265C thumb ov194
 *   NAMEIN_GRAPHIC_PickerToChar 0x021F2614 thumb ov194
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   func_02045CAC 0x02045CAC arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   WORDSET_SetSlotMonName 0x0201EE84 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Create  0x0203101C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMonSpecies 0x0201EEF4 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   WORDSET_SetSlotBoxName 0x0201F164 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   STRBUF_Clone 0x02045874 arm
 *   STRBUF_Clear 0x0204581C arm
 *   NAMEIN_SETUP_CopyName 0x0216C0D4 thumb ov010
 *   NAMEIN_SETUP_IsCanceled 0x0216C0E4 thumb ov010
 *   APP_ICON_GetArchiveId  0x020275E4  thumb
 *   APP_ICON_GetItemDataFileId  0x020276A4  thumb
 *   APP_ICON_GetItemExtraFileId  0x020276A8  thumb
 *   APP_ICON_GetItemAnim2FileId  0x020276AC  thumb
 *   APP_ICON_GetItemFrame2FileId  0x020276B0  thumb
 *   POKE_TOOL_GetIconPaletteArcId  0x0201BC3C  thumb
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   POKE_TOOL_GetIconCellArcId  0x0201BC40  thumb
 *   POKE_TOOL_GetIconCellEntryId  0x0201BCB4  thumb
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   CLACT_RegisterPaletteCompressed  0x0204ACEC  arm
 *   CLACT_RegisterPaletteEx  0x0204AC18  arm
 *   CLACT_RegisterCellAnim  0x0204AF28  arm
 *   CLACT_RegisterCharacter  0x0204A6C8  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   CLACT_CreateActor  0x0204B294  arm
 *   CLACT_SetActorAutoAnim  0x0204B92C  arm
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 *   BMP_Create  0x02043678  arm
 *   BMP_OAM_Create  0x020255A0  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   d_021F5569     0x021F5569  data ov194
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   BMP_OAM_Delete 0x0202570C thumb
 *   BMP_Delete 0x020437AC arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   FX_SinCosTable_ 0x020A1B38 data a4
 *   STRBUF_GetLength  0x020458F8  arm
 *   gSpeciesNameBank     0x020A7370  data
 *   NAMEIN_GRAPHIC_CopyToStrbuf 0x021F2328 thumb ov194
 *   STRBUF_IsEqual 0x0204589C arm
 *   NAMEIN_GRAPHIC_HasNonSpace 0x021F253C thumb ov194
 *   STRBUF_Copy 0x02045838 arm
 *   NAMEIN_GRAPHIC_GetLength 0x021F23F4 thumb
 *   NAMEIN_GRAPHIC_GetSecondaryLength 0x021F23F8 thumb
 *   NAMEIN_GRAPHIC_IsFieldDrawDone 0x021F22E8 thumb ov194
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_PrintStreamGetState 0x0201CE30 thumb
 *   KEY_GetCont 0x0203630C arm
 *   TOUCHPANEL_GetCont 0x02035C38 arm
 *   PRINTSYS_PrintStreamShortWait 0x0201CE5C thumb
 *   UI_SetInputMode 0x020355D8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   PRINTSYS_PrintStreamReleasePause 0x0201CE38 thumb
 *   NAMEIN_GRAPHIC_AppendChar 0x021F2190 thumb ov194
 *   NAMEIN_GRAPHIC_AppendCandidate 0x021F21BC thumb ov194
 *   NAMEIN_GRAPHIC_ApplyConversion 0x021F21FC thumb ov194
 *   NAMEIN_GRAPHIC_RevertChar 0x021F22AC thumb ov194
 *   NAMEIN_GRAPHIC_Backspace 0x021F2150 thumb ov194
 *   NAMEIN_GRAPHIC_ClearSecondary 0x021F233C thumb ov194
 *   NAMEIN_GRAPHIC_CommitSecondary 0x021F235C thumb ov194
 *   PROF_WORD_FindMatch 0x021F5370 thumb ov194
 *   PROF_WORD_CheckDigitCount 0x021F54CC thumb ov194
 *   NAMEIN_GRAPHIC_ClearPrimary 0x021F2394 thumb ov194
 *   NAMEIN_GRAPHIC_AppendString 0x021F23B8 thumb ov194
 *   NAMEIN_GRAPHIC_RefreshInputField 0x021F1FB4 thumb ov194
 *   STRBUF_GetChars 0x02045A90 arm
 *   BEACON_SetInputFlag 0x0200C0FC thumb
 *   SAVE_CONTROL_INTR_Pause 0x021BD368 thumb ov088
 *   SAVE_CONTROL_INTR_IsPausedOrFinished 0x021BD380 thumb ov088
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   d_021F5784 0x021F5784 data a1
 *   d_021F55D0 0x021F55D0 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021F55A4 0x021F55A4 data a4
 *   d_021F5600 0x021F5600 data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_ExitSystem  0x0204A5AC  arm  arm9
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *   CLACT_VBlankSystem  0x0204A648  arm  arm9
 *   CLACT_DeleteUnit  0x0204B1CC  arm  arm9
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 *   NAMEIN_GRAPHIC_LoadIconMember 0x021F51E4 thumb ov194
 */
#include "namein_graphic_shared_types.h"

#define OBJ(p) (*(char **)((p) + 0x2C4))

struct Descriptor;

struct Cfg;

struct Rect;

struct PrintSys;

struct CharBuf;

struct U16Vec;

struct MsgBank;

struct WordSet;

struct S02031140;

struct Rec3;

struct Bmp;

struct Grid;

struct Obj;

struct Param;

struct Sys;

struct Actor;

struct PtS;

struct Vec2;

struct Buf;

struct Strbuf;

struct Tcbl;

struct Rec;

struct Blk34;

struct DispVram;

struct Node;

struct DispConfig;

struct Bank;

typedef struct {int x,y;} Pair;

typedef struct {int x,y,z,w;} Box;

typedef struct {int left,top,right,bottom;} Rect;

typedef signed short s16;

typedef unsigned long long u64;

typedef signed int s32;

typedef struct {u16 w;u16 h;u32 pad;} Dim8;

typedef struct {short x,y;} Vec2;

typedef void (*NameinGraphicCallbackFn)(u8 *, u8 *, u32);

typedef struct {unsigned words[4];} Disp;

typedef struct {unsigned words[8];} Bg;

typedef struct {unsigned id;Bg config;unsigned type,enabled;} Entry;

/* The caller's parameter block reached from the work at 0x2C4. */
typedef struct NameinGraphicConfig {
    unsigned int mode;              /* 0x00 */
    unsigned short valueA;          /* 0x04 species id or kind */
    unsigned short valueB;          /* 0x06 form or variant */
    void *mon;                      /* 0x08 mon record, 0 for a plain name */
    unsigned int hasName;           /* 0x0C non-zero when the mon carries a name */
    unsigned char pad_10[8];
    unsigned int maxLength;         /* 0x18 name length limit */
    unsigned int accepted;          /* 0x1C name accepted flag */
    struct U16Vec *name;            /* 0x20 current name string */
    unsigned char *saveControl;     /* 0x24 save-control block */
    struct Blk34 *inputFlag;        /* 0x28 input-flag block */
} NameinGraphicConfig;

/* The kana/symbol grid work (the 0x130 block at work+0xFC). */
typedef struct NameinGraphicGrid {
    unsigned char picker[0x24];      /* 0x00 picker, see NAMEIN_GRAPHIC_InitPicker */
    unsigned char cursor[0xB4];      /* 0x24 kana/symbol cursor */
    int selectionX;                  /* 0xD8 selected cell x */
    int selectionY;                  /* 0xDC selected cell y */
    void *bmpWin;                    /* 0xE0 cell-tip bmp window */
    int state;                       /* 0xE4 input state (kana, symbol, commit) */
    int action;                      /* 0xE8 action returned by NAMEIN_GRAPHIC_GetGridAction */
    void *tipBmp;                    /* 0xEC cell-tip bmp, same window as bmpWin */
    unsigned char tipDirty;          /* 0xF0 */
    unsigned char pad_F1[3];
    void *font;                      /* 0xF4 */
    void *printSys;                  /* 0xF8 */
    unsigned short actionValue;      /* 0xFC */
    unsigned short heap;             /* 0xFE */
    int mode;                        /* 0x100 */
    int index;                       /* 0x104 */
    unsigned char variant;           /* 0x108 */
    unsigned char pad_109[1];
    unsigned short animTick;         /* 0x10A */
    unsigned short animPhase;        /* 0x10C */
    unsigned char pad_10E[2];
    int animActive;                  /* 0x110 */
    int targetMode;                  /* 0x114 */
    int extraLayer;                  /* 0x118 */
    void *paletteHandleA;            /* 0x11C */
    void *paletteHandleB;            /* 0x120 */
    void *paletteDataA;              /* 0x124 */
    void *paletteDataB;              /* 0x128 */
    void *data;                      /* 0x12C */
} NameinGraphicGrid;

/* The name-entry message box (the 0x24 block at work+0x230). */
typedef struct NameinGraphicMsgBox {
    void *bank;                      /* 0x00 message bank */
    unsigned int field4;             /* 0x04 text colour */
    void *bmp;                       /* 0x08 bmp used by the printer */
    unsigned char dirty;             /* 0x0C */
    unsigned char pad_0D[3];
    void *printSys;                  /* 0x10 */
    void *win;                       /* 0x14 bmp window */
    void *wordSet;                   /* 0x18 word set */
    void *strbuf;                    /* 0x1C scratch string buffer */
    unsigned short color;            /* 0x20 fill colour */
    unsigned char pad_22[2];
} NameinGraphicMsgBox;

/* The text-control block (the 0x10 block at work+0x254). */
typedef struct NameinGraphicTcbl {
    void *stream;                    /* 0x00 print stream */
    void *handle;                    /* 0x04 tcbl handle */
    unsigned int callback;           /* 0x08 callback address */
    unsigned short counter;          /* 0x0C */
    unsigned short flag;             /* 0x0E */
} NameinGraphicTcbl;

/* The icon actor work (the 0x3C block at work+0x264). */
typedef struct NameinGraphicIcon {
    void *actor;                     /* 0x00 */
    unsigned int field4;             /* 0x04 */
    unsigned int palette;            /* 0x08 */
    unsigned int character;          /* 0x0C */
    unsigned int cellAnim;           /* 0x10 */
    int state;                       /* 0x14 */
    int touchMode;                   /* 0x18 */
    int animActive;                  /* 0x1C */
    unsigned short animTick;         /* 0x20 */
    unsigned char pad_22[2];
    unsigned int palette2;           /* 0x24 */
    void *text;                      /* 0x28 */
    void *oam;                       /* 0x2C */
    void *bmp;                       /* 0x30 */
    int oamDirty;                    /* 0x34 */
    void *printSys;                  /* 0x38 */
} NameinGraphicIcon;

/* The callback block (the 0x10 block at work+0x2A0). */
typedef struct NameinGraphicCallback {
    unsigned int fn;                 /* 0x00 */
    unsigned int state;              /* 0x04 */
    unsigned int arg;                /* 0x08 */
    unsigned int owner;              /* 0x0C */
} NameinGraphicCallback;

/* The CLACT sub-object of the display (display+0x04). */
typedef struct NameinGraphicClact {
    void *unit;                      /* 0x00 */
} NameinGraphicClact;

/* The display object created by NAMEIN_GRAPHIC_CreateDisplay. */
typedef struct NameinGraphicDisplay {
    void *bg;                        /* 0x00 */
    void *clactUnit;                 /* 0x04 */
    unsigned int field8;             /* 0x08 */
    void *mainTask;                  /* 0x0C */
} NameinGraphicDisplay;

/* A screen point (the two-int argument of NAMEIN_GRAPHIC_IsPointInRect). */
typedef struct NameinGraphicPoint {
    unsigned int x;                  /* 0x00 */
    unsigned int y;                  /* 0x04 */
} NameinGraphicPoint;

/* A screen rectangle (the four-int argument of NAMEIN_GRAPHIC_IsPointInRect). */
typedef struct NameinGraphicRect4 {
    unsigned int left;               /* 0x00 */
    unsigned int top;                /* 0x04 */
    unsigned int right;              /* 0x08 */
    unsigned int bottom;             /* 0x0C */
} NameinGraphicRect4;

/* The name-entry screen work (partial view used by p03). */
typedef struct NameinGraphicWork {
    unsigned char pad_0[0x86];
    unsigned short primaryLength;    /* 0x86 input-field primary length */
    unsigned char pad_88[0x23C];
    NameinGraphicConfig *args;       /* 0x2C4 */
    int pendingMsg;                  /* 0x2C8 */
    void *profWord;                  /* 0x2CC */
    struct U16Vec *nameStrbuf;       /* 0x2D0 */
} NameinGraphicWork;

extern void MI_CpuFill8(void *,unsigned,unsigned);

extern void *ARC_UTIL_LoadPaletteDataFromArchive(u32,u32,u32,u32,u32);

extern void BG_SYS_DecodeTile(u32,const void *,u32);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void BG_SYS_PushTile(u32);

extern void NAMEIN_GRAPHIC_InitCursor(u8 *,void *,void *,u32);

extern void NAMEIN_GRAPHIC_InitPicker(char *,unsigned,int,void *,u32);

extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);

extern void BMP_WIN_TransferChars(struct Descriptor *d);

extern void BMP_WIN_MakeScreen(struct Cfg *cfg);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);

extern void NAMEIN_GRAPHIC_DrawCellTips(char *,char *,void *,void *,u32);

extern u8 UI_GetInputMode(void);

extern int NAMEIN_GRAPHIC_PickerGetBox(char *,Pair *,Box *);

extern void NAMEIN_GRAPHIC_SetupCursor(char *p, int mode, const struct Rect *rect, int flag, int selected);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern u32 GFL_HEAP_Free(void *p);

extern void NAMEIN_GRAPHIC_ClearPicker(void *);

extern void NAMEIN_GRAPHIC_ClearCursor(void *);

extern int NAMEIN_GRAPHIC_FindCellByValue(const char *,int,Pair *);

extern void NAMEIN_GRAPHIC_UpdateCursor(char *p, int sel, const void *rect);

extern void *BMP_WIN_GetBmp(struct Descriptor *);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void G2x_SetBlendAlpha_(void *,int,int,int,int);

extern u32 func_02040804(u32 layer);

extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);

extern void BMP_Clear(struct CharBuf *buf, u8 value);

extern void NAMEIN_GRAPHIC_ConvertCellMode(Pair *,int,int);

extern void NAMEIN_GRAPHIC_LoadGrid(int *,int,int);

extern unsigned KEY_GetRepeat(void);

extern unsigned KEY_GetTrg(void);

extern void func_020355D8(u8);

extern void GFL_USE_PlaySeDefaultVolume(unsigned);

extern void NAMEIN_GRAPHIC_PickerMove(char *,int,int);

extern unsigned TOUCHPANEL_GetPointTrg(unsigned *,unsigned *);

extern int NAMEIN_GRAPHIC_FindCellAtPoint(const char *,int *,Pair *);

extern unsigned NAMEIN_GRAPHIC_PickerToChar(char *,int *,unsigned short *);

extern struct U16Vec *STRBUF_Create(unsigned int capacity, unsigned int heapId);

extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

extern void STRBUF_Delete(struct U16Vec *vec);

extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);

extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);

/* Callee species is u16; this caller passes r2 without truncation. */
extern void *POKE_TOOL_Create(u32,u16,u64,u16);

extern void POKE_TOOL_SetPartyValue(void *,u32,u32);

extern void WORDSET_SetSlotMonName(struct WordSet *p, u32 i, void *mon);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);

extern void *TCBL_Create(int, int, int, int);

extern void PRINTSYS_PrintStreamDelete(int);

extern void TCBL_Destroy(struct S02031140 *);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern int NAMEIN_SETUP_IsCanceled(int *);

extern void NAMEIN_SETUP_CopyName(int *,int);

extern void WORDSET_SetSlotMonSpecies(struct WordSet *p, u32 i, void *mon);

extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);

extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);

extern void WORDSET_SetSlotBoxName(struct WordSet *p, u32 i, u32 a, u32 b);

extern void STRBUF_Clear(struct U16Vec *vec);

extern signed char MSG_SPEED_GetWait(void);

/* The caller consumes R0 returned by the legacy void forwarding wrapper. */
extern int PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);

extern u32  APP_ICON_GetArchiveId(void);

extern u32  APP_ICON_GetItemDataFileId(void);

extern u32  APP_ICON_GetItemExtraFileId(void);

extern u32  APP_ICON_GetItemAnim2FileId(u32 a);

extern u32  APP_ICON_GetItemFrame2FileId(u32 a);

extern int POKE_TOOL_GetIconPaletteArcId(void);

extern u32  POKE_TOOL_CalcGraphicIndex(u32 a, u32 b, u32 c, u32 d);

extern int POKE_TOOL_GetIconCellArcId(void);

extern int POKE_TOOL_GetIconCellEntryId(void);

extern u32  POKE_TOOL_CalcIconPalette(u32 a, u32 b, u32 c, u32 d);

extern void *ARC_TOOL_CreateHandle(unsigned,u16);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern void ARC_TOOL_DeleteHandle(void *h);

extern struct Obj *CLACT_CreateActor(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);

extern void CLACT_SetActorAutoAnim(struct Obj *p, u32 v);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern struct Grid *BMP_OAM_Create(struct Sys *sys, const struct Param *param);

extern void PRINTSYS_PrintQueColor(u32 a, void *b, s16 c, u32 d, void *e, u32 f, u32 g);

extern void CLACT_ReleasePalette(u32 i);

extern void BMP_OAM_Delete(struct Grid *g);

extern void BMP_Delete(struct Bmp *p);

extern void CLACT_ReleaseCharacter(u32 i);

extern void CLACT_ReleaseCellAnim(u32 i);

extern void CLACT_DeleteActor(struct Obj *p);

extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);

extern void BMP_OAM_UploadChars(struct Obj *);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern u16 STRBUF_GetLength(struct U16Vec *vec);

extern void NAMEIN_GRAPHIC_CopyToStrbuf(char *,struct Strbuf *);

extern int STRBUF_IsEqual(struct Buf *a, struct Buf *b);

extern int NAMEIN_GRAPHIC_HasNonSpace(u8 *p);

extern void STRBUF_Copy(struct U16Vec *dst, struct U16Vec *src);

extern u32 NAMEIN_GRAPHIC_GetLength(const u8 *p);

extern u32 NAMEIN_GRAPHIC_GetSecondaryLength(const u8 *p);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern int FADE_IsActive(void);

extern void TCBL_Main(struct Tcbl *);

extern unsigned PRINTSYS_PrintStreamGetState(void *);

extern unsigned int KEY_GetCont(void);

extern int TOUCHPANEL_GetCont(void);

extern void PRINTSYS_PrintStreamShortWait(struct Rec *, int);

extern void UI_SetInputMode(unsigned char);

extern int TOUCHPANEL_GetTrg(void);

extern void PRINTSYS_PrintStreamReleasePause(void *);

extern int NAMEIN_GRAPHIC_AppendChar(char *,u16);

extern int NAMEIN_GRAPHIC_AppendCandidate(unsigned char *p, unsigned short a, u32 b);

extern int NAMEIN_GRAPHIC_ApplyConversion(unsigned char *a, int b);

extern int NAMEIN_GRAPHIC_RevertChar(char *);

extern int NAMEIN_GRAPHIC_Backspace(unsigned char *p);

extern void NAMEIN_GRAPHIC_ClearSecondary(char *);

extern void NAMEIN_GRAPHIC_CommitSecondary(char *);

extern void NAMEIN_GRAPHIC_ClearPrimary(unsigned char *p);

extern void NAMEIN_GRAPHIC_AppendString(char *p, const u16 *q);

extern int PROF_WORD_FindMatch(const u32 *cache, const void *input, u16 heap);

extern int PROF_WORD_CheckDigitCount(void *,int,int);

extern u16 *STRBUF_GetChars(struct U16Vec *vec);

extern int NAMEIN_GRAPHIC_RefreshInputField(u8 *p);

extern void BEACON_SetInputFlag(struct Blk34 *p, u32 i, u8 v);

extern void SAVE_CONTROL_INTR_Pause(unsigned char *);

extern int SAVE_CONTROL_INTR_IsPausedOrFinished(unsigned char *);

extern void *GFL_HEAP_Alloc(unsigned, unsigned, int, const char *, unsigned short);

extern void BG_SYS_ClearGraphicsMemory(unsigned);

extern void BG_SYS_SetVramBanks(const struct DispVram *);

extern void BMP_SetDisplaySwap(unsigned);

extern void BG_SYS_ResetSubDisplay(void);

extern void BG_SYS_ClearMainPlanes(void);

extern void BG_SYS_ClearSubPlanes(void);

extern void GF_FONT_InitTextColor(void);

extern void *GFL_USE_AddMainTask(unsigned, unsigned, unsigned);

extern void TCB_DeleteTask(struct Node *);

extern void GF_FONT_SetDefaultTextColor(void);

extern void BG_SYS_Create(unsigned short);

extern void BMP_WIN_Init(unsigned short);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_InitBgLayer(unsigned char, const Bg *, unsigned char);

extern void BG_SYS_FreeSlot(unsigned char);

extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Delete(void);

extern void BG_SYS_Update(void);

extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, unsigned int heapId);

extern void CLACT_SetUnitDefaultRenderer(struct Bank *bank);

extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);

extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern void CLACT_ExitSystem(void);

extern void CLACT_DrawSystem(void);

extern void CLACT_VBlankSystem(void);

int NAMEIN_GRAPHIC_SymbolGetValue(Pair *p,Pair *out);

void NAMEIN_GRAPHIC_InitGrid(u8 *p,int mode,void *font,void *window,void *data,void *palette,u32 heap);

void NAMEIN_GRAPHIC_DeleteGrid(u8 *p);

void NAMEIN_GRAPHIC_UpdateGrid(char *p,char *q);

int NAMEIN_GRAPHIC_GetGridAction(char *p, unsigned short *out);

u32 NAMEIN_GRAPHIC_GetGridIndex(const u8 *p);

int NAMEIN_GRAPHIC_IsGridDrawDone(char *p);

void *NAMEIN_GRAPHIC_GetGridMode(const u8 *p);

u32 NAMEIN_GRAPHIC_GridIndex(u32 a,u32 b,u32 c);

int NAMEIN_GRAPHIC_SetGridMode(char *p,int mode);

int NAMEIN_GRAPHIC_AnimateGrid(char *p);

void NAMEIN_GRAPHIC_SwitchGridMode(char *p, u32 mode);

void NAMEIN_GRAPHIC_SetGridSelection(char *p,int index,int variant);

int NAMEIN_GRAPHIC_KanaKeyMove(char *p,int *out);

int NAMEIN_GRAPHIC_KanaKeyAction(char *p,int *out);

int NAMEIN_GRAPHIC_KanaTouch(char *p,int *out);

void NAMEIN_GRAPHIC_ApplyKanaAction(char *p,int *input);

int NAMEIN_GRAPHIC_SymbolKeyMove(char *p,int *out);

int NAMEIN_GRAPHIC_SymbolKeyAction(char *p,int *out);

int NAMEIN_GRAPHIC_SymbolTouch(char *p,int *out);

void NAMEIN_GRAPHIC_ApplySymbolAction(char *p,int *input);

void NAMEIN_GRAPHIC_InitMsgBox(unsigned char *p,int a,int b,int c,int d,unsigned short e);

void NAMEIN_GRAPHIC_DeleteMsgBox(u8 *p);

void NAMEIN_GRAPHIC_PrintMsg(char *p,int value);

void NAMEIN_GRAPHIC_PrintPokeMsg(char *p,int value,u32 id,u32 form,u16 heap);

void NAMEIN_GRAPHIC_PrintMonMsg(char *p,int value,void *mon);

int NAMEIN_GRAPHIC_IsMsgDrawDone(u8 *p);

void NAMEIN_GRAPHIC_InitTcbl(char *p, int v);

void NAMEIN_GRAPHIC_DeleteTcbl(unsigned char *p);

void NAMEIN_GRAPHIC_PrintNameStream(char *p,char *q,int *w,u32 heap);

void NAMEIN_GRAPHIC_InitIconActor(u8 *o, u32 mode, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap);

void NAMEIN_GRAPHIC_DeleteIconActor(unsigned char *p);

void NAMEIN_GRAPHIC_UpdateIconTouch(char *p);

void NAMEIN_GRAPHIC_FlushIconOam(unsigned char *p);

unsigned NAMEIN_GRAPHIC_IsIconAnimDone(unsigned char *p);

void NAMEIN_GRAPHIC_StartIconAnim(unsigned char *p);

int NAMEIN_GRAPHIC_StepIconAnim(char *p);

int NAMEIN_GRAPHIC_GetIconMode(int x, int y);

int NAMEIN_GRAPHIC_IsPointInRect(int *p, int *q);

int NAMEIN_GRAPHIC_GetNameForAction(u8 *p, int a, int b);

void NAMEIN_GRAPHIC_CommitName(char *p);

int NAMEIN_GRAPHIC_IsNameValid(int p);

void NAMEIN_GRAPHIC_InitCallback(u8 *a, u32 b, u32 c);

void NAMEIN_GRAPHIC_ClearCallback(void *p);

void NAMEIN_GRAPHIC_RunCallback(u8 *p);

unsigned NAMEIN_GRAPHIC_GetCallbackState(unsigned char *p);

void NAMEIN_GRAPHIC_SetCallback(unsigned char *p,unsigned value);

void NAMEIN_GRAPHIC_FinishCallback(unsigned char *p);

void NAMEIN_GRAPHIC_CallbackWaitDraw(unsigned char *p,int *unused,unsigned char *q);

void NAMEIN_GRAPHIC_CallbackFadeIn(unsigned char *p,int *state);

void NAMEIN_GRAPHIC_CallbackFadeOut(unsigned char *p,int *state);

void NAMEIN_GRAPHIC_CallbackWaitPrint(unsigned char *a, int *state, char *p);

void NAMEIN_GRAPHIC_CallbackGridAction(unsigned char *owner,void *unused,char *p);

void NAMEIN_GRAPHIC_CallbackFinish(unsigned char *a, int unused, char *p);

void NAMEIN_GRAPHIC_CallbackPauseSave(unsigned char *p,int *state,unsigned char *q);

unsigned char *NAMEIN_GRAPHIC_CreateDisplay(unsigned swap, unsigned short heap);

void NAMEIN_GRAPHIC_DeleteDisplay(unsigned char *p);

void NAMEIN_GRAPHIC_DrawDisplay(u8 *p);

unsigned NAMEIN_GRAPHIC_GetDisplayHandle(unsigned char *p);

void NAMEIN_GRAPHIC_DisplayMainTask(u32 a, u8 *b);

void NAMEIN_GRAPHIC_InitBg(void *p, unsigned short heap);

void NAMEIN_GRAPHIC_ExitBg(void *p);

void NAMEIN_GRAPHIC_Empty(u8 *a0);

void NAMEIN_GRAPHIC_ResetBg(u8 *a0);

void NAMEIN_GRAPHIC_InitClact(unsigned char *p, int a, int b);

void NAMEIN_GRAPHIC_ExitClact(u8 *p);

void NAMEIN_GRAPHIC_DrawClact(u8 *a0);

void NAMEIN_GRAPHIC_VBlankClact(u8 *a0);

u32 NAMEIN_GRAPHIC_LoadWord(const u32 *p);

void NAMEIN_GRAPHIC_LoadIconMember(u8 *dst,unsigned arc,u32 member,u32 index,u16 width,u16 height,int pos,int mode,u16 heap);

extern const u8 d_021F5569[];

extern short FX_SinCosTable_[];

extern u32  gSpeciesNameBank;

extern const char d_021F5784[];

extern const struct DispVram d_021F55D0;

extern const Disp d_021F55A4;

extern const Entry d_021F5600[];

int NAMEIN_GRAPHIC_SymbolGetValue(Pair *p,Pair *out) {
 int result;Pair xy;
 result=0;
 switch((unsigned)p->y) {
 case 0: if(p->x==10)result=6;else {xy=*p;result=1;}break;
 case 1: if(p->x==9)result=7;else {xy=*p;result=1;}break;
 case 2: if(p->x==0 || p->x==9)result=8;else {xy.x=p->x-1;xy.y=p->y;result=1;}break;
 case 3: result=9;if(p->x!=4)result=p->x+2;break;
 }
 if(result==1 && out) {*out=xy;}return result;
}

/*
 * tail: two zero alignment bytes at 021F31B6 before 31B8.
 * prototype: 256C retains fifth heap input visibly stored by caller; heap forwards use full words without caller-side truncation.
 */
void NAMEIN_GRAPHIC_InitGrid(u8 *p,int mode,void *font,void *window,void *data,void *palette,u32 heap)
{
 Box box;
 void *bg;
 int index;
 MI_CpuFill8(p,0,0x130);
 ((NameinGraphicGrid *)p)->selectionX=0;((NameinGraphicGrid *)p)->selectionY=0;
 ((NameinGraphicGrid *)p)->font=font;((NameinGraphicGrid *)p)->printSys=window;((NameinGraphicGrid *)p)->heap=heap;
 ((NameinGraphicGrid *)p)->mode=mode;((NameinGraphicGrid *)p)->targetMode=mode;((NameinGraphicGrid *)p)->data=data;
 ((NameinGraphicGrid *)p)->paletteHandleA=ARC_UTIL_LoadPaletteDataFromArchive(118,10,0,(u32)(p+0x124),heap);
 ((NameinGraphicGrid *)p)->paletteHandleB=ARC_UTIL_LoadPaletteDataFromArchive(118,5,0,(u32)(p+0x128),heap);
 if(mode==3){BG_SYS_DecodeTile(1,*(char * *)&((NameinGraphicGrid *)p)->paletteDataA+12,2048);BG_SYS_SetPlaneVisible(2,0);}
 else {BG_SYS_DecodeTile(1,*(char * *)&((NameinGraphicGrid *)p)->paletteDataB+12,2048);BG_SYS_SetPlaneVisible(2,1);}
 BG_SYS_PushTile(1);
 NAMEIN_GRAPHIC_InitCursor(p+0x24,(void *)mode,palette,heap);
 index=NAMEIN_GRAPHIC_GridIndex(((NameinGraphicGrid *)p)->mode,((NameinGraphicGrid *)p)->index,p[0x108]);
 NAMEIN_GRAPHIC_InitPicker((char *)p,mode,index,((NameinGraphicGrid *)p)->data,heap);
 bg=(void *)BMP_WIN_Create(3,3,5,26,15,15,1);
 ((NameinGraphicGrid *)p)->bmpWin=bg;
 BMP_WIN_TransferChars(bg);BMP_WIN_MakeScreen(bg);BG_SYS_PushTile(BMP_WIN_GetBgLayer(bg));
 ((NameinGraphicGrid *)p)->tipBmp=((NameinGraphicGrid *)p)->bmpWin;p[0xf0]=0;
 NAMEIN_GRAPHIC_DrawCellTips((char *)p,(char *)p+0xec,window,font,heap);
 if(UI_GetInputMode()==0){
  if(NAMEIN_GRAPHIC_PickerGetBox((char *)p,(Pair *)(p+0xd8),&box))NAMEIN_GRAPHIC_SetupCursor((char *)p+0x24,1,(const struct Rect *)(&box),((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
 }else {
  if(NAMEIN_GRAPHIC_PickerGetBox((char *)p,(Pair *)(p+0xd8),&box))NAMEIN_GRAPHIC_SetupCursor((char *)p+0x24,0,(const struct Rect *)(&box),((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
 }
}

void NAMEIN_GRAPHIC_DeleteGrid(u8 *p) {int off;BMP_WIN_Delete(((NameinGraphicGrid *)p)->bmpWin);NAMEIN_GRAPHIC_ClearPicker(p);NAMEIN_GRAPHIC_ClearCursor(p+36);off=0x11c;GFL_HEAP_Free(*(void **)(p+off));GFL_HEAP_Free(*(void **)(p+off+4));off+=20;MI_CpuFill8(p,0,off);}

void NAMEIN_GRAPHIC_UpdateGrid(char *p,char *q)
{
    int out0[4];
    int out2[4];
    Rect rect;
    int result;
    ((NameinGraphicGrid *)p)->action=0;
    switch(((NameinGraphicGrid *)p)->state){
    case 0:
        MI_CpuFill8(out0,0,16);
        result=NAMEIN_GRAPHIC_KanaTouch(p,out0);
        if(!result){NAMEIN_GRAPHIC_KanaKeyMove(p,out0);result=NAMEIN_GRAPHIC_KanaKeyAction(p,out0);}
        if(result)NAMEIN_GRAPHIC_ApplyKanaAction(p,out0);
        break;
    case 2:
        MI_CpuFill8(out2,0,16);
        result=NAMEIN_GRAPHIC_SymbolTouch(p,out2);
        if(!result){NAMEIN_GRAPHIC_SymbolKeyMove(p,out2);result=NAMEIN_GRAPHIC_SymbolKeyAction(p,out2);}
        if(result)NAMEIN_GRAPHIC_ApplySymbolAction(p,out2);
        if(NAMEIN_GRAPHIC_AnimateGrid(p))((NameinGraphicGrid *)p)->state=0;
        break;
    case 1:
        if(NAMEIN_GRAPHIC_IsFieldFull(q)){NAMEIN_GRAPHIC_FindCellByValue(p,7,(Pair *)(p+0xD8));((NameinGraphicGrid *)p)->action=11;}
        ((NameinGraphicGrid *)p)->state=0;
        break;
    }
    NAMEIN_GRAPHIC_PickerGetBox(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect));
    NAMEIN_GRAPHIC_UpdateCursor(p+0x24,((NameinGraphicGrid *)p)->mode,&rect);
    NAMEIN_GRAPHIC_IsGridDrawDone(p);
}

int NAMEIN_GRAPHIC_GetGridAction(char *p, unsigned short *out)
{
    int s = ((NameinGraphicGrid *)p)->action;
    if ((s == 1 || s == 2 || s == 9) && out != 0)
    {
        *out = ((NameinGraphicGrid *)p)->actionValue;
    }
    return ((NameinGraphicGrid *)p)->action;
}

u32 NAMEIN_GRAPHIC_GetGridIndex(const u8 *p) {return (u32)((NameinGraphicGrid *)p)->index;}

int NAMEIN_GRAPHIC_IsGridDrawDone(char *p) {
 int q;
 q=(int)((NameinGraphicGrid *)p)->printSys;
 if(((NameinGraphicGrid *)p)->tipDirty) {
 if(PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q,(void *)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((NameinGraphicGrid *)p)->tipBmp))==0) {
 BMP_WIN_TransferChars(((NameinGraphicGrid *)p)->tipBmp);((NameinGraphicGrid *)p)->tipDirty=0;
 }}
 if(((NameinGraphicGrid *)p)->tipDirty==0)return 1;return 0;
}

void *NAMEIN_GRAPHIC_GetGridMode(const u8 *p) {return (void *)((NameinGraphicGrid *)p)->mode;}

u32 NAMEIN_GRAPHIC_GridIndex(u32 a,u32 b,u32 c) {if(a==3) a=b+(a+2*c);return a;}

int NAMEIN_GRAPHIC_SetGridMode(char *p,int mode) {
 int flag;
 if(((NameinGraphicGrid *)p)->targetMode!=mode) {
 ((NameinGraphicGrid *)p)->targetMode=mode;((NameinGraphicGrid *)p)->animTick=0;((NameinGraphicGrid *)p)->animPhase=0;((NameinGraphicGrid *)p)->animActive=1;
 flag=0;
 if(mode==3 || ((NameinGraphicGrid *)p)->mode==3)flag=1;
 ((NameinGraphicGrid *)p)->extraLayer=flag;
 if(flag)G2x_SetBlendAlpha_((void *)0x04000050,14,47,16,16);
 else G2x_SetBlendAlpha_((void *)0x04000050,10,47,16,16);
 return 1;
 }return 0;
}

/*
 * note: 2026-10-05 wD4 lane09: EXACT. The calls in case 0 are written out in each arm of the f118 test (tail merge builds the shared movs r1,#0 join), so the join block holds only the state stores and the zero is not hoisted.
 */
int NAMEIN_GRAPHIC_AnimateGrid(char *p) {
    int c;
    int y;
    if (*(u32 *)(p + 0x110) != 0)
    switch (*(u16 *)(p + 0x10c)) {
    case 0:
        func_02040804(1);
        c = *(u16 *)(p + 0x10a);
        *(u16 *)0x04000052 = (s16)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16)((c * -48) / 7);
        BG_SYS_FillScrollArea(1, 3, y);
        BG_SYS_FillScrollArea(3, 3, y);
        if (*(u32 *)(p + 0x118)) BG_SYS_FillScrollArea(2, 3, y);
        if ((*(u16 *)(p + 0x10a))++ > 7) {
            if (*(u32 *)(p + 0x118)) {
                BG_SYS_SetPlaneVisible(1, 0);
                BG_SYS_SetPlaneVisible(2, 0);
                BG_SYS_SetPlaneVisible(3, 0);
            } else {
                BG_SYS_SetPlaneVisible(1, 0);
                BG_SYS_SetPlaneVisible(3, 0);
            }
            *(u16 *)(p + 0x10a) = 0;
            *(u16 *)(p + 0x10c) = 1;
        }
        break;
    case 1:
        y = -48;
        BG_SYS_FillScrollArea(1, 3, y);
        BG_SYS_FillScrollArea(3, 3, y);
        if (*(u32 *)(p + 0x118)) BG_SYS_FillScrollArea(2, 3, y);
        NAMEIN_GRAPHIC_SwitchGridMode(p, *(u32 *)(p + 0x114));
        *(u16 *)(p + 0x10c) = 2;
        break;
    case 2:
        *(u16 *)(p + 0x10a) = 7;
        *(u16 *)(p + 0x10c) = 3;
        BG_SYS_SetPlaneVisible(1, 1);
        BG_SYS_SetPlaneVisible(3, 1);
        if (*(u32 *)(p + 0x100) != 3) BG_SYS_SetPlaneVisible(2, 1);
        *(u16 *)0x04000052 = 1 << 12;
        break;
    case 3:
        c = *(u16 *)(p + 0x10a);
        *(u16 *)0x04000052 = (s16)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16)((c * -48) / 7);
        BG_SYS_FillScrollArea(1, 3, y);
        BG_SYS_FillScrollArea(3, 3, y);
        if (*(u32 *)(p + 0x118)) BG_SYS_FillScrollArea(2, 3, y);
        if ((*(u16 *)(p + 0x10a))-- == 0) *(u16 *)(p + 0x10c) = 4;
        break;
    case 4:
        BG_SYS_FillScrollArea(1, 3, 0);
        BG_SYS_FillScrollArea(3, 3, 0);
        BG_SYS_FillScrollArea(2, 3, 0);
        *(u32 *)(p + 0x118) = 0;
        *(u16 *)0x04000050 = 0;
        *(u32 *)(p + 0x110) = 0;
        return 1;
    }
    return 0;
}

void NAMEIN_GRAPHIC_SwitchGridMode(char *p, u32 mode) {
 int index;
 if(((NameinGraphicGrid *)p)->mode==mode)return;
 NAMEIN_GRAPHIC_ClearPicker(p);
 index=NAMEIN_GRAPHIC_GridIndex(mode,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->variant);
 NAMEIN_GRAPHIC_InitPicker(p,mode,index,((NameinGraphicGrid *)p)->data,((NameinGraphicGrid *)p)->heap);
 BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)((NameinGraphicGrid *)p)->bmpWin),0);
 NAMEIN_GRAPHIC_DrawCellTips(p,p+0xEC,(void *)(((NameinGraphicGrid *)p)->printSys),(void *)(((NameinGraphicGrid *)p)->font),((NameinGraphicGrid *)p)->heap);
 if(mode==3) {BG_SYS_DecodeTile(1,*(char * *)&((NameinGraphicGrid *)p)->paletteDataA+12,2048);BG_SYS_SetPlaneVisible(2,0);}
 else BG_SYS_DecodeTile(1,*(char * *)&((NameinGraphicGrid *)p)->paletteDataB+12,2048);
 BG_SYS_PushTile(1);
 if(mode==3 || ((NameinGraphicGrid *)p)->mode==3)NAMEIN_GRAPHIC_ConvertCellMode((Pair *)(p+0xD8),((NameinGraphicGrid *)p)->mode,mode);
 ((NameinGraphicGrid *)p)->mode=mode;
}

/*
 * volatile: 021F3676 and 021F3696 re-read the mode word at +0x100.
 */
void NAMEIN_GRAPHIC_SetGridSelection(char *p,int index,int variant) {
 int selected;
 if(*(volatile int *)&((NameinGraphicGrid *)p)->mode!=3)return;
 if(((NameinGraphicGrid *)p)->variant==variant && ((NameinGraphicGrid *)p)->index==index)return;
 selected=(int)NAMEIN_GRAPHIC_GridIndex((int)(*(volatile int *)&((NameinGraphicGrid *)p)->mode),(int)index,(unsigned char)variant);
 NAMEIN_GRAPHIC_LoadGrid((int *)p,selected,(int)((NameinGraphicGrid *)p)->data);
 BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)((NameinGraphicGrid *)p)->bmpWin),0);
 NAMEIN_GRAPHIC_DrawCellTips(p,p+0xEC,(void *)(((NameinGraphicGrid *)p)->printSys),(void *)(((NameinGraphicGrid *)p)->font),((NameinGraphicGrid *)p)->heap);
 ((NameinGraphicGrid *)p)->index=index;((NameinGraphicGrid *)p)->variant=variant;
}

int NAMEIN_GRAPHIC_KanaKeyMove(char *p,int *out)
{
    Rect rect;
    Pair delta;
    int changed=0;
    if(KEY_GetRepeat()&64){delta.x=0;delta.y=-1;changed=1;}
    else if(KEY_GetRepeat()&128){delta.x=0;delta.y=1;changed=1;}
    else if(KEY_GetRepeat()&32){delta.x=-1;delta.y=0;changed=1;}
    else if(KEY_GetRepeat()&16){delta.x=1;delta.y=0;changed=1;}
    else if(KEY_GetTrg()&8){
        delta.x=0;delta.y=0;changed=1;
        NAMEIN_GRAPHIC_FindCellByValue(p,7,(Pair *)(p+0xD8));
        NAMEIN_GRAPHIC_PickerMove(p,(int)(p+0xD8),(int)&delta);
    }
    if(changed){
        if(UI_GetInputMode()==1){
            if(NAMEIN_GRAPHIC_PickerGetBox(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                func_020355D8(0);
                NAMEIN_GRAPHIC_SetupCursor(p+0x24,1,(const struct Rect *)(&rect),((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
                GFL_USE_PlaySeDefaultVolume(1352);
            }
        }else{
            NAMEIN_GRAPHIC_PickerMove(p,(int)p+0xD8,(int)&delta);
            if(NAMEIN_GRAPHIC_PickerGetBox(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                GFL_USE_PlaySeDefaultVolume(1352);
                NAMEIN_GRAPHIC_SetupCursor(p+0x24,1,(const struct Rect *)(&rect),((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
            }
        }
    }
    return 0;
}

int NAMEIN_GRAPHIC_KanaKeyAction(char *p,int *out)
{
    Rect rect;
    int changed;
    changed=0;
    if(KEY_GetTrg()==1) {
        *(Pair *)(out+2)=*(Pair *)(p+0xD8);
        out[1]=1;changed=1;
    }
    if(KEY_GetTrg()==2) {
        NAMEIN_GRAPHIC_FindCellByValue(p,6,(Pair *)(out+2));out[0]=6;changed=1;
    }
    if(KEY_GetTrg()==4) {
        out[0]=((NameinGraphicGrid *)p)->mode+3;
        if(out[0]>5)out[0]=2;
        NAMEIN_GRAPHIC_FindCellByValue(p,out[0],(Pair *)(p+0xD8));
        *(Pair *)(out+2)=*(Pair *)(p+0xD8);changed=1;
    }
    if(KEY_GetTrg()==256){((NameinGraphicGrid *)p)->action=10;changed=0;}
    if(changed && UI_GetInputMode()==1) {
        if(NAMEIN_GRAPHIC_PickerGetBox(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))) {
            GFL_USE_PlaySeDefaultVolume(1352);func_020355D8(0);
            NAMEIN_GRAPHIC_SetupCursor(p+0x24,1,(const struct Rect *)(&rect),((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
            return 0;
        }
    }
    return changed;
}

int NAMEIN_GRAPHIC_KanaTouch(char *p,int *out) {
 int point[2];unsigned x,y;int u;
 if(TOUCHPANEL_GetPointTrg(&x,&y)) {
 point[0]=x;point[1]=y;
 if(NAMEIN_GRAPHIC_FindCellAtPoint(p,point,(Pair *)(p+0xD8))) {
 u=((NameinGraphicGrid *)p)->selectionX;out[3]=((NameinGraphicGrid *)p)->selectionY;out[1]=1;out[2]=u;func_020355D8(1);return 1;
 }}return 0;
}

void NAMEIN_GRAPHIC_ApplyKanaAction(char *p,int *input)
{
    unsigned code;
    Rect rect;
    if(input[1])code=NAMEIN_GRAPHIC_PickerToChar(p,(int *)(p+0xD8),(unsigned short *)(p+0xFC));
    else code=input[0];
    switch(code){
    case 0:break;
    case 1:((NameinGraphicGrid *)p)->action=1;((NameinGraphicGrid *)p)->state=1;break;
    case 9:((NameinGraphicGrid *)p)->action=9;((NameinGraphicGrid *)p)->state=1;break;
    case 2:case 3:case 4:case 5:
        if(NAMEIN_GRAPHIC_SetGridMode(p,code-2)){
            GFL_USE_PlaySeDefaultVolume(1611);((NameinGraphicGrid *)p)->state=2;((NameinGraphicGrid *)p)->action=6;
        }break;
    case 6:((NameinGraphicGrid *)p)->action=5;break;
    case 7:((NameinGraphicGrid *)p)->action=7;break;
    case 8:
        GFL_USE_PlaySeDefaultVolume(1356);((NameinGraphicGrid *)p)->action=8;
        NAMEIN_GRAPHIC_SetGridSelection(p,((NameinGraphicGrid *)p)->index^1,((NameinGraphicGrid *)p)->variant);break;
    case 10:((NameinGraphicGrid *)p)->action=3;break;
    case 11:((NameinGraphicGrid *)p)->action=4;break;
    }
    if(NAMEIN_GRAPHIC_PickerGetBox(p, (Pair *)((int)(input+2)), (Box *)((int)&rect)))
        NAMEIN_GRAPHIC_SetupCursor(p+0x24,2,(const struct Rect *)(&rect),((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
}

/*
 * lever: Integer address arithmetic for26E0 avoids caching p+D8 across2818.
 */
int NAMEIN_GRAPHIC_SymbolKeyMove(char *p,int *out)
{
    Rect rect;
    Pair delta;
    Pair point;
    int changed=0;
    if(((NameinGraphicGrid *)p)->extraLayer==0){
        if(KEY_GetTrg()&64){delta.x=0;delta.y=-1;changed=1;}
        else if(KEY_GetTrg()&128){delta.x=0;delta.y=1;changed=1;}
        else if(KEY_GetTrg()&32){delta.x=-1;delta.y=0;changed=1;}
        else if(KEY_GetTrg()&16){delta.x=1;delta.y=0;changed=1;}
    }
    if(changed){
        point=*(Pair *)(p+0xD8);
        NAMEIN_GRAPHIC_PickerMove(p,(int)&point,(int)&delta);
        if(NAMEIN_GRAPHIC_PickerToChar(p,&point.x,0)-2<=3){
            if(UI_GetInputMode()==1){
                if(NAMEIN_GRAPHIC_PickerGetBox(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                    GFL_USE_PlaySeDefaultVolume(1352);func_020355D8(0);
                    NAMEIN_GRAPHIC_SetupCursor(p+0x24,1,(const struct Rect *)(&rect),((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
                }
            }else{
                NAMEIN_GRAPHIC_PickerMove(p,(int)p+0xD8,(int)&delta);
                if(NAMEIN_GRAPHIC_PickerGetBox(p, (Pair *)((int)(p+0xD8)), (Box *)((int)&rect))){
                    GFL_USE_PlaySeDefaultVolume(1352);
                    NAMEIN_GRAPHIC_SetupCursor(p+0x24,1,(const struct Rect *)(&rect),((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
                }
            }
        }
    }
    return 0;
}

int NAMEIN_GRAPHIC_SymbolKeyAction(char *p,int *out) {
    int changed=0;
    int rect[4];
    if (((NameinGraphicGrid *)p)->extraLayer==0) {
        if (KEY_GetTrg()&1) {
            *(Pair *)(out+2)=*(Pair *)(p+0xd8);
            changed=1; out[1]=1;
        }
        if (KEY_GetTrg()&4) {
            out[0]=((NameinGraphicGrid *)p)->mode+3;
            if (out[0]>5) out[0]=2;
            NAMEIN_GRAPHIC_FindCellByValue(p,out[0],(Pair *)(p+0xd8));
            *(Pair *)(out+2)=*(Pair *)(p+0xd8);
            changed=1;
        }
        if (changed && UI_GetInputMode()==1) {
            if (NAMEIN_GRAPHIC_PickerGetBox(p,(Pair *)(p+0xd8),(Box *)rect)) {
                GFL_USE_PlaySeDefaultVolume(1352); func_020355D8(0);
                NAMEIN_GRAPHIC_SetupCursor(p+0x24,1,(const struct Rect *)rect,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
                return 0;
            }
        }
    }
    return changed;
}

/*
 * note: unsigned result minus two tests the contiguous range; point precedes x/y declarations.
 */
int NAMEIN_GRAPHIC_SymbolTouch(char *p,int *out) {
    int point[2],u;
    unsigned x,y;
    if (((NameinGraphicGrid *)p)->extraLayer==0) {
        if (TOUCHPANEL_GetPointTrg(&x,&y)) {
            point[0]=x; point[1]=y;
            if (NAMEIN_GRAPHIC_FindCellAtPoint(p,point,(Pair *)(p+0xd8))) {
                if (NAMEIN_GRAPHIC_PickerToChar(p,(int *)(p+0xd8),0)-2<=3) {
                    u=((NameinGraphicGrid *)p)->selectionX;
                    out[3]=((NameinGraphicGrid *)p)->selectionY;
                    out[1]=1; out[2]=u;
                    func_020355D8(1);
                    return 1;
                }
            }
        }
    }
    return 0;
}

void NAMEIN_GRAPHIC_ApplySymbolAction(char *p,int *input) {
    unsigned code;
    int rect[4];
    if (input[1]) code=NAMEIN_GRAPHIC_PickerToChar(p,(int *)(p+0xd8),(unsigned short *)(p+0xfc));
    else code=input[0];
    switch (code) {
    case 0: case 1: break;
    case 2: case 3: case 4: case 5:
        if (NAMEIN_GRAPHIC_SetGridMode(p,code-2)) {
            GFL_USE_PlaySeDefaultVolume(1611);
            ((NameinGraphicGrid *)p)->state=2; ((NameinGraphicGrid *)p)->action=6;
        }
        break;
    }
    if (NAMEIN_GRAPHIC_PickerGetBox(p,(Pair *)(input+2),(Box *)rect))
        NAMEIN_GRAPHIC_SetupCursor(p+0x24,2,(const struct Rect *)rect,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
}

void NAMEIN_GRAPHIC_InitMsgBox(unsigned char *p,int a,int b,int c,int d,unsigned short e) {
    int window;
    MI_CpuFill8(p,0,0x24);
    ((NameinGraphicMsgBox *)p)->color=15;
    ((NameinGraphicMsgBox *)p)->field4=a; ((NameinGraphicMsgBox *)p)->wordSet=(void *)d; ((NameinGraphicMsgBox *)p)->bank=(void *)b; ((NameinGraphicMsgBox *)p)->printSys=(void *)c;
    ((NameinGraphicMsgBox *)p)->strbuf=STRBUF_Create(255,e);
    ((NameinGraphicMsgBox *)p)->win=(void *)BMP_WIN_Create(4,1,19,30,4,15,1);
    BMP_MENUWORK_DrawWindow((void *)(((NameinGraphicMsgBox *)p)->win),2,1,14);
    ((NameinGraphicMsgBox *)p)->bmp=((NameinGraphicMsgBox *)p)->win;
    ((NameinGraphicMsgBox *)p)->dirty=0;
    BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)((NameinGraphicMsgBox *)p)->win),((NameinGraphicMsgBox *)p)->color);
    window=(int)((NameinGraphicMsgBox *)p)->win;
    BMP_WIN_TransferChars((struct Descriptor *)window); BMP_WIN_MakeScreen((struct Cfg *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)window));
}

/*
 * Addresses are Black-image addresses.
 */
void NAMEIN_GRAPHIC_DeleteMsgBox(u8 *p)
{
    BMP_WIN_Delete((struct Descriptor *)(((NameinGraphicMsgBox *)p)->win));
    STRBUF_Delete((struct U16Vec *)(((NameinGraphicMsgBox *)p)->strbuf));
    MI_CpuFill8(p, 0, 0x24);
}

void NAMEIN_GRAPHIC_PrintMsg(char *p,int value) {
    int window;
    while (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((NameinGraphicMsgBox *)p)->printSys),(void *)((int)BMP_WIN_GetBmp((struct Descriptor *)((NameinGraphicMsgBox *)p)->win))))
        PRINTSYS_QUE_Main((struct PrintSys *)(((NameinGraphicMsgBox *)p)->printSys));
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((NameinGraphicMsgBox *)p)->win)),((NameinGraphicMsgBox *)p)->color);
    func_02045CAC((struct MsgBank *)(((NameinGraphicMsgBox *)p)->bank),value,(void *)(((NameinGraphicMsgBox *)p)->strbuf));
    window=(int)((NameinGraphicMsgBox *)p)->printSys;
    PRINTSYS_PrintQue((struct PrintSys *)window,(int)BMP_WIN_GetBmp((struct Descriptor *)((NameinGraphicMsgBox *)p)->bmp),0,0,(void *)(*(int *)&((NameinGraphicMsgBox *)p)->strbuf),((NameinGraphicMsgBox *)p)->field4);
    ((NameinGraphicMsgBox *)p)->dirty=1;
}

void NAMEIN_GRAPHIC_PrintPokeMsg(char *p,int value,u32 id,u32 form,u16 heap) {void *mon;mon=POKE_TOOL_Create(id,1,0,heap);POKE_TOOL_SetPartyValue(mon,111,form);NAMEIN_GRAPHIC_PrintMonMsg(p,value,mon);GFL_HEAP_Free(mon);}

void NAMEIN_GRAPHIC_PrintMonMsg(char *p,int value,void *mon) {
    int text,window;
    WORDSET_SetSlotMonName(((NameinGraphicMsgBox *)p)->wordSet,0,mon);
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((NameinGraphicMsgBox *)p)->win)),((NameinGraphicMsgBox *)p)->color);
    text=(int)MSGDATA_AllocString((struct MsgBank *)(((NameinGraphicMsgBox *)p)->bank),value);
    WORDSET_CopyTaggedText((struct WordSet *)(*(int *)&((NameinGraphicMsgBox *)p)->wordSet),((NameinGraphicMsgBox *)p)->strbuf,(void *)text);
    window=(int)((NameinGraphicMsgBox *)p)->printSys;
    PRINTSYS_PrintQue((struct PrintSys *)window,(int)BMP_WIN_GetBmp((struct Descriptor *)((NameinGraphicMsgBox *)p)->bmp),0,0,(void *)(*(int *)&((NameinGraphicMsgBox *)p)->strbuf),((NameinGraphicMsgBox *)p)->field4);
    ((NameinGraphicMsgBox *)p)->dirty=1;
    STRBUF_Delete((struct U16Vec *)text);
}

int NAMEIN_GRAPHIC_IsMsgDrawDone(u8 *p) {int window;window=(int)((NameinGraphicMsgBox *)p)->printSys;if(p[12]) {if(PRINTSYS_QUE_IsExistTarget((struct PrintSys *)window,(void *)((int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((NameinGraphicMsgBox *)p)->bmp)))==0) {BMP_WIN_TransferChars(((NameinGraphicMsgBox *)p)->bmp);p[12]=0;}}if(!p[12]) return 1;return 0;}

void NAMEIN_GRAPHIC_InitTcbl(char *p, int v)
{
    MI_CpuFill8(p, 0, 0x10);
    ((NameinGraphicTcbl *)p)->handle = TCBL_Create(v, v, 1, 0);
}

void NAMEIN_GRAPHIC_DeleteTcbl(unsigned char *p){if(((NameinGraphicTcbl *)p)->stream)PRINTSYS_PrintStreamDelete((int)((NameinGraphicTcbl *)p)->stream);TCBL_Destroy(*(struct S02031140 * *)&((NameinGraphicTcbl *)p)->handle);MI_CpuFill8((unsigned char *)p, 0, 16);}

void NAMEIN_GRAPHIC_PrintNameStream(char *p,char *q,int *w,u32 heap)
{
    void *set=WORDSET_CreateDefault(heap);
    if(NAMEIN_SETUP_IsCanceled(w)) WORDSET_SetSlotMonSpecies(set,0,(void *)w[2]);
    else {
        int text=(int)STRBUF_Clone((struct U16Vec *)w[8],heap);
        NAMEIN_SETUP_CopyName(w,text);
        WORDSET_SetSlotTag(set,0,(void *)text,0,0,0);
        STRBUF_Delete((struct U16Vec *)text);
    }
    WORDSET_SetSlotBoxName(set,1,w[4],w[5]);
    if(((NameinGraphicTcbl *)p)->stream) PRINTSYS_PrintStreamDelete((int)((struct Rec3 *)(((NameinGraphicTcbl *)p)->stream)));
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((NameinGraphicMsgBox *)q)->win)),((NameinGraphicMsgBox *)q)->color);
    STRBUF_Clear(((NameinGraphicMsgBox *)q)->strbuf);
    WORDSET_CopyTaggedText(set,((NameinGraphicMsgBox *)q)->strbuf,(void *)w[3]);
    ((NameinGraphicTcbl *)p)->stream=(void *)PRINTSYS_PrintStream((u32)((NameinGraphicMsgBox *)q)->win,0,0,*(u32 *)&((NameinGraphicMsgBox *)q)->strbuf,((NameinGraphicMsgBox *)q)->field4,MSG_SPEED_GetWait(),(u32)((NameinGraphicTcbl *)p)->handle,2,heap,((NameinGraphicMsgBox *)q)->color);
    ((NameinGraphicTcbl *)p)->flag=0;
    *(void (**)(void))(p+8)=(void (*)(void))NAMEIN_GRAPHIC_CallbackFadeOut;
    ((NameinGraphicTcbl *)p)->counter=60;
    WORDSET_DeleteStrbufED04(set);
}

void NAMEIN_GRAPHIC_InitIconActor(u8 *o, u32 mode, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, void *s3, u32 s4, u16 heap)
{
    u32 flagA = 0;
    u32 v40;
    u32 v3c;
    u32 v38;
    u32 v34;
    u32 v30;
    u8 v2c;
    void *h;
    u32 w24 = 0x22;
    u32 h20 = 0x14;
    u32 v1c;
    u32 flagB = 0;

    MI_CpuFill8((unsigned char *)o, 0, 0x3c);
    v2c = 0;
    switch (mode) {
    case 0:
    case 1:
        v40 = APP_ICON_GetArchiveId();
        v3c = APP_ICON_GetItemDataFileId();
        v38 = APP_ICON_GetItemExtraFileId();
        v34 = APP_ICON_GetItemAnim2FileId(2);
        v30 = APP_ICON_GetItemFrame2FileId(2);
        v1c = a2;
        break;
    case 2:
        v40 = 0x20;
        v3c = flagB;
        v2c = d_021F5569[a2];
        v38 = a2 + 0x31;
        v34 = 0x41;
        v30 = 0x42;
        v1c = (a2 >= 8) ? 1 : flagB;
        break;
    case 3:
        flagA = 1;
        v1c = (a3 & 0xFF00) >> 8;
        if (v1c == 2) {
            flagA = 0;
        }
        v40 = 7;
        v3c = POKE_TOOL_GetIconPaletteArcId();
        v38 = POKE_TOOL_CalcGraphicIndex(a2, (u8)a3, v1c, 0);
        v34 = POKE_TOOL_GetIconCellArcId();
        v30 = POKE_TOOL_GetIconCellEntryId();
        w24 = 0x1e;
        h20 = 0x14;
        flagB = 1;
        break;
    case 4:
    case 5:
        v40 = 0x76;
        v3c = 9;
        v38 = 8;
        v34 = 7;
        v30 = 6;
        v2c = 1;
        break;
    }
    h = ARC_TOOL_CreateHandle(v40, heap);
    if (flagB != 0) {
        *(void **)(o + 8) = (void *)CLACT_RegisterPaletteCompressed(h, v3c, 0, 0x40, heap);
    } else {
        *(void **)(o + 8) = (void *)CLACT_RegisterPaletteEx(h, v3c, 0, 0x40, v2c, 1, heap);
    }
    *(void **)(o + 0x10) = (void *)CLACT_RegisterCellAnim(h, v34, v30, heap);
    flagB = 0;
    *(void **)(o + 0xC) = (void *)CLACT_RegisterCharacter(h, v38, 0, 0, heap);
    ARC_TOOL_DeleteHandle(h);
    {
        Dim8 dim;
        MI_CpuFill8((unsigned char *)&dim, 0, 8);
        dim.w = w24;
        dim.h = h20;
        *(void **)o = CLACT_CreateActor((void *)s0, (u32)(*(void **)(o + 0xC)), (u32)(*(void **)(o + 8)), (u32)(*(void **)(o + 0x10)), &dim, flagB, heap);
    }
    CLACT_SetActorAutoAnim(*(void **)o, 1);
    switch (mode) {
    case 0:
        if (a2 == 0) {
            NAMEIN_GRAPHIC_LoadIconMember(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
        } else {
            NAMEIN_GRAPHIC_LoadIconMember(*(void **)o, 0x31, 9, 3, 4, 4, 0, 0, heap);
        }
        break;
    case 1:
        NAMEIN_GRAPHIC_LoadIconMember(*(void **)o, 0x31, 6, 3, 4, 4, 0, 0, heap);
    case 2:
        CLACT_SetActorPaletteOffset(*(void **)o, 0, 1);
        break;
    case 3:
        CLACT_SetActorAnimSeq(*(void **)o, 1);
        CLACT_SetActorPaletteOffset(*(void **)o, POKE_TOOL_CalcIconPalette(a2, (u8)a3, (a3 & 0xFF00) >> 8, flagB), flagB);
        break;
    case 5:
        CLACT_SetActorAnimSeq(*(void **)o, 5);
        CLACT_SetActorPaletteOffset(*(void **)o, flagB, 1);
        break;
    case 4:
        CLACT_SetActorAnimSeq(*(void **)o, 2);
        CLACT_SetActorPaletteOffset(*(void **)o, flagB, 1);
        break;
    }
    if (flagA != 0) {
        void *h2;
        u32 r;
        u32 idx;
        u8 st[0x18];
        h2 = ARC_TOOL_CreateHandle(0x17, heap);
        *(void **)(o + 0x30) = BMP_Create(2, 2, 0x20, heap);
        *(void **)(o + 0x24) = (void *)CLACT_RegisterPaletteCompressed(h2, 5, 0, 0xA0, heap);
        ARC_TOOL_DeleteHandle(h2);
        MI_CpuFill8((unsigned char *)st, 0, 0x18);
        *(void **)(st + 0) = *(void **)(o + 0x30);
        *(u16 *)(st + 4) = 0x2e;
        *(u16 *)(st + 6) = 0x14;
        *(void **)(st + 8) = *(void **)(o + 0x24);
        *(u8 *)(st + 0x10) = 0;
        *(u16 *)(st + 0x12) = 0;
        *(u32 *)(st + 0x14) = 0;
        *(u8 *)(st + 0x11) = 0;
        *(u32 *)(st + 0xC) = 0;
        *(void **)(o + 0x2C) = BMP_OAM_Create((struct Sys *)s4, (const struct Param *)st);
        if (v1c == 1) {
            idx = 0x11;
            r = 0xC80;
        } else {
            idx = 0x10;
            r = 0x14C0;
        }
        *(void **)(o + 0x28) = MSGDATA_AllocString(s3, idx);
        BMP_Clear(*(void **)(o + 0x30), 0);
        PRINTSYS_PrintQueColor(s2, *(void **)(o + 0x30), 0, 0, *(void **)(o + 0x28), s1, r);
        *(u32 *)(o + 0x38) = s2;
        *(u32 *)(o + 0x34) = 1;
    }
}

void NAMEIN_GRAPHIC_DeleteIconActor(unsigned char *p) {
    if (((NameinGraphicIcon *)p)->oam) {
        CLACT_ReleasePalette(((NameinGraphicIcon *)p)->palette2);
        STRBUF_Delete(((NameinGraphicIcon *)p)->text);
        BMP_OAM_Delete(((NameinGraphicIcon *)p)->oam);
        BMP_Delete(((NameinGraphicIcon *)p)->bmp);
    }
    CLACT_ReleasePalette(((NameinGraphicIcon *)p)->palette);
    CLACT_ReleaseCharacter((u32)(((NameinGraphicIcon *)p)->character));
    CLACT_ReleaseCellAnim(((NameinGraphicIcon *)p)->cellAnim);
    CLACT_DeleteActor(((NameinGraphicIcon *)p)->actor);
    MI_CpuFill8(p,0,0x3c);
}

void NAMEIN_GRAPHIC_UpdateIconTouch(char *p) {
    int rect[4];
    unsigned x,y;
    Vec2 pos;
    int point[2];
    switch (((NameinGraphicIcon *)p)->touchMode) {
    case 0:
        CLACT_GetActorSurfacePos((struct Actor *)((NameinGraphicIcon *)p)->actor,(struct PtS *)&pos,0);
        ((NameinGraphicIcon *)p)->state=0;
        if (TOUCHPANEL_GetPointTrg(&x,&y)) {
            rect[0]=pos.x-16; rect[1]=pos.y-16;
            rect[2]=pos.x+16; rect[3]=pos.y+16;
            point[0]=x; point[1]=y;
            if (NAMEIN_GRAPHIC_IsPointInRect(rect,point)) {
                NAMEIN_GRAPHIC_StartIconAnim((unsigned char *)p);
                ((NameinGraphicIcon *)p)->touchMode=1;
            }
        }
        break;
    case 1:
        if (NAMEIN_GRAPHIC_StepIconAnim(p)) {((NameinGraphicIcon *)p)->state=1; ((NameinGraphicIcon *)p)->touchMode=0;}
        break;
    }
}

void NAMEIN_GRAPHIC_FlushIconOam(unsigned char *p){if(((NameinGraphicIcon *)p)->oamDirty){if(PRINTSYS_QUE_IsExistTarget((struct PrintSys *)(((NameinGraphicIcon *)p)->printSys), (void *)(((NameinGraphicIcon *)p)->bmp))==0){BMP_OAM_UploadChars(*(struct Obj * *)&((NameinGraphicIcon *)p)->oam);((NameinGraphicIcon *)p)->oamDirty=0;}}}

unsigned NAMEIN_GRAPHIC_IsIconAnimDone(unsigned char *p){return ((NameinGraphicIcon *)p)->state;}

void NAMEIN_GRAPHIC_StartIconAnim(unsigned char *p){((NameinGraphicIcon *)p)->animTick=0;*(unsigned *)&((NameinGraphicIcon *)p)->animActive=1;}

int NAMEIN_GRAPHIC_StepIconAnim(char *p) {
    Vec2 pos;
    int tick;
    if (((NameinGraphicIcon *)p)->animActive) {
        tick=((NameinGraphicIcon *)p)->animTick;
        ((NameinGraphicIcon *)p)->animTick=tick+1;
        CLACT_GetActorSurfacePos((struct Actor *)((NameinGraphicIcon *)p)->actor,(struct PtS *)&pos,0);
        pos.y=20-((12*FX_SinCosTable_[((unsigned short)(32767*tick/8)>>4)*2])>>12);
        CLACT_AddActorSurfacePos((struct Obj *)(((NameinGraphicIcon *)p)->actor),(const struct Vec2 *)(&pos),0);
        if (((NameinGraphicIcon *)p)->animTick>8) ((NameinGraphicIcon *)p)->animActive=0;
        return 0;
    }
    return 1;
}

int NAMEIN_GRAPHIC_GetIconMode(int x, int y)
{
    switch (x) {
    case 0:
    case 5:
    case 6:
    case 7:
        return 0;
    case 1: return 3;
    case 2: return 4;
    case 3: return 1;
    case 4: return y == 0xffff ? 5 : 2;
    default: return 0;
    }
}

int NAMEIN_GRAPHIC_IsPointInRect(int *p, int *q){return ((((NameinGraphicPoint *)q)->x-((NameinGraphicRect4 *)p)->left)<=(((NameinGraphicRect4 *)p)->right-((NameinGraphicRect4 *)p)->left)) & ((((NameinGraphicPoint *)q)->y-((NameinGraphicRect4 *)p)->top)<=(((NameinGraphicRect4 *)p)->bottom-((NameinGraphicRect4 *)p)->top));}

int NAMEIN_GRAPHIC_GetNameForAction(u8 *p, int a, int b)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        if (STRBUF_GetLength((struct U16Vec *)(((NameinGraphicWork *)p)->nameStrbuf)) == 0)
            return (int)MSGDATA_AllocString((struct MsgBank *)gSpeciesNameBank,
                                 *(u16 *)(*(u32 *)&((NameinGraphicWork *)p)->args + 4));
        return (int)STRBUF_Clone((struct U16Vec *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    case 2:
        return (int)STRBUF_Clone((struct U16Vec *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    case 3:
        return 0;
    case 4:
        return (int)STRBUF_Clone((struct U16Vec *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    case 5:
        return (int)STRBUF_Clone((struct U16Vec *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    case 6:
        return (int)STRBUF_Clone((struct U16Vec *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    case 7:
        return (int)STRBUF_Clone((struct U16Vec *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    default:
        return 0;
    }
}

void NAMEIN_GRAPHIC_CommitName(char *p) {
    int text;
    char *obj;
    ((NameinGraphicConfig *)(*(char * *)&((NameinGraphicWork *)p)->args))->accepted=0;
    text=(int)STRBUF_Clone((struct U16Vec *)(((NameinGraphicConfig *)(*(char * *)&((NameinGraphicWork *)p)->args))->name),30);
    NAMEIN_GRAPHIC_CopyToStrbuf(p+0x68,(struct Strbuf *)((NameinGraphicConfig *)(*(char * *)&((NameinGraphicWork *)p)->args))->name);
    if (STRBUF_IsEqual((struct Buf *)text,(struct Buf *)(((NameinGraphicConfig *)(*(char * *)&((NameinGraphicWork *)p)->args))->name)))
        ((NameinGraphicConfig *)(*(char * *)&((NameinGraphicWork *)p)->args))->accepted=1;
    if (!NAMEIN_GRAPHIC_HasNonSpace((u8 *)((int)(p+0x68)))) {
        STRBUF_Copy((struct U16Vec *)(((NameinGraphicConfig *)(*(char * *)&((NameinGraphicWork *)p)->args))->name),(struct U16Vec *)text);
        ((NameinGraphicConfig *)(*(char * *)&((NameinGraphicWork *)p)->args))->accepted=1;
    }
    STRBUF_Delete((struct U16Vec *)text);
    if (!STRBUF_GetLength((struct U16Vec *)(((NameinGraphicConfig *)(*(char * *)&((NameinGraphicWork *)p)->args))->name))) {
        obj=*(char * *)&((NameinGraphicWork *)p)->args;
        if (((NameinGraphicConfig *)obj)->mode!=0 && ((NameinGraphicConfig *)obj)->mode!=3) ((NameinGraphicConfig *)obj)->accepted=1;
    }
}

int NAMEIN_GRAPHIC_IsNameValid(int p)
{
    int *q = *(int * *)&((NameinGraphicWork *)p)->args;

    if (*q == 0 || *q == 3) {
        if (NAMEIN_GRAPHIC_GetLength((const u8 *)(p + 0x68)) == 0 && NAMEIN_GRAPHIC_GetSecondaryLength((const u8 *)(p + 0x68)) == 0) {
            return 0;
        }
        if (NAMEIN_GRAPHIC_HasNonSpace((u8 *)(p + 0x68)) == 0) {
            return 0;
        }
    }
    return 1;
}

void NAMEIN_GRAPHIC_InitCallback(u8 *a, u32 b, u32 c)
{
    MI_CpuFill8(a, 0, 0x10);
    ((NameinGraphicCallback *)a)->owner = b;
    NAMEIN_GRAPHIC_SetCallback(a, c);
}

void NAMEIN_GRAPHIC_ClearCallback(void *p){MI_CpuFill8(p,0,16);}

void NAMEIN_GRAPHIC_RunCallback(u8 *p)
{
    if (((NameinGraphicCallback *)p)->state == 0) {
        ((NameinGraphicCallbackFn)*(void **)p)(p, p + 8, ((NameinGraphicCallback *)p)->owner);
    }
}

unsigned NAMEIN_GRAPHIC_GetCallbackState(unsigned char *p){return ((NameinGraphicCallback *)p)->state;}

void NAMEIN_GRAPHIC_SetCallback(unsigned char *p,unsigned value){((NameinGraphicCallback *)p)->fn=value;((NameinGraphicCallback *)p)->arg=0;}

void NAMEIN_GRAPHIC_FinishCallback(unsigned char *p){((NameinGraphicCallback *)p)->state=1;}

void NAMEIN_GRAPHIC_CallbackWaitDraw(unsigned char *p,int *unused,unsigned char *q){int v;v=NAMEIN_GRAPHIC_IsGridDrawDone((char *)(q+252));v|=NAMEIN_GRAPHIC_IsFieldDrawDone(q+104);if(NAMEIN_GRAPHIC_IsMsgDrawDone(q+560)|v)NAMEIN_GRAPHIC_SetCallback(p,(unsigned)NAMEIN_GRAPHIC_CallbackFadeIn);}

void NAMEIN_GRAPHIC_CallbackFadeIn(unsigned char *p,int *state) {
    switch (*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if (!FADE_IsActive()) *state=2; break;
    case 2: NAMEIN_GRAPHIC_SetCallback(p,(unsigned)NAMEIN_GRAPHIC_CallbackGridAction); break;
    }
}

void NAMEIN_GRAPHIC_CallbackFadeOut(unsigned char *p,int *state) {
    switch (*state) {
    case 0: FADE_Start(3,0,16,0); *state=1; break;
    case 1: if (!FADE_IsActive()) *state=2; break;
    case 2: NAMEIN_GRAPHIC_SetCallback(p,(unsigned)NAMEIN_GRAPHIC_CallbackFinish); break;
    }
}

/*
 * Padding: two zero bytes at 0x021F47B2, then a function prologue.
 */
void NAMEIN_GRAPHIC_CallbackWaitPrint(unsigned char *a, int *state, char *p)
{
    char *q = p + 0x254;
    switch (*state) {
    case 0:
        TCBL_Main(*(struct Tcbl * *)&((NameinGraphicTcbl *)q)->handle);
        switch (PRINTSYS_PrintStreamGetState(((NameinGraphicTcbl *)q)->stream)) {
        case 0:
            if (((unsigned)KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
                PRINTSYS_PrintStreamShortWait(*(struct Rec * *)&((NameinGraphicTcbl *)q)->stream, 0);
                if (((unsigned)KEY_GetCont() & 3) != 0) UI_SetInputMode(0);
                else UI_SetInputMode(1);
            }
            break;
        case 2:
            *state = 1;
            break;
        case 1:
            if (((unsigned)KEY_GetTrg() & 3) != 0 || TOUCHPANEL_GetTrg() != 0) {
                PRINTSYS_PrintStreamReleasePause(((NameinGraphicTcbl *)q)->stream);
                if (((unsigned)KEY_GetTrg() & 3) != 0) UI_SetInputMode(0);
                else UI_SetInputMode(1);
            }
            break;
        }
        break;
    case 1:
        if (((NameinGraphicTcbl *)q)->flag >= ((NameinGraphicTcbl *)q)->counter) *state = 2;
        else (((NameinGraphicTcbl *)q)->flag)++;
        break;
    case 2:
        NAMEIN_GRAPHIC_SetCallback(a, ((NameinGraphicTcbl *)q)->callback);
        break;
    }
}

static inline int invert(char *p,int v) { int r=1; if(NAMEIN_GRAPHIC_ApplyConversion((unsigned char *)p,v)==0) r=0; return r; }

void NAMEIN_GRAPHIC_CallbackGridAction(unsigned char *owner,void *unused,char *p)
{
    u16 selected;
    u32 action=NAMEIN_GRAPHIC_GetGridAction(p+0xfc,&selected);
    u32 value=NAMEIN_GRAPHIC_GetGridIndex((const u8 *)(p+0xfc));
    if(((NameinGraphicWork *)p)->pendingMsg==1) {
        if(action!=0 || NAMEIN_GRAPHIC_IsIconAnimDone((unsigned char *)(p+0x264))!=0 || (KEY_GetTrg()&~1u)!=0) {
            int *q=*(int * *)&((NameinGraphicWork *)p)->args;
            if(q[0]==1) {
                if(q[2]==0) NAMEIN_GRAPHIC_PrintPokeMsg(p+0x230,q[0],((NameinGraphicConfig *)q)->valueA,((NameinGraphicConfig *)q)->valueB,30);
                else NAMEIN_GRAPHIC_PrintMonMsg(p+0x230,q[0],(void *)q[2]);
            } else NAMEIN_GRAPHIC_PrintMsg(p+0x230,q[0]);
            ((NameinGraphicWork *)p)->pendingMsg=0;
        }
    }
    switch(action) {
    case 1: if(NAMEIN_GRAPHIC_AppendChar(p+0x68,selected)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 2: if(NAMEIN_GRAPHIC_AppendCandidate((unsigned char *)(p+0x68),selected,value)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 3: if(invert(p+0x68,0)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 4: if(invert(p+0x68,1)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 10: if(NAMEIN_GRAPHIC_RevertChar(p+0x68)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 5: if(NAMEIN_GRAPHIC_Backspace((unsigned char *)(p+0x68))) GFL_USE_PlaySeDefaultVolume(0x553); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 6: NAMEIN_GRAPHIC_ClearSecondary(p+0x68); break;
    case 11: NAMEIN_GRAPHIC_CommitSecondary(p+0x68); break;
    case 7: if(NAMEIN_GRAPHIC_GetSecondaryLength((const u8 *)((int)(p+0x68)))==0) {
        if(NAMEIN_GRAPHIC_IsNameValid((int)p)==0) {GFL_USE_PlaySeDefaultVolume(0x557);NAMEIN_GRAPHIC_PrintMsg(p+0x230,8);((NameinGraphicWork *)p)->pendingMsg=1;}
        else {
            if(PROF_WORD_FindMatch(*(u32 * *)&((NameinGraphicWork *)p)->profWord,p+0x68,30)) GFL_USE_PlaySeDefaultVolume(0x557);
            else if(PROF_WORD_CheckDigitCount(p+0x68,((NameinGraphicWork *)p)->primaryLength,30)) {GFL_USE_PlaySeDefaultVolume(0x557);NAMEIN_GRAPHIC_PrintMsg(p+0x230,9);((NameinGraphicWork *)p)->pendingMsg=1;}
            else {
                int *q;
                GFL_USE_PlaySeDefaultVolume(0x54d);NAMEIN_GRAPHIC_CommitName(p);q=*(int * *)&((NameinGraphicWork *)p)->args;
                if(q[0]==1 && q[3]!=0) {NAMEIN_GRAPHIC_PrintNameStream(p+0x254,p+0x230,q,30);NAMEIN_GRAPHIC_SetCallback(owner,(u32)NAMEIN_GRAPHIC_CallbackWaitPrint);}
                else NAMEIN_GRAPHIC_SetCallback(owner,(u32)NAMEIN_GRAPHIC_CallbackFadeOut);
            }
        }
    } else {NAMEIN_GRAPHIC_CommitSecondary(p+0x68);GFL_USE_PlaySeDefaultVolume(0x54d);} break;
    case 0: if(NAMEIN_GRAPHIC_IsIconAnimDone((unsigned char *)(p+0x264))) {
        int text=NAMEIN_GRAPHIC_GetNameForAction((u8 *)p,**(int * *)&((NameinGraphicWork *)p)->args,30);
        NAMEIN_GRAPHIC_ClearPrimary((unsigned char *)(p+0x68));
        if(text) {NAMEIN_GRAPHIC_AppendString(p+0x68,STRBUF_GetChars((struct U16Vec *)text));STRBUF_Delete((struct U16Vec *)text);}
        GFL_USE_PlaySeDefaultVolume(0x54c);
    } break;
    case 9: NAMEIN_GRAPHIC_CommitSecondary(p+0x68);if(NAMEIN_GRAPHIC_AppendChar(p+0x68,selected)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557);break;
    default: break;
    }
    NAMEIN_GRAPHIC_UpdateGrid(p+0xfc,p+0x68);
    NAMEIN_GRAPHIC_RefreshInputField((u8 *)(p+0x68));
    NAMEIN_GRAPHIC_UpdateIconTouch(p+0x264);
    NAMEIN_GRAPHIC_IsMsgDrawDone((u8 *)(p+0x230));
}

void NAMEIN_GRAPHIC_CallbackFinish(unsigned char *a, int unused, char *p)
{
    unsigned n;
    if (*(void **)(OBJ(p) + 0x28) != 0) {
        n = (unsigned int)NAMEIN_GRAPHIC_GetGridMode((const unsigned char *)(p + 0xFC));
        BEACON_SetInputFlag(*(void **)(OBJ(p) + 0x28), (u32)(*(void **)OBJ(p)), n);
    }
    if (*(void **)(OBJ(p) + 0x24) != 0) NAMEIN_GRAPHIC_SetCallback(a, (unsigned)NAMEIN_GRAPHIC_CallbackPauseSave);
    else NAMEIN_GRAPHIC_FinishCallback(a);
}

void NAMEIN_GRAPHIC_CallbackPauseSave(unsigned char *p,int *state,unsigned char *q){switch(*state){case 0:SAVE_CONTROL_INTR_Pause(*(unsigned char * *)&((NameinGraphicConfig *)(*(unsigned char * *)&((NameinGraphicWork *)q)->args))->saveControl);*state=1;break;case 1:if(SAVE_CONTROL_INTR_IsPausedOrFinished(*(unsigned char * *)&((NameinGraphicConfig *)(*(unsigned char * *)&((NameinGraphicWork *)q)->args))->saveControl)==1)NAMEIN_GRAPHIC_FinishCallback(p);break;}}

static inline void G2_BlendNone(void) { *(volatile unsigned short *)0x04000050 = 0; }

static inline void G2S_BlendNone(void) { *(volatile unsigned short *)0x04001050 = 0; }

static inline void GX_SetVisibleWnd(int window) { *(volatile unsigned *)0x04000000 = (*(volatile unsigned *)0x04000000 & ~0xE000) | (window << 13); }

static inline void GXS_SetVisibleWnd(int window) { *(volatile unsigned *)0x04001000 = (*(volatile unsigned *)0x04001000 & ~0xE000) | (window << 13); }

/*
 * volatile: hardware 0x04000050, 0x04001050, 0x04000000, 0x04001000.
 */
unsigned char *NAMEIN_GRAPHIC_CreateDisplay(unsigned swap, unsigned short heap)
{
    unsigned char *p;
    p = GFL_HEAP_Alloc(heap, 0x10, 0, d_021F5784, 0x1BB);
    MI_CpuFill8(p, 0, 0x10);
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021F55D0);
    BMP_SetDisplaySwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    NAMEIN_GRAPHIC_InitBg(p, heap);
    NAMEIN_GRAPHIC_InitClact(p + 4, (int)&d_021F55D0, heap);
    ((NameinGraphicDisplay *)p)->mainTask = GFL_USE_AddMainTask((unsigned)NAMEIN_GRAPHIC_DisplayMainTask, (unsigned)p, 0);
    return p;
}

void NAMEIN_GRAPHIC_DeleteDisplay(unsigned char *p)
{
    TCB_DeleteTask(*(struct Node * *)&((NameinGraphicDisplay *)p)->mainTask);
    NAMEIN_GRAPHIC_ExitClact(p + 4);
    NAMEIN_GRAPHIC_ExitBg(p);
    GF_FONT_SetDefaultTextColor();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    MI_CpuFill8(p, 0, 0x10);
    GFL_HEAP_Free(p);
}

void NAMEIN_GRAPHIC_DrawDisplay(u8 *p)
{
    NAMEIN_GRAPHIC_DrawClact(p + 4);
    NAMEIN_GRAPHIC_Empty(p);
}

unsigned NAMEIN_GRAPHIC_GetDisplayHandle(unsigned char *p){return NAMEIN_GRAPHIC_LoadWord((const unsigned *)(p+4));}

void NAMEIN_GRAPHIC_DisplayMainTask(u32 a, u8 *b)
{
    NAMEIN_GRAPHIC_ResetBg(b);
    NAMEIN_GRAPHIC_VBlankClact(b + 4);
}

/*
 * Match lever: bind the entry id before binding its element pointer.
 */
void NAMEIN_GRAPHIC_InitBg(void *p, unsigned short heap)
{
    unsigned i = 0;
    unsigned id;
    const Entry *e;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&d_021F55A4));
    for (; i < 8; i++) {
        id = d_021F5600[i].id;
        e = &d_021F5600[i];
        BG_SYS_InitBgLayer(id, &e->config, e->type);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible((unsigned char)id, (unsigned char)e->enabled);
    }
}

/*
 * evidence: caller truncates id to u8 before 020403F4, whose own source uses u32.
 */
void NAMEIN_GRAPHIC_ExitBg(void *p)
{
    u32 i;
    for (i = 0; i < 8; i++)
        BG_SYS_FreeLayerBuf((u8)d_021F5600[i].id);
    BMP_WIN_Exit();
    BG_SYS_Delete();
    MI_CpuFill8(p, 0, 4);
}

void NAMEIN_GRAPHIC_Empty(u8 *a0) {}

void NAMEIN_GRAPHIC_ResetBg(u8 *a0) { BG_SYS_Update(); }

void NAMEIN_GRAPHIC_InitClact(unsigned char *p, int a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((const struct Cfg *)0x021F55B4, a, b);
    *(int *)&((NameinGraphicClact *)p)->unit = (int)CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((NameinGraphicClact *)p)->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void NAMEIN_GRAPHIC_ExitClact(u8 *p)
{
    CLACT_DeleteUnit((struct Bank *)(((NameinGraphicClact *)p)->unit));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void NAMEIN_GRAPHIC_DrawClact(u8 *a0) { CLACT_DrawSystem(); }

void NAMEIN_GRAPHIC_VBlankClact(u8 *a0) { CLACT_VBlankSystem(); }

/*
 * extent: lead tail-call stub followed by unlabelled load-and-return at 021F4D1C.
 */
u32 NAMEIN_GRAPHIC_LoadWord(const u32 *p) { return *p; }
