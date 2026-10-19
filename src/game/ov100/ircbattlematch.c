/*
 * file:     ircbattlematch.c
 * unit:     yes
 * function: IRCBATTLEMATCH_GetRecvBuffer, IRCBATTLEMATCH_GetRecvSize, IRCBATTLEMATCH_IsEqual, IRCBATTLEMATCH_SetStep, IRCBATTLEMATCH_AbortSession, IRCBATTLEMATCH_StepWipeEnd, IRCBATTLEMATCH_BlendBgPalette, IRCBATTLEMATCH_SetPaletteFade, IRCBATTLEMATCH_StartExitWipe, IRCBATTLEMATCH_LoadActorResources, IRCBATTLEMATCH_CreateActor, IRCBATTLEMATCH_NudgeActor, IRCBATTLEMATCH_MoveActor, IRCBATTLEMATCH_SetPlayerReady, IRCBATTLEMATCH_OnChangeoverConnected, IRCBATTLEMATCH_RecvModeHandler, IRCBATTLEMATCH_RecvMyStatusHandler, IRCBATTLEMATCH_GetParty, IRCBATTLEMATCH_RecvTrainerInfoHandler, IRCBATTLEMATCH_RecvMacAddressHandler, IRCBATTLEMATCH_RecvPlayerSlotsHandler, IRCBATTLEMATCH_StepWaitTouchThenExit, IRCBATTLEMATCH_StepWaitTimeout, IRCBATTLEMATCH_StepWaitFinalSync, IRCBATTLEMATCH_StepShowStartMessage, IRCBATTLEMATCH_GetSharedBattleReadyCount, IRCBATTLEMATCH_StepApplyPartyRules, IRCBATTLEMATCH_StepSendRegulation, IRCBATTLEMATCH_StepSendPlayerSlots, IRCBATTLEMATCH_StepSendMacAddress, IRCBATTLEMATCH_StepSendTrainerInfo, IRCBATTLEMATCH_StepSendMyStatus, IRCBATTLEMATCH_StepCompareModes, IRCBATTLEMATCH_StepResumeWaiting, IRCBATTLEMATCH_StepWaitQuitChoice, IRCBATTLEMATCH_StepOpenQuitConfirm, IRCBATTLEMATCH_StepSendMode, IRCBATTLEMATCH_StepRegisterCommands, IRCBATTLEMATCH_CollectMacAddresses, IRCBATTLEMATCH_OnChangeoverResult, IRCBATTLEMATCH_SetupDisplay, IRCBATTLEMATCH_VBlankTask, IRCBATTLEMATCH_OpenQuitMenu, IRCBATTLEMATCH_OpenWaitMenu, IRCBATTLEMATCH_PrintMainMessage, IRCBATTLEMATCH_PrintPlayerMessage, IRCBATTLEMATCH_PrintRetryMessage, IRCBATTLEMATCH_FreeMessageWindows, IRCBATTLEMATCH_InitWindowSystem, IRCBATTLEMATCH_ExitWindowSystem, IRCBATTLEMATCH_DeleteActor, IRCBATTLEMATCH_PrintWaitingMessage, IRCBATTLEMATCH_InitScreen, IRCBATTLEMATCH_StepWaitFadeIn, IRCBATTLEMATCH_IsCompatibleGameKind, IRCBATTLEMATCH_StepStartSession, IRCBATTLEMATCH_ExitScreen, IRCBATTLEMATCH_StepStartChangeover, IRCBATTLEMATCH_StepRedrawWaitMenu, IRCBATTLEMATCH_StepWaitQuitChoiceDuringWait, IRCBATTLEMATCH_StepWaitErrorDialogClose, IRCBATTLEMATCH_StepWaitWirelessStep, IRCBATTLEMATCH_StepOpenWirelessWaitMenu, IRCBATTLEMATCH_StepRestoreWaitMenu, IRCBATTLEMATCH_StepWaitCancelChoice, IRCBATTLEMATCH_StepWaitTouchThenCancel, IRCBATTLEMATCH_StepOpenQuitConfirmDuringWait, IRCBATTLEMATCH_StepOpenCancelConfirm, IRCBATTLEMATCH_StepCountdownThenExit, IRCBATTLEMATCH_StepShowErrorMessage, IRCBATTLEMATCH_StepWaitErrorChoice, IRCBATTLEMATCH_StepOpenErrorConfirm, IRCBATTLEMATCH_IconAnimLeft, IRCBATTLEMATCH_IconAnimRight, IRCBATTLEMATCH_StepShowDisconnectMessage, IRCBATTLEMATCH_StepAnimateIcons, IRCBATTLEMATCH_StepWaitSession, IRCBATTLEMATCH_ProcInit, IRCBATTLEMATCH_ProcMain, IRCBATTLEMATCH_ProcExit
 * address:  0x021B95A0
 * region:   ov100
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   TCB_DeleteTask 0x02030EAC arm
 *   CLACT_DeleteUnit 0x0204B1CC arm
 *   CLACT_ExitSystem 0x0204A5AC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   gIrcBattleMatchFileName 0x021BB8AC data a1
 *   gIrcBattleMatchRecvBuffer 0x021BB800 data a4
 *   gIrcBattleMatchRecvBuffer  0x021BB800  data  a4
 *   GFL_NET_IRC_WIRELESS_Exit 0x0203D0D0 arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   PALANM_Create  0x02021518  thumb
 *   PALANM_AllocSlotBuffers  0x0202155C  thumb
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 *   PALANM_BlendChannel  0x02021FD8  thumb
 *   PALANM_GetTransWork  0x02021730  thumb
 *   PALANM_FreeSlotBuffers  0x020215A0  thumb
 *   PALANM_Delete  0x02021540  thumb
 *   DC_FlushRange  0x020862F0  arm
 *   GXS_LoadOBJPltt  0x0207E5D0  arm
 *   GXS_LoadBGPltt  0x0207E468  arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 *   ARC_TOOL_CreateHandle 0x020490F4 arm
 *   CLACT_RegisterCharacter 0x0204A6C8 arm
 *   CLACT_RegisterPaletteEx 0x0204AC18 arm
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   CLACT_CreateActor 0x0204B294 arm
 *   CLACT_SetActorAutoAnim 0x0204B92C arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   CLACT_SetActorAffineMode 0x0204B570 arm
 *   CLACT_GetActorSurfacePos 0x0204B454 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   MATH_CountPopulation 0x02080D24 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GAME_DATA_GetPlayerStatusById 0x02012950 thumb
 *   MYSTATUS_Copy 0x02008494 thumb
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   MISC_SAVEDATA_GetBlock44 0x0200ED48 thumb
 *   MYSTATUS_GetId 0x02008530 thumb
 *   MISC_SAVEDATA_InsertRecentValue 0x0200ED54 thumb
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GFL_NET_ERR_InsertFriend 0x0200F5EC thumb
 *   GFL_NET_IsParentAid 0x0203D378 arm
 *   GF_STANDARD_CompareBytes 0x0203EFC8 arm
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_SetAutoExit 0x0203D7B0 arm
 *   GFL_NET_SetLoginOption 0x0203D7BC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   gIrcBattleMatchMsgRegulationPassed 0x021BB664 data a4
 *   gIrcBattleMatchMsgRegulationFailed 0x021BB678 data a4
 *   POKEPARTY_GetBattleReadyCount 0x0201AA50 thumb
 *   POKE_TOOL_HealParty 0x0201BA34 thumb
 *   POKE_REGULATION_GetDataSize 0x0201A918 thumb
 *   GFL_NET_SendData 0x0203D3F8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   OS_GetMacAddress 0x02087C6C arm
 *   GAME_DATA_GetField1A0 0x0201283C thumb
 *   WIFILIST_CreateExchangeToken 0x02009CA8 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   MYSTATUS_GetSize 0x02008468 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   APP_TASKMENU_IsFinish 0x020279E8 thumb
 *   APP_TASKMENU_GetCursorPos 0x02027A04 thumb
 *   BG_SYS_SetFlagField06 0x02041B6C arm
 *   gIrcBattleMatchMsgQuitConfirm 0x021BB65C data a4
 *   ARC_UTIL_UploadPaletteFromArchiveWhole 0x02049B40 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   GFL_NET_COMMAND_AddCommandTable 0x0203A574 arm
 *   gIrcBattleMatchCommandTable 0x021BB6C0 data a4
 *   GFL_NET_IRC_WIRELESS_GetMacAddress 0x0203D0B8 arm
 *   BG_SYS_SetVramBanks 0x020433E0 arm
 *   BG_SYS_SetGraphicsMode 0x0203FC28 arm
 *   BG_SYS_SetMainVisiblePlanes 0x02043534 arm
 *   BG_SYS_SetSubVisiblePlanes 0x020435F4 arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_SetTileEntry 0x02041300 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   BG_SYS_Init 0x02040C14 arm
 *   CLACT_VBlankSystem 0x0204A648 arm
 *   gIrcBattleMatchVramBanks 0x021BB6F0 data a4
 *   gIrcBattleMatchDispConfig 0x021BB6B0 data a4
 *   gIrcBattleMatchBgTemplate0 0x021BB720 data a4
 *   gIrcBattleMatchBgTemplate1 0x021BB740 data a4
 *   gIrcBattleMatchBgTemplate4 0x021BB760 data a4
 *   gIrcBattleMatchBgTemplate5 0x021BB780 data a4
 *   gIrcBattleMatchBgTemplate6 0x021BB7A0 data a4
 *   gIrcBattleMatchBgTemplate7 0x021BB7C0 data a4
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   APP_TASKMENU_OpenMenu 0x02027778 thumb
 *   APP_TASKMENU_SetDisableKey 0x02027CD8 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   WIFILIST_CountFriends 0x02009A34 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   GFL_NET_IRC_WIRELESS_GetRetryCount 0x0203D170 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   GF_FONT_InitTextColor 0x0201DD60 thumb
 *   CLACT_DeleteActor 0x0204B3B4 arm
 *   gIrcBattleMatchMsgPartnerLeft 0x021BB694 data a4
 *   gIrcBattleMatchMsgWaitingMode7Full 0x021BB690 data a4
 *   gIrcBattleMatchMsgWaitingMode7 0x021BB670 data a4
 *   gIrcBattleMatchMsgWaitingMode6 0x021BB680 data a4
 *   gIrcBattleMatchMsgWaitingMode5 0x021BB684 data a4
 *   gIrcBattleMatchMsgWaitingMode9 0x021BB67C data a4
 *   gIrcBattleMatchMsgWaitingMode10 0x021BB66C data a4
 *   gIrcBattleMatchMsgWaitingMode11 0x021BB6A0 data a4
 *   gIrcBattleMatchMsgWaitingDefault 0x021BB698 data a4
 *   WORDSET_Create 0x0201EC74 thumb
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromArchive 0x02045B38 arm
 *   ARC_UTIL_UploadPaletteFromHandleWhole 0x02049B68 arm
 *   ARC_UTIL_RegisterObjCharFromHandle 0x02049740 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   BMP_MENUWORK_LoadFrameGfx 0x0201F5DC thumb
 *   FADE_Start 0x0204E720 arm
 *   CLACT_InitSystem 0x0204A48C arm
 *   CLACT_CreateUnit 0x0204B100 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   APP_TASKMENU_RES_Create 0x02027F60 thumb
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   gClActorInitParam 0x020A1448 data a4
 *   FADE_IsActive 0x0204E804 arm
 *   gIrcBattleMatchSessionReq 0x021BB83C data a4
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   GFL_NET_IRC_WIRELESS_SetSessionParam 0x0203D0C4 arm
 *   GFL_NET_IRC_WIRELESS_SetRetryRequest 0x0203D164 arm
 *   GFL_NET_SetGameKindOverride 0x0203D0AC arm
 *   BG_SYS_SetTileUnit 0x02040DA8 arm
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BG_SYS_SetPlaneVisible 0x02040588 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   IRCNET_SetFilter 0x021799C0 thumb ov015
 *   GFL_NET_StartChangeoverEx 0x0203D060 arm
 *   GFL_NET_IRC_WIRELESS_Step 0x0203D158 arm
 *   gIrcBattleMatchMsgCancelConfirm 0x021BB674 data a4
 *   BUTTON_MAN_Delete 0x02051C6C arm
 *   gIrcBattleMatchMsgCancelConfirmAlt 0x021BB688 data a4
 *   gIrcBattleMatchMsgErrorConfirm 0x021BB668 data a4
 *   CLACT_GetActorAnimSeq 0x0204B898 arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 *   gIrcBattleMatchMsgDisconnected 0x021BB660 data a4
 *   CLACT_ApplyActorAnimCommand 0x0204BA00 arm
 *   gIrcBattleMatchMsgIconsParent 0x021BB69C data a4
 *   gIrcBattleMatchMsgIconsChild 0x021BB68C data a4
 *   GFL_NET_HANDLE_GetNegotiationState 0x020399DC arm
 *   gIrcBattleMatchModeMessages 0x021BB804 data a4
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   G2x_SetBlendAlpha_  0x0207D63C  arm
 *   GX_LoadBGPltt 0x0207E3D0 arm
 *   APP_TASKMENU_UpdateMenu 0x02027974 thumb
 *   APP_TASKMENU_WIN_Update 0x02028178 thumb
 *   BG_SYS_FillScrollArea 0x02040618 arm
 *   CLACT_DrawSystem 0x0204A600 arm
 *   PRINTSYS_QUE_Main 0x0201C4E4 thumb
 *   GFL_NET_ERR_GetErrorLevel 0x0200FB24 thumb
 *   GFL_NET_ERR_RequestScreen 0x0200FB38 thumb
 *   WIPE_SetBrightnessFadeOut 0x0202223C thumb
 *   BMP_WIN_Exit  0x020450C8  arm  arm9
 *   BG_SYS_Delete  0x0203F9B4  arm  arm9
 */
struct Chan02021FD8;
struct PalAnmSlot;
struct Obj;
struct Actor;
struct PtS;
struct Vec2;
struct Entry;
struct Big;
struct L0200ED54;
struct Rec44;
struct Sub0200852CObj;
struct Sub24;
struct Link;
struct BigObj;
struct TaskMenu;
struct DispConfig;
struct DispVram;
struct MsgBank;
struct U16Vec;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Sub020097BCObj;
struct WordSet;
struct Bank;
struct GfFont;
struct Rec;
struct TaskMenuRes;
struct Cmd;
struct Proc;
struct PrintSys;
struct Node;
struct NetSessionReq;
struct IrcBattleMatchWork;
typedef unsigned char u8;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef unsigned int u32;

typedef int s32;

#define PLTT_SUB_BG_ADDR 0x05000400
#define REG_BLDCNT_ADDR 0x04000050
#define VBLANK_COUNT_ADDR 0x02FFFC3C

/* Message id of the text printed in the main message window. */
typedef struct MessageRef { int msgId; } MessageRef;

typedef struct BgTemplate { unsigned int words[8]; } BgTemplate;

/* Layout of the task menu opened by APP_TASKMENU_OpenMenu. */
typedef struct TaskMenuTemplate {
    int heapId;
    u8 itemCount, pad[3];
    void *items;
    int flag;
    u8 x, y, paletteSlot, layer;
} TaskMenuTemplate;

typedef struct TaskMenuItem {
    struct U16Vec *label;
    u16 color, pad;
    int selectType;
} TaskMenuItem;

/* Session request block handed to GFL_NET_StartSession (112 bytes, copied from ROM data). */
typedef struct NetSessionReq {
    u32 header[24];
    u8 ruleA, ruleB, ruleC, ruleD, enabled, connectMode, flagF, sessionKind;
    u32 reserved68;
    u16 ruleValue, limit;
} NetSessionReq;

/* Parameter block shared with the caller (ov021 menu). Input: mode. Output: result code. */
typedef struct IrcBattleMatchParam {
    void *gameData;                  /* 0x00 */
    u8 *regulation;                  /* 0x04 */
    void *party[2];                  /* 0x08 own party, partner party */
    u8 unused10[8];                  /* 0x10 */
    u8 playerSlot[4];                /* 0x18 slot of each aid, exchanged with the partner */
    int mode;                        /* 0x1C input: match mode; output: result (12 error, 13 cancelled) */
    u8 *settings;                    /* 0x20 byte 0x60, 0x61 and halfword 0x6C feed the session request */
} IrcBattleMatchParam;

typedef void (*IrcBattleMatchStep)(struct IrcBattleMatchWork *work);

/* Actor list slots of the animated icons. */
typedef struct ActorTask {
    u16 state, pad;
    struct IrcBattleMatchWork *context;
    void (*callback)(struct IrcBattleMatchWork *work);
} ActorTask;

/* Actor creation parameter: surface position, animation, slot. */
typedef struct ActorParam { s16 x, y; u16 animSeq; u8 slot, mode; } ActorParam;

/* Work block of the infrared battle match screen (0xCF0 bytes, allocated by the proc). */
typedef struct IrcBattleMatchWork {
    u16 palette[18][16];             /* 0x000 background palette rows animated in the main loop */
    u16 paletteRow;                  /* 0x240 */
    u16 heapIdCopy;                  /* 0x242 */
    IrcBattleMatchParam *param;      /* 0x244 */
    IrcBattleMatchStep step;         /* 0x248 current step; 0 ends the proc */
    int mode;                        /* 0x24C */
    int modeByAid[4];                /* 0x250 mode announced by each aid */
    u8 macAddress[4][6];             /* 0x260 */
    u16 heapId;                      /* 0x278 */
    u8 pad27A[2];
    struct Descriptor *messageWin;   /* 0x27C */
    struct Descriptor *infoWin;      /* 0x280 */
    u8 unused284[4];
    struct MsgBank *msgData;         /* 0x288 */
    struct WordSet *wordSet;         /* 0x28C */
    struct GfFont *font;             /* 0x290 */
    struct U16Vec *tempStr;          /* 0x294 */
    struct U16Vec *msgStr;           /* 0x298 */
    u8 unused29C[0x14];
    struct Node *vblankTask;         /* 0x2B0 */
    struct Bank *clactUnit;          /* 0x2B4 */
    int actorPaletteId;              /* 0x2B8 */
    int actorCharId;                 /* 0x2BC */
    int actorCellAnimId;             /* 0x2C0 */
    u8 unused2C4[4];
    struct Obj *actors[8];           /* 0x2C8 */
    int readyMask;                   /* 0x2E8 */
    int allReady;                    /* 0x2EC */
    u8 unused2F0[12];
    int bgCharId;                    /* 0x2FC */
    u8 unused300[4];
    int windowPalette;               /* 0x304 */
    int bgScreenId;                  /* 0x308 */
    struct Node *extraTask;          /* 0x30C cleared at exit */
    int extraTaskArg;                /* 0x310 */
    u8 unused314[0xC7C - 0x314];
    int changeoverRole;              /* 0xC7C set by the changeover callback */
    int showTrigger;                 /* 0xC80 */
    int iconsVisible;                /* 0xC84 */
    int iconsTimer;                  /* 0xC88 */
    int iconsDirty;                  /* 0xC8C */
    int regulationResult;            /* 0xC90 */
    int iconsAnimating;              /* 0xC94 */
    int iconAnimTimer;               /* 0xC98 */
    int scrollY;                     /* 0xC9C */
    int partnerLeft;                 /* 0xCA0 */
    void *buttonMan;                 /* 0xCA4 */
    u8 unusedCA8[4];
    int timer;                       /* 0xCAC */
    int lastMessageId;               /* 0xCB0 */
    u8 *paletteBackup;               /* 0xCB4 */
    struct PrintSys *printQue;       /* 0xCB8 */
    int menuKind;                    /* 0xCBC 0 two items, 1 one item */
    struct TaskMenu *taskMenu;       /* 0xCC0 */
    struct TaskMenuRes *taskMenuRes; /* 0xCC4 */
    TaskMenuItem menuItems[2];       /* 0xCC8 */
    u8 *okWin;                       /* 0xCE0 */
    u8 *cancelWin;                   /* 0xCE4 */
    int retryCount;                  /* 0xCE8 */
    int paletteFlash;                /* 0xCEC */
} IrcBattleMatchWork;

extern void GFL_NET_IRC_WIRELESS_Exit(void);
extern int GFL_NET_Exit(int a0);
extern u32 WIPE_SYS_EndCheck(void);
extern void *PALANM_Create(u32 heap);
extern void PALANM_AllocSlotBuffers(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void PALANM_BlendChannel(struct Chan02021FD8 *p, u32 idx, u32 c, u32 count, u8 weight, u16 color);
extern int PALANM_GetTransWork(char *p, int i);
extern void DC_FlushRange(int, int);
extern void GXS_LoadOBJPltt(int, int, int);
extern void GXS_LoadBGPltt(int, int, int);
extern void PALANM_FreeSlotBuffers(struct PalAnmSlot *slots, u32 idx);
extern u32 PALANM_Delete(void *ctx);
extern void MI_CpuCopy8(const void *,void *,u32);
extern void WIPE_SYS_Start(void *divisionMode, u32 mainPattern, u32 subPattern, u32 color, u32 frames, u32 wait, u32 heapId);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern s32 CLACT_RegisterCharacter(void *a, u32 b, u32 c, u32 vram_mode, u16 flags);
extern s32 CLACT_RegisterPaletteEx(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
extern void ARC_TOOL_DeleteHandle(void *);
extern struct Obj *CLACT_CreateActor(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void CLACT_SetActorAutoAnim(struct Obj *p, unsigned int v);
extern void CLACT_SetActorDrawEnable(struct Obj *,unsigned int);
extern void CLACT_SetActorAffineMode(struct Actor *actor, u32 value);
extern void CLACT_GetActorSurfacePos(struct Actor *actor, struct PtS *out, u16 space);
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);
extern unsigned char MATH_CountPopulation(unsigned x);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern struct Rec44 *GAME_DATA_GetPlayerStatusById(struct Sub24 *p, u32 i);
extern void MYSTATUS_Copy(void *src, void *dst);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *MISC_SAVEDATA_GetBlock44(void *p);
extern u32 MYSTATUS_GetId(const struct Sub0200852CObj *obj);
extern void MISC_SAVEDATA_InsertRecentValue(struct L0200ED54 *l, u32 val);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern int GFL_NET_ERR_InsertFriend(void *saveData, void *profile, void *friendData, void *heapId);
extern unsigned GFL_NET_IsParentAid(void);
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
extern int TOUCHPANEL_GetTrg(void);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern void GFL_NET_SetAutoExit(u8 autoExit);
extern void GFL_NET_SetLoginOption(u8 loginOption);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *,unsigned int,unsigned int);
extern u32 POKEPARTY_GetBattleReadyCount(void *p);
extern void POKE_TOOL_HealParty(void *party);
extern int POKE_REGULATION_GetDataSize(void);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void OS_GetMacAddress(void *);
extern u32 GAME_DATA_GetField1A0(const struct BigObj *p);
extern void WIFILIST_CreateExchangeToken(void *account, void *out);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern int MYSTATUS_GetSize(void);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern u32 APP_TASKMENU_IsFinish(struct TaskMenu *m);
extern u8 APP_TASKMENU_GetCursorPos(struct TaskMenu *menu);
extern void BG_SYS_SetFlagField06(u32 bit);
extern void ARC_UTIL_UploadPaletteFromArchiveWhole(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void GF_FONT_SetDefaultTextColor(void);
extern void GFL_NET_COMMAND_AddCommandTable(unsigned,unsigned,unsigned,IrcBattleMatchWork *);
extern void GFL_NET_IRC_WIRELESS_GetMacAddress(void *,int);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_SetMainVisiblePlanes(u32 planes);
extern void BG_SYS_SetSubVisiblePlanes(u32 planes);
extern void BG_SYS_InitBgLayer(u32 bgId, const BgTemplate *tmpl, u32 type);
extern void BG_SYS_SetTileEntry(int,int,int,int,u8,u8,u8);
extern void BG_SYS_PushTile(u32 index);
extern void BG_SYS_Init(u32 layer, u32 value, u32 count, u32 index);
extern void CLACT_VBlankSystem(void);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern struct TaskMenu *APP_TASKMENU_OpenMenu(TaskMenuTemplate *tmpl, struct TaskMenuRes *res);
extern int APP_TASKMENU_SetDisableKey(struct TaskMenu *menu, int disable);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct Descriptor *BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, int slot);
extern void BMP_WIN_MakeScreen(struct Descriptor *win);
extern void BMP_MENUWORK_DrawWindow(void *win, int commitMode, int tileBase, int palette);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern u32 WIFILIST_CountFriends(struct Sub020097BCObj *obj);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern int GFL_NET_IRC_WIRELESS_GetRetryCount(void);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_Create(u16),BMP_WIN_Init(u16);
extern void GF_FONT_InitTextColor(void);
extern void BG_SYS_Delete(void);
extern void BMP_WIN_Exit(void);
extern void CLACT_DeleteActor(struct Obj *);
extern struct WordSet *WORDSET_Create(u32 n, u32 size, u16 heap);
extern struct GfFont *GF_FONT_Create(int archiveId, int fileId, int format, int isFixedWidth, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 ARC_UTIL_RegisterObjCharFromHandle(void *arc, u32 memberIdx, u32 bgId, u32 size, u32 heapID, u16 flags);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *arc, u32 memberIdx, u32 channel, u32 offset, u32 add, u32 size, u32 heapID, u16 flags);
extern void *BMP_MENUWORK_LoadFrameGfx(void *layer, u32 palSlot, u32 frameId, u32 heapId);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct Node *GFL_USE_AddMainTask(void (*task)(void), IrcBattleMatchWork *arg, u32 priority);
extern struct PrintSys *PRINTSYS_QUE_Create(void *heap);
extern struct TaskMenuRes *APP_TASKMENU_RES_Create(u16 bgFrame, u16 palNo, u32 font, u32 printQue, u16 heap);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *arc, u32 memberIdx, u32 unpackedOut, u32 flags);
extern void ARC_UTIL_UploadPaletteFromHandleWhole(void *,u32,u32,u32,u32,u16);
extern void FADE_Start(u32,int,int,int);
extern void CLACT_InitSystem(const struct Cfg *cfg, u32 arg, u32 heapId);
extern u32 GFL_HEAP_Free(void *p);
extern int FADE_IsActive(void);
extern void GFL_NET_StartSession(NetSessionReq *,u32,IrcBattleMatchWork *);
extern void GFL_NET_IRC_WIRELESS_SetSessionParam(int (*isCompatible)(int, int));
extern void GFL_NET_IRC_WIRELESS_SetRetryRequest(int);
extern void GFL_NET_SetGameKindOverride(int);
extern void BG_SYS_SetTileUnit(u32 idx, u32 count, u32 tile);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void BG_SYS_FreeLayerBuf(u32 i);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(struct GfFont *font);
extern void BG_SYS_SetPlaneVisible(unsigned char which, unsigned char enable);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuRes *res);
extern int GFL_NET_GetRunState(void);
extern void IRCNET_SetFilter(int (*isCompatible)(int, int));
extern void GFL_NET_StartChangeoverEx(void (*collectMacs)(IrcBattleMatchWork *), void (*onResult)(IrcBattleMatchWork *, int), void (*onConnected)(IrcBattleMatchWork *));
extern int GFL_NET_IRC_WIRELESS_Step(void);
extern void BUTTON_MAN_Delete(void *p);
extern u16 CLACT_GetActorAnimSeq(struct Obj *p);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void CLACT_ApplyActorAnimCommand(struct Actor *a, const ActorTask *task);
extern int GFL_NET_HANDLE_GetNegotiationState(struct Entry *);
extern void GFL_HEAP_CreateChildHeap(unsigned int, unsigned int, unsigned int);
extern void *PROCSYS_AllocProcWork(struct Proc *proc, u32 size, u32 heap);
extern void MI_CpuFill8(int, int, int);
extern void *GFL_HEAP_Alloc(unsigned int heapId, unsigned int size, int clear, const char *site, unsigned short tag);
extern void G2x_SetBlendAlpha_(int, int, int, int, int);
extern void GX_LoadBGPltt(void *, int, int);
extern void APP_TASKMENU_UpdateMenu(struct TaskMenu *);
extern void APP_TASKMENU_WIN_Update(u8 *);
extern void BG_SYS_FillScrollArea(u32, u32, u32);
extern void CLACT_DrawSystem(void);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern void GFL_NET_ERR_RequestScreen(void);
extern void WIPE_SetBrightnessFadeOut(u32, u32);
extern void APP_TASKMENU_WIN_Delete(u8 *win);
extern void WORDSET_DeleteStrbufED04(struct WordSet *wordSet);
extern void TCB_DeleteTask(struct Node *task);
extern u32 CLACT_DeleteUnit(struct Bank *unit);
extern void CLACT_ExitSystem(void);
extern void PRINTSYS_QUE_Clear(struct PrintSys *queue);
extern void PRINTSYS_QUE_Delete(struct PrintSys *queue);
extern void PROCSYS_FreeProcWork(struct Proc *proc);
extern void GFL_HEAP_DeleteChecked(unsigned int heapId);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 id);
void IRCBATTLEMATCH_SetStep(IrcBattleMatchWork *work, IrcBattleMatchStep step);

char *IRCBATTLEMATCH_GetRecvBuffer(void);
int IRCBATTLEMATCH_GetRecvSize(void);
int IRCBATTLEMATCH_IsEqual(int a, int b);
int IRCBATTLEMATCH_AbortSession(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWipeEnd(IrcBattleMatchWork *work);
int IRCBATTLEMATCH_BlendBgPalette(IrcBattleMatchWork *work, int bgSlot, int paletteCount);
void IRCBATTLEMATCH_SetPaletteFade(IrcBattleMatchWork *work,int enable);
void IRCBATTLEMATCH_StartExitWipe(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_LoadActorResources(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_CreateActor(IrcBattleMatchWork *work,int x,int y,int slot,int animSeq);
void IRCBATTLEMATCH_NudgeActor(IrcBattleMatchWork *work,int dx,int dy,int slot);
void IRCBATTLEMATCH_MoveActor(IrcBattleMatchWork *work,int x,int y,int slot);
void IRCBATTLEMATCH_SetPlayerReady(IrcBattleMatchWork *work,int aid);
void IRCBATTLEMATCH_OnChangeoverConnected(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_RecvModeHandler(unsigned aid,int size,int *data,IrcBattleMatchWork *work,void *handle);
void IRCBATTLEMATCH_RecvMyStatusHandler(int aid,int size,int data,IrcBattleMatchWork *work,int handle);
void IRCBATTLEMATCH_NoOp(void);
int IRCBATTLEMATCH_GetParty(int index,IrcBattleMatchWork *work);
void IRCBATTLEMATCH_RecvTrainerInfoHandler(int aid,int size,int data,IrcBattleMatchWork *work,int handle);
void IRCBATTLEMATCH_RecvMacAddressHandler(int aid,int size,void *data,IrcBattleMatchWork *work,int handle);
void IRCBATTLEMATCH_RecvPlayerSlotsHandler(int aid,int size,void *data,IrcBattleMatchWork *work,void *handle);
void IRCBATTLEMATCH_StepWaitTouchThenExit(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitTimeout(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitFinalSync(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepShowStartMessage(IrcBattleMatchWork *work);
int IRCBATTLEMATCH_GetSharedBattleReadyCount(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepApplyPartyRules(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendRegulation(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendPlayerSlots(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendMacAddress(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendTrainerInfo(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendMyStatus(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepCompareModes(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepResumeWaiting(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitQuitChoice(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepOpenQuitConfirm(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepSendMode(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepRegisterCommands(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_CollectMacAddresses(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_OnChangeoverResult(IrcBattleMatchWork *work,int role);
void IRCBATTLEMATCH_SetupDisplay(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_VBlankTask(void);
void IRCBATTLEMATCH_OpenQuitMenu(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_OpenWaitMenu(IrcBattleMatchWork *work,int twoItems);
void IRCBATTLEMATCH_PrintMainMessage(MessageRef *message,IrcBattleMatchWork *work);
void IRCBATTLEMATCH_PrintPlayerMessage(int msgId,IrcBattleMatchWork *work);
void IRCBATTLEMATCH_PrintRetryMessage(int msgId,IrcBattleMatchWork *work);
void IRCBATTLEMATCH_FreeMessageWindows(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_InitWindowSystem(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_ExitWindowSystem(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_DeleteActor(IrcBattleMatchWork *work,unsigned slot);
void IRCBATTLEMATCH_PrintWaitingMessage(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_InitScreen(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitFadeIn(IrcBattleMatchWork *work);
int IRCBATTLEMATCH_IsCompatibleGameKind(int a,int b);
void IRCBATTLEMATCH_StepStartSession(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_ExitScreen(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepStartChangeover(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepRedrawWaitMenu(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitQuitChoiceDuringWait(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitErrorDialogClose(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitWirelessStep(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepOpenWirelessWaitMenu(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepRestoreWaitMenu(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitCancelChoice(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitTouchThenCancel(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepOpenQuitConfirmDuringWait(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepOpenCancelConfirm(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepCountdownThenExit(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepShowErrorMessage(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitErrorChoice(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepOpenErrorConfirm(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_IconAnimLeft(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_IconAnimRight(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepShowDisconnectMessage(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepAnimateIcons(IrcBattleMatchWork *work);
void IRCBATTLEMATCH_StepWaitSession(IrcBattleMatchWork *work);
int IRCBATTLEMATCH_ProcInit(struct Proc *proc, int seq, IrcBattleMatchParam *param);
u32 IRCBATTLEMATCH_ProcMain(u32 a, u32 b, u32 c, IrcBattleMatchWork *work);
int IRCBATTLEMATCH_ProcExit(struct Proc *proc, int b, int c, IrcBattleMatchWork *work);

extern char gIrcBattleMatchRecvBuffer[];
extern const MessageRef gIrcBattleMatchMsgRegulationPassed,gIrcBattleMatchMsgRegulationFailed;
extern const MessageRef gIrcBattleMatchMsgQuitConfirm;
extern const unsigned gIrcBattleMatchCommandTable[];
extern const unsigned int gIrcBattleMatchDispConfig[];
extern const BgTemplate gIrcBattleMatchBgTemplate0,gIrcBattleMatchBgTemplate1,gIrcBattleMatchBgTemplate4,gIrcBattleMatchBgTemplate5,gIrcBattleMatchBgTemplate6,gIrcBattleMatchBgTemplate7;
extern const MessageRef gIrcBattleMatchMsgPartnerLeft,gIrcBattleMatchMsgWaitingMode7Full,gIrcBattleMatchMsgWaitingMode7,gIrcBattleMatchMsgWaitingMode6,gIrcBattleMatchMsgWaitingMode5,gIrcBattleMatchMsgWaitingMode9,gIrcBattleMatchMsgWaitingMode10,gIrcBattleMatchMsgWaitingMode11,gIrcBattleMatchMsgWaitingDefault;
extern const u32 gClActorInitParam[],gIrcBattleMatchVramBanks[];
extern const NetSessionReq gIrcBattleMatchSessionReq;
extern const MessageRef gIrcBattleMatchMsgCancelConfirm;
extern const MessageRef gIrcBattleMatchMsgCancelConfirmAlt;
extern const MessageRef gIrcBattleMatchMsgErrorConfirm;
extern const MessageRef gIrcBattleMatchMsgDisconnected;
extern const MessageRef gIrcBattleMatchMsgIconsParent,gIrcBattleMatchMsgIconsChild;
extern MessageRef gIrcBattleMatchModeMessages[];
extern const char gIrcBattleMatchFileName[];


char *IRCBATTLEMATCH_GetRecvBuffer(void)
{
    return gIrcBattleMatchRecvBuffer;
}

/*
 * Unlabelled leaf at the start of ov100 (the listing prints it as .word
 * data); referenced as 0x021B95A9 from the table word at 021BB858.
 */
int IRCBATTLEMATCH_GetRecvSize(void)
{
    return 4;
}

int IRCBATTLEMATCH_IsEqual(int a, int b)
{
    if (a == b)
        return 1;
    return 0;
}


void IRCBATTLEMATCH_SetStep(IrcBattleMatchWork *work, IrcBattleMatchStep step) { work->step = step; }

int IRCBATTLEMATCH_AbortSession(IrcBattleMatchWork *work) { work->param->mode=12; GFL_NET_IRC_WIRELESS_Exit(); return GFL_NET_Exit(0); }

/*
 * Extent remainder: two-byte alignment padding.
 */
void IRCBATTLEMATCH_StepWipeEnd(IrcBattleMatchWork *work) { if(WIPE_SYS_EndCheck()) IRCBATTLEMATCH_SetStep(work,0); }


/*
 *          (site +0084) have no witness outside this function's range.
 *          Both are unlabelled Thumb leaves in the ARM9 image, so neither
 *          `label` nor `sole-ref/code` can attest them; each call is their
 *          only referrer image-wide.  Every other byte is correct.
 */
int IRCBATTLEMATCH_BlendBgPalette(IrcBattleMatchWork *work, int bgSlot, int paletteCount)
{
    int palAnim;
    int byteSize;
    int transWork;

    palAnim = (int)PALANM_Create(work->heapId);
    PALANM_AllocSlotBuffers((struct PalAnmSlot *)palAnim, bgSlot, 0x200, work->heapId);
    byteSize = paletteCount << 5;
    PALANM_CopyHwPaletteToSlot((struct PalAnmSlot *)palAnim, bgSlot, 0, byteSize);
    PALANM_BlendChannel((struct Chan02021FD8 *)palAnim, bgSlot, 0, (u16)(paletteCount << 4), 6, 0);
    transWork = PALANM_GetTransWork((char *)palAnim, bgSlot);
    DC_FlushRange(transWork, byteSize);
    if (bgSlot != 1) {
        if (bgSlot == 3)
            GXS_LoadOBJPltt(transWork, 0, byteSize);
    } else {
        GXS_LoadBGPltt(transWork, 0, byteSize);
    }
    PALANM_FreeSlotBuffers((struct PalAnmSlot *)palAnim, bgSlot);
    return PALANM_Delete((void *)palAnim);
}

void IRCBATTLEMATCH_SetPaletteFade(IrcBattleMatchWork *work,int enable){if(enable){MI_CpuCopy8((void *)PLTT_SUB_BG_ADDR,work->paletteBackup,0x200);IRCBATTLEMATCH_BlendBgPalette(work,1,9);}else{GXS_LoadBGPltt((int)work->paletteBackup,0,0x120);}}

void IRCBATTLEMATCH_StartExitWipe(IrcBattleMatchWork *work){WIPE_SYS_Start(0,0,0,0,6,1,work->heapId);IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWipeEnd);}

/*
 * extent: 94 bytes code followed by two zero alignment bytes before 021B974C.
 */
void IRCBATTLEMATCH_LoadActorResources(IrcBattleMatchWork *work)
{
    void *arc;
    arc = ARC_TOOL_CreateHandle(28, work->heapId);
    work->actorCharId = CLACT_RegisterCharacter(arc, 7, 0, 0, work->heapId);
    work->actorPaletteId = CLACT_RegisterPaletteEx(arc, 3, 0, 0, 0, 3, work->heapId);
    work->actorCellAnimId = CLACT_RegisterCellAnim(arc, 9, 15, work->heapId);
    ARC_TOOL_DeleteHandle(arc);
}

void IRCBATTLEMATCH_CreateActor(IrcBattleMatchWork *work,int x,int y,int slot,int animSeq)
{
 ActorParam param;
 if(work->actors[slot]==0) {
  param.x=x; param.y=y; param.animSeq=animSeq; param.slot=slot; param.mode=2;
  work->actors[slot]=CLACT_CreateActor(work->clactUnit,work->actorCharId,work->actorPaletteId,work->actorCellAnimId,&param,0,work->heapId);
  CLACT_SetActorAutoAnim(work->actors[slot],1);
  CLACT_SetActorDrawEnable(work->actors[slot],1);
  CLACT_SetActorAffineMode((struct Actor *)work->actors[slot],2);
 }
}

void IRCBATTLEMATCH_NudgeActor(IrcBattleMatchWork *work,int dx,int dy,int slot)
{
 struct Vec2Short { s16 x,y; } pos;
 if(work->actors[slot] != 0) {
  CLACT_GetActorSurfacePos((struct Actor *)work->actors[slot],(struct PtS *)&pos,0);
  pos.x += (s16)dx;
  pos.y += (s16)dy;
  CLACT_AddActorSurfacePos(work->actors[slot],(const struct Vec2 *)(&pos),0);
 }
}

/* stand-in: the address is written as (int)work + 0x2c8 + slot * 4; work->actors[slot] compiles four bytes shorter. */
void IRCBATTLEMATCH_MoveActor(IrcBattleMatchWork *work,int x,int y,int slot) { struct Vec2Short { s16 x,y; } pos; struct Obj *actor; actor=*(struct Obj **)((int)work+0x2c8+slot*4); if(actor){pos.x=x;pos.y=y;CLACT_AddActorSurfacePos(actor,(const struct Vec2 *)(&pos),0);} }

void IRCBATTLEMATCH_SetPlayerReady(IrcBattleMatchWork *work,int aid)
{
 if(MATH_CountPopulation(work->readyMask |= 1 << aid)>=2) work->allReady=1;
}

void IRCBATTLEMATCH_OnChangeoverConnected(IrcBattleMatchWork *work)
{
 if(work->mode!=5) {
  work->showTrigger=1; work->iconsVisible=1; work->partnerLeft=1;
 } else {
  if(work->changeoverRole!=0 && work->iconAnimTimer!=0) {
   work->showTrigger=1; work->iconsVisible=1;
  }
 }
}

void IRCBATTLEMATCH_RecvModeHandler(unsigned aid,int size,int *data,IrcBattleMatchWork *work,void *handle)
{
 if(handle==GFL_NET_HANDLE_GetCurrentHandle()) work->modeByAid[aid]=*data;
}

void IRCBATTLEMATCH_RecvMyStatusHandler(int aid,int size,int data,IrcBattleMatchWork *work,int handle)
{
 int record;
 int saveData;
 if(handle==(int)GFL_NET_HANDLE_GetCurrentHandle()) {
  record=(int)GAME_DATA_GetPlayerStatusById((struct Sub24 *)work->param->gameData,aid);
  MYSTATUS_Copy((void *)data,(void *)record);
  saveData=(int)MISC_SAVEDATA_GetBlock44(GAME_DATA_GetSaveControl((struct Big *)work->param->gameData));
 MISC_SAVEDATA_InsertRecentValue((struct L0200ED54 *)saveData,MYSTATUS_GetId((const struct Sub0200852CObj *)record));
 }
}

void IRCBATTLEMATCH_NoOp(void) {}

int IRCBATTLEMATCH_GetParty(int index,IrcBattleMatchWork *work)
{
 if(index>=0 && index<4) return (int)work->param->party[index];
 return 0;
}

void IRCBATTLEMATCH_RecvTrainerInfoHandler(int aid,int size,int data,IrcBattleMatchWork *work,int handle)
{
 void *records = work->param->gameData;
 if (handle == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
  if (aid != GFL_NET_SYSTEM_GetCurrentAid()) {
   int record = (int)GAME_DATA_GetPlayerStatusById((struct Sub24 *)records,aid);
   work->regulationResult = GFL_NET_ERR_InsertFriend(records,(void *)record,(void *)data,(void *)(work->heapId));
  }
 }
}

void IRCBATTLEMATCH_RecvMacAddressHandler(int aid,int size,void *data,IrcBattleMatchWork *work,int handle)
{
 u8 *macs;
 int i;
 if(handle == (int)GFL_NET_HANDLE_GetCurrentHandle()) {
  if(GFL_NET_IsParentAid() != 0) {
   i=0;
   macs = (u8 *)work->macAddress;
   for(;i<4;i++) {
    if(GF_STANDARD_CompareBytes(macs+i*6,data,6)==0) {
     work->param->playerSlot[aid]=i;
     return;
    }
   }
  }
 }
}

void IRCBATTLEMATCH_RecvPlayerSlotsHandler(int aid,int size,void *data,IrcBattleMatchWork *work,void *handle)
{
 if(handle==GFL_NET_HANDLE_GetCurrentHandle()) {
  if(aid!=GFL_NET_SYSTEM_GetCurrentAid()) MI_CpuCopy8(data,work->param->playerSlot,4);
 }
}

void IRCBATTLEMATCH_StepWaitTouchThenExit(IrcBattleMatchWork *work)
{
 if(TOUCHPANEL_GetTrg()!=0) {
  IRCBATTLEMATCH_AbortSession(work);
  IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StartExitWipe);
 }
}

void IRCBATTLEMATCH_StepWaitTimeout(IrcBattleMatchWork *work)
{
 if(++work->timer>60) {
  GFL_NET_Exit(0);
  IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitTouchThenExit);
 }
}

void IRCBATTLEMATCH_StepWaitFinalSync(IrcBattleMatchWork *work)
{
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7f,12)!=0) {
  GFL_NET_SetAutoExit(0); GFL_NET_SetLoginOption(0);
  work->timer=0;
  IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitTimeout);
 }
}

/*
 * lever: one-word aggregate assignment schedules the stack address before its load/store.
 */
void IRCBATTLEMATCH_StepShowStartMessage(IrcBattleMatchWork *work)
{
 if(work->regulationResult!=0) {
  MessageRef message=gIrcBattleMatchMsgRegulationPassed;
  IRCBATTLEMATCH_PrintMainMessage(&message,work);
 } else {
  MessageRef message=gIrcBattleMatchMsgRegulationFailed;
  IRCBATTLEMATCH_PrintMainMessage(&message,work);
 }
 IRCBATTLEMATCH_PrintPlayerMessage(0x22,work);
 GFL_USE_PlaySeDefaultVolume(0x764);
 GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7f,12);
 IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitFinalSync);
}

int IRCBATTLEMATCH_GetSharedBattleReadyCount(IrcBattleMatchWork *work)
{
 int ownCount; int partnerCount;
 ownCount=POKEPARTY_GetBattleReadyCount(work->param->party[0]);
 partnerCount=POKEPARTY_GetBattleReadyCount(work->param->party[1]);
 if(ownCount>partnerCount) return partnerCount;
 return ownCount;
}

void IRCBATTLEMATCH_StepApplyPartyRules(IrcBattleMatchWork *work)
{
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7a,12)!=0) {
  switch(work->mode) {
  case 7: IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepShowStartMessage); return;
  case 1: case 2: case 3: case 4:
   POKE_TOOL_HealParty(work->param->party[0]);
   POKE_TOOL_HealParty(work->param->party[1]);
   switch(IRCBATTLEMATCH_GetSharedBattleReadyCount(work)) {
    case 0: break;
    case 1: work->param->mode=1; break;
    case 2: if(work->param->mode>2) work->param->mode=2; break;
   }
   IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StartExitWipe);
  default: case 0: case 5: case 6: IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StartExitWipe); break;
  }
 }
}

void IRCBATTLEMATCH_StepSendRegulation(IrcBattleMatchWork *work)
{
 int syncId=12;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7e,syncId)!=0) {
  int handle=(int)GFL_NET_HANDLE_GetCurrentHandle();
  int regulationSize=POKE_REGULATION_GetDataSize();
  if(GFL_NET_SendData(handle,0xff,0xc02,regulationSize,(u32)work->param->regulation,0,0,1)!=0) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7a,syncId);
   IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepApplyPartyRules);
  }
 }
}

void IRCBATTLEMATCH_StepSendPlayerSlots(IrcBattleMatchWork *work)
{
 int syncId=12;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7d,syncId)!=0) {
  if(GFL_NET_IsParentAid()!=0) {
   if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc05,4,(u32)work->param->playerSlot)!=0) {
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7e,syncId);
    IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepSendRegulation);
   }
  } else {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7e,syncId);
   IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepSendRegulation);
  }
 }
}

void IRCBATTLEMATCH_StepSendMacAddress(IrcBattleMatchWork *work)
{
 u8 macAddress[6];
 int syncId=12;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x79,syncId)!=0) {
  int mode=work->mode;
  switch(mode) {
  case 9: case 10: case 11:
   IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StartExitWipe);
   return;
  default: break;
  }
  OS_GetMacAddress(macAddress);
  if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc04,6,(u32)macAddress)!=0) {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7d,syncId);
   IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepSendPlayerSlots);
  }
 }
}

void IRCBATTLEMATCH_StepSendTrainerInfo(IrcBattleMatchWork *work)
{
 u8 trainerInfo[12];
 int syncId=12;
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7b,syncId)!=0) {
  if(work->mode==7) {
   WIFILIST_CreateExchangeToken((void *)GAME_DATA_GetField1A0((const struct BigObj *)work->param->gameData),trainerInfo);
   if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc03,syncId,(u32)trainerInfo)!=0) {
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x79,syncId);
    IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepSendMacAddress);
    if(work->taskMenu!=0) {
     APP_TASKMENU_CloseMenu(work->taskMenu);
     work->taskMenu=0;
    }
   }
  } else {
   GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x79,syncId);
   if(work->taskMenu!=0) {
    APP_TASKMENU_CloseMenu(work->taskMenu);
    work->taskMenu=0;
   }
   IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepSendMacAddress);
  }
 }
}

void IRCBATTLEMATCH_StepSendMyStatus(IrcBattleMatchWork *work) {
 int handle=(int)GFL_NET_HANDLE_GetCurrentHandle();
 int myStatusSize=MYSTATUS_GetSize();
 int myStatus=(int)GAME_DATA_GetMyStatus((void *)work->param->gameData);
 if(GFL_NET_SendToHandle((void *)handle,(u16)0xc01,(u16)myStatusSize,myStatus)!=0) {
  GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7b,12);
  IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepSendTrainerInfo);
 }
}

void IRCBATTLEMATCH_StepCompareModes(IrcBattleMatchWork *work) {
 if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x7c,12)!=0) {
  int aid=GFL_NET_SYSTEM_GetCurrentAid();
  int mode=work->mode;
  switch(mode) {
  case 1: case 2: case 3: case 4: {
   int partnerMode=work->modeByAid[1-aid];
   if(mode>partnerMode) work->param->mode=partnerMode;
   break;
  }
  }
  IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepSendMyStatus);
 }
}

void IRCBATTLEMATCH_StepResumeWaiting(IrcBattleMatchWork *work)
{
 MessageRef message;
 IRCBATTLEMATCH_FreeMessageWindows(work);
 message.msgId=work->lastMessageId;
 IRCBATTLEMATCH_PrintMainMessage(&message,work);
 IRCBATTLEMATCH_OpenWaitMenu(work,0);
 IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepSendMode);
}

void IRCBATTLEMATCH_StepWaitQuitChoice(IrcBattleMatchWork *work) {
 if(APP_TASKMENU_IsFinish(work->taskMenu)!=0) {
  int choice=APP_TASKMENU_GetCursorPos(work->taskMenu);
  APP_TASKMENU_CloseMenu(work->taskMenu);
  work->taskMenu=0;
  BG_SYS_SetFlagField06(6);
  if(choice==0) {
   IRCBATTLEMATCH_FreeMessageWindows(work);
   IRCBATTLEMATCH_AbortSession(work);
   IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StartExitWipe);
  } else IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepResumeWaiting);
  IRCBATTLEMATCH_SetPaletteFade(work,0);
 }
}

void IRCBATTLEMATCH_StepOpenQuitConfirm(IrcBattleMatchWork *work) {
 MessageRef message=gIrcBattleMatchMsgQuitConfirm;
 int savedMessageId=work->lastMessageId;
 ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,0x180,32,work->heapId);
 IRCBATTLEMATCH_PrintMainMessage(&message,work);
 work->lastMessageId=savedMessageId;
 IRCBATTLEMATCH_OpenQuitMenu(work);
 GF_FONT_SetDefaultTextColor();
 IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitQuitChoice);
}


void IRCBATTLEMATCH_StepSendMode(IrcBattleMatchWork *work)
{
    if (work->taskMenu != 0) {
        if (APP_TASKMENU_IsFinish(work->taskMenu) != 0) {
            APP_TASKMENU_GetCursorPos(work->taskMenu);
            APP_TASKMENU_CloseMenu(work->taskMenu);
            work->taskMenu = 0;
            BG_SYS_SetFlagField06(6);
            IRCBATTLEMATCH_SetStep(work, IRCBATTLEMATCH_StepOpenQuitConfirm);
            return;
        }
    } else {
        IRCBATTLEMATCH_OpenWaitMenu(work, 0);
        return;
    }
    {
        int syncId = 0xc;

        if (GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x78, syncId) != 0) {
            if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), syncId << 8, 4, (u32)&work->mode) != 0) {
                GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(), 0x7c, syncId);
                IRCBATTLEMATCH_SetStep(work, IRCBATTLEMATCH_StepCompareModes);
            }
        }
    }
}

void IRCBATTLEMATCH_StepRegisterCommands(IrcBattleMatchWork *work)
{
 GFL_NET_COMMAND_AddCommandTable(0xc00,(unsigned)gIrcBattleMatchCommandTable,6,work);
 GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),0x78,12);
 GFL_NET_SetAutoExit(1);GFL_NET_SetLoginOption(1);
 IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepSendMode);
}

void IRCBATTLEMATCH_CollectMacAddresses(IrcBattleMatchWork *work) {
 if(GFL_NET_IsParentAid()!=0) {
  char *macs;
  int i=0;
  macs=(char *)work->macAddress;
  for(;i<4;i++) GFL_NET_IRC_WIRELESS_GetMacAddress(macs+i*6,i);
 }
 IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepRegisterCommands);
}

void IRCBATTLEMATCH_OnChangeoverResult(IrcBattleMatchWork *work,int role) {
 work->changeoverRole=role;
 work->iconsDirty=1;
 work->iconsAnimating=1;
 if(work->mode==5 && role==0) {
  work->showTrigger=1;
  work->iconsVisible=1;
 }
}

void IRCBATTLEMATCH_SetupDisplay(IrcBattleMatchWork *work) {
 BG_SYS_SetVramBanks((const struct DispVram *)gIrcBattleMatchVramBanks);BG_SYS_SetGraphicsMode((struct DispConfig *)gIrcBattleMatchDispConfig);
 BG_SYS_SetMainVisiblePlanes(0);BG_SYS_SetSubVisiblePlanes(0);
 {BgTemplate bg=gIrcBattleMatchBgTemplate0;BG_SYS_InitBgLayer(0,&bg,0);BG_SYS_SetTileEntry(0,0,0,0,32,32,17);BG_SYS_PushTile(0);}
 {BgTemplate bg=gIrcBattleMatchBgTemplate1;BG_SYS_InitBgLayer(1,&bg,0);BG_SYS_SetTileEntry(1,0,0,0,32,32,17);BG_SYS_PushTile(1);}
 {BgTemplate bg=gIrcBattleMatchBgTemplate4;BG_SYS_InitBgLayer(4,&bg,0);BG_SYS_SetTileEntry(4,0,0,0,32,32,17);}
 {BgTemplate bg=gIrcBattleMatchBgTemplate5;BG_SYS_InitBgLayer(5,&bg,0);BG_SYS_SetTileEntry(5,0,0,0,32,32,17);BG_SYS_PushTile(5);}
 {BgTemplate bg=gIrcBattleMatchBgTemplate6;BG_SYS_InitBgLayer(6,&bg,0);BG_SYS_Init(6,0,1,0);BG_SYS_SetTileEntry(6,0,0,0,32,32,17);BG_SYS_PushTile(6);}
 {BgTemplate bg=gIrcBattleMatchBgTemplate7;BG_SYS_InitBgLayer(7,&bg,0);BG_SYS_SetTileEntry(7,0,0,0,32,32,17);BG_SYS_PushTile(7);}
}

void IRCBATTLEMATCH_VBlankTask(void) { CLACT_VBlankSystem(); }

void IRCBATTLEMATCH_OpenQuitMenu(IrcBattleMatchWork *work) {
 TaskMenuTemplate menu;
 struct TaskMenu *taskMenu;
 menu.heapId=work->heapId;
 menu.itemCount=2;
 menu.items=work->menuItems;
 menu.flag=1;
 menu.x=32; menu.y=13; menu.paletteSlot=13; menu.layer=3;
 work->menuItems[0].label=STRBUF_Create(100,menu.heapId);
 MSGDATA_ReadString(work->msgData,26,work->menuItems[0].label);
 work->menuItems[0].color=0x39e3;
 work->menuItems[1].label=STRBUF_Create(100,work->heapId);
 MSGDATA_ReadString(work->msgData,27,work->menuItems[1].label);
 work->menuItems[1].color=0x39e3;
 work->menuItems[0].selectType=0;
 work->menuItems[1].selectType=0;
 taskMenu=APP_TASKMENU_OpenMenu(&menu,work->taskMenuRes);
 work->taskMenu=taskMenu;
 switch(work->mode) {case 9: case 10: case 11: break; default: APP_TASKMENU_SetDisableKey(taskMenu,1); break;}
 STRBUF_Delete(work->menuItems[0].label);
 STRBUF_Delete(work->menuItems[1].label);
 IRCBATTLEMATCH_SetPaletteFade(work,1);
}

void IRCBATTLEMATCH_OpenWaitMenu(IrcBattleMatchWork *work,int twoItems) {
 TaskMenuTemplate menu;
 menu.heapId=work->heapId;
 menu.flag=1;
 menu.x=32;menu.y=24;menu.paletteSlot=13;menu.layer=3;
 if(twoItems!=0) {
  menu.itemCount=2;menu.items=work->menuItems;
  work->menuItems[0].label=STRBUF_Create(100,menu.heapId);
  MSGDATA_ReadString(work->msgData,0x23,work->menuItems[0].label);
  work->menuItems[0].color=0x39e3;work->menuItems[0].selectType=0;
  work->menuItems[1].label=STRBUF_Create(100,work->heapId);
  MSGDATA_ReadString(work->msgData,2,work->menuItems[1].label);
  work->menuItems[1].color=0x39e3;work->menuItems[1].selectType=1;
  work->taskMenu=APP_TASKMENU_OpenMenu(&menu,work->taskMenuRes);
  STRBUF_Delete(work->menuItems[0].label);STRBUF_Delete(work->menuItems[1].label);
  work->menuKind=0;
 } else {
  menu.itemCount=1;menu.items=work->menuItems;
  work->menuItems[0].label=STRBUF_Create(100,menu.heapId);
  MSGDATA_ReadString(work->msgData,2,work->menuItems[0].label);
  work->menuItems[0].color=0x39e3;work->menuItems[0].selectType=1;
  work->taskMenu=APP_TASKMENU_OpenMenu(&menu,work->taskMenuRes);
  STRBUF_Delete(work->menuItems[0].label);work->menuKind=1;
 }
 switch(work->mode) {case 9:case 10:case 11:break;default:APP_TASKMENU_SetDisableKey(work->taskMenu,1);break;}
}

void IRCBATTLEMATCH_PrintMainMessage(MessageRef *message,IrcBattleMatchWork *work) {
 ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,0x1a0,32,work->heapId);
 if(work->messageWin==0) {
  struct Descriptor *win=BMP_WIN_Create(5,1,1,30,5,13,0);
  work->messageWin=win;
  BMP_WIN_MakeScreen(win);
  BMP_MENUWORK_DrawWindow(work->messageWin,0,(unsigned short)(work->windowPalette),14);
 }
 BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp(work->messageWin)),255);
 work->lastMessageId=message->msgId;
 MSGDATA_ReadString(work->msgData,message->msgId,work->msgStr);
 PRINTSYS_Print(BMP_WIN_GetBmp(work->messageWin),4,4,work->msgStr,work->font);
 BMP_WIN_TransferChars(work->messageWin);
}

void IRCBATTLEMATCH_PrintPlayerMessage(int msgId,IrcBattleMatchWork *work) {
 if(work->infoWin==0) {
  struct Descriptor *win=BMP_WIN_Create(5,1,8,18,4,13,0);
  work->infoWin=win;
  BMP_WIN_MakeScreen(win);
  BMP_MENUWORK_DrawWindow(work->infoWin,0,(unsigned short)(work->windowPalette),14);
 }
 BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp(work->infoWin)),255);
 MSGDATA_ReadString(work->msgData,msgId,work->tempStr);
 WORDSET_SetSlotNumber(work->wordSet,0,WIFILIST_CountFriends((struct Sub020097BCObj *)GAME_DATA_GetField1A0((const struct BigObj *)work->param->gameData)),2,1,1);
 WORDSET_SetSlotNumber(work->wordSet,1,32,2,1,1);
 WORDSET_CopyTaggedText(work->wordSet,work->msgStr,work->tempStr);
 PRINTSYS_Print(BMP_WIN_GetBmp(work->infoWin),0,2,work->msgStr,work->font);
 BMP_WIN_TransferChars(work->infoWin);
}

/*
 *   veneer evidence cannot attest the target. the integrator owns the ARM9 fix.
 * note 2026-10-04 (wD2 lane18): still MATCH, only unresolved relocations remain: callee GFL_NET_IRC_WIRELESS_GetRetryCount (veneer to 0x0203E590) still has no witness; GFL_NET_IRC_WIRELESS_GetRetryCountValue filed EXACT as src/matched/arm9/GFL_NET_IRC_WIRELESS_GetRetryCountValue.c, integrator must regenerate labels/manifest so the veneer resolves.
 */
void IRCBATTLEMATCH_PrintRetryMessage(int msgId,IrcBattleMatchWork *work) {
 if(work->infoWin==0) work->infoWin=BMP_WIN_Create(5,1,8,23,4,13,0);
 BMP_Clear(BMP_WIN_GetBmp(work->infoWin),255);
 BMP_WIN_MakeScreen(work->infoWin);
 BMP_WIN_TransferChars(work->infoWin);
 BMP_MENUWORK_DrawWindow(work->infoWin,0,(unsigned short)(work->windowPalette),14);
 MSGDATA_ReadString(work->msgData,msgId,work->tempStr);
 WORDSET_SetSlotNumber(work->wordSet,0,GFL_NET_IRC_WIRELESS_GetRetryCount(),2,1,1);
 WORDSET_CopyTaggedText(work->wordSet,work->msgStr,work->tempStr);
 PRINTSYS_Print(BMP_WIN_GetBmp(work->infoWin),0,2,work->msgStr,work->font);
 BMP_WIN_TransferChars(work->infoWin);
}

void IRCBATTLEMATCH_FreeMessageWindows(IrcBattleMatchWork *work)
{
 if(work->messageWin!=0) BMP_WIN_Delete(work->messageWin);
 if(work->infoWin!=0) BMP_WIN_Delete(work->infoWin);
 work->messageWin=0;
 work->infoWin=0;
}

void IRCBATTLEMATCH_InitWindowSystem(IrcBattleMatchWork *work)
{
 BG_SYS_Create(work->heapId);
 BMP_WIN_Init(work->heapId);
 GF_FONT_InitTextColor();
}

void IRCBATTLEMATCH_ExitWindowSystem(IrcBattleMatchWork *work) { BG_SYS_Delete(); BMP_WIN_Exit(); }

void IRCBATTLEMATCH_DeleteActor(IrcBattleMatchWork *work,unsigned slot)
{
 if(work->actors[slot]!=0) {
  CLACT_DeleteActor(work->actors[slot]);
  work->actors[slot]=0;
 }
}

void IRCBATTLEMATCH_PrintWaitingMessage(IrcBattleMatchWork *work) {
 if(work->partnerLeft==1) {MessageRef message=gIrcBattleMatchMsgPartnerLeft;IRCBATTLEMATCH_PrintMainMessage(&message,work);return;}
 if(work->mode==7) {
  if(WIFILIST_CountFriends((struct Sub020097BCObj *)GAME_DATA_GetField1A0((const struct BigObj *)work->param->gameData))==32) {MessageRef message=gIrcBattleMatchMsgWaitingMode7Full;IRCBATTLEMATCH_PrintMainMessage(&message,work);return;}
  else {MessageRef message=gIrcBattleMatchMsgWaitingMode7;IRCBATTLEMATCH_PrintMainMessage(&message,work);IRCBATTLEMATCH_PrintPlayerMessage(0x22,work);return;}
 }
 if(work->mode==6) {MessageRef message=gIrcBattleMatchMsgWaitingMode6;IRCBATTLEMATCH_PrintMainMessage(&message,work);return;}
 if(work->mode==5) {MessageRef message=gIrcBattleMatchMsgWaitingMode5;IRCBATTLEMATCH_PrintMainMessage(&message,work);return;}
 if(work->mode==9) {MessageRef message=gIrcBattleMatchMsgWaitingMode9;IRCBATTLEMATCH_PrintMainMessage(&message,work);IRCBATTLEMATCH_PrintRetryMessage(0x27,work);return;}
 if(work->mode==10) {MessageRef message=gIrcBattleMatchMsgWaitingMode10;IRCBATTLEMATCH_PrintMainMessage(&message,work);return;}
 if(work->mode==11) {MessageRef message=gIrcBattleMatchMsgWaitingMode11;IRCBATTLEMATCH_PrintMainMessage(&message,work);return;}
 else {MessageRef message=gIrcBattleMatchMsgWaitingDefault;IRCBATTLEMATCH_PrintMainMessage(&message,work);return;}
}

void IRCBATTLEMATCH_InitScreen(IrcBattleMatchWork *work) {
 void *arc;
 void *rawData;
 void *resource;
 int i;
 GF_FONT_SetDefaultTextColor();
 work->wordSet=WORDSET_Create(11,200,work->heapId);
 IRCBATTLEMATCH_InitWindowSystem(work);IRCBATTLEMATCH_SetupDisplay(work);
 work->msgStr=STRBUF_Create(200,work->heapId);
 work->tempStr=STRBUF_Create(200,work->heapId);
 work->font=GF_FONT_Create(23,0,0,0,work->heapId);
 work->msgData=MSGDATA_CreateFromArchive(0,2,46,work->heapId);
 arc=ARC_TOOL_CreateHandle(28,work->heapId);
 ARC_UTIL_UploadPaletteFromHandleWhole(arc,1,0,0,0,work->heapId);
 work->bgCharId=(int)ARC_UTIL_RegisterObjCharFromHandle(arc,6,0,0,0,work->heapId);
 if(work->mode!=5) ARC_UTIL_UploadBgPaletteAddFromHandle(arc,13,1,0,(u16)(work->bgCharId),0,0,work->heapId);
 else {ARC_UTIL_UploadBgPaletteAddFromHandle(arc,13,0,0,(u16)(work->bgCharId),0,0,work->heapId);ARC_UTIL_UploadBgPaletteAddFromHandle(arc,14,1,0,(u16)(work->bgCharId),0,0,work->heapId);}
 ARC_TOOL_DeleteHandle(arc);
 arc=ARC_TOOL_CreateHandle(29,work->heapId);
 ARC_UTIL_UploadPaletteFromHandleWhole(arc,1,4,0,0,work->heapId);
 work->bgScreenId=(int)ARC_UTIL_RegisterObjCharFromHandle(arc,4,4,0,0,work->heapId);
 ARC_UTIL_UploadBgPaletteAddFromHandle(arc,9,4,0,(u16)(work->bgScreenId),0,0,work->heapId);ARC_TOOL_DeleteHandle(arc);
 work->windowPalette=(int)BMP_MENUWORK_LoadFrameGfx((void *)5,14,0,work->heapId);
 FADE_Start(3,16,0,2);IRCBATTLEMATCH_PrintWaitingMessage(work);
 CLACT_InitSystem((const struct Cfg *)gClActorInitParam,(u32)gIrcBattleMatchVramBanks,work->heapId);
 work->clactUnit=CLACT_CreateUnit(40,0,work->heapId);
 work->vblankTask=GFL_USE_AddMainTask(IRCBATTLEMATCH_VBlankTask,work,0);
 work->printQue=PRINTSYS_QUE_Create((void *)(work->heapId));
 work->taskMenuRes=APP_TASKMENU_RES_Create(6,9,(u32)work->font,(u32)work->printQue,work->heapId);
 IRCBATTLEMATCH_LoadActorResources(work);
 if(work->mode!=5) {
  IRCBATTLEMATCH_CreateActor(work,57,154,2,10);IRCBATTLEMATCH_CreateActor(work,128,113,4,2);IRCBATTLEMATCH_CreateActor(work,200,38,0,11);IRCBATTLEMATCH_CreateActor(work,128,77,5,3);
 } else {
  IRCBATTLEMATCH_CreateActor(work,57,154,0,4);IRCBATTLEMATCH_CreateActor(work,198,154,1,5);IRCBATTLEMATCH_CreateActor(work,200,38,2,6);IRCBATTLEMATCH_CreateActor(work,55,38,3,7);IRCBATTLEMATCH_CreateActor(work,152,146,6,0);IRCBATTLEMATCH_CreateActor(work,103,146,7,1);IRCBATTLEMATCH_CreateActor(work,152,46,4,0);IRCBATTLEMATCH_CreateActor(work,103,46,5,1);
 }
 BG_SYS_SetMainVisiblePlanes((int)19);BG_SYS_SetSubVisiblePlanes((int)23);
 work->heapIdCopy=work->heapId;
 arc=ARC_TOOL_CreateHandle(28,work->heapIdCopy);
 rawData=ARC_UTIL_LoadPaletteBlockFromHandle(arc,2,(u32)(&resource),work->heapIdCopy);
 MI_CpuCopy8(*(void **)((u8 *)resource+12),work,0x120);
 for(i=0;i<9;i++) MI_CpuCopy8(work->palette[8-i],work->palette[i+9],32);
 GFL_HEAP_Free(rawData);ARC_TOOL_DeleteHandle(arc);IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitFadeIn);
}

void IRCBATTLEMATCH_StepWaitFadeIn(IrcBattleMatchWork *work) {
 if(FADE_IsActive()!=0) {
  if(work->mode==7) {
   if(WIFILIST_CountFriends((struct Sub020097BCObj *)GAME_DATA_GetField1A0((const struct BigObj *)work->param->gameData))==32) {
    IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepCountdownThenExit);
    work->timer=180;
    return;
   }
  }
  IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepStartSession);
 }
}

int IRCBATTLEMATCH_IsCompatibleGameKind(int a,int b) {
 if(a==19 && b==18) return 1;
 if(b==19 && a==18) return 1;
 return 0;
}

/*
 *   Exact non-C body: E59FC000,E12FFF1C,0203DA68; unlabelled target.
 *   Data021BB83C resolves sole-ref on the byte-correct 256-byte run.
 *   D0C4 tail-forwards r0 unchanged; full DA68 body reads only that u32,
 *   copies it unchanged to singleton+74, no arithmetic or narrowing.
 *   scratch-only DA68 one --arm (no region), fixed flags: EXACT20, literal15.
 *   Verified C (not filed ARM9): extern unsigned char *gNetIrcWirelessLink;
 *   void GFL_NET_IRC_WIRELESS_SetSessionParamValue(unsigned int value) {
 *       *(unsigned int *)(gNetIrcWirelessLink+0x74)=value;
 *   }
 *   caller-only TU suggest-split MATCH256: two witnesses, both inside this
 *   sole function; zero viable pieces. Do not file overlay leaves while capped.
 * note 2026-10-04 (wD2 lane18): still MATCH, only unresolved relocations remain: callee GFL_NET_IRC_WIRELESS_SetSessionParam (veneer to 0x0203DA68) still has no witness; GFL_NET_IRC_WIRELESS_SetSessionParamValue filed EXACT as src/matched/arm9/GFL_NET_IRC_WIRELESS_SetSessionParamValue.c, integrator must regenerate labels so the veneer resolves.
 */
void IRCBATTLEMATCH_StepStartSession(IrcBattleMatchWork *work)
{
    NetSessionReq req;
    int zero;
    IrcBattleMatchParam *param;
    req=gIrcBattleMatchSessionReq;
    req.connectMode=4;
    switch(work->mode) {
    case 1:case 2:case 3:case 4:
        req.sessionKind=12;
        break;
    case 5:
        req.sessionKind=38;
        req.ruleA=4;
        break;
    case 7:
        req.sessionKind=29;
        break;
    case 6:
        req.sessionKind=28;
        break;
    case 11:
        req.sessionKind=44;
        break;
    case 9:
        req.limit=17;
        req.sessionKind=19;
        req.enabled=1;
        param=work->param;
        req.ruleA=param->settings[0x60];
        req.ruleB=param->settings[0x61];
        req.ruleValue=*(u16 *)(param->settings+0x6c);
        work->retryCount=-1;
        break;
    case 10:
        req.limit=17;
        req.sessionKind=18;
        req.enabled=1;
        param=work->param;
        req.ruleA=param->settings[0x60];
        req.ruleB=param->settings[0x61];
        req.ruleValue=*(u16 *)(param->settings+0x6c);
        work->retryCount=-1;
        break;
    }
    zero=0;
    GFL_NET_StartSession(&req,0,work);
    switch(work->mode) {
    case 10:
        GFL_NET_IRC_WIRELESS_SetSessionParam(IRCBATTLEMATCH_IsCompatibleGameKind);
        GFL_NET_IRC_WIRELESS_SetRetryRequest(1);
        GFL_NET_SetGameKindOverride(17);
        break;
    case 9:
        GFL_NET_IRC_WIRELESS_SetSessionParam(IRCBATTLEMATCH_IsCompatibleGameKind);
        GFL_NET_IRC_WIRELESS_SetRetryRequest(zero);
        GFL_NET_SetGameKindOverride(17);
        break;
    case 5:
        GFL_NET_SetGameKindOverride(37);
        break;
    }
    IRCBATTLEMATCH_OpenWaitMenu(work,0);
    IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepStartChangeover);
}

void IRCBATTLEMATCH_ExitScreen(IrcBattleMatchWork *work) {
 GF_FONT_SetDefaultTextColor();
 IRCBATTLEMATCH_FreeMessageWindows(work);
 BG_SYS_SetTileUnit(5,1,0);
 {
  unsigned int windowPalette=work->windowPalette;
  unsigned int paletteHigh=windowPalette>>16;
  BG_SYS_DeleteHalf(5,(unsigned short)windowPalette,(unsigned short)paletteHigh);
 }
 BG_SYS_FreeLayerBuf(5);
 MSGDATA_Delete((struct Rec *)work->msgData);
 GF_FONT_Delete(work->font);
 STRBUF_Delete(work->tempStr);
 STRBUF_Delete(work->msgStr);
 BG_SYS_SetPlaneVisible(5,0);
 APP_TASKMENU_RES_Delete(work->taskMenuRes);
 IRCBATTLEMATCH_ExitWindowSystem(work);
}

/*
 * evidence: 0x021799C0 is the ov015 Thumb callback setter, while ov009
 *   holds unrelated interior ARM instructions at the overlapping address.
 */
void IRCBATTLEMATCH_StepStartChangeover(IrcBattleMatchWork *work) {
 if(GFL_NET_GetRunState()==1) {
  switch(work->mode) { case 9: case 10: IRCNET_SetFilter(IRCBATTLEMATCH_IsCompatibleGameKind); break; }
  GFL_NET_StartChangeoverEx(IRCBATTLEMATCH_CollectMacAddresses,IRCBATTLEMATCH_OnChangeoverResult,IRCBATTLEMATCH_OnChangeoverConnected);
  IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitSession);
 }
}

void IRCBATTLEMATCH_StepRedrawWaitMenu(IrcBattleMatchWork *work) {
 MessageRef message;
 IRCBATTLEMATCH_FreeMessageWindows(work);
 message.msgId=work->lastMessageId;
 IRCBATTLEMATCH_PrintMainMessage(&message,work);
 if(work->mode==9 && work->retryCount>0) {
  IRCBATTLEMATCH_OpenWaitMenu(work,1);
  IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitSession);
  return;
 }
 IRCBATTLEMATCH_OpenWaitMenu(work,0);
 IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitSession);
}

void IRCBATTLEMATCH_StepWaitQuitChoiceDuringWait(IrcBattleMatchWork *work) {
 if(APP_TASKMENU_IsFinish(work->taskMenu)!=0) {
  int choice=APP_TASKMENU_GetCursorPos(work->taskMenu);
  APP_TASKMENU_CloseMenu(work->taskMenu);
  work->taskMenu=0;
  BG_SYS_SetFlagField06(6);
  if(choice==0) {
   IRCBATTLEMATCH_FreeMessageWindows(work); IRCBATTLEMATCH_AbortSession(work); IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StartExitWipe);
  } else IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepRedrawWaitMenu);
  IRCBATTLEMATCH_SetPaletteFade(work,0);
 }
}

void IRCBATTLEMATCH_StepWaitErrorDialogClose(IrcBattleMatchWork *work)
{
 if(APP_TASKMENU_IsFinish(work->taskMenu)!=0) {
  APP_TASKMENU_GetCursorPos(work->taskMenu);
  APP_TASKMENU_CloseMenu(work->taskMenu);
  work->taskMenu=0;
  BG_SYS_SetFlagField06(6);
  IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepOpenErrorConfirm);
 }
}

void IRCBATTLEMATCH_StepWaitWirelessStep(IrcBattleMatchWork *work) {
 if(GFL_NET_IRC_WIRELESS_Step()!=0) { IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitErrorDialogClose); return; }
 if(APP_TASKMENU_IsFinish(work->taskMenu)!=0) {
  APP_TASKMENU_GetCursorPos(work->taskMenu);
  APP_TASKMENU_CloseMenu(work->taskMenu);
  work->taskMenu=0;
  BG_SYS_SetFlagField06(6);
  IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepOpenErrorConfirm);
 }
}

void IRCBATTLEMATCH_StepOpenWirelessWaitMenu(IrcBattleMatchWork *work) { IRCBATTLEMATCH_OpenWaitMenu(work,0); IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitWirelessStep); }

void IRCBATTLEMATCH_StepRestoreWaitMenu(IrcBattleMatchWork *work) {
 MessageRef message;
 message.msgId=work->lastMessageId;
 IRCBATTLEMATCH_PrintMainMessage(&message,work);
 IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitSession);
 if(work->mode==9 && work->retryCount>0) { IRCBATTLEMATCH_OpenWaitMenu(work,1); return; }
 IRCBATTLEMATCH_OpenWaitMenu(work,0);
}

void IRCBATTLEMATCH_StepWaitCancelChoice(IrcBattleMatchWork *work) {
 if(APP_TASKMENU_IsFinish(work->taskMenu)!=0) {
  int choice=APP_TASKMENU_GetCursorPos(work->taskMenu);
  APP_TASKMENU_CloseMenu(work->taskMenu);
  work->taskMenu=0;
  if(choice==0) {
   IRCBATTLEMATCH_FreeMessageWindows(work); BG_SYS_SetFlagField06(6); IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepOpenWirelessWaitMenu); return;
  } else { IRCBATTLEMATCH_FreeMessageWindows(work); IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepRestoreWaitMenu); }
 }
}

/*
 * note: caller uses r0 after BLX; extern return retains that live value.
 */
void IRCBATTLEMATCH_StepWaitTouchThenCancel(IrcBattleMatchWork *work) {
    if(TOUCHPANEL_GetTrg()!=0) {
        IRCBATTLEMATCH_AbortSession(work);
        work->param->mode=13;
        IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StartExitWipe);
    }
}

void IRCBATTLEMATCH_StepOpenQuitConfirmDuringWait(IrcBattleMatchWork *work) {
 MessageRef message=gIrcBattleMatchMsgCancelConfirm;
 int savedMessageId=work->lastMessageId;
 ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,0x180,32,work->heapId);
 IRCBATTLEMATCH_PrintMainMessage(&message,work);
 work->lastMessageId=savedMessageId;
 IRCBATTLEMATCH_OpenQuitMenu(work);
 GF_FONT_SetDefaultTextColor();
 if(work->buttonMan!=0) BUTTON_MAN_Delete(work->buttonMan);
 work->buttonMan=0;
 IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitQuitChoiceDuringWait);
}

void IRCBATTLEMATCH_StepOpenCancelConfirm(IrcBattleMatchWork *work) {
 MessageRef message=gIrcBattleMatchMsgCancelConfirmAlt;
 int savedMessageId=work->lastMessageId;
 ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,0x180,32,work->heapId);
 IRCBATTLEMATCH_PrintMainMessage(&message,work);
 work->lastMessageId=savedMessageId;
 IRCBATTLEMATCH_OpenQuitMenu(work);
 GF_FONT_SetDefaultTextColor();
 IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitCancelChoice);
}

void IRCBATTLEMATCH_StepCountdownThenExit(IrcBattleMatchWork *work) {
    if(--work->timer==0) {
        IRCBATTLEMATCH_FreeMessageWindows(work);
        IRCBATTLEMATCH_AbortSession(work);
        IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StartExitWipe);
    }
}

void IRCBATTLEMATCH_StepShowErrorMessage(IrcBattleMatchWork *work) {
    MessageRef message;
    IRCBATTLEMATCH_FreeMessageWindows(work);
    message.msgId=12;
    IRCBATTLEMATCH_PrintMainMessage(&message,work);
    IRCBATTLEMATCH_OpenWaitMenu(work,0);
    IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitErrorDialogClose);
}

void IRCBATTLEMATCH_StepWaitErrorChoice(IrcBattleMatchWork *work) {
 if(APP_TASKMENU_IsFinish(work->taskMenu)!=0) {
  int choice=APP_TASKMENU_GetCursorPos(work->taskMenu);
  APP_TASKMENU_CloseMenu(work->taskMenu);
  work->taskMenu=0;
  BG_SYS_SetFlagField06(6);
  if(choice==0) {
   IRCBATTLEMATCH_FreeMessageWindows(work); IRCBATTLEMATCH_AbortSession(work); IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StartExitWipe);
  } else IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepShowErrorMessage);
  IRCBATTLEMATCH_SetPaletteFade(work,0);
 }
}

void IRCBATTLEMATCH_StepOpenErrorConfirm(IrcBattleMatchWork *work) {
 MessageRef message=gIrcBattleMatchMsgErrorConfirm;
 int savedMessageId=work->lastMessageId;
 ARC_UTIL_UploadPaletteFromArchiveWhole(23,5,4,0x180,32,work->heapId);
 IRCBATTLEMATCH_PrintMainMessage(&message,work);
 work->lastMessageId=savedMessageId;
 IRCBATTLEMATCH_OpenQuitMenu(work);
 GF_FONT_SetDefaultTextColor();
 if(work->buttonMan!=0) BUTTON_MAN_Delete(work->buttonMan);
 work->buttonMan=0;
 IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitErrorChoice);
}

void IRCBATTLEMATCH_IconAnimLeft(IrcBattleMatchWork *work) {
 switch(CLACT_GetActorAnimSeq(work->actors[0])) {
 case 8:
  CLACT_SetActorAnimSeq(work->actors[0],11);
  IRCBATTLEMATCH_MoveActor(work,200,38,0);
  IRCBATTLEMATCH_CreateActor(work,128,113,4,2);
  return;
 case 11: break;
 default: CLACT_SetActorAnimSeq(work->actors[0],8); break;
 }
}

void IRCBATTLEMATCH_IconAnimRight(IrcBattleMatchWork *work) {
 switch(CLACT_GetActorAnimSeq(work->actors[2])) {
 case 9:
  CLACT_SetActorAnimSeq(work->actors[2],10);
  IRCBATTLEMATCH_MoveActor(work,57,154,2);
  IRCBATTLEMATCH_CreateActor(work,128,77,5,3);
  return;
 case 10: break;
 default: CLACT_SetActorAnimSeq(work->actors[2],9); break;
 }
}

void IRCBATTLEMATCH_StepShowDisconnectMessage(IrcBattleMatchWork *work) {
    MessageRef message=gIrcBattleMatchMsgDisconnected;
    IRCBATTLEMATCH_FreeMessageWindows(work);
    IRCBATTLEMATCH_PrintMainMessage(&message,work);
    IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepWaitTouchThenCancel);
}

/*
 * evidence: BA00 tail forwards to D768; full D768 body reads state at0,
 *   words at4/8 for state0, and never the uninitialized padding at2 in that arm.
 * lever: b before a places their MessageRef locals at sp+4 and sp+0 respectively.
 */
void IRCBATTLEMATCH_StepAnimateIcons(IrcBattleMatchWork *work)
{
    MessageRef messageB,messageA;
    ActorTask task;
    IRCBATTLEMATCH_FreeMessageWindows(work);
    if(work->iconsDirty==1) {
        if(work->changeoverRole) {
            messageB=gIrcBattleMatchMsgIconsParent;
            IRCBATTLEMATCH_PrintMainMessage(&messageB,work);
        } else {
            messageA=gIrcBattleMatchMsgIconsChild;
            IRCBATTLEMATCH_PrintMainMessage(&messageA,work);
            IRCBATTLEMATCH_DeleteActor(work,0);
            IRCBATTLEMATCH_DeleteActor(work,2);
        }
        IRCBATTLEMATCH_DeleteActor(work,6);
        IRCBATTLEMATCH_DeleteActor(work,7);
        IRCBATTLEMATCH_DeleteActor(work,4);
        IRCBATTLEMATCH_DeleteActor(work,5);
        IRCBATTLEMATCH_DeleteActor(work,1);
        IRCBATTLEMATCH_DeleteActor(work,3);
        if(work->changeoverRole) {
            task.state=0;
            task.context=work;
            task.callback=IRCBATTLEMATCH_IconAnimLeft;
            CLACT_ApplyActorAnimCommand((struct Actor *)work->actors[0],&task);
            task.callback=IRCBATTLEMATCH_IconAnimRight;
            CLACT_ApplyActorAnimCommand((struct Actor *)work->actors[2],&task);
        }
        work->iconsDirty=0;
    }
    work->iconAnimTimer++;
    if(work->iconAnimTimer>8 && work->paletteFlash) {
        work->iconsAnimating=0;
        BG_SYS_SetPlaneVisible(1,0);
    }
}

void IRCBATTLEMATCH_StepWaitSession(IrcBattleMatchWork *work)
{
    int choice;
    if(work->iconsAnimating && work->mode==5) {
        IRCBATTLEMATCH_StepAnimateIcons(work);
    } else if(work->iconsVisible==1 && work->mode!=9) {
        if(work->showTrigger==1) {
            IRCBATTLEMATCH_FreeMessageWindows(work);
            IRCBATTLEMATCH_PrintMainMessage(&gIrcBattleMatchModeMessages[work->mode],work);
            IRCBATTLEMATCH_DeleteActor(work,4);
            IRCBATTLEMATCH_DeleteActor(work,5);
            work->showTrigger=0;
            if(work->actors[0]) {
                CLACT_SetActorAutoAnim(work->actors[0],0);
                CLACT_SetActorAutoAnim(work->actors[2],0);
            }
        }
        IRCBATTLEMATCH_NudgeActor(work,0,-2,0);
        IRCBATTLEMATCH_NudgeActor(work,0,2,2);
        work->iconsTimer++;
        if(work->iconsTimer>30) {
            if(work->actors[0]) {
                CLACT_SetActorDrawEnable(work->actors[0],0);
                CLACT_SetActorDrawEnable(work->actors[2],0);
            }
            work->iconsVisible=0;
        }
    }
    if(GFL_NET_GetRunState() && GFL_NET_HANDLE_GetNegotiationState(GFL_NET_HANDLE_GetCurrentHandle())==7) {
        IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepShowDisconnectMessage);
        return;
    }
    if(APP_TASKMENU_IsFinish(work->taskMenu)) {
        choice=APP_TASKMENU_GetCursorPos(work->taskMenu);
        APP_TASKMENU_CloseMenu(work->taskMenu);
        work->taskMenu=0;
        BG_SYS_SetFlagField06(6);
        if(work->menuKind) {
            IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepOpenQuitConfirmDuringWait);return;
        }
        if(choice==0) {
            IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepOpenCancelConfirm);return;
        } else {
            IRCBATTLEMATCH_SetStep(work,IRCBATTLEMATCH_StepOpenQuitConfirmDuringWait);return;
        }
    }
    if(work->mode==9) {
        if(work->retryCount!=GFL_NET_IRC_WIRELESS_GetRetryCount()) {
            IRCBATTLEMATCH_PrintRetryMessage(0x27,work);
            work->retryCount=GFL_NET_IRC_WIRELESS_GetRetryCount();
        }
        if(work->retryCount>0 && work->menuKind==1) {
            APP_TASKMENU_CloseMenu(work->taskMenu);
            work->taskMenu=0;
            IRCBATTLEMATCH_OpenWaitMenu(work,1);
        }
    }
}


int IRCBATTLEMATCH_ProcInit(struct Proc *proc, int seq, IrcBattleMatchParam *param)
{
    IrcBattleMatchWork *work;
    int workSize;

    GFL_HEAP_CreateChildHeap(1, 0x1f, 0x20000);
    workSize = 0xcf0;
    work = PROCSYS_AllocProcWork(proc, workSize, 0x1f);
    MI_CpuFill8((int)work, 0, workSize);
    work->param = param;
    work->heapId = 0x1f;
    work->mode = work->param->mode;
    work->paletteBackup =
        GFL_HEAP_Alloc(work->heapId, 0x200, 0, gIrcBattleMatchFileName, 0xb07);
    IRCBATTLEMATCH_InitScreen(work);
    GFL_NET_IRC_WIRELESS_Exit();
    G2x_SetBlendAlpha_(REG_BLDCNT_ADDR, 0x10, 3, 9, 0xe);
    return 1;
}

u32 IRCBATTLEMATCH_ProcMain(u32 a, u32 b, u32 c, IrcBattleMatchWork *work)
{
    IrcBattleMatchStep step = work->step;
    u32 ret = 1;
    u32 flag;
    if ((*(volatile u32 *)VBLANK_COUNT_ADDR & 7) == 1) {
        GX_LoadBGPltt(work->palette[work->paletteRow], 0, 0x20);
        work->paletteRow = work->paletteRow + 1;
        if (work->paletteRow == 9) {
            flag = ret;
            goto storeFlag;
        }
        if (work->paletteRow >= 0x12) work->paletteRow = 0;
    }
    flag = 0;
storeFlag:
    work->paletteFlash = flag;
    if (step) {
        step(work);
        if (work->step) ret = 0;
    }
    if (work->taskMenu) APP_TASKMENU_UpdateMenu(work->taskMenu);
    if (work->okWin) APP_TASKMENU_WIN_Update(work->okWin);
    if (work->cancelWin) APP_TASKMENU_WIN_Update(work->cancelWin);
    BG_SYS_FillScrollArea(4, 3, work->scrollY);
    work->scrollY = work->scrollY - 1;
    CLACT_DrawSystem();
    PRINTSYS_QUE_Main(work->printQue);
    if (GFL_NET_ERR_GetErrorLevel()) {
        GFL_NET_ERR_RequestScreen();
        work->param->mode = 12;
        ret = 1;
        WIPE_SetBrightnessFadeOut(0, 0);
        WIPE_SetBrightnessFadeOut(1, 0);
    }
    return ret;
}

int IRCBATTLEMATCH_ProcExit(struct Proc *proc, int b, int c, IrcBattleMatchWork *work)
{
    if(!WIPE_SYS_EndCheck()) return 0;
    if(GFL_NET_GetRunState()) GFL_NET_COMMAND_DeleteCommandTable(0xc00);
    if(work->taskMenu) APP_TASKMENU_CloseMenu(work->taskMenu);
    if(work->okWin) APP_TASKMENU_WIN_Delete(work->okWin);
    if(work->cancelWin) APP_TASKMENU_WIN_Delete(work->cancelWin);
    if(work->buttonMan) BUTTON_MAN_Delete(work->buttonMan);
    GFL_HEAP_Free(work->paletteBackup);
    work->buttonMan=0;
    WORDSET_DeleteStrbufED04(work->wordSet);
    IRCBATTLEMATCH_ExitScreen(work);
    TCB_DeleteTask(work->vblankTask);
    CLACT_DeleteUnit(work->clactUnit);
    CLACT_ExitSystem();
    PRINTSYS_QUE_Clear(work->printQue);
    PRINTSYS_QUE_Delete(work->printQue);
    if(work->extraTask) {
        TCB_DeleteTask(work->extraTask);
        work->extraTask=0;
        work->extraTaskArg=0;
    }
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(31);
    return 1;
}
