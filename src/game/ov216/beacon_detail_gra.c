/*
 * file:     beacon_detail_gra.c
 * unit:     yes
 * function: BEACON_DETAIL_GRA_Init, BEACON_DETAIL_GRA_Exit, BEACON_DETAIL_GRA_Main, BEACON_DETAIL_GRA_StateClose, BEACON_DETAIL_GRA_StateInit, BEACON_DETAIL_GRA_StateFadeIn, BEACON_DETAIL_GRA_StateFadeOut, BEACON_DETAIL_GRA_LoadBeaconInfo, BEACON_DETAIL_GRA_Delete, BEACON_DETAIL_GRA_CreateObjects, BEACON_DETAIL_GRA_DeleteObjects, BEACON_DETAIL_GRA_LoadBackground, BEACON_DETAIL_GRA_FreeBackground, BEACON_DETAIL_GRA_CreateTouchBar, BEACON_DETAIL_GRA_DeleteTouchBar, BEACON_DETAIL_GRA_UpdateTouchBar, BEACON_DETAIL_GRA_RegisterActorGfx, BEACON_DETAIL_GRA_ReleaseActorGfx, BEACON_DETAIL_GRA_LoadTrainerGfx, BEACON_DETAIL_GRA_FreeTrainerGfx, BEACON_DETAIL_GRA_CreateWindow, BEACON_DETAIL_GRA_CreatePositionedActor, BEACON_DETAIL_GRA_CreateDetailActors, BEACON_DETAIL_GRA_DeleteDetailActors, BEACON_DETAIL_GRA_CreateInfoWindow, BEACON_DETAIL_GRA_DeleteInfoWindow, BEACON_DETAIL_GRA_CreateListWindows, BEACON_DETAIL_GRA_DeleteListWindows, BEACON_DETAIL_GRA_IsPmsActive, BEACON_DETAIL_GRA_Create, BEACON_DETAIL_GRA_Destroy, BEACON_DETAIL_GRA_Draw, BEACON_DETAIL_GRA_GetClactUnit, BEACON_DETAIL_GRA_Task, BEACON_DETAIL_GRA_InitBgSystem, BEACON_DETAIL_GRA_ExitBgSystem, BEACON_DETAIL_GRA_Noop, BEACON_DETAIL_GRA_UpdateBg, BEACON_DETAIL_GRA_InitClact, BEACON_DETAIL_GRA_ExitClact, BEACON_DETAIL_GRA_DrawClact, BEACON_DETAIL_GRA_VBlankClact, BEACON_DETAIL_GRA_SetupBeaconList, BEACON_DETAIL_GRA_UpdateInteract, BEACON_DETAIL_GRA_RefreshButtons, BEACON_DETAIL_GRA_IsTouchOnActor, BEACON_DETAIL_GRA_PlaySe, BEACON_DETAIL_GRA_LoadPalette, BEACON_DETAIL_GRA_UpdateButtons, BEACON_DETAIL_GRA_GetPmVersionClass, BEACON_DETAIL_GRA_FindAppearanceType, BEACON_DETAIL_GRA_SetNameSlots, BEACON_DETAIL_GRA_SetActorAnim, BEACON_DETAIL_GRA_SetActorPos, BEACON_DETAIL_GRA_PrintMsg, BEACON_DETAIL_GRA_TransferChar, BEACON_DETAIL_GRA_InitWindows, BEACON_DETAIL_GRA_DrawWindowRecord, BEACON_DETAIL_GRA_SetSlotVisible, BEACON_DETAIL_GRA_MoveActor, BEACON_DETAIL_GRA_SetupSlot, BEACON_DETAIL_GRA_UpdateSlotInfo, BEACON_DETAIL_GRA_AddFadeTask, BEACON_DETAIL_GRA_Callback, BEACON_DETAIL_GRA_AddTimerTask, BEACON_DETAIL_GRA_AddTimerTaskEx, BEACON_DETAIL_GRA_UpdateTimer, BEACON_DETAIL_GRA_TimerCallback, BEACON_DETAIL_GRA_AddSlideTask, BEACON_DETAIL_GRA_SlideCallback, BEACON_DETAIL_GRA_AddSlotSlideTask, BEACON_DETAIL_GRA_AddSlotSlideTaskEx, BEACON_DETAIL_GRA_SlotSlideCallback, BEACON_DETAIL_GRA_DrawRecord, BEACON_DETAIL_GRA_AddPrintWaitTask, BEACON_DETAIL_GRA_PrintWaitTask
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
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
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
 *   configA 0x021BDB28 data a2
 *   configB 0x021BDB34 data a2
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
 *   BMP_SetDisplaySwap 0x0204363C arm
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
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   ICA_ANIME_GetUnk330 0x02012204 thumb
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
 *   BG_SYS_FillScrollArea 0x02040618 arm
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
 *   WORDSET_DeleteMsgdataF094 0x0201F094 thumb
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
 *   WORDSET_Callback  0x0201EE60  thumb  arm9
 *   WORDSET_SetSlotPokeData  0x0201F104  thumb  arm9
 *   WORDSET_SetSlotFromMsgBE  0x0201F134  thumb  arm9
 *   WORDSET_SetSlotFromMsg59  0x0201F158  thumb  arm9
 *   GFL_USE_AddMainTask  0x020056A0  thumb  arm9
 */

#define REC1(w, j, i) ((struct BeaconDetailGraWinRec *)((char *)(w) + (j) * 0x80 + (i) * 16))
#define HANDLE(p, k) (*(int *)((p) + (k)))
#define ARG(p, k) (*(int *)((p) + (k) + 0xC))
#define CALLS(r) do { void *d = (r)->d; BMP_WIN_TransferChars(d); BMP_WIN_MakeScreen(d); BG_SYS_PushTile(BMP_WIN_GetBgLayer(d)); } while (0)
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
struct PmsDraw;
struct Actor;
struct DispVram;
struct Node;
struct BgTemplate;
struct DispConfig;
struct Bank;
struct Ctx;
struct Bits;
struct Vec2;
struct BeaconDetailGraTransfer;
struct Bmp;
struct BeaconDetailGraPmsDraw;
struct BeaconDetailGraPmsDraw;
struct TouchBar;
struct TouchBar;
struct TcblNode;
struct Tcbl;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct TouchBarParam { unsigned char *f0; unsigned f4; int f8; unsigned fC,f10,f14; int f18,f1c; };




typedef signed int     s32;



struct BeaconDetailGraPosition { short x,y,z; unsigned char a,b; };



struct BeaconDetailGraBgEntry { unsigned id; char fields[32]; unsigned a,b; };

struct BeaconDetailGraRenderBlock { unsigned w[8]; };



struct BeaconDetailGraWinRec { void *d; int h; int u, v; };

struct BeaconDetailGraWinRec32 { void *d; int h; char pad[24]; };

struct BeaconDetailGraWinSet { struct BeaconDetailGraWinRec a[4]; struct BeaconDetailGraWinRec32 b; struct BeaconDetailGraWinRec32 c; };


enum Index { IndexZero=0 };

struct BeaconDetailGraPair { u16 a,b; };

struct BeaconDetailGraQuad { u16 a,b,c,d; };


typedef signed short s16;

typedef signed char s8;

typedef void (*TcblFunc)(struct TcblNode *,void *);

struct BeaconDetailGraPrintTask { int arg; u8 *owner; int *counter; };

/*
 * One real struct per object in this overlay.  The old per-function
 * ObjNNNNN matched-include views are folded into these.
 */
struct ProcOwner;              /* PROCSYS_AllocProcWork owner (0x0203159C) */
struct GflHeap;                /* GFL heap handle (0x020315D4) */
struct TouchBar;               /* touch bar instance (TOUCHBAR_*) */
struct GameBeaconRecord;       /* one GAME_BEACON_ACCESSOR record */
struct BeaconDetailGraTransfer; /* CLACT_TransferCharacter arg (0x0204A9D0) */
struct BeaconDetailGraPmsDraw;  /* PMS_DRAW instance (0x0202DCC4) */

/* CLACT palette/character/cellanim descriptor (configA/configB). */
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
union BeaconDetailGraWin { void *window; u32 handle; };

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
struct BeaconDetailGraConfig { u8 pad_00[9]; u8 mode; };

/* An unpacked G2d resource; the payload pointer lives at +0xC. */
struct BeaconDetailGraRes { u8 pad_00[12]; void *data; };

union BeaconDetailGraFont { void *ptr; u32 handle; };
union BeaconDetailGraTrainer { u32 handle; void *set; };

/* The main 620-byte beacon-detail graphics work object. */
struct BeaconDetailGraWork {
    u16 heapId;            /* 0x000 */
    u16 gfxHeapId;         /* 0x002 */
    int state;             /* 0x004 */
    u8 pad_08[4];
    int subMode;           /* 0x00C */
    int fadeMode;          /* 0x010 */
    void *config;          /* 0x014 */
    void *tcbl;            /* 0x018 */
    void *townInfo;        /* 0x01C */
    u8 pad_20[4];
    void *infoQueue;       /* 0x024 */
    void *beaconRecord;    /* 0x028 */
    u16 level;             /* 0x02C */
    u8 slotIndex;          /* 0x02E */
    u8 slotMax;            /* 0x02F */
    u8 cursor;             /* 0x030 */
    u8 slotOrder[16];      /* 0x031 */
    u8 pad_41[15];
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
    void *infoWindow;      /* 0x148 */
    void *detailWindow;    /* 0x14C */
    u8 pad_150[8];
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

extern int GF_OVERLAY_Load(int);
extern void GFL_HEAP_CreateChildHeap(unsigned,unsigned,unsigned);
extern void *PROCSYS_AllocProcWork(struct ProcOwner *obj, unsigned int size, unsigned int heap);
extern void MI_CpuFill8(void *,int,int);
extern void PROCSYS_FreeProcWork(struct GflHeap *);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
extern void GF_OVERLAY_Unload(int);
extern void TCBL_Main(struct Tcbl *);
extern unsigned PRINTSYS_QUE_Main(struct PrintSys *);
extern unsigned PRINTSYS_QUE_IsFinished(const struct PrintSys *);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void FADE_Start(unsigned,int,int,int);
extern int FADE_IsActive(void);
extern int TOUCHBAR_GetPressedButtonIdIfDone(unsigned char *);
extern u8 *GAME_BEACON_ACCESSOR_AllocInfo(u32);
extern u32 GAME_DATA_GetItemUseWork(const struct GameData *);
extern u32 BEACON_STATUS_GetLog(u32 a);
extern u8 GAME_BEACON_ACCESSOR_TableGetCount(u8 *);
extern int GAME_BEACON_ACCESSOR_TableRingGet(struct Queue *,struct GameBeaconRecord *,u16 *,int);
extern int GAME_BEACON_ACCESSOR_IsInfoInvalid(struct GameBeaconRecord *);
extern int GAME_BEACON_ACCESSOR_IsDistributionAction(u8 *);
extern signed char MSG_SPEED_GetWait(void);
extern int TOWNMAP_GRH_LoadTownInfo(int);
extern void TOWNMAP_GRH_FreeTownInfo(void *p);
extern u32 GFL_HEAP_Free(void *p);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, unsigned int count, unsigned int workSize);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void GF_FONT_SetTextColor(unsigned,unsigned,unsigned);
extern void *PRINTSYS_QUE_CreateEx(unsigned short,unsigned);
extern struct GfFont *GF_FONT_Create(int,int,int,int,unsigned);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct MsgBank *MSGDATA_CreateFromArchive(unsigned,unsigned,unsigned,unsigned);
extern struct U16Vec *STRBUF_Create(unsigned,unsigned);
extern void STRBUF_Delete(struct U16Vec *);
extern unsigned int MSGDATA_Delete(struct MsgBank *bank);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void TCBL_Destroy(struct Tcbl *);
extern void ARC_TOOL_DeleteHandle(void *);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,u32,u32,u32,u32,u16);
extern u32 ARC_UTIL_UploadBgCharFromHandle(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *,u32,u32,u32,u32,u32,u16);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32);
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *,u32,u32);
extern int NNS_G2dGetUnpackedPaletteData(struct NitroFileHeader *,void **);
extern void G2x_SetBlendAlpha_(u32 *,u32,u32,int,int);
extern struct TouchBar *TOUCHBAR_Create(struct TouchBarParam *,int);
extern void TOUCHBAR_Delete(unsigned char *);
extern void TOUCHBAR_Update(struct TouchBar *p);
extern signed int CLACT_RegisterPaletteEx(void *a, unsigned int b, unsigned int c, unsigned int d, unsigned short e, unsigned short f, unsigned short g);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleasePalette(u32 i);
extern int POKEGRA_OpenTrainerHandle(int a0);
extern int NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *,void **);
extern u32 POKEGRA_RegisterTrainerCgr(u32,u32,u32,u32);
extern s32 POKEGRA_RegisterTrainerPalette(u32 a, u32 b, u32 c, u32 d, u16 e);
extern int POKEGRA_RegisterTrainerCellAnim(int a0, int a1, int a2, unsigned short a3);
extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,unsigned char,unsigned char,unsigned char);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *,unsigned char);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *);
extern unsigned char BMP_WIN_GetBgLayer(struct Descriptor *);
extern struct ClactActor *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorPaletteOffset(struct ClactActor *o, u32 v, u32 flag);
extern void CLACT_SetActorDrawEnable(struct ClactActor *p, u32 v);
extern void CLACT_DeleteActor(struct ClactActor *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern struct PmsDraw *PMS_DRAW_Create(u32,u32,u32,u32,u8,u8,u16);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *,u8);
extern void PMS_DRAW_SetPrintColor(struct PmsDraw *,u16);
extern void PMS_DRAW_SetFollowBgScroll(struct PmsDraw *,u32);
extern void CLACT_SetActorObjMode(struct Actor *,u32);
extern void PMS_DRAW_Delete(struct ClactActor *p);
extern int PMS_DRAW_Main(u32);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void BG_SYS_ClearGraphicsMemory(u32 keep);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BMP_SetDisplaySwap(u32 swap);
extern void BG_SYS_ResetSubDisplay(void);
extern void BG_SYS_ClearMainPlanes(void);
extern void BG_SYS_ClearSubPlanes(void);
extern void GF_FONT_InitTextColor(void);
extern void *GFL_USE_AddMainTask(void (*)(void *,void *),void *,int);
extern void TCB_DeleteTask(struct Node *n);
extern void BG_SYS_Create(int);
extern void BMP_WIN_Init(int);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void BG_SYS_SetPlaneVisible(u8,u8);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const struct Cfg *cfg, unsigned int arg, unsigned int heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct ClactActor *CLACT_CreateRenderer(u8 *a0, u32 a1, u32 heap);
extern void CLACT_SetRendererCulling(struct Actor *a0, int a1);
extern void CLACT_SetUnitRenderer(struct Bank *bank, void *p);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void BG_SYS_SetSubPlaneVisible(u32 mask, u32 enable);
extern void CLACT_DeleteRenderer(void *);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
extern void CLACT_ExitSystem(void);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern int TOUCHBAR_GetPressedButtonIdIfPressing(unsigned char *);
extern u32 KEY_GetTrg(void);
extern unsigned ICA_ANIME_GetUnk330(const struct Ctx *);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outA, u32 *outB);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void DC_FlushRange(void *,unsigned);
extern void GX_LoadBGPltt(void *,unsigned,unsigned);
extern void GXS_LoadBGPltt(void *,unsigned,unsigned);
extern void GX_LoadOBJPltt(void *,unsigned,unsigned);
extern void GXS_LoadOBJPltt(void *,unsigned,unsigned);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
extern unsigned int GAME_BEACON_ACCESSOR_GetPmVersion(void *a0);
extern unsigned GAME_BEACON_ACCESSOR_GetDetailsType(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetDetailsMonsNo(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetDetailsTrainerNo(const char *);
extern unsigned short GAME_BEACON_ACCESSOR_GetZoneId(const struct Bits *);
extern u32 ZONEDATA_GetPlaceNameId(u32 id);
extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);
extern void WORDSET_SetSlotPokeData(struct WordSet *p, u32 i, u32 a);
extern void WORDSET_SetSlotFromMsgBE(struct WordSet *p, u32 i, u32 v);
extern void WORDSET_SetSlotFromMsg59(struct WordSet *p, u32 i, u32 v);
extern void CLACT_SetActorAnimSeq(struct ClactActor *p, u16 value);
extern void CLACT_RestartActorAnim(struct Actor *a);
extern void CLACT_AddActorSurfacePos(struct ClactActor *p, const struct Vec2 *delta, u32 which);
extern void MSGDATA_ReadString(struct MsgBank*,u32,void*);
extern void WORDSET_CopyTaggedText(struct WordSet*,void*,void*);
extern void CLACT_TransferCharacter(int,struct BeaconDetailGraTransfer*);
extern void BMP_FillRect(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern u32 PMS_DRAW_IsActive(const struct BeaconDetailGraPmsDraw *, u32);
extern void PMS_DRAW_SetVisible(struct BeaconDetailGraPmsDraw *, int, u32);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void BG_SYS_FillScrollArea(u32,u32,u32);
extern void GAME_BEACON_ACCESSOR_GetFavoriteColorRgb(int a0, int a1);
extern void PALANM_BlendColors(u16 *,u16 *,u32,int,u16);
extern void GAME_BEACON_ACCESSOR_GetPlayerName(struct GameBeaconRecord *,void *);
extern int GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond(int a0);
extern void STRBUF_Clear(struct U16Vec *);
extern void WORDSET_SetSlotFromMsg38(struct WordSet *,u32,u32);
extern int GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst(int a0);
extern void WORDSET_SetSlotFromMsg2B(struct WordSet *,u32,u32);
extern void GAME_BEACON_ACCESSOR_GetPlayTime(const struct GameBeaconRecord *p, u16 *a, u16 *b);
extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);
extern u8 GAME_BEACON_ACCESSOR_GetNation(const u8 *p);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *,u32,u32);
extern u8 GAME_BEACON_ACCESSOR_GetArea(const u8 *p);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *,u32,u32,u32);
extern u32 GAME_BEACON_ACCESSOR_GetPassCount(const struct GameBeaconRecord *p);
extern u32 GAME_BEACON_ACCESSOR_GetThanksCount(const struct GameBeaconRecord *p);
extern u32 PMS_DRAW_IsActive(const struct BeaconDetailGraPmsDraw *,u32);
extern void PMS_DRAW_Clear(struct BeaconDetailGraPmsDraw *,int,u32);
extern void GAME_BEACON_ACCESSOR_GetDetailsPms(const struct GameBeaconRecord *p, struct BeaconDetailGraQuad *q);
extern void PMS_DRAW_Print(u32,u32,u32,u32);
extern u8 GAME_BEACON_ACCESSOR_GetTrainerAppearance(struct GameBeaconRecord *);
extern u32 CURSOR_MOVE_GetTableGroup(u32);
extern void POKEGRA_LoadTrainerGraphics(void *set, u32 id, void *dstA, void *dstB, volatile u16 which);
extern u8 GAME_BEACON_ACCESSOR_GetResearchTeamRank(void *);
extern unsigned short GAME_BEACON_ACCESSOR_GetTownmapRootZoneId(const struct Bits *p);
extern int TOWNMAP_GRH_FindRecordIndex(int,int);
extern u16 TOWNMAP_GRH_GetTownInfoValue(char *,int,int);
extern struct TcblNode *TCBL_AddTask(struct Tcbl *, void (*)(struct TcblNode *, void *), u32, u32);
extern void *TCBL_GetWork(struct Tcbl *);
extern void TCBL_DeleteTask(struct TcblNode*);
extern void TOUCHBAR_SetAllButtonsEnabled(u8 *, u32);
extern int TOUCHPANEL_GetTrg(void);
extern void PRINTSYS_PrintQueColor(void *, u32, u32, u32, u32, u32, u16);
extern void BEACON_DETAIL_GRA_PrintWaitTask(int,int **);
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
struct TouchBar *BEACON_DETAIL_GRA_CreateTouchBar(int manager,int heap);
void BEACON_DETAIL_GRA_DeleteTouchBar(unsigned char *p);
void BEACON_DETAIL_GRA_UpdateTouchBar(struct TouchBar *p);
void BEACON_DETAIL_GRA_RegisterActorGfx(unsigned short *p,int *out,const struct ClactResConfig *cfg,void *handle);
void BEACON_DETAIL_GRA_ReleaseActorGfx(void *unused, char *p);
void BEACON_DETAIL_GRA_LoadTrainerGfx(char *p,u32 handle);
void BEACON_DETAIL_GRA_FreeTrainerGfx(char *p);
void BEACON_DETAIL_GRA_CreateWindow(struct BeaconDetailGraWindow *p,unsigned char layer,unsigned char palette,unsigned x,unsigned char y,unsigned char width,unsigned char height);
unsigned BEACON_DETAIL_GRA_CreatePositionedActor(unsigned short *p,void *manager,unsigned *r,short x,short y,unsigned char z,unsigned char a,unsigned char b,unsigned short flag);
void BEACON_DETAIL_GRA_CreateDetailActors(char *p);
void BEACON_DETAIL_GRA_DeleteDetailActors(struct BeaconDetailGraWork *p);
void BEACON_DETAIL_GRA_CreateInfoWindow(char *p);
u32 BEACON_DETAIL_GRA_DeleteInfoWindow(u32 *p);
void BEACON_DETAIL_GRA_CreateListWindows(char *p);
void BEACON_DETAIL_GRA_DeleteListWindows(char *p);
int BEACON_DETAIL_GRA_IsPmsActive(u32 *p);
void *BEACON_DETAIL_GRA_Create(int a,int heap);
void BEACON_DETAIL_GRA_Destroy(unsigned *p);
void BEACON_DETAIL_GRA_Draw(char *p);
void *BEACON_DETAIL_GRA_GetClactUnit(char *p);
void BEACON_DETAIL_GRA_Task(void *unused, char *p);
void BEACON_DETAIL_GRA_InitBgSystem(void *p,int heap);
void BEACON_DETAIL_GRA_ExitBgSystem(void *p);
void BEACON_DETAIL_GRA_Noop(void *p);
void BEACON_DETAIL_GRA_UpdateBg(void *a0);
void BEACON_DETAIL_GRA_InitClact(void **p,void *a,int heap);
void BEACON_DETAIL_GRA_ExitClact(char *p);
void BEACON_DETAIL_GRA_DrawClact(void *a0);
void BEACON_DETAIL_GRA_VBlankClact(void *a0);
u32 BEACON_DETAIL_GRA_ReadPtr(u32*p);
void BEACON_DETAIL_GRA_SetupBeaconList(unsigned char *p);
int BEACON_DETAIL_GRA_UpdateInteract(unsigned char *p);
void BEACON_DETAIL_GRA_RefreshButtons(u8*p);
int BEACON_DETAIL_GRA_IsTouchOnActor(u8*p);
void BEACON_DETAIL_GRA_PlaySe(int a);
void BEACON_DETAIL_GRA_LoadPalette(void *p,unsigned mode,unsigned a,unsigned b);
void BEACON_DETAIL_GRA_UpdateButtons(unsigned char *p);
int BEACON_DETAIL_GRA_GetPmVersionClass(void *a0);
const u8*BEACON_DETAIL_GRA_FindAppearanceType(u32 n);
void BEACON_DETAIL_GRA_SetNameSlots(void *p,void *q);
void BEACON_DETAIL_GRA_SetActorAnim(void *p, unsigned short value);
void BEACON_DETAIL_GRA_SetActorPos(void *a0, short a1, short a2, int a3);
void BEACON_DETAIL_GRA_PrintMsg(u8*p, u8 n);
void BEACON_DETAIL_GRA_TransferChar(u8*p,u32 n);
void BEACON_DETAIL_GRA_InitWindows(char *p);
void BEACON_DETAIL_GRA_DrawWindowRecord(void *p,void **q,int v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e);
void BEACON_DETAIL_GRA_SetSlotVisible(char *p, u8 index, u32 enable);
void BEACON_DETAIL_GRA_MoveActor(u8*p,int a);
void BEACON_DETAIL_GRA_SetupSlot(char *p,void *record,u16 unused,u8 slot);
void BEACON_DETAIL_GRA_UpdateSlotInfo(char *p);
void BEACON_DETAIL_GRA_AddFadeTask(char *owner, int direction, int *counter);
void BEACON_DETAIL_GRA_Callback(struct TcblNode*task,u8*p);
void BEACON_DETAIL_GRA_AddTimerTask(char*p);
void BEACON_DETAIL_GRA_AddTimerTaskEx(char *owner, int *counter);
int BEACON_DETAIL_GRA_UpdateTimer(char *p);
void BEACON_DETAIL_GRA_TimerCallback(struct TcblNode *task, void *data);
void BEACON_DETAIL_GRA_AddSlideTask(char *owner, u8 index, int position, u8 direction, int *counter);
void BEACON_DETAIL_GRA_SlideCallback(struct TcblNode *task, char *p);
void BEACON_DETAIL_GRA_AddSlotSlideTask(char*p,int a);
void BEACON_DETAIL_GRA_AddSlotSlideTaskEx(char *owner, int direction, int *counter);
void BEACON_DETAIL_GRA_SlotSlideCallback(struct TcblNode *task,char *work);
void BEACON_DETAIL_GRA_DrawRecord(char *owner, char *record, u32 b, u16 c, u32 d, u16 f);
void BEACON_DETAIL_GRA_AddPrintWaitTask(u8 *p,int arg,int *counter);
extern unsigned char ov067_id[],ov072_id[];
extern unsigned char ov072_id[],ov067_id[];
extern const unsigned char d_021BDB4C[];
extern const struct ClactResConfig configA,configB;
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






int BEACON_DETAIL_GRA_Init(struct ProcOwner *obj,int unused1,void *config)
{
    char *p;
    GF_OVERLAY_Load((int)ov067_id);
    GF_OVERLAY_Load((int)ov072_id);
    GFL_HEAP_CreateChildHeap(1,119,3<<16);
    p=PROCSYS_AllocProcWork(obj,620,119);
    MI_CpuFill8(p,0,620);
    ((struct BeaconDetailGraWork *)p)->config=config;
    ((struct BeaconDetailGraWork *)p)->heapId=119;
    ((struct BeaconDetailGraWork *)p)->gfxHeapId=0x8077;
    ((struct BeaconDetailGraWork *)p)->clactObj=BEACON_DETAIL_GRA_Create(0,((struct BeaconDetailGraWork *)p)->heapId);
    BEACON_DETAIL_GRA_LoadBeaconInfo((u8 *)p);
    BEACON_DETAIL_GRA_CreateObjects(p);
    BEACON_DETAIL_GRA_LoadBackground(p,((struct BeaconDetailGraWork *)p)->heapId);
    BEACON_DETAIL_GRA_CreateInfoWindow(p);
    BEACON_DETAIL_GRA_LoadTrainerGfx(p,(u32)(((struct BeaconDetailGraWork *)p)->arcFile));
    BEACON_DETAIL_GRA_CreateDetailActors(p);
    BEACON_DETAIL_GRA_CreateListWindows(p);
    ((struct BeaconDetailGraWork *)p)->touchBar=(void *)BEACON_DETAIL_GRA_CreateTouchBar((int)(BEACON_DETAIL_GRA_GetClactUnit(((struct BeaconDetailGraWork *)p)->clactObj)), ((struct BeaconDetailGraWork *)p)->heapId);
    return 1;
}






int BEACON_DETAIL_GRA_Exit(struct GflHeap *heap,int unused1,int unused2,char *p)
{
    BEACON_DETAIL_GRA_DeleteTouchBar(((struct BeaconDetailGraWork *)p)->touchBar);
    BEACON_DETAIL_GRA_DeleteListWindows(p);
    BEACON_DETAIL_GRA_DeleteDetailActors((struct BeaconDetailGraWork *)p);
    BEACON_DETAIL_GRA_FreeTrainerGfx(p);
    BEACON_DETAIL_GRA_DeleteInfoWindow((unsigned *)p);
    BEACON_DETAIL_GRA_FreeBackground(p);
    BEACON_DETAIL_GRA_DeleteObjects(p);
    BEACON_DETAIL_GRA_Delete(p);
    BEACON_DETAIL_GRA_Destroy(*(unsigned * *)&((struct BeaconDetailGraWork *)p)->clactObj);
    PROCSYS_FreeProcWork(heap);
    GFL_HEAP_DeleteChecked(119);
    GF_OVERLAY_Unload((int)ov072_id);
    GF_OVERLAY_Unload((int)ov067_id);
    return 1;
}






int BEACON_DETAIL_GRA_Main(int unused0,int *state,int unused2,char *p)
{
    if (((struct BeaconDetailGraWork *)p)->fadeMode) return 1;
    if (*state>=2 && *state<=3) BEACON_DETAIL_GRA_UpdateTouchBar((struct TouchBar *)(((struct BeaconDetailGraWork *)p)->touchBar));
    switch (*state) {
    case 0: *state=BEACON_DETAIL_GRA_StateInit((unsigned char *)p); break;
    case 1: *state=BEACON_DETAIL_GRA_StateFadeIn(p); break;
    case 2: *state=BEACON_DETAIL_GRA_StateInteract(p); break;
    case 3: *state=BEACON_DETAIL_GRA_StateClose(p); break;
    case 4: *state=BEACON_DETAIL_GRA_StateFadeOut(p); break;
    case 5: return 1;
    }
    TCBL_Main(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)p)->tcbl);
    PRINTSYS_QUE_Main(*(struct PrintSys * *)&((struct BeaconDetailGraWork *)p)->printQue);
    BEACON_DETAIL_GRA_IsPmsActive((unsigned *)p);
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






int BEACON_DETAIL_GRA_StateInit(unsigned char *p){switch(((struct BeaconDetailGraWork *)p)->state){case 0:BEACON_DETAIL_GRA_SetupBeaconList(p);(((struct BeaconDetailGraWork *)p)->state)++;break;case 1:if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct BeaconDetailGraWork *)p)->printQue)){((struct BeaconDetailGraWork *)p)->state=0;return 1;}break;}return 0;}






int BEACON_DETAIL_GRA_StateFadeIn(char *p){switch(((struct BeaconDetailGraWork *)p)->state){case 0:FADE_Start(3,16,0,0);(((struct BeaconDetailGraWork *)p)->state)++;break;case 1:if(FADE_IsActive()==0){((struct BeaconDetailGraWork *)p)->state=0;return 2;}break;}return 1;}






int BEACON_DETAIL_GRA_StateFadeOut(char *p)
{
    switch (((struct BeaconDetailGraWork *)p)->state) {
    case 0:
        if (((struct BeaconDetailGraConfig *)(*(char * *)&((struct BeaconDetailGraWork *)p)->config))->mode==0) {
            BEACON_DETAIL_GRA_UpdateTouchBar((struct TouchBar *)(((struct BeaconDetailGraWork *)p)->touchBar));
            if (TOUCHBAR_GetPressedButtonIdIfDone(*(unsigned char * *)&((struct BeaconDetailGraWork *)p)->touchBar)!=1) break;
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
    *(u8 **)(p+40)=GAME_BEACON_ACCESSOR_AllocInfo(*(u16 *)p);
    *(u32 *)(p+32)=GAME_DATA_GetItemUseWork(*(const struct GameData **)(*(u8 **)(p+20)+4));
    *(void **)(p+36)=(void *)BEACON_STATUS_GetLog((u32)(*(void **)(p+32)));
    count=GAME_BEACON_ACCESSOR_TableGetCount(*(u8 **)(p+36));
    p[48]=255;
    for(i=0;i<count;i++){
        GAME_BEACON_ACCESSOR_TableRingGet(*(struct Queue **)(p+36),*(struct GameBeaconRecord **)(p+40),(u16 *)(p+44),i);
        if(GAME_BEACON_ACCESSOR_IsInfoInvalid(*(struct GameBeaconRecord **)(p+40))==0 && GAME_BEACON_ACCESSOR_IsDistributionAction(*(u8 **)(p+40))==0){
            if((*(u8 **)(p+20))[8]==i)p[48]=p[47];
            p[p[47]++ +49]=i;
        }
    }
    if(p[48]==255 || p[48]>=p[47])p[48]=0;
    if(p[47]==0)*(u32 *)(p+16)=1;
    p[79]=MSG_SPEED_GetWait();
    *(int *)(p+28)=TOWNMAP_GRH_LoadTownInfo(*(u16 *)p);
}







void BEACON_DETAIL_GRA_Delete(char *p)
{
    TOWNMAP_GRH_FreeTownInfo((void *)(((struct BeaconDetailGraWork *)p)->townInfo));
    GFL_HEAP_Free((void *)(((struct BeaconDetailGraWork *)p)->beaconRecord));
}






void BEACON_DETAIL_GRA_CreateObjects(char *p)
{
    *(struct Tcbl * *)&((struct BeaconDetailGraWork *)p)->tcbl=TCBL_Create(((struct BeaconDetailGraWork *)p)->heapId,((struct BeaconDetailGraWork *)p)->heapId,64,128);
    ((struct BeaconDetailGraWork *)p)->arcFile=ARC_TOOL_CreateHandle(173,((struct BeaconDetailGraWork *)p)->heapId);
    GF_FONT_SetTextColor(7,8,15);
    ((struct BeaconDetailGraWork *)p)->printQue=PRINTSYS_QUE_CreateEx(2048,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct GfFont * *)&((struct BeaconDetailGraWork *)p)->font.ptr=GF_FONT_Create(23,0,0,0,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet=WORDSET_Create(8,64,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct MsgBank * *)&((struct BeaconDetailGraWork *)p)->msgBank=MSGDATA_CreateFromArchive(0,2,7,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct MsgBank * *)&((struct BeaconDetailGraWork *)p)->msgBank2=MSGDATA_CreateFromArchive(0,2,231,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf=STRBUF_Create(109,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf2=STRBUF_Create(109,((struct BeaconDetailGraWork *)p)->heapId);
    *(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf3=STRBUF_Create(109,((struct BeaconDetailGraWork *)p)->heapId);
}






void BEACON_DETAIL_GRA_DeleteObjects(char *p)
{
    STRBUF_Delete(*(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf3);
    STRBUF_Delete(*(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf2);
    STRBUF_Delete(*(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf);
    MSGDATA_Delete(*(struct MsgBank * *)&((struct BeaconDetailGraWork *)p)->msgBank2);
    MSGDATA_Delete(*(struct MsgBank * *)&((struct BeaconDetailGraWork *)p)->msgBank);
    WORDSET_DeleteStrbufED04(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet);
    GF_FONT_Delete(((struct BeaconDetailGraWork *)p)->font.ptr);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct BeaconDetailGraWork *)p)->printQue);
    PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct BeaconDetailGraWork *)p)->printQue);
    GF_FONT_SetDefaultTextColor();
    TCBL_Destroy(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)p)->tcbl);
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
    ((struct BeaconDetailGraWork *)p)->charHandle=ARC_TOOL_LoadHandleMember(*(struct ArcFile * *)&((struct BeaconDetailGraWork *)p)->arcFile,29,((struct BeaconDetailGraWork *)p)->heapId);
    NNS_G2dGetUnpackedPaletteData(*(struct NitroFileHeader * *)&((struct BeaconDetailGraWork *)p)->charHandle,(void **)(p+280));
    ((struct BeaconDetailGraWork *)p)->charData=((struct BeaconDetailGraRes *)(*(char * *)&((struct BeaconDetailGraWork *)p)->charFile))->data;
    ARC_TOOL_DeleteHandle(arc);
    G2x_SetBlendAlpha_((u32 *)0x04000050,2,30,11,5);
    G2x_SetBlendAlpha_((u32 *)0x04001050,3,31,13,3);
}







void BEACON_DETAIL_GRA_FreeBackground(char *p)
{
    GFL_HEAP_Free(((struct BeaconDetailGraWork *)p)->charHandle);
    *(volatile unsigned short *)0x04001050 = 0;
    *(volatile unsigned short *)0x04000050 = 0;
}






struct TouchBar *BEACON_DETAIL_GRA_CreateTouchBar(int manager,int heap){struct TouchBarParam a;enum {Zero} zero=Zero;MI_CpuFill8(&a,0,32);a.f0=(unsigned char *)d_021BDB4C;a.f4=3;a.f10=13;a.f14=11;a.f8=manager;a.fC=zero;a.f18=zero;return TOUCHBAR_Create(&a,heap);}






void BEACON_DETAIL_GRA_DeleteTouchBar(unsigned char *p){TOUCHBAR_Delete(p);}






void BEACON_DETAIL_GRA_UpdateTouchBar(struct TouchBar *p){TOUCHBAR_Update(p);}






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
void BEACON_DETAIL_GRA_LoadTrainerGfx(char *p,u32 handle)
{
    struct ClactResConfig a,b;
    struct ArcFile *arc;
    int i;
    ((struct BeaconDetailGraWork *)p)->trainer.handle=POKEGRA_OpenTrainerHandle(((struct BeaconDetailGraWork *)p)->heapId);
    a=configA;
    BEACON_DETAIL_GRA_RegisterActorGfx((u16 *)p, (int *)(p+92), (const struct ClactResConfig *)&a, (void *)handle);
    b=configB;
    arc=ARC_TOOL_CreateHandle(32,((struct BeaconDetailGraWork *)p)->gfxHeapId);
    BEACON_DETAIL_GRA_RegisterActorGfx((u16 *)p, (int *)(p+128), (const struct ClactResConfig *)&b, (void *)((u32)arc));
    ((struct BeaconDetailGraWork *)p)->paletteHandle=ARC_TOOL_LoadHandleMember(arc,0,((struct BeaconDetailGraWork *)p)->heapId);
    NNS_G2dGetUnpackedPaletteData(*(struct NitroFileHeader * *)&((struct BeaconDetailGraWork *)p)->paletteHandle,(void **)(p+268));
    ((struct BeaconDetailGraWork *)p)->paletteData=((struct BeaconDetailGraRes *)(*(char * *)&((struct BeaconDetailGraWork *)p)->paletteFile))->data;
    for(i=0;i<16;i++){
        *(void **)(p+i*8+144)=ARC_TOOL_LoadHandleMember(arc,i+49,((struct BeaconDetailGraWork *)p)->heapId);
        NNS_G2dGetUnpackedCharacterData(*(struct NitroFileHeader **)(p+i*8+144),(void **)(p+140+i*8));
    }
    ARC_TOOL_DeleteHandle(arc);
    for(i=0;i<2;i++){
        char *q=p+i*12;
        ((struct BeaconDetailGraWork *)q)->actors[1].character=POKEGRA_RegisterTrainerCgr(((struct BeaconDetailGraWork *)p)->trainer.handle,i+2,1,((struct BeaconDetailGraWork *)p)->heapId);
        ((struct BeaconDetailGraWork *)q)->actors[1].palette=(u32)POKEGRA_RegisterTrainerPalette(((struct BeaconDetailGraWork *)p)->trainer.handle,i+2,1,(u16)((i+8)<<5),((struct BeaconDetailGraWork *)p)->heapId);
        ((struct BeaconDetailGraWork *)q)->actors[1].cellAnim=POKEGRA_RegisterTrainerCellAnim(i+2,0,1,((struct BeaconDetailGraWork *)p)->heapId);
    }
}





void BEACON_DETAIL_GRA_FreeTrainerGfx(char *p)
{
    int i;
    for(i=0;i<2;i++) BEACON_DETAIL_GRA_ReleaseActorGfx(p,p+0x68+i*12);
    for(i=0;i<16;i++) GFL_HEAP_Free(*(void **)(p+0x90+i*8));
    GFL_HEAP_Free(((struct BeaconDetailGraWork *)p)->paletteHandle);
    BEACON_DETAIL_GRA_ReleaseActorGfx(p,p+0x80);
    BEACON_DETAIL_GRA_ReleaseActorGfx(p,p+0x5c);
    ARC_TOOL_DeleteHandle(((struct BeaconDetailGraWork *)p)->trainer.set);
}





void BEACON_DETAIL_GRA_CreateWindow(struct BeaconDetailGraWindow *p,unsigned char layer,unsigned char palette,unsigned x,unsigned char y,unsigned char width,unsigned char height)
{
    struct Descriptor *window;
    p->window=(struct Descriptor *)BMP_WIN_Create(layer,x,y,width,height,palette,1);
    p->buffer=BMP_WIN_GetBmp(p->window);
    p->copy=p->window;
    p->state=0;
    BMP_Clear(p->buffer,3);
    window=p->window;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen((struct Cfg *)window);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(window));
}





unsigned BEACON_DETAIL_GRA_CreatePositionedActor(unsigned short *p,void *manager,unsigned *r,short x,short y,unsigned char z,unsigned char a,unsigned char b,unsigned short flag){struct BeaconDetailGraPosition pos;pos.x=x;pos.y=y;pos.z=z;pos.b=b;pos.a=a;return (unsigned)CLACT_CreateActor(manager,r[1],r[0],r[2],&pos,flag,*p);}




void BEACON_DETAIL_GRA_CreateDetailActors(char *p)
{
    void *q=BEACON_DETAIL_GRA_GetClactUnit(((struct BeaconDetailGraWork *)p)->clactObj);
    void *a=(void *)BEACON_DETAIL_GRA_CreatePositionedActor((short unsigned int *)p,(void *)q,(unsigned int *)(p+0x80),128,120,0,0,2,0);
    ((struct BeaconDetailGraWork *)p)->mapActors[0]=a;
    CLACT_SetActorPaletteOffset(a,0,1);
    ((struct BeaconDetailGraWork *)p)->mapActors[1]=(void *)BEACON_DETAIL_GRA_CreatePositionedActor((short unsigned int *)p,(void *)q,(unsigned int *)(p+0x5c),96,120,0,1,2,0);
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


void BEACON_DETAIL_GRA_CreateInfoWindow(char *p){BEACON_DETAIL_GRA_CreateWindow((struct BeaconDetailGraWindow *)((struct BeaconDetailGraWindow *)(p+0x148)), 1, 11, 2, 22, 28, 6);}





/*
 * Tail-call getter: loads p[0x52] and tail-calls BMP_WIN_Delete.
 *
 * Addresses are Black-image addresses.
 */
u32 BEACON_DETAIL_GRA_DeleteInfoWindow(u32 *p)
{
    return BMP_WIN_Delete((struct Descriptor *)p[0x52]);
}




void BEACON_DETAIL_GRA_CreateListWindows(char *p)
{
    void *manager;
    int i,j,layer;
    char *q;
    manager=BEACON_DETAIL_GRA_GetClactUnit(*(void **)(p+80));
    *(struct PmsDraw **)(p+344)=PMS_DRAW_Create((u32)manager,1,*(u32 *)(p+300),*(u32 *)(p+296),10,2,*(u16 *)p);
    PMS_DRAW_SetNullColorPalette(*(struct PmsDraw **)(p+344),4);
    PMS_DRAW_SetPrintColor(*(struct PmsDraw **)(p+344),15812);
    PMS_DRAW_SetFollowBgScroll(*(struct PmsDraw **)(p+344),1);
    for(i=0;i<2;i++){
        layer=i+4;
        q=p+348+i*128;
        q[126]=(u8)layer;
        *(u32 *)(q+112)=BMP_WIN_Create((u8)layer,2,15,28,4,i,1);
        for(j=0;j<4;j++)BEACON_DETAIL_GRA_CreateWindow((struct BeaconDetailGraWindow *)(q+j*16),layer,i,2,j*2+1,19,2);
        BEACON_DETAIL_GRA_CreateWindow((struct BeaconDetailGraWindow *)(q+64),layer,i,2,9,19,2);
        BEACON_DETAIL_GRA_CreateWindow((struct BeaconDetailGraWindow *)(q+80),layer,i,3,11,28,4);
        BEACON_DETAIL_GRA_CreateWindow((struct BeaconDetailGraWindow *)(q+96),layer,i,4,19,27,4);
        *(void **)(q+120)=(void *)BEACON_DETAIL_GRA_CreatePositionedActor((unsigned short *)p,manager,(unsigned *)(p+104+i*12),220,44,0,1,i,1);
        CLACT_SetActorObjMode(*(struct Actor **)(q+120),0);
        CLACT_SetActorDrawEnable(*(void **)(q+120),0);
        *(void **)(q+116)=(void *)BEACON_DETAIL_GRA_CreatePositionedActor((unsigned short *)p,manager,(unsigned *)(p+92),200,80,6,0,i,1);
        CLACT_SetActorObjMode(*(struct Actor **)(q+116),1);
        CLACT_SetActorDrawEnable(*(void **)(q+116),0);
    }
}




void BEACON_DETAIL_GRA_DeleteListWindows(char *p)
{
    int i=0,j;
    char *base=p+0x15c;
    for(;i<2;i++) {
        char *q=base+i*128;
        CLACT_SetActorDrawEnable(((struct BeaconDetailGraEntry *)q)->actorB,0); CLACT_DeleteActor(((struct BeaconDetailGraEntry *)q)->actorB);
        CLACT_SetActorDrawEnable(((struct BeaconDetailGraEntry *)q)->actorA,0); CLACT_DeleteActor(((struct BeaconDetailGraEntry *)q)->actorA);
        BMP_WIN_Delete(((struct BeaconDetailGraEntry *)q)->winC.window);
        for(j=0;j<2;j++) BMP_WIN_Delete(*(void **)(q+0x40+j*16));
        for(j=0;j<4;j++) BMP_WIN_Delete(*(void **)(q+j*16));
        BMP_WIN_Delete(((struct BeaconDetailGraEntry *)q)->iconWindow.window);
    }
    PMS_DRAW_Delete(((struct BeaconDetailGraWork *)p)->pmsDraw);
}





/*
 * Tail-call getter: loads p[0x56] and tail-calls PMS_DRAW_Main.
 *
 * Addresses are Black-image addresses.
 */
int BEACON_DETAIL_GRA_IsPmsActive(u32 *p)
{
    return PMS_DRAW_Main(p[0x56]);
}




/*
 * volatile: hardware accesses 0x021BC956-0x021BC96A.
 */
void *BEACON_DETAIL_GRA_Create(int a,int heap)
{
    unsigned *p=GFL_HEAP_Alloc(heap,16,0,d_021BDDC0,317);
    MI_CpuFill8(p,0,16);
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks((const struct DispVram *)d_021BDBD8);
    BMP_SetDisplaySwap(a);
    BG_SYS_ResetSubDisplay();
    BG_SYS_ClearMainPlanes();
    BG_SYS_ClearSubPlanes();
    GF_FONT_InitTextColor();
    BEACON_DETAIL_GRA_InitBgSystem(p,heap);
    BEACON_DETAIL_GRA_InitClact((void **)(p+1),d_021BDBD8,heap);
    p[3]=(unsigned)GFL_USE_AddMainTask((void (*)(void *, void *))BEACON_DETAIL_GRA_Task,p,0);
    return p;
}




void BEACON_DETAIL_GRA_Destroy(unsigned *p)
{
    TCB_DeleteTask((void *)p[3]);
    BEACON_DETAIL_GRA_ExitClact((char *)(p+1));
    BEACON_DETAIL_GRA_ExitBgSystem(p);
    GF_FONT_SetDefaultTextColor();
    *(volatile unsigned short *)0x04000050=0;
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04000000 &= ~0xe000;
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    MI_CpuFill8(p,0,16);
    GFL_HEAP_Free(p);
}





void BEACON_DETAIL_GRA_Draw(char *p)
{
    BEACON_DETAIL_GRA_DrawClact(p + 4);
    BEACON_DETAIL_GRA_Noop(p);
}




void *BEACON_DETAIL_GRA_GetClactUnit(char *p){return (void *)BEACON_DETAIL_GRA_ReadPtr((u32 *)(p+4));}





void BEACON_DETAIL_GRA_Task(void *unused, char *p)
{
    BEACON_DETAIL_GRA_UpdateBg(p);
    BEACON_DETAIL_GRA_VBlankClact(p + 4);
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




void BEACON_DETAIL_GRA_ExitBgSystem(void *p){unsigned base=(unsigned)d_021BDC28;unsigned i;for(i=0;i<8;i++)BG_SYS_FreeLayerBuf((unsigned char)(*(const unsigned *)(base+i*44)));BMP_WIN_Exit();BG_SYS_Delete();MI_CpuFill8(p,0,4);}




void BEACON_DETAIL_GRA_Noop(void *p) {}



void BEACON_DETAIL_GRA_UpdateBg(void *a0){BG_SYS_Update();}



void BEACON_DETAIL_GRA_InitClact(void **p,void *a,int heap)
{
    struct BeaconDetailGraRenderBlock b;
    MI_CpuFill8(p,0,8);
    CLACT_InitSystem((const struct Cfg *)d_021BDBBC,(unsigned int)a,heap);
    p[0]=CLACT_CreateUnit(128,0,heap);
    b=d_021BDC08;
    p[1]=CLACT_CreateRenderer((u8 *)(&b),2,heap);
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
    MI_CpuFill8(p, 0, 8);
}



void BEACON_DETAIL_GRA_DrawClact(void *a0){CLACT_DrawSystem();}



void BEACON_DETAIL_GRA_VBlankClact(void *a0){CLACT_VBlankSystem();}



u32 BEACON_DETAIL_GRA_ReadPtr(u32*p){return *p;}



void BEACON_DETAIL_GRA_SetupBeaconList(unsigned char *p)
{
    BEACON_DETAIL_GRA_InitWindows((char *)p);
    GAME_BEACON_ACCESSOR_TableRingGet(((struct BeaconDetailGraWork *)p)->infoQueue,((struct BeaconDetailGraWork *)p)->beaconRecord,(u16 *)(p+0x2c),*(p+p[0x30]+0x31));
    BEACON_DETAIL_GRA_SetupSlot((char *)p,((struct BeaconDetailGraWork *)p)->beaconRecord,((struct BeaconDetailGraWork *)p)->level,p[0x2e]);
    BEACON_DETAIL_GRA_SetSlotVisible((char *)p,p[0x2e],1);
    BEACON_DETAIL_GRA_SetSlotVisible((char *)p,p[0x2e]^1,0);
    BEACON_DETAIL_GRA_UpdateSlotInfo((char *)p); BEACON_DETAIL_GRA_UpdateButtons(p);
    GFL_NET_RestartWithDefaultTimeout(0,((struct BeaconDetailGraWork *)p)->gfxHeapId);
}



int BEACON_DETAIL_GRA_UpdateInteract(unsigned char *p)
{
    int state=TOUCHBAR_GetPressedButtonIdIfPressing(((struct BeaconDetailGraWork *)p)->touchBar);
    unsigned keys=KEY_GetTrg();
    if(ICA_ANIME_GetUnk330((const struct Ctx *)**(void ** *)&((struct BeaconDetailGraWork *)p)->config)) { (*(unsigned char **)(p+0x14))[9]=1; return 4; }
    if(state==1) { (*(unsigned char **)(p+0x14))[9]=0; return 4; }
    if(state==3 && p[0x30]) { BEACON_DETAIL_GRA_AddSlotSlideTask((char *)p,1); return 3; }
    if(state==2 && p[0x30]<p[0x2f]-1) { BEACON_DETAIL_GRA_AddSlotSlideTask((char *)p,0); return 3; }
    if(!p[0x260]) return 2;
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
    if(p[0x30]) TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)p)->touchBar,3,1);
    else TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)p)->touchBar,3,0);
    if(p[0x30]<p[0x2f]-1) TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)p)->touchBar,2,1);
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
int BEACON_DETAIL_GRA_GetPmVersionClass(void *a0)
{
    switch (GAME_BEACON_ACCESSOR_GetPmVersion(a0)) {
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
        WORDSET_Callback(q,0,GAME_BEACON_ACCESSOR_GetDetailsMonsNo(p)); break;
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




void BEACON_DETAIL_GRA_SetActorPos(void *a0, short a1, short a2, int a3)
{
    u16 tmp[2];
    tmp[0] = a1;
    tmp[1] = a2;
    CLACT_AddActorSurfacePos(a0, (const struct Vec2 *)tmp, a3);
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
void BEACON_DETAIL_GRA_PrintMsg(u8*p, u8 n){MSGDATA_ReadString(*(struct MsgBank**)(p+0x130),n,*(void**)(p+0x13c));WORDSET_CopyTaggedText(*(struct WordSet**)(p+0x138),*(void**)(p+0x140),*(void**)(p+0x13c));}



void BEACON_DETAIL_GRA_TransferChar(u8*p,u32 n){CLACT_TransferCharacter(((struct BeaconDetailGraWork *)p)->actors[3].character,*(struct BeaconDetailGraTransfer**)((u32)p+n*8+0x8c));BEACON_DETAIL_GRA_LoadPalette((u8*)*(void* *)&((struct BeaconDetailGraWork *)p)->paletteData+(d_021BDD92[n]&15)*32,2,160,16);}




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
    struct BeaconDetailGraWinSet *w3;
    struct BeaconDetailGraWinSet *w2;
    struct BeaconDetailGraWinSet *w;
    int i, j;
    u8 b;
    u16 a;
    struct BeaconDetailGraWinRec *rec;
    int off;
    int x;

    i = 0;
    w = (struct BeaconDetailGraWinSet *)(p + 0x15C);

    do {
        MSGDATA_ReadString((struct MsgBank *)HANDLE(p, 0x130), i, (void *)ARG(p, 0x130));
        b = d_021BDD8A[i % 2].index;
        off = i * 16;
        a = d_021BDD8A[i % 2].color;
        j = 0;
        do {
            rec = (struct BeaconDetailGraWinRec *)(off + (u32)&w[j]);
            BMP_Clear((struct CharBuf *)rec->h, b);
            BEACON_DETAIL_GRA_DrawRecord(p, (char *)rec, 0, 0, ARG(p, 0x130), a);
            CALLS(rec);
            j++;
        } while (j < 2);
        i++;
    } while (i < 4);
    MSGDATA_ReadString((struct MsgBank *)HANDLE(p, 0x130), 7, (void *)ARG(p, 0x130));
    w2 = (struct BeaconDetailGraWinSet *)(p + 0x130 + 0x2C);

    x = 0;
    do {
        BMP_Clear((struct CharBuf *)w2[x].b.h, 3);
        BEACON_DETAIL_GRA_DrawRecord(p, (char *)&w2[x].b, 0, 0, ARG(p, 0x130), 0x3DC3);
        CALLS(&w2[x].b);
        x++;
    } while (x < 2);
    MSGDATA_ReadString((struct MsgBank *)HANDLE(p, 0x130), 9, (void *)ARG(p, 0x130));
    w3 = (struct BeaconDetailGraWinSet *)(p + 0x130 + 0x2C);
    j = 0;
    do {
        BMP_Clear((struct CharBuf *)w3[j].c.h, 3);
        BEACON_DETAIL_GRA_DrawRecord(p, (char *)&w3[j].c, 0, 0, ARG(p, 0x130), 0x3DC3);
        CALLS(&w3[j].c);
        j++;
    } while (j < 2);
}



#pragma opt_propagation reset



#pragma opt_lifetimes reset



void BEACON_DETAIL_GRA_DrawWindowRecord(void *p,void **q,int v,short a,unsigned char b,unsigned char c,unsigned char d,unsigned char e)
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
    entry = p + 0x15c + index * 128;
    CLACT_SetActorDrawEnable(*(struct ClactActor * *)&((struct BeaconDetailGraEntry *)entry)->actorB, enable);
    if (((struct BeaconDetailGraEntry *)entry)->hasSecondActor != 0)
        CLACT_SetActorDrawEnable(*(struct ClactActor * *)&((struct BeaconDetailGraEntry *)entry)->actorA, enable);
    if (PMS_DRAW_IsActive(*(struct BeaconDetailGraPmsDraw * *)&((struct BeaconDetailGraWork *)p)->pmsDraw, index) != 0)
        PMS_DRAW_SetVisible(*(struct BeaconDetailGraPmsDraw * *)&((struct BeaconDetailGraWork *)p)->pmsDraw, index, enable);
    BG_SYS_SetPlaneVisible(((struct BeaconDetailGraEntry *)entry)->layer, (u8)enable);
}



/*
 * prototype: 021BCE8C coordinate parameters are signed short: original uses asrs #16 before each call; same-overlay matched caller 021BD448 declares s16.
 */
void BEACON_DETAIL_GRA_MoveActor(u8*p,int a){BG_SYS_FillScrollArea(p[0x7e],3,-a);BEACON_DETAIL_GRA_SetActorPos(*(void* *)&((struct BeaconDetailGraEntry *)p)->actorB,220,a+44,1);BEACON_DETAIL_GRA_SetActorPos(*(void* *)&((struct BeaconDetailGraEntry *)p)->actorA,200,a+80,1);}



void BEACON_DETAIL_GRA_SetupSlot(char *p,void *record,u16 unused,u8 slot)
{
    struct BeaconDetailGraPair colors;
    struct BeaconDetailGraQuad data;
    struct BeaconDetailGraPair counts;
    char *q=(char *)p+0x15c+slot*128;
    u32 subtype;
    u16 value;
    int position;
    int index;
    GAME_BEACON_ACCESSOR_GetFavoriteColorRgb((int)(&colors.a),(int)record);
    PALANM_BlendColors(&colors.a,&colors.b,1,3,0);
    position=slot*16;
    BEACON_DETAIL_GRA_LoadPalette(&colors,1,(u16)(position+1),2);
    BEACON_DETAIL_GRA_LoadPalette(*(char * *)&((struct BeaconDetailGraWork *)p)->charData+BEACON_DETAIL_GRA_GetPmVersionClass(record)*32,1,(u16)(position+10),2);
    GAME_BEACON_ACCESSOR_GetPlayerName(record,((struct BeaconDetailGraWork *)p)->textBuf);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)q,*(int *)&((struct BeaconDetailGraWork *)p)->textBuf,6,48,13,2,0);
    subtype=GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond((int)record);
    if(subtype==255) STRBUF_Clear(*(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf2);
    else {WORDSET_SetSlotFromMsg38(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,0,subtype);BEACON_DETAIL_GRA_PrintMsg((u8 *)p,5);}
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(q+16),*(int *)&((struct BeaconDetailGraWork *)p)->textBuf2,6,48,13,2,1);
    subtype=GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst((int)record);
    if(subtype==255) STRBUF_Clear(*(struct U16Vec * *)&((struct BeaconDetailGraWork *)p)->textBuf2);
    else {WORDSET_SetSlotFromMsg2B(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,0,subtype);BEACON_DETAIL_GRA_PrintMsg((u8 *)p,4);}
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(q+32),*(int *)&((struct BeaconDetailGraWork *)p)->textBuf2,6,48,13,2,0);
    GAME_BEACON_ACCESSOR_GetPlayTime(record,&counts.b,&counts.a);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,2,counts.b,3,0,1);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,3,counts.a,2,2,1);
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,6);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(q+48),*(int *)&((struct BeaconDetailGraWork *)p)->textBuf2,6,48,13,2,1);
    value=(unsigned)GAME_BEACON_ACCESSOR_GetNation(record);
    WORDSET_SetSlotFromMsgE7(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,0,value);
    WORDSET_DeleteMsgdataF094(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,1,value,GAME_BEACON_ACCESSOR_GetArea(record));
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,8);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(q+80),*(int *)&((struct BeaconDetailGraWork *)p)->textBuf2,0,0,28,4,0);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,0,GAME_BEACON_ACCESSOR_GetPassCount(record),5,1,1);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,1,GAME_BEACON_ACCESSOR_GetThanksCount(record),5,1,1);
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,10);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(q+96),*(int *)&((struct BeaconDetailGraWork *)p)->textBuf2,21,0,6,4,0);
    if(PMS_DRAW_IsActive(*(struct BeaconDetailGraPmsDraw * *)&((struct BeaconDetailGraWork *)p)->pmsDraw,slot)!=0) PMS_DRAW_Clear(*(struct BeaconDetailGraPmsDraw * *)&((struct BeaconDetailGraWork *)p)->pmsDraw,slot,1);
    GAME_BEACON_ACCESSOR_GetDetailsPms(record,&data);
    PMS_DRAW_Print(*(u32 *)&((struct BeaconDetailGraWork *)p)->pmsDraw,((struct BeaconDetailGraEntry *)q)->iconWindow.handle,(u32)&data,slot);
    ((struct BeaconDetailGraEntry *)q)->appearance=GAME_BEACON_ACCESSOR_GetTrainerAppearance(record);
    index=slot*12;
    POKEGRA_LoadTrainerGraphics(((struct BeaconDetailGraWork *)p)->trainer.set,CURSOR_MOVE_GetTableGroup(((struct BeaconDetailGraEntry *)q)->appearance),*(void **)((u32)p+0x6c+(u32)index),*(void **)((u32)p+0x68+(u32)index),((struct BeaconDetailGraWork *)p)->gfxHeapId);
    subtype=GAME_BEACON_ACCESSOR_GetResearchTeamRank(record);
    if(subtype==0) {CLACT_SetActorDrawEnable(*(struct ClactActor * *)&((struct BeaconDetailGraEntry *)q)->actorA,0);return;}
    BEACON_DETAIL_GRA_SetActorAnim(((struct BeaconDetailGraEntry *)q)->actorA,(u8)(subtype+1));
    CLACT_SetActorDrawEnable(*(struct ClactActor * *)&((struct BeaconDetailGraEntry *)q)->actorA,1);
}



void BEACON_DETAIL_GRA_UpdateSlotInfo(char *p)
{
    const u8 *type;
    u32 value;
    int index,high;
    struct Descriptor *d;
    GAME_BEACON_ACCESSOR_TableRingGet(*(struct Queue * *)&((struct BeaconDetailGraWork *)p)->infoQueue,*(struct GameBeaconRecord * *)&((struct BeaconDetailGraWork *)p)->beaconRecord,(u16 *)(p+44),*(u8 *)((u32)p+((struct BeaconDetailGraWork *)p)->cursor+49));
    type=BEACON_DETAIL_GRA_FindAppearanceType(GAME_BEACON_ACCESSOR_GetDetailsType(*(const char * *)&((struct BeaconDetailGraWork *)p)->beaconRecord));
    BEACON_DETAIL_GRA_TransferChar((u8 *)p,GAME_BEACON_ACCESSOR_GetTrainerAppearance(*(struct GameBeaconRecord * *)&((struct BeaconDetailGraWork *)p)->beaconRecord));
    value=GAME_BEACON_ACCESSOR_GetZoneId(*(struct Bits * *)&((struct BeaconDetailGraWork *)p)->beaconRecord);
    index=TOWNMAP_GRH_FindRecordIndex(*(int *)&((struct BeaconDetailGraWork *)p)->townInfo,GAME_BEACON_ACCESSOR_GetTownmapRootZoneId((const struct Bits *)(*(const char * *)&((struct BeaconDetailGraWork *)p)->beaconRecord)));
    if(index==0xffff || TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct BeaconDetailGraWork *)p)->townInfo,index,16)!=0xffff || value>=427) {
        ((struct BeaconDetailGraWork *)p)->mapVisible=0;
        *(volatile s16 *)&((struct BeaconDetailGraWork *)p)->mapY=0;
        ((struct BeaconDetailGraWork *)p)->mapX=*(volatile s16 *)&((struct BeaconDetailGraWork *)p)->mapY;
        CLACT_SetActorDrawEnable(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)p)->mapActors[0],0);
        CLACT_SetActorDrawEnable(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)p)->mapActors[1],0);
    } else {
        ((struct BeaconDetailGraWork *)p)->mapVisible=1;
        ((struct BeaconDetailGraWork *)p)->mapX=TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct BeaconDetailGraWork *)p)->townInfo,index,2);
        ((struct BeaconDetailGraWork *)p)->mapY=TOWNMAP_GRH_GetTownInfoValue(*(char * *)&((struct BeaconDetailGraWork *)p)->townInfo,index,3)-16;
        if(((struct BeaconDetailGraWork *)p)->mapY<32) ((struct BeaconDetailGraWork *)p)->mapY=32;
        else if(((struct BeaconDetailGraWork *)p)->mapY>152) ((struct BeaconDetailGraWork *)p)->mapY=152;
        if(((struct BeaconDetailGraWork *)p)->mapX<16) ((struct BeaconDetailGraWork *)p)->mapX=16;
        else if(((struct BeaconDetailGraWork *)p)->mapX>240) ((struct BeaconDetailGraWork *)p)->mapX=240;
        BEACON_DETAIL_GRA_SetActorPos(((struct BeaconDetailGraWork *)p)->mapActors[0],((struct BeaconDetailGraWork *)p)->mapX,((struct BeaconDetailGraWork *)p)->mapY,0);
        CLACT_SetActorDrawEnable(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)p)->mapActors[0],1);
        if(type[2]!=0) {
            BEACON_DETAIL_GRA_SetActorPos(((struct BeaconDetailGraWork *)p)->mapActors[1],((struct BeaconDetailGraWork *)p)->mapX-24,((struct BeaconDetailGraWork *)p)->mapY,0);
            BEACON_DETAIL_GRA_SetActorAnim(((struct BeaconDetailGraWork *)p)->mapActors[1],(u8)(type[2]-1));
        }
        CLACT_SetActorDrawEnable(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)p)->mapActors[1],type[2]!=0);
    }
    BMP_Clear(*(struct CharBuf * *)&((struct BeaconDetailGraWork *)p)->detailWindow,15);
    high=(u8)(((struct BeaconDetailGraWork *)p)->level>>8);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,0,high,2,0,1);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct BeaconDetailGraWork *)p)->wordSet,1,(u8)((struct BeaconDetailGraWork *)p)->level,2,2,1);
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,(high/12)+13);
    BEACON_DETAIL_GRA_DrawRecord(p,p+0x148,0,0,*(u32 *)&((struct BeaconDetailGraWork *)p)->textBuf2,0x1d0f);
    BEACON_DETAIL_GRA_SetNameSlots(((struct BeaconDetailGraWork *)p)->beaconRecord,((struct BeaconDetailGraWork *)p)->wordSet);
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,type[1]);
    BEACON_DETAIL_GRA_DrawRecord(p,p+0x148,0,16,*(u32 *)&((struct BeaconDetailGraWork *)p)->textBuf2,0x1d0f);
    d=*(struct Descriptor * *)&((struct BeaconDetailGraWork *)p)->infoWindow;
    BMP_WIN_TransferChars(d);
    BMP_WIN_MakeScreen((struct Cfg *)d);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(d));
}



/*
 * lever: the signed byte step derives -8 from live 64 with subs #72; u8 emits movs #248.
 */
void BEACON_DETAIL_GRA_AddFadeTask(char *owner, int direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct Tcbl *)TCBL_AddTask(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)owner)->tcbl, (void (*)(struct TcblNode *, void *))BEACON_DETAIL_GRA_Callback, 12, 0));
    MI_CpuFill8(work, 0, 12);
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



void BEACON_DETAIL_GRA_Callback(struct TcblNode*task,u8*p){u32 old=p[2]++;if(old<p[1]){((struct BeaconDetailGraFadeTask *)p)->position=((struct BeaconDetailGraFadeTask *)p)->position+((struct BeaconDetailGraFadeTask *)p)->step;BG_SYS_FillScrollArea(1,3,((struct BeaconDetailGraFadeTask *)p)->position);}else{--**(u32* *)&((struct BeaconDetailGraFadeTask *)p)->counter;TCBL_DeleteTask(task);}}



void BEACON_DETAIL_GRA_AddTimerTask(char*p){BEACON_DETAIL_GRA_AddTimerTaskEx(p,(int*)(p+12));}



/*
 * region evidence: ov067 labels 021B64A8; its filed/full body reads the supplied object in r0 and enable in r1.
 */
void BEACON_DETAIL_GRA_AddTimerTaskEx(char *owner, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct Tcbl *)TCBL_AddTask(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)owner)->tcbl, BEACON_DETAIL_GRA_TimerCallback, 16, 0));
    MI_CpuFill8(work, 0, 16);
    *(char * *)&((struct BeaconDetailGraTimerTask *)work)->owner = owner;
    ((struct BeaconDetailGraTimerTask *)work)->count = 150;
    TOUCHBAR_SetAllButtonsEnabled(*(u8 * *)&((struct BeaconDetailGraWork *)owner)->touchBar, 0);
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



void BEACON_DETAIL_GRA_TimerCallback(struct TcblNode *task, void *data)
{
    char *p = data;
    switch (((struct BeaconDetailGraTimerTask *)p)->step) {
    case 0:
        BEACON_DETAIL_GRA_AddFadeTask(((struct BeaconDetailGraTimerTask *)p)->owner, 0, (int *)(p + 4));
        ++((struct BeaconDetailGraTimerTask *)p)->step;
        break;
    case 1:
        if (((struct BeaconDetailGraTimerTask *)p)->timer == 0)
            ++((struct BeaconDetailGraTimerTask *)p)->step;
        break;
    case 2:
        if (BEACON_DETAIL_GRA_UpdateTimer(p) == 0) {
            BEACON_DETAIL_GRA_AddFadeTask(((struct BeaconDetailGraTimerTask *)p)->owner, 1, (int *)(p + 4));
            ++((struct BeaconDetailGraTimerTask *)p)->step;
        }
        break;
    case 3:
        if (((struct BeaconDetailGraTimerTask *)p)->timer != 0)
            break;
    default:
        --**(int * *)&((struct BeaconDetailGraTimerTask *)p)->counter;
        TCBL_DeleteTask(task);
        break;
    }
}



/*
 * lever: u8 direction puts the r3 home first; caller 021BD948 supplies ldrb direction in r3.
 */
void BEACON_DETAIL_GRA_AddSlideTask(char *owner, u8 index, int position, u8 direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct Tcbl *)TCBL_AddTask(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)owner)->tcbl, (void (*)(struct TcblNode *, void *))BEACON_DETAIL_GRA_SlideCallback, 24, 0));
    MI_CpuFill8(work, 0, 24);
    *(char * *)&((struct BeaconDetailGraSlideTask *)work)->entry = owner + 0x15c + index * 128;
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



void BEACON_DETAIL_GRA_SlideCallback(struct TcblNode *task, char *p)
{
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
    TCBL_DeleteTask(task);
}



void BEACON_DETAIL_GRA_AddSlotSlideTask(char*p,int a){BEACON_DETAIL_GRA_AddSlotSlideTaskEx(p,a,(int*)(p+12));}



void BEACON_DETAIL_GRA_AddSlotSlideTaskEx(char *owner, int direction, int *counter)
{
    char *work;
    work = TCBL_GetWork((struct Tcbl *)TCBL_AddTask(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)owner)->tcbl, (void (*)(struct TcblNode *, void *))BEACON_DETAIL_GRA_SlotSlideCallback, 24, 0));
    MI_CpuFill8(work, 0, 24);
    ((struct BeaconDetailGraSlotTask *)work)->direction = direction;
    if (direction == 0) {
        ((struct BeaconDetailGraSlotTask *)work)->index = ((struct BeaconDetailGraWork *)owner)->cursor + 1;
        TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)owner)->touchBar, 3, 0);
    } else {
        ((struct BeaconDetailGraSlotTask *)work)->index = ((struct BeaconDetailGraWork *)owner)->cursor - 1;
        TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)owner)->touchBar, 2, 0);
    }
    TOUCHBAR_SetButtonEnabled(((struct BeaconDetailGraWork *)owner)->touchBar, 1, 0);
    GAME_BEACON_ACCESSOR_TableRingGet(*(struct Queue * *)&((struct BeaconDetailGraWork *)owner)->infoQueue, *(struct GameBeaconRecord * *)&((struct BeaconDetailGraWork *)owner)->beaconRecord, (u16 *)(owner + 0x2c), *(u8 *)(owner + 0x31 + ((struct BeaconDetailGraSlotTask *)work)->index));
    BEACON_DETAIL_GRA_SetupSlot(owner, ((struct BeaconDetailGraWork *)owner)->beaconRecord, ((struct BeaconDetailGraWork *)owner)->level, ((struct BeaconDetailGraWork *)owner)->slotIndex ^ 1);
    *(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner = owner;
    *(int * *)&((struct BeaconDetailGraSlotTask *)work)->counter = counter;
    ++*counter;
}



/*
 * Lever: explicit case 3 plus default preserves four switch arms; BD7D4 u8 index preserves the original XOR truncation pair, own int index notwithstanding.
 */
void BEACON_DETAIL_GRA_SlotSlideCallback(struct TcblNode *task,char *work)
{
    if(((struct BeaconDetailGraSlotTask *)work)->flags==0) {
        if(TOUCHBAR_GetPressedButtonIdIfDone(*(u8 * *)&((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->touchBar)!=-1)
            ((struct BeaconDetailGraSlotTask *)work)->flags=1;
    }
    if(PRINTSYS_QUE_IsFinished(*(struct PrintSys * *)&((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->printQue)==0) return;
    switch(((struct BeaconDetailGraSlotTask *)work)->step) {
    case 0:
        if(((struct BeaconDetailGraSlotTask *)work)->flags==0) break;
        TOUCHBAR_SetAllButtonsEnabled(*(u8 * *)&((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->touchBar,0);
        ++((struct BeaconDetailGraSlotTask *)work)->step;
        return;
    case 1:
        BEACON_DETAIL_GRA_AddSlideTask(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner,((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->slotIndex,1,((struct BeaconDetailGraSlotTask *)work)->direction,(int *)(work+8));
        BEACON_DETAIL_GRA_AddSlideTask(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner,((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->slotIndex^1,d_021BDD88[((struct BeaconDetailGraSlotTask *)work)->direction],((struct BeaconDetailGraSlotTask *)work)->direction,(int *)(work+8));
        CLACT_SetActorDrawEnable(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->mapActors[0],0);
        CLACT_SetActorDrawEnable(*(struct ClactActor * *)&((struct BeaconDetailGraWork *)(*(char * *)&((struct BeaconDetailGraSlotTask *)work)->owner))->mapActors[1],0);
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
        TCBL_DeleteTask(task);
        break;
    }
}



/*
 * lever: u16 c moves its r3 spill before the handle load and restores call setup; u32 leaves 24 concrete bytes different.
 */
void BEACON_DETAIL_GRA_DrawRecord(char *owner, char *record, u32 b, u16 c, u32 d, u16 f)
{
    void *handle;
    handle = ((struct BeaconDetailGraWork *)owner)->printQue;
    PRINTSYS_PrintQueColor(handle, (u32)BMP_WIN_GetBmp((struct Descriptor *)((struct BeaconDetailGraWinRecord *)record)->target.window), b, c, d, ((struct BeaconDetailGraWork *)owner)->font.handle, f);
    ((struct BeaconDetailGraWinRecord *)record)->target.pending = 1;
    BEACON_DETAIL_GRA_AddPrintWaitTask((u8 *)owner, (int)record, (int *)(owner + 12));
}



void BEACON_DETAIL_GRA_AddPrintWaitTask(u8 *p,int arg,int *counter)
{
    struct BeaconDetailGraPrintTask *work;
    work=TCBL_GetWork((struct Tcbl *)TCBL_AddTask(*(struct Tcbl * *)&((struct BeaconDetailGraWork *)p)->tcbl,(TcblFunc)BEACON_DETAIL_GRA_PrintWaitTask,12,0));
    MI_CpuFill8(work,0,12);
    work->owner=p;
    work->arg=arg;
    if(counter!=0){work->counter=counter;++*counter;}
}


void BEACON_DETAIL_GRA_PrintWaitTask(int a, int **b)
{
    u8   *s = (u8 *)b[0] + 8;
    void *q = ((struct BeaconDetailGraWork *)((char *)b[1]))->printQue;

    if (s[4]) {
        if (PRINTSYS_QUE_IsExistTarget((struct PrintSys *)q, (void *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct BeaconDetailGraWinTarget *)s)->window))) == 0) {
            BMP_WIN_TransferChars((struct Descriptor *)((struct BeaconDetailGraWinTarget *)s)->window);
            s[4] = 0;
        }
    }
    if (s[4] == 0) {
        if (b[2])
            --*(int *)b[2];
        TCBL_DeleteTask((struct TcblNode *)a);
    }
}
