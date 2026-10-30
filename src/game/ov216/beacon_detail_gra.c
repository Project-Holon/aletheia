/*
 * file:     beacon_detail_gra.c
 * unit:     yes
 * function: BEACON_DETAIL_GRA_Init, BEACON_DETAIL_GRA_Exit, BEACON_DETAIL_GRA_Main, BEACON_DETAIL_GRA_StateInteract, BEACON_DETAIL_GRA_StateClose, BEACON_DETAIL_GRA_StateInit, BEACON_DETAIL_GRA_StateFadeIn, BEACON_DETAIL_GRA_StateFadeOut, BEACON_DETAIL_GRA_LoadBeaconInfo, BEACON_DETAIL_GRA_Delete, BEACON_DETAIL_GRA_CreateObjects, BEACON_DETAIL_GRA_DeleteObjects, BEACON_DETAIL_GRA_LoadBackground, BEACON_DETAIL_GRA_FreeBackground, BEACON_DETAIL_GRA_CreateTouchBar, BEACON_DETAIL_GRA_DeleteTouchBar, BEACON_DETAIL_GRA_UpdateTouchBar, BEACON_DETAIL_GRA_RegisterActorGfx, BEACON_DETAIL_GRA_ReleaseActorGfx, BEACON_DETAIL_GRA_LoadTrainerGfx, BEACON_DETAIL_GRA_FreeTrainerGfx, BEACON_DETAIL_GRA_CreateWindow, BEACON_DETAIL_GRA_CreatePositionedActor, BEACON_DETAIL_GRA_CreateDetailActors, BEACON_DETAIL_GRA_DeleteDetailActors, BEACON_DETAIL_GRA_CreateInfoWindow, BEACON_DETAIL_GRA_DeleteInfoWindow, BEACON_DETAIL_GRA_CreateListWindows, BEACON_DETAIL_GRA_DeleteListWindows, BEACON_DETAIL_GRA_IsPmsActive, BEACON_DETAIL_GRA_Create, BEACON_DETAIL_GRA_Destroy, BEACON_DETAIL_GRA_Draw, BEACON_DETAIL_GRA_GetClactUnit, BEACON_DETAIL_GRA_Task, BEACON_DETAIL_GRA_InitBgSystem, BEACON_DETAIL_GRA_ExitBgSystem, BEACON_DETAIL_GRA_Noop, BEACON_DETAIL_GRA_UpdateBg, BEACON_DETAIL_GRA_InitClact, BEACON_DETAIL_GRA_ExitClact, BEACON_DETAIL_GRA_DrawClact, BEACON_DETAIL_GRA_VBlankClact, BEACON_DETAIL_GRA_ReadPtr, BEACON_DETAIL_GRA_SetupBeaconList, BEACON_DETAIL_GRA_UpdateInteract, BEACON_DETAIL_GRA_RefreshButtons, BEACON_DETAIL_GRA_IsTouchOnActor, BEACON_DETAIL_GRA_PlaySe, BEACON_DETAIL_GRA_LoadPalette, BEACON_DETAIL_GRA_UpdateButtons, BEACON_DETAIL_GRA_GetPmVersionClass, BEACON_DETAIL_GRA_FindAppearanceType, BEACON_DETAIL_GRA_SetNameSlots, BEACON_DETAIL_GRA_SetActorAnim, BEACON_DETAIL_GRA_SetActorPos, BEACON_DETAIL_GRA_PrintMsg, BEACON_DETAIL_GRA_TransferChar, BEACON_DETAIL_GRA_InitWindows, BEACON_DETAIL_GRA_DrawWindowRecord, BEACON_DETAIL_GRA_SetSlotVisible, BEACON_DETAIL_GRA_MoveActor, BEACON_DETAIL_GRA_SetupSlot, BEACON_DETAIL_GRA_UpdateSlotInfo, BEACON_DETAIL_GRA_AddFadeTask, BEACON_DETAIL_GRA_Callback, BEACON_DETAIL_GRA_AddTimerTask, BEACON_DETAIL_GRA_AddTimerTaskEx, BEACON_DETAIL_GRA_UpdateTimer, BEACON_DETAIL_GRA_TimerCallback, BEACON_DETAIL_GRA_AddSlideTask, BEACON_DETAIL_GRA_SlideCallback, BEACON_DETAIL_GRA_AddSlotSlideTask, BEACON_DETAIL_GRA_AddSlotSlideTaskEx, BEACON_DETAIL_GRA_SlotSlideCallback, BEACON_DETAIL_GRA_DrawRecord, BEACON_DETAIL_GRA_AddPrintWaitTask, BEACON_DETAIL_GRA_PrintWaitTask
 * address:  0x021BBD80
 * region:   ov216
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
 *   ov067_id 0x00000043 data
 *   ov072_id 0x00000048 data
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   TCBL_Main 0x020310C4 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   PRINTSYS_QUE_IsFinished 0x0201C6B4 thumb
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   TOUCHBAR_GetPressedButtonIdIfDone 0x021B6448 thumb ov067
 *   GAME_BEACON_ACCESSOR_AllocInfo 0x02165B10 thumb ov010
 *   GAME_DATA_GetItemUseWork 0x02012A54 thumb
 *   BEACON_STATUS_GetLog 0x020275A8 thumb
 *   GAME_BEACON_ACCESSOR_TableGetCount 0x02165B04 thumb ov010
 *   GAME_BEACON_ACCESSOR_TableRingGet 0x02165AC4 thumb ov010
 *   GAME_BEACON_ACCESSOR_IsInfoInvalid 0x02165B5C thumb ov010
 *   GAME_BEACON_ACCESSOR_IsDistributionAction 0x02165C10 thumb ov010
 *   MSG_SPEED_GetWait 0x02012FFC thumb
 *   TOWNMAP_GRH_LoadTownInfo 0x021BBB24 thumb ov072
 *   TOWNMAP_GRH_FreeTownInfo  0x021BBB34  thumb  ov072
 *   GFL_HEAP_Free  0x020307B0  arm
 *   TCBL_Create 0x0203101C arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_QUE_CreateEx 0x0201C450 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   WORDSET_Create 0x0201EC74 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   NNS_G2dGetUnpackedPaletteData 0x02062A98 arm
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   d_021BDB4C 0x021BDB4C data a4
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 *   TOUCHBAR_Update 0x021B63D0 thumb ov067
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   sBeaconDetailGraConfigA 0x021BDB28 data a2
 *   sBeaconDetailGraConfigB 0x021BDB34 data a2
 *   POKEGRA_OpenTrainerHandle 0x0202DA04 thumb
 *   NNS_G2dGetUnpackedCharacterData 0x02062A00 arm
 *   POKEGRA_RegisterTrainerCgr 0x0202DA48 thumb
 *   POKEGRA_RegisterTrainerPalette 0x0202DA18 thumb
 *   POKEGRA_RegisterTrainerCellAnim 0x0202DA6C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   PMS_DRAW_Create 0x0202DB0C thumb
 *   PMS_DRAW_SetNullColorPalette 0x0202DE5C thumb
 *   PMS_DRAW_SetPrintColor 0x0202DE64 thumb
 *   PMS_DRAW_SetFollowBgScroll 0x0202DE68 thumb
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PMS_DRAW_Main  0x0202DBC4  thumb
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetLcdSwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   BG_SYS_ClearSubPlanes 0x02043588 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   d_021BDDC0 0x021BDDC0 data a1
 *   d_021BDBD8 0x021BDBD8 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   d_021BDBAC 0x021BDBAC data a4
 *   d_021BDC28 0x021BDC28 data a4
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   BG_SYS_Update 0x020419E4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_CreateRenderer 0x0204B034 arm
 *   CLACT_SetRendererCulling 0x0204B0F4 arm
 *   CLACT_SetUnitRenderer 0x0204B258 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_021BDBBC 0x021BDBBC data a4
 *   d_021BDC08 0x021BDC08 data a4
 *   CLACT_DeleteRenderer 0x0204B084 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   MI_CpuFill8   0x02082BCC arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   GAMESYSTEM_IsNetOffBySleep 0x02012204 thumb
 *   TOUCHBAR_GetPressedButtonIdIfPressing 0x021B6470 thumb ov067
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   DC_FlushRange 0x020862F0 arm
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   GXS_LoadBGPltt 0x0207E468 arm
 *   GX_LoadOBJPltt 0x0207E51C arm
 *   GXS_LoadOBJPltt 0x0207E5D0 arm
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 *   GAME_BEACON_ACCESSOR_GetPmVersion  0x02165C48  thumb  ov010
 *   d_021BDDA2 0x021BDDA2 data a1
 *   GAME_BEACON_ACCESSOR_GetDetailsType 0x02165DAC thumb ov010
 *   GAME_BEACON_ACCESSOR_GetDetailsMonsNo 0x02165DF0 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetDetailsTrainerNo 0x02165DBC thumb ov010
 *   GAME_BEACON_ACCESSOR_GetZoneId 0x02165D28 thumb ov010
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   CLACT_RestartActorAnim  0x0204B9A0  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   CLACT_TransferCharacter 0x0204A9D0 arm
 *   d_021BDD92 0x021BDD92 data a1
 *   d_021BDD8A 0x021BDD8A data a2
 *   BMP_FillRect 0x02043AF4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   PMS_DRAW_IsActive 0x0202DCC4 thumb
 *   PMS_DRAW_SetVisible 0x0202DCB0 thumb
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   GAME_BEACON_ACCESSOR_GetFavoriteColorRgb 0x02165CC0 thumb ov010
 *   PALANM_BlendColors 0x02021F64 thumb
 *   GAME_BEACON_ACCESSOR_GetPlayerName 0x02165C34 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond 0x02165C60 thumb ov010
 *   STRBUF_Clear 0x0204581C arm
 *   WORDSET_SetSlotFromMsg38 0x0201F1C8 thumb
 *   GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst 0x02165C78 thumb ov010
 *   WORDSET_SetSlotFromMsg2B 0x0201F198 thumb
 *   GAME_BEACON_ACCESSOR_GetPlayTime 0x02165D10 thumb ov010
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   GAME_BEACON_ACCESSOR_GetNation 0x02165C58 thumb ov010
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   GAME_BEACON_ACCESSOR_GetArea 0x02165C5C thumb ov010
 *   WORDSET_SetSlotFromKeyedMessage 0x0201F094 thumb
 *   GAME_BEACON_ACCESSOR_GetPassCount 0x02165D40 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetThanksCount 0x02165D48 thumb ov010
 *   PMS_DRAW_IsActive 0x0202DCC4 thumb
 *   PMS_DRAW_Clear 0x0202DC9C thumb
 *   GAME_BEACON_ACCESSOR_GetDetailsPms 0x02165C90 thumb ov010
 *   PMS_DRAW_Print 0x0202DC48 thumb
 *   GAME_BEACON_ACCESSOR_GetTrainerAppearance 0x02165CE8 thumb ov010
 *   CURSOR_MOVE_GetTableGroup 0x02025C88 thumb
 *   POKEGRA_LoadTrainerGraphics 0x0202DAA4 thumb
 *   GAME_BEACON_ACCESSOR_GetResearchTeamRank 0x02165CB4 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetTownmapRootZoneId 0x02165D34 thumb ov010
 *   TOWNMAP_GRH_FindRecordIndex 0x021BBB48 thumb ov072
 *   TOWNMAP_GRH_GetTownInfoValue 0x021BBB3C thumb ov072
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   TCBL_DeleteTask 0x02031194 arm
 *   TOUCHBAR_SetAllButtonsEnabled 0x021B64A8 thumb ov067
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TCBL_DeleteTask 0x02031194 arm
 *   d_021BDD88 0x021BDD88 data a1
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   TCBL_AddTask 0x020311B8 arm
 *   TCBL_GetWork 0x02031290 arm
 *   BEACON_DETAIL_GRA_PrintWaitTask 0x021BDAD8 thumb ov216
 *   PMS_DRAW_Delete  0x0202DC08  thumb  arm9
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb  arm9
 *   WORDSET_SetSlotSpeciesName  0x0201EE60  thumb  arm9
 *   WORDSET_SetSlotPokeData  0x0201F104  thumb  arm9
 *   WORDSET_SetSlotFromMsgBE  0x0201F134  thumb  arm9
 *   WORDSET_SetSlotFromMsg59  0x0201F158  thumb  arm9
 *   GFL_USE_AddMainTask  0x020056A0  thumb  arm9
 *   PRINTSYS_QUE_IsExistTarget   0x0201C6C4  thumb
 */

#define CALLS(r) do { void *d = (r)->window; BMP_WIN_TransferChars(d); BMP_WIN_MakeScreen(d); BG_SYS_PushTile(BMP_WIN_GetBgLayer(d)); } while (0)
struct ProcOwner;
struct GflHeap;
struct Tcbl;
struct PrintSys;
struct Queue;
struct GameData;
struct GfFont;
struct WordSet;
struct MsgBank;
struct U16Vec;
struct Tcbl;
struct ArcFile;
struct NitroFileHeader;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct ClactActor;
struct Actor;
struct Node;
struct Bank;
struct Ctx;
struct Bits;
struct Vec2;
struct BeaconDetailGraTransfer;
struct Bmp;
struct TcblTask;
struct Tcbl;
#include "../version.h"

/* The play time line of a slot: its first tile column and width in tiles differ per language. */
#if LANGUAGE == LANGUAGE_JAPANESE
#define BEACON_DETAIL_PLAYTIME_TILE_X 9
#define BEACON_DETAIL_PLAYTIME_TEXT_X 0
#define BEACON_DETAIL_PLAYTIME_WIDTH 10
#elif LANGUAGE == LANGUAGE_SPANISH
#define BEACON_DETAIL_PLAYTIME_TILE_X 7
#define BEACON_DETAIL_PLAYTIME_WIDTH 12
#elif LANGUAGE == LANGUAGE_FRENCH
#define BEACON_DETAIL_PLAYTIME_TILE_X 10
#define BEACON_DETAIL_PLAYTIME_WIDTH 9
#elif LANGUAGE == LANGUAGE_GERMAN
#define BEACON_DETAIL_PLAYTIME_TILE_X 9
#define BEACON_DETAIL_PLAYTIME_WIDTH 10
#elif LANGUAGE == LANGUAGE_ITALIAN
#define BEACON_DETAIL_PLAYTIME_TILE_X 12
#define BEACON_DETAIL_PLAYTIME_WIDTH 7
#else
#define BEACON_DETAIL_PLAYTIME_TILE_X 6
#define BEACON_DETAIL_PLAYTIME_WIDTH 13
#endif
#ifndef BEACON_DETAIL_PLAYTIME_TEXT_X
#define BEACON_DETAIL_PLAYTIME_TEXT_X (BEACON_DETAIL_PLAYTIME_TILE_X * 8)
#endif

#include "../arm9/arc_tool.h"
#include "../sdk_ioreg.h"
#include "../arm9/arc_util.h"
#include "../arm9/pokegra.h"
#include "../types.h"

struct BeaconDetailGraQuad;
#include "../arm9/clact.h"
#include "../arm9/bg_sys_types.h"

struct TouchBarParam { unsigned char *f0; unsigned f4; int f8; unsigned fC,f10,f14; int f18,f1c; };

struct BeaconDetailGraPosition { short x,y,z; unsigned char a,b; };

struct BeaconDetailGraBgEntry { unsigned id; char fields[32]; unsigned a,b; };

struct BeaconDetailGraRenderBlock { unsigned w[8]; };

enum BeaconDetailIndex { IndexZero=0 };

struct BeaconDetailGraPair { u16 a,b; };

struct BeaconDetailGraQuad { u16 a,b,c,d; };

#include "../arm9/tcbl.h"

struct BeaconDetailGraPrintTask { void *arg; u8 *owner; int *counter; };

/*
 * One real struct per object in this overlay.  The old per-function
 * ObjNNNNN matched-include views are folded into these.
 */
struct ProcOwner;              /* PROCSYS_AllocProcWork owner (0x0203159C) */
struct GflHeap;                /* GFL heap handle (0x020315D4) */
struct GameBeaconRecord;       /* one GAME_BEACON_ACCESSOR record */
struct BeaconDetailGraTransfer; /* CLACT_TransferCharacter arg (0x0204A9D0) */

/* CLACT palette/character/cellanim descriptor (sBeaconDetailGraConfigA/sBeaconDetailGraConfigB). */
struct ClactResConfig { u8 a,b,c,pad; u16 first,second,third; };

/* A BMP window plus its back buffer and blit source. 16 bytes. */
struct BeaconDetailGraWindow {
    struct Descriptor *window;
    struct CharBuf *buffer;
    struct Descriptor *copy;
    u8 state;
};

/* Colour/palette pair from d_021BDD8A. 4 bytes. */
struct BeaconDetailGraColorPair { u16 color; u8 index, pad; };

/* A registered CLACT palette/character/cellanimation triple. 12 bytes. */
struct BeaconDetailGraActor { u32 palette; u32 character; u32 cellAnim; };

/* A loaded graphic resource: unpacked data and its archive handle. 8 bytes. */
struct BeaconDetailGraGfx { void *data; void *handle; };

/* The 16-byte graphics system block allocated by Create (main->clactObj). */
struct BeaconDetailGraGfxSys { u32 bgInit; void *clactUnit; void *clactRenderer; void *task; };

/* A BMP window handle, viewed as a pointer or as a word. */
union BeaconDetailGraWin { void *window; void *handle; };

/* One of the two 128-byte detail pages. */
struct BeaconDetailGraEntry {
    struct BeaconDetailGraWindow win[4]; /* 0x00 */
    struct BeaconDetailGraWindow winA;   /* 0x40 */
    struct BeaconDetailGraWindow winB;   /* 0x50 */
    struct BeaconDetailGraWindow winC;   /* 0x60 */
    union BeaconDetailGraWin iconWindow; /* 0x70 */
    void *actorA;                        /* 0x74 */
    void *actorB;                        /* 0x78 */
    u8 appearance;                       /* 0x7C */
    u8 hasSecondActor;                   /* 0x7D */
    u8 layer;                            /* 0x7E */
    u8 pad_7F;
};

/* Tail of a drawn window record. */
struct BeaconDetailGraWinTarget { void *window; u8 pending; };
struct BeaconDetailGraWinRecord { void *f0; void *f4; struct BeaconDetailGraWinTarget target; };

/* The CLACT unit/renderer block (main->clactObj + 4). */
struct BeaconDetailGraClact { void *unit; void *renderer; };

/* The config object passed to Init (main->config), mode at +9. */
struct GameSystem;
struct GameData;
struct BeaconDetailGraConfig { struct GameSystem *gameSystem; struct GameData *gameData; u8 selected; u8 mode; };

/* An unpacked G2d resource; the payload pointer lives at +0xC. */
struct BeaconDetailGraRes { u8 pad_00[12]; void *data; };

union BeaconDetailGraFont { void *ptr; void *handle; };
union BeaconDetailGraTrainer { void *handle; void *set; };

/* The main 620-byte beacon-detail graphics work object. */
struct BeaconDetailGraWork {
    u16 heapId;            /* 0x000 */
    u16 gfxHeapId;         /* 0x002 */
    int state;             /* 0x004 */
    u8 pad_08[4];
    int subMode;           /* 0x00C */
    int fadeMode;          /* 0x010 */
    struct BeaconDetailGraConfig *config; /* 0x014 */
    void *tcbl;            /* 0x018 */
    void *townInfo;        /* 0x01C */
    void *itemUseWork;     /* 0x020 */
    void *infoQueue;       /* 0x024 */
    void *beaconRecord;    /* 0x028 */
    u16 level;             /* 0x02C */
    u8 slotIndex;          /* 0x02E */
    u8 slotMax;            /* 0x02F */
    u8 cursor;             /* 0x030 */
    u8 slotOrder[16];      /* 0x031 */
    u8 pad_41[14];
    u8 msgWait;            /* 0x04F */
    void *clactObj;        /* 0x050 */
    void *arcFile;         /* 0x054 */
    union BeaconDetailGraTrainer trainer; /* 0x058 */
    struct BeaconDetailGraActor actors[4]; /* 0x05C */
    struct BeaconDetailGraGfx gfxChars[16]; /* 0x08C */
    void *paletteFile;     /* 0x10C */
    void *paletteData;     /* 0x110 */
    void *paletteHandle;   /* 0x114 */
    void *charFile;        /* 0x118 */
    void *charData;        /* 0x11C */
    void *charHandle;      /* 0x120 */
    void *touchBar;        /* 0x124 */
    union BeaconDetailGraFont font; /* 0x128 */
    void *printQue;        /* 0x12C */
    void *msgBank;         /* 0x130 */
    void *msgBank2;        /* 0x134 */
    void *wordSet;         /* 0x138 */
    void *textBuf;         /* 0x13C */
    void *textBuf2;        /* 0x140 */
    void *textBuf3;        /* 0x144 */
    struct BeaconDetailGraWindow infoWindow; /* 0x148 */
    void *pmsDraw;         /* 0x158 */
    struct BeaconDetailGraEntry entries[2]; /* 0x15C */
    short mapX;            /* 0x25C */
    short mapY;            /* 0x25E */
    u8 mapVisible;         /* 0x260 */
    u8 pad_261[3];
    void *mapActors[2];    /* 0x264 */
};

/* TCBL task work buffers used by the slide/fade/timer tasks. */
struct BeaconDetailGraFadeTask {
    u8 direction; u8 count; u8 elapsed; s8 position; s8 step; u8 pad_05[3]; int *counter;
};
struct BeaconDetailGraTimerTask {
    u8 step; u8 count; u8 pad_02[2]; int timer; void *owner; int *counter;
};
struct BeaconDetailGraSlideTask {
    u8 index; u8 count; u8 pad_02[2]; s16 offset; s16 delta; u8 pad_08[4]; void *entry; void *owner; int *counter;
};
struct BeaconDetailGraSlotTask {
    u8 step; u8 pad_01[2]; u8 index; u8 direction; u8 flags; u8 pad_06[2]; int wait; u8 pad_0C[4]; void *owner; int *counter;
};

#include "../arm9/gf_overlay.h"
#include "../arm9/gfl_heap.h"
struct Proc;
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gfl_heap_wrap.h"
struct TcblSystem;
extern void TCBL_Main(struct TcblSystem *tcbl);
struct PrintQueue;
extern unsigned PRINTSYS_QUE_Main(struct PrintQueue *queue);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintQueue *queue, struct Bmp *bmp);
#include "../arm9/fade.h"
struct GameBeaconInfo;
#include "../ov010/game_beacon_accessor.h"
#include "../arm9/game_data.h"
struct BeaconStatus;
struct GameBeaconInfoTable;
#include "../arm9/msg_speed.h"
struct TownMapInfoRow;
extern struct TcblSystem *TCBL_Create(u16 heap, u16 tag, unsigned int count, unsigned int workSize);
#include "../arm9/gf_font.h"
extern struct PrintQueue *PRINTSYS_QUE_CreateEx(unsigned short,unsigned);
#include "../arm9/wordset.h"
#include "../arm9/msgdata.h"
struct Strbuf;
#include "../arm9/strbuf.h"
extern void PRINTSYS_QUE_Clear(struct PrintQueue *queue);
extern void PRINTSYS_QUE_Delete(struct PrintQueue *queue);
extern void TCBL_Destroy(struct TcblSystem *tcbl);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32);
struct ArcHandle;
#include "../arm9/nns_g2d_anim_bank.h"
#include "../arm9/g2.h"
/* The DS code passes the heap id as a word (the original prototype); the header takes a halfword. The host build uses the header. */
#ifdef __MWERKS__
#define TOUCHBAR_Create TOUCHBAR_Create_header
#endif
#include "../ov067/touchbar.h"
#ifdef __MWERKS__
#undef TOUCHBAR_Create
extern TouchBar *TOUCHBAR_Create(TouchBarParams *params, int heapId);
#endif
/* The DS code takes the window width as a word and the result as a word (the original prototype); the header has a byte width and returns the window pointer. The host build uses the header. */
#ifdef __MWERKS__
struct BmpWin;
extern struct BmpWin *BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);
extern unsigned PRINTSYS_QUE_IsFinished(struct PrintQueue *queue);
#else
#include "../arm9/bmp_win.h"
#endif
struct BmpWin;
extern struct Bmp *BMP_WIN_GetBmp(struct BmpWin *win);
#include "../arm9/bmp.h"
extern void BMP_WIN_TransferChars(struct BmpWin *win);
extern void BMP_WIN_MakeScreen(struct BmpWin *win);
extern unsigned char BMP_WIN_GetBgLayer(struct BmpWin *win);
extern u32 BMP_WIN_Delete(struct BmpWin *win);
#include "../arm9/pms_draw.h"
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
struct TcbTask;
extern struct TcbTask *GFL_USE_AddMainTask(void (*)(void *,void *), void *work, unsigned int priority);
struct TcbTask;
#include "../arm9/tcb_list.h"
/* The DS code was built against other parameter widths for BG_SYS_Create (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void BG_SYS_Create(int);
#else
#include "../arm9/bg_sys.h"
#endif
extern void BMP_WIN_Init(u32);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(u8,u8);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
struct DispVramCfg;
struct SysInit;
struct SurfaceInit;
struct Renderer;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
#include "../arm9/net.h"
#include "../arm9/key.h"
struct GameSystem;
#include "../arm9/gamesystem.h"
#include "../arm9/touchpanel.h"
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
#include "../arm9/os_cache.h"
#include "../arm9/gx_load2d.h"
#include "../arm9/zonedata.h"
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_ChangeScrollImmediate(u32,u32,u32);
#include "../arm9/palanm.h"
struct GameBeaconPms;
#include "../arm9/cursor_move.h"
/* The DS code was built against other parameter widths for TOWNMAP_GRH_GetTownInfoValue (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern u16 TOWNMAP_GRH_GetTownInfoValue(struct TownMapInfoRow *,int,int);
#else
#include "../ov072/townmap_grh.h"
#endif
struct TcblTask;
/* The DS code was built against other parameter widths for PRINTSYS_PrintQueColor (the original prototypes); the header differs. The host build uses the header. */
#ifdef __MWERKS__
extern void PRINTSYS_PrintQueColor(struct PrintQueue *, struct Bmp *, u32, u32, struct Strbuf *, struct GfFont *, u16);
#else
#include "../arm9/printsys.h"
#endif
extern void BEACON_DETAIL_GRA_PrintWaitTask(struct TcblTask *a, void *b);
int BEACON_DETAIL_GRA_Init(struct ProcOwner *obj,int unused1,void *config);
int BEACON_DETAIL_GRA_Exit(struct GflHeap *heap,int unused1,int unused2,char *p);
int BEACON_DETAIL_GRA_Main(int unused0,int *state,int unused2,char *p);
int BEACON_DETAIL_GRA_StateInteract(char *p);
int BEACON_DETAIL_GRA_StateClose(char *p);
int BEACON_DETAIL_GRA_StateInit(unsigned char *p);
int BEACON_DETAIL_GRA_StateFadeIn(char *p);
int BEACON_DETAIL_GRA_StateFadeOut(char *p);
void BEACON_DETAIL_GRA_LoadBeaconInfo(u8 *p);
void BEACON_DETAIL_GRA_Delete(char *p);
void BEACON_DETAIL_GRA_CreateObjects(char *p);
void BEACON_DETAIL_GRA_DeleteObjects(char *p);
void BEACON_DETAIL_GRA_LoadBackground(char *p,u16 heap);
void BEACON_DETAIL_GRA_FreeBackground(char *p);
TouchBar *BEACON_DETAIL_GRA_CreateTouchBar(int manager,int heap);
void BEACON_DETAIL_GRA_DeleteTouchBar(unsigned char *p);
void BEACON_DETAIL_GRA_UpdateTouchBar(TouchBar *p);
void BEACON_DETAIL_GRA_RegisterActorGfx(unsigned short *p,int *out,const struct ClactResConfig *cfg,void *handle);
void BEACON_DETAIL_GRA_ReleaseActorGfx(void *unused, char *p);
void BEACON_DETAIL_GRA_LoadTrainerGfx(char *p,void *handle);
void BEACON_DETAIL_GRA_FreeTrainerGfx(char *p);
void BEACON_DETAIL_GRA_CreateWindow(struct BeaconDetailGraWindow *p,unsigned char layer,unsigned char palette,unsigned x,unsigned char y,unsigned char width,unsigned char height);
struct ClactActor *BEACON_DETAIL_GRA_CreatePositionedActor(unsigned short *p,void *manager,unsigned *r,short x,short y,unsigned char z,unsigned char a,unsigned char b,unsigned short flag);
void BEACON_DETAIL_GRA_CreateDetailActors(char *p);
void BEACON_DETAIL_GRA_DeleteDetailActors(struct BeaconDetailGraWork *p);
void BEACON_DETAIL_GRA_CreateInfoWindow(char *p);
u32 BEACON_DETAIL_GRA_DeleteInfoWindow(void **p);
void BEACON_DETAIL_GRA_CreateListWindows(char *p);
void BEACON_DETAIL_GRA_DeleteListWindows(char *p);
void BEACON_DETAIL_GRA_IsPmsActive(void **p);
void *BEACON_DETAIL_GRA_Create(int a,int heap);
void BEACON_DETAIL_GRA_Destroy(void **p);
void BEACON_DETAIL_GRA_Draw(char *p);
void *BEACON_DETAIL_GRA_GetClactUnit(char *p);
void BEACON_DETAIL_GRA_Task(void *unused, void * pArg);
void BEACON_DETAIL_GRA_InitBgSystem(void *p,int heap);
void BEACON_DETAIL_GRA_ExitBgSystem(void *p);
void BEACON_DETAIL_GRA_Noop(void *p);
void BEACON_DETAIL_GRA_UpdateBg(void *work);
void BEACON_DETAIL_GRA_InitClact(void **p,void *a,int heap);
void BEACON_DETAIL_GRA_ExitClact(char *p);
void BEACON_DETAIL_GRA_DrawClact(void *work);
void BEACON_DETAIL_GRA_VBlankClact(void *work);
void *BEACON_DETAIL_GRA_ReadPtr(void **p);
void BEACON_DETAIL_GRA_SetupBeaconList(unsigned char *p);
int BEACON_DETAIL_GRA_UpdateInteract(unsigned char *p);
void BEACON_DETAIL_GRA_RefreshButtons(u8*p);
int BEACON_DETAIL_GRA_IsTouchOnActor(u8*p);
void BEACON_DETAIL_GRA_PlaySe(int a);
void BEACON_DETAIL_GRA_LoadPalette(void *p,unsigned mode,unsigned a,unsigned b);
void BEACON_DETAIL_GRA_UpdateButtons(unsigned char *p);
int BEACON_DETAIL_GRA_GetPmVersionClass(void *beaconData);
const u8*BEACON_DETAIL_GRA_FindAppearanceType(u32 n);
void BEACON_DETAIL_GRA_SetNameSlots(void *p,void *q);
void BEACON_DETAIL_GRA_SetActorAnim(void *p, unsigned short value);
void BEACON_DETAIL_GRA_SetActorPos(void *actor, short x, short y, int surface);
void BEACON_DETAIL_GRA_PrintMsg(u8*p, u8 n);
void BEACON_DETAIL_GRA_TransferChar(u8*p,u32 n);
void BEACON_DETAIL_GRA_InitWindows(char *p);
void BEACON_DETAIL_GRA_DrawWindowRecord(void *p,void **q,void *v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e);
void BEACON_DETAIL_GRA_SetSlotVisible(char *p, u8 index, u32 enable);
void BEACON_DETAIL_GRA_MoveActor(u8*p,int a);
void BEACON_DETAIL_GRA_SetupSlot(char *p,void *record,u16 unused,u8 slot);
void BEACON_DETAIL_GRA_UpdateSlotInfo(char *p);
void BEACON_DETAIL_GRA_AddFadeTask(char *owner, int direction, int *counter);
void BEACON_DETAIL_GRA_Callback(struct TcblTask *task,void *work);
void BEACON_DETAIL_GRA_AddTimerTask(char*p);
void BEACON_DETAIL_GRA_AddTimerTaskEx(char *owner, int *counter);
int BEACON_DETAIL_GRA_UpdateTimer(char *p);
void BEACON_DETAIL_GRA_TimerCallback(struct TcblTask *task, void *data);
void BEACON_DETAIL_GRA_AddSlideTask(char *owner, u8 index, int position, u8 direction, int *counter);
void BEACON_DETAIL_GRA_SlideCallback(struct TcblTask *task, void *work);
void BEACON_DETAIL_GRA_AddSlotSlideTask(char*p,int a);
void BEACON_DETAIL_GRA_AddSlotSlideTaskEx(char *owner, int direction, int *counter);
void BEACON_DETAIL_GRA_SlotSlideCallback(struct TcblTask *task,void *work);
void BEACON_DETAIL_GRA_DrawRecord(char *owner, char *record, u32 b, u16 c, void *d, u16 f);
void BEACON_DETAIL_GRA_AddPrintWaitTask(u8 *p,void *arg,int *counter);
extern unsigned char ov067_id[],ov072_id[];
extern unsigned char ov072_id[],ov067_id[];
extern const unsigned char d_021BDB4C[];
extern const struct ClactResConfig sBeaconDetailGraConfigA,sBeaconDetailGraConfigB;
extern char d_021BDDC0[];
extern unsigned d_021BDBD8[];
extern const unsigned d_021BDBAC[];
extern const struct BeaconDetailGraBgEntry d_021BDC28[];
extern const unsigned d_021BDBBC[];
extern const struct BeaconDetailGraRenderBlock d_021BDC08;
extern const u8 d_021BDDA2[];
extern const u8 d_021BDD92[];
extern const struct BeaconDetailGraColorPair d_021BDD8A[];
extern const u8 d_021BDD88[];

#include "../arm9/beacon_status.h"
int BEACON_DETAIL_GRA_Init(struct ProcOwner *obj,int unused1,void *config)
{
    char *p;
    GF_OVERLAY_Load((sptr)ov067_id);
    GF_OVERLAY_Load((sptr)ov072_id);
    GFL_HEAP_CreateChildHeap(1,119,3<<16);
    p=PROCSYS_AllocProcWork((struct Proc *)obj,sizeof(struct BeaconDetailGraWork),119);
    MI_CpuFill8(p,0,sizeof(struct BeaconDetailGraWork));
    ((struct BeaconDetailGraWork *)p)->config=config;
    ((struct BeaconDetailGraWork *)p)->heapId=119;
    ((struct BeaconDetailGraWork *)p)->gfxHeapId=0x8077;
    ((struct BeaconDetailGraWork *)p)->clactObj=BEACON_DETAIL_GRA_Create(0,((struct BeaconDetailGraWork *)p)->heapId);
    BEACON_DETAIL_GRA_LoadBeaconInfo((u8 *)p);
    BEACON_DETAIL_GRA_CreateObjects(p);
    BEACON_DETAIL_GRA_LoadBackground(p,((struct BeaconDetailGraWork *)p)->heapId);
    BEACON_DETAIL_GRA_CreateInfoWindow(p);
    BEACON_DETAIL_GRA_LoadTrainerGfx(p,((struct BeaconDetailGraWork *)p)->arcFile);
    BEACON_DETAIL_GRA_CreateDetailActors(p);
    BEACON_DETAIL_GRA_CreateListWindows(p);
    ((struct BeaconDetailGraWork *)p)->touchBar=(void *)BEACON_DETAIL_GRA_CreateTouchBar((sptr)(BEACON_DETAIL_GRA_GetClactUnit(((struct BeaconDetailGraWork *)p)->clactObj)), ((struct BeaconDetailGraWork *)p)->heapId);
    return 1;
}

int BEACON_DETAIL_GRA_Exit(struct GflHeap *heap,int unused1,int unused2,char *p)
{
    BEACON_DETAIL_GRA_DeleteTouchBar(((struct BeaconDetailGraWork *)p)->touchBar);
    BEACON_DETAIL_GRA_DeleteListWindows(p);
    BEACON_DETAIL_GRA_DeleteDetailActors((struct BeaconDetailGraWork *)p);
    BEACON_DETAIL_GRA_FreeTrainerGfx(p);
    BEACON_DETAIL_GRA_DeleteInfoWindow((void **)p);
    BEACON_DETAIL_GRA_FreeBackground(p);
    BEACON_DETAIL_GRA_DeleteObjects(p);
    BEACON_DETAIL_GRA_Delete(p);
    BEACON_DETAIL_GRA_Destroy((void **)((struct BeaconDetailGraWork *)p)->clactObj);
    PROCSYS_FreeProcWork((struct Proc *)heap);
    GFL_HEAP_DeleteChecked(119);
    GF_OVERLAY_Unload((sptr)ov072_id);
    GF_OVERLAY_Unload((sptr)ov067_id);
    return 1;
}

int BEACON_DETAIL_GRA_Main(int unused0,int *state,int unused2,char *p)
{
    if (((struct BeaconDetailGraWork *)p)->fadeMode) return 1;
    if (*state>=2 && *state<=3) BEACON_DETAIL_GRA_UpdateTouchBar((TouchBar *)(((struct BeaconDetailGraWork *)p)->touchBar));
    switch (*state) {
    case 0: *state=BEACON_DETAIL_GRA_StateInit((unsigned char *)p); break;
    case 1: *state=BEACON_DETAIL_GRA_StateFadeIn(p); break;
    case 2: *state=BEACON_DETAIL_GRA_StateInteract(p); break;
    case 3: *state=BEACON_DETAIL_GRA_StateClose(p); break;
    case 4: *state=BEACON_DETAIL_GRA_StateFadeOut(p); break;
    case 5: return 1;
    }
    TCBL_Main((struct TcblSystem *)(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)p)->tcbl));
    PRINTSYS_QUE_Main((struct PrintQueue *)(*(struct PrintSys * *)&((struct BeaconDetailGraWork *)p)->printQue));
    BEACON_DETAIL_GRA_IsPmsActive((void **)p);
    BEACON_DETAIL_GRA_Draw(*(char * *)&((struct BeaconDetailGraWork *)p)->clactObj);
    return 0;
}

/*
 * follower: 021BBF0C pool-and-bx thunk forwarding to 021BCC10.
 */
int BEACON_DETAIL_GRA_StateInteract(char *p)
{
    return BEACON_DETAIL_GRA_UpdateInteract((unsigned char *)p);
}

/*
 * Addresses are Black-image addresses.
 */
int BEACON_DETAIL_GRA_StateClose(char *p)
{
    if (((struct BeaconDetailGraWork *)p)->subMode != 0)
        return 3;
    BEACON_DETAIL_GRA_RefreshButtons((u8 *)p);
    return 2;
}

int BEACON_DETAIL_GRA_StateInit(unsigned char *p){switch(((struct BeaconDetailGraWork *)p)->state){case 0:BEACON_DETAIL_GRA_SetupBeaconList(p);(((struct BeaconDetailGraWork *)p)->state)++;break;case 1:if(PRINTSYS_QUE_IsFinished((struct PrintQueue *)(*(struct PrintSys * *)&((struct BeaconDetailGraWork *)p)->printQue))){((struct BeaconDetailGraWork *)p)->state=0;return 1;}break;}return 0;}

int BEACON_DETAIL_GRA_StateFadeIn(char *p){switch(((struct BeaconDetailGraWork *)p)->state){case 0:FADE_Start(3,16,0,0);(((struct BeaconDetailGraWork *)p)->state)++;break;case 1:if(FADE_IsActive()==0){((struct BeaconDetailGraWork *)p)->state=0;return 2;}break;}return 1;}

int BEACON_DETAIL_GRA_StateFadeOut(char *p)
{
    switch (((struct BeaconDetailGraWork *)p)->state) {
    case 0:
        if (((struct BeaconDetailGraConfig *)(*(char * *)&((struct BeaconDetailGraWork *)p)->config))->mode==0) {
            BEACON_DETAIL_GRA_UpdateTouchBar((TouchBar *)(((struct BeaconDetailGraWork *)p)->touchBar));
            if (TOUCHBAR_GetPressedButtonIdIfDone((TouchBar *)(*(unsigned char * *)&((struct BeaconDetailGraWork *)p)->touchBar))!=1) break;
        }
        FADE_Start(3,0,16,0);
        (((struct BeaconDetailGraWork *)p)->state)++;
        break;
    case 1:
        if (FADE_IsActive()==0) {
            ((struct BeaconDetailGraWork *)p)->state=0;
            return 5;
        }
        break;
    }
    return 4;
}

/*
 * Verified EXACT Thumb C copied from parked BEACON_VIEW_InitWorkFromSave header:
 * u32 BEACON_STATUS_GetLog(u32 a) { return a; }
 * Singleton TU --suggest-split leaves caller out; no viable partition.
 * Trailing 021BC0B2..021BC0B4 is zero alignment padding.
 * lever: array index uses p[47]++ so byte count advances before the store.
 */
void BEACON_DETAIL_GRA_LoadBeaconInfo(u8 *p)
{
    int i,count;
    ((struct BeaconDetailGraWork *)p)->beaconRecord=(unsigned char *)GAME_BEACON_ACCESSOR_AllocInfo(*(u16 *)p);
    ((struct BeaconDetailGraWork *)p)->itemUseWork=GAME_DATA_GetItemUseWork(((struct BeaconDetailGraWork *)p)->config->gameData);
    ((struct BeaconDetailGraWork *)p)->infoQueue=(void *)BEACON_STATUS_GetLog(((struct BeaconDetailGraWork *)p)->itemUseWork);
    count=GAME_BEACON_ACCESSOR_TableGetCount((struct GameBeaconInfoTable *)(((struct BeaconDetailGraWork *)p)->infoQueue));
    ((struct BeaconDetailGraWork *)p)->cursor=255;
    for(i=0;i<count;i++){
        GAME_BEACON_ACCESSOR_TableRingGet((struct GameBeaconInfoTable *)(((struct BeaconDetailGraWork *)p)->infoQueue),(struct GameBeaconInfo *)(((struct BeaconDetailGraWork *)p)->beaconRecord),(u16 *)(&((struct BeaconDetailGraWork *)p)->level),i);
        if(GAME_BEACON_ACCESSOR_IsInfoInvalid((struct GameBeaconInfo *)(((struct BeaconDetailGraWork *)p)->beaconRecord))==0 && GAME_BEACON_ACCESSOR_IsDistributionAction((struct GameBeaconInfo *)(((struct BeaconDetailGraWork *)p)->beaconRecord))==0){
            if(((struct BeaconDetailGraWork *)p)->config->selected==i)((struct BeaconDetailGraWork *)p)->cursor=((struct BeaconDetailGraWork *)p)->slotMax;
            ((struct BeaconDetailGraWork *)p)->slotOrder[((struct BeaconDetailGraWork *)p)->slotMax++]=i;
        }
    }
    if(((struct BeaconDetailGraWork *)p)->cursor==255 || ((struct BeaconDetailGraWork *)p)->cursor>=((struct BeaconDetailGraWork *)p)->slotMax)((struct BeaconDetailGraWork *)p)->cursor=0;
    if(((struct BeaconDetailGraWork *)p)->slotMax==0)((struct BeaconDetailGraWork *)p)->fadeMode=1;
    ((struct BeaconDetailGraWork *)p)->msgWait=MSG_SPEED_GetWait();
    ((struct BeaconDetailGraWork *)p)->townInfo=(void *)TOWNMAP_GRH_LoadTownInfo((int)(*(u16 *)p));
}

void BEACON_DETAIL_GRA_Delete(char *p)
{
    TOWNMAP_GRH_FreeTownInfo((void *)(((struct BeaconDetailGraWork *)p)->townInfo));
    GFL_HEAP_Free((void *)(((struct BeaconDetailGraWork *)p)->beaconRecord));
}

#if LANGUAGE == LANGUAGE_JAPANESE
#define BEACON_DETAIL_MSG_ARCHIVE 0xa
#else
#define BEACON_DETAIL_MSG_ARCHIVE 7
#endif

void BEACON_DETAIL_GRA_CreateObjects(char *p)
{
    *(struct Tcbl * *)&((struct BeaconDetailGraWork *)p)->tcbl=(struct Tcbl *)TCBL_Create(((struct BeaconDetailGraWork *)p)->heapId,((struct BeaconDetailGraWork *)p)->heapId,64,128);
    ((struct BeaconDetailGraWork *)p)->arcFile=ARC_TOOL_CreateHandle(173,((struct BeaconDetailGraWork *)p)->heapId);
    GF_FONT_SetTextColor(7,8,15);
    ((struct BeaconDetailGraWork *)p)->printQue=PRINTSYS_QUE_CreateEx(2048,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct GfFont * *)&((struct BeaconDetailGraWork *)p)->font.ptr=GF_FONT_Create(23,0,0,0,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet=WORDSET_Create(8,64,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct MsgBank * *)&((struct BeaconDetailGraWork *)p)->msgBank=MSGDATA_CreateFromArchive(0,2,BEACON_DETAIL_MSG_ARCHIVE,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct MsgBank * *)&((struct BeaconDetailGraWork *)p)->msgBank2=MSGDATA_CreateFromArchive(0,2,231,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf=(struct U16Vec *)STRBUF_Create(109,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf2=(struct U16Vec *)STRBUF_Create(109,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf3=(struct U16Vec *)STRBUF_Create(109,((struct BeaconDetailGraWork *)p)->heapId);
}

void BEACON_DETAIL_GRA_DeleteObjects(char *p)
{
    STRBUF_Delete((struct Strbuf *)(*(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf3));
    STRBUF_Delete((struct Strbuf *)(*(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf2));
    STRBUF_Delete((struct Strbuf *)(*(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf));
    MSGDATA_Delete(*(struct MsgBank * *)&((struct BeaconDetailGraWork *)p)->msgBank2);
    MSGDATA_Delete(*(struct MsgBank * *)&((struct BeaconDetailGraWork *)p)->msgBank);
    WORDSET_Delete(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet);
    GF_FONT_Delete(((struct BeaconDetailGraWork *)p)->font.ptr);
    PRINTSYS_QUE_Clear((struct PrintQueue *)(*(struct PrintSys * *)&((struct BeaconDetailGraWork *)p)->printQue));
    PRINTSYS_QUE_Delete((struct PrintQueue *)(*(struct PrintSys * *)&((struct BeaconDetailGraWork *)p)->printQue));
    GF_FONT_SetDefaultTextColor();
    TCBL_Destroy((struct TcblSystem *)(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)p)->tcbl));
    ARC_TOOL_DeleteHandle(((struct BeaconDetailGraWork *)p)->arcFile);
}

void BEACON_DETAIL_GRA_LoadBackground(char *p,u16 heap)
{
    struct ArcFile *arc;
    arc=ARC_TOOL_CreateHandle(85,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(arc,0,0,0,512,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(((struct BeaconDetailGraWork *)p)->arcFile,28,4,0,512,heap);
    ARC_UTIL_UploadBgCharFromHandle(((struct BeaconDetailGraWork *)p)->arcFile,30,4,0,0,1,heap);
    ARC_UTIL_UploadBgCharFromHandle(((struct BeaconDetailGraWork *)p)->arcFile,30,5,0,0,1,heap);
    ARC_UTIL_UploadBgCharFromHandle(((struct BeaconDetailGraWork *)p)->arcFile,30,7,0,0,1,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(((struct BeaconDetailGraWork *)p)->arcFile,32,4,0,0,1,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(((struct BeaconDetailGraWork *)p)->arcFile,32,5,0,0,1,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(((struct BeaconDetailGraWork *)p)->arcFile,33,7,0,0,1,heap);
    BG_SYS_FillTileMap(5,0,0,32,24,1);
    BG_SYS_PushTile(5);
    ARC_UTIL_UploadBgCharFromHandle(((struct BeaconDetailGraWork *)p)->arcFile,31,1,0,0,1,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(((struct BeaconDetailGraWork *)p)->arcFile,34,1,0,2048,1,heap);
    ARC_UTIL_UploadBgCharFromHandle(arc,5,2,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,17,2,0,2048,0,heap);
    ARC_UTIL_UploadBgCharFromHandle(arc,7,3,0,0,0,heap);
    ARC_UTIL_UploadBgPaletteFromHandle(arc,16,3,0,2048,0,heap);
    ((struct BeaconDetailGraWork *)p)->charHandle=ARC_TOOL_LoadHandleMember((struct ArcHandle *)(*(struct ArcFile * *)&((struct BeaconDetailGraWork *)p)->arcFile),29,((struct BeaconDetailGraWork *)p)->heapId);
    NNS_G2dGetUnpackedPaletteData(*(struct NitroFileHeader * *)&((struct BeaconDetailGraWork *)p)->charHandle,(void **)(&((struct BeaconDetailGraWork *)p)->charFile));
    ((struct BeaconDetailGraWork *)p)->charData=((struct BeaconDetailGraRes *)(*(char * *)&((struct BeaconDetailGraWork *)p)->charFile))->data;
    ARC_TOOL_DeleteHandle(arc);
    G2x_SetBlendAlpha_((u32 *)REG_BLDCNT_ADDR,2,30,11,5);
    G2x_SetBlendAlpha_((u32 *)REG_DB_BLDCNT_ADDR,3,31,13,3);
}

void BEACON_DETAIL_GRA_FreeBackground(char *p)
{
    GFL_HEAP_Free(((struct BeaconDetailGraWork *)p)->charHandle);
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned short *)0x04000050 = 0;
}

TouchBar *BEACON_DETAIL_GRA_CreateTouchBar(int manager,int heap){struct TouchBarParam a;enum {Zero} zero=Zero;MI_CpuFill8(&a,0,sizeof(struct TouchBarParam));a.f0=(unsigned char *)d_021BDB4C;a.f4=3;a.f10=13;a.f14=11;a.f8=manager;a.fC=zero;a.f18=zero;return TOUCHBAR_Create((TouchBarParams *)(&a),heap);}

void BEACON_DETAIL_GRA_DeleteTouchBar(unsigned char *p){TOUCHBAR_Delete((TouchBar *)p);}

void BEACON_DETAIL_GRA_UpdateTouchBar(TouchBar *p){TOUCHBAR_Update(p);}

void BEACON_DETAIL_GRA_RegisterActorGfx(unsigned short *p,int *out,const struct ClactResConfig *cfg,void *handle)
{
    MI_CpuFill8(out,0,12);
    out[0]=CLACT_RegisterPaletteEx(handle,cfg->first,cfg->a,(unsigned short)(cfg->b<<5),0,cfg->c,*p);
    out[1]=CLACT_RegisterCharacter((void *)handle,cfg->second,0,cfg->a,*p);
    out[2]=CLACT_RegisterCellAnim((void *)handle,cfg->third,cfg->third+1,*p);
}

void BEACON_DETAIL_GRA_ReleaseActorGfx(void *unused, char *p)
{
    CLACT_ReleaseCellAnim(((struct BeaconDetailGraActor *)p)->cellAnim);
    CLACT_ReleaseCharacter(((struct BeaconDetailGraActor *)p)->character);
    CLACT_ReleasePalette(((struct BeaconDetailGraActor *)p)->palette);
}

/*
 * lever: two struct ClactResConfig locals preserve separate frame objects; p+i*8+144
 * retains per-iteration base addition, and q=p+i*12 holds the row base.
 * Prototype: 0202DA04's complete legacy body consumes only input0;
 * 0202DA48/0202DA18 leave returned r0 live and this caller stores it.
 */
/*
 * lever: two Config locals preserve separate frame objects; p+i*8+144
 * retains per-iteration base addition, and q=p+i*12 holds the row base.
 * Prototype: 0202DA04's complete legacy body consumes only input0;
 * 0202DA48/0202DA18 leave returned r0 live and this caller stores it.
 */
void BEACON_DETAIL_GRA_LoadTrainerGfx(char *p,void *handle)
{
    struct ClactResConfig a,b;
    struct ArcFile *arc;
    int i;
    ((struct BeaconDetailGraWork *)p)->trainer.handle=POKEGRA_OpenTrainerHandle((unsigned int)(((struct BeaconDetailGraWork *)p)->heapId));
    a=sBeaconDetailGraConfigA;
    BEACON_DETAIL_GRA_RegisterActorGfx((u16 *)p, (int *)(&((struct BeaconDetailGraWork *)p)->actors[0]), (const struct ClactResConfig *)&a, handle);
    b=sBeaconDetailGraConfigB;
    arc=ARC_TOOL_CreateHandle(32,((struct BeaconDetailGraWork *)p)->gfxHeapId);
    BEACON_DETAIL_GRA_RegisterActorGfx((u16 *)p, (int *)(&((struct BeaconDetailGraWork *)p)->actors[3]), (const struct ClactResConfig *)&b, (void *)(arc));
    ((struct BeaconDetailGraWork *)p)->paletteHandle=ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc,0,((struct BeaconDetailGraWork *)p)->heapId);
    NNS_G2dGetUnpackedPaletteData(*(struct NitroFileHeader * *)&((struct BeaconDetailGraWork *)p)->paletteHandle,(void **)(&((struct BeaconDetailGraWork *)p)->paletteFile));
    ((struct BeaconDetailGraWork *)p)->paletteData=((struct BeaconDetailGraRes *)(*(char * *)&((struct BeaconDetailGraWork *)p)->paletteFile))->data;
    for(i=0;i<16;i++){
        ((struct BeaconDetailGraWork *)p)->gfxChars[i].handle=ARC_TOOL_LoadHandleMember((struct ArcHandle *)arc,i+49,((struct BeaconDetailGraWork *)p)->heapId);
        NNS_G2dGetUnpackedCharacterData((struct NitroFileHeader *)((struct BeaconDetailGraWork *)p)->gfxChars[i].handle,(void **)(&((struct BeaconDetailGraWork *)p)->gfxChars[i]));
    }
    ARC_TOOL_DeleteHandle(arc);
    for(i=0;i<2;i++){
        ((struct BeaconDetailGraWork *)p)->actors[i+1].character=POKEGRA_RegisterTrainerCgr((((struct BeaconDetailGraWork *)p)->trainer.handle),i+2,1,((struct BeaconDetailGraWork *)p)->heapId);
        ((struct BeaconDetailGraWork *)p)->actors[i+1].palette=(u32)POKEGRA_RegisterTrainerPalette((((struct BeaconDetailGraWork *)p)->trainer.handle),i+2,1,(u16)((i+8)<<5),((struct BeaconDetailGraWork *)p)->heapId);
        ((struct BeaconDetailGraWork *)p)->actors[i+1].cellAnim=POKEGRA_RegisterTrainerCellAnim(i+2,0,1,((struct BeaconDetailGraWork *)p)->heapId);
    }
}

void BEACON_DETAIL_GRA_FreeTrainerGfx(char *p)
{
    int i;
    for(i=0;i<2;i++) BEACON_DETAIL_GRA_ReleaseActorGfx(p,(char *)(&((struct BeaconDetailGraWork *)p)->actors[1]+i));
    for(i=0;i<16;i++) GFL_HEAP_Free(((struct BeaconDetailGraWork *)p)->gfxChars[i].handle);
    GFL_HEAP_Free(((struct BeaconDetailGraWork *)p)->paletteHandle);
    BEACON_DETAIL_GRA_ReleaseActorGfx(p,(char *)&((struct BeaconDetailGraWork *)p)->actors[3]);
    BEACON_DETAIL_GRA_ReleaseActorGfx(p,(char *)&((struct BeaconDetailGraWork *)p)->actors[0]);
    ARC_TOOL_DeleteHandle(((struct BeaconDetailGraWork *)p)->trainer.set);
}

void BEACON_DETAIL_GRA_CreateWindow(struct BeaconDetailGraWindow *p,unsigned char layer,unsigned char palette,unsigned x,unsigned char y,unsigned char width,unsigned char height)
{
    struct Descriptor *window;
    p->window=(struct Descriptor *)BMP_WIN_Create(layer,x,y,width,height,palette,1);
    p->buffer=(struct CharBuf *)BMP_WIN_GetBmp((struct BmpWin *)p->window);
    p->copy=p->window;
    p->state=0;
    BMP_Clear((struct Bmp *)p->buffer,3);
    window=p->window;
    BMP_WIN_TransferChars((struct BmpWin *)window);
    BMP_WIN_MakeScreen((struct BmpWin *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)window));
}

struct ClactActor *BEACON_DETAIL_GRA_CreatePositionedActor(unsigned short *p,void *manager,unsigned *r,short x,short y,unsigned char z,unsigned char a,unsigned char b,unsigned short flag){struct BeaconDetailGraPosition pos;pos.x=x;pos.y=y;pos.z=z;pos.b=b;pos.a=a;return CLACT_CreateActor(manager,r[1],r[0],r[2],(struct ActorInitParam *)(&pos),flag,*p);}

void BEACON_DETAIL_GRA_CreateDetailActors(char *p)
{
    void *q=BEACON_DETAIL_GRA_GetClactUnit(((struct BeaconDetailGraWork *)p)->clactObj);
    struct ClactActor *a=BEACON_DETAIL_GRA_CreatePositionedActor((short unsigned int *)p,(void *)q,(unsigned int *)(&((struct BeaconDetailGraWork *)p)->actors[3]),128,120,0,0,2,0);
    ((struct BeaconDetailGraWork *)p)->mapActors[0]=a;
    CLACT_SetActorPaletteOffset(a,0,1);
    ((struct BeaconDetailGraWork *)p)->mapActors[1]=BEACON_DETAIL_GRA_CreatePositionedActor((short unsigned int *)p,(void *)q,(unsigned int *)(&((struct BeaconDetailGraWork *)p)->actors[0]),96,120,0,1,2,0);
}

void BEACON_DETAIL_GRA_DeleteDetailActors(struct BeaconDetailGraWork *p)
{
    int i;
    for (i = 0; i < 2; i++)
    {
        CLACT_SetActorDrawEnable(p->mapActors[i], 0);
        CLACT_DeleteActor(p->mapActors[i]);
    }
}

void BEACON_DETAIL_GRA_CreateInfoWindow(char *p){BEACON_DETAIL_GRA_CreateWindow((struct BeaconDetailGraWindow *)((struct BeaconDetailGraWindow *)(&((struct BeaconDetailGraWork *)p)->infoWindow)), 1, 11, 2, 22, 28, 6);}

/*
 * Tail-call getter: loads p[0x52] and tail-calls BMP_WIN_Delete.
 *
 * Addresses are Black-image addresses.
 */
u32 BEACON_DETAIL_GRA_DeleteInfoWindow(void **p)
{
    return BMP_WIN_Delete((struct BmpWin *)((struct BeaconDetailGraWork *)p)->infoWindow.window);
}

void BEACON_DETAIL_GRA_CreateListWindows(char *p)
{
    void *manager;
    int i,j,layer;
    char *q;
    manager=BEACON_DETAIL_GRA_GetClactUnit(((struct BeaconDetailGraWork *)p)->clactObj);
    ((struct BeaconDetailGraWork *)p)->pmsDraw=PMS_DRAW_Create(manager,1,((struct BeaconDetailGraWork *)p)->printQue,((struct BeaconDetailGraWork *)p)->font.ptr,10,2,*(u16 *)p);
    PMS_DRAW_SetNullColorPalette(((struct BeaconDetailGraWork *)p)->pmsDraw,4);
    PMS_DRAW_SetPrintColor(((struct BeaconDetailGraWork *)p)->pmsDraw,15812);
    PMS_DRAW_SetFollowBgScroll(((struct BeaconDetailGraWork *)p)->pmsDraw,1);
    for(i=0;i<2;i++){
        layer=i+4;
        q=(char *)&((struct BeaconDetailGraWork *)p)->entries[i];
        ((struct BeaconDetailGraEntry *)q)->layer=(u8)layer;
        ((struct BeaconDetailGraEntry *)q)->iconWindow.window=BMP_WIN_Create((u8)layer,2,15,28,4,i,1);
        for(j=0;j<4;j++)BEACON_DETAIL_GRA_CreateWindow((struct BeaconDetailGraWindow *)(&((struct BeaconDetailGraEntry *)q)->win[j]),layer,i,2,j*2+1,19,2);
        BEACON_DETAIL_GRA_CreateWindow((struct BeaconDetailGraWindow *)(&((struct BeaconDetailGraEntry *)q)->winA),layer,i,2,9,19,2);
        BEACON_DETAIL_GRA_CreateWindow((struct BeaconDetailGraWindow *)(&((struct BeaconDetailGraEntry *)q)->winB),layer,i,3,11,28,4);
        BEACON_DETAIL_GRA_CreateWindow((struct BeaconDetailGraWindow *)(&((struct BeaconDetailGraEntry *)q)->winC),layer,i,4,19,27,4);
        ((struct BeaconDetailGraEntry *)q)->actorB=BEACON_DETAIL_GRA_CreatePositionedActor((unsigned short *)p,manager,(unsigned *)(&((struct BeaconDetailGraWork *)p)->actors[1]+i),220,44,0,1,i,1);
        CLACT_SetActorObjMode(((struct BeaconDetailGraEntry *)q)->actorB,0);
        CLACT_SetActorDrawEnable(((struct BeaconDetailGraEntry *)q)->actorB,0);
        ((struct BeaconDetailGraEntry *)q)->actorA=BEACON_DETAIL_GRA_CreatePositionedActor((unsigned short *)p,manager,(unsigned *)(&((struct BeaconDetailGraWork *)p)->actors[0]),200,80,6,0,i,1);
        CLACT_SetActorObjMode(((struct BeaconDetailGraEntry *)q)->actorA,1);
        CLACT_SetActorDrawEnable(((struct BeaconDetailGraEntry *)q)->actorA,0);
    }
}

void BEACON_DETAIL_GRA_DeleteListWindows(char *p)
{
    int i=0,j;
    for(;i<2;i++) {
        char *q=(char *)&((struct BeaconDetailGraWork *)p)->entries[i];
        CLACT_SetActorDrawEnable(((struct BeaconDetailGraEntry *)q)->actorB,0); CLACT_DeleteActor(((struct BeaconDetailGraEntry *)q)->actorB);
        CLACT_SetActorDrawEnable(((struct BeaconDetailGraEntry *)q)->actorA,0); CLACT_DeleteActor(((struct BeaconDetailGraEntry *)q)->actorA);
        BMP_WIN_Delete((struct BmpWin *)(((struct BeaconDetailGraEntry *)q)->winC.window));
        for(j=0;j<2;j++) BMP_WIN_Delete((struct BmpWin *)(&((struct BeaconDetailGraEntry *)q)->winA)[j].window);
        for(j=0;j<4;j++) BMP_WIN_Delete((struct BmpWin *)((struct BeaconDetailGraEntry *)q)->win[j].window);
        BMP_WIN_Delete(((struct BeaconDetailGraEntry *)q)->iconWindow.window);
    }
    PMS_DRAW_Delete(((struct BeaconDetailGraWork *)p)->pmsDraw);
}

/*
 * Tail-call getter: loads p[0x56] and tail-calls PMS_DRAW_Main.
 *
 * Addresses are Black-image addresses.
 */
void BEACON_DETAIL_GRA_IsPmsActive(void **p)
{
    PMS_DRAW_Main((struct PmsDraw *)((struct BeaconDetailGraWork *)p)->pmsDraw);
}

/*
 * volatile: hardware accesses 0x021BC956-0x021BC96A.
 */
void *BEACON_DETAIL_GRA_Create(int a,int heap)
{
    struct BeaconDetailGraGfxSys *p=GFL_HEAP_Alloc(heap,sizeof(struct BeaconDetailGraGfxSys),0,d_021BDDC0,317);
    MI_CpuFill8(p,0,sizeof(struct BeaconDetailGraGfxSys));
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BDBD8);
    BG_SYS_SetLcdSwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    BEACON_DETAIL_GRA_InitBgSystem(p,heap);
    BEACON_DETAIL_GRA_InitClact((void **)&p->clactUnit,d_021BDBD8,heap);
    p->task=GFL_USE_AddMainTask(BEACON_DETAIL_GRA_Task,p,0);
    return p;
}

void BEACON_DETAIL_GRA_Destroy(void **p)
{
    TCB_DeleteTask(((struct BeaconDetailGraGfxSys *)p)->task);
    BEACON_DETAIL_GRA_ExitClact((char *)&((struct BeaconDetailGraGfxSys *)p)->clactUnit);
    BEACON_DETAIL_GRA_ExitBgSystem(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p,0,sizeof(struct BeaconDetailGraGfxSys));
    GFL_HEAP_Free(p);
}

void BEACON_DETAIL_GRA_Draw(char *p)
{
    BEACON_DETAIL_GRA_DrawClact(&((struct BeaconDetailGraGfxSys *)p)->clactUnit);
    BEACON_DETAIL_GRA_Noop(p);
}

void *BEACON_DETAIL_GRA_GetClactUnit(char *p){return BEACON_DETAIL_GRA_ReadPtr((void **)(&((struct BeaconDetailGraGfxSys *)p)->clactUnit));}

void BEACON_DETAIL_GRA_Task(void *unused, void * pArg)
{
    char * p = (char *)pArg;
    BEACON_DETAIL_GRA_UpdateBg(p);
    BEACON_DETAIL_GRA_VBlankClact(&((struct BeaconDetailGraGfxSys *)p)->clactUnit);
}

void BEACON_DETAIL_GRA_InitBgSystem(void *p,int heap)
{
    unsigned i;
    MI_CpuFill8(p,0,4);
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    BG_SYS_SetGraphicsMode((struct DispConfig *)d_021BDBAC);
    for(i=0;i<8;i++) {
        const struct BeaconDetailGraBgEntry *e=&d_021BDC28[i];
        unsigned id=e->id;
        BG_SYS_InitBgLayer((u8)id,(const struct BgTemplate *)e->fields,(u8)e->a);
        BG_SYS_FreeSlot(id);
        BG_SYS_SetPlaneVisible(id,e->b);
    }
}

void BEACON_DETAIL_GRA_ExitBgSystem(void *p){unsigned i;for(i=0;i<8;i++)BG_SYS_FreeLayerBuf((unsigned char)d_021BDC28[i].id);BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}

void BEACON_DETAIL_GRA_Noop(void *p) {}

void BEACON_DETAIL_GRA_UpdateBg(void *work){BG_SYS_Update();}

void BEACON_DETAIL_GRA_InitClact(void **p,void *a,int heap)
{
    struct BeaconDetailGraRenderBlock b;
    MI_CpuFill8(p,0,sizeof(struct BeaconDetailGraClact));
    CLACT_InitSystem((struct ClactSysInit *)d_021BDBBC,a,heap);
    p[0]=CLACT_CreateUnit(128,0,heap);
    b=d_021BDC08;
    p[1]=CLACT_CreateRenderer((struct SurfaceInit *)(&b),2,heap);
    CLACT_SetRendererCulling(p[1],1);
    CLACT_SetUnitRenderer(p[0],p[1]);
    BG_SYS_SetMainPlaneVisible(16,1);
    BG_SYS_SetSubPlaneVisible(16,1);
}

void BEACON_DETAIL_GRA_ExitClact(char *p)
{
    CLACT_DeleteRenderer(((struct BeaconDetailGraClact *)p)->renderer);
    CLACT_DeleteUnit(((struct BeaconDetailGraClact *)p)->unit);
    CLACT_ExitSystem();
    MI_CpuFill8(p, 0, sizeof(struct BeaconDetailGraClact));
}

void BEACON_DETAIL_GRA_DrawClact(void *work){CLACT_DrawSystem();}

void BEACON_DETAIL_GRA_VBlankClact(void *work){CLACT_VBlankSystem();}

void *BEACON_DETAIL_GRA_ReadPtr(void **p){return *p;}

void BEACON_DETAIL_GRA_SetupBeaconList(unsigned char *p)
{
    BEACON_DETAIL_GRA_InitWindows((char *)p);
    GAME_BEACON_ACCESSOR_TableRingGet(((struct BeaconDetailGraWork *)p)->infoQueue,((struct BeaconDetailGraWork *)p)->beaconRecord,(u16 *)(&((struct BeaconDetailGraWork *)p)->level),((struct BeaconDetailGraWork *)p)->slotOrder[((struct BeaconDetailGraWork *)p)->cursor]);
    BEACON_DETAIL_GRA_SetupSlot((char *)p,((struct BeaconDetailGraWork *)p)->beaconRecord,((struct BeaconDetailGraWork *)p)->level,((struct BeaconDetailGraWork *)p)->slotIndex);
    BEACON_DETAIL_GRA_SetSlotVisible((char *)p,((struct BeaconDetailGraWork *)p)->slotIndex,1);
    BEACON_DETAIL_GRA_SetSlotVisible((char *)p,((struct BeaconDetailGraWork *)p)->slotIndex^1,0);
    BEACON_DETAIL_GRA_UpdateSlotInfo((char *)p); BEACON_DETAIL_GRA_UpdateButtons(p);
    GFL_NET_RefreshWmIconAtTopRight(0,((struct BeaconDetailGraWork *)p)->gfxHeapId);
}

int BEACON_DETAIL_GRA_UpdateInteract(unsigned char *p)
{
    int state=TOUCHBAR_GetPressedButtonIdIfPressing(((struct BeaconDetailGraWork *)p)->touchBar);
    unsigned keys=KEY_GetTrg();
    if(GAMESYSTEM_IsNetOffBySleep(((struct BeaconDetailGraWork *)p)->config->gameSystem)) { ((struct BeaconDetailGraWork *)p)->config->mode=1; return 4; }
    if(state==1) { ((struct BeaconDetailGraWork *)p)->config->mode=0; return 4; }
    if(state==3 && ((struct BeaconDetailGraWork *)p)->cursor) { BEACON_DETAIL_GRA_AddSlotSlideTask((char *)p,1); return 3; }
    if(state==2 && ((struct BeaconDetailGraWork *)p)->cursor<((struct BeaconDetailGraWork *)p)->slotMax-1) { BEACON_DETAIL_GRA_AddSlotSlideTask((char *)p,0); return 3; }
    if(!((struct BeaconDetailGraWork *)p)->mapVisible) return 2;
    if(BEACON_DETAIL_GRA_IsTouchOnActor(p) || (keys&1)) { BEACON_DETAIL_GRA_PlaySe(1356); BEACON_DETAIL_GRA_AddTimerTask((char *)p); return 3; }
    return 2;
}

void BEACON_DETAIL_GRA_RefreshButtons(u8*p){BEACON_DETAIL_GRA_UpdateButtons(p);}

int BEACON_DETAIL_GRA_IsTouchOnActor(u8*p){u32 x,y;if(TOUCHPANEL_GetPointTrg(&x,&y)){if((u32)(x-(((struct BeaconDetailGraWork *)p)->mapX-12))<=24 && (u32)(y-(((struct BeaconDetailGraWork *)p)->mapY-16))<=32)return 1;}return 0;}

void BEACON_DETAIL_GRA_PlaySe(int a){GFL_USE_PlaySeDefaultVolume(a);}

void BEACON_DETAIL_GRA_LoadPalette(void *p,unsigned mode,unsigned a,unsigned b)
{
    unsigned x=a*2,y=b*2;
    DC_FlushRange(p,y);
    switch(mode) {
    case 0: GX_LoadBGPltt(p,x,y); break;
    case 1: GXS_LoadBGPltt(p,x,y); break;
    case 2: GX_LoadOBJPltt(p,x,y); break;
    case 3: GXS_LoadOBJPltt(p,x,y); break;
    }
}

void BEACON_DETAIL_GRA_UpdateButtons(unsigned char *p)
{
    TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)p)->touchBar,1,1);
    if(((struct BeaconDetailGraWork *)p)->cursor) TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)p)->touchBar,3,1);
    else TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)p)->touchBar,3,0);
    if(((struct BeaconDetailGraWork *)p)->cursor<((struct BeaconDetailGraWork *)p)->slotMax-1) TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)p)->touchBar,2,1);
    else TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)p)->touchBar,2,0);
}

/*
 * Unblocked by matching GAME_BEACON_ACCESSOR_GetPmVersion (ov010, EXACT): the +0002 call site now
 * attests as `matched`.  ov009 holds ARM code at that address; ov010 is the
 * coherent Thumb leaf, so the correct hint is ov010 (the earlier ov009 hint
 * was wrong).
 *
 * The original selects case 0x15 before 0x14: reversing the two source
 * case labels flips the fall-through to put the default arm last, which is
 * the only shape that reproduces the image's three-exit if-chain.
 *
 * Addresses are Black-image addresses.
 */
int BEACON_DETAIL_GRA_GetPmVersionClass(void *beaconData)
{
    switch (GAME_BEACON_ACCESSOR_GetPmVersion(beaconData)) {
    case 0x15:
        return 0;
    case 0x14:
        return 1;
    default:
        return 2;
    }
}

const u8*BEACON_DETAIL_GRA_FindAppearanceType(u32 n){u32 i;for(i=0;i<6;i++){if(n==d_021BDDA2[i*3])return d_021BDDA2+i*3;}return d_021BDDA2;}

void BEACON_DETAIL_GRA_SetNameSlots(void *p,void *q)
{
    switch(GAME_BEACON_ACCESSOR_GetDetailsType(p)) {
    case 0: case 1:
        WORDSET_SetSlotSpeciesName(q,0,GAME_BEACON_ACCESSOR_GetDetailsMonsNo(p)); break;
    case 2: {
        unsigned a=GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(p);
        WORDSET_SetSlotPokeData(q,0,a); WORDSET_SetSlotFromMsgBE(q,1,a); break;
    }
    case 3: case 4: break;
    default: {
        unsigned a=GAME_BEACON_ACCESSOR_GetZoneId(p);
        if(a>=427) a=317;
        WORDSET_SetSlotFromMsg59(q,0,ZONEDATA_GetPlaceNameId(a)); break;
    }
    }
}

void BEACON_DETAIL_GRA_SetActorAnim(void *p, unsigned short value)
{
    CLACT_SetActorAnimSeq(p, value);
    CLACT_RestartActorAnim(p);
}

void BEACON_DETAIL_GRA_SetActorPos(void *actor, short x, short y, int surface)
{
    u16 tmp[2];
    tmp[0] = x;
    tmp[1] = y;
    CLACT_AddActorSurfacePos(actor, (const struct ClactVec2 *)tmp, surface);
}

/*
 * typedef unsigned char  u8;
 * typedef unsigned short u16;
 * typedef unsigned int   u32;
 *
 * struct MsgEntry {
 *     u32 off;
 *     u16 len;
 *     u16 pad_06;
 * };
 *
 * struct MsgFile {
 *     u16 langCount;
 *     u16 count;
 *     u32 unk_04;
 *     u32 unk_08;
 *     u32 langOff[1];
 * };
 *
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void                 *base;
 *     struct MsgEntry       cache;
 *     u32                   origin;
 *     void                 *stream;
 *     u16                   heapId;
 *     u8                    langIndex;
 *     u8                    resident;
 * };
 *
 * extern char MSGDATA_AllocSite[];
 * extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
 *                           u16 tag);
 * extern void GFL_HEAP_Free(void *p);
 * extern void ARC_TOOL_ReadHandle(void *stream, u32 size, void *dest);
 * extern void ARC_TOOL_SeekHandle(void *stream, u32 pos);
 * extern void STRBUF_Clear(void *dest);
 * extern void STRBUF_SetChars(void *dest, const void *src, u16 len);
 * extern void MSGDATA_DecryptStrbuf(void *dest, u32 index);
 * extern u8 MSGDATA_GetLanguageIndex(const void *file);
 * extern void MSGDATA_LoadBank(struct MsgBank *bank);
 * extern void MSGDATA_RefreshLanguage(struct MsgBank *bank);
 *
 * void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *
 *     MSGDATA_RefreshLanguage(bank);
 *
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *
 *         ARC_TOOL_SeekHandle(bank->stream, pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream, 8, &bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *
 *     if (bank->resident == 0) {
 *         void *buf;
 *
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000), size,
 *                            0, MSGDATA_AllocSite, 0xd6);
 *         if (buf != 0) {
 *             ARC_TOOL_SeekHandle(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream, size, buf);
 *             STRBUF_SetChars(dest, buf, e->len);
 *             GFL_HEAP_Free(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest, (u8 *)bank->base + e->off, e->len);
 *     }
 *
 *     MSGDATA_DecryptStrbuf(dest, index);
 * }
 */
void BEACON_DETAIL_GRA_PrintMsg(u8*p, u8 n){MSGDATA_ReadString(((struct BeaconDetailGraWork *)p)->msgBank,n,((struct BeaconDetailGraWork *)p)->textBuf);WORDSET_CopyTaggedText(((struct BeaconDetailGraWork *)p)->wordSet,((struct BeaconDetailGraWork *)p)->textBuf2,((struct BeaconDetailGraWork *)p)->textBuf);}

void BEACON_DETAIL_GRA_TransferChar(u8*p,u32 n){CLACT_TransferCharacter(((struct BeaconDetailGraWork *)p)->actors[3].character,(struct NNSG2dCharacterData *)((struct BeaconDetailGraWork *)p)->gfxChars[n].data);BEACON_DETAIL_GRA_LoadPalette((u8*)*(void* *)&((struct BeaconDetailGraWork *)p)->paletteData+(d_021BDD92[n]&15)*32,2,160,16);}

#pragma opt_lifetimes off

#pragma opt_propagation off

/*
 * note: final push 2026-10-05 G5L8. EXACT 372 B (c99 and c). Closed by: opt_propagation off with named locals b, a,
 *   rec and off (b, the row offset i*16 and a set in that order in loop 1 before the j loop), do-while loops (with
 *   propagation off a for loop gets an entry guard), x and j as separate counters, j = 0 set only before loop 3
 *   (set before loop 2 it was loaded from x's slot), record address as off + (u32)&w[j] for the add order.
 */
void BEACON_DETAIL_GRA_InitWindows(char *p)
{
    struct BeaconDetailGraEntry *w3;
    struct BeaconDetailGraEntry *w2;
    struct BeaconDetailGraEntry *w;
    int i, j;
    u8 b;
    u16 a;
    struct BeaconDetailGraWindow *rec;
    int off;
    int x;

    i = 0;
    w = (struct BeaconDetailGraEntry *)(&((struct BeaconDetailGraWork *)p)->entries[0]);

    do {
        MSGDATA_ReadString(((struct BeaconDetailGraWork *)p)->msgBank, i, ((struct BeaconDetailGraWork *)p)->textBuf);
        b = d_021BDD8A[i % 2].index;
        off = i * sizeof(struct BeaconDetailGraWindow);
        a = d_021BDD8A[i % 2].color;
        j = 0;
        do {
            rec = (struct BeaconDetailGraWindow *)(off + (uptr)&w[j]);
            BMP_Clear((struct Bmp *)rec->buffer, b);
            BEACON_DETAIL_GRA_DrawRecord(p, (char *)rec, 0, 0, ((struct BeaconDetailGraWork *)p)->textBuf, a);
            CALLS(rec);
            j++;
        } while (j < 2);
        i++;
    } while (i < 4);
    MSGDATA_ReadString(((struct BeaconDetailGraWork *)p)->msgBank, 7, ((struct BeaconDetailGraWork *)p)->textBuf);
    w2 = (struct BeaconDetailGraEntry *)(&((struct BeaconDetailGraWork *)p)->entries[0]);

    x = 0;
    do {
        BMP_Clear((struct Bmp *)w2[x].winA.buffer, 3);
        BEACON_DETAIL_GRA_DrawRecord(p, (char *)&w2[x].winA, 0, 0, ((struct BeaconDetailGraWork *)p)->textBuf, 0x3DC3);
        CALLS(&w2[x].winA);
        x++;
    } while (x < 2);
    MSGDATA_ReadString(((struct BeaconDetailGraWork *)p)->msgBank, 9, ((struct BeaconDetailGraWork *)p)->textBuf);
    w3 = (struct BeaconDetailGraEntry *)(&((struct BeaconDetailGraWork *)p)->entries[0]);
    j = 0;
    do {
        BMP_Clear((struct Bmp *)w3[j].winC.buffer, 3);
        BEACON_DETAIL_GRA_DrawRecord(p, (char *)&w3[j].winC, 0, 0, ((struct BeaconDetailGraWork *)p)->textBuf, 0x3DC3);
        CALLS(&w3[j].winC);
        j++;
    } while (j < 2);
}

#pragma opt_propagation reset

#pragma opt_lifetimes reset

void BEACON_DETAIL_GRA_DrawWindowRecord(void *p,void **q,void *v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e)
{
    void *x;
    BMP_FillRect(q[1],(short)(a*8),0,(unsigned short)(c*8),(unsigned short)(d*8),d_021BDD8A[e].index);
    BEACON_DETAIL_GRA_DrawRecord(p,(char *)q,b,0,v,d_021BDD8A[e].color);
    x=q[0];
    BMP_WIN_TransferChars(x); BMP_WIN_MakeScreen(x); BG_SYS_PushTile(BMP_WIN_GetBgLayer(x));
}

void BEACON_DETAIL_GRA_SetSlotVisible(char *p, u8 index, u32 enable)
{
    char *entry;
    entry = (char *)&((struct BeaconDetailGraWork *)p)->entries[index];
    CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct ClactActor * *)&((struct BeaconDetailGraEntry *)entry)->actorB), enable);
    if (((struct BeaconDetailGraEntry *)entry)->hasSecondActor != 0)
        CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct ClactActor * *)&((struct BeaconDetailGraEntry *)entry)->actorA), enable);
    if (PMS_DRAW_IsActive(*(struct PmsDraw * *)&((struct BeaconDetailGraWork *)p)->pmsDraw, index) != 0)
        PMS_DRAW_SetVisible((struct PmsDraw *)(*(struct PmsDraw * *)&((struct BeaconDetailGraWork *)p)->pmsDraw), index, enable);
    BG_SYS_SetPlaneVisible(((struct BeaconDetailGraEntry *)entry)->layer, (u8)enable);
}

/*
 * prototype: 021BCE8C coordinate parameters are signed short: original uses asrs #16 before each call; same-overlay matched caller 021BD448 declares s16.
 */
void BEACON_DETAIL_GRA_MoveActor(u8*p,int a){BG_SYS_ChangeScrollImmediate(((struct BeaconDetailGraEntry *)p)->layer,3,-a);BEACON_DETAIL_GRA_SetActorPos(*(void* *)&((struct BeaconDetailGraEntry *)p)->actorB,220,a+44,1);BEACON_DETAIL_GRA_SetActorPos(*(void* *)&((struct BeaconDetailGraEntry *)p)->actorA,200,a+80,1);}

void BEACON_DETAIL_GRA_SetupSlot(char *p,void *record,u16 unused,u8 slot)
{
    struct BeaconDetailGraPair colors;
    struct BeaconDetailGraQuad data;
    struct BeaconDetailGraPair counts;
    char *q=(char *)&((struct BeaconDetailGraWork *)p)->entries[slot];
    u32 subtype;
    u16 value;
    int position;
    int index;
    GAME_BEACON_ACCESSOR_GetFavoriteColorRgb((&colors.a),record);
    PALANM_BlendColors(&colors.a,&colors.b,1,3,0);
    position=slot*16;
    BEACON_DETAIL_GRA_LoadPalette(&colors,1,(u16)(position+1),2);
    BEACON_DETAIL_GRA_LoadPalette(*(char * *)&((struct BeaconDetailGraWork *)p)->charData+BEACON_DETAIL_GRA_GetPmVersionClass(record)*32,1,(u16)(position+10),2);
    GAME_BEACON_ACCESSOR_GetPlayerName(record,((struct BeaconDetailGraWork *)p)->textBuf);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)q,((struct BeaconDetailGraWork *)p)->textBuf,6,48,13,2,0);
    subtype=GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond(record);
    if(subtype==255) STRBUF_Clear((struct Strbuf *)(*(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf2));
    else {WORDSET_SetSlotFromMsg38(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,0,subtype);BEACON_DETAIL_GRA_PrintMsg((u8 *)p,5);}
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(&((struct BeaconDetailGraEntry *)q)->win[1]),((struct BeaconDetailGraWork *)p)->textBuf2,6,48,13,2,1);
    subtype=GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst(record);
    if(subtype==255) STRBUF_Clear((struct Strbuf *)(*(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf2));
    else {WORDSET_SetSlotFromMsg2B(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,0,subtype);BEACON_DETAIL_GRA_PrintMsg((u8 *)p,4);}
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(&((struct BeaconDetailGraEntry *)q)->win[2]),((struct BeaconDetailGraWork *)p)->textBuf2,6,48,13,2,0);
    GAME_BEACON_ACCESSOR_GetPlayTime(record,&counts.b,&counts.a);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,2,counts.b,3,0,PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,3,counts.a,2,2,PM_LANG_HALF_WIDTH_DIGITS);
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,6);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(&((struct BeaconDetailGraEntry *)q)->win[3]),((struct BeaconDetailGraWork *)p)->textBuf2,BEACON_DETAIL_PLAYTIME_TILE_X,BEACON_DETAIL_PLAYTIME_TEXT_X,BEACON_DETAIL_PLAYTIME_WIDTH,2,1);
    value=(unsigned)GAME_BEACON_ACCESSOR_GetNation(record);
    WORDSET_SetSlotFromMsgE7(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,0,value);
    WORDSET_SetSlotFromKeyedMessage(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,1,value,GAME_BEACON_ACCESSOR_GetArea(record));
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,8);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(&((struct BeaconDetailGraEntry *)q)->winB),((struct BeaconDetailGraWork *)p)->textBuf2,0,0,28,4,0);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,0,GAME_BEACON_ACCESSOR_GetPassCount(record),5,1,PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,1,GAME_BEACON_ACCESSOR_GetThanksCount(record),5,1,PM_LANG_HALF_WIDTH_DIGITS);
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,10);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(&((struct BeaconDetailGraEntry *)q)->winC),((struct BeaconDetailGraWork *)p)->textBuf2,PM_LANG_JA(21,18),0,PM_LANG_JA(6,9),4,0);
    if(PMS_DRAW_IsActive(*(struct PmsDraw * *)&((struct BeaconDetailGraWork *)p)->pmsDraw,slot)!=0) PMS_DRAW_Clear((struct PmsDraw *)(*(struct PmsDraw * *)&((struct BeaconDetailGraWork *)p)->pmsDraw),slot,1);
    GAME_BEACON_ACCESSOR_GetDetailsPms(record,(struct GameBeaconPms *)(&data));
    PMS_DRAW_Print(((struct BeaconDetailGraWork *)p)->pmsDraw,((struct BeaconDetailGraEntry *)q)->iconWindow.handle,&data,slot);
    ((struct BeaconDetailGraEntry *)q)->appearance=GAME_BEACON_ACCESSOR_GetTrainerAppearance(record);
    POKEGRA_LoadTrainerGraphics(((struct BeaconDetailGraWork *)p)->trainer.set,CURSOR_MOVE_GetTableGroup(((struct BeaconDetailGraEntry *)q)->appearance),*(u32 *)((char *)&((struct BeaconDetailGraWork *)p)->actors[1].character + slot * (int)sizeof(((struct BeaconDetailGraWork *)p)->actors[0])),*(u32 *)((char *)&((struct BeaconDetailGraWork *)p)->actors[1].palette + slot * (int)sizeof(((struct BeaconDetailGraWork *)p)->actors[0])),((struct BeaconDetailGraWork *)p)->gfxHeapId);
    subtype=GAME_BEACON_ACCESSOR_GetResearchTeamRank(record);
    if(subtype==0) {CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct ClactActor * *)&((struct BeaconDetailGraEntry *)q)->actorA),0);return;}
    BEACON_DETAIL_GRA_SetActorAnim(((struct BeaconDetailGraEntry *)q)->actorA,(u8)(subtype+1));
    CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct ClactActor * *)&((struct BeaconDetailGraEntry *)q)->actorA),1);
}

void BEACON_DETAIL_GRA_UpdateSlotInfo(char *p)
{
    const u8 *type;
    u32 value;
    int index,high;
    struct Descriptor *d;
    GAME_BEACON_ACCESSOR_TableRingGet((struct GameBeaconInfoTable *)(*(struct Queue * *)&((struct BeaconDetailGraWork *)p)->infoQueue),(struct GameBeaconInfo *)(*(struct GameBeaconRecord * *)&((struct BeaconDetailGraWork *)p)->beaconRecord),(u16 *)(&((struct BeaconDetailGraWork *)p)->level),((struct BeaconDetailGraWork *)p)->slotOrder[((struct BeaconDetailGraWork *)p)->cursor]);
    type=BEACON_DETAIL_GRA_FindAppearanceType(GAME_BEACON_ACCESSOR_GetDetailsType((struct GameBeaconInfo *)(*(const char * *)&((struct BeaconDetailGraWork *)p)->beaconRecord)));
    BEACON_DETAIL_GRA_TransferChar((u8 *)p,GAME_BEACON_ACCESSOR_GetTrainerAppearance((struct GameBeaconInfo *)(*(struct GameBeaconRecord * *)&((struct BeaconDetailGraWork *)p)->beaconRecord)));
    value=GAME_BEACON_ACCESSOR_GetZoneId((struct GameBeaconInfo *)(*(struct Bits * *)&((struct BeaconDetailGraWork *)p)->beaconRecord));
    index=TOWNMAP_GRH_FindRecordIndex(*(struct TownMapInfoRow **)&((struct BeaconDetailGraWork *)p)->townInfo,GAME_BEACON_ACCESSOR_GetTownmapRootZoneId((struct GameBeaconInfo *)(*(const char * *)&((struct BeaconDetailGraWork *)p)->beaconRecord)));
    if(index==0xffff || TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)(*(char * *)&((struct BeaconDetailGraWork *)p)->townInfo),index,16)!=0xffff || value>=427) {
        ((struct BeaconDetailGraWork *)p)->mapVisible=0;
        *(volatile s16 *)&((struct BeaconDetailGraWork *)p)->mapY=0;
        ((struct BeaconDetailGraWork *)p)->mapX=*(volatile s16 *)&((struct BeaconDetailGraWork *)p)->mapY;
        CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)p)->mapActors[0]),0);
        CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)p)->mapActors[1]),0);
    } else {
        ((struct BeaconDetailGraWork *)p)->mapVisible=1;
        ((struct BeaconDetailGraWork *)p)->mapX=TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)(*(char * *)&((struct BeaconDetailGraWork *)p)->townInfo),index,2);
        ((struct BeaconDetailGraWork *)p)->mapY=TOWNMAP_GRH_GetTownInfoValue((struct TownMapInfoRow *)(*(char * *)&((struct BeaconDetailGraWork *)p)->townInfo),index,3)-16;
        if(((struct BeaconDetailGraWork *)p)->mapY<32) ((struct BeaconDetailGraWork *)p)->mapY=32;
        else if(((struct BeaconDetailGraWork *)p)->mapY>152) ((struct BeaconDetailGraWork *)p)->mapY=152;
        if(((struct BeaconDetailGraWork *)p)->mapX<16) ((struct BeaconDetailGraWork *)p)->mapX=16;
        else if(((struct BeaconDetailGraWork *)p)->mapX>240) ((struct BeaconDetailGraWork *)p)->mapX=240;
        BEACON_DETAIL_GRA_SetActorPos(((struct BeaconDetailGraWork *)p)->mapActors[0],((struct BeaconDetailGraWork *)p)->mapX,((struct BeaconDetailGraWork *)p)->mapY,0);
        CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)p)->mapActors[0]),1);
        if(type[2]!=0) {
            BEACON_DETAIL_GRA_SetActorPos(((struct BeaconDetailGraWork *)p)->mapActors[1],((struct BeaconDetailGraWork *)p)->mapX-24,((struct BeaconDetailGraWork *)p)->mapY,0);
            BEACON_DETAIL_GRA_SetActorAnim(((struct BeaconDetailGraWork *)p)->mapActors[1],(u8)(type[2]-1));
        }
        CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)p)->mapActors[1]),type[2]!=0);
    }
    BMP_Clear((struct Bmp *)((struct BeaconDetailGraWork *)p)->infoWindow.buffer,15);
    high=(u8)(((struct BeaconDetailGraWork *)p)->level>>8);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,0,PM_LANG_JA(high,high%12),2,0,PM_LANG_HALF_WIDTH_DIGITS);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,1,(u8)((struct BeaconDetailGraWork *)p)->level,2,2,PM_LANG_HALF_WIDTH_DIGITS);
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,(high/12)+13);
    BEACON_DETAIL_GRA_DrawRecord(p,(char *)&((struct BeaconDetailGraWork *)p)->infoWindow,0,0,((struct BeaconDetailGraWork *)p)->textBuf2,0x1d0f);
    BEACON_DETAIL_GRA_SetNameSlots(((struct BeaconDetailGraWork *)p)->beaconRecord,((struct BeaconDetailGraWork *)p)->wordSet);
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,type[1]);
    BEACON_DETAIL_GRA_DrawRecord(p,(char *)&((struct BeaconDetailGraWork *)p)->infoWindow,0,16,((struct BeaconDetailGraWork *)p)->textBuf2,0x1d0f);
    d=((struct BeaconDetailGraWork *)p)->infoWindow.window;
    BMP_WIN_TransferChars((struct BmpWin *)d);
    BMP_WIN_MakeScreen((struct BmpWin *)d);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct BmpWin *)d));
}

/*
 * lever: the signed byte step derives -8 from live 64 with subs #72; u8 emits movs #248.
 */
void BEACON_DETAIL_GRA_AddFadeTask(char *owner, int direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)owner)->tcbl), BEACON_DETAIL_GRA_Callback, sizeof(struct BeaconDetailGraFadeTask), 0));
    MI_CpuFill8(work, 0, sizeof(struct BeaconDetailGraFadeTask));
    ((struct BeaconDetailGraFadeTask *)work)->direction = direction;
    if (((struct BeaconDetailGraFadeTask *)work)->direction == 0) {
        ((struct BeaconDetailGraFadeTask *)work)->position = 0;
        ((struct BeaconDetailGraFadeTask *)work)->step = 8;
    } else {
        ((struct BeaconDetailGraFadeTask *)work)->position = 64;
        ((struct BeaconDetailGraFadeTask *)work)->step = -8;
    }
    ((struct BeaconDetailGraFadeTask *)work)->count = 8;
    BEACON_DETAIL_GRA_PlaySe(1357);
    *(int * *)&((struct BeaconDetailGraFadeTask *)work)->counter = counter;
    ++*counter;
}

void BEACON_DETAIL_GRA_Callback(struct TcblTask *task,void *work){u8 *p=work;u32 old=p[2]++;if(old<p[1]){((struct BeaconDetailGraFadeTask *)p)->position=((struct BeaconDetailGraFadeTask *)p)->position+((struct BeaconDetailGraFadeTask *)p)->step;BG_SYS_ChangeScrollImmediate(1,3,((struct BeaconDetailGraFadeTask *)p)->position);}else{--**(u32* *)&((struct BeaconDetailGraFadeTask *)p)->counter;TCBL_DeleteTask((struct TcblTask *)task);}}

void BEACON_DETAIL_GRA_AddTimerTask(char*p){BEACON_DETAIL_GRA_AddTimerTaskEx(p,(int*)(&((struct BeaconDetailGraWork *)p)->subMode));}

/*
 * region evidence: ov067 labels 021B64A8; its filed/full body reads the supplied object in r0 and enable in r1.
 */
void BEACON_DETAIL_GRA_AddTimerTaskEx(char *owner, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)owner)->tcbl), BEACON_DETAIL_GRA_TimerCallback, sizeof(struct BeaconDetailGraTimerTask), 0));
    MI_CpuFill8(work, 0, sizeof(struct BeaconDetailGraTimerTask));
    *(char * *)&((struct BeaconDetailGraTimerTask *)work)->owner = owner;
    ((struct BeaconDetailGraTimerTask *)work)->count = 150;
    TOUCHBAR_SetAllButtonsEnabled((TouchBar *)(*(u8 * *)&((struct BeaconDetailGraWork *)owner)->touchBar), 0);
    *(int * *)&((struct BeaconDetailGraTimerTask *)work)->counter = counter;
    ++*counter;
}

int BEACON_DETAIL_GRA_UpdateTimer(char *p)
{
    unsigned char c;
    if (TOUCHPANEL_GetTrg() != 0 || (KEY_GetTrg() & 1) != 0)
    {
        ((struct BeaconDetailGraTimerTask *)p)->count = 0;
        return 0;
    }
    c = ((struct BeaconDetailGraTimerTask *)p)->count;
    ((struct BeaconDetailGraTimerTask *)p)->count = c - 1;
    if (c != 0)
    {
        return 1;
    }
    return 0;
}

void BEACON_DETAIL_GRA_TimerCallback(struct TcblTask *task, void *data)
{
    char *p = data;
    switch (((struct BeaconDetailGraTimerTask *)p)->step) {
    case 0:
        BEACON_DETAIL_GRA_AddFadeTask(((struct BeaconDetailGraTimerTask *)p)->owner, 0, (int *)(&((struct BeaconDetailGraWork *)p)->state));
        ++((struct BeaconDetailGraTimerTask *)p)->step;
        break;
    case 1:
        if (((struct BeaconDetailGraTimerTask *)p)->timer == 0)
            ++((struct BeaconDetailGraTimerTask *)p)->step;
        break;
    case 2:
        if (BEACON_DETAIL_GRA_UpdateTimer(p) == 0) {
            BEACON_DETAIL_GRA_AddFadeTask(((struct BeaconDetailGraTimerTask *)p)->owner, 1, (int *)(&((struct BeaconDetailGraWork *)p)->state));
            ++((struct BeaconDetailGraTimerTask *)p)->step;
        }
        break;
    case 3:
        if (((struct BeaconDetailGraTimerTask *)p)->timer != 0)
            break;
    default:
        --**(int * *)&((struct BeaconDetailGraTimerTask *)p)->counter;
        TCBL_DeleteTask((struct TcblTask *)task);
        break;
    }
}

/*
 * lever: u8 direction puts the r3 home first; caller 021BD948 supplies ldrb direction in r3.
 */
void BEACON_DETAIL_GRA_AddSlideTask(char *owner, u8 index, int position, u8 direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)owner)->tcbl), BEACON_DETAIL_GRA_SlideCallback, sizeof(struct BeaconDetailGraSlideTask), 0));
    MI_CpuFill8(work, 0, sizeof(struct BeaconDetailGraSlideTask));
    *(char * *)&((struct BeaconDetailGraSlideTask *)work)->entry = (char *)&((struct BeaconDetailGraWork *)owner)->entries[index];
    ((struct BeaconDetailGraSlideTask *)work)->index = index;
    ((struct BeaconDetailGraSlideTask *)work)->offset = (1 - position) * -192;
    if (direction == 0)
        ((struct BeaconDetailGraSlideTask *)work)->delta -= 8;
    else
        ((struct BeaconDetailGraSlideTask *)work)->delta += 8;
    ((struct BeaconDetailGraSlideTask *)work)->count = 24;
    BEACON_DETAIL_GRA_MoveActor(((struct BeaconDetailGraSlideTask *)work)->entry, ((struct BeaconDetailGraSlideTask *)work)->offset);
    if (position != 1)
        BEACON_DETAIL_GRA_SetSlotVisible(owner, ((struct BeaconDetailGraSlideTask *)work)->index, 1);
    *(char * *)&((struct BeaconDetailGraSlideTask *)work)->owner = owner;
    *(int * *)&((struct BeaconDetailGraSlideTask *)work)->counter = counter;
    ++*counter;
}

void BEACON_DETAIL_GRA_SlideCallback(struct TcblTask *task, void *work)
{
    char *p = work;
    u8 count;
    count = ((struct BeaconDetailGraSlideTask *)p)->count;
    ((struct BeaconDetailGraSlideTask *)p)->count = count - 1;
    if (count != 0) {
        ((struct BeaconDetailGraSlideTask *)p)->offset += ((struct BeaconDetailGraSlideTask *)p)->delta;
        BEACON_DETAIL_GRA_MoveActor(((struct BeaconDetailGraSlideTask *)p)->entry, ((struct BeaconDetailGraSlideTask *)p)->offset);
        return;
    }
    if (((struct BeaconDetailGraSlideTask *)p)->offset != 0)
        BEACON_DETAIL_GRA_SetSlotVisible(((struct BeaconDetailGraSlideTask *)p)->owner, ((struct BeaconDetailGraSlideTask *)p)->index, 0);
    --**(int * *)&((struct BeaconDetailGraSlideTask *)p)->counter;
    TCBL_DeleteTask((struct TcblTask *)task);
}

void BEACON_DETAIL_GRA_AddSlotSlideTask(char*p,int a){BEACON_DETAIL_GRA_AddSlotSlideTaskEx(p,a,(int*)(&((struct BeaconDetailGraWork *)p)->subMode));}

void BEACON_DETAIL_GRA_AddSlotSlideTaskEx(char *owner, int direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)owner)->tcbl), BEACON_DETAIL_GRA_SlotSlideCallback, sizeof(struct BeaconDetailGraSlotTask), 0));
    MI_CpuFill8(work, 0, sizeof(struct BeaconDetailGraSlotTask));
    ((struct BeaconDetailGraSlotTask *)work)->direction = direction;
    if (direction == 0) {
        ((struct BeaconDetailGraSlotTask *)work)->index = ((struct BeaconDetailGraWork *)owner)->cursor + 1;
        TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)owner)->touchBar, 3, 0);
    } else {
        ((struct BeaconDetailGraSlotTask *)work)->index = ((struct BeaconDetailGraWork *)owner)->cursor - 1;
        TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)owner)->touchBar, 2, 0);
    }
    TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)owner)->touchBar, 1, 0);
    GAME_BEACON_ACCESSOR_TableRingGet((struct GameBeaconInfoTable *)(*(struct Queue * *)&((struct BeaconDetailGraWork *)owner)->infoQueue), (struct GameBeaconInfo *)(*(struct GameBeaconRecord * *)&((struct BeaconDetailGraWork *)owner)->beaconRecord), (u16 *)(&((struct BeaconDetailGraWork *)owner)->level), ((struct BeaconDetailGraWork *)owner)->slotOrder[((struct BeaconDetailGraSlotTask *)work)->index]);
    BEACON_DETAIL_GRA_SetupSlot(owner, ((struct BeaconDetailGraWork *)owner)->beaconRecord, ((struct BeaconDetailGraWork *)owner)->level, ((struct BeaconDetailGraWork *)owner)->slotIndex ^ 1);
    *(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner = owner;
    *(int * *)&((struct BeaconDetailGraSlotTask *)work)->counter = counter;
    ++*counter;
}

/*
 * Lever: explicit case 3 plus default preserves four switch arms; BD7D4 u8 index preserves the original XOR truncation pair, own int index notwithstanding.
 */
void BEACON_DETAIL_GRA_SlotSlideCallback(struct TcblTask *task,void *work)
{
    if(((struct BeaconDetailGraSlotTask *)work)->flags==0) {
        if(TOUCHBAR_GetPressedButtonIdIfDone((TouchBar *)(*(u8 * *)&((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->touchBar))!=-1)
            ((struct BeaconDetailGraSlotTask *)work)->flags=1;
    }
    if(PRINTSYS_QUE_IsFinished((struct PrintQueue *)(*(struct PrintSys * *)&((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->printQue))==0) return;
    switch(((struct BeaconDetailGraSlotTask *)work)->step) {
    case 0:
        if(((struct BeaconDetailGraSlotTask *)work)->flags==0) break;
        TOUCHBAR_SetAllButtonsEnabled((TouchBar *)(*(u8 * *)&((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->touchBar),0);
        ++((struct BeaconDetailGraSlotTask *)work)->step;
        return;
    case 1:
        BEACON_DETAIL_GRA_AddSlideTask(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner,((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->slotIndex,1,((struct BeaconDetailGraSlotTask *)work)->direction,(int *)(&((struct BeaconDetailGraSlotTask *)work)->wait));
        BEACON_DETAIL_GRA_AddSlideTask(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner,((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->slotIndex^1,d_021BDD88[((struct BeaconDetailGraSlotTask *)work)->direction],((struct BeaconDetailGraSlotTask *)work)->direction,(int *)(&((struct BeaconDetailGraSlotTask *)work)->wait));
        CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->mapActors[0]),0);
        CLACT_SetActorDrawEnable((struct ClactActor *)(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->mapActors[1]),0);
        ++((struct BeaconDetailGraSlotTask *)work)->step;
        return;
    case 2:
        if(((struct BeaconDetailGraSlotTask *)work)->wait!=0) break;
        ((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->slotIndex^=1;
        ((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->cursor=((struct BeaconDetailGraSlotTask *)work)->index;
        BEACON_DETAIL_GRA_UpdateSlotInfo(((struct BeaconDetailGraSlotTask *)work)->owner);
        ++((struct BeaconDetailGraSlotTask *)work)->step;
        return;
    case 3:
    default:
        --**(int * *)&((struct BeaconDetailGraSlotTask *)work)->counter;
        TCBL_DeleteTask((struct TcblTask *)task);
        break;
    }
}

/*
 * lever: u16 c moves its r3 spill before the handle load and restores call setup; u32 leaves 24 concrete bytes different.
 */
void BEACON_DETAIL_GRA_DrawRecord(char *owner, char *record, u32 b, u16 c, void *d, u16 f)
{
    void *handle;
    handle = ((struct BeaconDetailGraWork *)owner)->printQue;
    PRINTSYS_PrintQueColor(handle, BMP_WIN_GetBmp((struct BmpWin *)((struct BeaconDetailGraWinRecord *)record)->target.window), b, c, (struct Strbuf *)d, (struct GfFont *)(((struct BeaconDetailGraWork *)owner)->font.handle), f);
    ((struct BeaconDetailGraWinRecord *)record)->target.pending = 1;
    BEACON_DETAIL_GRA_AddPrintWaitTask((u8 *)owner, record, (int *)(&((struct BeaconDetailGraWork *)owner)->subMode));
}

void BEACON_DETAIL_GRA_AddPrintWaitTask(u8 *p,void *arg,int *counter)
{
    struct BeaconDetailGraPrintTask *work;
    work=TCBL_GetWork((struct TcblTask *)TCBL_AddTask((struct TcblSystem *)(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)p)->tcbl),BEACON_DETAIL_GRA_PrintWaitTask,sizeof(struct BeaconDetailGraPrintTask),0));
    MI_CpuFill8(work,0,sizeof(struct BeaconDetailGraPrintTask));
    work->owner=p;
    work->arg=arg;
    if(counter!=0){work->counter=counter;++*counter;}
}

void BEACON_DETAIL_GRA_PrintWaitTask(struct TcblTask *a, void *b)
{
    struct BeaconDetailGraPrintTask *t = (struct BeaconDetailGraPrintTask *)b;
    struct BeaconDetailGraWinTarget *s = &((struct BeaconDetailGraWinRecord *)t->arg)->target;
    void *q = ((struct BeaconDetailGraWork *)t->owner)->printQue;

    if (s->pending) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintQueue *)q, (void *)(BMP_WIN_GetBmp((struct BmpWin *)s->window))) == 0) {
            BMP_WIN_TransferChars((struct BmpWin *)s->window);
            s->pending = 0;
        }
    }
    if (s->pending == 0) {
        if (t->counter)
            --*t->counter;
        TCBL_DeleteTask(a);
    }
}
