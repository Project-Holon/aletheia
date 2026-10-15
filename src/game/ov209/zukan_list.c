/*
 * file:     zukan_list.c
 * unit:     yes
 * function: ZUKAN_LIST_ProcInit, ZUKAN_LIST_ProcMain, ZUKAN_LIST_ProcExit, ZUKAN_LIST_StartVBlankTask, ZUKAN_LIST_StopVBlankTask, ZUKAN_LIST_VBlankTask, ZUKAN_LIST_StartHBlankTask, ZUKAN_LIST_StopHBlankTask, ZUKAN_LIST_HBlankTask, ZUKAN_LIST_SetVramBanks, ZUKAN_LIST_GetVramBankConfig, ZUKAN_LIST_InitBgSystem, ZUKAN_LIST_ExitBgSystem, ZUKAN_LIST_LoadBgGraphics, ZUKAN_LIST_InitPaletteAnim, ZUKAN_LIST_ExitPaletteAnim, ZUKAN_LIST_RequestFade, ZUKAN_LIST_SetSubScreenBlendAlpha, ZUKAN_LIST_EnableSubWindows, ZUKAN_LIST_DisableSubWindows, ZUKAN_LIST_CreateFontAndPrinter, ZUKAN_LIST_DeleteFontAndPrinter, ZUKAN_LIST_LoadFormTable, ZUKAN_LIST_FreeFormTable, ZUKAN_LIST_MoveScrollBarActorsIn, ZUKAN_LIST_StartActorMoveFrames, ZUKAN_LIST_UpdateActorMove, ZUKAN_LIST_CreateFrameList, ZUKAN_LIST_DeleteFrameList, ZUKAN_LIST_FrameListMoveCallback, ZUKAN_LIST_FrameListSelectCallback, ZUKAN_LIST_ScrollByDelta, ZUKAN_LIST_RunState, ZUKAN_LIST_StateInit, ZUKAN_LIST_StateExit, ZUKAN_LIST_StateWaitFade, ZUKAN_LIST_StateFadeIn, ZUKAN_LIST_StateMain, ZUKAN_LIST_StateScroll, ZUKAN_LIST_StateScrollWait, ZUKAN_LIST_StateCursorFlash, ZUKAN_LIST_StateFadeOut, ZUKAN_LIST_ResetPaletteSlots, ZUKAN_LIST_StartButtonAnim, ZUKAN_LIST_IsSpeciesEntryValid, ZUKAN_LIST_StoreLastViewedSpecies, ZUKAN_LIST_StateSelectSpecies, ZUKAN_LIST_ToggleSaveFlag15, ZUKAN_LIST_CreateWindows, ZUKAN_LIST_DeleteWindows, ZUKAN_LIST_FlushWindows, ZUKAN_LIST_PrintTouchbarLabel, ZUKAN_LIST_PrintTouchbarLabelClone, ZUKAN_LIST_MakeWindowScreens, ZUKAN_LIST_ClearWindow, ZUKAN_LIST_DrawHeaderRegional, ZUKAN_LIST_DrawHeaderCounts, ZUKAN_LIST_DrawHeaderNational, ZUKAN_LIST_PrintListRow, ZUKAN_LIST_InitActors, ZUKAN_LIST_ExitActors, ZUKAN_LIST_UpdateActors, ZUKAN_LIST_SetActorAnim, ZUKAN_LIST_StartActorAnim, ZUKAN_LIST_GetActorAnimSeq, ZUKAN_LIST_IsActorAnimActive, ZUKAN_LIST_SetActorVisible, ZUKAN_LIST_GetActorVisible, ZUKAN_LIST_SetActorObjMode, ZUKAN_LIST_AddActorPos, ZUKAN_LIST_GetActorPos, ZUKAN_LIST_InitActorSystem, ZUKAN_LIST_LoadActorResources, ZUKAN_LIST_ReleaseActorResources, ZUKAN_LIST_CreateActors, ZUKAN_LIST_DeleteActor, ZUKAN_LIST_DeleteActorUnit, ZUKAN_LIST_LoadSpeciesIcon, ZUKAN_LIST_UpdateSpeciesActors, ZUKAN_LIST_TransferSpeciesGraphics, ZUKAN_LIST_IsActorHidden, ZUKAN_LIST_ShowSpeciesActor, ZUKAN_LIST_ScrollActorsBy, ZUKAN_LIST_HideAllActors, ZUKAN_LIST_ShowAllActors, ZUKAN_LIST_MoveCursorActor, ZUKAN_LIST_UpdateScrollBarActor, ZUKAN_LIST_UpdateArrowActors, ZUKAN_LIST_HandleTouchInput
 * address:  0x021BC240
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_list.c, ov209_func_021BE658.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_020419E4 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   func_02005624 0x02005624 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   gZukanListVramBankConfig 0x021BE7D4 data a4
 *   BG_SYS_Create 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   data_021BE804 0x021BE804 data a4
 *   data_021BE894 0x021BE894 data a4
 *   data_021BE874 0x021BE874 data a4
 *   data_021BE814 0x021BE814 data a4
 *   data_021BE8F4 0x021BE8F4 data a4
 *   data_021BE8B4 0x021BE8B4 data a4
 *   data_021BE854 0x021BE854 data a4
 *   data_021BE8D4 0x021BE8D4 data a4
 *   data_021BE834 0x021BE834 data a4
 *   func_020403F4  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_020275E4 0x020275E4 thumb
 *   func_02027628 0x02027628 thumb
 *   func_02027624 0x02027624 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02049740 0x02049740 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02049B40 0x02049B40 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   func_020056BC 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_02045B38 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   GF_FONT_Create_EC64 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   func_020307B0 0x020307B0 arm
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   ZUKAN_SAVE_GetLastViewedSpecies 0x0200CA8C thumb
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Clone 0x02045874 arm
 *   data_021BE7AC 0x021BE7AC data a4
 *   data_020A7370 0x020A7370 data a4
 *   FRAME_LIST_Delete 0x021B796C thumb ov067
 *   FRAME_LIST_GetItemValue 0x021B9398 thumb ov067
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   gZukanListStateHandlers 0x021BE96C data a4
 *   ZUKAN_TickCounter 0x021C93E4 thumb ov212
 *   ov067_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   func_0204363C 0x0204363C arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_02034A5C 0x02034A5C arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   FRAME_LIST_Update 0x021B7AB0 thumb ov067
 *   ZUKAN_LIST_HandleTouchInput 0x021BE658 thumb ov209
 *   FRAME_LIST_GetSelectedIndex 0x021B93A4 thumb ov067
 *   func_021B93D4 0x021B93D4 thumb ov067
 *   func_020355C4 0x020355C4 arm
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_SAVE_SetViewMode 0x0200CA5C thumb
 *   FRAME_LIST_SetRowPalette 0x021B9280 thumb ov067
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   ZUKAN_SAVE_SetLastViewedSpecies 0x0200CA78 thumb
 *   GAME_DATA_CheckSaveFlag 0x02012BF8 thumb
 *   GAME_DATA_SetSaveFlag 0x02012BE0 thumb
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   gZukanListWindowDefs 0x021BE990 data a1
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   TOUCHBAR_PrintAligned 0x021B6AE4 thumb ov067
 *   func_0201F250 0x0201F250 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   BMP_WIN_GetDispHeight 0x02045750 arm
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02049DF4 0x02049DF4 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   ZUKAN_SAVE_CountSeenNational 0x0200D0CC thumb
 *   ZUKAN_SAVE_CountCaughtNational 0x0200CF28 thumb
 *   ZUKAN_SAVE_CountSeenRegional 0x0200D0F8 thumb
 *   ZUKAN_SAVE_CountCaughtRegional 0x0200CF54 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   FRAME_LIST_GetPrinter 0x021B9394 thumb ov067
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_GetActorAutoAnim 0x0204B944 arm
 *   CLACT_AddActorAnimFrame 0x0204B8D4 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_SetActorAnimFrame 0x0204B8C4 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_IsActorAnimActive 0x0204B98C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   gZukanListClactInit 0x021BE9D4 data a4
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterPaletteCompressed 0x0204ACEC arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   POKE_TOOL_CalcGraphicIndex 0x0201BABC thumb
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BC78 0x0201BC78 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0201BCEC 0x0201BCEC thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   ZUKAN_CreateActor 0x021C940C thumb ov212
 *   CLACT_SetActorVisible 0x0204BA20 arm
 *   ZUKAN_SAVE_GetDexObtained 0x0200CA54 thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 *   gZukanListActorDescTable 0x021BE9F0 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   gZukanListActorDesc 0x021BE9BC data a4
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   ZUKAN_SAVE_GetViewGenderAndForm 0x0200CC40 thumb
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   ZUKAN_SAVE_GetSpindaPersonality 0x0200D288 thumb
 *   POKEGRA_RegisterCgr 0x0202D81C thumb
 *   POKEGRA_RegisterPalette 0x0202D7D8 thumb
 *   POKEGRA_RegisterCellAnim 0x0202D898 thumb
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   CLACT_SetActorFlip 0x0204B604 arm
 *   gZukanListSpeciesActor 0x021BE9A4 data a4
 *   func_02049E74 0x02049E74 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   CLACT_TransferCharacterPart 0x0204AA94 arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   FRAME_LIST_ClampToScrollBar 0x021B8AE4 thumb ov067
 *   FRAME_LIST_CanScrollDown 0x021B93C0 thumb ov067
 *   FRAME_LIST_HideCursor   0x021B941C  thumb
 *   func_021B940C   0x021B940C  thumb ov133
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   the name); it is a member function of the EXACT game_unit
 */

/* The ov067 scrolling list object stays opaque here. */
struct FrameList;

struct ProcSystem;

struct S020315D4;

struct Node;

struct S02021D50;

struct DispVram;

struct DispConfig;

struct PalAnmSlot;

struct GfFont;

struct MsgBank;

struct U16Vec;

struct WordSet;

struct PrintSys;

struct Rec;

struct Blk37;



struct Descriptor;

struct Cfg;

struct Bmp;

struct Actor;

struct Obj;

struct Vec2;

struct Bank;

struct Personal;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct Display {u32 w[4];};

struct BgTemplate {u32 w[8];};

typedef signed int s32;

/*
 * Create parameters of the ov067 frame list, owned by
 * ../ov067/frame_list_params.h.
 */
#include "../ov067/frame_list_params.h"

/* Arguments the ov209 zukan list screen receives from its creator. */
struct ZukanListArgs {
    void *gameData;          /* 0x00 handle passed to GAME_DATA_* */
    struct Blk37 *save;      /* 0x04 pokedex save block */
    u16 mode;                /* 0x08 header mode (0 regional counts, 1 national) */
    u16 count;               /* 0x0a number of species rows */
    u16 *ids;                /* 0x0c row species ids */
    u32 state;               /* 0x10 screen state requested by the list */
};

/* One touchbar window entry (three of them follow one another). */
struct ZukanListWindow {
    struct Descriptor *bmp;  /* 0x00 */
    u8 pending;              /* 0x04 string transfer still queued */
    u8 pad[3];
};

/* Whole-word view and the two bit fields of the 0xC24 status halfword. */
struct ZukanListFlags { u16 side : 1; u16 animIdx : 15; };
union ZukanListStatus { u16 all; struct ZukanListFlags bits; };

/* The 0xc44-byte proc work object of the zukan list screen. */
struct ZukanList {
    struct ZukanListArgs *args;          /* 0x000 */
    void *vblankTask;                    /* 0x004 */
    void *hblankTask;                    /* 0x008 */
    void *palAnm;                        /* 0x00C palette animation handle */
    int state;                           /* 0x010 processor state index */
    int scrollPhase;                     /* 0x014 */
    int returnState;                     /* 0x018 state to run after a button anim */
    int fadeReturnState;                 /* 0x01C state to run after a fade */
    struct ZukanListWindow windows[3];   /* 0x020 */
    void *font;                          /* 0x038 */
    struct MsgBank *msgBank;             /* 0x03C */
    struct WordSet *wordSet;             /* 0x040 */
    struct U16Vec *textBuf;              /* 0x044 */
    void *printer;                       /* 0x048 */
    struct U16Vec *speciesText[649];     /* 0x04C one string per species row */
    struct Bank *clactUnit;              /* 0xA70 */
    struct Obj *actors[60];              /* 0xA74 */
    u32 charHandles[36];                 /* 0xB64 */
    u32 paletteHandles[6];               /* 0xBF4 */
    u32 cellAnimHandles[6];              /* 0xC0C */
    union ZukanListStatus status;        /* 0xC24 side flag and running button anim */
    u8 cursorFlashPhase;                 /* 0xC26 */
    u8 cursorFlashTimer;                 /* 0xC27 */
    u16 hiddenMaskA;                     /* 0xC28 saved visibility of rows 10..25 */
    u16 hiddenMaskB;                     /* 0xC2A saved visibility of rows 26..41 */
    void *frameList;                     /* 0xC2C */
    int initPhase;                       /* 0xC30 */
    int rowCount;                        /* 0xC34 */
    u16 *formTable;                      /* 0xC38 */
    u8 padC3C[4];                        /* 0xC3C cursor tracker for ZUKAN_TickCounter */
    u16 moveTimer;                       /* 0xC40 */
    short moveDelta;                     /* 0xC42 */
};

/* Interrupt flag the vblank handler sets at 0x02FE3FF8. */
struct DtcmIrqFlag { u8 pad[0x3FF8]; unsigned flag; };

typedef struct WordSet WordSet;

typedef signed short s16;

typedef struct PtS {s16 x,y;} PtS;

/* Config passed to CLACT_InitSystem (seven full words). */
struct ClactInit { u32 words[7]; };

/* Descriptor ZUKAN_CreateActor builds one CLACT actor from. */
struct ClactActorDesc { u32 attr0, attr4, charIndex, palIndex, animIndex; u16 posX, posY; };

/* Descriptor ZUKAN_CreateActor builds the scrolling species actors from. */
struct ClactSpeciesActor { u16 attr0; u16 posY; u32 attr4; u32 charHandle; u32 palHandle; u32 animHandle; u16 attr14; u16 flags; };

/* Character part data returned by func_02049E74. */
struct ClactPartData { u8 pad[20]; void *part; };

enum Position { POSITION_ZERO=0 };

extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);

extern void *PROCSYS_AllocProcWork(struct ProcSystem *,unsigned,unsigned);

extern void MI_CpuFill8(void *,int,int);

extern void func_020315D4(struct S020315D4 *p);

extern void func_020306F0(unsigned int heap);

extern void *func_020056A0(unsigned,unsigned,unsigned);

extern void func_02030EAC(struct Node *);

extern void func_020419E4(void),CLACT_VBlankSystem(void);

extern void PALANM_TransferPalettes(struct S02021D50 *);

extern void *func_02005624(unsigned,unsigned,unsigned);

extern void BG_SYS_SetVramBanks(const struct DispVram *);

extern void BG_SYS_Create(u16);

extern void func_0203FC28(struct DispConfig *cfg);

extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);

extern void BG_SYS_ClearSlot(u32);

extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

extern void func_02041B6C(u32);

extern void BG_SYS_SetMainPlaneVisible(u32,u32);

extern void BG_SYS_SetSubPlaneVisible(u32,u32);

extern void func_020403F4(u32 i);

extern void BG_SYS_Delete(void);

extern void *func_020490F4(u32 id, u32 heap);

extern void func_02049B68(void *,u32,u32,u32,u32,u16);

extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void func_020498F4(void *,u32,u32,u32,u32,u32,u16);

extern void ARC_TOOL_DeleteHandle(void *);

extern u32 func_020275E4(void);

extern u32 func_02027628(void);

extern u32 func_02027624(void);

extern u32 func_0202762C(void);

extern u32 func_02049740(void *,u32,u32,u32,u32,u16);

extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern void func_02049B40(u32,u32,u32,u32,u32,u16);

extern void *PALANM_Create(u32);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,unsigned);

extern void PALANM_Delete(struct PalAnmSlot *);

extern u32 func_020056BC(void);

extern int PALANM_RequestFade(void *, u16, u16, short, u8, u8, u16, void *);

extern void func_0207D63C(void *,unsigned,unsigned,unsigned,unsigned);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern struct WordSet *GF_FONT_Create_EC64(u32 heap);

extern u32 PRINTSYS_QUE_Create(void *);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_Delete(struct U16Vec *);

extern void PRINTSYS_QUE_Delete(struct PrintSys *);

extern void WORDSET_DeleteStrbufED04(struct WordSet *);

extern void GF_FONT_Delete(void *);

extern void MSGDATA_Delete(struct Rec *);

extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);

extern u32 func_020307B0(void *p);

extern void BG_SYS_ResetSlot(u32, u32, u32);

extern u16 ZUKAN_SAVE_GetLastViewedSpecies(struct Blk37 *p);

extern struct FrameList *FRAME_LIST_Create(const FrameListParams *params, u32 heap);

extern void FRAME_LIST_CopyMapToBuffer(u8 *p, u32 a, u32 b, u32 c, u32 index);

extern void FRAME_LIST_LoadPalettes(u8 *p, u8 *a, u32 b, u32 c, u32 d);

extern void FRAME_LIST_AddItem(char *ctx, unsigned first, unsigned second);

extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *p, u16 id);

extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);

extern void *func_02045EC0(struct MsgBank *bank, u32 index);

extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);

extern void FRAME_LIST_Delete(struct FrameList *);

extern u32 FRAME_LIST_GetItemValue(char *p, int index);

extern int FRAME_LIST_GetScrollPos(char *);

extern int FRAME_LIST_GetCursor(char *);

extern void ZUKAN_LIST_UpdateActors(struct ZukanList *),ZUKAN_LIST_FlushWindows(struct ZukanList *),ZUKAN_TickCounter(u32,u32,u8 *);

extern void BG_SYS_SetMainVisiblePlanes(u32);

extern void BG_SYS_SetSubVisiblePlanes(u32);

extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);

extern int func_02034AC4(int);

extern void func_0204363C(u32);

extern void GFL_NET_RestartWithDefaultTimeout(u32, u32);

extern u32 PALANM_GetFadeRequestBits(const char *);

extern void func_02034A5C(int);

extern int FRAME_LIST_UpdateInit(struct FrameList *p);

extern int FRAME_LIST_Update(struct FrameList *p);

extern int ZUKAN_LIST_HandleTouchInput(struct ZukanList *p);

extern int FRAME_LIST_GetSelectedIndex(char *p);

extern void func_021B93D4(struct FrameList *s, int v);

extern u8 func_020355C4(void);

extern void func_020355D8(u8);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p);

extern void ZUKAN_SAVE_SetViewMode(struct Blk37 *p, u32 v);

extern void FRAME_LIST_SetRowPalette(u8 *p, int a, u32 b);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, unsigned, unsigned, unsigned);

extern void ZUKAN_SAVE_SetLastViewedSpecies(void *,u16);

extern int GAME_DATA_CheckSaveFlag(int, int);

extern void GAME_DATA_SetSaveFlag(void *, unsigned, unsigned);

extern void BMP_WIN_Init(unsigned short);

extern unsigned BMP_WIN_Create(unsigned, unsigned, unsigned, unsigned, u8, u8, u8);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_WIN_Exit(void);

extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);

extern void func_0201F250(struct WordSet *, void *, void *);

extern void BMP_WIN_MakeScreen(struct Cfg *);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);

extern u8 BMP_WIN_GetDispWidth(struct Descriptor *p);

extern u8 BMP_WIN_GetDispHeight(struct Descriptor *p);

extern u8 BMP_WIN_GetPosX(struct Descriptor *p);

extern u8 BMP_WIN_GetPosY(struct Descriptor *p);

extern void *BMP_GetPixels(const struct Bmp *bmp);

extern void *func_02049EF4(void *, u32, u32, void **, u16);

extern void *func_02049DF4(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);

extern u16 ZUKAN_SAVE_CountSeenNational(struct Blk37 *p);

extern u16 ZUKAN_SAVE_CountCaughtNational(struct Blk37 *p);

extern u16 ZUKAN_SAVE_CountSeenRegional(struct Blk37 *p, u32 heap);

extern u16 ZUKAN_SAVE_CountCaughtRegional(struct Blk37 *p, u32 heap);

extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

extern unsigned FRAME_LIST_GetPrinter(char *);

extern void CLACT_ExitSystem(void);

extern u32 CLACT_GetActorAutoAnim(struct Actor *);

extern void CLACT_AddActorAnimFrame(struct Obj *,u32);

extern void CLACT_DrawSystem(void);

extern void CLACT_SetActorAnimFrame(struct Obj *p, u32 value);

extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

extern void CLACT_SetActorAutoAnim(struct Obj *,unsigned int);

extern u16 CLACT_GetActorAnimSeq(struct Obj *p);

extern u32 CLACT_IsActorAnimActive(struct Actor *);

extern void CLACT_SetActorDrawEnable(struct Obj *,u32);

extern u32 CLACT_GetActorDrawEnable(struct Obj *);

extern void CLACT_SetActorObjMode(struct Actor *,u32);

extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

extern void CLACT_GetActorSurfacePos(struct Actor *,PtS *,unsigned int);

extern void CLACT_InitSystem(const struct Cfg *,u32,u32);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern int CLACT_RegisterPaletteCompressed(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern u32 POKE_TOOL_CalcGraphicIndex(u32, u32, u32, u32);

extern int func_0201BC3C(void);

extern int func_0201BC40(void);

extern int func_0201BC78(void);

extern int func_0201BCB4(void);

extern int func_0201BCEC(void);

extern u32 func_02027614(void);

extern u32 func_02027618(void);

extern u32 func_0202761C(u32);

extern u32 func_02027620(u32);

extern void CLACT_ReleaseCharacter(unsigned);

extern void CLACT_ReleasePalette(unsigned);

extern void CLACT_ReleaseCellAnim(unsigned);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern struct Obj *ZUKAN_CreateActor(u32 bank, const u8 *t, u16 heap);

extern void CLACT_SetActorVisible(struct Actor *a, u32 v);

extern u32 ZUKAN_SAVE_GetDexObtained(struct Blk37 *p);

extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);

extern void CLACT_DeleteActor(struct Obj *);

extern void CLACT_DeleteUnit(struct Bank *);

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern void ZUKAN_SAVE_GetViewGenderAndForm(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);

extern int POKEGRA_OpenHandle(int a0);

extern u32 ZUKAN_SAVE_GetSpindaPersonality(struct Blk37 *p, u32 which);

extern u32 POKEGRA_RegisterCgr(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern int POKEGRA_RegisterPalette(int,int,int,int,int,int,int,int,u16,u16);

extern u32 POKEGRA_RegisterCellAnim(u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern void *POKE_PERSONAL_Create(u32,int,u32);

extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);

extern void POKE_PERSONAL_Delete(void *);

extern void CLACT_SetActorFlip(struct Actor *actor, u32 which, u32 set);

extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

extern u16 CLACT_GetActorCharacterIndex(u8 *);

extern void CLACT_TransferCharacterPart(int,void *,unsigned,int,int);

extern unsigned POKE_TOOL_CalcIconPalette(unsigned,unsigned,unsigned,unsigned);

extern void CLACT_SetActorPaletteOffset(struct Obj *,unsigned,unsigned);

extern int FRAME_LIST_ClampToScrollBar(struct FrameList *s, unsigned int v);

extern int FRAME_LIST_CanScrollDown(char *);

int ZUKAN_LIST_ProcInit(struct ProcSystem *p,int unused,unsigned v);

int ZUKAN_LIST_ProcMain(int unused0, int unused1, int unused2, int work);

int ZUKAN_LIST_ProcExit(void *p);

void ZUKAN_LIST_StartVBlankTask(struct ZukanList *p);

void ZUKAN_LIST_StopVBlankTask(struct ZukanList *p);

void ZUKAN_LIST_VBlankTask(void *unused,struct ZukanList *p);

void ZUKAN_LIST_StartHBlankTask(struct ZukanList *p);

void ZUKAN_LIST_StopHBlankTask(struct ZukanList *p);

void ZUKAN_LIST_HBlankTask(void);

void ZUKAN_LIST_SetVramBanks(void);

void *ZUKAN_LIST_GetVramBankConfig(void);

void ZUKAN_LIST_InitBgSystem(void);

void ZUKAN_LIST_ExitBgSystem(void);

void ZUKAN_LIST_LoadBgGraphics(void);

void ZUKAN_LIST_InitPaletteAnim(struct ZukanList *p);

void ZUKAN_LIST_ExitPaletteAnim(struct ZukanList *p);

void ZUKAN_LIST_RequestFade(struct ZukanList *p, u8 fadeFrom, u8 fadeTo);

void ZUKAN_LIST_SetSubScreenBlendAlpha(void);

void ZUKAN_LIST_EnableSubWindows(void);

void ZUKAN_LIST_DisableSubWindows(void);

void ZUKAN_LIST_CreateFontAndPrinter(struct ZukanList *p);

void ZUKAN_LIST_DeleteFontAndPrinter(struct ZukanList *p);

void ZUKAN_LIST_LoadFormTable(struct ZukanList *p);

void ZUKAN_LIST_FreeFormTable(struct ZukanList *p);

void ZUKAN_LIST_MoveScrollBarActorsIn(struct ZukanList *p);

void ZUKAN_LIST_StartActorMoveFrames(struct ZukanList *a, int b);

int ZUKAN_LIST_UpdateActorMove(struct ZukanList *p);

void ZUKAN_LIST_CreateFrameList(struct ZukanList *p);

void ZUKAN_LIST_DeleteFrameList(struct ZukanList *p);

void ZUKAN_LIST_FrameListMoveCallback(struct ZukanList *p, int index, int dest, u16 position, int mode);

void ZUKAN_LIST_FrameListSelectCallback(struct ZukanList *p, int index);

void ZUKAN_LIST_ScrollByDelta(struct ZukanList *p,int delta);

int ZUKAN_LIST_RunState(struct ZukanList *p);

int ZUKAN_LIST_StateInit(struct ZukanList *p);

int ZUKAN_LIST_StateExit(struct ZukanList *p);

int ZUKAN_LIST_StateWaitFade(struct ZukanList *p);

int ZUKAN_LIST_StateFadeIn(struct ZukanList *p);

int ZUKAN_LIST_StateMain(struct ZukanList *p);

int ZUKAN_LIST_StateScroll(struct ZukanList *p);

int ZUKAN_LIST_StateScrollWait(struct ZukanList *p);

int ZUKAN_LIST_StateCursorFlash(struct ZukanList *p);

int ZUKAN_LIST_StateFadeOut(struct ZukanList *p);

void ZUKAN_LIST_ResetPaletteSlots(struct ZukanList *p);

int ZUKAN_LIST_StartButtonAnim(struct ZukanList *p,int actorIndex,int animValue,int nextState);

int ZUKAN_LIST_IsSpeciesEntryValid(struct ZukanList *p,int i);

void ZUKAN_LIST_StoreLastViewedSpecies(struct ZukanList *p,int i);

int ZUKAN_LIST_StateSelectSpecies(struct ZukanList *a, int speciesIndex);

void ZUKAN_LIST_ToggleSaveFlag15(struct ZukanList *p);

void ZUKAN_LIST_CreateWindows(struct ZukanList *p);

void ZUKAN_LIST_DeleteWindows(struct ZukanList *p);

void ZUKAN_LIST_FlushWindows(struct ZukanList *p);

void ZUKAN_LIST_PrintTouchbarLabel(struct ZukanList *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode);

void ZUKAN_LIST_PrintTouchbarLabelClone(struct ZukanList *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode);

void ZUKAN_LIST_MakeWindowScreens(void **p);

void ZUKAN_LIST_ClearWindow(struct ZukanList *p, u32 idx);

void ZUKAN_LIST_DrawHeaderRegional(struct ZukanList *p);

void ZUKAN_LIST_DrawHeaderCounts(struct ZukanList *p);

void ZUKAN_LIST_DrawHeaderNational(struct ZukanList *p);

void ZUKAN_LIST_PrintListRow(struct ZukanList *p, unsigned char *dest, unsigned text0, unsigned index);

void ZUKAN_LIST_InitActors(struct ZukanList *p);

void ZUKAN_LIST_ExitActors(struct ZukanList *list);

void ZUKAN_LIST_UpdateActors(struct ZukanList *p);

void ZUKAN_LIST_SetActorAnim(struct ZukanList *p, int idx, int v);

void ZUKAN_LIST_StartActorAnim(struct ZukanList *p,int idx,int value);

int ZUKAN_LIST_GetActorAnimSeq(struct ZukanList *a, int actorIndex);

u32 ZUKAN_LIST_IsActorAnimActive(struct ZukanList *p,u32 idx);

void ZUKAN_LIST_SetActorVisible(struct ZukanList *p,u32 idx,u32 value);

u32 ZUKAN_LIST_GetActorVisible(struct ZukanList *p,u32 idx);

void ZUKAN_LIST_SetActorObjMode(struct ZukanList *p,u32 idx,u32 flag);

void ZUKAN_LIST_AddActorPos(struct ZukanList *p, int idx, short x, short y, unsigned short surface);

void ZUKAN_LIST_GetActorPos(struct ZukanList *p,u32 idx,s16 *x,s16 *y,u16 space);

void ZUKAN_LIST_InitActorSystem(struct ZukanList *p);

void ZUKAN_LIST_LoadActorResources(struct ZukanList *p);

void ZUKAN_LIST_ReleaseActorResources(struct ZukanList *p);

void ZUKAN_LIST_CreateActors(struct ZukanList *p);

void ZUKAN_LIST_DeleteActor(struct ZukanList *p,u32 idx);

void ZUKAN_LIST_DeleteActorUnit(struct ZukanList *p);

void ZUKAN_LIST_LoadSpeciesIcon(struct ZukanList *p,u16 species);

void ZUKAN_LIST_UpdateSpeciesActors(struct ZukanList *p);

void ZUKAN_LIST_TransferSpeciesGraphics(struct ZukanList *p, int actorIndex, unsigned species, u16 form, u16 charHalf, int mode);

int ZUKAN_LIST_IsActorHidden(struct ZukanList *list, int group);

void ZUKAN_LIST_ShowSpeciesActor(struct ZukanList *p,u16 species,enum Position pos,int mode);

void ZUKAN_LIST_ScrollActorsBy(struct ZukanList *p, int delta);

void ZUKAN_LIST_HideAllActors(struct ZukanList *p);

void ZUKAN_LIST_ShowAllActors(struct ZukanList *p);

void ZUKAN_LIST_MoveCursorActor(struct ZukanList *p,int index);

void ZUKAN_LIST_UpdateScrollBarActor(struct ZukanList *p);

void ZUKAN_LIST_UpdateArrowActors(struct ZukanList *p,int flag);

extern const struct DispVram gZukanListVramBankConfig;

extern const struct Display data_021BE804;

extern const struct BgTemplate data_021BE894,data_021BE874,data_021BE814,data_021BE8F4,data_021BE8B4,data_021BE854,data_021BE8D4,data_021BE834;

extern const FrameListParams data_021BE7AC;

extern void *data_020A7370;

extern const char ov067_id[];

extern const u8 gZukanListWindowDefs[][6];

extern const struct ClactInit gZukanListClactInit;

extern const struct ClactActorDesc gZukanListActorDescTable[10];

extern const struct ClactActorDesc gZukanListActorDesc;

extern const struct ClactSpeciesActor gZukanListSpeciesActor;

int ZUKAN_LIST_ProcInit(struct ProcSystem *p,int unused,unsigned v){unsigned *q;GFL_HEAP_CreateChildHeap(1,107,0x60000);q=PROCSYS_AllocProcWork(p,0xc44,107);MI_CpuFill8(q,0,0xc44);*q=v;return 1;}

int ZUKAN_LIST_ProcMain(int unused0, int unused1, int unused2, int work)
{
    if (ZUKAN_LIST_RunState((struct ZukanList *)work) == 0)
        return 1;
    return 0;
}

int ZUKAN_LIST_ProcExit(void *p)
{
    func_020315D4(p);
    func_020306F0(0x6b);
    return 1;
}

void ZUKAN_LIST_StartVBlankTask(struct ZukanList *p){p->vblankTask=func_020056A0((unsigned)ZUKAN_LIST_VBlankTask,(unsigned)p,0);}

void ZUKAN_LIST_StopVBlankTask(struct ZukanList *p){func_02030EAC((struct Node *)p->vblankTask);}

/*
 * lever: enum-typed DTCM base preserves the base-first two-pool address; constant addition folds and enum offset reverses pool/register roles.
 * volatile: hardware interrupt check flag at 02FE3FF8 read and written by 021BC2D4/021BC2D8.
 */
void ZUKAN_LIST_VBlankTask(void *unused,struct ZukanList *p){enum Base { DTCM_BASE=0x02fe0000 } base;func_020419E4();CLACT_VBlankSystem();PALANM_TransferPalettes((struct S02021D50 *)p->palAnm);base=DTCM_BASE;*(volatile unsigned *)&((struct DtcmIrqFlag *)base)->flag|=1;}

void ZUKAN_LIST_StartHBlankTask(struct ZukanList *p){p->hblankTask=func_02005624((unsigned)ZUKAN_LIST_HBlankTask,(unsigned)p,0);}

void ZUKAN_LIST_StopHBlankTask(struct ZukanList *p)
{
    func_02030EAC(p->hblankTask);
}

/*
 * volatile: VCOUNT read at 021BC30A; BLDALPHA writes at 021BC314, 021BC320, 021BC32C, 021BC338, 021BC344, 021BC34A
 */
void ZUKAN_LIST_HBlankTask(void)
{
    int v = *(volatile u16 *)0x04000006;
    if (v >= 168) {
        *(volatile u16 *)0x04001052 = 0x050B;
        return;
    }
    if (v >= 144) {
        *(volatile u16 *)0x04001052 = 0x060A;
        return;
    }
    if (v >= 120) {
        *(volatile u16 *)0x04001052 = 0x0709;
        return;
    }
    if (v >= 96) {
        *(volatile u16 *)0x04001052 = 0x0808;
        return;
    }
    if (v >= 72) {
        *(volatile u16 *)0x04001052 = 0x0A06;
        return;
    }
    *(volatile u16 *)0x04001052 = 0x0C04;
}

void ZUKAN_LIST_SetVramBanks(void){BG_SYS_SetVramBanks(&gZukanListVramBankConfig);}

void *ZUKAN_LIST_GetVramBankConfig(void){return (void *)&gZukanListVramBankConfig;}

void ZUKAN_LIST_InitBgSystem(void)
{
    struct Display display;
    struct BgTemplate b0,b1,b2,b3,b4,b5,b6,b7;
    BG_SYS_Create(107);
    display=data_021BE804;func_0203FC28((struct DispConfig *)(&display));
    b0=data_021BE894;BG_SYS_InitBgLayer(0,&b0,0);
    BG_SYS_ClearSlot(0);BG_SYS_InitRun(0,32,0,107);func_02041B6C(0);
    b1=data_021BE874;BG_SYS_InitBgLayer(1,&b1,0);
    b2=data_021BE814;BG_SYS_InitBgLayer(2,&b2,0);
    BG_SYS_ClearSlot(2);func_02041B6C(2);
    b3=data_021BE8F4;BG_SYS_InitBgLayer(3,&b3,0);
    b4=data_021BE8B4;BG_SYS_InitBgLayer(4,&b4,0);
    BG_SYS_ClearSlot(4);BG_SYS_InitRun(4,32,0,107);func_02041B6C(4);
    b5=data_021BE854;BG_SYS_InitBgLayer(5,&b5,0);
    b6=data_021BE8D4;BG_SYS_InitBgLayer(6,&b6,0);
    BG_SYS_ClearSlot(6);func_02041B6C(6);
    b7=data_021BE834;BG_SYS_InitBgLayer(7,&b7,0);
    BG_SYS_SetMainPlaneVisible(15,1);BG_SYS_SetSubPlaneVisible(15,1);
}

void ZUKAN_LIST_ExitBgSystem(void)
{
    BG_SYS_SetMainPlaneVisible(0xf, 0);
    BG_SYS_SetSubPlaneVisible(0xf, 0);
    func_020403F4(7);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    BG_SYS_Delete();
}

void ZUKAN_LIST_LoadBgGraphics(void)
{
    void *arc;
    arc=func_020490F4(159,107);
    func_02049B68(arc,48,0,0,128,107);
    func_02049B68(arc,49,4,0,160,107);
    func_02049658(arc,58,2,0,0,0,107);
    func_02049658(arc,56,3,0,0,0,107);
    func_02049658(arc,59,6,0,0,0,107);
    func_02049658(arc,57,7,0,0,0,107);
    func_020498F4(arc,62,3,0,0,0,107);
    func_020498F4(arc,69,5,0,0,0,107);
    func_020498F4(arc,63,7,0,0,0,107);
    ARC_TOOL_DeleteHandle(arc);
    arc=func_020490F4(func_020275E4(),107);
    func_02049740(arc,func_02027628(),1,0,0,107);
    func_02049B68(arc,func_02027624(),0,448,32,107);
    func_020498F4(arc,func_0202762C(),1,0,0,0,107);
    func_020413B0(1,0,21,32,3,14);
    func_02041B6C(1);
    ARC_TOOL_DeleteHandle(arc);
    func_02049B40(23,5,0,480,32,107);
    func_02049B40(23,5,4,480,32,107);
}

void ZUKAN_LIST_InitPaletteAnim(struct ZukanList *p)
{
    p->palAnm = PALANM_Create(0x6B);
    PALANM_AllocSlotBuffers(p->palAnm, 0, 0x200, 0x6B);
    PALANM_AllocSlotBuffers(p->palAnm, 1, 0x200, 0x6B);
    PALANM_AllocSlotBuffers(p->palAnm, 2, 0x200, 0x6B);
    PALANM_AllocSlotBuffers(p->palAnm, 3, 0x200, 0x6B);
}

void ZUKAN_LIST_ExitPaletteAnim(struct ZukanList *p){PALANM_FreeSlotBuffers((struct PalAnmSlot *)p->palAnm,0);PALANM_FreeSlotBuffers((struct PalAnmSlot *)p->palAnm,1);PALANM_FreeSlotBuffers((struct PalAnmSlot *)p->palAnm,2);PALANM_FreeSlotBuffers((struct PalAnmSlot *)p->palAnm,3);PALANM_Delete((struct PalAnmSlot *)p->palAnm);}

void ZUKAN_LIST_RequestFade(struct ZukanList *p, u8 fadeFrom, u8 fadeTo)
{
    void *ctx;
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(p->palAnm, 1, 0xBFFF, -14, fadeFrom, fadeTo, 0, ctx);
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(p->palAnm, 2, 0xFFEF, -14, fadeFrom, fadeTo, 0, ctx);
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(p->palAnm, 4, 0xF878, -14, fadeFrom, fadeTo, 0, ctx);
    ctx = (void *)func_020056BC();
    PALANM_RequestFade(p->palAnm, 8, 0xBFFF, -14, fadeFrom, fadeTo, 0, ctx);
}

void ZUKAN_LIST_SetSubScreenBlendAlpha(void){func_0207D63C((void *)0x04001050,4,8,6,10);}

/* Sets the inside-window region bits (8..13) of WININ. */
static inline void setInsideWindowMask(int region, int enable)
{
    u32 tmp = (*(volatile u16 *)0x0400104A & ~0x3F00) | ((u32)region << 8);
    if (enable) tmp |= 0x2000;
    *(volatile u16 *)0x0400104A = (u16)tmp;
}

/* Sets the outside-window region bits (0..5) of WININ. */
static inline void setOutsideWindowMask(int region, int enable)
{
    u32 tmp = (*(volatile u16 *)0x0400104A & ~0x3F) | (u32)region;
    if (enable) tmp |= 0x20;
    *(volatile u16 *)0x0400104A = (u16)tmp;
}

/*
 * volatile: WINOUT reads/writes at 021BC7D4..021BC7F2; DISPCNT read/write at 021BC7F8..021BC802
 */
void ZUKAN_LIST_EnableSubWindows(void)
{
    setInsideWindowMask(27, 1);
    setOutsideWindowMask(31, 1);
    *(volatile u32 *)0x04001000 = (*(volatile u32 *)0x04001000 & ~0xE000) | 0x8000;
}

void ZUKAN_LIST_DisableSubWindows(void)
{
    *(volatile u32 *)0x04001000 &= 0xFFFF1FFF;
}

void ZUKAN_LIST_CreateFontAndPrinter(struct ZukanList *p)
{
    p->msgBank = func_02045B38(0, 2, 0x114, 0x6B);
    p->font = GF_FONT_Create(0x17, 0, 0, 0, 0x6B);
    p->wordSet = GF_FONT_Create_EC64(0x6B);
    p->printer = (void *)PRINTSYS_QUE_Create((void *)0x6B);
    p->textBuf = STRBUF_Create(0x80, 0x6B);
}

void ZUKAN_LIST_DeleteFontAndPrinter(struct ZukanList *p){STRBUF_Delete((struct U16Vec *)p->textBuf);PRINTSYS_QUE_Delete((struct PrintSys *)p->printer);WORDSET_DeleteStrbufED04((struct WordSet *)p->wordSet);GF_FONT_Delete(p->font);MSGDATA_Delete((struct Rec *)p->msgBank);}

void ZUKAN_LIST_LoadFormTable(struct ZukanList *p) { p->formTable=POKE_PERSONAL_LoadFormTable(107,0); }

void ZUKAN_LIST_FreeFormTable(struct ZukanList *p) { func_020307B0(p->formTable); }

void ZUKAN_LIST_MoveScrollBarActorsIn(struct ZukanList *p)
{
    unsigned i;
    s16 pair[2];
    BG_SYS_ResetSlot(5, 3, 48);
    BG_SYS_ResetSlot(1, 3, -48);
    for (i = 3; i <= 9; i++) {
        ZUKAN_LIST_GetActorPos(p, i, &pair[1], &pair[0], 0);
        pair[0] += 48;
        ZUKAN_LIST_AddActorPos(p, i, pair[1], pair[0], 0);
    }
}

void ZUKAN_LIST_StartActorMoveFrames(struct ZukanList *a, int b)
{
    a->moveTimer = 0x30;
    *(unsigned short *)&a->moveDelta = b;
}

int ZUKAN_LIST_UpdateActorMove(struct ZukanList *p)
{
    unsigned i;
    s16 pair[2];
    int d;
    if (p->moveTimer == 0) return 0;
    BG_SYS_ResetSlot(5, 4, p->moveDelta);
    BG_SYS_ResetSlot(1, 5, p->moveDelta);
    for (i = 3; i <= 9; i++) {
        ZUKAN_LIST_GetActorPos(p, i, &pair[1], &pair[0], 0);
        pair[0] += p->moveDelta;
        ZUKAN_LIST_AddActorPos(p, i, pair[1], pair[0], 0);
    }
    d = p->moveDelta;
    if (d < 0) d = -d;
    p->moveTimer -= d;
    return 1;
}

/*
 * ov067 is loaded by the same overlay's 021BCC94/021BCD48 path.
 */
void ZUKAN_LIST_CreateFrameList(struct ZukanList *p)
{
    FrameListParams tmpl;
    void *arc,*str;
    u32 species,i;
    arc=func_020490F4(159,0x806b);
    species=ZUKAN_SAVE_GetLastViewedSpecies(p->args->save);
    tmpl=data_021BE7AC;
    tmpl.itemCount=649;tmpl.userData=p;
    for(i=0;i<p->args->count;i++){
        if(species==p->args->ids[i]){
            if(i>p->args->count-7){
                tmpl.initialCursor=i-(p->args->count-7);
                tmpl.initialScroll=i-tmpl.initialCursor;
            }else if(i<7){tmpl.initialCursor=i;}
            else{tmpl.initialScroll=i;}
            break;
        }
    }
    p->frameList=FRAME_LIST_Create(&tmpl,107);
    if(p->args->count<7)p->rowCount=p->args->count;else p->rowCount=7;
    FRAME_LIST_CopyMapToBuffer(p->frameList,(u32)arc,66,0,0);
    FRAME_LIST_CopyMapToBuffer(p->frameList,(u32)arc,67,0,1);
    FRAME_LIST_CopyMapToBuffer(p->frameList,(u32)arc,68,0,2);
    FRAME_LIST_LoadPalettes(p->frameList,arc,48,2,3);
    ARC_TOOL_DeleteHandle(arc);
    for(i=0;i<p->args->count;i++){
        if(ZUKAN_SAVE_IsCaught(p->args->save,p->args->ids[i])==1){
            str=func_02045EC0(data_020A7370,p->args->ids[i]);
            *(void **)((u32)(char *)p+i*4+0x4c)=STRBUF_Clone(str,107);
            STRBUF_Delete(str);
            FRAME_LIST_AddItem(p->frameList,0,0x20000000|p->args->ids[i]);
        }else if(ZUKAN_SAVE_IsSeen(p->args->save,p->args->ids[i])==1){
            str=func_02045EC0(data_020A7370,p->args->ids[i]);
            *(void **)((u32)(char *)p+i*4+0x4c)=STRBUF_Clone(str,107);
            STRBUF_Delete(str);
            FRAME_LIST_AddItem(p->frameList,1,0x10000000|p->args->ids[i]);
        }else{
            *(void **)((u32)(char *)p+i*4+0x4c)=func_02045EC0(p->msgBank,7);
            FRAME_LIST_AddItem(p->frameList,2,p->args->ids[i]);
        }
    }
}

void ZUKAN_LIST_DeleteFrameList(struct ZukanList *p) { u32 i;FRAME_LIST_Delete((struct FrameList *)p->frameList);for(i=0;i<649;i++){struct U16Vec *q=*(struct U16Vec **)((u32)(char *)p+i*4+76);if(q)STRBUF_Delete(q);} }

void ZUKAN_LIST_FrameListMoveCallback(struct ZukanList *p, int index, int dest, u16 position, int mode)
{
    u32 v;
    u32 low;
    v = FRAME_LIST_GetItemValue(p->frameList, index);
    low = v & 0x0FFFFFFF;
    ZUKAN_LIST_PrintListRow(p, (unsigned char *)dest, (u32)p->speciesText[index], low);
    if ((v & 0xF0000000) >> 28) ZUKAN_LIST_ShowSpeciesActor(p, low, position, mode);
}

void ZUKAN_LIST_FrameListSelectCallback(struct ZukanList *p, int index)
{
    u32 v;
    v = FRAME_LIST_GetItemValue(p->frameList, index);
    if ((v & 0xF0000000) >> 28) ZUKAN_LIST_LoadSpeciesIcon(p, v & 0x0FFFFFFF);
    else ZUKAN_LIST_LoadSpeciesIcon(p, 0);
    ZUKAN_LIST_MoveCursorActor(p, index - FRAME_LIST_GetScrollPos(p->frameList));
}

void ZUKAN_LIST_ScrollByDelta(struct ZukanList *p,int delta) { ZUKAN_LIST_ScrollActorsBy(p,(signed char)-delta);ZUKAN_LIST_MoveCursorActor(p,FRAME_LIST_GetCursor(p->frameList));ZUKAN_LIST_UpdateArrowActors(p,1); }

extern int (*const gZukanListStateHandlers[])(char *);

int ZUKAN_LIST_RunState(struct ZukanList *p) { p->state=(*(int (**)(char *))((u32)gZukanListStateHandlers+p->state*4))((char *)p);if(p->state==9)return 0;ZUKAN_LIST_UpdateActors(p);ZUKAN_LIST_FlushWindows(p);ZUKAN_TickCounter(3,7,(u8 *)p->padC3C);return 1; }

/*
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCCB0, 021BCCB2
 */
int ZUKAN_LIST_StateInit(struct ZukanList *p)
{
    func_02034AC4((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
    func_0204363C(0);
    ZUKAN_LIST_InitPaletteAnim(p);
    ZUKAN_LIST_SetVramBanks();
    ZUKAN_LIST_InitBgSystem();
    ZUKAN_LIST_LoadBgGraphics();
    ZUKAN_LIST_CreateFontAndPrinter(p);
    ZUKAN_LIST_CreateWindows(p);
    ZUKAN_LIST_InitActors(p);
    ZUKAN_LIST_LoadFormTable(p);
    ZUKAN_LIST_CreateFrameList(p);
    if (p->args->mode == 0) ZUKAN_LIST_DrawHeaderCounts(p);
    else ZUKAN_LIST_DrawHeaderNational(p);
    GFL_NET_RestartWithDefaultTimeout(1, 0x6B);
    ZUKAN_LIST_SetSubScreenBlendAlpha();
    ZUKAN_LIST_EnableSubWindows();
    ZUKAN_LIST_MoveScrollBarActorsIn(p);
    ZUKAN_LIST_StartVBlankTask(p);
    ZUKAN_LIST_StartHBlankTask(p);
    return 3;
}

/*
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCDB6, 021BCDBA
 */
int ZUKAN_LIST_StateExit(struct ZukanList *p)
{
    if (ZUKAN_LIST_UpdateActorMove(p) == 1 || PALANM_GetFadeRequestBits(p->palAnm) != 0) return 1;
    ZUKAN_LIST_StopHBlankTask(p);
    ZUKAN_LIST_StopVBlankTask(p);
    ZUKAN_LIST_DisableSubWindows();
    ZUKAN_LIST_DeleteFrameList(p);
    ZUKAN_LIST_FreeFormTable(p);
    ZUKAN_LIST_ExitActors(p);
    ZUKAN_LIST_DeleteWindows(p);
    ZUKAN_LIST_DeleteFontAndPrinter(p);
    ZUKAN_LIST_ExitBgSystem();
    ZUKAN_LIST_ExitPaletteAnim(p);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    func_02034A5C((int)ov067_id);
    return 9;
}

int ZUKAN_LIST_StateWaitFade(struct ZukanList *p) { if(PALANM_GetFadeRequestBits(p->palAnm)==0)return p->fadeReturnState;return 2; }

/*
 * note: int step schedules the p copy before movs r6,16; enum step swaps those instructions (DIFF4).
 */
int ZUKAN_LIST_StateFadeIn(struct ZukanList *p)
{
    int step;
    switch (p->initPhase) {
    case 0:
        if (FRAME_LIST_UpdateInit((struct FrameList *)p->frameList) == 0) {
            ZUKAN_LIST_UpdateArrowActors(p, 0);
            ZUKAN_LIST_UpdateScrollBarActor(p);
            ZUKAN_LIST_HideAllActors(p);
            ZUKAN_LIST_ResetPaletteSlots(p);
            (p->initPhase)++;
        }
        break;
    case 1:
        if (PALANM_GetFadeRequestBits(p->palAnm) == 0) {
            GXx_SetMasterBrightness_((unsigned short *)0x0400006c, 0);
            GXx_SetMasterBrightness_((unsigned short *)0x0400106c, 0);
            ZUKAN_LIST_RequestFade(p, step = 16, 0);
            step -= 24;
            ZUKAN_LIST_StartActorMoveFrames(p, step);
            (p->initPhase)++;
        }
        break;
    case 2:
        if (ZUKAN_LIST_UpdateActorMove(p) == 0 && PALANM_GetFadeRequestBits(p->palAnm) == 0) {
            p->initPhase = 0;
            return 4;
        }
        break;
    }
    return 3;
}

/*
 * ov067 region follows the paired loader path 021BCC94/021BCD48.
 * 021B93D4's value is full width here: original subtract feeds r1 without narrowing.
 */
int ZUKAN_LIST_StateMain(struct ZukanList *p)
{
    int result=4;
    int selected;
    u32 action;
    u8 old;
    switch(FRAME_LIST_Update(p->frameList)){
    case -12: break;
    case -11:case -10:case -9:case -8:
        ZUKAN_LIST_UpdateArrowActors(p,0);break;
    case -7:
        ZUKAN_LIST_StartActorAnim(p,7,12);
        p->status.all=(p->status.all&~0xfffe)|14;p->scrollPhase=0;result=5;break;
    case -6:
        ZUKAN_LIST_StartActorAnim(p,6,13);
        p->status.all=(p->status.all&~0xfffe)|12;p->scrollPhase=0;result=5;break;
    case -5:return ZUKAN_LIST_StartButtonAnim(p,7,12,4);
    case -4:return ZUKAN_LIST_StartButtonAnim(p,6,13,4);
    case -3:case -2:
        ZUKAN_LIST_ShowAllActors(p);
        p->status.all=(p->status.all&~0xfffe)|120;p->scrollPhase=1;result=5;break;
    case -1:
        old=func_020355C4();
        action=ZUKAN_LIST_HandleTouchInput(p);
        switch(action){
        case 0:
            selected=FRAME_LIST_GetSelectedIndex(p->frameList);
            if(ZUKAN_LIST_IsSpeciesEntryValid(p,selected)==1){GFL_USE_PlaySeDefaultVolume(1356);return ZUKAN_LIST_StateSelectSpecies(p,selected);}
            func_020355D8(old);break;
        case 1:case 2:case 3:case 4:case 5:case 6:case 7:
            selected=action+FRAME_LIST_GetScrollPos(p->frameList)-1;
            if(ZUKAN_LIST_IsSpeciesEntryValid(p,selected)==1){
                GFL_USE_PlaySeDefaultVolume(1356);func_021B93D4(p->frameList,action-1);return ZUKAN_LIST_StateSelectSpecies(p,selected);
            }break;
        case 8:
            GFL_USE_PlaySeDefaultVolume(1356);p->args->state=4;
            ZUKAN_LIST_StoreLastViewedSpecies(p,FRAME_LIST_GetSelectedIndex(p->frameList));return ZUKAN_LIST_StartButtonAnim(p,9,4,8);
        case 9:
            GFL_USE_PlaySeDefaultVolume(1356);
            if(ZUKAN_SAVE_GetViewMode(p->args->save)==1)ZUKAN_SAVE_SetViewMode(p->args->save,0);else ZUKAN_SAVE_SetViewMode(p->args->save,1);
            p->args->state=2;
            ZUKAN_LIST_StoreLastViewedSpecies(p,FRAME_LIST_GetSelectedIndex(p->frameList));return ZUKAN_LIST_StartButtonAnim(p,8,5,8);
        case 10:GFL_USE_PlaySeDefaultVolume(1606);ZUKAN_LIST_ToggleSaveFlag15(p);break;
        case 11:
            GFL_USE_PlaySeDefaultVolume(1366);p->args->state=1;
            ZUKAN_LIST_StoreLastViewedSpecies(p,FRAME_LIST_GetSelectedIndex(p->frameList));return ZUKAN_LIST_StartButtonAnim(p,4,8,8);
        case 12:
            GFL_USE_PlaySeDefaultVolume(1361);p->args->state=0;
            ZUKAN_LIST_StoreLastViewedSpecies(p,FRAME_LIST_GetSelectedIndex(p->frameList));return ZUKAN_LIST_StartButtonAnim(p,3,9,8);
        case 13:
            GFL_USE_PlaySeDefaultVolume(1361);p->args->state=0;
            ZUKAN_LIST_StoreLastViewedSpecies(p,FRAME_LIST_GetSelectedIndex(p->frameList));return ZUKAN_LIST_StartButtonAnim(p,3,9,8);
        }
        break;
    default:
        selected=FRAME_LIST_GetSelectedIndex(p->frameList);ZUKAN_LIST_UpdateArrowActors(p,0);
        if(ZUKAN_LIST_IsSpeciesEntryValid(p,selected)==1){GFL_USE_PlaySeDefaultVolume(1356);return ZUKAN_LIST_StateSelectSpecies(p,selected);}
        break;
    }
    ZUKAN_LIST_UpdateScrollBarActor(p);ZUKAN_LIST_HideAllActors(p);return result;
}

int ZUKAN_LIST_StateScroll(struct ZukanList *p)
{
    switch (*(int *)&p->scrollPhase) {
    case 0:
        if (FRAME_LIST_Update((struct FrameList *)(p->frameList)) == -1) (*(int *)&p->scrollPhase)++;
        break;
    case 1:
        if (p->status.bits.animIdx == 60 || ZUKAN_LIST_IsActorAnimActive(p, p->status.bits.animIdx) == 0) {
            *(int *)&p->scrollPhase = 0;
            ZUKAN_LIST_UpdateArrowActors(p, 0);
            return 4;
        }
        break;
    }
    return 5;
}

int ZUKAN_LIST_StateScrollWait(struct ZukanList *p) { if(ZUKAN_LIST_IsActorAnimActive(p,p->status.bits.animIdx)==0){ZUKAN_LIST_UpdateArrowActors(p,0);return p->returnState;}return 6; }

/*
 * note: repeated decrement in each arm cross-jumps through branch stubs; explicit shared goto costs DIFF81/156.
 */
int ZUKAN_LIST_StateCursorFlash(struct ZukanList *p)
{
    switch (p->cursorFlashPhase) {
    case 0:
    case 2:
        if (p->cursorFlashTimer == 0) {
            FRAME_LIST_SetRowPalette((u8 *)(p->frameList), (unsigned short)FRAME_LIST_GetCursor(p->frameList), 1);
            p->cursorFlashTimer = 4;
            (p->cursorFlashPhase)++;
        } else (p->cursorFlashTimer)--;
        break;
    case 1:
    case 3:
        if (p->cursorFlashTimer == 0) {
            FRAME_LIST_SetRowPalette((u8 *)(p->frameList), (unsigned short)FRAME_LIST_GetCursor(p->frameList), 2);
            func_02041B6C(2);
            p->cursorFlashTimer = 4;
            (p->cursorFlashPhase)++;
        } else (p->cursorFlashTimer)--;
        break;
    case 4:
        if (p->cursorFlashTimer == 0) {
            p->cursorFlashPhase = 0;
            return 8;
        }
        (p->cursorFlashTimer)--;
        break;
    }
    return 7;
}

int ZUKAN_LIST_StateFadeOut(struct ZukanList *p) { ZUKAN_LIST_RequestFade(p,0,16);ZUKAN_LIST_StartActorMoveFrames(p,8);return 1; }

void ZUKAN_LIST_ResetPaletteSlots(struct ZukanList *p)
{
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)p->palAnm, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)p->palAnm, 1, 0, 512);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)p->palAnm, 2, 0, 512);
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)p->palAnm, 3, 0, 512);
    ZUKAN_LIST_RequestFade(p, 16, 16);
}

int ZUKAN_LIST_StartButtonAnim(struct ZukanList *p,int actorIndex,int animValue,int nextState) { ZUKAN_LIST_StartActorAnim(p,actorIndex,animValue);p->status.bits.animIdx=(u16)actorIndex;p->returnState=nextState;return 6; }

int ZUKAN_LIST_IsSpeciesEntryValid(struct ZukanList *p,int i) { if((FRAME_LIST_GetItemValue(p->frameList,i)&0xf0000000u)>>28)return 1;return 0; }

void ZUKAN_LIST_StoreLastViewedSpecies(struct ZukanList *p,int i) { if(ZUKAN_LIST_IsSpeciesEntryValid(p,i)==1)ZUKAN_SAVE_SetLastViewedSpecies(p->args->save,FRAME_LIST_GetItemValue(p->frameList,i)); }

int ZUKAN_LIST_StateSelectSpecies(struct ZukanList *a, int speciesIndex)
{
    ZUKAN_LIST_StoreLastViewedSpecies(a, speciesIndex);
    *(int *)(*(int *)&a->args + 0x10) = 3;
    return 7;
}

/*
 * extent: 021BD396 two-byte alignment padding before 021BD398.
 */
void ZUKAN_LIST_ToggleSaveFlag15(struct ZukanList *p)
{
    if (GAME_DATA_CheckSaveFlag(*(int *)p->args, 15) == 1) {
        GAME_DATA_SetSaveFlag(*(void **)p->args, 15, 0);
        ZUKAN_LIST_StartActorAnim(p, 5, 6);
    } else {
        GAME_DATA_SetSaveFlag(*(void **)p->args, 15, 1);
        ZUKAN_LIST_StartActorAnim(p, 5, 7);
    }
}

void ZUKAN_LIST_CreateWindows(struct ZukanList *p)
{
    unsigned i;
    BMP_WIN_Init(107);
    for (i = 0; i < 3; i++)
        *(unsigned *)&p->windows[i].bmp = BMP_WIN_Create(gZukanListWindowDefs[i][0], gZukanListWindowDefs[i][1], gZukanListWindowDefs[i][2], gZukanListWindowDefs[i][3], gZukanListWindowDefs[i][4], gZukanListWindowDefs[i][5], 1);
    ZUKAN_LIST_DrawHeaderRegional(p);
}

void ZUKAN_LIST_DeleteWindows(struct ZukanList *p) { u32 i;for(i=0;i<3;i++)BMP_WIN_Delete(*(struct Descriptor **)((u32)(char *)p+i*8+32));BMP_WIN_Exit(); }

/*
 * extent: 021BD43E..021BD440 is two zero alignment bytes before matched D440.
 * lever: first types search hoisted the initialized full-word ps load before entry arithmetic.
 * checks: 1 own C4E4, C6C4, 45770, 45334 bodies prove 1/2/1/1 arity; 2 ov0679344 and ov208C0740 confirm full-word handles; 3 carried two compiles exhausted; 4 carried two order/extraction probes exhausted; 5 fresh idioms/neighbours read, no stack object. Wave32 I4 pointer ps unchanged5; types search9 candidates exact after ps hoist, all inputs and call/store order preserved.
 */
void ZUKAN_LIST_FlushWindows(struct ZukanList *p)
{
    int ps;
    long i;
    PRINTSYS_QUE_Main((struct PrintSys *)p->printer);
    for (i = 0; i < 3u; i++) {
        ps = (int)p->printer;
        if (p->windows[i].pending) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)ps, BMP_WIN_GetBmp(p->windows[i].bmp)) == 0) {
                BMP_WIN_TransferChars(p->windows[i].bmp);
                p->windows[i].pending = 0;
            }
        }
    }
}

/*
 * extent: 021BD486 two-byte alignment padding before 021BD488.
 */
void ZUKAN_LIST_PrintTouchbarLabel(struct ZukanList *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode)
{
    void *text;
    text = func_02045EC0((struct MsgBank *)p->msgBank, msg);
    TOUCHBAR_PrintAligned((unsigned char *)&p->windows[index], (void *)(p->printer), x, y, (unsigned)text, *(unsigned *)&p->font, color, mode);
    STRBUF_Delete(text);
}

/*
 * extent: 021BD4DA two-byte alignment padding before existing labelled 021BD4DC.
 */
void ZUKAN_LIST_PrintTouchbarLabelClone(struct ZukanList *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode)
{
    void *text;
    text = func_02045EC0((struct MsgBank *)p->msgBank, msg);
    func_0201F250((struct WordSet *)p->wordSet, p->textBuf, text);
    TOUCHBAR_PrintAligned((unsigned char *)&p->windows[index], (void *)(p->printer), x, y, *(unsigned *)&p->textBuf, *(unsigned *)&p->font, color, mode);
    STRBUF_Delete(text);
}

void ZUKAN_LIST_MakeWindowScreens(void **p) {BMP_WIN_MakeScreen(*p);func_02041B6C(BMP_WIN_GetBgLayer(*p));}

void ZUKAN_LIST_ClearWindow(struct ZukanList *p, u32 idx)
{
    void *o2;
    void *o1;
    void *t2;
    u8 *gfx;
    void *t1;
    u8 *dst;
    u16 j;
    u8 *row;
    int y;
    int h;
    u8 w;
    int x;
    u8 *map;
    struct Descriptor **ent = &p->windows[0].bmp;
    void *arc;
    u16 i;

    w = BMP_WIN_GetDispWidth(*(struct Descriptor **)((u8 *)ent + idx * 8));
    h = BMP_WIN_GetDispHeight(*(struct Descriptor **)((u8 *)ent + idx * 8));
    x = BMP_WIN_GetPosX(*(struct Descriptor **)((u8 *)ent + idx * 8));
    y = BMP_WIN_GetPosY(*(struct Descriptor **)((u8 *)ent + idx * 8));
    dst = BMP_GetPixels(BMP_WIN_GetBmp(*(struct Descriptor **)((u8 *)ent + idx * 8)));
    arc = func_020490F4(0x9F, 0x6B);
    t1 = func_02049EF4(arc, 0x45, 0, &o1, 0x806B);
    map = (u8 *)o1 + 0xC;
    t2 = func_02049DF4(arc, 0x39, 0, (u32)(&o2), 0x806B);
    gfx = *(u8 **)((u8 *)o2 + 0x14);
    ARC_TOOL_DeleteHandle(arc);
    if (h > 0) {
        row = map + x * 2;
        j = 0;
        do {
            for (i = 0; i < w; i++) {
                u16 c = *(u16 *)(row + (y + j) * 64 + i * 2);
                MIi_CpuCopy32(gfx + (c & 0x3FF) * 32, dst + (i + j * w) * 32, 0x20);
            }
            j++;
        } while (j < h);
    }
    func_020307B0(t2);
    func_020307B0(t1);
}

void ZUKAN_LIST_DrawHeaderRegional(struct ZukanList *p)
{
    ZUKAN_LIST_ClearWindow(p, 0);
    if (ZUKAN_SAVE_GetViewMode(p->args->save) == 1)
        ZUKAN_LIST_PrintTouchbarLabel(p, 0, 1, 0, 4, 0x39e0, 0);
    else
        ZUKAN_LIST_PrintTouchbarLabel(p, 0, 0, 0, 4, 0x39e0, 0);
    ZUKAN_LIST_MakeWindowScreens((void **)&p->windows[0].bmp);
}

void ZUKAN_LIST_DrawHeaderCounts(struct ZukanList *p)
{
    unsigned a, b;
    if (ZUKAN_SAVE_GetViewMode(p->args->save) == 1) {
        a = ZUKAN_SAVE_CountSeenNational(p->args->save);
        b = ZUKAN_SAVE_CountCaughtNational(p->args->save);
    } else {
        a = ZUKAN_SAVE_CountSeenRegional(p->args->save, 0x806b);
        b = ZUKAN_SAVE_CountCaughtRegional(p->args->save, 0x806b);
    }
    ZUKAN_LIST_ClearWindow(p, 1);
    ZUKAN_LIST_ClearWindow(p, 2);
    ZUKAN_LIST_PrintTouchbarLabel(p, 1, 2, 0x48, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet * *)&p->wordSet, 0, a, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 1, 5, 0x68, 4, 0x31a0, 1);
    ZUKAN_LIST_PrintTouchbarLabel(p, 2, 3, 0x58, 4, 0x31a0, 1);
    func_0201EFA4(*(WordSet * *)&p->wordSet, 0, b, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 2, 5, 0x78, 4, 0x31a0, 1);
    ZUKAN_LIST_MakeWindowScreens((void **)&p->windows[1].bmp);
    ZUKAN_LIST_MakeWindowScreens((void **)&p->windows[2].bmp);
}

void ZUKAN_LIST_DrawHeaderNational(struct ZukanList *p)
{
    ZUKAN_LIST_ClearWindow(p, 2);
    ZUKAN_LIST_PrintTouchbarLabel(p, 2, 4, 88, 4, 0x31a0, 1);
    func_0201EFA4((struct WordSet *)p->wordSet, 0, p->args->count, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 2, 5, 120, 4, 0x31a0, 1);
    ZUKAN_LIST_MakeWindowScreens((void **)&p->windows[2].bmp);
}

void ZUKAN_LIST_PrintListRow(struct ZukanList *p, unsigned char *dest, unsigned text0, unsigned index)
{
    unsigned ps;
    void *text;
    ps = FRAME_LIST_GetPrinter(p->frameList);
    if (ZUKAN_SAVE_GetViewMode((struct Blk37 *)p->args->save) == 0)
        index = p->formTable[index];
    text = func_02045EC0((struct MsgBank *)p->msgBank, 8);
    func_0201EFA4((struct WordSet *)p->wordSet, 0, index, 3, 2, 1);
    func_0201F250((struct WordSet *)p->wordSet, p->textBuf, text);
    STRBUF_Delete(text);
    TOUCHBAR_PrintAligned(dest, (void *)ps, 0, 4, *(unsigned *)&p->textBuf, (unsigned)p->font, 0x39e0, 0);
    TOUCHBAR_PrintAligned(dest, (void *)ps, 28, 4, text0, (unsigned)p->font, 0x39e0, 0);
}

void ZUKAN_LIST_InitActors(struct ZukanList *p) {ZUKAN_LIST_InitActorSystem(p);ZUKAN_LIST_LoadActorResources(p);ZUKAN_LIST_CreateActors(p);ZUKAN_LIST_UpdateSpeciesActors(p);BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);}

void ZUKAN_LIST_ExitActors(struct ZukanList *list)
{
    ZUKAN_LIST_DeleteActorUnit(list);
    ZUKAN_LIST_ReleaseActorResources(list);
    CLACT_ExitSystem();
}

void ZUKAN_LIST_UpdateActors(struct ZukanList *p) {u32 i;for(i=0;i<60;i++) {if(p->actors[i]) {if(CLACT_GetActorAutoAnim((struct Actor *)p->actors[i])!=1) CLACT_AddActorAnimFrame(p->actors[i],0x1000);}}CLACT_DrawSystem();}

void ZUKAN_LIST_SetActorAnim(struct ZukanList *p, int idx, int v)
{
    CLACT_SetActorAnimFrame(*(void **)((char *)p + 0xa74 + idx * 4), 0);
    CLACT_SetActorAnimSeq(*(void **)((char *)p + 0xa74 + idx * 4), (unsigned short)v);
}

void ZUKAN_LIST_StartActorAnim(struct ZukanList *p,int idx,int value) {ZUKAN_LIST_SetActorAnim(p,idx,value);CLACT_SetActorAutoAnim((struct Obj *)(struct Actor *)p->actors[idx],1);}

int ZUKAN_LIST_GetActorAnimSeq(struct ZukanList *a, int actorIndex)
{
    return CLACT_GetActorAnimSeq((struct Obj *)(int)a->actors[actorIndex]);
}

u32 ZUKAN_LIST_IsActorAnimActive(struct ZukanList *p,u32 idx) {return CLACT_IsActorAnimActive((struct Actor *)p->actors[idx]);}

void ZUKAN_LIST_SetActorVisible(struct ZukanList *p,u32 idx,u32 value) {struct Obj *o;o=p->actors[idx];if(o) CLACT_SetActorDrawEnable(o,value);}

u32 ZUKAN_LIST_GetActorVisible(struct ZukanList *p,u32 idx) {return CLACT_GetActorDrawEnable(p->actors[idx]);}

void ZUKAN_LIST_SetActorObjMode(struct ZukanList *p,u32 idx,u32 flag) {if(flag==1) CLACT_SetActorObjMode((struct Actor *)p->actors[idx],1);else CLACT_SetActorObjMode((struct Actor *)p->actors[idx],0);}

void ZUKAN_LIST_AddActorPos(struct ZukanList *p, int idx, short x, short y, unsigned short surface)
{
    unsigned short buf[2];
    buf[0] = x;
    buf[1] = y;
    CLACT_AddActorSurfacePos((void *)p->actors[idx], (const struct Vec2 *)buf, surface);
}

/*
 * prototype: outgoing space argument is loaded by ldrh at 021BD966; callee extern uses u16 for the observed bits.
 */
void ZUKAN_LIST_GetActorPos(struct ZukanList *p,u32 idx,s16 *x,s16 *y,u16 space) {PtS point;CLACT_GetActorSurfacePos((struct Actor *)p->actors[idx],&point,space);*x=point.x;*y=point.y;}

void ZUKAN_LIST_InitActorSystem(struct ZukanList *p) {struct ClactInit t;t=gZukanListClactInit;CLACT_InitSystem((const struct Cfg *)&t,(u32)ZUKAN_LIST_GetVramBankConfig(),107);}

void ZUKAN_LIST_LoadActorResources(struct ZukanList *p)
{
    int h, h2, h3;
    u32 i;
    u32 k;
    u32 a;
    int *arr;
    int *pb;
    int *pc;

    for (k = 0; k < 0x24; k++) p->charHandles[k] = -1;
    for (k = 0; k < 6; k++) p->paletteHandles[k] = -1;
    for (k = 0; k < 6; k++) p->cellAnimHandles[k] = -1;

    h = (int)func_020490F4(0x9f, 0x806B);
    p->charHandles[0x23] = CLACT_RegisterCharacter((void *)h, 0x37, 0, 0, 0x6b);
    p->paletteHandles[5] = CLACT_RegisterPalette((void *)h, 0x33, 0, 0, 0x6b);
    p->cellAnimHandles[5] = CLACT_RegisterCellAnim((void *)h, 0x3d, 0x47, 0x6b);
    ARC_TOOL_DeleteHandle((void *)h);

    h2 = (int)func_020490F4(7, 0x806B);
    arr = (int *)p->charHandles;
    pb = (int *)&p->paletteHandles[0];
    pc = (int *)&p->cellAnimHandles[0];
    for (i = 0; i < 0x10; i++)
        arr[i] = CLACT_RegisterCharacter((void *)h2, POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0), 0, 0, 0x6b);
    *pb = CLACT_RegisterPaletteCompressed((void *)h2, func_0201BC3C(), 0, 0x80, 0x6b);
    a = func_0201BC40();
    *pc = CLACT_RegisterCellAnim((void *)h2, a, func_0201BCB4(), 0x6b);

    arr = (int *)&p->charHandles[0x10];
    pb = (int *)&p->paletteHandles[1];
    pc = (int *)&p->cellAnimHandles[1];
    for (i = 0; i < 0x10; i++)
        arr[i] = CLACT_RegisterCharacter((void *)h2, POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0), 0, 1, 0x6b);
    *pb = CLACT_RegisterPaletteCompressed((void *)h2, func_0201BC3C(), 1, 0, 0x6b);
    a = func_0201BC78();
    *pc = CLACT_RegisterCellAnim((void *)h2, a, func_0201BCEC(), 0x6b);
    ARC_TOOL_DeleteHandle((void *)h2);

    h3 = (int)func_020490F4(func_020275E4(), 0x806B);
    p->charHandles[0x22] = CLACT_RegisterCharacter((void *)h3, func_02027618(), 0, 0, 0x6b);
    p->paletteHandles[4] = CLACT_RegisterPalette((void *)h3, func_02027614(), 0, 0xe0, 0x6b);
    a = func_0202761C(2);
    p->cellAnimHandles[4] = CLACT_RegisterCellAnim((void *)h3, a, func_02027620(2), 0x6b);
    ARC_TOOL_DeleteHandle((void *)h3);
}

void ZUKAN_LIST_ReleaseActorResources(struct ZukanList *p)
{
    unsigned i;
    for(i=0;i<36;i++)if(p->charHandles[i]!=-1)CLACT_ReleaseCharacter(p->charHandles[i]);
    for(i=0;i<6;i++)if(p->paletteHandles[i]!=-1)CLACT_ReleasePalette(p->paletteHandles[i]);
    for(i=0;i<6;i++)if(p->cellAnimHandles[i]!=-1)CLACT_ReleaseCellAnim(p->cellAnimHandles[i]);
}

void ZUKAN_LIST_CreateActors(struct ZukanList *p)
{
    unsigned i;
    struct ClactActorDesc t;
    p->clactUnit = CLACT_CreateUnit(60, 0, 0x6b);
    for (i = 0; i < 60; i++)
        p->actors[i] = 0;
    for (i = 0; i <= 9; i++) {
        t = gZukanListActorDescTable[i];
        t.charIndex = p->charHandles[t.charIndex];
        t.palIndex = p->paletteHandles[t.palIndex];
        t.animIndex = p->cellAnimHandles[t.animIndex];
        p->actors[i] = ZUKAN_CreateActor((u32)(p->clactUnit), (const u8 *)(&t), 0x6b);
        CLACT_SetActorVisible((void *)p->actors[i], 0);
    }
    if (p->args->count <= 7) {
        ZUKAN_LIST_SetActorVisible(p, 0, 0);
        ZUKAN_LIST_SetActorVisible(p, 1, 0);
    }
    if (ZUKAN_SAVE_GetDexObtained(p->args->save) == 0)
        ZUKAN_LIST_SetActorVisible(p, 9, 0);
    if (ZUKAN_SAVE_IsNationalDexEnabled(p->args->save) == 0)
        ZUKAN_LIST_SetActorVisible(p, 8, 0);
    if (p->args->mode == 1) {
        ZUKAN_LIST_SetActorVisible(p, 8, 0);
        ZUKAN_LIST_SetActorVisible(p, 5, 0);
    } else if (GAME_DATA_CheckSaveFlag(*(int *)p->args, 15) == 1)
        ZUKAN_LIST_StartActorAnim(p, 5, 7);
}

void ZUKAN_LIST_DeleteActor(struct ZukanList *p,u32 idx) {char *base;u32 offset;offset=idx*4;base=(char *)p+0xa74;if(*(struct Obj **)(base+offset)) {CLACT_DeleteActor(*(struct Obj **)(base+offset));*(struct Obj **)(base+offset)=0;}}

void ZUKAN_LIST_DeleteActorUnit(struct ZukanList *p) {u32 i;for(i=0;i<60;i++) ZUKAN_LIST_DeleteActor(p,i);CLACT_DeleteUnit((struct Bank *)p->clactUnit);}

void ZUKAN_LIST_LoadSpeciesIcon(struct ZukanList *p,u16 species)
{
    struct ClactActorDesc t;
    unsigned out1,outForm,out2;
    unsigned other,index,base;
    void *personal;
    t=gZukanListActorDesc;
    if (p->status.bits.side==0) {
        other=59; index=58; base=0x160;
    } else {
        other=58; index=59;
        t.charIndex=33; t.palIndex=3; t.animIndex=3;
        base=0x180;
    }
    if (*(unsigned *)((char *)p+0xa74+index*4)!=0) {
        ZUKAN_LIST_DeleteActor(p,index);
        if (*(unsigned *)((char *)p+t.charIndex*4+0xb64)!=(unsigned)-1)
            CLACT_ReleaseCharacter(*(unsigned *)((char *)p+t.charIndex*4+0xb64));
        if (*(unsigned *)((char *)p+t.palIndex*4+0xbf4)!=(unsigned)-1)
            CLACT_ReleasePalette(*(unsigned *)((char *)p+t.palIndex*4+0xbf4));
        if (*(unsigned *)((char *)p+t.animIndex*4+0xc0c)!=(unsigned)-1)
            CLACT_ReleaseCellAnim(*(unsigned *)((char *)p+t.animIndex*4+0xc0c));
    }
    if (species==0) {
        void *arc;
        arc=func_020490F4(0x9f,0x806b);
        *(unsigned *)((char *)p+t.charIndex*4+0xb64)=CLACT_RegisterCharacter(arc,0x36,0,0,0x6b);
        *(unsigned *)((char *)p+t.palIndex*4+0xbf4)=CLACT_RegisterPaletteEx(arc,0x32,0,(u16)base,0,1,0x6b);
        *(unsigned *)((char *)p+t.animIndex*4+0xc0c)=CLACT_RegisterCellAnim(arc,0x3c,0x46,0x6b);
        ARC_TOOL_DeleteHandle(arc);
        ZUKAN_LIST_SetActorVisible(p,2,0);
    } else {
        void *arc;
        unsigned personality;
        ZUKAN_SAVE_GetViewGenderAndForm(*(u8 * *)&p->args->save,species,&out1,&out2,&outForm,0x806b);
        arc=(void *)POKEGRA_OpenHandle(0x806b);
        personality=species==0x147?ZUKAN_SAVE_GetSpindaPersonality(p->args->save,0):0;
        *(unsigned *)((char *)p+t.charIndex*4+0xb64)=POKEGRA_RegisterCgr((u32)arc,species,outForm,out1,out2,0,0,personality,0,0x6b);
        *(unsigned *)((char *)p+t.palIndex*4+0xbf4)=POKEGRA_RegisterPalette((int)arc,species,outForm,out1,out2,0,0,0,base,0x6b);
        *(unsigned *)((char *)p+t.animIndex*4+0xc0c)=POKEGRA_RegisterCellAnim(species,outForm,out1,out2,0,0,2,0,0x6b);
        ARC_TOOL_DeleteHandle(arc);
        ZUKAN_LIST_SetActorVisible(p,2,1);
    }
    t.charIndex=*(unsigned *)((char *)p+t.charIndex*4+0xb64);
    t.palIndex=*(unsigned *)((char *)p+t.palIndex*4+0xbf4);
    t.animIndex=*(unsigned *)((char *)p+t.animIndex*4+0xc0c);
    *(void **)((char *)p+0xa74+index*4)=ZUKAN_CreateActor((u32)(p->clactUnit),(const u8 *)(&t),0x6b);
    CLACT_SetActorVisible(*(void **)((char *)p+0xa74+index*4),0);
    personal=POKE_PERSONAL_Create(species,(u16)outForm,0x806b);
    if (species!=0 && POKE_PERSONAL_GetParam(personal,0x22)==0)
        CLACT_SetActorFlip(*(void **)((char *)p+0xa74+index*4),1,1);
    POKE_PERSONAL_Delete(personal);
    ZUKAN_LIST_SetActorVisible(p,other,0);
    PALANM_CopyHwPaletteToSlot(p->palAnm,2,(u16)((base>>5)<<4),0x20);
    p->status.bits.side^=1;
}

void ZUKAN_LIST_UpdateSpeciesActors(struct ZukanList *p) {
    struct ClactSpeciesActor a;
    struct ClactSpeciesActor b;
    u32 *pb;
    u32 i;
    u32 j;
    u32 k;
    a = gZukanListSpeciesActor;
    b = gZukanListSpeciesActor;
    b.palHandle = *(u32 *)((char *)p + 0xBF4);
    b.animHandle = *(u32 *)((char *)p + 0xC0C);
    for (i = 0; i < 16; i++) {
        b.posY = i * 0x18 + 8;
        b.charHandle = *(u32 *)((char *)p + i * 4 + 0xB64);
        *(u32 *)((char *)p + i * 4 + 0xA9C) = (u32)ZUKAN_CreateActor(*(u32 *)((char *)p + 0xA70), (const u8 *)(&b), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)((char *)p + i * 4 + 0xA9C)), 0);
    }
    b = a;
    b.palHandle = *(u32 *)((char *)p + 0xBF8);
    b.animHandle = *(u32 *)((char *)p + 0xC10);
    for (j = 0; j < 16; j++) {
        b.posY = j * 0x18 + 0x20;
        b.charHandle = *(u32 *)((char *)p + j * 4 + 0xBA4);
        b.flags = 1;
        *(u32 *)((char *)p + j * 4 + 0xADC) = (u32)ZUKAN_CreateActor(*(u32 *)((char *)p + 0xA70), (const u8 *)(&b), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)((char *)p + j * 4 + 0xADC)), 0);
        ZUKAN_LIST_SetActorObjMode(p, j + 0x1a, 1);
        pb = (u32 *)((char *)p + 0xA70);
        *(u32 *)((char *)p + j * 4 + 0xB1C) = (u32)ZUKAN_CreateActor(*pb, (const u8 *)(&b), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)((char *)p + j * 4 + 0xB1C)), 0);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)((char *)p + j * 4 + 0xB1C)), 2);
    }
    for (k = 0; k < 16; k++) ZUKAN_LIST_SetActorVisible(p, k + 0xa, 0);
    for (i = 0; i < 16; i++) {
        ZUKAN_LIST_SetActorVisible(p, i + 0x1a, 0);
        ZUKAN_LIST_SetActorVisible(p, i + 0x2a, 0);
    }
}

void ZUKAN_LIST_TransferSpeciesGraphics(struct ZukanList *p, int actorIndex, unsigned species, u16 form, u16 charHalf, int mode)
{
    void *owner;
    void *data;
    struct ClactPartData *out;
    struct Obj **slot;
    unsigned saved;
    owner=func_020490F4(7,0x806b);
    saved=charHalf;
    data=func_02049E74((void *)((unsigned)owner),POKE_TOOL_CalcGraphicIndex(species,form,saved,0),0,(unsigned)&out,0x806b);
    if (mode==1) {
        slot=&p->actors[actorIndex];
        CLACT_TransferCharacterPart(CLACT_GetActorCharacterIndex((u8 *)*slot),out->part,1024,0,0);
    } else {
        slot=&p->actors[actorIndex];
        CLACT_TransferCharacterPart(CLACT_GetActorCharacterIndex((u8 *)*slot),out->part,1024,0,1);
    }
    func_020307B0(data);
    ARC_TOOL_DeleteHandle(owner);
    CLACT_SetActorPaletteOffset(*slot,POKE_TOOL_CalcIconPalette(species,form,saved,0),1);
}

int ZUKAN_LIST_IsActorHidden(struct ZukanList *list, int group)
{
    unsigned int i;

    if (group == 1) {
        for (i = 0xa; i < 0x1a; i++) {
            if (ZUKAN_LIST_GetActorVisible(list, i) == 0) {
                return i;
            }
        }
    } else {
        for (i = 0x1a; i < 0x2a; i++) {
            if (ZUKAN_LIST_GetActorVisible(list, i) == 0) {
                return i;
            }
        }
    }
    return 0;
}

/*
 * Enum position preserves the full-width update and repeated signed-halfword argument conversions.
 */
void ZUKAN_LIST_ShowSpeciesActor(struct ZukanList *p,u16 species,enum Position pos,int mode)
{
    unsigned out1,outForm,out2;
    int index;
    ZUKAN_SAVE_GetViewGenderAndForm((u8 *)p->args->save,species,&out1,&out2,&outForm,0x806b);
    index=ZUKAN_LIST_IsActorHidden(p,mode);
    ZUKAN_LIST_TransferSpeciesGraphics(p,index,species,outForm,out1,mode);
    ZUKAN_LIST_SetActorVisible(p,index,1);
    ZUKAN_LIST_StartActorAnim(p,index,0);
    if (mode==1) {
        pos+=8;
        ZUKAN_LIST_AddActorPos(p,index,112,pos,0);
        return;
    }
    pos+=8;
    ZUKAN_LIST_AddActorPos(p,index,112,pos,1);
    ZUKAN_LIST_AddActorPos(p,index+16,112,pos,1);
    index+=16;
    ZUKAN_LIST_SetActorVisible(p,index,1);
}

void ZUKAN_LIST_ScrollActorsBy(struct ZukanList *p, int delta)
{
    unsigned i;
    short pos[2];
    for (i = 10; i < 26; i++) {
        if (ZUKAN_LIST_GetActorVisible(p, i) != 0) {
            ZUKAN_LIST_GetActorPos(p, i, &pos[1], &pos[0], 0);
            ZUKAN_LIST_AddActorPos(p, (unsigned)i, (short)pos[1], (short)(pos[0] + delta), 0);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200)
                ZUKAN_LIST_SetActorVisible(p, i, 0);
        }
    }
    for (i = 26; i < 42; i++) {
        if (ZUKAN_LIST_GetActorVisible(p, i) != 0) {
            ZUKAN_LIST_GetActorPos(p, i, &pos[1], &pos[0], 1);
            ZUKAN_LIST_AddActorPos(p, (unsigned)i, (short)pos[1], (short)(pos[0] + delta), 1);
            ZUKAN_LIST_AddActorPos(p, (unsigned)(i + 16), (short)pos[1], (short)(pos[0] + delta), 1);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200) {
                ZUKAN_LIST_SetActorVisible(p, i, 0);
                ZUKAN_LIST_SetActorVisible(p, i + 16, 0);
            }
        }
    }
}

void ZUKAN_LIST_HideAllActors(struct ZukanList *p)
{
    unsigned i;
    p->hiddenMaskA=0;
    p->hiddenMaskB=0;
    for(i=10;i<26;i++)if(ZUKAN_LIST_GetActorVisible(p,i))p->hiddenMaskA|=(u16)(1<<(i-10));
    for(i=26;i<42;i++)if(ZUKAN_LIST_GetActorVisible(p,i))p->hiddenMaskB|=(u16)(1<<(i-26));
}

void ZUKAN_LIST_ShowAllActors(struct ZukanList *p)
{
    unsigned i;
    for(i=10;i<26;i++)if(p->hiddenMaskA&(1<<(i-10)))ZUKAN_LIST_SetActorVisible(p,i,0);
    for(i=26;i<42;i++)if(p->hiddenMaskB&(1<<(i-26))){ZUKAN_LIST_SetActorVisible(p,i,0);ZUKAN_LIST_SetActorVisible(p,i+16,0);}
    p->hiddenMaskA=0;
    p->hiddenMaskB=0;
}

/*
 * Row expression assigned back to index keeps the entry register; 021BE586 is two zero alignment bytes.
 */
void ZUKAN_LIST_MoveCursorActor(struct ZukanList *p,int index)
{
    unsigned i;
    short pos[2];
    index=index*24+8;
    for(i=10;i<26;i++){
        if(ZUKAN_LIST_GetActorVisible(p,i)==0)ZUKAN_LIST_StartActorAnim(p,i,0);
        else{
            ZUKAN_LIST_GetActorPos(p,i,&pos[1],&pos[0],0);
            if(index==pos[0]){if(ZUKAN_LIST_GetActorAnimSeq(p,i)!=1)ZUKAN_LIST_StartActorAnim(p,i,1);}
            else ZUKAN_LIST_StartActorAnim(p,i,0);
        }
    }
}

void ZUKAN_LIST_UpdateScrollBarActor(struct ZukanList *p)
{
    short pos[2];
    unsigned value;
    ZUKAN_LIST_GetActorPos(p,0,&pos[1],&pos[0],0);
    value=FRAME_LIST_ClampToScrollBar((struct FrameList *)p->frameList,pos[0]);
    if(value<12)value=12;else if(value>156)value=156;
    ZUKAN_LIST_AddActorPos(p,0,(short)252,(short)value,0);
}

void ZUKAN_LIST_UpdateArrowActors(struct ZukanList *p,int flag)
{
    int n=FRAME_LIST_GetCursor(p->frameList);
    if (ZUKAN_LIST_GetActorAnimSeq(p,7)!=12 || flag==0) {
        if (FRAME_LIST_GetScrollPos(p->frameList)==0 && n==0)
            ZUKAN_LIST_StartActorAnim(p,7,18);
        else ZUKAN_LIST_StartActorAnim(p,7,4);
    }
    if (ZUKAN_LIST_GetActorAnimSeq(p,6)!=13 || flag==0) {
        if (FRAME_LIST_CanScrollDown(p->frameList)==0 && n==p->rowCount-1) {
            ZUKAN_LIST_StartActorAnim(p,6,19);
            return;
        }
        else ZUKAN_LIST_StartActorAnim(p,6,5);
    }
}

extern int TOUCHPANEL_HitTrg(const void *p);

extern u32 KEY_GetTrg(void);

extern void FRAME_LIST_HideCursor(u32);

extern int func_021B940C(u8 *p);

int ZUKAN_LIST_HandleTouchInput(struct ZukanList *p)
{
    int v = TOUCHPANEL_HitTrg((void *)0x021BEAE0);

    if (v != -1) {
        if (v == 8) {
            if (ZUKAN_SAVE_GetDexObtained(p->args->save) == 0)
                return -1;
        }
        if (v == 9) {
            if (ZUKAN_SAVE_IsNationalDexEnabled(p->args->save) == 0)
                return -1;
            if (p->args->mode == 1)
                return -1;
        }
        if (v == 0xa) {
            if (p->args->mode == 1)
                return -1;
            if (func_020355C4() == 0) {
                func_020355D8(1);
                FRAME_LIST_HideCursor((u32)p->frameList);
            }
        }
        func_020355D8(1);
        return v;
    } else {
        if (KEY_GetTrg() & 2) {
            func_020355D8(0);
            return 0xc;
        }
        if (KEY_GetTrg() & 0x400) {
            func_020355D8(0);
            return 0xb;
        }
        if (KEY_GetTrg() & 8) {
            if (ZUKAN_SAVE_GetDexObtained(p->args->save) == 1) {
                func_020355D8(0);
                return 8;
            }
        }
        if (KEY_GetTrg() & 4) {
            if (ZUKAN_SAVE_IsNationalDexEnabled(p->args->save) == 0)
                return -1;
            if (p->args->mode == 1)
                return -1;
            func_020355D8(0);
            return 9;
        }
        if (KEY_GetTrg() & 0x800) {
            if (p->args->mode == 1)
                return -1;
            if (func_020355C4() == 1) {
                func_020355D8(0);
                func_021B940C((u8 *)((u32)p->frameList));
            } else {
                func_020355D8(0);
            }
            return 0xa;
        }
        return v;
    }
}
