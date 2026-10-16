/*
 * file:     research_list.c
 * unit:     yes
 * function: RESEARCH_LIST_Create, RESEARCH_LIST_Destroy, RESEARCH_LIST_Update, RESEARCH_LIST_GetVisible, RESEARCH_LIST_GetActive, RESEARCH_LIST_EnterSetup, RESEARCH_LIST_HandleScrollInput, RESEARCH_LIST_HandleSelectInput, RESEARCH_LIST_UpdateOpen, RESEARCH_LIST_UpdateDrag, RESEARCH_LIST_HandleConfirm, RESEARCH_LIST_HandleCancel, RESEARCH_LIST_UpdateShowEntry, RESEARCH_LIST_UpdateHideEntry, RESEARCH_LIST_UpdateSaveExit, RESEARCH_LIST_UpdateFadeInWait, RESEARCH_LIST_UpdateFadeOutWait, RESEARCH_LIST_UpdateReturn, RESEARCH_LIST_EnterExit, RESEARCH_LIST_IncStateTimer, RESEARCH_LIST_PushCommand, RESEARCH_LIST_SetCommandReady, RESEARCH_LIST_GetEntryHandled, RESEARCH_LIST_SetEntryHandled, RESEARCH_LIST_SetActive, RESEARCH_LIST_GetFadeWaitFrames, RESEARCH_LIST_ProcessCommand, RESEARCH_LIST_GetState, RESEARCH_LIST_SetState, RESEARCH_LIST_GetSubState, RESEARCH_LIST_IncSubState, RESEARCH_LIST_ClearSubState, RESEARCH_LIST_SelectPrevious, RESEARCH_LIST_SelectNext, RESEARCH_LIST_SetSelectionMode, RESEARCH_LIST_ScrollSelectionIntoView, RESEARCH_LIST_SelectEntry, RESEARCH_LIST_StartEntryPaletteAnime, RESEARCH_LIST_ComputeOpenScroll, RESEARCH_LIST_ComputeReturnScroll, RESEARCH_LIST_ComputeCenterScroll, RESEARCH_LIST_FindSaveIndex, RESEARCH_LIST_StoreSaveValues, RESEARCH_LIST_FlipSelectionMode, RESEARCH_LIST_SetSelectionModeField, RESEARCH_LIST_SetEntryPaletteIdle, RESEARCH_LIST_SetEntryPaletteActive, RESEARCH_LIST_SetCursorSlot, RESEARCH_LIST_AdvanceEndIndex, RESEARCH_LIST_ShowCursor, RESEARCH_LIST_HideCursor, RESEARCH_LIST_ShiftTextRight, RESEARCH_LIST_ShiftTextLeft, RESEARCH_LIST_GetRowOffset, RESEARCH_LIST_GetRowBase, RESEARCH_LIST_GetEntryScreenX, RESEARCH_LIST_GetEntryScreenY, RESEARCH_LIST_GetEntryScreenYBottom, RESEARCH_LIST_UpdateWindowMask, RESEARCH_LIST_UpdateEntryActor, RESEARCH_LIST_PrintCurrentEntry, RESEARCH_LIST_PrintEntryLabels, RESEARCH_LIST_HideEntryLabels, RESEARCH_LIST_ShowEntryLabels, RESEARCH_LIST_UpdateScrollbarActor, RESEARCH_LIST_GetScrollbarY, RESEARCH_LIST_GetScrollYFromPosition, RESEARCH_LIST_UpdateMomentum, RESEARCH_LIST_IsMomentumActive, RESEARCH_LIST_ComputeMomentum, RESEARCH_LIST_DampMomentum, RESEARCH_LIST_SetMomentumDirection, RESEARCH_LIST_StartScrollAnim, RESEARCH_LIST_StepScrollAnim, RESEARCH_LIST_IsScrollAnimDone, RESEARCH_LIST_SetScrollTarget, RESEARCH_LIST_SetScrollValue, RESEARCH_LIST_ApplyScrollRegs, RESEARCH_LIST_SetListScroll, RESEARCH_LIST_GetScrollY, RESEARCH_LIST_SetScrollY, RESEARCH_LIST_GetScrollMin, RESEARCH_LIST_GetScrollMax, RESEARCH_LIST_DivideByEntryHeight, RESEARCH_LIST_EntryIndexToY, RESEARCH_LIST_EntryIndexToYBottom, RESEARCH_LIST_GetScrollRange, RESEARCH_LIST_GetScrollRangeMax, RESEARCH_LIST_NeedsScrollbar, RESEARCH_LIST_UpdateTouchRects, RESEARCH_LIST_FadeIn, RESEARCH_LIST_FadeOut, RESEARCH_LIST_IsFadeDone, RESEARCH_LIST_ShowEntryPalette, RESEARCH_LIST_HideEntryPalette, RESEARCH_LIST_IsPaletteFadeDone, RESEARCH_LIST_StartPaletteAnime, RESEARCH_LIST_StartListPaletteAnime, RESEARCH_LIST_StopListPaletteAnime, RESEARCH_LIST_IsListPaletteAnimeRunning, RESEARCH_LIST_UpdatePaletteAnimes, RESEARCH_LIST_UpdateCommonPaletteAnime, RESEARCH_LIST_GetKeyRepeatTimer, RESEARCH_LIST_IncKeyRepeatTimer, RESEARCH_LIST_ClearKeyRepeatTimer, RESEARCH_LIST_VBlankHandler, RESEARCH_LIST_GetAppResource, RESEARCH_LIST_SetHeapId, RESEARCH_LIST_SetOwner, RESEARCH_LIST_GetOwner, RESEARCH_LIST_SetListView, RESEARCH_LIST_SyncFromListView, RESEARCH_LIST_SyncToListView, RESEARCH_LIST_GetInputFlag, RESEARCH_LIST_GetEntryCount, RESEARCH_LIST_GetSelectedIndex, RESEARCH_LIST_SetSelectedIndex, RESEARCH_LIST_IsValidIndex, RESEARCH_LIST_GetResourceId, RESEARCH_LIST_GetClactUnit, RESEARCH_LIST_GetActor, RESEARCH_LIST_SetOamEnabled, RESEARCH_LIST_GetOamObject, RESEARCH_LIST_Alloc, RESEARCH_LIST_InitFields, RESEARCH_LIST_Free, RESEARCH_LIST_CountUnlockedEntries, RESEARCH_LIST_CreateFont, RESEARCH_LIST_ClearFont, RESEARCH_LIST_DeleteFont, RESEARCH_LIST_CreateMessages, RESEARCH_LIST_ClearMessages, RESEARCH_LIST_DeleteMessages, RESEARCH_LIST_CreateCommandQueue, RESEARCH_LIST_ClearCommandQueue, RESEARCH_LIST_DestroyCommandQueue, RESEARCH_LIST_InitTables, RESEARCH_LIST_InitBackgrounds, RESEARCH_LIST_ExitBackgrounds, RESEARCH_LIST_LoadBackground6, RESEARCH_LIST_DummyBg7, RESEARCH_LIST_UpdateBackground7, RESEARCH_LIST_ShowBackground7, RESEARCH_LIST_LoadBackground2, RESEARCH_LIST_DummyBg3, RESEARCH_LIST_LoadListBackground, RESEARCH_LIST_DummyListBg, RESEARCH_LIST_UpdateBackground3, RESEARCH_LIST_ShowBackground3, RESEARCH_LIST_CreateLabels, RESEARCH_LIST_ClearLabels, RESEARCH_LIST_DestroyLabels, RESEARCH_LIST_ClearResources, RESEARCH_LIST_RegisterEntryResources, RESEARCH_LIST_ReleaseEntryResources, RESEARCH_LIST_RegisterCursorResources, RESEARCH_LIST_ReleaseCursorResources, RESEARCH_LIST_ClearUnits, RESEARCH_LIST_CreateUnits, RESEARCH_LIST_DeleteUnits, RESEARCH_LIST_ClearActors, RESEARCH_LIST_CreateActors, RESEARCH_LIST_DeleteActors, RESEARCH_LIST_ClearBmps, RESEARCH_LIST_CreateBmps, RESEARCH_LIST_DrawBmps, RESEARCH_LIST_DrawBadgeA, RESEARCH_LIST_DrawBadgeB, RESEARCH_LIST_DeleteBmps, RESEARCH_LIST_CreateOamSys, RESEARCH_LIST_DeleteOamSys, RESEARCH_LIST_CreateOamObjects, RESEARCH_LIST_DeleteOamObjects, RESEARCH_LIST_ClearPalAnm, RESEARCH_LIST_CreatePalAnm, RESEARCH_LIST_DeletePalAnm, RESEARCH_LIST_CreatePaletteAnime, RESEARCH_LIST_ClearPaletteAnime, RESEARCH_LIST_DestroyPaletteAnime, RESEARCH_LIST_BindPaletteAnime, RESEARCH_LIST_RestorePaletteAnime, RESEARCH_LIST_UpdateCenterActor, RESEARCH_LIST_RestartNetwork, RESEARCH_LIST_RegisterVBlank, RESEARCH_LIST_UnregisterVBlank
 * address:  0x021BAB80
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from research_top.c, unit_021BFFC8.c, queue.c, palette_anime.c, ov217_func_021C2E20.c by tools/splitfile.py.
 *
 * symbols:
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   func_020490F4 0x020490F4 arm
 *   ARC_TOOL_LoadHandleMember 0x02049250 arm
 *   func_020307B0 0x020307B0 arm
 *   NNS_G2dGetUnpackedScreenData 0x02062B30 arm
 *   BG_SYS_DrawTile 0x02041090 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   RESEARCH_COMMON_GetHeapId  0x021C09AC  thumb  ov217
 *   RESEARCH_COMMON_UpdatePaletteAnime 0x021C09D0 thumb ov217
 *   CLACT_DrawSystem 0x0204A600 arm
 *   KEY_GetTrg 0x020362DC arm
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   RESEARCH_COMMON_GetTouchRects 0x021C09B8 thumb ov217
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   RESEARCH_COMMON_StopPaletteAnime  0x021C09E0  thumb  ov217
 *   RESEARCH_COMMON_RestorePaletteAnime  0x021C09EC  thumb  ov217
 *   RingQueue_Push  0x021C0E4C  thumb  ov217
 *   RingQueue_Pop  0x021C0E54  thumb  ov217
 *   RingQueue_IsEmpty  0x021C0E64  thumb  ov217
 *   RESEARCH_COMMON_GetEntryHandled  0x021C09CC  thumb  ov217
 *   RESEARCH_COMMON_SetEntryHandled  0x021C09C4  thumb  ov217
 *   BgTextLabel_SetPalette  0x021C1038  thumb  ov217
 *   RESEARCH_COMMON_StartPaletteAnime  0x021C09D8  thumb  ov217
 *   PALETTE_ANIME_Start  0x021C29F8  thumb  ov217
 *   PALETTE_ANIME_Stop  0x021C2A00  thumb  ov217
 *   PALETTE_ANIME_Update  0x021C29F0  thumb  ov217
 *   RESEARCH_COMMON_GetAppResource 0x021C09B4 thumb ov217
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   RESEARCH_COMMON_GetInputFlag  0x021C09F8  thumb  ov217
 *   GF_FONT_Delete  0x0201D83C  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   RingQueue_Create  0x021C0E08  thumb  ov217
 *   RingQueue_Destroy  0x021C0E3C  thumb  ov217
 *   func_0207D63C 0x0207D63C arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetTileUnit  0x02040DA8  arm
 *   BgTextLabel_Create 0x021C0EF4 thumb ov217
 *   BgTextLabel_PrintMessage 0x021C0F5C thumb ov217
 *   BgTextLabel_Destroy  0x021C0F48  thumb  ov217
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   PALETTE_ANIME_Create  0x021C29C8  thumb  ov217
 *   PALETTE_ANIME_Destroy  0x021C29D8  thumb  ov217
 *   PALETTE_ANIME_Bind  0x021C29E8  thumb  ov217
 *   PALETTE_ANIME_Restore  0x021C2A08  thumb  ov217
 *   CLACT_VBlankSystem  0x0204A648  arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   KEY_GetCont 0x0203630C arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   SYMBOL_SAVE_GetBitBlock 0x0200E394 thumb
 *   MISC_SAVEDATA_GetStatusByte 0x0200E44C thumb
 *   d_021C308A 0x021C308A data a1
 *   d_021C3080 0x021C3080 data a1
 *   d_021C30A8 0x021C30A8 data a1
 *   SYMBOL_SAVE_SetBitDescriptor 0x0200E440 thumb
 *   BMP_OAM_SetPalette  0x02025A54  thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_GetBuf 0x0204162C arm
 *   BG_SYS_GetChannelScrollX  0x02041648  arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   d_021C309E 0x021C309E data a1
 *   d_021C3094 0x021C3094 data a1
 *   d_021C30D0 0x021C30D0 data a1
 *   BgTextLabel_SetVisible  0x021C0FF8  thumb  ov217
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   func_02040804  0x02040804  arm
 *   func_0209C0A4  0x0209C0A4  arm
 *   PALANM_GetFadeRequestBits  0x02021ED8  thumb
 *   d_021C326C 0x021C326C data a4
 *   PALETTE_ANIME_IsRunning  0x021C2A10  thumb  ov217
 *   ListViewState_GetMode 0x021C0DF0 thumb ov217
 *   ListViewState_GetScrollX 0x021C0DF4 thumb ov217
 *   ListViewState_GetScrollY 0x021C0DF8 thumb ov217
 *   ListViewState_SetScrollY 0x021C0E04 thumb ov217
 *   ListViewState_SetScrollX 0x021C0E00 thumb ov217
 *   ListViewState_SetMode 0x021C0DFC thumb ov217
 *   BMP_OAM_SetEnabled  0x02025774  thumb
 *   d_021C3068  0x021C3068  data  ov217  a4
 *   func_02045B38 0x02045B38 arm
 *   d_021C3078 0x021C3078 data a4
 *   d_021C30B2 0x021C30B2 data a1 ov217
 *   d_021C3190 0x021C3190 data a4
 *   d_021C3070 0x021C3070 data a4 ov217
 *   d_021C30C0 0x021C30C0 data a4 ov217
 *   d_021C3110 0x021C3110 data a4 ov217
 *   d_021C3130 0x021C3130 data a4 ov217
 *   d_021C30F0 0x021C30F0 data a4 ov217
 *   d_021C3150 0x021C3150 data a4
 *   d_021C3170 0x021C3170 data a4 ov217
 *   d_021C33C8 0x021C33C8 data a4
 *   d_021C3520 0x021C3520 data a4
 *   CLACT_CreateUnit 0x0204B100 arm
 *   d_021C305C 0x021C305C data a1
 *   d_021C3060 0x021C3060 data a2
 *   d_021C320C 0x021C320C data a4
 *   BMP_Create 0x02043678 arm
 *   d_021C3470 0x021C3470 data a4
 *   BMP_CreateFromArchive 0x0204384C arm
 *   BMP_Blit 0x020439A0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   BMP_Delete 0x020437AC arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   d_021C3350 0x021C3350 data a4
 *   d_021C349C 0x021C349C data a4
 *   d_021C32D8 0x021C32D8 data a4
 *   d_021C34C8 0x021C34C8 data a4
 *   BMP_OAM_CreateSys  0x02025538  thumb
 *   BMP_OAM_DeleteSys  0x02025588  thumb
 *   BMP_OAM_Create  0x020255A0  thumb
 *   BMP_OAM_UploadChars  0x020257D0  thumb
 *   d_021C31BC 0x021C31BC data a4
 *   BMP_OAM_Delete  0x0202570C  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   d_021C3260 0x021C3260 data a4
 *   func_020056A0  0x020056A0  thumb
 *   FADE_Start  0x0204E720  arm
 *   PALANM_RequestFade 0x0202173C thumb
 *   func_020056BC 0x020056BC thumb
 *   PALANM_TransferPalettes  0x02021D50  thumb  arm9
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   PALANM_Create  0x02021518  thumb  arm9
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb  arm9
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb  arm9
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb  arm9
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm  arm9
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm  arm9
 *   CLACT_ReleasePalette  0x0204ADA4  arm  arm9
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm  arm9
 *   FADE_IsActive  0x0204E804  arm  arm9
 *   func_02030EAC  0x02030EAC  arm
 *   func_02030734  0x02030734  arm
 *   BG_SYS_Init  0x02040C14  arm  arm9
 *   BG_SYS_ClearSlot  0x020414EC  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 *   BG_SYS_FreeLayerBuf  0x020403F4  arm  arm9
 *   BG_SYS_FillScrollArea  0x02040618  arm  arm9
 */
#include "research_shared_types.h"

#define GB ((const struct ResearchListEntryDef *)gb)

struct ResearchTop {
    u32 owner;
    union { void * listView; u32 listViewU; };
    u16 heapId;
    u8 padA[0x2];
    union { u32 font; void * fontP; };
    union {
        u32 arr[0x50];
        struct {
            u32 messageBanks[2];
            u32 commandQueue;
            u32 state;
            u32 subState;
            u32 stateTimer;
            u32 fadeWaitFrames;
            u32 selectionMode;
            u8 entryCount;
            u8 selectedIndex;
            u8 cursorSlot;
            u8 pad33;
            int scrollY;
            u32 prevScrollY;
            u32 animStart;
            union { u32 animTarget; int animTargetSigned; };
            int animFrames;
            int animFrame;
            int momentum;
            u32 momentumDir;
            u32 keyRepeatTimer;
            u8 touchRects[0x40];
            void * palAnm;
            u32 paletteAnime[6];
            void * entryLabels[8];
            u8 padD4[0x10];
            u32 nameLabelA;
            u32 nameLabelB;
            u32 valueLabelA;
            u32 valueLabelB;
            u32 valueLabelC;
            int cursorCharacter;
            int cursorPalette;
            int cursorCell;
            int cursorEffectPalette;
            int entryCharacter;
            int entryPalette;
            int entryCell;
            int units[3];
            void * actorHandles[3];
            u32 oamSys;
            void * oamObjects[4];
            void * bmps[4];
        };
    };
    union { void * paletteAnimOwner; u32 paletteAnimOwnerU; };
    u32 vblankNode;
    u32 commandReady;
    u32 entryPaletteActive;
    u32 cursorVisible;
    u32 visible;
    u32 active;
};

typedef enum { INDEX_ZERO=0 } Index;

typedef enum { PLANE_NONE=0,PLANE_OUT=31,PLANE_IN=19 } Plane;

typedef enum { FALSE=0,TRUE=1 } Bool;

typedef enum { ZERO = 0 } Origin;

struct PalAnmDef { u32 mode; u16 color; u16 pad; u32 extra[3]; };

struct LabelEntry {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad;
    u32 idx;
    u32 arg;
    u32 w;
};

struct Loc {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u8 b6;
    u8 b7;
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad;
    u32 w;
};

struct ActorDef { s16 x,y,z; u8 a,b; u32 c,d,e,f; u16 g,pad; };

struct BmpDef { int x, y, z; int bank; int index; int px; int py; u8 r, g, b, pad2; u32 arc, member, enabled; };

struct Tab { int v[3][10]; };

struct ResearchListEntryDef {
    char pad0[0xc];
    u32 f0c;
    u32 f10;
    int f14;
    int f18;
    u8 f1c;
    u8 f1d;
    u8 f1e;
    u8 pad1f;
    u32 f20;
    u32 f24;
};

struct Param { void *bmp; s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct OamDef { s16 x,y; u32 f8,fc; u8 f10,f11; u16 f12; u32 f14; };

struct Entry021C3260 {
    int a;
    int b;
    unsigned char c;
    unsigned char pad[11];
};

typedef struct { unsigned short x, y; } Pos;

extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);

extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);

extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);

extern void func_02040588(unsigned char which, unsigned char enable);

extern u32 BG_SYS_FreeLayerBuf(u32 i);

extern void *func_020490F4(unsigned int id, u32 heap);

extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *, u32, u32);

extern u32 func_020307B0(void *p);

extern int NNS_G2dGetUnpackedScreenData(void *, void **);

extern void BG_SYS_DrawTile(u32, u32, u32, u32, u8, u8);

extern void ARC_TOOL_DeleteHandle(void *);

extern void BG_SYS_FillTileMap(int index, int x0, int y0, int w, int h, int pal);

extern u32 RESEARCH_COMMON_GetHeapId(void *);

extern void RESEARCH_COMMON_UpdatePaletteAnime(unsigned);

extern void CLACT_DrawSystem();

extern u32 KEY_GetTrg(void);

extern int TOUCHPANEL_HitTrg(const void *);

extern void * RESEARCH_COMMON_GetTouchRects(void *);

extern u32 GFL_USE_PlaySeDefaultVolume(u32 a);

extern int FADE_IsActive(void);

extern void RESEARCH_COMMON_StopPaletteAnime(u32 a0);

extern void RESEARCH_COMMON_RestorePaletteAnime(u32 a0);

extern void RingQueue_Push(u32, u32);

extern u32 RingQueue_Pop(struct Ring *r);

extern u32 RingQueue_IsEmpty();

extern u32 RESEARCH_COMMON_GetEntryHandled(void *p);

extern void RESEARCH_COMMON_SetEntryHandled(u8 *p, u32 v);

extern void BgTextLabel_SetPalette(u8 *p, u8 palette);

extern void RESEARCH_COMMON_StartPaletteAnime(u8 *p, u32 i);

extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);

extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);

extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

extern void PALETTE_ANIME_Start(u8 *p, u32 b, u16 c);

extern void PALETTE_ANIME_Stop(u32 a0);

extern void PALETTE_ANIME_Update(int);

extern unsigned RESEARCH_COMMON_GetAppResource(void *);

extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);

extern unsigned ZONEDATA_CheckEventFlag(void *,int);

extern u32 RESEARCH_COMMON_GetInputFlag(void *p);

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);

extern u32 GF_FONT_Delete(void *ptr);

extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);

extern u32 MSGDATA_Delete(struct Rec *rec);

extern int RingQueue_Create(int a0, int a1);

extern void RingQueue_Destroy(void *p);

extern void func_0207D63C(volatile unsigned *,unsigned,unsigned,unsigned,unsigned);

extern void BMP_WIN_Init(u16);

extern void BMP_WIN_Exit(void);

extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);

extern u32 BG_SYS_ClearSlot();

extern void BG_SYS_SetTileUnit(u32, u32, u32);

extern struct Record *BgTextLabel_Create(const struct Config *config, u32 a, u32 b, u32 heap);

u32 BgTextLabel_PrintMessage(u32 a0, u32 a1);

extern void BgTextLabel_Destroy(u8 *p);

extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);

extern s32 CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);

extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);

extern void CLACT_ReleaseCharacter(u32 i);

extern u32 CLACT_ReleasePalette(u32 i);

extern u32 CLACT_ReleaseCellAnim();

extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);

extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);

extern u32 CLACT_DeleteUnit(struct Bank *bank);

extern struct Obj *CLACT_CreateActor(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);

extern void CLACT_DeleteActor(struct Obj *p);

extern u32 PALETTE_ANIME_Create(u32 a0);

extern u32 PALETTE_ANIME_Destroy(void *a0);

extern void PALETTE_ANIME_Bind(void *p, u32 b, u32 c, u32 d);

extern int PALETTE_ANIME_Restore(char *p);

extern void CLACT_VBlankSystem(void);

extern int TOUCHPANEL_HitCont(const void *p);

extern u32 TOUCHPANEL_GetPointCont(u32 *,u32 *);

extern u32 KEY_GetCont(void);

extern void *GAME_DATA_GetSaveControl(struct Big *);

extern void *SYMBOL_SAVE_GetBitBlock(void *a0);

extern int MISC_SAVEDATA_GetStatusByte(int p0, int p1);

extern void SYMBOL_SAVE_SetBitDescriptor(u8 *p, int value, int index);

extern void BMP_OAM_SetPalette(u8 *g, u32 a);

extern void func_02041B6C(u32 layer);

extern u32 BG_SYS_GetBuf(int channel);

extern u32 BG_SYS_GetChannelScrollX(u8 channel);

extern void CLACT_AddActorSurfacePos(struct Obj *p,const struct Vec2 *delta,u32 which);

extern void BgTextLabel_SetVisible(u8 *p, int visible);

extern void BG_SYS_ResetSlot(unsigned layer,unsigned mode,unsigned value);

extern u32 func_02040804(u32 layer);

extern void BG_SYS_FillScrollArea(u32 layer, u32 a, u32 b);

extern u32 func_0209C0A4(u32, u32);

extern int PALANM_RequestFade(PalAnmObj *, u16, u16, s16, u8, u8, u16, void *);

extern u32 PALANM_GetFadeRequestBits(const char *ptr);

extern u32 PALETTE_ANIME_IsRunning();

extern u32 PALANM_TransferPalettes(struct S02021D50 *p);

extern u32 BG_SYS_Update();

extern u32 ListViewState_GetMode(void *p);

extern u32 ListViewState_GetScrollX(void *p);

extern u32 ListViewState_GetScrollY(void *p);

extern void ListViewState_SetScrollY(void *, u32);

extern void ListViewState_SetScrollX(void *, u32);

extern void ListViewState_SetMode(void *, u8);

extern void BMP_OAM_SetEnabled(u8 *g, u32 a);

extern u32 func_020056BC(void);

extern struct Bmp *BMP_Create(u32 width, u32 height, u32 depth, u16 heap);

extern struct Bmp *BMP_CreateFromArchive(u32,u32,u32,u32);

extern void BMP_Blit(struct Bmp *,struct Bmp *,u32,u32,int,int,u32,u32,u32);

extern void *func_02045EC0(struct MsgBank *,u32);

extern void PRINTSYS_PrintColor(void *,s16,s16,void *,void *,u16);

extern void BMP_Delete(struct Bmp *p);

extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);

extern void BMP_OAM_DeleteSys(void *p);

extern struct Grid *BMP_OAM_Create(struct Sys *,const struct Param *);

extern void BMP_OAM_UploadChars(struct Obj *);

extern void BMP_OAM_Delete(struct Grid *g);

extern void *PALANM_Create(u32);

extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *, u32, u32, u32);

extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *, u32, u32, u32);

extern u32 PALANM_Delete(void *a0);

extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);

extern int func_020056A0(void (*)(void), void *, int);

extern void func_02030EAC(struct Node *n);

u32 RESEARCH_LIST_Create(u32 a0, u32 a1);

u32 RESEARCH_LIST_Destroy(void *a0);

void RESEARCH_LIST_Update(void *self);

u32 RESEARCH_LIST_GetVisible(void *p);

u32 RESEARCH_LIST_GetActive(void *p);

void RESEARCH_LIST_EnterSetup(u8 *p);

void RESEARCH_LIST_HandleScrollInput(u8 *p);

void RESEARCH_LIST_HandleSelectInput(char *p);

void RESEARCH_LIST_UpdateOpen(u8 *p);

void RESEARCH_LIST_UpdateDrag(struct ResearchTop *p);

void RESEARCH_LIST_HandleConfirm(char *p);

void RESEARCH_LIST_HandleCancel(char *p);

void RESEARCH_LIST_UpdateShowEntry(u8 *p);

void RESEARCH_LIST_UpdateHideEntry(u8 *p);

void RESEARCH_LIST_UpdateSaveExit(u8 *p);

void RESEARCH_LIST_UpdateFadeInWait(u8 *p);

void RESEARCH_LIST_UpdateFadeOutWait(u8 *p);

void RESEARCH_LIST_UpdateReturn(struct ResearchTop *p);

void RESEARCH_LIST_EnterExit(u8 *p);

void RESEARCH_LIST_IncStateTimer(void *p);

void RESEARCH_LIST_PushCommand(u8 *a0, u32 a1);

void RESEARCH_LIST_SetCommandReady(void *p);

u32 RESEARCH_LIST_GetEntryHandled(u8 *a0);

void RESEARCH_LIST_SetEntryHandled(u8 *a0, u32 a1);

void RESEARCH_LIST_SetActive(void *p, u32 v);

u32 RESEARCH_LIST_GetFadeWaitFrames(u8 *a0);

void RESEARCH_LIST_ProcessCommand(u32 a0);

u32 RESEARCH_LIST_GetState(void *p);

int RESEARCH_LIST_SetState(char *p, int a1);

u32 RESEARCH_LIST_GetSubState(void *p);

void RESEARCH_LIST_IncSubState(void *p);

void *RESEARCH_LIST_ClearSubState(void *p);

void RESEARCH_LIST_SelectPrevious(u32 a0);

void RESEARCH_LIST_SelectNext(u32 a0);

void RESEARCH_LIST_SetSelectionMode(u32 a0, u32 a1);

void RESEARCH_LIST_ScrollSelectionIntoView(u8 *p);

void RESEARCH_LIST_SelectEntry(u32 a0, u8 a1);

void RESEARCH_LIST_StartEntryPaletteAnime(u32 a0);

void RESEARCH_LIST_ComputeOpenScroll(u8 *p);

void RESEARCH_LIST_ComputeReturnScroll(u8 *p);

void RESEARCH_LIST_ComputeCenterScroll(u8 *p);

u8 RESEARCH_LIST_FindSaveIndex(u8 *p);

void RESEARCH_LIST_StoreSaveValues(u8 *p);

void RESEARCH_LIST_FlipSelectionMode(void *p, s32 v);

void RESEARCH_LIST_SetSelectionModeField(void *p, u32 v);

void RESEARCH_LIST_SetEntryPaletteIdle(int a, int b);

void RESEARCH_LIST_SetEntryPaletteActive(int a, int b);

void RESEARCH_LIST_SetCursorSlot(void *p, u8 v);

void RESEARCH_LIST_AdvanceEndIndex(u8 *p, int a);

void RESEARCH_LIST_ShowCursor(u8 *p);

void RESEARCH_LIST_HideCursor(u8 *p);

void RESEARCH_LIST_ShiftTextRight(u32 object,u32 slot);

void RESEARCH_LIST_ShiftTextLeft(u32 object,u32 slot);

u32 RESEARCH_LIST_GetRowOffset(u32 a0, u32 a1);

u32 RESEARCH_LIST_GetRowBase(u32 unused, u32 v);

int RESEARCH_LIST_GetEntryScreenX(unsigned char *p, unsigned int slot);

int RESEARCH_LIST_GetEntryScreenY(unsigned char *p, unsigned char index);

int RESEARCH_LIST_GetEntryScreenYBottom(unsigned char *p, unsigned int index);

void RESEARCH_LIST_UpdateWindowMask(u8 *p);

void RESEARCH_LIST_UpdateEntryActor(u8 *p);

int RESEARCH_LIST_PrintCurrentEntry(char *p);

int RESEARCH_LIST_PrintEntryLabels(u8 *p, u8 index);

void RESEARCH_LIST_HideEntryLabels(u32 a0);

void RESEARCH_LIST_ShowEntryLabels(u32 a0);

void RESEARCH_LIST_UpdateScrollbarActor(u32 a0);

int RESEARCH_LIST_GetScrollbarY(void *p);

int RESEARCH_LIST_GetScrollYFromPosition(void *p,int position);

void RESEARCH_LIST_UpdateMomentum(void *p);

int RESEARCH_LIST_IsMomentumActive(void *p);

void RESEARCH_LIST_ComputeMomentum(void *p);

void RESEARCH_LIST_DampMomentum(struct ResearchTop *p);

void RESEARCH_LIST_SetMomentumDirection(void *p);

void RESEARCH_LIST_StartScrollAnim(void *p, u32 a, u32 b, u32 c);

void RESEARCH_LIST_StepScrollAnim(struct ResearchTop *p);

int RESEARCH_LIST_IsScrollAnimDone(void *p);

void RESEARCH_LIST_SetScrollTarget(struct ResearchTop *p, int v);

void RESEARCH_LIST_SetScrollValue(void *p, u32 v);

void RESEARCH_LIST_ApplyScrollRegs(u8 *p);

void RESEARCH_LIST_SetListScroll(struct ResearchTop *p);

int RESEARCH_LIST_GetScrollY(void);

void RESEARCH_LIST_SetScrollY(u32 a0);

u32 RESEARCH_LIST_GetScrollMin(void);

u32 RESEARCH_LIST_GetScrollMax(void);

int RESEARCH_LIST_DivideByEntryHeight(u32 a0);

u32 RESEARCH_LIST_EntryIndexToY(u32 v);

u32 RESEARCH_LIST_EntryIndexToYBottom(u32 v);

int RESEARCH_LIST_GetScrollRange(void *p);

u32 RESEARCH_LIST_GetScrollRangeMax(void *p);

int RESEARCH_LIST_NeedsScrollbar(void *p);

void RESEARCH_LIST_UpdateTouchRects(u8 *p);

void RESEARCH_LIST_FadeIn(void);

void RESEARCH_LIST_FadeOut(void);

int RESEARCH_LIST_IsFadeDone(void);

void RESEARCH_LIST_ShowEntryPalette(char *p);

void RESEARCH_LIST_HideEntryPalette(char *p);

u32 RESEARCH_LIST_IsPaletteFadeDone(u32 a0);

void RESEARCH_LIST_StartPaletteAnime(u8 **p, u32 i);

void RESEARCH_LIST_StartListPaletteAnime(char *p, int i);

void RESEARCH_LIST_StopListPaletteAnime(u8 *a0, int a1);

u32 RESEARCH_LIST_IsListPaletteAnimeRunning(u32 a0, u32 a1);

void RESEARCH_LIST_UpdatePaletteAnimes(int *p);

void RESEARCH_LIST_UpdateCommonPaletteAnime(u8 *a0);

u32 RESEARCH_LIST_GetKeyRepeatTimer(void *p);

void RESEARCH_LIST_IncKeyRepeatTimer(void *p);

void RESEARCH_LIST_ClearKeyRepeatTimer(void *p);

void RESEARCH_LIST_VBlankHandler(u32 a0, u32 a1);

u32 RESEARCH_LIST_GetAppResource(u8 *a0);

void RESEARCH_LIST_SetHeapId(void *p, u32 v);

void RESEARCH_LIST_SetOwner(void *p, u32 v);

u32 RESEARCH_LIST_GetOwner(void *p);

void RESEARCH_LIST_SetListView(void *p, u32 v);

void RESEARCH_LIST_SyncFromListView(struct ResearchTop *p);

void RESEARCH_LIST_SyncToListView(char *p);

u32 RESEARCH_LIST_GetInputFlag(void *p);

u32 RESEARCH_LIST_GetEntryCount(void *p);

u32 RESEARCH_LIST_GetSelectedIndex(void *p);

void RESEARCH_LIST_SetSelectedIndex(void *p, u8 v);

u32 RESEARCH_LIST_IsValidIndex(u32 a0, u32 a1);

u32 RESEARCH_LIST_GetResourceId(void *p, u32 i);

u32 RESEARCH_LIST_GetClactUnit(void *p, u32 i);

u32 RESEARCH_LIST_GetActor(void *p, u32 i);

void RESEARCH_LIST_SetOamEnabled(u8 *a0, u32 a1, u8 *a2);

int RESEARCH_LIST_GetOamObject(char *p, int i);

u32 RESEARCH_LIST_Alloc(u32 a0);

void RESEARCH_LIST_InitFields(u8 *p);

u32 RESEARCH_LIST_Free(void *a0);

void RESEARCH_LIST_CountUnlockedEntries(u8 *p);

void RESEARCH_LIST_CreateFont(u32 a0);

void RESEARCH_LIST_ClearFont(void *p);

void RESEARCH_LIST_DeleteFont(u8 *a0);

void RESEARCH_LIST_CreateMessages(struct ResearchTop *p);

void RESEARCH_LIST_ClearMessages(void *p);

void RESEARCH_LIST_DeleteMessages(int *p);

void RESEARCH_LIST_CreateCommandQueue(u32 a0);

void RESEARCH_LIST_ClearCommandQueue(void *p);

void RESEARCH_LIST_DestroyCommandQueue(u8 *a0);

void RESEARCH_LIST_InitTables(u8 *p);

void RESEARCH_LIST_InitBackgrounds(char *p);

u32 RESEARCH_LIST_ExitBackgrounds(u8 *a0);

void RESEARCH_LIST_LoadBackground6(char *p);

void RESEARCH_LIST_DummyBg7(u8 *a0);

u32 RESEARCH_LIST_UpdateBackground7(u32 a0);

void RESEARCH_LIST_ShowBackground7(u32 a0);

void RESEARCH_LIST_LoadBackground2(char *p);

void RESEARCH_LIST_DummyBg3(u8 *a0);

void RESEARCH_LIST_LoadListBackground(struct ResearchTop *p);

void RESEARCH_LIST_DummyListBg(u8 *a0);

u32 RESEARCH_LIST_UpdateBackground3(u32 a0);

void RESEARCH_LIST_ShowBackground3(u32 a0);

void RESEARCH_LIST_CreateLabels(struct ResearchTop *p);

void RESEARCH_LIST_ClearLabels(void *p);

void RESEARCH_LIST_DestroyLabels(u8 *p);

void RESEARCH_LIST_ClearResources(void *p);

void RESEARCH_LIST_RegisterEntryResources(char *p);

u32 RESEARCH_LIST_ReleaseEntryResources(u32 a0);

void RESEARCH_LIST_RegisterCursorResources(char *p);

u32 RESEARCH_LIST_ReleaseCursorResources(u32 a0);

void RESEARCH_LIST_ClearUnits(void *p);

void RESEARCH_LIST_CreateUnits(struct ResearchTop *p);

void RESEARCH_LIST_DeleteUnits(int *p);

void RESEARCH_LIST_ClearActors(void *p);

void RESEARCH_LIST_CreateActors(u8 *p);

void RESEARCH_LIST_DeleteActors(int *p);

void RESEARCH_LIST_ClearBmps(void *p);

void RESEARCH_LIST_CreateBmps(struct ResearchTop *p);

void RESEARCH_LIST_DrawBmps(u8 *p);

void RESEARCH_LIST_DrawBadgeA(struct ResearchTop *p);

void RESEARCH_LIST_DrawBadgeB(struct ResearchTop *p);

void RESEARCH_LIST_DeleteBmps(int *p);

void RESEARCH_LIST_CreateOamSys(char *p);

void RESEARCH_LIST_DeleteOamSys(u8 *a0);

void RESEARCH_LIST_CreateOamObjects(u8 *p);

void RESEARCH_LIST_DeleteOamObjects(int *p);

void RESEARCH_LIST_ClearPalAnm(void *p);

void RESEARCH_LIST_CreatePalAnm(u8 *p);

u32 RESEARCH_LIST_DeletePalAnm(u32 a0);

void RESEARCH_LIST_CreatePaletteAnime(char *p);

void RESEARCH_LIST_ClearPaletteAnime(void *p);

void RESEARCH_LIST_DestroyPaletteAnime(int *p);

void RESEARCH_LIST_BindPaletteAnime(int *p);

void RESEARCH_LIST_RestorePaletteAnime(int *p);

void RESEARCH_LIST_UpdateCenterActor(void *p);

void RESEARCH_LIST_RestartNetwork(u32 a0);

void RESEARCH_LIST_RegisterVBlank(char *p);

void RESEARCH_LIST_UnregisterVBlank(u32 a0);

extern const u8 d_021C308A[];

extern const u8 d_021C3080[];

extern const u8 d_021C30A8[];

extern const u8 d_021C309E[];

extern const u8 d_021C3094[];

extern const u8 d_021C30D0[];

extern const struct PalAnmDef d_021C326C[];

extern int d_021C3068[];

extern const unsigned int d_021C3078[];

extern const u8 d_021C30B2[];

extern const u8 d_021C3190[];

extern const u8 d_021C3070[];

extern struct DispConfig d_021C30C0;

extern const struct BgTemplate d_021C3110, d_021C3130, d_021C30F0, d_021C3150, d_021C3170;

extern const struct LabelEntry d_021C33C8[];

extern const struct LabelEntry d_021C3520[];

extern const u8 d_021C305C[];

extern const u16 d_021C3060[];

extern const struct ActorDef d_021C320C[];

extern const struct BmpDef d_021C3470[];

extern const struct Tab d_021C3350;

extern const struct ResearchListEntryDef d_021C349C;

extern const struct Tab d_021C32D8;

extern const struct ResearchListEntryDef d_021C34C8;

extern const struct OamDef d_021C31BC[];

extern const struct Entry021C3260 d_021C3260[];

u32 RESEARCH_LIST_Create(u32 a0, u32 a1)
{
    u32 v1 = RESEARCH_COMMON_GetHeapId((void *)a0);
    u32 v2 = RESEARCH_LIST_Alloc(v1);
    RESEARCH_LIST_InitFields((u8 *)v2);
    RESEARCH_LIST_SetHeapId((void *)v2, v1);
    RESEARCH_LIST_SetOwner((void *)v2, a0);
    RESEARCH_LIST_SetListView((void *)v2, a1);
    return v2;
}

u32 RESEARCH_LIST_Destroy(void *a0)
{
    RESEARCH_LIST_DestroyCommandQueue((u8 *)a0);
    return RESEARCH_LIST_Free(a0);
}

void RESEARCH_LIST_Update(void *self)
{
    switch (RESEARCH_LIST_GetState(self)) {
    case 0: RESEARCH_LIST_EnterSetup(self); break;
    case 1: RESEARCH_LIST_HandleScrollInput(self); break;
    case 2: RESEARCH_LIST_HandleSelectInput(self); break;
    case 3: RESEARCH_LIST_UpdateOpen(self); break;
    case 4: RESEARCH_LIST_UpdateDrag((struct ResearchTop *)self); break;
    case 6: RESEARCH_LIST_UpdateFadeInWait(self); break;
    case 5: RESEARCH_LIST_UpdateFadeOutWait(self); break;
    case 7: RESEARCH_LIST_UpdateShowEntry(self); break;
    case 8: RESEARCH_LIST_HandleConfirm(self); break;
    case 9: RESEARCH_LIST_UpdateHideEntry(self); break;
    case 10: RESEARCH_LIST_HandleCancel(self); break;
    case 11: RESEARCH_LIST_UpdateReturn((struct ResearchTop *)self); break;
    case 12: RESEARCH_LIST_UpdateSaveExit(self); break;
    case 13: RESEARCH_LIST_EnterExit(self); break;
    case 14: break;
    }
    if (!RESEARCH_LIST_GetVisible(self)) {
        RESEARCH_LIST_UpdateCommonPaletteAnime(self);
        RESEARCH_LIST_UpdatePaletteAnimes(self);
        CLACT_DrawSystem();
    }
    RESEARCH_LIST_IncStateTimer(self);
    RESEARCH_LIST_ProcessCommand((u32)self);
}

u32 RESEARCH_LIST_GetVisible(void *p)
{
    return ((struct ResearchTop *)p)->visible;
}

/*
 * Field getter, u32 at +0x168.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_LIST_GetActive(void *p)
{
    return ((struct ResearchTop *)p)->active;
}

void RESEARCH_LIST_EnterSetup(u8 *p)
{
    u8 slot;
    RESEARCH_LIST_CreateCommandQueue((u32)p);
    RESEARCH_LIST_CreateFont((u32)p);
    RESEARCH_LIST_CreateMessages((struct ResearchTop *)p);
    RESEARCH_LIST_InitTables(p);
    RESEARCH_LIST_UpdateTouchRects(p);
    RESEARCH_LIST_CountUnlockedEntries(p);
    RESEARCH_LIST_InitBackgrounds((char *)p);
    RESEARCH_LIST_LoadBackground6((char *)p);
    RESEARCH_LIST_UpdateBackground7((u32)p);
    RESEARCH_LIST_LoadBackground2((char *)p);
    RESEARCH_LIST_LoadListBackground((struct ResearchTop *)p);
    RESEARCH_LIST_UpdateBackground3((u32)p);
    RESEARCH_LIST_CreateLabels((struct ResearchTop *)p);
    RESEARCH_LIST_RegisterEntryResources((char *)p);
    RESEARCH_LIST_RegisterCursorResources((char *)p);
    RESEARCH_LIST_CreateUnits((struct ResearchTop *)p);
    RESEARCH_LIST_CreateActors(p);
    RESEARCH_LIST_CreateBmps((struct ResearchTop *)p);
    RESEARCH_LIST_DrawBmps(p);
    RESEARCH_LIST_DrawBadgeA((struct ResearchTop *)p);
    RESEARCH_LIST_DrawBadgeB((struct ResearchTop *)p);
    RESEARCH_LIST_CreateOamSys((char *)p);
    RESEARCH_LIST_CreateOamObjects(p);
    RESEARCH_LIST_CreatePalAnm(p);
    RESEARCH_LIST_CreatePaletteAnime((char *)p);
    RESEARCH_LIST_BindPaletteAnime((int *)p);
    RESEARCH_LIST_RegisterVBlank((char *)p);
    RESEARCH_LIST_RestartNetwork((u32)p);
    RESEARCH_LIST_UpdateCenterActor(p);
    RESEARCH_LIST_StartListPaletteAnime((char *)p,0);
    RESEARCH_LIST_SetOamEnabled(p,0,0);
    RESEARCH_LIST_SetOamEnabled(p,1,0);
    RESEARCH_LIST_SetOamEnabled(p,2,0);
    RESEARCH_LIST_SyncFromListView((struct ResearchTop *)p);
    slot=RESEARCH_LIST_FindSaveIndex(p);
    if(slot!=255) {
        RESEARCH_LIST_ShiftTextRight((u32)p,slot);
        RESEARCH_LIST_SetSelectedIndex(p,slot);
        RESEARCH_LIST_UpdateEntryActor(p);
    }
    RESEARCH_LIST_UpdateTouchRects(p);
    RESEARCH_LIST_UpdateScrollbarActor((u32)p);
    RESEARCH_LIST_UpdateEntryActor(p);
    RESEARCH_LIST_UpdateWindowMask(p);
    RESEARCH_LIST_PrintCurrentEntry((char *)p);
    if(RESEARCH_LIST_GetEntryHandled(p)==0) {
        RESEARCH_LIST_ShowCursor(p);
        RESEARCH_LIST_ShowEntryLabels((u32)p);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand(p,2);
    } else {
        RESEARCH_LIST_HideCursor(p);
        RESEARCH_LIST_HideEntryLabels((u32)p);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand(p,1);
    }
    RESEARCH_LIST_FadeIn();
}

/* Narrow selection parameters follow the caller's explicit lsls/lsrs #24 pairs. */
void RESEARCH_LIST_HandleScrollInput(u8 *p)
{
    u32 keys=KEY_GetTrg();
    int sel=TOUCHPANEL_HitTrg(p+0x64);
    int flag;
    u32 a,b;
    flag=TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(*(void **)p));
    TOUCHPANEL_GetPointCont(&a,&b);
    if(RESEARCH_LIST_GetInputFlag(p)!=0 || flag==0) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_StartEntryPaletteAnime((u32)p);
        RESEARCH_LIST_SetEntryHandled(p,1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand(p,5);
        return;
    }
    if(keys&2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_StartEntryPaletteAnime((u32)p);
        RESEARCH_LIST_SetEntryHandled(p,0);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand(p,5);
        return;
    }
    if((keys&0x40)||(keys&0x80)||(keys&0x20)||(keys&0x10)||(keys&1)) {
        RESEARCH_LIST_ShowCursor(p);
        RESEARCH_LIST_ShowEntryLabels((u32)p);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand(p,2);
        return;
    }
    if(sel>=0 && sel<=9) {
        if(b>=24 && b<=168) {
            if(RESEARCH_LIST_IsValidIndex((u32)p,(u8)sel)==1) {
                RESEARCH_LIST_SelectEntry((u32)p,sel);
                RESEARCH_LIST_SetSelectedIndex(p,p[0x32]);
                GFL_USE_PlaySeDefaultVolume(0x54c);
                RESEARCH_LIST_StartListPaletteAnime((char *)p,2);
                RESEARCH_LIST_PrintCurrentEntry((char *)p);
                RESEARCH_LIST_ShowEntryLabels((u32)p);
                RESEARCH_LIST_SetCommandReady(p);
                RESEARCH_LIST_PushCommand(p,7);
                return;
            }
        }
    } else {
        if(TOUCHPANEL_HitCont(p+0x90)==0 || TOUCHPANEL_HitTrg(p+0x90)==0) {
            if(RESEARCH_LIST_NeedsScrollbar(p)==1) {
                RESEARCH_LIST_SetCommandReady(p);
                RESEARCH_LIST_PushCommand(p,4);
                RESEARCH_LIST_PushCommand(p,1);
            }
        }
    }
}

void RESEARCH_LIST_HandleSelectInput(char *p)
{
    u32 trg = KEY_GetCont();
    u32 keys = KEY_GetTrg();
    int sel = TOUCHPANEL_HitTrg(p + 0x64);
    int flag;
    u32 a;
    u32 b;
    flag = TOUCHPANEL_HitTrg(RESEARCH_COMMON_GetTouchRects(*(void **)p));
    TOUCHPANEL_GetPointCont(&a, &b);
    if (trg & 0xc0) {
        RESEARCH_LIST_IncKeyRepeatTimer(p);
    } else {
        RESEARCH_LIST_ClearKeyRepeatTimer(p);
    }
    if (RESEARCH_LIST_GetInputFlag(p) != 0 || flag == 0) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_StartEntryPaletteAnime((u32)p);
        RESEARCH_LIST_SetEntryHandled((u8 *)p, (int)1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)6);
        return;
    }
    if ((keys & 0x40) || ((trg & 0x40) && ((struct ResearchTop *)p)->cursorSlot != 0 && RESEARCH_LIST_GetKeyRepeatTimer(p) > 10)) {
        RESEARCH_LIST_HideCursor((u8 *)p);
        RESEARCH_LIST_AdvanceEndIndex((u8 *)p, -1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)3);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)2);
        return;
    }
    if ((keys & 0x80) || ((trg & 0x80) && ((struct ResearchTop *)p)->cursorSlot < (int)RESEARCH_LIST_GetEntryCount(p) - 1 && RESEARCH_LIST_GetKeyRepeatTimer(p) > 10)) {
        RESEARCH_LIST_HideCursor((u8 *)p);
        RESEARCH_LIST_AdvanceEndIndex((u8 *)p, 1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)3);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)2);
        return;
    }
    if (keys & 1) {
        RESEARCH_LIST_StartListPaletteAnime(p, 2);
        RESEARCH_LIST_SetSelectedIndex(p, ((struct ResearchTop *)p)->cursorSlot);
        GFL_USE_PlaySeDefaultVolume(0x54c);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)9);
        RESEARCH_LIST_SetCommandReady(p);
        return;
    }
    if (sel >= 0 && sel <= 9) {
        if (b >= 0x18 && b <= 0xa8 && RESEARCH_LIST_IsValidIndex((u32)p, (u8)sel) == 1) {
            RESEARCH_LIST_SelectEntry((u32)p, (u8)sel);
            RESEARCH_LIST_SetSelectedIndex(p, ((struct ResearchTop *)p)->cursorSlot);
            RESEARCH_LIST_StartListPaletteAnime(p, 2);
            GFL_USE_PlaySeDefaultVolume(0x54c);
            RESEARCH_LIST_PrintCurrentEntry(p);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand((u8 *)p, (int)7);
        }
        return;
    }
    if (keys & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_StartEntryPaletteAnime((u32)p);
        RESEARCH_LIST_SetEntryHandled((u8 *)p, (int)0);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((u8 *)p, (int)6);
        return;
    }
    if (TOUCHPANEL_HitCont(p + 0x90) == 0 || TOUCHPANEL_HitTrg(p + 0x90) == 0) {
        if (RESEARCH_LIST_NeedsScrollbar(p) == 1) {
            RESEARCH_LIST_HideCursor((u8 *)p);
            RESEARCH_LIST_HideEntryLabels((u32)p);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand((u8 *)p, (int)4);
            RESEARCH_LIST_PushCommand((u8 *)p, (int)1);
        }
    }
}

void RESEARCH_LIST_UpdateOpen(u8 *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        RESEARCH_LIST_ComputeOpenScroll(p);
        RESEARCH_LIST_SelectEntry((unsigned)p, p[0x33]);
        RESEARCH_LIST_PrintCurrentEntry((char *)p);
        RESEARCH_LIST_IncSubState(p);
        break;
    case 1:
        RESEARCH_LIST_StepScrollAnim((struct ResearchTop *)p);
        RESEARCH_LIST_ApplyScrollRegs(p);
        RESEARCH_LIST_UpdateTouchRects(p);
        RESEARCH_LIST_UpdateScrollbarActor((unsigned)p);
        RESEARCH_LIST_UpdateEntryActor(p);
        RESEARCH_LIST_UpdateWindowMask(p);
        if (RESEARCH_LIST_IsScrollAnimDone(p)) {
            RESEARCH_LIST_UpdateWindowMask(p);
            RESEARCH_LIST_SetCommandReady(p);
        }
        break;
    }
}

void RESEARCH_LIST_UpdateDrag(struct ResearchTop *p)
{
    int a;
    int b;
    int r = TOUCHPANEL_GetPointCont((unsigned int *)(&a), (unsigned int *)(&b));
    int m = RESEARCH_LIST_GetSubState(p);
    switch (m) {
    case 0:
    {
        if (r == 0) {
            RESEARCH_LIST_DampMomentum((struct ResearchTop *)p);
            RESEARCH_LIST_SetMomentumDirection(p);
            RESEARCH_LIST_IncSubState(p);
        } else {
            RESEARCH_LIST_SetScrollTarget((struct ResearchTop *)p, RESEARCH_LIST_GetScrollYFromPosition(p, b));
            RESEARCH_LIST_SetListScroll((struct ResearchTop *)p);
            RESEARCH_LIST_UpdateTouchRects((u8 *)p);
            RESEARCH_LIST_UpdateScrollbarActor((unsigned int)p);
            RESEARCH_LIST_UpdateEntryActor((u8 *)p);
            RESEARCH_LIST_ComputeMomentum(p);
        }
        break;
    }
    case 1:
    {
        RESEARCH_LIST_SetScrollTarget((struct ResearchTop *)p, p->scrollY + p->momentum);
        RESEARCH_LIST_SetListScroll((struct ResearchTop *)p);
        RESEARCH_LIST_UpdateTouchRects((u8 *)p);
        RESEARCH_LIST_UpdateScrollbarActor((unsigned int)p);
        RESEARCH_LIST_UpdateEntryActor((u8 *)p);
        RESEARCH_LIST_UpdateMomentum(p);
        if (RESEARCH_LIST_IsMomentumActive(p) == 0) {
            RESEARCH_LIST_PrintCurrentEntry((char *)p);
            RESEARCH_LIST_SetCommandReady(p);
        }
        break;
    }
    }
    RESEARCH_LIST_ScrollSelectionIntoView((u8 *)p);
}

void RESEARCH_LIST_HandleConfirm(char *p)
{
    u32 keys = KEY_GetTrg();
    int st = TOUCHPANEL_HitTrg(p + 0x58);
    if ((keys & 0x40) || (keys & 0x80) || (keys & 0x20) || (keys & 0x10) || (keys & 1)) {
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((unsigned char *)p, 9);
        return;
    }
    if (st == 0) {
        RESEARCH_LIST_SetSelectionMode((u32)p, 0);
        RESEARCH_LIST_StopListPaletteAnime((u8 *)p, 3);
        RESEARCH_LIST_StartListPaletteAnime(p, 5);
        RESEARCH_LIST_SetEntryHandled((u8 *)p, 1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((unsigned char *)p, 12);
        return;
    }
    if (RESEARCH_LIST_GetInputFlag(p) != 0 || (keys & 2) || st == 1) {
        RESEARCH_LIST_SetSelectionMode((u32)p, 1);
        RESEARCH_LIST_StopListPaletteAnime((u8 *)p, 3);
        RESEARCH_LIST_StartListPaletteAnime(p, 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((unsigned char *)p, 11);
        RESEARCH_LIST_PushCommand((unsigned char *)p, 2);
    }
}

void RESEARCH_LIST_HandleCancel(char *p)
{
    u32 keys = KEY_GetTrg();
    int st = TOUCHPANEL_HitTrg(p + 0x58);
    if (keys & 0x40) {
        RESEARCH_LIST_SelectPrevious((u32)p);
    }
    if (keys & 0x80) {
        RESEARCH_LIST_SelectNext((u32)p);
    }
    if (keys & 1) {
        RESEARCH_LIST_StopListPaletteAnime((u8 *)p, 3);
        RESEARCH_LIST_StartListPaletteAnime(p, 5);
        switch (*(int *)&((struct ResearchTop *)p)->selectionMode) {
        case 0:
            RESEARCH_LIST_SetEntryHandled((u8 *)p, 0);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand((unsigned char *)p, 12);
            break;
        case 1:
            GFL_USE_PlaySeDefaultVolume(0x551);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand((unsigned char *)p, 11);
            RESEARCH_LIST_PushCommand((unsigned char *)p, 2);
            break;
        }
        return;
    }
    if (st == 0) {
        RESEARCH_LIST_SetSelectionMode((u32)p, 0);
        RESEARCH_LIST_StopListPaletteAnime((u8 *)p, 3);
        RESEARCH_LIST_StartListPaletteAnime(p, 5);
        RESEARCH_LIST_SetEntryHandled((u8 *)p, 1);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((unsigned char *)p, 12);
        return;
    }
    if (RESEARCH_LIST_GetInputFlag(p) != 0 || (keys & 2) || st == 1) {
        RESEARCH_LIST_SetSelectionMode((u32)p, 1);
        RESEARCH_LIST_StopListPaletteAnime((u8 *)p, 3);
        RESEARCH_LIST_StartListPaletteAnime(p, 5);
        GFL_USE_PlaySeDefaultVolume(0x551);
        RESEARCH_LIST_SetCommandReady(p);
        RESEARCH_LIST_PushCommand((unsigned char *)p, 11);
        RESEARCH_LIST_PushCommand((unsigned char *)p, 2);
    }
}

void RESEARCH_LIST_UpdateShowEntry(u8 *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        RESEARCH_LIST_SetEntryPaletteActive((int)p, 1);
        RESEARCH_LIST_SetEntryPaletteActive((int)p, 0);
        RESEARCH_LIST_SetOamEnabled(p, 0, (u8 *)1);
        RESEARCH_LIST_SetOamEnabled(p, 1, (u8 *)1);
        RESEARCH_LIST_SetOamEnabled(p, 2, (u8 *)1);
        if (((struct ResearchTop *)p)->entryPaletteActive == 0) {
            BgTextLabel_SetPalette((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 14);
            RESEARCH_LIST_ShowEntryPalette((char *)p);
        }
        RESEARCH_LIST_ComputeCenterScroll(p);
        RESEARCH_LIST_IncSubState(p);
        break;
    case 1:
        RESEARCH_LIST_StepScrollAnim((struct ResearchTop *)p);
        RESEARCH_LIST_ApplyScrollRegs(p);
        RESEARCH_LIST_UpdateTouchRects(p);
        RESEARCH_LIST_UpdateScrollbarActor((unsigned)p);
        RESEARCH_LIST_UpdateEntryActor(p);
        RESEARCH_LIST_UpdateWindowMask(p);
        if (RESEARCH_LIST_IsScrollAnimDone(p)) {
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand(p, 8);
        }
        break;
    }
}

void RESEARCH_LIST_UpdateHideEntry(u8 *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        RESEARCH_LIST_SetSelectionModeField(p, 0);
        RESEARCH_LIST_SetEntryPaletteActive((int)p, 1);
        RESEARCH_LIST_SetEntryPaletteIdle((int)p, 0);
        RESEARCH_LIST_StartListPaletteAnime((char *)((unsigned)p), 3);
        RESEARCH_LIST_SetOamEnabled(p, 0, (u8 *)1);
        RESEARCH_LIST_SetOamEnabled(p, 1, (u8 *)1);
        RESEARCH_LIST_SetOamEnabled(p, 2, (u8 *)1);
        if (((struct ResearchTop *)p)->entryPaletteActive == 0) {
            BgTextLabel_SetPalette((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 14);
            RESEARCH_LIST_ShowEntryPalette((char *)p);
        }
        RESEARCH_LIST_ComputeCenterScroll(p);
        RESEARCH_LIST_IncSubState(p);
        break;
    case 1:
        RESEARCH_LIST_StepScrollAnim((struct ResearchTop *)p);
        RESEARCH_LIST_ApplyScrollRegs(p);
        RESEARCH_LIST_UpdateTouchRects(p);
        RESEARCH_LIST_UpdateScrollbarActor((unsigned)p);
        RESEARCH_LIST_UpdateEntryActor(p);
        RESEARCH_LIST_UpdateWindowMask(p);
        if (RESEARCH_LIST_IsScrollAnimDone(p)) {
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand(p, 10);
        }
        break;
    }
}

/*
 * arity: BB910 retains supplied r1=13 through its forwarding chain.
 */
void RESEARCH_LIST_UpdateSaveExit(u8 *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        RESEARCH_LIST_ShiftTextLeft((unsigned int)p, RESEARCH_LIST_FindSaveIndex(p));
        RESEARCH_LIST_StoreSaveValues(p);
        RESEARCH_LIST_ShiftTextRight((unsigned int)p, RESEARCH_LIST_GetSelectedIndex(p));
        RESEARCH_LIST_UpdateEntryActor(p);
        RESEARCH_LIST_SetOamEnabled(p, 3, (u8 *)1);
        GFL_USE_PlaySeDefaultVolume(1898);
        RESEARCH_LIST_IncSubState(p);
        break;
    case 1:
        if (((struct ResearchTop *)p)->stateTimer >= 60) {
            RESEARCH_LIST_FadeOut();
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 2:
        if (RESEARCH_LIST_IsFadeDone()) {
            RESEARCH_LIST_HideEntryPalette((char *)p);
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 3:
        if (RESEARCH_LIST_IsPaletteFadeDone((unsigned)p)) {
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand(p, 13);
        }
        break;
    }
}

/*
 * extent: 021BB70E..021BB710 is two zero bytes of alignment padding.
 * arity: BB910 visibly receives r1=13; retain it through the forwarding chain despite its one-argument legacy file.
 */
void RESEARCH_LIST_UpdateFadeInWait(u8 *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        if (RESEARCH_LIST_GetFadeWaitFrames(p) < ((struct ResearchTop *)p)->stateTimer) {
            RESEARCH_LIST_FadeOut();
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 1:
        if (RESEARCH_LIST_IsFadeDone()) {
            RESEARCH_LIST_HideEntryPalette((char *)p);
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 2:
        if (RESEARCH_LIST_IsPaletteFadeDone((unsigned)p)) {
            BgTextLabel_SetPalette((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 15);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand(p, 13);
        }
        break;
    }
}

/*
 * extent: 021BB782..021BB784 is two zero bytes of alignment padding.
 * arity: BB910 visibly receives r1=13; retain it through the forwarding chain despite its one-argument legacy file.
 */
void RESEARCH_LIST_UpdateFadeOutWait(u8 *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        if (RESEARCH_LIST_GetFadeWaitFrames(p) < ((struct ResearchTop *)p)->stateTimer) {
            RESEARCH_LIST_FadeOut();
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 1:
        if (RESEARCH_LIST_IsFadeDone()) {
            RESEARCH_LIST_HideEntryPalette((char *)p);
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 2:
        if (RESEARCH_LIST_IsPaletteFadeDone((unsigned)p)) {
            BgTextLabel_SetPalette((u8 *)(*(unsigned *)(p + p[0x32] * 4 + 0xb4)), 15);
            RESEARCH_LIST_SetCommandReady(p);
            RESEARCH_LIST_PushCommand(p, 13);
        }
        break;
    }
}

void RESEARCH_LIST_UpdateReturn(struct ResearchTop *p)
{
    switch (RESEARCH_LIST_GetSubState(p)) {
    case 0:
        RESEARCH_LIST_ComputeReturnScroll((u8 *)p);
        RESEARCH_LIST_IncSubState(p);
        break;
    case 1:
        RESEARCH_LIST_StepScrollAnim((struct ResearchTop *)p);
        RESEARCH_LIST_ApplyScrollRegs((u8 *)p);
        RESEARCH_LIST_UpdateTouchRects((u8 *)p);
        RESEARCH_LIST_UpdateScrollbarActor((unsigned int)p);
        RESEARCH_LIST_UpdateEntryActor((u8 *)p);
        RESEARCH_LIST_UpdateWindowMask((u8 *)p);
        if (RESEARCH_LIST_IsScrollAnimDone(p) != 0) {
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 2:
        if (RESEARCH_LIST_IsListPaletteAnimeRunning((u32)p, 5) != 0) {
            RESEARCH_LIST_SetOamEnabled((u8 *)p, 0, 0);
            RESEARCH_LIST_SetOamEnabled((u8 *)p, 1, 0);
            RESEARCH_LIST_SetOamEnabled((u8 *)p, 2, 0);
            RESEARCH_LIST_UpdateWindowMask((u8 *)p);
            RESEARCH_LIST_HideEntryPalette((char *)p);
            RESEARCH_LIST_IncSubState(p);
        }
        break;
    case 3:
        if (RESEARCH_LIST_IsPaletteFadeDone((u32)p) != 0) {
            BgTextLabel_SetPalette(p->entryLabels[p->cursorSlot], 15);
            RESEARCH_LIST_SetCommandReady(p);
        }
        break;
    }
}

/*
 * volatile: DISPCNT read at 021BB8FA and write at 021BB900.
 * arity: C09E0/C09EC overwrite r1 before their indexed targets; BD3A4 overwrites r1=300; BCC58/BCB60 overwrite r1/r2 before 02040DA8. Omit only unused legacy trailing inputs, retain each visibly supplied context and BB910 r1=14.
 */
void RESEARCH_LIST_EnterExit(u8 *p)
{
    RESEARCH_LIST_SyncToListView((char *)p);
    RESEARCH_LIST_UnregisterVBlank((unsigned)p);
    RESEARCH_LIST_RestorePaletteAnime((int *)p);
    RESEARCH_LIST_DestroyPaletteAnime((int *)p);
    RESEARCH_COMMON_StopPaletteAnime(*(unsigned *)p);
    RESEARCH_COMMON_RestorePaletteAnime(*(unsigned *)p);
    RESEARCH_LIST_DeletePalAnm((unsigned)p);
    RESEARCH_LIST_DeleteBmps((int *)p);
    RESEARCH_LIST_DeleteOamObjects((int *)p);
    RESEARCH_LIST_DeleteOamSys(p);
    RESEARCH_LIST_DeleteActors((int *)p);
    RESEARCH_LIST_DeleteUnits((int *)p);
    RESEARCH_LIST_ReleaseEntryResources((unsigned)p);
    RESEARCH_LIST_ReleaseCursorResources((unsigned)p);
    RESEARCH_LIST_DestroyLabels(p);
    RESEARCH_LIST_ShowBackground3((unsigned)p);
    RESEARCH_LIST_DummyBg3(p);
    RESEARCH_LIST_DummyListBg(p);
    RESEARCH_LIST_ShowBackground7((unsigned)p);
    RESEARCH_LIST_DummyBg7(p);
    RESEARCH_LIST_ExitBackgrounds(p);
    RESEARCH_LIST_DeleteMessages((int *)p);
    RESEARCH_LIST_DeleteFont(p);
    RESEARCH_LIST_SetActive(p, 0);
    RESEARCH_LIST_SetCommandReady(p);
    RESEARCH_LIST_PushCommand(p, 14);
    ((struct ResearchTop *)p)->visible = 1;
    *(volatile unsigned *)0x04000000 &= 0xffff1fff;
}

void RESEARCH_LIST_IncStateTimer(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x24);
    *c += 1;
}

void RESEARCH_LIST_PushCommand(u8 *a0, u32 a1)
{
    RingQueue_Push((u32)(((struct ResearchTop *)a0)->commandQueue), a1);
}

/*
 * Set the u32 at +0x158 to 1.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_SetCommandReady(void *p)
{
    ((struct ResearchTop *)p)->commandReady = 1;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0)) to RESEARCH_COMMON_GetEntryHandled.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_LIST_GetEntryHandled(u8 *a0)
{
    return RESEARCH_COMMON_GetEntryHandled((void *)((u32)(((struct ResearchTop *)a0)->owner)));
}

void RESEARCH_LIST_SetEntryHandled(u8 *a0, u32 a1)
{
    RESEARCH_COMMON_SetEntryHandled(*(u8 * *)&((struct ResearchTop *)a0)->owner, a1);
}

/*
 * Field setter, u32 at +0x168.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_SetActive(void *p, u32 v)
{
    ((struct ResearchTop *)p)->active = v;
}

u32 RESEARCH_LIST_GetFadeWaitFrames(u8 *a0)
{
    return ((struct ResearchTop *)a0)->fadeWaitFrames;
}

/*
 * Same guard shape as 021BA158 on the +0x158 word, handing the +0x18
 * handle to RESEARCH_LIST_SetState.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_ProcessCommand(u32 a0)
{
    if (((struct ResearchTop *)a0)->commandReady != 0) {
    if (RingQueue_IsEmpty(((struct ResearchTop *)a0)->commandQueue) == 0) {
    RESEARCH_LIST_SetState((char *)a0, RingQueue_Pop((struct Ring *)(((struct ResearchTop *)a0)->commandQueue)));
    }
    }
}

u32 RESEARCH_LIST_GetState(void *p)
{
    return ((struct ResearchTop *)p)->state;
}

int RESEARCH_LIST_SetState(char *p, int a1)
{
    int off = 0x56;
    ((struct ResearchTop *)p)->state = a1;
    ((struct ResearchTop *)p)->stateTimer = 0;
    *(int *)(p + (off << 2)) = 0;
    return (int)RESEARCH_LIST_ClearSubState(p);
}

u32 RESEARCH_LIST_GetSubState(void *p)
{
    return ((struct ResearchTop *)p)->subState;
}

void RESEARCH_LIST_IncSubState(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x20);
    *c += 1;
}

/*
 * Unlabelled Thumb leaf in a .word run:
 *   movs r1,#0; str r1,[r0,#0x20]; bx lr
 * Clears the word at p+0x20.
 */
void *RESEARCH_LIST_ClearSubState(void *p)
{
    ((struct ResearchTop *)p)->subState = 0;
    return p;
}

void RESEARCH_LIST_SelectPrevious(u32 a0)
{
    RESEARCH_LIST_SetEntryPaletteActive(a0, ((struct ResearchTop *)a0)->selectionMode);
    RESEARCH_LIST_FlipSelectionMode((void *)a0, -1);
    RESEARCH_LIST_SetEntryPaletteIdle(a0, ((struct ResearchTop *)a0)->selectionMode);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_LIST_StartListPaletteAnime((char *)a0, 4);
}

void RESEARCH_LIST_SelectNext(u32 a0)
{
    RESEARCH_LIST_SetEntryPaletteActive(a0, ((struct ResearchTop *)a0)->selectionMode);
    RESEARCH_LIST_FlipSelectionMode((void *)a0, 1);
    RESEARCH_LIST_SetEntryPaletteIdle(a0, ((struct ResearchTop *)a0)->selectionMode);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_LIST_StartListPaletteAnime((char *)a0, 4);
}

void RESEARCH_LIST_SetSelectionMode(u32 a0, u32 a1)
{
    RESEARCH_LIST_SetEntryPaletteActive(a0, ((struct ResearchTop *)a0)->selectionMode);
    RESEARCH_LIST_SetSelectionModeField((void *)a0, a1);
    RESEARCH_LIST_SetEntryPaletteIdle(a0, ((struct ResearchTop *)a0)->selectionMode);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_LIST_StartListPaletteAnime((char *)a0, 4);
}

/*
 * arity: BC400 forwards entry r0 into BC3F8, so retain supplied argument despite legacy void. BC3EC overwrites r1 with 24 and tail-calls signed division; legacy trailing a1 neither read nor forwarded.
 */
void RESEARCH_LIST_ScrollSelectionIntoView(u8 *p)
{
    int low, high, left, right;
    u8 index;
    low = RESEARCH_LIST_GetScrollMin();
    high = RESEARCH_LIST_GetScrollMax();
    left = RESEARCH_LIST_EntryIndexToY(p[0x32]);
    right = RESEARCH_LIST_EntryIndexToYBottom(p[0x32]);
    if (right <= low) {
        index = RESEARCH_LIST_DivideByEntryHeight(right + 1);
        if (((struct ResearchTop *)p)->cursorVisible) RESEARCH_LIST_SelectEntry((unsigned)p, index);
        else RESEARCH_LIST_SetCursorSlot(p, index);
    }
    if (high <= left) {
        index = RESEARCH_LIST_DivideByEntryHeight(left - 1);
        if (((struct ResearchTop *)p)->cursorVisible) RESEARCH_LIST_SelectEntry((unsigned)p, index);
        else RESEARCH_LIST_SetCursorSlot(p, index);
    }
}

void RESEARCH_LIST_SelectEntry(u32 a0, u8 a1)
{
    RESEARCH_LIST_HideCursor((u8 *)a0);
    RESEARCH_LIST_SetCursorSlot((void *)a0, a1);
    RESEARCH_LIST_ShowCursor((u8 *)a0);
    GFL_USE_PlaySeDefaultVolume(1352);
    RESEARCH_LIST_StartListPaletteAnime((char *)a0, 1);
}

/*
 * Reconstructed from the listing.
 *
 * evidence: RESEARCH_LIST_StartPaletteAnime is ov217's own code ("ldr r0, [r0]; ldr r3,
 * =RESEARCH_COMMON_StartPaletteAnime; bx r3" after the pop at 0x021BC570), inside ov217's window,
 * so only ov217 can be resident there when this pool word is used.  Its start
 * is seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov217's own listing.  The old
 * hint ov209 named a different overlay's function mapped over the address.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_StartEntryPaletteAnime(u32 a0)
{
    RESEARCH_LIST_StartPaletteAnime((u8 **)a0, 0);
}

void RESEARCH_LIST_ComputeOpenScroll(u8 *p)
{
    int start, end, low, high, step, low2, high2;
    start = ((struct ResearchTop *)p)->scrollY;
    if (p[0x32] < p[0x33]) end = RESEARCH_LIST_EntryIndexToYBottom(p[0x33]) + 1;
    else end = RESEARCH_LIST_EntryIndexToY(p[0x33]);
    low = RESEARCH_LIST_GetScrollMin();
    high = RESEARCH_LIST_GetScrollMax();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 4;
    low2 = RESEARCH_LIST_GetScrollMin();
    high2 = RESEARCH_LIST_GetScrollMax();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 0;
    RESEARCH_LIST_StartScrollAnim(p, start, end, step);
}

void RESEARCH_LIST_ComputeReturnScroll(u8 *p)
{
    int start, end, step, low, high, low2, high2;
    start = ((struct ResearchTop *)p)->scrollY;
    end = start;
    if ((int)RESEARCH_LIST_GetScrollRangeMax(p) < start) end = RESEARCH_LIST_GetScrollRange(p) + 24;
    else if (start < 0) end = 144;
    low = RESEARCH_LIST_GetScrollMin();
    high = RESEARCH_LIST_GetScrollMax();
    if (end < low || high < end) {
        if (start < end) start = high;
        else start = low;
    }
    step = ((start >= end ? start : end) - (start <= end ? start : end)) / 3;
    low2 = RESEARCH_LIST_GetScrollMin();
    high2 = RESEARCH_LIST_GetScrollMax();
    if (low2 <= start && start <= high2 && low2 <= end && end <= high2) step = 1;
    RESEARCH_LIST_StartScrollAnim(p, start, end, step);
}

void RESEARCH_LIST_ComputeCenterScroll(u8 *p)
{
    int center, target, start, end;
    center = (int)(RESEARCH_LIST_GetScrollMin() + RESEARCH_LIST_GetScrollMax()) / 2;
    target = RESEARCH_LIST_GetRowBase((unsigned)p, p[0x32]) * 8;
    if (center < target) {
        start = RESEARCH_LIST_GetScrollMax();
        end = (target - center) + RESEARCH_LIST_GetScrollMax();
    } else {
        start = RESEARCH_LIST_GetScrollMin();
        end = RESEARCH_LIST_GetScrollMin() - (center - target);
    }
    RESEARCH_LIST_StartScrollAnim(p, start, end, ((start >= end ? start : end) - (start <= end ? start : end)) / 3);
}

u8 RESEARCH_LIST_FindSaveIndex(u8 *p)
{
    u8 values[3];
    int i;
    void *data;
    u8 a, b, c, index;
    data = SYMBOL_SAVE_GetBitBlock(GAME_DATA_GetSaveControl((struct Big *)RESEARCH_LIST_GetAppResource(p)));
    for (i = 0; i < 3; i++) values[i] = MISC_SAVEDATA_GetStatusByte((int)data, i);
    a = values[0];
    b = values[1];
    c = values[2];
    for (index = 0; index < 10; index++)
        if (a == d_021C30A8[index] && b == d_021C3080[index] && c == d_021C308A[index]) return index;
    return 0;
}

/*
 * blocker C: typedef unsigned char u8; void SYMBOL_SAVE_SetBitDescriptor(u8 *p,int value,int index) { (p+index)[640]=value; }
 * arity: BC628 returns C09B4's +8 pointer; E394 returns 071CC's pointer, both used live despite legacy void declarations.
 */
void RESEARCH_LIST_StoreSaveValues(u8 *p)
{
    u32 index;
    int data;
    index=RESEARCH_LIST_GetSelectedIndex(p);
    data=(int)SYMBOL_SAVE_GetBitBlock((void *)((int)GAME_DATA_GetSaveControl((struct Big *)RESEARCH_LIST_GetAppResource(p))));
    SYMBOL_SAVE_SetBitDescriptor((u8 *)data,d_021C30A8[index],0);
    SYMBOL_SAVE_SetBitDescriptor((u8 *)data,d_021C3080[index],1);
    SYMBOL_SAVE_SetBitDescriptor((u8 *)data,d_021C308A[index],2);
}

/*
 * Advance the u32 at +0x2c by the argument plus two, reduced modulo two.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_FlipSelectionMode(void *p, s32 v)
{
    *(s32 *)&((struct ResearchTop *)p)->selectionMode = (*(s32 *)&((struct ResearchTop *)p)->selectionMode + v + 2) % 2;
}

/*
 * Field setter, u32 at +0x2c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_SetSelectionModeField(void *p, u32 v)
{
    ((struct ResearchTop *)p)->selectionMode = v;
}

void RESEARCH_LIST_SetEntryPaletteIdle(int a, int b)
{
    BMP_OAM_SetPalette((u8 *)RESEARCH_LIST_GetOamObject((char *)a, b), 0);
}

void RESEARCH_LIST_SetEntryPaletteActive(int a, int b)
{
    BMP_OAM_SetPalette((u8 *)RESEARCH_LIST_GetOamObject((char *)a, b), 1);
}

/*
 * Field setter, u8 at +0x32.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_SetCursorSlot(void *p, u8 v)
{
    ((struct ResearchTop *)p)->cursorSlot = v;
}

void RESEARCH_LIST_AdvanceEndIndex(u8 *p, int a)
{
    int base = p[0x32];
    int x = (int)RESEARCH_LIST_GetEntryCount(p);
    int s = base + a;
    p[0x33] = (u8)((s + x) % (int)RESEARCH_LIST_GetEntryCount(p));
}

void RESEARCH_LIST_ShowCursor(u8 *p)
{
    u8 slot;
    u32 x;
    u32 y;
    slot=p[0x32];
    x=RESEARCH_LIST_GetRowOffset((u32)p,slot);
    y=RESEARCH_LIST_GetRowBase((u32)p,slot);
    BG_SYS_FillTileMap(2,x,y,28,3,10);
    func_02041B6C(2);
    ((struct ResearchTop *)p)->cursorVisible=1;
}

void RESEARCH_LIST_HideCursor(u8 *p)
{
    u8 slot;
    u32 x;
    u32 y;
    slot=p[0x32];
    x=RESEARCH_LIST_GetRowOffset((u32)p,slot);
    y=RESEARCH_LIST_GetRowBase((u32)p,slot);
    BG_SYS_FillTileMap(2,x,y,28,3,9);
    func_02041B6C(2);
    ((struct ResearchTop *)p)->cursorVisible=0;
}

void RESEARCH_LIST_ShiftTextRight(u32 object,u32 slot)
{
    u16 *first;
    int row;
    u16 *second;
    int column;
    Index index;
    int base,destination;
    first=(u16 *)BG_SYS_GetBuf(2);
    second=(u16 *)BG_SYS_GetBuf(3);
    for(row=0;row<3;row++) {
        for(column=0;column<28;column++) {
            base=RESEARCH_LIST_GetRowBase(object,slot);
            index=column+2+(base+row)*32;
            destination=index-1;
            first[destination]=first[index];
            second[destination]=second[index];
        }
    }
    base=RESEARCH_LIST_GetRowBase(object,slot);
    first[base*32+29]=first[0];
    second[base*32+29]=second[0];
    first[(base+1)*32+29]=first[0];
    second[(base+1)*32+29]=second[0];
    first[(base+2)*32+29]=first[0];
    second[(base+2)*32+29]=second[0];
    func_02041B6C(2);
    func_02041B6C(3);
}

void RESEARCH_LIST_ShiftTextLeft(u32 object,u32 slot)
{
    u16 *first;
    int row;
    u16 *second;
    int column;
    Index index;
    int base,destination;
    first=(u16 *)BG_SYS_GetBuf(2);
    second=(u16 *)BG_SYS_GetBuf(3);
    for(row=2;row>=0;row--) {
        for(column=27;column>=0;column--) {
            base=RESEARCH_LIST_GetRowBase(object,slot);
            index=column+1+(base+row)*32;
            destination=index+1;
            first[destination]=first[index];
            second[destination]=second[index];
        }
    }
    base=RESEARCH_LIST_GetRowBase(object,slot);
    first[base*32+1]=first[0];
    second[base*32+1]=second[0];
    first[(base+1)*32+1]=first[0];
    second[(base+1)*32+1]=second[0];
    first[(base+2)*32+1]=first[0];
    second[(base+2)*32+1]=second[0];
    func_02041B6C(2);
    func_02041B6C(3);
}

/*
 * Returns 2, or 1 when RESEARCH_LIST_FindSaveIndex() reports the caller's own a1.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_LIST_GetRowOffset(u32 a0, u32 a1)
{
    u8 v = 2;
    if (a1 == RESEARCH_LIST_FindSaveIndex((u8 *)a0)) {
    v -= 1;
    }
    return v;
}

u32 RESEARCH_LIST_GetRowBase(u32 unused, u32 v)
{
    return (u8)(v * 3);
}

int RESEARCH_LIST_GetEntryScreenX(unsigned char *p, unsigned int slot)
{
    int t = RESEARCH_LIST_GetRowOffset((unsigned int)p, slot) << 3;
    return t - BG_SYS_GetChannelScrollX(2);
}

int RESEARCH_LIST_GetEntryScreenY(unsigned char *p, unsigned char index)
{
    int t = RESEARCH_LIST_GetRowBase((unsigned int)p, index) << 3;
    return t - RESEARCH_LIST_GetScrollY();
}

int RESEARCH_LIST_GetEntryScreenYBottom(unsigned char *p, unsigned int index)
{
    int t = (RESEARCH_LIST_GetRowBase((unsigned int)p, index) << 3) + 0x17;
    return t - RESEARCH_LIST_GetScrollY();
}

static inline void outside(Plane wnd,Bool effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if(effect)tmp|=32;
    *(volatile u16 *)0x0400004A=(u16)tmp;
}

static inline void inside(Plane wnd,Bool effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x04000048 & ~63u) | (u32)wnd;
    if(effect)tmp|=32;
    *(volatile u16 *)0x04000048=(u16)tmp;
}

void RESEARCH_LIST_UpdateWindowMask(u8 *p)
{
    int active;
    int top,bottom;
    int x1,x2,y1,y2;
    active=0;
    top=RESEARCH_LIST_GetEntryScreenY(p,0);
    bottom=RESEARCH_LIST_GetEntryScreenYBottom(p,9);
    if(top>0) {
        active=1;x1=0;x2=240;y1=0;y2=top-1;
    } else if(bottom<192) {
        active=1;x1=0;x2=240;y1=bottom+1;y2=192;
    }
    if(active) {
        *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000 & 0xFFFF1FFF)|0x2000;
        *(volatile u16 *)0x04000040=(u16)(((x1<<8)&0xFF00)|(x2&0xFF));
        *(volatile u16 *)0x04000044=(u16)(((y1<<8)&0xFF00)|(y2&0xFF));
        outside(PLANE_OUT,TRUE);
        inside(PLANE_IN,TRUE);
    } else {
        *(volatile u32 *)0x04000000=*(volatile u32 *)0x04000000 & 0xFFFF1FFF;
    }
}

/*
 * arity: BF28/BF3C forward entry r0/r1 to BF04/BF1C; preserve both, with observed u8 argument truncation.
 */
void RESEARCH_LIST_UpdateEntryActor(u8 *p)
{
    struct Vec2 point;
    u32 index;
    struct Obj *obj;
    index=RESEARCH_LIST_FindSaveIndex(p);
    obj=(struct Obj *)RESEARCH_LIST_GetActor(p,2);
    if(index==255) {
        CLACT_SetActorDrawEnable(obj,0);
        return;
    }
    point.x=RESEARCH_LIST_GetEntryScreenX(p,(u8)index);
    point.y=RESEARCH_LIST_GetEntryScreenY(p,index)+10;
    CLACT_AddActorSurfacePos(obj,&point,0);
    CLACT_SetActorAutoAnim(obj,1);
    CLACT_SetActorDrawEnable(obj,1);
}

int RESEARCH_LIST_PrintCurrentEntry(char *p)
{
    return RESEARCH_LIST_PrintEntryLabels((u8 *)p, ((struct ResearchTop *)p)->cursorSlot);
}

/*
 * arity: original visibly supplies r1 to C0F5C; preserve second argument omitted by legacy source.
 */
int RESEARCH_LIST_PrintEntryLabels(u8 *p, u8 index)
{
    BgTextLabel_PrintMessage(((struct ResearchTop *)p)->nameLabelA,d_021C309E[index]);
    BgTextLabel_PrintMessage(((struct ResearchTop *)p)->nameLabelB,d_021C3094[index]);
    BgTextLabel_PrintMessage(((struct ResearchTop *)p)->valueLabelA,d_021C30D0[d_021C30A8[index]]);
    BgTextLabel_PrintMessage(((struct ResearchTop *)p)->valueLabelB,d_021C30D0[d_021C3080[index]]);
    return BgTextLabel_PrintMessage(((struct ResearchTop *)p)->valueLabelC,d_021C30D0[d_021C308A[index]]);
}

void RESEARCH_LIST_HideEntryLabels(u32 a0)
{
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->nameLabelA), 0);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->nameLabelB), 0);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->valueLabelA), 0);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->valueLabelB), 0);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->valueLabelC), 0);
}

void RESEARCH_LIST_ShowEntryLabels(u32 a0)
{
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->nameLabelA), 1);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->nameLabelB), 1);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->valueLabelA), 1);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->valueLabelB), 1);
    BgTextLabel_SetVisible((u8 *)(((struct ResearchTop *)a0)->valueLabelC), 1);
}

/*
 * Packs a 0xF8 message (second halfword from RESEARCH_LIST_GetScrollbarY()) and pushes
 * it through the +0x0c channel, on the path where RESEARCH_LIST_NeedsScrollbar() is clear.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_UpdateScrollbarActor(u32 a0)
{
    u8 s[4];
    u32 v1 = RESEARCH_LIST_GetActor((void *)a0, 0);
    if (RESEARCH_LIST_NeedsScrollbar((void *)a0) == 0) {
    CLACT_SetActorDrawEnable((struct Obj *)v1, 0);
    return;
    }
    ((struct Vec2 *)s)->x = 248;
    ((struct Vec2 *)s)->y = RESEARCH_LIST_GetScrollbarY((void *)a0);
    CLACT_AddActorSurfacePos((struct Obj *)v1, (const struct Vec2 *)s, 0);
    CLACT_SetActorDrawEnable((struct Obj *)v1, 1);
}

/*
 * 021BC40C forwards live r0 to 021BC6DC's +0x30 getter despite legacy void prototype.
 */
int RESEARCH_LIST_GetScrollbarY(void *p)
{
    int scroll;
    int height;
    float top;
    float span;
    int result;
    scroll=RESEARCH_LIST_GetScrollY();
    height=RESEARCH_LIST_GetScrollRange(p);
    scroll+=24;
    height+=24;
    top=(float)scroll;
    span=(float)height;
    result=(int)(32.0f+128.0f*(top/span));
    if(result<32)result=32;
    if(result>160)result=160;
    return result;
}

int RESEARCH_LIST_GetScrollYFromPosition(void *p,int position)
{
    float ratio;
    int height;
    float zero;
    Origin origin;
    if(position<32)position=32;
    if(position>160)position=160;
    ratio=(float)(position-32)/128.0f;
    height=RESEARCH_LIST_GetScrollRange(p)+24;
    origin=ZERO;
    zero=(float)origin;
    return (int)(zero+ratio*(float)height);
}

/*
 * Accumulate +0x50 into +0x4c, zeroing the total when the product is not positive.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_UpdateMomentum(void *p)
{
    s32 a = *(u32 *)&((struct ResearchTop *)p)->momentum;
    s32 b = ((struct ResearchTop *)p)->momentumDir;
    s32 t = a + b;
    if (a * t <= 0) {
        t = 0;
    }
    *(u32 *)&((struct ResearchTop *)p)->momentum = t;
}

/*
 * Flag test: nonzero u32 at +0x4c as 1/0.
 *
 * Addresses are Black-image addresses.
 */
int RESEARCH_LIST_IsMomentumActive(void *p)
{
    if (((struct ResearchTop *)p)->momentum != 0) {
        return 1;
    }
    return 0;
}

void RESEARCH_LIST_ComputeMomentum(void *p)
{
    int a = *(u32 *)&((struct ResearchTop *)p)->scrollY;
    int b = ((struct ResearchTop *)p)->prevScrollY;
    *(u32 *)&((struct ResearchTop *)p)->momentum = a - b;
}

void RESEARCH_LIST_DampMomentum(struct ResearchTop *p)
{
    double d = p->momentum;
    int v;
    d *= 1.5;
    v = d;
    p->momentum = v;
    if (v > 9) {
        p->momentum = 9;
    } else if (v < -9) {
        p->momentum = -9;
    }
}

void RESEARCH_LIST_SetMomentumDirection(void *p)
{
    if (((struct ResearchTop *)p)->momentum < 0) {
        ((struct ResearchTop *)p)->momentumDir = 1;
    } else {
        ((struct ResearchTop *)p)->momentumDir = -1;
    }
}

void RESEARCH_LIST_StartScrollAnim(void *p, u32 a, u32 b, u32 c)
{
    ((struct ResearchTop *)p)->animStart = a;
    ((struct ResearchTop *)p)->animTarget = b;
    *(u32 *)&((struct ResearchTop *)p)->animFrames = c;
    *(u32 *)&((struct ResearchTop *)p)->animFrame = 0;
}

void RESEARCH_LIST_StepScrollAnim(struct ResearchTop *p)
{
    int base = p->animStart;
    int n = p->animFrame + 1;
    p->animFrame = n;
    RESEARCH_LIST_SetScrollValue(p, base + (p->animTargetSigned - base) * n / p->animFrames);
}

int RESEARCH_LIST_IsScrollAnimDone(void *p)
{
    if (((struct ResearchTop *)p)->animFrames > ((struct ResearchTop *)p)->animFrame) {
        return 0;
    }
    return 1;
}

void RESEARCH_LIST_SetScrollTarget(struct ResearchTop *p, int v)
{
    if (v < 0) {
        v = 0;
    }
    if ((int)RESEARCH_LIST_GetScrollRangeMax(p) < v) {
        v = (int)RESEARCH_LIST_GetScrollRangeMax(p);
    }
    p->prevScrollY = p->scrollY;
    p->scrollY = v;
}

void RESEARCH_LIST_SetScrollValue(void *p, u32 v)
{
    ((struct ResearchTop *)p)->prevScrollY = v;
    ((struct ResearchTop *)p)->scrollY = v;
}

void RESEARCH_LIST_ApplyScrollRegs(u8 *p)
{
    int position;
    int low;
    int high;
    position=((struct ResearchTop *)p)->scrollY;
    low=RESEARCH_LIST_GetScrollMin();
    high=RESEARCH_LIST_GetScrollMax();
    if(position<low) {
        position-=24;
        BG_SYS_ResetSlot(2,3,position);
        BG_SYS_ResetSlot(3,3,position);
    } else if(high<position) {
        position-=168;
        BG_SYS_ResetSlot(2,3,position);
        BG_SYS_ResetSlot(3,3,position);
    }
}

void RESEARCH_LIST_SetListScroll(struct ResearchTop *p)
{
    int v = p->scrollY - 24;
    if (v < -24) {
        v = -24;
    }
    if (RESEARCH_LIST_GetScrollRange(p) < v) {
        v = RESEARCH_LIST_GetScrollRange(p);
    }
    RESEARCH_LIST_SetScrollY(v);
}

int RESEARCH_LIST_GetScrollY(void)
{
    return func_02040804(2);
}

void RESEARCH_LIST_SetScrollY(u32 a0)
{
    BG_SYS_FillScrollArea(2, 3, a0);
    BG_SYS_FillScrollArea(3, 3, a0);
}

u32 RESEARCH_LIST_GetScrollMin(void)
{
    return RESEARCH_LIST_GetScrollY() + 24;
}

u32 RESEARCH_LIST_GetScrollMax(void)
{
    return RESEARCH_LIST_GetScrollY() + 168;
}

/*
 * Tail-call veneer: forwards arg(s) a0, 24 to func_0209C0A4.
 *
 * Addresses are Black-image addresses.
 */
int RESEARCH_LIST_DivideByEntryHeight(u32 a0)
{
    return func_0209C0A4(a0, 24);
}

/*
 * Twenty-four times the argument.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_LIST_EntryIndexToY(u32 v)
{
    return v * 24;
}

u32 RESEARCH_LIST_EntryIndexToYBottom(u32 v)
{
    return RESEARCH_LIST_EntryIndexToY(v) + 23;
}

int RESEARCH_LIST_GetScrollRange(void *p)
{
    return (int)RESEARCH_LIST_GetEntryCount(p) * 0x18 - 0xa8;
}

u32 RESEARCH_LIST_GetScrollRangeMax(void *p)
{
    return RESEARCH_LIST_GetScrollRange(p) + 168;
}

int RESEARCH_LIST_NeedsScrollbar(void *p)
{
    return (int)RESEARCH_LIST_GetEntryCount(p) * 0x18 > 0x90;
}

void RESEARCH_LIST_UpdateTouchRects(u8 *p)
{
    int i;
    int x;
    int y;
    for(i=0;i<=9;i++) {
        x=RESEARCH_LIST_GetEntryScreenX(p,(u8)i);
        y=RESEARCH_LIST_GetEntryScreenY(p,i);
        p[i*4+0x66]=x;
        p[i*4+0x67]=x+0xd8;
        p[i*4+0x64]=y;
        p[i*4+0x65]=y+0x18;
    }
}

void RESEARCH_LIST_FadeIn(void)
{
    FADE_Start(3, 16, 0, 0);
}

void RESEARCH_LIST_FadeOut(void)
{
    FADE_Start(3, 0, 16, 0);
}

/*
 * Returns 1 when ARM FADE_IsActive() is 0.
 *
 * Addresses are Black-image addresses.
 */
int RESEARCH_LIST_IsFadeDone(void)
{
    return FADE_IsActive() == 0;
}

void RESEARCH_LIST_ShowEntryPalette(char *p)
{
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->palAnm, 1, 0xBBFF, 2, 0, 10, 0, ((struct ResearchTop *)p)->paletteAnimOwner);
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->palAnm, 4, 0xCF, 2, 0, 10, 0, ((struct ResearchTop *)p)->paletteAnimOwner);
    ((struct ResearchTop *)p)->entryPaletteActive = 1;
}

void RESEARCH_LIST_HideEntryPalette(char *p)
{
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->palAnm, 1, 0xBBFF, 2, 10, 0, 0, ((struct ResearchTop *)p)->paletteAnimOwner);
    PALANM_RequestFade(*(PalAnmObj * *)&((struct ResearchTop *)p)->palAnm, 4, 0xCF, 2, 10, 0, 0, ((struct ResearchTop *)p)->paletteAnimOwner);
    ((struct ResearchTop *)p)->entryPaletteActive = 0;
}

u32 RESEARCH_LIST_IsPaletteFadeDone(u32 a0)
{
    if (PALANM_GetFadeRequestBits((const char *)(((struct ResearchTop *)a0)->palAnm)) == 0) {
    return 1;
    }
    return 0;
}

void RESEARCH_LIST_StartPaletteAnime(u8 **p, u32 i)
{
    RESEARCH_COMMON_StartPaletteAnime(*p, i);
}

void RESEARCH_LIST_StartListPaletteAnime(char *p, int i)
{
    PALETTE_ANIME_Start((u8 *)(*(int *)(p + 0x9c + i * 4)), d_021C326C[i].mode, d_021C326C[i].color);
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + (a1)*4 + 156)), (a1)*4 to PALETTE_ANIME_Stop.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_StopListPaletteAnime(u8 *a0, int a1)
{
    PALETTE_ANIME_Stop((u32)(*(u32*)(a0 + (a1)*4 + 156)));
}

/*
 * Reports whether the a1-th entry of the +0x9c handle array is still
 * active.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_LIST_IsListPaletteAnimeRunning(u32 a0, u32 a1)
{
    if (PALETTE_ANIME_IsRunning(*(u32*)(((u8*)a0 + ((u32)a1 << 2) + 156))) == 0) {
    return 1;
    }
    return 0;
}

void RESEARCH_LIST_UpdatePaletteAnimes(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Update(p[i + 0x27]);
}

void RESEARCH_LIST_UpdateCommonPaletteAnime(u8 *a0)
{
    RESEARCH_COMMON_UpdatePaletteAnime((u32)(((struct ResearchTop *)a0)->owner));
}

u32 RESEARCH_LIST_GetKeyRepeatTimer(void *p)
{
    return ((struct ResearchTop *)p)->keyRepeatTimer;
}

/*
 * Increment the u32 at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_IncKeyRepeatTimer(void *p)
{
    u32 *c = (u32 *)((char *)p + 0x54);
    *c += 1;
}

/*
 * Clear the u32 at +0x54.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_ClearKeyRepeatTimer(void *p)
{
    ((struct ResearchTop *)p)->keyRepeatTimer = 0;
}

void RESEARCH_LIST_VBlankHandler(u32 a0, u32 a1)
{
    BG_SYS_Update();
    CLACT_VBlankSystem();
    PALANM_TransferPalettes((struct S02021D50 *)(((struct ResearchTop *)a1)->palAnm));
}

u32 RESEARCH_LIST_GetAppResource(u8 *a0)
{
    return RESEARCH_COMMON_GetAppResource((void *)((u32)(((struct ResearchTop *)a0)->owner)));
}

/*
 * Field setter, u16 at +8.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_SetHeapId(void *p, u32 v)
{
    ((struct ResearchTop *)p)->heapId = v;
}

/*
 * Field setter, u32 at +0.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_SetOwner(void *p, u32 v)
{
    ((struct ResearchTop *)p)->owner = v;
}

u32 RESEARCH_LIST_GetOwner(void *p)
{
    return (u32)((struct ResearchTop *)p)->owner;
}

/*
 * Field setter, u32 at +4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_SetListView(void *p, u32 v)
{
    ((struct ResearchTop *)p)->listViewU = v;
}

void RESEARCH_LIST_SyncFromListView(struct ResearchTop *p)
{
    int v;
    if (p->listView != 0) {
        v = ListViewState_GetScrollY(p->listView);
        if (v < -24) {
            v = -24;
        }
        if (v > 72) {
            v = 72;
        }
        RESEARCH_LIST_SetScrollY(v);
        v = ListViewState_GetScrollX(p->listView);
        if (v < 0) {
            v = 0;
        }
        if (v > 240) {
            v = 240;
        }
        p->scrollY = v;
        p->cursorSlot = ListViewState_GetMode(p->listView);
    }
}

/*
 * Extent ends in two zero alignment bytes at 021BC6CE.
 * 021BC3AC is void in its source but forwards to 02040804. Original reads
 * r0 as a signed coordinate, so declare int and preserve its visible input.
 */
void RESEARCH_LIST_SyncToListView(char *p)
{
    int y;
    if (*(u32 *)&((struct ResearchTop *)p)->listView != 0) {
        y = RESEARCH_LIST_GetScrollY();
        if (y < -24) y = -24;
        if (y > 72) y = 72;
        ListViewState_SetScrollY(((struct ResearchTop *)p)->listView, y);
        y = ((struct ResearchTop *)p)->scrollY;
        if (y < 0) y = 0;
        if (y > 240) y = 240;
        ListViewState_SetScrollX(((struct ResearchTop *)p)->listView, y);
        ListViewState_SetMode(((struct ResearchTop *)p)->listView, ((struct ResearchTop *)p)->cursorSlot);
    }
}

u32 RESEARCH_LIST_GetInputFlag(void *p)
{
    return RESEARCH_COMMON_GetInputFlag((void *)RESEARCH_LIST_GetOwner(p));
}

u32 RESEARCH_LIST_GetEntryCount(void *p)
{
    return ((struct ResearchTop *)p)->entryCount;
}

/*
 * Field getter, u8 at +0x31.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_LIST_GetSelectedIndex(void *p)
{
    return ((struct ResearchTop *)p)->selectedIndex;
}

void RESEARCH_LIST_SetSelectedIndex(void *p, u8 v)
{
    ((struct ResearchTop *)p)->selectedIndex = v;
}

u32 RESEARCH_LIST_IsValidIndex(u32 a0, u32 a1)
{
    if (a1 < RESEARCH_LIST_GetEntryCount((void *)a0)) {
    return 1;
    }
    return 0;
}

/*
 * Indexed u32 read: element i of the table at +0xf8.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_LIST_GetResourceId(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0xf8);
}

/*
 * Indexed u32 read: element i of the table at +0x114.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_LIST_GetClactUnit(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x114);
}

u32 RESEARCH_LIST_GetActor(void *p, u32 i)
{
    return *(u32 *)((char *)p + i * 4 + 0x120);
}

void RESEARCH_LIST_SetOamEnabled(u8 *a0, u32 a1, u8 *a2)
{
    BMP_OAM_SetEnabled((u8 *)((u32)(*(u32*)(a0 + (a1)*4 + 304))), (u32)(a2 + 0));
}

int RESEARCH_LIST_GetOamObject(char *p, int i)
{
    return *(int *)(p + (d_021C3068[i] << 2) + 0x130);
}

u32 RESEARCH_LIST_Alloc(u32 a0)
{
    return (u32)func_02030734(a0, 364, 0, (const char *)0x21C3FFC, 3687);
}

/*
 * Extent ends in two zero alignment bytes at 021BC816.
 */
void RESEARCH_LIST_InitFields(u8 *p)
{
    ((struct ResearchTop *)p)->listViewU = 0;
    ((struct ResearchTop *)p)->state = 0;
    ((struct ResearchTop *)p)->stateTimer = 0;
    ((struct ResearchTop *)p)->commandReady = 0;
    ((struct ResearchTop *)p)->fadeWaitFrames = 15;
    p[0x32] = 0;
    p[0x33] = 0;
    p[0x30] = 0;
    ((struct ResearchTop *)p)->selectionMode = 0;
    p[0x31] = 255;
    ((struct ResearchTop *)p)->paletteAnimOwnerU = func_020056BC();
    ((struct ResearchTop *)p)->scrollY = 0;
    ((struct ResearchTop *)p)->prevScrollY = 0;
    ((struct ResearchTop *)p)->animStart = 0;
    ((struct ResearchTop *)p)->animTarget = 0;
    ((struct ResearchTop *)p)->animFrames = 0;
    ((struct ResearchTop *)p)->animFrame = 0;
    ((struct ResearchTop *)p)->entryPaletteActive = 0;
    ((struct ResearchTop *)p)->cursorVisible = 0;
    ((struct ResearchTop *)p)->active = 0;
    ((struct ResearchTop *)p)->visible = 0;
    ((struct ResearchTop *)p)->vblankNode = 0;
    RESEARCH_LIST_ClearCommandQueue(p);
    RESEARCH_LIST_ClearMessages(p);
    RESEARCH_LIST_ClearFont(p);
    RESEARCH_LIST_ClearLabels(p);
    RESEARCH_LIST_ClearUnits(p);
    RESEARCH_LIST_ClearActors(p);
    RESEARCH_LIST_ClearResources(p);
    RESEARCH_LIST_ClearPalAnm(p);
    RESEARCH_LIST_ClearBmps(p);
    RESEARCH_LIST_ClearPaletteAnime(p);
}

/*
 * Tail-call veneer: branch to func_020307B0.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_LIST_Free(void *a0)
{
    return func_020307B0(a0);
}

void RESEARCH_LIST_CountUnlockedEntries(u8 *p)
{
    void *bitmap;
    int n;
    bitmap = (void *)GAME_DATA_GetEventWork((const struct BigObj *)RESEARCH_LIST_GetAppResource(p));
    n = 1;
    if (ZONEDATA_CheckEventFlag(bitmap, 240) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 241) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 242) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 243) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 244) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 245) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 246) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 247) == 1) n++;
    if (ZONEDATA_CheckEventFlag(bitmap, 248) == 1) n++;
    p[0x30] = n;
}

void RESEARCH_LIST_CreateFont(u32 a0)
{
    u8 s[4];
    *(u32 *)&((struct ResearchTop *)a0)->fontP = (u32)GF_FONT_Create(23, 0, 0, 0, (u32)(((struct ResearchTop *)a0)->heapId));
}

/*
 * Clear the u32 at +0xc.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_ClearFont(void *p)
{
    ((struct ResearchTop *)p)->font = 0;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 12)) to GF_FONT_Delete.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_DeleteFont(u8 *a0)
{
    GF_FONT_Delete((void *)((u32)(((struct ResearchTop *)a0)->font)));
}

void RESEARCH_LIST_CreateMessages(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        p->arr[i] = (int)func_02045B38(0, 2, (u16)d_021C3078[i], p->heapId);
    }
}

void RESEARCH_LIST_ClearMessages(void *p)
{
    int i;
    for (i = 0; i < 2; i++)
        *(u32 *)((char *)p + i * 4 + 0x10) = 0;
}

void RESEARCH_LIST_DeleteMessages(int *p)
{
    int i;
    for (i = 0; i < 2; i++)
        MSGDATA_Delete((struct Rec *)p[i + 4]);
}

void RESEARCH_LIST_CreateCommandQueue(u32 a0)
{
    ((struct ResearchTop *)a0)->commandQueue = RingQueue_Create(10, ((struct ResearchTop *)a0)->heapId);
}

/*
 * Clear the u32 at +0x18.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_ClearCommandQueue(void *p)
{
    ((struct ResearchTop *)p)->commandQueue = 0;
}

/*
 * Tail-call veneer: forwards arg(s) (u32)(*(u32*)(a0 + 24)) to RingQueue_Destroy.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_DestroyCommandQueue(u8 *a0)
{
    RingQueue_Destroy((void *)((u32)(((struct ResearchTop *)a0)->commandQueue)));
}

/*
 * Pool +94 names 021C3190; no cross-overlay loading proof. Drop contested
 * ov217 token to use the sole-ref/data witness without swapping tables.
 */
void RESEARCH_LIST_InitTables(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p[i * 4 + 0x5A] = d_021C30B2[i * 4];
        p[i * 4 + 0x5B] = d_021C30B2[i * 4 + 1];
        p[i * 4 + 0x58] = d_021C30B2[i * 4 + 2];
        p[i * 4 + 0x59] = d_021C30B2[i * 4 + 3];
    }
    for (i = 0; i < 11; i++) {
        p[i * 4 + 0x66] = d_021C3190[i * 4];
        p[i * 4 + 0x67] = d_021C3190[i * 4 + 1];
        p[i * 4 + 0x64] = d_021C3190[i * 4 + 2];
        p[i * 4 + 0x65] = d_021C3190[i * 4 + 3];
    }
    for (i = 0; i < 2; i++) {
        p[i * 4 + 0x92] = d_021C3070[i * 4];
        p[i * 4 + 0x93] = d_021C3070[i * 4 + 1];
        p[i * 4 + 0x90] = d_021C3070[i * 4 + 2];
        p[i * 4 + 0x91] = d_021C3070[i * 4 + 3];
    }
}

void RESEARCH_LIST_InitBackgrounds(char *p)
{
    BG_SYS_SetGraphicsMode(&d_021C30C0);
    BG_SYS_InitBgLayer(6, &d_021C3110, 0);
    BG_SYS_InitBgLayer(7, &d_021C3130, 0);
    BG_SYS_InitBgLayer(0, &d_021C30F0, 0);
    BG_SYS_InitBgLayer(2, &d_021C3150, 0);
    BG_SYS_InitBgLayer(3, &d_021C3170, 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
    func_02040588(1, 1);
    func_02040588(0, 1);
    func_02040588(2, 1);
    func_02040588(3, 1);
    func_0207D63C((volatile unsigned *)0x04001050, 2, 1, 16, 5);
    func_0207D63C((volatile unsigned *)0x04000050, 4, 2, 16, 5);
    BMP_WIN_Init(((struct ResearchTop *)p)->heapId);
}

u32 RESEARCH_LIST_ExitBackgrounds(u8 *a0)
{
    BMP_WIN_Exit();
    BG_SYS_FreeLayerBuf(3);
    BG_SYS_FreeLayerBuf(2);
    BG_SYS_FreeLayerBuf(0);
    BG_SYS_FreeLayerBuf(7);
    return BG_SYS_FreeLayerBuf(6);
}

/*
 * Original narrows the heap before 020490F4; its extern takes u16.
 */
void RESEARCH_LIST_LoadBackground6(char *p)
{
    void *arc;
    void *buf;
    void *screen;
    arc = func_020490F4(192, (u16)((((struct ResearchTop *)p)->heapId & 0x7FFF) | 0x8000));
    buf = ARC_TOOL_LoadHandleMember(arc, 13, ((struct ResearchTop *)p)->heapId);
    NNS_G2dGetUnpackedScreenData(buf, &screen);
    BG_SYS_DrawTile(6, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_02041B6C(6);
    func_020307B0(buf);
    ARC_TOOL_DeleteHandle(arc);
}

void RESEARCH_LIST_DummyBg7(u8 *a0)
{
}

u32 RESEARCH_LIST_UpdateBackground7(u32 a0)
{
    BG_SYS_Init(7, 0, 1, 0);
    return BG_SYS_ClearSlot(7);
}

void RESEARCH_LIST_ShowBackground7(u32 a0)
{
    BG_SYS_SetTileUnit(7, 1, 0);
}

void RESEARCH_LIST_LoadBackground2(char *p)
{
    void *arc;
    void *buf;
    void *screen;
    arc = func_020490F4(192, (u16)((((struct ResearchTop *)p)->heapId & 0x7FFF) | 0x8000));
    buf = ARC_TOOL_LoadHandleMember(arc, 3, ((struct ResearchTop *)p)->heapId);
    NNS_G2dGetUnpackedScreenData(buf, &screen);
    BG_SYS_DrawTile(0, (u32)((char *)screen + 12), 0, 0, 32, 24);
    func_02041B6C(0);
    func_020307B0(buf);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * Empty stub.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_DummyBg3(u8 *a0)
{
}

void RESEARCH_LIST_LoadListBackground(struct ResearchTop *p)
{
    void *heap = func_020490F4(0xc0, (u16)((p->heapId & 0x7fff) | 0x8000));
    int v = RESEARCH_LIST_GetEntryCount(p) * 3;
    void *res = ARC_TOOL_LoadHandleMember(heap, 5, p->heapId);
    char *q;
    NNS_G2dGetUnpackedScreenData(res, (void **)(&q));
    BG_SYS_DrawTile(2, (u32)(q + 0xc), 0, 0, 0x20, (u8)v);
    func_02041B6C(2);
    func_020307B0(res);
    ARC_TOOL_DeleteHandle(heap);
}

void RESEARCH_LIST_DummyListBg(u8 *a0)
{
}

u32 RESEARCH_LIST_UpdateBackground3(u32 a0)
{
    BG_SYS_Init(3, 0, 1, 0);
    return BG_SYS_ClearSlot(3);
}

void RESEARCH_LIST_ShowBackground3(u32 a0)
{
    BG_SYS_SetTileUnit(3, 1, 0);
}

void RESEARCH_LIST_CreateLabels(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        const struct LabelEntry *e = &d_021C33C8[i];
        struct Loc l1;
        l1.b0 = e->b0;
        l1.b1 = e->b1;
        l1.b2 = e->b2;
        l1.b3 = e->b3;
        l1.b4 = e->b4;
        l1.b5 = e->b5;
        l1.b6 = e->b6;
        l1.b7 = e->b7;
        l1.b8 = e->b8;
        l1.b9 = e->b9;
        l1.b10 = e->b10;
        l1.w = e->w;
        p->arr[0xdc / 4 - 4 + i] = (u32)BgTextLabel_Create((const struct Config *)(&l1), (u32)p->font, p->arr[e->idx], p->heapId);
        BgTextLabel_PrintMessage(p->arr[0xdc / 4 - 4 + i], e->arg);
    }
    for (i = 0; i < (int)RESEARCH_LIST_GetEntryCount(p); i++) {
        const struct LabelEntry *e = &d_021C3520[i];
        struct Loc l2;
        l2.b0 = e->b0;
        l2.b1 = e->b1;
        l2.b2 = e->b2;
        l2.b3 = e->b3;
        l2.b4 = e->b4;
        l2.b5 = e->b5;
        l2.b6 = e->b6;
        l2.b7 = e->b7;
        l2.b8 = e->b8;
        l2.b9 = e->b9;
        l2.b10 = e->b10;
        l2.w = e->w;
        p->arr[0xb4 / 4 - 4 + i] = (u32)BgTextLabel_Create((const struct Config *)(&l2), (u32)p->font, p->arr[e->idx], p->heapId);
        BgTextLabel_PrintMessage(p->arr[0xb4 / 4 - 4 + i], e->arg);
    }
}

/*
 * Clear seven u32 slots at +0xdc, then ten at +0xb4.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_ClearLabels(void *p)
{
    int i;
    for (i = 0; i < 7; i++)
        *(u32 *)((char *)p + i * 4 + 0xdc) = 0;
    for (i = 0; i < 10; i++)
        *(u32 *)((char *)p + i * 4 + 0xb4) = 0;
}

void RESEARCH_LIST_DestroyLabels(u8 *p)
{
    int i;
    for (i = 0; i < 7; i++) {
        BgTextLabel_Destroy(*(u8 **)(p + i * 4 + 0xDC));
        *(u32 *)(p + i * 4 + 0xDC) = 0;
    }
    for (i = 0; i < (int)RESEARCH_LIST_GetEntryCount(p); i++) {
        BgTextLabel_Destroy(*(u8 **)(p + i * 4 + 0xB4));
        *(u32 *)(p + i * 4 + 0xB4) = 0;
    }
}

void RESEARCH_LIST_ClearResources(void *p)
{
    int i;
    for (i = 0; i < 7; i++)
        *(u32 *)((char *)p + i * 4 + 0xf8) = 0;
}

/*
 * 0204ABF0 is void in its source but forwards to the int-returning
 * 0204AC18; the original stores its live r0 result. 020490F4 narrows heap.
 */
void RESEARCH_LIST_RegisterEntryResources(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c;
    heap = ((struct ResearchTop *)p)->heapId;
    arc = func_020490F4(192, (u16)((heap & 0x7FFF) | 0x8000));
    a = CLACT_RegisterCharacter((void *)((u32)arc), 15, 0, 1, heap);
    b = CLACT_RegisterPalette((void *)arc, 16, 1, 0, heap);
    c = CLACT_RegisterCellAnim((void *)((u32)arc), 14, 17, heap);
    ((struct ResearchTop *)p)->entryCharacter = a;
    ((struct ResearchTop *)p)->entryPalette = b;
    ((struct ResearchTop *)p)->entryCell = c;
    ARC_TOOL_DeleteHandle(arc);
}

u32 RESEARCH_LIST_ReleaseEntryResources(u32 a0)
{
    CLACT_ReleaseCharacter(((struct ResearchTop *)a0)->entryCharacter);
    CLACT_ReleasePalette(((struct ResearchTop *)a0)->entryPalette);
    return CLACT_ReleaseCellAnim(((struct ResearchTop *)a0)->entryCell);
}

void RESEARCH_LIST_RegisterCursorResources(char *p)
{
    u16 heap;
    void *arc;
    int a, b, c, d;
    heap = ((struct ResearchTop *)p)->heapId;
    arc = func_020490F4(192, (u16)((heap & 0x7FFF) | 0x8000));
    a = CLACT_RegisterCharacter((void *)((u32)arc), 15, 0, 0, heap);
    b = CLACT_RegisterPaletteEx((void *)((u32)arc), 16, 0, 192, 0, 4, heap);
    c = CLACT_RegisterCellAnim((void *)((u32)arc), 14, 17, heap);
    ARC_TOOL_DeleteHandle(arc);
    arc = func_020490F4(83, (u16)heap);
    d = CLACT_RegisterPaletteEx((void *)((u32)arc), 31, 0, 128, 0, 2, heap);
    ARC_TOOL_DeleteHandle(arc);
    ((struct ResearchTop *)p)->cursorCharacter = a;
    ((struct ResearchTop *)p)->cursorPalette = b;
    ((struct ResearchTop *)p)->cursorCell = c;
    ((struct ResearchTop *)p)->cursorEffectPalette = d;
}

u32 RESEARCH_LIST_ReleaseCursorResources(u32 a0)
{
    CLACT_ReleaseCharacter(((struct ResearchTop *)a0)->cursorCharacter);
    CLACT_ReleasePalette(((struct ResearchTop *)a0)->cursorPalette);
    CLACT_ReleaseCellAnim(((struct ResearchTop *)a0)->cursorCell);
    return CLACT_ReleasePalette(((struct ResearchTop *)a0)->cursorEffectPalette);
}

void RESEARCH_LIST_ClearUnits(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x114) = 0;
}

void RESEARCH_LIST_CreateUnits(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 3; i++) {
        p->units[i] = (int)CLACT_CreateUnit(d_021C3060[i], d_021C305C[i], p->heapId);
    }
}

void RESEARCH_LIST_DeleteUnits(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        CLACT_DeleteUnit((struct Bank *)p[i + 0x45]);
}

void RESEARCH_LIST_ClearActors(void *p)
{
    int i;
    for (i = 0; i < 3; i++)
        *(u32 *)((char *)p + i * 4 + 0x120) = 0;
}

/*
 * Lever: const source table and destination base without the field offset.
 */
void RESEARCH_LIST_CreateActors(u8 *p)
{
    struct Arg arg;
    const struct ActorDef *q;
    u8 *dest;
    int i;
    u32 a,b,c,d;
    for (i=0;i<3;i++) {
        q=&d_021C320C[i];
        arg.x=q->x; arg.y=q->y; arg.z=q->z; arg.a=q->a; arg.b=q->b;
        a=RESEARCH_LIST_GetClactUnit(p,q->c);
        b=RESEARCH_LIST_GetResourceId(p,q->d);
        c=RESEARCH_LIST_GetResourceId(p,q->e);
        d=RESEARCH_LIST_GetResourceId(p,q->f);
        dest=p+i*4;
        ((struct ResearchTop *)p)->actorHandles[i]=(void *)CLACT_CreateActor((void *)a,b,c,d,&arg,q->g,((struct ResearchTop *)p)->heapId);
        CLACT_SetActorDrawEnable((struct Obj *)((struct ResearchTop *)p)->actorHandles[i],0);
    }
}

void RESEARCH_LIST_DeleteActors(int *p)
{
    int i;
    for (i = 0; i < 3; i++)
        CLACT_DeleteActor((struct Obj *)p[i + 0x48]);
}

void RESEARCH_LIST_ClearBmps(void *p)
{
    int i;
    for (i = 0; i < 4; i++)
        *(u32 *)((char *)p + i * 4 + 0x140) = 0;
}

void RESEARCH_LIST_CreateBmps(struct ResearchTop *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        p->bmps[i] = (void *)BMP_Create(d_021C3470[i].x, d_021C3470[i].y, d_021C3470[i].z, p->heapId);
    }
}

void RESEARCH_LIST_DrawBmps(u8 *p)
{
    const struct BmpDef *q;
    struct Bmp *bmp;
    void *text;
    u16 color;
    u8 *dest;
    int i;
    for(i=0;i<4;i++) {
        q=&d_021C3470[i];
        if(q->enabled) {
            bmp=BMP_CreateFromArchive(q->arc,q->member,0,((struct ResearchTop *)p)->heapId);
            dest=p+i*4;
            BMP_Blit(bmp,((struct ResearchTop *)p)->bmps[i],0,0,0,0,q->x<<3,q->y<<3,q->b);
            color=((q->r&31)<<10)|((q->g&31)<<5)|(q->b&31);
            text=func_02045EC0(*(struct MsgBank **)(p+16+q->bank*4),q->index);
            PRINTSYS_PrintColor(((struct ResearchTop *)p)->bmps[i],q->px,q->py,text,((struct ResearchTop *)p)->fontP,color);
            func_020307B0(text);
            BMP_Delete((struct Bmp *)((int)bmp));
        }
    }
}

/*
 * Base address held in a u32 local and cast per use (reloads the pool word at each site); colour expression a | (c | b).
 */
void RESEARCH_LIST_DrawBadgeA(struct ResearchTop *p)
{
    u32 gb = (u32)&d_021C349C;
    struct Tab tab = d_021C3350;
    int i;
    int j;
    void *heap;
    void *res;
    u16 color;
    heap = BMP_CreateFromArchive(GB->f20, GB->f24, 0, p->heapId);
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 10; j++) {
            BMP_Blit(heap, p->bmps[1], (tab.v[i][j] % 3) * 8, (tab.v[i][j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    BMP_Delete(heap);
    color = (GB->f1e & 0x1f) | (((GB->f1c & 0x1f) << 10) | ((GB->f1d & 0x1f) << 5));
    res = func_02045EC0((void *)p->arr[GB->f0c], GB->f10);
    PRINTSYS_PrintColor(p->bmps[1], (s16)GB->f14, (s16)GB->f18, res, (void *)p->font, color);
    func_020307B0(res);
}

/*
 * Same lever as 021BD178: u32 base local cast per use, colour a | (c | b).
 */
void RESEARCH_LIST_DrawBadgeB(struct ResearchTop *p)
{
    u32 gb = (u32)&d_021C34C8;
    struct Tab tab = d_021C32D8;
    int i;
    int j;
    void *heap;
    void *res;
    u16 color;
    heap = BMP_CreateFromArchive(GB->f20, GB->f24, 0, p->heapId);
    for (i = 0; i < 3; i++) {
        int y = i * 8;
        for (j = 0; j < 10; j++) {
            BMP_Blit(heap, p->bmps[2], (tab.v[i][j] % 3) * 8, (tab.v[i][j] / 3) * 8, j * 8, y, 8, 8, 0);
        }
    }
    BMP_Delete(heap);
    color = (GB->f1e & 0x1f) | (((GB->f1c & 0x1f) << 10) | ((GB->f1d & 0x1f) << 5));
    res = func_02045EC0((void *)p->arr[GB->f0c], GB->f10);
    PRINTSYS_PrintColor(p->bmps[2], (s16)GB->f14, (s16)GB->f18, res, (void *)p->font, color);
    func_020307B0(res);
}

void RESEARCH_LIST_DeleteBmps(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        BMP_Delete(((struct ResearchTop *)p)->bmps[i]);
}

void RESEARCH_LIST_CreateOamSys(char *p)
{
    int i = 0x47;
    *(void **)(p + (i << 2) + 0x10) =
        BMP_OAM_CreateSys(((struct ResearchTop *)p)->heapId, *(void **)(p + (i << 2)));
}

void RESEARCH_LIST_DeleteOamSys(u8 *a0)
{
    BMP_OAM_DeleteSys((void *)((u32)(((struct ResearchTop *)a0)->oamSys)));
}

void RESEARCH_LIST_CreateOamObjects(u8 *p)
{
    int sysOff,outOff,callOff,uploadOff;
    struct Param param;
    int i;
    const struct OamDef *q;
    u8 *dest;
    sysOff=0x12C;
    outOff=0x130;
    callOff=0x130;
    uploadOff=0x130;
    for(i=0;i<4;i++) {
        dest=p+i*4;
        param.bmp=((struct ResearchTop *)p)->bmps[i];
        q=&d_021C31BC[i];
        param.x=q->x; param.y=q->y;
        param.f8=RESEARCH_LIST_GetResourceId(p,q->f8);
        param.fc=q->fc;
        param.f10=q->f10; param.f11=q->f11;
        param.f12=q->f12; param.f14=q->f14;
        *(struct Grid **)(dest+outOff)=BMP_OAM_Create(*(struct Sys **)(p+sysOff),&param);
        BMP_OAM_SetEnabled(*(u8 **)(dest+callOff),0);
        BMP_OAM_UploadChars(*(struct Obj **)(dest+uploadOff));
    }
}

void RESEARCH_LIST_DeleteOamObjects(int *p)
{
    int i;
    for (i = 0; i < 4; i++)
        BMP_OAM_Delete((struct Grid *)p[i + 0x4C]);
}

void RESEARCH_LIST_ClearPalAnm(void *p)
{
    ((struct ResearchTop *)p)->palAnm = 0;
}

void RESEARCH_LIST_CreatePalAnm(u8 *p)
{
    *(struct PalAnmSlot * *)&((struct ResearchTop *)p)->palAnm = PALANM_Create(((struct ResearchTop *)p)->heapId);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->palAnm, 0, 512, ((struct ResearchTop *)p)->heapId);
    PALANM_AllocSlotBuffers(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->palAnm, 2, 512, ((struct ResearchTop *)p)->heapId);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->palAnm, 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot * *)&((struct ResearchTop *)p)->palAnm, 2, 0, 512);
}

/*
 * Reconstructed from the listing (.inst decoded).
 *
 * BLOCKED at MATCH: the relocation site(s) below have no independent witness.
 *   +001E THM_CALL PALANM_Delete       -> unresolved: 02021540 (arm, from name) has no witness outside 021BD4CC..021BD4F0
 * Promote automatically when the target is matched.
 *
 * Addresses are Black-image addresses.
 */
u32 RESEARCH_LIST_DeletePalAnm(u32 a0)
{
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(((struct ResearchTop *)a0)->palAnm), 0);
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)(((struct ResearchTop *)a0)->palAnm), 2);
    return PALANM_Delete((void *)(((struct ResearchTop *)a0)->palAnm));
}

void RESEARCH_LIST_CreatePaletteAnime(char *p)
{
    int i;
    for (i = 0; i < 6; i++)
        ((int *)(p + 0x9c))[i] = PALETTE_ANIME_Create(((struct ResearchTop *)p)->heapId);
}

/*
 * Clear six u32 slots at +0x9c.
 *
 * Addresses are Black-image addresses.
 */
void RESEARCH_LIST_ClearPaletteAnime(void *p)
{
    int i;
    for (i = 0; i < 6; i++)
        *(u32 *)((char *)p + i * 4 + 0x9c) = 0;
}

void RESEARCH_LIST_DestroyPaletteAnime(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Destroy((void *)p[i + 0x27]);
}

void RESEARCH_LIST_BindPaletteAnime(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Bind((void *)p[i + 0x27], d_021C3260[i].a, d_021C3260[i].b, d_021C3260[i].c);
}

void RESEARCH_LIST_RestorePaletteAnime(int *p)
{
    int i;
    for (i = 0; i < 6; i++)
        PALETTE_ANIME_Restore((char *)p[i + 0x27]);
}

void RESEARCH_LIST_UpdateCenterActor(void *p)
{
    int obj = RESEARCH_LIST_GetActor(p, 1);
    Pos pos;
    pos.x = 0x80;
    pos.y = 0x60;
    CLACT_AddActorSurfacePos((struct Obj *)obj, (const struct Vec2 *)(&pos), 0);
    CLACT_SetActorDrawEnable((struct Obj *)obj, 1);
}

void RESEARCH_LIST_RestartNetwork(u32 a0)
{
    GFL_NET_RestartWithDefaultTimeout(1, ((struct ResearchTop *)a0)->heapId);
}

void RESEARCH_LIST_RegisterVBlank(char *p)
{
    ((struct ResearchTop *)p)->vblankNode = func_020056A0((void (*)(void))RESEARCH_LIST_VBlankHandler, p, 0);
}

void RESEARCH_LIST_UnregisterVBlank(u32 a0)
{
    func_02030EAC((struct Node *)(((struct ResearchTop *)a0)->vblankNode));
    ((struct ResearchTop *)a0)->vblankNode = 0;
}
