/*
 * file:     intrude_field.c
 * unit:     yes
 * function: INTRUDE_FIELD_Update, INTRUDE_FIELD_FindRemotePlayerAhead, INTRUDE_FIELD_CreateEdgeBlockTask, INTRUDE_FIELD_TaskEdgeBlock, INTRUDE_FIELD_CreateAreaChangeTask, INTRUDE_FIELD_TaskAreaChange, INTRUDE_FIELD_CreateTileEvent, INTRUDE_FIELD_CreateEdgeTask, INTRUDE_FIELD_CreateExitConfirmEvent, INTRUDE_FIELD_EventExitConfirm, INTRUDE_FIELD_CreateNoticeEvent, INTRUDE_FIELD_EventNotice, INTRUDE_FIELD_IsAtAreaEdge, INTRUDE_FIELD_IsInEdgeMargin, INTRUDE_FIELD_UpdateCommState, INTRUDE_FIELD_StartCommAfterExit, INTRUDE_FIELD_StartComm, INTRUDE_FIELD_UpdateAreaIndex, INTRUDE_FIELD_ResetExtraAreaCount, INTRUDE_FIELD_AddAreaMaps, INTRUDE_FIELD_AddAreaMapCount, INTRUDE_FIELD_ChangePlayerLook, INTRUDE_FIELD_TryStartOfferEvent, INTRUDE_FIELD_FindZonePos, INTRUDE_FIELD_GetZoneAnchor, INTRUDE_FIELD_InitStartParam, INTRUDE_FIELD_GetStartKind, INTRUDE_FIELD_AddMmdl, INTRUDE_FIELD_AddAreaMmdls, INTRUDE_FIELD_IsDisconnectNeeded, INTRUDE_FIELD_IsStartRequested, INTRUDE_FIELD_SetSingleAreaMode, INTRUDE_FIELD_GetHostGender, INTRUDE_FIELD_IsListedZone, INTRUDE_FIELD_AddMarkerMmdl, INTRUDE_FIELD_AddMarkerMmdls, INTRUDE_FIELD_AddSymbolMonMmdl, INTRUDE_FIELD_GetMmdlParamPair, INTRUDE_FIELD_GetMmdlParam0, INTRUDE_FIELD_CreateSymbolMon, INTRUDE_FIELD_SpawnSymbolMons, INTRUDE_FIELD_CreateOfferInfoEvent, INTRUDE_FIELD_EventOfferInfo, INTRUDE_FIELD_InitPlayerSpin, INTRUDE_FIELD_StepPlayerSpin
 * address:  0x0217AE20
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   INTRUDE_COMM_UpdatePlayerObjects  0x02175004  thumb  ov011
 *   INTRUDE_COMM_GetPlayerObjCode  0x02175598  thumb  ov011
 *   COMM_PLAYER_Update  0x02167590  thumb  ov010
 *   COMM_PLAYER_CheckOccupy  0x021677E4  thumb  ov010
 *   COMM_PLAYER_Add  0x021675D0  thumb  ov010
 *   COMM_PLAYER_SetPackage  0x02167848  thumb  ov010
 *   COMM_PLAYER_SetEffect  0x021679C4  thumb  ov010
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb  ov021
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb  ov021
 *   COMM_PLAYER_SearchGridPos  0x021679A4  thumb  ov010
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomMsgWin  0x021907A8  thumb  ov021
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintMsg  0x02190740  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   KEY_GetTrg  0x020362DC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   WORDSET_Delete  0x0201ED04  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_IsStepToOwnArea  0x021584A4  thumb
 *   INTRUDE_COMM_IsSessionAcceptedOrResultReady  0x02175BE4  thumb  ov011
 *   INTRUDE_COMM_PickDefaultObjCode  0x02175548  thumb
 *   INTRUDE_FIELD_InitMmdlCopyAnime  0x0217C758  thumb
 *   INTRUDE_FIELD_MainMmdlCopyAnime  0x0217C820  thumb
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb
 *   FIELD_PLACE_NAME_ForceShowForZone  0x021BC5A0  thumb
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_INTRUDE_EVENT_CreateSymbolEntryEvent  0x0216B340  thumb  ov010
 *   INTRUDE_FIELD_gSymbolMarkerPos     0x02182B90  data   a4
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetPlayerWork  0x02012798  thumb
 *   GAME_DATA_SetPlayerPosition  0x02012A90  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   EVENT_MAPCHANGE_CreateIntrudeReturnEvent  0x02185214  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb
 *   FIELD_MSGBG_SysWinPrintMsg  0x02190E74  thumb
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb
 *   FIELD_PLAYER_CheckFormModel  0x021A3238  thumb
 *   GAME_COMM_GetCounter  0x0202648C  thumb
 *   GAME_COMM_IsTransition  0x02026460  thumb
 *   DWCi_IsFold  0x02035390  arm
 *   UI_IsPowerConnected  0x020353B0  arm
 *   GAMESYSTEM_IsNetOffBySleep  0x02012204  thumb
 *   GAMESYSTEM_IsEventActive  0x020120D8  thumb
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GAME_COMM_RequestExit  0x0202640C  thumb
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAME_COMM_Start  0x020263D8  thumb
 *   INTRUDE_FIELD_gStartParamFile     0x02183AE0  data   a1
 *   GAME_DATA_GetPlayerDirectionType  0x02012AE4  thumb
 *   INTRUDE_COMM_HasResultReward  0x02175E90  thumb  ov011
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 *   INTRUDE_COMM_AdjustAllRemotePositions  0x02175274  thumb  ov011
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   INTRUDE_COMM_SetIntrudeId  0x02175710  thumb  ov011
 *   EVENT_FIELD_PROCLINK_SetReturnLinkId  0x02161FEC  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   MAP_MATRIX_Create  0x02159B48  thumb  ov010
 *   MAP_MATRIX_Load  0x02159B94  thumb  ov010
 *   MAP_MATRIX_Delete  0x02159BBC  thumb
 *   FIELD_G3D_MAPPER_AppendMatrix  0x0218CD20  thumb  ov021
 *   GAMESYSTEM_IsFieldMapActive  0x02012114  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   FIELD_PLAYER_SetObjCode  0x021A3220  thumb  ov021
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FIELD_PLAYER_ClearRememberedObjCode  0x021A322C  thumb  ov021
 *   INTRUDE_COMM_IsSessionAccepted  0x02175B8C  thumb  ov011
 *   INTRUDE_COMM_IsSessionFinished  0x02175BBC  thumb  ov011
 *   INTRUDE_COMM_GetActiveSessionRequest  0x02175B34  thumb  ov011
 *   INTRUDE_COMM_GetJoinStatus  0x02175CF4  thumb  ov011
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 *   EVENT_COMM_COMMON_CreateOfferEvent  0x02182124  thumb  ov018
 *   gIntrudeOfferZoneIds     0x021DB810  data   ov021  a2
 *   gIntrudeOfferTilePositions     0x021DB834  data   ov021  a2
 *   INTRUDE_FIELD_gZonePositions 0x02182B9C data ov018 a4
 *   INTRUDE_FIELD_gHomeAnchorPos     0x02182B60  data   a4
 *   FLDMMDL_AddMmdl  0x0216CE60  thumb  ov010
 *   INTRUDE_FIELD_gMmdlHeaderTemplate     0x02182B6C  data   a4
 *   INTRUDE_FIELD_gAreaMmdlDefs 0x02182B54 data a4
 *   ZONEDATA_IsZoneGroup118To120  0x02013D9C  thumb
 *   GAME_COMM_GetLastKind  0x0202647C  thumb
 *   INTRUDE_COMM_IsRequestFromSelf 0x02176258 thumb ov011
 *   GAME_COMM_GetGameData  0x02026478  thumb
 *   GAME_DATA_GetIntrudeId  0x02012B80  thumb
 *   INTRUDE_FIELD_gListedZoneCount 0x021700A4 data a4
 *   INTRUDE_FIELD_gListedZones 0x02170128 data a2
 *   INTRUDE_FIELD_gMarkerMmdlHeader     0x021835D4  data   a4
 *   TPOKE_DATA_GetRecordIndex  0x0202A188  thumb
 *   INTRUDE_FIELD_gSymbolMonMoveParams     0x0218360C  data   a4
 *   INTRUDE_FIELD_gSymbolMonMmdlHeader     0x0218362C  data   a4
 *   FLDMMDL_GetParam 0x0216D63C thumb ov010
 *   ARC_UTIL_LoadMember  0x0204A1BC  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MYSTATUS_GetId  0x02008530  thumb
 *   POKE_TOOL_CreatePersonalRnd  0x020186C8  thumb
 *   POKE_TOOL_Create  0x020173F0  thumb
 *   POKE_TOOL_SetupPartyParamEx  0x02017588  thumb
 *   POKE_TOOL_SetAbility  0x02018A00  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   POKE_TOOL_AddMove  0x0201808C  thumb
 *   POKE_TOOL_PushMove  0x020180F4  thumb
 *   SYMBOL_MAP_IsHomeCell  0x02166618  thumb  ov010
 *   SYMBOL_MAP_IsPlainCell  0x02166640  thumb  ov010
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   TPOKE_DATA_Create  0x0202A128  thumb
 *   TPOKE_Delete  0x0202A170  thumb
 *   GFL_USE_GetRandomBelow  0x02005728  thumb
 *   INTRUDE_FIELD_gSymbolMonOffsetsHome     0x02183678  data  a4
 *   INTRUDE_FIELD_gSymbolMonOffsetsPlain     0x021835F8  data  a4
 *   INTRUDE_FIELD_gSymbolMonOffsetsOther     0x02183650  data  a4
 *   EVENT_COMM_COMMON_InitMsgBox  0x0217F2B4  thumb  ov018
 *   INTRUDE_COMM_SetState  0x02174E14  thumb  ov011
 *   EVENT_COMM_COMMON_SetupListWindowB  0x0217F528  thumb  ov018
 *   INTRUDE_COMM_SetWordSetRequest  0x021762D8  thumb  ov011
 *   EVENT_COMM_COMMON_PrintListWindowB  0x0217F574  thumb  ov018
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayTask  0x02029830  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   EVENT_COMM_COMMON_DeleteListWindowB  0x0217F58C  thumb  ov018
 *   INTRUDE_CMD_SendRecordAccept  0x02173FC0  thumb  ov011
 *   INTRUDE_COMM_IsSessionTimeLimitSet  0x02175A24  thumb  ov011
 *   EVENT_COMM_COMMON_ExitMsgBox  0x0217F318  thumb  ov018
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   INTRUDE_FIELD_gSpinAcmds     0x021836A0  data  a1
 */
#include "../types.h"

#include "../sdk_fx.h"

#include "../ov011/intrude_comm_types.h"
#include "intrude_field_types.h"
#include "../ov010/fldmmdl_types.h"

struct GameSystem;
struct GameComm;
struct GameData;
struct GameEvent;
struct PlayerWork;
struct MyStatus;
struct FieldMap;
struct FieldPlayer;
struct FieldPlaceName;
struct MsgBank;
struct FieldMsgWin;
struct FieldSysWin;
struct FieldMenuFunc;
struct WordSet;
struct U16Vec;
struct MapMatrix;
struct Container;
struct Pokemon;

/* Appearance of the player chosen for the Entralink visit. */
typedef struct PlayerLook {
    u8 flag;
    u8 kind;
    u16 objCode;
} PlayerLook;

/* Task that bounces the player off the edge of the map (0x18 bytes). */
typedef struct EdgeBlockWork {
    struct FieldMap *fieldMap;      /* 0x00 */
    Mmdl *playerMmdl;               /* 0x04 */
    struct MsgBank *msgData;        /* 0x08 */
    struct FieldMsgWin *msgWin;          /* 0x0C */
    int sessionBusy;                /* 0x10 */
    u16 edgeDir;                    /* 0x14: 2 left edge, 3 right edge */
    u16 moveDir;                    /* 0x16 */
} EdgeBlockWork;

/* Task that changes the area when the player crosses the edge (0x30 bytes). */
typedef struct AreaChangeWork {
    struct FieldMap *fieldMap;      /* 0x00 */
    Mmdl *playerMmdl;               /* 0x04 */
    struct MsgBank *msgData;        /* 0x08 */
    struct FieldMsgWin *msgWin;          /* 0x0C */
    struct WordSet *wordSet;        /* 0x10 */
    u16 edgeDir;                    /* 0x14 */
    u8 sessionBusy;                 /* 0x16 */
    u8 pad17;
    u8 transitionWork[0x18];        /* 0x18: set up by INTRUDE_FIELD_InitMmdlCopyAnime, stepped by INTRUDE_FIELD_MainMmdlCopyAnime */
} AreaChangeWork;

/* Event that asks whether to leave the Entralink (0x2C bytes). */
typedef struct ExitConfirmWork {
    struct MsgBank *msgData;        /* 0x00 */
    struct FieldMsgWin *endMsgWin;       /* 0x04 */
    struct FieldSysWin *promptWin;    /* 0x08 */
    struct FieldMenuFunc *yesNoMenu;    /* 0x0C */
    PlayerSpinWork spin;            /* 0x10 */
    u16 waitFrames;                 /* 0x28 */
    u16 pad2A;
} ExitConfirmWork;

/* Event that shows a notice and spins the player (0x20 bytes). */
typedef struct NoticeEventWork {
    struct MsgBank *msgData;        /* 0x00 */
    struct FieldSysWin *promptWin;    /* 0x04 */
    PlayerSpinWork spin;            /* 0x08 */
} NoticeEventWork;

/* Parameter block of GAME_COMM_Start for the Entralink (0x10 bytes). */
typedef struct IntrudeStartParam {
    struct GameSystem *gameSystem;  /* 0x00 */
    struct GameComm *gameComm;      /* 0x04 */
    int reserved08;
    u16 reserved0C;
    u8 startKind;                   /* 0x0E: 1 when started from the field */
    u8 pad0F;
} IntrudeStartParam;

/* IntrudeZonePos (the Entralink zone table entry, 0x0C bytes) is shared with the
 * sub screen and lives in intrude_field_types.h. */

/* Position that a visit offer waits at, per offer index. */
typedef struct IntrudeTilePos {
    s16 x;
    s16 y;
    s16 z;
    s16 pad06;
} IntrudeTilePos;

/* Move parameters per appearance of a spawned partner Pokemon. */
typedef struct IntrudeMmdlMoveParam {
    u16 moveCode;
    u8 moveLimitX;
    u8 moveLimitZ;
} IntrudeMmdlMoveParam;

/* One entry of a symbol map page (IntrudeSymbolPage.entries): one Pokemon wandering on the symbol map. */
typedef struct SymbolMonEntry {
    u32 species : 11;
    u32 move : 10;
    u32 sex : 2;
    u32 form : 6;
    u32 appearance : 3;
} SymbolMonEntry;

/* Context of the Pokemon spawn on a symbol map. */
typedef struct SymbolSpawnContext {
    struct Container *tpoke;        /* 0x00: the Tpoke container (tpoke_data.c) */
    struct FieldMap *fieldMap;      /* 0x04 */
    int objIdBase;                  /* 0x08 */
} SymbolSpawnContext;

/* Low byte of IntrudeRequestHead.reserved08: bit per net ID. */
typedef struct IntrudeNetIdMask {
    u8 netIds : 3;
    u8 rest : 5;
} IntrudeNetIdMask;

/* Placement of a model in MmdlHeader.pos: tile x and z, then the height. */
typedef struct MmdlGridPos {
    u16 x;
    u16 z;
    int y;
} MmdlGridPos;

/* Definition of one model placed on each area (five halfwords). */
typedef struct IntrudeAreaMmdlDef {
    u16 objCode;
    u16 gridX;
    u16 gridZ;
    u16 eventId;
    u16 objIdBase;
} IntrudeAreaMmdlDef;

typedef enum AreaMmdlIndex {
    AREA_MMDL_FIRST,
    AREA_MMDL_SECOND
} AreaMmdlIndex;

/* Work of the event that shows the offered request (0x88 bytes). */
typedef struct OfferEventWork {
    u16 senderNetId;                /* 0x00 */
    u16 pad02;
    struct FieldMap *fieldMap;      /* 0x04 */
    u8 infoWindow[0x30];            /* 0x08: set up by EVENT_COMM_COMMON_InitMsgBox */
    IntrudeMemberRecord record;     /* 0x38: copy of the active offer */
    PlayerSpinWork spin;            /* 0x6C */
    u8 showInfo;                    /* 0x84 */
    u8 pad85[3];
} OfferEventWork;

/* GAMESYSTEM, GAME_DATA, GAME_COMM and GAME_EVENT access */
#include "../arm9/gamesystem.h"
#include "../arm9/game_comm.h"
#include "../arm9/game_data.h"
#include "../arm9/zonedata.h"
#include "../arm9/net_err.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/ui.h"
#include "../arm9/net_system.h"
#include "../arm9/mi_memory.h"
#include "../arm9/key.h"
#include "../arm9/gfl_use.h"
#include "../arm9/net.h"
#include "../arm9/field_sound_system.h"
                                           
extern u32 MYSTATUS_GetId(const struct MyStatus *status);
#ifdef __MWERKS__
extern u8 MYSTATUS_GetSex(const struct MyStatus *status); /* original prototype; the definition differs in return type */
#else
extern u32 MYSTATUS_GetSex(struct MyStatus*);
#endif
#include "../arm9/gf_font.h"
#include "../arm9/wordset.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/msgdata.h"
struct MsgBank;
#ifdef __MWERKS__
extern void *ARC_UTIL_LoadMember(int arcId, int memberIdx, int decompress, int heapId); /* original prototype; the definition differs in return type, argument width */
#else
#include "../arm9/arc_util.h"
#endif
extern u32 POKE_TOOL_CreatePersonalRnd(u32 otId, s32 species, u16 form, s32 ratioMode, s32 shinyWanted, s32 mode);
#ifdef __MWERKS__
extern void *POKE_TOOL_Create(u16 species, u16 level, u64 id, int heapId); /* original prototype; the definition differs in return type, argument width */
#else
extern struct PokemonParam*POKE_TOOL_Create(u16, u16, u64, u16);
#endif
struct PokemonParam;
extern void POKE_TOOL_SetupPartyParamEx(struct PokemonParam *pp, u16 species, u16 level, u64 otId, u32 ivs, u64 personality);
struct BoxPokemon;
extern void POKE_TOOL_SetAbility(struct BoxPokemon *box, u32 species, u32 form);
extern u32 POKE_TOOL_ChangeForm(struct PokemonParam *pp, u32 form);
extern u16 POKE_TOOL_AddMove(struct PokemonParam *pp, u16 move);
extern void POKE_TOOL_PushMove(struct PokemonParam *pp, u16 move);
struct Container;
#include "../arm9/tpoke_data.h"
struct Tpoke;
struct CommPlayerWork;
/* COMM_PLAYER, FLDMMDL and symbol map */
#include "../ov010/symbol_map.h"
struct EventSlots;
#include "../ov010/event_field_proclink_return.h"
#include "../ov010/field_intrude_event.h"
extern Mmdl *FLDMMDL_AddMmdl(MmdlSys *mmdlSys, const MmdlHeader *header, int zoneId);
extern int FLDMMDL_CheckPossibleAcmd(Mmdl *mmdl);
extern u16 FLDMMDL_GetDirDisp(Mmdl *mmdl);
extern void FLDMMDL_SetAcmd(Mmdl *mmdl, u16 acmd);
#ifdef __MWERKS__
/* The original call passes three more arguments than the function takes; the callee ignores them. */
extern int FLDMMDL_CheckEndAcmd(Mmdl *mmdl, u32 *seq, void *work, u32 extra);
#else
extern int FLDMMDL_CheckEndAcmd(Mmdl *mmdl);
#endif
extern int FLDMMDL_EndAcmd(Mmdl *mmdl);
extern int FLDMMDL_GetParam(Mmdl *mmdl, int paramIndex);
struct MmdlGridVec;
struct Mmdl;
extern void FLDMMDL_GetGridNowPos(struct Mmdl *mmdl, struct MmdlGridVec *out);
extern short FLDMMDL_GetGridNowX(Mmdl *mmdl);
extern short FLDMMDL_GetGridNowZ(Mmdl *mmdl);
struct VecFx32;
extern void FLDMMDL_SetDrawOffset(struct Mmdl *mmdl, struct VecFx32 *offset);
extern void FLDMMDL_SysPauseMove(MmdlSys *mmdlSys);
struct MmdlSys;
extern void FLDMMDL_SysResumeMove(MmdlSys *mmdlSys);
struct IntrudeSession;
/* INTRUDE_COMM */
#include "../ov011/intrude_comm.h"
struct IntrudePeer;
struct IntrudeMemberName;
struct IntrudeRequestHead;
#include "../ov010/intrude_comm_query.h"
struct IntrudeRequestHead;
struct IntrudeCommSys;
#include "event_comm_common.h"
#include "../ov020/event_mapchange.h"
/* map matrix and field map */
#include "../ov010/map_matrix.h"
struct FieldG3dMapper;
#include "../ov021/field_g3d_mapper.h"
#include "../ov021/fieldmap.h"
struct FieldPlaceName;
#include "../ov021/field_place_name.h"
/* FIELD_MSGBG */
#include "../ov021/field_msgbg.h"
 /* the definition is void and leaves the window in r0 */
struct FieldMsgWin;
struct FieldSysWin;
struct MsgBank;
struct FieldMsgBg;
struct FieldMenuFunc;
struct FieldMsgBg;
/* FIELD_PLAYER */
#include "../ov021/field_player.h"
#include "../arm9/game_event.h"
#include "../ov010/comm_player.h"
#include "../arm9/tpoke_data.h"
struct EventCommMsgBox;
/* next original file (sub display and transition steps) */
struct PlayerSpinWork;
extern void INTRUDE_FIELD_InitMmdlCopyAnime(struct PlayerSpinWork *spinWork, void *gameSystem, void *fieldMap, void *intrudeWork, u16 id, u8 kind, u8 flag, u16 idx, s32 place);
#ifdef __MWERKS__
/* The original call passes the intrude work as a second argument the callee ignores. */
extern int INTRUDE_FIELD_MainMmdlCopyAnime(struct PlayerSpinWork *spinWork, void *intrudeWork);
#else
extern int INTRUDE_FIELD_MainMmdlCopyAnime(struct PlayerSpinWork *spinWork);
#endif

void INTRUDE_FIELD_Update(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player);
int INTRUDE_FIELD_FindRemotePlayerAhead(IntrudeCommSys *work, struct FieldPlayer *player, int *outIndex);
struct GameEvent *INTRUDE_FIELD_CreateEdgeBlockTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, u16 moveDir, u16 edgeDir, int sessionBusy);
int INTRUDE_FIELD_TaskEdgeBlock(struct GameEvent *event, u32 *seq, EdgeBlockWork *work, u32 eventArg3);
#ifndef __MWERKS__
static int INTRUDE_FIELD_TaskEdgeBlockEvent(struct GameEvent *event, int *seq, void *work)
{
    return INTRUDE_FIELD_TaskEdgeBlock(event, (u32 *)seq, (EdgeBlockWork *)work, 0);
}
#endif
struct GameEvent *INTRUDE_FIELD_CreateAreaChangeTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, u16 edgeDir);
int INTRUDE_FIELD_TaskAreaChange(struct GameEvent *event, int *seq, void *work);
struct GameEvent *INTRUDE_FIELD_CreateTileEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player);
struct GameEvent *INTRUDE_FIELD_CreateEdgeTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, int *posX, u16 moveDir, u16 facingDir);
struct GameEvent *INTRUDE_FIELD_CreateExitConfirmEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *work);
int INTRUDE_FIELD_EventExitConfirm(struct GameEvent *event, int *seq, void *work);
struct GameEvent *INTRUDE_FIELD_CreateNoticeEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap);
int INTRUDE_FIELD_EventNotice(struct GameEvent *event, int *seq, void *work);
int INTRUDE_FIELD_IsAtAreaEdge(const VecFx32 *pos);
int INTRUDE_FIELD_IsInEdgeMargin(const VecFx32 *pos);
void INTRUDE_FIELD_UpdateCommState(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct GameComm *gameComm, struct FieldPlayer *player);
void INTRUDE_FIELD_StartCommAfterExit(void *gameSystem, int result);
void INTRUDE_FIELD_StartComm(struct GameSystem *gameSystem);
void INTRUDE_FIELD_UpdateAreaIndex(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player, IntrudeCommSys *work);
void INTRUDE_FIELD_ResetExtraAreaCount(void *unusedArg0, void *unusedArg1, IntrudeCommSys *work);
void INTRUDE_FIELD_AddAreaMaps(struct FieldMap *fieldMap, struct GameSystem *gameSystem, IntrudeCommSys *work);
void INTRUDE_FIELD_AddAreaMapCount(struct FieldMap *fieldMap, int count);
void INTRUDE_FIELD_ChangePlayerLook(IntrudeCommSys *work, struct GameSystem *gameSystem, int objCode, u8 kind, u8 flag);
struct GameEvent *INTRUDE_FIELD_TryStartOfferEvent(struct GameSystem *gameSystem, IntrudeCommSys *work, struct FieldPlayer *player);
IntrudeZonePos *INTRUDE_FIELD_FindZonePos(u32 zoneId);
int INTRUDE_FIELD_GetZoneAnchor(int zoneId, VecFx32 *out);
void INTRUDE_FIELD_InitStartParam(IntrudeStartParam *param);
u8 INTRUDE_FIELD_GetStartKind(IntrudeStartParam *param);
void INTRUDE_FIELD_AddMmdl(struct FieldMap *fieldMap, u16 gridX, u16 gridZ, int height, u16 objCode, u16 eventId, u16 objId);
void INTRUDE_FIELD_AddAreaMmdls(struct FieldMap *fieldMap);
int INTRUDE_FIELD_IsDisconnectNeeded(struct GameSystem *gameSystem, int zoneId);
int INTRUDE_FIELD_IsStartRequested(IntrudeCommSys *work);
void INTRUDE_FIELD_SetSingleAreaMode(IntrudeCommSys *work);
u8 INTRUDE_FIELD_GetHostGender(struct GameComm *gameComm);
int INTRUDE_FIELD_IsListedZone(u32 zoneId);
void INTRUDE_FIELD_AddMarkerMmdl(struct FieldMap *fieldMap, u16 gridX, u16 gridZ, int height);
void INTRUDE_FIELD_AddMarkerMmdls(struct FieldMap *fieldMap);
void INTRUDE_FIELD_AddSymbolMonMmdl(const SymbolSpawnContext *spawn, const SymbolMonEntry *entry, u16 objId, u16 gridX, u16 gridZ, int height);
void INTRUDE_FIELD_GetMmdlParamPair(u32 *out, Mmdl *mmdl);
int INTRUDE_FIELD_GetMmdlParam0(Mmdl *mmdl);
void *INTRUDE_FIELD_CreateSymbolMon(int heapId, struct GameData *gameData, const SymbolMonEntry *entry);
void INTRUDE_FIELD_SpawnSymbolMons(struct FieldMap *fieldMap, int objIdBase, SymbolMonEntry *entries, int unused, int cellKind);
struct GameEvent *INTRUDE_FIELD_CreateOfferInfoEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *work, u16 senderNetId);
int INTRUDE_FIELD_EventOfferInfo(struct GameEvent *event, int *seq, void *work);
void INTRUDE_FIELD_InitPlayerSpin(PlayerSpinWork *spin, struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 objCode, u8 kind, u8 flag);
int INTRUDE_FIELD_StepPlayerSpin(PlayerSpinWork *spin, IntrudeCommSys *work);

extern const VecFx32 INTRUDE_FIELD_gSymbolMarkerPos;
extern const char INTRUDE_FIELD_gStartParamFile[];
extern u16 gIntrudeOfferZoneIds[];
extern IntrudeTilePos gIntrudeOfferTilePositions[];
extern IntrudeZonePos INTRUDE_FIELD_gZonePositions[];
extern const VecFx32 INTRUDE_FIELD_gHomeAnchorPos;
extern const MmdlHeader INTRUDE_FIELD_gMmdlHeaderTemplate;
extern const IntrudeAreaMmdlDef INTRUDE_FIELD_gAreaMmdlDefs[];
extern const u32 INTRUDE_FIELD_gListedZoneCount;
extern const u16 INTRUDE_FIELD_gListedZones[];
extern const MmdlHeader INTRUDE_FIELD_gMarkerMmdlHeader;
extern const IntrudeMmdlMoveParam INTRUDE_FIELD_gSymbolMonMoveParams[];
extern const MmdlHeader INTRUDE_FIELD_gSymbolMonMmdlHeader;
extern const u8 INTRUDE_FIELD_gSymbolMonOffsetsHome[20][2];
extern const u8 INTRUDE_FIELD_gSymbolMonOffsetsPlain[20][2];
extern const u8 INTRUDE_FIELD_gSymbolMonOffsetsOther[20][2];
extern const u8 INTRUDE_FIELD_gSpinAcmds[4];

void INTRUDE_FIELD_Update(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player)
{
    int zoneId;
    struct GameComm *gameComm;
    IntrudeCommSys *work;
    struct GameData *gameData;
    int ownId;
    int i;
    int objCode;

    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    work = GAME_COMM_GetWork(gameComm);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    if (GAME_DATA_IsSaving(gameData) == 1)
        return;
    INTRUDE_FIELD_UpdateCommState(fieldMap, gameSystem, gameComm, player);
    if (GAME_COMM_GetKind(gameComm) != 2 || work == 0)
        return;
    zoneId = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(gameData));
    if (work->specialZoneEntered == 0 && ZONEDATA_IsEntralink(zoneId) == 1)
        work->specialZoneEntered = 1;
    INTRUDE_FIELD_AddAreaMaps(fieldMap, gameSystem, work);
    if (work->step != 7 || GFL_NET_ERR_GetErrorLevel() != 0)
        return;
    if (GAME_DATA_GetIntrudeCount(gameData) == 0) {
        if (work->zoneCheck == 0) {
            if (INTRUDE_FIELD_IsListedZone(work->localPeer.zoneId) == 1)
                work->zoneCheck = 1;
            else
                work->zoneCheck = 2;
        }
        if (work->zoneCheck == 2)
            return;
    }
    ownId = GAME_DATA_GetOwnNetId(gameData);
    INTRUDE_COMM_UpdatePlayerObjects(work);
    COMM_PLAYER_Update(gameSystem, work->commPlayer);
    for (i = 0; i < 3; i++) {
        if (i == ownId || !(work->peerMask & (1 << i)))
            continue;
        if (COMM_PLAYER_CheckOccupy(work->commPlayer, i) == 0) {
            GAME_DATA_GetMyStatusPlayer(gameData, i);
            objCode = INTRUDE_COMM_GetPlayerObjCode(&work->peers[i], (GAME_DATA_GetMyStatusPlayer(gameData, i)));
            if (work->peers[i].objCode != 0 || GAME_DATA_GetIntrudeCount(gameData) != 0)
                COMM_PLAYER_Add(work->commPlayer, i, objCode, &work->peers[i].package);
        } else {
            COMM_PLAYER_SetPackage(work->commPlayer, i, &work->peers[i].package);
            if (work->peers[i].package.vanish == 0) {
                if ((u16)(work->peers[i].state + 0xFFFE) <= 1)
                    COMM_PLAYER_SetEffect(work->commPlayer, i);
            }
        }
    }
    INTRUDE_FIELD_UpdateAreaIndex(fieldMap, gameSystem, player, work);
}

int INTRUDE_FIELD_FindRemotePlayerAhead(IntrudeCommSys *work, struct FieldPlayer *player, int *outIndex)
{
    int moveState;
    int peerIndex;
    u32 hit;
    int result;
    s16 grid[3];

    result = 0;
    hit = result;
    if (work == 0 || work->commPlayer == 0)
        return 0;
    moveState = FIELD_PLAYER_GetFormCode(player);
    if (moveState != 0 && moveState != 1)
        return result;
    FIELD_PLAYER_GetFrontGridPos(player, grid + 2, grid + 1, grid);
    for (;;) {
        moveState = COMM_PLAYER_SearchGridPos(work->commPlayer, grid[2], grid[1], grid[0], &peerIndex, &hit);
        if (moveState != 1)
            break;
        if (work->peers[peerIndex].package.vanish == 0) {
            *outIndex = peerIndex;
            return 1;
        }
    }
    return 0;
}

struct GameEvent *INTRUDE_FIELD_CreateEdgeBlockTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, u16 moveDir, u16 edgeDir, int sessionBusy)
{
    struct GameEvent *event;
    EdgeBlockWork *work;

#ifdef __MWERKS__
    event = GAME_EVENT_Create(gameSystem, 0, (GameEventFunc)INTRUDE_FIELD_TaskEdgeBlock, sizeof(EdgeBlockWork));
#else
    event = GAME_EVENT_Create(gameSystem, 0, INTRUDE_FIELD_TaskEdgeBlockEvent, sizeof(EdgeBlockWork));
#endif
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, sizeof(EdgeBlockWork));
    work->fieldMap = fieldMap;
    work->playerMmdl = FIELD_PLAYER_GetMmdl(player);
    work->moveDir = moveDir;
    work->edgeDir = edgeDir;
    work->sessionBusy = sessionBusy;
    return event;
}

int INTRUDE_FIELD_TaskEdgeBlock(struct GameEvent *event, u32 *seq, EdgeBlockWork *work, u32 eventArg3)
{
    u16 turnAcmd;
    int acmd;
    struct FieldMsgBg *msgBg;

    switch (*seq) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(work->playerMmdl) == 1) {
            if (work->edgeDir == 3)
                acmd = 3;
            else
                acmd = 2;
            turnAcmd = acmd;
            if (work->edgeDir != FLDMMDL_GetDirDisp(work->playerMmdl)) {
                FLDMMDL_SetAcmd(work->playerMmdl, turnAcmd);
                *seq += 1;
            } else {
                *seq = 2;
            }
        }
        break;
    case 1:
#ifdef __MWERKS__
        if (FLDMMDL_CheckEndAcmd(work->playerMmdl, seq, work, eventArg3) == 1) {
            FLDMMDL_EndAcmd(work->playerMmdl);
            *seq += 1;
        }
#else
        if (FLDMMDL_CheckEndAcmd(work->playerMmdl) == 1) {
            FLDMMDL_EndAcmd(work->playerMmdl);
            *seq += 1;
        }
#endif
        break;
    case 2:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        msgBg = FIELDMAP_GetMsgBg(work->fieldMap);
        work->msgData = FIELD_MSGBG_CreateMsgData(msgBg, 0x2D);
        work->msgWin = FIELD_MSGBG_CreateBottomMsgWin(msgBg, work->msgData);
        FIELD_MSGBG_MsgWinPrintMsg(work->msgWin, 0, 0, work->sessionBusy == 0 ? 0x52 : 0x4F);
        *seq += 1;
        break;
    case 3:
        if (FIELD_MSGBG_IsMsgWinTransDone(work->msgWin) == 1)
            *seq += 1;
        break;
    case 4:
        if (work->sessionBusy == 0) {
            if (KEY_GetTrg() & 3)
                *seq += 1;
        } else {
            if (KEY_GetTrg() & 0xF3)
                *seq = 8;
        }
        break;
    case 5:
        FIELD_MSGBG_ClearMsgWin(work->msgWin);
        FIELD_MSGBG_MsgWinPrintMsg(work->msgWin, 0, 0, 0x53);
        *seq += 1;
        break;
    case 6:
        if (FIELD_MSGBG_IsMsgWinTransDone(work->msgWin) == 1)
            *seq += 1;
        break;
    case 7:
        if (KEY_GetTrg() & 0xF3)
            *seq += 1;
        break;
    case 8:
        FIELD_MSGBG_DeleteMsgWin(work->msgWin);
        MSGDATA_Delete(work->msgData);
        *seq += 1;
        break;
    case 9:
        if (FLDMMDL_CheckPossibleAcmd(work->playerMmdl) == 1) {
            FLDMMDL_SetAcmd(work->playerMmdl, (u16)(work->edgeDir == 3 ? 10 : 11));
            *seq += 1;
        }
        break;
    case 10:
#ifdef __MWERKS__
        if (FLDMMDL_CheckEndAcmd(work->playerMmdl, seq, work, eventArg3) == 1) {
            FLDMMDL_EndAcmd(work->playerMmdl);
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
            return 1;
        }
#else
        if (FLDMMDL_CheckEndAcmd(work->playerMmdl) == 1) {
            FLDMMDL_EndAcmd(work->playerMmdl);
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
            return 1;
        }
#endif
        break;
    }
    return 0;
}

struct GameEvent *INTRUDE_FIELD_CreateAreaChangeTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, u16 edgeDir)
{
    struct GameEvent *event;
    AreaChangeWork *work;

    event = GAME_EVENT_Create(gameSystem, 0, INTRUDE_FIELD_TaskAreaChange, sizeof(AreaChangeWork));
    work = GAME_EVENT_GetWork(event);
    MI_CpuFill8(work, 0, sizeof(AreaChangeWork));
    work->fieldMap = fieldMap;
    work->playerMmdl = FIELD_PLAYER_GetMmdl(player);
    work->edgeDir = edgeDir;
    return event;
}

int INTRUDE_FIELD_TaskAreaChange(struct GameEvent *event, int *seq, void *workPtr)
{
    AreaChangeWork *work = workPtr;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    struct GameData *gameData;
    IntrudeCommSys *intrudeWork;
    struct FieldMsgBg *msgBg;
    struct FieldPlaceName *placeName;
    struct Strbuf *nameText;
    struct Strbuf *template;
    PlayerLook look;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    intrudeWork = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    switch (*seq) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        *seq += 1;
        break;
    case 1:
        if (FLDMMDL_CheckPossibleAcmd(work->playerMmdl) == 0)
            break;
        if (intrudeWork == 0) {
            *seq = 6;
            break;
        }
        if (INTRUDE_COMM_IsSessionAcceptedOrResultReady(&intrudeWork->session) == 1) {
            work->sessionBusy = 1;
            INTRUDE_FIELD_InitMmdlCopyAnime((struct PlayerSpinWork *)work->transitionWork, gameSystem, work->fieldMap, intrudeWork, 0, 0, 0, work->edgeDir, 0);
        } else if (INTRUDE_COMM_IsStepToOwnArea(gameComm, gameData, work->edgeDir) == 1) {
            INTRUDE_FIELD_InitMmdlCopyAnime((struct PlayerSpinWork *)work->transitionWork, gameSystem, work->fieldMap, intrudeWork, 0, 0, 0, work->edgeDir, 1);
        } else {
            INTRUDE_COMM_PickDefaultObjCode((GAME_DATA_GetMyStatus(gameData)), &look.objCode, &look.kind, &look.flag);
            INTRUDE_FIELD_InitMmdlCopyAnime((struct PlayerSpinWork *)work->transitionWork, gameSystem, work->fieldMap, intrudeWork, look.objCode, look.kind, look.flag, work->edgeDir, 1);
        }
        *seq += 1;
        break;
    case 2:
#ifdef __MWERKS__
        if (INTRUDE_FIELD_MainMmdlCopyAnime((struct PlayerSpinWork *)work->transitionWork, intrudeWork) == 1)
            *seq += 1;
#else
        if (INTRUDE_FIELD_MainMmdlCopyAnime((struct PlayerSpinWork *)work->transitionWork) == 1)
            *seq += 1;
#endif
        break;
    case 3:
        if (intrudeWork == 0) {
            *seq = 6;
            break;
        }
        msgBg = FIELDMAP_GetMsgBg(work->fieldMap);
        work->msgData = FIELD_MSGBG_CreateMsgData(msgBg, 0x2D);
        work->msgWin = FIELD_MSGBG_CreateBottomMsgWin(msgBg, work->msgData);
        work->wordSet = WORDSET_CreateDefault(4);
        if (intrudeWork->localPeer.intrudeId == GAME_DATA_GetOwnNetId(gameData)) {
            if (work->sessionBusy == 1)
                FIELD_MSGBG_MsgWinPrintMsg(work->msgWin, 0, 0, 0x4F);
            else
                FIELD_MSGBG_MsgWinPrintMsg(work->msgWin, 0, 0, 0x4E);
        } else {
            nameText = STRBUF_Create(0x100, 0x15);
            WORDSET_SetSlotMyStatus(work->wordSet, 0, GAME_DATA_GetMyStatusPlayer(gameData, intrudeWork->localPeer.intrudeId));
            if (work->sessionBusy == 1)
                template = MSGDATA_AllocString(work->msgData, 0x50);
            else
                template = MSGDATA_AllocString(work->msgData, 0x51);
            WORDSET_CopyTaggedText(work->wordSet, nameText, template);
            FIELD_MSGBG_MsgWinPrintStr(work->msgWin, 0, 0, nameText);
            STRBUF_Delete(template);
            STRBUF_Delete(nameText);
        }
        *seq += 1;
        break;
    case 4:
        if (FIELD_MSGBG_IsMsgWinTransDone(work->msgWin) == 1) {
            placeName = FIELDMAP_GetPlaceName(work->fieldMap);
            FIELD_PLACE_NAME_ForceShowForZone(placeName, FIELDMAP_GetZoneId(work->fieldMap));
            *seq += 1;
        }
        break;
    case 5:
        if (KEY_GetTrg() & 0xF3)
            *seq += 1;
        break;
    case 6:
        if (work->msgWin != 0) {
            FIELD_MSGBG_DeleteMsgWin(work->msgWin);
            MSGDATA_Delete(work->msgData);
            WORDSET_Delete(work->wordSet);
        }
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->fieldMap));
        return 1;
    }
    return 0;
}

struct GameEvent *INTRUDE_FIELD_CreateTileEvent(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player)
{
    int zoneId;
    IntrudeCommSys *work;
    int i;
    int areaBaseX;
    VecFx32 playerPos;
    VecFx32 markerPos;

    zoneId = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(gameSystem));
    work = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
    if (ZONEDATA_IsEntralink(zoneId) == 0)
        return 0;
    FIELD_PLAYER_GetPos(player, &playerPos);
    for (i = 0; i < 3; i++) {
        if (playerPos.x >= (i << 22) + 0x1F8000 && playerPos.x <= (i << 22) + 0x1F8000 && playerPos.z >= 0x2C8000 && playerPos.z <= 0x2C8000)
            return INTRUDE_FIELD_CreateExitConfirmEvent(gameSystem, fieldMap, work);
    }
    areaBaseX = 0x1F8000;
    for (i = 0; i < 3; i++) {
        if (playerPos.x >= areaBaseX && playerPos.x < areaBaseX + 0x20000 && playerPos.z == 0x158000) {
            markerPos = INTRUDE_FIELD_gSymbolMarkerPos;
            markerPos.x += playerPos.x - areaBaseX;
            return FIELD_INTRUDE_EVENT_CreateSymbolEntryEvent(gameSystem, 1, &markerPos, 0, 4);
        }
        areaBaseX += 0x400000;
    }
    return 0;
}

struct GameEvent *INTRUDE_FIELD_CreateEdgeTask(struct GameSystem *gameSystem, struct FieldMap *fieldMap, struct FieldPlayer *player, int *posX, u16 moveDir, u16 facingDir)
{
    IntrudeCommSys *work;
    u16 edgeDir;
    int column;
    int x;
    int areaCount;
    int offsetInArea;

    work = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
    edgeDir = 9;
    x = *posX;
    areaCount = 1;
    if (work)
        areaCount = work->memberCount;
    if (x <= 0) {
        x += areaCount << 22;
    } else if (x >= areaCount << 22) {
        x -= areaCount << 22;
    }
    column = ((x >> 12) / 16) % 64;
    offsetInArea = x % 0x400000;
    if (facingDir == 2) {
        if ((moveDir != 3 || (moveDir == 3 && offsetInArea <= 0x8000)) && column == 0)
            edgeDir = 2;
    } else if (facingDir == 3) {
        if ((moveDir != 2 || (moveDir == 2 && offsetInArea >= 0x3F8000)) && column == 0x3F)
            edgeDir = 3;
    }
    if (edgeDir != 9) {
        if (work == 0 || GFL_NET_GetNegotiationNum() <= 1 || work->memberCount < 2)
            return INTRUDE_FIELD_CreateEdgeBlockTask(gameSystem, fieldMap, player, moveDir, edgeDir, 0);
        if (INTRUDE_COMM_IsSessionAcceptedOrResultReady(&work->session) == 1)
            return INTRUDE_FIELD_CreateEdgeBlockTask(gameSystem, fieldMap, player, moveDir, edgeDir, 1);
        return INTRUDE_FIELD_CreateAreaChangeTask(gameSystem, fieldMap, player, edgeDir);
    }
    return 0;
}

struct GameEvent *INTRUDE_FIELD_CreateExitConfirmEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *work)
{
    struct GameEvent *event;
    ExitConfirmWork *eventWork;

    event = GAME_EVENT_Create(gameSystem, 0, INTRUDE_FIELD_EventExitConfirm, sizeof(ExitConfirmWork));
    eventWork = GAME_EVENT_GetWork(event);
    MI_CpuFill8(eventWork, 0, sizeof(ExitConfirmWork));
    return event;
}

/*
 * Byte-correct (528 of 528 bytes).  Sole blocker: the THM_CALL at +0x13C to
 * 0x02012798, an unlabelled arm9 leaf that disasm.py prints as .word data in
 * the pool at 02012794 (asm/arm9/main.s), after the pop at 0x02012790 and before
 * GAME_DATA_GetMyPlayerWork; no listing labels it and this call is its only witness, so
 * every class refuses it.  Verified EXACT at 0x02012798 (arm9, thumb, 10 B):
 *
 *     u8 *GAME_DATA_GetPlayerWork(u8 *p, int i) { return p + 4 + i * 0x44; }
 *
 * It is the player work indexer that belongs beside GAME_DATA_GetMyStatusPlayer in
 * src/matched/arm9/unit_02012924.c; once it is labelled or matched this file
 * should verify EXACT unchanged.  The 12-byte scratch is a cast u8 buffer
 * (docs/idioms/a-declared-struct-local-folds-to-sp-relative-a-cast-buffer-does-not.md):
 * the stores go through r7, which a declared struct folds to sp.
 */
int INTRUDE_FIELD_EventExitConfirm(struct GameEvent *event, int *seq, void *workPtr)
{
    ExitConfirmWork *work = workPtr;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct GameComm *gameComm;
    struct FieldMsgBg *msgBg;
    int answer;
    struct GameData *gameData;
    int i;
    u8 zeroPos[12];
    struct PlayerPosition *zeroPosView;
    Mmdl *playerMmdl;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    switch (*seq) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        msgBg = FIELDMAP_GetMsgBg(fieldMap);
        work->msgData = FIELD_MSGBG_CreateMsgData(msgBg, 0x2D);
        work->promptWin = FIELD_MSGBG_CreateBottomSysWin((struct FieldMsgBg *)msgBg, (struct MsgBank *)work->msgData);
        FIELD_MSGBG_SysWinPrintMsg(work->promptWin, 0, 0, 0x54);
        *seq += 1;
        break;
    case 1:
        if (FIELD_MSGBG_SysWinMain(work->promptWin) == 1) {
            work->yesNoMenu = FIELD_MSGBG_CreateYesNoMenu((void *)(FIELDMAP_GetMsgBg(fieldMap)), 0);
            *seq += 1;
        }
        break;
    case 2:
        answer = FIELD_MSGBG_YesNoMenuMain(work->yesNoMenu);
        if (answer != 2) {
            FIELD_MSGBG_DeleteMenuFunc(work->yesNoMenu);
            FIELD_MSGBG_DeleteSysWin(work->promptWin);
            work->yesNoMenu = 0;
            work->promptWin = 0;
            if (answer == 0)
                *seq = 3;
            else
                *seq = 11;
        }
        break;
    case 3:
        if (GFL_NET_ERR_GetErrorLevel() == 0 && GAME_COMM_GetKind(gameComm) == 2) {
            GAME_COMM_RequestExitNoCallback(gameComm);
            work->endMsgWin = FIELD_MSGBG_CreateBottomMsgWin(FIELDMAP_GetMsgBg(fieldMap), work->msgData);
            FIELD_MSGBG_MsgWinPrintMsg(work->endMsgWin, 0, 0, 0x14);
        }
        *seq += 1;
        break;
    case 4:
        if (work->endMsgWin == 0 || FIELD_MSGBG_IsMsgWinTransDone(work->endMsgWin) == 1)
            *seq += 1;
        break;
    case 5:
        work->waitFrames++;
        if (work->endMsgWin != 0 && work->waitFrames <= 0x3C)
            break;
        if (GAME_COMM_GetKind(gameComm) == 2)
            break;
        gameData = GAMESYSTEM_GetGameData(gameSystem);
        zeroPosView = (struct PlayerPosition *)zeroPos;
        zeroPosView->x = 0;
        zeroPosView->y = 0;
        zeroPosView->z = 0;
        for (i = 0; i < 3; i++)
            GAME_DATA_SetPlayerPosition(GAME_DATA_GetPlayerWork(gameData, i), zeroPosView);
        *seq += 1;
        break;
    case 6:
        if (work->endMsgWin != 0)
            FIELD_MSGBG_DeleteMsgWin(work->endMsgWin);
        MSGDATA_Delete(work->msgData);
        *seq += 1;
        break;
    case 7:
        fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
        if (FIELDMAP_IsReady(fieldMap) != 1)
            break;
        if (FIELD_PLAYER_CheckFormModel(FIELDMAP_GetFieldPlayer(fieldMap)) == 0) {
            INTRUDE_FIELD_InitPlayerSpin(&work->spin, gameSystem, fieldMap, 0, 0, 0);
            *seq += 1;
        } else {
            *seq = 9;
        }
        break;
    case 8:
        if (INTRUDE_FIELD_StepPlayerSpin(&work->spin, 0) == 1)
            *seq += 1;
        break;
    case 9:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateIntrudeReturnEvent(gameSystem));
        *seq += 1;
        break;
    case 10:
        *seq = 14;
        break;
    case 11:
        MSGDATA_Delete(work->msgData);
        *seq = 12;
        break;
    case 12:
        playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
        if (FLDMMDL_CheckPossibleAcmd(playerMmdl) == 1) {
            FLDMMDL_SetAcmd(playerMmdl, 8);
            *seq += 1;
        }
        break;
    case 13:
        if (FLDMMDL_EndAcmd(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap))) == 1)
            *seq = 14;
        break;
    case 14:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
        return 1;
    }
    return 0;
}

struct GameEvent *INTRUDE_FIELD_CreateNoticeEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap)
{
    struct GameEvent *event;
    NoticeEventWork *work;

    event = GAME_EVENT_Create(gameSystem, 0, INTRUDE_FIELD_EventNotice, sizeof(NoticeEventWork));
    work = GAME_EVENT_GetWork(event);
    return event;
}

int INTRUDE_FIELD_EventNotice(struct GameEvent *event, int *seq, void *workPtr)
{
    NoticeEventWork *work = workPtr;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;
    struct FieldMsgBg *msgBg;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    GAMESYSTEM_GetGameComm(gameSystem);
    switch (*seq) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        msgBg = FIELDMAP_GetMsgBg(fieldMap);
        work->msgData = FIELD_MSGBG_CreateMsgData(msgBg, 0x2D);
        work->promptWin = FIELD_MSGBG_CreateBottomSysWin((struct FieldMsgBg *)msgBg, (struct MsgBank *)work->msgData);
        FIELD_MSGBG_SysWinPrintMsg(work->promptWin, 0, 0, 0x60);
        (*seq)++;
        break;
    case 1:
        if (FIELD_MSGBG_SysWinMain(work->promptWin) == 1) {
            FIELD_MSGBG_DeleteSysWin(work->promptWin);
            MSGDATA_Delete(work->msgData);
            (*seq)++;
        }
        break;
    case 2:
        fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
        if (FIELDMAP_IsReady(fieldMap) == 1) {
            if (FIELD_PLAYER_CheckFormModel(FIELDMAP_GetFieldPlayer(fieldMap)) == 0) {
                INTRUDE_FIELD_InitPlayerSpin(&work->spin, gameSystem, fieldMap, 0, 0, 0);
                (*seq)++;
            } else {
                *seq = 4;
            }
        }
        break;
    case 3:
        if (INTRUDE_FIELD_StepPlayerSpin(&work->spin, 0) == 1)
            (*seq)++;
        break;
    case 4:
        GAME_EVENT_CallEvent(event, EVENT_MAPCHANGE_CreateIntrudeReturnEvent(gameSystem));
        (*seq)++;
        break;
    case 5:
        if (fieldMap != 0 && FIELDMAP_IsReady(fieldMap) == 1) {
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
            return 1;
        }
        break;
    }
    return 0;
}

int INTRUDE_FIELD_IsAtAreaEdge(const VecFx32 *pos)
{
    if (pos->x >= 0x348000 || pos->x <= 0xb8000)
        return 1;
    return 0;
}

int INTRUDE_FIELD_IsInEdgeMargin(const VecFx32 *pos)
{
    if (pos->x > 0x308000 || pos->x < 0xe8000)
        return 1;
    return 0;
}

void INTRUDE_FIELD_UpdateCommState(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct GameComm *gameComm, struct FieldPlayer *player)
{
    VecFx32 playerPos;

    if (GAME_COMM_GetCounter(gameComm) != 0)
        return;
    if (GAME_COMM_IsTransition(gameComm) == 1)
        return;
    if (GFL_NET_ERR_GetErrorLevel() != 0)
        return;
    if (DWCi_IsFold() == 1 && UI_IsPowerConnected() == 1)
        return;
    if (GAMESYSTEM_IsNetOffBySleep(gameSystem) == 1)
        return;
    if (GAMESYSTEM_IsEventActive(gameSystem) == 1)
        return;
    if (ZONEDATA_IsEntralink(GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork(GAMESYSTEM_GetGameData(gameSystem)))) == 0)
        return;
    FIELD_PLAYER_GetPos(player, &playerPos);
    switch (GAME_COMM_GetKind(gameComm)) {
    case 0:
        if (INTRUDE_FIELD_IsAtAreaEdge(&playerPos) == 1)
            INTRUDE_FIELD_StartComm(gameSystem);
        break;
    case 2:
        if (INTRUDE_FIELD_IsAtAreaEdge(&playerPos) != 0)
            return;
        if (GFL_NET_SYSTEM_GetConnectNum() > 1)
            return;
        if (((IntrudeCommSys *)GAME_COMM_GetWork(gameComm))->step == 4)
            return;
        GAME_COMM_RequestExitNoCallback(gameComm);
        break;
    case 1:
        if (INTRUDE_FIELD_IsAtAreaEdge(&playerPos) == 1)
            GAME_COMM_RequestExit(gameComm, INTRUDE_FIELD_StartCommAfterExit, gameSystem);
        break;
    }
}

void INTRUDE_FIELD_StartCommAfterExit(void *gameSystem, int result)
{
    if (result == 0)
        INTRUDE_FIELD_StartComm(gameSystem);
}

void INTRUDE_FIELD_StartComm(struct GameSystem *gameSystem)
{
    struct GameComm *gameComm;
    IntrudeStartParam *param;

    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    if (GFL_NET_ERR_GetErrorLevel() != 0)
        return;
    if (GAMESYSTEM_IsNetOffBySleep(gameSystem) == 1)
        return;
    if (DWCi_IsFold() == 1 && UI_IsPowerConnected() == 1)
        return;
    param = GFL_HEAP_Alloc(0x8005, sizeof(IntrudeStartParam), 1, (char *)INTRUDE_FIELD_gStartParamFile, 0x528);
    param->startKind = 1;
    param->gameSystem = gameSystem;
    param->gameComm = gameComm;
    GAME_COMM_Start(gameComm, 2, (uptr)param);
}

void INTRUDE_FIELD_UpdateAreaIndex(struct FieldMap *fieldMap, struct GameSystem *gameSystem, struct FieldPlayer *player, IntrudeCommSys *work)
{
    int x;
    int areaIndex;
    VecFx32 playerPos;
    VecFx32 wrappedPos;
    int wrapped;
    int prevAreaId;
    int areaSpan;
    int zoneId;
    struct PlayerWork *playerWork;
    struct GameComm *gameComm;

    playerWork = GAMESYSTEM_GetMyPlayerWork(gameSystem);
    zoneId = GAME_DATA_GetPlayerZoneId(playerWork);
    GAME_DATA_GetPlayerDirectionType(playerWork);
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    wrapped = 0;
    GAMESYSTEM_GetGameData(gameSystem);
    if ((int)GAME_COMM_GetKind(gameComm) != 2)
        return;
    if (work == 0)
        return;
    if (ZONEDATA_IsEntralink(zoneId) == 0)
        return;
    if (work->memberCount < 2)
        return;
    if (INTRUDE_COMM_HasResultReward(work, &work->session) == 1)
        return;
    FIELD_PLAYER_GetPos(player, &playerPos);
    wrappedPos = playerPos;
    x = playerPos.x;
    prevAreaId = work->localPeer.intrudeId;
    areaSpan = (work->lastAreaIndex + 1) << 22;
    if (x < 0) {
        wrappedPos.x = areaSpan + x;
        wrapped = 1;
    } else if (x > areaSpan) {
        wrappedPos.x = x - areaSpan;
        wrapped = 1;
    }
    if (wrapped == 1) {
        x = wrappedPos.x;
        if (GAMESYSTEM_IsEventActive(gameSystem) == 1) {
            wrappedPos = playerPos;
            wrapped = 0;
        }
    }
    areaIndex = x / 0x400000;
    if (wrapped == 1) {
        FIELD_PLAYER_SetPos(player, &wrappedPos);
        INTRUDE_COMM_AdjustAllRemotePositions(work, wrappedPos.x);
    }
    areaIndex += GFL_NET_SYSTEM_GetCurrentAid();
    if (areaIndex > work->lastAreaIndex)
        areaIndex -= work->lastAreaIndex + 1;
    if (prevAreaId == areaIndex)
        return;
    INTRUDE_COMM_SetIntrudeId(work, areaIndex);
    work->peerStatusDirty = 1;
    EVENT_FIELD_PROCLINK_SetReturnLinkId((struct EventSlots *)work->returnSlots, (u8)areaIndex);
}

void INTRUDE_FIELD_ResetExtraAreaCount(void *unusedArg0, void *unusedArg1, IntrudeCommSys *work)
{
    work->lastAreaIndex = 0;
}

void INTRUDE_FIELD_AddAreaMaps(struct FieldMap *fieldMap, struct GameSystem *gameSystem, IntrudeCommSys *work)
{
    VecFx32 playerPos;
    int areaLimit;
    struct FieldPlayer *player;
    struct MapMatrix *matrix;

    if (work == 0 || fieldMap == 0)
        return;
    if (FIELDMAP_GetG3dMapper(fieldMap) == 0)
        return;
    if (ZONEDATA_IsEntralink(FIELDMAP_GetZoneId(fieldMap)) == 0)
        return;
    areaLimit = work->memberCount - 1;
    if (areaLimit <= 0)
        areaLimit = 1;
    if (work->flagBit5 == 1)
        areaLimit = 1;
    if (work->lastAreaIndex >= areaLimit)
        return;
    player = FIELDMAP_GetFieldPlayer(fieldMap);
    if (player == 0)
        return;
    FIELD_PLAYER_GetPos(player, &playerPos);
    playerPos.x = playerPos.x % 0x400000;
    if (INTRUDE_FIELD_IsInEdgeMargin(&playerPos) == 1)
        return;
    matrix = MAP_MATRIX_Create(0x8015);
    MAP_MATRIX_Load(matrix, 0x76, 0x76 + 0xa1, 0x8015);
    do {
        FIELD_G3D_MAPPER_AppendMatrix(fieldMap, FIELDMAP_GetG3dMapper(fieldMap), matrix);
        work->lastAreaIndex++;
    } while (work->lastAreaIndex < areaLimit);
    MAP_MATRIX_Delete(matrix);
}

void INTRUDE_FIELD_AddAreaMapCount(struct FieldMap *fieldMap, int count)
{
    struct MapMatrix *matrix;

    if (count >= 3)
        count = 2;
    matrix = MAP_MATRIX_Create(0x15);
    MAP_MATRIX_Load(matrix, 0x76, 0x76 + 0xa1, 0x8015);
    while (count > 0) {
        FIELD_G3D_MAPPER_AppendMatrix(fieldMap, FIELDMAP_GetG3dMapper(fieldMap), matrix);
        count--;
    }
    MAP_MATRIX_Delete(matrix);
}

void INTRUDE_FIELD_ChangePlayerLook(IntrudeCommSys *work, struct GameSystem *gameSystem, int objCode, u8 kind, u8 flag)
{
    int playerForm;
    struct FieldPlayer *player;
    int gender;
    struct MyStatus *myStatus;
    struct GameData *gameData = GAMESYSTEM_GetGameData(gameSystem);
    VecFx32 drawOffset = { 0, 0, 0 };

    if (GAMESYSTEM_IsFieldMapActive(gameSystem) == 0)
        return;
    myStatus = GAME_DATA_GetMyStatus(GAMESYSTEM_GetGameData(gameSystem));
    gender = MYSTATUS_GetSex(myStatus);
    if (work != 0) {
        if (objCode == 0xFFFF) {
            if (work->localPeer.intrudeId == GAME_DATA_GetOwnNetId(gameData))
                objCode = 0;
        }
        if (objCode == 0) {
            kind = gender == 0 ? 3 : 4;
            flag = gender;
        }
        if (work->localPeer.objCode == objCode)
            return;
        work->localPeer.objCode = objCode;
        work->localPeer.lookKind = kind;
        work->localPeer.lookFlag = flag;
        work->peerStatusDirty = 1;
        playerForm = INTRUDE_COMM_GetPlayerObjCode(&work->localPeer, myStatus);
    } else {
        objCode = 0;
        playerForm = 1;
        if (gender)
            playerForm = 4;
    }
    player = FIELDMAP_GetFieldPlayer(GAMESYSTEM_GetFieldMap(gameSystem));
    FIELD_PLAYER_SetObjCode(player, (u16)playerForm);
    FLDMMDL_SetDrawOffset(FIELD_PLAYER_GetMmdl(player), (struct VecFx32 *)(&drawOffset));
    if (objCode == 0)
        FIELD_PLAYER_ClearRememberedObjCode(player);
}

struct GameEvent *INTRUDE_FIELD_TryStartOfferEvent(struct GameSystem *gameSystem, IntrudeCommSys *work, struct FieldPlayer *player)
{
    IntrudeMemberRecord *offer;
    int zoneId;
    int offerIndex;
    MmdlGridVec playerGrid;

    if (INTRUDE_COMM_IsSessionAccepted(&work->session) != 1)
        goto fail;
    if (INTRUDE_COMM_IsSessionFinished(&work->session) != 0)
        goto fail;
    offer = INTRUDE_COMM_GetActiveSessionRequest(&work->session);
    if (offer == 0)
        goto fail;
    if (offer->head.kind != 4)
        goto fail;
    if (work->localPeer.intrudeId != offer->name.netId)
        goto fail;
    if (INTRUDE_COMM_GetJoinStatus(work, &work->session) != 0)
        goto fail;
    zoneId = GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(gameSystem));
    FLDMMDL_GetGridNowPos(FIELD_PLAYER_GetMmdl(player), &playerGrid);
    offerIndex = offer->head.param.x;
    if (zoneId != gIntrudeOfferZoneIds[offerIndex])
        goto fail;
    if (playerGrid.x != gIntrudeOfferTilePositions[offerIndex].x)
        goto fail;
    if (playerGrid.y != gIntrudeOfferTilePositions[offerIndex].y)
        goto fail;
    if (playerGrid.z != gIntrudeOfferTilePositions[offerIndex].z)
        goto fail;
    return EVENT_COMM_COMMON_CreateOfferEvent(gameSystem, work, offer);
fail:
    return 0;
}

IntrudeZonePos *INTRUDE_FIELD_FindZonePos(u32 zoneId)
{
    u32 i;

    for (i = 0; i < 218; i++) {
        if (INTRUDE_FIELD_gZonePositions[i].zoneId == zoneId)
            return &INTRUDE_FIELD_gZonePositions[i];
    }
    return 0;
}

int INTRUDE_FIELD_GetZoneAnchor(int zoneId, VecFx32 *out)
{
    IntrudeZonePos *entry;
    int x, y, z;

    if (ZONEDATA_IsEntralink(zoneId) != 1) {
        entry = INTRUDE_FIELD_FindZonePos(zoneId);
        if (entry == 0)
            return 0;
        z = entry->tileZ << 16;
        y = entry->tileY << 16;
        x = entry->tileX << 16;
        out->x = x;
        out->y = y;
        out->z = z;
    } else {
        *out = INTRUDE_FIELD_gHomeAnchorPos;
    }
    return 1;
}

void INTRUDE_FIELD_InitStartParam(IntrudeStartParam *param)
{
    MI_CpuFill8(param, 0, sizeof(IntrudeStartParam));
}

u8 INTRUDE_FIELD_GetStartKind(IntrudeStartParam *param)
{
    return param->startKind;
}

void INTRUDE_FIELD_AddMmdl(struct FieldMap *fieldMap, u16 gridX, u16 gridZ, int height, u16 objCode, u16 eventId, u16 objId)
{
    MmdlHeader header;
    MmdlGridPos *gridPos;
    MmdlSys *mmdlSys;
    int zoneId;

    mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    zoneId = FIELDMAP_GetZoneId(fieldMap);
    header = INTRUDE_FIELD_gMmdlHeaderTemplate;
    header.objId = objId;
    header.objCode = objCode;
    header.eventId = eventId;
    gridPos = (MmdlGridPos *)header.pos;
    gridPos->x = gridX;
    gridPos->z = gridZ;
    gridPos->y = height;
    FLDMMDL_AddMmdl(mmdlSys, &header, zoneId);
}

/*
 * lever: enum inner counter preserves the one-iteration loop; unsigned comparison;
 *   named column load fixes the Thumb add operands.
 */
void INTRUDE_FIELD_AddAreaMmdls(struct FieldMap *fieldMap)
{
    AreaMmdlIndex defIndex;
    int areaIndex;
    unsigned int gridX;

    areaIndex = 1;
    do {
        defIndex = AREA_MMDL_FIRST;
        do {
            gridX = INTRUDE_FIELD_gAreaMmdlDefs[defIndex].gridX;
            INTRUDE_FIELD_AddMmdl(fieldMap, gridX + (areaIndex << 6), INTRUDE_FIELD_gAreaMmdlDefs[defIndex].gridZ, 0x2001F, INTRUDE_FIELD_gAreaMmdlDefs[defIndex].objCode, INTRUDE_FIELD_gAreaMmdlDefs[defIndex].eventId, areaIndex + INTRUDE_FIELD_gAreaMmdlDefs[defIndex].objIdBase - 1);
            defIndex++;
        } while ((unsigned int)defIndex < 1);
        areaIndex++;
    } while (areaIndex < 3);
}

int INTRUDE_FIELD_IsDisconnectNeeded(struct GameSystem *gameSystem, int zoneId)
{
    struct GameData *gameData;
    struct GameComm *gameComm;
    IntrudeCommSys *work;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    work = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (GAME_DATA_GetIntrudeCount(gameData) == 0)
        return 0;
    if (work != 0)
        return 0;
    if (GAMESYSTEM_IsNetOffBySleep(gameSystem) == 1)
        return 1;
    if (ZONEDATA_IsEntralink(zoneId) == 1) {
        if (GAME_COMM_GetCounter(gameComm) != 0)
            return 1;
        return 0;
    }
    if (ZONEDATA_IsZoneGroup118To120(zoneId) == 1) {
        if (GAME_COMM_GetKind(gameComm) == 2 || (GAME_COMM_GetKind(gameComm) == 0 && GAME_COMM_GetLastKind(gameComm) == 2 && GAME_COMM_GetCounter(gameComm) != 0))
            return 1;
        return 0;
    }
    return 1;
}

int INTRUDE_FIELD_IsStartRequested(IntrudeCommSys *work)
{
    if (work->startFlag == 1 || INTRUDE_COMM_IsRequestFromSelf(work) == 1)
        return 1;
    return 0;
}

void INTRUDE_FIELD_SetSingleAreaMode(IntrudeCommSys *work)
{
    if (work != 0) {
        work->flagBit5 = 1;
    }
}

u8 INTRUDE_FIELD_GetHostGender(struct GameComm *gameComm)
{
    struct GameData *gameData;
    IntrudeCommSys *hostWork;
    struct MyStatus *status;

    gameData = GAME_COMM_GetGameData(gameComm);
    if (GAME_DATA_GetIntrudeCount(gameData) == 0) {
        status = GAME_DATA_GetMyStatus(gameData);
    } else if (GAME_DATA_GetIntrudeId(gameData) == GAME_DATA_GetOwnNetId(gameData)) {
        status = GAME_DATA_GetMyStatus(gameData);
    } else {
        hostWork = 0;
        if (GAME_COMM_GetKind(gameComm) == 2 && GAME_COMM_GetWork(gameComm) != 0)
            hostWork = GAME_COMM_GetWork(gameComm);
        if (hostWork == 0) {
            status = GAME_DATA_GetMyStatus(gameData);
        } else if (ZONEDATA_IsEntralink(hostWork->localPeer.zoneId) == 1) {
            status = GAME_DATA_GetMyStatus(gameData);
        } else {
            status = GAME_DATA_GetMyStatusPlayer(gameData, GAME_DATA_GetIntrudeId(gameData));
        }
    }
    return MYSTATUS_GetSex(status);
}

/*
 * lever: index declared before count preserves r3/r4 allocation.
 */
int INTRUDE_FIELD_IsListedZone(u32 zoneId)
{
    u32 i;
    u32 count;

    count = INTRUDE_FIELD_gListedZoneCount;
    for (i = 0; i < count; ++i) {
        if (zoneId == INTRUDE_FIELD_gListedZones[i])
            return 1;
    }
    return 0;
}

void INTRUDE_FIELD_AddMarkerMmdl(struct FieldMap *fieldMap, u16 gridX, u16 gridZ, int height)
{
    MmdlSys *mmdlSys;
    int zoneId;
    MmdlHeader header;
    MmdlGridPos *gridPos;

    mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    zoneId = FIELDMAP_GetZoneId(fieldMap);
    header = INTRUDE_FIELD_gMarkerMmdlHeader;
    gridPos = (MmdlGridPos *)header.pos;
    gridPos->x = gridX;
    gridPos->z = gridZ;
    gridPos->y = height;
    FLDMMDL_AddMmdl(mmdlSys, &header, zoneId);
}

/*
 * extent: two alignment bytes at 0x0217C1CE.
 */
void INTRUDE_FIELD_AddMarkerMmdls(struct FieldMap *fieldMap)
{
    int i;

    if (ZONEDATA_IsEntralink(FIELDMAP_GetZoneId(fieldMap)) != 0) {
        for (i = 0; i < 3; ++i)
            INTRUDE_FIELD_AddMarkerMmdl(fieldMap, (((i << 22) + 0x1f8000) >> 12) / 16, 29, 32);
    }
}

/*
 * lever: const pointer parameters, u16 argument homes and u16 c/result
 * preserve the original spill and field-load scheduling together.
 */
void INTRUDE_FIELD_AddSymbolMonMmdl(const SymbolSpawnContext *spawn, const SymbolMonEntry *entry, u16 objId, u16 gridX, u16 gridZ, int height)
{
    const IntrudeMmdlMoveParam *moveParam;
    MmdlSys *mmdlSys;
    u16 zoneId;
    MmdlHeader header;
    MmdlGridPos *gridPos;

    moveParam = &INTRUDE_FIELD_gSymbolMonMoveParams[entry->appearance];
    mmdlSys = FIELDMAP_GetMmdlSys(spawn->fieldMap);
    zoneId = FIELDMAP_GetZoneId(spawn->fieldMap);
    header = INTRUDE_FIELD_gSymbolMonMmdlHeader;
    header.objId = objId;
    header.objCode = TPOKE_DATA_GetRecordIndex(spawn->tpoke, (u16)entry->species, (u16)entry->sex, (u16)entry->form);
    header.moveCode = moveParam->moveCode;
    header.moveLimitX = moveParam->moveLimitX;
    header.moveLimitZ = moveParam->moveLimitZ;
    header.param0 = spawn->objIdBase + objId;
    header.param1 = *(const u32 *)entry;
    header.param2 = *(const u32 *)entry >> 16;
    gridPos = (MmdlGridPos *)header.pos;
    gridPos->x = gridX;
    gridPos->z = gridZ;
    gridPos->y = height;
    FLDMMDL_AddMmdl(mmdlSys, &header, zoneId);
}

void INTRUDE_FIELD_GetMmdlParamPair(u32 *out, Mmdl *mmdl)
{
    int low;

    low = FLDMMDL_GetParam(mmdl, 1);
    *out = low | (FLDMMDL_GetParam(mmdl, 2) << 16);
}

/*
 * Recursive MATCH unblocker: callee of SCRCMD_SYMBOL_SelectObjectEntry (ov010) +0026 and
 * SCRCMD_SYMBOL_MoveObjectEntryToPairedBand (ov010) +0032. Thumb tail-call thunk to 0x0216D63C; the
 * address is coherent Thumb only in ov018 (mid-instruction in ov019/ov176,
 * ARM in ov009), so the ov018 shard makes both sites attest as `matched`.
 */
int INTRUDE_FIELD_GetMmdlParam0(Mmdl *mmdl)
{
    return FLDMMDL_GetParam(mmdl, 0);
}

/*
 * The const on the entry pointer is what lets the bitfield loads be
 * scheduled above the outgoing stack-argument stores (48 bytes otherwise).
 */
void *INTRUDE_FIELD_CreateSymbolMon(int heapId, struct GameData *gameData, const SymbolMonEntry *entry)
{
    u8 *levelTable;
    u8 level;
    u32 trainerId;
    u32 personality;
    void *mon;

    levelTable = ARC_UTIL_LoadMember(0xE3, 0, 0, heapId);
    level = levelTable[entry->species];
    GFL_HEAP_Free(levelTable);
    trainerId = MYSTATUS_GetId(GAME_DATA_GetMyStatus(gameData));
    personality = POKE_TOOL_CreatePersonalRnd(trainerId, (u16)entry->species, (u16)entry->form, entry->sex, 0, 0);
    mon = POKE_TOOL_Create(entry->species, level, -1, heapId);
    POKE_TOOL_SetupPartyParamEx(mon, entry->species, level, trainerId, -1, personality);
    POKE_TOOL_SetAbility(mon, entry->species, entry->form);
    POKE_TOOL_ChangeForm(mon, (u16)entry->form);
    if (entry->move != 0) {
        if (POKE_TOOL_AddMove(mon, entry->move) == 0xFFFF)
            POKE_TOOL_PushMove(mon, (u16)entry->move);
    }
    return mon;
}

void INTRUDE_FIELD_SpawnSymbolMons(struct FieldMap *fieldMap, int objIdBase, SymbolMonEntry *entries, int unused, int cellKind)
{
    const u8 (*offsets)[2];
    SymbolSpawnContext spawn;
    Mmdl *playerMmdl;
    u16 playerGridX;
    u16 playerGridZ;
    int i;
    int jitterX;
    int jitterZ;
    int x;
    int z;

    if (SYMBOL_MAP_IsHomeCell(cellKind))
        offsets = INTRUDE_FIELD_gSymbolMonOffsetsHome;
    else if (SYMBOL_MAP_IsPlainCell(cellKind))
        offsets = INTRUDE_FIELD_gSymbolMonOffsetsPlain;
    else
        offsets = INTRUDE_FIELD_gSymbolMonOffsetsOther;

    spawn.tpoke = (struct Container *)TPOKE_DATA_Create(FIELDMAP_GetHeapId(fieldMap));
    spawn.fieldMap = fieldMap;
    spawn.objIdBase = objIdBase;
    playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap));
    playerGridX = FLDMMDL_GetGridNowX(playerMmdl);
    playerGridZ = FLDMMDL_GetGridNowZ(playerMmdl);

    for (i = 0; i < 20; i++) {
        if (entries[i].species != 0) {
            jitterX = GFL_USE_GetRandomBelow(2) - 1;
            jitterZ = GFL_USE_GetRandomBelow(2) - 1;
            x = jitterX + offsets[i][0];
            z = jitterZ + offsets[i][1];
            if (playerGridX == x && playerGridZ == z) {
                if (jitterX != 0)
                    x -= jitterX;
                else if (jitterZ != 0)
                    z -= jitterZ;
                else
                    x++;
            }
            INTRUDE_FIELD_AddSymbolMonMmdl(&spawn, &entries[i], i, x, z, 0);
        }
    }
    TPOKE_Delete((struct Tpoke *)spawn.tpoke);
}

struct GameEvent *INTRUDE_FIELD_CreateOfferInfoEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *work, u16 senderNetId)
{
    IntrudeMemberRecord *offer;
    OfferEventWork *eventWork;
    struct GameEvent *event;

    offer = INTRUDE_COMM_GetActiveSessionRequest(&work->session);
    GAMESYSTEM_GetGameData(gameSystem);
    event = GAME_EVENT_Create(gameSystem, 0, INTRUDE_FIELD_EventOfferInfo, sizeof(OfferEventWork));
    eventWork = GAME_EVENT_GetWork(event);
    MI_CpuFill8(eventWork, 0, sizeof(OfferEventWork));
    eventWork->senderNetId = senderNetId;
    eventWork->fieldMap = fieldMap;
    eventWork->record = *offer;
    eventWork->showInfo = 1;
    EVENT_COMM_COMMON_InitMsgBox((struct EventCommMsgBox *)eventWork->infoWindow, gameSystem);
    INTRUDE_COMM_SetState(work, 5);
    return event;
}

/*
 * Task callback registered by INTRUDE_FIELD_CreateOfferInfoEvent (0x88-byte work, state word
 * in the second argument).
 */
int INTRUDE_FIELD_EventOfferInfo(struct GameEvent *event, int *seq, void *workPtr)
{
    OfferEventWork *work = workPtr;
    struct GameSystem *gameSystem;
    IntrudeCommSys *intrudeWork;
    u16 pointIndex;
    u8 ownId;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    intrudeWork = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
    if (intrudeWork == 0 && *seq == 0)
        *seq = 8;

    switch (*seq) {
    case 0:
        if (work->showInfo == 0) {
            *seq = 4;
            break;
        }
        EVENT_COMM_COMMON_SetupListWindowB((struct EventCommMsgBox *)work->infoWindow, gameSystem, 1, 1, 0x1E, 0x10);
        INTRUDE_COMM_SetWordSetRequest( (const struct IntrudeRequestHead *)&work->record, &work->record.name, *(struct WordSet **)work->infoWindow, work->senderNetId);
        pointIndex = work->record.head.pointIndex;
        EVENT_COMM_COMMON_PrintListWindowB((struct EventCommMsgBox *)work->infoWindow, (u16)work->record.head.kind, 8, 0);
        EVENT_COMM_COMMON_PrintListWindowB((struct EventCommMsgBox *)work->infoWindow, (u16)pointIndex, 8, 0x10);
        (*seq)++;
        break;
    case 1:
        GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPushAndPlayTask(gameSystem, 0x52B));
        (*seq)++;
        break;
    case 2:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GAME_EVENT_CallEvent(event, FIELD_SOUND_SYSTEM_StartPopAndWaitTask(gameSystem, 0, 6));
            (*seq)++;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_DeleteListWindowB((struct EventCommMsgBox *)work->infoWindow);
        (*seq)++;
        break;
    case 4:
        ownId = (int)GAME_DATA_GetOwnNetId(GAMESYSTEM_GetGameData(gameSystem));
        INTRUDE_FIELD_InitPlayerSpin(&work->spin, gameSystem, work->fieldMap, work->record.head.ids[ownId], work->record.head.grades[ownId], ((IntrudeNetIdMask *)&work->record.head.reserved08)->netIds & (1 << ownId));
        (*seq)++;
        break;
    case 5:
        if (INTRUDE_FIELD_StepPlayerSpin(&work->spin, intrudeWork) == 1)
            (*seq)++;
        break;
    case 6:
        if (intrudeWork != 0) {
            if (INTRUDE_CMD_SendRecordAccept((sptr)intrudeWork, &intrudeWork->session) == 1)
                (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 7:
        if (intrudeWork != 0) {
            if (INTRUDE_COMM_IsSessionTimeLimitSet(&intrudeWork->session) == 1)
                (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 8:
        EVENT_COMM_COMMON_ExitMsgBox((struct EventCommMsgBox *)work->infoWindow);
        if (intrudeWork != 0)
            INTRUDE_COMM_SetState(intrudeWork, 0);
        return 1;
    }
    return 0;
}

/*
 * extent: two alignment bytes at 0x0217C686.
 */
void INTRUDE_FIELD_InitPlayerSpin(PlayerSpinWork *spin, struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 objCode, u8 kind, u8 flag)
{
    MI_CpuFill8(spin, 0, sizeof(PlayerSpinWork));
    spin->gameSystem = gameSystem;
    spin->fieldMap = fieldMap;
    spin->objCode = objCode;
    spin->kind = kind;
    spin->flag = flag;
    spin->stepFrames = 15;
    spin->shownStep = spin->stepFrames;
}

/*
 * Per-frame step of the 0x18-byte record INTRUDE_FIELD_InitPlayerSpin initialises.
 */
int INTRUDE_FIELD_StepPlayerSpin(PlayerSpinWork *spin, IntrudeCommSys *work)
{
    Mmdl *playerMmdl;
    s16 frames;

    switch (spin->state) {
    case 0:
        spin->stepFrames = 15;
        spin->shownStep = spin->stepFrames;
        GFL_USE_PlaySeDefaultVolume(0x738);
        spin->state++;
        break;
    case 1:
        if (FIELDMAP_IsReady(spin->fieldMap) == 1) {
            playerMmdl = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(spin->fieldMap));
            if (FLDMMDL_CheckPossibleAcmd(playerMmdl) == 1) {
                if (spin->stepFrames >= 15 && spin->switched != 0 && INTRUDE_FIELD_gSpinAcmds[spin->dirIndex] == 1) {
                    spin->state++;
                    break;
                }
                spin->dirIndex = (spin->dirIndex + 1) & 3;
                frames = spin->stepFrames;
                spin->shownStep = frames;
                if (spin->switched == 0) {
                    spin->stepFrames--;
                    if (spin->stepFrames <= 1) {
                        GAMESYSTEM_GetGameData(spin->gameSystem);
                        INTRUDE_FIELD_ChangePlayerLook(work, spin->gameSystem, spin->objCode, spin->kind, spin->flag);
                        spin->switched++;
                    }
                } else if (frames < 15) {
                    spin->stepFrames++;
                }
                FLDMMDL_SetAcmd(playerMmdl, INTRUDE_FIELD_gSpinAcmds[spin->dirIndex]);
            }
        }
        break;
    default:
        return 1;
    }
    return 0;
}
