/*
 * file:     field_event_check.c
 * unit:     yes
 * function: FIELDMAP_GetHeapSizeForMapType, FIELD_EVENT_CHECK_CheckGridEvents, FIELD_EVENT_CHECK_RunGrid, FIELD_EVENT_CHECK_CheckCommEvents, FIELD_EVENT_CHECK_RunRail, FIELD_EVENT_CHECK_CheckRailEvents, FIELD_EVENT_CHECK_Run, FIELD_EVENT_CHECK_InitInput, FIELD_EVENT_CHECK_StopSoundAfterEvent, FIELD_EVENT_CHECK_AddStepRecord, FIELD_EVENT_CHECK_StartPendingScript, FIELD_EVENT_CHECK_CheckPosEventAtPlayer, FIELD_EVENT_CHECK_CheckPosEventForDir, FIELD_EVENT_CHECK_CheckPosEventFacing, FIELD_EVENT_CHECK_CheckPosEventHeldDir, FIELD_EVENT_CHECK_CheckIntrudeEdge, FIELD_EVENT_CHECK_CheckPosEventCenterTile, FIELD_EVENT_CHECK_CheckStepEvents, FIELD_EVENT_CHECK_GetEggCycleDecrement, FIELD_EVENT_CHECK_DecrementEggCycles, FIELD_EVENT_CHECK_UpdateEggStepCounter, FIELD_EVENT_CHECK_IsEggReadyToHatch, FIELD_EVENT_CHECK_CheckEggHatch, FIELD_EVENT_CHECK_UpdateWalkFriendship, FIELD_EVENT_CHECK_CheckZoneStepMessage, FIELD_EVENT_CHECK_CheckSaveFlagMessage, FIELD_EVENT_CHECK_CheckStepEncount, FIELD_EVENT_CHECK_CreateGPowerExpireEvent, FIELD_EVENT_CHECK_CheckGridConnect, FIELD_EVENT_CHECK_CheckTileMoveTask, FIELD_EVENT_CHECK_StartConnectEvent, FIELD_EVENT_CHECK_SetEntranceFromGridConnect, FIELD_EVENT_CHECK_FindGridConnectId, FIELD_EVENT_CHECK_GetFrontPos, FIELD_EVENT_CHECK_IsConnectOnFootType, FIELD_EVENT_CHECK_IsConnectExitDir, FIELD_EVENT_CHECK_CheckGridConnectFront, FIELD_EVENT_CHECK_CheckFrontTileEvents, FIELD_EVENT_CHECK_CheckRailConnect, FIELD_EVENT_CHECK_CheckRailConnectFront, FIELD_EVENT_CHECK_CheckWildEncount, FIELD_EVENT_CHECK_CheckRailSignBoard, FIELD_EVENT_CHECK_SetEntranceFromRailConnect, FIELD_EVENT_CHECK_StartRailConnectEvent, FIELD_EVENT_CHECK_IsRailFrontFree, FIELD_EVENT_CHECK_LedgeJumpTaskMain, FIELD_EVENT_CHECK_CreateLedgeJumpTask, FIELD_EVENT_CHECK_CheckLedgeJump, FIELD_EVENT_CHECK_SearchGridFrontMmdl, FIELD_EVENT_CHECK_SearchRailFrontMmdl, FIELD_EVENT_CHECK_GetFrontTileMessage, FIELD_EVENT_CHECK_FindPartyMemberWithMove, FIELD_EVENT_CHECK_CountAlivePartyMembers, FIELD_EVENT_CHECK_IsLedgePathClear
 * address:  0x02189BBC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from field_msgbg.c: event checks run each frame by fieldmap.c (talk, background, position and step events, input). No __FILE__ anchor; file name is a guess. TU boundary before 0x02189BBC is proven (tuboundary).
 *
 * symbols:
 *   FIELDMAP_GetMapType  0x02189B28  thumb  ov021
 *   gMapTypeCtrlTable     0x021D373C  data  a4
 *   GAME_DATA_GetEventState  0x02012ED0  thumb
 *   PLEASURE_BOAT_Update  0x021C868C  thumb
 *   EVENT_TRAINER_EYE_Check  0x021AE0CC  thumb
 *   func_0201296C  0x0201296C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   FIELD_PLAYER_TryPushBoulder  0x021A2F20  thumb
 *   func_02012138  0x02012138  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   INTRUDE_FIELD_IsCommAllowed  0x0217BFD8  thumb  ov018
 *   INTRUDE_SUBDISP_CreateDisconnectEvent  0x0217CA84  thumb  ov018
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   func_02012B70  0x02012B70  thumb
 *   INTRUDE_FIELD_IsStartRequested  0x0217C070  thumb  ov018
 *   INTRUDE_FIELD_CreateNoticeEvent  0x0217B810  thumb  ov018
 *   INTRUDE_COMM_ConsumeAreaNoticeSeen  0x0217689C  thumb  ov011
 *   GAME_DATA_GetSymbolMapFlag  0x02012FB0  thumb
 *   FIELD_INTRUDE_EVENT_StartSymbolEntry  0x0216B3A8  thumb  ov010
 *   INTRUDE_COMM_GetActiveRequestTarget  0x021754B4  thumb  ov011
 *   FIELD_PLAYER_ResetMoveWork  0x021A2F6C  thumb
 *   EVENT_COMM_COMMON_CreateTalkedStartEvent  0x0217FC6C  thumb  ov018
 *   INTRUDE_FIELD_TryStartOfferEvent  0x0217BDE0  thumb  ov018
 *   INTRUDE_FIELD_FindRemotePlayerAhead  0x0217AFC4  thumb  ov018
 *   EVENT_COMM_COMMON_CreateTalkStartEvent  0x0217FB5C  thumb  ov018
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_GetEventId  0x0216D5B8  thumb  ov010
 *   SCRIPT_SYS_IsZoneScriptId  0x02158D90  thumb  ov010
 *   func_0219F01C  0x0219F01C  thumb
 *   EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk  0x02162A54  thumb  ov010
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb
 *   INTRUDE_FindOfferSlotAt  0x021CFAC0  thumb
 *   INTRUDE_StartOfferEvent  0x021CFC14  thumb
 *   FIELD_GetPlayerAreaZoneId  0x021CD440  thumb
 *   ZONEDATA_IsZoneInTableDFB8  0x02013FFC  thumb
 *   EVENTDATA_SYSTEM_GetAutoPosEventScriptId  0x02162940  thumb  ov010
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb
 *   EVENT_SHORTCUT_MENU_HasShortcuts  0x0215FF34  thumb  ov010
 *   FIELD_SUBSCREEN_IsIdle  0x021A0ED4  thumb
 *   EVENT_SHORTCUT_MENU_Create  0x0215FF54  thumb  ov010
 *   func_0201212C  0x0201212C  thumb
 *   EVENT_COMM_ERROR_Create  0x021C06CC  thumb
 *   FIELD_SUBSCREEN_GetMode  0x021A0F90  thumb
 *   SCRCMD_NETWORK_CreateBattleRecordLinkEvent  0x0215FC40  thumb  ov010
 *   FIELD_SUBSCREEN_CheckModeRequest  0x021A0EB0  thumb
 *   INTRUDE_FIELD_CreateTileEvent  0x0217B410  thumb  ov018
 *   func_0201210C  0x0201210C  thumb
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_UpdateOccupiedSpot  0x021AA8F8  thumb  ov021
 *   EFFECT_ENCOUNT_Reset  0x021AA8EC  thumb  ov021
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_Cancel  0x021BC5BC  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_SetGridMoveFlag  0x021A3550  thumb  ov021
 *   FIELD_PLAYER_ResetGridMove  0x021A356C  thumb  ov021
 *   FIELDMAP_GetZoneEffectWork  0x02189A70  thumb  ov021
 *   FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume  0x021F3B10  thumb  ov053
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   EVENT_MAPCHANGE_CreateSpecialLocationEvent  0x021850FC  thumb  ov020
 *   UNION_MAIN_GetFieldRequest  0x0217391C  thumb  ov012
 *   UNION_MAIN_IsExitStarted  0x02173928  thumb  ov012
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   UNION_ONESELF_TryStartSubEvent  0x0217B80C  thumb  ov019
 *   UNION_ONESELF_GetFieldTalkEvent  0x0217B83C  thumb  ov019
 *   UNION_MAIN_IsIdle  0x0217394C  thumb  ov012
 *   FLDMMDL_GetObjId  0x0216D588  thumb  ov010
 *   UNION_CHARA_IsUnionObjId  0x0217AF38  thumb  ov019
 *   SCRCMD_NETWORK_CreateBattleRecordLinkEventForZone  0x0215FCE0  thumb  ov010
 *   FLDMMDL_RAIL_GetFrontLocation  0x0219E634  thumb  ov021
 *   FLDMMDL_RAIL_GetNextLocation  0x0219E2F4  thumb  ov021
 *   EVENTDATA_SYSTEM_GetRailPosEventScriptId  0x02162958  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden  0x02162A5C  thumb  ov010
 *   FIELDMAP_GetMoveKind  0x02188CFC  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012844  0x02012844  thumb
 *   FIELD_PLAYER_UpdateStepPhase  0x021A2FE4  thumb
 *   FIELD_PLAYER_GetStepKind  0x021A3080  thumb
 *   FIELD_PLAYER_GetStepPhase  0x021A308C  thumb
 *   FLDMMDL_GetPosPtr  0x0216D888  thumb  ov010
 *   func_02012B38  0x02012B38  thumb
 *   FIELD_STATUS_GetProcAction  0x02014478  thumb
 *   FIELD_PLAYER_GetNowAttribute  0x021A30C8  thumb
 *   FIELD_PLAYER_GetGridMoveState  0x021A3584  thumb
 *   FIELD_SUBSCREEN_GetCGear  0x021A1358  thumb  ov021
 *   func_02012A30  0x02012A30  thumb
 *   func_02028A70  0x02028A70  thumb
 *   C_GEAR_IsLastCommandKind5  0x021F2AB8  thumb  ov029
 *   C_GEAR_StopRingtone  0x021F2AD4  thumb  ov029
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   FIELD_STATUS_SetProcAction  0x02014474  thumb
 *   SCRIPT_SYS_CreateSceneChangeEvent  0x02158B00  thumb  ov010
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb
 *   MAP_ATTR_GetAt  0x021AB0D4  thumb
 *   MAP_ATTR_GetTerrainId  0x021AB0F0  thumb
 *   MAP_ATTR_IsNoInteract  0x021AB188  thumb
 *   EVENTDATA_SYSTEM_GetPosEventScriptId  0x02162928  thumb  ov010
 *   FIELD_PLAYER_ChooseMoveDirFromKeys  0x021A2FA4  thumb
 *   INTRUDE_FIELD_CreateEdgeTask  0x0217B4D8  thumb ov018
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight  0x0216282C  thumb  ov010
 *   FIELD_PLAYER_GetFormCode  0x021A3098  thumb
 *   FLDMMDL_GetAcmdCode  0x0216D7C4  thumb  ov010
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb
 *   func_02008970  0x02008970  thumb
 *   func_0200896C  0x0200896C  thumb
 *   func_02012934  0x02012934  thumb
 *   FIELDMAP_GetSodateya  0x02188D50  thumb
 *   SODATEYA_AddStep  0x021C3378  thumb
 *   func_02008978  0x02008978  thumb
 *   func_02008980  0x02008980  thumb
 *   func_02008854  0x02008854  thumb
 *   SCRCMD_ShowStepMilestoneMessage  0x021D220C  thumb
 *   func_02008990  0x02008990  thumb
 *   func_02008988  0x02008988  thumb
 *   MOVE_POKEMON_SAVE_TickCooldown  0x0200D564  thumb
 *   EFFECT_ENCOUNT_TriggerSpot  0x021AA944  thumb
 *   EFFECT_ENCOUNT_OnPlayerStep  0x021AA80C  thumb
 *   GPOWER_GetExpiringPowerId  0x02010F18  thumb
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   abs_id_83      0x00000053  data
 *   GPOWER_EVENT_CreateTimeoutScriptEvent  0x021F532C  thumb  ov083
 *   EVENTDATA_SYSTEM_GetConnectData  0x021625CC  thumb  ov010
 *   EVENTDATA_SYSTEM_IsConnectDisabled  0x021626EC  thumb  ov010
 *   FIELD_TILE_MOVE_IsSpinTile  0x021C8A74  thumb
 *   FIELD_TILE_MOVE_StartSpinTask  0x021C8A30  thumb
 *   FIELD_TILE_MOVE_IsSlideTile  0x021C8CF0  thumb
 *   FIELD_TILE_MOVE_StartSlideTask  0x021C8C88  thumb
 *   EVENTDATA_SYSTEM_GetConnectGridExitOffset  0x021626A8  thumb  ov010
 *   EVENTDATA_SYSTEM_GetConnectExitType  0x021626E8  thumb  ov010
 *   EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate  0x02185410  thumb  ov020
 *   EVENT_MAPCHANGE_CreateExitWarpEvent  0x02185360  thumb  ov020
 *   ZONEDATA_SetExitLocation  0x02014110  thumb
 *   func_02012878  0x02012878  thumb
 *   EVENTDATA_SYSTEM_SearchConnectIdByGridPos  0x02162564  thumb  ov010
 *   EVENTDATA_SYSTEM_IsConnectExitDir  0x021626B8  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 *   FIELD_GIMMICK_IsGimmickId  0x021BE288  thumb  ov021
 *   FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent  0x021F3A88  thumb  ov038
 *   FIELD_GIMMICK_D06_CheckPushStone  0x021F38A4  thumb  ov051
 *   MAP_ATTR_IsWaterfall  0x021AB310  thumb  ov021
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FIELD_GIMMICK_CART_LANES_CheckRideEvent  0x021F404C  thumb  ov039
 *   FIELD_GIMMICK_CANNONS_CreateLaunchEvent  0x021F37E0  thumb  ov041
 *   EVENTDATA_SYSTEM_SearchConnectIdByRailLocation  0x02162598  thumb  ov010
 *   ZONEDATA_IsZoneInTableDFC0  0x02013DD0  thumb
 *   FIELD_ENCOUNT_CheckWfbcEncount  0x021AA248  thumb
 *   FIELD_ENCOUNT_CheckWildEncount  0x021A9F40  thumb
 *   RAIL_ATTR_IsSignBoard  0x021BB188  thumb
 *   FLDMMDL_RAIL_GetHitBitsDirNoAttr  0x0219E418  thumb
 *   RAIL_SLIPDOWN_StartAtPlayer  0x021C46F8  thumb
 *   ZONEDATA_SetExitRailLocation  0x02014134  thumb
 *   EVENTDATA_SYSTEM_GetConnectRailExitOffset  0x021626B0  thumb  ov010
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb
 *   FLDEFF_NAMIPOKE_SetFollowMode  0x021ACBB8  thumb
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb
 *   FIELD_PLAYER_FinishFormChange  0x021A2F60  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FIELD_PLAYER_ChangeToNormalForm  0x021A2FD0  thumb
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FIELD_PLAYER_SetGridMoveState  0x021A35A0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   FIELD_PLAYER_GetPosInDir  0x021A3364  thumb
 *   MAP_ATTR_IsLongHopEdge  0x021AB2E8  thumb
 *   FIELD_PLAYER_GetFrontGridPos  0x021A3460  thumb
 *   FLDMMDL_MOVE_GridToVector  0x02164294  thumb  ov010
 *   MAP_ATTR_IsCameraStep  0x021AB194  thumb
 *   FLDMMDL_MOVE_AddDirGrid  0x02164240  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 *   FLDMMDL_SysSearchGridPosHeight  0x0216DDDC  thumb  ov010
 *   FLDMMDL_RAIL_SearchMmdlByLocation  0x0219E570  thumb  ov021
 *   FIELD_PLAYER_GetFrontAttribute  0x021A3128  thumb
 *   ZONEDATA_IsNormalFieldZone  0x02013E04  thumb
 *   FIELD_PLAYER_CheckEncountAttr  0x021A3504  thumb
 *   FIELD_PLAYER_CheckSurfEntryAttr  0x021A3524  thumb
 *   data_021D3CE8  0x021D3CE8  data
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 *   MI_CpuFill8  0x02082BCC  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   KEY_GetCont  0x0203630C  arm
 *   FIELD_G3D_MAPPER_GetWfbc  0x0218DC70  thumb  ov021
 *   GPOWER_ApplyHatchRate  0x02010FF4  thumb  arm9
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb  arm9
 *   NATSUKI_CalcWalk  0x0201B7EC  thumb  arm9
 *   MOVE_POKEMON_SAVE_GetBlock  0x0200D418  thumb  arm9
 */
#include "fieldmap_types.h"
#include "fldmmdl_rail_types.h"

typedef unsigned int u32;
typedef signed int s32;

struct GameEvent;
struct EventDataSystem;

/*
 * The per-frame field input record (0x40 bytes), built on the stack by
 * FIELD_EVENT_CHECK_InitInput and read by every check of this file.
 */
typedef struct FieldEventInput {
    u16 heapId;                 /*
0x00: field heap id of the field map
 */
    u16 heapIdPad;              /*
0x02
 */
    void *gameSystem;           /*
0x04
 */
    void *gameData;             /*
0x08
 */
    void *eventData;            /*
0x0C: map event data (EventDataSystem)
 */
    u16 zoneId;                 /*
0x10
 */
    u16 zoneIdPad;              /*
0x12
 */
    FieldMap *fieldMap;         /*
0x14
 */
    void *player;               /*
0x18: field player
 */
    u32 moveState;              /*
0x1C: player move state, 3 = step finished
 */
    u32 moveMode;               /*
0x20: player move mode (1 walk, 2 other)
 */
    u16 facingDir;              /*
0x24: dir of the player model
 */
    u16 pendingScriptId;        /*
0x26: script id queued by a proc action
 */
    u32 keyTrg;                 /*
0x28: pad trigger
 */
    u32 keyCont;                /*
0x2C: pad held
 */
    u16 heldDir;                /*
0x30: direction of the held d-pad, 9 none
 */
    u16 heldDirPad;             /*
0x32
 */
    VecFx32 *playerPos;         /*
0x34: position of the player model
 */
    u32 tileAttr;               /*
0x38: tile attribute under the player
 */
    u32 aPressed : 1;           /*
0x3C bit 0: A pressed, talk
 */
    u32 xPressed : 1;           /*
bit 1: X pressed, menu
 */
    u32 walkStepDone : 1;       /*
bit 2: step finished while walking
 */
    u32 stepDone : 1;           /*
bit 3: step finished
 */
    u32 otherMoveBusy : 1;      /*
bit 4: unfinished move of mode 2
 */
    u32 pushingFacing : 1;      /*
bit 5: held d-pad matches the facing
 */
    u32 yPressed : 1;           /*
bit 6: Y pressed, registered item
 */
    u32 noButton : 1;           /*
bit 7: no button pressed
 */
    u32 padBit8 : 1;            /*
bit 8: never set
 */
    u32 tileChanged : 1;        /*
bit 9: player entered a new tile
 */
    u32 inputEnabled : 1;       /*
bit 10: move state allows input
 */
} FieldEventInput;

/*
Position event record (PosEventData, 0x16 bytes, eventdata_system.c).
 */
typedef struct PosEvent {
    u16 scriptId;               /*
0x00
 */
    u16 workValue;              /*
0x02
 */
    u16 workId;                 /*
0x04
 */
    u16 checkType;              /*
0x06
 */
    u16 posType;                /*
0x08: 0 grid area
 */
    struct {
        u16 x;
        u16 z;
        u16 width;
        u16 height;
    } area;                     /*
0x0A
 */
} PosEvent;

/*
Work of the ledge jump task (0x10 bytes).
 */
typedef struct LedgeJumpWork {
    int reserved;               /*
0x00
 */
    u16 dir;                    /*
0x04
 */
    u16 jumpTwoTiles;           /*
0x06
 */
    void *gameSystem;           /*
0x08
 */
    FieldMap *fieldMap;         /*
0x0C
 */
} LedgeJumpWork;

/*
Message shown for the tile the player faces (table at data_021D3CE8).
 */
struct TileMessage {
    int (*test)(u16 attr);
    u16 dir;
    u16 scriptId;
};

extern u32 *GAME_DATA_GetEventState(void *p);
extern int PLEASURE_BOAT_Update(int a, char *b);
extern int EVENT_TRAINER_EYE_Check(int a);
extern u32 func_0201296C(const void *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern int FIELD_PLAYER_TryPushBoulder(u32 *p, int a, int b, int c);
extern u32 func_02012138(const void *p);
extern int INTRUDE_COMM_GetWorkIfRunning(int a0);
extern void *FIELD_PLAYER_GetMmdl(u8 *);
extern int INTRUDE_FIELD_IsCommAllowed(const void *a, int b);
extern int INTRUDE_SUBDISP_CreateDisconnectEvent(void *sys, int v);
extern u32 GAME_COMM_GetKind(void *obj);
extern int func_02012B70(const void *p);
extern int INTRUDE_FIELD_IsStartRequested(u8 *p);
extern void *INTRUDE_FIELD_CreateNoticeEvent(void *a, FieldMap *fieldMap);
extern int INTRUDE_COMM_ConsumeAreaNoticeSeen(u8 *ctx, int arg);
extern int GAME_DATA_GetSymbolMapFlag(unsigned char *base);
extern struct GameEvent *FIELD_INTRUDE_EVENT_StartSymbolEntry(int a0, int a1, int a2);
extern int INTRUDE_COMM_GetActiveRequestTarget(u8 *p, int *out);
extern void FIELD_PLAYER_ResetMoveWork(u32 *p);
extern void *EVENT_COMM_COMMON_CreateTalkedStartEvent(void *p, int a, int b, int c, int d, u16 e);
extern int INTRUDE_FIELD_TryStartOfferEvent(int a, u8 *b, void *player);
extern int INTRUDE_FIELD_FindRemotePlayerAhead(int *a, u8 *b, int *out);
extern void *EVENT_COMM_COMMON_CreateTalkStartEvent(void *owner, int b, int unused, int d, int e, u16 f);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern void FIELD_PLAYER_GetPos(u8 *, VecFx32 *);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern u32 FLDMMDL_GetEventId(void *p);
extern int SCRIPT_SYS_IsZoneScriptId(u16 v);
extern int func_0219F01C(u32 a, u32 b, u32 c, u32 e0, u32 e1, u16 id);
extern u32 EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk(void *p, void *q, int *pos, u32 d);
extern struct GameEvent *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
extern void *GAME_DATA_GetSaveControl(void *p);
extern u16 *func_0200BE48(void *sys);
extern u16 FIELDMAP_GetZoneId(FieldMap *fieldMap);
extern int INTRUDE_FindOfferSlotAt(u8 *base, int a, int b, int c, int d);
extern void *INTRUDE_StartOfferEvent(void *a, u16 heapId, void *c);
extern int FIELD_GetPlayerAreaZoneId(void *a, u16 *out);
extern u32 ZONEDATA_IsZoneInTableDFB8(u32 id);
extern u16 EVENTDATA_SYSTEM_GetAutoPosEventScriptId(void *p, void *q, int key);
extern u32 WIPE_SYS_EndCheck(void);
extern u32 FIELDMAP_GetSubscreen(FieldMap *fieldMap);
extern int EVENT_SHORTCUT_MENU_HasShortcuts(void *sys);
extern int FIELD_SUBSCREEN_IsIdle(u32 a);
extern struct GameEvent *EVENT_SHORTCUT_MENU_Create(int a0, int a1, u16 a2);
extern u8 func_0201212C(const void *p);
extern int EVENT_COMM_ERROR_Create(void *sys, FieldMap *fieldMap);
extern u32 FIELD_SUBSCREEN_GetMode(u8 *p);
extern struct GameEvent *SCRCMD_NETWORK_CreateBattleRecordLinkEvent(int a0, int a1, u16 a2);
extern int FIELD_SUBSCREEN_CheckModeRequest(u32 *p, u32 a);
extern int INTRUDE_FIELD_CreateTileEvent(int a0, int a1, void *player);
extern void *func_0201210C(const void *p);
extern u32 FIELDMAP_GetEncount(FieldMap *fieldMap);
extern void EFFECT_ENCOUNT_UpdateOccupiedSpot(void);
extern void EFFECT_ENCOUNT_Reset(u8 *p);
extern u32 FIELDMAP_GetPlaceName(FieldMap *fieldMap);
extern int FIELD_PLACE_NAME_Cancel(u8 *a);
extern void *FIELDMAP_GetFieldPlayer(FieldMap *fieldMap);
extern void FIELD_PLAYER_SetGridMoveFlag(u32 *p, int a);
extern void FIELD_PLAYER_ResetGridMove(void **p);
extern u32 FIELDMAP_GetZoneEffectWork(FieldMap *fieldMap);
extern void FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume(void);
extern u32 GAME_COMM_GetWork(void *obj);
extern u32 func_0200FB24(void);
extern void *EVENT_MAPCHANGE_CreateSpecialLocationEvent(void *p, FieldMap *fieldMap);
extern int UNION_MAIN_GetFieldRequest(u8 *p);
extern int UNION_MAIN_IsExitStarted(u8 *p);
extern void GAME_COMM_RequestExitNoCallback(void *p);
extern int UNION_ONESELF_TryStartSubEvent(int a, int b);
extern int UNION_ONESELF_GetFieldTalkEvent(void *sys, void *pos);
extern int UNION_MAIN_IsIdle(const void *p);
extern u16 FLDMMDL_GetObjId(void *p);
extern int UNION_CHARA_IsUnionObjId(u16 a);
extern int SCRCMD_NETWORK_CreateBattleRecordLinkEventForZone(int a, int b, unsigned short c);
extern int FLDMMDL_RAIL_GetFrontLocation(void *, RailLocation *);
extern void FLDMMDL_RAIL_GetNextLocation(void *o, RailLocation *out);
extern u16 EVENTDATA_SYSTEM_GetRailPosEventScriptId(void *c, void *a, RailLocation *key);
extern u16 FLDMMDL_GetDirDisp(void *obj);
extern u16 EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden(void *set, void *flags, const RailLocation *where, u16 type);
extern u32 FIELDMAP_GetMoveKind(FieldMap *fieldMap);
extern u32 MI_CpuFill8(void *, int, u32);
extern u16 FIELDMAP_GetHeapId(FieldMap *fieldMap);
extern void *func_020120F4(const void *p);
extern u32 func_02012844(const void *p);
extern u32 KEY_GetTrg(void);
extern unsigned int KEY_GetCont(void);
extern void FIELD_PLAYER_UpdateStepPhase(u32 *p);
extern u32 FIELD_PLAYER_GetStepKind(u8 *p);
extern u32 FIELD_PLAYER_GetStepPhase(u8 *p);
extern void *FLDMMDL_GetPosPtr(void *p);
extern void *func_02012B38(const void *p);
extern u16 FIELD_STATUS_GetProcAction(void *o);
extern u32 FIELD_PLAYER_GetNowAttribute(void **ctx);
extern int FIELD_PLAYER_GetGridMoveState(void *v);
extern u32 FIELD_SUBSCREEN_GetCGear(u32 *p);
extern u32 func_02012A30(const void *p);
extern void func_02028A70(void *sys);
extern int C_GEAR_IsLastCommandKind5(char *p);
extern void C_GEAR_StopRingtone(u8 *p);
extern u32 func_02008DF0(void *obj, int i);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern void FIELD_STATUS_SetProcAction(void *o, u16 v);
extern void *SCRIPT_SYS_CreateSceneChangeEvent(void *a, u32 b);
extern u32 FIELDMAP_GetG3dMapper(FieldMap *fieldMap);
extern int MAP_ATTR_GetAt(void *a, void *b);
extern u16 MAP_ATTR_GetTerrainId(u32 attr);
extern int MAP_ATTR_IsNoInteract(u16 id);
extern u16 EVENTDATA_SYSTEM_GetPosEventScriptId(void *p, void *q, int key, int mode);
extern u16 FIELD_PLAYER_ChooseMoveDirFromKeys(u8 *p, u32 a1);
extern u32 ZONEDATA_IsZone117(u32 id);
extern void *INTRUDE_FIELD_CreateEdgeTask(void *a, void *b, void *c, int *d, u16 e, int f);
extern void *EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(void *c, void *a, int *key, int mode);
extern u32 FIELD_PLAYER_GetFormCode(u8 *p);
extern u16 FLDMMDL_GetAcmdCode(u8 *p);
extern void *FIELDMAP_GetGameSystem(FieldMap *fieldMap);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *mon, u32 id, u32 v);
extern void *func_02008854(void *sys);
extern void func_02008970(const void *obj, u32 *out);
extern void func_0200896C(void *obj, u32 value);
extern u32 GPOWER_ApplyHatchRate(u32 v);
extern void *func_02012934(const void *p);
extern void *FIELDMAP_GetSodateya(FieldMap *fieldMap);
extern int SODATEYA_AddStep(void **p);
extern u16 func_02008978(const void *obj);
extern void func_02008980(void *obj, u16 value);
extern void NATSUKI_CalcWalk(void *mon, int a, int b);
extern int SCRCMD_ShowStepMilestoneMessage(void *gameSystem, FieldMap *fieldMap);
extern u16 func_02008990(const void *obj);
extern void func_02008988(void *obj, u16 value);
extern void *MOVE_POKEMON_SAVE_GetBlock(void *p);
extern u32 MOVE_POKEMON_SAVE_TickCooldown(void *p);
extern int EFFECT_ENCOUNT_TriggerSpot(void *self);
extern void EFFECT_ENCOUNT_OnPlayerStep(void *ctx);
extern u8 GPOWER_GetExpiringPowerId(void);
extern struct GameEvent *GAME_EVENT_CreateOverlayEvent(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3);
extern void GPOWER_EVENT_CreateTimeoutScriptEvent(void *p);
extern void *EVENTDATA_SYSTEM_GetConnectData(char *p, unsigned i);
extern int EVENTDATA_SYSTEM_IsConnectDisabled(u16 *p);
extern int FIELD_TILE_MOVE_IsSpinTile(u32 a);
extern void *FIELD_TILE_MOVE_StartSpinTask(u32 prio, void *sys, void *owner);
extern int FIELD_TILE_MOVE_IsSlideTile(u32 a);
extern void *FIELD_TILE_MOVE_StartSlideTask(u32 prio, void *sys, void *owner);
extern u16 EVENTDATA_SYSTEM_GetConnectGridExitOffset(void *b, void *pos);
extern u8 EVENTDATA_SYSTEM_GetConnectExitType(u8 *p);
extern void *EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate(void *p, int u, int a, int b);
extern void *EVENT_MAPCHANGE_CreateExitWarpEvent(void *p, int u, int a, int b);
extern void ZONEDATA_SetExitLocation(void *p, u16 a, s16 b, u16 c, u16 d, u32 e, u32 f, u32 g);
extern void func_02012878(void *p, const void *src);
extern int EVENTDATA_SYSTEM_SearchConnectIdByGridPos(void *eventData, VecFx32 *pos);
int EVENTDATA_SYSTEM_IsConnectExitDir(char *a0, int a1);
extern u16 MAP_ATTR_GetFlags(u32 attr);
extern int FIELD_GIMMICK_IsGimmickId(FieldMap *fieldMap, int k);
extern int FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent(int a0, int a1, int a2);
extern int FIELD_GIMMICK_D06_CheckPushStone(int a, int b);
extern int MAP_ATTR_IsWaterfall(u16 a);
extern int FLDMMDL_MOVE_GetMapHeight(void *m, VecFx32 *pos, int *h);
extern int FIELD_GIMMICK_CART_LANES_CheckRideEvent(void *a);
extern int FIELD_GIMMICK_CANNONS_CreateLaunchEvent(void *a);
extern int EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(void *eventData, RailLocation *location);
extern int ZONEDATA_IsZoneInTableDFC0(int a0);
extern int FIELD_ENCOUNT_CheckWfbcEncount(void *ctx, void *b);
extern int FIELD_ENCOUNT_CheckWildEncount(void *ctx, int mode);
extern int RAIL_ATTR_IsSignBoard(u16 a);
extern int FLDMMDL_RAIL_GetHitBitsDirNoAttr(u32 a, u32 b);
extern u32 RAIL_SLIPDOWN_StartAtPlayer(u32 a, u32 b, u32 c);
extern void ZONEDATA_SetExitRailLocation(u8 *p, u16 b, int c, u16 d, u16 e, u16 f, u16 g, s16 h);
extern u16 EVENTDATA_SYSTEM_GetConnectRailExitOffset(void *b, void *q);
extern void *FLDMMDL_GetMmdlSys(void *o);
extern void FLDMMDL_SysPauseMove(void *o);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);
extern u32 FIELD_PLAYER_GetRideEffect(u8 *p);
extern void FLDEFF_NAMIPOKE_SetFollowMode(u32 a, u8 v);
extern void FIELD_PLAYER_StartFormChange(u8 *p, u32 a1);
extern void FIELD_PLAYER_FinishFormChange(int *p);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *o, int a);
extern int FLDMMDL_CheckEndAcmd(void *o);
extern int FIELD_PLAYER_ChangeToNormalForm(void *a);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern void FIELD_PLAYER_SetGridMoveState(u32 *p, int a);
struct GameEvent *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(void *p);
extern void FIELD_PLAYER_GetPosInDir(u32 *a, int b, int *out);
extern int MAP_ATTR_IsLongHopEdge(int a);
extern int FIELD_PLAYER_GetFrontGridPos(u32 a, u32 b, u32 c, u32 d);
extern void FLDMMDL_MOVE_GridToVector(int x, int y, int z, int *out);
extern int MAP_ATTR_IsCameraStep(u16 id);
extern void FLDMMDL_MOVE_AddDirGrid(int dir, s16 *x, s16 *z, s16 amt);
extern void *FIELDMAP_GetMmdlSys(FieldMap *fieldMap);
extern u32 FLDMMDL_GetPosY(void *p);
extern u8 *FLDMMDL_SysSearchGridPosHeight(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
u32 FLDMMDL_RAIL_SearchMmdlByLocation(u32 o, u32 k, u32 flag);
extern u32 FIELD_PLAYER_GetFrontAttribute(u32 *a, u32 b);
extern u32 ZONEDATA_IsNormalFieldZone(u32 id);
extern int FIELD_PLAYER_CheckEncountAttr(u8 *a, int b, int c);
extern int FIELD_PLAYER_CheckSurfEntryAttr(u8 *a, int b, int c);
extern int FLDMMDL_GetGridNowX(void *o);
extern int FLDMMDL_GetGridNowZ(void *o);
extern int FLDMMDL_MOVE_GetDirAddGridX(u16 d);
extern int FLDMMDL_MOVE_GetDirAddGridZ(u16 d);
extern void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d);
void *FIELD_G3D_MAPPER_GetWfbc(u8 *p);
extern FieldMapTypeEntryTail gMapTypeCtrlTable[];
extern u8 abs_id_83[];
extern const struct TileMessage data_021D3CE8[13];


int FIELDMAP_GetHeapSizeForMapType(int zoneId);
int FIELD_EVENT_CHECK_CheckGridEvents(void *gameSystem, FieldMap *fieldMap, int *outResetEncount, int *outMenuRequest);
int FIELD_EVENT_CHECK_RunGrid(void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckCommEvents(void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_RunRail(void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckRailEvents(void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_Run(void *gameSystem, FieldMap *fieldMap, u32 unusedC, u32 unusedD);
void FIELD_EVENT_CHECK_InitInput(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
void FIELD_EVENT_CHECK_StopSoundAfterEvent(void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_AddStepRecord(void *gameData);
int FIELD_EVENT_CHECK_StartPendingScript(FieldEventInput *input);
int FIELD_EVENT_CHECK_CheckPosEventAtPlayer(FieldEventInput *input);
int FIELD_EVENT_CHECK_CheckPosEventForDir(FieldEventInput *input, int dir);
int FIELD_EVENT_CHECK_CheckPosEventFacing(FieldEventInput *input);
int FIELD_EVENT_CHECK_CheckPosEventHeldDir(FieldEventInput *input);
void *FIELD_EVENT_CHECK_CheckIntrudeEdge(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckPosEventCenterTile(FieldEventInput *input);
int FIELD_EVENT_CHECK_CheckStepEvents(FieldEventInput *input, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_GetEggCycleDecrement(void *party);
void FIELD_EVENT_CHECK_DecrementEggCycles(void *party);
void FIELD_EVENT_CHECK_UpdateEggStepCounter(void *gameData, void *party);
int FIELD_EVENT_CHECK_IsEggReadyToHatch(void *party);
int FIELD_EVENT_CHECK_CheckEggHatch(FieldEventInput *input, FieldMap *fieldMap, void *gameSystem, void *gameData);
void FIELD_EVENT_CHECK_UpdateWalkFriendship(void *gameData, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckZoneStepMessage(void *gameSystem, FieldMap *fieldMap, u16 zoneId);
int FIELD_EVENT_CHECK_CheckSaveFlagMessage(FieldMap *fieldMap, void *gameSystem, void *gameData);
int FIELD_EVENT_CHECK_CheckStepEncount(FieldMap *fieldMap, void *gameSystem, void *gameData);
struct GameEvent *FIELD_EVENT_CHECK_CreateGPowerExpireEvent(void *gameSystem);
int FIELD_EVENT_CHECK_CheckGridConnect(FieldEventInput *input, FieldMap *fieldMap, VecFx32 *pos);
void *FIELD_EVENT_CHECK_CheckTileMoveTask(FieldEventInput *input, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_StartConnectEvent(FieldEventInput *input, FieldMap *fieldMap, int connectId, VecFx32 *pos);
void FIELD_EVENT_CHECK_SetEntranceFromGridConnect(FieldEventInput *input, int connectId, VecFx32 *pos);
u32 FIELD_EVENT_CHECK_FindGridConnectId(FieldEventInput *input, VecFx32 *pos);
void FIELD_EVENT_CHECK_GetFrontPos(FieldEventInput *input, VecFx32 *out);
int FIELD_EVENT_CHECK_IsConnectOnFootType(void *connect);
int FIELD_EVENT_CHECK_IsConnectExitDir(void *connect, int dir);
int FIELD_EVENT_CHECK_CheckGridConnectFront(FieldEventInput *input, int unused, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckFrontTileEvents(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckRailConnect(FieldEventInput *input, void *unused, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckRailConnectFront(FieldEventInput *input, void *unused, FieldMap *fieldMap, RailLocation *frontLocation);
int FIELD_EVENT_CHECK_CheckWildEncount(FieldEventInput *input, void *unused, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_CheckRailSignBoard(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
void FIELD_EVENT_CHECK_SetEntranceFromRailConnect(FieldEventInput *input, int connectId, RailLocation *location);
int FIELD_EVENT_CHECK_StartRailConnectEvent(FieldEventInput *input, FieldMap *fieldMap, int connectId, RailLocation *location);
int FIELD_EVENT_CHECK_IsRailFrontFree(void *player, FieldEventInput *input);
int FIELD_EVENT_CHECK_LedgeJumpTaskMain(void *task, int *seq, LedgeJumpWork *work);
int FIELD_EVENT_CHECK_CreateLedgeJumpTask(int unused, void *gameSystem, FieldMap *fieldMap, int dir, int jumpTwoTiles);
int FIELD_EVENT_CHECK_CheckLedgeJump(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_SearchGridFrontMmdl(FieldEventInput *input, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_SearchRailFrontMmdl(FieldEventInput *input, FieldMap *fieldMap);
u16 FIELD_EVENT_CHECK_GetFrontTileMessage(FieldEventInput *input, FieldMap *fieldMap);
int FIELD_EVENT_CHECK_FindPartyMemberWithMove(void *gameData, u32 move);
int FIELD_EVENT_CHECK_CountAlivePartyMembers(void *gameSystem);
int FIELD_EVENT_CHECK_IsLedgePathClear(FieldEventInput *input, FieldMap *fieldMap);

int FIELDMAP_GetHeapSizeForMapType(int zoneId)
{
    return gMapTypeCtrlTable[(int)FIELDMAP_GetMapType((unsigned int)zoneId)].extra;
}


/*
 * Root of the field input tree: builds the field input record on the stack
 * and runs the talk / step / menu / surf / script checks in order,
 * returning the first non-zero result.  The u16 local at sp+0x28 is the
 * out slot of FIELD_GetPlayerAreaZoneId; its address doubles as the base for the
 * in.heapId / in.zoneId loads, which is why `add r1, sp, #0x28` sits above the
 * beq after the INTRUDE_FindOfferSlotAt test.
 */
int FIELD_EVENT_CHECK_CheckGridEvents(void *gameSystem, FieldMap *fieldMap, int *outResetEncount, int *outMenuRequest)
{
    FieldEventInput input;
    int frontPos[3];
    u32 commTarget;
    u16 areaZoneId;
    int result;
    u32 blockFlags;
    void *commWork;
    void *gameComm;
    void *playerMmdl;

    *outResetEncount = 0;
    *outMenuRequest = 0;
    FIELD_EVENT_CHECK_InitInput(&input, gameSystem, fieldMap);
    result = FIELD_EVENT_CHECK_StartPendingScript(&input);
    if (result != 0) {
        *outResetEncount = 1;
        return result;
    }
    result = PLEASURE_BOAT_Update((int)gameSystem, (char *)(*GAME_DATA_GetEventState(input.gameData)));
    if (result != 0)
        return result;
    result = EVENT_TRAINER_EYE_Check((int)fieldMap);
    if (result != 0) {
        *outResetEncount = 1;
        return result;
    }
    if (input.walkStepDone)
        FIELD_EVENT_CHECK_AddStepRecord(input.gameData);
    if (input.walkStepDone) {
        result = FIELD_EVENT_CHECK_CheckPosEventAtPlayer(&input);
        if (result != 0) {
            *outResetEncount = 1;
            return result;
        }
        result = FIELD_EVENT_CHECK_CheckGridConnect(&input, fieldMap, input.playerPos);
        if (result != 0)
            return result;
        result = (int)FIELD_EVENT_CHECK_CheckTileMoveTask(&input, fieldMap);
        if (result != 0)
            return result;
    }
    result = FIELD_EVENT_CHECK_CheckStepEvents(&input, fieldMap);
    if (result != 0)
        return result;
    if (input.stepDone) {
        result = FIELD_EVENT_CHECK_CheckPosEventFacing(&input);
        if (result != 0)
            return result;
    }
    result = FIELD_EVENT_CHECK_CheckPosEventHeldDir(&input);
    if (result != 0)
        return result;
    result = (int)FIELD_EVENT_CHECK_CheckIntrudeEdge(&input, gameSystem, fieldMap);
    if (result != 0)
        return result;
    result = FIELD_EVENT_CHECK_CheckWildEncount(&input, gameSystem, fieldMap);
    if (result != 0)
        return result;

    blockFlags = 0;
    if ((int)ZONEDATA_CheckEventFlag((void *)func_0201296C(input.gameData), (u32)0x964) == 1)
        blockFlags |= 1;
    result = FIELD_PLAYER_TryPushBoulder(input.player, input.keyTrg, input.keyCont, blockFlags);
    if (result != 0)
        return result;

    gameComm = (void *)func_02012138(gameSystem);
    commWork = (void *)INTRUDE_COMM_GetWorkIfRunning((int)gameComm);
    playerMmdl = FIELD_PLAYER_GetMmdl(input.player);
    if (INTRUDE_FIELD_IsCommAllowed((const void *)gameSystem, input.zoneId) == 1)
        return INTRUDE_SUBDISP_CreateDisconnectEvent(gameSystem, 0);
    if ((int)GAME_COMM_GetKind(gameComm) == 2 && commWork != 0) {
        if (func_02012B70(input.gameData) == 1 && INTRUDE_FIELD_IsStartRequested(commWork) == 1)
            return (int)INTRUDE_FIELD_CreateNoticeEvent(gameSystem, fieldMap);
        if (INTRUDE_COMM_ConsumeAreaNoticeSeen(commWork, input.zoneId) == 1)
            return (int)FIELD_INTRUDE_EVENT_StartSymbolEntry((int)gameSystem, 9, (u32)GAME_DATA_GetSymbolMapFlag(input.gameData));
        if (input.inputEnabled == 1 && INTRUDE_COMM_GetActiveRequestTarget(commWork, (int *)(&commTarget)) == 1) {
            FIELD_PLAYER_ResetMoveWork(input.player);
            return (int)EVENT_COMM_COMMON_CreateTalkedStartEvent(gameSystem, (int)fieldMap, (int)commWork, (int)playerMmdl, commTarget, input.heapId);
        }
        if (input.stepDone) {
            result = INTRUDE_FIELD_TryStartOfferEvent((int)gameSystem, commWork, input.player);
            if (result != 0)
                return result;
        }
        if (input.aPressed && INTRUDE_FIELD_FindRemotePlayerAhead(commWork, input.player, (int *)(&commTarget)) == 1) {
            FIELD_PLAYER_ResetMoveWork(input.player);
            return (int)EVENT_COMM_COMMON_CreateTalkStartEvent(gameSystem, (int)fieldMap, (int)commWork, (int)playerMmdl, commTarget, input.heapId);
        }
    }

    if (input.aPressed) {
        u32 facing = FIELD_PLAYER_GetDirDisp(input.player);
        int frontMmdl;
        u32 scriptId;
        int gridX;
        int gridY;
        int gridZ;
        void *mapper;

        FIELD_PLAYER_GetPos(input.player, (VecFx32 *)frontPos);
        FLDMMDL_MOVE_AddDirVector((u32)facing, frontPos, 0x10000);
        frontMmdl = FIELD_EVENT_CHECK_SearchGridFrontMmdl(&input, fieldMap);
        if (frontMmdl != 0) {
            u32 eventId = FLDMMDL_GetEventId((void *)frontMmdl);

            if (SCRIPT_SYS_IsZoneScriptId(eventId) == 1) {
                void *mmdl = FIELD_PLAYER_GetMmdl(input.player);

                FIELD_PLAYER_ResetMoveWork(input.player);
                *outResetEncount = 1;
                return func_0219F01C((u32)gameSystem, (u32)fieldMap, eventId, (u32)mmdl, frontMmdl, input.heapId);
            }
        }
        scriptId = EVENTDATA_SYSTEM_SearchBgEventScriptIdTalk(input.eventData, (void *)func_0201296C(input.gameData), frontPos, facing);
        if (scriptId != 0xFFFF)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)gameSystem, scriptId, 0, input.heapId);
        scriptId = FIELD_EVENT_CHECK_GetFrontTileMessage(&input, fieldMap);
        if (scriptId != 0xFFFF)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)gameSystem, scriptId, 0, input.heapId);
        gridX = frontPos[0] >> 12;
        gridY = frontPos[1] >> 12;
        gridZ = frontPos[2] >> 12;
        mapper = func_0200BE48(GAME_DATA_GetSaveControl(input.gameData));
        scriptId = (u32)INTRUDE_FindOfferSlotAt(mapper, (u16)FIELDMAP_GetZoneId(fieldMap), (s16)(gridX / 16), (s16)(gridY / 16), (s16)(gridZ / 16));
        if (scriptId != 0xFF)
            return (int)INTRUDE_StartOfferEvent(gameSystem, input.heapId, (void *)scriptId);
        if (FIELD_GetPlayerAreaZoneId(fieldMap, &areaZoneId) == 1)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)gameSystem, 0x271B, 0, input.heapId);
        if (ZONEDATA_IsZoneInTableDFB8(input.zoneId)) {
            scriptId = EVENTDATA_SYSTEM_GetAutoPosEventScriptId(input.eventData, (void *)func_0201296C(input.gameData), (int)frontPos);
            if (scriptId != 0xFFFF)
                return (int)SCRIPT_SYS_CreateScriptEventSimple((int)gameSystem, scriptId, 0, input.heapId);
        }
    }

    if (input.moveState == 3 || input.moveState == 0) {
        result = FIELD_EVENT_CHECK_CheckLedgeJump(&input, gameSystem, fieldMap);
        if (result != 0)
            return result;
    }
    if (input.pushingFacing) {
        result = FIELD_EVENT_CHECK_CheckGridConnectFront(&input, (int)gameSystem, fieldMap);
        if (result != 0)
            return result;
        result = FIELD_EVENT_CHECK_CheckFrontTileEvents(&input, gameSystem, fieldMap);
        if (result != 0)
            return result;
    }
    if (input.yPressed && WIPE_SYS_EndCheck()) {
        void *subscreen = (void *)FIELDMAP_GetSubscreen(fieldMap);

        if (EVENT_SHORTCUT_MENU_HasShortcuts(gameSystem) && FIELD_SUBSCREEN_IsIdle((u32)subscreen)) {
            result = (int)EVENT_SHORTCUT_MENU_Create((int)gameSystem, (int)fieldMap, input.heapId);
            if (result != 0)
                return result;
        }
    }
    if (func_0201212C(gameSystem) == 1 && WIPE_SYS_EndCheck() && input.inputEnabled)
        return EVENT_COMM_ERROR_Create(gameSystem, fieldMap);
    if (input.xPressed && WIPE_SYS_EndCheck()) {
        if ((int)FIELD_SUBSCREEN_GetMode((void *)FIELDMAP_GetSubscreen(fieldMap)) == 6)
            return 0;
        *outMenuRequest = 1;
        return (int)SCRCMD_NETWORK_CreateBattleRecordLinkEvent((int)gameSystem, (int)fieldMap, input.heapId);
    }
    if (WIPE_SYS_EndCheck()) {
        result = FIELD_SUBSCREEN_CheckModeRequest((void *)FIELDMAP_GetSubscreen(fieldMap), input.noButton);
        if (result != 0)
            return result;
    }
    if (input.noButton && WIPE_SYS_EndCheck()) {
        result = (int)FIELD_EVENT_CHECK_CreateGPowerExpireEvent(gameSystem);
        if (result != 0)
            return result;
    }
    result = INTRUDE_FIELD_CreateTileEvent((int)fieldMap, (int)gameSystem, input.player);
    if (result == 0)
        return 0;
    return result;
}


int FIELD_EVENT_CHECK_RunGrid(void *gameSystem, FieldMap *fieldMap)
{
    int resetEncount;
    int menuRequest;
    int result;
    FieldMap *curFieldMap;
    void *encount;

    curFieldMap = func_0201210C(gameSystem);
    encount = (void *)FIELDMAP_GetEncount(curFieldMap);
    EFFECT_ENCOUNT_UpdateOccupiedSpot();
    result = FIELD_EVENT_CHECK_CheckGridEvents(gameSystem, fieldMap, &resetEncount, &menuRequest);
    if (result != 0) {
        if (resetEncount != 0)
            EFFECT_ENCOUNT_Reset(encount);
        FIELD_PLACE_NAME_Cancel((u8 *)((void *)FIELDMAP_GetPlaceName(curFieldMap)));
        FIELD_PLAYER_SetGridMoveFlag(FIELDMAP_GetFieldPlayer(curFieldMap), menuRequest);
        FIELD_PLAYER_ResetGridMove(FIELDMAP_GetFieldPlayer(curFieldMap));
        if (FIELDMAP_GetZoneEffectWork(curFieldMap) != 0)
            FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume();
        FIELD_EVENT_CHECK_StopSoundAfterEvent(gameSystem, curFieldMap);
    }
    return result;
}


int FIELD_EVENT_CHECK_CheckCommEvents(void *gameSystem, FieldMap *fieldMap)
{
    FieldEventInput input;
    void *gameComm;
    void *commWork;
    int result;
    int frontMmdl;
    u32 eventId;
    void *playerMmdl;

    gameComm = (void *)func_02012138(gameSystem);
    commWork = (void *)GAME_COMM_GetWork(gameComm);
    FIELD_EVENT_CHECK_InitInput(&input, gameSystem, fieldMap);
    if (commWork == 0) {
        if (func_0200FB24() != 0) {
            if (WIPE_SYS_EndCheck() != 0)
                return EVENT_COMM_ERROR_Create(gameSystem, fieldMap);
            return 0;
        }
        return (int)EVENT_MAPCHANGE_CreateSpecialLocationEvent(gameSystem, fieldMap);
    }
    if (UNION_MAIN_GetFieldRequest(commWork) == 1) {
        if (UNION_MAIN_IsExitStarted(commWork) == 0)
            GAME_COMM_RequestExitNoCallback(gameComm);
        return 0;
    }
    if (input.walkStepDone && (result = FIELD_EVENT_CHECK_CheckPosEventForDir(&input, 9)) != 0)
        return result;
    if ((result = UNION_ONESELF_TryStartSubEvent((int)gameSystem, (int)fieldMap)) != 0)
        return result;
    if (input.aPressed && (result = UNION_ONESELF_GetFieldTalkEvent(gameSystem, fieldMap)) != 0)
        return result;
    if (input.aPressed && UNION_MAIN_IsIdle(gameSystem) == 1) {
        frontMmdl = FIELD_EVENT_CHECK_SearchGridFrontMmdl(&input, fieldMap);
        if (frontMmdl != 0) {
            eventId = FLDMMDL_GetEventId((void *)frontMmdl);
            if (SCRIPT_SYS_IsZoneScriptId(eventId) == 1) {
                playerMmdl = FIELD_PLAYER_GetMmdl(input.player);
                if (UNION_CHARA_IsUnionObjId(FLDMMDL_GetObjId((void *)frontMmdl)) == 0) {
                    FIELD_PLAYER_ResetMoveWork(input.player);
                    return func_0219F01C((u32)gameSystem, (u32)fieldMap, eventId, (u32)playerMmdl, frontMmdl, input.heapId);
                }
            }
        }
    }
    if (func_0201212C(gameSystem) == 1 && WIPE_SYS_EndCheck() != 0)
        return EVENT_COMM_ERROR_Create(gameSystem, fieldMap);
    if (UNION_MAIN_IsIdle(gameSystem) == 0)
        return 0;
    if (input.xPressed && WIPE_SYS_EndCheck() != 0)
        return SCRCMD_NETWORK_CreateBattleRecordLinkEventForZone((int)gameSystem, (int)fieldMap, input.heapId);
    return 0;
}


int FIELD_EVENT_CHECK_RunRail(void *gameSystem, FieldMap *fieldMap)
{
    FieldMap *curFieldMap;
    int result = FIELD_EVENT_CHECK_CheckRailEvents(gameSystem, fieldMap);
    if (result != 0) {
        curFieldMap = func_0201210C(gameSystem);
        FIELD_PLACE_NAME_Cancel((u8 *)FIELDMAP_GetPlaceName(curFieldMap));
        if (FIELDMAP_GetZoneEffectWork(curFieldMap) != 0)
            FIELD_GIMMICK_SOUND_OBJS_RaiseBgmVolume();
        FIELD_EVENT_CHECK_StopSoundAfterEvent(gameSystem, curFieldMap);
    }
    return result;
}


int FIELD_EVENT_CHECK_CheckRailEvents(void *gameSystem, FieldMap *fieldMap)
{
    FieldEventInput input;
    RailLocation frontLocation;
    RailLocation nextLocation;
    RailLocation locationCopy;
    void *playerMmdl;
    int result;
    u32 scriptId;

    FIELD_EVENT_CHECK_InitInput(&input, gameSystem, fieldMap);
    playerMmdl = FIELD_PLAYER_GetMmdl(input.player);
    FLDMMDL_RAIL_GetFrontLocation(playerMmdl, &frontLocation);
    result = FIELD_EVENT_CHECK_StartPendingScript(&input);
    if (result != 0)
        return result;
    if (input.walkStepDone)
        FIELD_EVENT_CHECK_AddStepRecord(input.gameData);
    if (input.walkStepDone) {
        void *playerMmdlNow = FIELD_PLAYER_GetMmdl(input.player);
        void *eventWork = (void *)func_0201296C(input.gameData);

        FLDMMDL_RAIL_GetNextLocation(playerMmdlNow, &nextLocation);
        scriptId = EVENTDATA_SYSTEM_GetRailPosEventScriptId(input.eventData, eventWork, &nextLocation);
        if (scriptId != 0xFFFF)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)gameSystem, scriptId, 0, input.heapId);
        result = FIELD_EVENT_CHECK_CheckRailConnect(&input, gameSystem, fieldMap);
        if (result != 0)
            return result;
        result = FIELD_EVENT_CHECK_CheckStepEvents(&input, fieldMap);
        if (result != 0)
            return result;
    }
    result = FIELD_EVENT_CHECK_CheckWildEncount(&input, gameSystem, fieldMap);
    if (result != 0)
        return result;
    if (input.aPressed) {
        int frontMmdl = FIELD_EVENT_CHECK_SearchRailFrontMmdl(&input, fieldMap);
        void *eventWork;
        u16 dirDisp;

        if (frontMmdl != 0) {
            u32 eventId = FLDMMDL_GetEventId((void *)frontMmdl);

            if (SCRIPT_SYS_IsZoneScriptId(eventId) == 1) {
                void *mmdl = FIELD_PLAYER_GetMmdl(input.player);

                FIELD_PLAYER_ResetMoveWork(input.player);
                return func_0219F01C((u32)gameSystem, (u32)fieldMap, eventId, (u32)mmdl, frontMmdl, input.heapId);
            }
        }
        eventWork = (void *)func_0201296C(input.gameData);
        dirDisp = FLDMMDL_GetDirDisp(playerMmdl);
        locationCopy = frontLocation;
        scriptId = EVENTDATA_SYSTEM_SearchBgEventScriptIdHidden(input.eventData, eventWork, &locationCopy, dirDisp);
        if (scriptId != 0xFFFF)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)gameSystem, scriptId, 0, input.heapId);
    }
    if (input.pushingFacing && FIELD_EVENT_CHECK_IsRailFrontFree(FIELDMAP_GetFieldPlayer(fieldMap), &input) == 0) {
        result = FIELD_EVENT_CHECK_CheckRailConnectFront(&input, gameSystem, fieldMap, &frontLocation);
        if (result != 0)
            return result;
    }
    result = FIELD_EVENT_CHECK_CheckRailSignBoard(&input, gameSystem, fieldMap);
    if (result != 0)
        return result;
    if (input.yPressed && WIPE_SYS_EndCheck()) {
        void *subscreen = (void *)FIELDMAP_GetSubscreen(fieldMap);

        if (EVENT_SHORTCUT_MENU_HasShortcuts(gameSystem) && FIELD_SUBSCREEN_IsIdle((u32)subscreen)) {
            result = (int)EVENT_SHORTCUT_MENU_Create((int)gameSystem, (int)fieldMap, input.heapId);
            if (result != 0)
                return result;
        }
    }
    if (func_0201212C(gameSystem) == 1 && WIPE_SYS_EndCheck() && input.inputEnabled)
        return EVENT_COMM_ERROR_Create(gameSystem, fieldMap);
    if (input.xPressed && WIPE_SYS_EndCheck()) {
        if (FIELD_SUBSCREEN_GetMode((void *)FIELDMAP_GetSubscreen(fieldMap)) == 6)
            return 0;
        return (int)SCRCMD_NETWORK_CreateBattleRecordLinkEvent((int)gameSystem, (int)fieldMap, input.heapId);
    }
    {
        u32 noButtonActive = (input.noButton && WIPE_SYS_EndCheck()) ? 1 : 0;

        result = FIELD_SUBSCREEN_CheckModeRequest((void *)FIELDMAP_GetSubscreen(fieldMap), noButtonActive);
        if (result != 0)
            return result;
    }
    if (input.noButton && WIPE_SYS_EndCheck()) {
        result = (int)FIELD_EVENT_CHECK_CreateGPowerExpireEvent(gameSystem);
        if (result != 0)
            return result;
    }
    return 0;
}


int FIELD_EVENT_CHECK_Run(void *gameSystem, FieldMap *fieldMap, u32 unusedC, u32 unusedD)
{
    if (FIELDMAP_GetMoveKind(fieldMap) == 0)
        return FIELD_EVENT_CHECK_RunGrid(gameSystem, fieldMap);
    return FIELD_EVENT_CHECK_RunRail(gameSystem, fieldMap);
}


/*
 * Fills the 0x40 byte field input record for one frame: pad trigger and held
 * keys, the held d-pad direction, the player object's position, facing and
 * movement state, and the request bitfield at 0x3C (talk on A, menu on X,
 * registered item on Y, no-input, step, surf and push flags).
 */
void FIELD_EVENT_CHECK_InitInput(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap)
{
    void *playerMmdl;

    MI_CpuFill8(input, 0, 0x40);
    input->heapId = FIELDMAP_GetHeapId(fieldMap);
    input->gameSystem = gameSystem;
    input->gameData = func_020120F4(gameSystem);
    input->eventData = (void *)func_02012844(input->gameData);
    input->zoneId = FIELDMAP_GetZoneId(fieldMap);
    input->keyTrg = KEY_GetTrg();
    input->keyCont = KEY_GetCont();
    input->heldDir = 9;
    if (input->keyCont & 0x40)
        input->heldDir = 0;
    else if (input->keyCont & 0x80)
        input->heldDir = 1;
    else if (input->keyCont & 0x20)
        input->heldDir = 2;
    else if (input->keyCont & 0x10)
        input->heldDir = 3;
    input->fieldMap = fieldMap;
    input->player = FIELDMAP_GetFieldPlayer(fieldMap);
    FIELD_PLAYER_UpdateStepPhase(input->player);
    input->moveMode = FIELD_PLAYER_GetStepKind(input->player);
    input->moveState = FIELD_PLAYER_GetStepPhase(input->player);
    playerMmdl = FIELD_PLAYER_GetMmdl(input->player);
    input->facingDir = FLDMMDL_GetDirDisp(playerMmdl);
    input->playerPos = (VecFx32 *)FLDMMDL_GetPosPtr(playerMmdl);
    input->pendingScriptId = FIELD_STATUS_GetProcAction(func_02012B38(input->gameData));
    input->tileAttr = FIELD_PLAYER_GetNowAttribute(input->player);

    if (input->moveState == 3 || input->moveState == 0) {
        u8 buttonCount;

        input->inputEnabled = 1;
        input->aPressed = (input->keyTrg & 1) ? 1 : 0;
        input->xPressed = (input->keyTrg & 0x400) ? 1 : 0;
        input->yPressed = (input->keyTrg & 0x800) ? 1 : 0;
        buttonCount = 0;
        buttonCount += input->aPressed;
        buttonCount += input->xPressed;
        buttonCount += input->yPressed;
        if (buttonCount == 0)
            input->noButton = 1;
    }
    input->walkStepDone = 0;
    input->tileChanged = 0;
    if (input->moveMode == 1)
        input->walkStepDone = (input->moveState == 3) ? 1 : 0;
    if (FIELD_PLAYER_GetGridMoveState(input->player))
        input->tileChanged = 1;
    input->stepDone = (input->moveState == 3) ? 1 : 0;
    input->otherMoveBusy = 0;
    if (input->moveState != 3 && input->moveMode == 2)
        input->otherMoveBusy = 1;
    if ((input->facingDir == 0 && (input->keyCont & 0x40)) || (input->facingDir == 1 && (input->keyCont & 0x80))
        || (input->facingDir == 2 && (input->keyCont & 0x20)) || (input->facingDir == 3 && (input->keyCont & 0x10)))
        input->pushingFacing = 1;
    else
        input->pushingFacing = 0;
}


void FIELD_EVENT_CHECK_StopSoundAfterEvent(void *gameSystem, FieldMap *fieldMap)
{
    void *subscreenProc;

    subscreenProc = (void *)FIELD_SUBSCREEN_GetCGear((u32 *)FIELDMAP_GetSubscreen(fieldMap));
    if (subscreenProc == 0) {
        func_02028A70((void *)func_02012A30(func_020120F4(gameSystem)));
        return;
    }
    if (C_GEAR_IsLastCommandKind5(subscreenProc) == 0) {
        func_02028A70((void *)func_02012A30(func_020120F4(gameSystem)));
        C_GEAR_StopRingtone(subscreenProc);
    }
}


int FIELD_EVENT_CHECK_AddStepRecord(void *gameData)
{
return func_02008DF0((void *)GAME_DATA_GetTrainerRecord((int *)gameData), 0);
}


/*
 * Starts the pending script (field 0x26) through SCRIPT_SYS_CreateScriptEventSimple, or else asks
 * SCRIPT_SYS_CreateSceneChangeEvent for the default one; returns the result.
 */
int FIELD_EVENT_CHECK_StartPendingScript(FieldEventInput *input)
{
    int r;

    if (input->pendingScriptId != 0) {
        FIELD_STATUS_SetProcAction(func_02012B38(input->gameData), 0);
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)input->gameSystem, input->pendingScriptId, 0, input->heapId);
    }
    r = (int)SCRIPT_SYS_CreateSceneChangeEvent(input->gameSystem, input->heapId);
    if (r == 0)
        return 0;
    return r;
}


/*
 * Tries FIELD_EVENT_CHECK_CheckPosEventCenterTile, then FIELD_EVENT_CHECK_CheckPosEventForDir with direction 9.
 */
int FIELD_EVENT_CHECK_CheckPosEventAtPlayer(FieldEventInput *input)
{
    int r = FIELD_EVENT_CHECK_CheckPosEventCenterTile(input);

    if (r != 0)
        return r;
    return FIELD_EVENT_CHECK_CheckPosEventForDir(input, 9);
}


/*
 * Unless the tile attribute under the object's position blocks it
 * (MAP_ATTR_IsNoInteract), asks ov010 EVENTDATA_SYSTEM_GetPosEventScriptId for a message id and shows it
 * through SCRIPT_SYS_CreateScriptEventSimple; returns 0 otherwise.
 */
int FIELD_EVENT_CHECK_CheckPosEventForDir(FieldEventInput *input, int dir)
{
    FieldMap *curFieldMap = func_0201210C(input->gameSystem);
    void *eventWork = (void *)func_0201296C(input->gameData);
    u32 playerPos[3];
    u32 scriptId;

    FIELD_PLAYER_GetPos(input->player, (VecFx32 *)playerPos);
    if (MAP_ATTR_IsNoInteract(MAP_ATTR_GetTerrainId(MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(curFieldMap), playerPos))) == 1)
        return 0;
    scriptId = EVENTDATA_SYSTEM_GetPosEventScriptId(input->eventData, eventWork, (int)playerPos, dir);
    if (scriptId != 0xFFFF)
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)input->gameSystem, scriptId, 0, input->heapId);
    return 0;
}


/*
 * Tries FIELD_EVENT_CHECK_CheckPosEventForDir for the current facing, then for the direction from
 * FIELD_PLAYER_ChooseMoveDirFromKeys when that differs and is not 9.
 */
int FIELD_EVENT_CHECK_CheckPosEventFacing(FieldEventInput *input)
{
    int result = FIELD_EVENT_CHECK_CheckPosEventForDir(input, input->facingDir);
    int inputDir;

    if (result != 0)
        return result;
    inputDir = FIELD_PLAYER_ChooseMoveDirFromKeys(input->player, input->keyCont);
    if (inputDir == 9 || inputDir == input->facingDir)
        return 0;
    result = FIELD_EVENT_CHECK_CheckPosEventForDir(input, inputDir);
    if (result == 0)
        return 0;
    return result;
}


/*
 * Maps the held d-pad bits (up, down, left, right) to a direction and, unless
 * it is the current facing, none, or the movement mode is 1 or 2, tries
 * FIELD_EVENT_CHECK_CheckPosEventForDir with it. The two-value mode test is a switch.
 */
int FIELD_EVENT_CHECK_CheckPosEventHeldDir(FieldEventInput *input)
{
    u32 keyCont = input->keyCont;
    u32 moveState = input->moveState;
    int heldDir = 9;

    if (keyCont & 0x40)
        heldDir = 0;
    else if (keyCont & 0x80)
        heldDir = 1;
    else if (keyCont & 0x20)
        heldDir = 2;
    else if (keyCont & 0x10)
        heldDir = 3;
    if (heldDir == input->facingDir)
        return 0;
    if (heldDir == 9)
        return 0;
    switch (moveState) {
    case 1:
    case 2:
        return 0;
    }
    return FIELD_EVENT_CHECK_CheckPosEventForDir(input, heldDir);
}


/*
 * When flag field 0x10 is set and FIELD_PLAYER_ChooseMoveDirFromKeys does not report 9, forwards
 * the object to ov018 INTRUDE_FIELD_CreateEdgeTask; returns 0 otherwise.
 */
void *FIELD_EVENT_CHECK_CheckIntrudeEdge(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap)
{
    int inputDir;

    if (ZONEDATA_IsZone117(input->zoneId) == 0)
        return 0;
    inputDir = FIELD_PLAYER_ChooseMoveDirFromKeys(input->player, input->keyCont);
    if (inputDir == 9)
        return 0;
    return INTRUDE_FIELD_CreateEdgeTask(gameSystem, fieldMap, input->player, *(int * *)&input->playerPos, input->facingDir, inputDir);
}


/*
 * Checks the background event in front of the player: shows its message when
 * the player stands at the event's centre tile, or when the tile behaviour is
 * one of 0x58..0x5B or 0xA3..0xA6 (range test spelled as the add of the
 * complement,
 * docs/idioms/a-masked-byte-subtract-in-a-range-test-is-an-add-of-the-complement.md)
 * or FIELD_PLAYER_GetFormCode allows it.
 */
int FIELD_EVENT_CHECK_CheckPosEventCenterTile(FieldEventInput *input)
{
    FieldMap *curFieldMap = func_0201210C(input->gameSystem);
    void *player = FIELDMAP_GetFieldPlayer(curFieldMap);
    int playerPos[3];
    PosEvent *posEvent;
    int canTrigger;
    u16 tileBehavior;
    u32 centerX;
    u16 *area;
    u32 centerZ;

    FIELD_PLAYER_GetPos(player, (VecFx32 *)playerPos);
    if (MAP_ATTR_IsNoInteract(MAP_ATTR_GetTerrainId(MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(curFieldMap), playerPos))) != 1)
        return 0;
    posEvent = (PosEvent *)EVENTDATA_SYSTEM_SearchPosEventIgnoreHeight(input->eventData, (void *)func_0201296C(input->gameData), playerPos, 9);
    if (posEvent == 0)
        return 0;
    if (posEvent->posType != 0)
        return 0;
    area = (u16 *)&posEvent->area;
    centerZ = area[1] + ((u32)area[3] >> 1);
    centerX = posEvent->area.x + ((u32)area[2] >> 1);
    if (centerX == (playerPos[0] >> 12) / 16 && centerZ == (playerPos[2] >> 12) / 16)
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)input->gameSystem, posEvent->scriptId, 0, input->heapId);
    canTrigger = FIELD_PLAYER_GetFormCode(player);
    tileBehavior = FLDMMDL_GetAcmdCode(FIELD_PLAYER_GetMmdl(player));
    if (canTrigger != 0 || tileBehavior == 0x58 || tileBehavior == 0x59 || tileBehavior == 0x5A || tileBehavior == 0x5B || (u16)(tileBehavior + 0xFF5D) <= 3)   /*
tileBehavior - 0xA3
 */
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)input->gameSystem, posEvent->scriptId, 0, input->heapId);
    return 0;
}


/*
 * Field step handler: runs the step-triggered checks in order (FIELD_EVENT_CHECK_CheckStepEncount,
 * the 128-step counter, milestones, egg hatching, the save flag message) and
 * returns the first non-zero result. Flags come from the u32 bitfield at
 * 0x3C.
 */
int FIELD_EVENT_CHECK_CheckStepEvents(FieldEventInput *input, FieldMap *fieldMap)
{
    void *gameSystem;
    void *gameData;
    int result;

    FIELDMAP_GetHeapId(fieldMap);
    gameSystem = FIELDMAP_GetGameSystem(fieldMap);
    gameData = func_020120F4(gameSystem);
    if (input->walkStepDone || input->tileChanged) {
        result = FIELD_EVENT_CHECK_CheckStepEncount(fieldMap, gameSystem, gameData);
        if (result != 0)
            return result;
    }
    if (!input->walkStepDone)
        return 0;
    FIELD_EVENT_CHECK_UpdateWalkFriendship(input->gameData, fieldMap);
    result = FIELD_EVENT_CHECK_CheckZoneStepMessage(gameSystem, fieldMap, input->zoneId);
    if (result != 0)
        return result;
    result = FIELD_EVENT_CHECK_CheckEggHatch(input, fieldMap, gameSystem, gameData);
    if (result != 0)
        return result;
    result = FIELD_EVENT_CHECK_CheckSaveFlagMessage(fieldMap, gameSystem, gameData);
    if (result == 0)
        return 0;
    return result;
}


/*
 * Returns 2 when a non-egg party member holds item 0x31 or 0x28, else 1.
 */
int FIELD_EVENT_CHECK_GetEggCycleDecrement(void *party)
{
    int memberCount = POKEPARTY_GetCount(party);
    int index;

    for (index = 0; index < memberCount; index++) {
        void *member = POKEPARTY_GetMember(party, index);
        u32 heldItem = func_02017E1C(member, 0xA, 0);
        if (func_02017E1C(member, 0x4C, 0) == 0 && (heldItem == 0x31 || heldItem == 0x28))
            return 2;
    }
    return 1;
}


/*
 * For every egg in the party, lowers field 9 (the step counter) by the amount
 * from FIELD_EVENT_CHECK_GetEggCycleDecrement, clamping at zero.
 */
void FIELD_EVENT_CHECK_DecrementEggCycles(void *party)
{
    int memberCount = POKEPARTY_GetCount(party);
    u32 decrement = FIELD_EVENT_CHECK_GetEggCycleDecrement(party);
    int index;

    for (index = 0; index < memberCount; index++) {
        void *member = POKEPARTY_GetMember(party, index);
        u32 isEgg = func_02017E1C(member, 0x4C, 0);
        u32 eggCycles = func_02017E1C(member, 9, 0);
        if (isEgg == 1) {
            u32 newCycles = 0;
            if (eggCycles >= decrement)
                newCycles = eggCycles - decrement;
            POKE_TOOL_SetPartyValue(member, 9, newCycles);
        }
    }
}


/*
 * Adds GPOWER_ApplyHatchRate(0x100) to the step accumulator in the save block; once
 * it passes 0x10000 it advances the party's egg counters (FIELD_EVENT_CHECK_DecrementEggCycles) and
 * resets it.
 */
void FIELD_EVENT_CHECK_UpdateEggStepCounter(void *gameData, void *party)
{
    void *stepSave = func_02008854(GAME_DATA_GetSaveControl(gameData));
    u32 stepCounter;

    func_02008970(stepSave, &stepCounter);
    stepCounter += GPOWER_ApplyHatchRate(0x100);
    if (stepCounter > 0x10000) {
        FIELD_EVENT_CHECK_DecrementEggCycles(party);
        stepCounter = 0;
    }
    func_0200896C(stepSave, stepCounter);
}


/*
 * Returns 1 when some egg in the party has field 9 (the step counter) at
 * zero.
 */
int FIELD_EVENT_CHECK_IsEggReadyToHatch(void *party)
{
    int memberCount = POKEPARTY_GetCount(party);
    int index;

    for (index = 0; index < memberCount; index++) {
        void *member = POKEPARTY_GetMember(party, index);
        u32 isEgg = func_02017E1C(member, 0x4C, 0);
        u32 eggCycles = func_02017E1C(member, 9, 0);
        if (isEgg == 1 && eggCycles == 0)
            return 1;
    }
    return 0;
}


/*
 * Step hook: updates SODATEYA_AddStep, advances the party step counter
 * (FIELD_EVENT_CHECK_UpdateEggStepCounter) and, when an egg is ready (FIELD_EVENT_CHECK_IsEggReadyToHatch), shows message
 * 0x8CA.
 */
int FIELD_EVENT_CHECK_CheckEggHatch(FieldEventInput *input, FieldMap *fieldMap, void *gameSystem, void *gameData)
{
    u16 heapId = FIELDMAP_GetHeapId(fieldMap);
    void *party = func_02012934(gameData);

    SODATEYA_AddStep(FIELDMAP_GetSodateya(fieldMap));
    FIELD_EVENT_CHECK_UpdateEggStepCounter(gameData, party);
    if (FIELD_EVENT_CHECK_IsEggReadyToHatch(party))
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)gameSystem, 0x8CA, 0, heapId);
    return 0;
}


/*
 * Bumps a 7-bit counter in the save block; when it wraps, calls NATSUKI_CalcWalk
 * on every party member with the two coordinates read from the position
 * object.
 */
void FIELD_EVENT_CHECK_UpdateWalkFriendship(void *gameData, FieldMap *fieldMap)
{
    void *walkSave = func_02008854(GAME_DATA_GetSaveControl(gameData));
    int counterWrapped = 0;
    u16 walkCount = func_02008978(walkSave) + 1;

    if (walkCount >= 0x80) {
        walkCount = 0;
        counterWrapped = 1;
    }
    func_02008980(walkSave, walkCount);
    if (counterWrapped) {
        void *party = func_02012934(gameData);
        int zoneId;
        int heapId;
        int memberCount;
        int index;

        zoneId = FIELDMAP_GetZoneId(fieldMap);
        heapId = FIELDMAP_GetHeapId(fieldMap);
        memberCount = POKEPARTY_GetCount(party);
        for (index = 0; index < memberCount; index++)
            NATSUKI_CalcWalk(POKEPARTY_GetMember(party, index), zoneId, heapId);
    }
}


/*
 * When ZONEDATA_IsZoneInTableDFB8 accepts the id, shows the milestone message
 * (SCRCMD_ShowStepMilestoneMessage) and increments the save block counter; returns the message
 * result.
 */
int FIELD_EVENT_CHECK_CheckZoneStepMessage(void *gameSystem, FieldMap *fieldMap, u16 zoneId)
{
    void *stepSave = func_02008854(GAME_DATA_GetSaveControl(func_020120F4(gameSystem)));
    int result = 0;

    if (ZONEDATA_IsZoneInTableDFB8(zoneId)) {
        result = SCRCMD_ShowStepMilestoneMessage(gameSystem, fieldMap);
        func_02008988(stepSave, func_02008990(stepSave) + 1);
    }
    return result;
}


int FIELD_EVENT_CHECK_CheckSaveFlagMessage(FieldMap *fieldMap, void *gameSystem, void *gameData)
{
    if ((u8)MOVE_POKEMON_SAVE_TickCooldown(MOVE_POKEMON_SAVE_GetBlock(GAME_DATA_GetSaveControl(gameData))))
        return (int)SCRIPT_SYS_CreateScriptEventSimple((int)gameSystem, 0x2792, 0, FIELDMAP_GetHeapId(fieldMap));
    return 0;
}


/*
 * Runs EFFECT_ENCOUNT_TriggerSpot on the position's object; when it declines, calls
 * EFFECT_ENCOUNT_OnPlayerStep and returns 0.
 */
int FIELD_EVENT_CHECK_CheckStepEncount(FieldMap *fieldMap, void *gameSystem, void *gameData)
{
    void *encount;
    int result;

    GAME_DATA_GetSaveControl(gameData);
    encount = (void *)FIELDMAP_GetEncount(fieldMap);
    result = EFFECT_ENCOUNT_TriggerSpot(encount);
    if (result == 0) {
        EFFECT_ENCOUNT_OnPlayerStep(encount);
        return 0;
    }
    return result;
}


struct GameEvent *FIELD_EVENT_CHECK_CreateGPowerExpireEvent(void *gameSystem)
{
    if (GPOWER_GetExpiringPowerId() == 0x30) {
        return 0;
    }
    return GAME_EVENT_CreateOverlayEvent(gameSystem, (u32)abs_id_83, (u32 (*)(void *, u32))GPOWER_EVENT_CreateTimeoutScriptEvent, 0);
}


/*
 * For a usable entry id (FIELD_EVENT_CHECK_FindGridConnectId), unless ov010 EVENTDATA_SYSTEM_IsConnectDisabled reports
 * kind 1 or FIELD_EVENT_CHECK_IsConnectOnFootType rejects it, builds its record (FIELD_EVENT_CHECK_SetEntranceFromGridConnect) and
 * dispatches it (FIELD_EVENT_CHECK_StartConnectEvent).
 */
int FIELD_EVENT_CHECK_CheckGridConnect(FieldEventInput *input, FieldMap *fieldMap, VecFx32 *pos)
{
    u32 connectId = FIELD_EVENT_CHECK_FindGridConnectId(input, pos);
    void *connect;

    if (connectId == 0xFFFF)
        return 0;
    connect = EVENTDATA_SYSTEM_GetConnectData(input->eventData, (u16)connectId);
    if (EVENTDATA_SYSTEM_IsConnectDisabled(connect) == 1 || !FIELD_EVENT_CHECK_IsConnectOnFootType(connect))
        return 0;
    FIELD_EVENT_CHECK_SetEntranceFromGridConnect(input, connectId, pos);
    return FIELD_EVENT_CHECK_StartConnectEvent(input, fieldMap, connectId, pos);
}


/*
 * Looks up the tile attribute under the position and starts the matching tile
 * task (FIELD_TILE_MOVE_StartSpinTask or FIELD_TILE_MOVE_StartSlideTask); returns the task or 0.
 */
void *FIELD_EVENT_CHECK_CheckTileMoveTask(FieldEventInput *input, FieldMap *fieldMap)
{
    int playerVec[3];
    u16 tileAttr;

    FIELD_PLAYER_GetPos(input->player, (VecFx32 *)playerVec);
    tileAttr = MAP_ATTR_GetTerrainId(MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(fieldMap), playerVec));
    if (FIELD_TILE_MOVE_IsSpinTile(tileAttr))
        return FIELD_TILE_MOVE_StartSpinTask(0, input->gameSystem, fieldMap);
    if (FIELD_TILE_MOVE_IsSlideTile(tileAttr))
        return FIELD_TILE_MOVE_StartSlideTask(0, input->gameSystem, fieldMap);
    return 0;
}


/*
 * Looks up entry id through EVENTDATA_SYSTEM_GetConnectData, optionally resolves its argument,
 * then dispatches to ov020 EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate for kind 6 or EVENT_MAPCHANGE_CreateExitWarpEvent
 * otherwise.
 */
int FIELD_EVENT_CHECK_StartConnectEvent(FieldEventInput *input, FieldMap *fieldMap, int connectId, VecFx32 *pos)
{
    void *connect = EVENTDATA_SYSTEM_GetConnectData(input->eventData, (u16)connectId);
    void *exitOffset;

    if (pos != 0)
        exitOffset = (void *)EVENTDATA_SYSTEM_GetConnectGridExitOffset(connect, pos);
    else
        exitOffset = 0;
    if (EVENTDATA_SYSTEM_GetConnectExitType(connect) == 6)
        return (int)EVENT_MAPCHANGE_CreateExitWarpEventNoEntranceUpdate(input->gameSystem, (int)fieldMap, (int)connect, (int)exitOffset);
    else
        return (int)EVENT_MAPCHANGE_CreateExitWarpEvent(input->gameSystem, (int)fieldMap, (int)connect, (int)exitOffset);
}


/*
 * Builds a 0x1C byte rectangle record with ZONEDATA_SetExitLocation from the object's
 * map value, an id and three words, and hands it to func_02012878.
 */
void FIELD_EVENT_CHECK_SetEntranceFromGridConnect(FieldEventInput *input, int connectId, VecFx32 *pos)
{
    u8 location[0x1C];

    ZONEDATA_SetExitLocation(location, FIELDMAP_GetZoneId(input->fieldMap), connectId, 0, 0, pos->x, pos->y, pos->z);
    func_02012878(input->gameData, (const void *)location);
}


/*
 * Returns the current entry id from EVENTDATA_SYSTEM_SearchConnectIdByGridPos when it is usable
 * (FIELD_EVENT_CHECK_IsConnectOnFootType or FIELD_EVENT_CHECK_IsConnectExitDir accepts it), else 0xFFFF.
 */
u32 FIELD_EVENT_CHECK_FindGridConnectId(FieldEventInput *input, VecFx32 *pos)
{
    u32 connectId = (u32)EVENTDATA_SYSTEM_SearchConnectIdByGridPos(input->eventData, pos);
    void *connect;

    if (connectId == 0xFFFF)
        return 0xFFFF;
    connect = EVENTDATA_SYSTEM_GetConnectData(input->eventData, (u16)connectId);
    if (!FIELD_EVENT_CHECK_IsConnectOnFootType(connect) && !FIELD_EVENT_CHECK_IsConnectExitDir(connect, input->facingDir))
        return 0xFFFF;
    return connectId;
}


void FIELD_EVENT_CHECK_GetFrontPos(FieldEventInput *input, VecFx32 *out)
{
    *out = *input->playerPos;
    switch (input->facingDir) {
    case 0:
        out->z -= 0x10000;
        break;
    case 1:
        out->z += 0x10000;
        break;
    case 2:
        out->x -= 0x10000;
        break;
    case 3:
        out->x += 0x10000;
        break;
    }
}


/*
 * True when EVENTDATA_SYSTEM_GetConnectExitType reports kind 0, 5 or 6.
 */
int FIELD_EVENT_CHECK_IsConnectOnFootType(void *connect)
{
    u8 exitType = EVENTDATA_SYSTEM_GetConnectExitType(connect);
    return exitType == 0 || exitType == 5 || exitType == 6;
}


int FIELD_EVENT_CHECK_IsConnectExitDir(void *connect, int dir)
{
    return EVENTDATA_SYSTEM_IsConnectExitDir(connect, dir);
}


int FIELD_EVENT_CHECK_CheckGridConnectFront(FieldEventInput *input, int unused, FieldMap *fieldMap)
{
    VecFx32 frontPos;
    int connectId;
    void *connect;

    FIELD_EVENT_CHECK_GetFrontPos(input, &frontPos);
    if ((MAP_ATTR_GetFlags(MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(fieldMap), &frontPos)) & 1) == 0)
        return 0;
    connectId = (int)FIELD_EVENT_CHECK_FindGridConnectId(input, input->playerPos);
    if (connectId != 0xFFFF) {
        connect = EVENTDATA_SYSTEM_GetConnectData(input->eventData, (u16)connectId);
        if (EVENTDATA_SYSTEM_IsConnectDisabled(connect) == 0 && EVENTDATA_SYSTEM_GetConnectExitType(connect) == 1) {
            FIELD_EVENT_CHECK_SetEntranceFromGridConnect(input, connectId, input->playerPos);
            return FIELD_EVENT_CHECK_StartConnectEvent(input, fieldMap, connectId, input->playerPos);
        }
    }
    connectId = (int)FIELD_EVENT_CHECK_FindGridConnectId(input, &frontPos);
    if (connectId != 0xFFFF) {
        if (EVENTDATA_SYSTEM_IsConnectDisabled(EVENTDATA_SYSTEM_GetConnectData(input->eventData, (u16)connectId)) == 0) {
            FIELD_EVENT_CHECK_SetEntranceFromGridConnect(input, connectId, input->playerPos);
            return FIELD_EVENT_CHECK_StartConnectEvent(input, fieldMap, connectId, &frontPos);
        }
    }
    return 0;
}


int FIELD_EVENT_CHECK_CheckFrontTileEvents(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap)
{
    VecFx32 frontPos;
    VecFx32 aheadPos;
    int aheadHeight;
    u32 frontAttr;
    void *playerMmdl;

    FIELD_EVENT_CHECK_GetFrontPos(input, &frontPos);
    if (FIELD_GIMMICK_IsGimmickId(fieldMap, 6))
        return FIELD_GIMMICK_PLATE_DOORS_StartDoorEvent((int)gameSystem, frontPos.x / 0x10000, frontPos.z / 0x10000);
    if (FIELD_GIMMICK_IsGimmickId(fieldMap, 0x19) || FIELD_GIMMICK_IsGimmickId(fieldMap, 0x1A) || FIELD_GIMMICK_IsGimmickId(fieldMap, 0x1B))
        return FIELD_GIMMICK_D06_CheckPushStone((int)fieldMap, input->facingDir);
    frontAttr = MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(fieldMap), &frontPos);
    if ((MAP_ATTR_GetFlags(frontAttr) & 1) == 0)
        return 0;
    if (FIELD_PLAYER_GetFormCode(input->player) == 2 && FIELD_EVENT_CHECK_FindPartyMemberWithMove(input->gameData, 0x7F) != 6
        && MAP_ATTR_IsWaterfall(MAP_ATTR_GetTerrainId(frontAttr)) == 1) {
        aheadPos = frontPos;
        playerMmdl = FIELD_PLAYER_GetMmdl(input->player);
        FLDMMDL_MOVE_AddDirVector(input->facingDir, (int *)(&aheadPos), 0x10000);
        if (FLDMMDL_MOVE_GetMapHeight(playerMmdl, &aheadPos, &aheadHeight) == 1 && frontPos.y > aheadHeight)
            return (int)SCRIPT_SYS_CreateScriptEventSimple((int)input->gameSystem, 0x271F, 0, input->heapId);
    }
    if (FIELD_EVENT_CHECK_FindGridConnectId(input, &frontPos) == 0xFFFF) {
        if (FIELD_GIMMICK_IsGimmickId(fieldMap, 2))
            return FIELD_GIMMICK_CART_LANES_CheckRideEvent(gameSystem);
        if (FIELD_GIMMICK_IsGimmickId(fieldMap, 5))
            return FIELD_GIMMICK_CANNONS_CreateLaunchEvent(gameSystem);
    }
    return 0;
}


int FIELD_EVENT_CHECK_CheckRailConnect(FieldEventInput *input, void *unused, FieldMap *fieldMap)
{
    RailLocation nextLocation;
    int connectId;
    void *connect;

    FLDMMDL_RAIL_GetNextLocation(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), &nextLocation);
    connectId = EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(input->eventData, &nextLocation);
    if (connectId == 0xFFFF)
        return 0;
    connect = EVENTDATA_SYSTEM_GetConnectData(input->eventData, (u16)connectId);
    if (EVENTDATA_SYSTEM_IsConnectDisabled(connect) == 1 || FIELD_EVENT_CHECK_IsConnectOnFootType(connect) == 0)
        return 0;
    FIELD_EVENT_CHECK_SetEntranceFromRailConnect(input, connectId, &nextLocation);
    return FIELD_EVENT_CHECK_StartRailConnectEvent(input, fieldMap, connectId, &nextLocation);
}


int FIELD_EVENT_CHECK_CheckRailConnectFront(FieldEventInput *input, void *unused, FieldMap *fieldMap, RailLocation *frontLocation)
{
    RailLocation nextLocation;
    int connectId;
    void *connect;

    FLDMMDL_RAIL_GetNextLocation(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(fieldMap)), &nextLocation);
    connectId = EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(input->eventData, &nextLocation);
    if (connectId != 0xFFFF) {
        connect = EVENTDATA_SYSTEM_GetConnectData(input->eventData, (u16)connectId);
        if (EVENTDATA_SYSTEM_IsConnectDisabled(connect) == 0 && FIELD_EVENT_CHECK_IsConnectExitDir(connect, input->facingDir) != 0
            && EVENTDATA_SYSTEM_GetConnectExitType(connect) == 1) {
            FIELD_EVENT_CHECK_SetEntranceFromRailConnect(input, connectId, &nextLocation);
            return FIELD_EVENT_CHECK_StartRailConnectEvent(input, fieldMap, connectId, &nextLocation);
        }
    }
    connectId = EVENTDATA_SYSTEM_SearchConnectIdByRailLocation(input->eventData, frontLocation);
    if (connectId == 0xFFFF)
        return 0;
    connect = EVENTDATA_SYSTEM_GetConnectData(input->eventData, (u16)connectId);
    if (EVENTDATA_SYSTEM_IsConnectDisabled(connect) == 0 && FIELD_EVENT_CHECK_IsConnectExitDir(connect, input->facingDir) != 0) {
        FIELD_EVENT_CHECK_SetEntranceFromRailConnect(input, connectId, &nextLocation);
        return FIELD_EVENT_CHECK_StartRailConnectEvent(input, fieldMap, connectId, &nextLocation);
    }
    return 0;
}


/*
 * When bit 3 of the flag word is set, runs the object's interaction:
 * FIELD_ENCOUNT_CheckWfbcEncount with the map value when ZONEDATA_IsZoneInTableDFC0 accepts field 0x10,
 * else FIELD_ENCOUNT_CheckWildEncount(obj, 0).
 */
int FIELD_EVENT_CHECK_CheckWildEncount(FieldEventInput *input, void *unused, FieldMap *fieldMap)
{
    void *encount = (void *)FIELDMAP_GetEncount(fieldMap);

    if (!input->stepDone)
        return 0;
    if (ZONEDATA_IsZoneInTableDFC0(input->zoneId))
        return FIELD_ENCOUNT_CheckWfbcEncount(encount, FIELD_G3D_MAPPER_GetWfbc((u8 *)FIELDMAP_GetG3dMapper(fieldMap)));
    return FIELD_ENCOUNT_CheckWildEncount(encount, 0);
}


int FIELD_EVENT_CHECK_CheckRailSignBoard(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap)
{
    void *player = FIELDMAP_GetFieldPlayer(fieldMap);
    void *playerMmdl = FIELD_PLAYER_GetMmdl(player);
    int inputDir = FIELD_PLAYER_ChooseMoveDirFromKeys(player, input->keyCont);

    if (inputDir == 1) {
        int moveState = input->moveState;
        if (moveState == 0 || moveState == 3) {
            if (RAIL_ATTR_IsSignBoard(MAP_ATTR_GetTerrainId(input->tileAttr))) {
                if (FLDMMDL_RAIL_GetHitBitsDirNoAttr((u32)playerMmdl, inputDir) & 3)
                    return RAIL_SLIPDOWN_StartAtPlayer((u32)gameSystem, (u32)fieldMap, inputDir);
            }
        }
    }
    return 0;
}


void FIELD_EVENT_CHECK_SetEntranceFromRailConnect(FieldEventInput *input, int connectId, RailLocation *location)
{
    u8 locationRec[0x1C];

    ZONEDATA_SetExitRailLocation(locationRec, FIELDMAP_GetZoneId(input->fieldMap), (s16)connectId, 0, 0, location->railIndex, location->lineGrid, location->widthGrid);
    func_02012878(input->gameData, (const void *)locationRec);
}


int FIELD_EVENT_CHECK_StartRailConnectEvent(FieldEventInput *input, FieldMap *fieldMap, int connectId, RailLocation *location)
{
    void *connect = EVENTDATA_SYSTEM_GetConnectData(input->eventData, (u16)connectId);
    return (int)EVENT_MAPCHANGE_CreateExitWarpEvent(input->gameSystem, (int)fieldMap, (int)connect, EVENTDATA_SYSTEM_GetConnectRailExitOffset(connect, location));
}


int FIELD_EVENT_CHECK_IsRailFrontFree(void *player, FieldEventInput *input)
{
    if ((FLDMMDL_RAIL_GetHitBitsDirNoAttr((u32)FIELD_PLAYER_GetMmdl(player), input->facingDir) & 3) == 0)
        return 1;
    return 0;
}


int FIELD_EVENT_CHECK_LedgeJumpTaskMain(void *task, int *seq, LedgeJumpWork *work)
{
    void *player = FIELDMAP_GetFieldPlayer(work->fieldMap);
    void *playerMmdl;
    int acmdCode;

    FIELD_PLAYER_GetFormCode(player);
    playerMmdl = FIELD_PLAYER_GetMmdl(player);
    switch (*seq) {
    case 0:
        FLDMMDL_SysPauseMove(FLDMMDL_GetMmdlSys(playerMmdl));
        FLDMMDL_SetDirDispCheckPause((int)playerMmdl, work->dir);
        *seq = *seq + 1;
        break;
    case 1:
        FLDEFF_NAMIPOKE_SetFollowMode((u32)FIELD_PLAYER_GetRideEffect(player), 0);
        FIELD_PLAYER_StartFormChange(player, 1);
        FIELD_PLAYER_FinishFormChange(player);
        acmdCode = FLDMMDL_ACMD_ConvertCodeByDir(work->dir, 0x34);
        if (work->jumpTwoTiles == 1)
            acmdCode = FLDMMDL_ACMD_ConvertCodeByDir(work->dir, 0x38);
        FLDMMDL_SetAcmd(playerMmdl, acmdCode);
        *seq = *seq + 1;
        break;
    case 2:
        if (FLDMMDL_CheckEndAcmd(playerMmdl) == 1) {
            FIELD_PLAYER_ChangeToNormalForm(player);
            *seq = *seq + 1;
        }
        break;
    case 3:
        FLDMMDL_SysResumeMove(FLDMMDL_GetMmdlSys(playerMmdl));
        FIELD_PLAYER_SetGridMoveState(player, 1);
        return 1;
    }
    return 0;
}


int FIELD_EVENT_CHECK_CreateLedgeJumpTask(int unused, void *gameSystem, FieldMap *fieldMap, int dir, int jumpTwoTiles)
{
    int h = (int)func_020122C0((void *)gameSystem, 0, FIELD_EVENT_CHECK_LedgeJumpTaskMain, 0x10);
    LedgeJumpWork *work = func_020124E8((void *)h);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->dir = dir;
    work->jumpTwoTiles = jumpTwoTiles;
    return h;
}


int FIELD_EVENT_CHECK_CheckLedgeJump(FieldEventInput *input, void *gameSystem, FieldMap *fieldMap)
{
    void *g3dMapper;
    int inputDir;
    int frontTile;
    int jumpTwoTiles;
    int frontAttr;
    void *player;
    int frontHitBits;
    int frontPos[3];

    player = FIELDMAP_GetFieldPlayer(fieldMap);
    if (FIELD_PLAYER_GetFormCode(player) == 2) {
        g3dMapper = (void *)FIELDMAP_GetG3dMapper(fieldMap);
        inputDir = FIELD_PLAYER_ChooseMoveDirFromKeys((u8 *)(*(int *)&input->player), input->keyCont);
        if (inputDir != 9) {
            FIELD_PLAYER_GetPosInDir(player, inputDir, frontPos);
            frontTile = MAP_ATTR_GetAt(g3dMapper, frontPos);
            frontHitBits = MAP_ATTR_GetFlags(frontTile);
            frontAttr = MAP_ATTR_GetTerrainId(frontTile);
            jumpTwoTiles = 0;
            if (MAP_ATTR_IsLongHopEdge(frontAttr) == 1) {
                FLDMMDL_MOVE_AddDirVector(inputDir, frontPos, 0x10000);
                frontHitBits = MAP_ATTR_GetFlags(MAP_ATTR_GetAt(g3dMapper, frontPos));
                jumpTwoTiles = 1;
            }
            if (FIELD_EVENT_CHECK_IsLedgePathClear(input, fieldMap) == 1 && !(frontHitBits & 1) && !(frontHitBits & 2))
                return FIELD_EVENT_CHECK_CreateLedgeJumpTask((int)input, gameSystem, fieldMap, inputDir, jumpTwoTiles);
        }
    }
    return 0;
}


/*
 * Reads the object's grid position, and when the tile attribute in front
 * allows it (MAP_ATTR_IsCameraStep) steps it one tile in its facing direction, then
 * moves the camera object there (FLDMMDL_SysSearchGridPosHeight).
 */
int FIELD_EVENT_CHECK_SearchGridFrontMmdl(FieldEventInput *input, FieldMap *fieldMap)
{
    void *playerMmdl = FIELD_PLAYER_GetMmdl(input->player);
    s16 gridPos[3];
    int worldPos[3];
    void *mmdlSys;

    FIELD_PLAYER_GetFrontGridPos((u32)input->player, (u32)(&gridPos[2]), (u32)(&gridPos[1]), (u32)(&gridPos[0]));
    FLDMMDL_MOVE_GridToVector(gridPos[2], gridPos[1], gridPos[0], worldPos);
    if (MAP_ATTR_IsCameraStep(MAP_ATTR_GetTerrainId(MAP_ATTR_GetAt((void *)FIELDMAP_GetG3dMapper(fieldMap), worldPos))) == 1)
        FLDMMDL_MOVE_AddDirGrid(FLDMMDL_GetDirDisp(playerMmdl), &gridPos[2], &gridPos[0], 1);
    mmdlSys = FIELDMAP_GetMmdlSys(fieldMap);
    return (int)FLDMMDL_SysSearchGridPosHeight((u32)mmdlSys, gridPos[2], gridPos[0], FLDMMDL_GetPosY(playerMmdl), 0x10000, 0);
}


int FIELD_EVENT_CHECK_SearchRailFrontMmdl(FieldEventInput *input, FieldMap *fieldMap)
{
    RailLocation frontLocation;
    if (FLDMMDL_RAIL_GetFrontLocation(FIELD_PLAYER_GetMmdl(input->player), &frontLocation) != 0)
        return FLDMMDL_RAIL_SearchMmdlByLocation((u32)FIELDMAP_GetMmdlSys(fieldMap), (u32)&frontLocation, 0);
    return 0;
}


/*
 * Picks the message for the tile the player faces: the first of the 13 table
 * entries at 0x021D3CE8 whose direction matches and whose attribute test
 * passes, else the water prompts 0x2712 (when a party member knows Surf) or
 * 0x2716; 0xFFFF for none.
 */
u16 FIELD_EVENT_CHECK_GetFrontTileMessage(FieldEventInput *input, FieldMap *fieldMap)
{
    u32 tileAttrHere;
    u32 tileAttrAhead;
    u16 aheadBehavior;
    u32 index;

    if (func_02012B70(input->gameData) == 1)
        return 0xFFFF;
    tileAttrHere = FIELD_PLAYER_GetNowAttribute(input->player);
    tileAttrAhead = FIELD_PLAYER_GetFrontAttribute(input->player, input->facingDir);
    aheadBehavior = MAP_ATTR_GetTerrainId(tileAttrAhead);
    for (index = 0; index < 13; index++) {
        if ((input->facingDir == data_021D3CE8[index].dir || data_021D3CE8[index].dir == 9) && data_021D3CE8[index].test(aheadBehavior))
            return data_021D3CE8[index].scriptId;
    }
    if (!ZONEDATA_IsNormalFieldZone(input->zoneId) || func_02012B70(input->gameData) == 1)
        return 0xFFFF;
    if (FIELD_PLAYER_CheckEncountAttr(input->player, tileAttrHere, tileAttrAhead) && FIELD_EVENT_CHECK_FindPartyMemberWithMove(input->gameData, 0x39) != 6)
        return 0x2712;
    if (FIELD_PLAYER_CheckSurfEntryAttr(input->player, (u32)tileAttrHere, (u32)tileAttrAhead))
        return 0x2716;
    return 0xFFFF;
}


/*
 * Returns the index of the first non-egg party member that knows the given
 * move (checks move slots 0x36..0x39), or 6 when none does. Called with 0x39
 * (Surf).
 */
int FIELD_EVENT_CHECK_FindPartyMemberWithMove(void *gameData, u32 move)
{
    int memberCount;
    void *party;
    int index;

    party = func_02012934(gameData);
    memberCount = POKEPARTY_GetCount(party);

    for (index = 0; index < memberCount; index++) {
        void *member = POKEPARTY_GetMember(party, index);

        if (func_02017E1C(member, 0x4C, 0) == 0) {
            if (move == func_02017E1C(member, 0x36, 0) || move == func_02017E1C(member, 0x37, 0)
                || move == func_02017E1C(member, 0x38, 0) || move == func_02017E1C(member, 0x39, 0))
                return index;
        }
    }
    return 6;
}


int FIELD_EVENT_CHECK_CountAlivePartyMembers(void *gameSystem)
{
    void *party;
    void *member;
    int memberCount;
    int index;
    int aliveCount;

    party = func_02012934(func_020120F4(gameSystem));
    memberCount = POKEPARTY_GetCount(party);
    index = 0;
    aliveCount = 0;
    for (; index < memberCount; index++) {
        member = POKEPARTY_GetMember(party, index);
        if (func_02017E1C(member, 0x4C, 0) == 0 && func_02017E1C(member, 0xA0, 0) != 0)
            aliveCount++;
    }
    return aliveCount;
}


int FIELD_EVENT_CHECK_IsLedgePathClear(FieldEventInput *input, FieldMap *fieldMap)
{
    void *playerMmdl = FIELD_PLAYER_GetMmdl(input->player);
    u16 heldDir = input->heldDir;
    int gridX = FLDMMDL_GetGridNowX(playerMmdl);
    int gridZ = FLDMMDL_GetGridNowZ(playerMmdl);
    int index;

    for (index = 0; index < 2; index++) {
        gridX = (s16)(gridX + FLDMMDL_MOVE_GetDirAddGridX(heldDir));
        gridZ = (s16)(gridZ + FLDMMDL_MOVE_GetDirAddGridZ(heldDir));
        if (FLDMMDL_SysSearchGridPos((u32)FIELDMAP_GetMmdlSys(fieldMap), gridX, gridZ, 1))
            return 0;
    }
    return 1;
}
