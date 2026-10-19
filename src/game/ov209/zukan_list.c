/*
 * file:     zukan_list.c
 * unit:     yes
 * function: ZUKAN_LIST_ProcInit, ZUKAN_LIST_ProcMain, ZUKAN_LIST_ProcExit, ZUKAN_LIST_StartVBlankTask, ZUKAN_LIST_StopVBlankTask, ZUKAN_LIST_VBlankTask, ZUKAN_LIST_StartHBlankTask, ZUKAN_LIST_StopHBlankTask, ZUKAN_LIST_HBlankTask, ZUKAN_LIST_SetVramBanks, ZUKAN_LIST_GetVramBankConfig, ZUKAN_LIST_InitBgSystem, ZUKAN_LIST_ExitBgSystem, ZUKAN_LIST_LoadBgGraphics, ZUKAN_LIST_InitPaletteAnim, ZUKAN_LIST_ExitPaletteAnim, ZUKAN_LIST_RequestFade, ZUKAN_LIST_SetSubScreenBlendAlpha, ZUKAN_LIST_EnableSubWindows, ZUKAN_LIST_DisableSubWindows, ZUKAN_LIST_CreateFontAndPrinter, ZUKAN_LIST_DeleteFontAndPrinter, ZUKAN_LIST_LoadFormTable, ZUKAN_LIST_FreeFormTable, ZUKAN_LIST_MoveScrollBarActorsIn, ZUKAN_LIST_StartActorMoveFrames, ZUKAN_LIST_UpdateActorMove, ZUKAN_LIST_CreateFrameList, ZUKAN_LIST_DeleteFrameList, ZUKAN_LIST_FrameListMoveCallback, ZUKAN_LIST_FrameListSelectCallback, ZUKAN_LIST_ScrollByDelta, ZUKAN_LIST_RunState, ZUKAN_LIST_StateInit, ZUKAN_LIST_StateExit, ZUKAN_LIST_StateWaitFade, ZUKAN_LIST_StateFadeIn, ZUKAN_LIST_StateMain, ZUKAN_LIST_StateScroll, ZUKAN_LIST_StateScrollWait, ZUKAN_LIST_StateCursorFlash, ZUKAN_LIST_StateFadeOut, ZUKAN_LIST_ResetPaletteSlots, ZUKAN_LIST_StartButtonAnim, ZUKAN_LIST_IsSpeciesEntryValid, ZUKAN_LIST_StoreLastViewedSpecies, ZUKAN_LIST_StateSelectSpecies, ZUKAN_LIST_ToggleSaveFlag15, ZUKAN_LIST_CreateWindows, ZUKAN_LIST_DeleteWindows, ZUKAN_LIST_FlushWindows, ZUKAN_LIST_PrintTouchbarLabel, ZUKAN_LIST_PrintTouchbarLabelClone, ZUKAN_LIST_MakeWindowScreens, ZUKAN_LIST_ClearWindow, ZUKAN_LIST_DrawHeaderRegional, ZUKAN_LIST_DrawHeaderCounts, ZUKAN_LIST_DrawHeaderNational, ZUKAN_LIST_PrintListRow, ZUKAN_LIST_InitActors, ZUKAN_LIST_ExitActors, ZUKAN_LIST_UpdateActors, ZUKAN_LIST_SetActorAnim, ZUKAN_LIST_StartActorAnim, ZUKAN_LIST_GetActorAnimSeq, ZUKAN_LIST_IsActorAnimActive, ZUKAN_LIST_SetActorVisible, ZUKAN_LIST_GetActorVisible, ZUKAN_LIST_SetActorObjMode, ZUKAN_LIST_AddActorPos, ZUKAN_LIST_GetActorPos, ZUKAN_LIST_InitActorSystem, ZUKAN_LIST_LoadActorResources, ZUKAN_LIST_ReleaseActorResources, ZUKAN_LIST_CreateActors, ZUKAN_LIST_DeleteActor, ZUKAN_LIST_DeleteActorUnit, ZUKAN_LIST_LoadSpeciesIcon, ZUKAN_LIST_UpdateSpeciesActors, ZUKAN_LIST_TransferSpeciesGraphics, ZUKAN_LIST_FindHiddenSpeciesActor, ZUKAN_LIST_ShowSpeciesActor, ZUKAN_LIST_ScrollActorsBy, ZUKAN_LIST_HideAllActors, ZUKAN_LIST_ShowAllActors, ZUKAN_LIST_MoveCursorActor, ZUKAN_LIST_UpdateScrollBarActor, ZUKAN_LIST_UpdateArrowActors, ZUKAN_LIST_HandleTouchInput
 * address:  0x021BC240
 * region:   ov209
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from zukan_list.c, ZUKAN_LIST_HandleTouchInput.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   PALANM_TransferPalettes 0x02021D50 thumb
 *   GFL_USE_AddHBlankTask 0x02005624 thumb
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   gZukanListVramBankConfig 0x021BE7D4 data a4
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   BG_SYS_MarkTileDirty 0x02041B6C arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   gZukanListDisplayConfig 0x021BE804 data a4
 *   gZukanListBgTemplateLayer0 0x021BE894 data a4
 *   gZukanListBgTemplateLayer1 0x021BE874 data a4
 *   gZukanListBgTemplateLayer2 0x021BE814 data a4
 *   gZukanListBgTemplateLayer3 0x021BE8F4 data a4
 *   gZukanListBgTemplateLayer4 0x021BE8B4 data a4
 *   gZukanListBgTemplateLayer5 0x021BE854 data a4
 *   gZukanListBgTemplateLayer6 0x021BE8D4 data a4
 *   gZukanListBgTemplateLayer7 0x021BE834 data a4
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm
 *   BG_SYS_Delete  0x0203F9B4  arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   APP_ICON_GetArchiveId 0x020275E4 thumb
 *   APP_ICON_GetStatusFrameFileId 0x02027628 thumb
 *   APP_ICON_GetStatusAnimFileId 0x02027624 thumb
 *   APP_ICON_GetStatusDataFileId 0x0202762C thumb
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   PALANM_Create 0x02021518 thumb
 *   PALANM_AllocSlotBuffers 0x0202155C thumb
 *   PALANM_FreeSlotBuffers 0x020215A0 thumb
 *   PALANM_Delete 0x02021540 thumb
 *   GFL_USE_GetMainTaskList 0x020056BC thumb
 *   PALANM_RequestFade 0x0202173C thumb
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   POKE_PERSONAL_LoadFormTable 0x0201AF80 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   ZUKAN_SAVE_GetLastViewedSpecies 0x0200CA8C thumb
 *   FRAME_LIST_Create 0x021B7754 thumb ov067
 *   FRAME_LIST_CopyMapToBuffer 0x021B7A10 thumb ov067
 *   FRAME_LIST_LoadPalettes 0x021B7A4C thumb ov067
 *   FRAME_LIST_AddItem 0x021B79E4 thumb ov067
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_IsSeen 0x0200D064 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   STRBUF_Clone 0x02045874 arm
 *   gZukanListFrameListParams 0x021BE7AC data a4
 *   gSpeciesNameBank 0x020A7370 data a4
 *   FRAME_LIST_Delete 0x021B796C thumb ov067
 *   FRAME_LIST_GetItemValue 0x021B9398 thumb ov067
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   gZukanListStateHandlers 0x021BE96C data a4
 *   ZUKAN_TickCounter 0x021C93E4 thumb ov212
 *   ov067_id 0x00000043 data a1
 *   GF_OVERLAY_Load 0x02034AC4 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   GXx_SetMasterBrightness_ 0x0207D534 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   PALANM_GetFadeRequestBits 0x02021ED8 thumb
 *   FRAME_LIST_UpdateInit 0x021B7A64 thumb ov067
 *   FRAME_LIST_Update 0x021B7AB0 thumb ov067
 *   ZUKAN_LIST_HandleTouchInput 0x021BE658 thumb ov209
 *   FRAME_LIST_GetSelectedIndex 0x021B93A4 thumb ov067
 *   FRAME_LIST_SetCursor 0x021B93D4 thumb ov067
 *   UI_GetInputMode 0x020355C4 arm
 *   UI_SetInputMode 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   ZUKAN_SAVE_GetViewMode 0x0200CA70 thumb
 *   ZUKAN_SAVE_SetViewMode 0x0200CA5C thumb
 *   FRAME_LIST_SetRowPalette 0x021B9280 thumb ov067
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 *   ZUKAN_SAVE_SetLastViewedSpecies 0x0200CA78 thumb
 *   GAME_DATA_ContainsRecentId 0x02012BF8 thumb
 *   GAME_DATA_SetRecentId 0x02012BE0 thumb
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
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_GetDispWidth 0x02045748 arm
 *   BMP_WIN_GetDispHeight 0x02045750 arm
 *   BMP_WIN_GetPosX 0x02045758 arm
 *   BMP_WIN_GetPosY 0x02045760 arm
 *   BMP_GetPixels 0x020437D4 arm
 *   ARC_UTIL_LoadPaletteDataFromHandle 0x02049EF4 arm
 *   ARC_UTIL_LoadBgCharDataFromHandle 0x02049DF4 arm
 *   MIi_CpuCopy32 0x02082A90 arm
 *   ZUKAN_SAVE_CountSeenNational 0x0200D0CC thumb
 *   ZUKAN_SAVE_CountCaughtNational 0x0200CF28 thumb
 *   ZUKAN_SAVE_CountSeenRegional 0x0200D0F8 thumb
 *   ZUKAN_SAVE_CountCaughtRegional 0x0200CF54 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
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
 *   POKE_TOOL_GetIconPaletteArcId 0x0201BC3C thumb
 *   POKE_TOOL_GetIconCellArcId 0x0201BC40 thumb
 *   POKE_TOOL_GetIconCellArcIdSub 0x0201BC78 thumb
 *   POKE_TOOL_GetIconCellEntryId 0x0201BCB4 thumb
 *   POKE_TOOL_GetIconCellEntryIdSub 0x0201BCEC thumb
 *   APP_ICON_GetMoveKindPaletteFileId 0x02027614 thumb
 *   APP_ICON_GetMoveKindAnimFileId 0x02027618 thumb
 *   APP_ICON_GetStatusCellFileId 0x0202761C thumb
 *   APP_ICON_GetStatusPaletteFileId 0x02027620 thumb
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
 *   ARC_UTIL_LoadScreenDataFromHandle 0x02049E74 arm
 *   CLACT_GetActorCharacterIndex 0x0204B7F0 arm
 *   CLACT_TransferCharacterPart 0x0204AA94 arm
 *   POKE_TOOL_CalcIconPalette 0x0201BB5C thumb
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   FRAME_LIST_ClampToScrollBar 0x021B8AE4 thumb ov067
 *   FRAME_LIST_CanScrollDown 0x021B93C0 thumb ov067
 *   FRAME_LIST_HideCursor   0x021B941C  thumb
 *   FRAME_LIST_ShowCursor   0x021B940C  thumb ov067
 *   TOUCHPANEL_HitTrg  0x02035C08  arm  arm9
 *   KEY_GetTrg  0x020362DC  arm  arm9
 *   the name); it is a member function of the EXACT game_unit
 */

/* The ov067 scrolling list object stays opaque here. */
struct FrameList;

struct ProcSystem;

struct Proc;

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

struct DispConfig {u32 w[4];};

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
    u8 tickState[4];                     /* 0xC3C scratch state of ZUKAN_TickCounter */
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

/* Character part data returned by ARC_UTIL_LoadScreenDataFromHandle. */
struct ClactPartData { u8 pad[20]; void *part; };

enum Position { POSITION_ZERO=0 };

extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);

extern void *PROCSYS_AllocProcWork(struct ProcSystem *,unsigned,unsigned);

extern void MI_CpuFill8(void *,int,int);

extern void PROCSYS_FreeProcWork(struct Proc *p);

extern void GFL_HEAP_DeleteChecked(unsigned int heap);

extern void *GFL_USE_AddMainTask(unsigned,unsigned,unsigned);

extern void TCB_DeleteTask(struct Node *);

extern void BG_SYS_Update(void),CLACT_VBlankSystem(void);

extern void PALANM_TransferPalettes(struct S02021D50 *);

extern void *GFL_USE_AddHBlankTask(unsigned,unsigned,unsigned);

extern void BG_SYS_SetVramBanks(const struct DispVram *);

extern void BG_SYS_Create(u16);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);

extern void BG_SYS_ClearSlot(u32);

extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

extern void BG_SYS_MarkTileDirty(u32);

extern void BG_SYS_SetMainPlaneVisible(u32,u32);

extern void BG_SYS_SetSubPlaneVisible(u32,u32);

extern void BG_SYS_FreeLayerBuf(u32 i);

extern void BG_SYS_Delete(void);

extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);

extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,u32,u32,u32,u32,u16);

extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);

extern void ARC_UTIL_UploadBgPaletteFromHandle(void *,u32,u32,u32,u32,u32,u16);

extern void ARC_TOOL_DeleteHandle(void *);

extern u32 APP_ICON_GetArchiveId(void);

extern u32 APP_ICON_GetStatusFrameFileId(void);

extern u32 APP_ICON_GetStatusAnimFileId(void);

extern u32 APP_ICON_GetStatusDataFileId(void);

extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *,u32,u32,u32,u32,u16);

extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);

extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32,u32,u32,u32,u32,u16);

extern void *PALANM_Create(u32);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *,unsigned);

extern void PALANM_Delete(struct PalAnmSlot *);

extern u32 GFL_USE_GetMainTaskList(void);

extern int PALANM_RequestFade(void *, u16, u16, short, u8, u8, u16, void *);

extern void G2x_SetBlendAlpha_(void *,unsigned,unsigned,unsigned,unsigned);

extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);

extern struct WordSet *WORDSET_CreateDefault(u32 heap);

extern u32 PRINTSYS_QUE_Create(void *);

extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);

extern void STRBUF_Delete(struct U16Vec *);

extern void PRINTSYS_QUE_Delete(struct PrintSys *);

extern void WORDSET_Delete(struct WordSet *);

extern void GF_FONT_Delete(void *);

extern void MSGDATA_Delete(struct Rec *);

extern u16 *POKE_PERSONAL_LoadFormTable(u32 heap, u16 *countOut);

extern u32 GFL_HEAP_Free(void *p);

extern void BG_SYS_ChangeScroll(u32, u32, u32);

extern u16 ZUKAN_SAVE_GetLastViewedSpecies(struct Blk37 *p);

extern struct FrameList *FRAME_LIST_Create(const FrameListParams *params, u32 heap);

extern void FRAME_LIST_CopyMapToBuffer(u8 *p, u32 a, u32 b, u32 c, u32 index);

extern void FRAME_LIST_LoadPalettes(u8 *p, u8 *a, u32 b, u32 c, u32 d);

extern void FRAME_LIST_AddItem(char *ctx, unsigned first, unsigned second);

extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *p, u16 id);

extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);

extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);

extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);

extern void FRAME_LIST_Delete(struct FrameList *);

extern u32 FRAME_LIST_GetItemValue(char *p, int index);

extern int FRAME_LIST_GetScrollPos(char *);

extern int FRAME_LIST_GetCursor(char *);

extern void ZUKAN_LIST_UpdateActors(struct ZukanList *),ZUKAN_LIST_FlushWindows(struct ZukanList *),ZUKAN_TickCounter(u32,u32,u8 *);

extern void BG_SYS_SetMainVisiblePlanes(u32);

extern void BG_SYS_SetSubVisiblePlanes(u32);

extern void GXx_SetMasterBrightness_(volatile u16 *reg, int brightness);

extern int GF_OVERLAY_Load(int);

extern void BMP_SetDisplaySwap(u32);

extern void GFL_NET_RefreshWmIconAtTopRight(u32, u32);

extern u32 PALANM_GetFadeRequestBits(const char *);

extern void GF_OVERLAY_Unload(int);

extern int FRAME_LIST_UpdateInit(struct FrameList *p);

extern int FRAME_LIST_Update(struct FrameList *p);

extern int ZUKAN_LIST_HandleTouchInput(struct ZukanList *p);

extern int FRAME_LIST_GetSelectedIndex(char *p);

extern void FRAME_LIST_SetCursor(struct FrameList *s, int v);

extern u8 UI_GetInputMode(void);

extern void UI_SetInputMode(u8);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern u32 ZUKAN_SAVE_GetViewMode(struct Blk37 *p);

extern void ZUKAN_SAVE_SetViewMode(struct Blk37 *p, u32 v);

extern void FRAME_LIST_SetRowPalette(u8 *p, int a, u32 b);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, unsigned, unsigned, unsigned);

extern void ZUKAN_SAVE_SetLastViewedSpecies(void *,u16);

extern int GAME_DATA_ContainsRecentId(int, int);

extern void GAME_DATA_SetRecentId(void *, unsigned, unsigned);

extern void BMP_WIN_Init(unsigned short);

extern unsigned BMP_WIN_Create(unsigned, unsigned, unsigned, unsigned, u8, u8, u8);

extern u32 BMP_WIN_Delete(struct Descriptor *d);

extern void BMP_WIN_Exit(void);

extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);

extern void *BMP_WIN_GetBmp(struct Descriptor *p);

extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);

extern void BMP_WIN_TransferChars(struct Descriptor *);

extern void TOUCHBAR_PrintAligned(u8 *p, void *a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);

extern void WORDSET_CopyTaggedText(struct WordSet *, void *, void *);

extern void BMP_WIN_MakeScreen(struct Cfg *);

extern u8 BMP_WIN_GetBgLayer(struct Descriptor *);

extern u8 BMP_WIN_GetDispWidth(struct Descriptor *p);

extern u8 BMP_WIN_GetDispHeight(struct Descriptor *p);

extern u8 BMP_WIN_GetPosX(struct Descriptor *p);

extern u8 BMP_WIN_GetPosY(struct Descriptor *p);

extern void *BMP_GetPixels(const struct Bmp *bmp);

extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *, u32, u32, void **, u16);

extern void *ARC_UTIL_LoadBgCharDataFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

extern void MIi_CpuCopy32(const void *src, void *dst, u32 size);

extern u16 ZUKAN_SAVE_CountSeenNational(struct Blk37 *p);

extern u16 ZUKAN_SAVE_CountCaughtNational(struct Blk37 *p);

extern u16 ZUKAN_SAVE_CountSeenRegional(struct Blk37 *p, u32 heap);

extern u16 ZUKAN_SAVE_CountCaughtRegional(struct Blk37 *p, u32 heap);

extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);

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

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern int CLACT_RegisterPaletteCompressed(void *archive, u32 file_idx, u32 vram_mode, u32 vram_offset, u16 heap_id);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern u32 POKE_TOOL_CalcGraphicIndex(u32, u32, u32, u32);

extern int POKE_TOOL_GetIconPaletteArcId(void);

extern int POKE_TOOL_GetIconCellArcId(void);

extern int POKE_TOOL_GetIconCellArcIdSub(void);

extern int POKE_TOOL_GetIconCellEntryId(void);

extern int POKE_TOOL_GetIconCellEntryIdSub(void);

extern u32 APP_ICON_GetMoveKindPaletteFileId(void);

extern u32 APP_ICON_GetMoveKindAnimFileId(void);

extern u32 APP_ICON_GetStatusCellFileId(u32);

extern u32 APP_ICON_GetStatusPaletteFileId(u32);

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

extern void ZUKAN_SAVE_GetViewGenderAndForm(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 language);

extern int POKEGRA_OpenHandle(int heapId);

extern u32 ZUKAN_SAVE_GetSpindaPersonality(struct Blk37 *p, u32 which);

extern u32 POKEGRA_RegisterCgr(u32,u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern int POKEGRA_RegisterPalette(int,int,int,int,int,int,int,int,u16,u16);

extern u32 POKEGRA_RegisterCellAnim(u32,u32,u32,u32,u32,u32,u32,u32,u16);

extern void *POKE_PERSONAL_Create(u32,int,u32);

extern u32 POKE_PERSONAL_GetParam(const struct Personal *p, u32 field);

extern void POKE_PERSONAL_Delete(void *);

extern void CLACT_SetActorFlip(struct Actor *actor, u32 which, u32 set);

extern void *ARC_UTIL_LoadScreenDataFromHandle(void *arc, u32 memberIdx, u32 heapID, u32 unpackedOut, u16 flags);

extern u16 CLACT_GetActorCharacterIndex(u8 *);

extern void CLACT_TransferCharacterPart(int,void *,unsigned,int,int);

extern unsigned POKE_TOOL_CalcIconPalette(unsigned,unsigned,unsigned,unsigned);

extern void CLACT_SetActorPaletteOffset(struct Obj *,unsigned,unsigned);

extern int FRAME_LIST_ClampToScrollBar(struct FrameList *s, unsigned int v);

extern int FRAME_LIST_CanScrollDown(char *);

int ZUKAN_LIST_ProcInit(struct ProcSystem *p,int unused,unsigned arg);

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

void ZUKAN_LIST_StartActorMoveFrames(struct ZukanList *p, int delta);

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

int ZUKAN_LIST_IsSpeciesEntryValid(struct ZukanList *p,int speciesIndex);

void ZUKAN_LIST_StoreLastViewedSpecies(struct ZukanList *p,int speciesIndex);

int ZUKAN_LIST_StateSelectSpecies(struct ZukanList *p, int speciesIndex);

void ZUKAN_LIST_ToggleSaveFlag15(struct ZukanList *p);

void ZUKAN_LIST_CreateWindows(struct ZukanList *p);

void ZUKAN_LIST_DeleteWindows(struct ZukanList *p);

void ZUKAN_LIST_FlushWindows(struct ZukanList *p);

void ZUKAN_LIST_PrintTouchbarLabel(struct ZukanList *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode);

void ZUKAN_LIST_PrintTouchbarLabelClone(struct ZukanList *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode);

void ZUKAN_LIST_MakeWindowScreens(void **p);

void ZUKAN_LIST_ClearWindow(struct ZukanList *p, u32 windowIndex);

void ZUKAN_LIST_DrawHeaderRegional(struct ZukanList *p);

void ZUKAN_LIST_DrawHeaderCounts(struct ZukanList *p);

void ZUKAN_LIST_DrawHeaderNational(struct ZukanList *p);

void ZUKAN_LIST_PrintListRow(struct ZukanList *p, unsigned char *dest, unsigned text0, unsigned index);

void ZUKAN_LIST_InitActors(struct ZukanList *p);

void ZUKAN_LIST_ExitActors(struct ZukanList *list);

void ZUKAN_LIST_UpdateActors(struct ZukanList *p);

void ZUKAN_LIST_SetActorAnim(struct ZukanList *p, int actorIndex, int animValue);

void ZUKAN_LIST_StartActorAnim(struct ZukanList *p,int actorIndex,int value);

int ZUKAN_LIST_GetActorAnimSeq(struct ZukanList *p, int actorIndex);

u32 ZUKAN_LIST_IsActorAnimActive(struct ZukanList *p,u32 actorIndex);

void ZUKAN_LIST_SetActorVisible(struct ZukanList *p,u32 actorIndex,u32 value);

u32 ZUKAN_LIST_GetActorVisible(struct ZukanList *p,u32 actorIndex);

void ZUKAN_LIST_SetActorObjMode(struct ZukanList *p,u32 actorIndex,u32 flag);

void ZUKAN_LIST_AddActorPos(struct ZukanList *p, int actorIndex, short x, short y, unsigned short surface);

void ZUKAN_LIST_GetActorPos(struct ZukanList *p,u32 actorIndex,s16 *x,s16 *y,u16 space);

void ZUKAN_LIST_InitActorSystem(struct ZukanList *p);

void ZUKAN_LIST_LoadActorResources(struct ZukanList *p);

void ZUKAN_LIST_ReleaseActorResources(struct ZukanList *p);

void ZUKAN_LIST_CreateActors(struct ZukanList *p);

void ZUKAN_LIST_DeleteActor(struct ZukanList *p,u32 actorIndex);

void ZUKAN_LIST_DeleteActorUnit(struct ZukanList *p);

void ZUKAN_LIST_LoadSpeciesIcon(struct ZukanList *p,u16 species);

void ZUKAN_LIST_UpdateSpeciesActors(struct ZukanList *p);

void ZUKAN_LIST_TransferSpeciesGraphics(struct ZukanList *p, int actorIndex, unsigned species, u16 form, u16 charHalf, int mode);

int ZUKAN_LIST_FindHiddenSpeciesActor(struct ZukanList *list, int group);

void ZUKAN_LIST_ShowSpeciesActor(struct ZukanList *p,u16 species,enum Position pos,int mode);

void ZUKAN_LIST_ScrollActorsBy(struct ZukanList *p, int delta);

void ZUKAN_LIST_HideAllActors(struct ZukanList *p);

void ZUKAN_LIST_ShowAllActors(struct ZukanList *p);

void ZUKAN_LIST_MoveCursorActor(struct ZukanList *p,int index);

void ZUKAN_LIST_UpdateScrollBarActor(struct ZukanList *p);

void ZUKAN_LIST_UpdateArrowActors(struct ZukanList *p,int flag);

extern const struct DispVram gZukanListVramBankConfig;

extern const struct DispConfig gZukanListDisplayConfig;

extern const struct BgTemplate gZukanListBgTemplateLayer0,gZukanListBgTemplateLayer1,gZukanListBgTemplateLayer2,gZukanListBgTemplateLayer3,gZukanListBgTemplateLayer4,gZukanListBgTemplateLayer5,gZukanListBgTemplateLayer6,gZukanListBgTemplateLayer7;

extern const FrameListParams gZukanListFrameListParams;

extern struct MsgBank *gSpeciesNameBank;

extern const char ov067_id[];

extern const u8 gZukanListWindowDefs[][6];

extern const struct ClactInit gZukanListClactInit;

extern const struct ClactActorDesc gZukanListActorDescTable[10];

extern const struct ClactActorDesc gZukanListActorDesc;

extern const struct ClactSpeciesActor gZukanListSpeciesActor;

int ZUKAN_LIST_ProcInit(struct ProcSystem *p,int unused,unsigned arg){unsigned *work;GFL_HEAP_CreateChildHeap(1,107,0x60000);work=PROCSYS_AllocProcWork(p,0xc44,107);MI_CpuFill8(work,0,0xc44);*work=arg;return 1;}

int ZUKAN_LIST_ProcMain(int unused0, int unused1, int unused2, int work)
{
    if (ZUKAN_LIST_RunState((struct ZukanList *)work) == 0)
        return 1;
    return 0;
}

int ZUKAN_LIST_ProcExit(void *p)
{
    PROCSYS_FreeProcWork(p);
    GFL_HEAP_DeleteChecked(0x6b);
    return 1;
}

void ZUKAN_LIST_StartVBlankTask(struct ZukanList *p){p->vblankTask=GFL_USE_AddMainTask((unsigned)ZUKAN_LIST_VBlankTask,(unsigned)p,0);}

void ZUKAN_LIST_StopVBlankTask(struct ZukanList *p){TCB_DeleteTask((struct Node *)p->vblankTask);}

/*
 * lever: enum-typed DTCM base preserves the base-first two-pool address; constant addition folds and enum offset reverses pool/register roles.
 * volatile: hardware interrupt check flag at 02FE3FF8 read and written by 021BC2D4/021BC2D8.
 */
void ZUKAN_LIST_VBlankTask(void *unused,struct ZukanList *p){enum Base { DTCM_BASE=0x02fe0000 } base;BG_SYS_Update();CLACT_VBlankSystem();PALANM_TransferPalettes((struct S02021D50 *)p->palAnm);base=DTCM_BASE;*(volatile unsigned *)&((struct DtcmIrqFlag *)base)->flag|=1;}

void ZUKAN_LIST_StartHBlankTask(struct ZukanList *p){p->hblankTask=GFL_USE_AddHBlankTask((unsigned)ZUKAN_LIST_HBlankTask,(unsigned)p,0);}

void ZUKAN_LIST_StopHBlankTask(struct ZukanList *p)
{
    TCB_DeleteTask(p->hblankTask);
}

/*
 * volatile: VCOUNT read at 021BC30A; BLDALPHA writes at 021BC314, 021BC320, 021BC32C, 021BC338, 021BC344, 021BC34A
 */
void ZUKAN_LIST_HBlankTask(void)
{
    int vcount = *(volatile u16 *)0x04000006;
    if (vcount >= 168) {
        *(volatile u16 *)0x04001052 = 0x050B;
        return;
    }
    if (vcount >= 144) {
        *(volatile u16 *)0x04001052 = 0x060A;
        return;
    }
    if (vcount >= 120) {
        *(volatile u16 *)0x04001052 = 0x0709;
        return;
    }
    if (vcount >= 96) {
        *(volatile u16 *)0x04001052 = 0x0808;
        return;
    }
    if (vcount >= 72) {
        *(volatile u16 *)0x04001052 = 0x0A06;
        return;
    }
    *(volatile u16 *)0x04001052 = 0x0C04;
}

void ZUKAN_LIST_SetVramBanks(void){BG_SYS_SetVramBanks(&gZukanListVramBankConfig);}

void *ZUKAN_LIST_GetVramBankConfig(void){return (void *)&gZukanListVramBankConfig;}

void ZUKAN_LIST_InitBgSystem(void)
{
    struct DispConfig display;
    struct BgTemplate bgTemplate0,bgTemplate1,bgTemplate2,bgTemplate3,bgTemplate4,bgTemplate5,bgTemplate6,bgTemplate7;
    BG_SYS_Create(107);
    display=gZukanListDisplayConfig;BG_SYS_SetGraphicsMode((struct DispConfig *)(&display));
    bgTemplate0=gZukanListBgTemplateLayer0;BG_SYS_InitBgLayer(0,&bgTemplate0,0);
    BG_SYS_ClearSlot(0);BG_SYS_InitRun(0,32,0,107);BG_SYS_MarkTileDirty(0);
    bgTemplate1=gZukanListBgTemplateLayer1;BG_SYS_InitBgLayer(1,&bgTemplate1,0);
    bgTemplate2=gZukanListBgTemplateLayer2;BG_SYS_InitBgLayer(2,&bgTemplate2,0);
    BG_SYS_ClearSlot(2);BG_SYS_MarkTileDirty(2);
    bgTemplate3=gZukanListBgTemplateLayer3;BG_SYS_InitBgLayer(3,&bgTemplate3,0);
    bgTemplate4=gZukanListBgTemplateLayer4;BG_SYS_InitBgLayer(4,&bgTemplate4,0);
    BG_SYS_ClearSlot(4);BG_SYS_InitRun(4,32,0,107);BG_SYS_MarkTileDirty(4);
    bgTemplate5=gZukanListBgTemplateLayer5;BG_SYS_InitBgLayer(5,&bgTemplate5,0);
    bgTemplate6=gZukanListBgTemplateLayer6;BG_SYS_InitBgLayer(6,&bgTemplate6,0);
    BG_SYS_ClearSlot(6);BG_SYS_MarkTileDirty(6);
    bgTemplate7=gZukanListBgTemplateLayer7;BG_SYS_InitBgLayer(7,&bgTemplate7,0);
    BG_SYS_SetMainPlaneVisible(15,1);BG_SYS_SetSubPlaneVisible(15,1);
}

void ZUKAN_LIST_ExitBgSystem(void)
{
    BG_SYS_SetMainPlaneVisible(0xf, 0);
    BG_SYS_SetSubPlaneVisible(0xf, 0);
    BG_SYS_FreeLayerBuf(7);
    BG_SYS_FreeLayerBuf(6);
    BG_SYS_FreeLayerBuf(5);
    BG_SYS_FreeLayerBuf(4);
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(1);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_Delete();
}

void ZUKAN_LIST_LoadBgGraphics(void)
{
    void *arc;
    arc=ARC_TOOL_CreateHandle(159,107);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,48,0,0,128,107);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,49,4,0,160,107);
    ARC_UTIL_UploadBgCharFromHandle(arc,58,2,0,0,0,107);
    ARC_UTIL_UploadBgCharFromHandle(arc,56,3,0,0,0,107);
    ARC_UTIL_UploadBgCharFromHandle(arc,59,6,0,0,0,107);
    ARC_UTIL_UploadBgCharFromHandle(arc,57,7,0,0,0,107);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,62,3,0,0,0,107);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,69,5,0,0,0,107);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,63,7,0,0,0,107);
    ARC_TOOL_DeleteHandle(arc);
    arc=ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(),107);
    ARC_UTIL_RegisterObjCharFromHandle(arc,APP_ICON_GetStatusFrameFileId(),1,0,0,107);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,APP_ICON_GetStatusAnimFileId(),0,448,32,107);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,APP_ICON_GetStatusDataFileId(),1,0,0,0,107);
    BG_SYS_FillTileMap(1,0,21,32,3,14);
    BG_SYS_MarkTileDirty(1);
    ARC_TOOL_DeleteHandle(arc);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,0,480,32,107);
    ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,480,32,107);
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
    ctx = (void *)GFL_USE_GetMainTaskList();
    PALANM_RequestFade(p->palAnm, 1, 0xBFFF, -14, fadeFrom, fadeTo, 0, ctx);
    ctx = (void *)GFL_USE_GetMainTaskList();
    PALANM_RequestFade(p->palAnm, 2, 0xFFEF, -14, fadeFrom, fadeTo, 0, ctx);
    ctx = (void *)GFL_USE_GetMainTaskList();
    PALANM_RequestFade(p->palAnm, 4, 0xF878, -14, fadeFrom, fadeTo, 0, ctx);
    ctx = (void *)GFL_USE_GetMainTaskList();
    PALANM_RequestFade(p->palAnm, 8, 0xBFFF, -14, fadeFrom, fadeTo, 0, ctx);
}

void ZUKAN_LIST_SetSubScreenBlendAlpha(void){G2x_SetBlendAlpha_((void *)0x04001050,4,8,6,10);}

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
    p->msgBank = MSGDATA_CreateFromArchive(0, 2, 0x114, 0x6B);
    p->font = GF_FONT_Create(0x17, 0, 0, 0, 0x6B);
    p->wordSet = WORDSET_CreateDefault(0x6B);
    p->printer = (void *)PRINTSYS_QUE_Create((void *)0x6B);
    p->textBuf = STRBUF_Create(0x80, 0x6B);
}

void ZUKAN_LIST_DeleteFontAndPrinter(struct ZukanList *p){STRBUF_Delete((struct U16Vec *)p->textBuf);PRINTSYS_QUE_Delete((struct PrintSys *)p->printer);WORDSET_Delete((struct WordSet *)p->wordSet);GF_FONT_Delete(p->font);MSGDATA_Delete((struct Rec *)p->msgBank);}

void ZUKAN_LIST_LoadFormTable(struct ZukanList *p) { p->formTable=POKE_PERSONAL_LoadFormTable(107,0); }

void ZUKAN_LIST_FreeFormTable(struct ZukanList *p) { GFL_HEAP_Free(p->formTable); }

void ZUKAN_LIST_MoveScrollBarActorsIn(struct ZukanList *p)
{
    unsigned actorIndex;
    s16 pos[2];
    BG_SYS_ChangeScroll(5, 3, 48);
    BG_SYS_ChangeScroll(1, 3, -48);
    for (actorIndex = 3; actorIndex <= 9; actorIndex++) {
        ZUKAN_LIST_GetActorPos(p, actorIndex, &pos[1], &pos[0], 0);
        pos[0] += 48;
        ZUKAN_LIST_AddActorPos(p, actorIndex, pos[1], pos[0], 0);
    }
}

void ZUKAN_LIST_StartActorMoveFrames(struct ZukanList *p, int delta)
{
    p->moveTimer = 0x30;
    *(unsigned short *)&p->moveDelta = delta;
}

int ZUKAN_LIST_UpdateActorMove(struct ZukanList *p)
{
    unsigned actorIndex;
    s16 pos[2];
    int absDelta;
    if (p->moveTimer == 0) return 0;
    BG_SYS_ChangeScroll(5, 4, p->moveDelta);
    BG_SYS_ChangeScroll(1, 5, p->moveDelta);
    for (actorIndex = 3; actorIndex <= 9; actorIndex++) {
        ZUKAN_LIST_GetActorPos(p, actorIndex, &pos[1], &pos[0], 0);
        pos[0] += p->moveDelta;
        ZUKAN_LIST_AddActorPos(p, actorIndex, pos[1], pos[0], 0);
    }
    absDelta = p->moveDelta;
    if (absDelta < 0) absDelta = -absDelta;
    p->moveTimer -= absDelta;
    return 1;
}

/*
 * ov067 is loaded by the same overlay's 021BCC94/021BCD48 path.
 */
void ZUKAN_LIST_CreateFrameList(struct ZukanList *p)
{
    FrameListParams tmpl;
    void *arc,*text;
    u32 species,rowIndex;
    arc=ARC_TOOL_CreateHandle(159,0x806b);
    species=ZUKAN_SAVE_GetLastViewedSpecies(p->args->save);
    tmpl=gZukanListFrameListParams;
    tmpl.itemCount=649;tmpl.userData=p;
    for(rowIndex=0;rowIndex<p->args->count;rowIndex++){
        if(species==p->args->ids[rowIndex]){
            if(rowIndex>p->args->count-7){
                tmpl.initialCursor=rowIndex-(p->args->count-7);
                tmpl.initialScroll=rowIndex-tmpl.initialCursor;
            }else if(rowIndex<7){tmpl.initialCursor=rowIndex;}
            else{tmpl.initialScroll=rowIndex;}
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
    for(rowIndex=0;rowIndex<p->args->count;rowIndex++){
        if(ZUKAN_SAVE_IsCaught(p->args->save,p->args->ids[rowIndex])==1){
            text=MSGDATA_AllocString(gSpeciesNameBank,p->args->ids[rowIndex]);
            *(void **)((u32)(char *)p+rowIndex*4+0x4c)=STRBUF_Clone(text,107);
            STRBUF_Delete(text);
            FRAME_LIST_AddItem(p->frameList,0,0x20000000|p->args->ids[rowIndex]);
        }else if(ZUKAN_SAVE_IsSeen(p->args->save,p->args->ids[rowIndex])==1){
            text=MSGDATA_AllocString(gSpeciesNameBank,p->args->ids[rowIndex]);
            *(void **)((u32)(char *)p+rowIndex*4+0x4c)=STRBUF_Clone(text,107);
            STRBUF_Delete(text);
            FRAME_LIST_AddItem(p->frameList,1,0x10000000|p->args->ids[rowIndex]);
        }else{
            *(void **)((u32)(char *)p+rowIndex*4+0x4c)=MSGDATA_AllocString(p->msgBank,7);
            FRAME_LIST_AddItem(p->frameList,2,p->args->ids[rowIndex]);
        }
    }
}

void ZUKAN_LIST_DeleteFrameList(struct ZukanList *p) { u32 i;FRAME_LIST_Delete((struct FrameList *)p->frameList);for(i=0;i<649;i++){struct U16Vec *text=*(struct U16Vec **)((u32)(char *)p+i*4+76);if(text)STRBUF_Delete(text);} }

void ZUKAN_LIST_FrameListMoveCallback(struct ZukanList *p, int index, int dest, u16 position, int mode)
{
    u32 itemValue;
    u32 speciesId;
    itemValue = FRAME_LIST_GetItemValue(p->frameList, index);
    speciesId = itemValue & 0x0FFFFFFF;
    ZUKAN_LIST_PrintListRow(p, (unsigned char *)dest, (u32)p->speciesText[index], speciesId);
    if ((itemValue & 0xF0000000) >> 28) ZUKAN_LIST_ShowSpeciesActor(p, speciesId, position, mode);
}

void ZUKAN_LIST_FrameListSelectCallback(struct ZukanList *p, int index)
{
    u32 itemValue;
    itemValue = FRAME_LIST_GetItemValue(p->frameList, index);
    if ((itemValue & 0xF0000000) >> 28) ZUKAN_LIST_LoadSpeciesIcon(p, itemValue & 0x0FFFFFFF);
    else ZUKAN_LIST_LoadSpeciesIcon(p, 0);
    ZUKAN_LIST_MoveCursorActor(p, index - FRAME_LIST_GetScrollPos(p->frameList));
}

void ZUKAN_LIST_ScrollByDelta(struct ZukanList *p,int delta) { ZUKAN_LIST_ScrollActorsBy(p,(signed char)-delta);ZUKAN_LIST_MoveCursorActor(p,FRAME_LIST_GetCursor(p->frameList));ZUKAN_LIST_UpdateArrowActors(p,1); }

extern int (*const gZukanListStateHandlers[])(char *);

int ZUKAN_LIST_RunState(struct ZukanList *p) { p->state=(*(int (**)(char *))((u32)gZukanListStateHandlers+p->state*4))((char *)p);if(p->state==9)return 0;ZUKAN_LIST_UpdateActors(p);ZUKAN_LIST_FlushWindows(p);ZUKAN_TickCounter(3,7,(u8 *)p->tickState);return 1; }

/*
 * lever: pooled 0x43 is the linker-defined ov067 id, not an integer literal
 * volatile: BLDCNT hardware zero stores at 021BCCB0, 021BCCB2
 */
int ZUKAN_LIST_StateInit(struct ZukanList *p)
{
    GF_OVERLAY_Load((int)ov067_id);
    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    GXx_SetMasterBrightness_((volatile u16 *)0x0400006C, -16);
    GXx_SetMasterBrightness_((volatile u16 *)0x0400106C, -16);
    BMP_SetDisplaySwap(0);
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
    GFL_NET_RefreshWmIconAtTopRight(1, 0x6B);
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
    GF_OVERLAY_Unload((int)ov067_id);
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
        old=UI_GetInputMode();
        action=ZUKAN_LIST_HandleTouchInput(p);
        switch(action){
        case 0:
            selected=FRAME_LIST_GetSelectedIndex(p->frameList);
            if(ZUKAN_LIST_IsSpeciesEntryValid(p,selected)==1){GFL_USE_PlaySeDefaultVolume(1356);return ZUKAN_LIST_StateSelectSpecies(p,selected);}
            UI_SetInputMode(old);break;
        case 1:case 2:case 3:case 4:case 5:case 6:case 7:
            selected=action+FRAME_LIST_GetScrollPos(p->frameList)-1;
            if(ZUKAN_LIST_IsSpeciesEntryValid(p,selected)==1){
                GFL_USE_PlaySeDefaultVolume(1356);FRAME_LIST_SetCursor(p->frameList,action-1);return ZUKAN_LIST_StateSelectSpecies(p,selected);
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
            BG_SYS_MarkTileDirty(2);
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

int ZUKAN_LIST_IsSpeciesEntryValid(struct ZukanList *p,int speciesIndex) { if((FRAME_LIST_GetItemValue(p->frameList,speciesIndex)&0xf0000000u)>>28)return 1;return 0; }

void ZUKAN_LIST_StoreLastViewedSpecies(struct ZukanList *p,int speciesIndex) { if(ZUKAN_LIST_IsSpeciesEntryValid(p,speciesIndex)==1)ZUKAN_SAVE_SetLastViewedSpecies(p->args->save,FRAME_LIST_GetItemValue(p->frameList,speciesIndex)); }

int ZUKAN_LIST_StateSelectSpecies(struct ZukanList *p, int speciesIndex)
{
    ZUKAN_LIST_StoreLastViewedSpecies(p, speciesIndex);
    *(int *)(*(int *)&p->args + 0x10) = 3;
    return 7;
}

/*
 * extent: 021BD396 two-byte alignment padding before 021BD398.
 */
void ZUKAN_LIST_ToggleSaveFlag15(struct ZukanList *p)
{
    if (GAME_DATA_ContainsRecentId(*(int *)p->args, 15) == 1) {
        GAME_DATA_SetRecentId(*(void **)p->args, 15, 0);
        ZUKAN_LIST_StartActorAnim(p, 5, 6);
    } else {
        GAME_DATA_SetRecentId(*(void **)p->args, 15, 1);
        ZUKAN_LIST_StartActorAnim(p, 5, 7);
    }
}

void ZUKAN_LIST_CreateWindows(struct ZukanList *p)
{
    unsigned windowIndex;
    BMP_WIN_Init(107);
    for (windowIndex = 0; windowIndex < 3; windowIndex++)
        *(unsigned *)&p->windows[windowIndex].bmp = BMP_WIN_Create(gZukanListWindowDefs[windowIndex][0], gZukanListWindowDefs[windowIndex][1], gZukanListWindowDefs[windowIndex][2], gZukanListWindowDefs[windowIndex][3], gZukanListWindowDefs[windowIndex][4], gZukanListWindowDefs[windowIndex][5], 1);
    ZUKAN_LIST_DrawHeaderRegional(p);
}

void ZUKAN_LIST_DeleteWindows(struct ZukanList *p) { u32 windowIndex;for(windowIndex=0;windowIndex<3;windowIndex++)BMP_WIN_Delete(*(struct Descriptor **)((u32)(char *)p+windowIndex*8+32));BMP_WIN_Exit(); }

/*
 * extent: 021BD43E..021BD440 is two zero alignment bytes before matched D440.
 * lever: first types search hoisted the initialized full-word ps load before entry arithmetic.
 * checks: 1 own C4E4, C6C4, 45770, 45334 bodies prove 1/2/1/1 arity; 2 ov0679344 and ov208C0740 confirm full-word handles; 3 carried two compiles exhausted; 4 carried two order/extraction probes exhausted; 5 fresh idioms/neighbours read, no stack object. Wave32 I4 pointer ps unchanged5; types search9 candidates exact after ps hoist, all inputs and call/store order preserved.
 */
void ZUKAN_LIST_FlushWindows(struct ZukanList *p)
{
    int printer;
    long windowIndex;
    PRINTSYS_QUE_Main((struct PrintSys *)p->printer);
    for (windowIndex = 0; windowIndex < 3u; windowIndex++) {
        printer = (int)p->printer;
        if (p->windows[windowIndex].pending) {
            if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)printer, BMP_WIN_GetBmp(p->windows[windowIndex].bmp)) == 0) {
                BMP_WIN_TransferChars(p->windows[windowIndex].bmp);
                p->windows[windowIndex].pending = 0;
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
    text = MSGDATA_AllocString((struct MsgBank *)p->msgBank, msg);
    TOUCHBAR_PrintAligned((unsigned char *)&p->windows[index], (void *)(p->printer), x, y, (unsigned)text, *(unsigned *)&p->font, color, mode);
    STRBUF_Delete(text);
}

/*
 * extent: 021BD4DA two-byte alignment padding before existing labelled 021BD4DC.
 */
void ZUKAN_LIST_PrintTouchbarLabelClone(struct ZukanList *p, unsigned index, unsigned msg, unsigned x, unsigned y, u16 color, unsigned mode)
{
    void *text;
    text = MSGDATA_AllocString((struct MsgBank *)p->msgBank, msg);
    WORDSET_CopyTaggedText((struct WordSet *)p->wordSet, p->textBuf, text);
    TOUCHBAR_PrintAligned((unsigned char *)&p->windows[index], (void *)(p->printer), x, y, *(unsigned *)&p->textBuf, *(unsigned *)&p->font, color, mode);
    STRBUF_Delete(text);
}

void ZUKAN_LIST_MakeWindowScreens(void **p) {BMP_WIN_MakeScreen(*p);BG_SYS_MarkTileDirty(BMP_WIN_GetBgLayer(*p));}

void ZUKAN_LIST_ClearWindow(struct ZukanList *p, u32 windowIndex)
{
    void *gfxRes;
    void *mapRes;
    void *gfxHandle;
    u8 *gfx;
    void *mapHandle;
    u8 *dst;
    u16 row;
    u8 *map;
    int y;
    int h;
    u8 w;
    int x;
    u8 *tileMap;
    struct Descriptor **ent = &p->windows[0].bmp;
    void *arc;
    u16 col;

    w = BMP_WIN_GetDispWidth(*(struct Descriptor **)((u8 *)ent + windowIndex * 8));
    h = BMP_WIN_GetDispHeight(*(struct Descriptor **)((u8 *)ent + windowIndex * 8));
    x = BMP_WIN_GetPosX(*(struct Descriptor **)((u8 *)ent + windowIndex * 8));
    y = BMP_WIN_GetPosY(*(struct Descriptor **)((u8 *)ent + windowIndex * 8));
    dst = BMP_GetPixels(BMP_WIN_GetBmp(*(struct Descriptor **)((u8 *)ent + windowIndex * 8)));
    arc = ARC_TOOL_CreateHandle(0x9F, 0x6B);
    mapHandle = ARC_UTIL_LoadPaletteDataFromHandle(arc, 0x45, 0, &mapRes, 0x806B);
    tileMap = (u8 *)mapRes + 0xC;
    gfxHandle = ARC_UTIL_LoadBgCharDataFromHandle(arc, 0x39, 0, (u32)(&gfxRes), 0x806B);
    gfx = *(u8 **)((u8 *)gfxRes + 0x14);
    ARC_TOOL_DeleteHandle(arc);
    if (h > 0) {
        map = tileMap + x * 2;
        row = 0;
        do {
            for (col = 0; col < w; col++) {
                u16 tile = *(u16 *)(map + (y + row) * 64 + col * 2);
                MIi_CpuCopy32(gfx + (tile & 0x3FF) * 32, dst + (col + row * w) * 32, 0x20);
            }
            row++;
        } while (row < h);
    }
    GFL_HEAP_Free(gfxHandle);
    GFL_HEAP_Free(mapHandle);
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
    unsigned seenCount, caughtCount;
    if (ZUKAN_SAVE_GetViewMode(p->args->save) == 1) {
        seenCount = ZUKAN_SAVE_CountSeenNational(p->args->save);
        caughtCount = ZUKAN_SAVE_CountCaughtNational(p->args->save);
    } else {
        seenCount = ZUKAN_SAVE_CountSeenRegional(p->args->save, 0x806b);
        caughtCount = ZUKAN_SAVE_CountCaughtRegional(p->args->save, 0x806b);
    }
    ZUKAN_LIST_ClearWindow(p, 1);
    ZUKAN_LIST_ClearWindow(p, 2);
    ZUKAN_LIST_PrintTouchbarLabel(p, 1, 2, 0x48, 4, 0x31a0, 1);
    WORDSET_SetSlotNumber(*(WordSet * *)&p->wordSet, 0, seenCount, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 1, 5, 0x68, 4, 0x31a0, 1);
    ZUKAN_LIST_PrintTouchbarLabel(p, 2, 3, 0x58, 4, 0x31a0, 1);
    WORDSET_SetSlotNumber(*(WordSet * *)&p->wordSet, 0, caughtCount, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 2, 5, 0x78, 4, 0x31a0, 1);
    ZUKAN_LIST_MakeWindowScreens((void **)&p->windows[1].bmp);
    ZUKAN_LIST_MakeWindowScreens((void **)&p->windows[2].bmp);
}

void ZUKAN_LIST_DrawHeaderNational(struct ZukanList *p)
{
    ZUKAN_LIST_ClearWindow(p, 2);
    ZUKAN_LIST_PrintTouchbarLabel(p, 2, 4, 88, 4, 0x31a0, 1);
    WORDSET_SetSlotNumber((struct WordSet *)p->wordSet, 0, p->args->count, 3, 0, 1);
    ZUKAN_LIST_PrintTouchbarLabelClone(p, 2, 5, 120, 4, 0x31a0, 1);
    ZUKAN_LIST_MakeWindowScreens((void **)&p->windows[2].bmp);
}

void ZUKAN_LIST_PrintListRow(struct ZukanList *p, unsigned char *dest, unsigned text0, unsigned index)
{
    unsigned printer;
    void *text;
    printer = FRAME_LIST_GetPrinter(p->frameList);
    if (ZUKAN_SAVE_GetViewMode((struct Blk37 *)p->args->save) == 0)
        index = p->formTable[index];
    text = MSGDATA_AllocString((struct MsgBank *)p->msgBank, 8);
    WORDSET_SetSlotNumber((struct WordSet *)p->wordSet, 0, index, 3, 2, 1);
    WORDSET_CopyTaggedText((struct WordSet *)p->wordSet, p->textBuf, text);
    STRBUF_Delete(text);
    TOUCHBAR_PrintAligned(dest, (void *)printer, 0, 4, *(unsigned *)&p->textBuf, (unsigned)p->font, 0x39e0, 0);
    TOUCHBAR_PrintAligned(dest, (void *)printer, 28, 4, text0, (unsigned)p->font, 0x39e0, 0);
}

void ZUKAN_LIST_InitActors(struct ZukanList *p) {ZUKAN_LIST_InitActorSystem(p);ZUKAN_LIST_LoadActorResources(p);ZUKAN_LIST_CreateActors(p);ZUKAN_LIST_UpdateSpeciesActors(p);BG_SYS_SetMainPlaneVisible(16,1);BG_SYS_SetSubPlaneVisible(16,1);}

void ZUKAN_LIST_ExitActors(struct ZukanList *list)
{
    ZUKAN_LIST_DeleteActorUnit(list);
    ZUKAN_LIST_ReleaseActorResources(list);
    CLACT_ExitSystem();
}

void ZUKAN_LIST_UpdateActors(struct ZukanList *p) {u32 actorIndex;for(actorIndex=0;actorIndex<60;actorIndex++) {if(p->actors[actorIndex]) {if(CLACT_GetActorAutoAnim((struct Actor *)p->actors[actorIndex])!=1) CLACT_AddActorAnimFrame(p->actors[actorIndex],0x1000);}}CLACT_DrawSystem();}

void ZUKAN_LIST_SetActorAnim(struct ZukanList *p, int actorIndex, int animValue)
{
    CLACT_SetActorAnimFrame(*(void **)((char *)p + 0xa74 + actorIndex * 4), 0);
    CLACT_SetActorAnimSeq(*(void **)((char *)p + 0xa74 + actorIndex * 4), (unsigned short)animValue);
}

void ZUKAN_LIST_StartActorAnim(struct ZukanList *p,int actorIndex,int value) {ZUKAN_LIST_SetActorAnim(p,actorIndex,value);CLACT_SetActorAutoAnim((struct Obj *)(struct Actor *)p->actors[actorIndex],1);}

int ZUKAN_LIST_GetActorAnimSeq(struct ZukanList *p, int actorIndex)
{
    return CLACT_GetActorAnimSeq((struct Obj *)(int)p->actors[actorIndex]);
}

u32 ZUKAN_LIST_IsActorAnimActive(struct ZukanList *p,u32 actorIndex) {return CLACT_IsActorAnimActive((struct Actor *)p->actors[actorIndex]);}

void ZUKAN_LIST_SetActorVisible(struct ZukanList *p,u32 actorIndex,u32 value) {struct Obj *actor;actor=p->actors[actorIndex];if(actor) CLACT_SetActorDrawEnable(actor,value);}

u32 ZUKAN_LIST_GetActorVisible(struct ZukanList *p,u32 actorIndex) {return CLACT_GetActorDrawEnable(p->actors[actorIndex]);}

void ZUKAN_LIST_SetActorObjMode(struct ZukanList *p,u32 actorIndex,u32 flag) {if(flag==1) CLACT_SetActorObjMode((struct Actor *)p->actors[actorIndex],1);else CLACT_SetActorObjMode((struct Actor *)p->actors[actorIndex],0);}

void ZUKAN_LIST_AddActorPos(struct ZukanList *p, int actorIndex, short x, short y, unsigned short surface)
{
    unsigned short buf[2];
    buf[0] = x;
    buf[1] = y;
    CLACT_AddActorSurfacePos((void *)p->actors[actorIndex], (const struct Vec2 *)buf, surface);
}

/*
 * prototype: outgoing space argument is loaded by ldrh at 021BD966; callee extern uses u16 for the observed bits.
 */
void ZUKAN_LIST_GetActorPos(struct ZukanList *p,u32 actorIndex,s16 *x,s16 *y,u16 space) {PtS point;CLACT_GetActorSurfacePos((struct Actor *)p->actors[actorIndex],&point,space);*x=point.x;*y=point.y;}

void ZUKAN_LIST_InitActorSystem(struct ZukanList *p) {struct ClactInit init;init=gZukanListClactInit;CLACT_InitSystem((const struct Cfg *)&init,(u32)ZUKAN_LIST_GetVramBankConfig(),107);}

void ZUKAN_LIST_LoadActorResources(struct ZukanList *p)
{
    int arcActor, arcSpecies, arcUi;
    u32 gfxIndex;
    u32 slot;
    u32 cellAnimIndex;
    int *charSlot;
    int *palSlot;
    int *animSlot;

    for (slot = 0; slot < 0x24; slot++) p->charHandles[slot] = -1;
    for (slot = 0; slot < 6; slot++) p->paletteHandles[slot] = -1;
    for (slot = 0; slot < 6; slot++) p->cellAnimHandles[slot] = -1;

    arcActor = (int)ARC_TOOL_CreateHandle(0x9f, 0x806B);
    p->charHandles[0x23] = CLACT_RegisterCharacter((void *)arcActor, 0x37, 0, 0, 0x6b);
    p->paletteHandles[5] = CLACT_RegisterPalette((void *)arcActor, 0x33, 0, 0, 0x6b);
    p->cellAnimHandles[5] = CLACT_RegisterCellAnim((void *)arcActor, 0x3d, 0x47, 0x6b);
    ARC_TOOL_DeleteHandle((void *)arcActor);

    arcSpecies = (int)ARC_TOOL_CreateHandle(7, 0x806B);
    charSlot = (int *)p->charHandles;
    palSlot = (int *)&p->paletteHandles[0];
    animSlot = (int *)&p->cellAnimHandles[0];
    for (gfxIndex = 0; gfxIndex < 0x10; gfxIndex++)
        charSlot[gfxIndex] = CLACT_RegisterCharacter((void *)arcSpecies, POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0), 0, 0, 0x6b);
    *palSlot = CLACT_RegisterPaletteCompressed((void *)arcSpecies, POKE_TOOL_GetIconPaletteArcId(), 0, 0x80, 0x6b);
    cellAnimIndex = POKE_TOOL_GetIconCellArcId();
    *animSlot = CLACT_RegisterCellAnim((void *)arcSpecies, cellAnimIndex, POKE_TOOL_GetIconCellEntryId(), 0x6b);

    charSlot = (int *)&p->charHandles[0x10];
    palSlot = (int *)&p->paletteHandles[1];
    animSlot = (int *)&p->cellAnimHandles[1];
    for (gfxIndex = 0; gfxIndex < 0x10; gfxIndex++)
        charSlot[gfxIndex] = CLACT_RegisterCharacter((void *)arcSpecies, POKE_TOOL_CalcGraphicIndex(0, 0, 0, 0), 0, 1, 0x6b);
    *palSlot = CLACT_RegisterPaletteCompressed((void *)arcSpecies, POKE_TOOL_GetIconPaletteArcId(), 1, 0, 0x6b);
    cellAnimIndex = POKE_TOOL_GetIconCellArcIdSub();
    *animSlot = CLACT_RegisterCellAnim((void *)arcSpecies, cellAnimIndex, POKE_TOOL_GetIconCellEntryIdSub(), 0x6b);
    ARC_TOOL_DeleteHandle((void *)arcSpecies);

    arcUi = (int)ARC_TOOL_CreateHandle(APP_ICON_GetArchiveId(), 0x806B);
    p->charHandles[0x22] = CLACT_RegisterCharacter((void *)arcUi, APP_ICON_GetMoveKindAnimFileId(), 0, 0, 0x6b);
    p->paletteHandles[4] = CLACT_RegisterPalette((void *)arcUi, APP_ICON_GetMoveKindPaletteFileId(), 0, 0xe0, 0x6b);
    cellAnimIndex = APP_ICON_GetStatusCellFileId(2);
    p->cellAnimHandles[4] = CLACT_RegisterCellAnim((void *)arcUi, cellAnimIndex, APP_ICON_GetStatusPaletteFileId(2), 0x6b);
    ARC_TOOL_DeleteHandle((void *)arcUi);
}

void ZUKAN_LIST_ReleaseActorResources(struct ZukanList *p)
{
    unsigned slot;
    for(slot=0;slot<36;slot++)if(p->charHandles[slot]!=-1)CLACT_ReleaseCharacter(p->charHandles[slot]);
    for(slot=0;slot<6;slot++)if(p->paletteHandles[slot]!=-1)CLACT_ReleasePalette(p->paletteHandles[slot]);
    for(slot=0;slot<6;slot++)if(p->cellAnimHandles[slot]!=-1)CLACT_ReleaseCellAnim(p->cellAnimHandles[slot]);
}

void ZUKAN_LIST_CreateActors(struct ZukanList *p)
{
    unsigned actorIndex;
    struct ClactActorDesc desc;
    p->clactUnit = CLACT_CreateUnit(60, 0, 0x6b);
    for (actorIndex = 0; actorIndex < 60; actorIndex++)
        p->actors[actorIndex] = 0;
    for (actorIndex = 0; actorIndex <= 9; actorIndex++) {
        desc = gZukanListActorDescTable[actorIndex];
        desc.charIndex = p->charHandles[desc.charIndex];
        desc.palIndex = p->paletteHandles[desc.palIndex];
        desc.animIndex = p->cellAnimHandles[desc.animIndex];
        p->actors[actorIndex] = ZUKAN_CreateActor((u32)(p->clactUnit), (const u8 *)(&desc), 0x6b);
        CLACT_SetActorVisible((void *)p->actors[actorIndex], 0);
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
    } else if (GAME_DATA_ContainsRecentId(*(int *)p->args, 15) == 1)
        ZUKAN_LIST_StartActorAnim(p, 5, 7);
}

void ZUKAN_LIST_DeleteActor(struct ZukanList *p,u32 actorIndex) {char *actorTable;u32 actorOffset;actorOffset=actorIndex*4;actorTable=(char *)p+0xa74;if(*(struct Obj **)(actorTable+actorOffset)) {CLACT_DeleteActor(*(struct Obj **)(actorTable+actorOffset));*(struct Obj **)(actorTable+actorOffset)=0;}}

void ZUKAN_LIST_DeleteActorUnit(struct ZukanList *p) {u32 actorIndex;for(actorIndex=0;actorIndex<60;actorIndex++) ZUKAN_LIST_DeleteActor(p,actorIndex);CLACT_DeleteUnit((struct Bank *)p->clactUnit);}

void ZUKAN_LIST_LoadSpeciesIcon(struct ZukanList *p,u16 species)
{
    struct ClactActorDesc desc;
    unsigned out1,outForm,out2;
    unsigned otherSlot,actorIndex,paletteBase;
    void *personal;
    desc=gZukanListActorDesc;
    if (p->status.bits.side==0) {
        otherSlot=59; actorIndex=58; paletteBase=0x160;
    } else {
        otherSlot=58; actorIndex=59;
        desc.charIndex=33; desc.palIndex=3; desc.animIndex=3;
        paletteBase=0x180;
    }
    if (*(unsigned *)((char *)p+0xa74+actorIndex*4)!=0) {
        ZUKAN_LIST_DeleteActor(p,actorIndex);
        if (*(unsigned *)((char *)p+desc.charIndex*4+0xb64)!=(unsigned)-1)
            CLACT_ReleaseCharacter(*(unsigned *)((char *)p+desc.charIndex*4+0xb64));
        if (*(unsigned *)((char *)p+desc.palIndex*4+0xbf4)!=(unsigned)-1)
            CLACT_ReleasePalette(*(unsigned *)((char *)p+desc.palIndex*4+0xbf4));
        if (*(unsigned *)((char *)p+desc.animIndex*4+0xc0c)!=(unsigned)-1)
            CLACT_ReleaseCellAnim(*(unsigned *)((char *)p+desc.animIndex*4+0xc0c));
    }
    if (species==0) {
        void *arc;
        arc=ARC_TOOL_CreateHandle(0x9f,0x806b);
        *(unsigned *)((char *)p+desc.charIndex*4+0xb64)=CLACT_RegisterCharacter(arc,0x36,0,0,0x6b);
        *(unsigned *)((char *)p+desc.palIndex*4+0xbf4)=CLACT_RegisterPaletteEx(arc,0x32,0,(u16)paletteBase,0,1,0x6b);
        *(unsigned *)((char *)p+desc.animIndex*4+0xc0c)=CLACT_RegisterCellAnim(arc,0x3c,0x46,0x6b);
        ARC_TOOL_DeleteHandle(arc);
        ZUKAN_LIST_SetActorVisible(p,2,0);
    } else {
        void *arc;
        unsigned personality;
        ZUKAN_SAVE_GetViewGenderAndForm(*(u8 * *)&p->args->save,species,&out1,&out2,&outForm,0x806b);
        arc=(void *)POKEGRA_OpenHandle(0x806b);
        personality=species==0x147?ZUKAN_SAVE_GetSpindaPersonality(p->args->save,0):0;
        *(unsigned *)((char *)p+desc.charIndex*4+0xb64)=POKEGRA_RegisterCgr((u32)arc,species,outForm,out1,out2,0,0,personality,0,0x6b);
        *(unsigned *)((char *)p+desc.palIndex*4+0xbf4)=POKEGRA_RegisterPalette((int)arc,species,outForm,out1,out2,0,0,0,paletteBase,0x6b);
        *(unsigned *)((char *)p+desc.animIndex*4+0xc0c)=POKEGRA_RegisterCellAnim(species,outForm,out1,out2,0,0,2,0,0x6b);
        ARC_TOOL_DeleteHandle(arc);
        ZUKAN_LIST_SetActorVisible(p,2,1);
    }
    desc.charIndex=*(unsigned *)((char *)p+desc.charIndex*4+0xb64);
    desc.palIndex=*(unsigned *)((char *)p+desc.palIndex*4+0xbf4);
    desc.animIndex=*(unsigned *)((char *)p+desc.animIndex*4+0xc0c);
    *(void **)((char *)p+0xa74+actorIndex*4)=ZUKAN_CreateActor((u32)(p->clactUnit),(const u8 *)(&desc),0x6b);
    CLACT_SetActorVisible(*(void **)((char *)p+0xa74+actorIndex*4),0);
    personal=POKE_PERSONAL_Create(species,(u16)outForm,0x806b);
    if (species!=0 && POKE_PERSONAL_GetParam(personal,0x22)==0)
        CLACT_SetActorFlip(*(void **)((char *)p+0xa74+actorIndex*4),1,1);
    POKE_PERSONAL_Delete(personal);
    ZUKAN_LIST_SetActorVisible(p,otherSlot,0);
    PALANM_CopyHwPaletteToSlot(p->palAnm,2,(u16)((paletteBase>>5)<<4),0x20);
    p->status.bits.side^=1;
}

void ZUKAN_LIST_UpdateSpeciesActors(struct ZukanList *p) {
    struct ClactSpeciesActor proto;
    struct ClactSpeciesActor desc;
    u32 *unitPtr;
    u32 rowUpper;
    u32 rowLower;
    u32 rowHide;
    proto = gZukanListSpeciesActor;
    desc = gZukanListSpeciesActor;
    desc.palHandle = *(u32 *)((char *)p + 0xBF4);
    desc.animHandle = *(u32 *)((char *)p + 0xC0C);
    for (rowUpper = 0; rowUpper < 16; rowUpper++) {
        desc.posY = rowUpper * 0x18 + 8;
        desc.charHandle = *(u32 *)((char *)p + rowUpper * 4 + 0xB64);
        *(u32 *)((char *)p + rowUpper * 4 + 0xA9C) = (u32)ZUKAN_CreateActor(*(u32 *)((char *)p + 0xA70), (const u8 *)(&desc), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)((char *)p + rowUpper * 4 + 0xA9C)), 0);
    }
    desc = proto;
    desc.palHandle = *(u32 *)((char *)p + 0xBF8);
    desc.animHandle = *(u32 *)((char *)p + 0xC10);
    for (rowLower = 0; rowLower < 16; rowLower++) {
        desc.posY = rowLower * 0x18 + 0x20;
        desc.charHandle = *(u32 *)((char *)p + rowLower * 4 + 0xBA4);
        desc.flags = 1;
        *(u32 *)((char *)p + rowLower * 4 + 0xADC) = (u32)ZUKAN_CreateActor(*(u32 *)((char *)p + 0xA70), (const u8 *)(&desc), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)((char *)p + rowLower * 4 + 0xADC)), 0);
        ZUKAN_LIST_SetActorObjMode(p, rowLower + 0x1a, 1);
        unitPtr = (u32 *)((char *)p + 0xA70);
        *(u32 *)((char *)p + rowLower * 4 + 0xB1C) = (u32)ZUKAN_CreateActor(*unitPtr, (const u8 *)(&desc), 0x6b);
        CLACT_SetActorVisible((struct Actor *)(*(u32 *)((char *)p + rowLower * 4 + 0xB1C)), 0);
        CLACT_SetActorObjMode((struct Actor *)(*(u32 *)((char *)p + rowLower * 4 + 0xB1C)), 2);
    }
    for (rowHide = 0; rowHide < 16; rowHide++) ZUKAN_LIST_SetActorVisible(p, rowHide + 0xa, 0);
    for (rowUpper = 0; rowUpper < 16; rowUpper++) {
        ZUKAN_LIST_SetActorVisible(p, rowUpper + 0x1a, 0);
        ZUKAN_LIST_SetActorVisible(p, rowUpper + 0x2a, 0);
    }
}

void ZUKAN_LIST_TransferSpeciesGraphics(struct ZukanList *p, int actorIndex, unsigned species, u16 form, u16 charHalf, int mode)
{
    void *owner;
    void *data;
    struct ClactPartData *out;
    struct Obj **slot;
    unsigned charHalfSaved;
    owner=ARC_TOOL_CreateHandle(7,0x806b);
    charHalfSaved=charHalf;
    data=ARC_UTIL_LoadScreenDataFromHandle((void *)((unsigned)owner),POKE_TOOL_CalcGraphicIndex(species,form,charHalfSaved,0),0,(unsigned)&out,0x806b);
    if (mode==1) {
        slot=&p->actors[actorIndex];
        CLACT_TransferCharacterPart(CLACT_GetActorCharacterIndex((u8 *)*slot),out->part,1024,0,0);
    } else {
        slot=&p->actors[actorIndex];
        CLACT_TransferCharacterPart(CLACT_GetActorCharacterIndex((u8 *)*slot),out->part,1024,0,1);
    }
    GFL_HEAP_Free(data);
    ARC_TOOL_DeleteHandle(owner);
    CLACT_SetActorPaletteOffset(*slot,POKE_TOOL_CalcIconPalette(species,form,charHalfSaved,0),1);
}

int ZUKAN_LIST_FindHiddenSpeciesActor(struct ZukanList *list, int group)
{
    unsigned int actorIndex;

    if (group == 1) {
        for (actorIndex = 0xa; actorIndex < 0x1a; actorIndex++) {
            if (ZUKAN_LIST_GetActorVisible(list, actorIndex) == 0) {
                return actorIndex;
            }
        }
    } else {
        for (actorIndex = 0x1a; actorIndex < 0x2a; actorIndex++) {
            if (ZUKAN_LIST_GetActorVisible(list, actorIndex) == 0) {
                return actorIndex;
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
    int actorIndex;
    ZUKAN_SAVE_GetViewGenderAndForm((u8 *)p->args->save,species,&out1,&out2,&outForm,0x806b);
    actorIndex=ZUKAN_LIST_FindHiddenSpeciesActor(p,mode);
    ZUKAN_LIST_TransferSpeciesGraphics(p,actorIndex,species,outForm,out1,mode);
    ZUKAN_LIST_SetActorVisible(p,actorIndex,1);
    ZUKAN_LIST_StartActorAnim(p,actorIndex,0);
    if (mode==1) {
        pos+=8;
        ZUKAN_LIST_AddActorPos(p,actorIndex,112,pos,0);
        return;
    }
    pos+=8;
    ZUKAN_LIST_AddActorPos(p,actorIndex,112,pos,1);
    ZUKAN_LIST_AddActorPos(p,actorIndex+16,112,pos,1);
    actorIndex+=16;
    ZUKAN_LIST_SetActorVisible(p,actorIndex,1);
}

void ZUKAN_LIST_ScrollActorsBy(struct ZukanList *p, int delta)
{
    unsigned actorIndex;
    short pos[2];
    for (actorIndex = 10; actorIndex < 26; actorIndex++) {
        if (ZUKAN_LIST_GetActorVisible(p, actorIndex) != 0) {
            ZUKAN_LIST_GetActorPos(p, actorIndex, &pos[1], &pos[0], 0);
            ZUKAN_LIST_AddActorPos(p, (unsigned)actorIndex, (short)pos[1], (short)(pos[0] + delta), 0);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200)
                ZUKAN_LIST_SetActorVisible(p, actorIndex, 0);
        }
    }
    for (actorIndex = 26; actorIndex < 42; actorIndex++) {
        if (ZUKAN_LIST_GetActorVisible(p, actorIndex) != 0) {
            ZUKAN_LIST_GetActorPos(p, actorIndex, &pos[1], &pos[0], 1);
            ZUKAN_LIST_AddActorPos(p, (unsigned)actorIndex, (short)pos[1], (short)(pos[0] + delta), 1);
            ZUKAN_LIST_AddActorPos(p, (unsigned)(actorIndex + 16), (short)pos[1], (short)(pos[0] + delta), 1);
            if (pos[0] + delta <= -16 || pos[0] + delta >= 200) {
                ZUKAN_LIST_SetActorVisible(p, actorIndex, 0);
                ZUKAN_LIST_SetActorVisible(p, actorIndex + 16, 0);
            }
        }
    }
}

void ZUKAN_LIST_HideAllActors(struct ZukanList *p)
{
    unsigned actorIndex;
    p->hiddenMaskA=0;
    p->hiddenMaskB=0;
    for(actorIndex=10;actorIndex<26;actorIndex++)if(ZUKAN_LIST_GetActorVisible(p,actorIndex))p->hiddenMaskA|=(u16)(1<<(actorIndex-10));
    for(actorIndex=26;actorIndex<42;actorIndex++)if(ZUKAN_LIST_GetActorVisible(p,actorIndex))p->hiddenMaskB|=(u16)(1<<(actorIndex-26));
}

void ZUKAN_LIST_ShowAllActors(struct ZukanList *p)
{
    unsigned actorIndex;
    for(actorIndex=10;actorIndex<26;actorIndex++)if(p->hiddenMaskA&(1<<(actorIndex-10)))ZUKAN_LIST_SetActorVisible(p,actorIndex,0);
    for(actorIndex=26;actorIndex<42;actorIndex++)if(p->hiddenMaskB&(1<<(actorIndex-26))){ZUKAN_LIST_SetActorVisible(p,actorIndex,0);ZUKAN_LIST_SetActorVisible(p,actorIndex+16,0);}
    p->hiddenMaskA=0;
    p->hiddenMaskB=0;
}

/*
 * Row expression assigned back to index keeps the entry register; 021BE586 is two zero alignment bytes.
 */
void ZUKAN_LIST_MoveCursorActor(struct ZukanList *p,int index)
{
    unsigned actorIndex;
    short pos[2];
    index=index*24+8;
    for(actorIndex=10;actorIndex<26;actorIndex++){
        if(ZUKAN_LIST_GetActorVisible(p,actorIndex)==0)ZUKAN_LIST_StartActorAnim(p,actorIndex,0);
        else{
            ZUKAN_LIST_GetActorPos(p,actorIndex,&pos[1],&pos[0],0);
            if(index==pos[0]){if(ZUKAN_LIST_GetActorAnimSeq(p,actorIndex)!=1)ZUKAN_LIST_StartActorAnim(p,actorIndex,1);}
            else ZUKAN_LIST_StartActorAnim(p,actorIndex,0);
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
    int cursor=FRAME_LIST_GetCursor(p->frameList);
    if (ZUKAN_LIST_GetActorAnimSeq(p,7)!=12 || flag==0) {
        if (FRAME_LIST_GetScrollPos(p->frameList)==0 && cursor==0)
            ZUKAN_LIST_StartActorAnim(p,7,18);
        else ZUKAN_LIST_StartActorAnim(p,7,4);
    }
    if (ZUKAN_LIST_GetActorAnimSeq(p,6)!=13 || flag==0) {
        if (FRAME_LIST_CanScrollDown(p->frameList)==0 && cursor==p->rowCount-1) {
            ZUKAN_LIST_StartActorAnim(p,6,19);
            return;
        }
        else ZUKAN_LIST_StartActorAnim(p,6,5);
    }
}

extern int TOUCHPANEL_HitTrg(const void *p);

extern u32 KEY_GetTrg(void);

extern void FRAME_LIST_HideCursor(u32);

extern int FRAME_LIST_ShowCursor(u8 *p);

int ZUKAN_LIST_HandleTouchInput(struct ZukanList *p)
{
    int hit = TOUCHPANEL_HitTrg((void *)0x021BEAE0);

    if (hit != -1) {
        if (hit == 8) {
            if (ZUKAN_SAVE_GetDexObtained(p->args->save) == 0)
                return -1;
        }
        if (hit == 9) {
            if (ZUKAN_SAVE_IsNationalDexEnabled(p->args->save) == 0)
                return -1;
            if (p->args->mode == 1)
                return -1;
        }
        if (hit == 0xa) {
            if (p->args->mode == 1)
                return -1;
            if (UI_GetInputMode() == 0) {
                UI_SetInputMode(1);
                FRAME_LIST_HideCursor((u32)p->frameList);
            }
        }
        UI_SetInputMode(1);
        return hit;
    } else {
        if (KEY_GetTrg() & 2) {
            UI_SetInputMode(0);
            return 0xc;
        }
        if (KEY_GetTrg() & 0x400) {
            UI_SetInputMode(0);
            return 0xb;
        }
        if (KEY_GetTrg() & 8) {
            if (ZUKAN_SAVE_GetDexObtained(p->args->save) == 1) {
                UI_SetInputMode(0);
                return 8;
            }
        }
        if (KEY_GetTrg() & 4) {
            if (ZUKAN_SAVE_IsNationalDexEnabled(p->args->save) == 0)
                return -1;
            if (p->args->mode == 1)
                return -1;
            UI_SetInputMode(0);
            return 9;
        }
        if (KEY_GetTrg() & 0x800) {
            if (p->args->mode == 1)
                return -1;
            if (UI_GetInputMode() == 1) {
                UI_SetInputMode(0);
                FRAME_LIST_ShowCursor((u8 *)((u32)p->frameList));
            } else {
                UI_SetInputMode(0);
            }
            return 0xa;
        }
        return hit;
    }
}
