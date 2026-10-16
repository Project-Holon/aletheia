/*
 * file:     irc_compatible_touch_test.c
 * unit:     yes
 * function: IRC_COMPATIBLE_TOUCH_TEST_ProcInit, IRC_COMPATIBLE_TOUCH_TEST_ProcExit, IRC_COMPATIBLE_TOUCH_TEST_ProcMain, IRC_COMPATIBLE_TOUCH_TEST_InitScene, IRC_COMPATIBLE_TOUCH_TEST_ExitScene, IRC_COMPATIBLE_TOUCH_TEST_UpdateScene, IRC_COMPATIBLE_TOUCH_TEST_GetSprite, IRC_COMPATIBLE_TOUCH_TEST_GetSpriteUnit, IRC_COMPATIBLE_TOUCH_TEST_GetMarkers, IRC_COMPATIBLE_TOUCH_TEST_VBlankTask, IRC_COMPATIBLE_TOUCH_TEST_InitBackgrounds, IRC_COMPATIBLE_TOUCH_TEST_ExitBackgrounds, IRC_COMPATIBLE_TOUCH_TEST_BackgroundVBlank, IRC_COMPATIBLE_TOUCH_TEST_InitSprites, IRC_COMPATIBLE_TOUCH_TEST_ExitSprites, IRC_COMPATIBLE_TOUCH_TEST_DrawSpriteSystem, IRC_COMPATIBLE_TOUCH_TEST_VBlankSpriteSystem, IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetActor, IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetUnit, IRC_COMPATIBLE_TOUCH_TEST_Init3D, IRC_COMPATIBLE_TOUCH_TEST_Exit3D, IRC_COMPATIBLE_TOUCH_TEST_Begin3DFrame, IRC_COMPATIBLE_TOUCH_TEST_End3DFrame, IRC_COMPATIBLE_TOUCH_TEST_Get3DModel, IRC_COMPATIBLE_TOUCH_TEST_Setup3DDisplay, IRC_COMPATIBLE_TOUCH_TEST_InitModel, IRC_COMPATIBLE_TOUCH_TEST_ExitModel, IRC_COMPATIBLE_TOUCH_TEST_DrawModel, IRC_COMPATIBLE_TOUCH_TEST_ModelHasLooped, IRC_COMPATIBLE_TOUCH_TEST_ModelSetPosition, IRC_COMPATIBLE_TOUCH_TEST_ModelSetActive, IRC_COMPATIBLE_TOUCH_TEST_ModelIsActive, IRC_COMPATIBLE_TOUCH_TEST_InitText, IRC_COMPATIBLE_TOUCH_TEST_ExitText, IRC_COMPATIBLE_TOUCH_TEST_UpdateTextQueue, IRC_COMPATIBLE_TOUCH_TEST_TextGetFont, IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue, IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData, IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet, IRC_COMPATIBLE_TOUCH_TEST_InitTitleWindow, IRC_COMPATIBLE_TOUCH_TEST_InitWindow, IRC_COMPATIBLE_TOUCH_TEST_ExitWindow, IRC_COMPATIBLE_TOUCH_TEST_UpdateWindow, IRC_COMPATIBLE_TOUCH_TEST_PrintMessage, IRC_COMPATIBLE_TOUCH_TEST_PrintMessageCentered, IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName, IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer, IRC_COMPATIBLE_TOUCH_TEST_ClearWindow, IRC_COMPATIBLE_TOUCH_TEST_SetHandler, IRC_COMPATIBLE_TOUCH_TEST_SetHandlerWithState, IRC_COMPATIBLE_TOUCH_TEST_SetFinished, IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch, IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch, IRC_COMPATIBLE_TOUCH_TEST_HandleThirdTouch, IRC_COMPATIBLE_TOUCH_TEST_HandleScoring, IRC_COMPATIBLE_TOUCH_TEST_HandleAbort, IRC_COMPATIBLE_TOUCH_TEST_InitExchange, IRC_COMPATIBLE_TOUCH_TEST_ExitExchange, IRC_COMPATIBLE_TOUCH_TEST_SendDrawing, IRC_COMPATIBLE_TOUCH_TEST_GetReceivedDrawing, IRC_COMPATIBLE_TOUCH_TEST_ExchangeReceiveCallback, IRC_COMPATIBLE_TOUCH_TEST_ExchangeGetBuffer, IRC_COMPATIBLE_TOUCH_TEST_InitMarkers, IRC_COMPATIBLE_TOUCH_TEST_ExitMarkers, IRC_COMPATIBLE_TOUCH_TEST_UpdateMarkers, IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive, IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition, IRC_COMPATIBLE_TOUCH_TEST_PollTouchTrigger, IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld, IRC_COMPATIBLE_TOUCH_TEST_ScoreDrawing, IRC_COMPATIBLE_TOUCH_TEST_ScoreStroke, IRC_COMPATIBLE_TOUCH_TEST_LoadScreenBlock, IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens, IRC_COMPATIBLE_TOUCH_TEST_InitTrail, IRC_COMPATIBLE_TOUCH_TEST_ExitTrail, IRC_COMPATIBLE_TOUCH_TEST_InitTrailSprite, IRC_COMPATIBLE_TOUCH_TEST_ClearStroke, IRC_COMPATIBLE_TOUCH_TEST_RecordStroke, IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished
 * address:  0x021B7560
 * region:   ov103
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap 0x0203064C arm
 *   PROCSYS_AllocProcWork 0x0203159C arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ICA_ANIME_GetField24 0x02012138 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BG_SYS_SetScrollY 0x02041F6C arm
 *   BG_SYS_SetAffine 0x02041FB0 arm
 *   IRC_APPBAR_Create 0x021B70DC thumb ov101
 *   COMPATIBLE_IRC_SYS_SetOwnValue 0x021B63CC thumb ov101
 *   IRC_APPBAR_Delete 0x021B71C0 thumb ov101
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   FADE_Start 0x0204E720 arm
 *   FADE_IsActive 0x0204E804 arm
 *   COMPATIBLE_IRC_SYS_UpdateValueSync 0x021B63D0 thumb ov101
 *   IRC_APPBAR_Update 0x021B71E4 thumb ov101
 *   BG_SYS_ClearGraphicsMemory 0x0204335C arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BMP_SetDisplaySwap 0x0204363C arm
 *   BG_SYS_ResetSubDisplay 0x0204361C arm
 *   BG_SYS_ClearMainPlanes 0x020434CC arm
 *   func_020056A0 0x020056A0 thumb
 *   IRC_COMPATIBLE_TOUCH_TEST_VramBankConfig 0x021B92D4 data ov103 a4
 *   func_02030EAC 0x02030EAC arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_FreeSlot 0x020414AC arm
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   func_02049740 0x02049740 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_0207D63C 0x0207D63C arm
 *   IRC_COMPATIBLE_TOUCH_TEST_BgDisplayConfig 0x021B924C data ov103 a4
 *   IRC_COMPATIBLE_TOUCH_TEST_BgLayerIds 0x021B927C data a4
 *   IRC_COMPATIBLE_TOUCH_TEST_BgLayerTypes 0x021B9298 data a4
 *   IRC_COMPATIBLE_TOUCH_TEST_BgTemplates 0x021B9310 data ov103 a4
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   BG_SYS_Delete 0x0203F9B4 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   CLACT_SetUnitDefaultRenderer 0x0204B270 arm
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   CLACT_RegisterPalette 0x0204ABF0 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorBgPriority 0x0204B84C arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   CLACT_ReleasePalette 0x0204ADA4 arm
 *   CLACT_ReleaseCharacter 0x0204A8D4 arm
 *   CLACT_ReleaseCellAnim 0x0204AFD8 arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   IRC_COMPATIBLE_TOUCH_TEST_CameraPosition 0x021B9228 data a4
 *   IRC_COMPATIBLE_TOUCH_TEST_CameraTarget 0x021B9234 data a4
 *   IRC_COMPATIBLE_TOUCH_TEST_CameraUp 0x021B9240 data a4
 *   IRC_COMPATIBLE_TOUCH_TEST_ModelFileIds 0x021B9218 data a4
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_SYSTEM_Exit 0x02046788 arm
 *   func_02047964 0x02047964 arm
 *   func_02048AD0 0x02048AD0 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   IRC_COMPATIBLE_TOUCH_TEST_Lights 0x021B92B4 data a4
 *   G3D_SYSTEM_CreateResourceArcHandle 0x02046E24 arm
 *   G3D_SYSTEM_CheckResourceType 0x02046F50 arm
 *   G3D_SYSTEM_TransVramTexture 0x02046FF8 arm
 *   G3D_SYSTEM_CreateRender 0x02047400 arm
 *   G3D_SYSTEM_GetRenderObj 0x0204755C arm
 *   G3D_SYSTEM_CreateAnime 0x02047564 arm
 *   G3D_SYSTEM_CreateObject 0x0204767C arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   NNS_G3dMdlSetMdlPolygonIDAll 0x0206E5EC arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   G3D_SYSTEM_DeleteObject 0x02047738 arm
 *   G3D_SYSTEM_DeleteAnime 0x0204762C arm
 *   G3D_SYSTEM_DeleteRender 0x02047504 arm
 *   func_02046EFC 0x02046EFC arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame 0x02047910 arm
 *   func_02047828 0x02047828 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   func_02047804 0x02047804 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   func_02045B38 0x02045B38 arm
 *   WORDSET_CreateDefault 0x0201EC64 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_IsExistTarget 0x0201C6C4 thumb
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   IRC_APPBAR_GetResult 0x021B7250 thumb ov101
 *   IRC_APPBAR_IsBusy 0x021B727C thumb ov101
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   COMPATIBLE_IRC_SYS_GetValueDifference 0x021B6480 thumb ov101
 *   IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect 0x021B925C data a4
 *   IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect 0x021B926C data a4
 *   COMPATIBLE_IRC_SYS_StepShareValue 0x021B630C thumb ov101
 *   COMPATIBLE_IRC_SYS_SendOwnValue 0x021B6424 thumb ov101
 *   IRC_APPBAR_SetActive 0x021B72A0 thumb ov101
 *   ICA_ANIME_GetField1C 0x020120F4 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200A9D4 0x0200A9D4 thumb
 *   COMPATIBLE_IRC_SYS_AddCommandTable 0x021B64F0 thumb ov101
 *   IRC_COMPATIBLE_TOUCH_TEST_ExchangeCommandTable 0x021B9220 data a4
 *   COMPATIBLE_IRC_SYS_DeleteCommandTable 0x021B6508 thumb ov101
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   COMPATIBLE_IRC_SYS_SendData 0x021B64B8 thumb ov101
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   NNS_G3dScrPosToWorldLine 0x0206E0C4 arm
 *   VEC_Subtract 0x0207CA00 arm
 *   VEC_Normalize 0x0207CCA4 arm
 *   VEC_MultAdd 0x0207CEE4 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   func_02041B6C 0x02041B6C arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb  arm9
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm  arm9
 *   ARC_UTIL_LoadHandleMember  0x0204A380  arm  arm9
 *   CLACT_DrawSystem  0x0204A600  arm  arm9
 *   IRC_RANKING_GetFromSave  0x0200A8A0  thumb  arm9
 *   BG_SYS_GetBuf  0x0204162C  arm  arm9
 *   BG_SYS_GetField16  0x0204169C  arm  arm9
 *   BG_SYS_DrawTileEx  0x020410D0  arm  arm9
 *   BG_SYS_FillTileMap  0x020413B0  arm  arm9
 *   BG_SYS_Update  0x020419E4  arm  arm9
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm  arm9
 */
#include "../ov102/irc_screen_types.h"
#include "../ov101/irc_appbar.h"

/* Hardware registers. */
#define REG_WIN0H (*(volatile u16 *)0x04000040)
#define REG_WIN1H (*(volatile u16 *)0x04000042)
#define REG_WIN0V (*(volatile u16 *)0x04000044)
#define REG_WIN1V (*(volatile u16 *)0x04000046)
#define REG_WININ (*(volatile u16 *)0x04000048)
#define REG_WINOUT (*(volatile u16 *)0x0400004a)
#define REG_BG0CNT_MAIN (*(volatile u16 *)0x04000008)
#define REG_DISP3DCNT (*(volatile u16 *)0x04000060)
#define REG_GX_VIEWPORT (*(volatile u32 *)0x04000580)

/* Number of sprite slots the screen creates. */
#define IRC_TOUCH_SPRITE_COUNT 33
#define IRC_TOUCH_MODEL_COUNT 2
#define IRC_TRAIL_SPRITE_COUNT 32

struct IrcTouchWork;


typedef void (*IrcTouchHandler)(struct IrcTouchWork *work, u16 *state);

/* A point on the touch panel. */
typedef struct IrcTouchPoint {
    u32 x;
    u32 y;
} IrcTouchPoint;

/* Samples of one stroke on the touch panel (96 bytes). */
typedef struct IrcStroke {
    IrcTouchPoint point[10];         /* 0x00 samples, one every 16 frames */
    u16 sampleCount;                 /* 0x50 */
    u16 pad52;
    u32 frames;                      /* 0x54 frames since the stroke started */
    u32 sampleTimer;                 /* 0x58 */
    u32 finished;                    /* 0x5C */
} IrcStroke;

/* What the player drew: first and last touch plus two strokes (208 bytes). */
typedef struct IrcDrawing {
    IrcTouchPoint start;             /* 0x00 first touch */
    IrcTouchPoint end;               /* 0x08 second touch */
    IrcStroke strokeA;               /* 0x10 */
    IrcStroke strokeB;               /* 0x70 */
} IrcDrawing;

/* Drawing as sent to the partner (216 bytes). */
typedef struct IrcDrawingPacket {
    IrcDrawing drawing;
    u32 attempts;                    /* 0xD0 */
    u32 bonus;                       /* 0xD4 */
} IrcDrawingPacket;

/* Sends the own drawing and receives the partner's (660 bytes). */
typedef struct IrcDrawingExchange {
    IrcSys *sys;                     /* 0x000 */
    int state;                       /* 0x004 send step */
    IrcDrawingPacket partner;        /* 0x008 drawing received from the partner */
    IrcDrawingPacket own;            /* 0x0E0 own drawing as echoed back */
    IrcDrawingPacket outgoing;       /* 0x1B8 */
    int received;                    /* 0x290 set when the partner's drawing arrived */
} IrcDrawingExchange;

/* Sprite set of the touch test: the shared resources and one actor per slot (148 bytes). */
typedef struct IrcTouchSprites {
    IrcSpriteResources res;
    void *actors[IRC_TOUCH_SPRITE_COUNT];
} IrcTouchSprites;

typedef struct IrcVec3 {
    u32 x, y, z;
} IrcVec3;

/* Position, scale and rotation of a model, in the order the draw call reads them. */
typedef struct IrcModelTransform {
    IrcVec3 position;                /* 0x00 */
    int scaleX, scaleY, scaleZ;      /* 0x0C */
    int rotation[9];                 /* 0x18 */
} IrcModelTransform;

/* One 3D model with its two animations (96 bytes). */
typedef struct IrcModel {
    void *resource;                  /* 0x00 */
    void *animResource[2];           /* 0x04 */
    void *render;                    /* 0x0C */
    void *object;                    /* 0x10 */
    void *anime[2];                  /* 0x14 */
    IrcModelTransform transform;     /* 0x1C */
    int active;                      /* 0x58 */
    int looped;                      /* 0x5C animation is back at its first frame */
} IrcModel;

typedef struct IrcScene3d {
    void *camera;                    /* 0x00 */
    IrcModel model[IRC_TOUCH_MODEL_COUNT];
} IrcScene3d;

/* Markers that follow the touch points: two models and the last touch (16 bytes). */
typedef struct IrcMarkers {
    IrcModel *model[IRC_TOUCH_MODEL_COUNT];
    int lastX;                       /* 0x08 */
    int lastY;                       /* 0x0C */
} IrcMarkers;

typedef struct IrcTrailSprite {
    void *actor;                     /* 0x00 */
    u32 kind;                        /* 0x04 */
    u8 pad08[0x24];
} IrcTrailSprite;

/* Sprites that trail the touch point (1424 bytes). */
typedef struct IrcTrail {
    IrcTrailSprite sprite[IRC_TRAIL_SPRITE_COUNT];
    int mode;                        /* 0x580 */
    int paletteOffset;               /* 0x584 */
    int head;                        /* 0x588 */
    int interval;                    /* 0x58C */
} IrcTrail;

/* Work area of the touch test step (0xB10 bytes). */
typedef struct IrcTouchWork {
    u32 bgCharRange;                 /* 0x000 loaded character range */
    IrcScene3d scene;                /* 0x004 */
    u8 padC8[4];
    IrcTouchSprites sprites;         /* 0x0CC */
    IrcMarkers markers;              /* 0x160 */
    u32 vblankTask;                  /* 0x170 */
    IrcTextSystem text;              /* 0x174 */
    IrcWindow title;                 /* 0x184 */
    IrcTrail trail;                  /* 0x198 */
    IrcTouchHandler handler;         /* 0x728 */
    u16 handlerState;                /* 0x72C */
    u16 ticks;                       /* 0x72E */
    u32 finished;                    /* 0x730 */
    u8 pad734[4];
    u32 attempts;                    /* 0x738 completed drawing attempts */
    u32 scoreWait;                   /* 0x73C frames waited before the score is read */
    u32 idleTimer;                   /* 0x740 frames since the last hint */
    u32 hintToggle;                  /* 0x744 */
    IrcWindow bottomWin;             /* 0x748 */
    IrcDrawingExchange exchange;     /* 0x75C */
    u8 pad9F0[0x48];
    IrcAppBar *appBar;        /* 0xA38 */
    IrcDrawing drawing;              /* 0xA3C */
    IrcSecondTestArgs *args;         /* 0xB0C */
} IrcTouchWork;

extern void GFL_HEAP_CreateChildHeap(u32 parentId, u32 heapId, u32 size);
extern void *PROCSYS_AllocProcWork(void *proc, u32 size, u32 heapId);
extern void MI_CpuFill8(void *dest, int value, u32 size);
extern u32 ICA_ANIME_GetField24(void *gameSystem);
extern void BMP_MENUWORK_DrawWindow(void *bmpWin, int a1, int a2, int a3);
extern void BG_SYS_SetScrollY(u32 which, u32 op, u32 value);
extern void BG_SYS_SetAffine(u32 which, u32 op, u16 value);
extern void COMPATIBLE_IRC_SYS_SetOwnValue(IrcSys *sys, int value);
extern void func_020315D4(void *proc);
extern void GFL_HEAP_DeleteChecked(unsigned heapId);
extern void FADE_Start(u32, int, int, int);
extern int FADE_IsActive(void);
extern int COMPATIBLE_IRC_SYS_UpdateValueSync(IrcSys *sys);
extern void BG_SYS_ClearGraphicsMemory(int);
extern void BG_SYS_SetVramBanks(const void *config);
extern int BMP_SetDisplaySwap(int);
extern int BG_SYS_ResetSubDisplay(int);
extern void BG_SYS_ClearMainPlanes(int);
extern unsigned func_020056A0(void (*task)(unsigned, void *), void *work, unsigned priority);
extern void func_02030EAC(unsigned task);
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
extern void BG_SYS_SetGraphicsMode(const void *config);
extern void BG_SYS_InitBgLayer(u32 bgId, const void *template, u32 type);
extern void BG_SYS_FreeSlot(u8);
extern void func_02040588(u8, u8);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void BG_SYS_Init(u32, u32, u32, u32);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_0207D63C(int, int, int, int, int);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_SetTileUnit(int, int, int);
extern void BG_SYS_FreeLayerBuf(u8);
extern void BMP_WIN_Exit(void);
extern void BG_SYS_Delete(void);
extern void BG_SYS_Update(void);
extern void CLACT_InitSystem(const void *config, u32 arg, u32 heapId);
extern void *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void CLACT_SetUnitDefaultRenderer(void *unit);
extern void BG_SYS_SetMainPlaneVisible(u32, u32);
extern void BG_SYS_SetSubPlaneVisible(u32, u32);
extern int CLACT_RegisterPalette(void *a, u32 b, u32 c, u32 d, u16 g);
extern int CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void *CLACT_CreateActor(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void CLACT_SetActorDrawEnable(void *, unsigned int);
extern void CLACT_SetActorBgPriority(void *, u32);
extern void CLACT_SetActorAutoAnim(void *, u32);
extern void CLACT_SetActorAnimSeq(void *actor, u16 seq);
extern void CLACT_DeleteActor(void *actor);
extern void CLACT_ReleasePalette(int);
extern void CLACT_ReleaseCharacter(int);
extern void CLACT_ReleaseCellAnim(int);
extern int CLACT_DeleteUnit(void *unit);
extern void CLACT_ExitSystem(int);
extern void CLACT_DrawSystem(void);
extern void CLACT_VBlankSystem(void);
extern void G3D_SYSTEM_Init(int, int, int, int, int, int, void (*setupDisplay)(void));
extern void *G3D_CAMERA_Create(int, int, int, int, int, int, int, int, void *, void *, void *, int);
extern void G3D_CAMERA_Delete(void *);
extern void G3D_SYSTEM_Exit(void);
extern void func_02047964(void);
extern void func_02048AD0(void *);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern void G3D_SYSTEM_DrawEnd(void);
extern void G3X_SetFog(int, int, int, int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern void *G3D_SYSTEM_CreateResourceArcHandle(void *, u16);
extern int G3D_SYSTEM_CheckResourceType(void *, int);
extern void G3D_SYSTEM_TransVramTexture(void *);
extern void *G3D_SYSTEM_CreateRender(void *, unsigned, void *);
extern int *G3D_SYSTEM_GetRenderObj(void *);
extern void *G3D_SYSTEM_CreateAnime(void *, const void *, int);
extern void *G3D_SYSTEM_CreateObject(void *, void *, int);
extern void G3D_SYSTEM_EnableObjectAnime(void *, u16);
extern void NNS_G3dMdlSetMdlPolygonIDAll(int, int);
extern void MTX_Identity33_(void *matrix);
extern void G3D_SYSTEM_DeleteObject(void *);
extern void G3D_SYSTEM_DeleteAnime(void *);
extern void G3D_SYSTEM_DeleteRender(void *);
extern void func_02046EFC(void *);
extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);
extern void func_02047828(void *object, int index, int *frame);
extern void G3D_SYSTEM_DrawObject(void *object, void *transform);
extern u32 func_02047804(void *object, u16 idx);
extern void GF_FONT_InitTextColor(void);
extern void *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern void *PRINTSYS_QUE_Create(u32 heapId);
extern void *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *WORDSET_CreateDefault(u32 heap);
extern u32 WORDSET_DeleteStrbufED04(void *wordSet);
extern void MSGDATA_Delete(void *msgData);
extern void PRINTSYS_QUE_Delete(void *printQueue);
extern void GF_FONT_Delete(void *font);
extern u32 PRINTSYS_QUE_Main(void *printQueue);
extern void *BMP_WIN_Create(u32, u32, u32, u32, u8, u8, u8);
extern void *STRBUF_Create(u32 capacity, u32 heapId);
extern void BMP_WIN_TransferChars(void *bmpWin);
extern void BMP_WIN_MakeScreen(void *bmpWin);
extern u8 BMP_WIN_GetBgLayer(void *bmpWin);
extern void BG_SYS_PushTile(u8 index);
extern void *BMP_WIN_GetBmp(void *bmpWin);
extern void BMP_Clear(void *bmp, u8 value);
extern void func_02045CAC(void *msgData, u32 msgId, void *dest);
extern void PRINTSYS_QUE_Clear(void *printQueue);
extern void PRINTSYS_PrintQue(void *printQueue, void *bmp, s16 x, s16 y, void *strBuf, void *font);
extern void STRBUF_Delete(void *strBuf);
extern void BMP_WIN_Delete(void *bmpWin);
extern int PRINTSYS_QUE_IsExistTarget(void *printQueue, void *bmp);
extern u8 BMP_WIN_GetWidth(void *bmpWin);
extern int BMP_WIN_GetHeight(void *bmpWin);
extern int func_0201D304(void *strBuf, void *font, int margin);
extern int func_0201D42C(void *strBuf, void *font);
extern void PRINTSYS_PrintQueColor(void *printQueue, void *bmp, s16 x, s16 y, void *strBuf, void *font, int color);
extern void WORDSET_SetSlotMyStatus(void *wordSet, u32 index, const u8 *myStatus);
extern void *func_02045EC0(void *msgData, u32 msgId);
extern void WORDSET_CopyTaggedText(void *wordSet, void *dest, void *src);
extern void GFL_USE_StopAllSe(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern int COMPATIBLE_IRC_SYS_GetValueDifference(IrcSys *sys);
extern int COMPATIBLE_IRC_SYS_StepShareValue(IrcSys *sys, int value);
extern int COMPATIBLE_IRC_SYS_SendOwnValue(IrcSys *sys);
extern void *ICA_ANIME_GetField1C(void *gameSystem);
extern void *GAME_DATA_GetSaveControl(void *gameData);
extern void *IRC_RANKING_GetFromSave(void *saveControl);
extern u32 func_02008530(const u8 *myStatus);
extern int func_0200A9D4(void *records, u32 value);
extern void COMPATIBLE_IRC_SYS_AddCommandTable(IrcSys *sys, int commandBase, const void *commandTable, int count, void *userData);
extern void COMPATIBLE_IRC_SYS_DeleteCommandTable(IrcSys *sys, int commandBase);
extern void *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_GetHandleNetID(void *handle);
extern u32 COMPATIBLE_IRC_SYS_SendData(IrcSys *sys, u32 commandBase, u32 size, void *data, u8 isParent, u32 e, u32 f, u32 g);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void NNS_G3dScrPosToWorldLine(int x, int y, IrcVec3 *origin, IrcVec3 *target);
extern void VEC_Subtract(IrcVec3 *a, IrcVec3 *b, IrcVec3 *out);
extern void VEC_Normalize(IrcVec3 *in, IrcVec3 *out);
extern void VEC_MultAdd(int scale, IrcVec3 *dir, IrcVec3 *origin, IrcVec3 *out);
extern u32 TOUCHPANEL_GetPointTrg(u32 *outX, u32 *outY);
extern u32 TOUCHPANEL_GetPointCont(u32 *outX, u32 *outY);
extern void *ARC_UTIL_LoadHandleMember(void *arc, u32 memberId, u32 compressed, u32 flags);
extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);
extern u8 BG_SYS_GetField16(int channel);
extern u32 BG_SYS_GetBuf(int channel);
extern void BG_SYS_DrawTileEx(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void BG_SYS_FillTileMap(u8, u8, u8, u8, u8, u8);
extern u32 func_020307B0(void *p);
extern void BG_SYS_SetTileEntry(u8, u8, u8, u8, u8, u8, u8);
extern void func_02041B6C(u32 bit);
extern void CLACT_SetActorPaletteOffset(void *actor, u32 offset, u32 flag);

extern u8 IRC_COMPATIBLE_TOUCH_TEST_VramBankConfig[];
extern u32 IRC_COMPATIBLE_TOUCH_TEST_BgDisplayConfig[], IRC_COMPATIBLE_TOUCH_TEST_BgLayerIds[], IRC_COMPATIBLE_TOUCH_TEST_BgLayerTypes[];
extern const u32 IRC_COMPATIBLE_TOUCH_TEST_BgTemplates[][8];
extern const char gClActorInitParam[];
extern u8 IRC_COMPATIBLE_TOUCH_TEST_CameraPosition[];
extern u8 IRC_COMPATIBLE_TOUCH_TEST_CameraTarget[];
extern u8 IRC_COMPATIBLE_TOUCH_TEST_CameraUp[];
extern u8 IRC_COMPATIBLE_TOUCH_TEST_ModelFileIds[];
extern const u8 IRC_COMPATIBLE_TOUCH_TEST_Lights[];
extern u32 IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect[], IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect[];
extern u8 IRC_COMPATIBLE_TOUCH_TEST_ExchangeCommandTable[];

int IRC_COMPATIBLE_TOUCH_TEST_ProcInit(void *proc, int unused, IrcSecondTestArgs *args);
int IRC_COMPATIBLE_TOUCH_TEST_ProcExit(void *proc, int unused, int unused2, IrcTouchWork *work);
int IRC_COMPATIBLE_TOUCH_TEST_ProcMain(void *unused, u32 *state, int unused2, IrcTouchWork *work);
void IRC_COMPATIBLE_TOUCH_TEST_InitScene(IrcTouchWork *work, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_ExitScene(IrcTouchWork *work);
void IRC_COMPATIBLE_TOUCH_TEST_UpdateScene(IrcTouchWork *work);
void *IRC_COMPATIBLE_TOUCH_TEST_GetSprite(IrcTouchWork *work, int index);
void *IRC_COMPATIBLE_TOUCH_TEST_GetSpriteUnit(IrcTouchWork *work);
IrcMarkers *IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(IrcTouchWork *work);
void IRC_COMPATIBLE_TOUCH_TEST_VBlankTask(unsigned taskId, void *work);
void IRC_COMPATIBLE_TOUCH_TEST_InitBackgrounds(u32 *charRange, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_ExitBackgrounds(u32 *charRange);
void IRC_COMPATIBLE_TOUCH_TEST_BackgroundVBlank(void *unused);
void IRC_COMPATIBLE_TOUCH_TEST_InitSprites(IrcTouchSprites *sprites, const void *config, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_ExitSprites(IrcTouchSprites *sprites);
void IRC_COMPATIBLE_TOUCH_TEST_DrawSpriteSystem(void *sprites);
void IRC_COMPATIBLE_TOUCH_TEST_VBlankSpriteSystem(void *sprites);
void *IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetActor(IrcTouchSprites *sprites, u32 index);
void *IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetUnit(IrcTouchSprites *sprites);
void IRC_COMPATIBLE_TOUCH_TEST_Init3D(IrcScene3d *scene, int heapId);
void IRC_COMPATIBLE_TOUCH_TEST_Exit3D(IrcScene3d *scene);
void IRC_COMPATIBLE_TOUCH_TEST_Begin3DFrame(IrcScene3d *scene);
void IRC_COMPATIBLE_TOUCH_TEST_End3DFrame(IrcScene3d *scene);
IrcModel *IRC_COMPATIBLE_TOUCH_TEST_Get3DModel(IrcScene3d *scene, u16 index);
void IRC_COMPATIBLE_TOUCH_TEST_Setup3DDisplay(void);
void IRC_COMPATIBLE_TOUCH_TEST_InitModel(IrcModel *model, void *arc, const u16 *fileIds, int polygonId, int unused);
void IRC_COMPATIBLE_TOUCH_TEST_ExitModel(IrcModel *model);
void IRC_COMPATIBLE_TOUCH_TEST_DrawModel(IrcModel *model);
u32 IRC_COMPATIBLE_TOUCH_TEST_ModelHasLooped(IrcModel *model);
void IRC_COMPATIBLE_TOUCH_TEST_ModelSetPosition(IrcModel *model, IrcVec3 *position);
void IRC_COMPATIBLE_TOUCH_TEST_ModelSetActive(IrcModel *model, int active);
u32 IRC_COMPATIBLE_TOUCH_TEST_ModelIsActive(IrcModel *model);
void IRC_COMPATIBLE_TOUCH_TEST_InitText(IrcTextSystem *text, int skipFont, u32 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_ExitText(IrcTextSystem *text);
u32 IRC_COMPATIBLE_TOUCH_TEST_UpdateTextQueue(IrcTextSystem *text);
void *IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(IrcTextSystem *text);
void *IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(IrcTextSystem *text);
void *IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(IrcTextSystem *text);
void *IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet(IrcTextSystem *text);
void IRC_COMPATIBLE_TOUCH_TEST_InitTitleWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_InitWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 fillColor, u8 charBase, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_ExitWindow(IrcWindow *win);
int IRC_COMPATIBLE_TOUCH_TEST_UpdateWindow(IrcWindow *win, IrcTextSystem *text);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(IrcWindow *win, IrcTextSystem *text, int msgId, int x, s16 y);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageCentered(IrcWindow *win, IrcTextSystem *text, int msgId);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(IrcWindow *win, IrcTextSystem *text, int msgId, const IrcCompatibleProfile *profile, s16 x, s16 y, int heapId);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer(IrcWindow *win, IrcTouchWork *work, int msgId);
void IRC_COMPATIBLE_TOUCH_TEST_ClearWindow(IrcWindow *win);
void IRC_COMPATIBLE_TOUCH_TEST_SetHandler(IrcTouchWork *work, IrcTouchHandler handler);
void IRC_COMPATIBLE_TOUCH_TEST_SetHandlerWithState(IrcTouchWork *work, IrcTouchHandler handler, u16 state);
void IRC_COMPATIBLE_TOUCH_TEST_SetFinished(IrcTouchWork *work);
void IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch(IrcTouchWork *work, u16 *state);
void IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch(IrcTouchWork *work, u16 *state);
void IRC_COMPATIBLE_TOUCH_TEST_HandleThirdTouch(IrcTouchWork *work, u16 *state);
void IRC_COMPATIBLE_TOUCH_TEST_HandleScoring(IrcTouchWork *work, u16 *state);
void IRC_COMPATIBLE_TOUCH_TEST_HandleAbort(IrcTouchWork *work, u16 *state);
void IRC_COMPATIBLE_TOUCH_TEST_InitExchange(IrcDrawingExchange *exchange, IrcSys *sys);
void IRC_COMPATIBLE_TOUCH_TEST_ExitExchange(IrcDrawingExchange *exchange);
int IRC_COMPATIBLE_TOUCH_TEST_SendDrawing(IrcDrawingExchange *exchange, const IrcDrawingPacket *packet);
void IRC_COMPATIBLE_TOUCH_TEST_GetReceivedDrawing(IrcDrawingExchange *exchange, IrcDrawingPacket *out);
void IRC_COMPATIBLE_TOUCH_TEST_ExchangeReceiveCallback(u32 netId, u32 size, u32 data, IrcDrawingExchange *exchange, void *handle);
IrcDrawingPacket *IRC_COMPATIBLE_TOUCH_TEST_ExchangeGetBuffer(u32 netId, IrcDrawingExchange *exchange);
void IRC_COMPATIBLE_TOUCH_TEST_InitMarkers(IrcMarkers *markers, IrcScene3d *scene, int unused);
void IRC_COMPATIBLE_TOUCH_TEST_ExitMarkers(IrcMarkers *markers);
void IRC_COMPATIBLE_TOUCH_TEST_UpdateMarkers(IrcMarkers *markers);
void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(IrcMarkers *markers, int index, int active);
void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(IrcMarkers *markers, int index, int x, int y);
int IRC_COMPATIBLE_TOUCH_TEST_PollTouchTrigger(const u32 *rect, IrcTouchPoint *out);
int IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(const u32 *rect, IrcTouchPoint *out);
u8 IRC_COMPATIBLE_TOUCH_TEST_ScoreDrawing(IrcTouchWork *work);
u8 IRC_COMPATIBLE_TOUCH_TEST_ScoreStroke(const IrcTouchPoint *refOrigin, const IrcTouchPoint *ref, const IrcTouchPoint *curOrigin, const IrcTouchPoint *cur);
void IRC_COMPATIBLE_TOUCH_TEST_LoadScreenBlock(void *arc, int memberId, int bgLayer, int tileOffset, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 dstX, u8 dstY, u8 dstWidth, u8 dstHeight, u8 palette, int compressed, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(int mask, u16 heapId);
void IRC_COMPATIBLE_TOUCH_TEST_InitTrail(IrcTrail *trail, IrcTouchWork *work, int mode, int paletteOffset, int firstSprite, u8 kind);
void IRC_COMPATIBLE_TOUCH_TEST_ExitTrail(IrcTrail *trail);
void IRC_COMPATIBLE_TOUCH_TEST_InitTrailSprite(IrcTrailSprite *sprite, void *actor, int paletteOffset, u8 kind);
void IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(IrcStroke *stroke);
int IRC_COMPATIBLE_TOUCH_TEST_RecordStroke(IrcStroke *stroke, const u32 *rect);
int IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(IrcStroke *stroke);

int IRC_COMPATIBLE_TOUCH_TEST_ProcInit(void *proc, int unused, IrcSecondTestArgs *args)
{
    IrcTouchWork *work;
    void *unit;
    void *font, *printQueue;
    GFL_HEAP_CreateChildHeap(1, 55, 0x25000);
    work = PROCSYS_AllocProcWork(proc, 0xb10, 55);
    MI_CpuFill8(work, 0, 0xb10);
    work->args = args;
    work->args->penalty = 0;
    IRC_COMPATIBLE_TOUCH_TEST_InitExchange(&work->exchange, work->args->view);
    IRC_COMPATIBLE_TOUCH_TEST_InitScene(work, 55);
    IRC_COMPATIBLE_TOUCH_TEST_InitText(&work->text, 0, 55);
    if (work->args->gameSystem) ICA_ANIME_GetField24(work->args->gameSystem);
    IRC_COMPATIBLE_TOUCH_TEST_InitTitleWindow(&work->title, 5, 1, 18, 30, 5, 8, 55);
    BMP_MENUWORK_DrawWindow(work->title.bmpWin, 0, (u16)work->bgCharRange, 6);
    IRC_COMPATIBLE_TOUCH_TEST_InitWindow(&work->bottomWin, 7, 6, 3, 20, 5, 8, 1, 1, 55);
    IRC_COMPATIBLE_TOUCH_TEST_PrintMessageCentered(&work->bottomWin, &work->text, 16);
    BG_SYS_SetScrollY(7, 3, 0x1000);
    BG_SYS_SetScrollY(7, 6, 0x1000);
    BG_SYS_SetAffine(7, 9, 128);
    BG_SYS_SetAffine(7, 12, 40);
    IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(&work->drawing.strokeA);
    IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(&work->drawing.strokeB);
    IRC_COMPATIBLE_TOUCH_TEST_InitTrail(&work->trail, work, 0, 1, 0, 1);
    unit = IRC_COMPATIBLE_TOUCH_TEST_GetSpriteUnit(work);
    font = IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(&work->text);
    printQueue = IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(&work->text);
    work->appBar = IRC_APPBAR_Create(2, unit, 1, 13, 13, 2, font, printQueue, 55);
    COMPATIBLE_IRC_SYS_SetOwnValue(work->args->view, 2);
    IRC_COMPATIBLE_TOUCH_TEST_SetHandler(work, IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch);
    REG_DISPCNT_MAIN = (REG_DISPCNT_MAIN & ~0xe000) | 0x6000;
    REG_WININ = (REG_WININ & ~0x3f) | 0x1e;
    REG_WININ = (REG_WININ & ~0x3f00) | 0x1e00;
    REG_WINOUT = (REG_WINOUT & ~0x3f) | 0x1f;
    REG_WIN0H = 0xff2c;
    REG_WIN0V = 0xa8c0;
    REG_WIN1H = 0xff;
    REG_WIN1V = 0xa8c0;
    return 1;
}

/*
 * volatile: 021B7750 reads display control register.
 */
int IRC_COMPATIBLE_TOUCH_TEST_ProcExit(void *proc, int unused, int unused2, IrcTouchWork *work)
{
    REG_DISPCNT_MAIN &= ~0xe000;
    IRC_APPBAR_Delete(work->appBar);
    IRC_COMPATIBLE_TOUCH_TEST_ExitTrail(&work->trail);
    IRC_COMPATIBLE_TOUCH_TEST_ExitWindow(&work->bottomWin);
    IRC_COMPATIBLE_TOUCH_TEST_ExitWindow(&work->title);
    IRC_COMPATIBLE_TOUCH_TEST_ExitScene(work);
    IRC_COMPATIBLE_TOUCH_TEST_ExitText(&work->text);
    IRC_COMPATIBLE_TOUCH_TEST_ExitExchange(&work->exchange);
    func_020315D4(proc);
    GFL_HEAP_DeleteChecked(55);
    return 1;
}

/*
 * prototype: 7FF0 tail-forwards to u32-returning 0201C4E4; caller tests live r0.
 */
int IRC_COMPATIBLE_TOUCH_TEST_ProcMain(void *unused, u32 *state, int unused2, IrcTouchWork *work)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        FADE_Start(3, 16, 0, 0);
        *state = 2;
        break;
    case 2:
        if (FADE_IsActive() == 0) *state = 3;
        break;
    case 3:
        work->handler(work, &work->handlerState);
        if (work->finished != 0) *state = 4;
        break;
    case 4:
        FADE_Start(3, 0, 16, 0);
        *state = 5;
        break;
    case 5:
        if (FADE_IsActive() == 0) *state = 6;
        break;
    case 6:
        return 1;
    }
    if (IRC_COMPATIBLE_TOUCH_TEST_UpdateTextQueue(&work->text) != 0) {
        IRC_COMPATIBLE_TOUCH_TEST_UpdateWindow(&work->title, &work->text);
        IRC_COMPATIBLE_TOUCH_TEST_UpdateWindow(&work->bottomWin, &work->text);
    }
    IRC_COMPATIBLE_TOUCH_TEST_UpdateScene(work);
    COMPATIBLE_IRC_SYS_UpdateValueSync(work->args->view);
    IRC_APPBAR_Update(work->appBar);
    return 0;
}

/*
 * note: Verified against the ov103 Thumb image.
 */
void IRC_COMPATIBLE_TOUCH_TEST_InitScene(IrcTouchWork *work, u16 heapId)
{
    MI_CpuFill8(work, 0, 0x174);
    BG_SYS_ClearGraphicsMemory(0);
    BG_SYS_SetVramBanks(IRC_COMPATIBLE_TOUCH_TEST_VramBankConfig);
    BG_SYS_ClearMainPlanes(BG_SYS_ResetSubDisplay(BMP_SetDisplaySwap(0)));
    IRC_COMPATIBLE_TOUCH_TEST_InitSprites(&work->sprites, IRC_COMPATIBLE_TOUCH_TEST_VramBankConfig, heapId);
    IRC_COMPATIBLE_TOUCH_TEST_InitBackgrounds(&work->bgCharRange, heapId);
    IRC_COMPATIBLE_TOUCH_TEST_Init3D(&work->scene, heapId);
    IRC_COMPATIBLE_TOUCH_TEST_InitMarkers(&work->markers, &work->scene, heapId);
    work->vblankTask = func_020056A0(IRC_COMPATIBLE_TOUCH_TEST_VBlankTask, work, 0);
}

void IRC_COMPATIBLE_TOUCH_TEST_ExitScene(IrcTouchWork *work)
{
    func_02030EAC(work->vblankTask);
    IRC_COMPATIBLE_TOUCH_TEST_ExitMarkers(&work->markers);
    IRC_COMPATIBLE_TOUCH_TEST_Exit3D(&work->scene);
    IRC_COMPATIBLE_TOUCH_TEST_ExitBackgrounds(&work->bgCharRange);
    IRC_COMPATIBLE_TOUCH_TEST_ExitSprites(&work->sprites);
}

void IRC_COMPATIBLE_TOUCH_TEST_UpdateScene(IrcTouchWork *work)
{
    IRC_COMPATIBLE_TOUCH_TEST_DrawSpriteSystem(&work->sprites);
    IRC_COMPATIBLE_TOUCH_TEST_Begin3DFrame(&work->scene);
    IRC_COMPATIBLE_TOUCH_TEST_UpdateMarkers(&work->markers);
    IRC_COMPATIBLE_TOUCH_TEST_End3DFrame(&work->scene);
}

/*
 * evidence: IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetActor is ov103's own code ("lsls r1, #2; adds r0, r1;
 * ldr r0, [r0, #0x10]; bx lr" after the pool at 021B7C58), inside ov103's window, so
 * only ov103 can be resident there when this pool word is used.  Its start is
 * seeded in layout/function_starts.txt from this pointer word, the only
 * reference; it attests as sole-ref/code from ov103's own listing.  The old
 * hint ov016 named a different overlay's function mapped over the address.
 */
void *IRC_COMPATIBLE_TOUCH_TEST_GetSprite(IrcTouchWork *work, int index) { return IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetActor(&work->sprites, index); }

void *IRC_COMPATIBLE_TOUCH_TEST_GetSpriteUnit(IrcTouchWork *work) { return IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetUnit(&work->sprites); }

IrcMarkers *IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(IrcTouchWork *work) { return &work->markers; }

void IRC_COMPATIBLE_TOUCH_TEST_VBlankTask(unsigned taskId, void *work)
{
    IRC_COMPATIBLE_TOUCH_TEST_BackgroundVBlank(work);
    IRC_COMPATIBLE_TOUCH_TEST_VBlankSpriteSystem(&((IrcTouchWork *)work)->sprites);
}

void IRC_COMPATIBLE_TOUCH_TEST_InitBackgrounds(u32 *charRange, u16 heapId)
{
    int i;
    u32 layer;
    void *arc;
    BG_SYS_Create(heapId);
    BMP_WIN_Init(heapId);
    BG_SYS_SetGraphicsMode(IRC_COMPATIBLE_TOUCH_TEST_BgDisplayConfig);
    for (i = 0; i < 7; i++) {
        layer = IRC_COMPATIBLE_TOUCH_TEST_BgLayerIds[i];
        BG_SYS_InitBgLayer((u8)layer, IRC_COMPATIBLE_TOUCH_TEST_BgTemplates[i], (u8)IRC_COMPATIBLE_TOUCH_TEST_BgLayerTypes[i]);
        BG_SYS_FreeSlot(layer);
        func_02040588(layer, 1);
    }
    arc = func_020490F4(94, heapId);
    func_02049B68(arc, 1, 0, 0, 0, heapId);
    func_02049B68(arc, 1, 4, 0, 0, heapId);
    func_02049B68(arc, 6, 0, 0x120, 0, heapId);
    func_02049658(arc, 2, 3, 0, 0, 0, heapId);
    func_02049658(arc, 0, 6, 0, 0, 0, heapId);
    func_02049658(arc, 48, 4, 0, 0, 0, heapId);
    func_02049658(arc, 5, 2, 0, 0, 0, heapId);
    func_020498F4(arc, 3, 3, 0, 0, 0, heapId);
    func_020498F4(arc, 4, 6, 0, 0, 0, heapId);
    func_020498F4(arc, 45, 4, 0, 0, 0, heapId);
    func_020498F4(arc, 7, 2, 0, 0, 0, heapId);
    IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(1, heapId);
    BG_SYS_Init(5, 0, 1, 0);
    *charRange = func_02049740(arc, 49, 5, 0, 0, heapId);
    ARC_TOOL_DeleteHandle(arc);
    func_0207D63C(0x04000050, 5, 12, 13, 8);
}

void IRC_COMPATIBLE_TOUCH_TEST_ExitBackgrounds(u32 *charRange)
{
    int i;
    REG_BLDCNT_MAIN = 0;
    BG_SYS_DeleteHalf(5, (u16)(*charRange), (u16)(*charRange >> 16));
    BG_SYS_SetTileUnit(5, 1, 0);
    for (i = 0; i < 7; i++) BG_SYS_FreeLayerBuf(IRC_COMPATIBLE_TOUCH_TEST_BgLayerIds[i]);
    BMP_WIN_Exit();
    BG_SYS_Delete();
}

void IRC_COMPATIBLE_TOUCH_TEST_BackgroundVBlank(void *unused) { BG_SYS_Update(); }

void IRC_COMPATIBLE_TOUCH_TEST_InitSprites(IrcTouchSprites *sprites, const void *config, u16 heapId)
{
    void *arc;
    int i;
    u16 position[4];
    MI_CpuFill8(sprites, 0, 0x94);
    CLACT_InitSystem(gClActorInitParam, (u32)config, heapId);
    sprites->res.unit = CLACT_CreateUnit(128, 0, heapId);
    CLACT_SetUnitDefaultRenderer(sprites->res.unit);
    BG_SYS_SetMainPlaneVisible(16, 1);
    BG_SYS_SetSubPlaneVisible(16, 1);
    arc = func_020490F4(94, heapId);
    sprites->res.palette = CLACT_RegisterPalette(arc, 12, 1, 0, heapId);
    sprites->res.characters = CLACT_RegisterCharacter(arc, 11, 0, 1, heapId);
    sprites->res.cellAnim = CLACT_RegisterCellAnim(arc, 10, 9, heapId);
    ARC_TOOL_DeleteHandle(arc);
    MI_CpuFill8(position, 0, 8);
    for (i = 0; i < 32; i++) {
        sprites->actors[i] = CLACT_CreateActor(sprites->res.unit, sprites->res.characters, sprites->res.palette, sprites->res.cellAnim, position, 1, heapId);
        CLACT_SetActorDrawEnable(sprites->actors[i], 0);
        CLACT_SetActorBgPriority(sprites->actors[i], 3);
        CLACT_SetActorAutoAnim(sprites->actors[i], 1);
        CLACT_SetActorAnimSeq(sprites->actors[i], 0);
    }
}

void IRC_COMPATIBLE_TOUCH_TEST_ExitSprites(IrcTouchSprites *sprites)
{
    int i;
    for (i = 0; i < IRC_TOUCH_SPRITE_COUNT; i++) {
        if (sprites->actors[i]) CLACT_DeleteActor(sprites->actors[i]);
    }
    CLACT_ReleasePalette(sprites->res.palette);
    CLACT_ReleaseCharacter(sprites->res.characters);
    CLACT_ReleaseCellAnim(sprites->res.cellAnim);
    CLACT_ExitSystem(CLACT_DeleteUnit(sprites->res.unit));
    MI_CpuFill8(sprites, 0, 0x94);
}

void IRC_COMPATIBLE_TOUCH_TEST_DrawSpriteSystem(void *sprites) { CLACT_DrawSystem(); }

void IRC_COMPATIBLE_TOUCH_TEST_VBlankSpriteSystem(void *sprites) { CLACT_VBlankSystem(); }

void *IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetActor(IrcTouchSprites *sprites, u32 index) { return sprites->actors[index]; }

/*
 * First-word accessor.
 */
void *IRC_COMPATIBLE_TOUCH_TEST_SpriteSetGetUnit(IrcTouchSprites *sprites)
{
    return sprites->res.unit;
}

void IRC_COMPATIBLE_TOUCH_TEST_Init3D(IrcScene3d *scene, int heapId)
{
    void *arc;
    G3D_SYSTEM_Init(0, 1, 0, 1, 0, heapId, IRC_COMPATIBLE_TOUCH_TEST_Setup3DDisplay);
    scene->camera = G3D_CAMERA_Create(2, 6 << 14, 0xFFFE8000, 0xFFFE0000, 1 << 17, 1 << 12, 250 << 14, 0,
                              IRC_COMPATIBLE_TOUCH_TEST_CameraPosition, IRC_COMPATIBLE_TOUCH_TEST_CameraTarget, IRC_COMPATIBLE_TOUCH_TEST_CameraUp, heapId);
    arc = func_020490F4(0x5e, heapId);
    IRC_COMPATIBLE_TOUCH_TEST_InitModel(&scene->model[0], arc, (const u16 *)IRC_COMPATIBLE_TOUCH_TEST_ModelFileIds, 1, heapId);
    IRC_COMPATIBLE_TOUCH_TEST_InitModel(&scene->model[1], arc, (const u16 *)IRC_COMPATIBLE_TOUCH_TEST_ModelFileIds, 2, heapId);
    ARC_TOOL_DeleteHandle(arc);
}

/*
 * note: Two-byte zero alignment padding follows the compiled body.
 */
void IRC_COMPATIBLE_TOUCH_TEST_Exit3D(IrcScene3d *scene)
{
    int i;
    for (i = 0; i < IRC_TOUCH_MODEL_COUNT; i++) IRC_COMPATIBLE_TOUCH_TEST_ExitModel(&scene->model[i]);
    G3D_CAMERA_Delete(scene->camera);
    G3D_SYSTEM_Exit();
}

void IRC_COMPATIBLE_TOUCH_TEST_Begin3DFrame(IrcScene3d *scene)
{
    func_02047964();
    func_02048AD0(scene->camera);
    G3D_SYSTEM_ApplyLookAt();
}

void IRC_COMPATIBLE_TOUCH_TEST_End3DFrame(IrcScene3d *scene) { G3D_SYSTEM_DrawEnd(); }

IrcModel *IRC_COMPATIBLE_TOUCH_TEST_Get3DModel(IrcScene3d *scene, u16 index) { return &scene->model[index]; }

/*
 * note: Full u16 cast around the BG0 priority update preserves the full complement and bics.
 * volatile: DISP3DCNT is a hardware register, re-read at 021B7D72, 021B7D7E, 021B7D88, 021B7D92, 021B7D9E.
 */
void IRC_COMPATIBLE_TOUCH_TEST_Setup3DDisplay(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1, 1);
    REG_BG0CNT_MAIN = (u16)(REG_BG0CNT_MAIN & ~3);
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3002) | 2;
    REG_DISP3DCNT &= ~0x3010;
    REG_DISP3DCNT &= ~0x3004;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 8;
    REG_DISP3DCNT &= ~0x3020;
    G3X_SetFog(0, 0, 0, 0);
    G3X_SetClearColor(0, 0, 0x7fff, 63, 0);
    REG_GX_VIEWPORT = 0xbfff0000;
    for (i = 0; i < 4; i++) G3D_SYSTEM_SetLight((u8)i, (const u16 *)(IRC_COMPATIBLE_TOUCH_TEST_Lights + i * 8));
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
}

void IRC_COMPATIBLE_TOUCH_TEST_InitModel(IrcModel *model, void *arc, const u16 *fileIds, int polygonId, int unused)
{
    int i, j;
    void *textureResource = 0;
    int *renderObj;
    MI_CpuFill8(model, 0, 0x60);
    model->resource = G3D_SYSTEM_CreateResourceArcHandle(arc, fileIds[0]);
    if (G3D_SYSTEM_CheckResourceType(model->resource, 2)) {
        textureResource = model->resource;
        G3D_SYSTEM_TransVramTexture(textureResource);
    }
    if (G3D_SYSTEM_CheckResourceType(model->resource, 1)) {
        i = 0;
        model->render = G3D_SYSTEM_CreateRender(model->resource, 0, textureResource);
        renderObj = G3D_SYSTEM_GetRenderObj(model->render);
        for (; i < 2; i++) {
            model->animResource[i] = G3D_SYSTEM_CreateResourceArcHandle(arc, fileIds[i + 1]);
            model->anime[i] = G3D_SYSTEM_CreateAnime(model->render, model->animResource[i], 0);
        }
        model->object = G3D_SYSTEM_CreateObject(model->render, model->anime, 2);
        for (j = 0; j < 2; j++) G3D_SYSTEM_EnableObjectAnime(model->object, j);
        NNS_G3dMdlSetMdlPolygonIDAll(renderObj[1], polygonId);
    }
    MTX_Identity33_(model->transform.rotation);
    model->transform.scaleX = 4096;
    model->transform.scaleY = 4096;
    model->transform.scaleZ = 4096;
}

/*
 * note: 2-byte zero padding before the next labelled function.
 */
void IRC_COMPATIBLE_TOUCH_TEST_ExitModel(IrcModel *model)
{
    int i;
    G3D_SYSTEM_DeleteObject(model->object);
    for (i = 0; i < 2; i++) {
        if (model->anime[i]) G3D_SYSTEM_DeleteAnime(model->anime[i]);
    }
    G3D_SYSTEM_DeleteRender(model->render);
    for (i = 0; i < 2; i++) func_02046EFC(model->animResource[i]);
    func_02046EFC(model->resource);
    MI_CpuFill8(model, 0, 0x60);
}

/*
 * note: Verified against the ov103 Thumb image.
 */
void IRC_COMPATIBLE_TOUCH_TEST_DrawModel(IrcModel *model)
{
    int i, frame, atStart;
    if (model->active) {
        for (i = 0; i < 2; i++) G3D_SYSTEM_LoopObjectAnimeFrame(model->object, (u16)i, 4096);
        func_02047828(model->object, 0, &frame);
        atStart = 0;
        if (frame == 0) atStart = 1;
        model->looped = atStart;
        G3D_SYSTEM_DrawObject(model->object, &model->transform);
    }
}

u32 IRC_COMPATIBLE_TOUCH_TEST_ModelHasLooped(IrcModel *model) { return model->looped; }

void IRC_COMPATIBLE_TOUCH_TEST_ModelSetPosition(IrcModel *model, IrcVec3 *position)
{
    model->transform.position = *position;
}

void IRC_COMPATIBLE_TOUCH_TEST_ModelSetActive(IrcModel *model, int active)
{
    if (model->active != active) {
        func_02047804(model->object, 0);
        model->active = active;
    }
}

u32 IRC_COMPATIBLE_TOUCH_TEST_ModelIsActive(IrcModel *model) { return model->active; }

void IRC_COMPATIBLE_TOUCH_TEST_InitText(IrcTextSystem *text, int skipFont, u32 heapId)
{
    MI_CpuFill8(text, 0, 16);
    GF_FONT_InitTextColor();
    if (skipFont == 0)
        text->font = GF_FONT_Create(23, 0, 0, 0, heapId);
    text->printQueue = PRINTSYS_QUE_Create(heapId);
    text->msgData = func_02045B38(0, 2, 47, heapId);
    text->wordSet = WORDSET_CreateDefault(heapId);
}

void IRC_COMPATIBLE_TOUCH_TEST_ExitText(IrcTextSystem *text)
{
    WORDSET_DeleteStrbufED04(text->wordSet);
    MSGDATA_Delete(text->msgData);
    PRINTSYS_QUE_Delete(text->printQueue);
    GF_FONT_Delete(text->font);
    MI_CpuFill8(text, 0, 16);
}

u32 IRC_COMPATIBLE_TOUCH_TEST_UpdateTextQueue(IrcTextSystem *text) { return PRINTSYS_QUE_Main(text->printQueue); }

/*
 * four getters at +0, +8, +4, +c.
 */
void *IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(IrcTextSystem *text)
{
    return text->font;
}

void *IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(IrcTextSystem *text)
{
    return text->printQueue;
}

void *IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(IrcTextSystem *text)
{
    return text->msgData;
}

void *IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet(IrcTextSystem *text)
{
    return text->wordSet;
}

void IRC_COMPATIBLE_TOUCH_TEST_InitTitleWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 heapId)
{
    void *bmpWin;
    MI_CpuFill8(win, 0, 20);
    win->fillColor = 15;
    win->bmpWin = BMP_WIN_Create(bgLayer, x, y, width, height, palette, 1);
    win->strBuf = STRBUF_Create(255, heapId);
    win->printWin = win->bmpWin;
    win->printPending = 0;
    IRC_COMPATIBLE_TOUCH_TEST_ClearWindow(win);
    bmpWin = win->bmpWin;
    BMP_WIN_TransferChars(bmpWin);
    BMP_WIN_MakeScreen(bmpWin);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(bmpWin));
}

/*
 * note: The third register parameter is u8: its full-word spill reload stays after the stack-argument stores.
 */
void IRC_COMPATIBLE_TOUCH_TEST_InitWindow(IrcWindow *win, int bgLayer, int x, u8 y, u8 width, u8 height, u8 palette, u16 fillColor, u8 charBase, u16 heapId)
{
    void *bmpWin;
    MI_CpuFill8(win, 0, 20);
    win->fillColor = fillColor;
    win->bmpWin = BMP_WIN_Create(bgLayer, x, y, width, height, palette, charBase);
    win->strBuf = STRBUF_Create(255, heapId);
    win->printWin = win->bmpWin;
    win->printPending = 0;
    BMP_Clear(BMP_WIN_GetBmp(win->bmpWin), win->fillColor);
    bmpWin = win->bmpWin;
    BMP_WIN_TransferChars(bmpWin);
    BMP_WIN_MakeScreen(bmpWin);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(bmpWin));
}

void IRC_COMPATIBLE_TOUCH_TEST_ExitWindow(IrcWindow *win)
{
    STRBUF_Delete(win->strBuf);
    BMP_WIN_Delete(win->bmpWin);
    MI_CpuFill8(win, 0, 20);
}

int IRC_COMPATIBLE_TOUCH_TEST_UpdateWindow(IrcWindow *win, IrcTextSystem *text)
{
    void *printQueue;
    printQueue = text->printQueue;
    if (win->printPending != 0) {
        if (PRINTSYS_QUE_IsExistTarget(printQueue, BMP_WIN_GetBmp(win->printWin)) == 0) {
            BMP_WIN_TransferChars(win->printWin);
            win->printPending = 0;
        }
    }
    if (win->printPending == 0) return 1;
    return 0;
}

void IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(IrcWindow *win, IrcTextSystem *text, int msgId, int x, s16 y)
{
    void *msgData, *printQueue, *font;
    msgData = IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(text);
    printQueue = IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(text);
    font = IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(text);
    BMP_Clear(BMP_WIN_GetBmp(win->bmpWin), win->fillColor);
    func_02045CAC(msgData, msgId, win->strBuf);
    PRINTSYS_QUE_Clear(printQueue);
    PRINTSYS_PrintQue(printQueue, BMP_WIN_GetBmp(win->printWin), x, y, win->strBuf, font);
    win->printPending = 1;
}

/*
 * note: Narrow each dimension after shifting right, then subtract from the u16 coordinates.
 */
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageCentered(IrcWindow *win, IrcTextSystem *text, int msgId)
{
    void *msgData, *printQueue, *font;
    u16 x, y;
    msgData = IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(text);
    printQueue = IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(text);
    font = IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(text);
    BMP_Clear(BMP_WIN_GetBmp(win->bmpWin), win->fillColor);
    func_02045CAC(msgData, msgId, win->strBuf);
    x = BMP_WIN_GetWidth(win->bmpWin) * 4;
    y = BMP_WIN_GetHeight(win->bmpWin) * 4;
    x -= (u16)(func_0201D304(win->strBuf, font, 0) >> 1);
    y -= (u16)(func_0201D42C(win->strBuf, font) >> 1);
    PRINTSYS_QUE_Clear(printQueue);
    PRINTSYS_PrintQueColor(printQueue, BMP_WIN_GetBmp(win->printWin), x, y, win->strBuf, font, 0x3dc4);
    win->printPending = 1;
}

void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(IrcWindow *win, IrcTextSystem *text, int msgId, const IrcCompatibleProfile *profile, s16 x, s16 y, int heapId)
{
    void *wordSet, *msgData, *printQueue, *font, *message;
    BMP_Clear(BMP_WIN_GetBmp(win->bmpWin), win->fillColor);
    wordSet = IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet(text);
    msgData = IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(text);
    WORDSET_SetSlotMyStatus(wordSet, 0, profile->myStatus);
    message = func_02045EC0(msgData, msgId);
    WORDSET_CopyTaggedText(wordSet, win->strBuf, message);
    STRBUF_Delete(message);
    printQueue = IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(text);
    font = IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(text);
    PRINTSYS_QUE_Clear(printQueue);
    PRINTSYS_PrintQue(printQueue, BMP_WIN_GetBmp(win->printWin), x, y, win->strBuf, font);
    win->printPending = 1;
}

void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer(IrcWindow *win, IrcTouchWork *work, int msgId)
{
    IrcSecondTestArgs *args = work->args;
    if (args->gameSystem)
        IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(win, &work->text, msgId, args->profile, 0, 0, 0x37);
    else
        IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(win, &work->text, msgId, 0, 0);
}

void IRC_COMPATIBLE_TOUCH_TEST_ClearWindow(IrcWindow *win)
{
    BMP_Clear(BMP_WIN_GetBmp(win->bmpWin), win->fillColor);
    BMP_WIN_TransferChars(win->bmpWin);
}

void IRC_COMPATIBLE_TOUCH_TEST_SetHandler(IrcTouchWork *work, IrcTouchHandler handler)
{
    work->handler = handler;
    work->handlerState = 0;
}

void IRC_COMPATIBLE_TOUCH_TEST_SetHandlerWithState(IrcTouchWork *work, IrcTouchHandler handler, u16 state)
{
    work->handler = handler;
    work->handlerState = state;
}

void IRC_COMPATIBLE_TOUCH_TEST_SetFinished(IrcTouchWork *work) { work->finished = 1; }

void IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch(IrcTouchWork *work, u16 *state)
{
    IrcTouchPoint *position;
    IrcMarkers *markers;
    int i;
    position = &work->drawing.start;
    if (IRC_APPBAR_GetResult(work->appBar) == 1) {
        work->args->result = 1;
        IRC_COMPATIBLE_TOUCH_TEST_SetFinished(work);
    } else if (!IRC_APPBAR_IsBusy(work->appBar)) {
        switch (*state) {
        case 0:
            if (IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(&work->drawing.strokeA))
                IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 17, 0, 0);
            else if (work->args->gameSystem)
                IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(&work->title, &work->text, 0, work->args->profile, 0, 0, 55);
            else IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 0, 0, 0);
            markers = IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(work);
            for (i = 0; i < 2; i++) IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(markers, i, 0);
            GFL_USE_StopAllSe();
            IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(1, 55);
            work->idleTimer = 0;
            *state = 1;
            break;
        case 1:
            if (IRC_COMPATIBLE_TOUCH_TEST_PollTouchTrigger(IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect, position)) {
                IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(0, 55);
                work->idleTimer = 0;
                work->hintToggle = 0;
                markers = IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(work);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(markers, 0, 1);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(markers, 0, position->x, position->y);
                GFL_USE_PlaySeDefaultVolume(0x651);
                if (IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(&work->drawing.strokeA)) {
                    IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 2, 0, 0);
                    IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(3, 55);
                    IRC_COMPATIBLE_TOUCH_TEST_SetHandlerWithState(work, IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch, 1);
                } else {
                    if (work->args->gameSystem)
                        IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(&work->title, &work->text, 1, work->args->profile, 0, 0, 55);
                    else IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 1, 0, 0);
                    IRC_COMPATIBLE_TOUCH_TEST_SetHandler(work, IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch);
                }
            } else if (!IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(&work->drawing.strokeA)) {
                if ((work->idleTimer)++ >= 180) {
                    work->idleTimer = 0;
                    work->hintToggle ^= 1;
                    if (work->hintToggle) IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer(&work->title, work, 11);
                    else IRC_COMPATIBLE_TOUCH_TEST_PrintMessageForPlayer(&work->title, work, 0);
                }
            }
            break;
        }
    }
    if (COMPATIBLE_IRC_SYS_GetValueDifference(work->args->view))
        IRC_COMPATIBLE_TOUCH_TEST_SetHandler(work, IRC_COMPATIBLE_TOUCH_TEST_HandleAbort);
}

void IRC_COMPATIBLE_TOUCH_TEST_HandleSecondTouch(IrcTouchWork *work, u16 *state)
{
    IrcTouchPoint touch;
    IrcTouchPoint *position;
    IrcStroke *stroke;
    IrcMarkers *markers;
    position = &work->drawing.end;
    stroke = &work->drawing.strokeA;
    if (IRC_APPBAR_GetResult(work->appBar) == 1) {
        work->args->result = 1;
        IRC_COMPATIBLE_TOUCH_TEST_SetFinished(work);
    } else if (!IRC_APPBAR_IsBusy(work->appBar)) {
        switch (*state) {
        case 0:
            if (IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect, &touch)) {
                if (IRC_COMPATIBLE_TOUCH_TEST_RecordStroke(stroke, IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect)) {
                    IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 2, 0, 0);
                    IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(3, 55);
                    *state = 1;
                }
                markers = IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(work);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(markers, 0, 1);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(markers, 0, touch.x, touch.y);
            } else {
                if (IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(stroke)) {
                    IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 2, 0, 0);
                    IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(3, 55);
                    *state = 1;
                } else IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(stroke);
                *state = 2;
            }
            break;
        case 1:
            if (IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect, position)) {
                IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(0, 55);
                if (work->args->gameSystem)
                    IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(&work->title, &work->text, 1, work->args->profile, 0, 0, 55);
                else IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 1, 0, 0);
                IRC_COMPATIBLE_TOUCH_TEST_SetHandler(work, IRC_COMPATIBLE_TOUCH_TEST_HandleThirdTouch);
                markers = IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(work);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(markers, 1, 1);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(markers, 1, position->x, position->y);
                GFL_USE_PlaySeDefaultVolume(0x656);
            } else if (!IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(IRC_COMPATIBLE_TOUCH_TEST_FirstTouchRect, &touch)) *state = 2;
            break;
        case 2:
            (work->attempts)++;
            IRC_COMPATIBLE_TOUCH_TEST_SetHandler(work, IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch);
            break;
        }
    }
    if (COMPATIBLE_IRC_SYS_GetValueDifference(work->args->view))
        IRC_COMPATIBLE_TOUCH_TEST_SetHandler(work, IRC_COMPATIBLE_TOUCH_TEST_HandleAbort);
}

/*
 * stand-in: the field accesses are written as offsets derived from one variable
 * (strokeB at 0xAAC, appBar at 0xAAC - 0x74, args at 0xAAC + 0x60). With plain
 * field accesses the function compiles 4 bytes shorter: the compiler then loads
 * each offset on its own instead of deriving them from one register.
 */
typedef enum { IRC_TOUCH_STROKE_B_OFFSET = 0xaac } IrcTouchOffset;

void IRC_COMPATIBLE_TOUCH_TEST_HandleThirdTouch(IrcTouchWork *work, u16 *state)
{
    IrcTouchPoint point;
    IrcTouchOffset off;
    IrcTouchOffset tmp;
    IrcSecondTestArgs *args;
    u8 *base = (u8 *)work;
    off = IRC_TOUCH_STROKE_B_OFFSET;
    if (IRC_APPBAR_GetResult(*(IrcAppBar **)(base + (off - 0x74))) == 1) {
        tmp = (IrcTouchOffset)off;
        args = *(IrcSecondTestArgs **)(base + (tmp + 0x60));
        args->result = 1;
        IRC_COMPATIBLE_TOUCH_TEST_SetFinished(work);
    } else if (IRC_APPBAR_IsBusy(*(IrcAppBar **)(base + (int)((u32)off - 0x74))) == 0) {
        switch (*state) {
        case 0: {
            IrcMarkers *markers;
            if (IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect, &point)) {
                if (IRC_COMPATIBLE_TOUCH_TEST_RecordStroke((IrcStroke *)(base + off), IRC_COMPATIBLE_TOUCH_TEST_SecondTouchRect)) {
                    IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 3, 0, 0);
                    GFL_USE_PlaySeDefaultVolume(0x654);
                    IRC_COMPATIBLE_TOUCH_TEST_SetHandler(work, IRC_COMPATIBLE_TOUCH_TEST_HandleScoring);
                }
                if (off) {}
                markers = IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(work);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(markers, 1, 1);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(markers, 1, point.x, point.y);
            } else {
                markers = IRC_COMPATIBLE_TOUCH_TEST_GetMarkers(work);
                IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(markers, 1, 0);
                IRC_COMPATIBLE_TOUCH_TEST_ClearStroke((IrcStroke *)(base + off));
                *state = 1;
            }
            break;
        }
        case 1:
            (work->attempts)++;
            IRC_COMPATIBLE_TOUCH_TEST_SetHandler(work, IRC_COMPATIBLE_TOUCH_TEST_HandleFirstTouch);
            break;
        }
    }
    if (COMPATIBLE_IRC_SYS_GetValueDifference(work->args->view))
        IRC_COMPATIBLE_TOUCH_TEST_SetHandler(work, IRC_COMPATIBLE_TOUCH_TEST_HandleAbort);
}

void IRC_COMPATIBLE_TOUCH_TEST_HandleScoring(IrcTouchWork *work, u16 *state)
{
    IrcDrawingPacket own;
    IrcDrawingPacket partner;
    if (*state < 5 && IRC_APPBAR_GetResult(work->appBar) == 1) {
        work->args->result = 1;
        IRC_COMPATIBLE_TOUCH_TEST_SetFinished(work);
        return;
    }
    switch (*state) {
    case 0: if (COMPATIBLE_IRC_SYS_StepShareValue(work->args->view, 4)) *state = 1; break;
    case 1: IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 4, 0, 0); *state = 2; break;
    case 2:
        own.drawing.start = work->drawing.start;
        own.drawing.end = work->drawing.end;
        own.drawing.strokeA = work->drawing.strokeA;
        own.drawing.strokeB = work->drawing.strokeB;
        own.attempts = work->attempts;
        if (work->args->gameSystem) {
            void *records;
            records = IRC_RANKING_GetFromSave(GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(work->args->gameSystem)));
            own.bonus = func_0200A9D4(records, func_02008530(work->args->profile->myStatus)) == 0;
        }
        if (IRC_COMPATIBLE_TOUCH_TEST_SendDrawing(&work->exchange, &own)) *state = 3;
        break;
    case 3:
        COMPATIBLE_IRC_SYS_SetOwnValue(work->args->view, 3);
        if (COMPATIBLE_IRC_SYS_SendOwnValue(work->args->view)) *state = 4;
        break;
    case 4:
        if (COMPATIBLE_IRC_SYS_StepShareValue(work->args->view, 5)) {
            IRC_APPBAR_SetActive(work->appBar, 0);
            *state = 5;
        }
        break;
    case 5:
        if (work->ticks >= 60) {
            GFL_USE_PlaySeDefaultVolume(0x64b);
            IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 5, 0, 0);
            work->scoreWait = 0;
            *state = 6;
        }
        break;
    case 6:
        if ((work->scoreWait)++ < 30) return;
        work->args->score = IRC_COMPATIBLE_TOUCH_TEST_ScoreDrawing(work);
        IRC_COMPATIBLE_TOUCH_TEST_GetReceivedDrawing(&work->exchange, &partner);
        work->args->penalty = work->attempts + partner.attempts;
        work->args->bonus = partner.bonus;
        work->args->result = 0;
        *state = 7;
        return;
    case 7: IRC_COMPATIBLE_TOUCH_TEST_SetFinished(work); return;
    }
    if (*state < 3 && COMPATIBLE_IRC_SYS_GetValueDifference(work->args->view)) IRC_COMPATIBLE_TOUCH_TEST_SetHandler(work, IRC_COMPATIBLE_TOUCH_TEST_HandleAbort);
    if (*state >= 1 && *state <= 5) { if (work->ticks <= 60) ++work->ticks; }
}

void IRC_COMPATIBLE_TOUCH_TEST_HandleAbort(IrcTouchWork *work, u16 *state)
{
    switch (*state) {
    case 0:
        if (COMPATIBLE_IRC_SYS_GetValueDifference(work->args->view) > 0) *state = 1;
        else if (COMPATIBLE_IRC_SYS_GetValueDifference(work->args->view) < 0) {
            work->args->score = 0;
            work->args->result = 2;
            IRC_COMPATIBLE_TOUCH_TEST_SetFinished(work);
        }
        break;
    case 1:
        work->args->score = 0;
        work->args->result = 2;
        *state = 2;
        break;
    case 2: IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(&work->title, &work->text, 6, 0, 0); *state = 3; break;
    case 3: if (COMPATIBLE_IRC_SYS_StepShareValue(work->args->view, 6)) *state = 4; break;
    case 4: IRC_COMPATIBLE_TOUCH_TEST_SetFinished(work); break;
    }
}

void IRC_COMPATIBLE_TOUCH_TEST_InitExchange(IrcDrawingExchange *exchange, IrcSys *sys)
{
    MI_CpuFill8(exchange, 0, 0x294);
    exchange->sys = sys;
    COMPATIBLE_IRC_SYS_AddCommandTable(sys, 0xe00, IRC_COMPATIBLE_TOUCH_TEST_ExchangeCommandTable, 1, exchange);
}

void IRC_COMPATIBLE_TOUCH_TEST_ExitExchange(IrcDrawingExchange *exchange)
{
    COMPATIBLE_IRC_SYS_DeleteCommandTable(exchange->sys, 0xe00);
    MI_CpuFill8(exchange, 0, 0x294);
}

int IRC_COMPATIBLE_TOUCH_TEST_SendDrawing(IrcDrawingExchange *exchange, const IrcDrawingPacket *packet)
{
    switch (exchange->state) {
    case 0:
        exchange->outgoing = *packet;
        exchange->state = 1;
        break;
    case 1:
        if (COMPATIBLE_IRC_SYS_SendData(exchange->sys, 0xe00, 0xd8, &exchange->outgoing, (u8)(GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) == 0), 0, 0, 1))
            exchange->state = 2;
        break;
    case 2:
        if (exchange->received) {
            exchange->received = 0;
            exchange->state = 0;
            return 1;
        }
        break;
    }
    return 0;
}

void IRC_COMPATIBLE_TOUCH_TEST_GetReceivedDrawing(IrcDrawingExchange *exchange, IrcDrawingPacket *out)
{
    *out = exchange->partner;
}

/*
 * extent: two zero alignment bytes follow compiled code.
 */
void IRC_COMPATIBLE_TOUCH_TEST_ExchangeReceiveCallback(u32 netId, u32 size, u32 data, IrcDrawingExchange *exchange, void *handle)
{
    if (handle == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (netId != GFL_NET_SYSTEM_GetCurrentAid()) exchange->received = 1;
    }
}

IrcDrawingPacket *IRC_COMPATIBLE_TOUCH_TEST_ExchangeGetBuffer(u32 netId, IrcDrawingExchange *exchange)
{
    IrcDrawingPacket *buffer;
    if (netId == GFL_NET_SYSTEM_GetCurrentAid()) buffer = &exchange->own;
    else buffer = &exchange->partner;
    return buffer;
}

void IRC_COMPATIBLE_TOUCH_TEST_InitMarkers(IrcMarkers *markers, IrcScene3d *scene, int unused)
{
    int i;
    MI_CpuFill8(markers, 0, 16);
    for (i = 0; i < IRC_TOUCH_MODEL_COUNT; i++) {
        markers->model[i] = IRC_COMPATIBLE_TOUCH_TEST_Get3DModel(scene, i);
        IRC_COMPATIBLE_TOUCH_TEST_ModelSetActive(markers->model[i], 0);
    }
}

void IRC_COMPATIBLE_TOUCH_TEST_ExitMarkers(IrcMarkers *markers) { MI_CpuFill8(markers, 0, 0x10); }

void IRC_COMPATIBLE_TOUCH_TEST_UpdateMarkers(IrcMarkers *markers)
{
    int i;
    for (i = 0; i < IRC_TOUCH_MODEL_COUNT; i++) IRC_COMPATIBLE_TOUCH_TEST_DrawModel(markers->model[i]);
    if (IRC_COMPATIBLE_TOUCH_TEST_ModelIsActive(markers->model[0]) && IRC_COMPATIBLE_TOUCH_TEST_ModelHasLooped(markers->model[0])) GFL_USE_PlaySeDefaultVolume(0x651);
    if (IRC_COMPATIBLE_TOUCH_TEST_ModelIsActive(markers->model[1]) && IRC_COMPATIBLE_TOUCH_TEST_ModelHasLooped(markers->model[1])) GFL_USE_PlaySeDefaultVolume(0x656);
}

void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerActive(IrcMarkers *markers, int index, int active) { IRC_COMPATIBLE_TOUCH_TEST_ModelSetActive(markers->model[index], active); }

void IRC_COMPATIBLE_TOUCH_TEST_SetMarkerPosition(IrcMarkers *markers, int index, int x, int y)
{
    IrcVec3 origin, target, direction;
    switch (index) {
    case 0:
        NNS_G3dScrPosToWorldLine(x, y, &origin, &target);
        VEC_Subtract(&target, &origin, &direction);
        VEC_Normalize(&direction, &direction);
        VEC_MultAdd(0x40000, &direction, &origin, &origin);
        IRC_COMPATIBLE_TOUCH_TEST_ModelSetPosition(markers->model[index], &origin);
        markers->lastX = x;
        markers->lastY = y;
        break;
    case 1:
        NNS_G3dScrPosToWorldLine(markers->lastX + (x - markers->lastX) * 2, markers->lastY + (y - markers->lastY) * 2, &origin, &target);
        VEC_Subtract(&target, &origin, &direction);
        VEC_Normalize(&direction, &direction);
        VEC_MultAdd(0x40000, &direction, &origin, &origin);
        IRC_COMPATIBLE_TOUCH_TEST_ModelSetPosition(markers->model[index], &origin);
        break;
    }
}

int IRC_COMPATIBLE_TOUCH_TEST_PollTouchTrigger(const u32 *rect, IrcTouchPoint *out)
{
    u32 x, y;
    if (TOUCHPANEL_GetPointTrg(&x, &y)) {
        if (x - rect[0] < rect[2] - rect[0] && y - rect[1] < rect[3] - rect[1]) {
            if (out) { out->x = x; out->y = y; }
            return 1;
        }
    }
    return 0;
}

int IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(const u32 *rect, IrcTouchPoint *out)
{
    u32 x, y;
    if (TOUCHPANEL_GetPointCont(&x, &y)) {
        if (x - rect[0] < rect[2] - rect[0] && y - rect[1] < rect[3] - rect[1]) {
            if (out) { out->x = x; out->y = y; }
            return 1;
        }
    }
    return 0;
}

u8 IRC_COMPATIBLE_TOUCH_TEST_ScoreDrawing(IrcTouchWork *work)
{
    IrcDrawingPacket ref;
    IrcDrawingPacket cur;
    IrcTouchPoint refStart, curStart;
    u32 dx, dy, dist;
    u32 score;
    u32 first, second;
    IrcStroke *strokeA;
    ref.drawing.start = work->drawing.start;
    strokeA = &work->drawing.strokeA;
    ref.drawing.end = work->drawing.end;
    ref.drawing.strokeA = *strokeA;
    ref.drawing.strokeB = work->drawing.strokeB;
    IRC_COMPATIBLE_TOUCH_TEST_GetReceivedDrawing(&work->exchange, &cur);
    refStart = ref.drawing.start;
    curStart = cur.drawing.start;
    dy = refStart.y;
    dy = dy - curStart.y;
    dx = refStart.x - curStart.x;
    dist = dx * dx + dy * dy;
    if (dist > 0 && dist <= 64) score = 100;
    else if (dist > 64 && dist <= 256) score = 80;
    else if (dist > 256 && dist <= 576) score = 50;
    else if (dist > 576 && dist <= 1024) score = 30;
    else if (dist > 1024 && dist <= 1600) score = 10;
    else score = 0;
    first = IRC_COMPATIBLE_TOUCH_TEST_ScoreStroke(ref.drawing.strokeA.point, ref.drawing.strokeA.point, cur.drawing.strokeA.point, cur.drawing.strokeA.point);
    second = IRC_COMPATIBLE_TOUCH_TEST_ScoreStroke(ref.drawing.strokeB.point, ref.drawing.strokeB.point, cur.drawing.strokeB.point, cur.drawing.strokeB.point);
    return (score * 40u) / 100u + (first * 40u) / 100u + (second * 20u) / 100u;
}

/*
 * The caller passes each stroke twice: once as the origin and once as the point array.
 */
u8 IRC_COMPATIBLE_TOUCH_TEST_ScoreStroke(const IrcTouchPoint *refOrigin, const IrcTouchPoint *ref, const IrcTouchPoint *curOrigin, const IrcTouchPoint *cur)
{
    int i;
    u32 sum;
    sum = 0;
    for (i = 1; i < 10; i++) {
        int refDy, refDx, curDy, curDx;
        u32 refDist, curDist;
        u16 diff;
        refDx = ref[i].x - refOrigin->x;
        refDy = ref[i].y - refOrigin->y;
        curDx = cur[i].x - curOrigin->x;
        curDy = cur[i].y - curOrigin->y;
        if (refDy < 0) refDy = -refDy;
        if (refDx < 0) refDx = -refDx;
        refDist = refDx + refDy;
        if (curDy < 0) curDy = -curDy;
        if (curDx < 0) curDx = -curDx;
        curDist = curDx + curDy;
        if (refDist > curDist) diff = refDist - curDist; else diff = curDist - refDist;
        if (diff == 0)
            sum += 100;
        else if (diff == 1)
            sum += 80;
        else if (diff == 2)
            sum += 50;
        else if (diff >= 3 && diff <= 5)
            sum += 30;
    }
    return (u8)(sum / 9);
}

void IRC_COMPATIBLE_TOUCH_TEST_LoadScreenBlock(void *arc, int memberId, int bgLayer, int tileOffset, u8 srcX, u8 srcY, u8 srcWidth, u8 srcHeight, u8 dstX, u8 dstY, u8 dstWidth, u8 dstHeight, u8 palette, int compressed, u16 heapId)
{
    void *file;
    int t;
    u8 *data;
    u16 *screen;
    file = ARC_UTIL_LoadHandleMember(arc, memberId, compressed, (u16)((heapId & 0x7fff) | 0x8000));
    NNS_G2dGetUnpackedScreenData(file, (void **)(&data));
    if (tileOffset && !BG_SYS_GetField16((u8)bgLayer)) {
        screen = (u16 *)(data + 12);
        for (t = 0; t < (srcWidth * srcHeight); t++) screen[t] += (u16)tileOffset;
    }
    if (BG_SYS_GetBuf((u8)bgLayer)) {
        BG_SYS_DrawTileEx((u8)bgLayer, dstX, dstY, dstWidth, dstHeight, (u32)(data + 12), srcX, srcY, srcWidth, srcHeight);
        BG_SYS_FillTileMap(bgLayer, dstX, dstY, dstWidth, dstHeight, palette);
        BG_SYS_PushTile(bgLayer);
    }
    func_020307B0(file);
}

void IRC_COMPATIBLE_TOUCH_TEST_LoadGuideScreens(int mask, u16 heapId)
{
    void *arc = func_020490F4(94, heapId);
    if (mask & 1) IRC_COMPATIBLE_TOUCH_TEST_LoadScreenBlock(arc, 7, 2, 0, 0, 0, 16, 24, 0, 0, 16, 24, 9, 0, heapId);
    else BG_SYS_SetTileEntry(2, 0, 0, 0, 16, 24, 9);
    if (mask & 2) IRC_COMPATIBLE_TOUCH_TEST_LoadScreenBlock(arc, 8, 2, 0, 0, 0, 16, 24, 16, 0, 16, 24, 9, 0, heapId);
    else BG_SYS_SetTileEntry(2, 0, 16, 0, 16, 24, 9);
    func_02041B6C(2);
    ARC_TOOL_DeleteHandle(arc);
}

void IRC_COMPATIBLE_TOUCH_TEST_InitTrail(IrcTrail *trail, IrcTouchWork *work, int mode, int paletteOffset, int firstSprite, u8 kind)
{
    int i;
    MI_CpuFill8(trail, 0, 0x590);
    trail->mode = mode;
    trail->paletteOffset = paletteOffset;
    trail->head = 0;
    trail->interval = 10;
    for (i = 0; i < IRC_TRAIL_SPRITE_COUNT; i++) IRC_COMPATIBLE_TOUCH_TEST_InitTrailSprite(&trail->sprite[i], IRC_COMPATIBLE_TOUCH_TEST_GetSprite(work, firstSprite + i), paletteOffset, kind);
}

void IRC_COMPATIBLE_TOUCH_TEST_ExitTrail(IrcTrail *trail) { MI_CpuFill8(trail, 0, 0x590); }

void IRC_COMPATIBLE_TOUCH_TEST_InitTrailSprite(IrcTrailSprite *sprite, void *actor, int paletteOffset, u8 kind)
{
    MI_CpuFill8(sprite, 0, 0x2c);
    sprite->actor = actor;
    sprite->kind = kind;
    CLACT_SetActorPaletteOffset(actor, (u8)paletteOffset, 1);
}

void IRC_COMPATIBLE_TOUCH_TEST_ClearStroke(IrcStroke *stroke) { MI_CpuFill8(stroke, 0, 0x60); }

int IRC_COMPATIBLE_TOUCH_TEST_RecordStroke(IrcStroke *stroke, const u32 *rect)
{
    u16 index;
    if (stroke->finished) return 1;
    if ((stroke->frames)++ > 150) {
        IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(rect, &stroke->point[9]);
        stroke->finished = 1;
        return 1;
    }
    if (stroke->sampleTimer == 0) {
        index = stroke->sampleCount;
        stroke->sampleCount++;
        IRC_COMPATIBLE_TOUCH_TEST_PollTouchHeld(rect, &stroke->point[index]);
    }
    if ((stroke->sampleTimer)++ > 15) stroke->sampleTimer = 0;
    return 0;
}

int IRC_COMPATIBLE_TOUCH_TEST_IsStrokeFinished(IrcStroke *stroke)
{
    return stroke->finished;
}
