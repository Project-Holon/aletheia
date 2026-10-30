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
 *   BG_SYS_GetScrollY 0x02040804 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   BMP_Clear 0x02043B5C arm
 *   NAMEIN_GRAPHIC_ConvertCellMode 0x021F2884 thumb ov194
 *   NAMEIN_GRAPHIC_LoadGrid 0x021F25F8 thumb ov194
 *   KEY_GetRepeat 0x0203633C arm
 *   KEY_GetTrg 0x020362DC arm
 *   UI_SetInputMode 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   NAMEIN_GRAPHIC_PickerMove 0x021F26E0 thumb ov194
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   NAMEIN_GRAPHIC_FindCellAtPoint 0x021F265C thumb ov194
 *   NAMEIN_GRAPHIC_PickerToChar 0x021F2614 thumb ov194
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   WORDSET_SetSlotMonSpeciesName 0x0201EE84 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Create  0x0203101C arm
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_SetSlotMonNickname 0x0201EEF4 thumb
 *   WORDSET_SetSlotTag 0x0201EE0C thumb
 *   WORDSET_SetSlotBoxName 0x0201F164 thumb
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
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
 *   MISC_SetInputFlag 0x0200C0FC thumb
 *   SAVE_CONTROL_INTR_Pause 0x021BD368 thumb ov088
 *   SAVE_CONTROL_INTR_IsPausedOrFinished 0x021BD380 thumb ov088
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
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
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define NAMEIN_GRAPHIC_DrawCellTips NAMEIN_GRAPHIC_DrawCellTips_header
#endif
#include "namein_graphic_shared_types.h"
#include "../sdk_ioreg.h"
#include "namein_graphic_field.h"
#ifdef __MWERKS__
#undef NAMEIN_GRAPHIC_DrawCellTips
extern void NAMEIN_GRAPHIC_DrawCellTips(char *, char *, void *, void *, u32);
#endif


struct Descriptor;

struct Cfg;

struct NameinGraphicMainRect;

struct PrintSys;

struct CharBuf;

struct U16Vec;

struct MsgBank;

struct WordSet;

struct S02031140;

struct Rec3;

struct Bmp;

struct Grid;

struct ClactActor;

struct BmpOamParam;

struct BmpOamSys;

struct ClactActor;

struct ClactVec2;

struct ClactVec2;

struct Buf;

struct Strbuf;

struct Tcbl;

struct Rec;

struct Blk34;

struct DispVram;

struct Node;

struct DispConfig;

struct Unit;



typedef struct {int left,top,right,bottom;} NameinGraphicRect;

#include "../types.h"
#include "../ov194/namein_graphic_field.h"

typedef struct {u16 w;u16 h;u32 pad;} Dim8;

typedef struct {short x,y;} NameinGraphicVec2;

typedef struct {unsigned words[4];} Disp;

typedef struct {unsigned words[8];} Bg;

typedef struct {unsigned id;Bg config;unsigned type,enabled;} NameinGraphicEntry;

#include "../ov010/namein_args.h"

/* The CLACT sub-object of the display (display+0x04). */
typedef struct NameinGraphicClact {
    void *unit;                      /* 0x00 */
} NameinGraphicClact;

/* The display object created by NAMEIN_GRAPHIC_CreateDisplay. */
typedef struct NameinGraphicDisplay {
    void *bg;                        /* 0x00 */
    void *clactUnit;                 /* 0x04 */
    unsigned int reserved08;             /* 0x08 */
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

#include "../arm9/mi_memory.h"

/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define ARC_UTIL_LoadPaletteDataFromArchive ARC_UTIL_LoadPaletteDataFromArchive_header
#endif
#include "../arm9/arc_util.h"
#ifdef __MWERKS__
#undef ARC_UTIL_LoadPaletteDataFromArchive
extern void * ARC_UTIL_LoadPaletteDataFromArchive(u32, u32, u32, void *, u32);
#endif

/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define BG_SYS_InitBgLayer BG_SYS_InitBgLayer_header
#endif
#include "../arm9/bg_sys.h"
#ifdef __MWERKS__
#undef BG_SYS_InitBgLayer
extern void BG_SYS_InitBgLayer(unsigned char, const struct BgTemplate *, unsigned char);
#endif



#include "namein_graphic_main.h"

struct BmpWin;

#include "../arm9/bmp_win.h"





#include "../arm9/ui.h"

struct NameinGraphicMainRect;



#include "../arm9/gfl_heap_wrap.h"





struct PrintQueue;

/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define PRINTSYS_PrintQueColor PRINTSYS_PrintQueColor_header
#define PRINTSYS_PrintStream PRINTSYS_PrintStream_header
#endif
#include "../arm9/printsys.h"
#ifdef __MWERKS__
#undef PRINTSYS_PrintQueColor
#undef PRINTSYS_PrintStream
extern void PRINTSYS_PrintQueColor(struct PrintQueue *, struct Bmp *, s16, u32, struct Strbuf *, struct GfFont *, u32);
extern struct TextPrinter * PRINTSYS_PrintStream(struct BmpWin *, u32, u32, struct Strbuf *, struct GfFont *, u32, struct Tcbl *, u32, u32, u16);
#endif

#include "../arm9/g2.h"



typedef short s16_p07;
#include "../arm9/bmp.h"



#include "../arm9/key.h"



#include "../arm9/gfl_use.h"


#include "../arm9/touchpanel.h"



#include "../arm9/strbuf.h"

#include "../arm9/bmp_menuwork.h"



#include "../arm9/msgdata.h"
struct GfFont;


/* Callee species is u16; this caller passes r2 without truncation. */
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define POKE_TOOL_Create POKE_TOOL_Create_header
#endif
#include "../arm9/poke_tool.h"
#ifdef __MWERKS__
#undef POKE_TOOL_Create
extern struct PokemonParam * POKE_TOOL_Create(u32, u16, u64, u16);
#endif
struct PokemonParam;


#include "../arm9/wordset.h"



/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define TCBL_Create TCBL_Create_header
#endif
#include "../arm9/tcbl.h"
#ifdef __MWERKS__
#undef TCBL_Create
extern struct TcblSystem * TCBL_Create(int, int, int, int);
#endif
struct TextPrinter;

struct TcblSystem;


/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define WORDSET_CreateDefault WORDSET_CreateDefault_header
#endif
#include "../arm9/gf_font.h"
#ifdef __MWERKS__
#undef WORDSET_CreateDefault
extern struct WordSet * WORDSET_CreateDefault(u32);
#endif
struct NameInArgs;

#include "../ov010/namein_setup.h"







#include "../arm9/msg_speed.h"

/* The caller consumes R0 returned by the legacy void forwarding wrapper. */


#include "../arm9/app_icon.h"





#include "../arm9/poke_tool_ext.h"





#include "../arm9/arc_tool.h"

#include "../arm9/clact.h"





struct ClactActor;



struct BmpOamParam;
struct BmpOamSys;
struct BmpOam;


#include "../arm9/bmp_oam.h"


struct BmpOam;





struct ClactVec2;











#include "../arm9/fade.h"



















#include "prof_word.h"



struct MiscSave;

#include "../arm9/beacon.h"
struct SaveControlIntr;

#include "../ov088/save_control_intr.h"










struct TcbTask;

#include "../arm9/tcb_list.h"











struct DispVramCfg;
struct ClactSysInit;
struct ClactSysInit;










int NAMEIN_GRAPHIC_SymbolGetValue(NameinGraphicPair *p,NameinGraphicPair *out);

void NAMEIN_GRAPHIC_InitGrid(u8 *p,int mode,void *font,void *window,void **data,void *palette,u32 heap);

void NAMEIN_GRAPHIC_DeleteGrid(u8 *p);

void NAMEIN_GRAPHIC_UpdateGrid(char *p,char *q);

int NAMEIN_GRAPHIC_GetGridAction(char *p, unsigned short *out);

u32 NAMEIN_GRAPHIC_GetGridIndex(const u8 *p);

int NAMEIN_GRAPHIC_IsGridDrawDone(char *p);

int NAMEIN_GRAPHIC_GetGridMode(const u8 *p);

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

void NAMEIN_GRAPHIC_InitMsgBox(unsigned char *p,struct GfFont *a,struct MsgBank *b,struct PrintQueue *c,struct WordSet *d,unsigned short e);

void NAMEIN_GRAPHIC_DeleteMsgBox(u8 *p);

void NAMEIN_GRAPHIC_PrintMsg(char *p,int value);

void NAMEIN_GRAPHIC_PrintPokeMsg(char *p,int value,u32 id,u32 form,u16 heap);

void NAMEIN_GRAPHIC_PrintMonMsg(char *p,int value,void *mon);

int NAMEIN_GRAPHIC_IsMsgDrawDone(u8 *p);

void NAMEIN_GRAPHIC_InitTcbl(char *p, int v);

void NAMEIN_GRAPHIC_DeleteTcbl(unsigned char *p);

void NAMEIN_GRAPHIC_PrintNameStream(char *p,char *q,NameInArgs *w,u32 heap);

void NAMEIN_GRAPHIC_InitIconActor(NameinGraphicIcon *o, u32 mode, u32 iconIndex, u32 iconForm, struct Unit *s0, struct GfFont *s1, struct PrintQueue *s2, struct MsgBank *s3, struct BmpOamSys *s4, u16 heap);

void NAMEIN_GRAPHIC_DeleteIconActor(unsigned char *p);

void NAMEIN_GRAPHIC_UpdateIconTouch(char *p);

void NAMEIN_GRAPHIC_FlushIconOam(unsigned char *p);

unsigned NAMEIN_GRAPHIC_IsIconAnimDone(unsigned char *p);

void NAMEIN_GRAPHIC_StartIconAnim(unsigned char *p);

int NAMEIN_GRAPHIC_StepIconAnim(char *p);

int NAMEIN_GRAPHIC_GetIconMode(int x, int y);

int NAMEIN_GRAPHIC_IsPointInRect(int *p, int *q);

struct Strbuf *NAMEIN_GRAPHIC_GetNameForAction(u8 *p, int a, int b);

void NAMEIN_GRAPHIC_CommitName(char *p);

int NAMEIN_GRAPHIC_IsNameValid(char *p);

void NAMEIN_GRAPHIC_InitCallback(NameinGraphicCallback *a, void *b, NameinGraphicStep c);

void NAMEIN_GRAPHIC_ClearCallback(NameinGraphicCallback *p);

void NAMEIN_GRAPHIC_RunCallback(NameinGraphicCallback *p);

unsigned NAMEIN_GRAPHIC_GetCallbackState(NameinGraphicCallback *p);

void NAMEIN_GRAPHIC_SetCallback(NameinGraphicCallback *p,NameinGraphicStep value);

void NAMEIN_GRAPHIC_FinishCallback(NameinGraphicCallback *p);

void NAMEIN_GRAPHIC_CallbackWaitDraw(NameinGraphicCallback *p,int *unused,unsigned char *q);

void NAMEIN_GRAPHIC_CallbackFadeIn(NameinGraphicCallback *p,int *state);

void NAMEIN_GRAPHIC_CallbackFadeOut(NameinGraphicCallback *p,int *state);

void NAMEIN_GRAPHIC_CallbackWaitPrint(NameinGraphicCallback *a, int *state, char *p);

void NAMEIN_GRAPHIC_CallbackGridAction(NameinGraphicCallback *owner,void *unused,char *p);

void NAMEIN_GRAPHIC_CallbackFinish(NameinGraphicCallback *a, int unused, char *p);

void NAMEIN_GRAPHIC_CallbackPauseSave(NameinGraphicCallback *p,int *state,unsigned char *q);

unsigned char *NAMEIN_GRAPHIC_CreateDisplay(unsigned swap, unsigned short heap);

void NAMEIN_GRAPHIC_DeleteDisplay(unsigned char *p);

void NAMEIN_GRAPHIC_DrawDisplay(u8 *p);

struct Unit *NAMEIN_GRAPHIC_GetDisplayHandle(unsigned char *p);

void NAMEIN_GRAPHIC_DisplayMainTask(struct TcbTask *a, void *b);

void NAMEIN_GRAPHIC_InitBg(void *p, unsigned short heap);

void NAMEIN_GRAPHIC_ExitBg(void *p);

void NAMEIN_GRAPHIC_Empty(u8 *unused);

void NAMEIN_GRAPHIC_ResetBg(u8 *unused);

void NAMEIN_GRAPHIC_InitClact(unsigned char *p, struct DispVramCfg *a, int b);

void NAMEIN_GRAPHIC_ExitClact(u8 *p);

void NAMEIN_GRAPHIC_DrawClact(u8 *unused);

void NAMEIN_GRAPHIC_VBlankClact(u8 *unused);

void *NAMEIN_GRAPHIC_LoadWord(void *const *p);

#include "nsbtx_to_clwk.h"

extern const u8 d_021F5569[];
extern const u8 d_ja_021F53C4[];

extern short FX_SinCosTable_[];

extern struct MsgBank *gSpeciesNameBank;

extern const char d_021F5784[];

extern const struct DispVram d_021F55D0;

extern const Disp d_021F55A4;

extern const NameinGraphicEntry d_021F5600[];

int NAMEIN_GRAPHIC_SymbolGetValue(NameinGraphicPair *p,NameinGraphicPair *out) {
 int result;NameinGraphicPair xy;
 result=0;
 switch((unsigned)p->y) {
 case 0: if(p->x==10)result=NAMEIN_KIND_BACK;else {xy=*p;result=1;}break;
 case 1: if(p->x==9)result=NAMEIN_KIND_OK;else {xy=*p;result=1;}break;
 case 2: if(p->x==0 || p->x==9)result=NAMEIN_KIND_TOGGLE;else {xy.x=p->x-1;xy.y=p->y;result=1;}break;
 case 3: result=NAMEIN_KIND_SPACE;if(p->x!=PM_LANG_JA(4,5))result=p->x+2;break;
 }
 if(result==1 && out) {*out=xy;}return result;
}

/*
 * tail: two zero alignment bytes at 021F31B6 before 31B8.
 * prototype: 256C retains fifth heap input visibly stored by caller; heap forwards use full words without caller-side truncation.
 */
void NAMEIN_GRAPHIC_InitGrid(u8 *p,int mode,void *font,void *window,void **data,void *palette,u32 heap)
{
 NameinGraphicBox box;
 void *bg;
 int index;
 MI_CpuFill8(p,0,sizeof(NameinGraphicGrid));
 ((NameinGraphicGrid *)p)->selectionX=0;((NameinGraphicGrid *)p)->selectionY=0;
 ((NameinGraphicGrid *)p)->font=font;((NameinGraphicGrid *)p)->printSys=window;((NameinGraphicGrid *)p)->heap=heap;
 ((NameinGraphicGrid *)p)->mode=mode;((NameinGraphicGrid *)p)->targetMode=mode;((NameinGraphicGrid *)p)->data=data;
 ((NameinGraphicGrid *)p)->paletteHandleA=ARC_UTIL_LoadPaletteDataFromArchive(118,10,0,(void *)((((void *)&((struct NameinGraphicGrid *)p)->paletteDataA))),heap);
 ((NameinGraphicGrid *)p)->paletteHandleB=ARC_UTIL_LoadPaletteDataFromArchive(118,5,0,(void *)((((void *)&((struct NameinGraphicGrid *)p)->paletteDataB))),heap);
 if(mode==NAMEIN_GRAPHIC_MODE_SYMBOL){BG_SYS_DecodeTile(1,*(char * *)&((NameinGraphicGrid *)p)->paletteDataA+12,2048);BG_SYS_SetPlaneVisible(2,0);}
 else {BG_SYS_DecodeTile(1,*(char * *)&((NameinGraphicGrid *)p)->paletteDataB+12,2048);BG_SYS_SetPlaneVisible(2,1);}
 BG_SYS_PushTile(1);
 NAMEIN_GRAPHIC_InitCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor),mode,palette,heap);
#if LANGUAGE == LANGUAGE_JAPANESE
 NAMEIN_GRAPHIC_InitPicker((char *)p,mode,((NameinGraphicGrid *)p)->data,heap);
#else
 index=NAMEIN_GRAPHIC_GridIndex(((NameinGraphicGrid *)p)->mode,((NameinGraphicGrid *)p)->index,((struct NameinGraphicGrid *)p)->variant);
 NAMEIN_GRAPHIC_InitPicker((char *)p,mode,index,((NameinGraphicGrid *)p)->data,heap);
#endif
 bg=(void *)BMP_WIN_Create(3,3,5,26,15,15,1);
 ((NameinGraphicGrid *)p)->bmpWin=bg;
 BMP_WIN_TransferChars(bg);BMP_WIN_MakeScreen(bg);BG_SYS_PushTile(BMP_WIN_GetBgLayer(bg));
 ((NameinGraphicGrid *)p)->tipBmp=((NameinGraphicGrid *)p)->bmpWin;((struct NameinGraphicGrid *)p)->tipDirty=0;
 NAMEIN_GRAPHIC_DrawCellTips((char *)p,(char *)((void *)&((struct NameinGraphicGrid *)p)->tipBmp),window,font,heap);
 if(UI_GetInputMode()==0){
  if(NAMEIN_GRAPHIC_PickerGetBox((char *)p,(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)),&box))NAMEIN_GRAPHIC_SetupCursor((char *)((void *)&((struct NameinGraphicGrid *)p)->cursor),1, (const struct NameinGraphicMainRect *)&box,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
 }else {
  if(NAMEIN_GRAPHIC_PickerGetBox((char *)p,(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)),&box))NAMEIN_GRAPHIC_SetupCursor((char *)((void *)&((struct NameinGraphicGrid *)p)->cursor),0, (const struct NameinGraphicMainRect *)&box,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
 }
}

void NAMEIN_GRAPHIC_DeleteGrid(u8 *p) {int off;BMP_WIN_Delete(((NameinGraphicGrid *)p)->bmpWin);NAMEIN_GRAPHIC_ClearPicker(p);NAMEIN_GRAPHIC_ClearCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor));GFL_HEAP_Free(((NameinGraphicGrid *)p)->paletteHandleA);GFL_HEAP_Free(((NameinGraphicGrid *)p)->paletteHandleB);off=sizeof(NameinGraphicGrid);MI_CpuFill8(p,0,off);}

void NAMEIN_GRAPHIC_UpdateGrid(char *p,char *q)
{
    int out0[4];
    int out2[4];
    NameinGraphicRect rect;
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
        if(NAMEIN_GRAPHIC_IsFieldFull(q)){NAMEIN_GRAPHIC_FindCellByValue(p,NAMEIN_KIND_OK,(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)));((NameinGraphicGrid *)p)->action=11;}
        ((NameinGraphicGrid *)p)->state=0;
        break;
    }
    NAMEIN_GRAPHIC_PickerGetBox(p, (NameinGraphicPair *)((((void *)&((struct NameinGraphicGrid *)p)->selectionX))), (NameinGraphicBox *)&rect);
    NAMEIN_GRAPHIC_UpdateCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor),((NameinGraphicGrid *)p)->mode,&rect);
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
 void *q;
 q=((NameinGraphicGrid *)p)->printSys;
 if(((NameinGraphicGrid *)p)->tipDirty) {
 if(PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)q,(void *)BMP_WIN_GetBmp(*(struct BmpWin **)&((NameinGraphicGrid *)p)->tipBmp))==0) {
 BMP_WIN_TransferChars(((NameinGraphicGrid *)p)->tipBmp);((NameinGraphicGrid *)p)->tipDirty=0;
 }}
 if(((NameinGraphicGrid *)p)->tipDirty==0)return 1;return 0;
}

int NAMEIN_GRAPHIC_GetGridMode(const u8 *p) {return ((NameinGraphicGrid *)p)->mode;}

#if LANGUAGE != LANGUAGE_JAPANESE
u32 NAMEIN_GRAPHIC_GridIndex(u32 a,u32 b,u32 c) {if(a==3) a=b+(a+2*c);return a;}
#endif

int NAMEIN_GRAPHIC_SetGridMode(char *p,int mode) {
 int flag;
 if(((NameinGraphicGrid *)p)->targetMode!=mode) {
 ((NameinGraphicGrid *)p)->targetMode=mode;((NameinGraphicGrid *)p)->animTick=0;((NameinGraphicGrid *)p)->animPhase=0;((NameinGraphicGrid *)p)->animActive=1;
 flag=0;
 if(mode==NAMEIN_GRAPHIC_MODE_SYMBOL || ((NameinGraphicGrid *)p)->mode==NAMEIN_GRAPHIC_MODE_SYMBOL)flag=1;
 ((NameinGraphicGrid *)p)->extraLayer=flag;
 if(flag)G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,14,47,16,16);
 else G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,10,47,16,16);
 return 1;
 }return 0;
}

/*
 * note: 2026-10-05 wD4 lane09: EXACT. The calls in case 0 are written out in each arm of the f118 test (tail merge builds the shared movs r1,#0 join), so the join block holds only the state stores and the zero is not hoisted.
 */
int NAMEIN_GRAPHIC_AnimateGrid(char *p) {
    int c;
    int y;
    if (((struct NameinGraphicGrid *)p)->animActive != 0)
    switch (((struct NameinGraphicGrid *)p)->animPhase) {
    case 0:
        BG_SYS_GetScrollY(1);
        c = ((struct NameinGraphicGrid *)p)->animTick;
        *(u16 *)0x04000052 = (s16)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16)((c * -48) / 7);
        BG_SYS_ChangeScrollImmediate(1, 3, y);
        BG_SYS_ChangeScrollImmediate(3, 3, y);
        if (((struct NameinGraphicGrid *)p)->extraLayer) BG_SYS_ChangeScrollImmediate(2, 3, y);
        if ((((struct NameinGraphicGrid *)p)->animTick)++ > 7) {
            if (((struct NameinGraphicGrid *)p)->extraLayer) {
                BG_SYS_SetPlaneVisible(1, 0);
                BG_SYS_SetPlaneVisible(2, 0);
                BG_SYS_SetPlaneVisible(3, 0);
            } else {
                BG_SYS_SetPlaneVisible(1, 0);
                BG_SYS_SetPlaneVisible(3, 0);
            }
            ((struct NameinGraphicGrid *)p)->animTick = 0;
            ((struct NameinGraphicGrid *)p)->animPhase = 1;
        }
        break;
    case 1:
        y = -48;
        BG_SYS_ChangeScrollImmediate(1, 3, y);
        BG_SYS_ChangeScrollImmediate(3, 3, y);
        if (((struct NameinGraphicGrid *)p)->extraLayer) BG_SYS_ChangeScrollImmediate(2, 3, y);
        NAMEIN_GRAPHIC_SwitchGridMode(p, ((struct NameinGraphicGrid *)p)->targetMode);
        ((struct NameinGraphicGrid *)p)->animPhase = 2;
        break;
    case 2:
        ((struct NameinGraphicGrid *)p)->animTick = 7;
        ((struct NameinGraphicGrid *)p)->animPhase = 3;
        BG_SYS_SetPlaneVisible(1, 1);
        BG_SYS_SetPlaneVisible(3, 1);
        if (((struct NameinGraphicGrid *)p)->mode != NAMEIN_GRAPHIC_MODE_SYMBOL) BG_SYS_SetPlaneVisible(2, 1);
        *(u16 *)0x04000052 = 1 << 12;
        break;
    case 3:
        c = ((struct NameinGraphicGrid *)p)->animTick;
        *(u16 *)0x04000052 = (s16)(-(c * 16) / 7 + 16) | (1 << 12);
        y = (s16)((c * -48) / 7);
        BG_SYS_ChangeScrollImmediate(1, 3, y);
        BG_SYS_ChangeScrollImmediate(3, 3, y);
        if (((struct NameinGraphicGrid *)p)->extraLayer) BG_SYS_ChangeScrollImmediate(2, 3, y);
        if ((((struct NameinGraphicGrid *)p)->animTick)-- == 0) ((struct NameinGraphicGrid *)p)->animPhase = 4;
        break;
    case 4:
        BG_SYS_ChangeScrollImmediate(1, 3, 0);
        BG_SYS_ChangeScrollImmediate(3, 3, 0);
        BG_SYS_ChangeScrollImmediate(2, 3, 0);
        ((struct NameinGraphicGrid *)p)->extraLayer = 0;
        *(u16 *)0x04000050 = 0;
        ((struct NameinGraphicGrid *)p)->animActive = 0;
        return 1;
    }
    return 0;
}

void NAMEIN_GRAPHIC_SwitchGridMode(char *p, u32 mode) {
 int index;
 if(((NameinGraphicGrid *)p)->mode==mode)return;
 NAMEIN_GRAPHIC_ClearPicker(p);
#if LANGUAGE == LANGUAGE_JAPANESE
 NAMEIN_GRAPHIC_InitPicker(p,mode,((NameinGraphicGrid *)p)->data,((NameinGraphicGrid *)p)->heap);
#else
 index=NAMEIN_GRAPHIC_GridIndex(mode,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->variant);
 NAMEIN_GRAPHIC_InitPicker(p,mode,index,((NameinGraphicGrid *)p)->data,((NameinGraphicGrid *)p)->heap);
#endif
 BMP_Clear((struct Bmp *)BMP_WIN_GetBmp((struct BmpWin *)((NameinGraphicGrid *)p)->bmpWin),0);
 NAMEIN_GRAPHIC_DrawCellTips(p,((void *)&((struct NameinGraphicGrid *)p)->tipBmp),(void *)(((NameinGraphicGrid *)p)->printSys),(void *)(((NameinGraphicGrid *)p)->font),((NameinGraphicGrid *)p)->heap);
 if(mode==NAMEIN_GRAPHIC_MODE_SYMBOL) {BG_SYS_DecodeTile(1,*(char * *)&((NameinGraphicGrid *)p)->paletteDataA+12,2048);BG_SYS_SetPlaneVisible(2,0);}
 else BG_SYS_DecodeTile(1,*(char * *)&((NameinGraphicGrid *)p)->paletteDataB+12,2048);
 BG_SYS_PushTile(1);
 if(mode==NAMEIN_GRAPHIC_MODE_SYMBOL || ((NameinGraphicGrid *)p)->mode==NAMEIN_GRAPHIC_MODE_SYMBOL)NAMEIN_GRAPHIC_ConvertCellMode((NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)),((NameinGraphicGrid *)p)->mode,mode);
 ((NameinGraphicGrid *)p)->mode=mode;
}

#if LANGUAGE != LANGUAGE_JAPANESE
/*
 * volatile: 021F3676 and 021F3696 re-read the mode word at +0x100.
 */
void NAMEIN_GRAPHIC_SetGridSelection(char *p,int index,int variant) {
 int selected;
 if(*(volatile int *)&((NameinGraphicGrid *)p)->mode!=NAMEIN_GRAPHIC_MODE_SYMBOL)return;
 if(((NameinGraphicGrid *)p)->variant==variant && ((NameinGraphicGrid *)p)->index==index)return;
 selected=NAMEIN_GRAPHIC_GridIndex(((u32)((NameinGraphicGrid *)p)->mode),(int)index,(unsigned char)variant);
 NAMEIN_GRAPHIC_LoadGrid((void **)p,selected,((NameinGraphicGrid *)p)->data);
 BMP_Clear((struct Bmp *)BMP_WIN_GetBmp((struct BmpWin *)((NameinGraphicGrid *)p)->bmpWin),0);
 NAMEIN_GRAPHIC_DrawCellTips(p,((void *)&((struct NameinGraphicGrid *)p)->tipBmp),(void *)(((NameinGraphicGrid *)p)->printSys),(void *)(((NameinGraphicGrid *)p)->font),((NameinGraphicGrid *)p)->heap);
 ((NameinGraphicGrid *)p)->index=index;((NameinGraphicGrid *)p)->variant=variant;
}
#endif

int NAMEIN_GRAPHIC_KanaKeyMove(char *p,int *out)
{
    NameinGraphicRect rect;
    NameinGraphicPair delta;
    int changed=0;
    if(KEY_GetRepeat()&64){delta.x=0;delta.y=-1;changed=1;}
    else if(KEY_GetRepeat()&128){delta.x=0;delta.y=1;changed=1;}
    else if(KEY_GetRepeat()&32){delta.x=-1;delta.y=0;changed=1;}
    else if(KEY_GetRepeat()&16){delta.x=1;delta.y=0;changed=1;}
    else if(KEY_GetTrg()&8){
        delta.x=0;delta.y=0;changed=1;
        NAMEIN_GRAPHIC_FindCellByValue(p,NAMEIN_KIND_OK,(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)));
        NAMEIN_GRAPHIC_PickerMove(p,(((void *)&((struct NameinGraphicGrid *)p)->selectionX)),(int *)&delta);
    }
    if(changed){
        if(UI_GetInputMode()==1){
            if(NAMEIN_GRAPHIC_PickerGetBox(p, (NameinGraphicPair *)((((void *)&((struct NameinGraphicGrid *)p)->selectionX))), (NameinGraphicBox *)&rect)){
                UI_SetInputMode(0);
                NAMEIN_GRAPHIC_SetupCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor),1, (const struct NameinGraphicMainRect *)&rect,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
                GFL_USE_PlaySeDefaultVolume(1352);
            }
        }else{
            NAMEIN_GRAPHIC_PickerMove(p,((void *)&((struct NameinGraphicGrid *)p)->selectionX),(int *)&delta);
            if(NAMEIN_GRAPHIC_PickerGetBox(p, (NameinGraphicPair *)((((void *)&((struct NameinGraphicGrid *)p)->selectionX))), (NameinGraphicBox *)&rect)){
                GFL_USE_PlaySeDefaultVolume(1352);
                NAMEIN_GRAPHIC_SetupCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor),1, (const struct NameinGraphicMainRect *)&rect,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
            }
        }
    }
    return 0;
}

int NAMEIN_GRAPHIC_KanaKeyAction(char *p,int *out)
{
    NameinGraphicRect rect;
    int changed;
    changed=0;
    if(KEY_GetTrg()==1) {
        *(NameinGraphicPair *)(out+2)=*(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX));
        out[1]=1;changed=1;
    }
    if(KEY_GetTrg()==2) {
        NAMEIN_GRAPHIC_FindCellByValue(p,NAMEIN_KIND_BACK,(NameinGraphicPair *)(out+2));out[0]=NAMEIN_KIND_BACK;changed=1;
    }
    if(KEY_GetTrg()==4) {
        out[0]=((NameinGraphicGrid *)p)->mode+3;
        if(out[0]>NAMEIN_KIND_LAST_PAGE)out[0]=2;
        NAMEIN_GRAPHIC_FindCellByValue(p,out[0],(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)));
        *(NameinGraphicPair *)(out+2)=*(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX));changed=1;
    }
    if(KEY_GetTrg()==256){((NameinGraphicGrid *)p)->action=10;changed=0;}
    if(changed && UI_GetInputMode()==1) {
        if(NAMEIN_GRAPHIC_PickerGetBox(p, (NameinGraphicPair *)((((void *)&((struct NameinGraphicGrid *)p)->selectionX))), (NameinGraphicBox *)&rect)) {
            GFL_USE_PlaySeDefaultVolume(1352);UI_SetInputMode(0);
            NAMEIN_GRAPHIC_SetupCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor),1, (const struct NameinGraphicMainRect *)&rect,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
            return 0;
        }
    }
    return changed;
}

int NAMEIN_GRAPHIC_KanaTouch(char *p,int *out) {
 int point[2];unsigned x,y;int u;
 if(TOUCHPANEL_GetPointTrg(&x,&y)) {
 point[0]=x;point[1]=y;
 if(NAMEIN_GRAPHIC_FindCellAtPoint(p,point,(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)))) {
 u=((NameinGraphicGrid *)p)->selectionX;out[3]=((NameinGraphicGrid *)p)->selectionY;out[1]=1;out[2]=u;UI_SetInputMode(1);return 1;
 }}return 0;
}

void NAMEIN_GRAPHIC_ApplyKanaAction(char *p,int *input)
{
    unsigned code;
    NameinGraphicRect rect;
    if(input[1])code=NAMEIN_GRAPHIC_PickerToChar(p,(int *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)),(unsigned short *)(((void *)&((struct NameinGraphicGrid *)p)->actionValue)));
    else code=input[0];
    switch(code){
    case 0:break;
#if LANGUAGE == LANGUAGE_JAPANESE
    case 1:((NameinGraphicGrid *)p)->action=(((NameinGraphicGrid *)p)->mode==NAMEIN_GRAPHIC_MODE_SYMBOL)?2:1;((NameinGraphicGrid *)p)->state=1;break;
#else
    case 1:((NameinGraphicGrid *)p)->action=1;((NameinGraphicGrid *)p)->state=1;break;
#endif
    case NAMEIN_KIND_SPACE:((NameinGraphicGrid *)p)->action=9;((NameinGraphicGrid *)p)->state=1;break;
    case 2:case 3:case 4:case 5:
#if LANGUAGE == LANGUAGE_JAPANESE
    case 6:
#endif
        if(NAMEIN_GRAPHIC_SetGridMode(p,code-2)){
            GFL_USE_PlaySeDefaultVolume(1611);((NameinGraphicGrid *)p)->state=2;((NameinGraphicGrid *)p)->action=6;
        }break;
    case NAMEIN_KIND_BACK:((NameinGraphicGrid *)p)->action=5;break;
    case NAMEIN_KIND_OK:((NameinGraphicGrid *)p)->action=7;break;
    case NAMEIN_KIND_TOGGLE:
        GFL_USE_PlaySeDefaultVolume(1356);((NameinGraphicGrid *)p)->action=8;
#if LANGUAGE == LANGUAGE_JAPANESE
        ((NameinGraphicGrid *)p)->index^=1;
#else
        NAMEIN_GRAPHIC_SetGridSelection(p,((NameinGraphicGrid *)p)->index^1,((NameinGraphicGrid *)p)->variant);
#endif
        break;
    case NAMEIN_KIND_CHAR_A:((NameinGraphicGrid *)p)->action=3;break;
    case NAMEIN_KIND_CHAR_B:((NameinGraphicGrid *)p)->action=4;break;
    }
    if(NAMEIN_GRAPHIC_PickerGetBox(p, (NameinGraphicPair *)((input+2)), (NameinGraphicBox *)&rect))
        NAMEIN_GRAPHIC_SetupCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor),2, (const struct NameinGraphicMainRect *)&rect,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
}

/*
 * lever: Integer address arithmetic for26E0 avoids caching p+D8 across2818.
 */
int NAMEIN_GRAPHIC_SymbolKeyMove(char *p,int *out)
{
    NameinGraphicRect rect;
    NameinGraphicPair delta;
    NameinGraphicPair point;
    int changed=0;
    if(((NameinGraphicGrid *)p)->extraLayer==0){
        if(KEY_GetTrg()&64){delta.x=0;delta.y=-1;changed=1;}
        else if(KEY_GetTrg()&128){delta.x=0;delta.y=1;changed=1;}
        else if(KEY_GetTrg()&32){delta.x=-1;delta.y=0;changed=1;}
        else if(KEY_GetTrg()&16){delta.x=1;delta.y=0;changed=1;}
    }
    if(changed){
        point=*(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX));
        NAMEIN_GRAPHIC_PickerMove(p,(int *)&point,(int *)&delta);
        if(NAMEIN_GRAPHIC_PickerToChar(p,&point.x,0)-2<=NAMEIN_KIND_LAST_PAGE-2){
            if(UI_GetInputMode()==1){
                if(NAMEIN_GRAPHIC_PickerGetBox(p, (NameinGraphicPair *)((((void *)&((struct NameinGraphicGrid *)p)->selectionX))), (NameinGraphicBox *)&rect)){
                    GFL_USE_PlaySeDefaultVolume(1352);UI_SetInputMode(0);
                    NAMEIN_GRAPHIC_SetupCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor),1, (const struct NameinGraphicMainRect *)&rect,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
                }
            }else{
                NAMEIN_GRAPHIC_PickerMove(p,((void *)&((struct NameinGraphicGrid *)p)->selectionX),(int *)&delta);
                if(NAMEIN_GRAPHIC_PickerGetBox(p, (NameinGraphicPair *)((((void *)&((struct NameinGraphicGrid *)p)->selectionX))), (NameinGraphicBox *)&rect)){
                    GFL_USE_PlaySeDefaultVolume(1352);
                    NAMEIN_GRAPHIC_SetupCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor),1, (const struct NameinGraphicMainRect *)&rect,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
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
            *(NameinGraphicPair *)(out+2)=*(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX));
            changed=1; out[1]=1;
        }
        if (KEY_GetTrg()&4) {
            out[0]=((NameinGraphicGrid *)p)->mode+3;
            if (out[0]>NAMEIN_KIND_LAST_PAGE) out[0]=2;
            NAMEIN_GRAPHIC_FindCellByValue(p,out[0],(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)));
            *(NameinGraphicPair *)(out+2)=*(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX));
            changed=1;
        }
        if (changed && UI_GetInputMode()==1) {
            if (NAMEIN_GRAPHIC_PickerGetBox(p,(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)),(NameinGraphicBox *)rect)) {
                GFL_USE_PlaySeDefaultVolume(1352); UI_SetInputMode(0);
                NAMEIN_GRAPHIC_SetupCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor),1,(struct NameinGraphicMainRect *)rect,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
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
            if (NAMEIN_GRAPHIC_FindCellAtPoint(p,point,(NameinGraphicPair *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)))) {
                if (NAMEIN_GRAPHIC_PickerToChar(p,(int *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)),0)-2<=NAMEIN_KIND_LAST_PAGE-2) {
                    u=((NameinGraphicGrid *)p)->selectionX;
                    out[3]=((NameinGraphicGrid *)p)->selectionY;
                    out[1]=1; out[2]=u;
                    UI_SetInputMode(1);
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
    if (input[1]) code=NAMEIN_GRAPHIC_PickerToChar(p,(int *)(((void *)&((struct NameinGraphicGrid *)p)->selectionX)),(unsigned short *)(((void *)&((struct NameinGraphicGrid *)p)->actionValue)));
    else code=input[0];
    switch (code) {
    case 0: case 1: break;
    case 2: case 3: case 4: case 5:
#if LANGUAGE == LANGUAGE_JAPANESE
    case 6:
#endif
        if (NAMEIN_GRAPHIC_SetGridMode(p,code-2)) {
            GFL_USE_PlaySeDefaultVolume(1611);
            ((NameinGraphicGrid *)p)->state=2; ((NameinGraphicGrid *)p)->action=6;
        }
        break;
    }
    if (NAMEIN_GRAPHIC_PickerGetBox(p,(NameinGraphicPair *)(input+2),(NameinGraphicBox *)rect))
        NAMEIN_GRAPHIC_SetupCursor(((void *)&((struct NameinGraphicGrid *)p)->cursor),2,(struct NameinGraphicMainRect *)rect,((NameinGraphicGrid *)p)->index,((NameinGraphicGrid *)p)->mode);
}

void NAMEIN_GRAPHIC_InitMsgBox(unsigned char *p,struct GfFont *a,struct MsgBank *b,struct PrintQueue *c,struct WordSet *d,unsigned short e) {
    void *window;
    MI_CpuFill8(p,0,sizeof(NameinGraphicMsgBox));
    ((NameinGraphicMsgBox *)p)->color=15;
    ((NameinGraphicMsgBox *)p)->font=a; ((NameinGraphicMsgBox *)p)->wordSet=d; ((NameinGraphicMsgBox *)p)->bank=b; ((NameinGraphicMsgBox *)p)->printSys=c;
    ((NameinGraphicMsgBox *)p)->strbuf=STRBUF_Create(255,e);
    ((NameinGraphicMsgBox *)p)->win=(void *)BMP_WIN_Create(4,1,19,30,4,15,1);
    BMP_MENUWORK_DrawWindow((void *)(((NameinGraphicMsgBox *)p)->win),2,1,14);
    ((NameinGraphicMsgBox *)p)->bmp=((NameinGraphicMsgBox *)p)->win;
    ((NameinGraphicMsgBox *)p)->dirty=0;
    BMP_Clear((struct Bmp *)BMP_WIN_GetBmp((struct BmpWin *)((NameinGraphicMsgBox *)p)->win),((NameinGraphicMsgBox *)p)->color);
    window=((NameinGraphicMsgBox *)p)->win;
    BMP_WIN_TransferChars((struct BmpWin *)window); BMP_WIN_MakeScreen((struct BmpWin *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)window));
}

/*
 * Addresses are Black-image addresses.
 */
void NAMEIN_GRAPHIC_DeleteMsgBox(u8 *p)
{
    BMP_WIN_Delete((struct BmpWin *)(((NameinGraphicMsgBox *)p)->win));
    STRBUF_Delete((struct Strbuf *)(((NameinGraphicMsgBox *)p)->strbuf));
    MI_CpuFill8(p, 0, sizeof(NameinGraphicMsgBox));
}

void NAMEIN_GRAPHIC_PrintMsg(char *p,int value) {
    void *window;
#if LANGUAGE != LANGUAGE_JAPANESE
    while (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)(((NameinGraphicMsgBox *)p)->printSys),(void *)(BMP_WIN_GetBmp((struct BmpWin *)((NameinGraphicMsgBox *)p)->win))))
        PRINTSYS_QUE_Main((struct PrintQueue *)(((NameinGraphicMsgBox *)p)->printSys));
#endif
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((NameinGraphicMsgBox *)p)->win)),((NameinGraphicMsgBox *)p)->color);
    MSGDATA_ReadString((struct MsgBank *)(((NameinGraphicMsgBox *)p)->bank),value,(void *)(((NameinGraphicMsgBox *)p)->strbuf));
    window=((NameinGraphicMsgBox *)p)->printSys;
    PRINTSYS_PrintQue((struct PrintQueue *)window,BMP_WIN_GetBmp((struct BmpWin *)((NameinGraphicMsgBox *)p)->bmp),0,0,*(void **)&((NameinGraphicMsgBox *)p)->strbuf,(struct GfFont *)(((NameinGraphicMsgBox *)p)->font));
    ((NameinGraphicMsgBox *)p)->dirty=1;
}

void NAMEIN_GRAPHIC_PrintPokeMsg(char *p,int value,u32 id,u32 form,u16 heap) {void *mon;mon=POKE_TOOL_Create(id,1,0,heap);POKE_TOOL_SetPartyValue(mon,111,form);NAMEIN_GRAPHIC_PrintMonMsg(p,value,mon);GFL_HEAP_Free(mon);}

void NAMEIN_GRAPHIC_PrintMonMsg(char *p,int value,void *mon) {
    struct Strbuf *text;
    void *window;
    WORDSET_SetSlotMonSpeciesName(((NameinGraphicMsgBox *)p)->wordSet,0,mon);
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp((struct BmpWin *)((NameinGraphicMsgBox *)p)->win)),((NameinGraphicMsgBox *)p)->color);
    text=MSGDATA_AllocString((struct MsgBank *)(((NameinGraphicMsgBox *)p)->bank),value);
    WORDSET_CopyTaggedText(*(struct WordSet **)&((NameinGraphicMsgBox *)p)->wordSet,((NameinGraphicMsgBox *)p)->strbuf,(void *)text);
    window=((NameinGraphicMsgBox *)p)->printSys;
    PRINTSYS_PrintQue((struct PrintQueue *)window,BMP_WIN_GetBmp((struct BmpWin *)((NameinGraphicMsgBox *)p)->bmp),0,0,*(void **)&((NameinGraphicMsgBox *)p)->strbuf,(struct GfFont *)(((NameinGraphicMsgBox *)p)->font));
    ((NameinGraphicMsgBox *)p)->dirty=1;
    STRBUF_Delete((struct Strbuf *)text);
}

int NAMEIN_GRAPHIC_IsMsgDrawDone(u8 *p) {struct PrintQueue *window;window=((NameinGraphicMsgBox *)p)->printSys;if(((struct NameinGraphicMsgBox *)p)->dirty) {if(PRINTSYS_QUE_IsExistTarget(window,(void *)(BMP_WIN_GetBmp(*(struct BmpWin **)&((NameinGraphicMsgBox *)p)->bmp)))==0) {BMP_WIN_TransferChars((struct BmpWin *)(((NameinGraphicMsgBox *)p)->bmp));((struct NameinGraphicMsgBox *)p)->dirty=0;}}if(!((struct NameinGraphicMsgBox *)p)->dirty) return 1;return 0;}

void NAMEIN_GRAPHIC_InitTcbl(char *p, int v)
{
    MI_CpuFill8(p, 0, sizeof(NameinGraphicTcbl));
    ((NameinGraphicTcbl *)p)->handle = TCBL_Create(v, v, 1, 0);
}

void NAMEIN_GRAPHIC_DeleteTcbl(unsigned char *p){if(((NameinGraphicTcbl *)p)->stream)PRINTSYS_PrintStreamDelete(((NameinGraphicTcbl *)p)->stream);TCBL_Destroy((struct TcblSystem *)(*(struct S02031140 * *)&((NameinGraphicTcbl *)p)->handle));MI_CpuFill8((unsigned char *)p, 0, sizeof(NameinGraphicTcbl));}

void NAMEIN_GRAPHIC_PrintNameStream(char *p,char *q,NameInArgs *w,u32 heap)
{
    void *set=WORDSET_CreateDefault(heap);
    if(NAMEIN_SETUP_IsCanceled(w)) WORDSET_SetSlotMonNickname(set,0,w->mon);
    else {
        struct Strbuf *text = STRBUF_Clone(w->name,heap);
        NAMEIN_SETUP_CopyName(w,(struct Strbuf *)text);
        WORDSET_SetSlotTag(set,0,(void *)text,0,0,0);
        STRBUF_Delete((struct Strbuf *)text);
    }
    WORDSET_SetSlotBoxName(set,1,w->boxManager,w->boxIndex);
    if(((NameinGraphicTcbl *)p)->stream) PRINTSYS_PrintStreamDelete((struct TextPrinter *)(((struct Rec3 *)(((NameinGraphicTcbl *)p)->stream))));
    BMP_Clear((struct Bmp *)(BMP_WIN_GetBmp(*(struct BmpWin **)&((NameinGraphicMsgBox *)q)->win)),((NameinGraphicMsgBox *)q)->color);
    STRBUF_Clear(((NameinGraphicMsgBox *)q)->strbuf);
    WORDSET_CopyTaggedText(set,((NameinGraphicMsgBox *)q)->strbuf,w->boxName);
    ((NameinGraphicTcbl *)p)->stream=(void *)PRINTSYS_PrintStream((struct BmpWin *)(((NameinGraphicMsgBox *)q)->win),0,0,*(struct Strbuf **)&((NameinGraphicMsgBox *)q)->strbuf,(struct GfFont *)(((NameinGraphicMsgBox *)q)->font),MSG_SPEED_GetWait(),(struct Tcbl *)(((NameinGraphicTcbl *)p)->handle),2,heap,((NameinGraphicMsgBox *)q)->color);
    ((NameinGraphicTcbl *)p)->flag=0;
    ((NameinGraphicTcbl *)p)->callback=NAMEIN_GRAPHIC_CallbackFadeOut;
    ((NameinGraphicTcbl *)p)->counter=60;
    WORDSET_Delete(set);
}

void NAMEIN_GRAPHIC_InitIconActor(NameinGraphicIcon *o, u32 mode, u32 iconIndex, u32 iconForm, struct Unit *s0, struct GfFont *s1, struct PrintQueue *s2, struct MsgBank *s3, struct BmpOamSys *s4, u16 heap)
{
    u32 flagA = 0;
    u32 archiveId;
    u32 paletteFileId;
    u32 characterFileId;
    u32 cellAnimArcId;
    u32 cellAnimEntryId;
    u8 paletteSlot;
    void *h;
    u32 w24 = 0x22;
    u32 h20 = 0x14;
    u32 v1c;
    u32 flagB = 0;

    MI_CpuFill8((unsigned char *)o, 0, sizeof(*o));
    paletteSlot = 0;
    switch (mode) {
    case 0:
    case 1:
        archiveId = APP_ICON_GetArchiveId();
        paletteFileId = APP_ICON_GetItemDataFileId();
        characterFileId = APP_ICON_GetItemExtraFileId();
        cellAnimArcId = APP_ICON_GetItemAnim2FileId(2);
        cellAnimEntryId = APP_ICON_GetItemFrame2FileId(2);
        v1c = iconIndex;
        break;
    case 2:
        archiveId = 0x20;
        paletteFileId = flagB;
        paletteSlot = PM_LANG_JA(d_021F5569, d_ja_021F53C4)[iconIndex];
        characterFileId = iconIndex + 0x31;
        cellAnimArcId = 0x41;
        cellAnimEntryId = 0x42;
        v1c = (iconIndex >= 8) ? 1 : flagB;
        break;
    case 3:
        flagA = 1;
        v1c = (iconForm & 0xFF00) >> 8;
        if (v1c == 2) {
            flagA = 0;
        }
        archiveId = 7;
        paletteFileId = POKE_TOOL_GetIconPaletteArcId();
        characterFileId = POKE_TOOL_CalcGraphicIndex(iconIndex, (u8)iconForm, v1c, 0);
        cellAnimArcId = POKE_TOOL_GetIconCellArcId();
        cellAnimEntryId = POKE_TOOL_GetIconCellEntryId();
        w24 = 0x1e;
        h20 = 0x14;
        flagB = 1;
        break;
    case 4:
    case 5:
        archiveId = 0x76;
        paletteFileId = 9;
        characterFileId = 8;
        cellAnimArcId = 7;
        cellAnimEntryId = 6;
        paletteSlot = 1;
        break;
    }
    h = ARC_TOOL_CreateHandle(archiveId, heap);
    if (flagB != 0) {
        o->palette = CLACT_RegisterPaletteCompressed(h, paletteFileId, 0, 0x40, heap);
    } else {
        o->palette = CLACT_RegisterPaletteEx(h, paletteFileId, 0, 0x40, paletteSlot, 1, heap);
    }
    o->cellAnim = CLACT_RegisterCellAnim(h, cellAnimArcId, cellAnimEntryId, heap);
    flagB = 0;
    o->character = CLACT_RegisterCharacter(h, characterFileId, 0, 0, heap);
    ARC_TOOL_DeleteHandle(h);
    {
        Dim8 dim;
        MI_CpuFill8((unsigned char *)&dim, 0, 8);
        dim.w = w24;
        dim.h = h20;
        o->actor = CLACT_CreateActor(s0, o->character, o->palette, o->cellAnim, (const struct ActorInitParam *)&dim, flagB, heap);
    }
    CLACT_SetActorAutoAnim(o->actor, 1);
    switch (mode) {
    case 0:
        if (iconIndex == 0) {
            NAMEIN_GRAPHIC_LoadIconMember(o->actor, 0x31, 6, 3, 4, 4, 0, 0, heap);
        } else {
            NAMEIN_GRAPHIC_LoadIconMember(o->actor, 0x31, 9, 3, 4, 4, 0, 0, heap);
        }
        break;
    case 1:
        NAMEIN_GRAPHIC_LoadIconMember(o->actor, 0x31, 6, 3, 4, 4, 0, 0, heap);
    case 2:
        CLACT_SetActorPaletteOffset(o->actor, 0, 1);
        break;
    case 3:
        CLACT_SetActorAnimSeq(o->actor, 1);
        CLACT_SetActorPaletteOffset(o->actor, POKE_TOOL_CalcIconPalette(iconIndex, (u8)iconForm, (iconForm & 0xFF00) >> 8, flagB), flagB);
        break;
    case 5:
        CLACT_SetActorAnimSeq(o->actor, 5);
        CLACT_SetActorPaletteOffset(o->actor, flagB, 1);
        break;
    case 4:
        CLACT_SetActorAnimSeq(o->actor, 2);
        CLACT_SetActorPaletteOffset(o->actor, flagB, 1);
        break;
    }
    if (flagA != 0) {
        void *h2;
        u32 r;
        u32 idx;
        struct BmpOamParam st;
        h2 = ARC_TOOL_CreateHandle(0x17, heap);
        o->bmp = BMP_Create(2, 2, 0x20, heap);
        o->palette2 = CLACT_RegisterPaletteCompressed(h2, 5, 0, 0xA0, heap);
        ARC_TOOL_DeleteHandle(h2);
        MI_CpuFill8(&st, 0, sizeof(st));
        st.bmp = o->bmp;
        st.x = 0x2e;
        st.y = 0x14;
        st.animResId = o->palette2;
        st.drawPriority = 0;
        st.space = 0;
        st.engine = 0;
        st.bgPriority = 0;
        st.palette = 0;
        o->oam = BMP_OAM_Create(s4, &st);
        if (v1c == 1) {
            idx = 0x11;
            r = 0xC80;
        } else {
            idx = 0x10;
            r = 0x14C0;
        }
        o->text = MSGDATA_AllocString(s3, idx);
        BMP_Clear(o->bmp, 0);
        PRINTSYS_PrintQueColor(s2, o->bmp, 0, 0, o->text, s1, r);
        o->printSys = s2;
        o->oamDirty = 1;
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
    MI_CpuFill8(p,0,sizeof(NameinGraphicIcon));
}

void NAMEIN_GRAPHIC_UpdateIconTouch(char *p) {
    int rect[4];
    unsigned x,y;
    NameinGraphicVec2 pos;
    int point[2];
    switch (((NameinGraphicIcon *)p)->touchMode) {
    case 0:
        CLACT_GetActorSurfacePos((struct ClactActor *)((NameinGraphicIcon *)p)->actor,(struct ClactVec2 *)&pos,0);
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

void NAMEIN_GRAPHIC_FlushIconOam(unsigned char *p){if(((NameinGraphicIcon *)p)->oamDirty){if(PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)(((NameinGraphicIcon *)p)->printSys), (void *)(((NameinGraphicIcon *)p)->bmp))==0){BMP_OAM_UploadChars((struct BmpOam *)(*(struct ClactActor * *)&((NameinGraphicIcon *)p)->oam));((NameinGraphicIcon *)p)->oamDirty=0;}}}

unsigned NAMEIN_GRAPHIC_IsIconAnimDone(unsigned char *p){return ((NameinGraphicIcon *)p)->state;}

void NAMEIN_GRAPHIC_StartIconAnim(unsigned char *p){((NameinGraphicIcon *)p)->animTick=0;*(unsigned *)&((NameinGraphicIcon *)p)->animActive=1;}

int NAMEIN_GRAPHIC_StepIconAnim(char *p) {
    NameinGraphicVec2 pos;
    int tick;
    if (((NameinGraphicIcon *)p)->animActive) {
        tick=((NameinGraphicIcon *)p)->animTick;
        ((NameinGraphicIcon *)p)->animTick=tick+1;
#if LANGUAGE == LANGUAGE_JAPANESE
        pos.x=0x22;
#else
        CLACT_GetActorSurfacePos((struct ClactActor *)((NameinGraphicIcon *)p)->actor,(struct ClactVec2 *)&pos,0);
#endif
        pos.y=20-((12*FX_SinCosTable_[((unsigned short)(32767*tick/8)>>4)*2])>>12);
        CLACT_AddActorSurfacePos((struct ClactActor *)(((NameinGraphicIcon *)p)->actor), (const struct ClactVec2 *)&pos,0);
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

struct Strbuf *NAMEIN_GRAPHIC_GetNameForAction(u8 *p, int a, int b)
{
    switch (a) {
    case 0:
        return 0;
    case 1:
        if (STRBUF_GetLength((struct Strbuf *)(((NameinGraphicWork *)p)->nameStrbuf)) == 0)
            return MSGDATA_AllocString((struct MsgBank *)gSpeciesNameBank,
                                 ((NameInArgs *)((NameinGraphicWork *)p)->args)->species);
        return STRBUF_Clone((struct Strbuf *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    case 2:
        return STRBUF_Clone((struct Strbuf *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    case 3:
        return 0;
    case 4:
        return STRBUF_Clone((struct Strbuf *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    case 5:
        return STRBUF_Clone((struct Strbuf *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    case 6:
        return STRBUF_Clone((struct Strbuf *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    case 7:
        return STRBUF_Clone((struct Strbuf *)(((NameinGraphicWork *)p)->nameStrbuf), b);
    default:
        return 0;
    }
}

void NAMEIN_GRAPHIC_CommitName(char *p) {
    struct Strbuf *text;
    char *obj;
    ((NameInArgs *)(*(char * *)&((NameinGraphicWork *)p)->args))->canceled=0;
    text=STRBUF_Clone((struct Strbuf *)(((NameInArgs *)(*(char * *)&((NameinGraphicWork *)p)->args))->name),30);
    NAMEIN_GRAPHIC_CopyToStrbuf(((void *)&((struct NameinGraphicWork *)p)->inputField),(struct Strbuf *)((NameInArgs *)(*(char * *)&((NameinGraphicWork *)p)->args))->name);
    if (STRBUF_IsEqual((struct Strbuf *)text,(struct Strbuf *)(((NameInArgs *)(*(char * *)&((NameinGraphicWork *)p)->args))->name)))
        ((NameInArgs *)(*(char * *)&((NameinGraphicWork *)p)->args))->canceled=1;
    if (!NAMEIN_GRAPHIC_HasNonSpace((u8 *)((((void *)&((struct NameinGraphicWork *)p)->inputField))))) {
        STRBUF_Copy((struct Strbuf *)(((NameInArgs *)(*(char * *)&((NameinGraphicWork *)p)->args))->name),(struct Strbuf *)text);
        ((NameInArgs *)(*(char * *)&((NameinGraphicWork *)p)->args))->canceled=1;
    }
    STRBUF_Delete((struct Strbuf *)text);
    if (!STRBUF_GetLength((struct Strbuf *)(((NameInArgs *)(*(char * *)&((NameinGraphicWork *)p)->args))->name))) {
        obj=*(char * *)&((NameinGraphicWork *)p)->args;
        if (((NameInArgs *)obj)->kind!=0 && ((NameInArgs *)obj)->kind!=3) ((NameInArgs *)obj)->canceled=1;
    }
}

int NAMEIN_GRAPHIC_IsNameValid(char *p)
{
    int *q = *(int * *)&((NameinGraphicWork *)p)->args;

    if (*q == 0 || *q == 3) {
        if (NAMEIN_GRAPHIC_GetLength((const u8 *)(((void *)&((struct NameinGraphicWork *)p)->inputField))) == 0 && NAMEIN_GRAPHIC_GetSecondaryLength((const u8 *)(((void *)&((struct NameinGraphicWork *)p)->inputField))) == 0) {
            return 0;
        }
        if (NAMEIN_GRAPHIC_HasNonSpace((u8 *)(((void *)&((struct NameinGraphicWork *)p)->inputField))) == 0) {
            return 0;
        }
    }
    return 1;
}

void NAMEIN_GRAPHIC_InitCallback(NameinGraphicCallback *a, void *b, NameinGraphicStep c)
{
    MI_CpuFill8(a, 0, sizeof(NameinGraphicCallback));
    a->owner = b;
    NAMEIN_GRAPHIC_SetCallback(a, c);
}

void NAMEIN_GRAPHIC_ClearCallback(NameinGraphicCallback *p){MI_CpuFill8(p,0,sizeof(NameinGraphicCallback));}

void NAMEIN_GRAPHIC_RunCallback(NameinGraphicCallback *p)
{
    if (p->state == 0) {
        p->fn(p, &p->arg, p->owner);
    }
}

unsigned NAMEIN_GRAPHIC_GetCallbackState(NameinGraphicCallback *p){return p->state;}

void NAMEIN_GRAPHIC_SetCallback(NameinGraphicCallback *p,NameinGraphicStep value){p->fn=value;p->arg=0;}

void NAMEIN_GRAPHIC_FinishCallback(NameinGraphicCallback *p){p->state=1;}

void NAMEIN_GRAPHIC_CallbackWaitDraw(NameinGraphicCallback *p,int *unused,unsigned char *q){int v;v=NAMEIN_GRAPHIC_IsGridDrawDone((char *)&((NameinGraphicWork *)q)->grid);v|=NAMEIN_GRAPHIC_IsFieldDrawDone((u8 *)&((NameinGraphicWork *)q)->inputField);if(NAMEIN_GRAPHIC_IsMsgDrawDone((u8 *)&((NameinGraphicWork *)q)->msgBox)|v)NAMEIN_GRAPHIC_SetCallback(p,NAMEIN_GRAPHIC_CallbackFadeIn);}

void NAMEIN_GRAPHIC_CallbackFadeIn(NameinGraphicCallback *p,int *state) {
    switch (*state) {
    case 0: FADE_Start(3,16,0,0); *state=1; break;
    case 1: if (!FADE_IsActive()) *state=2; break;
    case 2: NAMEIN_GRAPHIC_SetCallback(p,NAMEIN_GRAPHIC_CallbackGridAction); break;
    }
}

void NAMEIN_GRAPHIC_CallbackFadeOut(NameinGraphicCallback *p,int *state) {
    switch (*state) {
    case 0: FADE_Start(3,0,16,0); *state=1; break;
    case 1: if (!FADE_IsActive()) *state=2; break;
    case 2: NAMEIN_GRAPHIC_SetCallback(p,NAMEIN_GRAPHIC_CallbackFinish); break;
    }
}

/*
 * Padding: two zero bytes at 0x021F47B2, then a function prologue.
 */
void NAMEIN_GRAPHIC_CallbackWaitPrint(NameinGraphicCallback *a, int *state, char *p)
{
    char *q = ((void *)&((struct NameinGraphicWork *)p)->tcbl);
    switch (*state) {
    case 0:
        TCBL_Main((struct TcblSystem *)(*(struct Tcbl * *)&((NameinGraphicTcbl *)q)->handle));
        switch (PRINTSYS_PrintStreamGetState(((NameinGraphicTcbl *)q)->stream)) {
        case 0:
            if (((unsigned)KEY_GetCont() & 3) != 0 || TOUCHPANEL_GetCont() != 0) {
                PRINTSYS_PrintStreamShortWait((struct TextPrinter *)(*(struct Rec * *)&((NameinGraphicTcbl *)q)->stream), 0);
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

void NAMEIN_GRAPHIC_CallbackGridAction(NameinGraphicCallback *owner,void *unused,char *p)
{
    u16 selected;
    u32 action=NAMEIN_GRAPHIC_GetGridAction(((void *)&((struct NameinGraphicWork *)p)->grid),&selected);
    u32 value=NAMEIN_GRAPHIC_GetGridIndex((const u8 *)(((void *)&((struct NameinGraphicWork *)p)->grid)));
    if(((NameinGraphicWork *)p)->pendingMsg==1) {
        if(action!=0 || NAMEIN_GRAPHIC_IsIconAnimDone((unsigned char *)(((void *)&((struct NameinGraphicWork *)p)->icon)))!=0 || (KEY_GetTrg()&~1u)!=0) {
            NameInArgs *q=((NameinGraphicWork *)p)->args;
            if(q->kind==1) {
                if(q->mon==0) NAMEIN_GRAPHIC_PrintPokeMsg(((void *)&((struct NameinGraphicWork *)p)->msgBox),q->kind,q->species,q->traits,30);
                else NAMEIN_GRAPHIC_PrintMonMsg(((void *)&((struct NameinGraphicWork *)p)->msgBox),q->kind,q->mon);
            } else NAMEIN_GRAPHIC_PrintMsg(((void *)&((struct NameinGraphicWork *)p)->msgBox),q->kind);
            ((NameinGraphicWork *)p)->pendingMsg=0;
        }
    }
    switch(action) {
    case 1: if(NAMEIN_GRAPHIC_AppendChar(((void *)&((struct NameinGraphicWork *)p)->inputField),selected)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 2: if(NAMEIN_GRAPHIC_AppendCandidate((unsigned char *)(((void *)&((struct NameinGraphicWork *)p)->inputField)),selected,value)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 3: if(invert(((void *)&((struct NameinGraphicWork *)p)->inputField),0)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 4: if(invert(((void *)&((struct NameinGraphicWork *)p)->inputField),1)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 10: if(NAMEIN_GRAPHIC_RevertChar(((void *)&((struct NameinGraphicWork *)p)->inputField))) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 5: if(NAMEIN_GRAPHIC_Backspace((unsigned char *)(((void *)&((struct NameinGraphicWork *)p)->inputField)))) GFL_USE_PlaySeDefaultVolume(0x553); else GFL_USE_PlaySeDefaultVolume(0x557); break;
    case 6: NAMEIN_GRAPHIC_ClearSecondary(((void *)&((struct NameinGraphicWork *)p)->inputField)); break;
    case 11: NAMEIN_GRAPHIC_CommitSecondary(((void *)&((struct NameinGraphicWork *)p)->inputField)); break;
    case 7: if(NAMEIN_GRAPHIC_GetSecondaryLength((const u8 *)((((void *)&((struct NameinGraphicWork *)p)->inputField))))==0) {
        if(NAMEIN_GRAPHIC_IsNameValid(p)==0) {GFL_USE_PlaySeDefaultVolume(0x557);NAMEIN_GRAPHIC_PrintMsg(((void *)&((struct NameinGraphicWork *)p)->msgBox),8);((NameinGraphicWork *)p)->pendingMsg=1;}
        else {
            if(PROF_WORD_FindMatch((const Resources *)((NameinGraphicWork *)p)->profWord,((void *)&((struct NameinGraphicWork *)p)->inputField),30)) GFL_USE_PlaySeDefaultVolume(0x557);
            else if(PROF_WORD_CheckDigitCount(((void *)&((struct NameinGraphicWork *)p)->inputField),((NameinGraphicWork *)p)->inputField.primaryLength,30)) {GFL_USE_PlaySeDefaultVolume(0x557);NAMEIN_GRAPHIC_PrintMsg(((void *)&((struct NameinGraphicWork *)p)->msgBox),9);((NameinGraphicWork *)p)->pendingMsg=1;}
            else {
                NameInArgs *q;
                GFL_USE_PlaySeDefaultVolume(0x54d);NAMEIN_GRAPHIC_CommitName(p);q=((NameinGraphicWork *)p)->args;
                if(q->kind==1 && q->boxName!=0) {NAMEIN_GRAPHIC_PrintNameStream(((void *)&((struct NameinGraphicWork *)p)->tcbl),((void *)&((struct NameinGraphicWork *)p)->msgBox),q,30);NAMEIN_GRAPHIC_SetCallback(owner,NAMEIN_GRAPHIC_CallbackWaitPrint);}
                else NAMEIN_GRAPHIC_SetCallback(owner,NAMEIN_GRAPHIC_CallbackFadeOut);
            }
        }
    } else {NAMEIN_GRAPHIC_CommitSecondary(((void *)&((struct NameinGraphicWork *)p)->inputField));GFL_USE_PlaySeDefaultVolume(0x54d);} break;
    case 0: if(NAMEIN_GRAPHIC_IsIconAnimDone((unsigned char *)(((void *)&((struct NameinGraphicWork *)p)->icon)))) {
        struct Strbuf *text = NAMEIN_GRAPHIC_GetNameForAction((u8 *)p,**(int * *)&((NameinGraphicWork *)p)->args,30);
        NAMEIN_GRAPHIC_ClearPrimary((unsigned char *)(((void *)&((struct NameinGraphicWork *)p)->inputField)));
        if(text) {NAMEIN_GRAPHIC_AppendString(((void *)&((struct NameinGraphicWork *)p)->inputField),STRBUF_GetChars((struct Strbuf *)text));STRBUF_Delete((struct Strbuf *)text);}
        GFL_USE_PlaySeDefaultVolume(0x54c);
    } break;
    case 9: NAMEIN_GRAPHIC_CommitSecondary(((void *)&((struct NameinGraphicWork *)p)->inputField));if(NAMEIN_GRAPHIC_AppendChar(((void *)&((struct NameinGraphicWork *)p)->inputField),selected)) GFL_USE_PlaySeDefaultVolume(0x54c); else GFL_USE_PlaySeDefaultVolume(0x557);break;
    default: break;
    }
    NAMEIN_GRAPHIC_UpdateGrid(((void *)&((struct NameinGraphicWork *)p)->grid),((void *)&((struct NameinGraphicWork *)p)->inputField));
    NAMEIN_GRAPHIC_RefreshInputField((u8 *)(((void *)&((struct NameinGraphicWork *)p)->inputField)));
    NAMEIN_GRAPHIC_UpdateIconTouch(((void *)&((struct NameinGraphicWork *)p)->icon));
    NAMEIN_GRAPHIC_IsMsgDrawDone((u8 *)(((void *)&((struct NameinGraphicWork *)p)->msgBox)));
}

void NAMEIN_GRAPHIC_CallbackFinish(NameinGraphicCallback *a, int unused, char *p)
{
    unsigned n;
    if (((NameinGraphicWork *)p)->args->pokedex != 0) {
        n = NAMEIN_GRAPHIC_GetGridMode((const unsigned char *)(((void *)&((struct NameinGraphicWork *)p)->grid)));
        MISC_SetInputFlag(((NameinGraphicWork *)p)->args->pokedex, ((NameinGraphicWork *)p)->args->kind, n);
    }
    if (((NameinGraphicWork *)p)->args->saveIntr != 0) NAMEIN_GRAPHIC_SetCallback(a, NAMEIN_GRAPHIC_CallbackPauseSave);
    else NAMEIN_GRAPHIC_FinishCallback(a);
}

void NAMEIN_GRAPHIC_CallbackPauseSave(NameinGraphicCallback *p,int *state,unsigned char *q){switch(*state){case 0:SAVE_CONTROL_INTR_Pause(((NameInArgs *)(*(unsigned char * *)&((NameinGraphicWork *)q)->args))->saveIntr);*state=1;break;case 1:if(SAVE_CONTROL_INTR_IsPausedOrFinished(((NameInArgs *)(*(unsigned char * *)&((NameinGraphicWork *)q)->args))->saveIntr)==1)NAMEIN_GRAPHIC_FinishCallback(p);break;}}

static inline void G2_BlendNone(void) { *(volatile unsigned short *)REG_BLDCNT_ADDR = 0; }

static inline void G2S_BlendNone(void) { *(volatile unsigned short *)REG_DB_BLDCNT_ADDR = 0; }

static inline void GX_SetVisibleWnd(int window) { *(volatile unsigned *)REG_DISPCNT_ADDR = (*(volatile unsigned *)REG_DISPCNT_ADDR & ~0xE000) | (window << 13); }

static inline void GXS_SetVisibleWnd(int window) { *(volatile unsigned *)REG_DB_DISPCNT_ADDR = (*(volatile unsigned *)REG_DB_DISPCNT_ADDR & ~0xE000) | (window << 13); }

/*
 * volatile: hardware 0x04000050, 0x04001050, 0x04000000, 0x04001000.
 */
unsigned char *NAMEIN_GRAPHIC_CreateDisplay(unsigned swap, unsigned short heap)
{
    unsigned char *p;
    p = GFL_HEAP_Alloc(heap, sizeof(NameinGraphicDisplay), 0, d_021F5784, 0x1BB);
    MI_CpuFill8(p, 0, sizeof(NameinGraphicDisplay));
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(&d_021F55D0);
    BG_SYS_SetLcdSwap(swap);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    NAMEIN_GRAPHIC_InitBg(p, heap);
    NAMEIN_GRAPHIC_InitClact((unsigned char *)&((NameinGraphicDisplay *)p)->clactUnit, (struct DispVramCfg *)&d_021F55D0, heap);
    ((NameinGraphicDisplay *)p)->mainTask = GFL_USE_AddMainTask(NAMEIN_GRAPHIC_DisplayMainTask, p, 0);
    return p;
}

void NAMEIN_GRAPHIC_DeleteDisplay(unsigned char *p)
{
    TCB_DeleteTask((struct TcbTask *)(*(struct Node * *)&((NameinGraphicDisplay *)p)->mainTask));
    NAMEIN_GRAPHIC_ExitClact((unsigned char *)&((NameinGraphicDisplay *)p)->clactUnit);
    NAMEIN_GRAPHIC_ExitBg(p);
    GF_FONT_SetDefaultTextColor();
    G2_BlendNone();
    G2S_BlendNone();
    GX_SetVisibleWnd(0);
    GXS_SetVisibleWnd(0);
    MI_CpuFill8(p, 0, sizeof(NameinGraphicDisplay));
    GFL_HEAP_Free(p);
}

void NAMEIN_GRAPHIC_DrawDisplay(u8 *p)
{
    NAMEIN_GRAPHIC_DrawClact((unsigned char *)&((NameinGraphicDisplay *)p)->clactUnit);
    NAMEIN_GRAPHIC_Empty(p);
}

struct Unit *NAMEIN_GRAPHIC_GetDisplayHandle(unsigned char *p){return NAMEIN_GRAPHIC_LoadWord((void *const *)&((NameinGraphicDisplay *)p)->clactUnit);}

void NAMEIN_GRAPHIC_DisplayMainTask(struct TcbTask *a, void *bArg)
{
    u8 * b = bArg;
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
    const NameinGraphicEntry *e;
    MI_CpuFill8(p, 0, 4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&d_021F55A4));
    for (; i < 8; i++) {
        id = d_021F5600[i].id;
        e = &d_021F5600[i];
        BG_SYS_InitBgLayer(id, (const struct BgTemplate *)&e->config, e->type);
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

void NAMEIN_GRAPHIC_Empty(u8 *unused) {}

void NAMEIN_GRAPHIC_ResetBg(u8 *unused) { BG_SYS_Update(); }

void NAMEIN_GRAPHIC_InitClact(unsigned char *p, struct DispVramCfg *a, int b)
{
    MI_CpuFill8(p, 0, 4);
    CLACT_InitSystem((struct ClactSysInit *)0x021F55B4, a, b);
    ((NameinGraphicClact *)p)->unit = CLACT_CreateUnit(0x80, 0, b);
    CLACT_SetUnitDefaultRenderer(((NameinGraphicClact *)p)->unit);
    BG_SYS_SetMainPlaneVisible(0x10, 1);
    BG_SYS_SetSubPlaneVisible(0x10, 1);
}

void NAMEIN_GRAPHIC_ExitClact(u8 *p)
{
    CLACT_DeleteUnit((struct Unit *)(((NameinGraphicClact *)p)->unit));
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, 4);
}

void NAMEIN_GRAPHIC_DrawClact(u8 *unused) { CLACT_DrawSystem(); }

void NAMEIN_GRAPHIC_VBlankClact(u8 *unused) { CLACT_VBlankSystem(); }

/*
 * extent: lead tail-call stub followed by unlabelled load-and-return at 021F4D1C.
 */
void *NAMEIN_GRAPHIC_LoadWord(void *const *p) { return *p; }
