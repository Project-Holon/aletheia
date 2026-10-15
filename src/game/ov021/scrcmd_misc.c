/*
 * file:     scrcmd_misc.c
 * unit:     yes
 * function: FIELD_G3D_MAPPER_GetTilePlane, SCRCMD_CheckWifiListFlags, SCRCMD_WifiListOperation, SCRCMD_SetWifiFriendNameWord, SCRCMD_MMDL_ICA_CreateProc, SCRCMD_MMDL_ICA_EndProc, SCRCMD_MMDL_ICA_Start, SCRCMD_MMDL_ICA_IsDone, SCRCMD_MMDL_ICA_Update, SCRCMD_MMDL_ICA_Nop, SCRCMD_MMDL_ICA_ApplyFrame, SCRCMD_CreateMmdlIcaProc, SCRCMD_EndMmdlIcaProc, SCRCMD_StartMmdlIcaAnime, SCRCMD_MMDL_ICA_WaitTask, SCRCMD_WaitMmdlIcaAnime, SCRCMD_SUBSCREEN_ChangeModeTask, SCRCMD_ChangeSubscreenMode, SCRCMD_ResetSubscreenMode, SCRCMD_SUBSCREEN_ResetModeTask, EVENT_PERAP_RECORD_Create, EVENT_PERAP_RECORD_Main, EVENT_PERAP_RECORD_OnRecorded, EVENT_PERAP_RECORD_PauseMmdls, EVENT_PERAP_RECORD_ResumeMmdls, EVENT_PERAP_RECORD_CreatePokeIcon, EVENT_PERAP_RECORD_DeletePokeIcon, EVENT_PERAP_RECORD_HopPokeIcon, EVENT_PERAP_RECORD_SetupWindow, EVENT_PERAP_RECORD_Cleanup, SCRCMD_CheckPmsWordPair, FIELD_SOUND_SYSTEM_FindSlotSound, FIELD_SOUND_SYSTEM_IsSlotSoundTracked, SCRCMD_ShowStepMilestoneMessage, FLDEFF_RIPPLE_WarpToZoneStartTask, FLDEFF_RIPPLE_WarpToSpecialLocationTask, FLDEFF_RIPPLE_CreateZoneStartWarpTask, FLDEFF_RIPPLE_CreateSpecialLocationWarpTask, SCRCMD_GetBirthdayMessageIds, SCRCMD_ShowPokeIconWindow, SCRCMD_POKE_ICON_InitWindow, SCRCMD_POKE_ICON_ShowWindow, SCRCMD_POKE_ICON_CreateIcon, SCRCMD_POKE_ICON_DeleteIcon, SCRCMD_POKE_ICON_Task, SCRCMD_CheckBeaconTrainerKey, FIELD_CheckPlayerPositionFree, FIELD_SUBSCREEN_CreateAnimTask, FIELD_SUBSCREEN_AnimTask, SCRCMD_ShowOrClearInfoWindow, SCRCMD_AddTrainerRecordValue, SCRCMD_GetTrainerRecordValue, SCRCMD_GetNpcGreetingMessage, SCRCMD_GREETING_AdjustMessageIdByMisc, SCRCMD_GREETING_AdjustMessageIdByRandom, FIELD_CAMERA_CreateShakeTask, FIELD_CAMERA_ShakeTask, SCRCMD_StartSwapNpcEvent, SCRCMD_StartArcPlayerEffect, SCRCMD_StartArcEffect, SCRCMD_ShowArcModelAt, SCRCMD_WaitArcEffectEnd, SCRCMD_WaitArcEffectPeak
 * address:  0x021D14C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_palace_sys.c at 0x021D14C4 (no __FILE__ anchor between field_saveanime.c and event_game_manual.c; script command handlers).
 *
 * symbols:
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   BMP_WIN_Create  0x020450F0  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_Delete  0x020452E8  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   func_02041B6C  0x02041B6C  arm
 *   gTileNormalTable     0x021DB9A0  data
 *   gTilePlaneDistTable     0x021DC158  data
 *   func_0207C768  0x0207C768  arm
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   GAME_DATA_GetSaveBlockWork  0x02012F8C  thumb
 *   func_020092EC  0x020092EC  thumb
 *   func_020092D8  0x020092D8  thumb
 *   func_02009390  0x02009390  thumb
 *   func_020093D8  0x020093D8  thumb
 *   func_02009418  0x02009418  thumb
 *   func_02009428  0x02009428  thumb
 *   func_020093F0  0x020093F0  thumb
 *   SCRCMD_WORK_GetHeapId  0x0215A5CC  thumb  ov010
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetStringN  0x02045994  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetMapFunc  0x02188D24  thumb  ov021
 *   FIELD_SUBPROC_Start  0x021BB990  thumb  ov021
 *   FIELD_SUBPROC_GetWork  0x021BBA6C  thumb  ov021
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   gMmdlIcaSubprocTemplate     0x021DD5F0  data    ov021  a4
 *   FIELD_SUBPROC_End  0x021BBA1C  thumb  ov021
 *   ICA_ANIME_CreateWithStreamBuffer  0x0201147C  thumb
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   ICA_ANIME_IncFrameLoop  0x02011590  thumb
 *   ICA_ANIME_Delete  0x02011558  thumb
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_InitPosition  0x0216E014  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 *   FLDMMDL_CallDrawProc  0x0216D758  thumb  ov010
 *   gMmdlIcaReleaseMoveBitTable     0x021DD5E0  data    ov021  a4
 *   ICA_ANIME_Get  0x02011610  thumb
 *   ICA_ANIME_Check1638  0x02011638  thumb
 *   VEC_Add  0x0207C9D0  arm
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_SetDirAll  0x0216D60C  thumb  ov010
 *   SCRIPT_WORK_ResetFieldParam  0x02158F58  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   SCRIPT_WORK_SetReturnParam  0x02159104  thumb  ov010
 *   SCRIPT_WORK_GetReturnParam  0x0215910C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb  ov021
 *   FIELD_SUBSCREEN_RequestMode  0x021A0F30  thumb  ov021
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb  ov021
 *   gSubscreenModeTable     0x021DD608  data  a4
 *   SCRIPT_WORK_SetCheckFlag  0x02159144  thumb  ov010
 *   SCRIPT_WORK_ResetCheckFlag  0x02159168  thumb  ov010
 *   MI_CpuFill8  0x02082BCC  arm
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02007B44  0x02007B44  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   PM_VOICE_Play  0x02006984  thumb
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   SND_MIC_Init  0x02006CBC  thumb
 *   SND_MIC_Exit  0x02006D44  thumb
 *   SND_MIC_AddElapsed  0x02006D64  thumb
 *   SND_MIC_IsLimitReached  0x02006D94  thumb
 *   SND_MIC_StartRecording  0x02006DD8  thumb
 *   SND_MIC_StoreRecording  0x02006E18  thumb
 *   func_02007B50  0x02007B50  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   WORDSET_SetSlotMonSpecies  0x0201EEF4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_SOUND_SYSTEM_StartPushTask  0x020295A4  thumb
 *   func_02029620  0x02029620  thumb
 *   TIME_ICON_Create  0x0202EE30  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   UI_SetKeepAwakeFlagsGlobal  0x02034F84  arm
 *   UI_ClearKeepAwakeFlagsGlobal  0x02034FB8  arm
 *   func_02045EC0  0x02045EC0  arm
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgData  0x021904C8  thumb  ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   FIELD_MSGBG_SysWinPrintMsg  0x02190E74  thumb  ov021
 *   FIELD_MSGBG_SysWinPrintStr  0x02190EB8  thumb  ov021
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   FIELD_MSGBG_ClearSysWin  0x02190F7C  thumb  ov021
 *   FIELD_MSGBG_GetSysWinBmpWin  0x02190F9C  thumb  ov021
 *   sub_020056BC   0x020056BC  thumb
 *   sub_02006BD0   0x02006BD0  thumb
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   CLACT_CreateUnit  0x0204B100  arm
 *   func_020185F0  0x020185F0  thumb
 *   POKEGRA_OpenHandle  0x0202D7C8  thumb
 *   func_02017DBC  0x02017DBC  thumb
 *   POKEGRA_RegisterCgrPP  0x0202D934  thumb
 *   POKEGRA_RegisterPalettePP  0x0202D8D0  thumb
 *   POKEGRA_RegisterCellAnimPP  0x0202D9A4  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   CLACT_CreateActor  0x0204B294  arm
 *   gPerapIconActorParam     0x021DD60C  data  a2
 *   CLACT_DeleteActor  0x0204B3B4  arm
 *   CLACT_ReleaseCharacter  0x0204A8D4  arm
 *   CLACT_ReleasePalette  0x0204ADA4  arm
 *   CLACT_ReleaseCellAnim  0x0204AFD8  arm
 *   CLACT_DeleteUnit  0x0204B1CC  arm
 *   CLACT_GetActorSurfacePos  0x0204B454  arm
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 *   BMP_MENUWORK_GetPlttFileId  0x0201F548  thumb
 *   ARC_UTIL_UploadPaletteFromArchive  0x02049B90  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   BMP_MENUWORK_DrawWindowBorder  0x0201F7A8  thumb
 *   PMS_WORD_IsSameGroup  0x020249B0  thumb
 *   gFieldSoundSlotTable     0x021DD614  data  ov021  a4
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   gStepMilestoneTable  0x021DD6BC  data
 *   FIELDMAP_GetTaskManager  0x02188D38  thumb  ov021
 *   FIELD_TASK_CreatePlayerDrawOffsetTween  0x021C7858  thumb  ov021
 *   FIELD_TASK_MANAGER_AddTask  0x021C6DE0  thumb  ov021
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FIELD_PLAYER_SetFormCode  0x021A30A4  thumb  ov021
 *   FIELD_GetPlayerAreaZoneId  0x021CD440  thumb  ov021
 *   EVENT_MAPCHANGE_CreateZoneStartWarpEvent  0x02184FD4  thumb  ov020
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FIELDMAP_GetFog  0x02188C64  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinEaseIn  0x021C7260  thumb  ov021
 *   FIELD_TASK_CreatePlayerSpinLinear  0x021C71D4  thumb  ov021
 *   FIELD_FOG_GetSlope  0x021A01D4  thumb  ov021
 *   FIELD_FOG_FADE_Init  0x021A01FC  thumb  ov021
 *   EVENT_MAPCHANGE_CreateSpecialLocationWarpEvent  0x02184F88  thumb  ov020
 *   func_02008B08  0x02008B08  thumb
 *   FIELD_CLOCK_GetMonth  0x021690D0  thumb  ov010
 *   FIELD_CLOCK_GetDay  0x021690E0  thumb  ov010
 *   func_02008B94  0x02008B94  thumb
 *   func_02008B98  0x02008B98  thumb
 *   func_020056EC  0x020056EC  thumb
 *   gBirthdayTextIdTable     0x021DD6D0  data  a2
 *   POKEGRA_RegisterCgr  0x0202D81C  thumb
 *   POKEGRA_RegisterPalette  0x0202D7D8  thumb
 *   POKEGRA_RegisterCellAnim  0x0202D898  thumb
 *   gPokeIconActorParam     0x021DD710  data  a2
 *   KEY_GetTrg  0x020362DC  arm
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   FIELD_G3D_MAP_CheckBeaconTrainerKey  0x0216BF9C  thumb  ov010
 *   GAME_DATA_GetField158  0x02012844  thumb
 *   EVENTDATA_SYSTEM_GetNpcHeaders  0x02162740  thumb  ov010
 *   EVENTDATA_SYSTEM_GetNpcCount  0x02162744  thumb  ov010
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   ZONEDATA_IsPalaceEnabled  0x02013C60  thumb
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   FLDMMDL_LoadObjCodeParam  0x0216E2E8  thumb  ov010
 *   FIELD_PLAYER_GetNowGridPos  0x021A35FC  thumb  ov021
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELD_PLAYER_SetNogridLocation  0x021A36BC  thumb  ov021
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   EVENTDATA_SYSTEM_SearchAutoPosEvent  0x02162890  thumb  ov010
 *   FIELD_WFBC_DATA_LOCAL_OpenNpcData  0x021867C4  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable  0x02186830  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetPositionPair  0x02186844  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_GetItemPositionPair  0x0218684C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable  0x0218683C  thumb  ov020
 *   FIELD_WFBC_DATA_LOCAL_CloseNpcData  0x02186804  thumb  ov020
 *   FIELD_SUBSCREEN_GetPanelResult  0x021A0F94  thumb  ov021
 *   FIELD_SUBSCREEN_ClearPanelResult  0x021A0FA8  thumb  ov021
 *   VM_ReadU16  0x02011330  thumb
 *   func_02045B38  0x02045B38  arm
 *   BMP_WIN_CreateAt  0x02045180  arm
 *   func_02045CAC  0x02045CAC  arm
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   PRINTSYS_Print  0x0201C7A4  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   BG_SYS_SetTileEntry  0x02041300  arm
 *   func_02008C58  0x02008C58  thumb
 *   func_02008DAC  0x02008DAC  thumb
 *   func_02008DFC  0x02008DFC  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   WORDSET_Callback  0x0201EE60  thumb
 *   GF_STANDARD_SetField00  0x0203F4CC  arm
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   gGreetingCounterTable     0x021DD774  data  ov021
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   gGreetingMiscMessageIds     0x021DD718  data  a4
 *   BEACON_GetBlock  0x0200C0F0  thumb
 *   BEACON_GetFlag  0x0200C234  thumb
 *   gGreetingRandomMessageIds     0x021DD738  data  ov021  a4
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   FIELD_CAMERA_EndDelay  0x0218F0A8  thumb  ov021
 *   FIELD_CAMERA_IsDelayEnabled  0x0218F0E8  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetEyeShift  0x0218ED04  thumb  ov021
 *   FIELD_CAMERA_SetTraceTarget  0x0218EC30  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FX_SinCosTable_     0x020A1B38  data   a2
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   SP_POKE_GIMMICK_StartSwapNpc  0x021F3CFC  thumb  ov059
 *   FIELD_GIMMICK_ARC_EFFECT_StartPlayerEffect  0x021F37B8  thumb  ov064
 *   FIELD_GIMMICK_ARC_EFFECT_StartArcEffect  0x021F3970  thumb  ov064
 *   FIELD_GIMMICK_ARC_EFFECT_ShowArcModelAt  0x021F3A44  thumb  ov064
 *   FIELD_GIMMICK_ARC_EFFECT_CreateWaitEndEvent  0x021F3ADC  thumb
 *   FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent  0x021F3AC0  thumb  ov064
 */
#include "../arm9/script_vm_types.h"
#include "../ov010/script_work_types.h"
#include "../ov010/fldmmdl_types.h"
#include "fieldmap_types.h"
#include "fldmmdl_rail_types.h"
#include "scrcmd_misc_types.h"

typedef int fx32;
typedef int s32;
typedef long long s64;

typedef struct GameSystem GameSystem;
typedef struct GameData GameData;
typedef struct GameEvent GameEvent;
typedef struct ScrcmdWork ScrcmdWork;
typedef struct SaveControl SaveControl;
typedef struct PlayerStatus PlayerStatus;
typedef struct PokemonParam PokemonParam;
typedef struct BoxPokemon BoxPokemon;
typedef struct Party Party;
typedef struct Strbuf Strbuf;
typedef struct WordSet WordSet;
typedef struct MsgData MsgData;
typedef struct MsgBank MsgBank;
typedef struct GfFont GfFont;
typedef struct Bmp Bmp;
typedef struct BmpWin BmpWin;
typedef struct Unit Unit;
typedef struct Actor Actor;
typedef struct IcaAnime IcaAnime;
typedef struct TcbList TcbList;
typedef struct TimeIcon TimeIcon;
typedef struct PerapVoice PerapVoice;
typedef struct FieldCamera FieldCamera;
typedef struct FieldFog FieldFog;
typedef struct FieldSubscreen FieldSubscreen;
typedef struct FieldMsgBg FieldMsgBg;
typedef struct FieldSysWin FieldSysWin;
typedef struct FieldMenuFunc FieldMenuFunc;
typedef struct FieldTaskManager FieldTaskManager;
typedef struct FieldTask FieldTask;
typedef struct FieldmapFunc FieldmapFunc;
typedef struct FieldSubproc FieldSubproc;
typedef struct FieldSubprocTemplate FieldSubprocTemplate;
typedef struct EventDataSystem EventDataSystem;
typedef struct WfbcNpcData WfbcNpcData;
/* Grid cell of a person or an item on the town map (same record as WfbcPosition in ov020/field_wfbc_data_local_types.h, which cannot be included together with fldmmdl_types.h). */
typedef struct WfbcPosition {
    u8 x;
    u8 z;
} WfbcPosition;
typedef struct OccupyInfo OccupyInfo;
typedef struct WifiListSave WifiListSave;
typedef struct BeaconSave BeaconSave;
typedef struct PlayerBirthday PlayerBirthday;
typedef struct StepCounter StepCounter;
typedef struct TrainerRecord TrainerRecord;

/* Packed collision tile of a map block (8 bytes of packed indices plus the attribute word). */
typedef struct PackedTile {
    u16 type : 2;             /* 0 one plane, 2 two planes (split record), other: flat */
    u16 normalIndex : 14;     /* normal triple index in gTileNormalTable */
    u16 distIndex;            /* plane distance index in gTilePlaneDistTable; split record index for type 2 */
    u32 attr : 31;
    u32 diagonalFlip : 1;
} PackedTile;

/* Two planes of a split tile, one per triangle. */
typedef struct PackedTileSplit {
    u16 type : 2;
    u16 normalIndexA : 14;
    u16 normalIndexB;
    u16 distIndexA;
    u16 distIndexB;
} PackedTileSplit;

/* Collision grid of a map block: width and height in tiles, then the tiles, then the split records. */
typedef struct PackedTileMap {
    u16 width;
    u16 height;
    PackedTile tiles[1];
} PackedTileMap;

/* Normal component of the packed normal table, and one (x, y, z) triple of it. */
typedef short NormComp;
typedef struct NormTriple {
    NormComp x;
    NormComp y;
    NormComp z;
} NormTriple;

/* Plane found under a position (fields of the first 12 bytes of CollisionPlane in field_g3d_map_block.c). */
typedef struct TileSurface {
    NormComp normalX;
    NormComp normalY;
    NormComp normalZ;
    NormComp padding06;
    u32 attr;
    fx32 height;
} TileSurface;

typedef struct {
    u16 v[4];
} ClactInitParam;

typedef struct {
    s16 x;
    s16 y;
} SpritePos;

/* Sound effect slot table entry: sound id and whether the field sound system tracks its slot. */
typedef struct FieldSoundSlotEntry {
    u32 soundId;
    u32 tracked;
} FieldSoundSlotEntry;

struct Milestone {
    u16 count;
    u16 msg;
};

typedef struct {
    u16 textId[31];
} TextIdTable;

typedef struct RtcTime {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

/* Rail place of a field model header (MmdlHeader.pos when posType is 1). */
typedef struct MmdlHeaderRailPos {
    u16 railIndex;
    u16 lineGrid;
    s16 widthGrid;
} MmdlHeaderRailPos;

typedef union MmdlHeaderPos {
    MmdlHeaderGridPos grid;
    MmdlHeaderRailPos rail;
} MmdlHeaderPos;

typedef struct {
    u32 idA;
    u32 idB;
    u32 digitsA;
    u32 digitsB;
} CounterMsgEntry;

typedef struct CameraShakeWork {
    CameraShakeParams params;
    const VecFx32 *pos;
} CameraShakeWork;

#define NRM(i) ((NormComp *)gTileNormalTable)[i]

extern GameData *ICA_ANIME_GetField1C(const GameSystem *gameSystem);
extern PlayerStatus *func_02012944(GameData *gameData);
extern u8 func_02008550(const PlayerStatus *status);
extern void ARC_TOOL_DeleteHandle(void *handle);
extern struct FieldPlayer *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern FieldCamera *FIELDMAP_GetCamera(FieldMap *fieldMap);
extern void FIELD_PLAYER_GetPos(struct FieldPlayer *player, VecFx32 *out);
extern BmpWin *BMP_WIN_Create(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u8 allocDir);
extern Bmp *BMP_WIN_GetBmp(BmpWin *win);
extern void BMP_Clear(Bmp *bmp, u8 value);
extern void BMP_WIN_TransferChars(BmpWin *win);
extern u32 BMP_WIN_Delete(BmpWin *win);
extern void func_02041B6C(u32 bgLayer);
extern void BMP_WIN_MakeScreen(BmpWin *win);
extern u32 func_0207C768(u32 a, u32 b);
extern struct ScriptWork *SCRCMD_WORK_GetScriptWork(ScrcmdWork *cmdWork);
extern GameSystem *SCRCMD_WORK_GetGameSystem(ScrcmdWork *cmdWork);
extern GameData *SCRCMD_WORK_GetGameData(ScrcmdWork *cmdWork);
extern u16 SCRIPT_WORK_ReadWorkValue(ScriptVm *vm, ScrcmdWork *cmdWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, ScrcmdWork *cmdWork);
extern WifiListSave *GAME_DATA_GetSaveBlockWork(GameData *gameData);
extern u8 func_020092EC(const WifiListSave *wifiList);
extern u8 func_020092D8(const WifiListSave *wifiList);
extern u16 *func_02009390(WifiListSave *wifiList, int index);
extern u32 func_020093D8(const WifiListSave *wifiList);
extern u32 func_02009418(const WifiListSave *wifiList);
extern void func_02009428(WifiListSave *wifiList, int value);
extern void func_020093F0(WifiListSave *wifiList, int value);
extern u16 SCRCMD_WORK_GetHeapId(ScrcmdWork *cmdWork);
extern WordSet *SCRIPT_WORK_GetWordSet(struct ScriptWork *scriptWork);
extern Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetStringN(Strbuf *strbuf, const u16 *srcChars, u32 charCount);
extern void WORDSET_SetSlotTag(WordSet *words, u32 slot, Strbuf *src, u32 grammarCase, u32 isPlural, u32 gender);
extern void STRBUF_Delete(Strbuf *strbuf);
extern MmdlSys *FIELDMAP_GetMmdlSys(FieldMap *fieldMap);
extern FieldmapFunc *FIELDMAP_GetMapFunc(FieldMap *fieldMap);
extern FieldSubproc *FIELD_SUBPROC_Start(int overlayId, FieldmapFunc *mgr, const FieldSubprocTemplate *tmpl);
extern void *FIELD_SUBPROC_GetWork(const FieldSubproc *proc);
extern Mmdl *FLDMMDL_SysSearchObjId(MmdlSys *sys, u32 objId);
extern void FIELD_SUBPROC_End(FieldSubproc *proc);
extern IcaAnime *ICA_ANIME_CreateWithStreamBuffer(u32 heapId, u32 arcId, u32 dataId, u32 bufFrameNum, void *buffer, u32 bufferSize);
extern void FLDMMDL_SetMoveBit(Mmdl *mmdl, u32 bit);
extern u32 ICA_ANIME_IncFrameLoop(IcaAnime *anime, s32 step);
extern void ICA_ANIME_Delete(IcaAnime *anime);
extern void FLDMMDL_GetPos(const Mmdl *mmdl, MmdlVec *out);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern void FLDMMDL_InitPosition(Mmdl *mmdl, const MmdlVec *pos, int dir);
extern void FLDMMDL_ClearMoveBit(Mmdl *mmdl, u32 bit);
extern void FLDMMDL_CallDrawProc(Mmdl *mmdl);
extern u32 ICA_ANIME_Get(IcaAnime *anime, VecFx32 *trans);
extern u32 ICA_ANIME_Check1638(IcaAnime *anime, VecFx32 *rot);
extern void VEC_Add(const VecFx32 *a, const VecFx32 *b, VecFx32 *ab);
extern void FLDMMDL_SetPos(Mmdl *mmdl, const MmdlVec *pos);
extern void FLDMMDL_SetDirAll(Mmdl *mmdl, int dir);
extern ScriptFieldParam *SCRIPT_WORK_ResetFieldParam(struct ScriptWork *scriptWork);
extern u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern void SCRIPT_WORK_SetReturnParam(struct ScriptWork *scriptWork, u32 param);
extern u32 SCRIPT_WORK_GetReturnParam(struct ScriptWork *scriptWork);
extern GameEvent *func_020122C0(GameSystem *owner, GameEvent *parent, void *proc, u32 workSize);
extern void *func_020124E8(GameEvent *event);
extern void SCRIPT_SYS_CallEvent(struct ScriptWork *scriptWork, GameEvent *event);
extern int FIELD_SUBSCREEN_IsIdle(FieldSubscreen *subscreen);
extern int FIELD_SUBSCREEN_RequestMode(FieldSubscreen *subscreen, u32 mode);
extern FieldSubscreen *FIELDMAP_GetSubscreen(FieldMap *fieldMap);
extern void SCRIPT_WORK_SetCheckFlag(int flagId);
extern void SCRIPT_WORK_ResetCheckFlag(int flagId);
extern void MI_CpuFill8(void *dst, int value, int size);
extern SaveControl *GAME_DATA_GetSaveControl(GameData *gameData);
extern PerapVoice *func_02007B44(SaveControl *save);
extern Party *GAME_DATA_GetMyParty(GameData *gameData);
extern PokemonParam *POKEPARTY_GetMember(Party *party, u32 pos);
extern FieldMsgBg *FIELDMAP_GetMsgBg(FieldMap *fieldMap);
extern MsgData *FIELD_MSGBG_CreateMsgData(FieldMsgBg *msgBg, u32 fileId);
extern FieldSysWin *FIELD_MSGBG_CreateBottomSysWin(FieldMsgBg *msgBg, MsgData *msgData);
extern WordSet *GF_FONT_Create_EC64(u16 heapId);
extern int func_02007B50(PerapVoice *perapVoice);
extern void FIELD_MSGBG_SysWinPrintMsg(FieldSysWin *sysWin, u32 x, u16 y, u32 msgId);
extern u32 FIELD_MSGBG_SysWinMain(FieldSysWin *sysWin);
extern FieldMenuFunc *FIELD_MSGBG_CreateYesNoMenu(FieldMsgBg *msgBg, u32 cursorPos);
extern int FIELD_MSGBG_YesNoMenuMain(FieldMenuFunc *menu);
extern int FIELD_MSGBG_DeleteMenuFunc(FieldMenuFunc *menu);
extern void FIELD_MSGBG_ClearSysWin(FieldSysWin *sysWin);
extern void UI_SetKeepAwakeFlagsGlobal(u8 flags);
extern u32 SND_MIC_Init(u32 heapId);
extern TcbList *sub_020056BC(u32 mic);
extern BmpWin *FIELD_MSGBG_GetSysWinBmpWin(FieldSysWin *sysWin);
extern TimeIcon *TIME_ICON_Create(TcbList *taskList, BmpWin *refWin, u8 fillColor, u8 waitInterval, volatile u16 heapId);
extern void SND_MIC_AddElapsed(u32 ticks);
extern u32 SND_MIC_IsLimitReached(void);
extern void TIME_ICON_Delete(TimeIcon *icon);
extern GameEvent *FIELD_SOUND_SYSTEM_StartPushTask(GameSystem *gameSystem, u32 fadeOutFrames);
extern void GAME_EVENT_CallEvent(GameEvent *parent, GameEvent *child);
extern u32 SND_MIC_StartRecording(void *callback, void *arg);
extern Strbuf *func_02045EC0(MsgData *msgData, u32 index);
extern void WORDSET_SetSlotMonSpecies(WordSet *words, u32 slot, PokemonParam *mon);
extern void WORDSET_CopyTaggedText(WordSet *words, Strbuf *dst, Strbuf *src);
extern void FIELD_MSGBG_SysWinPrintStr(FieldSysWin *sysWin, u32 x, u16 y, Strbuf *str);
extern void SND_MIC_Exit(void);
extern void UI_ClearKeepAwakeFlagsGlobal(u8 flags);
extern GameEvent *func_02029620(GameSystem *gameSystem, u32 a, u32 b);
extern void SND_MIC_StoreRecording(PerapVoice *perapVoice);
extern void PM_VOICE_GetPerapVoiceSave(void **out);
extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, void *perapVoiceSave);
extern u32 sub_02006BD0(u32 slot);
extern u32 WORDSET_DeleteStrbufED04(WordSet *words);
extern int FIELD_MSGBG_DeleteSysWin(FieldSysWin *sysWin);
extern u32 FIELD_MSGBG_DeleteMsgData(MsgData *msgData);
extern FieldMap *ICA_ANIME_GetField20(const GameSystem *gameSystem);
extern void FLDMMDL_SysPauseMove(MmdlSys *sys);
extern void FLDMMDL_SysResumeMove(MmdlSys *sys);
extern Unit *CLACT_CreateUnit(int count, u8 priority, u32 heapId);
extern BoxPokemon *func_020185F0(PokemonParam *pp);
extern void *POKEGRA_OpenHandle(u32 heapId);
extern u32 func_02017DBC(BoxPokemon *box);
extern int POKEGRA_RegisterCgrPP(void *handle, BoxPokemon *box, int dir, int drawType, unsigned short heapId);
extern int POKEGRA_RegisterPalettePP(void *handle, BoxPokemon *box, int dir, int drawType, unsigned short palOffset, unsigned short heapId);
extern u32 POKEGRA_RegisterCellAnimPP(BoxPokemon *box, u32 dir, u32 mapping, u32 unusedArg, u16 heapId);
extern u32 func_02017DE4(BoxPokemon *box, u32 didDecode);
extern Actor *CLACT_CreateActor(Unit *unit, u32 charRes, u32 palRes, u32 cellRes, const ClactInitParam *param, u16 priority, u16 heapId);
extern void CLACT_ReleaseCharacter(u32 idx);
extern void CLACT_ReleasePalette(u32 idx);
extern void CLACT_ReleaseCellAnim(u32 idx);
extern u32 CLACT_DeleteUnit(Unit *unit);
extern void CLACT_DeleteActor(Actor *actor);
extern void CLACT_GetActorSurfacePos(Actor *actor, SpritePos *out, u16 space);
extern void CLACT_AddActorSurfacePos(Actor *actor, const SpritePos *delta, u32 which);
extern u8 BMP_MENUWORK_GetPlttFileId(int index);
extern void ARC_UTIL_UploadPaletteFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void BMP_MENUWORK_DrawWindow(BmpWin *win, int commitMode, u16 tileBase, u32 palette);
extern void BMP_MENUWORK_DrawWindowBorder(BmpWin *win, u32 commitMode);
extern int PMS_WORD_IsSameGroup(u32 a, u16 b);
extern StepCounter *func_02008854(SaveControl *save);
extern u16 func_02008990(const StepCounter *counter);
extern GameEvent *SCRIPT_SYS_CreateScriptEventSimple(void *fieldSys, u16 scriptId, void *target, int reserved);
extern FieldTaskManager *FIELDMAP_GetTaskManager(FieldMap *fieldMap);
extern FieldTask *FIELD_TASK_CreatePlayerDrawOffsetTween(FieldMap *fieldMap, int frames, const VecFx32 *offset);
extern void FIELD_TASK_MANAGER_AddTask(FieldTaskManager *manager, FieldTask *task, FieldTask *prerequisite);
extern void GFL_USE_PlaySeDefaultVolume(u32 seqNo);
extern int GFL_USE_GetSeSlot(u32 seqNo);
extern int GFL_USE_IsSeSlotBusy(u32 slot);
extern Mmdl *FIELD_PLAYER_GetMmdl(struct FieldPlayer *player);
extern void FIELD_PLAYER_SetFormCode(struct FieldPlayer *player, u32 formCode);
extern int FIELD_GetPlayerAreaZoneId(FieldMap *fieldMap, u16 *zoneIdOut);
extern GameEvent *EVENT_MAPCHANGE_CreateZoneStartWarpEvent(GameSystem *gameSystem, u16 zoneId);
extern void FLDMMDL_SetAcmd(Mmdl *mmdl, u16 code);
extern int FLDMMDL_CheckEndAcmd(Mmdl *mmdl);
extern FieldFog *FIELDMAP_GetFog(FieldMap *fieldMap);
extern FieldTask *FIELD_TASK_CreatePlayerSpinEaseIn(FieldMap *fieldMap, u16 frames, int spins);
extern FieldTask *FIELD_TASK_CreatePlayerSpinLinear(FieldMap *fieldMap, u32 frames, u32 spins);
extern u32 FIELD_FOG_GetSlope(FieldFog *fog);
extern void FIELD_FOG_FADE_Init(FieldFog *fog, u32 endOffset, u32 endSlope, u32 frames);
extern GameEvent *EVENT_MAPCHANGE_CreateSpecialLocationWarpEvent(GameSystem *gameSystem);
extern PlayerBirthday *func_02008B08(SaveControl *save);
extern int FIELD_CLOCK_GetMonth(GameData *gameData);
extern int FIELD_CLOCK_GetDay(GameData *gameData);
extern u8 func_02008B94(const PlayerBirthday *birthday);
extern u8 func_02008B98(const PlayerBirthday *birthday);
extern u32 func_020056EC(u32 limit);
extern u32 POKEGRA_RegisterCgr(void *handle, u32 species, u32 form, u32 isEgg, u32 gender, u32 e, u32 f, u32 flags, u32 i, u32 heapId);
extern int POKEGRA_RegisterPalette(void *handle, u32 species, u32 form, u32 isEgg, u32 gender, u32 e, u32 f, u32 g, unsigned short h, unsigned short heapId);
extern u32 POKEGRA_RegisterCellAnim(u32 species, u32 form, u32 isEgg, u32 gender, u32 e, u32 f, u32 g, u32 h, u32 heapId);
extern u32 KEY_GetTrg(void);
extern void *GAME_DATA_GetMiscSave(GameData *gameData);
extern int FIELD_G3D_MAP_CheckBeaconTrainerKey(void *miscSave, int slot, PlayerStatus *status);
extern EventDataSystem *GAME_DATA_GetField158(const GameData *gameData);
extern MmdlHeader *EVENTDATA_SYSTEM_GetNpcHeaders(EventDataSystem *system);
extern u16 EVENTDATA_SYSTEM_GetNpcCount(EventDataSystem *system);
extern u16 FIELDMAP_GetZoneId(FieldMap *fieldMap);
extern u32 ZONEDATA_IsPalaceEnabled(u32 zoneId);
extern u32 FIELD_PLAYER_GetFormCode(struct FieldPlayer *player);
extern void FLDMMDL_LoadObjCodeParam(const MmdlSys *sys, u32 objCode, MmdlObjCodeParam *out);
extern void FIELD_PLAYER_GetNowGridPos(struct FieldPlayer *player, u16 *gridX, u16 *gridY, u16 *gridZ);
extern u32 FIELDMAP_GetMoveKind(FieldMap *fieldMap);
extern void FIELD_PLAYER_SetNogridLocation(struct FieldPlayer *player, RailLocation *out);
extern void *GAME_DATA_GetEventWork(const GameData *gameData);
extern void *EVENTDATA_SYSTEM_SearchAutoPosEvent(EventDataSystem *system, void *eventWork, VecFx32 *pos);
extern WfbcNpcData *FIELD_WFBC_DATA_LOCAL_OpenNpcData(int fileId, int heapId);
extern WfbcPosition *FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(WfbcNpcData *npcData, int cityType, unsigned int heapId);
extern WfbcPosition *FIELD_WFBC_DATA_LOCAL_GetPositionPair(WfbcPosition *positions, int index);
extern WfbcPosition *FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(WfbcPosition *positions, int index);
extern void FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(WfbcPosition *positions);
extern void FIELD_WFBC_DATA_LOCAL_CloseNpcData(WfbcNpcData *npcData);
extern int FIELD_SUBSCREEN_GetPanelResult(FieldSubscreen *subscreen);
extern void FIELD_SUBSCREEN_ClearPanelResult(FieldSubscreen *subscreen);
extern u16 VM_ReadU16(ScriptVm *vm);
extern MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern BmpWin *BMP_WIN_CreateAt(u32 bgLayer, u32 posX, u32 posY, u8 width, u8 height, u8 palette, u32 charOffset);
extern void func_02045CAC(MsgBank *bank, u32 index, Strbuf *dest);
extern GfFont *FIELD_MSGBG_GetFont(FieldMsgBg *msgBg);
extern void PRINTSYS_Print(Bmp *bmp, s16 x, s16 y, Strbuf *str, GfFont *font);
extern u32 MSGDATA_Delete(MsgBank *bank);
extern void BG_SYS_SetTileEntry(u32 layer, u16 value, u8 x0, u8 y0, u8 w, u8 h, u8 mode);
extern TrainerRecord *func_02008C58(SaveControl *save);
extern u32 func_02008DAC(TrainerRecord *record, int index, u32 delta);
extern u32 func_02008DFC(TrainerRecord *record, int index);
extern void WORDSET_SetSlotMyStatus(WordSet *words, u32 slot, PlayerStatus *status);
extern u32 POKEPARTY_GetCount(Party *party);
extern u32 func_02017E1C(PokemonParam *pp, u32 paramId, u32 arg);
extern void WORDSET_Callback(WordSet *words, u32 slot, u16 speciesId);
extern void GF_STANDARD_SetField00(RtcTime *time);
extern TrainerRecord *GAME_DATA_GetTrainerRecord(GameData *gameData);
extern void WORDSET_SetSlotNumber(WordSet *words, u32 slot, u32 number, u32 topDigitIndex, u32 padMode, u32 isHalfWidth);
extern BeaconSave *BEACON_GetBlock(SaveControl *save);
extern int BEACON_GetFlag(BeaconSave *beacon);
extern GameSystem *GAME_EVENT_GetGameSystem(GameEvent *event);
extern void FIELD_CAMERA_EndDelay(FieldCamera *camera);
extern u32 FIELD_CAMERA_IsDelayEnabled(FieldCamera *camera);
extern const VecFx32 *FIELD_CAMERA_GetTraceTarget(FieldCamera *camera);
extern void FIELD_CAMERA_StopTargetTrace(FieldCamera *camera);
extern void FIELD_CAMERA_SetEyeShift(FieldCamera *camera, const VecFx32 *shift);
extern void FIELD_CAMERA_SetTraceTarget(FieldCamera *camera, const VecFx32 *target);
extern void FIELD_CAMERA_RestartDelay(FieldCamera *camera);
extern void FIELD_CAMERA_SetTarget(FieldCamera *camera, const VecFx32 *target);
extern OccupyInfo *SCRCMD_WORK_GetOccupyInfo(ScrcmdWork *cmdWork);
extern GameEvent *SP_POKE_GIMMICK_StartSwapNpc(GameSystem *gameSystem, VecFx32 *pos, u32 removeObjectId, u32 addObjectId);
extern GameEvent *FIELD_GIMMICK_ARC_EFFECT_StartPlayerEffect(GameSystem *gameSystem);
extern GameEvent *FIELD_GIMMICK_ARC_EFFECT_StartArcEffect(GameSystem *gameSystem, const VecFx32 *startPos, const VecFx32 *endPos, int arcHeight, int arcParam);
extern void FIELD_GIMMICK_ARC_EFFECT_ShowArcModelAt(GameSystem *gameSystem, VecFx32 *pos);
extern GameEvent *FIELD_GIMMICK_ARC_EFFECT_CreateWaitEndEvent(GameSystem *gameSystem);
extern GameEvent *FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent(GameSystem *gameSystem);

void FIELD_G3D_MAPPER_GetTilePlane(TileSurface *out, int idx, PackedTileMap *map, VecFx32 *pos, fx32 size, fx32 base);
int SCRCMD_CheckWifiListFlags(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WifiListOperation(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SetWifiFriendNameWord(ScriptVm *vm, ScrcmdWork *cmdWork);
MmdlIcaWork *SCRCMD_MMDL_ICA_CreateProc(FieldMap *fieldMap, u16 mmdlId, VecFx32 *offset, u16 heapId);
void SCRCMD_MMDL_ICA_EndProc(MmdlIcaWork *work);
void SCRCMD_MMDL_ICA_Start(MmdlIcaWork *work, u32 animKind);
u32 SCRCMD_MMDL_ICA_IsDone(MmdlIcaWork *work, u32 unusedArg1, u32 unusedArg2, u32 unusedArg3);
void SCRCMD_MMDL_ICA_Update(u32 event, u32 state, MmdlIcaWork *work);
void SCRCMD_MMDL_ICA_Nop(void);
void SCRCMD_MMDL_ICA_ApplyFrame(IcaAnime *icaAnime, Mmdl *mmdl, VecFx32 *offset);
int SCRCMD_CreateMmdlIcaProc(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_EndMmdlIcaProc(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StartMmdlIcaAnime(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_MMDL_ICA_WaitTask(u32 event, u32 state, MmdlIcaWaitWork *work, u32 arg);
int SCRCMD_WaitMmdlIcaAnime(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SUBSCREEN_ChangeModeTask(GameEvent *event, int *seq, SubscreenModeWork *work);
int SCRCMD_ChangeSubscreenMode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_ResetSubscreenMode(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_SUBSCREEN_ResetModeTask(u32 *eventWords, int *seq);
GameEvent *EVENT_PERAP_RECORD_Create(GameSystem *gameSystem, FieldMap *fieldMap, u32 partySlot);
int EVENT_PERAP_RECORD_Main(GameEvent *event, int *seq, PerapRecordWork *work);
void EVENT_PERAP_RECORD_OnRecorded(void *unused, int *done);
void EVENT_PERAP_RECORD_PauseMmdls(PerapRecordWork *work);
void EVENT_PERAP_RECORD_ResumeMmdls(PerapRecordWork *work);
void EVENT_PERAP_RECORD_CreatePokeIcon(PerapRecordWork *work);
int EVENT_PERAP_RECORD_DeletePokeIcon(PerapRecordWork *work);
int EVENT_PERAP_RECORD_HopPokeIcon(PerapRecordWork *work);
void EVENT_PERAP_RECORD_SetupWindow(PerapRecordWork *work);
int EVENT_PERAP_RECORD_Cleanup(PerapRecordWork *work);
int SCRCMD_CheckPmsWordPair(ScriptVm *vm, ScrcmdWork *cmdWork);
int FIELD_SOUND_SYSTEM_FindSlotSound(u32 soundId);
int FIELD_SOUND_SYSTEM_IsSlotSoundTracked(u32 soundId);
GameEvent *SCRCMD_ShowStepMilestoneMessage(GameSystem *gameSystem, FieldMap *fieldMap);
int FLDEFF_RIPPLE_WarpToZoneStartTask(GameEvent *event, int *seq, RippleWarpWork *work);
int FLDEFF_RIPPLE_WarpToSpecialLocationTask(GameEvent *event, int *seq, RippleWarpWork *work);
GameEvent *FLDEFF_RIPPLE_CreateZoneStartWarpTask(GameSystem *gameSystem, FieldMap *fieldMap);
GameEvent *FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(GameSystem *gameSystem, FieldMap *fieldMap, u32 useSpin);
int SCRCMD_GetBirthdayMessageIds(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_ShowPokeIconWindow(ScriptVm *vm, ScrcmdWork *cmdWork);
void SCRCMD_POKE_ICON_InitWindow(PokeIconWork *work);
void SCRCMD_POKE_ICON_ShowWindow(PokeIconWork *work);
void SCRCMD_POKE_ICON_CreateIcon(PokeIconWork *work, int species, int form, int isEgg, int gender, int charFlags);
int SCRCMD_POKE_ICON_DeleteIcon(PokeIconWork *work);
u32 SCRCMD_POKE_ICON_Task(GameEvent *event, u32 *state, PokeIconWork *work);
u32 SCRCMD_CheckBeaconTrainerKey(ScriptVm *vm, ScrcmdWork *cmdWork);
int FIELD_CheckPlayerPositionFree(GameSystem *gameSystem);
GameEvent *FIELD_SUBSCREEN_CreateAnimTask(GameSystem *gameSystem);
u32 FIELD_SUBSCREEN_AnimTask(GameEvent *event, u32 *state, SubscreenAnimWork *work);
int SCRCMD_ShowOrClearInfoWindow(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_AddTrainerRecordValue(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetTrainerRecordValue(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_GetNpcGreetingMessage(ScriptVm *vm, ScrcmdWork *cmdWork);
u32 SCRCMD_GREETING_AdjustMessageIdByMisc(GameData *gameData, int messageId);
u32 SCRCMD_GREETING_AdjustMessageIdByRandom(GameData *gameData, u32 messageId, int fixedMessage);
GameEvent *FIELD_CAMERA_CreateShakeTask(GameSystem *gameSystem, CameraShakeParams *params);
int FIELD_CAMERA_ShakeTask(GameEvent *event, int *state);
u32 SCRCMD_StartSwapNpcEvent(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_StartArcPlayerEffect(ScriptVm *vm, ScrcmdWork *cmdWork);
u32 SCRCMD_StartArcEffect(ScriptVm *vm, ScrcmdWork *cmdWork);
u32 SCRCMD_ShowArcModelAt(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitArcEffectEnd(ScriptVm *vm, ScrcmdWork *cmdWork);
int SCRCMD_WaitArcEffectPeak(ScriptVm *vm, ScrcmdWork *cmdWork);
extern NormTriple gTileNormalTable[];
extern const fx32 gTilePlaneDistTable[];
extern const FieldSubprocTemplate gMmdlIcaSubprocTemplate;
extern u32 gMmdlIcaReleaseMoveBitTable[];
extern u32 gSubscreenModeTable[];
extern ClactInitParam gPerapIconActorParam;
extern FieldSoundSlotEntry gFieldSoundSlotTable[];
extern const struct Milestone gStepMilestoneTable[5];
extern TextIdTable gBirthdayTextIdTable;
extern ClactInitParam gPokeIconActorParam;
extern const CounterMsgEntry gGreetingCounterTable[];
extern u32 gGreetingMiscMessageIds[];
extern u32 gGreetingRandomMessageIds[];
extern const s16 FX_SinCosTable_[];

static inline fx32 FX_MUL(fx32 a, fx32 b)
{
    return (fx32)(((s64)a * b + 0x800LL) >> 12);
}

static inline void TileSurface_SetNormal(TileSurface *surface, int x, int y, int z)
{
    surface->normalX = x;
    surface->normalY = y;
    surface->normalZ = z;
}

/*
 * The a/0/0/8 grid tile reader (see docs/notes/func_021D14C4_tile_record_reader.c.txt):
 * picks the tile under pos, writes its surface normal, attribute word and
 * solved height into out[idx].
 *
 * Shape notes, each one measured:
 * - the normal table is read through an NormComp pointer cast of a differently
 *   typed object, so mwcc cannot prove it disjoint from out: the setter's
 *   right-to-left arguments then stay as z, y, x temporaries (y spilled) and
 *   the pool word is reloaded per access. A plain NormComp array sinks the loads.
 * - the height table is const (its load is scheduled above the z store).
 * - the tile record is read through a volatile pointer: the image reloads
 *   the norm halfword after the type test instead of reusing the type load;
 *   no non-volatile spelling (casts, unions, other access paths, const)
 *   stopped mwcc from CSE-ing the two halfword loads.
 * - the row index is x/0x10000 + w * (z/0x10000) in that operand order;
 *   p (= &out[idx]) is live into the tail, where only the x read uses it.
 */
void FIELD_G3D_MAPPER_GetTilePlane(TileSurface *out, int idx, PackedTileMap *map, VecFx32 *pos, fx32 size, fx32 base)
{
    fx32 half = size / 2;
    fx32 z = pos->z + half;
    fx32 x = pos->x + half;
    int fracX = x % 0x10000;
    int fracZ = z % 0x10000;
    int tileIndex = x / 0x10000 + ((size >> 12) / 16) * (z / 0x10000);
    volatile PackedTile *tile = &map->tiles[tileIndex];
    fx32 planeDist;
    TileSurface *surface;
    u8 tileType = tile->type;

    if (tileType == 0) {
        int normalOffset = tile->normalIndex * 3;
        int distIndex = tile->distIndex;
        TileSurface_SetNormal(surface = &out[idx], NRM(normalOffset), NRM(normalOffset + 1), -NRM(normalOffset + 2));
        planeDist = gTilePlaneDistTable[distIndex];
    } else if (tileType == 2) {
        PackedTileSplit *split = (PackedTileSplit *)(map->tiles + map->width * map->height) + tile->distIndex;
        int normalOffset;
        int distIndex;
        if (tile->diagonalFlip == 0) {
            if (fracX + fracZ < 0x10000) {
                normalOffset = split->normalIndexA * 3;
                distIndex = split->distIndexA;
            } else {
                normalOffset = split->normalIndexB * 3;
                distIndex = split->distIndexB;
            }
        } else {
            if (fracX > fracZ) {
                normalOffset = split->normalIndexA * 3;
                distIndex = split->distIndexA;
            } else {
                normalOffset = split->normalIndexB * 3;
                distIndex = split->distIndexB;
            }
        }
        TileSurface_SetNormal(surface = &out[idx], NRM(normalOffset), NRM(normalOffset + 1), -NRM(normalOffset + 2));
        planeDist = gTilePlaneDistTable[distIndex];
    } else {
        TileSurface_SetNormal(surface = &out[idx], 0, 0x1000, 0);
        planeDist = 0;
    }
    {
        fx32 normalY = out[idx].normalY;
        fx32 dotZ = FX_MUL(out[idx].normalZ, pos->z);
        fx32 dotX = FX_MUL(surface->normalX, pos->x);
        out[idx].attr = tile->attr;
        out[idx].height = base + func_0207C768(-(planeDist + (dotX + dotZ)), normalY);
    }
}

/*
 * GAME_DATA_GetSaveBlockWork (arm9 Thumb leaf) is filed as src/matched/arm9/GAME_DATA_GetSaveBlockWork.c
 * to give the witness.
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_CheckWifiListFlags(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameData *gameData;
    u32 listKind;
    u16 *resultVar;
    WifiListSave *wifiList;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    listKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    wifiList = GAME_DATA_GetSaveBlockWork(gameData);
    if (listKind == 0) {
        if (func_020092EC(wifiList) == 1 && func_020092D8(wifiList) == 1) {
            *resultVar = 1;
        } else {
            *resultVar = 0;
        }
    }
    return 0;
}

int SCRCMD_WifiListOperation(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameData *gameData;
    u32 operation;
    u32 operand;
    u16 *resultVar;
    u8 i;
    u16 *entry;
    WifiListSave *wifiList;

    SCRCMD_WORK_GetScriptWork(cmdWork);
    SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    operation = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    operand = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    wifiList = GAME_DATA_GetSaveBlockWork(gameData);
    switch (operation) {
    case 0:
        *resultVar = 1;
        for (i = 0; i < 5; i++) {
            entry = func_02009390(wifiList, i);
            if (entry == 0) {
                *resultVar = 0;
            } else if (entry[0] == 0x7E || entry[0] == 0) {
                *resultVar = 0;
            }
        }
        break;
    case 1:
        if (func_020093D8(wifiList) == 0x7F) {
            *resultVar = 0;
        } else {
            *resultVar = 1;
        }
        break;
    case 2:
        if (func_02009418(wifiList) == 1) {
            *resultVar = 1;
        } else {
            *resultVar = 0;
        }
        break;
    case 3:
        func_02009428(wifiList, 0);
        break;
    case 4:
        func_020093F0(wifiList, operand);
        break;
    }
    return 0;
}

int SCRCMD_SetWifiFriendNameWord(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    GameData *gameData;
    u32 heapId;
    WordSet *wordSet;
    u32 wordSlot;
    u32 entryIndex;
    u16 *entry;
    Strbuf *nameBuf;
    WifiListSave *wifiList;

    SCRCMD_WORK_GetGameSystem(cmdWork);
    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    heapId = SCRCMD_WORK_GetHeapId(cmdWork);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    wifiList = GAME_DATA_GetSaveBlockWork(gameData);
    wordSlot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    entryIndex = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    entry = func_02009390(wifiList, entryIndex);
    if (entry != 0 && entry[0] != 0x7E && entry[0] != 0) {
        nameBuf = STRBUF_Create(0xE, heapId);
        STRBUF_SetStringN(nameBuf, entry + 1, 0xD);
        WORDSET_SetSlotTag(wordSet, wordSlot, nameBuf, 0, 0, 2);
        STRBUF_Delete(nameBuf);
    }
    return 0;
}

/*
 * The spilled second parameter is a u16 (FLDMMDL_SysSearchObjId compares its id
 * against FLDMMDL_GetObjId's u16): as u32/int its reload from [sp] is hoisted
 * above the struct copy's last store. FIELD_SUBPROC_GetWork takes the result of
 * FIELD_SUBPROC_Start (the bl has no argument setup of its own).
 *
 * Addresses are Black-image addresses.
 */
MmdlIcaWork *SCRCMD_MMDL_ICA_CreateProc(FieldMap *fieldMap, u16 mmdlId, VecFx32 *offset, u16 heapId)
{
    MmdlSys *mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    FieldmapFunc *subprocMgr = FIELDMAP_GetMapFunc(fieldMap);
    FieldSubproc *handle = FIELD_SUBPROC_Start(-1, subprocMgr, &gMmdlIcaSubprocTemplate);
    MmdlIcaWork *work = FIELD_SUBPROC_GetWork(handle);

    work->subprocHandle = handle;
    work->heapId = heapId;
    work->offset = *offset;
    work->mmdl = FLDMMDL_SysSearchObjId(mmdlSys, mmdlId);
    return work;
}

/*
 * Tail call on the word at +0x188.
 *
 * Addresses are Black-image addresses.
 */
void SCRCMD_MMDL_ICA_EndProc(MmdlIcaWork *work)
{
    FIELD_SUBPROC_End(work->subprocHandle);
}

void SCRCMD_MMDL_ICA_Start(MmdlIcaWork *work, u32 animKind)
{
    work->icaAnime = ICA_ANIME_CreateWithStreamBuffer(work->heapId, 0xCB, animKind, 10, work->icaBuffer, 0x180);
    work->state = 1;
    work->animKind = animKind;
    SCRCMD_MMDL_ICA_ApplyFrame(work->icaAnime, work->mmdl, &work->offset);
    FLDMMDL_SetMoveBit(work->mmdl, 0x8000);
}

u32 SCRCMD_MMDL_ICA_IsDone(MmdlIcaWork *work, u32 unusedArg1, u32 unusedArg2, u32 unusedArg3)
{
    if (work->state == 0) {
        return 1;
    }
    return 0;
}

void SCRCMD_MMDL_ICA_Update(u32 event, u32 state, MmdlIcaWork *work)
{
    MmdlVec pos;

    if (work->state == 0) {
        return;
    }
    if (work->state == 1) {
        if (ICA_ANIME_IncFrameLoop(work->icaAnime, 0x1000) == 0) {
            SCRCMD_MMDL_ICA_ApplyFrame(work->icaAnime, work->mmdl, &work->offset);
        } else {
            ICA_ANIME_Delete(work->icaAnime);
            work->icaAnime = 0;
            work->state = 0;
            FLDMMDL_GetPos(work->mmdl, &pos);
            FLDMMDL_InitPosition(work->mmdl, &pos, FLDMMDL_GetDirDisp(work->mmdl));
            if (gMmdlIcaReleaseMoveBitTable[work->animKind] != 0) {
                FLDMMDL_ClearMoveBit(work->mmdl, 0x8000);
            }
        }
        FLDMMDL_CallDrawProc(work->mmdl);
    }
}

void SCRCMD_MMDL_ICA_Nop(void) {}

void SCRCMD_MMDL_ICA_ApplyFrame(IcaAnime *icaAnime, Mmdl *mmdl, VecFx32 *offset)
{
    VecFx32 pos;
    VecFx32 rotation;

    ICA_ANIME_Get(icaAnime, &pos);
    ICA_ANIME_Check1638(icaAnime, &rotation);
    VEC_Add(&pos, offset, &pos);
    FLDMMDL_SetPos(mmdl, (MmdlVec *)&pos);
    if (rotation.y == 0) {
        FLDMMDL_SetDirAll(mmdl, 1);
    } else if (rotation.y == 0x5A000) {
        FLDMMDL_SetDirAll(mmdl, 3);
    } else if (rotation.y == 0xB4000) {
        FLDMMDL_SetDirAll(mmdl, 0);
    } else if (rotation.y == 0x10E000) {
        FLDMMDL_SetDirAll(mmdl, 2);
    }
}

int SCRCMD_CreateMmdlIcaProc(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 pos;
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    ScriptFieldParam *fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    u16 heapId = FIELDMAP_GetHeapId(fieldParam->fieldSystem);
    u16 mmdlId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    MmdlIcaWork *icaWork;

    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(fieldParam->fieldSystem), &pos);
    icaWork = SCRCMD_MMDL_ICA_CreateProc(fieldParam->fieldSystem, mmdlId, &pos, heapId);
    SCRIPT_WORK_SetReturnParam(scriptWork, (u32)icaWork);
    return 0;
}

/*
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 */
int SCRCMD_EndMmdlIcaProc(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);

    SCRCMD_MMDL_ICA_EndProc((MmdlIcaWork *)SCRIPT_WORK_GetReturnParam(scriptWork));
    SCRIPT_WORK_SetReturnParam(scriptWork, 0);
    return 0;
}

int SCRCMD_StartMmdlIcaAnime(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    u16 animKind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    SCRCMD_MMDL_ICA_Start((MmdlIcaWork *)SCRIPT_WORK_GetReturnParam(scriptWork), animKind);
    return 0;
}

int SCRCMD_MMDL_ICA_WaitTask(u32 event, u32 state, MmdlIcaWaitWork *work, u32 arg)
{
    if (SCRCMD_MMDL_ICA_IsDone(work->ica, state, (u32)work, arg) == 1) {
        return 1;
    }
    return 0;
}

int SCRCMD_WaitMmdlIcaAnime(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    GameEvent *task = func_020122C0(SCRCMD_WORK_GetGameSystem(cmdWork), 0, SCRCMD_MMDL_ICA_WaitTask, 4);
    MmdlIcaWaitWork *work = func_020124E8(task);

    work->ica = (MmdlIcaWork *)SCRIPT_WORK_GetReturnParam(scriptWork);
    SCRIPT_SYS_CallEvent(scriptWork, task);
    return 1;
}

int SCRCMD_SUBSCREEN_ChangeModeTask(GameEvent *event, int *seq, SubscreenModeWork *work)
{
    switch (*seq) {
    case 0:
        if (FIELD_SUBSCREEN_IsIdle(work->subscreen)) {
            FIELD_SUBSCREEN_RequestMode(work->subscreen, work->mode);
            (*seq)++;
        }
        break;
    case 1:
        if (FIELD_SUBSCREEN_IsIdle(work->subscreen)) {
            return 1;
        }
        break;
    }
    return 0;
}

int SCRCMD_ChangeSubscreenMode(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FieldSubscreen *subscreen;
    u32 mode;
    ScriptFieldParam *fieldParam;
    struct ScriptWork *scriptWork;
    GameSystem *gameSystem;
    GameEvent *task;
    SubscreenModeWork *work;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    fieldParam = SCRIPT_WORK_ResetFieldParam(scriptWork);
    mode = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    subscreen = FIELDMAP_GetSubscreen(fieldParam->fieldSystem);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    task = func_020122C0(gameSystem, 0, SCRCMD_SUBSCREEN_ChangeModeTask, 8);
    work = func_020124E8(task);
    mode = gSubscreenModeTable[mode];
    work->subscreen = subscreen;
    work->mode = mode;
    SCRIPT_SYS_CallEvent(scriptWork, task);
    SCRIPT_WORK_SetCheckFlag(8);
    return 1;
}

int SCRCMD_ResetSubscreenMode(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    FieldSubscreen *subscreen;
    struct ScriptWork *scriptWork;
    GameSystem *gameSystem;
    GameEvent *task;
    SubscreenModeWork *work;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    subscreen = FIELDMAP_GetSubscreen(SCRIPT_WORK_ResetFieldParam(scriptWork)->fieldSystem);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    task = func_020122C0(gameSystem, 0, SCRCMD_SUBSCREEN_ChangeModeTask, 8);
    work = func_020124E8(task);
    work->subscreen = subscreen;
    work->mode = 0;
    SCRIPT_SYS_CallEvent(scriptWork, task);
    SCRIPT_WORK_ResetCheckFlag(8);
    return 1;
}

int SCRCMD_SUBSCREEN_ResetModeTask(u32 *eventWords, int *seq)
{
    FieldSubscreen *subscreen;

    subscreen = FIELDMAP_GetSubscreen(SCRIPT_WORK_ResetFieldParam((struct ScriptWork *)eventWords[2])->fieldSystem);
    switch (*seq) {
    case 0:
        if (FIELD_SUBSCREEN_IsIdle(subscreen)) {
            FIELD_SUBSCREEN_RequestMode(subscreen, 0);
            SCRIPT_WORK_ResetCheckFlag(8);
            (*seq)++;
        }
        break;
    case 1:
        if (FIELD_SUBSCREEN_IsIdle(subscreen)) {
            return 1;
        }
        break;
    }
    return 0;
}

GameEvent *EVENT_PERAP_RECORD_Create(GameSystem *gameSystem, FieldMap *fieldMap, u32 partySlot)
{
    GameEvent *task;
    PerapRecordWork *work;

    task = func_020122C0(gameSystem, 0, EVENT_PERAP_RECORD_Main, sizeof(PerapRecordWork));
    work = func_020124E8(task);
    MI_CpuFill8(work, 0, sizeof(PerapRecordWork));
    work->gameSystem = gameSystem;
    work->gameData = ICA_ANIME_GetField1C(gameSystem);
    work->perapVoice = func_02007B44(GAME_DATA_GetSaveControl(work->gameData));
    work->fieldMap = fieldMap;
    work->fieldPlayer = FIELDMAP_GetFieldPlayer(fieldMap);
    work->partyMon = POKEPARTY_GetMember(GAME_DATA_GetMyParty(work->gameData), partySlot);
    work->msgBg = FIELDMAP_GetMsgBg(work->fieldMap);
    work->partySlot = partySlot;
    work->recordDone = 0;
    return task;
}

/*
 * Fifteen-state field sequence: sets up handles, runs fades and a message task, then tears down.
 *
 * Addresses are Black-image addresses.
 */
int EVENT_PERAP_RECORD_Main(GameEvent *event, int *seq, PerapRecordWork *work)
{
    Strbuf *string;
    TcbList *taskList;
    MsgData *msgData;
    void *voiceSave;

    switch (*seq) {
    case 0:
        EVENT_PERAP_RECORD_PauseMmdls(work);
        *seq = 1;
        break;
    case 1:
        work->msgData = msgData = FIELD_MSGBG_CreateMsgData(work->msgBg, 88);
        work->sysWin = FIELD_MSGBG_CreateBottomSysWin(work->msgBg, msgData);
        work->wordSet = GF_FONT_Create_EC64(21);
        work->msgBuf = STRBUF_Create(0x400, 21);
        EVENT_PERAP_RECORD_SetupWindow(work);
        if (func_02007B50(work->perapVoice) == 1) {
            FIELD_MSGBG_SysWinPrintMsg(work->sysWin, 0, 0, 0);
            *seq = 2;
        } else {
            FIELD_MSGBG_SysWinPrintMsg(work->sysWin, 0, 0, 6);
            *seq = 4;
        }
        break;
    case 2:
        if (FIELD_MSGBG_SysWinMain(work->sysWin) == 1) {
            work->yesNoMenu = FIELD_MSGBG_CreateYesNoMenu(work->msgBg, 0);
            *seq = 3;
        }
        break;
    case 3:
        switch (FIELD_MSGBG_YesNoMenuMain(work->yesNoMenu)) {
        case 0:
            FIELD_MSGBG_DeleteMenuFunc(work->yesNoMenu);
            FIELD_MSGBG_ClearSysWin(work->sysWin);
            FIELD_MSGBG_SysWinPrintMsg(work->sysWin, 0, 0, 6);
            *seq = 4;
            break;
        case 1:
            FIELD_MSGBG_DeleteMenuFunc(work->yesNoMenu);
            *seq = 13;
            break;
        }
        break;
    case 4:
        if (FIELD_MSGBG_SysWinMain(work->sysWin) == 1) {
            UI_SetKeepAwakeFlagsGlobal(8);
            taskList = sub_020056BC(SND_MIC_Init(21));
            work->timeIcon = TIME_ICON_Create(taskList, FIELD_MSGBG_GetSysWinBmpWin(work->sysWin), 15, 16, 21);
            *seq = 5;
        }
        break;
    case 5:
        SND_MIC_AddElapsed(2);
        if (SND_MIC_IsLimitReached() == 1) {
            TIME_ICON_Delete(work->timeIcon);
            FIELD_MSGBG_ClearSysWin(work->sysWin);
            FIELD_MSGBG_SysWinPrintMsg(work->sysWin, 0, 0, 1);
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushTask(work->gameSystem, 6));
            *seq = 6;
        }
        break;
    case 6:
        if (FIELD_MSGBG_SysWinMain(work->sysWin) == 1) {
            if (SND_MIC_StartRecording(EVENT_PERAP_RECORD_OnRecorded, &work->recordDone) == 0) {
                *seq = 7;
            } else {
                string = func_02045EC0(work->msgData, 3);
                WORDSET_SetSlotMonSpecies(work->wordSet, 0, work->partyMon);
                WORDSET_CopyTaggedText(work->wordSet, work->msgBuf, string);
                STRBUF_Delete(string);
                FIELD_MSGBG_ClearSysWin(work->sysWin);
                FIELD_MSGBG_SysWinPrintStr(work->sysWin, 0, 0, work->msgBuf);
                SND_MIC_Exit();
                UI_ClearKeepAwakeFlagsGlobal(8);
                GAME_EVENT_CallEvent(event, func_02029620(work->gameSystem, 0, 30));
                *seq = 12;
            }
        }
        break;
    case 7:
        if (work->recordDone == 1) {
            SND_MIC_StoreRecording(work->perapVoice);
            SND_MIC_Exit();
            UI_ClearKeepAwakeFlagsGlobal(8);
            GAME_EVENT_CallEvent(event, func_02029620(work->gameSystem, 0, 30));
            *seq = 8;
        }
        break;
    case 8:
        if (EVENT_PERAP_RECORD_HopPokeIcon(work) == 0) {
            string = func_02045EC0(work->msgData, 2);
            WORDSET_SetSlotMonSpecies(work->wordSet, 0, work->partyMon);
            WORDSET_CopyTaggedText(work->wordSet, work->msgBuf, string);
            STRBUF_Delete(string);
            FIELD_MSGBG_ClearSysWin(work->sysWin);
            FIELD_MSGBG_SysWinPrintStr(work->sysWin, 0, 0, work->msgBuf);
            *seq = 9;
        }
        break;
    case 9:
        if (FIELD_MSGBG_SysWinMain(work->sysWin) == 1) {
            *seq = 10;
        }
        break;
    case 10:
        PM_VOICE_GetPerapVoiceSave(&voiceSave);
        work->voiceHandle = PM_VOICE_Play(0x1B9, 0, 64, 0, 0, 0, 0, &voiceSave);
        *seq = 11;
        break;
    case 11:
        if (sub_02006BD0(work->voiceHandle) == 0) {
            *seq = 13;
        }
        break;
    case 12:
        if (FIELD_MSGBG_SysWinMain(work->sysWin) == 1) {
            *seq = 13;
        }
        break;
    case 13:
        EVENT_PERAP_RECORD_Cleanup(work);
        STRBUF_Delete(work->msgBuf);
        WORDSET_DeleteStrbufED04(work->wordSet);
        FIELD_MSGBG_DeleteSysWin(work->sysWin);
        FIELD_MSGBG_DeleteMsgData(work->msgData);
        *seq = 14;
        break;
    case 14:
        EVENT_PERAP_RECORD_ResumeMmdls(work);
        return 1;
    }
    return 0;
}

/*
 * Completion callback: writes 1 through its second argument.  Referenced
 * only by address from EVENT_PERAP_RECORD_Main's literal pool.
 *
 * Addresses are Black-image addresses.
 */
void EVENT_PERAP_RECORD_OnRecorded(void *unused, int *done)
{
    *done = 1;
}

void EVENT_PERAP_RECORD_PauseMmdls(PerapRecordWork *work)
{
    FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(ICA_ANIME_GetField20(work->gameSystem)));
}

void EVENT_PERAP_RECORD_ResumeMmdls(PerapRecordWork *work)
{
    FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(ICA_ANIME_GetField20(work->gameSystem)));
}

void EVENT_PERAP_RECORD_CreatePokeIcon(PerapRecordWork *work)
{
    BoxPokemon *box;
    void *resHandle;
    u32 savedState;
    ClactInitParam actorParam;

    work->clactUnit = CLACT_CreateUnit(1, 0, 0x15);
    box = func_020185F0(work->partyMon);
    resHandle = POKEGRA_OpenHandle(0x15);
    savedState = func_02017DBC(box);
    work->charRes = POKEGRA_RegisterCgrPP(resHandle, box, 0, 0, 0x15);
    work->palRes = POKEGRA_RegisterPalettePP(resHandle, box, 0, 0, 0x60, 0x15);
    work->cellRes = POKEGRA_RegisterCellAnimPP(box, 0, 1, 0, 0x15);
    func_02017DE4(box, savedState);
    ARC_TOOL_DeleteHandle(resHandle);
    actorParam = gPerapIconActorParam;
    work->clactActor = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &actorParam, 0, 0x15);
}

int EVENT_PERAP_RECORD_DeletePokeIcon(PerapRecordWork *work)
{
    CLACT_DeleteActor(work->clactActor);
    CLACT_ReleaseCharacter(work->charRes);
    CLACT_ReleasePalette(work->palRes);
    CLACT_ReleaseCellAnim(work->cellRes);
    return CLACT_DeleteUnit(work->clactUnit);
}

int EVENT_PERAP_RECORD_HopPokeIcon(PerapRecordWork *work)
{
    SpritePos pos;

    if (work->hopCount == 0) {
        work->hopSpeed = -4;
    }
    if (work->hopSpeed == -4) {
        work->hopSpeed = 3;
        work->hopCount = work->hopCount + 1;
        if (work->hopCount == 3) {
            return 0;
        }
    }
    CLACT_GetActorSurfacePos(work->clactActor, &pos, 0);
    pos.y = pos.y - work->hopSpeed;
    CLACT_AddActorSurfacePos(work->clactActor, &pos, 0);
    work->hopSpeed = work->hopSpeed - 1;
    return 1;
}

void EVENT_PERAP_RECORD_SetupWindow(PerapRecordWork *work)
{
    ARC_UTIL_UploadPaletteFromArchive(5, BMP_MENUWORK_GetPlttFileId(0), 0, 0, 0, 0x20, 0x15);
    work->bmpWin = BMP_WIN_Create(1, 10, 3, 12, 12, 0, 1);
    BMP_Clear(BMP_WIN_GetBmp(work->bmpWin), 0x11);
    BMP_WIN_TransferChars(work->bmpWin);
    BMP_WIN_MakeScreen(work->bmpWin);
    BMP_MENUWORK_DrawWindow(work->bmpWin, 1, 1, 0);
    EVENT_PERAP_RECORD_CreatePokeIcon(work);
}

int EVENT_PERAP_RECORD_Cleanup(PerapRecordWork *work)
{
    EVENT_PERAP_RECORD_DeletePokeIcon(work);
    BMP_MENUWORK_DrawWindowBorder(work->bmpWin, 1);
    return BMP_WIN_Delete(work->bmpWin);
}

/*
 * Callee witnesses filed in wave A1 (witness lane).
 *
 * Addresses are Black-image addresses.
 */
int SCRCMD_CheckPmsWordPair(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 groupBegin, wordA, wordB, kind, groupEnd;
    u16 *resultVar;

    kind = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    wordA = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    wordB = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    switch (kind) {
    case 1:
        groupBegin = 0x5C0;
        groupEnd = groupBegin + 0xBB;
        break;
    case 2:
        groupBegin = 0x664;
        groupEnd = groupBegin + 0x53;
        break;
    default:
        *resultVar = 0;
        return 0;
    }
    if (PMS_WORD_IsSameGroup(groupBegin, wordA & 0x7FF) && PMS_WORD_IsSameGroup(groupEnd, wordB & 0x7FF)) {
        *resultVar = 1;
    } else {
        *resultVar = 0;
    }
    return 0;
}

int FIELD_SOUND_SYSTEM_FindSlotSound(u32 soundId)
{
    u32 i;

    for (i = 0; i < 0x15; i++) {
        if (soundId == gFieldSoundSlotTable[i].soundId) {
            return 1;
        }
    }
    return 0;
}

int FIELD_SOUND_SYSTEM_IsSlotSoundTracked(u32 soundId)
{
    u32 i;

    for (i = 0; i < 0x15; i++) {
        if (soundId == gFieldSoundSlotTable[i].soundId && gFieldSoundSlotTable[i].tracked == 1) {
            return 1;
        }
    }
    return 0;
}

/*
 * Shows the milestone message for the counter read from the save block when
 * it equals one of the five table entries at 0x021DD6BC, or message 0x28E1
 * once it passes 500; returns 0 otherwise.
 *
 * Addresses are Black-image addresses.
 */
GameEvent *SCRCMD_ShowStepMilestoneMessage(GameSystem *gameSystem, FieldMap *fieldMap)
{
    u16 steps = func_02008990(func_02008854(GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(gameSystem))));
    u32 i;

    for (i = 0; i < 5; i++) {
        if (steps == gStepMilestoneTable[i].count)
            return SCRIPT_SYS_CreateScriptEventSimple(gameSystem, gStepMilestoneTable[i].msg, 0, FIELDMAP_GetHeapId(fieldMap));
    }
    if (steps > 500)
        return SCRIPT_SYS_CreateScriptEventSimple(gameSystem, 0x28E1, 0, FIELDMAP_GetHeapId(fieldMap));
    return 0;
}

int FLDEFF_RIPPLE_WarpToZoneStartTask(GameEvent *event, int *seq, RippleWarpWork *work)
{
    VecFx32 drawOffset;
    u16 zoneId;
    FieldTaskManager *taskManager;
    struct FieldPlayer *player;

    switch (*seq) {
    case 0:
        taskManager = FIELDMAP_GetTaskManager(work->fieldMap);
        drawOffset.x = 0;
        drawOffset.y = -0x40000;
        drawOffset.z = 0;
        FIELD_TASK_MANAGER_AddTask(taskManager, FIELD_TASK_CreatePlayerDrawOffsetTween(work->fieldMap, 0x28, &drawOffset), 0);
        work->waitFrames = 8;
        (*seq)++;
        break;
    case 1:
        work->waitFrames--;
        if (work->waitFrames > 0) {
            break;
        }
        GFL_USE_PlaySeDefaultVolume(0x63C);
        (*seq)++;
        break;
    case 2:
        if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x63C)) != 0) {
            break;
        }
        player = FIELDMAP_GetFieldPlayer(work->fieldMap);
        FIELD_PLAYER_GetMmdl(player);
        FIELD_PLAYER_SetFormCode(player, 3);
        FIELD_GetPlayerAreaZoneId(work->fieldMap, &zoneId);
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateZoneStartWarpEvent(work->gameSystem, zoneId));
        (*seq)++;
        break;
    case 3:
        FLDMMDL_SetAcmd(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(work->fieldMap)), 8);
        (*seq)++;
        break;
    case 4:
        if (FLDMMDL_CheckEndAcmd(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(work->fieldMap)))) {
            return 1;
        }
        break;
    }
    return 0;
}

int FLDEFF_RIPPLE_WarpToSpecialLocationTask(GameEvent *event, int *seq, RippleWarpWork *work)
{
    FieldTaskManager *taskManager;
    FieldFog *fog;
    FieldTask *spinTaskA;
    FieldTask *spinTaskB;

    taskManager = FIELDMAP_GetTaskManager(work->fieldMap);
    switch (*seq) {
    case 0:
        GFL_USE_PlaySeDefaultVolume(0x63C);
        work->waitFrames = 0x18;
        if (work->useSpin) {
            fog = FIELDMAP_GetFog(work->fieldMap);
            spinTaskA = FIELD_TASK_CreatePlayerSpinEaseIn(work->fieldMap, 0x14, 3);
            spinTaskB = FIELD_TASK_CreatePlayerSpinLinear(work->fieldMap, 0xc, 3);
            FIELD_TASK_MANAGER_AddTask(taskManager, spinTaskA, 0);
            FIELD_TASK_MANAGER_AddTask(taskManager, spinTaskB, spinTaskA);
            FIELD_FOG_FADE_Init(fog, 0x7F0F, FIELD_FOG_GetSlope(fog), 0x1A);
        }
        (*seq)++;
        break;
    case 1:
        FIELD_PLAYER_SetFormCode(FIELDMAP_GetFieldPlayer(work->fieldMap), 2);
        (*seq)++;
        break;
    case 2:
        work->waitFrames--;
        if (work->waitFrames > 0) {
            break;
        }
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateSpecialLocationWarpEvent(work->gameSystem));
        (*seq)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}

GameEvent *FLDEFF_RIPPLE_CreateZoneStartWarpTask(GameSystem *gameSystem, FieldMap *fieldMap)
{
    GameEvent *task = func_020122C0(gameSystem, 0, FLDEFF_RIPPLE_WarpToZoneStartTask, sizeof(RippleWarpWork));
    RippleWarpWork *work = func_020124E8(task);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->useSpin = 0;
    return task;
}

GameEvent *FLDEFF_RIPPLE_CreateSpecialLocationWarpTask(GameSystem *gameSystem, FieldMap *fieldMap, u32 useSpin)
{
    GameEvent *task = func_020122C0(gameSystem, 0, FLDEFF_RIPPLE_WarpToSpecialLocationTask, sizeof(RippleWarpWork));
    RippleWarpWork *work = func_020124E8(task);

    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->useSpin = useSpin;
    return task;
}

int SCRCMD_GetBirthdayMessageIds(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameData *gameData;
    u32 sceneFlag;
    PlayerBirthday *birthday;
    u32 currentMonth, currentDay, birthMonth;
    u16 *outA, *outB, *outC;
    TextIdTable table;

    gameData = SCRCMD_WORK_GetGameData(cmdWork);
    sceneFlag = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    outA = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    outB = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    outC = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    table = gBirthdayTextIdTable;
    birthday = func_02008B08(GAME_DATA_GetSaveControl(gameData));
    currentMonth = FIELD_CLOCK_GetMonth(gameData);
    currentDay = FIELD_CLOCK_GetDay(gameData);
    birthMonth = func_02008B94(birthday);
    if (currentDay == func_02008B98(birthday) && currentMonth == birthMonth) {
        *outA = 0x34;
        *outB = 0x53;
        *outC = table.textId[30];
    } else {
        u32 i = func_020056EC(sceneFlag ? 0x1E : 0x16);
        *outA = i + 0x16;
        *outB = i + 0x35;
        *outC = table.textId[i];
    }
    return 0;
}

int SCRCMD_ShowPokeIconWindow(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 gender, species, form, isEgg;
    GameEvent *task;
    GameSystem *gameSystem;
    PokeIconWork *work;
    struct ScriptWork *scriptWork;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    ICA_ANIME_GetField20(gameSystem);
    species = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    form = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    isEgg = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    gender = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    task = func_020122C0(gameSystem, 0, SCRCMD_POKE_ICON_Task, 0x18);
    work = func_020124E8(task);
    SCRCMD_POKE_ICON_InitWindow(work);
    SCRCMD_POKE_ICON_CreateIcon(work, species, form, isEgg, gender, 0);
    SCRIPT_SYS_CallEvent(scriptWork, task);
    return 1;
}

void SCRCMD_POKE_ICON_InitWindow(PokeIconWork *work)
{
    work->bmpWin = BMP_WIN_Create(1, 10, 3, 12, 12, 13, 1);
    BMP_Clear(BMP_WIN_GetBmp(work->bmpWin), 17);
    BMP_WIN_TransferChars(work->bmpWin);
    BMP_WIN_MakeScreen(work->bmpWin);
    BMP_MENUWORK_DrawWindow(work->bmpWin, 1, 1, 13);
}

/*
 * Tail call with the leading word and a constant one.
 *
 * Addresses are Black-image addresses.
 */
void SCRCMD_POKE_ICON_ShowWindow(PokeIconWork *work)
{
    BMP_MENUWORK_DrawWindowBorder(work->bmpWin, 1);
}

/*
 * The pooled 0x8015 is the heap id as a plain literal: it is too wide for a
 * Thumb movs, so the compiler pools it by itself; no symbol is needed. int
 * params were the fix for register allocation.
 *
 * Addresses are Black-image addresses.
 */
void SCRCMD_POKE_ICON_CreateIcon(PokeIconWork *work, int species, int form, int isEgg, int gender, int charFlags)
{
    ClactInitParam actorParam;
    void *resHandle;

    work->clactUnit = CLACT_CreateUnit(1, 0, 0x8015);
    resHandle = POKEGRA_OpenHandle(0x8015);
    work->charRes = POKEGRA_RegisterCgr(resHandle, species, form, isEgg, gender, 0, 0, charFlags, 0, 0x8015);
    work->palRes = POKEGRA_RegisterPalette(resHandle, species, form, isEgg, gender, 0, 0, 0, 0, 0x8015);
    ARC_TOOL_DeleteHandle(resHandle);
    work->cellRes = POKEGRA_RegisterCellAnim(species, form, isEgg, gender, 0, 0, 1, 0, 0x8015);
    actorParam = gPokeIconActorParam;
    work->clactActor = CLACT_CreateActor(work->clactUnit, work->charRes, work->palRes, work->cellRes, &actorParam, 0, 0x8015);
}

int SCRCMD_POKE_ICON_DeleteIcon(PokeIconWork *work)
{
    CLACT_DeleteActor(work->clactActor);
    CLACT_ReleaseCharacter(work->charRes);
    CLACT_ReleasePalette(work->palRes);
    CLACT_ReleaseCellAnim(work->cellRes);
    return CLACT_DeleteUnit(work->clactUnit);
}

u32 SCRCMD_POKE_ICON_Task(GameEvent *event, u32 *state, PokeIconWork *work)
{
    switch (state[0]) {
    case 0:
        if (KEY_GetTrg() & 3) {
            SCRCMD_POKE_ICON_DeleteIcon(work);
            SCRCMD_POKE_ICON_ShowWindow(work);
            state[0]++;
        }
        break;
    case 1:
        BMP_WIN_Delete(work->bmpWin);
        return 1;
    }
    return 0;
}

u32 SCRCMD_CheckBeaconTrainerKey(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    u32 slot;
    u16 *resultVar;
    GameData *gameData;
    void *miscSave;

    slot = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    gameData = ICA_ANIME_GetField1C(SCRCMD_WORK_GetGameSystem(cmdWork));
    miscSave = GAME_DATA_GetMiscSave(gameData);
    *resultVar = FIELD_G3D_MAP_CheckBeaconTrainerKey(miscSave, slot, func_02012944(gameData));
    return 0;
}

/*
 * Spill slots follow declaration order (h, f, list, y, x, id, q, hdl, n from
 * the top down); the tail loops' counter and table pointer are block locals
 * declared j before t, which puts j in r4 and t in r5.
 *
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`q
 * = (Sub *)e;` before `q = &e->sub;`). Game code has no line table, so these
 * were stand-ins. The plain single assignment gives EXACT in --lang c99 and
 * --lang c: the output bytes do not change. Older text in this header that
 * asks for the double assignment is superseded.
 *
 * Addresses are Black-image addresses.
 */
int FIELD_CheckPlayerPositionFree(GameSystem *gameSystem)
{
    MmdlObjCodeParam objCodeParam;
    VecFx32 playerPos;
    RailLocation rail;
    struct {
        s16 gridZ;
        s16 gridY;
        s16 gridX;
    } gridPos;
    GameData *gameData;
    EventDataSystem *eventData;
    MmdlHeader *list;
    FieldMap *fieldMap;
    MmdlSys *mmdlSys;
    struct FieldPlayer *player;
    u32 zoneId;
    MmdlHeader *header;
    MmdlHeaderPos *pos;
    WfbcNpcData *npcData;
    int i;
    int n;
    WfbcPosition *entry;
    void *eventWork;
    Mmdl *playerMmdl;

    gameData = ICA_ANIME_GetField1C(gameSystem);
    eventData = GAME_DATA_GetField158(gameData);
    list = EVENTDATA_SYSTEM_GetNpcHeaders(eventData);
    n = EVENTDATA_SYSTEM_GetNpcCount(eventData);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    zoneId = FIELDMAP_GetZoneId(fieldMap);
    if (ZONEDATA_IsPalaceEnabled((u16)zoneId) == 0) {
        return 0;
    }
    if (FIELD_PLAYER_GetFormCode(player) - 2 <= 1) {
        return 0;
    }
    if ((list == 0 || n == 0) && zoneId != 0 && zoneId != 0x1A8) {
        return 1;
    }
    for (i = 0; i < n; i++) {
        header = &list[i];
        if (header->posType == 0) {
            pos = (MmdlHeaderPos *)header->pos;
            FLDMMDL_LoadObjCodeParam(mmdlSys, header->objCode, &objCodeParam);
            FIELD_PLAYER_GetNowGridPos(player, (u16 *)&gridPos.gridX, (u16 *)&gridPos.gridY, (u16 *)&gridPos.gridZ);
            if (pos->grid.gridX <= gridPos.gridX && gridPos.gridX < pos->grid.gridX + objCodeParam.sizeWidth) {
                if (pos->grid.gridZ - objCodeParam.sizeDepth < gridPos.gridZ && gridPos.gridZ <= pos->grid.gridZ) {
                    return 0;
                }
            }
        } else if (header->posType == 1) {
            pos = (MmdlHeaderPos *)header->pos;
            if (FIELDMAP_GetMoveKind(fieldMap) == 1) {
                FIELD_PLAYER_SetNogridLocation(player, &rail);
                if (pos->rail.railIndex == rail.railIndex && pos->rail.lineGrid == rail.lineGrid && pos->rail.widthGrid == rail.widthGrid) {
                    return 0;
                }
            }
        }
    }
    if (FIELDMAP_GetMoveKind(fieldMap) == 0) {
        playerMmdl = FIELD_PLAYER_GetMmdl(player);
        eventWork = GAME_DATA_GetEventWork(gameData);
        FLDMMDL_GetPos(playerMmdl, (MmdlVec *)&playerPos);
        if (EVENTDATA_SYSTEM_SearchAutoPosEvent(eventData, eventWork, &playerPos)) {
            return 0;
        }
    }
    if (zoneId == 0 || zoneId == 0x1A8) {
        int j;
        WfbcPosition *table;
        FIELD_PLAYER_GetNowGridPos(player, (u16 *)&gridPos.gridX, (u16 *)&gridPos.gridY, (u16 *)&gridPos.gridZ);
        npcData = FIELD_WFBC_DATA_LOCAL_OpenNpcData(0, 0x8015);
        table = FIELD_WFBC_DATA_LOCAL_LoadMmdlPositionTable(npcData, zoneId != 0, 0x8015);
        for (j = 0; j < 10; j++) {
            entry = FIELD_WFBC_DATA_LOCAL_GetPositionPair(table, j);
            if (entry->x == gridPos.gridX && entry->z == gridPos.gridZ) {
                FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(table);
                FIELD_WFBC_DATA_LOCAL_CloseNpcData(npcData);
                return 0;
            }
        }
        for (j = 0; j < 10; j++) {
            entry = FIELD_WFBC_DATA_LOCAL_GetItemPositionPair(table, j);
            if (entry->x == gridPos.gridX && entry->z == gridPos.gridZ) {
                FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(table);
                FIELD_WFBC_DATA_LOCAL_CloseNpcData(npcData);
                return 0;
            }
        }
        FIELD_WFBC_DATA_LOCAL_FreeMmdlPositionTable(table);
        FIELD_WFBC_DATA_LOCAL_CloseNpcData(npcData);
    }
    return 1;
}

GameEvent *FIELD_SUBSCREEN_CreateAnimTask(GameSystem *gameSystem)
{
    GameEvent *task = func_020122C0(gameSystem, 0, FIELD_SUBSCREEN_AnimTask, sizeof(SubscreenAnimWork));
    SubscreenAnimWork *work = func_020124E8(task);

    work->fieldMap = ICA_ANIME_GetField20(gameSystem);
    work->subscreen = FIELDMAP_GetSubscreen(work->fieldMap);
    return task;
}

u32 FIELD_SUBSCREEN_AnimTask(GameEvent *event, u32 *state, SubscreenAnimWork *work)
{
    switch (state[0]) {
    case 0:
        FIELD_SUBSCREEN_RequestMode(work->subscreen, 9);
        state[0]++;
        break;
    case 1:
        if (FIELD_SUBSCREEN_GetPanelResult(work->subscreen) == 14) {
            FIELD_SUBSCREEN_ClearPanelResult(work->subscreen);
            state[0]++;
        }
        break;
    case 2:
        FIELD_SUBSCREEN_RequestMode(work->subscreen, 0);
        return 1;
    }
    return 0;
}

int SCRCMD_ShowOrClearInfoWindow(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    ScriptFieldParam *fieldParam;
    u32 heapId;
    MsgBank *msgBank;
    BmpWin *bmpWin;
    Strbuf *msgBuf;
    FieldMsgBg *msgBg;

    fieldParam = SCRIPT_WORK_ResetFieldParam(SCRCMD_WORK_GetScriptWork(cmdWork));
    heapId = FIELDMAP_GetHeapId(fieldParam->fieldSystem);
    msgBg = FIELDMAP_GetMsgBg(fieldParam->fieldSystem);
    if (VM_ReadU16(vm)) {
        msgBank = func_02045B38(0, 2, 0x16, heapId);
        bmpWin = BMP_WIN_CreateAt(2, 1, 1, 0x1E, 10, 14, 0x40);
        BMP_Clear(BMP_WIN_GetBmp(bmpWin), 0xF);
        BMP_WIN_TransferChars(bmpWin);
        BMP_WIN_MakeScreen(bmpWin);
        BMP_MENUWORK_DrawWindow(bmpWin, 0, 1, 0xD);
        msgBuf = STRBUF_Create(0xB4, heapId);
        func_02045CAC(msgBank, 3, msgBuf);
        PRINTSYS_Print(BMP_WIN_GetBmp(bmpWin), 0, 0, msgBuf, FIELD_MSGBG_GetFont(msgBg));
        BMP_WIN_TransferChars(bmpWin);
        func_02041B6C(2);
        STRBUF_Delete(msgBuf);
        MSGDATA_Delete(msgBank);
        BMP_WIN_Delete(bmpWin);
    } else {
        BG_SYS_SetTileEntry(2, 0, 0, 0, 0x20, 0xC, 0x11);
        func_02041B6C(2);
    }
    return 0;
}

int SCRCMD_AddTrainerRecordValue(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u32 counterId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u32 delta = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);

    func_02008DAC(func_02008C58(GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(gameSystem))), counterId, delta);
    return 0;
}

int SCRCMD_GetTrainerRecordValue(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    u32 counterId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    u16 *resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);

    *resultVar = func_02008DFC(func_02008C58(GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(gameSystem))), counterId);
    return 0;
}

int SCRCMD_GetNpcGreetingMessage(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    GameData *gameData;
    PlayerStatus *status;
    WordSet *wordSet;
    u32 fixedMessage;
    struct ScriptWork *scriptWork;
    u16 *resultVar;
    Party *party;
    int i, partyCount;
    PokemonParam *mon;
    RtcTime time;
    int base;
    int msgIndex;
    u32 countA, countB;
    TrainerRecord *trainerRecord;
    u32 idA, idB;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameData = ICA_ANIME_GetField1C(SCRCMD_WORK_GetGameSystem(cmdWork));
    status = func_02012944(gameData);
    wordSet = SCRIPT_WORK_GetWordSet(scriptWork);
    fixedMessage = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    resultVar = SCRIPT_WORK_ReadWorkPointer(vm, cmdWork);
    WORDSET_SetSlotMyStatus(wordSet, 0, status);
    party = GAME_DATA_GetMyParty(gameData);
    partyCount = POKEPARTY_GetCount(party);
    for (i = 0; i < partyCount; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            WORDSET_Callback(wordSet, 3, func_02017E1C(mon, 5, 0));
            break;
        }
    }
    GF_STANDARD_SetField00(&time);
    if (time.minute < 10) {
        base = 0;
        msgIndex = func_020056EC(0x1D);
        countA = 0;
        countB = 0;
        trainerRecord = GAME_DATA_GetTrainerRecord(gameData);
        idA = gGreetingCounterTable[msgIndex].idA;
        if (idA != -1) {
            countA = func_02008DFC(trainerRecord, idA);
            WORDSET_SetSlotNumber(wordSet, 1, countA, gGreetingCounterTable[msgIndex].digitsA, 0, 1);
        }
        idB = gGreetingCounterTable[msgIndex].idB;
        if (idB != -1) {
            countB = func_02008DFC(trainerRecord, idB);
            WORDSET_SetSlotNumber(wordSet, 2, countB, gGreetingCounterTable[msgIndex].digitsB, 0, 1);
        }
        if (msgIndex < 11) {
            if (idA != -1 && idB != -1) {
                if (countA == 0 || countB == 0) {
                    msgIndex = 0;
                }
            } else if (idB == -1 && countA == 0) {
                msgIndex = 0;
            }
        }
        if (msgIndex < 11) {
            if ((u8)(int)func_02008550(status) == 1) {
                msgIndex += 11;
            }
        } else {
            msgIndex += 11;
        }
    } else if (time.minute < 0x23) {
        base = 0x28;
        msgIndex = func_020056EC(0x32);
    } else {
        base = 0x5A;
        msgIndex = func_020056EC(0x50);
    }
    *resultVar = SCRCMD_GREETING_AdjustMessageIdByRandom(gameData, SCRCMD_GREETING_AdjustMessageIdByMisc(gameData, base + msgIndex), fixedMessage);
    return 0;
}

/*
 * The 0x0C-random-plus-0x5A path returns through its own temporary (an
 * else arm with a local); a direct `return f() + 0x5a` merges into v. The
 * loop index reuses the second parameter's register: v is copied out and the
 * parameter becomes the index, which gives the image's r1/r2/r3 colouring
 * (a fresh int index rotates them by one).
 */
u32 SCRCMD_GREETING_AdjustMessageIdByMisc(GameData *gameData, int messageId)
{
    u32 v = messageId;
    BeaconSave *beacon = BEACON_GetBlock(GAME_DATA_GetSaveControl(gameData));

    for (messageId = 0; messageId < 8; messageId++) {
        if (v == gGreetingMiscMessageIds[messageId]) {
            if (BEACON_GetFlag(beacon)) {
                return v;
            } else {
                u32 rolled = func_020056EC(0xc);
                return rolled + 0x5a;
            }
        }
    }
    return v;
}

u32 SCRCMD_GREETING_AdjustMessageIdByRandom(GameData *gameData, u32 messageId, int fixedMessage)
{
    int i;

    if (fixedMessage == 0) {
        for (i = 0; i < 0xf; i++) {
            if (messageId == gGreetingRandomMessageIds[i]) {
                return func_020056EC(0x14) + 0x6e;
            }
        }
    }
    return messageId;
}

GameEvent *FIELD_CAMERA_CreateShakeTask(GameSystem *gameSystem, CameraShakeParams *params)
{
    GameEvent *task = func_020122C0(gameSystem, 0, FIELD_CAMERA_ShakeTask, sizeof(CameraShakeWork));

    *(CameraShakeParams *)func_020124E8(task) = *params;
    return task;
}

/*
 * Task step: case 2 swings the object on a sine of tick/steps. The zero
 * vector is a block-scoped `= {0, 0, 0}` (base pointer then three stores);
 * the offset's products are named locals stored after the position copy.
 *
 * Addresses are Black-image addresses.
 */
int FIELD_CAMERA_ShakeTask(GameEvent *event, int *state)
{
    CameraShakeWork *shake;
    FieldMap *fieldMap;
    FieldCamera *camera;
    int done;
    u16 angle;
    int swingScale;

    done = 0;
    fieldMap = ICA_ANIME_GetField20(GAME_EVENT_GetGameSystem(event));
    shake = func_020124E8(event);
    camera = FIELDMAP_GetCamera(fieldMap);

    switch (*state) {
    case 0:
        FIELD_CAMERA_EndDelay(camera);
        (*state)++;
        break;
    case 1:
        if (FIELD_CAMERA_IsDelayEnabled(camera) == 0) {
            shake->pos = FIELD_CAMERA_GetTraceTarget(camera);
            FIELD_CAMERA_StopTargetTrace(camera);
            (*state)++;
        }
        break;
    case 2:
        shake->params.tick++;
        angle = (shake->params.tick << 16) / shake->params.steps;
        if (shake->params.thresh != 0 && shake->params.total - shake->params.left >= shake->params.thresh) {
            shake->params.cnt++;
            if (shake->params.cnt >= shake->params.period) {
                shake->params.cnt = 0;
                shake->params.y -= shake->params.dy;
                shake->params.x -= shake->params.dx;
                if (shake->params.y <= 0) {
                    shake->params.y = 1;
                }
                if (shake->params.x <= 0) {
                    shake->params.x = 1;
                }
            }
        }
        if (shake->params.tick >= shake->params.steps) {
            shake->params.left--;
            shake->params.tick = 0;
        }
        if (shake->params.left == 0) {
            shake->params.tick = 0;
            done = 1;
        }
        if (done) {
            VecFx32 zero = {0, 0, 0};
            FIELD_CAMERA_SetEyeShift(camera, &zero);
            FIELD_CAMERA_SetTraceTarget(camera, shake->pos);
            FIELD_CAMERA_RestartDelay(camera);
            (*state)++;
        } else {
            VecFx32 target;
            VecFx32 eyeShift;
            int shiftX, shiftY;
            swingScale = FX_SinCosTable_[(angle >> 4) * 2];
            shiftX = shake->params.x * swingScale;
            shiftY = shake->params.y * swingScale;
            target = *shake->pos;
            target.x += shiftX;
            target.y += shiftY;
            eyeShift.x = shiftX;
            eyeShift.y = shiftY;
            eyeShift.z = 0;
            FIELD_CAMERA_SetTarget(camera, &target);
            FIELD_CAMERA_SetEyeShift(camera, &eyeShift);
        }
        break;
    case 3:
        return 1;
    }
    return 0;
}

u32 SCRCMD_StartSwapNpcEvent(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 pos;
    struct ScriptWork *scriptWork;
    GameSystem *gameSystem;
    u32 removeObjId;
    u32 addObjId;
    GameEvent *task;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    ICA_ANIME_GetField20(gameSystem);
    removeObjId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    addObjId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    FLDMMDL_GetPos(FLDMMDL_SysSearchObjId((MmdlSys *)SCRCMD_WORK_GetOccupyInfo(cmdWork), removeObjId), (MmdlVec *)&pos);
    task = SP_POKE_GIMMICK_StartSwapNpc(gameSystem, &pos, removeObjId, addObjId);
    if (task == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, task);
    return 1;
}

/*
 * FIELD_GIMMICK_ARC_EFFECT_StartPlayerEffect resolves in ov064 (2026-10-02, lane gA2). Starts exist at
 * 0x021F37B8 in ov041, ov050, ov060 and ov064. ov050 is void(void) and ov060
 * takes two arguments. ov041 is out on two counts: its body ends in a tail
 * call to FLD_EXP_OBJ_RemoveUnit, which is void (src/matched/ov/ov021_func_021BE418.c,
 * EXACT), so it returns no value for the `t == 0` test; and it hands its
 * argument straight to FIELDMAP_GetExpObj and FIELDMAP_FreeCommonWork, the type that
 * ICA_ANIME_GetField20 returns, while this call passes SCRCMD_WORK_GetGameSystem(b), which the
 * sibling SCRCMD_StartArcEffect feeds to ICA_ANIME_GetField20. ov064's function applies
 * ICA_ANIME_GetField20 to its argument and returns func_020122C0(arg, 0, cb, 0), a
 * task, which is what SCRIPT_SYS_CallEvent(x, t) receives here and in the same-shape
 * siblings SCRCMD_WaitArcEffectEnd (ov064-only FIELD_GIMMICK_ARC_EFFECT_CreateWaitEndEvent) and SCRCMD_WaitArcEffectPeak
 * (FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent, ov064). SCRCMD_StartArcEffect and SCRCMD_ShowArcModelAt also call ov064.
 */
int SCRCMD_StartArcPlayerEffect(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    GameEvent *task = FIELD_GIMMICK_ARC_EFFECT_StartPlayerEffect(SCRCMD_WORK_GetGameSystem(cmdWork));

    if (task == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, task);
    return 1;
}

u32 SCRCMD_StartArcEffect(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 startPos;
    VecFx32 endPos;
    struct ScriptWork *scriptWork;
    GameSystem *gameSystem;
    FieldMap *fieldMap;
    int objId;
    int tileX;
    int tileY;
    int tileZ;
    int arcHeight;
    int arcParam;
    Mmdl *mmdl;
    GameEvent *task;

    scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    objId = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    tileX = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    tileY = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    tileZ = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    arcHeight = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    arcParam = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    mmdl = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys(fieldMap), objId);
    if (mmdl != 0) {
        FLDMMDL_GetPos(mmdl, (MmdlVec *)&startPos);
    }
    endPos.x = (tileX << 16) + 0x8000;
    endPos.y = tileY << 15;
    endPos.z = (tileZ << 16) + 0x8000;
    task = FIELD_GIMMICK_ARC_EFFECT_StartArcEffect(gameSystem, &startPos, &endPos, arcHeight << 15, arcParam);
    if (task == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, task);
    return 1;
}

u32 SCRCMD_ShowArcModelAt(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    VecFx32 pos;
    GameSystem *gameSystem;
    int tileX;
    int tileY;
    int tileZ;

    gameSystem = SCRCMD_WORK_GetGameSystem(cmdWork);
    tileX = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    tileY = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    tileZ = SCRIPT_WORK_ReadWorkValue(vm, cmdWork);
    pos.x = (tileX << 16) + 0x8000;
    pos.y = tileY << 15;
    pos.z = (tileZ << 16) + 0x8000;
    FIELD_GIMMICK_ARC_EFFECT_ShowArcModelAt(gameSystem, &pos);
    return 0;
}

int SCRCMD_WaitArcEffectEnd(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    GameEvent *task = FIELD_GIMMICK_ARC_EFFECT_CreateWaitEndEvent(SCRCMD_WORK_GetGameSystem(cmdWork));

    if (task == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, task);
    return 1;
}

/*
 * FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent resolves in ov064: the only Thumb function starting there
 * that takes one argument (ov043's takes two), and the neighbouring ov021
 * functions SCRCMD_StartArcEffect and SCRCMD_ShowArcModelAt already call ov064 code.
 */
int SCRCMD_WaitArcEffectPeak(ScriptVm *vm, ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork = SCRCMD_WORK_GetScriptWork(cmdWork);
    GameEvent *task = FIELD_GIMMICK_ARC_EFFECT_CreateWaitPeakEvent(SCRCMD_WORK_GetGameSystem(cmdWork));

    if (task == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(scriptWork, task);
    return 1;
}
