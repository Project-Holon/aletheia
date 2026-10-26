/*
 * file:     mystery.c
 * unit:     yes
 * function: MYSTERY_Create, MYSTERY_Delete, MYSTERY_Main, MYSTERY_InitBgHeap, MYSTERY_ExitBgHeap, MYSTERY_SetupBg, MYSTERY_CreateClact, MYSTERY_DeleteClact, MYSTERY_GetClactActor, MYSTERY_TransferPalette, MYSTERY_RotateActors, MYSTERY_ResetActorAngle, MYSTERY_CreateParticle, MYSTERY_DeleteParticle, MYSTERY_LoadParticle, MYSTERY_StartParticle, MYSTERY_IsParticleCreated, MYSTERY_TaskInitSave, MYSTERY_TaskFadeToMenu, MYSTERY_TaskExitAlbum, MYSTERY_TaskMenu, MYSTERY_TaskMenuAction, MYSTERY_TaskReceive, MYSTERY_TaskAlbum, MYSTERY_TaskAlbumView, MYSTERY_TaskNetAlbum, MYSTERY_TaskNetExit, MYSTERY_TaskCleanup, MYSTERY_TaskMessage, MYSTERY_CreateSaveMenu, MYSTERY_DeleteSaveMenu, MYSTERY_CreateCardMenu, MYSTERY_DeleteCardMenu, MYSTERY_PollCardMenu, MYSTERY_CardMenuCallback, MYSTERY_CreatePartyMenu, MYSTERY_DeletePartyMenu, MYSTERY_CreateReceivedMon, MYSTERY_InitCardView, MYSTERY_DeleteCardView, MYSTERY_StepCardView, MYSTERY_IsCardViewDone, MYSTERY_CardViewAnimScroll, MYSTERY_CardViewAnimReveal, MYSTERY_CardViewAnimFade, MYSTERY_InitScroll, MYSTERY_ClearScroll, MYSTERY_StepScroll, MYSTERY_StartScroll, MYSTERY_SetScrollParam, MYSTERY_UpdateScrollA, MYSTERY_UpdateScrollB, MYSTERY_CreateOamSprite, MYSTERY_DeleteOamSprite, MYSTERY_PollOamSprite, MYSTERY_MeasureGraChar, MYSTERY_IsCardValid, MYSTERY_SetupDisplay3d
 * address:  0x021D6660
 * region:   ov121
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
 *   GAME_DATA_Create 0x020124F4 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MYSTERY_DATA_Create 0x0200A300 thumb
 *   MYSTERY_GRAPHIC_Create 0x021D9624 thumb ov121
 *   MYSTERY_GRAPHIC_GetClactUnit 0x021D9744 thumb ov121
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   MYSTERY_UTIL_CreateTask 0x021DA854 thumb ov121
 *   MYSTERY_UTIL_CreateMenuWindow 0x021D9CA4 thumb ov121
 *   MYSTERY_UTIL_DrawMenuWindow 0x021D9FFC thumb ov121
 *   MYSTERY_NET_Create 0x021DE2A0 thumb ov121
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   ov114_id 0x00000072 data
 *   MYSTERY_NET_Delete 0x021DE2F0 thumb ov121
 *   MYSTERY_UTIL_DeleteMenuWindow 0x021D9E04 thumb ov121
 *   MYSTERY_UTIL_DeleteTask 0x021DA890 thumb ov121
 *   MYSTERY_GRAPHIC_Delete 0x021D96C4 thumb ov121
 *   MSGDATA_Delete 0x02045C04 arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   OS_ResetSystem 0x02087BCC arm
 *   GF_OVERLAY_Unload 0x02034A5C arm
 *   ov_id 0x00000072 data
 *   MYSTERY_NET_Step 0x021DE300 thumb ov121
 *   MYSTERY_UTIL_DispatchTask 0x021DA898 thumb ov121
 *   MYSTERY_GRAPHIC_Draw 0x021D9718 thumb ov121
 *   MYSTERY_GRAPHIC_DrawScene 0x021D972C thumb ov121
 *   MYSTERY_GRAPHIC_DrawEnd 0x021D9738 thumb ov121
 *   MYSTERY_UTIL_UpdateMenuWindow 0x021D9E50 thumb ov121
 *   MYSTERY_UTIL_IsWindowListDone 0x021DA2C8 thumb ov121
 *   MYSTERY_UTIL_Update 0x021DA840 thumb ov121
 *   MYSTERY_UTIL_IsTaskDone 0x021DA8AC thumb ov121
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_UploadBgCharFromHandle 0x02049658 arm
 *   ARC_UTIL_UploadBgPaletteFromHandle 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BMP_MENUWORK_LoadCharAndPltt 0x0201F5BC thumb
 *   BG_SYS_InitRun 0x02040B94 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   GFL_USE_GetRandomBelow 0x02005728 thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   MYSTERY_UTIL_BlendPalette 0x021DAAA4 thumb ov121
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   d_021DFB80 0x021DFB80 data ov121 a1
 *   PARTICLE_LoadArchiveMember  0x0205121C  arm
 *   PARTICLE_SetupSystem  0x02051230  arm
 *   PARTICLE_StartEffectWithCallback  0x020515CC  arm
 *   MYSTERY_UTIL_SetMenuMessage 0x021D9F08 thumb ov121
 *   MYSTERY_UTIL_SetTaskHandler 0x021DA8B0 thumb ov121
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   APP_ENV_IsWirelessAvailable 0x0202EB44 thumb
 *   MYSTERY_UTIL_SetListValue 0x021DA84C thumb ov121
 *   MYSTERY_NET_GetResult 0x021DE4D8 thumb ov121
 *   MYSTERY_NET_SetAction 0x021DE308 thumb ov121
 *   MYSTERY_NET_GetAction 0x021DE3E0 thumb ov121
 *   MYSTERY_NET_GetReceivedData 0x021DE4DC thumb ov121
 *   MYSTERY_NET_ImportRecords 0x021DEF6C thumb ov121
 *   MYSTERY_NET_UpdateWifiError 0x021DE500 thumb ov121
 *   MYSTERY_NET_Exit 0x021DE550 thumb ov121
 *   MYSTERY_UTIL_SetTaskArg 0x021DA8C0 thumb ov121
 *   MYSTERY_UTIL_GetTaskArg 0x021DA8C4 thumb ov121
 *   MYSTERY_UTIL_UpdateMenu 0x021DA178 thumb ov121
 *   MYSTERY_UTIL_GetMenuState 0x021D9FF8 thumb ov121
 *   KEY_GetTrg 0x020362DC arm
 *   GF_STANDARD_GetCachedDate 0x0203F4E4 arm
 *   MYSTERY_GRAPHIC_StartRender 0x021D9750 thumb ov121
 *   MYSTERY_DATA_SaveStart 0x0200A2B8 thumb
 *   MYSTERY_DATA_SaveMain 0x0200A2D8 thumb
 *   MYSTERY_GRAPHIC_StopRender 0x021D9790 thumb ov121
 *   MYSTERY_ALBUM_CreateSlotWork 0x021DCFC8 thumb ov121
 *   MYSTERY_ALBUM_CreateAlbumView 0x021DD24C thumb ov121
 *   MYSTERY_ALBUM_RequestSetup 0x021DE0AC thumb ov121
 *   MYSTERY_ALBUM_StepIntro 0x021DD9CC thumb ov121
 *   MYSTERY_ALBUM_StartIntro 0x021DDF5C thumb ov121
 *   MYSTERY_ALBUM_IsIntroIdle 0x021DE014 thumb ov121
 *   G2x_SetBlendAlpha_ 0x0207D63C arm
 *   MYSTERY_ALBUM_Create 0x021DAC18 thumb ov121
 *   MYSTERY_ALBUM_Update 0x021DAEF0 thumb ov121
 *   MYSTERY_ALBUM_GetWindowState 0x021DB008 thumb ov121
 *   MYSTERY_ALBUM_DeleteWork 0x021DAE1C thumb ov121
 *   MYSTERY_ALBUM_UpdateWindows 0x021DAFCC thumb ov121
 *   MYSTERY_DATA_HasCardSpace 0x0200A0C8 thumb
 *   MYSTERY_DATA_IsMainSave 0x0200A350 thumb
 *   PROCSYS_PushGlobal 0x020312CC arm
 *   GFL_NET_RefreshWmIconAtTopRight 0x0203D34C arm
 *   gNetSaveMainProc 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data a1
 *   MYSTERY_ALBUM_Delete 0x021DD980 thumb ov121
 *   MYSTERY_ALBUM_DeleteSlotWork 0x021DD1FC thumb ov121
 *   MYSTERY_UTIL_MarkTaskDone 0x021DA8B8 thumb ov121
 *   MYSTERY_UTIL_CreateMenu 0x021DA038 thumb ov121
 *   MYSTERY_UTIL_DeleteMenu  0x021DA148  thumb
 *   STRBUF_Create 0x020457B0 arm
 *   STRBUF_SetStringN 0x02045994 arm
 *   STRBUF_Delete 0x02045808 arm
 *   ARC_UTIL_UploadBgPaletteFromArchive 0x0204989C arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   MYSTERY_UTIL_CreateDetailWindow 0x021DA4DC thumb ov121
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   MYSTERY_UTIL_DeleteDetailWindow 0x021DA698 thumb ov121
 *   MYSTERY_UTIL_SetVoice 0x021DA6D0 thumb ov121
 *   MYSTERY_UTIL_CreateWindowList 0x021DA1BC thumb ov121
 *   d_021DF544 0x021DF544 data a4
 *   MYSTERY_UTIL_ClearWindowList 0x021DA2A8 thumb ov121
 *   MYSTERY_UTIL_DeleteWindowList 0x021DA280 thumb ov121
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   POKE_TOOL_Create 0x020173F0 thumb
 *   POKE_TOOL_CreatePersonalRnd 0x020186C8 thumb
 *   POKE_TOOL_SetupPartyParamEx 0x02017588 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKE_TOOL_SetDefaultMoves 0x02017FA8 thumb
 *   POKE_TOOL_AddMove 0x0201808C thumb
 *   POKE_TOOL_PushMove 0x020180F4 thumb
 *   POKE_TOOL_SetAbility 0x02018A00 thumb
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   MYSTATUS_GetName 0x020084F4 thumb
 *   MYSTATUS_GetSex 0x02008550 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   SAVE_EVENT_WriteWithDate 0x0202F2AC thumb
 *   POKE_TOOL_RecalcParam 0x020185C4 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKEGRA_OpenHandle 0x0202D7C8 thumb
 *   POKE_TOOL_GetBoxParam 0x020185F4 thumb
 *   POKEGRA_RegisterPalettePP 0x0202D8D0 thumb
 *   POKEGRA_RegisterCellAnimPP 0x0202D9A4 thumb
 *   POKEGRA_RegisterCgrPP 0x0202D934 thumb
 *   FILE_UTIL_Get 0x02020E60 thumb
 *   MIi_CpuClear16 0x02082A48 arm
 *   CLACT_SetActorObjMode 0x0204B688 arm
 *   d_021DF4F2 0x021DF4F2 data a2
 *   d_021DF4FC 0x021DF4FC data a4
 *   GAME_VERSION_Code 0x0209DF08 data
 *   GAME_LANGUAGE_Code 0x0209DF0C data
 *   gSpeciesNameBank 0x020A7370 data a4
 *   MYSTERY_UTIL_BlendPaletteRange 0x021DAB50 thumb ov121
 *   CLACT_SetActorSurfacePosAxis 0x0204B49C arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   CLACT_GetActorPos 0x0204B53C arm
 *   CLACT_GetActorDrawEnable 0x0204B3F4 arm
 *   CLACT_SetActorPos 0x0204B528 arm
 *   BG_SYS_ChangeScroll 0x02041EE4 arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   MYSTERY_UTIL_CreateTaskEx 0x021DA8CC thumb ov121
 *   MYSTERY_UTIL_SetActorPairColor 0x021DA9EC thumb ov121
 *   MYSTERY_UTIL_SetVec 0x021DA9F0 thumb ov121
 *   MYSTERY_UTIL_SetActorPairText 0x021DA994 thumb ov121
 *   MYSTERY_UTIL_UpdateActorPair 0x021DA978 thumb ov121
 *   MYSTERY_UTIL_DeleteActorPair 0x021DA958 thumb ov121
 *   BMP_OAM_DeleteSys 0x02025588 thumb
 *   MYSTERY_UTIL_IsMenuFinished 0x021DA9F8 thumb ov121
 *   POKEGRA_LoadCharDataPP 0x0202D6F4 thumb
 *   POKEGRA_ConvertCharTo2D 0x0202D214 thumb
 *   MYSTERY_DATA_CheckPacketCrc 0x0200A21C thumb
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021DF5E4 0x021DF5E4 data a4
 *   GFL_USE_CancelChangeAndStopBgm  0x02005D28  thumb  arm9
 *   GFL_USE_FadeOutBgm  0x02005E30  thumb  arm9
 *   MYSTERY_DATA_AddCard  0x0200A034  thumb  arm9
 *   MYSTERY_DATA_IsEventFlag  0x0200A1A8  thumb  arm9
 *   MYSTERY_DATA_SetEventFlag  0x0200A1E4  thumb  arm9
 *   MYSTERY_DATA_GetCardSlotNum  0x0200A348  thumb  arm9
 *   GAME_DATA_Delete  0x02012704  thumb  arm9
 *   MYSTERY_DATA_IsCardReceived  0x0200A104  thumb  arm9
 *   MYSTERY_DATA_Delete  0x0200A338  thumb  arm9
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 */
#include "../arm9/app_env.h"
#include "../sdk_ioreg.h"
#include "../version.h"

#define PALETTE ((void *)0x050003C0)
#define D(k) (*(u32 *)(desc+(k)))
#define H(k) (*(u16 *)(desc+(k)))
#define REG (*(volatile u16 *)REG_DISP3DCNT_ADDR)
struct Proc;
struct Big;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Rec;
struct Proc;
struct Obj;
#include "../sdk_rtc.h"
struct U16Vec;
struct Strbuf;
struct Actor;
struct Sub0200852CObj;
struct Mon;
struct Vec2;
struct Pt;
#include "../types.h"
#include "../arm9/item.h"
#include "../arm9/move.h"

typedef struct { s16 x,y,z; u8 a,b; } MysteryActorPos;

typedef struct {int y,m,d,week;} MysteryRtcDate;

typedef struct {u8 bit:1;} MysteryPacketFlag;

#include "mystery_album_types.h"
#include "mystery_util_shared_types.h"




/* Two descriptors of a window list (MYSTERY_UTIL_CreateWindowList), copied from d_021DF544. */
typedef struct { MysteryUtilMenuEntry e[2]; } MysteryPartyDesc;

typedef struct {u8 iv[6];u16 move[4];MysteryActorPos point;NNSG2dPaletteData *resdesc;} MysteryMonWork;

typedef struct {s16 x,y;} MysteryScreenPos;

/*
 * Real layouts for the ov121 mystery front end. The whole screen is one
 * 0x69C-byte proc work allocation (MysteryWork) created by MYSTERY_Create; the
 * card view, the two scrollers, the clact actor set and the received packet
 * are embedded sub-objects of it. Field offsets match the old Obj views
 * exactly, so replacing the view cast with the real struct cannot change code.
 */
typedef struct {
    u8 pad_000[0x60];
    u16 name[37];           /* 0x060 trainer name */
    u8 pad_0AA[2];
    u32 date;               /* 0x0AC packed year/month/day */
    u16 eventFlag;          /* 0x0B0 */
    u8 pad_0B2[1];
    u8 giftType;            /* 0x0B3 */
    u32 flags;              /* 0x0B4 */
    u8 pad_0B8[0x14];
    u32 crc;                /* 0x0CC */
    u16 title[253];         /* 0x0D0 */
    u8 flag2CA;             /* 0x2CA */
    u8 pad_2CB[5];
} MysteryPacket;

typedef union { void *ptr; u32 val; } MysteryPtrWord;
typedef union { void *ptr; int i; } MysteryPtrInt;
typedef union { int i; u32 val; void *ptr; } MysteryWord;

typedef struct {
    void *sys;              /* 0x00 particle system */
    u32 reserved04;
    void *buffer;           /* 0x08 archive member */
    unsigned int created;   /* 0x0C */
} MysteryParticle;

typedef struct MysteryCardView {
    u16 heap;               /* 0x000 */
    u8 pad_002[2];
    void *actor;            /* 0x004 */
    u32 done;               /* 0x008 */
    u32 palette;            /* 0x00C */
    u32 character;          /* 0x010 */
    u32 cellAnim;           /* 0x014 */
    u32 step;               /* 0x018 */
    u32 step2;              /* 0x01C */
    u32 state;              /* 0x020 */
    u16 *bgHeap;            /* 0x024 */
    struct MysteryScroll *scroll; /* 0x028 */
    void (*callback)(struct MysteryCardView *); /* 0x02C */
    u16 fade;               /* 0x030 */
    u16 paletteBuf[7][16];  /* 0x032 seven CLACT palettes */
    u8 pad_112[2];
    const MysteryPacket *desc; /* 0x114 received packet */
    MysteryParticle particle;/* 0x118 */
    s16 value;              /* 0x128 */
    s16 value2;             /* 0x12A */
} MysteryCardView;

typedef struct MysteryScroll {
    u32 active;             /* 0x000 */
    u32 enabled;
    u16 step;               /* 0x008 */
    u8 pad_00A[2];
    int scroll;             /* 0x00C */
    int value;              /* 0x010 */
    int startValue;         /* 0x014 */
    int y[32];              /* 0x018 */
    int vy[32];             /* 0x098 */
    struct MysteryClactActor *clactUnit; /* 0x118 */
    void (*callback)(struct MysteryScroll *);/* 0x11C */
    u8 pad_120[4];
    u16 heapId;           /* 0x124 */
    u8 pad_126[2];
} MysteryScroll;

typedef struct MysteryClactActor {
    int palette;            /* 0x000 */
    int character;          /* 0x004 */
    int cellAnim;           /* 0x008 */
    void *actors[35];       /* 0x00C */
    u16 angle;            /* 0x098 */
    MysteryUtilBlendPalettes pals; /* 0x09A actor palette blend (current, from, to) */
    u8 pad_0FA[2];
} MysteryClactActor;

typedef struct {
    struct BmpOamSys *sys;              /* 0x00 */
    struct MysteryUtilActorPair *sprite;           /* 0x04 */
    const struct MysteryClactActor *clact;            /* 0x08 */
} MysteryOamSprite;

typedef struct {
    struct GameData *gameData; /* 0x00 */
    u32 reserved04;
    u32 flag;               /* 0x08 */
    u32 mode;               /* 0x0C */
    u32 reserved10;
    u32 saveType;           /* 0x14 */
    u32 reserved18;
    u32 ready;              /* 0x1C */
    u8 pad_020[8];
} MysteryNetSaveParam;

typedef struct { u8 pad_000[0x0C]; void *data; } MysteryClactResource;

typedef struct { u8 pad_000[0x14]; void *data; } MysteryPokeGraObject;

typedef struct {
    struct MysteryAlbum *album;            /* 0x000 */
    struct MysteryAlbumSlotWork *albumWork;        /* 0x004 */
    struct MysteryAlbumWork *netAlbum;         /* 0x008 */
    MysteryCardView cardView;  /* 0x00C */
    MysteryScroll scroll;   /* 0x138 */
    void *saveMenu;         /* 0x260 */
    MysteryOamSprite oam;   /* 0x264 */
    struct MysteryUtilDetailWindow *msgDialog;        /* 0x270 */
    unsigned int dialogResult[4];  /* 0x274 */
    void *textBox;          /* 0x284 */
    void *menuA;            /* 0x288 */
    void *menuB;            /* 0x28C */
    void *task;             /* 0x290 */
    MysteryClactActor clact;/* 0x294 */
    u16 heap;               /* 0x390 */
    u8 pad_392[2];
    void *graphic;          /* 0x394 */
    struct GfFont *font;    /* 0x398 */
    struct PrintQueue *printQueue; /* 0x39C */
    struct MsgBank *msgBankAlt;  /* 0x3A0 */
    struct MsgBank *msgBank;    /* 0x3A4 */
    struct WordSet *wordSet; /* 0x3A8 */
    u32 mode;               /* 0x3AC */
    void *net;              /* 0x3B0 */
    u32 savedValue;         /* 0x3B4 */
    struct GameData *gameData;/* 0x3B8 */
    struct MysteryData *mysteryData; /* 0x3BC */
    MysteryNetSaveParam *saveParam; /* 0x3C0 */
    u32 timer;              /* 0x3C4 */
    unsigned int cardSpaceFlag; /* 0x3C8 */
    MysteryPacket packet;   /* 0x3CC */
} MysteryWork;

#if __SIZEOF_POINTER__ == 4
typedef char MysteryWork_size_check[(sizeof(MysteryWork) == 0x69C) ? 1 : -1];
typedef char MysteryCardView_size_check[(sizeof(MysteryCardView) == 0x12C) ? 1 : -1];
typedef char MysteryScroll_size_check[(sizeof(MysteryScroll) == 0x128) ? 1 : -1];
typedef char MysteryClactActor_size_check[(sizeof(MysteryClactActor) == 0xFC) ? 1 : -1];
typedef char MysteryPacket_size_check[(sizeof(MysteryPacket) == 0x2D0) ? 1 : -1];
#endif

#ifdef __MWERKS__
#define ARC_UTIL_UploadBgPaletteFromArchive ARC_UTIL_UploadBgPaletteFromArchive_hdr
#define ARC_UTIL_LoadPaletteBlockFromArchive ARC_UTIL_LoadPaletteBlockFromArchive_hdr
#define ARC_UTIL_UploadBgCharFromHandle ARC_UTIL_UploadBgCharFromHandle_hdr
#define ARC_UTIL_UploadPaletteFromHandleWhole ARC_UTIL_UploadPaletteFromHandleWhole_hdr
#endif
#include "../arm9/arc_util.h"
#ifdef __MWERKS__
#undef ARC_UTIL_UploadBgPaletteFromArchive
#undef ARC_UTIL_LoadPaletteBlockFromArchive
#undef ARC_UTIL_UploadBgCharFromHandle
#undef ARC_UTIL_UploadPaletteFromHandleWhole
void ARC_UTIL_UploadBgPaletteFromArchive(int, int, int, int, int, int, int);
void * ARC_UTIL_LoadPaletteBlockFromArchive(u32, u32, void *, u32);
void ARC_UTIL_UploadBgCharFromHandle();
void ARC_UTIL_UploadPaletteFromHandleWhole();
#endif
#ifdef __MWERKS__
#define POKE_TOOL_Create POKE_TOOL_Create_hdr
#endif
#ifdef __MWERKS__
#define POKE_TOOL_PushMove POKE_TOOL_PushMove_hdr
#define POKE_TOOL_AddMove POKE_TOOL_AddMove_hdr
#endif
#include "../arm9/poke_tool.h"
#ifdef __MWERKS__
#undef POKE_TOOL_PushMove
#undef POKE_TOOL_AddMove
void POKE_TOOL_PushMove(struct PokemonParam *, int);
u32 POKE_TOOL_AddMove(struct PokemonParam *, u32);
#endif
#ifdef __MWERKS__
#undef POKE_TOOL_Create
void * POKE_TOOL_Create(u16, u16, u32, u32, u32);
#endif
#ifdef __MWERKS__
#define POKEGRA_ConvertCharTo2D POKEGRA_ConvertCharTo2D_hdr
#endif
#include "../arm9/pokegra.h"
#ifdef __MWERKS__
#undef POKEGRA_ConvertCharTo2D
void POKEGRA_ConvertCharTo2D(void *, u16);
#endif
#ifdef __MWERKS__
#define MYSTERY_UTIL_CreateWindowList MYSTERY_UTIL_CreateWindowList_hdr
#endif
#ifdef __MWERKS__
#define MYSTERY_UTIL_CreateMenu MYSTERY_UTIL_CreateMenu_hdr
#define MYSTERY_UTIL_CreateDetailWindow MYSTERY_UTIL_CreateDetailWindow_hdr
#endif
#include "mystery_util.h"
#ifdef __MWERKS__
#undef MYSTERY_UTIL_CreateMenu
#undef MYSTERY_UTIL_CreateDetailWindow
void * MYSTERY_UTIL_CreateMenu(const MysteryUtilMenuDef *, int);
struct MysteryUtilDetailWindow * MYSTERY_UTIL_CreateDetailWindow(const struct MysteryUtilDetailDef *, int);
#endif
#ifdef __MWERKS__
#undef MYSTERY_UTIL_CreateWindowList
void * MYSTERY_UTIL_CreateWindowList(void *, const char *, int, int, int, struct PrintQueue *, struct MsgBank *, struct GfFont *, int);
#endif
#include "../arm9/gf_overlay.h"
#include "../arm9/gfl_heap.h"
#include "../arm9/procsys.h"
#include "../arm9/mi_memory.h"
struct GameData;
#include "../arm9/game_data.h"
struct SaveControl;
struct MysteryData;
#include "../arm9/mystery_data.h"
#include "mystery_graphic.h"
#include "../arm9/gf_font.h"
struct PrintQueue;
#include "../arm9/printsys.h"
#include "../arm9/msgdata.h"
#include "mystery_net.h"
#include "../arm9/gfl_use.h"
#include "../arm9/wordset.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/os_reset.h"
#include "../arm9/bg_sys.h"
#include "../arm9/arc_tool.h"
#include "../arm9/bmp_menuwork.h"
#include "../arm9/clact.h"
struct PaletteData;
struct ParticleSys;
#include "../arm9/particle.h"
#include "../arm9/fade.h"
#include "../arm9/key.h"
#include "../arm9/gf_standard.h"
#include "mystery_album.h"
struct CtxB;
struct MysteryAlbumCard;
struct MysteryAlbumView;
struct MysteryAlbum;
#include "../arm9/g2.h"
struct MysteryAlbumWork;
#include "../arm9/net.h"
#include "../arm9/strbuf.h"
struct MyStatus;
#include "../arm9/mystatus.h"
struct PokemonParam;
struct BoxPokemon;
struct SaveData;
#include "../arm9/save_event.h"
#include "../arm9/file_util.h"
struct Pt16;
struct BmpOamSys;
#include "../arm9/bmp_oam.h"
struct MysteryGiftPacket;
#include "../arm9/g3x.h"
struct G3dLight;
#include "../arm9/g3d_system.h"
int MYSTERY_Create(void *owner, u32 unused, u32 arg);
int MYSTERY_Delete(void *a, int b, int c, MysteryWork *p);
int MYSTERY_Main(int a, int b, int c, MysteryWork *p);
void MYSTERY_InitBgHeap(u16 *p,u16 heap);
void MYSTERY_ExitBgHeap(void *work);
void MYSTERY_SetupBg(u16 *p,int mode);
void MYSTERY_CreateClact(MysteryClactActor *p, void *owner, u16 heap);
void MYSTERY_DeleteClact(MysteryClactActor *p);
void *MYSTERY_GetClactActor(const MysteryClactActor *p,int i);
void MYSTERY_TransferPalette(MysteryClactActor *p,int heap);
void MYSTERY_RotateActors(MysteryClactActor *p);
void MYSTERY_ResetActorAngle(MysteryClactActor *p);
void MYSTERY_CreateParticle(MysteryParticle *p, int heap);
void MYSTERY_DeleteParticle(MysteryParticle *p);
void MYSTERY_LoadParticle(MysteryParticle *p, int a, int b, int c);
struct SPLEmitter *MYSTERY_StartParticle(MysteryParticle *p, int x);
int MYSTERY_IsParticleCreated(MysteryParticle *p);
void MYSTERY_TaskInitSave(void *a,int b,MysteryWork *p);
void MYSTERY_TaskFadeToMenu(void *a, int *state, void *unused2);
void MYSTERY_TaskExitAlbum(void *a, int *state, void *unused2);
void MYSTERY_TaskMenu(void *task, int *state, void *pArg);
void MYSTERY_TaskMenuAction(void *a, int *state, void *pArg);
void MYSTERY_TaskReceive(void *task, int *state, void *pArg);
void MYSTERY_TaskAlbum(void *task, int *state, void *pArg);
void MYSTERY_TaskAlbumView(void *task, int *state, void *pArg);
void MYSTERY_TaskNetAlbum(void *task, int *state, void *pArg);
void MYSTERY_TaskNetExit(void *task, int *state, void *pArg);
void MYSTERY_TaskCleanup(void *p, int *n, void *qArg);
void MYSTERY_TaskMessage(void *a, int *state, void *pArg);
void MYSTERY_CreateSaveMenu(MysteryWork *p, int unused, int heap);
void MYSTERY_DeleteSaveMenu(MysteryWork *p);
void MYSTERY_CreateCardMenu(MysteryWork *p,u32 which,int heap);
void MYSTERY_DeleteCardMenu(MysteryWork *p);
int MYSTERY_PollCardMenu(MysteryWork *p);
void MYSTERY_CardMenuCallback(void *p);
void MYSTERY_CreatePartyMenu(MysteryWork *p,int heap);
void MYSTERY_DeletePartyMenu(MysteryWork *p);
void MYSTERY_CreateReceivedMon(MysteryCardView *out,void *owner,const u8 *desc,struct GameData *save,MysteryClactActor *list,u16 *bgHeap,MysteryScroll *scroll,u16 heap);
void MYSTERY_InitCardView(MysteryCardView *p,int mode);
void MYSTERY_DeleteCardView(MysteryCardView *p);
void MYSTERY_StepCardView(MysteryCardView *p);
int MYSTERY_IsCardViewDone(MysteryCardView *p);
void MYSTERY_CardViewAnimScroll(MysteryCardView *p);
void MYSTERY_CardViewAnimReveal(MysteryCardView *p);
void MYSTERY_CardViewAnimFade(MysteryCardView *p);
void MYSTERY_InitScroll(MysteryScroll *p,MysteryClactActor *q,u16 h);
void MYSTERY_ClearScroll(MysteryScroll *p);
void MYSTERY_StepScroll(MysteryScroll *p);
void MYSTERY_StartScroll(MysteryScroll *p,int n);
void MYSTERY_SetScrollParam(MysteryScroll *p,unsigned v);
void MYSTERY_UpdateScrollA(MysteryScroll *p);
void MYSTERY_UpdateScrollB(MysteryScroll *p);
void MYSTERY_CreateOamSprite(MysteryOamSprite *p,const MysteryClactActor *q,void *n,struct PrintQueue *k,struct MsgBank *x,int y,struct GfFont *z,u16 heap);
void MYSTERY_DeleteOamSprite(MysteryOamSprite *p);
int MYSTERY_PollOamSprite(MysteryOamSprite *p);
unsigned MYSTERY_MeasureGraChar(void *id,int heap);
int MYSTERY_IsCardValid(MysteryPacket *p,int n);
void MYSTERY_SetupDisplay3d(void);
extern char ov114_id[];
extern char ov_id[];
extern const char d_021DFB80[];
#include "../arm9/net_save.h"
extern char ov115_id[];
extern const MysteryPartyDesc d_021DF544;
extern const u16 d_021DF4F2[];
extern const u32 d_021DF4FC[];
extern const u8 GAME_VERSION_Code;
extern const u8 GAME_LANGUAGE_Code;
extern void *gSpeciesNameBank;
extern const int d_021DF5E4[];

int MYSTERY_Create(void *owner, u32 unused, u32 arg)
{
    MysteryWork *work;
    GF_OVERLAY_Load((sptr)ov114_id);
    GFL_HEAP_CreateChildHeap(1, 29, 0xA0000);
    work = PROCSYS_AllocProcWork(owner, sizeof(*work), 29);
    MI_CpuFill8(work, 0, sizeof(*work));
    work->savedValue = arg;
    work->gameData = GAME_DATA_Create(29);
    work->mysteryData = MYSTERY_DATA_Create(GAME_DATA_GetSaveControl(work->gameData), (s32)1, (u32)29);
    work->graphic = MYSTERY_GRAPHIC_Create(1, 29);
    MYSTERY_InitBgHeap(&work->heap, 29);
    MYSTERY_CreateClact(&work->clact, MYSTERY_GRAPHIC_GetClactUnit(work->graphic), 29);
    work->font = GF_FONT_Create(23, 0, 0, 0, 29);
    work->printQueue = PRINTSYS_QUE_Create((u32)29);
    work->msgBank = MSGDATA_CreateFromArchive(0, 2, 0x50, 29);
    work->msgBankAlt = MSGDATA_CreateFromArchive(0, 3, 0x9E, 29);
    work->wordSet = WORDSET_CreateDefault(29);
    work->task = MYSTERY_UTIL_CreateTask(work, (void *)MYSTERY_TaskInitSave, 29);
    work->textBox = MYSTERY_UTIL_CreateMenuWindow(1, 15, work->printQueue, work->font, 29);
    MYSTERY_UTIL_DrawMenuWindow((u8 *)work->textBox, 10, 14);
    work->net = MYSTERY_NET_Create(GAME_DATA_GetSaveControl(work->gameData), 29);
    MYSTERY_InitScroll(&work->scroll, &work->clact, 29);
    MYSTERY_StartScroll(&work->scroll, 0);
    MYSTERY_SetScrollParam(&work->scroll, 1);
    GFL_USE_CancelChangeAndPlayBgm(1154, 0xFFFF);
    return 1;
}

int MYSTERY_Delete(void *a, int b, int c, MysteryWork *p)
{
    MYSTERY_ClearScroll(&p->scroll);
    MYSTERY_NET_Delete(p->net);
    if (p->textBox) MYSTERY_UTIL_DeleteMenuWindow(p->textBox);
    MYSTERY_UTIL_DeleteTask(p->task);
    WORDSET_Delete(p->wordSet);
    MSGDATA_Delete(p->msgBankAlt);
    MSGDATA_Delete(p->msgBank);
    PRINTSYS_QUE_Delete(p->printQueue);
    GF_FONT_Delete(p->font);
    MYSTERY_DeleteClact(&p->clact);
    MYSTERY_ExitBgHeap(&p->heap);
    MYSTERY_GRAPHIC_Delete(p->graphic);
    MYSTERY_DATA_Delete(p->mysteryData);
    GAME_DATA_Delete(p->gameData);
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(29);
    OS_ResetSystem(0);
    GF_OVERLAY_Unload((sptr)ov_id);
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}

/*
 * follower: two zero padding bytes at 0x021D6922.
 */
int MYSTERY_Main(int a, int b, int c, MysteryWork *p)
{
    MYSTERY_NET_Step(p->net);
    MYSTERY_UTIL_DispatchTask(p->task);
    if (p->graphic) {
        MYSTERY_GRAPHIC_Draw(p->graphic);
        MYSTERY_GRAPHIC_DrawScene(p->graphic);
        MYSTERY_GRAPHIC_DrawEnd(p->graphic);
    }
    MYSTERY_StepScroll(&p->scroll);
    PRINTSYS_QUE_Main(p->printQueue);
    if (p->textBox) MYSTERY_UTIL_UpdateMenuWindow(p->textBox);
    if (p->menuB) MYSTERY_UTIL_IsWindowListDone(p->menuB);
    if (p->menuA) MYSTERY_UTIL_IsWindowListDone(p->menuA);
    if (p->msgDialog) MYSTERY_UTIL_Update(p->msgDialog);
    if (MYSTERY_UTIL_IsTaskDone(p->task)) return 1;
    return 0;
}

/*
 * Extent remainder: two-byte zero alignment padding.
 */
void MYSTERY_InitBgHeap(u16 *p,u16 heap)
{
    MI_CpuFill8(p,0,2);
    *p=heap;
    MYSTERY_SetupBg(p,0);
    BG_SYS_SetPlaneVisible(6,1);
}

void MYSTERY_ExitBgHeap(void *work) { }

void MYSTERY_SetupBg(u16 *p,int mode)
{
    u16 heap=(*p&0x7fff)|0x8000;
    void *arc;
    switch (mode) {
    case 0:
        arc=ARC_TOOL_CreateHandle(34,heap);
        ARC_UTIL_UploadPaletteFromHandleWhole(arc,6,0,0,0,heap);
        ARC_UTIL_UploadPaletteFromHandleWhole(arc,6,4,0,128,heap);
        ARC_UTIL_UploadPaletteFromHandleWhole(arc,7,4,32,32,heap);
        ARC_UTIL_UploadBgCharFromHandle(arc,15,3,0,0,0,heap);
        ARC_UTIL_UploadBgCharFromHandle(arc,15,7,0,0,0,heap);
        ARC_UTIL_UploadBgPaletteFromHandle(arc,31,3,0,0,0,heap);
        ARC_UTIL_UploadBgPaletteFromHandle(arc,31,7,0,0,0,heap);
        ARC_TOOL_DeleteHandle(arc);
        arc=ARC_TOOL_CreateHandle(23,heap);
        ARC_UTIL_UploadPaletteFromHandleWhole(arc,5,0,480,32,heap);
        ARC_UTIL_UploadPaletteFromHandleWhole(arc,5,4,480,32,heap);
        ARC_TOOL_DeleteHandle(arc);
        BMP_MENUWORK_LoadCharAndPltt(1,10,14,0,heap);
        BMP_MENUWORK_LoadCharAndPltt(0,1,13,0,heap);
        BG_SYS_InitRun(1,32,0,heap);
        BG_SYS_InitRun(0,32,0,heap);
        break;
    case 1:
        arc=ARC_TOOL_CreateHandle(34,heap);
        ARC_UTIL_UploadPaletteFromHandleWhole(arc,6,4,0,192,heap);
        ARC_UTIL_UploadBgCharFromHandle(arc,15,6,0,0,0,heap);
        ARC_UTIL_UploadBgPaletteFromHandle(arc,21,6,0,0,0,heap);
        ARC_TOOL_DeleteHandle(arc);
        break;
    case 2:
        arc=ARC_TOOL_CreateHandle(34,heap);
        ARC_UTIL_UploadBgCharFromHandle(arc,11,2,0,0,0,heap);
        ARC_UTIL_UploadBgPaletteFromHandle(arc,28,2,0,0,0,heap);
        ARC_TOOL_DeleteHandle(arc);
        break;
    }
}

/*
 * follower: two zero padding bytes at 0x021D6C26.
 * lever: spell the object slot as p+i*4+16; data precedes allocation in local declarations.
 * interfaces: ABF0 and B294 leave r0 live and this caller consumes it despite legacy void definitions.
 */
void MYSTERY_CreateClact(MysteryClactActor *p, void *owner, u16 heap)
{
    void *res;
    MysteryActorPos point;
    int bound;
    char *data;
    void *allocation;
    void *arc;
    int i;
    arc=ARC_TOOL_CreateHandle(34,heap);
    p->palette=CLACT_RegisterPalette(arc,8,2,0,heap);
    p->cellAnim=CLACT_RegisterCellAnim(arc,34,37,heap);
    p->character=CLACT_RegisterCharacter(arc,16,0,2,heap);
    allocation=ARC_UTIL_LoadPaletteBlockFromHandle((void *)arc,8,(&res),heap);
    data=*(char * *)&((MysteryClactResource *)res)->data;
    MI_CpuCopy8(data,p->pals.blendTo,32);
    data+=32;
    MI_CpuCopy8(data,p->pals.blendFrom,32);
    GFL_HEAP_Free(allocation);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&point,0,8);
    p->actors[0]=CLACT_CreateActor((struct Unit *)owner,p->character,p->palette,p->cellAnim,(const struct ActorInitParam *)&point,0,heap);
    CLACT_SetActorDrawEnable(p->actors[0],0);
    bound=256;
    bound+=16;
    for (i=0;i<32;i++) {
        point.x=GFL_USE_GetRandomBelow(256);
        point.y=GFL_USE_GetRandomBelow(256)-bound;
        point.b=3;
        point.z=GFL_USE_GetRandomBelow(6)+3;
        p->actors[i+1]=CLACT_CreateActor((struct Unit *)owner,p->character,p->palette,p->cellAnim,(const struct ActorInitParam *)&point,0,heap);
        CLACT_SetActorDrawEnable(p->actors[i+1],0);
    }
    point.x=128;
    point.y=177;
    point.b=0;
    point.a=1;
    point.z=9;
    p->actors[34]=CLACT_CreateActor((struct Unit *)owner,p->character,p->palette,p->cellAnim,(const struct ActorInitParam *)&point,0,heap);
    CLACT_SetActorDrawEnable(p->actors[34],0);
}

void MYSTERY_DeleteClact(MysteryClactActor *p)
{
    int i;
    void *q;
    for(i=0;i<35;i++){
        q=p->actors[i];
        if(q) CLACT_DeleteActor(q);
    }
    CLACT_ReleasePalette(p->palette);
    CLACT_ReleaseCharacter(p->character);
    CLACT_ReleaseCellAnim(p->cellAnim);
}

void *MYSTERY_GetClactActor(const MysteryClactActor *p,int i) { return p->actors[i]; }

void MYSTERY_TransferPalette(MysteryClactActor *p,int heap)
{
    void *out;
    void *raw;
    raw=ARC_UTIL_LoadPaletteBlockFromArchive(34,8,&out,heap);
    CLACT_TransferPalette(p->palette,out,7);
    GFL_HEAP_Free(raw);
}

static inline int wrap(int n, u16 *p)
{
    if (*p + n >= 65536) return *p + n - 65536;
    return *(volatile u16 *)p + n;
}

/*
 * follower: two zero padding bytes at 0x021D6CEA.
 * volatile: 0x021D6C8E and 0x021D6CA6 read the same halfword; only the latter access is volatile.
 */
void MYSTERY_RotateActors(MysteryClactActor *p)
{
    int i;
    p->angle = wrap(1024, &p->angle);
    for (i = 0; i < 5; i++)
        MYSTERY_UTIL_BlendPalette(14, &p->pals.current[i], p->angle, 0, (u8)i, p->pals.blendFrom[i], p->pals.blendTo[i]);
}

void MYSTERY_ResetActorAngle(MysteryClactActor *p) { p->angle=0; }

void MYSTERY_CreateParticle(MysteryParticle *p, int heap)
{
    void *v;
    MI_CpuFill8(p, 0, sizeof(*p));
    p->created = 1;
    v = GFL_HEAP_Alloc(heap, 0x4800, 0, d_021DFB80, 0x482);
    p->buffer = v;
    p->sys = (void *)PARTICLE_CreateSystemDefault(v, 0x4800, 1, heap);
}

/*
 * Addresses are Black-image addresses.
 */
void MYSTERY_DeleteParticle(MysteryParticle *p)
{
    GFL_HEAP_Free(p->buffer);
    MI_CpuFill8(p, 0, sizeof(*p));
}

/*
 * Promoted from MATCH by the recursive-unblocker lane: 0x0205121C now has an
 * EXACT arm9 shard entry (pkt_0205121C), so the call at +000A resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */
void MYSTERY_LoadParticle(MysteryParticle *p, int a, int b, int c)
{
    void *x = PARTICLE_LoadArchiveMember(a, b, c);
    PARTICLE_SetupSystem((struct ParticleSys *)p->sys, x, 1, 0);
}

struct SPLEmitter *MYSTERY_StartParticle(MysteryParticle *p, int x)
{
    return PARTICLE_StartEffectWithCallback(p->sys, x, 0, p);
}

int MYSTERY_IsParticleCreated(MysteryParticle *p) { return p->created; }

void MYSTERY_TaskInitSave(void *a,int b,MysteryWork *p)
{
    MYSTERY_UTIL_SetMenuMessage(*(u8 * *)&p->textBox,p->msgBank,79,0);
    MYSTERY_CreateCardMenu(p,0,29);
    MYSTERY_UTIL_SetTaskHandler(a,MYSTERY_TaskFadeToMenu);
}

void MYSTERY_TaskFadeToMenu(void *a, int *state, void *unused2)
{
    switch (*state) {
    case 0: FADE_Start(3, 16, 0, 0); *state = 1; break;
    case 1: if (!FADE_IsActive()) *state = 2; break;
    case 2: MYSTERY_UTIL_SetTaskHandler(a, MYSTERY_TaskMenu); break;
    }
}

void MYSTERY_TaskExitAlbum(void *a, int *state, void *unused2)
{
    switch (*state) {
    case 0: FADE_Start(12, 0, 16, 0); GFL_USE_FadeOutBgm(8); *state = 1; break;
    case 1: if (!FADE_IsActive()) *state = 2; break;
    case 2: MYSTERY_UTIL_SetTaskHandler(a, MYSTERY_TaskCleanup); break;
    }
}

void MYSTERY_TaskMenu(void *task, int *state, void *pArg)
{
    MysteryWork *p = pArg;
    int v,flag,all,id;
    u32 i;
    switch(*state) {
    case 0:
        if(p->cardSpaceFlag) {p->cardSpaceFlag=0;*state=2;break;}
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,79,0);
        if(p->msgDialog==0) MYSTERY_CreateCardMenu(p,0,29);
        *state=1;break;
    case 1:
        v=MYSTERY_PollCardMenu(p);
        if(v!=-1) {
        if(v==0) {
            all=1;
            MYSTERY_DeleteCardMenu(p);
            flag=(MYSTERY_DATA_HasCardSpace(p->mysteryData)==0);
            if(flag) {
                for(i=0;i<MYSTERY_DATA_GetCardSlotNum(p->mysteryData);i++) {
                    if(MYSTERY_DATA_IsCardReceived(p->mysteryData,i)) all=0;
                }
            }
            if(flag) {
                if(all) {
                    if(MYSTERY_DATA_IsMainSave(p->mysteryData)==0) id=146;
                    else id=137;
                    MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,id,1);
                    MYSTERY_UTIL_SetTaskArg(task,0);*state=19;
                } else *state=16;
            } else {
                if(APP_ENV_IsWirelessAvailable()==0) MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskMessage);
                else *state=2;
            }
        } else if(v==1) {
            MYSTERY_DeleteCardMenu(p);MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskAlbumView);
        } else if(v==2) {
            MYSTERY_DeleteCardMenu(p);MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskMenuAction);
        } else if(v==3) MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskExitAlbum);
        else break;
        }
        break;
    case 2:
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,83,1);
        MYSTERY_UTIL_SetTaskArg(task,3);*state=19;break;
    case 3:MYSTERY_CreateSaveMenu(p,0,29);*state=4;break;
    case 4:
        v=MYSTERY_UTIL_UpdateMenu(p->saveMenu);
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu(p);
            if(v==0) *state=5;else if(v==1) *state=0;
        }
        break;
    case 5:MYSTERY_NET_SetAction(p->net,1);*state=6;break;
    case 6:if(MYSTERY_NET_GetAction(p->net)==2) *state=7;break;
    case 7:
        MYSTERY_DeleteCardMenu(p);MYSTERY_CreateCardMenu(p,1,29);
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,86,0);*state=8;break;
    case 8:
        if((MYSTERY_NET_GetResult(p->net))&32) MYSTERY_UTIL_SetListValue(p->msgDialog,0,1);
        else MYSTERY_UTIL_SetListValue(p->msgDialog,0,0);
        v=MYSTERY_PollCardMenu(p);
        if(v!=-1) {
        MYSTERY_DeleteCardMenu(p);
        switch(v) {
        case 0:p->mode=0;*state=9;break;
        case 1:p->mode=1;*state=12;break;
        case 2:p->mode=2;*state=9;break;
        case 3:*state=14;break;
        }
        }
        break;
    case 9:
        switch(p->mode) {
        case 0:MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,96,1);MYSTERY_UTIL_SetTaskArg(task,10);*state=19;break;
        case 1:break;
        case 2:MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,102,1);MYSTERY_UTIL_SetTaskArg(task,10);*state=19;break;
        }
        break;
    case 10:MYSTERY_CreateSaveMenu(p,0,29);*state=11;break;
    case 11:
        v=MYSTERY_UTIL_UpdateMenu(p->saveMenu);
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu(p);
            if(v==0) *state=12;else if(v==1) *state=7;
        }
        break;
    case 12:
        if(MYSTERY_NET_GetAction(p->net)==2) {MYSTERY_NET_SetAction(p->net,3);*state=13;}
        break;
    case 13:
        if(MYSTERY_NET_GetAction(p->net)==0) {
            if(p->mode==1) MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskNetExit);
            else MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskReceive);
        }
        break;
    case 14:
        if(MYSTERY_NET_GetAction(p->net)==2) {MYSTERY_NET_SetAction(p->net,3);*state=15;}
        else *state=0;
        break;
    case 15:if(MYSTERY_NET_GetAction(p->net)==0) *state=0;break;
    case 16:
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,141,1);
        MYSTERY_UTIL_SetTaskArg(task,17);*state=19;break;
    case 17:MYSTERY_CreateSaveMenu(p,0,29);*state=18;break;
    case 18:
        v=MYSTERY_UTIL_UpdateMenu(p->saveMenu);
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu(p);
            if(v==0) MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskNetAlbum);
            else if(v==1) *state=0;
        }
        break;
    case 19:if(MYSTERY_UTIL_GetMenuState(p->textBox)) MYSTERY_UTIL_GetTaskArg(task);break;
    }
}

void MYSTERY_TaskMenuAction(void *a, int *state, void *pArg)
{
    MysteryWork *p = pArg;
    int result;
    switch (*state) {
    case 0:
        MYSTERY_UTIL_SetMenuMessage(p->textBox, p->msgBank, 126, 0);
        MYSTERY_CreateCardMenu(p, 3, 29);
        *state = 2;
        break;
    case 2:
        result = MYSTERY_PollCardMenu(p);
        if (result == -1) break;
        MYSTERY_DeleteCardMenu(p);
        if (result == 0) {
            MYSTERY_UTIL_SetMenuMessage(p->textBox, p->msgBank, 132, 1);
            MYSTERY_UTIL_SetTaskArg(a, 0);
            *state = 3;
        } else if (result == 1) {
            MYSTERY_UTIL_SetMenuMessage(p->textBox, p->msgBank, 133, 1);
            MYSTERY_UTIL_SetTaskArg(a, 0);
            *state = 3;
        } else if (result == 2) {
            MYSTERY_UTIL_SetMenuMessage(p->textBox, p->msgBank, 134, 1);
            MYSTERY_UTIL_SetTaskArg(a, 0);
            *state = 3;
        } else if (result == 3) {
            MYSTERY_UTIL_SetTaskHandler(a, MYSTERY_TaskMenu);
        }
        break;
    case 3:
        if (MYSTERY_UTIL_GetMenuState(p->textBox)) MYSTERY_UTIL_GetTaskArg(a);
        break;
    }
}

void MYSTERY_TaskReceive(void *task, int *state, void *pArg)
{
    MysteryWork *p = pArg;
    int v,flag;
    MysteryRtcDate date;
    switch(*state) {
    case 0:
        switch(p->mode) {
        case 1:MYSTERY_NET_SetAction(p->net,4);break;
        case 0:MYSTERY_NET_SetAction(p->net,7);break;
        case 2:MYSTERY_NET_SetAction(p->net,10);break;
        }
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,105,0);
        p->timer=0;*state=1;break;
    case 1:
        if(MYSTERY_NET_GetAction(p->net)==0) {
            v=MYSTERY_NET_GetReceivedData(p->net,&p->packet,720);
            if(v==1) {
                v=MYSTERY_NET_ImportRecords((char *)&p->packet,p->gameData,32797);
                if(MYSTERY_IsCardValid(&p->packet,v)) *state=5;
                else *state=12;
            } else if(v==2) *state=2;
        }
        v=MYSTERY_NET_UpdateWifiError(p->net);
        switch(v) {case 1:case 2:MYSTERY_NET_Exit(p->net);MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskMenu);break;}
        if((KEY_GetTrg()&2) || p->timer++>7200) {
            flag=0;
            switch(p->mode) {
            case 1:
                if(MYSTERY_NET_GetAction(p->net)==4) {MYSTERY_NET_SetAction(p->net,5);flag=1;}break;
            case 0:
                if(MYSTERY_NET_GetAction(p->net)==8) {MYSTERY_NET_SetAction(p->net,9);flag=1;}break;
            case 2:
                if(MYSTERY_NET_GetAction(p->net)==11) {MYSTERY_NET_SetAction(p->net,12);flag=1;}break;
            }
            if(flag) {*state=2;p->timer=0;}
        }
        break;
    case 2:
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,136,2);
        MYSTERY_UTIL_SetTaskArg(task,3);*state=14;break;
    case 3:
        p->timer++;
        if(MYSTERY_NET_GetAction(p->net)==0 && p->timer>30) {
            p->timer=0;
            MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,139,1);
            MYSTERY_UTIL_SetTaskArg(task,4);*state=14;
        }
        break;
    case 4:MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskMenu);break;
    case 5:
        MYSTERY_CreateCardMenu(p,2,29);MYSTERY_CreatePartyMenu(p,29);
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,106,0);*state=6;break;
    case 6:
        flag=0;v=MYSTERY_PollCardMenu(p);
        if(v!=-1) {
        if(v==0) {
            MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,110,1);
            MYSTERY_UTIL_SetTaskArg(task,7);*state=14;
        } else if(v==-2) flag=1;
        } else if(KEY_GetTrg()&2) flag=1;
        if(flag) {
            MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,107,1);
            MYSTERY_UTIL_SetTaskArg(task,9);*state=14;
        }
        break;
    case 7:MYSTERY_CreateSaveMenu(p,0,29);*state=8;break;
    case 8:
        v=MYSTERY_UTIL_UpdateMenu(p->saveMenu);
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu(p);
            if(v==0) {
                MYSTERY_DeleteCardMenu(p);
                if(((MysteryPacketFlag *)&p->packet.flags)->bit && MYSTERY_DATA_IsEventFlag(p->mysteryData,p->packet.eventFlag)) {*state=11;break;}
                GF_STANDARD_GetCachedDate((RTCDate *)(&date));
                p->packet.date=(((u32)date.y+2000)<<16)|(((u32)date.m<<24)>>16)|(u8)date.d;
                MYSTERY_DATA_AddCard(p->mysteryData,&p->packet);
                MYSTERY_DATA_SetEventFlag(p->mysteryData,p->packet.eventFlag);
                MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskAlbum);
            } else if(v==1) *state=5;
        }
        break;
    case 9:MYSTERY_CreateSaveMenu(p,0,29);*state=10;break;
    case 10:
        v=MYSTERY_UTIL_UpdateMenu(p->saveMenu);
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu(p);
            if(v==0) {
                MYSTERY_DeleteCardMenu(p);MYSTERY_DeletePartyMenu(p);
                MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskMenu);
            } else if(v==1) *state=5;
        }
        break;
    case 11:
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,138,1);
        MYSTERY_UTIL_SetTaskArg(task,13);*state=14;break;
    case 12:
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,144,1);
        MYSTERY_UTIL_SetTaskArg(task,13);*state=14;break;
    case 13:
        MYSTERY_DeleteCardMenu(p);MYSTERY_DeletePartyMenu(p);
        MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskMenu);break;
    case 14:
        if(MYSTERY_UTIL_GetMenuState(p->textBox)) MYSTERY_UTIL_GetTaskArg(task);
        break;
    }
}

/*
 * volatile: 0x021D79BC writes the display blend register 0x04000050.
 */
void MYSTERY_TaskAlbum(void *task, int *state, void *pArg)
{
    MysteryWork *p = pArg;
    MysteryAlbumDesc d;
    switch (*state) {
    case 0:
        MYSTERY_GRAPHIC_StartRender(p->graphic);
        BG_SYS_SetPlaneVisible(1,1);
        BG_SYS_SetPlaneVisible(3,1);
        MYSTERY_CreateReceivedMon(&p->cardView,MYSTERY_GRAPHIC_GetClactUnit(p->graphic),(const u8 *)&p->packet,p->gameData,&p->clact,&p->heap,&p->scroll,29);
        MYSTERY_InitCardView(&p->cardView,0);
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,113,2);
        *state=1;
        break;
    case 1:
        BG_SYS_SetPlaneVisible(0,1);
        *state=2;
        break;
    case 2:
        if (MYSTERY_UTIL_GetMenuState(p->textBox)) *state=3;
        break;
    case 3:
        MYSTERY_StepCardView(&p->cardView);
        if (MYSTERY_IsCardViewDone(&p->cardView)) *state=4;
        break;
    case 4:
        MYSTERY_DATA_SaveStart(p->mysteryData,p->gameData);
        *state=5;
        break;
    case 5:
        if (MYSTERY_DATA_SaveMain(p->mysteryData,p->gameData)==2) *state=6;
        break;
    case 6:
        MYSTERY_InitCardView(&p->cardView,1);
        *state=7;
        break;
    case 7:
        MYSTERY_StepCardView(&p->cardView);
        if (MYSTERY_IsCardViewDone(&p->cardView)) *state=8;
        break;
    case 8:
        MYSTERY_UTIL_SetMenuMessage(p->textBox,p->msgBank,114,1);
        *state=9;
        break;
    case 9:
        if (MYSTERY_UTIL_GetMenuState(p->textBox)) *state=10;
        break;
    case 10:
        MYSTERY_DeleteCardView(&p->cardView);
        MYSTERY_UTIL_DeleteMenuWindow(p->textBox);
        p->textBox=0;
        MYSTERY_DeleteCardMenu(p);
        *(volatile u16 *)REG_BLDCNT_ADDR=0;
        MYSTERY_GRAPHIC_StopRender(p->graphic);
        BG_SYS_SetPlaneVisible(1,1);
        BG_SYS_SetPlaneVisible(3,1);
        *state=11;
        break;
    case 11:
        BG_SYS_SetPlaneVisible(0,1);
        *state=12;
        break;
    case 12:
        BG_SYS_SetPlaneVisible(1,0);
        MI_CpuFill8(&d,0,sizeof(d));
        d.frontPlane=2;
        d.backPlane=0;
        d.reserved08=8;
        d.windowPalette=15;
        d.paletteBank=13;
        d.charPalette=10;
        d.clactUnit=MYSTERY_GRAPHIC_GetClactUnit(p->graphic);
        d.cardList=p->mysteryData;
        d.msgBank=p->msgBank;
        d.font=p->font;
        d.printQueue=p->printQueue;
        d.wordSet=p->wordSet;
        p->albumWork=MYSTERY_ALBUM_CreateSlotWork(&d,29);
        p->album=(MysteryAlbum *)MYSTERY_ALBUM_CreateAlbumView((MysteryAlbumCard *)&p->packet,p->albumWork,p->gameData,29);
        MYSTERY_ALBUM_RequestSetup(p->album,0);
        *state=13;
        break;
    case 13:
        MYSTERY_ALBUM_StepIntro(p->album);
        MYSTERY_ALBUM_StartIntro(p->album);
        *state=14;
        break;
    case 14:
        MYSTERY_ALBUM_StepIntro(p->album);
        if (MYSTERY_ALBUM_IsIntroIdle(p->album)) {
            p->timer=0;
            *state=15;
        }
        break;
    case 15:
        if (KEY_GetTrg()&1) *state=18;
        if ((p->timer)++>240) {
            p->timer=0;
            *state=16;
        }
        break;
    case 16:
        MYSTERY_CreateOamSprite(&p->oam,&p->clact,MYSTERY_GRAPHIC_GetClactUnit(p->graphic),p->printQueue,p->msgBank,155,p->font,29);
        MYSTERY_PollOamSprite(&p->oam);
        *state=17;
        break;
    case 17:
        MYSTERY_PollOamSprite(&p->oam);
        if (KEY_GetTrg()&1) {
            MYSTERY_DeleteOamSprite(&p->oam);
            *state=18;
        }
        break;
    case 18:
        MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskExitAlbum);
        break;
    }
}

void MYSTERY_TaskAlbumView(void *task, int *state, void *pArg)
{
    MysteryWork *p = pArg;
    MysteryAlbumCreateInput d;
    switch(*state) {
    case 0:
        FADE_Start(3,0,16,-1);
        MYSTERY_UTIL_SetTaskArg(task,1);
        *state=8;
        break;
    case 1:
        MYSTERY_SetScrollParam(&p->scroll,0);
        MYSTERY_DeleteCardMenu(p);
        MYSTERY_UTIL_DeleteMenuWindow(p->textBox);
        p->textBox=0;
        MI_CpuFill8(&d,0,sizeof(d));
        d.mode=0;
        d.clactUnit=MYSTERY_GRAPHIC_GetClactUnit(p->graphic);
        d.cardList=p->mysteryData;
        d.font=p->font;
        d.printQueue=p->printQueue;
        d.wordSet=p->wordSet;
        d.msgBank=p->msgBank;
        d.gameData=p->gameData;
        p->netAlbum=MYSTERY_ALBUM_Create(&d,29);
        *state=2;
        break;
    case 2:
        FADE_Start(3,16,0,-1);
        MYSTERY_UTIL_SetTaskArg(task,3);
        *state=8;
        break;
    case 3:
        MYSTERY_ALBUM_Update(p->netAlbum);
        if(MYSTERY_ALBUM_GetWindowState(p->netAlbum)) *state=4;
        break;
    case 4:
        FADE_Start(3,0,16,0);
        MYSTERY_UTIL_SetTaskArg(task,5);
        *state=8;
        break;
    case 5:
        MYSTERY_SetScrollParam(&p->scroll,1);
        MYSTERY_ALBUM_DeleteWork(p->netAlbum);
        p->netAlbum=0;
        MYSTERY_SetupBg(&p->heap,0);
        MYSTERY_TransferPalette(&p->clact,29);
        p->textBox=MYSTERY_UTIL_CreateMenuWindow(1,15,p->printQueue,p->font,29);
        MYSTERY_UTIL_DrawMenuWindow(p->textBox,10,14);
        MYSTERY_CreateCardMenu(p,0,29);
        G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,4,24,15,3);
        *state=6;
        break;
    case 6:
        FADE_Start(3,16,0,0);
        MYSTERY_UTIL_SetTaskArg(task,7);
        *state=8;
        break;
    case 7:
        MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskMenu);
        break;
    case 8:
        if(!FADE_IsActive()) MYSTERY_UTIL_GetTaskArg(task);
        break;
    }
    if(p->netAlbum) MYSTERY_ALBUM_UpdateWindows(p->netAlbum);
}

void MYSTERY_TaskNetAlbum(void *task, int *state, void *pArg)
{
    MysteryWork *p = pArg;
    MysteryAlbumCreateInput d;
    switch(*state) {
    case 0:
        FADE_Start(3,0,16,-1);
        MYSTERY_UTIL_SetTaskArg(task,1);
        *state=8;
        break;
    case 1:
        MYSTERY_SetScrollParam(&p->scroll,0);
        MYSTERY_DeleteCardMenu(p);
        MYSTERY_UTIL_DeleteMenuWindow(p->textBox);
        p->textBox=0;
        MI_CpuFill8(&d,0,sizeof(d));
        d.mode=1;
        d.clactUnit=MYSTERY_GRAPHIC_GetClactUnit(p->graphic);
        d.cardList=p->mysteryData;
        d.font=p->font;
        d.printQueue=p->printQueue;
        d.wordSet=p->wordSet;
        d.msgBank=p->msgBank;
        d.gameData=p->gameData;
        p->netAlbum=MYSTERY_ALBUM_Create(&d, 29);
        *state=2;
        break;
    case 2:
        FADE_Start(3,16,0,-1);
        MYSTERY_UTIL_SetTaskArg(task,3);
        *state=8;
        break;
    case 3:
        MYSTERY_ALBUM_Update(p->netAlbum);
        if(MYSTERY_ALBUM_GetWindowState(p->netAlbum)) *state=4;
        break;
    case 4:
        FADE_Start(3,0,16,0);
        MYSTERY_UTIL_SetTaskArg(task,5);
        *state=8;
        break;
    case 5:
        MYSTERY_SetScrollParam(&p->scroll,1);
        MYSTERY_ALBUM_DeleteWork(p->netAlbum);
        p->netAlbum=0;
        MYSTERY_SetupBg(&p->heap,0);
        MYSTERY_TransferPalette(&p->clact,29);
        p->textBox=MYSTERY_UTIL_CreateMenuWindow(1,15,p->printQueue,p->font,29);
        MYSTERY_UTIL_DrawMenuWindow(p->textBox,10,14);
        G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,4,24,15,3);
        MYSTERY_CreateCardMenu(p,0,29);
        *state=6;
        break;
    case 6:
        FADE_Start(3,16,0,0);
        MYSTERY_UTIL_SetTaskArg(task,7);
        *state=8;
        break;
    case 7:
        p->cardSpaceFlag=MYSTERY_DATA_HasCardSpace(p->mysteryData);
        MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskMenu);
        break;
    case 8:
        if(!FADE_IsActive()) MYSTERY_UTIL_GetTaskArg(task);
        break;
    }
    if(p->netAlbum) MYSTERY_ALBUM_UpdateWindows(p->netAlbum);
}

void MYSTERY_TaskNetExit(void *task, int *state, void *pArg)
{
    MysteryWork *p = pArg;
    int result;
    result=MYSTERY_NET_UpdateWifiError(p->net);
    switch(result) {
    case 1: case 2:
        MYSTERY_NET_Exit(p->net);
        MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskMenu);
        break;
    }
    switch(*state) {
    case 0:
        FADE_Start(3,0,16,0);
        *state=1; return;
    case 1:
        if(!FADE_IsActive()) {
            MYSTERY_SetScrollParam(&p->scroll,0);
            *state=2; return;
        }
        break;
    case 2:
        if(p->textBox) {
            MYSTERY_UTIL_DeleteMenuWindow(p->textBox);
            p->textBox=0;
        }
        MYSTERY_DeleteClact(&p->clact);
        MYSTERY_ExitBgHeap(&p->heap);
        MYSTERY_GRAPHIC_Delete(p->graphic);
        p->graphic=0;
        *state=3; return;
    case 3:
        p->saveParam=GFL_HEAP_Alloc(29,sizeof(*p->saveParam),0,d_021DFB80,2664);
        MI_CpuFill8(p->saveParam,0,sizeof(*p->saveParam));
        p->saveParam->gameData=p->gameData;
        p->saveParam->reserved04=0;
        p->saveParam->flag=1;
        p->saveParam->reserved10=0;
        p->saveParam->reserved18=0;
        p->saveParam->mode=9;
        if(!MYSTERY_DATA_IsMainSave((struct MysteryData *)(p->mysteryData))) p->saveParam->saveType=2;
        else p->saveParam->saveType=0;
        PROCSYS_PushGlobal((uptr)ov115_id,&gNetSaveMainProc,p->saveParam);
        *state=5; return;
    case 5:
        p->graphic=MYSTERY_GRAPHIC_Create(1,29);
        MYSTERY_InitBgHeap(&p->heap,29);
        MYSTERY_CreateClact(&p->clact,(void *)MYSTERY_GRAPHIC_GetClactUnit(p->graphic),29);
        p->textBox=MYSTERY_UTIL_CreateMenuWindow(1,15,p->printQueue,p->font,29);
        MYSTERY_UTIL_DrawMenuWindow(p->textBox,10,14);
        G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,4,24,15,3);
        GFL_NET_RefreshWmIconAtTopRight(1,29);
        GFL_USE_CancelChangeAndPlayBgm(1154,65535);
        MYSTERY_SetScrollParam(&p->scroll,1);
        *state=4; return;
    case 4:
        *state=6; return;
    case 6:
        FADE_Start(3,16,0,0);
        *state=7; return;
    case 7:
        if(!FADE_IsActive()) { *state=8; return; }
        break;
    case 8:
        if(!p->saveParam->ready) MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskReceive);
        else MYSTERY_UTIL_SetTaskHandler(task,MYSTERY_TaskMenu);
        GFL_HEAP_Free(p->saveParam);
        break;
    }
}

void MYSTERY_TaskCleanup(void *p, int *n, void *qArg) {
    MysteryWork *q = qArg;
 MYSTERY_DeleteSaveMenu(q);MYSTERY_DeleteCardMenu(q);MYSTERY_DeletePartyMenu(q);
 if(q->album) {MYSTERY_ALBUM_Delete(q->album);MYSTERY_ALBUM_DeleteSlotWork(q->albumWork);}
 MYSTERY_UTIL_MarkTaskDone(p);
}

void MYSTERY_TaskMessage(void *a, int *state, void *pArg)
{
    MysteryWork *p = pArg;
    switch (*state) {
    case 0: MYSTERY_UTIL_SetMenuMessage(*(u8 * *)&p->textBox, p->msgBankAlt, 22, 1); *state = 1; break;
    case 1: if (MYSTERY_UTIL_GetMenuState(p->textBox)) MYSTERY_UTIL_SetTaskHandler(a, MYSTERY_TaskMenu); break;
    }
}

/*
 * follower: two zero padding bytes at 0x021D8196.
 */
void MYSTERY_CreateSaveMenu(MysteryWork *p, int unused, int heap)
{
    MysteryUtilMenuDef c;
    if (p->saveMenu == 0) {
        MI_CpuFill8(&c, 0, sizeof(c));
        c.menuTable = p->msgBank;
        c.messageTable = p->font;
        c.printOwner = p->printQueue;
        c.menuItems[0] = 0x54;
        c.menuItems[1] = 0x55;
        c.count = 2;
        c.bgLayer = 0;
        c.palette = 15;
        c.windowX = 14;
        c.windowY = 1;
        p->saveMenu = MYSTERY_UTIL_CreateMenu(&c, heap);
    }
}

void MYSTERY_DeleteSaveMenu(MysteryWork *p)
{
    void *x = p->saveMenu;
    if (x != 0) {
        MYSTERY_UTIL_DeleteMenu(x);
        p->saveMenu = 0;
    }
}

void MYSTERY_CreateCardMenu(MysteryWork *p,u32 which,int heap)
{
    struct MysteryUtilDetailDef d;
    void *archive;
    int i;
    if(p->msgDialog) return;
    MI_CpuFill8(&d,0,sizeof(d));
    d.font=p->font;
    d.printQueue=p->printQueue;
    d.actor=MYSTERY_GetClactActor(&p->clact,0);
    d.bgLayer=1;
    d.windowPalette=15;
    d.windowPalette2=2;
    d.paletteBank=4;
    d.callback=MYSTERY_CardMenuCallback;
    d.callbackArg=p;
    d.rowOffset=0;
    d.colOffset=0;
    d.animSeq=0;
    d.outIndex=&p->dialogResult[which];
    switch(which) {
    case 0:
        d.bank=p->msgBank;
        d.ids[0].id=80; d.ids[1].id=81; d.ids[2].id=131; d.ids[3].id=82; d.count=4;
        break;
    case 1:
        d.bank=p->msgBank;
        d.ids[0].id=87; d.ids[1].id=88; d.ids[2].id=89; d.ids[3].id=90; d.count=4;
        break;
    case 2:
        d.bank=0;
        d.ids[0].str=STRBUF_Create(37,heap);
        STRBUF_SetStringN(d.ids[0].str,p->packet.name,37);
        d.count=1;
        d.rowOffset=-1;
        d.colOffset=-2;
        d.animSeq=10;
        break;
    case 3:
        d.bank=p->msgBank;
        d.ids[0].id=127; d.ids[1].id=128; d.ids[2].id=129; d.ids[3].id=130; d.count=4;
        break;
    }
    archive=ARC_TOOL_CreateHandle(34,heap);
    ARC_UTIL_UploadPaletteFromHandleWhole(archive,6,0,0,160,heap);
    ARC_UTIL_UploadBgCharFromHandle(archive,15,2,0,0,0,heap);
    if(which==2) ARC_UTIL_UploadBgPaletteFromArchive(34,30,2,0,0,0,heap);
    else ARC_UTIL_UploadBgPaletteFromArchive(34,29,2,0,0,0,heap);
    ARC_TOOL_DeleteHandle(archive);
    BG_SYS_FillTileMap(2,0,0,32,24,4);
    BG_SYS_PushTile(2);
    BG_SYS_SetPlaneVisible(2,1);
    p->msgDialog=MYSTERY_UTIL_CreateDetailWindow(&d,heap);
    if(!d.bank) {
        for(i=0;i<4;i++) {
            if(d.ids[i].str) STRBUF_Delete(d.ids[i].str);
        }
    }
    G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,4,24,15,3);
    MYSTERY_ResetActorAngle(&p->clact);
}

void MYSTERY_DeleteCardMenu(MysteryWork *p) {
 if(p->msgDialog!=0) {BG_SYS_ClearSlot(2);BG_SYS_PushTile(2);BG_SYS_SetPlaneVisible(2,0);MYSTERY_UTIL_DeleteDetailWindow(p->msgDialog);p->msgDialog=0;}
}

int MYSTERY_PollCardMenu(MysteryWork *p) {
 int n=MYSTERY_UTIL_SetVoice(p->msgDialog);
 MYSTERY_RotateActors(&p->clact);
 return n;
}

/*
 * leaf: sole callback blocker of 021D81B0; root claim granted.
 */
void MYSTERY_CardMenuCallback(void *p)
{
    MYSTERY_ResetActorAngle(&((MysteryWork *)p)->clact);
}

/*
 * volatile: hardware argument 04001050 passed to blend helper
 */
void MYSTERY_CreatePartyMenu(MysteryWork *p,int heap)
{
    MysteryPartyDesc c;
    if(p->menuB==0) {
        c=d_021DF544;
        c.e[0].str.stringPtr=STRBUF_Create(37,heap);
        STRBUF_SetStringN(c.e[0].str.stringPtr,p->packet.name,37);
        c.e[1].str.stringPtr=STRBUF_Create(253,heap);
        STRBUF_SetStringN(c.e[1].str.stringPtr,p->packet.title,253);
        p->menuB=MYSTERY_UTIL_CreateWindowList(0,(const char *)&c,2,4,15,p->printQueue,p->msgBank,p->font,heap);
        STRBUF_Delete(c.e[0].str.stringPtr);
        STRBUF_Delete(c.e[1].str.stringPtr);
        MYSTERY_SetupBg(&p->heap,1);
        BG_SYS_PushTile(6);
        BG_SYS_SetPlaneVisible(6,1);
        G2x_SetBlendAlpha_((void *)REG_DB_BLDCNT_ADDR,4,24,15,3);
    }
}

void MYSTERY_DeletePartyMenu(MysteryWork *p) {
 if(p->menuB) {
  *(unsigned short *)0x04001050=0;
  MYSTERY_UTIL_ClearWindowList(p->menuB);MYSTERY_UTIL_DeleteWindowList(p->menuB);
  p->menuB=0;
  BG_SYS_PushTile(4);BG_SYS_SetPlaneVisible(6,0);
 }
}

/*
 * note 2026-10-05 (wave D9r lane P7): real extent is 0x744 bytes (1860); the 2004-byte
 *   listing extent includes the filed follower MYSTERY_InitCardView. Compiled size now equals
 *   the original (1860 bytes); 1055 concrete bytes still differ, almost all from two
 *   small layout residues that shift every later branch target by 2 bytes.
 *   Fixed this wave (from the older draft in docs/notes/pkt_ov121_021D84D4.c.txt):
 *   frame 0x64 -> 0x68 and push {r3-r7} (clamp local zero, arc spilled to its slot,
 *   zero set after the 0202D8D0 statement so the scheduler hoists it next to the call);
 *   D(8) tested as if(D(8)!=0) first (gives the beq over a lone b stub);
 *   the desc[90] > 2 arm written A-first (if(v<=2) set(v); else {v=f(); set(v);}) gives
 *   the bhi over b with the tail cross-jumped; the H(30)==0 failure block written inline
 *   with the failed label inside it; ability default is mon=0; goto image (original
 *   skips the free); move[i] read as a raw u16 at base+i*2 gives add sp/adds #2/ldrh [r0,r1].
 *   Remaining residue: (1) the default arm and the H(74)==0 arm are single b stubs into
 *   the H(30) failure block in the original (b 3F2 and b 3EC); here the copies are not
 *   cross-jumped (default keeps movs r6 + b, H(74) is a plain beq); (2) 02017588's
 *   arguments load id before level in the original (ldr r2,[sp,#0x1c] then r1); (3) the
 *   0186C8 call argument order: original stores [sp,#4] before the zero high word
 *   [sp,#0x34] and loads r2 after the lsls; (4) str r7,[sp] (day) comes after the r2/r3
 *   setup before 0202F2AC in the original.
 *   Tried (about 18 compiles): u64 id local (worse, 1165), separate move array (worse),
 *   separate base local for 020185F0 (no change), pragma scheduling off (no change),
 *   H74 arm written out (merges only blx..b, +8 bytes), value arm B-first (no b stub).
 *   Idioms checked: a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy
 *   (default/H74 stubs still not merged), a-shared-exit-block-is-written-out-in-each-arm
 *   (gave the D8 and value stubs), two-arms-write-the-tail-out-and-the-third-branches-back-into-one
 *   (H74 copy not merged), a-call-before-a-goto-into-the-shared-tail-is-cross-jumped-to-its-bl (no).
 *   Callee prototypes: 020185F0 returns its argument in r0 (stub bx lr), as in the older draft.
 *   Pragma check (per brief): opt_lifetimes off 994 B differ (1864 size), opt_propagation off 1719,
 *   opt_common_subs off 1422, opt_dead_assignments off 1055, peephole off 1055, scheduling off no change.
 *   None closes it, so none is filed. Total compiles this lane: 24.
 * note 2026-10-05 (wave D9r lane P7b): 1055 -> 32 concrete bytes differ (size 1864 = the
 *   real extent; the final literal 0x2CA at +0x744 is shared with the original). Fix: the H(74)==0
 *   arm is a written-out copy of the failure block, `if(H(74)==0){GFL_HEAP_Free(allocated);mon=0;
 *   goto image;}`, not `goto failed` (the copy is cross-jumped into the b stub, the ability
 *   default arm then also becomes the b stub, as in the original; matched twin
 *   MYSTERY_GIFT_CreateMon does the same for its nick and OT-name arms). Also id is now a u64 local
 *   with a separate u32 otId (`id = otId;` before 020173F0), day is u8, as in that twin.
 *   Residue (all instruction-order, no register or slot difference): (1) 020173F0 loads r1 (level)
 *   before r2 (id); (2) 0186C8 arms: ldrb r2,[desc+0x1c] and the str [sp,4]/[sp,0x34] order;
 *   (3) str r7,[sp] (day) before the r2/r3 setup of 0202F2AC instead of last.
 *   Tried this lane (about 17 compiles, plus a static inline wrapper for 0202F2AC (identical)): `default: goto nomon;` with a label inside the
 *   H(30) block (mwcc hangs, killed), function-level labels (default becomes bls table; b, worse),
 *   020173F0 prototype with u16 level (adds lsls/lsrs, worse), u16 level local (slot order
 *   changes, worse), static inline wrapper for 020173F0 (identical output), passing otId
 *   instead of id (identical), 020186C8 third parameter u8 (identical), u8 day (identical),
 *   pragma scheduling off and peephole off (identical). Non-const desc fixes the ldrb placement
 *   in the 0186C8 arms but hoists str [sp,4] above the species load and moves the H(26) load in
 *   02017588 (36 bytes, not kept). Idioms checked: a-conditional-branch-onto-an-unconditional-b-
 *   is-a-cross-jumped-tail-copy (the written-out copy form closes the stubs), a-goto-join-loses-
 *   the-registers-that-repeating-the-tail-in-each-arm-keeps (goto failed loses the stub),
 *   an-inline-wrappers-arguments-are-evaluated-last-to-first (no change),
 *   an-inline-call-argument-is-scheduled-per-site-a-local-is-not (no change),
 *   a-jump-table-bounds-check-turns-into-bls-and-b-when-the-default-is-out-of-range (explains
 *   the default b stub being local).
 * note 2026-10-05 (wave D9r lane P7c): 32 -> 14 concrete bytes differ (size 1864). Fixes from
 *   the matched twins (ov010 02157E9C, ov121 021DD24C): (a) gender is u8, ability and selector
 *   u32 (twin locals; cleared the whole 0186C8 arm residue, 14 B); (b) 020173F0 is called as
 *   in 021DD24C with an explicit zero high word and a u16 level: proto (u16,u16,u32,u32,u32),
 *   call f(species,level,otId,0,tag), with `id=otId;` just before it (the u64 copy is only for
 *   02017588), and level and tag are u16 locals (this gave the original r2-before-r1 loads and
 *   the slot order; a u32 level or the 4-arg u64 form load r1 first).
 *   Remaining residue (one hunk, 2 instructions): `str r7,[sp]` (day) before the call to
 *   0202F2AC sits right after the bl of 020185F0 here; the original (and the twin) emit it
 *   last, after `adds r1,r6,#0`. Tried this lane (about 20 compiles, all no change unless
 *   noted): place as ternary, place inline in the call, u16 place, int w = D(172) date word,
 *   u32 day, day declared first, 0202F2AC proto with u8 day (same), proto u16,u16,u8,u8 (worse),
 *   day inline as (u8)D(172) (worse, 47), place before the date block (worse), day after place
 *   (worse), pragma scheduling off and peephole off (no change).
 *   Idioms checked: a-spilled-constant-high-word-is-a-u32-copied-into-a-u64-before-the-call
 *   (already applied: closed the id copy, and its twin gave the explicit-0 call form).
 * note 2026-10-05 (wave D9r lane P7d): CLOSED, EXACT* (c99 and c). 14 -> 0 B. The date
 *   year local is u32 (`u32 year;` with `year=(u16)((int)D(172)>>16)`), not u16: a spilled
 *   narrow local keeps its reload below the outgoing stack-argument store, a spilled u32
 *   local has its reload hoisted above it, so `str r7,[sp]` (day) now comes last, after
 *   `adds r1,r6,#0`, as in the original (docs/idioms/a-reload-kept-below-outgoing-stack-
 *   stores-is-a-narrow-local.md read the other way round). Compiles this lane: 3.
 */
void MYSTERY_CreateReceivedMon(MysteryCardView *out,void *owner,const u8 *desc,struct GameData *save,MysteryClactActor *list,u16 *bgHeap,MysteryScroll *scroll,u16 heap)
{
    u32 palette;
    void *buf,*mon,*allocated,*str;
    u8 *base;
    int i;
    u32 selector;
    MysteryMonWork work;
    void *arc;
    u32 month;
    u32 year;
    u32 ability;
    u8 gender;
    int clamp;
    u64 random;
    u32 species,otId;
    u16 level,tag;
    u64 id;
    u32 packed,j,place,value;
    u8 day;
    MI_CpuFill8(out,0,sizeof(*out));
    out->scroll=scroll;out->bgHeap=bgHeap;out->heap=heap;out->desc=(const MysteryPacket *)desc;out->value=0;out->value2=0;
    if(desc[714]) palette=3;
    else palette=d_021DF4F2[desc[179]];
    buf=ARC_UTIL_LoadPaletteBlockFromArchive(34,2,&work.resdesc,heap);
    base=work.resdesc->pRawData;
    MI_CpuCopy8(base,out->paletteBuf[3],32);
    MI_CpuCopy8(base+palette*32,out->paletteBuf[2],32);
    GFL_HEAP_Free(buf);
    for(i=0;i<32;i++) CLACT_SetActorPaletteOffset(MYSTERY_GetClactActor(list,i+1),(u8)palette,0);
    switch(desc[179]) {
    case 1:
        mon=0;
        tag=(u16)((heap&0x7FFF)|0x8000);
        level=desc[91];otId=D(0);species=H(26);gender=desc[53];ability=desc[54];
        work.iv[0]=desc[67];work.iv[1]=desc[68];work.iv[2]=desc[69];
        work.iv[3]=desc[71];work.iv[4]=desc[72];work.iv[5]=desc[70];
        work.move[0]=H(18);work.move[1]=H(20);work.move[2]=H(22);work.move[3]=H(24);
        if(desc[179]!=1 || species>SPECIES_LAST || species==0 || level>100 || H(16)>ITEM_LAST) goto image;
        if(level==0) level=(u16)(GFL_USE_GetRandom(100)+1);
        if(D(0)==0) otId=MYSTATUS_GetId((struct MyStatus *)GAME_DATA_GetMyStatus(save));
        if(gender==255) gender=2;
        for(i=0;i<6;i++) if(work.iv[i]==255) work.iv[i]=GFL_USE_GetRandom(32);
        id=otId;
#ifdef __MWERKS__
        allocated=POKE_TOOL_Create(species,level,otId,0,tag);
#else
        allocated=POKE_TOOL_Create(species,level,otId,tag);
#endif
        packed=(work.iv[0]&31)|((u32)work.iv[1]<<27>>22)|((u32)work.iv[2]<<27>>17)|
               ((u32)work.iv[3]<<27>>12)|((u32)work.iv[4]<<27>>7)|((u32)work.iv[5]<<27>>2);
        if(ability==4) ability=(u8)GFL_USE_GetRandom(3);
        switch(ability) {
        case 0:selector=0;break;
        case 1:selector=1;break;
        case 2:selector=0;break;
        case 3:selector=2;break;
        default:mon=0;goto image;
        }
        if(D(8)!=0) random=D(8);
        else {
            if(desc[55]==0) random=POKE_TOOL_CreatePersonalRnd(otId,(u16)species,desc[28],gender,selector,0);
            else if(desc[55]==1) random=POKE_TOOL_CreatePersonalRnd(otId,(u16)species,desc[28],gender,selector,2);
            else if(desc[55]==2) random=POKE_TOOL_CreatePersonalRnd(otId,(u16)species,desc[28],gender,selector,1);
        }
        POKE_TOOL_SetupPartyParamEx(allocated,H(26),level,id,packed,random);
        POKE_TOOL_SetPartyValue(allocated,6,H(16));POKE_TOOL_SetDefaultMoves(allocated);
        for(i=0;i<4;i++) {
            value=*(u16 *)((u8 *)&work.move[0]+i*2);
            if(value!=0 && value<MOVE_LAST+1 && POKE_TOOL_AddMove(allocated,value)==65535) POKE_TOOL_PushMove(allocated,value);
        }
        if(D(8)==0 && ability==2) POKE_TOOL_SetAbility(allocated,species,desc[28]);
        POKE_TOOL_SetPartyValue(allocated,111,desc[28]);
        if(H(14)!=0 && H(14)<=25) POKE_TOOL_SetPartyValue(allocated,152,H(14));
        else POKE_TOOL_SetPartyValue(allocated,152,4);
        if(desc[60]!=0) POKE_TOOL_SetPartyValue(allocated,153,desc[60]);
        POKE_TOOL_SetPartyValue(allocated,19,desc[61]);POKE_TOOL_SetPartyValue(allocated,20,desc[62]);
        POKE_TOOL_SetPartyValue(allocated,21,desc[63]);POKE_TOOL_SetPartyValue(allocated,22,desc[64]);
        POKE_TOOL_SetPartyValue(allocated,23,desc[65]);POKE_TOOL_SetPartyValue(allocated,24,desc[65]);
        for(j=0;j<15;j++) if(H(12)&(1<<j)) POKE_TOOL_SetPartyValue(allocated,d_021DF4FC[j],1);
        if(D(4)==0) POKE_TOOL_SetPartyValue(allocated,119,GAME_VERSION_Code);
        else POKE_TOOL_SetPartyValue(allocated,119,D(4));
        if(desc[29]==0) POKE_TOOL_SetPartyValue(allocated,12,GAME_LANGUAGE_Code);
        else POKE_TOOL_SetPartyValue(allocated,12,desc[29]);
        if(H(30)==0) {
        failed: GFL_HEAP_Free(allocated);
        nomon: mon=0;goto image;
        }
        if(H(30)!=STRBUF_GetEosChar()) POKE_TOOL_SetPartyValue(allocated,116,(uptr)(desc+30));
        value=desc[52];
        if(value==255) value=(u8)GFL_USE_GetRandom(25);
        POKE_TOOL_SetPartyValue(allocated,112,value);
        POKE_TOOL_SetPartyValue(allocated,149,H(56));POKE_TOOL_SetPartyValue(allocated,150,H(58));
        if(H(74)==0) {GFL_HEAP_Free(allocated);mon=0;goto image;}
        if(H(74)==STRBUF_GetEosChar()) POKE_TOOL_SetPartyValue(allocated,142,(uptr)MYSTATUS_GetName(GAME_DATA_GetMyStatus(save)));
        else POKE_TOOL_SetPartyValue(allocated,142,(uptr)(desc+74));
        value=desc[90];
        if(value<=2) POKE_TOOL_SetPartyValue(allocated,154,value);
        else {value=MYSTATUS_GetSex((struct MyStatus *)GAME_DATA_GetMyStatus(save));POKE_TOOL_SetPartyValue(allocated,154,value);}
        if(desc[92]) {
            POKE_TOOL_SetPartyValue(allocated,76,1);
            str=MSGDATA_AllocString(gSpeciesNameBank,650);
            POKE_TOOL_SetPartyValue(allocated,115,(uptr)str);
            STRBUF_Delete(str);POKE_TOOL_SetPartyValue(allocated,9,10);
        }
        year=(u16)((int)D(172)>>16);month=(u8)((int)D(172)>>8);day=(u8)D(172);
        if(desc[92]) place=H(56);else place=H(58);
        SAVE_EVENT_WriteWithDate((struct SaveData *)POKE_TOOL_CastToBoxParam(allocated),place,year-2000,month,day);
        POKE_TOOL_RecalcParam(allocated);
        if(POKE_TOOL_GetPartyValue(allocated,3,0)!=0) {GFL_HEAP_Free(allocated);mon=0;}
        else mon=allocated;
        goto image;
    image:
        arc=POKEGRA_OpenHandle(heap);
        out->palette=POKEGRA_RegisterPalettePP(arc,POKE_TOOL_GetBoxParam(mon),0,0,448,heap);
        clamp=0;
        out->cellAnim=POKEGRA_RegisterCellAnimPP(POKE_TOOL_GetBoxParam(mon),0,2,0,heap);
        out->character=POKEGRA_RegisterCgrPP(arc,POKE_TOOL_GetBoxParam(mon),0,0,heap);
        out->value=MYSTERY_MeasureGraChar(POKE_TOOL_GetBoxParam(mon),heap)-48;
        if(out->value>48) clamp=48;
        else if(out->value>=0) clamp=out->value;
        out->value=clamp;
        ARC_TOOL_DeleteHandle(arc);GFL_HEAP_Free(mon);
        break;
    case 2:
        arc=ARC_TOOL_CreateHandle(25,heap);
        out->palette=CLACT_RegisterPalette(arc,FILE_UTIL_Get((u16)D(0),2),0,448,heap);
        out->cellAnim=CLACT_RegisterCellAnim(arc,1,0,heap);
        out->character=CLACT_RegisterCharacter(arc,FILE_UTIL_Get((u16)D(0),1),0,0,heap);
        ARC_TOOL_DeleteHandle(arc);out->value2=4;out->value=8;
        break;
    case 3:
        arc=ARC_TOOL_CreateHandle(34,heap);
        out->palette=CLACT_RegisterPalette(arc,3,0,448,heap);
        out->cellAnim=CLACT_RegisterCellAnim(arc,33,36,heap);
        out->character=CLACT_RegisterCharacter(arc,12,0,0,heap);
        ARC_TOOL_DeleteHandle(arc);out->value=8;
        break;
    }
    if(desc[714]) {
        MI_CpuCopy8(PALETTE,out->paletteBuf[6],32);
        MIi_CpuClear16(32767,PALETTE,32);
        MI_CpuCopy8(PALETTE,out->paletteBuf[5],32);
    }
    MI_CpuFill8(&work.point,0,8);
    work.point.x=out->value2+128;work.point.y=-96;work.point.b=2;
    out->actor=CLACT_CreateActor((struct Unit *)((void *)(owner)),out->character,out->palette,out->cellAnim,(const struct ActorInitParam *)&work.point,0,heap);
    CLACT_SetActorDrawEnable(out->actor,0);
    if(desc[714]) CLACT_SetActorObjMode(out->actor,1);
}

static inline void GX_SetVisibleWnd(int window)
{
    *(volatile u32 *)REG_DISPCNT_ADDR=(*(volatile u32 *)REG_DISPCNT_ADDR&~0xe000)|(window<<13);
}

static inline void G2_SetWnd0InsidePlane(int wnd,int effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)REG_WININ_ADDR&~0x3f)|(u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)REG_WININ_ADDR=(u16)tmp;
}

static inline void G2_SetWndOutsidePlane(int wnd,int effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)REG_WINOUT_ADDR&~0x3f)|(u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)REG_WINOUT_ADDR=(u16)tmp;
}

static inline void G2_SetWnd0Position(int x1,int y1,int x2,int y2)
{
    *(volatile u16 *)REG_WIN0H_ADDR=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)REG_WIN0V_ADDR=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}

/*
 * volatile: hardware reads/writes at 021D8C4E..021D8C8A: DISPCNT, WININ, WINOUT, WIN0H/V.
 */
void MYSTERY_InitCardView(MysteryCardView *p,int mode)
{
    p->done=0;
    p->state=0;
    p->step=0;
    switch(mode) {
    case 0:
        if (p->desc->flag2CA) p->callback=MYSTERY_CardViewAnimReveal;
        else p->callback=MYSTERY_CardViewAnimScroll;
        break;
    case 1:
        p->callback=MYSTERY_CardViewAnimFade;
        break;
    }
    GX_SetVisibleWnd(1);
    G2_SetWnd0InsidePlane(15,1);
    G2_SetWndOutsidePlane(31,1);
    G2_SetWnd0Position(0,168,255,192);
}

/*
 * volatile: hardware access at 021D8CB2
 */
void MYSTERY_DeleteCardView(MysteryCardView *p)
{
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    if(MYSTERY_IsParticleCreated(&p->particle)) MYSTERY_DeleteParticle(&p->particle);
    BG_SYS_SetPlaneVisible(2,0);
    CLACT_DeleteActor(p->actor);
    CLACT_ReleasePalette((u32)(p->palette));
    CLACT_ReleaseCharacter((u32)(p->character));
    CLACT_ReleaseCellAnim((u32)(p->cellAnim));
    MI_CpuFill8(p,0,sizeof(*p));
}

void MYSTERY_StepCardView(MysteryCardView *p)
{
    if (p->callback != 0) {
        p->callback(p);
        if (p->done != 0)
            p->callback = 0;
    }
}

int MYSTERY_IsCardViewDone(MysteryCardView *p)
{
    return p->done;
}

/*
 * volatile: hardware stores at 021D8D9A and 021D8DEC.
 */
void MYSTERY_CardViewAnimScroll(MysteryCardView *p)
{
    s16 y;
    switch(p->state) {
    case 0:
        BG_SYS_SetPlaneVisible(2,0);
        MYSTERY_SetupBg(p->bgHeap,2);
        p->state=1;
        return;
    case 1:
        G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,4,8,0,16);
        BG_SYS_SetPlaneVisible(2,1);
        p->step=0;
        p->state=2;
        return;
    case 2: {
        u32 n=(p->step*16u)/120u;
        *(volatile u16 *)REG_BLDALPHA_ADDR=(s16)n|((s16)(16-n)<<8);
        p->fade=(p->step*32767u)/120u;
        MYSTERY_UTIL_BlendPaletteRange(15,p->paletteBuf[0],p->fade,0,p->paletteBuf[2],p->paletteBuf[3]);
        MYSTERY_UTIL_BlendPaletteRange(31,p->paletteBuf[1],p->fade,0,p->paletteBuf[2],p->paletteBuf[3]);
        if((p->step)++>120) {
            *(volatile u16 *)REG_BLDCNT_ADDR=0;
            MYSTERY_StartScroll(p->scroll,1);
            p->step=0;
            p->state=3;
            return;
        }
        break;
    }
    case 3:
        if((p->step)++>180) {
            p->step=0;
            p->state=4;
            return;
        }
        break;
    case 4:
        y=((214-p->value)*p->step)/60u-96;
        CLACT_SetActorSurfacePosAxis(p->actor,y,0,1);
        if(y>=-48 && y<=192) CLACT_SetActorDrawEnable(p->actor,1);
        if((p->step)++>=60) {
            GFL_USE_PlaySeDefaultVolume(1649);
            MYSTERY_StartScroll(p->scroll,0);
            p->step=0;
            p->state=5;
            return;
        }
        break;
    case 5:
        if((p->step)++>60) {
            p->step=0;
            p->state=6;
            return;
        }
        break;
    case 6:
        p->done=1;
        break;
    }
}

/*
 * volatile: hardware stores at 021D8F44, 021D8F96, 021D9062, 021D908E, 021D9116.
 */
void MYSTERY_CardViewAnimReveal(MysteryCardView *p)
{
    MysteryScreenPos pos;
    switch(p->state) {
    case 0:
        MYSTERY_CreateParticle(&p->particle,p->heap);
        MYSTERY_LoadParticle(&p->particle,0x22,0x26,p->heap);
        BG_SYS_SetPlaneVisible(2,0);
        MYSTERY_SetupBg(p->bgHeap,2);
        p->state=1;
        return;
    case 1:
        G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,4,8,0,16);
        BG_SYS_SetPlaneVisible(2,1);
        p->step=0;
        p->state=2;
        return;
    case 2: {
        u32 n=(p->step*16u)/120u;
        *(volatile u16 *)REG_BLDALPHA_ADDR=(s16)n|((s16)(16-n)<<8);
        p->fade=(p->step*32767u)/120u;
        MYSTERY_UTIL_BlendPaletteRange(15,p->paletteBuf[0],p->fade,0,p->paletteBuf[2],p->paletteBuf[3]);
        MYSTERY_UTIL_BlendPaletteRange(31,p->paletteBuf[1],p->fade,0,p->paletteBuf[2],p->paletteBuf[3]);
        if((p->step)++>120) {
            *(volatile u16 *)REG_BLDCNT_ADDR=0;
            p->step=0;
            p->state=3;
            return;
        }
        break;
    }
    case 3:
        if((p->step)++>180) {
            p->step=0;
            p->state=6;
            G2x_SetBlendAlpha_((void *)REG_BLDCNT_ADDR,1,31,0,16);
            MYSTERY_StartParticle(&p->particle,0);
            MYSTERY_StartParticle(&p->particle,1);
            MYSTERY_StartParticle(&p->particle,2);
            GFL_USE_PlaySeDefaultVolume(0x794);
            return;
        }
        break;
    case 6:
        if((p->step)++>120) {
            GFL_USE_PlaySeDefaultVolume(0x795);
            p->step=0;
            p->state=4;
            MYSTERY_StartScroll(p->scroll,1);
            return;
        }
        break;
    case 4:
        pos.x=128;
        pos.y=118-p->value;
        CLACT_AddActorSurfacePos((struct ClactActor *)(p->actor),(const struct ClactVec2 *)((const struct Vec2 *)(&pos)),0);
        CLACT_SetActorDrawEnable(p->actor,1);
        p->step2=0;
        p->state=5;
        return;
    case 5: {
        u32 n=(p->step2*16u)/10u;
        *(volatile u16 *)REG_BLDALPHA_ADDR=(s16)n|((s16)(16-n)<<8);
        (p->step)++;
        if((p->step2)++>10) {
            p->step2=0;
            p->state=7;
            return;
        }
        break;
    }
    case 7:
        if((p->step)++>90) {
            *(volatile u16 *)REG_BLDCNT_ADDR=0;
            p->step=0;
            p->state=8;
            return;
        }
        break;
    case 8:
        if((p->step)++>10) {
            p->step=0;
            p->state=9;
            return;
        }
        break;
    case 9:
        p->fade=(p->step*32767u)/120u;
        MYSTERY_UTIL_BlendPaletteRange(14,p->paletteBuf[4],p->fade,14,p->paletteBuf[6],p->paletteBuf[5]);
        if((p->step)++>120) {
            MYSTERY_StartScroll(p->scroll,0);
            p->step=0;
            p->state=10;
            return;
        }
        break;
    case 10:
        if((p->step)++>60) {
            GFL_USE_PlaySeDefaultVolume(0x671);
            p->step=0;
            p->state=11;
            return;
        }
        break;
    case 11:
        *(volatile u16 *)REG_BLDCNT_ADDR=0;
        p->done=1;
        break;
    }
}

void MYSTERY_CardViewAnimFade(MysteryCardView *p)
{
    switch(p->state) {
    case 0: p->state=1; return;
    case 1:
        p->fade=(p->step*32767u)/60u;
        MYSTERY_UTIL_BlendPaletteRange(15,p->paletteBuf[0],p->fade,0,p->paletteBuf[3],p->paletteBuf[2]);
        MYSTERY_UTIL_BlendPaletteRange(31,p->paletteBuf[1],p->fade,0,p->paletteBuf[3],p->paletteBuf[2]);
        if((p->step)++ >60) {
            p->step=0;
            p->state=2;
            return;
        }
        break;
    case 2: p->done=1; break;
    }
}

void MYSTERY_InitScroll(MysteryScroll *p,MysteryClactActor *q,u16 h)
{
    int i;
    s16 xy[2];
    MI_CpuFill8(p,0,sizeof(*p));
    p->value=-819;
    p->clactUnit=q;
    p->startValue=-819;
    p->heapId=h;
    for(i=0;i<32;i++) {
        CLACT_GetActorPos(MYSTERY_GetClactActor(p->clactUnit,i+1),(struct Pt16 *)xy);
        p->y[i]=xy[1]<<12;
        p->vy[i]=GFL_USE_GetRandomBelow(4096)+6554;
    }
}

void MYSTERY_ClearScroll(MysteryScroll *p)
{
    MI_CpuFill8(p, 0, sizeof(*p));
}

void MYSTERY_StepScroll(MysteryScroll *p)
{
    if (p->enabled != 0 && p->active != 0) {
        void (*fp)(MysteryScroll *) = p->callback;
        if (fp != 0)
            fp(p);
    }
}

void MYSTERY_StartScroll(MysteryScroll *p,int n) {
 p->active=1;
 p->step=0;
 p->startValue=p->value;
 switch(n) {case 0: p->callback=MYSTERY_UpdateScrollA;break;case 1:p->callback=MYSTERY_UpdateScrollB;break;}
}

void MYSTERY_SetScrollParam(MysteryScroll *p,unsigned v) { p->enabled=v; }

void MYSTERY_UpdateScrollA(MysteryScroll *p)
{
    int i;
    void *sprite;
    s16 xy[2];
    if(p->value!=-819) {
        int base=p->startValue;
        p->value=base+((-819-base)*p->step)/60;
        if((p->step)++>60) p->value=-819;
    }
    for(i=0;i<32;i++) {
        sprite=MYSTERY_GetClactActor(p->clactUnit,i+1);
        if(CLACT_GetActorDrawEnable(sprite)) {
            p->y[i]=p->y[i]+p->vy[i];
            CLACT_GetActorPos(sprite,(struct Pt16 *)xy);
            xy[1]=p->y[i]>>12;
            CLACT_SetActorPos(sprite,(struct Pt16 *)xy);
            if(xy[1]>=0 && xy[1]<=208) CLACT_SetActorDrawEnable(sprite,1);
            else CLACT_SetActorDrawEnable(sprite,0);
        }
    }
    p->scroll=p->scroll+p->value;
    BG_SYS_ChangeScroll(3,3,p->scroll>>12);
    BG_SYS_ChangeScroll(7,3,p->scroll>>12);
}

void MYSTERY_UpdateScrollB(MysteryScroll *p)
{
    int i;
    void *sprite;
    s16 xy[2];
    if(p->value!=-16384) {
        int base=p->startValue;
        p->value=base+((-16384-base)*p->step)/60;
        if((p->step)++>60) p->value=-16384;
    }
    for(i=0;i<32;i++) {
        p->y[i]=p->y[i]+p->vy[i];
        if(p->y[i]>=851968) p->y[i]=-65536;
        sprite=MYSTERY_GetClactActor(p->clactUnit,i+1);
        CLACT_GetActorPos(sprite,(struct Pt16 *)xy);
        xy[1]=p->y[i]>>12;
        CLACT_SetActorPos(sprite,(struct Pt16 *)xy);
        if(xy[1]>=0 && xy[1]<=208) CLACT_SetActorDrawEnable(sprite,1);
        else CLACT_SetActorDrawEnable(sprite,0);
    }
    p->scroll=p->scroll+p->value;
    BG_SYS_ChangeScroll(3,3,p->scroll>>12);
    BG_SYS_ChangeScroll(7,3,p->scroll>>12);
}

/*
 * extent: two zero alignment bytes at 021D9486; next function starts 021D9488.
 */
void MYSTERY_CreateOamSprite(MysteryOamSprite *p,const MysteryClactActor *q,void *n,struct PrintQueue *k,struct MsgBank *x,int y,struct GfFont *z,u16 heap)
{
    MysteryActorPos pos;
    MI_CpuFill8(p,0,sizeof(*p));
    p->clact=q;
    p->sys=BMP_OAM_CreateSys(heap,n);
    MI_CpuFill8(&pos,0,8);
    pos.x=96; pos.y=169; pos.a=0; pos.b=0;
    p->sprite=MYSTERY_UTIL_CreateTaskEx((const char *)(&pos),8,2,q->palette,3,0,p->sys,k,heap);
    MYSTERY_UTIL_SetActorPairColor(p->sprite,1120);
    MYSTERY_UTIL_SetVec(p->sprite,0,0,1);
    MYSTERY_UTIL_SetActorPairText(p->sprite,x,y,z);
    CLACT_SetActorDrawEnable(MYSTERY_GetClactActor(q,34),1);
}

void MYSTERY_DeleteOamSprite(MysteryOamSprite *p) {
 MYSTERY_UTIL_UpdateActorPair(p->sprite);CLACT_SetActorDrawEnable(MYSTERY_GetClactActor(p->clact,34),0);MYSTERY_UTIL_DeleteActorPair(p->sprite);BMP_OAM_DeleteSys(p->sys);MI_CpuFill8(p,0,sizeof(*p));
}

/*
 * interfaces: named the callee's boolean return; the tail jump forwards it unchanged.
 */
int MYSTERY_PollOamSprite(MysteryOamSprite *p)
{
    return MYSTERY_UTIL_IsMenuFinished(p->sprite);
}

unsigned MYSTERY_MeasureGraChar(void *id,int heap)
{
    unsigned result=48;
    int found=0;
    int row,col,bit;
    NNSG2dCharacterData *object;
    void *allocation;
    u8 *table;
    heap=(heap&32767)|32768;
    allocation=(void *)POKEGRA_LoadCharDataPP(&object,id,(int)0,(u16)heap);
    POKEGRA_ConvertCharTo2D(object,heap);
    for(row=11;row>=0;row--) {
        for(col=0;col<12;col++) {
            unsigned *p=(unsigned *)(*(u8 * *)&((MysteryPokeGraObject *)object)->data+(row*12+col)*32);
            for(bit=7;bit>=0;bit--) {
                if(p[bit]) {
                    unsigned index=row*8+bit;
                    if(result<index) result=index;
                    found=1;
                }
            }
        }
        if(found) break;
    }
    GFL_HEAP_Free(allocation);
    return result;
}

int MYSTERY_IsCardValid(MysteryPacket *p,int n) {
 if(MYSTERY_DATA_CheckPacketCrc((struct MysteryGiftPacket *)p)!=0 && n==0 && (p->crc==0 || (p->crc&PM_VERSION_MASK)!=0)) return 1;
 return 0;
}

/*
 * volatile: hardware rereads at 021D959A..021D95CA
 */
void MYSTERY_SetupDisplay3d(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1,0);
    *(volatile u16 *)REG_BG0CNT_ADDR=(u16)(*(volatile u16 *)REG_BG0CNT_ADDR &~3);
    REG=(u16)((REG&~0x3002)|2);
    REG&=(u16)~0x3010;
    REG&=(u16)~0x3004;
    REG=(u16)((REG&~0x3000)|8);
    REG&=(u16)~0x3020;
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,32767,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,(struct G3dLight *)(d_021DF5E4+i*2));
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
