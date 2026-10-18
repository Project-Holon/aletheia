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
 *   MYSTERY_UTIL_GetTaskField04 0x021DA8AC thumb ov121
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
 *   APP_ENV_InitParentalControl 0x0202EB44 thumb
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
 *   GF_STANDARD_SetField00_F4E4 0x0203F4E4 arm
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
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
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
 *   MYSTATUS_GetOutfitVariant 0x02008550 thumb
 *   MSGDATA_AllocString 0x02045EC0 arm
 *   POKE_TOOL_Dummy 0x020185F0 thumb
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
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   BMP_OAM_CreateSys 0x02025538 thumb
 *   MYSTERY_UTIL_CreateTaskEx 0x021DA8CC thumb ov121
 *   MYSTERY_UTIL_SetFlag 0x021DA9EC thumb ov121
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
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb  arm9
 */

#define PALETTE ((void *)0x050003C0)
#define D(k) (*(u32 *)(desc+(k)))
#define H(k) (*(u16 *)(desc+(k)))
#define O(k) (*(u32 *)(out+(k)))
#define OH(k) (*(u16 *)(out+(k)))
#define REG (*(volatile u16 *)0x04000060)
struct Proc;
struct Big;
struct GfFont;
struct MsgBank;
struct WordSet;
struct PrintSys;
struct Rec;
struct Proc;
struct Obj;
struct RtcDate;
struct U16Vec;
struct Strbuf;
struct Actor;
struct Sub0200852CObj;
struct Mon;
struct Vec2;
struct Pt;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed short s16;

typedef struct { s16 x,y,z; u8 a,b; } MysteryActorPos;

typedef signed int     s32;

typedef struct {int y,m,d,week;} MysteryRtcDate;

typedef struct {u8 bit:1;} MysteryPacketFlag;

typedef struct { u32 w[12]; } MysteryAlbumDesc;

typedef struct { u32 w[9]; } MysteryNetAlbumDesc;

typedef struct { int f0, f4, f8, fc, f10, f14, f18; u16 f1c, f1e, f20, f22; } MysterySaveDesc;

typedef struct { u32 w[9]; s16 h[7]; u16 pad; void *callback,*arg,*result; } MysteryMessageDesc;

typedef struct { int w[12]; } MysteryPartyDesc;

typedef unsigned long long u64;

typedef struct {u8 iv[6];u16 move[4];MysteryActorPos point;void *resdesc;} MysteryMonWork;

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
    u32 field04;
    void *buffer;           /* 0x08 archive member */
    MysteryPtrWord created; /* 0x0C */
} MysteryParticle;

typedef struct {
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
    void *scrollA;          /* 0x024 */
    void *scrollB;          /* 0x028 */
    void *callback;         /* 0x02C */
    u16 fade;               /* 0x030 */
    u16 paletteBuf[7][16];  /* 0x032 seven CLACT palettes */
    u8 pad_112[2];
    void *desc;             /* 0x114 received packet */
    MysteryParticle particle;/* 0x118 */
    s16 value;              /* 0x128 */
    s16 value2;             /* 0x12A */
} MysteryCardView;

typedef struct {
    u32 active;             /* 0x000 */
    u32 field04;
    u16 step;               /* 0x008 */
    u8 pad_00A[2];
    int scroll;             /* 0x00C */
    int value;              /* 0x010 */
    int startValue;         /* 0x014 */
    int y[32];              /* 0x018 */
    int vy[32];             /* 0x098 */
    void *clactUnit;        /* 0x118 */
    MysteryPtrWord callback;/* 0x11C */
    u8 pad_120[4];
    u16 field124;           /* 0x124 */
    u8 pad_126[2];
} MysteryScroll;

typedef struct {
    MysteryPtrWord palette;   /* 0x000 */
    MysteryPtrWord character; /* 0x004 */
    MysteryPtrWord cellAnim;  /* 0x008 */
    void *actors[35];       /* 0x00C */
    u16 field98;            /* 0x098 */
    u8 pad_09A[2];
} MysteryClactActor;

typedef struct {
    void *sys;              /* 0x00 */
    void *sprite;           /* 0x04 */
    void *clact;            /* 0x08 */
} MysteryOamSprite;

typedef struct {
    MysteryPtrWord gameData; /* 0x00 */
    u32 field04;
    u32 flag;               /* 0x08 */
    u32 mode;               /* 0x0C */
    u32 field10;
    u32 saveType;           /* 0x14 */
    u32 field18;
    u32 ready;              /* 0x1C */
    u8 pad_020[8];
} MysteryNetSaveParam;

typedef struct { u8 pad_000[0x0C]; void *data; } MysteryClactResource;

typedef struct { u8 pad_000[0x14]; void *data; } MysteryPokeGraObject;

typedef struct {
    void *album;            /* 0x000 */
    void *albumWork;        /* 0x004 */
    void *netAlbum;         /* 0x008 */
    MysteryCardView cardView;  /* 0x00C */
    MysteryScroll scroll;   /* 0x138 */
    void *saveMenu;         /* 0x260 */
    MysteryOamSprite oam;   /* 0x264 */
    void *msgDialog;        /* 0x270 */
    void *dialogResult[4];  /* 0x274 */
    void *textBox;          /* 0x284 */
    void *menuA;            /* 0x288 */
    void *menuB;            /* 0x28C */
    void *task;             /* 0x290 */
    MysteryClactActor clact;/* 0x294 */
    u8 pad_330[0x60];
    u16 heap;               /* 0x390 */
    u8 pad_392[2];
    void *graphic;          /* 0x394 */
    MysteryPtrWord font;    /* 0x398 */
    MysteryPtrWord printQueue; /* 0x39C */
    MysteryPtrInt msgBankAlt;  /* 0x3A0 */
    MysteryWord msgBank;    /* 0x3A4 */
    MysteryPtrWord wordSet; /* 0x3A8 */
    u32 mode;               /* 0x3AC */
    void *net;              /* 0x3B0 */
    u32 savedValue;         /* 0x3B4 */
    MysteryPtrWord gameData;/* 0x3B8 */
    MysteryPtrWord mysteryData; /* 0x3BC */
    void *saveParam;        /* 0x3C0 */
    u32 timer;              /* 0x3C4 */
    MysteryPtrWord cardSpaceFlag; /* 0x3C8 */
    MysteryPacket packet;   /* 0x3CC */
} MysteryWork;

typedef char MysteryWork_size_check[(sizeof(MysteryWork) == 0x69C) ? 1 : -1];
typedef char MysteryCardView_size_check[(sizeof(MysteryCardView) == 0x12C) ? 1 : -1];
typedef char MysteryScroll_size_check[(sizeof(MysteryScroll) == 0x128) ? 1 : -1];
typedef char MysteryClactActor_size_check[(sizeof(MysteryClactActor) == 0x9C) ? 1 : -1];
typedef char MysteryPacket_size_check[(sizeof(MysteryPacket) == 0x2D0) ? 1 : -1];

extern int GF_OVERLAY_Load(int id);
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
extern void *PROCSYS_AllocProcWork(struct Proc *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *, int, int);
extern void *GAME_DATA_Create(u16 id);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MYSTERY_DATA_Create(void *, void *, void *);
extern u8 *MYSTERY_GRAPHIC_Create(int arg, u16 heap);
extern unsigned MYSTERY_GRAPHIC_GetClactUnit(char *p);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern u32 PRINTSYS_QUE_Create(void *p);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void *MYSTERY_UTIL_CreateTask(void *, void *, u16);
extern void *MYSTERY_UTIL_CreateMenuWindow(int a, u8 b, void *c, void *d, u16 heap);
extern void MYSTERY_UTIL_DrawMenuWindow(u8 *p, int a, int b);
extern void *MYSTERY_NET_Create(void *arg, int heap);
extern void GFL_USE_CancelChangeAndPlayBgm(int, int);
extern void MYSTERY_NET_Delete(u8 *p);
extern void MYSTERY_UTIL_DeleteMenuWindow(u8 *p);
extern void MYSTERY_UTIL_DeleteTask(void *);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void MYSTERY_GRAPHIC_Delete(u8 *p);
extern void MYSTERY_DATA_Delete(void *);
extern void GAME_DATA_Delete(u8 *p);
extern void PROCSYS_FreeProcWork(struct Proc *p);
extern void GFL_HEAP_DeleteChecked(unsigned int);
extern void OS_ResetSystem(u32 parameter);
extern void GF_OVERLAY_Unload(int);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern void MYSTERY_NET_Step(char *p);
extern void MYSTERY_UTIL_DispatchTask(char *p);
extern void MYSTERY_GRAPHIC_Draw(u8 *p);
extern void MYSTERY_GRAPHIC_DrawScene(char *p);
extern void MYSTERY_GRAPHIC_DrawEnd(char *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void MYSTERY_UTIL_UpdateMenuWindow(u8 *p);
extern int MYSTERY_UTIL_IsWindowListDone(u8 *p);
extern int MYSTERY_UTIL_Update(void **);
extern int MYSTERY_UTIL_GetTaskField04(u32 *p);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void ARC_UTIL_UploadPaletteFromHandleWhole();
extern void ARC_UTIL_UploadBgCharFromHandle();
extern void ARC_UTIL_UploadBgPaletteFromHandle(void *,u32,u32,u32,u32,u32,u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BMP_MENUWORK_LoadCharAndPltt(u32,u32,u32,u32,u16);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern int CLACT_RegisterPalette(void *,u32,u32,u32,u16);
extern int CLACT_RegisterCellAnim(void *,u32,u32,u32);
extern int CLACT_RegisterCharacter(void *,u32,u32,u32,u16);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(const void *,void *,int);
extern u32 GFL_HEAP_Free(void *p);
extern struct Obj *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern u32 GFL_USE_GetRandomBelow(u32 range);
extern void CLACT_DeleteActor(struct Obj *p);
extern void CLACT_ReleasePalette(u32 i);
extern void CLACT_ReleaseCharacter(u32 i);
extern void CLACT_ReleaseCellAnim(u32 i);
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern void CLACT_TransferPalette(void *,void *,int);
extern s32 MYSTERY_UTIL_BlendPalette(int a, u16 *p, int angle, int bank, u8 index, u16 c1, u16 c2);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int PARTICLE_CreateSystemDefault(int a, int b, int c, int d);
extern int PARTICLE_LoadArchiveMember(u32 a, u32 b, u32 c);
extern void PARTICLE_SetupSystem(int, int, int, int);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern void MYSTERY_UTIL_SetMenuMessage(u8 *,int,int,int);
extern void MYSTERY_UTIL_SetTaskHandler(u32 *p, u32 a);
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);
extern int FADE_IsActive(void);
extern void GFL_USE_FadeOutBgm(u32 a);
extern void MYSTERY_NET_SetAction(char *,unsigned);
extern int MYSTERY_NET_GetAction(void *);
extern int MYSTERY_NET_GetReceivedData(u8 *p, void *a, u32 b);
extern int MYSTERY_NET_ImportRecords(char *,void *,u16);
extern int MYSTERY_NET_UpdateWifiError(void *);
extern void MYSTERY_NET_Exit(char *p);
extern void MYSTERY_UTIL_SetTaskArg(u32 *p, u32 a);
extern void MYSTERY_UTIL_GetTaskArg(u32 *p);
extern int MYSTERY_UTIL_UpdateMenu(char *);
extern unsigned MYSTERY_UTIL_GetMenuState(u8 *p);
extern u32 KEY_GetTrg(void);
extern void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);
extern int MYSTERY_DATA_IsEventFlag(char *p, unsigned int bit);
extern int MYSTERY_DATA_AddCard(void *p, void *arg);
extern void MYSTERY_DATA_SetEventFlag(void *p, unsigned int idx);
extern u32 MYSTERY_DATA_HasCardSpace(u8 *p);
extern u32 MYSTERY_DATA_GetCardSlotNum(struct Obj *);
extern int MYSTERY_DATA_IsCardReceived(char *p, unsigned int idx);
extern int MYSTERY_DATA_IsMainSave(struct Obj *a0);
extern int APP_ENV_InitParentalControl(void);
extern void *MYSTERY_NET_GetResult(char *p);
extern void MYSTERY_UTIL_SetListValue(u8 *p, u32 i, u32 value);
extern void MYSTERY_GRAPHIC_StartRender(u8 *p);
extern void MYSTERY_DATA_SaveStart(void *a0, int a1);
extern int MYSTERY_DATA_SaveMain(void *a0, int a1);
extern void MYSTERY_GRAPHIC_StopRender(char *p);
extern void *MYSTERY_ALBUM_CreateSlotWork(MysteryAlbumDesc *,u16);
extern void *MYSTERY_ALBUM_CreateAlbumView(void *,void *,void *,u16);
extern void MYSTERY_ALBUM_RequestSetup(u8 *p, u32 b);
extern void MYSTERY_ALBUM_StepIntro(char *p);
extern void MYSTERY_ALBUM_StartIntro(u8 *p);
extern int MYSTERY_ALBUM_IsIntroIdle(char *p);
extern void G2x_SetBlendAlpha_(void *,int,int,int,int);
extern void *MYSTERY_ALBUM_Create(MysteryNetAlbumDesc *,int);
extern void MYSTERY_ALBUM_Update(struct Obj *obj);
extern int MYSTERY_ALBUM_GetWindowState(char *p);
extern void MYSTERY_ALBUM_DeleteWork(struct Obj *obj);
extern void MYSTERY_ALBUM_UpdateWindows(char *p);
extern void PROCSYS_PushGlobal(u32,u32,u32);
extern void GFL_NET_RestartWithDefaultTimeout(u32,u32);
extern void MYSTERY_ALBUM_Delete(char *);
extern void MYSTERY_ALBUM_DeleteSlotWork(void **);
extern void MYSTERY_UTIL_MarkTaskDone(u32 *p);
extern void *MYSTERY_UTIL_CreateMenu(MysterySaveDesc *, int);
extern void MYSTERY_UTIL_DeleteMenu(u8 *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetStringN(struct Strbuf *,const u16 *,u32);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void ARC_UTIL_UploadBgPaletteFromArchive(int,int,int,int,int,int,int);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void BG_SYS_PushTile(u32 index);
extern void *MYSTERY_UTIL_CreateDetailWindow(MysteryMessageDesc *,int);
extern void BG_SYS_ClearSlot(unsigned);
extern void MYSTERY_UTIL_DeleteDetailWindow(u8 *p);
extern int MYSTERY_UTIL_SetVoice(unsigned char *);
extern void *MYSTERY_UTIL_CreateWindowList(int,MysteryPartyDesc *,int,int,int,void *,void *,void *,int);
extern void MYSTERY_UTIL_ClearWindowList(u8 *p);
extern void MYSTERY_UTIL_DeleteWindowList(u8 *p);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern u32 GFL_USE_GetRandom(u32);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj);
extern void *POKE_TOOL_Create(u16,u16,u32,u32,u32);
extern u32 POKE_TOOL_CreatePersonalRnd(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern void POKE_TOOL_SetupPartyParamEx(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void POKE_TOOL_SetPartyValue(void *,u32,u32);
extern u32 POKE_TOOL_SetDefaultMoves(void *);
extern u32 POKE_TOOL_AddMove(void *,u32);
extern void POKE_TOOL_PushMove(void *p, int move);
extern void POKE_TOOL_SetAbility(void *,u32,u32);
extern u16 STRBUF_GetEosChar(void);
extern const void *MYSTATUS_GetName(const void *p);
extern u8 MYSTATUS_GetOutfitVariant(const struct Sub0200852CObj *obj);
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void *POKE_TOOL_Dummy(void *);
extern void SAVE_EVENT_WriteWithDate(void *,u32,u32,u32,u32);
extern void POKE_TOOL_RecalcParam(void *);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern int POKEGRA_OpenHandle(int);
extern void *POKE_TOOL_GetBoxParam(void *);
extern int POKEGRA_RegisterPalettePP(int,void *,int,int,u16,u16);
extern u32 POKEGRA_RegisterCellAnimPP(u32,u32,u32,u32,u16);
extern int POKEGRA_RegisterCgrPP(int,void *,int,int,u16);
extern u32 FILE_UTIL_Get(u32 item, u32 which);
extern void MIi_CpuClear16(u32,void *,u32);
extern void CLACT_SetActorObjMode(struct Actor *actor, u32 value);
extern void MYSTERY_UTIL_BlendPaletteRange(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
extern void CLACT_SetActorSurfacePosAxis(struct Actor *actor, s16 value, u32 space, u32 axis);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void CLACT_GetActorPos(const struct Actor *actor, struct Pt *out);
extern u32 CLACT_GetActorDrawEnable(struct Obj *p);
extern void CLACT_SetActorPos(struct Actor *actor, const struct Pt *src);
extern void BG_SYS_ResetSlot(u32 index, u32 a, u32 b);
extern void *BMP_OAM_CreateSys(unsigned int a0, void *a1);
extern void *MYSTERY_UTIL_CreateTaskEx(const char *p, u16 a, u16 b, int c, u8 d, int e, void *f, void *g, u16 heap);
extern void MYSTERY_UTIL_SetFlag(u8 *p, int a);
extern void MYSTERY_UTIL_SetVec(u32 *p, u32 a, u32 b, u32 c);
extern void MYSTERY_UTIL_SetActorPairText(char *p, int a, int b, int c);
extern void MYSTERY_UTIL_UpdateActorPair(char *p);
extern void MYSTERY_UTIL_DeleteActorPair(unsigned char *p);
extern void BMP_OAM_DeleteSys(void *);
extern int MYSTERY_UTIL_IsMenuFinished(u8 *p);
extern u32 POKEGRA_LoadCharDataPP(void *a0, void *mon, u32 a2, u32 a3);
extern void POKEGRA_ConvertCharTo2D(void *,u16);
extern int MYSTERY_DATA_CheckPacketCrc(u8 *obj);
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
int MYSTERY_Create(void *a, u32 b, u32 c);
int MYSTERY_Delete(void *a, int b, int c, char *p);
int MYSTERY_Main(int a, int b, int c, char *p);
void MYSTERY_InitBgHeap(u16 *p,u16 heap);
void MYSTERY_ExitBgHeap(void *a0);
void MYSTERY_SetupBg(u16 *p,int mode);
void MYSTERY_CreateClact(char *p, void *owner, u16 heap);
void MYSTERY_DeleteClact(u8 *p);
void *MYSTERY_GetClactActor(u8 *p,int i);
void MYSTERY_TransferPalette(u8 *p,int heap);
void MYSTERY_RotateActors(u8 *p);
void MYSTERY_ResetActorAngle(u8 *p);
void MYSTERY_CreateParticle(int *p, int heap);
void MYSTERY_DeleteParticle(void *p);
void MYSTERY_LoadParticle(int *p, int a, int b, int c);
int MYSTERY_StartParticle(void **p, int x);
void *MYSTERY_IsParticleCreated(u8 *p);
void MYSTERY_TaskInitSave(void *a,int b,u8 *p);
void MYSTERY_TaskFadeToMenu(void *a, int *state);
void MYSTERY_TaskExitAlbum(void *a, int *state);
void MYSTERY_TaskMenu(void *task,u32 *state,u8 *p);
void MYSTERY_TaskMenuAction(void *a, int *state, char *p);
void MYSTERY_TaskReceive(void *task,u32 *state,u8 *p);
void MYSTERY_TaskAlbum(void *task,u32 *state,u8 *p);
void MYSTERY_TaskAlbumView(void *task,u32 *state,u8 *p);
void MYSTERY_TaskNetAlbum(void *task,u32 *state,u8 *p);
void MYSTERY_TaskNetExit(void *task,u32 *state,u8 *p);
void MYSTERY_TaskCleanup(void *p,int n,char *q);
void MYSTERY_TaskMessage(void *a, int *state, u8 *p);
void MYSTERY_CreateSaveMenu(u8 *p, int unused, int heap);
void MYSTERY_DeleteSaveMenu(char *p);
void MYSTERY_CreateCardMenu(u8 *p,u32 which,int heap);
void MYSTERY_DeleteCardMenu(char *p);
int MYSTERY_PollCardMenu(char *p);
void MYSTERY_CardMenuCallback(char *p);
void MYSTERY_CreatePartyMenu(u8 *p,int heap);
void MYSTERY_DeletePartyMenu(char *p);
void MYSTERY_CreateReceivedMon(u8 *out,void *owner,const u8 *desc,void *save,void *list,void *a5,void *a6,u16 heap);
void MYSTERY_InitCardView(u8 *p,int mode);
void MYSTERY_DeleteCardView(u8 *p);
void MYSTERY_StepCardView(char *p);
int MYSTERY_IsCardViewDone(char *p);
void MYSTERY_CardViewAnimScroll(u8 *p);
void MYSTERY_CardViewAnimReveal(u8 *p);
void MYSTERY_CardViewAnimFade(u8 *p);
void MYSTERY_InitScroll(u8 *p,void *q,u16 h);
void MYSTERY_ClearScroll(void *p);
void MYSTERY_StepScroll(char *p);
void MYSTERY_StartScroll(char *p,int n);
void MYSTERY_SetScrollParam(unsigned *p,unsigned v);
void MYSTERY_UpdateScrollA(u8 *p);
void MYSTERY_UpdateScrollB(u8 *p);
void MYSTERY_CreateOamSprite(u8 *p,const void *q,int n,int k,int x,int y,int z,u16 heap);
void MYSTERY_DeleteOamSprite(void **p);
int MYSTERY_PollOamSprite(char *p);
unsigned MYSTERY_MeasureGraChar(int id,int heap);
int MYSTERY_IsCardValid(char *p,int n);
void MYSTERY_SetupDisplay3d(void);
extern char ov114_id[];
extern char ov_id[];
extern const char d_021DFB80[];
extern const int gNetSaveMainProc[];
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
    GF_OVERLAY_Load((int)ov114_id);
    GFL_HEAP_CreateChildHeap(1, 29, 0xA0000);
    work = PROCSYS_AllocProcWork(owner, 0x69C, 29);
    MI_CpuFill8(work, 0, 0x69C);
    work->savedValue = arg;
    work->gameData.ptr = GAME_DATA_Create(29);
    work->mysteryData.ptr = MYSTERY_DATA_Create(GAME_DATA_GetSaveControl(work->gameData.ptr), (void *)1, (void *)29);
    work->graphic = MYSTERY_GRAPHIC_Create(1, 29);
    MYSTERY_InitBgHeap(&work->heap, 29);
    MYSTERY_CreateClact((char *)&work->clact, (void *)MYSTERY_GRAPHIC_GetClactUnit((char *)work->graphic), 29);
    work->font.ptr = GF_FONT_Create(23, 0, 0, 0, 29);
    work->printQueue.val = PRINTSYS_QUE_Create((void *)29);
    work->msgBank.ptr = MSGDATA_CreateFromArchive(0, 2, 0x50, 29);
    work->msgBankAlt.ptr = MSGDATA_CreateFromArchive(0, 3, 0x9E, 29);
    work->wordSet.ptr = WORDSET_CreateDefault(29);
    work->task = MYSTERY_UTIL_CreateTask(work, (void *)MYSTERY_TaskInitSave, 29);
    work->textBox = MYSTERY_UTIL_CreateMenuWindow(1, 15, work->printQueue.ptr, work->font.ptr, 29);
    MYSTERY_UTIL_DrawMenuWindow((u8 *)work->textBox, 10, 14);
    work->net = MYSTERY_NET_Create(GAME_DATA_GetSaveControl(work->gameData.ptr), 29);
    MYSTERY_InitScroll((u8 *)&work->scroll, &work->clact, 29);
    MYSTERY_StartScroll((char *)&work->scroll, 0);
    MYSTERY_SetScrollParam((unsigned int *)&work->scroll, 1);
    GFL_USE_CancelChangeAndPlayBgm(1154, 0xFFFF);
    return 1;
}





int MYSTERY_Delete(void *a, int b, int c, char *p)
{
    MYSTERY_ClearScroll(p + 0x138);
    MYSTERY_NET_Delete(((MysteryWork *)p)->net);
    if (((MysteryWork *)p)->textBox) MYSTERY_UTIL_DeleteMenuWindow(((MysteryWork *)p)->textBox);
    MYSTERY_UTIL_DeleteTask(((MysteryWork *)p)->task);
    WORDSET_DeleteStrbufED04(((MysteryWork *)p)->wordSet.ptr);
    MSGDATA_Delete(((MysteryWork *)p)->msgBankAlt.ptr);
    MSGDATA_Delete(((MysteryWork *)p)->msgBank.ptr);
    PRINTSYS_QUE_Delete(((MysteryWork *)p)->printQueue.ptr);
    GF_FONT_Delete(((MysteryWork *)p)->font.ptr);
    MYSTERY_DeleteClact((u8 *)(p + 0x294));
    MYSTERY_ExitBgHeap(p + 0x390);
    MYSTERY_GRAPHIC_Delete(((MysteryWork *)p)->graphic);
    MYSTERY_DATA_Delete(((MysteryWork *)p)->mysteryData.ptr);
    GAME_DATA_Delete(((MysteryWork *)p)->gameData.ptr);
    PROCSYS_FreeProcWork(a);
    GFL_HEAP_DeleteChecked(29);
    OS_ResetSystem(0);
    GF_OVERLAY_Unload((int)ov_id);
    GFL_USE_CancelChangeAndStopBgm();
    return 1;
}





/*
 * follower: two zero padding bytes at 0x021D6922.
 */
int MYSTERY_Main(int a, int b, int c, char *p)
{
    MYSTERY_NET_Step(((MysteryWork *)p)->net);
    MYSTERY_UTIL_DispatchTask(((MysteryWork *)p)->task);
    if (((MysteryWork *)p)->graphic) {
        MYSTERY_GRAPHIC_Draw(((MysteryWork *)p)->graphic);
        MYSTERY_GRAPHIC_DrawScene(((MysteryWork *)p)->graphic);
        MYSTERY_GRAPHIC_DrawEnd(((MysteryWork *)p)->graphic);
    }
    MYSTERY_StepScroll(p + 0x138);
    PRINTSYS_QUE_Main(((MysteryWork *)p)->printQueue.ptr);
    if (((MysteryWork *)p)->textBox) MYSTERY_UTIL_UpdateMenuWindow(((MysteryWork *)p)->textBox);
    if (((MysteryWork *)p)->menuB) MYSTERY_UTIL_IsWindowListDone(((MysteryWork *)p)->menuB);
    if (((MysteryWork *)p)->menuA) MYSTERY_UTIL_IsWindowListDone(((MysteryWork *)p)->menuA);
    if (((MysteryWork *)p)->msgDialog) MYSTERY_UTIL_Update(*(void ** *)&((MysteryWork *)p)->msgDialog);
    if (MYSTERY_UTIL_GetTaskField04(((MysteryWork *)p)->task)) return 1;
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





void MYSTERY_ExitBgHeap(void *a0) { }





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
void MYSTERY_CreateClact(char *p, void *owner, u16 heap)
{
    void *res;
    MysteryActorPos point;
    int bound;
    char *data;
    void *allocation;
    void *arc;
    int i;
    arc=ARC_TOOL_CreateHandle(34,heap);
    *(int *)&((MysteryClactActor *)p)->palette.val=CLACT_RegisterPalette(arc,8,2,0,heap);
    *(int *)&((MysteryClactActor *)p)->cellAnim.val=CLACT_RegisterCellAnim(arc,34,37,heap);
    *(int *)&((MysteryClactActor *)p)->character.val=CLACT_RegisterCharacter(arc,16,0,2,heap);
    allocation=ARC_UTIL_LoadPaletteBlockFromHandle(arc,8,(u32)(&res),heap);
    data=*(char * *)&((MysteryClactResource *)res)->data;
    MI_CpuCopy8(data,p+0xda,32);
    data+=32;
    MI_CpuCopy8(data,p+0xba,32);
    GFL_HEAP_Free(allocation);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(&point,0,8);
    ((MysteryClactActor *)p)->actors[0]=CLACT_CreateActor((void *)owner,((MysteryClactActor *)p)->character.val,((MysteryClactActor *)p)->palette.val,((MysteryClactActor *)p)->cellAnim.val,&point,0,heap);
    CLACT_SetActorDrawEnable(((MysteryClactActor *)p)->actors[0],0);
    bound=256;
    bound+=16;
    for (i=0;i<32;i++) {
        point.x=GFL_USE_GetRandomBelow(256);
        point.y=GFL_USE_GetRandomBelow(256)-bound;
        point.b=3;
        point.z=GFL_USE_GetRandomBelow(6)+3;
        *(void **)(p+i*4+16)=CLACT_CreateActor((void *)owner,((MysteryClactActor *)p)->character.val,((MysteryClactActor *)p)->palette.val,((MysteryClactActor *)p)->cellAnim.val,&point,0,heap);
        CLACT_SetActorDrawEnable(*(void **)(p+i*4+16),0);
    }
    point.x=128;
    point.y=177;
    point.b=0;
    point.a=1;
    point.z=9;
    ((MysteryClactActor *)p)->actors[34]=CLACT_CreateActor((void *)owner,((MysteryClactActor *)p)->character.val,((MysteryClactActor *)p)->palette.val,((MysteryClactActor *)p)->cellAnim.val,&point,0,heap);
    CLACT_SetActorDrawEnable(((MysteryClactActor *)p)->actors[34],0);
}





void MYSTERY_DeleteClact(u8 *p)
{
    int i;
    void *q;
    for(i=0;i<35;i++){
        q=*(void **)(p+i*4+12);
        if(q) CLACT_DeleteActor(q);
    }
    CLACT_ReleasePalette((u32)(((MysteryClactActor *)p)->palette.ptr));
    CLACT_ReleaseCharacter((u32)(((MysteryClactActor *)p)->character.ptr));
    CLACT_ReleaseCellAnim((u32)(((MysteryClactActor *)p)->cellAnim.ptr));
}





void *MYSTERY_GetClactActor(u8 *p,int i) { return *(void **)(p+i*4+12); }





void MYSTERY_TransferPalette(u8 *p,int heap)
{
    void *out;
    void *raw;
    raw=ARC_UTIL_LoadPaletteBlockFromArchive(34,8,(u32)(&out),heap);
    CLACT_TransferPalette(((MysteryClactActor *)p)->palette.ptr,out,7);
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
void MYSTERY_RotateActors(u8 *p)
{
    int i;
    ((MysteryClactActor *)p)->field98 = wrap(1024, (u16 *)(p + 0x98));
    for (i = 0; i < 5; i++)
        MYSTERY_UTIL_BlendPalette(14, (u16 *)(p + 0x9a) + i, ((MysteryClactActor *)p)->field98, 0, (u8)i, *(u16 *)(p + 0xba + i * 2), *(u16 *)(p + 0xda + i * 2));
}





void MYSTERY_ResetActorAngle(u8 *p) { ((MysteryClactActor *)p)->field98=0; }





void MYSTERY_CreateParticle(int *p, int heap)
{
    void *v;
    MI_CpuFill8(p, 0, 16);
    p[3] = 1;
    v = GFL_HEAP_Alloc(heap, 0x4800, 0, d_021DFB80, 0x482);
    p[2] = (int)v;
    p[0] = (int)PARTICLE_CreateSystemDefault((int)v, 0x4800, 1, heap);
}






/*
 * Addresses are Black-image addresses.
 */
void MYSTERY_DeleteParticle(void *p)
{
    GFL_HEAP_Free(((MysteryParticle *)p)->buffer);
    MI_CpuFill8(p, 0, 0x10);
}






/*
 * Promoted from MATCH by the recursive-unblocker lane: 0x0205121C now has an
 * EXACT arm9 shard entry (pkt_0205121C), so the call at +000A resolves via
 * `matched`.  Verified EXACT.
 *
 * Addresses are Black-image addresses.
 */
void MYSTERY_LoadParticle(int *p, int a, int b, int c)
{
    int x = PARTICLE_LoadArchiveMember(a, b, c);
    PARTICLE_SetupSystem(*p, x, 1, 0);
}






int MYSTERY_StartParticle(void **p, int x)
{
    return PARTICLE_StartEffectWithCallback(*p, x, 0, (int)p);
}





void *MYSTERY_IsParticleCreated(u8 *p) { return ((MysteryParticle *)p)->created.ptr; }





void MYSTERY_TaskInitSave(void *a,int b,u8 *p)
{
    MYSTERY_UTIL_SetMenuMessage(*(u8 * *)&((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,79,0);
    MYSTERY_CreateCardMenu(p,0,29);
    MYSTERY_UTIL_SetTaskHandler(a,(u32)MYSTERY_TaskFadeToMenu);
}





void MYSTERY_TaskFadeToMenu(void *a, int *state)
{
    switch (*state) {
    case 0: FADE_Start(3, 16, 0, 0); *state = 1; break;
    case 1: if (!FADE_IsActive()) *state = 2; break;
    case 2: MYSTERY_UTIL_SetTaskHandler(a, (u32)MYSTERY_TaskMenu); break;
    }
}





void MYSTERY_TaskExitAlbum(void *a, int *state)
{
    switch (*state) {
    case 0: FADE_Start(12, 0, 16, 0); GFL_USE_FadeOutBgm(8); *state = 1; break;
    case 1: if (!FADE_IsActive()) *state = 2; break;
    case 2: MYSTERY_UTIL_SetTaskHandler(a, (u32)MYSTERY_TaskCleanup); break;
    }
}





void MYSTERY_TaskMenu(void *task,u32 *state,u8 *p)
{
    int v,flag,all,id;
    u32 i;
    switch(*state) {
    case 0:
        if(((MysteryWork *)p)->cardSpaceFlag.val) {((MysteryWork *)p)->cardSpaceFlag.val=0;*state=2;break;}
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,79,0);
        if(((MysteryWork *)p)->msgDialog==0) MYSTERY_CreateCardMenu(p,0,29);
        *state=1;break;
    case 1:
        v=MYSTERY_PollCardMenu((char *)p);
        if(v!=-1) {
        if(v==0) {
            all=1;
            MYSTERY_DeleteCardMenu((char *)p);
            flag=(MYSTERY_DATA_HasCardSpace(((MysteryWork *)p)->mysteryData.ptr)==0);
            if(flag) {
                for(i=0;i<MYSTERY_DATA_GetCardSlotNum(((MysteryWork *)p)->mysteryData.ptr);i++) {
                    if(MYSTERY_DATA_IsCardReceived(((MysteryWork *)p)->mysteryData.ptr,i)) all=0;
                }
            }
            if(flag) {
                if(all) {
                    if(MYSTERY_DATA_IsMainSave(((MysteryWork *)p)->mysteryData.ptr)==0) id=146;
                    else id=137;
                    MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,id,1);
                    MYSTERY_UTIL_SetTaskArg(task,0);*state=19;
                } else *state=16;
            } else {
                if(APP_ENV_InitParentalControl()==0) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMessage);
                else *state=2;
            }
        } else if(v==1) {
            MYSTERY_DeleteCardMenu((char *)p);MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskAlbumView);
        } else if(v==2) {
            MYSTERY_DeleteCardMenu((char *)p);MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenuAction);
        } else if(v==3) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskExitAlbum);
        else break;
        }
        break;
    case 2:
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,83,1);
        MYSTERY_UTIL_SetTaskArg(task,3);*state=19;break;
    case 3:MYSTERY_CreateSaveMenu(p,0,29);*state=4;break;
    case 4:
        v=MYSTERY_UTIL_UpdateMenu(((MysteryWork *)p)->saveMenu);
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu((char *)p);
            if(v==0) *state=5;else if(v==1) *state=0;
        }
        break;
    case 5:MYSTERY_NET_SetAction(((MysteryWork *)p)->net,1);*state=6;break;
    case 6:if(MYSTERY_NET_GetAction(((MysteryWork *)p)->net)==2) *state=7;break;
    case 7:
        MYSTERY_DeleteCardMenu((char *)p);MYSTERY_CreateCardMenu(p,1,29);
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,86,0);*state=8;break;
    case 8:
        if(((u32)MYSTERY_NET_GetResult(((MysteryWork *)p)->net))&32) MYSTERY_UTIL_SetListValue(((MysteryWork *)p)->msgDialog,0,1);
        else MYSTERY_UTIL_SetListValue(((MysteryWork *)p)->msgDialog,0,0);
        v=MYSTERY_PollCardMenu((char *)p);
        if(v!=-1) {
        MYSTERY_DeleteCardMenu((char *)p);
        switch(v) {
        case 0:((MysteryWork *)p)->mode=0;*state=9;break;
        case 1:((MysteryWork *)p)->mode=1;*state=12;break;
        case 2:((MysteryWork *)p)->mode=2;*state=9;break;
        case 3:*state=14;break;
        }
        }
        break;
    case 9:
        switch(((MysteryWork *)p)->mode) {
        case 0:MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,96,1);MYSTERY_UTIL_SetTaskArg(task,10);*state=19;break;
        case 1:break;
        case 2:MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,102,1);MYSTERY_UTIL_SetTaskArg(task,10);*state=19;break;
        }
        break;
    case 10:MYSTERY_CreateSaveMenu(p,0,29);*state=11;break;
    case 11:
        v=MYSTERY_UTIL_UpdateMenu(((MysteryWork *)p)->saveMenu);
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu((char *)p);
            if(v==0) *state=12;else if(v==1) *state=7;
        }
        break;
    case 12:
        if(MYSTERY_NET_GetAction(((MysteryWork *)p)->net)==2) {MYSTERY_NET_SetAction(((MysteryWork *)p)->net,3);*state=13;}
        break;
    case 13:
        if(MYSTERY_NET_GetAction(((MysteryWork *)p)->net)==0) {
            if(((MysteryWork *)p)->mode==1) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskNetExit);
            else MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskReceive);
        }
        break;
    case 14:
        if(MYSTERY_NET_GetAction(((MysteryWork *)p)->net)==2) {MYSTERY_NET_SetAction(((MysteryWork *)p)->net,3);*state=15;}
        else *state=0;
        break;
    case 15:if(MYSTERY_NET_GetAction(((MysteryWork *)p)->net)==0) *state=0;break;
    case 16:
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,141,1);
        MYSTERY_UTIL_SetTaskArg(task,17);*state=19;break;
    case 17:MYSTERY_CreateSaveMenu(p,0,29);*state=18;break;
    case 18:
        v=MYSTERY_UTIL_UpdateMenu(((MysteryWork *)p)->saveMenu);
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu((char *)p);
            if(v==0) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskNetAlbum);
            else if(v==1) *state=0;
        }
        break;
    case 19:if(MYSTERY_UTIL_GetMenuState(((MysteryWork *)p)->textBox)) MYSTERY_UTIL_GetTaskArg(task);break;
    }
}




void MYSTERY_TaskMenuAction(void *a, int *state, char *p)
{
    int result;
    switch (*state) {
    case 0:
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox, ((MysteryWork *)p)->msgBank.i, 126, 0);
        MYSTERY_CreateCardMenu((u8 *)p, 3, 29);
        *state = 2;
        break;
    case 2:
        result = MYSTERY_PollCardMenu(p);
        if (result == -1) break;
        MYSTERY_DeleteCardMenu(p);
        if (result == 0) {
            MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox, ((MysteryWork *)p)->msgBank.i, 132, 1);
            MYSTERY_UTIL_SetTaskArg(a, 0);
            *state = 3;
        } else if (result == 1) {
            MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox, ((MysteryWork *)p)->msgBank.i, 133, 1);
            MYSTERY_UTIL_SetTaskArg(a, 0);
            *state = 3;
        } else if (result == 2) {
            MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox, ((MysteryWork *)p)->msgBank.i, 134, 1);
            MYSTERY_UTIL_SetTaskArg(a, 0);
            *state = 3;
        } else if (result == 3) {
            MYSTERY_UTIL_SetTaskHandler(a, (u32)MYSTERY_TaskMenu);
        }
        break;
    case 3:
        if (MYSTERY_UTIL_GetMenuState(((MysteryWork *)p)->textBox)) MYSTERY_UTIL_GetTaskArg(a);
        break;
    }
}




void MYSTERY_TaskReceive(void *task,u32 *state,u8 *p)
{
    int v,flag;
    MysteryRtcDate date;
    switch(*state) {
    case 0:
        switch(((MysteryWork *)p)->mode) {
        case 1:MYSTERY_NET_SetAction(((MysteryWork *)p)->net,4);break;
        case 0:MYSTERY_NET_SetAction(((MysteryWork *)p)->net,7);break;
        case 2:MYSTERY_NET_SetAction(((MysteryWork *)p)->net,10);break;
        }
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,105,0);
        ((MysteryWork *)p)->timer=0;*state=1;break;
    case 1:
        if(MYSTERY_NET_GetAction(((MysteryWork *)p)->net)==0) {
            v=MYSTERY_NET_GetReceivedData(((MysteryWork *)p)->net,p+972,720);
            if(v==1) {
                v=MYSTERY_NET_ImportRecords((char *)p+972,((MysteryWork *)p)->gameData.ptr,32797);
                if(MYSTERY_IsCardValid((char *)(p+972),v)) *state=5;
                else *state=12;
            } else if(v==2) *state=2;
        }
        v=MYSTERY_NET_UpdateWifiError(((MysteryWork *)p)->net);
        switch(v) {case 1:case 2:MYSTERY_NET_Exit(((MysteryWork *)p)->net);MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);break;}
        if((KEY_GetTrg()&2) || ((MysteryWork *)p)->timer++>7200) {
            flag=0;
            switch(((MysteryWork *)p)->mode) {
            case 1:
                if(MYSTERY_NET_GetAction(((MysteryWork *)p)->net)==4) {MYSTERY_NET_SetAction(((MysteryWork *)p)->net,5);flag=1;}break;
            case 0:
                if(MYSTERY_NET_GetAction(((MysteryWork *)p)->net)==8) {MYSTERY_NET_SetAction(((MysteryWork *)p)->net,9);flag=1;}break;
            case 2:
                if(MYSTERY_NET_GetAction(((MysteryWork *)p)->net)==11) {MYSTERY_NET_SetAction(((MysteryWork *)p)->net,12);flag=1;}break;
            }
            if(flag) {*state=2;((MysteryWork *)p)->timer=0;}
        }
        break;
    case 2:
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,136,2);
        MYSTERY_UTIL_SetTaskArg(task,3);*state=14;break;
    case 3:
        ((MysteryWork *)p)->timer++;
        if(MYSTERY_NET_GetAction(((MysteryWork *)p)->net)==0 && ((MysteryWork *)p)->timer>30) {
            ((MysteryWork *)p)->timer=0;
            MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,139,1);
            MYSTERY_UTIL_SetTaskArg(task,4);*state=14;
        }
        break;
    case 4:MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);break;
    case 5:
        MYSTERY_CreateCardMenu(p,2,29);MYSTERY_CreatePartyMenu(p,29);
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,106,0);*state=6;break;
    case 6:
        flag=0;v=MYSTERY_PollCardMenu((char *)p);
        if(v!=-1) {
        if(v==0) {
            MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,110,1);
            MYSTERY_UTIL_SetTaskArg(task,7);*state=14;
        } else if(v==-2) flag=1;
        } else if(KEY_GetTrg()&2) flag=1;
        if(flag) {
            MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,107,1);
            MYSTERY_UTIL_SetTaskArg(task,9);*state=14;
        }
        break;
    case 7:MYSTERY_CreateSaveMenu(p,0,29);*state=8;break;
    case 8:
        v=MYSTERY_UTIL_UpdateMenu(((MysteryWork *)p)->saveMenu);
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu((char *)p);
            if(v==0) {
                MYSTERY_DeleteCardMenu((char *)p);
                if(((MysteryPacketFlag *)(p+1152))->bit && MYSTERY_DATA_IsEventFlag(((MysteryWork *)p)->mysteryData.ptr,((MysteryWork *)p)->packet.eventFlag)) {*state=11;break;}
                GF_STANDARD_SetField00_F4E4((struct RtcDate *)(&date));
                ((MysteryWork *)p)->packet.date=(((u32)date.y+2000)<<16)|(((u32)date.m<<24)>>16)|(u8)date.d;
                MYSTERY_DATA_AddCard(((MysteryWork *)p)->mysteryData.ptr,p+972);
                MYSTERY_DATA_SetEventFlag(((MysteryWork *)p)->mysteryData.ptr,((MysteryWork *)p)->packet.eventFlag);
                MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskAlbum);
            } else if(v==1) *state=5;
        }
        break;
    case 9:MYSTERY_CreateSaveMenu(p,0,29);*state=10;break;
    case 10:
        v=MYSTERY_UTIL_UpdateMenu(((MysteryWork *)p)->saveMenu);
        if(v!=-1) {
            MYSTERY_DeleteSaveMenu((char *)p);
            if(v==0) {
                MYSTERY_DeleteCardMenu((char *)p);MYSTERY_DeletePartyMenu((char *)p);
                MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);
            } else if(v==1) *state=5;
        }
        break;
    case 11:
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,138,1);
        MYSTERY_UTIL_SetTaskArg(task,13);*state=14;break;
    case 12:
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,144,1);
        MYSTERY_UTIL_SetTaskArg(task,13);*state=14;break;
    case 13:
        MYSTERY_DeleteCardMenu((char *)p);MYSTERY_DeletePartyMenu((char *)p);
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);break;
    case 14:
        if(MYSTERY_UTIL_GetMenuState(((MysteryWork *)p)->textBox)) MYSTERY_UTIL_GetTaskArg(task);
        break;
    }
}




/*
 * volatile: 0x021D79BC writes the display blend register 0x04000050.
 */
void MYSTERY_TaskAlbum(void *task,u32 *state,u8 *p)
{
    MysteryAlbumDesc d;
    switch (*state) {
    case 0:
        MYSTERY_GRAPHIC_StartRender(((MysteryWork *)p)->graphic);
        BG_SYS_SetPlaneVisible(1,1);
        BG_SYS_SetPlaneVisible(3,1);
        MYSTERY_CreateReceivedMon(p+12,(void *)MYSTERY_GRAPHIC_GetClactUnit(((MysteryWork *)p)->graphic),p+972,(void *)(*(int *)&((MysteryWork *)p)->gameData.ptr),p+660,p+912,p+312,29);
        MYSTERY_InitCardView(p+12,0);
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,113,2);
        *state=1;
        break;
    case 1:
        BG_SYS_SetPlaneVisible(0,1);
        *state=2;
        break;
    case 2:
        if (MYSTERY_UTIL_GetMenuState(((MysteryWork *)p)->textBox)) *state=3;
        break;
    case 3:
        MYSTERY_StepCardView((char *)(p+12));
        if (MYSTERY_IsCardViewDone((char *)(p+12))) *state=4;
        break;
    case 4:
        MYSTERY_DATA_SaveStart(((MysteryWork *)p)->mysteryData.ptr,(int)(((MysteryWork *)p)->gameData.ptr));
        *state=5;
        break;
    case 5:
        if (MYSTERY_DATA_SaveMain(((MysteryWork *)p)->mysteryData.ptr,(int)(((MysteryWork *)p)->gameData.ptr))==2) *state=6;
        break;
    case 6:
        MYSTERY_InitCardView(p+12,1);
        *state=7;
        break;
    case 7:
        MYSTERY_StepCardView((char *)(p+12));
        if (MYSTERY_IsCardViewDone((char *)(p+12))) *state=8;
        break;
    case 8:
        MYSTERY_UTIL_SetMenuMessage(((MysteryWork *)p)->textBox,((MysteryWork *)p)->msgBank.i,114,1);
        *state=9;
        break;
    case 9:
        if (MYSTERY_UTIL_GetMenuState(((MysteryWork *)p)->textBox)) *state=10;
        break;
    case 10:
        MYSTERY_DeleteCardView(p+12);
        MYSTERY_UTIL_DeleteMenuWindow(((MysteryWork *)p)->textBox);
        ((MysteryWork *)p)->textBox=0;
        MYSTERY_DeleteCardMenu((char *)p);
        *(volatile u16 *)0x04000050=0;
        MYSTERY_GRAPHIC_StopRender(((MysteryWork *)p)->graphic);
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
        MI_CpuFill8(&d,0,48);
        d.w[0]=2;
        d.w[1]=0;
        d.w[2]=8;
        d.w[3]=15;
        d.w[5]=13;
        d.w[4]=10;
        d.w[6]=(u32)MYSTERY_GRAPHIC_GetClactUnit(((MysteryWork *)p)->graphic);
        d.w[7]=*(u32 *)&((MysteryWork *)p)->mysteryData.ptr;
        d.w[8]=*(u32 *)&((MysteryWork *)p)->msgBank.i;
        d.w[9]=((MysteryWork *)p)->font.val;
        d.w[10]=((MysteryWork *)p)->printQueue.val;
        d.w[11]=((MysteryWork *)p)->wordSet.val;
        ((MysteryWork *)p)->albumWork=MYSTERY_ALBUM_CreateSlotWork(&d,29);
        ((MysteryWork *)p)->album=MYSTERY_ALBUM_CreateAlbumView(p+972,((MysteryWork *)p)->albumWork,((MysteryWork *)p)->gameData.ptr,29);
        MYSTERY_ALBUM_RequestSetup(((MysteryWork *)p)->album,0);
        *state=13;
        break;
    case 13:
        MYSTERY_ALBUM_StepIntro(((MysteryWork *)p)->album);
        MYSTERY_ALBUM_StartIntro(((MysteryWork *)p)->album);
        *state=14;
        break;
    case 14:
        MYSTERY_ALBUM_StepIntro(((MysteryWork *)p)->album);
        if (MYSTERY_ALBUM_IsIntroIdle(((MysteryWork *)p)->album)) {
            ((MysteryWork *)p)->timer=0;
            *state=15;
        }
        break;
    case 15:
        if (KEY_GetTrg()&1) *state=18;
        if ((((MysteryWork *)p)->timer)++>240) {
            ((MysteryWork *)p)->timer=0;
            *state=16;
        }
        break;
    case 16:
        MYSTERY_CreateOamSprite(p+612,p+660,(int)MYSTERY_GRAPHIC_GetClactUnit(((MysteryWork *)p)->graphic),*(int *)&((MysteryWork *)p)->printQueue.val,((MysteryWork *)p)->msgBank.i,155,*(int *)&((MysteryWork *)p)->font.val,29);
        MYSTERY_PollOamSprite((char *)(p+612));
        *state=17;
        break;
    case 17:
        MYSTERY_PollOamSprite((char *)(p+612));
        if (KEY_GetTrg()&1) {
            MYSTERY_DeleteOamSprite((void **)(p+612));
            *state=18;
        }
        break;
    case 18:
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskExitAlbum);
        break;
    }
}




void MYSTERY_TaskAlbumView(void *task,u32 *state,u8 *p)
{
    MysteryNetAlbumDesc d;
    switch(*state) {
    case 0:
        FADE_Start(3,0,16,-1);
        MYSTERY_UTIL_SetTaskArg(task,1);
        *state=8;
        break;
    case 1:
        MYSTERY_SetScrollParam((unsigned int *)(p+312),0);
        MYSTERY_DeleteCardMenu((char *)p);
        MYSTERY_UTIL_DeleteMenuWindow(((MysteryWork *)p)->textBox);
        ((MysteryWork *)p)->textBox=0;
        MI_CpuFill8(&d,0,36);
        d.w[0]=0;
        d.w[2]=(u32)MYSTERY_GRAPHIC_GetClactUnit(((MysteryWork *)p)->graphic);
        d.w[3]=((MysteryWork *)p)->mysteryData.val;
        d.w[4]=*(u32 *)&((MysteryWork *)p)->font.ptr;
        d.w[5]=*(u32 *)&((MysteryWork *)p)->printQueue.ptr;
        d.w[6]=((MysteryWork *)p)->wordSet.val;
        d.w[7]=((MysteryWork *)p)->msgBank.val;
        d.w[8]=((MysteryWork *)p)->gameData.val;
        ((MysteryWork *)p)->netAlbum=MYSTERY_ALBUM_Create(&d,29);
        *state=2;
        break;
    case 2:
        FADE_Start(3,16,0,-1);
        MYSTERY_UTIL_SetTaskArg(task,3);
        *state=8;
        break;
    case 3:
        MYSTERY_ALBUM_Update(((MysteryWork *)p)->netAlbum);
        if(MYSTERY_ALBUM_GetWindowState(((MysteryWork *)p)->netAlbum)) *state=4;
        break;
    case 4:
        FADE_Start(3,0,16,0);
        MYSTERY_UTIL_SetTaskArg(task,5);
        *state=8;
        break;
    case 5:
        MYSTERY_SetScrollParam((unsigned int *)(p+312),1);
        MYSTERY_ALBUM_DeleteWork(((MysteryWork *)p)->netAlbum);
        ((MysteryWork *)p)->netAlbum=0;
        MYSTERY_SetupBg((u16 *)(p+912),0);
        MYSTERY_TransferPalette(p+660,29);
        ((MysteryWork *)p)->textBox=MYSTERY_UTIL_CreateMenuWindow(1,15,((MysteryWork *)p)->printQueue.ptr,((MysteryWork *)p)->font.ptr,29);
        MYSTERY_UTIL_DrawMenuWindow(((MysteryWork *)p)->textBox,10,14);
        MYSTERY_CreateCardMenu(p,0,29);
        G2x_SetBlendAlpha_((void *)0x04000050,4,24,15,3);
        *state=6;
        break;
    case 6:
        FADE_Start(3,16,0,0);
        MYSTERY_UTIL_SetTaskArg(task,7);
        *state=8;
        break;
    case 7:
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);
        break;
    case 8:
        if(!FADE_IsActive()) MYSTERY_UTIL_GetTaskArg(task);
        break;
    }
    if(((MysteryWork *)p)->netAlbum) MYSTERY_ALBUM_UpdateWindows(((MysteryWork *)p)->netAlbum);
}



void MYSTERY_TaskNetAlbum(void *task,u32 *state,u8 *p)
{
    MysteryNetAlbumDesc d;
    switch(*state) {
    case 0:
        FADE_Start(3,0,16,-1);
        MYSTERY_UTIL_SetTaskArg(task,1);
        *state=8;
        break;
    case 1:
        MYSTERY_SetScrollParam((unsigned int *)(p+312),0);
        MYSTERY_DeleteCardMenu((char *)p);
        MYSTERY_UTIL_DeleteMenuWindow(((MysteryWork *)p)->textBox);
        ((MysteryWork *)p)->textBox=0;
        MI_CpuFill8(&d,0,36);
        d.w[0]=1;
        d.w[2]=(u32)MYSTERY_GRAPHIC_GetClactUnit(((MysteryWork *)p)->graphic);
        d.w[3]=*(u32 *)&((MysteryWork *)p)->mysteryData.ptr;
        d.w[4]=*(u32 *)&((MysteryWork *)p)->font.ptr;
        d.w[5]=*(u32 *)&((MysteryWork *)p)->printQueue.ptr;
        d.w[6]=((MysteryWork *)p)->wordSet.val;
        d.w[7]=((MysteryWork *)p)->msgBank.val;
        d.w[8]=((MysteryWork *)p)->gameData.val;
        ((MysteryWork *)p)->netAlbum=MYSTERY_ALBUM_Create((MysteryNetAlbumDesc *)&d, 29);
        *state=2;
        break;
    case 2:
        FADE_Start(3,16,0,-1);
        MYSTERY_UTIL_SetTaskArg(task,3);
        *state=8;
        break;
    case 3:
        MYSTERY_ALBUM_Update(((MysteryWork *)p)->netAlbum);
        if(MYSTERY_ALBUM_GetWindowState(((MysteryWork *)p)->netAlbum)) *state=4;
        break;
    case 4:
        FADE_Start(3,0,16,0);
        MYSTERY_UTIL_SetTaskArg(task,5);
        *state=8;
        break;
    case 5:
        MYSTERY_SetScrollParam((unsigned int *)(p+312),1);
        MYSTERY_ALBUM_DeleteWork(((MysteryWork *)p)->netAlbum);
        ((MysteryWork *)p)->netAlbum=0;
        MYSTERY_SetupBg((u16 *)(p+912),0);
        MYSTERY_TransferPalette(p+660,29);
        ((MysteryWork *)p)->textBox=MYSTERY_UTIL_CreateMenuWindow(1,15,((MysteryWork *)p)->printQueue.ptr,((MysteryWork *)p)->font.ptr,29);
        MYSTERY_UTIL_DrawMenuWindow(((MysteryWork *)p)->textBox,10,14);
        G2x_SetBlendAlpha_((void *)0x04000050,4,24,15,3);
        MYSTERY_CreateCardMenu(p,0,29);
        *state=6;
        break;
    case 6:
        FADE_Start(3,16,0,0);
        MYSTERY_UTIL_SetTaskArg(task,7);
        *state=8;
        break;
    case 7:
        ((MysteryWork *)p)->cardSpaceFlag.ptr=(void *)MYSTERY_DATA_HasCardSpace(((MysteryWork *)p)->mysteryData.ptr);
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);
        break;
    case 8:
        if(!FADE_IsActive()) MYSTERY_UTIL_GetTaskArg(task);
        break;
    }
    if(((MysteryWork *)p)->netAlbum) MYSTERY_ALBUM_UpdateWindows(((MysteryWork *)p)->netAlbum);
}



void MYSTERY_TaskNetExit(void *task,u32 *state,u8 *p)
{
    int result;
    result=MYSTERY_NET_UpdateWifiError(((MysteryWork *)p)->net);
    switch(result) {
    case 1: case 2:
        MYSTERY_NET_Exit(((MysteryWork *)p)->net);
        MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);
        break;
    }
    switch(*state) {
    case 0:
        FADE_Start(3,0,16,0);
        *state=1; return;
    case 1:
        if(!FADE_IsActive()) {
            MYSTERY_SetScrollParam((unsigned int *)(p+312),0);
            *state=2; return;
        }
        break;
    case 2:
        if(((MysteryWork *)p)->textBox) {
            MYSTERY_UTIL_DeleteMenuWindow(((MysteryWork *)p)->textBox);
            ((MysteryWork *)p)->textBox=0;
        }
        MYSTERY_DeleteClact(p+660);
        MYSTERY_ExitBgHeap(p+912);
        MYSTERY_GRAPHIC_Delete(((MysteryWork *)p)->graphic);
        ((MysteryWork *)p)->graphic=0;
        *state=3; return;
    case 3:
        *(u8 * *)&((MysteryWork *)p)->saveParam=GFL_HEAP_Alloc(29,40,0,d_021DFB80,2664);
        MI_CpuFill8(((MysteryWork *)p)->saveParam,0,40);
        ((MysteryNetSaveParam *)(*(u8 * *)&((MysteryWork *)p)->saveParam))->gameData.val=((MysteryWork *)p)->gameData.val;
        ((MysteryNetSaveParam *)(*(u8 * *)&((MysteryWork *)p)->saveParam))->field04=0;
        ((MysteryNetSaveParam *)(*(u8 * *)&((MysteryWork *)p)->saveParam))->flag=1;
        ((MysteryNetSaveParam *)(*(u8 * *)&((MysteryWork *)p)->saveParam))->field10=0;
        ((MysteryNetSaveParam *)(*(u8 * *)&((MysteryWork *)p)->saveParam))->field18=0;
        ((MysteryNetSaveParam *)(*(u8 * *)&((MysteryWork *)p)->saveParam))->mode=9;
        if(!MYSTERY_DATA_IsMainSave(((MysteryWork *)p)->mysteryData.ptr)) ((MysteryNetSaveParam *)(*(u8 * *)&((MysteryWork *)p)->saveParam))->saveType=2;
        else ((MysteryNetSaveParam *)(*(u8 * *)&((MysteryWork *)p)->saveParam))->saveType=0;
        PROCSYS_PushGlobal((u32)ov115_id,(u32)gNetSaveMainProc,(u32)((MysteryWork *)p)->saveParam);
        *state=5; return;
    case 5:
        ((MysteryWork *)p)->graphic=MYSTERY_GRAPHIC_Create(1,29);
        MYSTERY_InitBgHeap((u16 *)(p+912),29);
        MYSTERY_CreateClact((char *)(p+660),(void *)MYSTERY_GRAPHIC_GetClactUnit(((MysteryWork *)p)->graphic),29);
        ((MysteryWork *)p)->textBox=MYSTERY_UTIL_CreateMenuWindow(1,15,((MysteryWork *)p)->printQueue.ptr,((MysteryWork *)p)->font.ptr,29);
        MYSTERY_UTIL_DrawMenuWindow(((MysteryWork *)p)->textBox,10,14);
        G2x_SetBlendAlpha_((void *)0x04000050,4,24,15,3);
        GFL_NET_RestartWithDefaultTimeout(1,29);
        GFL_USE_CancelChangeAndPlayBgm(1154,65535);
        MYSTERY_SetScrollParam((unsigned int *)(p+312),1);
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
        if(!((MysteryNetSaveParam *)(*(u8 * *)&((MysteryWork *)p)->saveParam))->ready) MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskReceive);
        else MYSTERY_UTIL_SetTaskHandler(task,(u32)MYSTERY_TaskMenu);
        GFL_HEAP_Free(((MysteryWork *)p)->saveParam);
        break;
    }
}



void MYSTERY_TaskCleanup(void *p,int n,char *q) {
 MYSTERY_DeleteSaveMenu(q);MYSTERY_DeleteCardMenu(q);MYSTERY_DeletePartyMenu(q);
 if(*(char * *)&((MysteryWork *)q)->album) {MYSTERY_ALBUM_Delete(*(char * *)&((MysteryWork *)q)->album);MYSTERY_ALBUM_DeleteSlotWork(*(void ** *)&((MysteryWork *)q)->albumWork);}
 MYSTERY_UTIL_MarkTaskDone(p);
}



void MYSTERY_TaskMessage(void *a, int *state, u8 *p)
{
    switch (*state) {
    case 0: MYSTERY_UTIL_SetMenuMessage(*(u8 * *)&((MysteryWork *)p)->textBox, ((MysteryWork *)p)->msgBankAlt.i, 22, 1); *state = 1; break;
    case 1: if (MYSTERY_UTIL_GetMenuState(((MysteryWork *)p)->textBox)) MYSTERY_UTIL_SetTaskHandler(a, (u32)MYSTERY_TaskMenu); break;
    }
}


/*
 * follower: two zero padding bytes at 0x021D8196.
 */
void MYSTERY_CreateSaveMenu(u8 *p, int unused, int heap)
{
    MysterySaveDesc c;
    if (*(int *)&((MysteryWork *)p)->saveMenu == 0) {
        MI_CpuFill8(&c, 0, 0x24);
        c.f0 = ((MysteryWork *)p)->msgBank.i;
        c.f4 = *(int *)&((MysteryWork *)p)->font.val;
        c.f8 = *(int *)&((MysteryWork *)p)->printQueue.val;
        c.fc = 0x54;
        c.f10 = 0x55;
        c.f18 = 2;
        c.f1c = 0;
        c.f1e = 15;
        c.f20 = 14;
        c.f22 = 1;
        ((MysteryWork *)p)->saveMenu = MYSTERY_UTIL_CreateMenu(&c, heap);
    }
}



void MYSTERY_DeleteSaveMenu(char *p)
{
    void *x = ((MysteryWork *)p)->saveMenu;
    if (x != 0) {
        MYSTERY_UTIL_DeleteMenu(x);
        *(u32 *)&((MysteryWork *)p)->saveMenu = 0;
    }
}


void MYSTERY_CreateCardMenu(u8 *p,u32 which,int heap)
{
    MysteryMessageDesc d;
    void *archive;
    int i;
    if(((MysteryWork *)p)->msgDialog) return;
    MI_CpuFill8(&d,0,64);
    d.w[1]=((MysteryWork *)p)->font.val;
    d.w[2]=((MysteryWork *)p)->printQueue.val;
    d.w[3]=(u32)MYSTERY_GetClactActor(p+660,0);
    d.h[0]=1;
    d.h[1]=15;
    d.h[2]=2;
    d.h[3]=4;
    d.callback=MYSTERY_CardMenuCallback;
    d.arg=p;
    d.h[4]=0;
    d.h[5]=0;
    d.h[6]=0;
    d.result=p+628+which*4;
    switch(which) {
    case 0:
        d.w[0]=*(u32 *)&((MysteryWork *)p)->msgBank.i;
        d.w[4]=80; d.w[5]=81; d.w[6]=131; d.w[7]=82; d.w[8]=4;
        break;
    case 1:
        d.w[0]=*(u32 *)&((MysteryWork *)p)->msgBank.i;
        d.w[4]=87; d.w[5]=88; d.w[6]=89; d.w[7]=90; d.w[8]=4;
        break;
    case 2:
        d.w[0]=0;
        d.w[4]=(u32)STRBUF_Create(37,heap);
        STRBUF_SetStringN((struct Strbuf *)d.w[4],(const u16 *)(p+1068),37);
        d.w[8]=1;
        d.h[4]=-1;
        d.h[5]=-2;
        d.h[6]=10;
        break;
    case 3:
        d.w[0]=*(u32 *)&((MysteryWork *)p)->msgBank.i;
        d.w[4]=127; d.w[5]=128; d.w[6]=129; d.w[7]=130; d.w[8]=4;
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
    ((MysteryWork *)p)->msgDialog=MYSTERY_UTIL_CreateDetailWindow(&d,heap);
    if(!d.w[0]) {
        for(i=0;i<4;i++) {
            if(d.w[4+i]) STRBUF_Delete((void *)d.w[4+i]);
        }
    }
    G2x_SetBlendAlpha_((void *)0x04000050,4,24,15,3);
    MYSTERY_ResetActorAngle(p+660);
}


void MYSTERY_DeleteCardMenu(char *p) {
 if(((MysteryWork *)p)->msgDialog!=0) {BG_SYS_ClearSlot(2);BG_SYS_PushTile(2);BG_SYS_SetPlaneVisible(2,0);MYSTERY_UTIL_DeleteDetailWindow(((MysteryWork *)p)->msgDialog);*(unsigned *)&((MysteryWork *)p)->msgDialog=0;}
}


int MYSTERY_PollCardMenu(char *p) {
 int n=MYSTERY_UTIL_SetVoice(*(unsigned char * *)&((MysteryWork *)p)->msgDialog);
 MYSTERY_RotateActors((u8 *)(p+0x294));
 return n;
}


/*
 * leaf: sole callback blocker of 021D81B0; root claim granted.
 */
void MYSTERY_CardMenuCallback(char *p)
{
    MYSTERY_ResetActorAngle((u8 *)(p+660));
}


/*
 * volatile: hardware argument 04001050 passed to blend helper
 */
void MYSTERY_CreatePartyMenu(u8 *p,int heap)
{
    MysteryPartyDesc c;
    if(((MysteryWork *)p)->menuB==0) {
        c=d_021DF544;
        c.w[2]=(int)STRBUF_Create(37,heap);
        STRBUF_SetStringN((struct Strbuf *)c.w[2],(const unsigned short *)(p+1068),37);
        c.w[8]=(int)STRBUF_Create(253,heap);
        STRBUF_SetStringN((struct Strbuf *)c.w[8],(const unsigned short *)(p+1180),253);
        ((MysteryWork *)p)->menuB=MYSTERY_UTIL_CreateWindowList(0,&c,2,4,15,((MysteryWork *)p)->printQueue.ptr,((MysteryWork *)p)->msgBank.ptr,((MysteryWork *)p)->font.ptr,heap);
        STRBUF_Delete((void *)c.w[2]);
        STRBUF_Delete((void *)c.w[8]);
        MYSTERY_SetupBg((u16 *)(p+912),1);
        BG_SYS_PushTile(6);
        BG_SYS_SetPlaneVisible(6,1);
        G2x_SetBlendAlpha_((void *)0x04001050,4,24,15,3);
    }
}


void MYSTERY_DeletePartyMenu(char *p) {
 if(((MysteryWork *)p)->menuB) {
  *(unsigned short *)0x04001050=0;
  MYSTERY_UTIL_ClearWindowList(((MysteryWork *)p)->menuB);MYSTERY_UTIL_DeleteWindowList(((MysteryWork *)p)->menuB);
  *(unsigned *)&((MysteryWork *)p)->menuB=0;
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
void MYSTERY_CreateReceivedMon(u8 *out,void *owner,const u8 *desc,void *save,void *list,void *a5,void *a6,u16 heap)
{
    u32 palette;
    void *buf,*mon,*allocated,*str;
    u8 *base;
    int i;
    u32 selector;
    MysteryMonWork work;
    u32 arc;
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
    MI_CpuFill8(out,0,300);
    O(40)=(u32)a6;O(36)=(u32)a5;OH(0)=heap;O(276)=(u32)desc;OH(296)=0;OH(298)=0;
    if(desc[714]) palette=3;
    else palette=d_021DF4F2[desc[179]];
    buf=ARC_UTIL_LoadPaletteBlockFromArchive(34,2,(u32)&work.resdesc,heap);
    base=*(u8 **)((u8 *)work.resdesc+12);
    MI_CpuCopy8(base,out+146,32);
    MI_CpuCopy8(base+palette*32,out+114,32);
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
        if(desc[179]!=1 || species>649 || species==0 || level>100 || H(16)>626) goto image;
        if(level==0) level=(u16)(GFL_USE_GetRandom(100)+1);
        if(D(0)==0) otId=MYSTATUS_GetId((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(save));
        if(gender==255) gender=2;
        for(i=0;i<6;i++) if(work.iv[i]==255) work.iv[i]=GFL_USE_GetRandom(32);
        id=otId;
        allocated=POKE_TOOL_Create(species,level,otId,0,tag);
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
            if(value!=0 && value<560 && POKE_TOOL_AddMove(allocated,value)==65535) POKE_TOOL_PushMove(allocated,value);
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
        if(H(30)!=STRBUF_GetEosChar()) POKE_TOOL_SetPartyValue(allocated,116,(u32)(desc+30));
        value=desc[52];
        if(value==255) value=(u8)GFL_USE_GetRandom(25);
        POKE_TOOL_SetPartyValue(allocated,112,value);
        POKE_TOOL_SetPartyValue(allocated,149,H(56));POKE_TOOL_SetPartyValue(allocated,150,H(58));
        if(H(74)==0) {GFL_HEAP_Free(allocated);mon=0;goto image;}
        if(H(74)==STRBUF_GetEosChar()) POKE_TOOL_SetPartyValue(allocated,142,(u32)MYSTATUS_GetName(GAME_DATA_GetMyStatus(save)));
        else POKE_TOOL_SetPartyValue(allocated,142,(u32)(desc+74));
        value=desc[90];
        if(value<=2) POKE_TOOL_SetPartyValue(allocated,154,value);
        else {value=MYSTATUS_GetOutfitVariant((const struct Sub0200852CObj *)GAME_DATA_GetMyStatus(save));POKE_TOOL_SetPartyValue(allocated,154,value);}
        if(desc[92]) {
            POKE_TOOL_SetPartyValue(allocated,76,1);
            str=MSGDATA_AllocString(gSpeciesNameBank,650);
            POKE_TOOL_SetPartyValue(allocated,115,(u32)str);
            STRBUF_Delete(str);POKE_TOOL_SetPartyValue(allocated,9,10);
        }
        year=(u16)((int)D(172)>>16);month=(u8)((int)D(172)>>8);day=(u8)D(172);
        if(desc[92]) place=H(56);else place=H(58);
        SAVE_EVENT_WriteWithDate(POKE_TOOL_Dummy(allocated),place,year-2000,month,day);
        POKE_TOOL_RecalcParam(allocated);
        if(POKE_TOOL_GetPartyValue(allocated,3,0)!=0) {GFL_HEAP_Free(allocated);mon=0;}
        else mon=allocated;
        goto image;
    image:
        arc=POKEGRA_OpenHandle(heap);
        O(12)=POKEGRA_RegisterPalettePP((int)arc,POKE_TOOL_GetBoxParam(mon),0,0,448,heap);
        clamp=0;
        O(20)=POKEGRA_RegisterCellAnimPP((u32)POKE_TOOL_GetBoxParam(mon),0,2,0,heap);
        O(16)=POKEGRA_RegisterCgrPP((int)arc,POKE_TOOL_GetBoxParam(mon),0,0,heap);
        OH(296)=MYSTERY_MeasureGraChar((int)POKE_TOOL_GetBoxParam(mon),heap)-48;
        if(*(s16 *)(out+296)>48) clamp=48;
        else if(*(s16 *)(out+296)>=0) clamp=*(s16 *)(out+296);
        OH(296)=clamp;
        ARC_TOOL_DeleteHandle((void *)arc);GFL_HEAP_Free(mon);
        break;
    case 2:
        arc=(u32)ARC_TOOL_CreateHandle(25,heap);
        O(12)=CLACT_RegisterPalette((void *)arc,FILE_UTIL_Get((u16)D(0),2),0,448,heap);
        O(20)=CLACT_RegisterCellAnim((void *)arc,1,0,heap);
        O(16)=CLACT_RegisterCharacter((void *)arc,FILE_UTIL_Get((u16)D(0),1),0,0,heap);
        ARC_TOOL_DeleteHandle((void *)arc);OH(298)=4;OH(296)=8;
        break;
    case 3:
        arc=(u32)ARC_TOOL_CreateHandle(34,heap);
        O(12)=CLACT_RegisterPalette((void *)arc,3,0,448,heap);
        O(20)=CLACT_RegisterCellAnim((void *)arc,33,36,heap);
        O(16)=CLACT_RegisterCharacter((void *)arc,12,0,0,heap);
        ARC_TOOL_DeleteHandle((void *)arc);OH(296)=8;
        break;
    }
    if(desc[714]) {
        MI_CpuCopy8(PALETTE,out+242,32);
        MIi_CpuClear16(32767,PALETTE,32);
        MI_CpuCopy8(PALETTE,out+210,32);
    }
    MI_CpuFill8(&work.point,0,8);
    work.point.x=*(s16 *)(out+298)+128;work.point.y=-96;work.point.b=2;
    O(4)=(u32)CLACT_CreateActor((void *)((u32)owner),O(16),O(12),O(20),&work.point,0,heap);
    CLACT_SetActorDrawEnable((void *)O(4),0);
    if(desc[714]) CLACT_SetActorObjMode((void *)O(4),1);
}


static inline void GX_SetVisibleWnd(int window)
{
    *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|(window<<13);
}


static inline void G2_SetWnd0InsidePlane(int wnd,int effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x04000048&~0x3f)|(u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)0x04000048=(u16)tmp;
}


static inline void G2_SetWndOutsidePlane(int wnd,int effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x0400004a&~0x3f)|(u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)0x0400004a=(u16)tmp;
}


static inline void G2_SetWnd0Position(int x1,int y1,int x2,int y2)
{
    *(volatile u16 *)0x04000040=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04000044=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}


/*
 * volatile: hardware reads/writes at 021D8C4E..021D8C8A: DISPCNT, WININ, WINOUT, WIN0H/V.
 */
void MYSTERY_InitCardView(u8 *p,int mode)
{
    ((MysteryCardView *)p)->done=0;
    ((MysteryCardView *)p)->state=0;
    ((MysteryCardView *)p)->step=0;
    switch(mode) {
    case 0:
        if (((MysteryPacket *)(*(u8 * *)&((MysteryCardView *)p)->desc))->flag2CA) *(void (**)(u8 *))(p+44)=MYSTERY_CardViewAnimReveal;
        else *(void (**)(u8 *))(p+44)=MYSTERY_CardViewAnimScroll;
        break;
    case 1:
        *(void (**)(u8 *))(p+44)=MYSTERY_CardViewAnimFade;
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
void MYSTERY_DeleteCardView(u8 *p)
{
    *(volatile unsigned *)0x04000000 &= 0xFFFF1FFF;
    if(MYSTERY_IsParticleCreated(p+280)) MYSTERY_DeleteParticle(p+280);
    BG_SYS_SetPlaneVisible(2,0);
    CLACT_DeleteActor(((MysteryCardView *)p)->actor);
    CLACT_ReleasePalette((u32)(((MysteryCardView *)p)->palette));
    CLACT_ReleaseCharacter((u32)(((MysteryCardView *)p)->character));
    CLACT_ReleaseCellAnim((u32)(((MysteryCardView *)p)->cellAnim));
    MI_CpuFill8(p,0,300);
}



void MYSTERY_StepCardView(char *p)
{
    if (*(void (**)(void))(p + 0x2c) != 0) {
        (*(void (**)(char *))(p + 0x2c))(p);
        if (((MysteryCardView *)p)->done != 0)
            *(u32 *)&((MysteryCardView *)p)->callback = 0;
    }
}


int MYSTERY_IsCardViewDone(char *p)
{
    return ((MysteryCardView *)p)->done;
}


/*
 * volatile: hardware stores at 021D8D9A and 021D8DEC.
 */
void MYSTERY_CardViewAnimScroll(u8 *p)
{
    s16 y;
    switch(((MysteryCardView *)p)->state) {
    case 0:
        BG_SYS_SetPlaneVisible(2,0);
        MYSTERY_SetupBg(((MysteryCardView *)p)->scrollA,2);
        ((MysteryCardView *)p)->state=1;
        return;
    case 1:
        G2x_SetBlendAlpha_((void *)0x04000050,4,8,0,16);
        BG_SYS_SetPlaneVisible(2,1);
        ((MysteryCardView *)p)->step=0;
        ((MysteryCardView *)p)->state=2;
        return;
    case 2: {
        u32 n=(((MysteryCardView *)p)->step*16u)/120u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        ((MysteryCardView *)p)->fade=(((MysteryCardView *)p)->step*32767u)/120u;
        MYSTERY_UTIL_BlendPaletteRange((void *)15,(u16 *)(p+50),((MysteryCardView *)p)->fade,0,(const u16 *)(p+114),(const u16 *)(p+146));
        MYSTERY_UTIL_BlendPaletteRange((void *)31,(u16 *)(p+82),((MysteryCardView *)p)->fade,0,(const u16 *)(p+114),(const u16 *)(p+146));
        if((((MysteryCardView *)p)->step)++>120) {
            *(volatile u16 *)0x04000050=0;
            MYSTERY_StartScroll(((MysteryCardView *)p)->scrollB,1);
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=3;
            return;
        }
        break;
    }
    case 3:
        if((((MysteryCardView *)p)->step)++>180) {
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=4;
            return;
        }
        break;
    case 4:
        y=((214-((MysteryCardView *)p)->value)*((MysteryCardView *)p)->step)/60u-96;
        CLACT_SetActorSurfacePosAxis(((MysteryCardView *)p)->actor,y,0,1);
        if(y>=-48 && y<=192) CLACT_SetActorDrawEnable(((MysteryCardView *)p)->actor,1);
        if((((MysteryCardView *)p)->step)++>=60) {
            GFL_USE_PlaySeDefaultVolume(1649);
            MYSTERY_StartScroll(((MysteryCardView *)p)->scrollB,0);
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=5;
            return;
        }
        break;
    case 5:
        if((((MysteryCardView *)p)->step)++>60) {
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=6;
            return;
        }
        break;
    case 6:
        ((MysteryCardView *)p)->done=1;
        break;
    }
}


/*
 * volatile: hardware stores at 021D8F44, 021D8F96, 021D9062, 021D908E, 021D9116.
 */
void MYSTERY_CardViewAnimReveal(u8 *p)
{
    MysteryScreenPos pos;
    switch(((MysteryCardView *)p)->state) {
    case 0:
        MYSTERY_CreateParticle((int *)(p+0x118),((MysteryCardView *)p)->heap);
        MYSTERY_LoadParticle((int *)(p+0x118),0x22,0x26,((MysteryCardView *)p)->heap);
        BG_SYS_SetPlaneVisible(2,0);
        MYSTERY_SetupBg(*(u16 * *)&((MysteryCardView *)p)->scrollA,2);
        ((MysteryCardView *)p)->state=1;
        return;
    case 1:
        G2x_SetBlendAlpha_((void *)0x04000050,4,8,0,16);
        BG_SYS_SetPlaneVisible(2,1);
        ((MysteryCardView *)p)->step=0;
        ((MysteryCardView *)p)->state=2;
        return;
    case 2: {
        u32 n=(((MysteryCardView *)p)->step*16u)/120u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        ((MysteryCardView *)p)->fade=(((MysteryCardView *)p)->step*32767u)/120u;
        MYSTERY_UTIL_BlendPaletteRange((void *)15,(u16 *)(p+50),((MysteryCardView *)p)->fade,0,(const u16 *)(p+114),(const u16 *)(p+146));
        MYSTERY_UTIL_BlendPaletteRange((void *)31,(u16 *)(p+82),((MysteryCardView *)p)->fade,0,(const u16 *)(p+114),(const u16 *)(p+146));
        if((((MysteryCardView *)p)->step)++>120) {
            *(volatile u16 *)0x04000050=0;
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=3;
            return;
        }
        break;
    }
    case 3:
        if((((MysteryCardView *)p)->step)++>180) {
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=6;
            G2x_SetBlendAlpha_((void *)0x04000050,1,31,0,16);
            MYSTERY_StartParticle((void **)(p+0x118),0);
            MYSTERY_StartParticle((void **)(p+0x118),1);
            MYSTERY_StartParticle((void **)(p+0x118),2);
            GFL_USE_PlaySeDefaultVolume(0x794);
            return;
        }
        break;
    case 6:
        if((((MysteryCardView *)p)->step)++>120) {
            GFL_USE_PlaySeDefaultVolume(0x795);
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=4;
            MYSTERY_StartScroll(((MysteryCardView *)p)->scrollB,1);
            return;
        }
        break;
    case 4:
        pos.x=128;
        pos.y=118-((MysteryCardView *)p)->value;
        CLACT_AddActorSurfacePos(((MysteryCardView *)p)->actor,(const struct Vec2 *)(&pos),0);
        CLACT_SetActorDrawEnable(((MysteryCardView *)p)->actor,1);
        ((MysteryCardView *)p)->step2=0;
        ((MysteryCardView *)p)->state=5;
        return;
    case 5: {
        u32 n=(((MysteryCardView *)p)->step2*16u)/10u;
        *(volatile u16 *)0x04000052=(s16)n|((s16)(16-n)<<8);
        (((MysteryCardView *)p)->step)++;
        if((((MysteryCardView *)p)->step2)++>10) {
            ((MysteryCardView *)p)->step2=0;
            ((MysteryCardView *)p)->state=7;
            return;
        }
        break;
    }
    case 7:
        if((((MysteryCardView *)p)->step)++>90) {
            *(volatile u16 *)0x04000050=0;
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=8;
            return;
        }
        break;
    case 8:
        if((((MysteryCardView *)p)->step)++>10) {
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=9;
            return;
        }
        break;
    case 9:
        ((MysteryCardView *)p)->fade=(((MysteryCardView *)p)->step*32767u)/120u;
        MYSTERY_UTIL_BlendPaletteRange((void *)14,(u16 *)(p+178),((MysteryCardView *)p)->fade,14,(const u16 *)(p+242),(const u16 *)(p+210));
        if((((MysteryCardView *)p)->step)++>120) {
            MYSTERY_StartScroll(((MysteryCardView *)p)->scrollB,0);
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=10;
            return;
        }
        break;
    case 10:
        if((((MysteryCardView *)p)->step)++>60) {
            GFL_USE_PlaySeDefaultVolume(0x671);
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=11;
            return;
        }
        break;
    case 11:
        *(volatile u16 *)0x04000050=0;
        ((MysteryCardView *)p)->done=1;
        break;
    }
}


void MYSTERY_CardViewAnimFade(u8 *p)
{
    switch(((MysteryCardView *)p)->state) {
    case 0: ((MysteryCardView *)p)->state=1; return;
    case 1:
        ((MysteryCardView *)p)->fade=(((MysteryCardView *)p)->step*32767u)/60u;
        MYSTERY_UTIL_BlendPaletteRange((void *)15,(u16 *)(p+50),((MysteryCardView *)p)->fade,0,(const u16 *)(p+146),(const u16 *)(p+114));
        MYSTERY_UTIL_BlendPaletteRange((void *)31,(u16 *)(p+82),((MysteryCardView *)p)->fade,0,(const u16 *)(p+146),(const u16 *)(p+114));
        if((((MysteryCardView *)p)->step)++ >60) {
            ((MysteryCardView *)p)->step=0;
            ((MysteryCardView *)p)->state=2;
            return;
        }
        break;
    case 2: ((MysteryCardView *)p)->done=1; break;
    }
}


void MYSTERY_InitScroll(u8 *p,void *q,u16 h)
{
    int i;
    s16 xy[2];
    MI_CpuFill8(p,0,296);
    ((MysteryScroll *)p)->value=-819;
    ((MysteryScroll *)p)->clactUnit=q;
    ((MysteryScroll *)p)->startValue=-819;
    ((MysteryScroll *)p)->field124=h;
    for(i=0;i<32;i++) {
        CLACT_GetActorPos(MYSTERY_GetClactActor(((MysteryScroll *)p)->clactUnit,i+1),(struct Pt *)xy);
        ((MysteryScroll *)p)->y[i]=xy[1]<<12;
        ((MysteryScroll *)p)->vy[i]=GFL_USE_GetRandomBelow(4096)+6554;
    }
}



void MYSTERY_ClearScroll(void *p)
{
    MI_CpuFill8(p, 0, 0x128);
}



void MYSTERY_StepScroll(char *p)
{
    if (((MysteryScroll *)p)->field04 != 0 && ((MysteryScroll *)p)->active != 0) {
        void (*fp)(char *) = *(void (**)(char *))(p + 0x11c);
        if (fp != 0)
            fp(p);
    }
}


void MYSTERY_StartScroll(char *p,int n) {
 ((MysteryScroll *)p)->active=1;
 ((MysteryScroll *)p)->step=0;
 ((MysteryScroll *)p)->startValue=((MysteryScroll *)p)->value;
 switch(n) {case 0: ((MysteryScroll *)p)->callback.val=(unsigned)MYSTERY_UpdateScrollA;break;case 1:((MysteryScroll *)p)->callback.val=(unsigned)MYSTERY_UpdateScrollB;break;}
}


void MYSTERY_SetScrollParam(unsigned *p,unsigned v) { p[1]=v; }


void MYSTERY_UpdateScrollA(u8 *p)
{
    int i;
    void *sprite;
    s16 xy[2];
    if(((MysteryScroll *)p)->value!=-819) {
        int base=((MysteryScroll *)p)->startValue;
        ((MysteryScroll *)p)->value=base+((-819-base)*((MysteryScroll *)p)->step)/60;
        if((((MysteryScroll *)p)->step)++>60) ((MysteryScroll *)p)->value=-819;
    }
    for(i=0;i<32;i++) {
        sprite=MYSTERY_GetClactActor(((MysteryScroll *)p)->clactUnit,i+1);
        if(CLACT_GetActorDrawEnable(sprite)) {
            ((MysteryScroll *)p)->y[i]=((MysteryScroll *)p)->y[i]+((MysteryScroll *)p)->vy[i];
            CLACT_GetActorPos(sprite,(struct Pt *)xy);
            xy[1]=((MysteryScroll *)p)->y[i]>>12;
            CLACT_SetActorPos(sprite,(const struct Pt *)xy);
            if(xy[1]>=0 && xy[1]<=208) CLACT_SetActorDrawEnable(sprite,1);
            else CLACT_SetActorDrawEnable(sprite,0);
        }
    }
    ((MysteryScroll *)p)->scroll=((MysteryScroll *)p)->scroll+((MysteryScroll *)p)->value;
    BG_SYS_ResetSlot(3,3,((MysteryScroll *)p)->scroll>>12);
    BG_SYS_ResetSlot(7,3,((MysteryScroll *)p)->scroll>>12);
}


void MYSTERY_UpdateScrollB(u8 *p)
{
    int i;
    void *sprite;
    s16 xy[2];
    if(((MysteryScroll *)p)->value!=-16384) {
        int base=((MysteryScroll *)p)->startValue;
        ((MysteryScroll *)p)->value=base+((-16384-base)*((MysteryScroll *)p)->step)/60;
        if((((MysteryScroll *)p)->step)++>60) ((MysteryScroll *)p)->value=-16384;
    }
    for(i=0;i<32;i++) {
        ((MysteryScroll *)p)->y[i]=((MysteryScroll *)p)->y[i]+((MysteryScroll *)p)->vy[i];
        if(((MysteryScroll *)p)->y[i]>=851968) ((MysteryScroll *)p)->y[i]=-65536;
        sprite=MYSTERY_GetClactActor(((MysteryScroll *)p)->clactUnit,i+1);
        CLACT_GetActorPos(sprite,(struct Pt *)xy);
        xy[1]=((MysteryScroll *)p)->y[i]>>12;
        CLACT_SetActorPos(sprite,(const struct Pt *)xy);
        if(xy[1]>=0 && xy[1]<=208) CLACT_SetActorDrawEnable(sprite,1);
        else CLACT_SetActorDrawEnable(sprite,0);
    }
    ((MysteryScroll *)p)->scroll=((MysteryScroll *)p)->scroll+((MysteryScroll *)p)->value;
    BG_SYS_ResetSlot(3,3,((MysteryScroll *)p)->scroll>>12);
    BG_SYS_ResetSlot(7,3,((MysteryScroll *)p)->scroll>>12);
}


/*
 * extent: two zero alignment bytes at 021D9486; next function starts 021D9488.
 */
void MYSTERY_CreateOamSprite(u8 *p,const void *q,int n,int k,int x,int y,int z,u16 heap)
{
    MysteryActorPos pos;
    MI_CpuFill8(p,0,12);
    *(const void * *)&((MysteryOamSprite *)p)->clact=q;
    ((MysteryOamSprite *)p)->sys=BMP_OAM_CreateSys(heap,(void *)n);
    MI_CpuFill8(&pos,0,8);
    pos.x=96; pos.y=169; pos.a=0; pos.b=0;
    ((MysteryOamSprite *)p)->sprite=MYSTERY_UTIL_CreateTaskEx((const char *)(&pos),8,2,(int)(*(void *const *)&((MysteryClactActor *)q)->palette.ptr),3,0,((MysteryOamSprite *)p)->sys,(void *)k,heap);
    MYSTERY_UTIL_SetFlag(((MysteryOamSprite *)p)->sprite,1120);
    MYSTERY_UTIL_SetVec(((MysteryOamSprite *)p)->sprite,0,0,1);
    MYSTERY_UTIL_SetActorPairText(((MysteryOamSprite *)p)->sprite,x,y,z);
    CLACT_SetActorDrawEnable(MYSTERY_GetClactActor((u8 *)q,34),1);
}


void MYSTERY_DeleteOamSprite(void **p) {
 MYSTERY_UTIL_UpdateActorPair(p[1]);CLACT_SetActorDrawEnable(MYSTERY_GetClactActor(p[2],34),0);MYSTERY_UTIL_DeleteActorPair(p[1]);BMP_OAM_DeleteSys(p[0]);MI_CpuFill8(p,0,12);
}


/*
 * interfaces: named the callee's boolean return; the tail jump forwards it unchanged.
 */
int MYSTERY_PollOamSprite(char *p)
{
    return MYSTERY_UTIL_IsMenuFinished(((MysteryOamSprite *)p)->sprite);
}


unsigned MYSTERY_MeasureGraChar(int id,int heap)
{
    unsigned result=48;
    int found=0;
    int row,col,bit;
    void *object;
    void *allocation;
    u8 *table;
    heap=(heap&32767)|32768;
    allocation=(void *)POKEGRA_LoadCharDataPP(&object,(void *)id,(int)0,(u16)heap);
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


int MYSTERY_IsCardValid(char *p,int n) {
 if(MYSTERY_DATA_CheckPacketCrc((u8 *)p)!=0 && n==0 && (((MysteryPacket *)p)->crc==0 || (((MysteryPacket *)p)->crc&0x200000)!=0)) return 1;
 return 0;
}


/*
 * volatile: hardware rereads at 021D959A..021D95CA
 */
void MYSTERY_SetupDisplay3d(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1,0);
    *(volatile u16 *)0x04000008=(u16)(*(volatile u16 *)0x04000008 &~3);
    REG=(u16)((REG&~0x3002)|2);
    REG&=(u16)~0x3010;
    REG&=(u16)~0x3004;
    REG=(u16)((REG&~0x3000)|8);
    REG&=(u16)~0x3020;
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,32767,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,(const u16 *)(d_021DF5E4+i*2));
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
