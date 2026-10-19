/*
 * file:     event_mapchange.c
 * unit:     yes
 * function: EVENT_MAPCHANGE_CallHookAndInvert, EVENT_MAPCHANGE_CreateByMode, EVENT_MAPCHANGE_FirstStartEvent, EVENT_MAPCHANGE_CreateFirstStartEvent, EVENT_MAPCHANGE_InitUnionInfo, EVENT_MAPCHANGE_NewGameStartEvent, EVENT_MAPCHANGE_CreateNewGameStartEvent, EVENT_MAPCHANGE_RefreshUnionInfo, EVENT_MAPCHANGE_ContinueEvent, EVENT_MAPCHANGE_CreateContinueEvent, EVENT_MAPCHANGE_CheckSeasonChange, EVENT_MAPCHANGE_SetupExitEntranceParam, EVENT_MAPCHANGE_SetupEnterEntranceParam, EVENT_MAPCHANGE_ChangeFieldEvent, EVENT_MAPCHANGE_CreateChangeFieldEvent, EVENT_MAPCHANGE_EntranceEvent, EVENT_MAPCHANGE_EntranceCommEvent, EVENT_MAPCHANGE_DetachedTailEvent, EVENT_MAPCHANGE_FadeEvent, EVENT_MAPCHANGE_FadeDelayedEvent, EVENT_MAPCHANGE_TargetPositionEvent, EVENT_MAPCHANGE_SeasonEffectAEvent, EVENT_MAPCHANGE_SeasonEffectBEvent, EVENT_MAPCHANGE_ResetPlayerFormEvent, EVENT_MAPCHANGE_FadeWaitEvent, EVENT_MAPCHANGE_FadeDetachEvent, EVENT_MAPCHANGE_EffectCEvent, EVENT_MAPCHANGE_SwapCommOverlayEvent, EVENT_MAPCHANGE_RunFixedZoneEvent, EVENT_MAPCHANGE_InitWork, EVENT_MAPCHANGE_CreateWarpEvent, EVENT_MAPCHANGE_CreateRailWarpEvent, EVENT_MAPCHANGE_CreateRailWarpEventWithTransition, EVENT_MAPCHANGE_CreateWarpEventWithTargetPos, EVENT_MAPCHANGE_CreateDigEscapeEvent, EVENT_MAPCHANGE_CreateEscapeRopeEvent, EVENT_MAPCHANGE_CreateSituationWarpEvent, EVENT_MAPCHANGE_CreateSpecialLocationWarpEvent, EVENT_MAPCHANGE_CreateZoneStartWarpEvent, EVENT_MAPCHANGE_CreateFixedExitTypeWarpEvent, EVENT_MAPCHANGE_CreateFixedZoneEvent, EVENT_MAPCHANGE_CreateSpecialLocationEvent, EVENT_MAPCHANGE_CreateIntrudeWarpEvent, EVENT_MAPCHANGE_CreateIntrudeReturnEvent, EVENT_MAPCHANGE_GetCurrentLocation, EVENT_MAPCHANGE_CreateExitWarpEvent, EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate, EVENT_MAPCHANGE_CreateWarpEventWithTransition, EVENT_MAPCHANGE_CreateWarpEventDefaultTransition, EVENT_MAPCHANGE_CreateWarpEventToLocation, EVENT_MAPCHANGE_CreateWarpEventPlain, EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset, EVENT_MAPCHANGE_InitFieldFromSituationWarp, EVENT_MAPCHANGE_RunSituationWarpArrivalEvent, EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent, EVENT_MAPCHANGE_DirToAngle, EVENT_MAPCHANGE_ResolveLocation, EVENT_MAPCHANGE_ApplyLocation, EVENT_MAPCHANGE_AddEventDataMmdl, EVENT_MAPCHANGE_AddWfbcMmdl, EVENT_MAPCHANGE_DeleteAllMmdl, EVENT_MAPCHANGE_ReloadMmdl, EVENT_MAPCHANGE_SetMapEffectMask, EVENT_MAPCHANGE_UpdateFieldStateForZone, EVENT_MAPCHANGE_DeleteAllMmdlOfSystem, EVENT_MAPCHANGE_SetPlayerVanish, EVENT_MAPCHANGE_ApplyZoneTableEntry, EVENT_MAPCHANGE_CreateIntrudeSessionEvent, EVENT_MAPCHANGE_CreateIntrudeArriveEvent, EVENT_MAPCHANGE_RunIntrudeArriveEvent, EVENT_MAPCHANGE_RunIntrudeSessionEvent, EVENT_MAPCHANGE_UpdateEscapeLocation, EVENT_MAPCHANGE_CopySpecialLocation, EVENT_MAPCHANGE_ResetPlayerObjectCode, EVENT_MAPCHANGE_AddPresetMail, EVENT_MAPCHANGE_StartSeasonEffect, EVENT_MAPCHANGE_TamperLeakA, EVENT_MAPCHANGE_TamperLeakB, EVENT_MAPCHANGE_NopHook
 * address:  0x02183B60
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GX_SetBankForLCDC  0x0208068C  arm
 *   MIi_CpuClearFast  0x02082AC0  arm
 *   GX_DisableBankForLCDC  0x02080B98  arm
 *   COMM_PLAYER_SUPPORT_GetSeasonFromClock  0x0202E888  thumb
 *   GAME_DATA_GetSeason  0x02012984  thumb
 *   EL_SCOREBOARD_StartStandalone  0x02187808  thumb  ov020
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   EVENT_FIELD_PROCLINK_CreateCommExitEvent  0x02161B90  thumb  ov010
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   GAME_EVENT_Create 0x020122C0 thumb
 *   GAME_EVENT_GetWork 0x020124E8 thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   FIELD_WFBC_DATA_LOCAL_Init  0x021860D4  thumb  ov020
 *   EVENT_FIELD_PROCLINK_ApplyZoneChangeEnable  0x02161D64  thumb  ov010
 *   GAME_DATA_GetMusicalShotExtraData  0x020127F0  thumb
 *   EVENT_FIELD_PROCLINK_GetReturnInfo  0x02161F14  thumb  ov010
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   SCRIPT_SYS_RunInitScript  0x02158A10  thumb  ov010
 *   FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx  0x02029DF4  thumb
 *   FIELD_SOUND_SYSTEM_StartChangeTask  0x020298A0  thumb
 *   FIELD_STATUS_CreateFieldOpenNoNotifyEvent  0x020145FC  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeIn  0x021BE92C  thumb  ov021
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_ShowForZone  0x021BC578  thumb  ov021
 *   ZONEDATA_SetGameStartLocation  0x02014264  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   CONSOLE_STAMP_GetFromSave  0x02008B08  thumb
 *   CONSOLE_STAMP_SetIdentity  0x02008B20  thumb
 *   PALANM_StartTimer  0x02021444  thumb
 *   GAME_DATA_GetMoveModelSys  0x02012B38  thumb
 *   FIELD_STATUS_SetContinueFlag  0x0201445C  thumb
 *   GAME_DATA_GetSpecialLocation  0x02012894  thumb
 *   GAME_BEACON_SetZone  0x0202735C  thumb
 *   FIELD_CLOCK_Update  0x02168EEC  thumb  ov010
 *   FIELD_MAP_CHANGE_MoveActiveEntries  0x02164474  thumb  ov010
 *   WEATHER_RefreshStoredWeatherId  0x0202C860  thumb
 *   ZONEDATA_GetMapSubType  0x0201405C  thumb
 *   GAME_DATA_GetOccupyInfo  0x02012964  thumb
 *   FLDMMDL_SysLoadObjCodeParamCache  0x0216E29C  thumb  ov010
 *   FLDMMDL_ClearObjCodeParamCache  0x0216CCCC  thumb  ov010
 *   ZONEDATA_GetEventWorkAddress  0x020143CC  thumb
 *   SCRIPT_SYS_CallScriptEvent  0x02158780  thumb  ov010
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   ZONEDATA_ResetEventFlag  0x0201433C  thumb
 *   POKEPARTY_GetSaveData  0x0201AD0C  thumb
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   CONSOLE_STAMP_IsThisConsole  0x02008B4C  thumb
 *   CONSOLE_STAMP_IsRtcOffsetCurrent  0x02008B78  thumb
 *   CONSOLE_STAMP_GetDailyClock  0x02008B14  thumb
 *   DAILY_CLOCK_Refill  0x02008C00  thumb
 *   FORMCHANGE_RevertShayminAndRegister  0x0216A390  thumb  ov010
 *   GF_STANDARD_GetRtcTimestamp  0x0203F524  arm
 *   MISC_SetLastTime  0x0200C384  thumb
 *   FORMCHANGE_UpdateSeasonForms  0x0216AAE4  thumb  ov010
 *   COMM_PLAYER_SUPPORT_IsSeasonChanged  0x0202E848  thumb
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   ZONEDATA_GetAreaId  0x02013B38  thumb
 *   ZONEDATA_CreateAreaData  0x0201407C  thumb
 *   ZONEDATA_GetAreaInnerOuter  0x020140D8  thumb
 *   ZONEDATA_DeleteAreaData  0x020140B4  thumb
 *   EVENT_FIELDMAP_CONTROL_GetExitEffect  0x021BE89C  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_GetEntranceEffect  0x021BE8B8  thumb  ov021
 *   COMM_PLAYER_SUPPORT_NextSeason   0x0202E8A4  thumb
 *   GAME_DATA_GetEventData  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 *   ov230_id       0x000000E6  data
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   FIELD_STATUS_SwapSeasonDispFlag  0x0201447C  thumb
 *   FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent  0x02014554  thumb
 *   GF_OVERLAY_Load  0x02034AC4  arm
 *   GF_OVERLAY_Unload  0x02034A5C  arm
 *   ZONEDATA_IsNoGameEventZone  0x02013D34  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   OV230_CallSealedBody0  0x021882A0  arm  ov230d
 *   OV230_CallSealedBody2  0x02188318  arm  ov230d
 *   OV230_CallSealedBody5  0x021883CC  arm  ov230d
 *   COMM_PLAYER_SUPPORT_SetSeason  0x0202E8CC  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   FORMCHANGE_RevertShayminAtNight  0x0216A358  thumb  ov010
 *   FIELD_MAP_CHANGE_ResetGimmickStateCase1  0x02164454  thumb  ov010
 *   FIELD_MAP_CHANGE_ResetGimmickStateCase3  0x0216445C  thumb  ov010
 *   FIELD_MAP_CHANGE_ResetGimmickStateCase2  0x02164464  thumb  ov010
 *   INTRUDE_COMM_ClearHoldMode  0x0215874C  thumb  ov010
 *   FIELD_SOUND_SYSTEM_StartWaitSettledTask  0x02029C64  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   EVENT_ENTRANCE_IN_Create  0x021BD648  thumb  ov021
 *   EVENT_ENTRANCE_OUT_Create  0x021BD9BC  thumb  ov021
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   GAME_DATA_GetIntrudeIdByte  0x0215841C  thumb  ov010
 *   INTRUDE_COMM_SendUnionInfoRequest  0x021746AC  thumb  ov011
 *   INTRUDE_COMM_GetUnionInfoReceived  0x02158428  thumb  ov010
 *   GAME_DATA_GetBgmInfo  0x02012A30  thumb
 *   EVENT_FIELD_PROCLINK_CreateAnimEvent  0x02161824  thumb  ov010
 *   FIELD_SOUND_SYSTEM_PostZoneBgmReplace  0x02029D44  thumb
 *   FIELD_SOUND_SYSTEM_PostFadeIn  0x02029D7C  thumb
 *   EVENT_FIELDMAP_CONTROL_StartFadeOut  0x021BE8D4  thumb  ov021
 *   FIELD_PLACE_NAME_OnZoneChange  0x021BC550  thumb  ov021
 *   EVENT_APPEAR_CreatePlayerDrop  0x021BF58C  thumb  ov021
 *   EVENT_DISAPPEAR_CreateWalkFall  0x021BFD34  thumb  ov021
 *   EVENT_APPEAR_CreateSpinZoom  0x021BF5B4  thumb  ov021
 *   EVENT_DISAPPEAR_CreateSpinZoom  0x021BFD70  thumb  ov021
 *   EVENT_APPEAR_CreateSpinZoomAlt  0x021BF5E8  thumb  ov021
 *   EVENT_DISAPPEAR_CreateSpinZoomEffect  0x021BFDA0  thumb  ov021
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_SetPlayerObjectCode  0x02012B2C  thumb
 *   EVENT_APPEAR_CreateSpinZoomSmoke  0x021BF61C  thumb  ov021
 *   EVENT_DISAPPEAR_CreateSpinFade  0x021BFDD0  thumb  ov021
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_MANAGER_IsEmpty  0x021C6E48  thumb  ov021
 *   EVENT_DISAPPEAR_CreateRisingSpin  0x021BFE00  thumb  ov021
 *   EVENT_APPEAR_CreateDescendingSpin  0x021BF644  thumb  ov021
 *   ov011_id       0x0000000B  data  a1
 *   ov012_id       0x0000000C  data  a1
 *   UNION_MAIN_StartComm  0x02173744  thumb  ov012
 *   EVENT_APPEAR_CreateMoveAnime  0x021BF66C  thumb  ov021
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_SetEffectPaused  0x021AAAF0  thumb  ov021
 *   ZONEDATA_DirToExitDir  0x020142A4  thumb
 *   ZONEDATA_SetDirectLocation  0x02014184  thumb
 *   ZONEDATA_SetDirectRailLocation  0x020141A8  thumb
 *   GAME_DATA_GetEscapeLocation  0x020128B8  thumb
 *   GAME_DATA_GetSituationWarpId  0x02012914  thumb
 *   ZONEDATA_SetZoneStartLocation  0x02014204  thumb
 *   MAP_REPLACE_GetWarpFlagId  0x02159F94  thumb  ov010
 *   GAME_DATA_GetPlayerPosition  0x02012AA0  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetPlayerDirectionType  0x02012AE4  thumb
 *   GAME_DATA_SetSpecialLocation  0x0201289C  thumb
 *   GAME_DATA_SetWarpLocation  0x020128E4  thumb
 *   INTRUDE_GetFromSave  0x0200BE48  thumb
 *   GAME_DATA_GetPlayTime  0x02012FCC  thumb
 *   INTRUDE_UpdatePlaySeconds  0x0200BFA4  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   INTRUDE_COMM_HasUnlockFlags  0x02158590  thumb  ov010
 *   INTRUDE_COMM_GetRequesterNetId  0x02176230  thumb  ov011
 *   GAME_DATA_GetWarpLocation  0x020128DC  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_COMM_ClearCounter  0x02026484  thumb
 *   GAME_DATA_SetIntrudeCount  0x02012B78  thumb
 *   GAME_DATA_SetOwnNetId  0x02012B64  thumb
 *   GAME_DATA_SetIntrudeId  0x02012B8C  thumb
 *   GAME_DATA_SetEnterMode  0x02012B4C  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_CheckFormModel  0x021A3238  thumb  ov021
 *   INTRUDE_FIELD_ChangePlayerLook  0x0217BCDC  thumb  ov018
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_GetNogridNextRailLocation  0x021A36BC  thumb  ov021
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   GAME_DATA_GetEntranceLocation  0x02012870  thumb
 *   ZONEDATA_IsFieldMatrix  0x02013E7C  thumb
 *   GAME_DATA_SetEscapeLocation  0x020128C0  thumb
 *   EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly  0x02162694  thumb  ov010
 *   EVENTDATA_SYSTEM_IsSpecialExitConnect  0x021625E8  thumb  ov010
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   MAP_REPLACE_ApplyWarpLocation  0x02159FA8  thumb  ov010
 *   FIELD_MAP_CHANGE_ResetGimmickStateCase4  0x0216446C  thumb  ov010
 *   GAMESYSTEM_GetIssSystem  0x02012134  thumb
 *   ISS_SYS_GetSwitchSys  0x0202B578  thumb
 *   ISS_SWITCH_SYS_ResetSwitch  0x0202C110  thumb
 *   EVENTDATA_SYSTEM_SetConnectExitLocation 0x021625FC thumb ov010
 *   FIELD_STATUS_SetFieldInitFlag  0x02014454  thumb
 *   GAME_DATA_SetPlayerZoneId  0x02012AC4  thumb
 *   GAME_DATA_SetPlayerDirection  0x02012ACC  thumb
 *   ZONEDATA_GetLocationPosType  0x020141DC  thumb
 *   GAME_DATA_SetPlayerPosition  0x02012A90  thumb
 *   GAME_DATA_SetPlayerRail  0x02012AA4  thumb
 *   GAME_DATA_SetPlayerMoveForm  0x02012ABC  thumb
 *   ISS_SYS_ChangeZone  0x0202B544  thumb
 *   GAME_DATA_SetStartLocation  0x02012854  thumb
 *   GAME_DATA_SetWarpId  0x02012900  thumb
 *   WEATHER_StoreZoneWeatherId  0x0202C83C  thumb
 *   MAP_REPLACE_FindFlyTargetIndex  0x02159FE0  thumb  ov010
 *   FIELD_MAP_CHANGE_SetupZone  0x021643E8  thumb  ov010
 *   MAP_REPLACE_SetArriveFlag  0x0215A014  thumb  ov010
 *   SCRIPT_SYS_RunZoneChangeScript  0x02158AE0  thumb  ov010
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   FLDMMDL_AddMmdlHeaderList  0x0216CEAC  thumb  ov010
 *   FIELD_STATUS_GetMapMode  0x0201444C  thumb
 *   GAME_DATA_GetUnionInfo  0x020127D0  thumb
 *   GAME_DATA_GetMusicalShotTitle  0x020127E0  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders  0x02186538  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CountPeople  0x02186278  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CountItemSlots  0x02186854  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders  0x021868B8  thumb  ov020
 *   FLDMMDL_DeleteAllMmdl  0x0216CF6C  thumb
 *   FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList 0x02186470 thumb ov020
 *   FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus 0x021864DC thumb ov020
 *   ZONEDATA_GetFieldSkillMapEffect 0x02013F6C thumb
 *   FIELD_STATUS_IsFlashActive 0x02014468 thumb
 *   FIELD_STATUS_SetMapEffectMask 0x0201446C thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   FIELD_STATUS_SetMapMode  0x02014450  thumb
 *   ZONEDATA_IsUnionRoom  0x02013CC8  thumb
 *   ZONEDATA_IsZone96Pair  0x02013CE0  thumb
 *   ZONEDATA_IsZone4E  0x02013DF0  thumb
 *   ZONEDATA_IsZone34  0x02013D20  thumb
 *   GAME_DATA_GetSubscreenType  0x020129AC  thumb
 *   GAME_DATA_SetSubscreenType  0x020129B8  thumb
 *   GAME_DATA_GetFieldWork  0x02012974  thumb
 *   ZONEDATA_GetMatrixId  0x02013B44  thumb
 *   EVENTDATA_SYSTEM_Load  0x02162408  thumb  ov010
 *   MAP_MATRIX_Load  0x02159B94  thumb  ov010
 *   MAP_MATRIX_ApplyReplace  0x02159CC4  thumb  ov010
 *   FLDMMDL_SetStatusBitVanish 0x0216DAC8 thumb ov010
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_Reset  0x0200B37C  thumb
 *   GIMMICK_WORK_InitWithId  0x0200B394  thumb
 *   ARC_TOOL_CreateHandle  0x020490F4  arm
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm
 *   ARC_TOOL_GetHandleMemberSize  0x020493D4  arm
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELDMAP_GetEncEff  0x02189A08  thumb  ov021
 *   ENCEFF_Start  0x021CF498  thumb  ov021
 *   EVENT_FIELDMAP_CONTROL_CreateFadeInEventWithBgRestore  0x021BE9F0  thumb  ov021
 *   INTRUDE_FIELD_IsStartRequested  0x0217C070  thumb  ov018
 *   INTRUDE_COMM_GetRequestState  0x02158630  thumb  ov010
 *   FIELD_CheckPlayerPositionFree  0x021D2750  thumb  ov021
 *   INTRUDE_COMM_SetSuspended  0x0217574C  thumb  ov011
 *   INTRUDE_COMM_SetIntrudeId  0x02175710  thumb  ov011
 *   INTRUDE_COMM_AcceptSession  0x02175B4C  thumb  ov011
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GAME_DATA_GetStartLocation  0x0201284C  thumb
 *   ZONEDATA_IsParentZoneD6  0x02014068  thumb
 *   ZONEDATA_IsWeatherEnabled  0x02013C50  thumb
 *   ZONEDATA_IsZoneInTableDFDC 0x02013FEC thumb
 *   GAME_DATA_GetPlayerObjectCode 0x02012B28 thumb
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_ToChars  0x02045A38  arm
 *   MAIL_Create  0x02008F08  thumb
 *   MAIL_SetWriterName  0x02008F88  thumb
 *   MAIL_SetGender  0x02008FA0  thumb
 *   MAIL_SetDesign  0x02008FA8  thumb
 *   MAIL_SetLanguage  0x02008FB4  thumb
 *   MAIL_SetVersion  0x02008FBC  thumb
 *   MAIL_SetMessage  0x02008FD8  thumb
 *   MAIL_SetMessageId  0x02008FC4  thumb
 *   MAIL_GetBox  0x02008FEC  thumb
 *   MAIL_SetSlot  0x0200903C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   d_02187DA4  0x02187DA4  data  ov020  a4
 *   d_02187DAC  0x02187DAC  data  ov020  a4
 *   d_02187DB4  0x02187DB4  data  ov020  a4
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   d_02187EA0 0x02187EA0 data ov020 a1
 *   _u32_div_f     0x0209C2B0  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */
#include "../types.h"

#include "../version.h"
#include "event_mapchange_types.h"

struct GameSystem;
struct GameEvent;
struct GameData;
struct FieldMap;
struct GameComm;
struct EventWork;
struct SaveControl;
struct MiscSave;
struct AreaData;
struct FieldSoundSystem;
struct PlaceNameSys;
struct ConsoleInfo;
struct ConsoleInfoSession;

/* How the game starts (GameInitWork.mode). */
enum {
    GAMEINIT_MODE_FIRST = 0,    /* first start: season setup, opening, then the new game start */
    GAMEINIT_MODE_CONTINUE = 1, /* load a save */
    GAMEINIT_MODE_DEBUG = 2     /* straight to the new game start location */
};

/* Start request handed in by the boot code (also kept in the game system global). */
typedef struct GameInitWork {
    int mode;
    u32 position[3];
    u16 zoneId;
    u16 direction;
} GameInitWork;

/* Work of the first start event. */
typedef struct FirstStartWork {
    struct GameSystem *gameSystem;
    GameInitWork *initWork;
} FirstStartWork;

/* Work of the new game start event (0x24 bytes). */
typedef struct NewGameStartWork {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    Location startLocation;
} NewGameStartWork;

/* Work of the continue event (0x10 bytes). */
typedef struct ContinueWork {
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    u16 zoneId;
    u8 pad0A[2];
    int useSpecialLocation;     /* event flag 0x966 was set when the save was written */
} ContinueWork;

/* Work of the change field event: only points back at the map change work. */
typedef struct ChangeFieldWork {
    MapChangeWork *mapChange;
} ChangeFieldWork;

/* Opaque record of the arc 0x65 table (entry: zone id, save slot). */
typedef struct {
    int zoneId;
    u16 value;
    u16 unused06;
} ZoneTableEntry;

struct MsgData;
struct Strbuf;
struct Mail;

extern struct GameData *GAMESYSTEM_GetGameData(struct GameSystem *gameSystem);
extern void GX_SetBankForLCDC(int a);
extern void MIi_CpuClearFast(int v, u32 a, u32 b);
extern void GX_DisableBankForLCDC(void);
extern int COMM_PLAYER_SUPPORT_GetSeasonFromClock(void);
extern u8 COMM_PLAYER_SUPPORT_SetSeason(s32 handle, s32 value);
extern u8 GAME_DATA_GetSeason(struct GameData *gameData);
extern struct GameEvent *EL_SCOREBOARD_StartStandalone(struct GameSystem *gameSystem, int fromSeason, int toSeason);
extern void GAME_EVENT_CallEvent(struct GameEvent *parent, struct GameEvent *child);
extern struct GameEvent *EVENT_FIELD_PROCLINK_CreateCommExitEvent(struct GameSystem *gameSystem, struct GameEvent *parent, int kind, int sub, int flag);
extern void GAME_EVENT_ChangeEvent(struct GameEvent *event, struct GameEvent *newEvent);
extern struct GameEvent *GAME_EVENT_Create(struct GameSystem *gameSystem, struct GameEvent *parent, void *callback, u32 workSize);
extern void *GAME_EVENT_GetWork(struct GameEvent *event);
struct UnionInfo;
struct UnionInfo *GAME_DATA_GetSecondUnionInfo(GameData *gameData);
struct MyStatus;
extern struct MyStatus *GAME_DATA_GetMyStatus(struct GameData *gameData);
struct WfbcData;
extern void FIELD_WFBC_DATA_LOCAL_Init(struct WfbcData *data, struct MyStatus *myStatus, s32 heapSeed);
struct ZoneFlagSetting;
extern int EVENT_FIELD_PROCLINK_ApplyZoneChangeEnable(struct ZoneFlagSetting *setting);
extern u8 *GAME_DATA_GetMusicalShotExtraData(struct GameData *gameData);
struct ProcLinkRequest;
extern void EVENT_FIELD_PROCLINK_GetReturnInfo(u16 *result, struct ProcLinkRequest *request, s32 variant);
extern void *GAME_DATA_GetEventWork(struct GameData *gameData);
extern void SCRIPT_SYS_RunInitScript(void *fieldSys, s32 reserved);
void EVENT_MAPCHANGE_UpdateFieldStateForZone(GameSystem *gameSystem, int zoneId);
void EVENT_MAPCHANGE_ApplyLocation(GameSystem *gameSystem, Location *warpLocation);
extern unsigned int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(struct GameData *gameData, unsigned int zoneId, unsigned int season);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartChangeTask(struct GameSystem *gameSystem, u32 bgmId, u32 b, u32 frames);
extern struct GameEvent *FIELD_STATUS_CreateFieldOpenNoNotifyEvent(struct GameSystem *gameSystem);
extern void *GAMESYSTEM_GetFieldMap(struct GameSystem *gameSystem);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeIn(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effect, int d, int e, u8 fromSeason, u8 toSeason);
struct FieldPlaceName;
extern struct FieldPlaceName *FIELDMAP_GetPlaceName(struct FieldMap *fieldMap);
extern void FIELD_PLACE_NAME_ShowForZone(struct FieldPlaceName *placeName, s32 zoneId);
extern void ZONEDATA_SetGameStartLocation(Location *location);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
struct ConsoleStamp;
extern struct ConsoleStamp *CONSOLE_STAMP_GetFromSave(struct SaveControl *saveControl);
extern void CONSOLE_STAMP_SetIdentity(struct ConsoleStamp *stamp);
extern void PALANM_StartTimer(void);
void EVENT_MAPCHANGE_AddPresetMail(GameData *gameData);
extern void *GAME_DATA_GetMoveModelSys(GameData *gameData);
struct FieldStatus;
extern void FIELD_STATUS_SetContinueFlag(struct FieldStatus *fs, u8 continueFlag);
extern Location *GAME_DATA_GetSpecialLocation(struct GameData *gameData);
void EVENT_MAPCHANGE_DeleteAllMmdlOfSystem(GameSystem *gameSystem);
void EVENT_MAPCHANGE_StartSeasonEffect(GameData *gameData);
extern void GAME_BEACON_SetZone(u32 zoneId, u32 zoneSource);
extern void FIELD_CLOCK_Update(struct GameData *gameData);
extern void FIELD_MAP_CHANGE_MoveActiveEntries(void *object, s32 unused);
extern void WEATHER_RefreshStoredWeatherId(u8 *gameData, s32 zoneId);
extern u8 ZONEDATA_GetMapSubType(u32 zoneId);
extern void *GAME_DATA_GetOccupyInfo(GameData *gameData);
extern void FLDMMDL_SysLoadObjCodeParamCache(MmdlSys *mmdlSys, int objCodeSet);
extern void FLDMMDL_ClearObjCodeParamCache(MmdlSys *mmdlSys);
extern u16 *ZONEDATA_GetEventWorkAddress(struct EventWork *eventWork, u32 workId);
extern void *SCRIPT_SYS_CallScriptEvent(void *parentEvent, u16 scriptId, void *target, void *parentWork, u16 reserved);
extern u32 ZONEDATA_CheckEventFlag(struct EventWork *eventWork, s32 flagId);
extern void ZONEDATA_ResetEventFlag(struct EventWork *eventWork, int flagId);
struct Party;
extern struct Party *POKEPARTY_GetSaveData(struct SaveControl *saveControl);
extern void *GAME_DATA_GetMiscSave(struct GameData *gameData);
extern int CONSOLE_STAMP_IsThisConsole(struct ConsoleStamp *stamp);
extern int CONSOLE_STAMP_IsRtcOffsetCurrent(struct ConsoleStamp *stamp);
extern struct ConsoleInfoSession *CONSOLE_STAMP_GetDailyClock(struct SaveControl *saveControl);
extern void DAILY_CLOCK_Refill(struct ConsoleInfoSession *session);
extern void FORMCHANGE_RevertShayminAndRegister(struct GameData *gameData, void *party);
extern u64 GF_STANDARD_GetRtcTimestamp();
extern void MISC_SetLastTime(struct MiscSave *miscSave, u32 lo, u32 hi);
extern void FORMCHANGE_UpdateSeasonForms(struct GameData *gameData, struct Party *party, s32 season);
struct PlayerInfo;
extern int COMM_PLAYER_SUPPORT_IsSeasonChanged(struct PlayerInfo *info, u16 *outStored, u16 *outCurrent);
extern u32 ZONEDATA_GetAreaId(u32 zoneId);
u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern struct AreaData *ZONEDATA_CreateAreaData(int heapId, int areaId, int c);
extern u8 ZONEDATA_GetAreaInnerOuter(struct AreaData *areaData);
extern u32 ZONEDATA_DeleteAreaData(struct AreaData *areaData);
extern int EVENT_FIELDMAP_CONTROL_GetExitEffect(int fromZone, u32 toZone);
extern int EVENT_FIELDMAP_CONTROL_GetEntranceEffect(int fromZone, int toZone);
extern u8 COMM_PLAYER_SUPPORT_NextSeason(u8 a);
extern void *GAME_DATA_GetEventData(GameData *gameData);
extern void *EVENTDATA_SYSTEM_GetConnectData(EventData *eventData, u16 exitId);
struct ConnectData;
extern u8 EVENTDATA_SYSTEM_GetConnectExitType(struct ConnectData *connect);
extern struct GameComm *GAMESYSTEM_GetGameComm(struct GameSystem *gameSystem);
extern u8 FIELD_STATUS_SwapSeasonDispFlag(FieldStatus *fieldStatus, u8 value);
extern struct GameEvent *FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern int GF_OVERLAY_Load(int id);
extern void GF_OVERLAY_Unload(int handle);
extern u32 ZONEDATA_IsNoGameEventZone(u32 zoneId);
extern u32 GAME_COMM_GetKind(struct GameComm *gameComm);
extern void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
void *EVENT_MAPCHANGE_TamperLeakA(void);
void *EVENT_MAPCHANGE_TamperLeakB(void);
void EVENT_MAPCHANGE_NopHook(void);
extern u32 OV230_CallSealedBody0(void (*hook)(void), void (*hookArg)(void), u32 unused);
extern u32 OV230_CallSealedBody2(void (*hook)(void), void (*hookArg)(void), u32 unused);
extern u32 OV230_CallSealedBody5(void (*hook)(void), void (*hookArg)(void), u32 unused);
extern void *GAME_DATA_GetMyParty(struct GameData *gameData);
extern int FORMCHANGE_RevertShayminAtNight(struct GameData *gameData, struct Party *party, u32 *hour, s32 season);
extern int FIELD_MAP_CHANGE_ResetGimmickStateCase1(s32 object, s32 unused);
extern int FIELD_MAP_CHANGE_ResetGimmickStateCase3(s32 object, s32 unused);
extern int FIELD_MAP_CHANGE_ResetGimmickStateCase2(s32 object, s32 unused);
extern void INTRUDE_COMM_ClearHoldMode(struct GameComm *gameComm);
extern struct GameEvent *FIELD_SOUND_SYSTEM_StartWaitSettledTask(struct GameSystem *gameSystem);
struct MmdlSys;
extern struct MmdlSys *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern void FLDMMDL_SysPauseMove(struct MmdlSys *sys);
extern struct GameEvent *EVENT_ENTRANCE_IN_Create(EntranceParam *param);
extern struct GameEvent *EVENT_ENTRANCE_OUT_Create(EntranceParam *param);
extern IntrudeComm *INTRUDE_COMM_GetWorkIfRunning(GameComm *gameComm);
extern void FLDMMDL_SysResumeMove(struct MmdlSys *sys);
extern int ZONEDATA_IsZoneInTableDFC0(int zoneId);
extern u8 GAME_DATA_GetIntrudeIdByte(struct GameData *gameData);
struct IntrudeCommSys;
extern int INTRUDE_COMM_SendUnionInfoRequest(struct IntrudeCommSys *work, u8 netId);
extern u8 INTRUDE_COMM_GetUnionInfoReceived(struct IntrudeCommSys *work);
extern u32 GAME_DATA_GetBgmInfo(struct GameData *gameData);
extern struct GameEvent *EVENT_FIELD_PROCLINK_CreateAnimEvent(struct GameSystem *gameSystem, void *fieldMap);
extern void FIELD_SOUND_SYSTEM_PostZoneBgmReplace(struct FieldSoundSystem *fieldSound, struct GameData *gameData, u16 zoneId, u8 season);
extern void FIELD_SOUND_SYSTEM_PostFadeIn(struct FieldSoundSystem *fieldSound, struct GameData *gameData);
extern struct GameEvent *EVENT_FIELDMAP_CONTROL_StartFadeOut(struct GameSystem *gameSystem, struct FieldMap *fieldMap, int effect, int d);
extern void FIELD_PLACE_NAME_OnZoneChange(struct FieldPlaceName *placeName, s32 zoneId);
extern struct GameEvent *EVENT_APPEAR_CreatePlayerDrop(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *EVENT_DISAPPEAR_CreateWalkFall(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, const VecFx32 *targetPos);
void EVENT_MAPCHANGE_ResetPlayerObjectCode(GameData *gameData);
extern struct GameEvent *EVENT_APPEAR_CreateSpinZoom(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, int seasonChanged, int fromSeason, int toSeason);
extern struct GameEvent *EVENT_DISAPPEAR_CreateSpinZoom(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, int seasonChanged);
extern struct GameEvent *EVENT_APPEAR_CreateSpinZoomAlt(struct GameEvent *parent, struct GameSystem *gameSystem, struct FieldMap *fieldMap, s32 showSeasonScoreboard, s32 seasonShown, s32 seasonTarget);
extern struct GameEvent *EVENT_DISAPPEAR_CreateSpinZoomEffect(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, int seasonChanged);
extern void *GAME_DATA_GetMyPlayerWork(struct GameData *gameData);
extern void GAME_DATA_SetPlayerObjectCode(void *playerWork, u32 objectCode);
extern struct GameEvent *EVENT_APPEAR_CreateSpinZoomSmoke(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *EVENT_DISAPPEAR_CreateSpinFade(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap, int arg);
struct FieldTaskManager;
extern struct FieldTaskManager *FIELDMAP_GetTaskManager(struct FieldMap *fieldMap);
extern int FIELD_TASK_MANAGER_IsEmpty(struct FieldTaskManager *manager);
extern struct GameEvent *EVENT_DISAPPEAR_CreateRisingSpin(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap);
extern struct GameEvent *EVENT_APPEAR_CreateDescendingSpin(struct GameEvent *event, struct GameSystem *gameSystem, struct FieldMap *fieldMap);

struct GameEvent *EVENT_MAPCHANGE_CreateFirstStartEvent(struct GameSystem *gameSystem, GameInitWork *initWork);
struct GameEvent *EVENT_MAPCHANGE_CreateContinueEvent(struct GameSystem *gameSystem, GameInitWork *initWork);
extern struct GameEvent *EVENT_MAPCHANGE_CreateNewGameStartEvent();
struct GameEvent *EVENT_MAPCHANGE_CreateChangeFieldEvent(MapChangeWork *work, int changeKind);
void UNION_MAIN_StartComm(GameSystem *gameSystem);
GameEvent *EVENT_APPEAR_CreateMoveAnime(GameEvent *parent, GameSystem *gameSystem, FieldMap *fieldMap);
u16 FIELDMAP_GetZoneId(FieldMap *fieldMap);
struct FieldEncount;
struct FieldEncount *FIELDMAP_GetEncount(FieldMap *fieldMap);
void EFFECT_ENCOUNT_SetEffectPaused(struct FieldEncount *encount, s32 paused);
u32 ZONEDATA_DirToExitDir(u32 dir);
void ZONEDATA_SetDirectLocation(Location *location, int zoneId, s16 dir, int x, int y, int z);
void ZONEDATA_SetDirectRailLocation(Location *location, int zoneId, int dir, u16 railIndex, u16 lineGrid, s16 widthGrid);
Location *GAME_DATA_GetEscapeLocation(const GameData *gameData);
void EVENT_MAPCHANGE_CopySpecialLocation(GameData *gameData, Location *out);
u16 GAME_DATA_GetSituationWarpId(const GameData *gameData);
u16 MAP_REPLACE_GetWarpFlagId(int warpId);
void ZONEDATA_SetZoneStartLocation(Location *location, int zoneId);
void *GAME_DATA_GetPlayerPosition(PlayerWork *playerWork);
u16 GAME_DATA_GetPlayerZoneId(const PlayerWork *playerWork);
u32 GAME_DATA_GetPlayerDirectionType(const PlayerWork *playerWork);
void GAME_DATA_SetSpecialLocation(GameData *gameData, const Location *location);
void GAME_DATA_SetWarpLocation(GameData *gameData, const Location *location);
u16 *INTRUDE_GetFromSave(void *saveControl);
void *GAME_DATA_GetPlayTime(GameData *gameData);
u64 INTRUDE_UpdatePlaySeconds(u16 *record, void *playTime, u32 mode);
u8 GAME_DATA_GetOwnNetId(const GameData *gameData);
int INTRUDE_COMM_HasUnlockFlags(GameData *gameData);
struct IntrudeSession;
u8 INTRUDE_COMM_GetRequesterNetId(struct IntrudeCommSys *w, struct IntrudeSession *session);
Location *GAME_DATA_GetWarpLocation(GameData *gameData);
u32 GAME_COMM_GetCounter(GameComm *gameComm);
void GAME_COMM_ClearCounter(GameComm *gameComm);
GameData *GAME_DATA_SetIntrudeCount(GameData *gameData, u8 value);
void GAME_DATA_SetOwnNetId(GameData *gameData, int value);
void GAME_DATA_SetIntrudeId(GameData *gameData, u32 value);
void GAME_DATA_SetEnterMode(GameData *gameData, u8 value);
struct FieldPlayer;
struct FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
int FIELD_PLAYER_CheckFormModel(struct FieldPlayer *player);
void INTRUDE_FIELD_ChangePlayerLook(struct IntrudeCommSys *work, struct GameSystem *gameSystem, s32 objCode, u8 kind, u8 flag);
u32 FIELDMAP_GetMoveKind(FieldMap *fieldMap);
void *FIELD_PLAYER_GetMmdl(void *fieldPlayer);
void FIELD_PLAYER_GetNogridNextRailLocation(struct FieldPlayer *player, void *a);
VecFx32 *FLDMMDL_GetPosPtr(void *mmdl);
Location *GAME_DATA_GetEntranceLocation(const GameData *gameData);
u32 ZONEDATA_IsFieldMatrix(u32 zoneId);
void GAME_DATA_SetEscapeLocation(GameData *gameData, const Location *location);
int EVENTDATA_SYSTEM_IsSpecialExitConnect(struct ConnectData *connect);
void EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly(struct ConnectData *connect, s32 exitInfo, s32 exitOffset);
void EVENT_MAPCHANGE_UpdateEscapeLocation(GameData *gameData, const Location *destination);
extern u32 ZONEDATA_IsEntralink(u32 zoneId);
void MAP_REPLACE_ApplyWarpLocation(s32 warpId, s32 location);
int FIELD_MAP_CHANGE_ResetGimmickStateCase4(s32 object, s32 unused);
void *GAMESYSTEM_GetIssSystem(const GameSystem *gameSystem);
void *ISS_SYS_GetSwitchSys(void *issSystem);
void ISS_SWITCH_SYS_ResetSwitch(void *issSwitchSys);
struct EventDataSystem;
extern int EVENTDATA_SYSTEM_SetConnectExitLocation(struct EventDataSystem *system, s32 *exitInfo, s32 connectIndex, s32 exitOffset);
void FIELD_STATUS_SetFieldInitFlag(FieldStatus *fieldStatus, u8 value);
PlayerWork *GAME_DATA_SetPlayerZoneId(PlayerWork *playerWork, u16 zoneId);
void GAME_DATA_SetPlayerDirection(PlayerWork *playerWork, int dir);
int ZONEDATA_GetLocationPosType(const Location *location);
struct PlayerPosition;
struct PlayerWork;
void GAME_DATA_SetPlayerPosition(struct PlayerWork *player, struct PlayerPosition *pos);
struct RailLocationWords;
void GAME_DATA_SetPlayerRail(struct PlayerWork *player, struct RailLocationWords *rail);
void GAME_DATA_SetPlayerMoveForm(PlayerWork *playerWork, u8 isRail);
void ISS_SYS_ChangeZone(void *issSystem, u16 zoneId);
void GAME_DATA_SetStartLocation(GameData *gameData, const Location *location);
void GAME_DATA_SetWarpId(const GameData *gameData, u16 warpId);
int WEATHER_StoreZoneWeatherId(int gameSystem, int zoneId);
int MAP_REPLACE_FindFlyTargetIndex(int zoneId);
void FIELD_MAP_CHANGE_SetupZone(struct GameData *gameData, u32 zoneId);
void MAP_REPLACE_SetArriveFlag(void *gameData, s32 zoneId);
void SCRIPT_SYS_RunZoneChangeScript(void *fieldSys, s32 reserved);
u16 EVENTDATA_SYSTEM_GetNpcCount(struct EventDataSystem *system);
u32 EVENTDATA_SYSTEM_GetNpcHeaders(struct EventDataSystem *system);
struct MmdlHeader;
void FLDMMDL_AddMmdlHeaderList(struct MmdlSys *sys, struct MmdlHeader *header, s32 zoneId, u32 count, void *evWork);
u32 FIELD_STATUS_GetMapMode(FieldStatus *fieldStatus);
u8 *GAME_DATA_GetUnionInfo(GameData *gameData, u32 index);
u16 *GAME_DATA_GetMusicalShotTitle(GameData *gameData);
u32 GFL_HEAP_Free(void *memory);
struct MmdlHeader *FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders(struct WfbcData *data, s32 which, s32 heapSeed);
int FIELD_WFBC_DATA_LOCAL_CountPeople(struct WfbcData *data, s32 which);
int FIELD_WFBC_DATA_LOCAL_CountItemSlots(u16 *itemSlots);
struct MmdlHeader *FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders(u16 *itemSlots, int mapMode, int index, int flag);
void FLDMMDL_DeleteAllMmdl(MmdlSys *mmdlSys);
extern void FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList(GameData *gameData);
extern void FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus(u8 *data);
extern unsigned int ZONEDATA_GetFieldSkillMapEffect(unsigned int zoneId);
extern u8 FIELD_STATUS_IsFlashActive(FieldStatus *fieldStatus);
extern void FIELD_STATUS_SetMapEffectMask(FieldStatus *fieldStatus, unsigned int mask);
int GAME_DATA_GetIntrudeCount(const GameData *gameData);
void FIELD_STATUS_SetMapMode(FieldStatus *fieldStatus, u32 mapMode);
u32 ZONEDATA_IsUnionRoom(u32 zoneId);
u32 ZONEDATA_IsZone96Pair(u32 zoneId);
u32 ZONEDATA_IsZone4E(u32 zoneId);
u32 ZONEDATA_IsZone34(u32 zoneId);
u8 GAME_DATA_GetSubscreenType(const GameData *gameData);
void GAME_DATA_SetSubscreenType(GameData *gameData, u32 subscreenType);
u32 GAME_DATA_GetFieldWork(const GameData *gameData);
u32 ZONEDATA_GetMatrixId(u32 zoneId);
int EVENTDATA_SYSTEM_Load(int eventData, int zoneId, int season);
int MAP_MATRIX_Load(int fieldWork, int matrixId, int zoneId, int heapId);
struct MapMatrix;
void MAP_MATRIX_ApplyReplace(struct MapMatrix *matrix, s32 gameSystem, s32 heapId);
struct Mmdl;
extern void FLDMMDL_SetStatusBitVanish(struct Mmdl *mmdl, s32 flag);
u8 *GAME_DATA_GetFieldSave(GameData *gameData);
struct GimmickWork;
void GIMMICK_WORK_Reset(struct GimmickWork *gimmick);
s32 *GIMMICK_WORK_InitWithId(struct GimmickWork *gimmick, s32 id);
void *ARC_TOOL_CreateHandle(u32 archiveID, u16 heapID);
struct ArcHandle;
void *ARC_TOOL_LoadHandleMember(struct ArcHandle *arc, u32 memberIdx, u16 heapID);
u32 ARC_TOOL_GetHandleMemberSize(struct ArcHandle *arc, u32 memberIdx);
void ARC_TOOL_DeleteHandle(void *arcHandle);
void GFL_USE_PlaySeDefaultVolume(u32 seId);
struct EncEff;
struct EncEff *FIELDMAP_GetEncEff(FieldMap *fieldMap);
struct EncEffWork;
void ENCEFF_Start(struct EncEffWork *eff, struct GameEvent *parentEvent, s32 kind);
struct GameEvent *EVENT_FIELDMAP_CONTROL_CreateFadeInEventWithBgRestore(GameSystem *gameSystem, FieldMap *fieldMap, int a, int b, int c);
extern int INTRUDE_FIELD_IsStartRequested(struct IntrudeCommSys *work);
extern int INTRUDE_COMM_GetRequestState(GameComm *gameComm);
extern int FIELD_CheckPlayerPositionFree(GameSystem *gameSystem);
extern void INTRUDE_COMM_SetSuspended(struct IntrudeCommSys *work, u32 value);
extern void INTRUDE_COMM_SetIntrudeId(struct IntrudeCommSys *work, u32 intrudeId);
extern void INTRUDE_COMM_AcceptSession(IntrudeComm *comm, u8 *requestInfo);
extern int GFL_NET_SYSTEM_GetCurrentAid(int aidSource);
int EVENT_MAPCHANGE_EntranceEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_EntranceCommEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_DetachedTailEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_FadeEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_FadeDelayedEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_TargetPositionEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_SeasonEffectAEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_SeasonEffectBEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_ResetPlayerFormEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_FadeWaitEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_FadeDetachEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_EffectCEvent(struct GameEvent *event, int *seq, MapChangeWork *work);
int EVENT_MAPCHANGE_SwapCommOverlayEvent(struct GameEvent *event, int *seq, MapChangeWork *work);

int EVENT_MAPCHANGE_RunFixedZoneEvent(GameEvent *event, int *state, MapChangeWork *work);
void EVENT_MAPCHANGE_InitWork(MapChangeWork *work, GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateWarpEvent(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, u16 dir, int seasonFadeAllowed);
GameEvent *EVENT_MAPCHANGE_CreateRailWarpEvent(GameSystem *gameSystem, int unused, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);
GameEvent *EVENT_MAPCHANGE_CreateRailWarpEventWithTransition(GameSystem *gameSystem, int unused, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventWithTargetPos(GameSystem *gameSystem, int unused, const VecFx32 *targetPos, s16 zoneId, const VecFx32 *pos);
GameEvent *EVENT_MAPCHANGE_CreateDigEscapeEvent(int unused, GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateEscapeRopeEvent(GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateSituationWarpEvent(GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateSpecialLocationWarpEvent(GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateZoneStartWarpEvent(GameSystem *gameSystem, u16 zoneId);
GameEvent *EVENT_MAPCHANGE_CreateFixedExitTypeWarpEvent(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, u16 dir);
GameEvent *EVENT_MAPCHANGE_CreateFixedZoneEvent(GameSystem *gameSystem);
GameEvent *EVENT_MAPCHANGE_CreateSpecialLocationEvent(GameSystem *gameSystem, u8 *unusedPos);
GameEvent *EVENT_MAPCHANGE_CreateIntrudeWarpEvent(GameSystem *gameSystem, int zoneId, VecFx32 *pos, int requestSession);
GameEvent *EVENT_MAPCHANGE_CreateIntrudeReturnEvent(GameSystem *gameSystem);
void EVENT_MAPCHANGE_GetCurrentLocation(Location *location, FieldMap *fieldMap);
GameEvent *EVENT_MAPCHANGE_CreateExitWarpEvent(GameSystem *gameSystem, int unused, void *connectData, int exitDir);
GameEvent *EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate(GameSystem *gameSystem, int unused, void *connectData, int exitDir);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventWithTransition(GameSystem *gameSystem, int unused, int transitionType, s16 zoneId, const VecFx32 *pos, u16 dir);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(GameSystem *gameSystem, int unused, s16 zoneId, const VecFx32 *pos, u16 dir);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventToLocation(GameSystem *gameSystem, int unused, int unused2, const Location *location, u16 dir);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventPlain(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, short dir);
GameEvent *EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(GameSystem *gameSystem, u16 zoneId, const VecFx32 *pos);
void EVENT_MAPCHANGE_InitFieldFromSituationWarp(GameSystem *gameSystem);
int EVENT_MAPCHANGE_RunSituationWarpArrivalEvent(GameEvent *event, int *state, WarpIdArrivalWork *work);
GameEvent *EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent(GameSystem *gameSystem);
int EVENT_MAPCHANGE_DirToAngle(int dir);
void EVENT_MAPCHANGE_ResolveLocation(EventData *eventData, Location *source, Location *dest);
void EVENT_MAPCHANGE_AddEventDataMmdl(GameData *gameData, const Location *location);
void EVENT_MAPCHANGE_AddWfbcMmdl(GameData *gameData, const Location *location);
void EVENT_MAPCHANGE_DeleteAllMmdl(GameData *gameData);
void EVENT_MAPCHANGE_ReloadMmdl(GameData *gameData, const Location *location);
void EVENT_MAPCHANGE_SetMapEffectMask(GameData *gameData, unsigned int zoneId);
void EVENT_MAPCHANGE_SetPlayerVanish(FieldMap *fieldMap, unsigned int vanish);
void EVENT_MAPCHANGE_ApplyZoneTableEntry(GameData *gameData, int zoneId);
GameEvent *EVENT_MAPCHANGE_CreateIntrudeSessionEvent(GameSystem *gameSystem, FieldMap *fieldMap, Location *location, int requestSession, int intrudeId);
GameEvent *EVENT_MAPCHANGE_CreateIntrudeArriveEvent(GameSystem *gameSystem, FieldMap *fieldMap, Location *location);
int EVENT_MAPCHANGE_RunIntrudeArriveEvent(GameEvent *event, int *state, MapChangeIntrudeWork *work);
int EVENT_MAPCHANGE_RunIntrudeSessionEvent(GameEvent *event, int *state, MapChangeIntrudeWork *work);

u32 ZONEDATA_IsParentZoneD6(u16 zoneId);
u32 ZONEDATA_IsWeatherEnabled(u32 id);
u32 ZONEDATA_IsZoneInTableDFDC(u32 id);
Location *GAME_DATA_GetStartLocation(const GameData *gameData);
u32 GAME_DATA_GetPlayerObjectCode(const PlayerWork *playerWork);
struct MsgBank;
struct MsgBank *MSGDATA_CreateFromArchive(u32 resident, u32 arcId, u32 fileId, u32 heapId);
struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
void STRBUF_ToChars(struct Strbuf *strbuf, u16 *dest, u32 length);
struct Mail *MAIL_Create(int heapId);
void MAIL_SetWriterName(struct Mail *mail, void *name);
void MAIL_SetGender(struct Mail *mail, u8 gender);
void MAIL_SetDesign(struct Mail *mail, u32 design);
void MAIL_SetLanguage(struct Mail *mail, u8 language);
void MAIL_SetVersion(struct Mail *mail, u8 version);
void MAIL_SetMessage(struct Mail *mail, const void *message, u32 index);
void MAIL_SetMessageId(struct Mail *mail, u16 messageId);
struct MailBox;
struct MailBox *MAIL_GetBox(struct GameData *gameData);
void MAIL_SetSlot(struct Mail *box, u32 unused, int slot, const struct Mail *src);
void STRBUF_Delete(struct Strbuf *strbuf);
u32 MSGDATA_Delete(struct MsgBank *bank);
void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u8 ov230_id[];
extern char ov011_id[];
extern char ov012_id[];
extern char d_02187DA4[];
extern char d_02187DAC[];
extern char d_02187DB4[];
extern char d_02187EA0[];

/* Overlay entry hook: runs the callback when one is set. */
int EVENT_MAPCHANGE_CallHookAndInvert(void (*hook)(void))
{
    if (hook)
        hook();
    return ~(int)hook;
}

/* Starts the game according to the init work mode. */
void EVENT_MAPCHANGE_CreateByMode(struct GameSystem *gameSystem, GameInitWork *initWork)
{
    switch (initWork->mode) {
    case GAMEINIT_MODE_FIRST:
        EVENT_MAPCHANGE_CreateFirstStartEvent(gameSystem, initWork);
        break;
    case GAMEINIT_MODE_CONTINUE:
        EVENT_MAPCHANGE_CreateContinueEvent(gameSystem, initWork);
        break;
    case GAMEINIT_MODE_DEBUG:
        EVENT_MAPCHANGE_CreateNewGameStartEvent(gameSystem);
        break;
    }
}

/* First start: set the season, run the opening events, then hand over to the new game start event. */
int EVENT_MAPCHANGE_FirstStartEvent(struct GameEvent *event, int *seq, FirstStartWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct GameEvent *child;
    int season;

    switch (*seq) {
    case 0:
        GX_SetBankForLCDC(0x1ff);
        MIi_CpuClearFast(0, 0x1a << 22, 0x29 << 14);
        GX_DisableBankForLCDC();
        (*seq)++;
        break;
    case 1:
        COMM_PLAYER_SUPPORT_SetSeason((s32)gameData, (u16)COMM_PLAYER_SUPPORT_GetSeasonFromClock());
        season = GAME_DATA_GetSeason(gameData);
        child = EL_SCOREBOARD_StartStandalone(gameSystem, season, season);
        GAME_EVENT_CallEvent(event, child);
        (*seq)++;
        break;
    case 2:
        child = EVENT_FIELD_PROCLINK_CreateCommExitEvent(gameSystem, event, 5, 0, 1);
        GAME_EVENT_CallEvent(event, child);
        (*seq)++;
        break;
    case 3:
        GAME_EVENT_ChangeEvent(event, EVENT_MAPCHANGE_CreateNewGameStartEvent(gameSystem, work->initWork));
        break;
    }
    return 0;
}

struct GameEvent *EVENT_MAPCHANGE_CreateFirstStartEvent(struct GameSystem *gameSystem, GameInitWork *initWork)
{
    struct GameEvent *event;
    FirstStartWork *work;

    event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_FirstStartEvent, sizeof(FirstStartWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->initWork = initWork;
    return event;
}

/* Fills the player's union room info from the own status. */
void EVENT_MAPCHANGE_InitUnionInfo(struct GameSystem *gameSystem)
{
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    void *unionInfo = GAME_DATA_GetSecondUnionInfo(gameData);
    void *recvInfo;

    FIELD_WFBC_DATA_LOCAL_Init(unionInfo, GAME_DATA_GetMyStatus(gameData), 1);
    EVENT_FIELD_PROCLINK_ApplyZoneChangeEnable((struct ZoneFlagSetting *)GAME_DATA_GetSecondUnionInfo(gameData));
    recvInfo = GAME_DATA_GetMusicalShotExtraData(gameData);
    EVENT_FIELD_PROCLINK_GetReturnInfo(recvInfo, (struct ProcLinkRequest *)GAME_DATA_GetSecondUnionInfo(gameData), 1);
}

/* New game start event: plays the start BGM, fades in and shows the place name. */
int EVENT_MAPCHANGE_NewGameStartEvent(struct GameEvent *event, int *seq, NewGameStartWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct FieldMap *fieldMap;

    GAME_DATA_GetEventWork(gameData);
    switch (*seq) {
    case 0:
        SCRIPT_SYS_RunInitScript(gameSystem, 1);
        EVENT_MAPCHANGE_UpdateFieldStateForZone(gameSystem, (u16)work->startLocation.zoneId);
        EVENT_MAPCHANGE_ApplyLocation(gameSystem, &work->startLocation);
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartChangeTask(gameSystem, FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(gameData, (s16)work->startLocation.zoneId, GAME_DATA_GetSeason(gameData)), 0, 0x3c));
        (*seq)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenNoNotifyEvent(gameSystem));
        (*seq)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 1, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 4:
        fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
        if (FIELDMAP_GetPlaceName(fieldMap) != 0)
            FIELD_PLACE_NAME_ShowForZone(FIELDMAP_GetPlaceName(fieldMap), (s16)work->startLocation.zoneId);
        return 1;
    }
    return 0;
}

struct GameEvent *EVENT_MAPCHANGE_CreateNewGameStartEvent(struct GameSystem *gameSystem)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_NewGameStartEvent, sizeof(NewGameStartWork));
    NewGameStartWork *work = GAME_EVENT_GetWork(event);

    work->gameSystem = gameSystem;
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    ZONEDATA_SetGameStartLocation(&work->startLocation);
    EVENT_MAPCHANGE_InitUnionInfo(gameSystem);
    CONSOLE_STAMP_SetIdentity(CONSOLE_STAMP_GetFromSave(GAME_DATA_GetSaveControl(work->gameData)));
    PALANM_StartTimer();
    EVENT_MAPCHANGE_AddPresetMail(work->gameData);
    GX_SetBankForLCDC(0x1ff);
    MIi_CpuClearFast(0, 0x1a << 22, 0x29 << 14);
    GX_DisableBankForLCDC();
    return event;
}

/* interface: 020127C4 forwards 020127D0's returned pointer in r0. */
void EVENT_MAPCHANGE_RefreshUnionInfo(struct GameSystem *gameSystem)
{
    EVENT_FIELD_PROCLINK_ApplyZoneChangeEnable((struct ZoneFlagSetting *)GAME_DATA_GetSecondUnionInfo(GAMESYSTEM_GetGameData(gameSystem)));
}

/* Continue event: restores the field state from the save and enters the saved map. */
int EVENT_MAPCHANGE_ContinueEvent(struct GameEvent *event, int *seq, ContinueWork *work)
{
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct EventWork *eventWork;
    Location *specialLocation;
    struct FieldMap *fieldMap;
    void *mmdlSys;
    int mapSubType;

    gameSystem = work->gameSystem;
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    eventWork = GAME_DATA_GetEventWork(gameData);

    switch (*seq) {
    case 0:
        FIELD_STATUS_SetContinueFlag(GAME_DATA_GetMoveModelSys(gameData), 1);
        if (work->useSpecialLocation != 0) {
            specialLocation = GAME_DATA_GetSpecialLocation(gameData);
            *(s16 *)&work->zoneId = *(s16 *)&specialLocation->zoneId;
            EVENT_MAPCHANGE_DeleteAllMmdlOfSystem(gameSystem);
            EVENT_MAPCHANGE_UpdateFieldStateForZone(gameSystem, work->zoneId);
            EVENT_MAPCHANGE_StartSeasonEffect(gameData);
            EVENT_MAPCHANGE_ApplyLocation(gameSystem, specialLocation);
            GAME_BEACON_SetZone((u32)specialLocation->zoneId, (u32)gameData);
        } else {
            EVENT_MAPCHANGE_UpdateFieldStateForZone(gameSystem, work->zoneId);
            EVENT_MAPCHANGE_StartSeasonEffect(gameData);
            FIELD_CLOCK_Update(gameData);
            FIELD_MAP_CHANGE_MoveActiveEntries(gameData, work->zoneId);
            WEATHER_RefreshStoredWeatherId((u8 *)gameData, work->zoneId);
            mapSubType = ZONEDATA_GetMapSubType(work->zoneId);
            mmdlSys = GAME_DATA_GetOccupyInfo(gameData);
            if (mapSubType < 16) {
                FLDMMDL_SysLoadObjCodeParamCache(mmdlSys, mapSubType);
            } else {
                FLDMMDL_ClearObjCodeParamCache(mmdlSys);
            }
        }
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartChangeTask(gameSystem, FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(gameData, work->zoneId, GAME_DATA_GetSeason(gameData)), 0, 0x3c));
        (*seq)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenNoNotifyEvent(gameSystem));
        (*seq)++;
        break;
    case 3:
        if (work->useSpecialLocation != 0 && *ZONEDATA_GetEventWorkAddress(eventWork, 0x4041) != 0) {
            SCRIPT_SYS_CallScriptEvent(event, 0x83b, 0, 0, 0x15);
        } else {
            u8 season = GAME_DATA_GetSeason(gameData);
            GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), 3, 0, 0, season, season));
        }
        (*seq)++;
        break;
    case 4:
        fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
        if (FIELDMAP_GetPlaceName(fieldMap) != 0) {
            FIELD_PLACE_NAME_ShowForZone(FIELDMAP_GetPlaceName(fieldMap), work->zoneId);
        }
        return 1;
    }
    return 0;
}

struct GameEvent *EVENT_MAPCHANGE_CreateContinueEvent(struct GameSystem *gameSystem, GameInitWork *initWork)
{
    struct GameEvent *event;
    ContinueWork *work;
    struct EventWork *eventWork;
    struct SaveControl *saveControl;
    struct ConsoleInfo *consoleInfo;
    void *partySave;
    struct MiscSave *miscSave;
    u64 nowSeconds;

    event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_ContinueEvent, sizeof(ContinueWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->zoneId = initWork->zoneId;
    eventWork = GAME_DATA_GetEventWork(work->gameData);
    work->useSpecialLocation = ZONEDATA_CheckEventFlag(eventWork, 0x966);
    ZONEDATA_ResetEventFlag(eventWork, 0x966);
    saveControl = GAME_DATA_GetSaveControl(work->gameData);
    consoleInfo = (struct ConsoleInfo *)CONSOLE_STAMP_GetFromSave(saveControl);
    partySave = POKEPARTY_GetSaveData(saveControl);
    miscSave = GAME_DATA_GetMiscSave(work->gameData);
    /* the save was written on another console or with another clock offset */
    if (!CONSOLE_STAMP_IsThisConsole((struct ConsoleStamp *)consoleInfo) || !CONSOLE_STAMP_IsRtcOffsetCurrent((struct ConsoleStamp *)consoleInfo)) {
        DAILY_CLOCK_Refill(CONSOLE_STAMP_GetDailyClock(saveControl));
        FORMCHANGE_RevertShayminAndRegister(work->gameData, partySave);
        nowSeconds = GF_STANDARD_GetRtcTimestamp();
        MISC_SetLastTime(miscSave, (u32)nowSeconds, (u32)(nowSeconds >> 32));
    }
    CONSOLE_STAMP_SetIdentity((struct ConsoleStamp *)consoleInfo);
    FORMCHANGE_UpdateSeasonForms(work->gameData, partySave, GAME_DATA_GetSeason(work->gameData));
    EVENT_MAPCHANGE_RefreshUnionInfo(gameSystem);
    PALANM_StartTimer();
    GX_SetBankForLCDC(0x1FF);
    MIi_CpuClearFast(0, 0x06800000, 0xA4000);
    GX_DisableBankForLCDC();
    return event;
}

/* Reads the season pair for the destination: when the season changed and the destination is
 * outdoors, marks the change in the work. */
void EVENT_MAPCHANGE_CheckSeasonChange(MapChangeWork *work)
{
    u16 seasons[2];
    struct AreaData *areaData;
    int outdoors;
    u16 fromSeason;

    COMM_PLAYER_SUPPORT_IsSeasonChanged((struct PlayerInfo *)work->gameData, &seasons[1], &seasons[0]);
    areaData = ZONEDATA_CreateAreaData(FIELDMAP_GetHeapId(work->fieldMap), ZONEDATA_GetAreaId(work->destination.zoneId), 0);
    outdoors = 0;
    if (ZONEDATA_GetAreaInnerOuter(areaData) != 0)
        outdoors = 1;
    ZONEDATA_DeleteAreaData(areaData);
    fromSeason = seasons[1];
    if (seasons[0] != fromSeason && outdoors) {
        work->seasonChanged = 1;
        work->fromSeason = fromSeason;
        work->toSeason = seasons[0];
    }
}

/* Fills the entrance parameters of the exit effect. */
void EVENT_MAPCHANGE_SetupExitEntranceParam(MapChangeWork *work, struct GameEvent *event)
{
    EntranceParam *entrance = &work->entrance;

    entrance->gameSystem = work->gameSystem;
    entrance->gameData = work->gameData;
    entrance->fieldMap = work->fieldMap;
    entrance->exitType = work->exitType;
    work->entrance.event = event;
    entrance->currentZoneId = work->currentZoneId;
    entrance->destination = work->destination;
    entrance->exitEffectId = EVENT_FIELDMAP_CONTROL_GetExitEffect(work->currentZoneId, work->destination.zoneId);
    entrance->entranceEffectId = EVENT_FIELDMAP_CONTROL_GetEntranceEffect(work->currentZoneId, work->destination.zoneId);
    entrance->seasonChanged = (work->seasonFadeAllowed != 0 && work->seasonChanged != 0) ? 1 : 0;
    entrance->fromSeasonIndex = COMM_PLAYER_SUPPORT_NextSeason(work->fromSeason);
    entrance->toSeason = work->toSeason;
    entrance->bgmReplaced = 0;
    entrance->bgmFadeStarted = 0;
}

/* Fills the entrance parameters of the entrance effect. */
void EVENT_MAPCHANGE_SetupEnterEntranceParam(MapChangeWork *work, struct GameEvent *event)
{
    EntranceParam *entrance = &work->entrance;

    entrance->gameSystem = work->gameSystem;
    entrance->gameData = work->gameData;
    entrance->fieldMap = work->fieldMap;
    entrance->exitType = work->exitType;
    work->entrance.event = event;
    entrance->currentZoneId = work->currentZoneId;
    entrance->destination = work->destination;
    entrance->exitEffectId = EVENT_FIELDMAP_CONTROL_GetExitEffect(work->currentZoneId, work->destination.zoneId);
    entrance->entranceEffectId = EVENT_FIELDMAP_CONTROL_GetEntranceEffect(work->currentZoneId, work->destination.zoneId);
    entrance->seasonChanged = (work->seasonFadeAllowed != 0 && work->seasonChanged != 0) ? 1 : 0;
    entrance->fromSeasonIndex = COMM_PLAYER_SUPPORT_NextSeason(work->fromSeason);
    entrance->toSeason = work->toSeason;
    if (work->destination.type == 1) {
        entrance->destExitType = 0;
        return;
    }
    entrance->destExitType = EVENTDATA_SYSTEM_GetConnectExitType(EVENTDATA_SYSTEM_GetConnectData(GAME_DATA_GetEventData(work->gameData), work->destination.exitId));
}

/* Change field event: unloads the old field, loads the new one and starts the arrival events.
 * Two spellings are load-bearing.  The u8 range check on GAME_COMM_GetKind's
 * result is `adds r0, #0xff; lsls/lsrs #0x18; cmp #1; bhi`: written
 * `(u8)(v - 1) <= 1` it compiles to `subs r0, r0, #1` (one byte out), and as
 * `switch (v) { case 1: case 2: }` it grows by 4 bytes with two compares;
 * only `(u8)(v + 0xff) <= 1` gives the add.  The dead `str r2, [sp, #0xc]`
 * after `adds r2, #0x14` is `a += 0x14;` on the spilled local before the
 * FORMCHANGE_RevertShayminAtNight call.  OV230_CallSealedBody0, 2 and 5 are slots of ov230's decrypted
 * dispatcher (ov230d token); each gets EVENT_MAPCHANGE_CallHookAndInvert as the hook and
 * one of this overlay's functions (TamperLeakA, TamperLeakB, NopHook) as the hook argument. */
int EVENT_MAPCHANGE_ChangeFieldEvent(struct GameEvent *event, int *seq, ChangeFieldWork *changeField)
{
    MapChangeWork *work;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    struct GameComm *gameComm;
    void *party;
    int season;
    int sessionPtr;

    work = changeField->mapChange;
    fieldMap = work->fieldMap;
    gameSystem = work->gameSystem;
    gameData = work->gameData;
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);

    switch (*seq) {
    case 0:
        FIELD_STATUS_SwapSeasonDispFlag(GAME_DATA_GetMoveModelSys(gameData), 2);
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldCloseNoSoundWaitEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        GF_OVERLAY_Load((int)ov230_id);
        if (ZONEDATA_IsNoGameEventZone(work->destination.zoneId) == 1 && (u8)(GAME_COMM_GetKind(gameComm) + 0xff) <= 1) {
            GAME_COMM_RequestExitNoCallback(gameComm);
            *seq = 2;
        } else {
            *seq = 3;
        }
        break;
    case 2:
        if (GAME_COMM_GetKind(gameComm) == 0) {
            *seq = 3;
        }
        break;
    case 3:
        OV230_CallSealedBody0((void (*)(void))EVENT_MAPCHANGE_CallHookAndInvert, (void (*)(void))EVENT_MAPCHANGE_TamperLeakA, 0);
        EVENT_MAPCHANGE_DeleteAllMmdlOfSystem(gameSystem);
        if (work->seasonFadeAllowed != 0 && work->seasonChanged != 0) {
            COMM_PLAYER_SUPPORT_SetSeason((s32)gameData, work->toSeason);
            sessionPtr = (int)CONSOLE_STAMP_GetDailyClock(GAME_DATA_GetSaveControl(gameData));
            season = GAME_DATA_GetSeason(gameData);
            party = GAME_DATA_GetMyParty(gameData);
            FORMCHANGE_UpdateSeasonForms(gameData, party, season);
            sessionPtr += 0x14;
            FORMCHANGE_RevertShayminAtNight(gameData, party, (u32 *)sessionPtr, season);
        }
        OV230_CallSealedBody2((void (*)(void))EVENT_MAPCHANGE_CallHookAndInvert, (void (*)(void))EVENT_MAPCHANGE_TamperLeakB, 0);
        EVENT_MAPCHANGE_UpdateFieldStateForZone(gameSystem, work->destination.zoneId);
        EVENT_MAPCHANGE_ApplyLocation(gameSystem, &work->destination);
        if (work->changeKind != 4) {
            GAME_BEACON_SetZone((u32)work->destination.zoneId, (u32)gameData);
        }
        OV230_CallSealedBody5((void (*)(void))EVENT_MAPCHANGE_CallHookAndInvert, EVENT_MAPCHANGE_NopHook, 0);
        switch (work->changeKind) {
        case 1:
            FIELD_MAP_CHANGE_ResetGimmickStateCase1((s32)gameData, work->destination.zoneId);
            break;
        case 2:
            FIELD_MAP_CHANGE_ResetGimmickStateCase2((s32)gameData, work->destination.zoneId);
            break;
        case 3:
            FIELD_MAP_CHANGE_ResetGimmickStateCase3((s32)gameData, work->destination.zoneId);
            break;
        }
        GF_OVERLAY_Unload((int)ov230_id);
        INTRUDE_COMM_ClearHoldMode(gameComm);
        (*seq)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, FIELD_STATUS_CreateFieldOpenNoNotifyEvent(gameSystem));
        (*seq)++;
        break;
    case 5:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartWaitSettledTask(gameSystem));
        (*seq)++;
        break;
    case 6:
        return 1;
    }
    return 0;
}

/* Starts the change field event as a child of the work's game system. */
struct GameEvent *EVENT_MAPCHANGE_CreateChangeFieldEvent(MapChangeWork *work, int changeKind)
{
    struct GameEvent *event;
    ChangeFieldWork *changeField;

    event = GAME_EVENT_Create(work->gameSystem, 0, EVENT_MAPCHANGE_ChangeFieldEvent, sizeof(ChangeFieldWork));
    changeField = GAME_EVENT_GetWork(event);
    changeField->mapChange = work;
    work->changeKind = changeKind;
    return event;
}

/* Map change with the entrance effects. */
int EVENT_MAPCHANGE_EntranceEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldMap *fieldMap = work->fieldMap;

    switch (*seq) {
    case 0:
        EVENT_MAPCHANGE_CheckSeasonChange(work);
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        EVENT_MAPCHANGE_SetupExitEntranceParam(work, event);
        GAME_EVENT_CallEvent(event, EVENT_ENTRANCE_IN_Create(&work->entrance));
        (*seq)++;
        return 0x21;
    case 1:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, 0));
        (*seq)++;
        break;
    case 2:
        EVENT_MAPCHANGE_SetupEnterEntranceParam(work, event);
        GAME_EVENT_CallEvent(event, EVENT_ENTRANCE_OUT_Create(&work->entrance));
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Map change with the entrance effects for zones in the table at 0209DFC0: waits for the
 * communication partner first.
 * The leaf ZONEDATA_IsZoneInTableDFC0 is `ZONEDATA_IsZoneInTable(v, tbl_0209DFC0, 4)`. */
int EVENT_MAPCHANGE_EntranceCommEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldMap *fieldMap;
    struct GameData *gameData;
    void *commHandle;

    fieldMap = work->fieldMap;
    gameData = work->gameData;
    commHandle = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(work->gameSystem));

    switch (*seq) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        if (ZONEDATA_IsZoneInTableDFC0(work->destination.zoneId) == 1) {
            *seq = 5;
        } else {
            *seq = 1;
        }
        break;
    case 1:
        EVENT_MAPCHANGE_SetupExitEntranceParam(work, event);
        GAME_EVENT_CallEvent(event, EVENT_ENTRANCE_IN_Create(&work->entrance));
        (*seq)++;
        return 0x21;
    case 2:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, 0));
        (*seq)++;
        break;
    case 3:
        EVENT_MAPCHANGE_SetupEnterEntranceParam(work, event);
        GAME_EVENT_CallEvent(event, EVENT_ENTRANCE_OUT_Create(&work->entrance));
        (*seq)++;
        break;
    case 4:
        return 1;
    case 5:
        if (commHandle == 0) {
            *seq = 7;
            break;
        }
        if (INTRUDE_COMM_SendUnionInfoRequest(commHandle, GAME_DATA_GetIntrudeIdByte(gameData)) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (commHandle == 0) {
            *seq = 7;
            break;
        }
        if (INTRUDE_COMM_GetUnionInfoReceived(commHandle) == 1) {
            *seq = 1;
        }
        break;
    case 7:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
        return 1;
    }
    return 0;
}

/* Tail of the detached map change: sound, then the change field event. */
int EVENT_MAPCHANGE_DetachedTailEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameEvent *child;
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    fieldMap = work->fieldMap;
    gameData = work->gameData;
    fieldSound = (struct FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);

    switch (*seq) {
    case 0:
        child = EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap);
        GAME_EVENT_CallEvent(event, child);
        (*seq)++;
        break;
    case 1:
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        FIELD_SOUND_SYSTEM_PostFadeIn(fieldSound, gameData);
        (*seq)++;
        break;
    case 2:
        child = EVENT_MAPCHANGE_CreateChangeFieldEvent(work, work->changeKind);
        GAME_EVENT_CallEvent(event, child);
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Map change with a fade, the fade picked from the season change or the zone pair. */
int EVENT_MAPCHANGE_FadeEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;

    gameSystem = work->gameSystem;
    fieldMap = work->fieldMap;

    switch (*seq) {
    case 0:
        EVENT_MAPCHANGE_CheckSeasonChange(work);
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        if (work->seasonFadeAllowed != 0 && work->seasonChanged != 0) {
            GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        } else {
            GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, EVENT_FIELDMAP_CONTROL_GetExitEffect(work->currentZoneId, work->destination.zoneId), 0));
        }
        (*seq)++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, work->changeKind));
        (*seq)++;
        break;
    case 3:
        if (work->seasonFadeAllowed != 0 && work->seasonChanged != 0) {
            GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 3, 0, 0, (u8)work->fromSeason, (u8)work->toSeason));
        } else {
            GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, EVENT_FIELDMAP_CONTROL_GetEntranceEffect(work->currentZoneId, work->destination.zoneId), 0, 1, 0, 0));
        }
        (*seq)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}

/* Map change with fade effect 2; the default case waits seven frames between steps 0 and 8. */
int EVENT_MAPCHANGE_FadeDelayedEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    gameData = work->gameData;
    fieldMap = work->fieldMap;
    fieldSound = (struct FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 8:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 2, 0));
        (*seq)++;
        break;
    case 9:
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        FIELD_SOUND_SYSTEM_PostFadeIn(fieldSound, gameData);
        (*seq)++;
        break;
    case 10:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, work->changeKind));
        (*seq)++;
        break;
    case 11:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 2, 0, 0, 0, 0));
        (*seq)++;
        break;
    case 12:
        FIELD_PLACE_NAME_OnZoneChange(FIELDMAP_GetPlaceName(fieldMap), (s16)work->destination.zoneId);
        return 1;
    default:
        (*seq)++;
        break;
    }
    return 0;
}

/* Map change that moves the player to the target position. */
int EVENT_MAPCHANGE_TargetPositionEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    gameData = work->gameData;
    fieldMap = work->fieldMap;
    fieldSound = (struct FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, EVENT_DISAPPEAR_CreateWalkFall(event, gameSystem, fieldMap, &work->targetPos));
        (*seq)++;
        break;
    case 2:
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        FIELD_SOUND_SYSTEM_PostFadeIn(fieldSound, gameData);
        (*seq)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, 0));
        (*seq)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_APPEAR_CreatePlayerDrop(event, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}

/* Map change of kind 2 with the season passed to the effect events. */
int EVENT_MAPCHANGE_SeasonEffectAEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    gameData = work->gameData;
    fieldMap = work->fieldMap;
    fieldSound = (struct FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);

    switch (*seq) {
    case 0:
        EVENT_MAPCHANGE_CheckSeasonChange(work);
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, EVENT_DISAPPEAR_CreateSpinZoom(event, gameSystem, fieldMap, work->seasonChanged));
        (*seq)++;
        break;
    case 2:
        EVENT_MAPCHANGE_ResetPlayerObjectCode(gameData);
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        FIELD_SOUND_SYSTEM_PostFadeIn(fieldSound, gameData);
        (*seq)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, 2));
        (*seq)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_APPEAR_CreateSpinZoom(event, gameSystem, fieldMap, work->seasonChanged,
                                           work->fromSeason, work->toSeason));
        (*seq)++;
        break;
    case 5:
        FIELD_PLACE_NAME_OnZoneChange(FIELDMAP_GetPlaceName(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Same steps as the previous one with the second pair of effect events. */
int EVENT_MAPCHANGE_SeasonEffectBEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct GameData *gameData = work->gameData;
    struct FieldMap *fieldMap = work->fieldMap;
    struct FieldSoundSystem *fieldSound = (struct FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);

    switch (*seq) {
    case 0:
        EVENT_MAPCHANGE_CheckSeasonChange(work);
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, EVENT_DISAPPEAR_CreateSpinZoomEffect(event, gameSystem, fieldMap, work->seasonChanged));
        (*seq)++;
        break;
    case 2:
        EVENT_MAPCHANGE_ResetPlayerObjectCode(gameData);
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        FIELD_SOUND_SYSTEM_PostFadeIn(fieldSound, gameData);
        (*seq)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, 2));
        (*seq)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_APPEAR_CreateSpinZoomAlt(event, gameSystem, fieldMap, work->seasonChanged, work->fromSeason, work->toSeason));
        (*seq)++;
        break;
    case 5:
        FIELD_PLACE_NAME_OnZoneChange(FIELDMAP_GetPlaceName(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Map change of kind 3: resets the player's object code. */
int EVENT_MAPCHANGE_ResetPlayerFormEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    gameData = work->gameData;
    fieldMap = work->fieldMap;
    fieldSound = (struct FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, EVENT_DISAPPEAR_CreateSpinFade(event, gameSystem, fieldMap, 1));
        (*seq)++;
        break;
    case 2:
        GAME_DATA_SetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(gameData), 0);
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        FIELD_SOUND_SYSTEM_PostFadeIn(fieldSound, gameData);
        (*seq)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, 3));
        (*seq)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_APPEAR_CreateSpinZoomSmoke(event, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 5:
        FIELD_PLACE_NAME_OnZoneChange(FIELDMAP_GetPlaceName(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Map change with fade effect 1; waits for the field map transition before the animation. */
int EVENT_MAPCHANGE_FadeWaitEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct FieldMap *fieldMap = work->fieldMap;
    int transition = (s32)FIELDMAP_GetTaskManager(fieldMap);

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 1, 0));
        (*seq)++;
        break;
    case 1:
        if ((struct FieldTaskManager *)FIELD_TASK_MANAGER_IsEmpty((struct FieldTaskManager *)transition)) {
            GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
            (*seq)++;
        }
        break;
    case 2:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, 0));
        (*seq)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 1, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 4:
        FIELD_PLACE_NAME_OnZoneChange(FIELDMAP_GetPlaceName(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Map change with fade effect 0: fades out, then continues in a detached copy of the work. */
int EVENT_MAPCHANGE_FadeDetachEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct FieldMap *fieldMap = work->fieldMap;
    struct GameEvent *tailEvent;
    MapChangeWork *tailWork;

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeOut(gameSystem, fieldMap, 0, 0));
        (*seq)++;
        break;
    case 2:
        tailEvent = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_DetachedTailEvent, sizeof(MapChangeWork));
        tailWork = GAME_EVENT_GetWork(tailEvent);
        *tailWork = *work;
        GAME_EVENT_CallEvent(event, tailEvent);
        (*seq)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_StartFadeIn(gameSystem, fieldMap, 0, 0, 1, 0, 0));
        (*seq)++;
        break;
    case 4:
        FIELD_PLACE_NAME_OnZoneChange(FIELDMAP_GetPlaceName(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Map change of kind 0 with the third pair of effect events. */
int EVENT_MAPCHANGE_EffectCEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct FieldSoundSystem *fieldSound;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameData *gameData;

    gameSystem = work->gameSystem;
    gameData = work->gameData;
    fieldMap = work->fieldMap;
    fieldSound = (struct FieldSoundSystem *)GAME_DATA_GetBgmInfo(gameData);

    switch (*seq) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, EVENT_DISAPPEAR_CreateRisingSpin(event, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 2:
        FIELD_SOUND_SYSTEM_PostZoneBgmReplace(fieldSound, gameData, work->destination.zoneId, (u8)work->toSeason);
        FIELD_SOUND_SYSTEM_PostFadeIn(fieldSound, gameData);
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, 0));
        (*seq)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, EVENT_APPEAR_CreateDescendingSpin(event, gameSystem, fieldMap));
        (*seq)++;
        break;
    case 4:
        FIELD_PLACE_NAME_OnZoneChange(FIELDMAP_GetPlaceName(fieldMap), (s16)work->destination.zoneId);
        return 1;
    }
    return 0;
}

/* Map change that swaps the communication overlay (ov012 out, ov011 in) and calls script 0x83A. */
int EVENT_MAPCHANGE_SwapCommOverlayEvent(struct GameEvent *event, int *seq, MapChangeWork *work)
{
    struct GameSystem *gameSystem = work->gameSystem;
    struct FieldMap *fieldMap = work->fieldMap;
    struct GameEvent *child;

    switch (*seq) {
    case 0:
        child = EVENT_DISAPPEAR_CreateSpinFade(event, gameSystem, fieldMap, 0);
    join:
        GAME_EVENT_CallEvent(event, child);
        (*seq)++;
        break;
    case 1:
        child = EVENT_MAPCHANGE_CreateChangeFieldEvent(work, 0);
        goto join;
    case 2:
        GF_OVERLAY_Unload((int)ov012_id);
        GF_OVERLAY_Load((int)ov011_id);
        SCRIPT_SYS_CallScriptEvent(event, 0x83A, 0, 0, 0x15);
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Event callback: plays the animation, swaps overlays 11 and 12, runs the fade. */
int EVENT_MAPCHANGE_RunFixedZoneEvent(GameEvent *event, int *state, MapChangeWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;

    switch (*state) {
    case 0:
        GAME_EVENT_CallEvent(event, EVENT_FIELD_PROCLINK_CreateAnimEvent(gameSystem, fieldMap));
        (*state)++;
        break;
    case 1:
        GF_OVERLAY_Unload((int)ov011_id);
        GF_OVERLAY_Load((int)ov012_id);
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateChangeFieldEvent(work, 4));
        (*state)++;
        break;
    case 2:
        UNION_MAIN_StartComm(gameSystem);
        (*state)++;
        break;
    case 3:
        GAME_EVENT_CallEvent(event, EVENT_APPEAR_CreateMoveAnime(event, gameSystem, fieldMap));
        (*state)++;
        break;
    case 4:
        return 1;
    }
    return 0;
}

/* Fills the common part of a map change work area. */
void EVENT_MAPCHANGE_InitWork(MapChangeWork *work, GameSystem *gameSystem)
{
    GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    FieldMap *fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    u16 season = GAME_DATA_GetSeason(gameData);

    work->gameSystem = gameSystem;
    work->gameData = gameData;
    work->fieldMap = fieldMap;
    work->currentZoneId = FIELDMAP_GetZoneId(fieldMap);
    work->seasonFadeAllowed = 0;
    work->seasonChanged = 0;
    work->fromSeason = season;
    work->toSeason = season;
    EFFECT_ENCOUNT_SetEffectPaused(FIELDMAP_GetEncount(work->fieldMap), 1);
}

/*
 * The leaf ZONEDATA_SetDirectLocation is resolved by its matched shard.
 *
 * What made it byte-correct: `const VecFx32 *pos` (see the EXACT twins
 * EVENT_MAPCHANGE_CreateRailWarpEvent and EVENT_MAPCHANGE_CreateRailWarpEventWithTransition).
 */
GameEvent *EVENT_MAPCHANGE_CreateWarpEvent(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, u16 dir, int seasonFadeAllowed)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_EntranceEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    dir = ZONEDATA_DirToExitDir(dir);
    ZONEDATA_SetDirectLocation(&work->destination, zoneId, (s16)dir, pos->x, pos->y, pos->z);
    work->exitType = 0;
    work->seasonFadeAllowed = seasonFadeAllowed;
    return event;
}

/*
 * Rail variant of the warp event: the 0x1C-byte location at +0x10 is
 * filled by ZONEDATA_SetDirectRailLocation from the rail position.
 * What closed it: `const RailLocation *rail`. Without const the field loads
 * are kept below the outgoing stack-argument stores and `adds r1,r7` is
 * scheduled first; const lets them hoist. The u16 stack parameter dir fixes
 * the frame.
 */
GameEvent *EVENT_MAPCHANGE_CreateRailWarpEvent(GameSystem *gameSystem, int unused, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_EntranceEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    dir = ZONEDATA_DirToExitDir(dir);
    ZONEDATA_SetDirectRailLocation(&work->destination, zoneId, (s16)dir, rail->railIndex, rail->lineGrid, rail->widthGrid);
    work->exitType = 0;
    work->seasonFadeAllowed = seasonFadeAllowed;
    return event;
}

GameEvent *EVENT_MAPCHANGE_CreateRailWarpEventWithTransition(GameSystem *gameSystem, int unused, int zoneId, const RailLocation *rail, u16 dir, int seasonFadeAllowed)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_DetachedTailEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    dir = ZONEDATA_DirToExitDir(dir);
    ZONEDATA_SetDirectRailLocation(&work->destination, zoneId, (s16)dir, rail->railIndex, rail->lineGrid, rail->widthGrid);
    work->exitType = 0;
    work->seasonFadeAllowed = seasonFadeAllowed;
    return event;
}

static inline void EVENT_MAPCHANGE_SetVec(VecFx32 *dst, int x, int y, int z)
{
    dst->x = x;
    dst->y = y;
    dst->z = z;
}

GameEvent *EVENT_MAPCHANGE_CreateWarpEventWithTargetPos(GameSystem *gameSystem, int unused, const VecFx32 *targetPos, s16 zoneId, const VecFx32 *pos)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_TargetPositionEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);
    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    ZONEDATA_SetDirectLocation(&work->destination, zoneId, 1, pos->x, pos->y, pos->z);
    EVENT_MAPCHANGE_SetVec(&work->targetPos, targetPos->x, targetPos->y, targetPos->z);
    work->exitType = 0;
    return event;
}

/* Escape event: warps to the stored escape location. */
GameEvent *EVENT_MAPCHANGE_CreateDigEscapeEvent(int unused, GameSystem *gameSystem)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_SeasonEffectAEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);
    Location *escapeLocation;

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    escapeLocation = GAME_DATA_GetEscapeLocation(work->gameData);
    work->destination = *escapeLocation;
    EVENT_MAPCHANGE_CopySpecialLocation(work->gameData, &work->destination);
    work->destination.type = 1;
    work->exitType = 0;
    work->seasonFadeAllowed = 1;
    return event;
}

GameEvent *EVENT_MAPCHANGE_CreateEscapeRopeEvent(GameSystem *gameSystem)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_SeasonEffectBEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);
    Location *escapeLocation;

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    escapeLocation = GAME_DATA_GetEscapeLocation(work->gameData);
    work->destination = *escapeLocation;
    EVENT_MAPCHANGE_CopySpecialLocation(work->gameData, &work->destination);
    work->destination.type = 1;
    work->exitType = 0;
    work->seasonFadeAllowed = 1;
    return event;
}

/* Warp to the start location of the situation warp id. */
GameEvent *EVENT_MAPCHANGE_CreateSituationWarpEvent(GameSystem *gameSystem)
{
    int warpId = GAME_DATA_GetSituationWarpId(GAMESYSTEM_GetGameData(gameSystem));
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_ResetPlayerFormEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    ZONEDATA_SetZoneStartLocation(&work->destination, MAP_REPLACE_GetWarpFlagId(warpId));
    work->destination.type = 1;
    work->exitType = 0;
    return event;
}

/* Warp to the stored special location, facing dir 2. */
GameEvent *EVENT_MAPCHANGE_CreateSpecialLocationWarpEvent(GameSystem *gameSystem)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_FadeWaitEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);
    Location *specialLocation;

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    specialLocation = GAME_DATA_GetSpecialLocation(work->gameData);
    work->destination = *specialLocation;
    work->destination.type = 1;
    work->destination.dir = 2;
    work->exitType = 0;
    return event;
}

/*
 * Warp to the start location of a zone. The current player position is
 * stored as the special location first.
 */
GameEvent *EVENT_MAPCHANGE_CreateZoneStartWarpEvent(GameSystem *gameSystem, u16 zoneId)
{
    Location playerLocation;
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_FadeDetachEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);
    PlayerWork *playerWork;
    int playerZoneId, playerDir;
    VecFx32 *playerPos;

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    ZONEDATA_SetZoneStartLocation(&work->destination, zoneId);
    work->exitType = 0;
    work->destination.dir = 1;
    playerWork = GAME_DATA_GetMyPlayerWork(work->gameData);
    playerPos = GAME_DATA_GetPlayerPosition(playerWork);
    playerZoneId = GAME_DATA_GetPlayerZoneId(playerWork);
    ZONEDATA_SetDirectLocation(&playerLocation, playerZoneId, (s16)GAME_DATA_GetPlayerDirectionType(playerWork), playerPos->x, playerPos->y, playerPos->z);
    GAME_DATA_SetSpecialLocation(work->gameData, &playerLocation);
    return event;
}

GameEvent *EVENT_MAPCHANGE_CreateFixedExitTypeWarpEvent(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, u16 dir)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_EffectCEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    dir = ZONEDATA_DirToExitDir(dir);
    ZONEDATA_SetDirectLocation(&work->destination, zoneId, dir, pos->x, pos->y, pos->z);
    work->exitType = 5;
    work->seasonFadeAllowed = 0;
    return event;
}

/* Fixed destination: zone 0x1A6 at a hard-coded position. */
GameEvent *EVENT_MAPCHANGE_CreateFixedZoneEvent(GameSystem *gameSystem)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_RunFixedZoneEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    ZONEDATA_SetDirectLocation(&work->destination, 0x1A6, ZONEDATA_DirToExitDir(0), 0x2E << 14, 0, 0x3E << 14);
    work->exitType = 0;
    return event;
}

/* Allocator with callback, then the special location copied to +0x10. */
GameEvent *EVENT_MAPCHANGE_CreateSpecialLocationEvent(GameSystem *gameSystem, u8 *unusedPos)
{
    Location *specialLocation = GAME_DATA_GetSpecialLocation(GAMESYSTEM_GetGameData(gameSystem));
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_SwapCommOverlayEvent, 0x9C);
    MapChangeWork *work = GAME_EVENT_GetWork(event);

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    work->destination = *specialLocation;
    return event;
}

/*
 * Starts an intrude warp: builds the current location, shifts the x
 * position by the intrude slot and creates the arrival event.
 */
GameEvent *EVENT_MAPCHANGE_CreateIntrudeWarpEvent(GameSystem *gameSystem, int zoneId, VecFx32 *pos, int requestSession)
{
    FieldMap *fieldMap;
    GameData *gameData;
    VecFx32 shiftedPos;
    Location currentLocation;
    Location eventLocation;
    int xFlag;
    int intrudeId;
    int slotOffset;
    void *saveRecord;
    IntrudeComm *comm;

    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    shiftedPos = *pos;
    xFlag = 0;
    EVENT_MAPCHANGE_GetCurrentLocation(&currentLocation, fieldMap);
    GAME_DATA_SetWarpLocation(gameData, &currentLocation);
    saveRecord = INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(gameData));
    INTRUDE_UpdatePlaySeconds(saveRecord, GAME_DATA_GetPlayTime(gameData), 0);
    comm = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
    if (comm == 0 || INTRUDE_COMM_HasUnlockFlags(gameData) == 0) {
        intrudeId = 0;
        slotOffset = 0;
    } else {
        intrudeId = INTRUDE_COMM_GetRequesterNetId((struct IntrudeCommSys *)comm, (struct IntrudeSession *)comm->requestInfo);
        slotOffset = intrudeId - GAME_DATA_GetOwnNetId(gameData);
        if (slotOffset < 0)
            slotOffset += comm->slotCount;
        xFlag = 0x10000;
    }
    shiftedPos.x += xFlag + (slotOffset << 22);
    ZONEDATA_SetDirectLocation(&eventLocation, zoneId, ZONEDATA_DirToExitDir(0), shiftedPos.x, shiftedPos.y, shiftedPos.z);
    return EVENT_MAPCHANGE_CreateIntrudeSessionEvent(gameSystem, fieldMap, &eventLocation, requestSession, intrudeId);
}

static inline void EVENT_MAPCHANGE_CreateArriveEvent(GameSystem *gameSystem, FieldMap *fieldMap, Location *location, GameEvent **out)
{
    *out = EVENT_MAPCHANGE_CreateIntrudeArriveEvent(gameSystem, fieldMap, location);
}

static inline GameEvent *EVENT_MAPCHANGE_FinishIntrudeWarp(GameSystem *gameSystem, GameData *gameData, FieldMap *fieldMap, GameEvent *event)
{
    u16 *saveRecord;
    GameComm *gameComm;

    saveRecord = INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(gameData));
    INTRUDE_UpdatePlaySeconds(saveRecord, GAME_DATA_GetPlayTime(gameData), 1);
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    GAME_COMM_GetCounter(gameComm);
    if (GAME_COMM_GetKind(gameComm) == 0)
        GAME_COMM_ClearCounter(gameComm);
    if (FIELD_PLAYER_CheckFormModel(FIELDMAP_GetFieldPlayer(fieldMap)) == 0)
        INTRUDE_FIELD_ChangePlayerLook(0, gameSystem, 0, 0, 0);
    GAME_DATA_SetIntrudeCount(gameData, 0);
    if (INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem)) == 0) {
        GAME_DATA_SetOwnNetId(gameData, 0);
        GAME_DATA_SetIntrudeId(gameData, 0);
        GAME_DATA_SetEnterMode(gameData, 1);
    }
    return event;
}

/*
 * Lever: GAME_COMM_GetCounter reads its pointer argument in the matched ARM9
 * unit_02026454.c. The original forwards GAMESYSTEM_GetGameComm(gameSystem) in r0
 * with no intervening argument setup. Explicitly passing gameComm restores
 * the return-value spill and all frame/register choices.
 */
GameEvent *EVENT_MAPCHANGE_CreateIntrudeReturnEvent(GameSystem *gameSystem)
{
    GameData *gameData;
    FieldMap *fieldMap;
    Location warpLocation;
    GameEvent *event;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    warpLocation = *GAME_DATA_GetWarpLocation(gameData);
    if (ZONEDATA_IsZoneInTableDFC0(warpLocation.zoneId) == 1)
        ZONEDATA_SetZoneStartLocation(&warpLocation, warpLocation.zoneId);
    EVENT_MAPCHANGE_CreateArriveEvent(gameSystem, fieldMap, &warpLocation, &event);
    return EVENT_MAPCHANGE_FinishIntrudeWarp(gameSystem, gameData, fieldMap, event);
}

/* Builds the location of the player on the current map (direct or rail). */
void EVENT_MAPCHANGE_GetCurrentLocation(Location *location, FieldMap *fieldMap)
{
    RailLocation rail;
    void *fieldPlayer = FIELDMAP_GetFieldPlayer(fieldMap);

    if (FIELDMAP_GetMoveKind(fieldMap) == 0) {
        VecFx32 *playerPos;

        playerPos = FLDMMDL_GetPosPtr(FIELD_PLAYER_GetMmdl(fieldPlayer));
        ZONEDATA_SetDirectLocation(location, FIELDMAP_GetZoneId(fieldMap), 1, playerPos->x, playerPos->y, playerPos->z);
        return;
    }
    FIELD_PLAYER_GetNogridNextRailLocation(fieldPlayer, &rail);
    ZONEDATA_SetDirectRailLocation(location, FIELDMAP_GetZoneId(fieldMap), 2, rail.railIndex, rail.lineGrid, rail.widthGrid);
}

/* Warp through a map exit (door, stairs, connection). */
GameEvent *EVENT_MAPCHANGE_CreateExitWarpEvent(GameSystem *gameSystem, int unused, void *connectData, int exitDir)
{
    MapChangeWork *work;
    GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_EntranceEvent, 0x9c);
    Location *entranceLocation;

    work = GAME_EVENT_GetWork(event);
    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    work->seasonFadeAllowed = 1;
    if (EVENTDATA_SYSTEM_IsSpecialExitConnect(connectData) != 0) {
        work->destination = *GAME_DATA_GetSpecialLocation(gameData);
    } else {
        EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly(connectData, (s32)(&work->destination), exitDir);
    }
    work->exitType = EVENTDATA_SYSTEM_GetConnectExitType(connectData);
    entranceLocation = GAME_DATA_GetEntranceLocation(gameData);
    if (ZONEDATA_IsFieldMatrix(entranceLocation->zoneId) == 1 && ZONEDATA_IsFieldMatrix(work->destination.zoneId) == 0) {
        GAME_DATA_SetEscapeLocation(gameData, entranceLocation);
    }
    EVENT_MAPCHANGE_UpdateEscapeLocation(gameData, &work->destination);
    FIELD_STATUS_SwapSeasonDispFlag(GAME_DATA_GetMoveModelSys(gameData), 2);
    return event;
}

GameEvent *EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate(GameSystem *gameSystem, int unused, void *connectData, int exitDir)
{
    GameEvent *event;
    MapChangeWork *work;

    GAMESYSTEM_GetGameData(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_EntranceCommEvent, 0x9c);
    work = GAME_EVENT_GetWork(event);
    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    work->seasonFadeAllowed = 1;
    EVENTDATA_SYSTEM_SetConnectExitLocationIdOnly(connectData, (s32)(&work->destination), exitDir);
    work->exitType = EVENTDATA_SYSTEM_GetConnectExitType(connectData);
    return event;
}

GameEvent *EVENT_MAPCHANGE_CreateWarpEventWithTransition(GameSystem *gameSystem, int unused, int transitionType, s16 zoneId, const VecFx32 *pos, u16 dir)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_DetachedTailEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    dir = ZONEDATA_DirToExitDir(dir);
    ZONEDATA_SetDirectLocation(&work->destination, zoneId, dir, pos->x, pos->y, pos->z);
    work->exitType = 0;
    work->changeKind = transitionType;
    return event;
}

GameEvent *EVENT_MAPCHANGE_CreateWarpEventDefaultTransition(GameSystem *gameSystem, int unused, s16 zoneId, const VecFx32 *pos, u16 dir)
{
    return EVENT_MAPCHANGE_CreateWarpEventWithTransition(gameSystem, unused, 0, zoneId, pos, dir);
}

/* Warp to a ready-made location, facing dir. */
GameEvent *EVENT_MAPCHANGE_CreateWarpEventToLocation(GameSystem *gameSystem, int unused, int unused2, const Location *location, u16 dir)
{
    GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    GameEvent *event;
    MapChangeWork *work;

    GAME_DATA_SetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(gameData), 0);
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_DetachedTailEvent, 0x9c);
    work = GAME_EVENT_GetWork(event);
    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    work->destination = *location;
    work->destination.dir = dir;
    work->exitType = 0;
    work->changeKind = 1;
    EVENT_MAPCHANGE_UpdateEscapeLocation(gameData, &work->destination);
    return event;
}

/*
 * Lever: `const VecFx32 *pos` (as in EVENT_MAPCHANGE_CreateWarpEventWithTargetPos) and the callee's third
 * parameter declared short.
 */
GameEvent *EVENT_MAPCHANGE_CreateWarpEventPlain(GameSystem *gameSystem, int unused, int zoneId, const VecFx32 *pos, short dir)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_FadeEvent, 0x9c);
    MapChangeWork *work = GAME_EVENT_GetWork(event);

    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    *(u16 *)&dir = ZONEDATA_DirToExitDir(*(u16 *)&dir);
    ZONEDATA_SetDirectLocation(&work->destination, zoneId, dir, pos->x, pos->y, pos->z);
    work->exitType = 0;
    return event;
}

/*
 * Two source facts closed the last 18 bytes: (1) zoneId is a u16 parameter,
 * and ZONEDATA_SetDirectLocation takes a u16 id (its matched definition in
 * src/matched/arm9/ZONEDATA_SetDirectLocation.c); (2) the bit field slot is read into its
 * own block local (`int slot = comm->slot; offset = slot - exitMode;`), the
 * same shape as EVENT_MAPCHANGE_CreateIntrudeWarpEvent.
 */
GameEvent *EVENT_MAPCHANGE_CreateWarpEventWithIntrudeOffset(GameSystem *gameSystem, u16 zoneId, const VecFx32 *pos)
{
    VecFx32 warpPos = *pos;
    GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_FadeDelayedEvent, 0x9C);
    MapChangeWork *work = GAME_EVENT_GetWork(event);
    int slotOffset = 0;

    if (ZONEDATA_IsEntralink(zoneId) == 1) {
        IntrudeComm *comm = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
        if (comm != 0) {
            int slot = comm->slot;
            slotOffset = slot - GAME_DATA_GetOwnNetId(gameData);
            if (slotOffset < 0)
                slotOffset += comm->slotCount;
        }
        warpPos.x += (u32)slotOffset << 22;
    }
    EVENT_MAPCHANGE_InitWork(work, gameSystem);
    ZONEDATA_SetDirectLocation(&work->destination, zoneId, (s16)ZONEDATA_DirToExitDir(0), warpPos.x, warpPos.y, warpPos.z);
    work->exitType = 0;
    work->seasonFadeAllowed = 0;
    return event;
}

/* Sets up the game state for the warp id of the situation block. */
void EVENT_MAPCHANGE_InitFieldFromSituationWarp(GameSystem *gameSystem)
{
    GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    struct {
        Location startLocation;
        Location arrivalLocation;
    } locations;

    MAP_REPLACE_ApplyWarpLocation((s32)(GAME_DATA_GetSituationWarpId(gameData)), (s32)(&locations.arrivalLocation));
    ZONEDATA_SetZoneStartLocation(&locations.startLocation, MAP_REPLACE_GetWarpFlagId(GAME_DATA_GetSituationWarpId(gameData)));
    GAME_DATA_SetEscapeLocation(gameData, &locations.startLocation);
    EVENT_MAPCHANGE_DeleteAllMmdlOfSystem(gameSystem);
    EVENT_MAPCHANGE_UpdateFieldStateForZone(gameSystem, locations.arrivalLocation.zoneId);
    EVENT_MAPCHANGE_ApplyLocation(gameSystem, &locations.arrivalLocation);
    GAME_BEACON_SetZone((u32)locations.arrivalLocation.zoneId, (u32)gameData);
    FIELD_CLOCK_Update(gameData);
    FIELD_MAP_CHANGE_ResetGimmickStateCase4((s32)gameData, locations.arrivalLocation.zoneId);
}

/*
 * The leaves ISS_SYS_GetSwitchSys (`return p[8]`) and FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx (a thumb
 * tail-call stub to FIELD_SOUND_SYSTEM_GetFieldBgmForZone) are unlabelled ARM9 code resolved by
 * their matched shards.
 */
int EVENT_MAPCHANGE_RunSituationWarpArrivalEvent(GameEvent *event, int *state, WarpIdArrivalWork *work)
{
    GameEvent *child;
    unsigned int bgmId;

    switch (state[0]) {
    case 0:
        EVENT_MAPCHANGE_InitFieldFromSituationWarp(work->gameSystem);
        state[0]++;
        break;
    case 1:
        GAME_DATA_SetPlayerObjectCode(GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(work->gameSystem)), 0);
        ISS_SWITCH_SYS_ResetSwitch(ISS_SYS_GetSwitchSys(GAMESYSTEM_GetIssSystem(work->gameSystem)));
        bgmId = FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(work->gameData, (s16)work->location.zoneId, GAME_DATA_GetSeason(work->gameData));
        child = FIELD_SOUND_SYSTEM_StartChangeTask(work->gameSystem, bgmId, 0, 0x3c);
        GAME_EVENT_CallEvent(event, child);
        state[0]++;
        break;
    case 2:
        child = FIELD_STATUS_CreateFieldOpenNoNotifyEvent(work->gameSystem);
        GAME_EVENT_CallEvent(event, child);
        state[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

GameEvent *EVENT_MAPCHANGE_CreateSituationWarpArrivalEvent(GameSystem *gameSystem)
{
    GameEvent *event;
    WarpIdArrivalWork *work;

    GAMESYSTEM_GetGameData(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_RunSituationWarpArrivalEvent, sizeof(WarpIdArrivalWork));
    work = GAME_EVENT_GetWork(event);
    work->gameSystem = gameSystem;
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    MAP_REPLACE_ApplyWarpLocation((s32)(GAME_DATA_GetSituationWarpId(work->gameData)), (s32)(&work->location));
    return event;
}

/* Maps a direction code to a rotation angle. */
int EVENT_MAPCHANGE_DirToAngle(int dir)
{
    switch (dir) {
    case 0:
    case 1:
    default: return 0;
    case 3: return 0x4000;
    case 2: return 0x8000;
    case 4: return 0xc000;
    }
}

/* Resolves a location: copies direct ones, looks up exits, else zone start. */
void EVENT_MAPCHANGE_ResolveLocation(EventData *eventData, Location *source, Location *dest)
{
    if (source->type == 1) {
        *dest = *source;
    } else {
        if (EVENTDATA_SYSTEM_SetConnectExitLocation((struct EventDataSystem *)eventData, (s32 *)dest, (u16)source->exitId, source->exitOffset) == 0) {
            ZONEDATA_SetZoneStartLocation(dest, source->zoneId);
        }
    }
}

/* Applies a new location to the player, the map objects and the field state. */
void EVENT_MAPCHANGE_ApplyLocation(GameSystem *gameSystem, Location *warpLocation)
{
    GameData *gameData;
    PlayerWork *playerWork;
    EventData *eventData;
    Location location;
    u16 warpId;
    int mapSubType;
    MmdlSys *mmdlSys;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    playerWork = GAME_DATA_GetMyPlayerWork(gameData);
    eventData = (EventData *)GAME_DATA_GetEventData(gameData);
    FIELD_STATUS_SetFieldInitFlag(GAME_DATA_GetMoveModelSys(gameData), 1);
    EVENT_MAPCHANGE_ResolveLocation(eventData, warpLocation, &location);
    if (location.type == 3)
        GAME_DATA_SetSpecialLocation(gameData, GAME_DATA_GetEntranceLocation(gameData));
    GAME_DATA_SetPlayerZoneId(playerWork, location.zoneId);
    GAME_DATA_SetPlayerDirection(playerWork, EVENT_MAPCHANGE_DirToAngle(location.dir));
    if (ZONEDATA_GetLocationPosType(&location) == 0) {
        GAME_DATA_SetPlayerPosition(playerWork, (struct PlayerPosition *)(&location.pos.vec));
        GAME_DATA_SetPlayerMoveForm(playerWork, 0);
    } else {
        GAME_DATA_SetPlayerRail(playerWork, (struct RailLocationWords *)(&location.pos.rail));
        GAME_DATA_SetPlayerMoveForm(playerWork, 1);
    }
    ISS_SYS_ChangeZone(GAMESYSTEM_GetIssSystem(gameSystem), location.zoneId);
    GAME_DATA_SetStartLocation(gameData, &location);
    warpId = MAP_REPLACE_FindFlyTargetIndex((s16)location.zoneId);
    if (warpId != 0)
        GAME_DATA_SetWarpId(gameData, warpId);
    EVENT_MAPCHANGE_ApplyZoneTableEntry(gameData, (s16)location.zoneId);
    FIELD_CLOCK_Update(gameData);
    FIELD_MAP_CHANGE_SetupZone(gameData, location.zoneId);
    MAP_REPLACE_SetArriveFlag(gameData, (s16)location.zoneId);
    SCRIPT_SYS_RunZoneChangeScript(gameSystem, (s32)4);
    EVENT_MAPCHANGE_AddEventDataMmdl(gameData, warpLocation);
    EVENT_MAPCHANGE_SetMapEffectMask(gameData, location.zoneId);
    EVENT_MAPCHANGE_ReloadMmdl(gameData, &location);
    WEATHER_StoreZoneWeatherId((int)gameSystem, (s16)location.zoneId);
    mapSubType = ZONEDATA_GetMapSubType(location.zoneId);
    mmdlSys = GAME_DATA_GetOccupyInfo(gameData);
    if (mapSubType < 16)
        FLDMMDL_SysLoadObjCodeParamCache(mmdlSys, mapSubType);
    else
        FLDMMDL_ClearObjCodeParamCache(mmdlSys);
}

/* Adds the map objects (NPC headers) of the event data of a zone. */
void EVENT_MAPCHANGE_AddEventDataMmdl(GameData *gameData, const Location *location)
{
    EventData *eventData = (EventData *)GAME_DATA_GetEventData(gameData);
    int npcCount = EVENTDATA_SYSTEM_GetNpcCount((struct EventDataSystem *)eventData);

    if (npcCount != 0) {
        int eventWork = (int)GAME_DATA_GetEventWork(gameData);
        MmdlSys *mmdlSys = GAME_DATA_GetOccupyInfo(gameData);
        int npcHeaders = EVENTDATA_SYSTEM_GetNpcHeaders((struct EventDataSystem *)eventData);
        int zoneId = (s16)location->zoneId;
        FLDMMDL_AddMmdlHeaderList(mmdlSys, (struct MmdlHeader *)npcHeaders, zoneId, npcCount, (void *)eventWork);
    }
}

/*
 * Adds the map objects of the White Forest / Black City (WFBC) data of a
 * zone: the people, then the items.
 * The leaf ZONEDATA_IsZoneInTableDFC0 returns whether the zone is in a fixed table
 * (`return ZONEDATA_IsZoneInTable(zoneId, table, 4)`).
 */
void EVENT_MAPCHANGE_AddWfbcMmdl(GameData *gameData, const Location *location)
{
    int mapMode;
    int headers;
    int itemCount;
    int headerCount;
    int mmdlSys;
    int eventWork;
    unsigned short *wfbcData;
    int itemSlots;

    if (ZONEDATA_IsZoneInTableDFC0((unsigned short)location->zoneId) == 0)
        return;

    mapMode = (int)FIELD_STATUS_GetMapMode(GAME_DATA_GetMoveModelSys(gameData));
    mmdlSys = (int)GAME_DATA_GetOccupyInfo(gameData);
    eventWork = (int)GAME_DATA_GetEventWork(gameData);
    if (mapMode == 0)
        wfbcData = (u16 *)GAME_DATA_GetSecondUnionInfo(gameData);
    else
        wfbcData = (u16 *)GAME_DATA_GetUnionInfo(gameData, (int)0);

    headers = (s32)FIELD_WFBC_DATA_LOCAL_CreateMmdlHeaders((struct WfbcData *)wfbcData, mapMode, 1);
    headerCount = FIELD_WFBC_DATA_LOCAL_CountPeople((struct WfbcData *)wfbcData, mapMode);
    if (headers != 0 && headerCount != 0)
        FLDMMDL_AddMmdlHeaderList((MmdlSys *)mmdlSys, (struct MmdlHeader *)headers, (s16)location->zoneId, (int)headerCount, (void *)eventWork);
    if (headers != 0)
        GFL_HEAP_Free((void *)headers);

    itemSlots = (int)GAME_DATA_GetMusicalShotTitle(gameData);
    itemCount = FIELD_WFBC_DATA_LOCAL_CountItemSlots((u16 *)itemSlots);
    headers = (s32)FIELD_WFBC_DATA_LOCAL_CreateItemMmdlHeaders((u16 *)itemSlots, mapMode, wfbcData[1], 1);
    if (headers != 0 && itemCount != 0)
        FLDMMDL_AddMmdlHeaderList((MmdlSys *)mmdlSys, (struct MmdlHeader *)headers, (s16)location->zoneId, (int)itemCount, (void *)eventWork);
    if (headers != 0)
        GFL_HEAP_Free((void *)headers);
}

void EVENT_MAPCHANGE_DeleteAllMmdl(GameData *gameData)
{
    FLDMMDL_DeleteAllMmdl(GAME_DATA_GetOccupyInfo(gameData));
}

/* Reloads the map objects of a zone (people, WFBC people and items). */
void EVENT_MAPCHANGE_ReloadMmdl(GameData *gameData, const Location *location)
{
    FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList(gameData);
    if (ZONEDATA_IsZoneInTableDFC0(location->zoneId) != 0) {
        EVENT_MAPCHANGE_AddWfbcMmdl(gameData, location);
        if (FIELD_STATUS_GetMapMode(GAME_DATA_GetMoveModelSys(gameData)) == 0) {
            FIELD_WFBC_DATA_LOCAL_ApplyTalkedMoodBonus((u8 *)GAME_DATA_GetSecondUnionInfo(gameData));
        }
    }
}

/*
 * Interface: FIELD_STATUS_SetMapEffectMask takes the full-word mask (the absent call-site
 * truncation matches).
 */
void EVENT_MAPCHANGE_SetMapEffectMask(GameData *gameData, unsigned int zoneId)
{
    FieldStatus *fieldStatus;
    unsigned int effectMask;

    fieldStatus = GAME_DATA_GetMoveModelSys(gameData);
    effectMask = ZONEDATA_GetFieldSkillMapEffect(zoneId);
    if ((effectMask & 1) && FIELD_STATUS_IsFlashActive(fieldStatus)) {
        effectMask &= ~1;
        effectMask |= 2;
    }
    FIELD_STATUS_SetMapEffectMask(fieldStatus, effectMask);
}

/* Updates map mode, subscreen type, matrix and field work for a zone. */
void EVENT_MAPCHANGE_UpdateFieldStateForZone(GameSystem *gameSystem, int zoneId)
{
    GameData *gameData;
    EventData *eventData;
    void *fieldWork;
    int subscreenType;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    eventData = (EventData *)GAME_DATA_GetEventData(gameData);
    GAMESYSTEM_GetFieldMap(gameSystem);
    if (GAME_DATA_GetIntrudeCount(gameData) == 1 && ZONEDATA_IsEntralink(zoneId) == 0)
        FIELD_STATUS_SetMapMode(GAME_DATA_GetMoveModelSys(gameData), 1);
    else
        FIELD_STATUS_SetMapMode(GAME_DATA_GetMoveModelSys(gameData), 0);

    if (ZONEDATA_IsUnionRoom(zoneId) != 0) {
        GAME_DATA_SetSubscreenType(gameData, 2);
    } else if (ZONEDATA_IsZone96Pair(zoneId) != 0 || ZONEDATA_IsZone4E(zoneId) != 0 || ZONEDATA_IsZone34(zoneId) != 0) {
        GAME_DATA_SetSubscreenType(gameData, 5);
    } else {
        if (GAME_DATA_GetIntrudeCount(gameData) == 1 && GAME_DATA_GetSubscreenType(gameData) != 3)
            GAME_DATA_SetSubscreenType(gameData, 3);
        else if (GAME_DATA_GetIntrudeCount(gameData) == 0 && GAME_DATA_GetSubscreenType(gameData) == 3)
            GAME_DATA_SetSubscreenType(gameData, 0);
        subscreenType = GAME_DATA_GetSubscreenType(gameData);
        if (subscreenType != 3 && subscreenType != 4 && subscreenType != 6)
            GAME_DATA_SetSubscreenType(gameData, 0);
    }

    EVENTDATA_SYSTEM_Load((int)eventData, zoneId, GAME_DATA_GetSeason(gameData));
    fieldWork = (void *)GAME_DATA_GetFieldWork(gameData);
    MAP_MATRIX_Load((int)fieldWork, ZONEDATA_GetMatrixId(zoneId), zoneId, 0x8001);
    MAP_MATRIX_ApplyReplace(fieldWork, (int)gameSystem, 0x8001);
    EVENT_MAPCHANGE_SetMapEffectMask(gameData, zoneId);
}

/*
 * Interface: EVENT_MAPCHANGE_DeleteAllMmdl forwards the incoming r0 to GAME_DATA_GetOccupyInfo.
 */
void EVENT_MAPCHANGE_DeleteAllMmdlOfSystem(GameSystem *gameSystem)
{
    GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    GAMESYSTEM_GetFieldMap(gameSystem);
    EVENT_MAPCHANGE_DeleteAllMmdl(gameData);
}

void EVENT_MAPCHANGE_SetPlayerVanish(FieldMap *fieldMap, unsigned int vanish)
{
    FLDMMDL_SetStatusBitVanish(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), vanish);
}

/* Looks up a zone in the arc 0x65 table and applies its entry to the field save. */
void EVENT_MAPCHANGE_ApplyZoneTableEntry(GameData *gameData, int zoneId)
{
    unsigned count, i;
    void *fieldSave = GAME_DATA_GetFieldSave(gameData);
    void *arcHandle;
    int heapId = 0x8001;
    ZoneTableEntry *entries;

    GIMMICK_WORK_Reset(fieldSave);
    arcHandle = ARC_TOOL_CreateHandle(0x65, heapId);
    entries = ARC_TOOL_LoadHandleMember(arcHandle, 0, heapId);
    count = ARC_TOOL_GetHandleMemberSize(arcHandle, 0) >> 3;
    for (i = 0; i < count; i++) {
        if (zoneId == entries[i].zoneId) {
            GIMMICK_WORK_InitWithId(fieldSave, entries[i].value);
            break;
        }
    }
    GFL_HEAP_Free(entries);
    ARC_TOOL_DeleteHandle(arcHandle);
}

/* Allocator with callback, copies the location and fills the link fields. */
GameEvent *EVENT_MAPCHANGE_CreateIntrudeSessionEvent(GameSystem *gameSystem, FieldMap *fieldMap, Location *location, int requestSession, int intrudeId)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_RunIntrudeSessionEvent, 0x30);
    MapChangeIntrudeWork *work = GAME_EVENT_GetWork(event);

    work->location = *location;
    work->gameSystem = gameSystem;
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->fieldMap = fieldMap;
    work->requestSession = requestSession;
    work->intrudeId = intrudeId;
    return event;
}

/* Allocator with callback, copies the location and two link fields. */
GameEvent *EVENT_MAPCHANGE_CreateIntrudeArriveEvent(GameSystem *gameSystem, FieldMap *fieldMap, Location *location)
{
    GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_RunIntrudeArriveEvent, 0x30);
    MapChangeIntrudeWork *work = GAME_EVENT_GetWork(event);

    work->location = *location;
    work->gameSystem = gameSystem;
    work->gameData = GAMESYSTEM_GetGameData(gameSystem);
    work->fieldMap = fieldMap;
    return event;
}

int EVENT_MAPCHANGE_RunIntrudeArriveEvent(GameEvent *event, int *state, MapChangeIntrudeWork *work)
{
    GameSystem *gameSystem = work->gameSystem;
    FieldMap *fieldMap = work->fieldMap;
    GameEvent *child;
    MapChangeWork *childWork;

    switch (state[0]) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x773);
        ENCEFF_Start((struct EncEffWork *)FIELDMAP_GetEncEff(fieldMap), event, 0x24);
        state[0]++;
        break;
    case 1:
        child = GAME_EVENT_Create(gameSystem, 0, EVENT_MAPCHANGE_DetachedTailEvent, 0x9c);
        childWork = GAME_EVENT_GetWork(child);
        EVENT_MAPCHANGE_InitWork(childWork, gameSystem);
        childWork->destination = work->location;
        childWork->exitType = 0;
        childWork->seasonFadeAllowed = 0;
        GAME_EVENT_CallEvent(event, child);
        state[0]++;
        break;
    case 2:
        GAME_EVENT_CallEvent(event, EVENT_FIELDMAP_CONTROL_CreateFadeInEventWithBgRestore(gameSystem, fieldMap, 0, 0, 2));
        state[0]++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Intrude warp event: starts the session, sets the intrude id, runs the arrival. */
int EVENT_MAPCHANGE_RunIntrudeSessionEvent(GameEvent *event, int *state, MapChangeIntrudeWork *work)
{
    int busy;
    GameComm *gameComm;
    int isHost;
    int scriptId;
    IntrudeComm *comm;

    gameComm = GAMESYSTEM_GetGameComm(work->gameSystem);
    switch (*state) {
    case 0:
        comm = INTRUDE_COMM_GetWorkIfRunning(gameComm);
        isHost = 0;
        busy = 0;
        if (comm != 0) {
            busy = INTRUDE_FIELD_IsStartRequested((struct IntrudeCommSys *)comm);
            if (INTRUDE_COMM_GetRequestState(gameComm) == 3)
                isHost = 1;
        }
        if (busy == 0 && FIELD_CheckPlayerPositionFree(work->gameSystem) != 0) {
            scriptId = !isHost ? 0x279A : 0x279B;
            SCRIPT_SYS_CallScriptEvent(event, scriptId, 0, 0, FIELDMAP_GetHeapId(work->fieldMap));
            if (INTRUDE_COMM_HasUnlockFlags(work->gameData) == 0)
                GAME_COMM_RequestExitNoCallback(gameComm);
            *state = 1;
        } else {
            scriptId = !busy ? 0x279C : 0x279D;
            SCRIPT_SYS_CallScriptEvent(event, scriptId, 0, 0, FIELDMAP_GetHeapId(work->fieldMap));
            *state = 3;
        }
        break;
    case 1:
        if (INTRUDE_COMM_HasUnlockFlags(work->gameData) == 0) {
            if (GAME_COMM_GetKind(gameComm) != 0)
                break;
            GAME_COMM_ClearCounter(gameComm);
        }
        if (work->requestSession == 1 && INTRUDE_COMM_GetRequestState(gameComm) != 3) {
            SCRIPT_SYS_CallScriptEvent(event, 0x279F, 0, 0, FIELDMAP_GetHeapId(work->fieldMap));
            *state = 3;
            break;
        }
        comm = INTRUDE_COMM_GetWorkIfRunning(gameComm);
        if (comm != 0) {
            INTRUDE_COMM_SetSuspended((struct IntrudeCommSys *)comm, 1);
            INTRUDE_COMM_SetIntrudeId((struct IntrudeCommSys *)comm, work->intrudeId);
            if (work->requestSession == 1)
                INTRUDE_COMM_AcceptSession(comm, comm->requestInfo);
        }
        GAME_DATA_SetOwnNetId(work->gameData, GFL_NET_SYSTEM_GetCurrentAid((int)GAME_DATA_SetIntrudeCount(work->gameData, 1)));
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateIntrudeArriveEvent(work->gameSystem, work->fieldMap, &work->location));
        *state = 2;
        break;
    case 2:
        comm = INTRUDE_COMM_GetWorkIfRunning(gameComm);
        if (comm != 0)
            INTRUDE_COMM_SetSuspended((struct IntrudeCommSys *)comm, 0);
        *state = 3;
        break;
    case 3:
        return 1;
    }
    return 0;
}

/* Sets the escape location for a warp into a zone that keeps one. */
void EVENT_MAPCHANGE_UpdateEscapeLocation(GameData *gameData, const Location *destination)
{
    Location *entranceLocation = GAME_DATA_GetEntranceLocation(gameData);
    Location *startLocation = GAME_DATA_GetStartLocation(gameData);
    Location escapeLocation;

    if (ZONEDATA_IsParentZoneD6(destination->zoneId)) {
        if ((s16)startLocation->zoneId == 0x88) {
            GAME_DATA_SetEscapeLocation(gameData, entranceLocation);
        } else if (!ZONEDATA_IsParentZoneD6((s16)startLocation->zoneId)) {
            ZONEDATA_SetZoneStartLocation(&escapeLocation, 0xd6);
            GAME_DATA_SetEscapeLocation(gameData, &escapeLocation);
        }
    }
    if ((s16)startLocation->zoneId == 0x9e) {
        if (ZONEDATA_IsWeatherEnabled(destination->zoneId))
            GAME_DATA_SetEscapeLocation(gameData, entranceLocation);
    }
}

/* Copies the special location into *out when the start zone allows it. */
void EVENT_MAPCHANGE_CopySpecialLocation(GameData *gameData, Location *out)
{
    if (ZONEDATA_IsZoneInTableDFDC(GAME_DATA_GetStartLocation(gameData)->zoneId))
        *out = *GAME_DATA_GetSpecialLocation(gameData);
}

/* Object code 3 becomes 2, every other code becomes 0. */
void EVENT_MAPCHANGE_ResetPlayerObjectCode(GameData *gameData)
{
    PlayerWork *playerWork = GAME_DATA_GetMyPlayerWork(gameData);

    if (GAME_DATA_GetPlayerObjectCode(playerWork) != 3)
        GAME_DATA_SetPlayerObjectCode(playerWork, 0);
    else
        GAME_DATA_SetPlayerObjectCode(playerWork, 2);
}

/* Puts the preset mail (writer name from message 0x3b of file 0xbe) into mail box slot 0. */
void EVENT_MAPCHANGE_AddPresetMail(GameData *gameData)
{
    struct MsgData *msgData = (struct MsgData *)MSGDATA_CreateFromArchive(0, 2, 0xbe, 1);
    struct Strbuf *writerName = MSGDATA_AllocString((struct MsgBank *)msgData, 0x3b);
    struct Mail *mail;
    u16 writerChars[0x10];

    STRBUF_ToChars(writerName, writerChars, 0x10);
    mail = MAIL_Create(1);
    MAIL_SetWriterName(mail, writerChars);
    MAIL_SetGender(mail, 1);
    MAIL_SetDesign(mail, 3);
    MAIL_SetLanguage(mail, 2);
    MAIL_SetVersion(mail, PM_VERSION_ID);
    MAIL_SetMessage(mail, d_02187DA4, 0);
    MAIL_SetMessage(mail, d_02187DAC, 1);
    MAIL_SetMessage(mail, d_02187DB4, 2);
    MAIL_SetMessageId(mail, 0x58F);
    MAIL_SetSlot((struct Mail *)MAIL_GetBox(gameData), 0, 0, mail);
    GFL_HEAP_Free(mail);
    STRBUF_Delete(writerName);
    MSGDATA_Delete((struct MsgBank *)msgData);
}

void EVENT_MAPCHANGE_StartSeasonEffect(GameData *gameData)
{
    void *saveControl = GAME_DATA_GetSaveControl(gameData);
    void *partySave = POKEPARTY_GetSaveData(saveControl);
    int season = GAME_DATA_GetSeason(gameData);

    FORMCHANGE_RevertShayminAtNight(gameData, partySave, (u32 *)((u8 *)CONSOLE_STAMP_GetDailyClock(saveControl) + 0x14), season);
}

void *EVENT_MAPCHANGE_TamperLeakA(void)
{
    return GFL_HEAP_Alloc(0x8004, 0x1000, 0, d_02187EA0, 0xe35);
}

void *EVENT_MAPCHANGE_TamperLeakB(void)
{
    return GFL_HEAP_Alloc(0x8004, 0x1000, 0, d_02187EA0, 0xe3a);
}

/*
 * An empty function (`bx lr` plus two bytes of padding) at the end of the
 * file.  EVENT_MAPCHANGE_ChangeFieldEvent passes its address as the hook argument of
 * the ov230 routine OV230_CallSealedBody5, the same way it passes EVENT_MAPCHANGE_TamperLeakA and
 * EVENT_MAPCHANGE_TamperLeakB to OV230_CallSealedBody0 and OV230_CallSealedBody2.
 */
void EVENT_MAPCHANGE_NopHook(void)
{
}
