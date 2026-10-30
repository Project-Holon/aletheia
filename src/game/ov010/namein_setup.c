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
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Copy  0x02045838  arm
 *   d_02172A60     0x02172A60  data  ov010  a1
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_CAMERA_ANIME_Setup  0x0218FEA4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam  0x0218FE78  thumb  ov021
 *   FIELD_CAMERA_ANIME_Start  0x0218FF00  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb
 *   FIELD_CAMERA_ANIME_Delete  0x0218FE98  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   ICA_ANIME_CreateFull  0x020114D0  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 *   ICA_ANIME_GetTranslate  0x02011610  thumb
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
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_CAMERA_ANIME_Create  0x0218FE80  thumb  ov021
 *   FIELD_CAMERA_ANIME_SetData  0x0218FEA0  thumb  ov021
 *   d_02172528     0x02172528  data  ov010  a4
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_GIMMICK_MODELS_B_StartModel0Anime  0x021F3714  thumb  ov050
 *   FIELD_GIMMICK_MODELS_B_ShowModel1  0x021F37B8  thumb  ov050
 *   FIELD_GIMMICK_MODELS_B_IsModel0AnimeDone  0x021F3758  thumb  ov050
 *   FIELD_GIMMICK_MODELS_B_IsModel1AnimeDone  0x021F3808  thumb  ov050
 *   FIELD_GIMMICK_MODELS_B_StopModel0Anime  0x021F3744  thumb  ov050
 *   FIELD_GIMMICK_MODELS_B_HideModel1  0x021F3788  thumb  ov050
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb
 *   FIELD_CAMERA_CreateShakeTask  0x021D2D50  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateSubProcListEvent  0x02014910  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   POKE_REGULATION_Load  0x0201A354  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   BATTLE_REC_AllocWork  0x0200B400  thumb
 *   BSUBWAY_SCR_CreateBtlSetup  0x021CBD08  thumb  ov021
 *   EVENT_BATTLE_CreateResultOnlyTask  0x0216E8CC  thumb  ov010
 *   FIELD_MSGBG_TalkWinMain  0x02191388  thumb  ov021
 *   FIELD_MSGBG_TalkWinDrawCursor  0x021914CC  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   FIELD_MSGBG_DeleteTalkWin  0x021912D8  thumb  ov021
 *   FIELD_MSGBG_WaitTalkWinClose  0x021912F8  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   MSGDATA_CreateFromArchive   0x02045B38  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   PMSI_PARAM_ToString  0x0202435C  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
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
 *   PROCSYS_Delete 0x0203133C arm
 *   PROCSYS_FreeProcWork 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 *   PROCSYS_Main  0x02031330  arm
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_StartTimingSync  0x0203D594  arm
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GFL_NET_CheckTimingSync  0x0203D5A0  arm
 *   PROCSYS_Push  0x02031348  arm
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
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
 *   BSUBWAY_SCR_GetNameinEncounterWork   0x021CBD84  thumb  ov021
 *   GAME_EVENT_Create   0x020122C0  thumb
 *   GAME_EVENT_GetWork   0x020124E8  thumb
 *   SCRCMD_MSGWIN_GetBalloonSide  0x021B0A40  thumb  ov021
 *   SAVE_CONTROL_GetBlock  0x020071CC  thumb
 *   BSUBWAY_SAVEDATA_AllocHistoryCopy  0x0200DF58  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAME_DATA_GetFieldSave 0x02012EC4 thumb
 *   GIMMICK_WORK_GetWork 0x0200B3A4 thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 */
struct IcaAnime;
#include "../types.h"

#include "../sdk_fx.h"

typedef struct Strbuf Strbuf;
/*
 * Argument block of the name input screen (0x2c bytes). Kind 0 asks for a
 * player name; kind 1 asks for a monster nickname, either from a species and
 * traits pair or from the monster itself (NAMEIN_SETUP_CreateMonArgs).
 */
#include "namein_args.h"

#include "../ov021/field_camera_anime.h"
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
#include "../ov021/field_task_manager.h"
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
    int nationalDexEnabled; /* 0x18 */
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
    struct BattleSetupParam *transitionInfo; /* 0x7CC */
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
/* The balloon the history variant shows: the same first 0x1C bytes without the npc id (allocated 0x1C bytes). */
typedef struct NameBalloonWaitWork {
    GameSystem *gameSystem;     /* 0x00 */
    u32 reserved04;
    VecFx32 pos;                /* 0x08 */
    void *balloon;              /* 0x14 */
    Strbuf *name;               /* 0x18 */
} NameBalloonWaitWork;
/* One 0x22-byte entry of the history table; the name balloon shows its name. */
typedef struct NameinHistoryEntry {
    u8 reserved00[0x18];
    u16 nameChars[5];           /* 0x18 */
} NameinHistoryEntry;
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
struct SaveControl;
#include "../arm9/game_data.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/strbuf.h"
struct PokemonParam;
#include "../arm9/poke_tool.h"
struct FieldCameraAnime;
struct FieldCameraParam;
struct FieldCamera;
struct FieldTaskManager;
#include "../ov021/fieldmap.h"
#include "../arm9/ica_anime.h"
#include "../arm9/gfl_use.h"
struct FldExpObjCnt;
struct G3dObjectStatus;
#include "../ov021/fld_exp_obj.h"
struct FieldPlayer;
struct VecFx32;
                                  
                                            
struct FieldCameraAnimeData;
#include "fldmmdl_move.h"
#include "../ov021/field_camera.h"
#include "../ov021/field_player.h"
#include "../ov050/field_gimmick_models_b.h"
struct CameraShakeParams;
#include "../ov021/scrcmd_misc.h"
struct FieldPlayer;
#include "../arm9/field_status.h"
#include "../arm9/mi_memory.h"
#include "../arm9/gamesystem.h"
#include "../arm9/poke_regulation.h"
#include "../arm9/zukan_save.h"
struct Party;
#include "../arm9/pokeparty.h"
struct ZukanSave;
#include "../arm9/battle_rec.h"
struct BsubwayScrWork;
#include "../ov021/bsubway_scr.h"
#include "event_battle.h"
struct FieldTalkWin;
#include "../ov021/field_msgbg.h"
#include "../arm9/key.h"
struct FieldMsgBg;
#include "../arm9/msgdata.h"
struct G3dCamera;
extern void SCRCMD_MSGWIN_GetBalloonTailParams(int dir, int *kind, int *flags);
struct BsubwaySave;
typedef unsigned short StatRow;
#include "../arm9/bsubway_savedata.h"
#include "../arm9/gfl_heap.h"
struct Proc;
#include "../arm9/procsys.h"
#include "../arm9/gf_overlay.h"
#include "../arm9/net_command.h"
struct GFLNetHandle;
#include "../arm9/net_handle.h"
#include "../arm9/net.h"
#include "../arm9/net_err.h"
#include "event_field_proclink.h"
#include "../arm9/field_sound_system.h"
struct FieldEncount;
#include "../ov021/effect_encount.h"
struct EncEffWork;
struct EncEffWork;
#include "../ov021/enceff.h"
extern int SCRCMD_MSGWIN_GetBalloonSide(struct Mmdl *playerMmdl, VecFx32 *targetPos);
#include "../arm9/save_control.h"
struct HistoryBuf;
struct ScrcmdWork;
#include "scrcmd_work.h"
struct GimmickWork;
#include "../arm9/gimmick.h"
struct VecFx32;
#include "fldmmdl.h"
#include "../arm9/game_event.h"
#include "../ov021/event_fieldmap_control.h"
#include "../ov020/event_mapchange.h"
#include "../arm9/pmsi_param.h"
#include "../version.h"
#ifdef __MWERKS__
extern void SCRCMD_MSGWIN_GetBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera, void *windowKind); /* original prototype: the definition takes u8 windowKind */
#define BALLOON_WINDOW_KIND(dir) ((void *)(dir))
#else
extern void SCRCMD_MSGWIN_GetBalloonOffset(const VecFx32 *mmdlPos, VecFx32 *out, struct G3dCamera *camera, struct FieldCamera *fieldCamera, u8 windowKind);
#define BALLOON_WINDOW_KIND(dir) ((u8)(dir))
#endif
#define WAIT_TALK_WIN_CLOSE(talkWin, state, work, extra) FIELD_MSGBG_WaitTalkWinClose(talkWin)
struct MmdlSys;
NameInArgs *NAMEIN_SETUP_CreateArgs(unsigned short heapId, int kind, short species, short traits, int maxLen, Strbuf *initialName, void *pokedex);
NameInArgs *NAMEIN_SETUP_CreateMonArgs(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, void *pokedex);
NameInArgs *NAMEIN_SETUP_CreateCaptureArgs(unsigned short heapId, void *mon, int maxLen, Strbuf *initialName, Strbuf *boxName, void *boxManager, int boxIndex, void *pokedex);
void NAMEIN_SETUP_FreeArgs(NameInArgs *args);
void NAMEIN_SETUP_CopyName(NameInArgs *args, Strbuf *dest);
int NAMEIN_SETUP_IsCanceled(NameInArgs *args);
int NAMEIN_SETUP_RunFallEvent(struct GameEvent *event, int *state, void *work);
GameEvent *NAMEIN_SETUP_StartFallEvent(GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_StepLandAnim(LandEventWork *work);
void *NAMEIN_SETUP_SyncObjHeightToAnim(LandEventWork *work);
void NAMEIN_SETUP_SnapObjToGrid(LandEventWork *work);
int NAMEIN_SETUP_RunLandEvent(struct GameEvent *event, int *state, void *work);
GameEvent *NAMEIN_SETUP_StartLandEvent(GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_RunPartyPickEvent(struct GameEvent *event, int *state, void *work);
GameEvent *NAMEIN_SETUP_StartPartyPickEvent(EncounterContext *ctx, GameSystem *gameSystem, u8 useOwnParty);
GameEvent *NAMEIN_SETUP_StartEncounterScene(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_RunNameBalloonEvent(struct GameEvent *event, int *state, void *work);
GameEvent *NAMEIN_SETUP_StartNameBalloonFromRecord(NameBalloonRecord *records, GameSystem *gameSystem, u32 recordIndex, u16 npcId, u8 dir);
int NAMEIN_SETUP_RunHistoryScreenEvent(struct GameEvent *event, int *state, void *work);
GameEvent *NAMEIN_SETUP_StartHistoryScreenEvent(GameSystem *gameSystem);
int NAMEIN_SETUP_InitHostProc(void *proc, int *seq, void *pwk, void *mywk);
int NAMEIN_SETUP_ExitHostProc(void *proc, int *seq, void *pwk, void **mywk);
int NAMEIN_SETUP_MainHostProc(void *proc, int *seq, void **pwk, struct ProcSys **mywk);
int NAMEIN_SETUP_RunProcCallEvent(struct GameEvent *event, int *state, void *work);
GameEvent *NAMEIN_SETUP_StartProcCallEvent(GameSystem *gameSystem, TransitionInfo *transitionInfo, void *extra);
int NAMEIN_SETUP_RunSceneEvent(struct GameEvent *event, int *state, void *work);
GameEvent *NAMEIN_SETUP_StartSceneEvent(GameSystem *gameSystem, FieldMap *fieldMap, TransitionInfo *transitionInfo, void *extra);
GameEvent *NAMEIN_SETUP_StartEncounterTransition(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap);
int NAMEIN_SETUP_RunNameBalloonWaitEvent(struct GameEvent *event, int *state, void *work);
GameEvent *NAMEIN_SETUP_StartNameBalloonFromHistory(GameSystem *gameSystem, int recordIndex, u8 npcId);
int NAMEIN_SETUP_ScrCmdSetFieldSaveFlag(void *scriptCtx, void *scriptWork);
void NAMEIN_SETUP_SetFieldSaveFlag(GameSystem *gameSystem);
extern char d_02172A60[];
extern CameraTarget d_02172528;
extern char d_021BA650[];
extern char id_00000045[];
extern char id_0000005D[];
extern NetCommandEntry d_021F03C4[];
extern const struct ProcData d_021EFDAC;
extern const ProcData d_02172548;

/*
 * The heap id is a u16: as an int its entry spill (str r0,[sp,#4]) sinks
 * below the stack-argument setup. STRBUF_Copy takes the flag as its second
 * argument, which is why the image loads it into r1 ahead of the p[8] store.
 */
NameInArgs *NAMEIN_SETUP_CreateArgs(unsigned short heapId, int kind, short species, short traits, int maxLen, Strbuf *initialName, void *pokedex)
{
    NameInArgs *args = GFL_HEAP_Alloc(heapId, sizeof(NameInArgs), 0, d_02172A60, 0x37);
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
    NameInArgs *args = GFL_HEAP_Alloc(heapId, sizeof(NameInArgs), 0, d_02172A60, 0x59);
    MI_CpuFill8(args, 0, sizeof(NameInArgs));
    args->kind = 1;
    args->maxLen = maxLen;
    args->mon = mon;
    args->pokedex = pokedex;
    if (mon) {
        int low;
        args->species = POKE_TOOL_GetPartyValue(mon, 5, 0);
        low = POKE_TOOL_GetPartyValue(mon, 0x6f, 0);
        args->traits = (POKE_TOOL_GetPartyValue(mon, 0x6e, 0) << 8) | low;
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
    GFL_HEAP_Free(args);
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
int NAMEIN_SETUP_RunFallEvent(struct GameEvent *event, int *state, void *workPtr)
{
    FallEventWork *work = workPtr;
    VecFx32 cur;
    VecFx32 v;
    VecFx32 pos;
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;
    void *cameraStatus = work->cameraStatus;
    void *playerObj;

    switch (*state) {
    case 0:
        FIELD_CAMERA_ANIME_Setup(work->playerObj);
        FIELD_CAMERA_ANIME_GetCurrentParam(work->camera, (struct FieldCameraParam *)work->cameraMove.startArgs);
        FIELD_CAMERA_ANIME_Start((struct FieldCameraAnime *)work->playerObj);
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
        GFL_USE_PlaySeInSlot((u32)1953, GFL_USE_GetSeSlot(1953));
        (*state)++;
        break;
    case 3:
        ICA_ANIME_GetTranslate(work->anim, &cur);
        ((struct VecFx32 *)FLD_EXP_OBJ_GetModelStatus(FIELDMAP_GetExpObj(fieldMap), 0, 0))->y = cur.y;
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
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, NAMEIN_SETUP_RunFallEvent, sizeof(FallEventWork));
    FallEventWork *work = GAME_EVENT_GetWork(event);
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
    FIELD_CAMERA_ANIME_SetData(work->playerObj, (struct FieldCameraAnimeData *)(&work->cameraMove));
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

    ICA_ANIME_GetTranslate(work->anim, &animPos);
    mapPos = (struct VecFx32 *)FLD_EXP_OBJ_GetModelStatus(FIELDMAP_GetExpObj(work->fieldMap), 0, 0);
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

    mapPos = (struct VecFx32 *)FLD_EXP_OBJ_GetModelStatus(FIELDMAP_GetExpObj(work->fieldMap), 0, 0);
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
int NAMEIN_SETUP_RunLandEvent(struct GameEvent *event, int *state, void *workPtr)
{
    LandEventWork *work = workPtr;
    ScreenChangeParam param;
    VecFx32 playerPos;
    fx32 groundY;
    int landed;
    void *playerObj;
    Mmdl *mapObj;

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
        FIELD_GIMMICK_MODELS_B_StartModel0Anime(work->fieldMap);
        FIELD_GIMMICK_MODELS_B_ShowModel1(work->fieldMap);
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
            GAME_EVENT_CallEvent(event, FIELD_CAMERA_CreateShakeTask(work->gameSystem, (struct CameraShakeParams *)(&param)));
            (*state)++;
        }
        break;
    case 4:
        if (FIELD_GIMMICK_MODELS_B_IsModel0AnimeDone(work->fieldMap) && FIELD_GIMMICK_MODELS_B_IsModel1AnimeDone(work->fieldMap)) {
            FIELD_GIMMICK_MODELS_B_StopModel0Anime(work->fieldMap);
            FIELD_GIMMICK_MODELS_B_HideModel1(work->fieldMap);
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

    event = GAME_EVENT_Create(gameSystem, 0, NAMEIN_SETUP_RunLandEvent, sizeof(LandEventWork));
    work = GAME_EVENT_GetWork(event);
    work->heapId = FIELDMAP_GetHeapId(fieldMap);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->camera = FIELDMAP_GetCamera(fieldMap);
    work->anim = 0;
    return event;
}

int NAMEIN_SETUP_RunPartyPickEvent(struct GameEvent *event, int *state, void *workPtr)
{
    PartyTaskWork *work = workPtr;
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
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcListEvent(gameSystem, work->fieldMap, &work->partyScreen, &work->summary));
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        (*state)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        MI_CpuCopy8(work->partyScreen.pickedSlots, work->pickedSlotsOut, 6);
        *work->pickedSlotOut = work->partyScreen.pickedSlot;
        *work->pickedSubOut = work->partyScreen.pickedSub;
        GFL_HEAP_Free(work->partyScreen.regulation);
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
 * ZUKAN_SAVE_GetFromGameData call). The one wildcard is arm9 0x0201A354, an unlabelled
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

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, NAMEIN_SETUP_RunPartyPickEvent, sizeof(PartyTaskWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->pickedSlotsOut = ctx->pickedSlots;
    work->pickedSlotOut = &ctx->pickResult;
    work->pickedSubOut = &ctx->pickResultSub;
    if (useOwnParty == 0)
        party = GAME_DATA_GetMyParty(gameData);
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
    statusData = ZUKAN_SAVE_GetFromGameData(gameData);
    MI_CpuFill8(summary, 0, sizeof(SummaryArgs));
    summary->party = party;
    summary->mode = 1;
    summary->partyCount = POKEPARTY_GetCount(party);
    summary->startSlot = 0;
    summary->startPage = 0;
    summary->gameData = gameData;
    summary->nationalDexEnabled = ZUKAN_SAVE_IsNationalDexEnabled(statusData);
    return event;
}

/*
 * lever: The result of BSUBWAY_SCR_CreateBtlSetup remains live in r2 and is the third argument of EVENT_BATTLE_CreateResultOnlyTask.
 *
 * DIFF: original keeps the call result in r2 (adds r2,r0) and loads the 0x7CC offset into r0;
 * ours loads the offset into r1 and stores r0. Tried a local, a struct field, unsigned char.
 */
GameEvent *NAMEIN_SETUP_StartEncounterScene(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap)
{
    struct BattleSetupParam *transitionInfo;
    BATTLE_REC_AllocWork(4);
    transitionInfo = BSUBWAY_SCR_CreateBtlSetup((struct BsubwayScrWork *)ctx, gameSystem);
    ctx->transitionInfo = transitionInfo;
    if (ctx->kind == 3 || ctx->kind == 8) {
        return NAMEIN_SETUP_StartEncounterTransition(ctx, gameSystem, fieldMap);
    }
    return EVENT_BATTLE_CreateResultOnlyTask(gameSystem, fieldMap, transitionInfo);
}

int NAMEIN_SETUP_RunNameBalloonEvent(struct GameEvent *event, int *state, void *workPtr)
{
    NameBalloonWork *work = workPtr;
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
        if (WAIT_TALK_WIN_CLOSE(work->balloon, (u32)state, (u32)work, extra) == 1) {
            STRBUF_Delete(work->name);
            return 1;
        }
        break;
    }
    return 0;
}

/*
 * unit_02045C44.c omits MSGDATA_ReadString from function:. Singleton TU split
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
 * extern void *GFL_HEAP_Alloc(u32,u32,int,const char *,u16);
 * extern void GFL_HEAP_Free(void *);
 * extern void ARC_TOOL_ReadHandle(void *,u32,void *);
 * extern void ARC_TOOL_SeekHandle(void *,u32);
 * extern void STRBUF_Clear(void *);
 * extern void STRBUF_SetChars(void *,const void *,u16);
 * extern void MSGDATA_DecryptStrbuf(void *,u32);
 * extern void MSGDATA_RefreshLanguage(struct MsgBank *);
 * void MSGDATA_ReadString(struct MsgBank *bank,u32 index,void *dest)
 * {
 *     u32 size;
 *     struct MsgEntry *e;
 *     if (index >= bank->file->count) {
 *         STRBUF_Clear(dest);
 *         return;
 *     }
 *     MSGDATA_RefreshLanguage(bank);
 *     if (bank->resident == 0) {
 *         u32 pos = bank->origin + bank->file->langOff[bank->langIndex];
 *         ARC_TOOL_SeekHandle(bank->stream,pos + (index * 8 + 4));
 *         ARC_TOOL_ReadHandle(bank->stream,8,&bank->cache);
 *         e = &bank->cache;
 *     } else {
 *         e = (struct MsgEntry *)((u8 *)bank->base + 4) + index;
 *     }
 *     if (bank->resident == 0) {
 *         void *buf;
 *         size = e->len * 2;
 *         buf = GFL_HEAP_Alloc((u16)((bank->heapId & 0x7fff) | 0x8000),size,
 *                            0,MSGDATA_AllocSite,0xd6);
 *         if (buf != 0) {
 *             ARC_TOOL_SeekHandle(bank->stream,
 *                           e->off + (bank->origin
 *                               + bank->file->langOff[bank->langIndex]));
 *             ARC_TOOL_ReadHandle(bank->stream,size,buf);
 *             STRBUF_SetChars(dest,buf,e->len);
 *             GFL_HEAP_Free(buf);
 *         }
 *     } else {
 *         STRBUF_SetChars(dest,(u8 *)bank->base + e->off,e->len);
 *     }
 *     MSGDATA_DecryptStrbuf(dest,index);
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

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    balloonManager = FIELDMAP_GetMsgBg(fieldMap);
    event = GAME_EVENT_Create(gameSystem, 0, NAMEIN_SETUP_RunNameBalloonEvent, 0xD8);
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->npcId = npcId;
    if (*(u16 *)((uptr)records + 0xA0 + recordIndex * 0x120) == 0xFFFF) {
        work->name = STRBUF_Create(PM_LANG_JA(0x300, 0x200), 4);
        bank = MSGDATA_CreateFromArchive(0, 2, 0xB8, 4);
        msgIndex = *(u16 *)((u8 *)records + 0xA2 + recordIndex * 0x120);
        if (msgIndex >= 0x3AE)
            msgIndex = 0;
        MSGDATA_ReadString(bank, msgIndex, work->name);
        MSGDATA_Delete(bank);
    } else {
        work->name = PMSI_PARAM_ToString((const struct PmsData *)((uptr)records + 0xA0 + recordIndex * 0x120), 4);
    }
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId(GAME_DATA_GetOccupyInfo(gameData), work->npcId), (struct VecFx32 *)(&work->pos));
    camera = FIELDMAP_GetCamera(fieldMap);
    SCRCMD_MSGWIN_GetBalloonOffset(&work->pos, &offset, FIELD_CAMERA_GetG3dCamera(camera), camera, BALLOON_WINDOW_KIND(dir));
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
int NAMEIN_SETUP_RunHistoryScreenEvent(struct GameEvent *event, int *state, void *workPtr)
{
    HistoryScreenWork *work = workPtr;
    void *history;
    switch (*state) {
    case 0:
        work->gameData = GAMESYSTEM_GetGameData(work->gameSystem);
        history = GAME_DATA_GetSaveBlock3B(work->gameData);
        work->historyTagA = BSUBWAY_SAVEDATA_GetHistoryTagA(history);
        work->historyTagB = BSUBWAY_SAVEDATA_GetHistoryTagB(history);
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateSubProcEvent(work->gameSystem, work->fieldMap, (sptr)id_00000045, d_021BA650, &work->gameData));
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

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, NAMEIN_SETUP_RunHistoryScreenEvent, sizeof(HistoryScreenWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    return event;
}

/* GFL_PROC init callback: creates the 0x76 heap and the proc work holding one allocation. */
int NAMEIN_SETUP_InitHostProc(void *proc, int *seq, void *pwk, void *mywk)
{
    void **work;

    GFL_HEAP_CreateChildHeap(1, 0x76, 0x4000);
    work = PROCSYS_AllocProcWork(proc, sizeof(*work), 0x76);
    *work = PROCSYS_Create(0x76);
    return 1;
}

/*
 * extent: zero alignment halfword at 0x0216C8CA, then labelled 0x0216C8CC.
 */
int NAMEIN_SETUP_ExitHostProc(void *proc, int *seq, void *pwk, void **mywk)
{
    PROCSYS_Delete(*mywk);
    PROCSYS_FreeProcWork(proc);
    GFL_HEAP_DeleteChecked(0x76);
    return 1;
}

/*
 * blockers: d_021F03C4 and d_021EFDAC data pointers outside ov010 window; no witness
 * (tried ov006/008/011/187/199/ov010 hints)
 *
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 */
int NAMEIN_SETUP_MainHostProc(void *proc, int *seq, void **pwk, struct ProcSys **mywk)
{
    int status = PROCSYS_Main(mywk[0]);
    switch (*seq) {
    case 0:
        GF_OVERLAY_Load((sptr)id_0000005D);
        GFL_NET_COMMAND_AddCommandTable(0x100, d_021F03C4, 9, 0);
        GFL_NET_StartTimingSync((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8);
        *seq = 1;
        break;
    case 1:
        if (GFL_NET_ERR_GetErrorLevel() != 0) {
            *seq = 4;
            break;
        }
        if (GFL_NET_CheckTimingSync((struct GFLNetHandle *)GFL_NET_HANDLE_GetCurrentHandle(), 0xc8) == 0)
            break;
        *seq = 2;
        break;
    case 2:
        PROCSYS_Push(mywk[0], ~0, &d_021EFDAC, pwk[1]);
        *seq = 3;
        break;
    case 3:
        if (status == 1)
            break;
        *seq = 4;
        break;
    case 4:
        GFL_NET_COMMAND_DeleteCommandTable(0x100);
        GF_OVERLAY_Unload((sptr)id_0000005D);
        *seq = 5;
        break;
    case 5:
        return 1;
    }
    return 0;
}

int NAMEIN_SETUP_RunProcCallEvent(struct GameEvent *event, int *state, void *workPtr)
{
    ProcCallWork *work = workPtr;
    GameSystem *gameSystem = work->gameSystem;
    ProcCallParam *param;
    switch (*state) {
    case 0:
        param = &work->param;
        param->gameData = GAMESYSTEM_GetGameData(gameSystem);
        param->transitionInfo = work->transitionInfo;
        param->extra = work->extra;
        GAMESYSTEM_CallProc(gameSystem, ~0, &d_02172548, param);
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
    event = GAME_EVENT_Create(gameSystem, 0, NAMEIN_SETUP_RunProcCallEvent, 0x3c);
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->transitionInfo = transitionInfo;
    work->extra = extra;
    return event;
}

int NAMEIN_SETUP_RunSceneEvent(struct GameEvent *event, int *state, void *workPtr)
{
    SceneEventWork *work = workPtr;
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
        ENCEFF_Start((struct EncEffWork *)FIELDMAP_GetEncEff(work->fieldMap), event, 9);
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
    event = GAME_EVENT_Create(gameSystem, 0, NAMEIN_SETUP_RunSceneEvent, sizeof(SceneEventWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->transitionInfo = transitionInfo;
    work->extra = extra;
    work->fieldMap = fieldMap;
    return event;
}

/*
 * unblocked: BSUBWAY_SCR_GetNameinEncounterWork (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021CBD84; the `ov021` token then resolves the site as
 *   `matched, overlay`.
 *
 * The far field (0x7CC) of the context and the arm9 probe result are the
 * last two arguments of the four-argument overlay call.
 */
GameEvent *NAMEIN_SETUP_StartEncounterTransition(EncounterContext *ctx, GameSystem *gameSystem, FieldMap *fieldMap)
{
    void *extra = BSUBWAY_SCR_GetNameinEncounterWork(ctx);

    return NAMEIN_SETUP_StartSceneEvent(gameSystem, fieldMap, (TransitionInfo *)ctx->transitionInfo, extra);
}

int NAMEIN_SETUP_RunNameBalloonWaitEvent(struct GameEvent *event, int *state, void *workPtr)
{
    NameBalloonWaitWork *work = workPtr;
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
    NameBalloonWaitWork *work;
    void *occupyInfo;
    void *mmdlSys;
    void *camera;
    VecFx32 offset;
    int balloonKind;
    int balloonFlags;
    NameinHistoryEntry *entries;
    int dir;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    balloonManager = FIELDMAP_GetMsgBg(fieldMap);
    event = GAME_EVENT_Create(gameSystem, 0, NAMEIN_SETUP_RunNameBalloonWaitEvent, sizeof(NameBalloonWaitWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    occupyInfo = GAME_DATA_GetOccupyInfo(gameData);
    mmdlSys = FLDMMDL_SysSearchPlayer(occupyInfo);
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId(occupyInfo, npcId), (struct VecFx32 *)(&work->pos));
    dir = SCRCMD_MSGWIN_GetBalloonSide(mmdlSys, &work->pos);
    camera = FIELDMAP_GetCamera(fieldMap);
    SCRCMD_MSGWIN_GetBalloonOffset(&work->pos, &offset, FIELD_CAMERA_GetG3dCamera(camera), camera, BALLOON_WINDOW_KIND(dir));
    work->pos.x += offset.x;
    work->pos.y += offset.y;
    work->pos.z += offset.z;
    entries = (struct NameinHistoryEntry *)BSUBWAY_SAVEDATA_AllocHistoryCopy(SAVE_CONTROL_GetBlock(GAME_DATA_GetSaveControl(gameData), 0x3b), 4);
    work->name = PMSI_PARAM_ToString((const struct PmsData *)entries[recordIndex].nameChars, 4);
    GFL_HEAP_Free(entries);
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
    *GIMMICK_WORK_GetWork((struct GimmickWork *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(gameSystem)), 0x34) = 1;
}
