/*
 * file:     namein_setup.c
 * unit:     yes
 * function: NAMEIN_SETUP_CreateArgs, NAMEIN_SETUP_CreateMonArgs, NAMEIN_SETUP_CreateCaptureArgs, NAMEIN_SETUP_FreeArgs, NAMEIN_SETUP_CopyName, NAMEIN_SETUP_IsCanceled, NAMEIN_SETUP_RunFallEvent, NAMEIN_SETUP_StartFallEvent, NAMEIN_SETUP_StepLandAnim, NAMEIN_SETUP_SyncObjHeightToAnim, NAMEIN_SETUP_SnapObjToGrid, NAMEIN_SETUP_RunLandEvent, NAMEIN_SETUP_StartLandEvent, NAMEIN_SETUP_RunPartyPickEvent, NAMEIN_SETUP_StartPartyPickEvent, NAMEIN_SETUP_StartEncounterScene, NAMEIN_SETUP_RunNameBalloonEvent, NAMEIN_SETUP_StartNameBalloonFromRecord, NAMEIN_SETUP_RunHistoryScreenEvent, NAMEIN_SETUP_StartHistoryScreenEvent, NAMEIN_SETUP_InitHostProc, NAMEIN_SETUP_ExitHostProc, NAMEIN_SETUP_MainHostProc, NAMEIN_SETUP_RunProcCallEvent, NAMEIN_SETUP_StartProcCallEvent, NAMEIN_SETUP_RunSceneEvent, NAMEIN_SETUP_StartSceneEvent, NAMEIN_SETUP_StartEncounterTransition, NAMEIN_SETUP_RunNameBalloonWaitEvent, NAMEIN_SETUP_StartNameBalloonFromHistory, NAMEIN_SETUP_ScrCmdSetFieldSaveFlag, NAMEIN_SETUP_SetFieldSaveFlag
 * address:  0x0216BFD4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fldmmdl.c at 0x0216BFD4 and 0x0216CC58 (__FILE__ anchors: namein_setup.c up to 0x0216CC40, fldmmdl.c from 0x0216CC58).
 *
 * symbols:
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02030734  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Copy  0x02045838  arm
 *   d_02172A60     0x02172A60  data  ov010  a1
 *   func_02017E1C  0x02017E1C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_020307B0  0x020307B0  arm
 *   FIELD_CAMERA_ANIME_Setup  0x0218FEA4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam  0x0218FE78  thumb  ov021
 *   FIELD_CAMERA_ANIME_Start  0x0218FF00  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb
 *   FIELD_CAMERA_ANIME_Delete  0x0218FE98  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   ICA_ANIME_CreateFull  0x020114D0  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   func_02011610  0x02011610  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb
 *   EVENT_MAPCHANGE_CreateWarpEventDefaultTransition  0x021854B0  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_CAMERA_ANIME_Create  0x0218FE80  thumb  ov021
 *   FIELD_CAMERA_ANIME_SetData  0x0218FEA0  thumb  ov021
 *   d_02172528     0x02172528  data  ov010  a4
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   GIMMICK50_InitModelsB  0x021F3714  thumb  ov050
 *   GIMMICK50_ShowModel1  0x021F37B8  thumb  ov050
 *   GIMMICK50_IsModel0AnimeDone  0x021F3758  thumb  ov050
 *   GIMMICK50_IsModel1AnimeDone  0x021F3808  thumb  ov050
 *   GIMMICK50_StopModel0Anime  0x021F3744  thumb  ov050
 *   GIMMICK50_HideModel1  0x021F3788  thumb  ov050
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   FIELD_CAMERA_CreateShakeTask  0x021D2D50  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012934  0x02012934  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   POKE_REGULATION_Load  0x0201A354  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   BATTLE_REC_AllocWork  0x0200B400  thumb
 *   func_021CBD08  0x021CBD08  thumb  ov021
 *   EVENT_BATTLE_CreateResultOnlyTask  0x0216E8CC  thumb  ov010
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb  ov021
 *   FIELD_MSGBG_TalkWinDrawCursor  0x021914CC  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb  ov021
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   MSGDATA_CreateFromArchive   0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   SCRCMD_MSGWIN_GetBalloonOffset  0x021B09D8  thumb
 *   SCRCMD_MSGWIN_GetBalloonTailParams  0x021B09EC  thumb
 *   FIELD_MSGBG_AddTalkWin  0x0219129C  thumb  ov021
 *   GAME_DATA_GetSaveBlock3B  0x02012EFC  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryTagA  0x0200DF40  thumb
 *   BSUBWAY_SAVEDATA_GetHistoryTagB  0x0200DF4C  thumb
 *   FIELD_STATUS_CreateSubProcEvent  0x020146F8  thumb
 *   id_00000045    0x00000045  data  a1
 *   d_021BA650     0x021BA650  data  a4 ov069
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   PROCSYS_Create  0x02031324  arm
 *   func_0203133C 0x0203133C arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   PROCSYS_Main  0x02031330  arm
 *   func_02034AC4  0x02034AC4  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_StartTimingSync  0x0203D594  arm
 *   func_0200FB24  0x0200FB24  thumb
 *   GFL_NET_CheckTimingSync  0x0203D5A0  arm
 *   PROCSYS_Push  0x02031348  arm
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   id_0000005D    0x0000005D  data  a1
 *   d_021F03C4     0x021F03C4  data  a4 ov093
 *   d_021EFDAC     0x021EFDAC  data  a4 ov026
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   d_02172548     0x02172548  data  ov010  a4
 *   EVENT_FIELD_PROCLINK_CreateAnimEvent  0x02161824  thumb  ov010
 *   FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask  0x02029BCC  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_ConsumeSpot  0x021AAABC  thumb  ov021
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask  0x02029C00  thumb
 *   FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask  0x02029CC0  thumb
 *   func_021CBD84   0x021CBD84  thumb  ov021
 *   GAME_EVENT_Create   0x020122C0  thumb
 *   GAME_EVENT_GetWork   0x020124E8  thumb
 *   SCRCMD_MSGWIN_GetBalloonSide  0x021B0A40  thumb  ov021
 *   func_020071CC  0x020071CC  thumb
 *   BSUBWAY_SAVEDATA_AllocHistoryCopy  0x0200DF58  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   func_0200B3A4 0x0200B3A4 thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 */
struct IcaAnime;
typedef unsigned char u8;

typedef struct Strbuf Strbuf;
typedef unsigned short u16;
typedef unsigned int u32;
/*
 * Argument block of the name input screen (0x2c bytes). Kind 0 asks for a
 * player name; kind 1 asks for a monster nickname, either from a species and
 * traits pair or from the monster itself (NAMEIN_SETUP_CreateMonArgs).
 */
typedef struct NameInArgs {
    int kind;           /* 0x00 */
    u16 species;        /* 0x04 */
    u16 traits;         /* 0x06: gender in the high byte, form in the low byte */
    void *mon;          /* 0x08 */
    Strbuf *boxName;    /* 0x0C */
    void *boxManager;   /* 0x10 */
    int boxIndex;       /* 0x14 */
    int maxLen;         /* 0x18 */
    int canceled;       /* 0x1C */
    Strbuf *name;       /* 0x20 */
    u32 reserved24;     /* 0x24 */
    void *pokedex;      /* 0x28 */
} NameInArgs;

typedef int s32;
typedef s32 fx32;
typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;
typedef struct GameSystem GameSystem;
typedef struct GameEvent GameEvent;
typedef struct FieldMap FieldMap;
typedef struct Pos {
    u32 x;
    u32 y;
    u32 z;
} Pos;
/* Eight words of camera target data, copied from the table at d_02172528. */
typedef struct CameraTarget {
    int words[8];
} CameraTarget;
/* Camera move request the fall event hands to the ov021 camera helper (0x4C bytes). */
typedef struct CameraMoveParam {
    int frames;         /* 0x00: 0x14 */
    int startArgs[8];   /* 0x04 */
    CameraTarget target;/* 0x24 */
    int easeIn;         /* 0x44 */
    int easeOut;        /* 0x48 */
} CameraMoveParam;
/* Work of the fall event (0x64 bytes): camera move, landing animation, hand-off to the land event. */
typedef struct FallEventWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    void *camera;               /* 0x08 */
    void *cameraStatus;         /* 0x0C */
    struct IcaAnime *anim;      /* 0x10 */
    CameraMoveParam cameraMove; /* 0x14 */
    void *playerObj;            /* 0x60 */
} FallEventWork;
/* Screen change request for the land event's result screen (0x18 bytes). */
typedef struct ScreenChangeParam {
    u16 mode;           /* 0x00 */
    u16 variant;        /* 0x02 */
    u16 startDelay;     /* 0x04 */
    u16 step;           /* 0x06 */
    u16 colorLow;       /* 0x08 */
    u16 colorHigh;      /* 0x0A */
    u16 screenMask;     /* 0x0C */
    u8 fadeOutKind;     /* 0x0E */
    u8 fadeInKind;      /* 0x0F */
    u32 effectKind;     /* 0x10 */
    u32 reserved14;     /* 0x14 */
} ScreenChangeParam;
/* Work of the land event (0x14 bytes). */
typedef struct LandEventWork {
    u16 heapId;                 /* 0x00 */
    GameSystem *gameSystem;     /* 0x04 */
    FieldMap *fieldMap;         /* 0x08 */
    void *camera;               /* 0x0C */
    struct IcaAnime *anim;      /* 0x10 */
} LandEventWork;
typedef struct GameData GameData;
typedef struct Mmdl Mmdl;
typedef struct MsgBank MsgBank;
/* Transition request record behind EncounterContext.transitionInfo; only the scene id is read here. */
typedef struct TransitionInfo {
    u8 reserved00[0x18];
    u16 sceneId;        /* 0x18 */
} TransitionInfo;
/* Summary screen argument block, embedded in PartyTaskWork (0x28 bytes). */
typedef struct SummaryArgs {
    void *party;        /* 0x00 */
    u32 reserved04;
    GameData *gameData; /* 0x08 */
    u8 mode;            /* 0x0C: 1 */
    u8 startSlot;       /* 0x0D */
    u8 partyCount;      /* 0x0E */
    u8 reserved0F;
    u8 startPage;       /* 0x10 */
    u8 reserved11[7];
    void *statusData;   /* 0x18 */
    u8 reserved1C[0xC];
} SummaryArgs;
/* Party screen argument block, embedded in PartyTaskWork (0x98 bytes). */
typedef struct PartyScreenArgs {
    void *party;        /* 0x00 */
    u8 reserved04[0x10];
    void *regulation;   /* 0x14: loaded for the screen, freed when it closes */
    u8 reserved18[0x1C];
    u32 screenType;     /* 0x34: 0x16 */
    u32 selectMode;     /* 0x38 */
    u32 pickedSlot;     /* 0x3C */
    u32 pickedSub;      /* 0x40 */
    u8 reserved44[5];
    u8 pickedSlots[6];  /* 0x49 */
    u8 reserved4F[0x49];
} PartyScreenArgs;
/* Work of the party pick task (0xD8 bytes). */
typedef struct PartyTaskWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    SummaryArgs summary;        /* 0x08 */
    PartyScreenArgs partyScreen;/* 0x30 */
    u16 *pickedSubOut;          /* 0xC8 */
    u16 *pickedSlotOut;         /* 0xCC */
    u8 *pickedSlotsOut;         /* 0xD0 */
    u8 reservedD4[4];
} PartyTaskWork;
/* Encounter context of the field caller (at least 0x7D0 bytes): what asked for the pick and where its results go. */
typedef struct EncounterContext {
    u8 reserved00[9];
    u8 kind;                    /* 0x009 */
    u8 reserved0A[0x72];
    u8 pickedSlots[6];          /* 0x07C */
    u16 pickResult;             /* 0x082 */
    u16 pickResultSub;          /* 0x084 */
    u8 reserved86[0x7C8 - 0x86];
    void *party;                /* 0x7C8 */
    int transitionInfo;         /* 0x7CC */
} EncounterContext;
/* Work of the name balloon tasks: C6E8 allocates 0xD8 bytes, CB48 only 0x1C. */
typedef struct NameBalloonWork {
    GameSystem *gameSystem;     /* 0x00 */
    u32 reserved04;
    VecFx32 pos;                /* 0x08 */
    void *balloon;              /* 0x14 */
    Strbuf *name;               /* 0x18 */
    u16 npcId;                  /* 0x1C */
} NameBalloonWork;
/* One 0x22-byte entry of the history table; the name balloon shows its name. */
typedef struct HistoryEntry {
    u8 reserved00[0x18];
    u16 nameChars[5];           /* 0x18 */
} HistoryEntry;
/* One 0x120-byte record of the table the name balloon reads its text from. */
typedef struct NameBalloonRecord {
    u8 reserved00[0xA0];
    u16 nameChars[2];           /* 0xA0: 0xFFFF then a message index, or the first characters of a name */
    u8 reservedA4[0x120 - 0xA4];
} NameBalloonRecord;
/* Work of the history screen task (0x14 bytes). */
typedef struct HistoryScreenWork {
    FieldMap *fieldMap;         /* 0x00 */
    GameSystem *gameSystem;     /* 0x04 */
    GameData *gameData;         /* 0x08 */
    int historyTagA;            /* 0x0C */
    int historyTagB;            /* 0x10 */
} HistoryScreenWork;
/* Parameter block of the sub proc call (the last three words of ProcCallWork). */
typedef struct ProcCallParam {
    GameData *gameData;         /* 0x00 */
    TransitionInfo *transitionInfo; /* 0x04 */
    void *extra;                /* 0x08 */
} ProcCallParam;
/* Work of the proc call task (0x3C bytes). */
typedef struct ProcCallWork {
    GameSystem *gameSystem;     /* 0x00 */
    TransitionInfo *transitionInfo; /* 0x04 */
    void *extra;                /* 0x08 */
    ProcCallParam param;        /* 0x0C */
    u8 reserved18[0x24];
} ProcCallWork;
/* Work of the scene event task (0x10 bytes). */
typedef struct SceneEventWork {
    GameSystem *gameSystem;     /* 0x00 */
    FieldMap *fieldMap;         /* 0x04 */
    TransitionInfo *transitionInfo; /* 0x08 */
    void *extra;                /* 0x0C */
} SceneEventWork;
extern void *GAME_DATA_GetSaveControl(GameData *gameData);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Copy(Strbuf *dst, Strbuf *src);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void STRBUF_Delete(Strbuf *s);
extern void func_020307B0(void *);
extern void FIELD_CAMERA_ANIME_Setup(void *playerObj);
extern void FIELD_CAMERA_ANIME_GetCurrentParam(void *camera, int *startArgs);
extern int FIELD_CAMERA_ANIME_Start(u32 a);
extern int FIELD_TASK_MANAGER_IsEmpty(void *cameraStatus);
extern void FIELD_CAMERA_ANIME_Delete(void *playerObj);
extern u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern void *ICA_ANIME_CreateFull(u32 heap, u32 a1, u32 a2);
extern int GFL_USE_GetSeSlot(u32 a0);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);
extern u32 func_02011610(struct IcaAnime *anim, VecFx32 *out);
extern void *FIELDMAP_GetExpObj(FieldMap *fieldMap);
extern VecFx32 *FLD_EXP_OBJ_GetModelStatus(void *p, int a, int b);
extern void *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern void FIELD_PLAYER_GetPos(void *playerObj, VecFx32 *out);
extern void FIELD_PLAYER_SetPos(void *playerObj, void *pos);
extern u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *p, s32 v);
extern void ICA_ANIME_Delete(struct IcaAnime *p);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeOut(GameSystem *, FieldMap *, u32, u32);
extern void *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(GameSystem *gameSystem, FieldMap *fieldMap, u32 id, Pos *pos, u32 flag);
extern void GAME_EVENT_CallEvent(GameEvent *event, GameEvent *next);
extern void GAME_EVENT_ChangeEvent(GameEvent *event, GameEvent *next);
extern GameEvent *func_020122C0(GameSystem *gameSystem, GameEvent *parent, void *func, u32 size);
extern void *func_020124E8(GameEvent *event);
extern void *FIELDMAP_GetCamera(FieldMap *fieldMap);
extern void *FIELDMAP_GetTaskManager(FieldMap *fieldMap);
extern void *FIELD_CAMERA_ANIME_Create(FieldMap *fieldMap);
extern void FIELD_CAMERA_ANIME_SetData(void *playerObj, CameraMoveParam *param);
extern void FLDMMDL_MOVE_GetMapHeight(void *mapObj, VecFx32 *pos, fx32 *groundY);
extern void FIELD_CAMERA_EndDelay(void *camera);
extern u32 FIELD_CAMERA_IsDelayEnabled(void *camera);
extern void GIMMICK50_InitModelsB(FieldMap *fieldMap);
extern void GIMMICK50_ShowModel1(FieldMap *fieldMap);
extern int GIMMICK50_IsModel0AnimeDone(FieldMap *fieldMap);
extern int GIMMICK50_IsModel1AnimeDone(FieldMap *fieldMap);
extern void GIMMICK50_StopModel0Anime(FieldMap *fieldMap);
extern void GIMMICK50_HideModel1(FieldMap *fieldMap);
extern void *EVENT_FIELDMAP_CONTROL_StartFadeIn(GameSystem *, FieldMap *, u32, u32, u32, u32, u32);
extern void *FIELD_CAMERA_CreateShakeTask(GameSystem *gameSystem, ScreenChangeParam *param);
extern void *FIELD_PLAYER_GetMmdl(void *playerObj);
extern void GFL_USE_StopSeSlot(int i);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern GameEvent *FIELD_STATUS_CreateFieldCloseEvent(GameSystem *gameSystem, FieldMap *fieldMap);
extern GameEvent *func_02014910(GameSystem *gameSystem, FieldMap *fieldMap, PartyScreenArgs *partyScreen, SummaryArgs *summary);
extern GameEvent *FIELD_STATUS_CreateFieldOpenEvent(GameSystem *gameSystem);
extern void func_02082D44(const void *src, void *dst, int size);
extern GameData *func_020120F4(GameSystem *gameSystem);
extern FieldMap *func_0201210C(GameSystem *gameSystem);
extern void *func_02012934(GameData *gameData);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void *POKE_REGULATION_Load(int a, int b);
extern void *func_0200CA1C(GameData *gameData);
extern u32 POKEPARTY_GetCount(void *party);
extern u32 func_0200CA38(void *p);
extern void BATTLE_REC_AllocWork(u32 heap);
extern u32 func_021CBD08(EncounterContext *ctx, GameSystem *gameSystem);
extern int EVENT_BATTLE_CreateResultOnlyTask(GameSystem *, FieldMap *, int);
extern int FIELD_MSGBG_TalkWinMain();
extern void FIELD_MSGBG_TalkWinDrawCursor(void *balloon);
extern u32 KEY_GetTrg(void);
extern int FIELD_MSGBG_DeleteTalkWin(void *balloon);
extern int FIELD_MSGBG_WaitTalkWinClose();
extern void *FIELDMAP_GetMsgBg(FieldMap *fieldMap);
extern MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(MsgBank *bank, u32 index, Strbuf *dest);
extern u32 MSGDATA_Delete(MsgBank *bank);
extern Strbuf *PMSI_PARAM_ToString(const u16 *chars, unsigned int heap);
extern void *func_02012964(GameData *gameData);
extern u32 FIELD_CAMERA_GetG3dCamera(void *camera);
extern void SCRCMD_MSGWIN_GetBalloonOffset(VecFx32 *pos, VecFx32 *offset, u32 mapKind, void *camera, void *dir);
extern void SCRCMD_MSGWIN_GetBalloonTailParams(int dir, int *kind, int *flags);
extern void *FIELD_MSGBG_AddTalkWin(void *manager, int kind, VecFx32 *pos, Strbuf *name, u32 c, u32 flags);
extern void *GAME_DATA_GetSaveBlock3B(GameData *gameData);
extern int BSUBWAY_SAVEDATA_GetHistoryTagA(void *history);
extern u8 BSUBWAY_SAVEDATA_GetHistoryTagB(void *history);
extern GameEvent *FIELD_STATUS_CreateSubProcEvent(GameSystem *gameSystem, FieldMap *fieldMap, int procId, void *procData, void *param);
extern void GFL_HEAP_CreateChildHeap(unsigned int src, unsigned int dst, unsigned int size);
extern void **PROCSYS_AllocProcWork(void *proc, int size, int heapId);
extern void *PROCSYS_Create(int heapId);
extern void func_0203133C(void *w);
extern void func_020315D4(void *proc);
extern void func_020306F0(unsigned int);
extern unsigned int PROCSYS_Main(void *p);
extern int func_02034AC4(s32 handle);
extern void GFL_NET_COMMAND_AddCommandTable(u32 a, u32 b, u32 c, u32 d);
extern void *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_StartTimingSync(int, int);
extern u32 func_0200FB24(void);
extern int GFL_NET_CheckTimingSync(int, int);
extern void PROCSYS_Push(int, int, char *, int);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 key);
extern void func_02034A5C(s32 handle);
extern void GAMESYSTEM_CallProc(GameSystem *gameSystem, u32 id, const void *procData, void *param);
extern u32 GAMESYSTEM_GetProcStatus(GameSystem *gameSystem);
extern GameEvent *EVENT_FIELD_PROCLINK_CreateAnimEvent(GameSystem *gameSystem, FieldMap *fieldMap);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(GameSystem *gameSystem, u32 b);
extern u32 FIELDMAP_GetEncount(FieldMap *fieldMap);
extern void EFFECT_ENCOUNT_ConsumeSpot(int);
extern void *FIELDMAP_GetEncEff(FieldMap *fieldMap);
extern void ENCEFF_Start(void *p, GameEvent *event, int mode);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(GameSystem *gameSystem);
extern GameEvent *FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(GameSystem *gameSystem);
extern void *func_021CBD84(EncounterContext *ctx);
extern int SCRCMD_MSGWIN_GetBalloonSide(void *m2, VecFx32 *pos);
extern void *func_020071CC(void *saveControl, u32 id);
extern void *BSUBWAY_SAVEDATA_AllocHistoryCopy(void *bsubwaySave, u32 heap);
extern GameSystem *SCRCMD_WORK_GetGameSystem(void *scriptWork);
extern void *GAME_DATA_GetFieldSave(GameData *gameData);
extern s32 *func_0200B3A4(void *fieldSave, u32 b);
extern void FLDMMDL_GetPos(const Mmdl *mmdl, VecFx32 *out);
extern Mmdl *FLDMMDL_SysSearchObjId(void *occupyInfo, u32 id);
extern void *FLDMMDL_SysSearchPlayer(void *occupyInfo);
NameInArgs *NAMEIN_SETUP_CreateArgs(unsigned short heapId, int kind, short species, short traits, int maxLen, Strbuf *initialName, void *pokedex);
NameInArgs *NAMEIN_SETUP_CreateMonArgs(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, void *pokedex);
NameInArgs *NAMEIN_SETUP_CreateCaptureArgs(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, Strbuf *boxName, void *boxManager, int boxIndex, void *pokedex);
void NAMEIN_SETUP_FreeArgs(NameInArgs *args);
void NAMEIN_SETUP_CopyName(NameInArgs *args, Strbuf *dest);
int NAMEIN_SETUP_IsCanceled(NameInArgs *args);
int NAMEIN_SETUP_RunFallEvent(GameEvent *event, u32 *state, FallEventWork *work);
GameEvent *NAMEIN_SETUP_StartFallEvent(GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_StepLandAnim(LandEventWork *work);
void *NAMEIN_SETUP_SyncObjHeightToAnim(LandEventWork *work);
void NAMEIN_SETUP_SnapObjToGrid(LandEventWork *work);
int NAMEIN_SETUP_RunLandEvent(GameEvent *event, u32 *state, LandEventWork *work);
GameEvent *NAMEIN_SETUP_StartLandEvent(GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_RunPartyPickEvent(GameEvent *event, int *state, PartyTaskWork *work);
GameEvent *NAMEIN_SETUP_StartPartyPickEvent(EncounterContext *ctx, GameSystem *gameSystem, u8 useOwnParty);
void NAMEIN_SETUP_StartEncounterScene(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_RunNameBalloonEvent(GameEvent *event, int *state, NameBalloonWork *work, u32 extra);
GameEvent *NAMEIN_SETUP_StartNameBalloonFromRecord(NameBalloonRecord *records, GameSystem *gameSystem, u32 recordIndex, u16 npcId, u8 dir);
int NAMEIN_SETUP_RunHistoryScreenEvent(GameEvent *event, int *state, HistoryScreenWork *work);
GameEvent *NAMEIN_SETUP_StartHistoryScreenEvent(GameSystem *gameSystem);
int NAMEIN_SETUP_InitHostProc(void *proc, int *seq, void *pwk, void *mywk);
int NAMEIN_SETUP_ExitHostProc(void *proc, int *seq, void *pwk, void **mywk);
int NAMEIN_SETUP_MainHostProc(void *proc, int *seq, int *pwk, int *mywk);
int NAMEIN_SETUP_RunProcCallEvent(GameEvent *event, int *state, ProcCallWork *work);
GameEvent *NAMEIN_SETUP_StartProcCallEvent(GameSystem *gameSystem, TransitionInfo *transitionInfo, void *extra);
int NAMEIN_SETUP_RunSceneEvent(GameEvent *event, int *state, SceneEventWork *work);
GameEvent *NAMEIN_SETUP_StartSceneEvent(GameSystem *gameSystem, FieldMap *fieldMap, TransitionInfo *transitionInfo, void *extra);
void NAMEIN_SETUP_StartEncounterTransition(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_RunNameBalloonWaitEvent(GameEvent *event, int *state, NameBalloonWork *work);
GameEvent *NAMEIN_SETUP_StartNameBalloonFromHistory(GameSystem *gameSystem, int recordIndex, u8 npcId);
int NAMEIN_SETUP_ScrCmdSetFieldSaveFlag(void *scriptCtx, void *scriptWork);
void NAMEIN_SETUP_SetFieldSaveFlag(GameSystem *gameSystem);
extern char d_02172A60[];
extern CameraTarget d_02172528;
extern char d_021BA650[];
extern char id_00000045[];
extern char id_0000005D[];
extern char d_021F03C4[];
extern char d_021EFDAC[];
extern char d_02172548[];


/*
 * The heap id is a u16: as an int its entry spill (str r0,[sp,#4]) sinks
 * below the stack-argument setup. STRBUF_Copy takes the flag as its second
 * argument, which is why the image loads it into r1 ahead of the p[8] store.
 */
NameInArgs *NAMEIN_SETUP_CreateArgs(unsigned short heapId, int kind, short species, short traits, int maxLen, Strbuf *initialName, void *pokedex)
{
    NameInArgs *args = func_02030734(heapId, sizeof(NameInArgs), 0, d_02172A60, 0x37);
    MI_CpuFill8(args, 0, sizeof(NameInArgs));
    args->kind = kind;
    args->maxLen = maxLen;
    args->species = species;
    args->traits = traits;
    args->pokedex = pokedex;
    args->name = STRBUF_Create(0xb, heapId);
    if (initialName)
        STRBUF_Copy(args->name, initialName);
    return args;
}






/*
 * The heap id is a u16, as in NAMEIN_SETUP_CreateArgs; that keeps its entry spill
 * at the front of the prologue.
 */
NameInArgs *NAMEIN_SETUP_CreateMonArgs(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, void *pokedex)
{
    NameInArgs *args = func_02030734(heapId, sizeof(NameInArgs), 0, d_02172A60, 0x59);
    MI_CpuFill8(args, 0, sizeof(NameInArgs));
    args->kind = 1;
    args->maxLen = maxLen;
    args->mon = mon;
    args->pokedex = pokedex;
    if (mon) {
        int low;
        args->species = func_02017E1C(mon, 5, 0);
        low = func_02017E1C(mon, 0x6f, 0);
        args->traits = (func_02017E1C(mon, 0x6e, 0) << 8) | low;
    }
    args->name = STRBUF_Create(0xb, heapId);
    if (initialName)
        STRBUF_Copy(args->name, initialName);
    return args;
}





NameInArgs *NAMEIN_SETUP_CreateCaptureArgs(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, Strbuf *boxName, void *boxManager, int boxIndex, void *pokedex)
{
    NameInArgs *args = NAMEIN_SETUP_CreateMonArgs(heapId, mon, maxLen, initialName, pokedex);
    args->boxName = boxName;
    args->boxManager = boxManager;
    args->boxIndex = boxIndex;
    return args;
}






void NAMEIN_SETUP_FreeArgs(NameInArgs *args)
{
    STRBUF_Delete(args->name);
    func_020307B0(args);
}






void NAMEIN_SETUP_CopyName(NameInArgs *args, Strbuf *dest)
{
    STRBUF_Copy(dest, args->name);
}





int NAMEIN_SETUP_IsCanceled(NameInArgs *args)
{
    return args->canceled;
}






/*
 * Eight-state proc of the field event beside NAMEIN_SETUP_RunLandEvent: run the
 * ov021 camera move, animate the actor to the ground, then push the next
 * screens. First draft.
 */
int NAMEIN_SETUP_RunFallEvent(GameEvent *event, u32 *state, FallEventWork *work)
{
    VecFx32 cur;
    VecFx32 v;
    Pos pos;
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;
    void *cameraStatus = work->cameraStatus;
    void *playerObj;

    switch (*state) {
    case 0:
        FIELD_CAMERA_ANIME_Setup(work->playerObj);
        FIELD_CAMERA_ANIME_GetCurrentParam(work->camera, work->cameraMove.startArgs);
        FIELD_CAMERA_ANIME_Start((u32)work->playerObj);
        (*state)++;
        break;
    case 1:
        if (FIELD_TASK_MANAGER_IsEmpty(cameraStatus) != 0) {
            FIELD_CAMERA_ANIME_Delete(work->playerObj);
            (*state)++;
        }
        break;
    case 2:
        work->anim = ICA_ANIME_CreateFull(FIELDMAP_GetHeapId(fieldMap), 0x9D, 0x18);
        GFL_USE_PlaySeInSlot((void *)1953, GFL_USE_GetSeSlot(1953));
        (*state)++;
        break;
    case 3:
        func_02011610(work->anim, &cur);
        FLD_EXP_OBJ_GetModelStatus(FIELDMAP_GetExpObj(fieldMap), 0, 0)->y = cur.y;
        playerObj = FIELDMAP_GetFieldPlayer(fieldMap);
        FIELD_PLAYER_GetPos(playerObj, &v);
        v.y = cur.y;
        FIELD_PLAYER_SetPos(playerObj, &v);
        if (ICA_ANIME_IncFrameLoop(work->anim, 0x1000) != 0) {
            ICA_ANIME_Delete(work->anim);
            (*state)++;
        }
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        (*state)++;
        break;
    case 5:
        pos.x = 0;
        pos.y = 0;
        pos.z = 0;
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(gameSystem, fieldMap, 0x8A, &pos, 1));
        (*state)++;
        break;
    case 6:
        GAME_EVENT_ChangeEvent(event, NAMEIN_SETUP_StartLandEvent(gameSystem, fieldMap));
        (*state)++;
        break;
    case 7:
        return 1;
    }
    return 0;
}






GameEvent *NAMEIN_SETUP_StartFallEvent(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event = func_020122C0(gameSystem, 0, (void *)NAMEIN_SETUP_RunFallEvent, 0x64);
    FallEventWork *work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->anim = 0;
    work->camera = FIELDMAP_GetCamera(fieldMap);
    work->cameraStatus = FIELDMAP_GetTaskManager(fieldMap);
    work->cameraMove.frames = 0x14;
    work->cameraMove.target = d_02172528;
    work->cameraMove.easeIn = 1;
    work->cameraMove.easeOut = 1;
    work->playerObj = FIELD_CAMERA_ANIME_Create(fieldMap);
    FIELD_CAMERA_ANIME_SetData(work->playerObj, &work->cameraMove);
    return event;
}






int NAMEIN_SETUP_StepLandAnim(LandEventWork *work)
{
    return ICA_ANIME_IncFrameLoop(work->anim, 0x1000);
}




/*
 * unblocked: FLD_EXP_OBJ_GetModelStatus (ov021, unlabelled leaf) matched bottom-up and
 *           filed as pkt_021BE480; the `ov021` token resolves the +0x18
 *           call as `matched, overlay`.  FIELDMAP_GetExpObj was already matched.
 *
 * Asks the arm9 side for the slot's descriptor, sizes it through the
 * overlay helper and copies the second word of the local into it.
 */
void *NAMEIN_SETUP_SyncObjHeightToAnim(LandEventWork *work)
{
    VecFx32 animPos;
    VecFx32 *mapPos;

    func_02011610(work->anim, &animPos);
    mapPos = FLD_EXP_OBJ_GetModelStatus(FIELDMAP_GetExpObj(work->fieldMap), 0, 0);
    mapPos->y = animPos.y;

    return mapPos;
}



#pragma opt_propagation off


/*
 * Snap the actor's position to the 16-unit grid (z biased by 32) and
 * write it to the ov021 map object.
 *
 * pass 6 2026-10-06 P6L05: closed from a capture of the compiler's register
 * colouring (debugger break at the colour select step of mwccarm). The
 * graph showed y with a long live range (stored after the x snap) was
 * coloured early and took r3. Storing v.y first makes y short-lived, so it
 * is coloured late, after x; reading z, y, x (x snapped first, its load
 * hoisted) gives the image's load order x, z, y. EXACT in c99 and c.
 */
void NAMEIN_SETUP_SnapObjToGrid(LandEventWork *work)
{
    VecFx32 snapped;
    const VecFx32 *mapPos;
    void *playerObj;
    fx32 x;
    fx32 y;
    fx32 z;
    fx32 k;

    mapPos = FLD_EXP_OBJ_GetModelStatus(FIELDMAP_GetExpObj(work->fieldMap), 0, 0);
    playerObj = FIELDMAP_GetFieldPlayer(work->fieldMap);
    z = mapPos->z;
    y = mapPos->y;
    x = mapPos->x;
    k = 0x20000;
    z = z + k;
    snapped.y = y;
    snapped.x = (((x >> 12) / 16) << 16) + 0x8000;
    snapped.z = (((z >> 12) / 16) << 16) + 0x8000;
    FIELD_PLAYER_SetPos(playerObj, &snapped);
}


#pragma opt_propagation reset






/*
 * Seven-state proc of a field event in ov010: animate the actor until it
 * lands on the grid, push the result screen with a fixed Param, then
 * settle the ov050 gimmick and drop the object back to the ground height.
 * First draft; the 0x021F37xx callees are declared ov050, the only
 * overlay that labels all six.
 */
int NAMEIN_SETUP_RunLandEvent(GameEvent *event, u32 *state, LandEventWork *work)
{
    ScreenChangeParam param;
    VecFx32 playerPos;
    fx32 groundY;
    int landed;
    void *playerObj;
    void *mapObj;

    FIELDMAP_GetExpObj(work->fieldMap);
    switch (*state) {
    case 0:
        work->anim = ICA_ANIME_CreateFull(work->heapId, 0x9D, 0x19);
        NAMEIN_SETUP_SyncObjHeightToAnim(work);
        NAMEIN_SETUP_SnapObjToGrid(work);
        FIELD_CAMERA_EndDelay(work->camera);
        (*state)++;
        break;
    case 1:
        if (FIELD_CAMERA_IsDelayEnabled(work->camera) == 0)
            (*state)++;
        break;
    case 2:
        GIMMICK50_InitModelsB(work->fieldMap);
        GIMMICK50_ShowModel1(work->fieldMap);
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(work->gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 3:
        landed = NAMEIN_SETUP_StepLandAnim(work);
        if (landed == 0) {
            NAMEIN_SETUP_SyncObjHeightToAnim(work);
            NAMEIN_SETUP_SnapObjToGrid(work);
        }
        if (landed != 0) {
            ICA_ANIME_Delete(work->anim);
            GFL_USE_StopSeSlot(GFL_USE_GetSeSlot(1953));
            GFL_USE_PlaySeDefaultVolume(1775);
            param.mode = 2;
            param.variant = 0;
            param.effectKind = 3;
            param.fadeInKind = 2;
            param.fadeOutKind = 2;
            param.reserved14 = 0;
            param.startDelay = 0;
            param.step = 1;
            param.colorLow = 0;
            param.colorHigh = 0;
            param.screenMask = 2;
            GAME_EVENT_CallEvent(event, FIELD_CAMERA_CreateShakeTask(work->gameSystem, &param));
            (*state)++;
        }
        break;
    case 4:
        if (GIMMICK50_IsModel0AnimeDone(work->fieldMap) && GIMMICK50_IsModel1AnimeDone(work->fieldMap)) {
            GIMMICK50_StopModel0Anime(work->fieldMap);
            GIMMICK50_HideModel1(work->fieldMap);
            (*state)++;
        }
        break;
    case 5:
        playerObj = FIELDMAP_GetFieldPlayer(work->fieldMap);
        mapObj = FIELD_PLAYER_GetMmdl(playerObj);
        FIELD_PLAYER_GetPos(playerObj, &playerPos);
        FLDMMDL_MOVE_GetMapHeight(mapObj, &playerPos, &groundY);
        playerPos.y = groundY;
        FIELD_PLAYER_SetPos(playerObj, &playerPos);
        (*state)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}







GameEvent *NAMEIN_SETUP_StartLandEvent(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *event;
    LandEventWork *work;

    event = func_020122C0(gameSystem, 0, (void *)NAMEIN_SETUP_RunLandEvent, 0x14);
    work = func_020124E8(event);
    work->heapId = FIELDMAP_GetHeapId(fieldMap);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->camera = FIELDMAP_GetCamera(fieldMap);
    work->anim = 0;
    return event;
}








int NAMEIN_SETUP_RunPartyPickEvent(GameEvent *event, int *state, PartyTaskWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, work->fieldMap, 0, 0));
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, work->fieldMap));
        (*state)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, func_02014910(gameSystem, work->fieldMap, &work->partyScreen, &work->summary));
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*state)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        func_02082D44(work->partyScreen.pickedSlots, work->pickedSlotsOut, 6);
        *work->pickedSlotOut = work->partyScreen.pickedSlot;
        *work->pickedSubOut = work->partyScreen.pickedSub;
        func_020307B0(work->partyScreen.regulation);
        (*state)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}








/*
 * Starts the NAMEIN_SETUP_RunPartyPickEvent task over a 0xD8-byte work: points it at the
 * result fields of the encounter context, picks the party (the player's, or
 * the one at +0x7C8 when useOwnParty is set), and fills the party-screen and
 * summary argument blocks; the screen mode (0x14, 0x15 or 0x16) follows the
 * kind at +9 of the context.
 *
 * MATCH (2026-09-28 tree_ov010_4; levers: declaration order fieldMap, event,
 * gameData for the frame slots, the summary block pointer formed before the
 * func_0200CA1C call). The one wildcard is arm9 0x0201A354, an unlabelled
 * Thumb thunk (`movs r0, #0x69; bx` to 0x02048F60) inside the listing's
 * ARM data run: a seed for the ARM9 session.
 */
GameEvent *NAMEIN_SETUP_StartPartyPickEvent(EncounterContext *ctx, GameSystem *gameSystem, u8 useOwnParty)
{
    FieldMap *fieldMap;
    GameEvent *event;
    GameData *gameData;
    PartyTaskWork *work;
    void *party;
    PartyScreenArgs *partyScreen;
    SummaryArgs *summary;
    void *statusData;
    u32 screenMode;
    u32 selectMode;

    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    event = func_020122C0(gameSystem, 0, NAMEIN_SETUP_RunPartyPickEvent, sizeof(PartyTaskWork));
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->pickedSlotsOut = ctx->pickedSlots;
    work->pickedSlotOut = &ctx->pickResult;
    work->pickedSubOut = &ctx->pickResultSub;
    if (useOwnParty == 0)
        party = func_02012934(gameData);
    else
        party = ctx->party;
    screenMode = 0x14;
    selectMode = 0;
    partyScreen = &work->partyScreen;
    MI_CpuFill8(partyScreen, 0, sizeof(PartyScreenArgs));
    partyScreen->party = party;
    switch (ctx->kind) {
    case 1:
    case 6:
        screenMode = 0x15;
        selectMode = 1;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        screenMode = 0x16;
        selectMode = 2;
        break;
    }
    partyScreen->regulation = POKE_REGULATION_Load(screenMode, 4);
    partyScreen->screenType = 0x16;
    partyScreen->selectMode = selectMode;
    summary = &work->summary;
    statusData = func_0200CA1C(gameData);
    MI_CpuFill8(summary, 0, sizeof(SummaryArgs));
    summary->party = party;
    summary->mode = 1;
    summary->partyCount = POKEPARTY_GetCount(party);
    summary->startSlot = 0;
    summary->startPage = 0;
    summary->gameData = gameData;
    summary->statusData = (void *)func_0200CA38(statusData);
    return event;
}








/*
 * lever: The result of func_021CBD08 remains live in r2 and is the third argument of EVENT_BATTLE_CreateResultOnlyTask.
 *
 * DIFF: original keeps the call result in r2 (adds r2,r0) and loads the 0x7CC offset into r0;
 * ours loads the offset into r1 and stores r0. Tried a local, a struct field, unsigned char.
 */
void NAMEIN_SETUP_StartEncounterScene(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap)
{
    int transitionInfo;
    BATTLE_REC_AllocWork(4);
    transitionInfo = func_021CBD08(ctx, gameSystem);
    ctx->transitionInfo = transitionInfo;
    if (ctx->kind == 3 || ctx->kind == 8) {
        NAMEIN_SETUP_StartEncounterTransition(ctx, gameSystem, fieldMap);
        return;
    }
    EVENT_BATTLE_CreateResultOnlyTask(gameSystem, fieldMap, transitionInfo);
}








int NAMEIN_SETUP_RunNameBalloonEvent(GameEvent *event, int *state, NameBalloonWork *work, u32 extra)
{
    switch (*state) {
    case 0:
        if (!FIELD_MSGBG_TalkWinMain(work->balloon))
            break;
        (*state)++;
    case 1:
        FIELD_MSGBG_TalkWinDrawCursor(work->balloon);
        if ((KEY_GetTrg() & 3) == 0)
            break;
        GFL_USE_PlaySeDefaultVolume(0x547);
        FIELD_MSGBG_DeleteTalkWin(work->balloon);
        (*state)++;
        break;
    case 2:
        if (FIELD_MSGBG_WaitTalkWinClose(work->balloon, (u32)state, (u32)work, extra) == 1) {
            STRBUF_Delete(work->name);
            return 1;
        }
        break;
    }
    return 0;
}








/*
 * unit_02045C44.c omits func_02045CAC from function:. Singleton TU split
 * leaves this caller OUT. No overlay leaves filed.
 * EXACT 344 bytes through the ov070 blocker evidence; not recompiled here.
 * typedef unsigned char u8;
 * typedef unsigned short u16;
 * typedef unsigned int u32;
 * struct MsgEntry { u32 off; u16 len; u16 pad_06; };
 * struct MsgFile {
 *     u16 langCount; u16 count; u32 unk_04; u32 unk_08; u32 langOff[1];
 * };
 * struct MsgBank {
 *     const struct MsgFile *file;
 *     void *base;
 *     struct MsgEntry cache;
 *     u32 origin;
 *     void *stream;
 *     u16 heapId;
 *     u8 langIndex;
 *     u8 resident;
 * };
 * extern char MSGDATA_AllocSite[];
 * extern void *sub_02030734(u32,u32,int,const char *,u16);
 * extern void func_020307B0(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void func_0204960C(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void func_02045E04(void *,u32);
 * extern void func_02046180(struct MsgBank *);
 * void func_02045CAC(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     func_02046180(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         func_0204960C(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = sub_02030734((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             func_0204960C(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             func_020307B0(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     func_02045E04(dest,index);
 * }
 * lever: task, ctx, x, proc declaration order restores pointer spill slots.
 */
GameEvent *NAMEIN_SETUP_StartNameBalloonFromRecord(NameBalloonRecord *records, GameSystem *gameSystem, u32 recordIndex, u16 npcId, u8 dir)
{
    VecFx32 offset;
    int balloonKind;
    int balloonFlags;
    GameEvent *event;
    GameData *gameData;
    void *balloonManager;
    FieldMap *fieldMap;
    NameBalloonWork *work;
    MsgBank *bank;
    void *camera;
    u16 msgIndex;

    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    balloonManager = FIELDMAP_GetMsgBg(fieldMap);
    event = func_020122C0(gameSystem, 0, NAMEIN_SETUP_RunNameBalloonEvent, 0xD8);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->npcId = npcId;
    if (*(u16 *)((u32)records + 0xA0 + recordIndex * 0x120) == 0xFFFF) {
        work->name = STRBUF_Create(0x300, 4);
        bank = MSGDATA_CreateFromArchive(0, 2, 0xB8, 4);
        msgIndex = *(u16 *)((u32)records + 0xA2 + recordIndex * 0x120);
        if (msgIndex >= 0x3AE)
            msgIndex = 0;
        func_02045CAC(bank, msgIndex, work->name);
        MSGDATA_Delete(bank);
    } else {
        work->name = PMSI_PARAM_ToString((u16 *)((u32)records + 0xA0 + recordIndex * 0x120), 4);
    }
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId(func_02012964(gameData), work->npcId), &work->pos);
    camera = FIELDMAP_GetCamera(fieldMap);
    SCRCMD_MSGWIN_GetBalloonOffset(&work->pos, &offset, FIELD_CAMERA_GetG3dCamera(camera), camera, (void *)dir);
    work->pos.x += offset.x;
    work->pos.y += offset.y;
    work->pos.z += offset.z;
    SCRCMD_MSGWIN_GetBalloonTailParams(dir, &balloonKind, &balloonFlags);
    work->balloon = FIELD_MSGBG_AddTalkWin(balloonManager, balloonKind, &work->pos, work->name, 0, balloonFlags);
    return event;
}








/*
 * blockers: GAME_DATA_GetSaveBlock3B (unlabelled arm9 leaf, no witness), id_00000045 (pooled small
 * constant, a symbol; no witness), d_021BA650 (pointer into another overlay, no witness)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int NAMEIN_SETUP_RunHistoryScreenEvent(GameEvent *event, int *state, HistoryScreenWork *work)
{
    void *history;
    switch (*state) {
    case 0:
        work->gameData = func_020120F4(work->gameSystem);
        history = GAME_DATA_GetSaveBlock3B(work->gameData);
        work->historyTagA = BSUBWAY_SAVEDATA_GetHistoryTagA(history);
        work->historyTagB = BSUBWAY_SAVEDATA_GetHistoryTagB(history);
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcEvent(work->gameSystem, work->fieldMap, (int)id_00000045, d_021BA650, &work->gameData));
        (*state)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}







GameEvent *NAMEIN_SETUP_StartHistoryScreenEvent(GameSystem *gameSystem)
{
    FieldMap *fieldMap;
    GameEvent *event;
    HistoryScreenWork *work;

    fieldMap = func_0201210C(gameSystem);
    event = func_020122C0(gameSystem, 0, (void *)NAMEIN_SETUP_RunHistoryScreenEvent, 0x14);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    return event;
}








/* GFL_PROC init callback: creates the 0x76 heap and the proc work holding one allocation. */
int NAMEIN_SETUP_InitHostProc(void *proc, int *seq, void *pwk, void *mywk)
{
    void **work;

    GFL_HEAP_CreateChildHeap(1, 0x76, 0x4000);
    work = PROCSYS_AllocProcWork(proc, 4, 0x76);
    *work = PROCSYS_Create(0x76);
    return 1;
}







/*
 * extent: zero alignment halfword at 0x0216C8CA, then labelled 0x0216C8CC.
 */
int NAMEIN_SETUP_ExitHostProc(void *proc, int *seq, void *pwk, void **mywk)
{
    func_0203133C(*mywk);
    func_020315D4(proc);
    func_020306F0(0x76);
    return 1;
}






/*
 * blockers: d_021F03C4 and d_021EFDAC data pointers outside ov010 window; no witness
 * (tried ov006/008/011/187/199/ov010 hints)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int NAMEIN_SETUP_MainHostProc(void *proc, int *seq, int *pwk, int *mywk)
{
    int status = PROCSYS_Main((void *)mywk[0]);
    switch (*seq) {
    case 0:
        func_02034AC4((s32)id_0000005D);
        GFL_NET_COMMAND_AddCommandTable(0x100, (u32)d_021F03C4, 9, 0);
        GFL_NET_StartTimingSync((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8);
        *seq = 1;
        break;
    case 1:
        if (func_0200FB24() != 0) {
            *seq = 4;
            break;
        }
        if (GFL_NET_CheckTimingSync((int)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8) == 0)
            break;
        *seq = 2;
        break;
    case 2:
        PROCSYS_Push(mywk[0], ~0, d_021EFDAC, pwk[1]);
        *seq = 3;
        break;
    case 3:
        if (status == 1)
            break;
        *seq = 4;
        break;
    case 4:
        GFL_NET_COMMAND_DeleteCommandTable(0x100);
        func_02034A5C((s32)id_0000005D);
        *seq = 5;
        break;
    case 5:
        return 1;
    }
    return 0;
}






int NAMEIN_SETUP_RunProcCallEvent(GameEvent *event, int *state, ProcCallWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    ProcCallParam *param;
    switch (*state) {
    case 0:
        param = &work->param;
        param->gameData = func_020120F4(gameSystem);
        param->transitionInfo = work->transitionInfo;
        param->extra = work->extra;
        GAMESYSTEM_CallProc(gameSystem, ~0, d_02172548, param);
        (*state)++;
        break;
    case 1:
        if (GAMESYSTEM_GetProcStatus(gameSystem) == 0)
            return 1;
        break;
    }
    return 0;
}





GameEvent *NAMEIN_SETUP_StartProcCallEvent(GameSystem *gameSystem, TransitionInfo *transitionInfo, void *extra)
{
    GameEvent *event;
    ProcCallWork *work;
    event = func_020122C0(gameSystem, 0, (void *)NAMEIN_SETUP_RunProcCallEvent, 0x3c);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->transitionInfo = transitionInfo;
    work->extra = extra;
    return event;
}






int NAMEIN_SETUP_RunSceneEvent(GameEvent *event, int *state, SceneEventWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;
    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
        (*state)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushOrFadeOutAndPlayTask(gameSystem, work->transitionInfo->sceneId));
        (*state)++;
        break;
    case 2:
        EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount(fieldMap));
        ENCEFF_Start(FIELDMAP_GetEncEff(work->fieldMap), event, 9);
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseEvent(gameSystem, fieldMap));
        (*state)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, NAMEIN_SETUP_StartProcCallEvent(gameSystem, work->transitionInfo, work->extra));
        (*state)++;
        break;
    case 5:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopDefaultFadeTask(gameSystem));
        (*state)++;
        break;
    case 6:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*state)++;
        break;
    case 7:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitAcceptRequestTask(gameSystem));
        (*state)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 9:
        return 1;
    default:
        return 1;
    }
    return 0;
}





GameEvent *NAMEIN_SETUP_StartSceneEvent(GameSystem *gameSystem, FieldMap *fieldMap, TransitionInfo *transitionInfo, void *extra)
{
    GameEvent *event;
    SceneEventWork *work;
    event = func_020122C0(gameSystem, 0, (void *)NAMEIN_SETUP_RunSceneEvent, 0x10);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->transitionInfo = transitionInfo;
    work->extra = extra;
    work->fieldMap = fieldMap;
    return event;
}






/*
 * unblocked: func_021CBD84 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021CBD84; the `ov021` token then resolves the site as
 *   `matched, overlay`.
 *
 * The far field (0x7CC) of the context and the arm9 probe result are the
 * last two arguments of the four-argument overlay call.
 */
void NAMEIN_SETUP_StartEncounterTransition(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap)
{
    void *extra = func_021CBD84(ctx);

    NAMEIN_SETUP_StartSceneEvent(gameSystem, fieldMap, (TransitionInfo *)ctx->transitionInfo, extra);
}






int NAMEIN_SETUP_RunNameBalloonWaitEvent(GameEvent *event, int *state, NameBalloonWork *work)
{
    switch (*state) {
    case 0:
        if (FIELD_MSGBG_TalkWinMain(work->balloon) == 1)
            (*state)++;
        break;
    case 1:
        if ((KEY_GetTrg() & 3) == 0)
            break;
        FIELD_MSGBG_DeleteTalkWin(work->balloon);
        (*state)++;
        break;
    case 2:
        if (FIELD_MSGBG_WaitTalkWinClose(work->balloon) == 1) {
            STRBUF_Delete(work->name);
            return 1;
        }
        break;
    }
    return 0;
}






/*
 * The third parameter is u8: with it declared int the body is byte-identical
 * except that the work->gameSystem store and the next call's argument move swap
 * places (4 bytes); the u8 spill to [sp,#8] changes nothing visible but the
 * schedule.
 *
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =PMSI_PARAM_ToStringWords; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x02168138), so the call
 * attests as `label`.
 */
GameEvent *NAMEIN_SETUP_StartNameBalloonFromHistory(GameSystem *gameSystem, int recordIndex, u8 npcId)
{
    GameData *gameData;
    FieldMap *fieldMap;
    void *balloonManager;
    GameEvent *event;
    NameBalloonWork *work;
    void *occupyInfo;
    void *mmdlSys;
    void *camera;
    VecFx32 offset;
    int balloonKind;
    int balloonFlags;
    HistoryEntry *entries;
    int dir;

    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    balloonManager = FIELDMAP_GetMsgBg(fieldMap);
    event = func_020122C0(gameSystem, 0, NAMEIN_SETUP_RunNameBalloonWaitEvent, 0x1C);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    occupyInfo = func_02012964(gameData);
    mmdlSys = FLDMMDL_SysSearchPlayer(occupyInfo);
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId(occupyInfo, npcId), &work->pos);
    dir = SCRCMD_MSGWIN_GetBalloonSide(mmdlSys, &work->pos);
    camera = FIELDMAP_GetCamera(fieldMap);
    SCRCMD_MSGWIN_GetBalloonOffset(&work->pos, &offset, FIELD_CAMERA_GetG3dCamera(camera), camera, (void *)dir);
    work->pos.x += offset.x;
    work->pos.y += offset.y;
    work->pos.z += offset.z;
    entries = BSUBWAY_SAVEDATA_AllocHistoryCopy(func_020071CC(GAME_DATA_GetSaveControl(gameData), 0x3b), 4);
    work->name = PMSI_PARAM_ToString(entries[recordIndex].nameChars, 4);
    func_020307B0(entries);
    SCRCMD_MSGWIN_GetBalloonTailParams(dir, &balloonKind, &balloonFlags);
    work->balloon = FIELD_MSGBG_AddTalkWin(balloonManager, balloonKind, &work->pos, work->name, 0, balloonFlags);
    return event;
}






/* Script command: raise the save flag in the field save block (the command context is unused). */
int NAMEIN_SETUP_ScrCmdSetFieldSaveFlag(void *scriptCtx, void *scriptWork)
{
    GameSystem *gameSystem;

    gameSystem = SCRCMD_WORK_GetGameSystem(scriptWork);
    NAMEIN_SETUP_SetFieldSaveFlag(gameSystem);
    return 0;
}





/*
 * extent: zero alignment halfword at 0x0216CC56, then labelled 0x0216CC58.
 * interface: r1=0x34 is visibly supplied to the accessor despite its body only reading r0.
 */
void NAMEIN_SETUP_SetFieldSaveFlag(GameSystem *gameSystem)
{
    *func_0200B3A4(GAME_DATA_GetFieldSave(func_020120F4(gameSystem)), 0x34) = 1;
}
