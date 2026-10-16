/*
 * file:     event_comm_common.c
 * unit:     yes
 * function: EVENT_COMM_COMMON_InitMsgBox, EVENT_COMM_COMMON_ExitMsgBox, EVENT_COMM_COMMON_SetupPrintWin, EVENT_COMM_COMMON_DeletePrintWin, EVENT_COMM_COMMON_PrintText, EVENT_COMM_COMMON_PrintMsg, EVENT_COMM_COMMON_ClearPrintWin, EVENT_COMM_COMMON_IsPrintFinished, EVENT_COMM_COMMON_IsKeyTrg, EVENT_COMM_COMMON_SetupListWindow, EVENT_COMM_COMMON_DeleteListWindow, EVENT_COMM_COMMON_PrintToWindow, EVENT_COMM_COMMON_PrintListWindow, EVENT_COMM_COMMON_DeleteChoice, EVENT_COMM_COMMON_StartChoice, EVENT_COMM_COMMON_PollChoice, EVENT_COMM_COMMON_SetupListWindowB, EVENT_COMM_COMMON_PrintListWindowB, EVENT_COMM_COMMON_DeleteListWindowB, EVENT_COMM_COMMON_GetMissionState, EVENT_COMM_COMMON_GetPeerTalkStatus, EVENT_COMM_COMMON_CmdCallExitSyncEvent, EVENT_COMM_COMMON_CreateExitSyncEvent, EVENT_COMM_COMMON_ExitSyncEventMain, EVENT_COMM_COMMON_CmdGetObjCode, EVENT_COMM_COMMON_CmdCheckMissionInfoPending, EVENT_COMM_COMMON_CmdCallMissionInfoEvent, EVENT_COMM_COMMON_CreateMissionInfoEvent, EVENT_COMM_COMMON_MissionInfoEventMain, EVENT_COMM_COMMON_FreeMissionInfoWork, EVENT_COMM_COMMON_CreateReturnPalaceEvent, EVENT_COMM_COMMON_ReturnPalaceEventMain, EVENT_COMM_COMMON_CmdGetIntrudeDistance, EVENT_COMM_COMMON_CmdCheckBattleRecState, EVENT_COMM_COMMON_CreateTalkStartEvent, EVENT_COMM_COMMON_TalkStartEventMain, EVENT_COMM_COMMON_CreateTalkEvent, EVENT_COMM_COMMON_CreateTalkedStartEvent, EVENT_COMM_COMMON_TalkedStartEventMain, EVENT_COMM_COMMON_CreateTalkedEvent, EVENT_COMM_COMMON_InitCommonWork, EVENT_COMM_COMMON_ExitCommonWork, EVENT_COMM_COMMON_TalkEventMain, EVENT_COMM_COMMON_TalkedEventMain, EVENT_COMM_COMMON_ChangeTalkTypeEvent, EVENT_COMM_COMMON_ChangeTalkedTypeEvent, EVENT_COMM_COMMON_GetTalkType, EVENT_COMM_COMMON_CreateMissionResultEvent, EVENT_COMM_COMMON_MissionResultEventMain, EVENT_COMM_COMMON_ChangeTalkMsgEvent, EVENT_COMM_COMMON_TalkMsgEventMain, EVENT_COMM_COMMON_ChangeTalkedMsgEvent, EVENT_COMM_COMMON_ChangeTalkPowerGiftTargetEvent, EVENT_COMM_COMMON_TalkPowerGiftTargetEventMain, EVENT_COMM_COMMON_ChangeTalkPowerGiftAsTargetEvent, EVENT_COMM_COMMON_TalkPowerGiftAsTargetEventMain, EVENT_COMM_COMMON_ChangeTalkedPowerGiftAsTargetEvent, EVENT_COMM_COMMON_TalkedPowerGiftAsTargetEventMain, EVENT_COMM_COMMON_ChangeTalkedPowerGiftTargetEvent, EVENT_COMM_COMMON_TalkedPowerGiftTargetEventMain, EVENT_COMM_COMMON_ChangeTalkPowerShareTargetEvent, EVENT_COMM_COMMON_TalkPowerShareTargetEventMain, EVENT_COMM_COMMON_ChangeTalkPowerShareAsTargetEvent, EVENT_COMM_COMMON_TalkPowerShareAsTargetEventMain, EVENT_COMM_COMMON_ChangeTalkedPowerShareAsTargetEvent, EVENT_COMM_COMMON_TalkedPowerShareAsTargetEventMain, EVENT_COMM_COMMON_ChangeTalkedPowerShareTargetEvent, EVENT_COMM_COMMON_TalkedPowerShareTargetEventMain, EVENT_COMM_COMMON_ChangeTalkBattleTargetEvent, EVENT_COMM_COMMON_BattleRequestEventMain, EVENT_COMM_COMMON_ChangeTalkBattleAsTargetEvent, EVENT_COMM_COMMON_BattleAnswerEventMain, EVENT_COMM_COMMON_ChangeTalkedBattleAsTargetEvent, EVENT_COMM_COMMON_ChangeTalkedBattleTargetEvent, EVENT_COMM_COMMON_ChangeTalkSearchTargetEvent, EVENT_COMM_COMMON_TalkSearchTargetEventMain, EVENT_COMM_COMMON_ChangeTalkSearchAsTargetEvent, EVENT_COMM_COMMON_TalkSearchAsTargetEventMain, EVENT_COMM_COMMON_ChangeTalkedSearchAsTargetEvent, EVENT_COMM_COMMON_TalkedSearchAsTargetEventMain, EVENT_COMM_COMMON_ChangeTalkedSearchTargetEvent, EVENT_COMM_COMMON_TalkedSearchTargetEventMain, EVENT_COMM_COMMON_ChangeSearchFoundEvent, EVENT_COMM_COMMON_SearchFoundEventMain, EVENT_COMM_COMMON_CreateSupportMsgEvent, EVENT_COMM_COMMON_SupportMsgEventMain, EVENT_COMM_COMMON_ChangeTalkGreetingTargetEvent, EVENT_COMM_COMMON_TalkGreetingTargetEventMain, EVENT_COMM_COMMON_ChangeTalkGreetingAsTargetEvent, EVENT_COMM_COMMON_TalkGreetingAsTargetEventMain, EVENT_COMM_COMMON_ChangeTalkedGreetingAsTargetEvent, EVENT_COMM_COMMON_TalkedGreetingAsTargetEventMain, EVENT_COMM_COMMON_ChangeTalkedGreetingTargetEvent, EVENT_COMM_COMMON_TalkedGreetingTargetEventMain, EVENT_COMM_COMMON_CreateOfferEvent, EVENT_COMM_COMMON_OfferEventMain, EVENT_COMM_COMMON_CreateOfferAnswerEvent, EVENT_COMM_COMMON_OfferAnswerEventMain, EVENT_COMM_COMMON_ChangeTalkItemSaleEvent, EVENT_COMM_COMMON_ItemSaleEventMain, EVENT_COMM_COMMON_ChangeTalkItemPurchaseEvent, EVENT_COMM_COMMON_ItemPurchaseEventMain, EVENT_COMM_COMMON_ChangeTalkedItemSaleEvent, EVENT_COMM_COMMON_ChangeTalkedItemPurchaseEvent, EVENT_COMM_COMMON_StartMsgEvent, EVENT_COMM_COMMON_MsgEventMain, EVENT_COMM_COMMON_StartMsgEvent95, EVENT_COMM_COMMON_StartMsgEvent105, EVENT_COMM_COMMON_StartMsgEvent110ByKindA, EVENT_COMM_COMMON_StartMsgEvent110ByKindB, EVENT_COMM_COMMON_StartMsgEvent110Alt, EVENT_COMM_COMMON_StartMsgScriptEvent, EVENT_COMM_COMMON_MsgScriptEventMain
 * address:  0x0217F2B4
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   ICA_ANIME_GetField1C  0x020120F4  thumb
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   INTRUDE_COMM_TakeRequestResult  0x02175514  thumb  ov011
 *   KEY_GetTrg  0x020362DC  arm
 *   INTRUDE_COMM_SendAnswer  0x02173B9C  thumb  ov011
 *   INTRUDE_COMM_NextRequestToken  0x021753B8  thumb  ov011
 *   INTRUDE_COMM_SendReply  0x02173AE0  thumb  ov011
 *   ICA_ANIME_GetField24  0x02012138  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   ICA_ANIME_GetField20  0x0201210C  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   func_02029830  0x02029830  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   MSGDATA_Delete  0x02045C04  arm
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   func_02030734  0x02030734  arm
 *   ICA_ANIME_GetField114  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   func_020307B0  0x020307B0  arm
 *   GAME_DATA_GetIntrudeIdByte            0x0215841C  thumb  ov010
 *   func_02034714            0x02034714  arm
 *   ZONEDATA_IsZone117  0x02013D5C  thumb
 *   INTRUDE_COMM_HasResult  0x02175DA8  thumb  ov011
 *   INTRUDE_COMM_IsSessionAccepted  0x02175B8C  thumb  ov011
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GAME_DATA_GetPlayerStatusById  0x02012950  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GAME_DATA_GetMyStatusByNetId  0x021583EC  thumb  ov010
 *   INTRUDE_COMM_SetWordSetRequest  0x021762D8  thumb  ov011
 *   INTRUDE_COMM_GetActiveSessionRequest  0x02175B34  thumb  ov011
 *   WORDSET_Create  0x0201EC74  thumb
 *   FIELD_MSGBG_DeleteMsgData  0x021904C8  thumb  ov021
 *   FIELD_MSGBG_SysWinPrintStr  0x02190EB8  thumb  ov021
 *   FIELD_MSGBG_ClearSysWin  0x02190F7C  thumb  ov021
 *   sEmptyTextMsgBox     0x02183B2C  data
 *   FIELD_MSGBG_CreateMsgWin 0x02190708 thumb ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintStr 0x02190758 thumb ov021
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu 0x02190BE4 thumb ov021
 *   FIELD_MSGBG_YesNoMenuMain 0x02190C78 thumb ov021
 *   GAME_COMM_GetGameData 0x02026478 thumb
 *   SCRCMD_WORK_GetScriptWork 0x0215A5F4 thumb ov010
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   SCRIPT_SYS_CallEvent 0x0215897C thumb ov010
 *   GAME_DATA_GetIntrudeId  0x02012B80  thumb
 *   INTRUDE_COMM_ClearSessionEntries  0x021757A8  thumb  ov011
 *   INTRUDE_FIELD_InitStartParam  0x0217BF1C  thumb  ov018
 *   FIELD_MSGBG_CreateBottomMsgWin  0x021907A8  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintMsg  0x02190740  thumb  ov021
 *   INTRUDE_CMD_SendEntryIndex  0x02173D2C  thumb  ov011
 *   INTRUDE_COMM_GetMemberNameNetId  0x02175FB4  thumb  ov011
 *   INTRUDE_COMM_SendReady  0x02173C6C  thumb  ov011
 *   INTRUDE_FIELD_GetStartKind  0x0217BF28  thumb  ov018
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   INTRUDE_FIELD_CreateOfferInfoEvent  0x0217C458  thumb  ov018
 *   GAME_EVENT_ChangeEvent  0x0201235C  thumb
 *   INTRUDE_COMM_GetRequesterNetId  0x02176230  thumb  ov011
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   INTRUDE_GetFromSave 0x0200BE48 thumb
 *   INTRUDE_GetMonolithLevel 0x0200BF10 thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   INTRUDE_COMM_InitRequest  0x0217538C  thumb  ov011
 *   INTRUDE_COMM_ClearNotice  0x02175368  thumb  ov011
 *   INTRUDE_COMM_ClearRequestOpen  0x0217545C  thumb ov011
 *   COMM_PLAYER_CheckActive  0x02167A54  thumb ov010
 *   COMM_PLAYER_GetPlayerModel 0x02167A14 thumb ov010
 *   MYSTATUS_Copy 0x02008494 thumb
 *   INTRUDE_COMM_IsSessionActive 0x02175B14 thumb ov011
 *   MI_CpuCopy8 0x02082D44 arm
 *   INTRUDE_COMM_SetState 0x02174E14 thumb ov011
 *   INTRUDE_COMM_GetRequestKind  0x02175DCC  thumb  ov011
 *   INTRUDE_COMM_GetSessionResult  0x02175BCC  thumb  ov011
 *   INTRUDE_COMM_IsRequestFromNetId  0x0217620C  thumb  ov011
 *   INTRUDE_CMD_SendReadyNotice  0x02174258  thumb  ov011
 *   INTRUDE_COMM_TakeNoticeState  0x02175C40  thumb  ov011
 *   INTRUDE_COMM_ClearRequestResult  0x0217553C  thumb  ov011
 *   INTRUDE_COMM_SendNoticeBytes  0x02173C04  thumb  ov011
 *   INTRUDE_COMM_GetNotice  0x0217537C  thumb  ov011
 *   sEventCommCommonFile   0x02183B30  data   a1
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   sEmptyTextTalkTable  0x02183B44  data ov018 a1
 *   sTalkEventTable  0x0218374C  data ov018 a4
 *   sTalkedEventTable  0x021837C4  data ov018 a4
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb ov021
 *   INTRUDE_COMM_HasResultReward  0x02175E90  thumb  ov011
 *   INTRUDE_COMM_GetPartnerTallyValid  0x021756A4  thumb  ov011
 *   INTRUDE_COMM_GetResultCount  0x02175DE4  thumb  ov011
 *   INTRUDE_AddMissionBonusScore  0x0200BE24  thumb
 *   INTRUDE_AddMissionScore  0x0200BE00  thumb
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_0200823C  0x0200823C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   INTRUDE_IncrementMissionClearCount  0x0200BF78  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   sEmptyTextResult   0x02183B48  data   ov018  a1
 *   GAME_EVENT_Change 0x0201232C thumb
 *   sTalkMsgIds     0x0218383C  data ov018 a2
 *   INTRUDE_CMD_SendProposal  0x0217405C  thumb  ov011
 *   INTRUDE_COMM_GetJoinStatus  0x02175CF4  thumb  ov011
 *   WORDSET_SetSlotFromMsgA0  0x0201F184  thumb
 *   sMissionAchieveMsgIdsA     0x02183870  data   a2
 *   sMissionAchieveMsgIdsB     0x0218387A  data   a2
 *   sMissionAchieveMsgIdsC     0x02183884  data   a2
 *   sTalkPowerGiftAsTargetMsgIds     0x02183848  data ov018 a2
 *   sTalkedPowerGiftAsTargetMsgIds     0x02183866  data ov018 a2
 *   GAME_EVENT_CreateOverlayEvent  0x020124AC  thumb
 *   GPOWER_EVENT_CreateActivateEvent  0x021F5260  thumb  ov083
 *   ov083_id       0x00000053  data
 *   sTalkedPowerGiftTargetMsgIds     0x02183852  data   a2
 *   sTalkedPowerGiftEndMsgIds     0x0218385C  data   a2
 *   sTalkPowerShareTargetMsgIds     0x021838B8  data ov018 a2
 *   sTalkPowerShareAsTargetMsgIds     0x02183890  data  a2
 *   sTalkedPowerShareAchieveMsgIdsA     0x021838A4  data  a2
 *   sTalkedPowerShareAchieveMsgIdsB     0x021838AE  data  a2
 *   sTalkedPowerShareTargetMsgIds     0x0218389A  data ov018 a2
 *   func_0215839C  0x0215839C  thumb  ov010
 *   INTRUDE_COMM_SetLock  0x021756F0  thumb
 *   INTRUDE_COMM_SendPeerFlags  0x021744D0  thumb
 *   INTRUDE_LINK_CreateEvent  0x021766CC  thumb
 *   sBattleRequestMsgIds     0x021838F6  data  a2
 *   sBattleRequestTalkedMsgIds     0x02183900  data  a2
 *   sBattleRequestAcceptedMsgIds     0x0218390A  data  a2
 *   sBattleRequestEndMsgIds     0x02183914  data  a2
 *   sBattleRequestRefusedMsgIds     0x0218391E  data  a2
 *   INTRUDE_COMM_PickEntryForKind  0x021763D8  thumb  ov011
 *   sBattleAnswerMsgIds     0x021838C4  data  a2
 *   sBattleAnswerTalkedMsgIds     0x021838CE  data  a2
 *   sBattleAnswerAcceptedMsgIds     0x021838D8  data  a2
 *   sBattleAnswerEndMsgIds     0x021838E2  data  a2
 *   sBattleAnswerRefusedMsgIds     0x021838EC  data  a2
 *   sTalkSearchTargetMsgIds     0x02183928  data  a2
 *   sTalkSearchAsTargetMsgIds     0x0218393C  data  a2
 *   sTalkedSearchAsTargetMsgIds     0x02183932  data  a2
 *   sTalkedSearchTargetMsgIds     0x02183946  data  a2
 *   INTRUDE_COMM_SendSupportMode  0x0217456C  thumb  ov011
 *   sSearchFoundMsgIdsA     0x02183950  data  a2
 *   sSearchFoundMsgIdsB     0x0218395A  data  a2
 *   sSearchFoundOtherMsgIds     0x02183964  data  a2
 *   GAME_DATA_GetPmsWork  0x02012F20  thumb
 *   MYSTATUS_Create  0x0200846C  thumb
 *   COMM_PLAYER_SUPPORT_GetActiveRecord  0x0202E82C  thumb
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   SCRIPT_SYS_GetEventScriptWork  0x021589D0  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 *   sTalkGreetingTargetMsgIds     0x02183970  data  a2
 *   sTalkGreetingAsTargetMsgIds     0x02183984  data  a2
 *   sTalkedGreetingAsTargetMsgIds     0x0218397A  data   a2
 *   sTalkedGreetingTargetMsgIds     0x0218398E  data   a2
 *   func_020084F8  0x020084F8  thumb
 *   INTRUDE_COMM_SendProfile  0x021745F8  thumb  ov011
 *   WORDSET_Callback_EF40  0x0201EF40  thumb
 *   sOfferAnswerMsgIds     0x02183998  data  a2
 *   INTRUDE_COMM_IsValidProfileCode 0x021756D0 thumb ov011
 *   sItemSaleMsgIds     0x021839E0  data  a2
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   BEACON_GetPoints  0x0200C274  thumb
 *   BEACON_SubPoints  0x0200C29C  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   sItemPurchaseMsgIds     0x021839A4  data  a2
 *   INTRUDE_SUBDISP_MainRequestAnswerSeq  0x0217C914  thumb  ov018
 *   INTRUDE_SUBDISP_CreatePalaceWarpEvent  0x0217CA1C  thumb  ov018
 *   INTRUDE_SUBDISP_CreateDisconnectEvent  0x0217CA84  thumb  ov018
 *   INTRUDE_SUBDISP_CreateTownWarpEvent  0x0217CE08  thumb  ov018
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   sEmptyTextA     0x02183B4C  data   a1
 *   sMsgIds95     0x02183A20  data   a2
 *   sMsgIds105     0x02183A38  data   a2
 *   sMsgIds110ByKindA 0x02183A80 data a2
 *   sMsgIds110ByKindB 0x02183A44 data a2
 *   sMsgIds110 0x02183A2C data a2
 *   sMsgIds110Alt 0x02183A14 data a2
 *   sEmptyTextB     0x02183B50  data   a1
 *   sMsgIds125     0x02183ABC  data   a2
 */
#include "../arm9/script_vm_types.h"
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

#include "../ov011/intrude_comm_types.h"
#include "event_comm_common_types.h"

struct GameSystem;
struct GameData;
struct GameEvent;
struct FieldMap;
struct FldMmdl;
struct ScriptWork;
struct GameComm;
struct CommPlayerWork;
struct WordSet;
typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

/*
 * Work of the message event (0xAC bytes for the plain variant, 0xA0 for the
 * script variant): the first 0x98 bytes are a copy of the work of the event
 * that starts it.
 */
typedef struct EventCommMsgWork {
    EventCommCommonWork common;     /* 0x00 */
    u32 reserved98;                 /* 0x98: variant slot; the talk and mission variants use it, this event does not */
    u16 msgId;                      /* 0x9C: message the event prints */
} EventCommMsgWork;

/* Work of the talk and talked events (0x9C bytes). */
typedef struct EventCommTalkWork {
    EventCommCommonWork common;     /* 0x00 */
    u8 answerSeq;                   /* 0x98: step of the request and answer exchange */
    u8 answer;                      /* 0x99: answer sent to the partner, 1 = yes */
} EventCommTalkWork;

/* Parameter of the talk and talked start events (0x10 bytes). */
typedef struct EventCommTalkParam {
    struct FieldMap *fieldMap;      /* 0x00 */
    struct FldMmdl *playerMmdl;     /* 0x04 */
    int netId;                      /* 0x08: net ID of the partner */
    u16 heapId;                     /* 0x0C */
} EventCommTalkParam;

/* Work of the exit sync event (0x10 bytes). */
typedef struct EventCommExitSyncWork {
    void *msgData;                  /* 0x00 */
    void *window;                   /* 0x04 */
    void *wordSet;                  /* 0x08 */
    u16 *result;                    /* 0x0C: script variable, 1 = all players are ready */
} EventCommExitSyncWork;

/* Work of the mission result event (0x138 bytes). */
typedef struct EventCommMissionResultWork {
    u16 heapId;                     /* 0x00 */
    u16 pad02;
    EventCommMsgBox msgBox;         /* 0x04 */
    int showResult;                 /* 0x34: 0 = only clear the visit, no messages */
    u8 pad38[0xEC - 0x38];
    IntrudeResultRecord result;     /* 0xEC: copy of the session result */
    u16 missionKind;                /* 0x128 */
    u16 missionPoint;               /* 0x12A */
    int hasReward;                  /* 0x12C */
    u32 rewardCount;                /* 0x130: items 0x23F given as reward */
    u8 tallyCountA;                 /* 0x134: partnerTally.countA */
    u8 tallyCountB;                 /* 0x135: partnerTally.countB */
    u16 waitFrames;                 /* 0x136 */
} EventCommMissionResultWork;

/* Work of the talk type events that end with a mission result (0xA4 bytes). */
typedef struct EventCommMissionTalkWork {
    EventCommCommonWork common;     /* 0x00 */
    int disconnected;               /* 0x98: the visit ended while the event ran */
    int achieved;                   /* 0x9C: the mission is done, show the result */
    int joinStatus;                 /* 0xA0: INTRUDE_COMM_GetJoinStatus result; 1 shows the achieve messages */
} EventCommMissionTalkWork;

/* Work of the talked event that activates a G-Power (0xA4 bytes). */
typedef struct EventCommGPowerTalkWork {
    EventCommCommonWork common;     /* 0x00 */
    u8 pad98[0xA0 - 0x98];
    int msgIndex;                   /* 0xA0: common.msgIndex kept while the text box is closed */
} EventCommGPowerTalkWork;

/* Parameter of the G-Power activation event of overlay 83 (GPOWER_EVENT_CreateActivateEvent). */
typedef struct EventCommGPowerParam {
    u32 powerId;                    /* from the mission argument; IDs above 0x2D become 0 */
    u32 arg;
} EventCommGPowerParam;

/* Parameter of the link battle event (INTRUDE_LINK_CreateEvent), 0x0C bytes. */
typedef struct EventCommBattleParam {
    struct GameSystem *gameSystem;  /* 0x00 */
    u8 partnerNetId;                /* 0x04 */
    u8 battleArg;                   /* 0x05: mission argument */
    u8 linkMode;                    /* 0x06: 2 */
    u8 pad07;
    int isTalked;                   /* 0x08: 0 = this player talked, 1 = was talked to */
} EventCommBattleParam;

/* Work of the battle request and battle answer events (0xB0 bytes). */
typedef struct EventCommBattleTalkWork {
    EventCommCommonWork common;     /* 0x00 */
    int disconnected;               /* 0x98 */
    EventCommBattleParam battle;    /* 0x9C */
    int battleDone;                 /* 0xA8 */
    int canceled;                   /* 0xAC: the player canceled the request with B */
} EventCommBattleTalkWork;

/* Work of the support message event (0x34 bytes). */
typedef struct EventCommSupportMsgWork {
    EventCommMsgBox msgBox;         /* 0x00 */
    void *myStatus;                 /* 0x30: MyStatus of the supporting player */
} EventCommSupportMsgWork;

/* Work of the offer answer event (0x54 bytes). */
typedef struct EventCommOfferWork {
    EventCommMsgBox msgBox;         /* 0x00 */
    u8 myName[0x10];                /* 0x30: name of this player, sent to the sender */
    u16 itemId;                     /* 0x40: offer param.y */
    u8 offerArg;                    /* 0x42: offer param.x */
    u8 pad43;
    u16 senderNetId;                /* 0x44 */
    u8 pad46[2];
    int disconnected;               /* 0x48 */
    int accepted;                   /* 0x4C */
    int joinStatus;                 /* 0x50: INTRUDE_COMM_GetJoinStatus result */
} EventCommOfferWork;

/* Work of the item sale and item purchase events (0xA4 bytes); member.head.param is item ID and price. */
typedef struct EventCommItemSaleWork {
    EventCommCommonWork common;     /* 0x00 */
    int disconnected;               /* 0x98 */
    int sold;                       /* 0x9C */
    int canceled;                   /* 0xA0: the player canceled the offer with B */
} EventCommItemSaleWork;

extern void MI_CpuFill8(void *dest, int value, int size);
extern struct GameData *ICA_ANIME_GetField1C(struct GameSystem *gameSystem);
extern void FLDMMDL_SetAcmd(struct FldMmdl *mmdl, int acmd);
extern void GFL_USE_PlaySeDefaultVolume(u32 seId);
extern int FLDMMDL_EndAcmd(struct FldMmdl *mmdl);
extern int INTRUDE_COMM_TakeRequestResult(IntrudeCommSys *sys);
extern u32 KEY_GetTrg(void);
extern int INTRUDE_COMM_SendAnswer(int netId, int seq);
extern void INTRUDE_COMM_NextRequestToken(IntrudeCommSys *sys);
extern int INTRUDE_COMM_SendReply(IntrudeCommSys *sys, int netId, int requestActive, int seq);
extern struct GameComm *ICA_ANIME_GetField24(struct GameSystem *gameSystem);
extern u8 GAME_DATA_GetOwnNetId(struct GameData *gameData);
extern IntrudeCommSys *INTRUDE_COMM_GetWorkIfRunning(struct GameComm *gameComm);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, unsigned int workSize);
extern void *func_020124E8(struct GameEvent *event);
u32 GAME_COMM_GetKind(struct GameComm *gameComm);
IntrudeCommSys *GAME_COMM_GetWork(struct GameComm *gameComm);
extern struct GameSystem *GAME_EVENT_GetGameSystem(struct GameEvent *event);
extern void GAME_EVENT_CallEvent(struct GameEvent *event, struct GameEvent *child);
u32 func_0200FB24(void);
void GAME_COMM_RequestExitNoCallback(struct GameComm *gameComm);
extern struct FieldMap *ICA_ANIME_GetField20(struct GameSystem *gameSystem);
int FIELDMAP_IsReady(struct FieldMap *fieldMap);
extern void *FIELDMAP_GetMsgBg(struct FieldMap *fieldMap);
extern void *FIELD_MSGBG_CreateMsgData(void *fieldMsgbg, u32 arcDatId);
extern void *FIELD_MSGBG_CreateBottomSysWin(void *fieldMsgbg, void *msgData);
void *func_02029830(struct GameSystem *gameSystem, u32 soundId);
int GFL_USE_IsBgmPlaying(void);
void *func_02029620(struct GameSystem *gameSystem, u32 popMode, u32 fadeFrames);
extern int FIELD_MSGBG_SysWinMain(void *printer);
extern void FIELD_MSGBG_DeleteSysWin(void *printer);
extern u32 MSGDATA_Delete(void *msgData);
extern struct GameSystem *SCRCMD_WORK_GetGameSystem(struct ScriptWork *scriptWork);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void *ICA_ANIME_GetField114(struct GameSystem *gameSystem);
extern u16 GAME_DATA_GetPlayerZoneId(void *playerWork);
extern u32 func_020307B0(void *memory);
extern u8 GAME_DATA_GetIntrudeIdByte(struct GameData *gameData);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 ZONEDATA_IsZone117(u32 zoneId);
extern int INTRUDE_COMM_HasResult(IntrudeSession *session);
extern int INTRUDE_COMM_IsSessionAccepted(IntrudeSession *session);
extern struct WordSet *WORDSET_CreateDefault(u32 heapId);
extern void *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(void *strbuf);
extern unsigned int WORDSET_DeleteStrbufED04(void *wordSet);
extern void *GAME_DATA_GetMyStatus(struct GameData *gameData);
extern u8 func_02008550(void *myStatus);
extern void *func_02045EC0(void *msgData, u32 msgId);
extern void *GAME_DATA_GetLastBattleRecSlot(struct GameData *gameData);
extern void *GAME_DATA_GetPlayerStatusById(struct GameData *gameData, u32 netId);
extern void WORDSET_SetSlotMyStatus(void *wordSet, u32 index, void *myStatus);
extern void func_02045CAC(void *msgData, u32 msgId, void *dest);
extern void WORDSET_CopyTaggedText(void *wordSet, void *dest, void *src);
int GFL_NET_GetNegotiationNum(void);
extern void *GAME_DATA_GetMyStatusByNetId(struct GameData *gameData, int netId);
void INTRUDE_COMM_SetWordSetRequest(IntrudeMemberRecord *record, IntrudeMemberName *name, void *wordSet, u16 heapId);
extern IntrudeMemberRecord *INTRUDE_COMM_GetActiveSessionRequest(IntrudeSession *session);
extern struct WordSet *WORDSET_Create(u32 count, u32 length, u16 heapId);
extern void FIELD_MSGBG_DeleteMsgData(void *msgData);
extern void FIELD_MSGBG_SysWinPrintStr(void *printer, u32 x, u16 y, void *text);
extern void FIELD_MSGBG_ClearSysWin(void *printer);
extern void *FIELD_MSGBG_CreateMsgWin(void *fieldMsgbg, void *msgData, u16 x, u16 y, u16 width, u16 height);
extern int FIELD_MSGBG_DeleteMsgWin(void *window);
extern void FIELD_MSGBG_MsgWinPrintStr(void *window, u16 x, u16 y, void *text);
extern int FIELD_MSGBG_DeleteMenuFunc(void *menu);
extern void *FIELD_MSGBG_CreateYesNoMenu(void *fieldMsgbg, u32 cursorPos);
extern int FIELD_MSGBG_YesNoMenuMain(void *menu);
extern struct GameData *GAME_COMM_GetGameData(struct GameComm *gameComm);
extern void *SCRCMD_WORK_GetScriptWork(struct ScriptWork *scriptWork);
extern u16 *SCRIPT_WORK_ReadWorkPointer(ScriptVm *vm, struct ScriptWork *scriptWork);
extern void SCRIPT_SYS_CallEvent(void *scriptSys, struct GameEvent *event);
extern u8 GAME_DATA_GetIntrudeId(struct GameData *gameData);
extern void INTRUDE_COMM_ClearSessionEntries(IntrudeSession *session);
extern void INTRUDE_FIELD_InitStartParam(IntrudeRemoteRecord *startParam);
extern void *FIELD_MSGBG_CreateBottomMsgWin(void *fieldMsgbg, void *msgData);
extern int FIELD_MSGBG_MsgWinPrintMsg(void *window, u32 x, u32 y, u32 msgId);
extern int INTRUDE_CMD_SendEntryIndex(IntrudeCommSys *sys, int netId);
extern int INTRUDE_COMM_GetMemberNameNetId(IntrudeMemberEntry *entry);
extern int INTRUDE_COMM_SendReady(IntrudeCommSys *sys, int netId);
extern u8 INTRUDE_FIELD_GetStartKind(IntrudeRemoteRecord *startParam);
extern int FIELD_MSGBG_IsMsgWinTransDone(void *window);
extern struct GameEvent *INTRUDE_FIELD_CreateOfferInfoEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, u16 senderNetId);
extern void GAME_EVENT_ChangeEvent(struct GameEvent *event, struct GameEvent *next);
extern u8 INTRUDE_COMM_GetRequesterNetId(IntrudeCommSys *sys, IntrudeSession *session);
extern void *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern void *INTRUDE_GetFromSave(void *saveControl);
extern u8 INTRUDE_GetMonolithLevel(void *battleRec);
extern void *FIELDMAP_GetMmdlSys(struct FieldMap *fieldMap);
extern void FLDMMDL_SysPauseMove(void *mmdlSys);
extern u32 *FLDMMDL_SysResumeMove(void *mmdlSys);
extern void INTRUDE_COMM_InitRequest(IntrudeCommSys *sys, int netId);
extern void INTRUDE_COMM_ClearNotice(IntrudeCommSys *sys);
extern void INTRUDE_COMM_ClearRequestOpen(IntrudeCommSys *sys);
extern int COMM_PLAYER_CheckActive(struct CommPlayerWork *commPlayer, int netId);
extern struct FldMmdl *COMM_PLAYER_GetPlayerModel(struct CommPlayerWork *commPlayer, int netId);
extern void MYSTATUS_Copy(void *src, void *dest);
extern int INTRUDE_COMM_IsSessionActive(IntrudeSession *session);
extern void MI_CpuCopy8(const void *src, void *dest, int size);
extern void INTRUDE_COMM_SetState(IntrudeCommSys *sys, int state);
extern int INTRUDE_COMM_GetRequestKind(IntrudeSession *session);
extern IntrudeResultRecord *INTRUDE_COMM_GetSessionResult(IntrudeSession *session);
extern int INTRUDE_COMM_IsRequestFromNetId(IntrudeSession *session, int netId);
extern int INTRUDE_CMD_SendReadyNotice(IntrudeCommSys *sys);
extern int INTRUDE_COMM_TakeNoticeState(IntrudeSession *session);
extern void INTRUDE_COMM_ClearRequestResult(IntrudeCommSys *sys);
extern int INTRUDE_COMM_SendNoticeBytes(int netId, int answer);
extern u8 *INTRUDE_COMM_GetNotice(IntrudeCommSys *sys);
extern int FLDMMDL_CheckPossibleAcmd(struct FldMmdl *mmdl);
extern struct GameSystem *FIELDMAP_GetGameSystem(struct FieldMap *fieldMap);
u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
int INTRUDE_COMM_HasResultReward(IntrudeCommSys *sys, IntrudeSession *session);
u8 INTRUDE_COMM_GetPartnerTallyValid(IntrudeCommSys *sys);
int INTRUDE_COMM_GetResultCount(IntrudeCommSys *sys, IntrudeSession *session);
void INTRUDE_AddMissionBonusScore(void *battleRec, s32 count);
void INTRUDE_AddMissionScore(void *battleRec, s32 count);
void *GAME_DATA_GetMyItem(struct GameData *gameData);
u32 func_02007FB8(void *myItem, u16 itemId, u16 heapId);
u32 func_0200823C(u32 itemId);
u32 func_02007E50(void *myItem, u16 itemId, u16 count, u16 heapId);
u32 INTRUDE_IncrementMissionClearCount(void *record);
void WORDSET_SetSlotNumber(void *wordSet, u32 index, u32 number, u32 digits, u32 dispType, u32 codeType);
extern void GAME_EVENT_Change(struct GameEvent *event, GameEventFunc func, int workSize);
int INTRUDE_CMD_SendProposal(IntrudeCommSys *sys, IntrudeSession *session);
int INTRUDE_COMM_GetJoinStatus(IntrudeCommSys *sys, IntrudeSession *session);
void WORDSET_SetSlotFromMsgA0(void *wordSet, u32 index, s32 value);
struct GameEvent *GAME_EVENT_CreateOverlayEvent(struct GameSystem *gameSystem, u32 overlayId, struct GameEvent *(*createFunc)(struct GameSystem *gameSystem, void *param), void *param);
struct GameEvent *GPOWER_EVENT_CreateActivateEvent(struct GameSystem *gameSystem, void *param);
int func_0215839C(IntrudeCommSys *sys, int flags, int netId);
void INTRUDE_COMM_SetLock(IntrudeCommSys *sys, int locked);
int INTRUDE_COMM_SendPeerFlags(IntrudeCommSys *sys, int netId, int flags);
struct GameEvent *INTRUDE_LINK_CreateEvent(struct GameSystem *gameSystem, EventCommBattleParam *param);
void INTRUDE_COMM_PickEntryForKind(void *battleRec, u32 key);
int INTRUDE_COMM_SendSupportMode(IntrudeCommSys *sys, int netId, int mode);
void *GAME_DATA_GetPmsWork(struct GameData *gameData);
void *MYSTATUS_Create(u32 heapId);
void *COMM_PLAYER_SUPPORT_GetActiveRecord(void *pmsWork);
struct GameEvent *SCRIPT_SYS_CreateScriptEventSimple(struct GameSystem *gameSystem, int scriptId, int param, int heapId);
void *SCRIPT_SYS_GetEventScriptWork(struct GameEvent *event);
int SCRIPT_WORK_SetParams(void *scriptWork, int param0, int param1, int param2, u16 param3);
extern u32 func_020084F8(void *myStatus, void *dest, u32 size);
int INTRUDE_COMM_SendProfile(u32 netId, void *name);
void WORDSET_Callback_EF40(void *wordSet, u32 index, u32 itemId);
extern int INTRUDE_COMM_IsValidProfileCode(u32 itemId);
extern void *GAME_DATA_GetMiscSave(struct GameData *gameData);
extern u32 BEACON_GetPoints(void *miscSave);
extern u32 BEACON_SubPoints(void *miscSave, u32 amount);
extern u32 func_02007E3C(void *myItem, u16 itemId, u16 count, u16 heapId);
extern int INTRUDE_SUBDISP_MainRequestAnswerSeq(IntrudeCommSys *sys, EventCommCommonWork *work, u8 *answerSeq);
struct GameEvent *INTRUDE_SUBDISP_CreatePalaceWarpEvent(struct GameSystem *gameSystem);
struct GameEvent *INTRUDE_SUBDISP_CreateDisconnectEvent(struct GameSystem *gameSystem, int mode);
extern struct GameEvent *INTRUDE_SUBDISP_CreateTownWarpEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 zoneId, int mode);
extern struct GameComm *GAMESYSTEM_GetGameComm(struct GameSystem *gameSystem);
void EVENT_COMM_COMMON_InitMsgBox(EventCommMsgBox *msgBox, struct GameSystem *gameSystem);
void EVENT_COMM_COMMON_ExitMsgBox(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_SetupPrintWin(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_DeletePrintWin(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_PrintText(EventCommMsgBox *msgBox, void *text);
void EVENT_COMM_COMMON_PrintMsg(EventCommMsgBox *msgBox, u16 msgId);
void EVENT_COMM_COMMON_ClearPrintWin(EventCommMsgBox *msgBox);
int EVENT_COMM_COMMON_IsPrintFinished(EventCommMsgBox *msgBox);
int EVENT_COMM_COMMON_IsKeyTrg(void);
void EVENT_COMM_COMMON_SetupListWindow(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_DeleteListWindow(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_PrintToWindow(EventCommMsgBox *msgBox, void *msgData, void *window, unsigned int msgId, int x, int y);
void EVENT_COMM_COMMON_PrintListWindow(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y);
void EVENT_COMM_COMMON_DeleteChoice(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_StartChoice(EventCommMsgBox *msgBox, struct GameSystem *gameSystem);
int EVENT_COMM_COMMON_PollChoice(EventCommMsgBox *msgBox);
void EVENT_COMM_COMMON_SetupListWindowB(EventCommMsgBox *msgBox, struct GameSystem *gameSystem, int x, int y, int width, int height);
void EVENT_COMM_COMMON_PrintListWindowB(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y);
void EVENT_COMM_COMMON_DeleteListWindowB(EventCommMsgBox *msgBox);
int EVENT_COMM_COMMON_GetMissionState(IntrudeSession *session);
int EVENT_COMM_COMMON_GetPeerTalkStatus(IntrudeCommSys *sys, u8 netId);
int EVENT_COMM_COMMON_CmdCallExitSyncEvent(ScriptVm *vm, struct ScriptWork *scriptWork);
struct GameEvent *EVENT_COMM_COMMON_CreateExitSyncEvent(struct GameSystem *gameSystem, u16 *result);
int EVENT_COMM_COMMON_ExitSyncEventMain(struct GameEvent *event, int *seq, void *wk);
int EVENT_COMM_COMMON_CmdGetObjCode(ScriptVm *vm, struct ScriptWork *scriptWork);
int EVENT_COMM_COMMON_CmdCheckMissionInfoPending(ScriptVm *vm, struct ScriptWork *scriptWork);
int EVENT_COMM_COMMON_CmdCallMissionInfoEvent(ScriptVm *vm, struct ScriptWork *scriptWork);
struct GameEvent *EVENT_COMM_COMMON_CreateMissionInfoEvent(struct GameSystem *gameSystem);
int EVENT_COMM_COMMON_MissionInfoEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_FreeMissionInfoWork(EventCommMsgBox *msgBox);
struct GameEvent *EVENT_COMM_COMMON_CreateReturnPalaceEvent(struct GameSystem *gameSystem);
int EVENT_COMM_COMMON_ReturnPalaceEventMain(struct GameEvent *event, int *seq, void *wk);
int EVENT_COMM_COMMON_CmdGetIntrudeDistance(ScriptVm *vm, struct ScriptWork *scriptWork);
int EVENT_COMM_COMMON_CmdCheckBattleRecState(ScriptVm *vm, struct ScriptWork *scriptWork);
struct GameEvent *EVENT_COMM_COMMON_CreateTalkStartEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, void *unused, struct FldMmdl *playerMmdl, int netId, u16 heapId);
int EVENT_COMM_COMMON_TalkStartEventMain(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *EVENT_COMM_COMMON_CreateTalkEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId);
struct GameEvent *EVENT_COMM_COMMON_CreateTalkedStartEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId);
int EVENT_COMM_COMMON_TalkedStartEventMain(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *EVENT_COMM_COMMON_CreateTalkedEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId);
void EVENT_COMM_COMMON_InitCommonWork(struct GameSystem *gameSystem, IntrudeCommSys *sys, EventCommCommonWork *work, struct FieldMap *fieldMap, struct FldMmdl *playerMmdl, int netId, u16 heapId);
void EVENT_COMM_COMMON_ExitCommonWork(IntrudeCommSys *sys, EventCommCommonWork *work);
int EVENT_COMM_COMMON_TalkEventMain(struct GameEvent *event, int *seq, void *wk);
int EVENT_COMM_COMMON_TalkedEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkTypeEvent(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys);
void EVENT_COMM_COMMON_ChangeTalkedTypeEvent(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys);
int EVENT_COMM_COMMON_GetTalkType(EventCommCommonWork *work, IntrudeCommSys *sys);
struct GameEvent *EVENT_COMM_COMMON_CreateMissionResultEvent(struct GameSystem *gameSystem, int showResult);
int EVENT_COMM_COMMON_MissionResultEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkMsgEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkMsgEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedMsgEvent(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_ChangeTalkPowerGiftTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkPowerGiftTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkPowerGiftAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkPowerGiftAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedPowerGiftAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedPowerGiftAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedPowerGiftTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedPowerGiftTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkPowerShareTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkPowerShareTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkPowerShareAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkPowerShareAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedPowerShareAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedPowerShareAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedPowerShareTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedPowerShareTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkBattleTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_BattleRequestEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkBattleAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_BattleAnswerEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedBattleAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_ChangeTalkedBattleTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_ChangeTalkSearchTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkSearchTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkSearchAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkSearchAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedSearchAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedSearchAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedSearchTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedSearchTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeSearchFoundEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_SearchFoundEventMain(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *EVENT_COMM_COMMON_CreateSupportMsgEvent(struct GameSystem *gameSystem, u32 heapId);
int EVENT_COMM_COMMON_SupportMsgEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkGreetingTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkGreetingTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkGreetingAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkGreetingAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedGreetingAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedGreetingAsTargetEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedGreetingTargetEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_TalkedGreetingTargetEventMain(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *EVENT_COMM_COMMON_CreateOfferEvent(struct GameSystem *gameSystem, IntrudeCommSys *sys, IntrudeMemberRecord *offer);
int EVENT_COMM_COMMON_OfferEventMain(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *EVENT_COMM_COMMON_CreateOfferAnswerEvent(struct GameSystem *gameSystem, IntrudeMemberRecord *offer);
int EVENT_COMM_COMMON_OfferAnswerEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkItemSaleEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_ItemSaleEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkItemPurchaseEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_ItemPurchaseEventMain(struct GameEvent *event, int *seq, void *wk);
void EVENT_COMM_COMMON_ChangeTalkedItemSaleEvent(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_ChangeTalkedItemPurchaseEvent(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent(struct GameEvent *event, EventCommCommonWork *src, u16 *msgIds);
int EVENT_COMM_COMMON_MsgEventMain(struct GameEvent *event, int *seq, void *eventWork);
void EVENT_COMM_COMMON_StartMsgEvent95(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent105(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110ByKindA(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110ByKindB(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgEvent110Alt(struct GameEvent *event, EventCommCommonWork *src);
void EVENT_COMM_COMMON_StartMsgScriptEvent(struct GameEvent *event, EventCommCommonWork *src);
int EVENT_COMM_COMMON_MsgScriptEventMain(struct GameEvent *event, int *seq, void *eventWork);
extern const char sEmptyTextMsgBox[];
extern char sEventCommCommonFile[];
extern const char sEmptyTextTalkTable[];
extern const char sEmptyTextResult[];
extern u16 sTalkMsgIds[];
extern u16 sMissionAchieveMsgIdsA[];
extern u16 sMissionAchieveMsgIdsB[];
extern u16 sMissionAchieveMsgIdsC[];
extern u16 sTalkPowerGiftAsTargetMsgIds[];
extern u16 sTalkedPowerGiftAsTargetMsgIds[];
extern u8 ov083_id[];
extern u16 sTalkedPowerGiftTargetMsgIds[];
extern u16 sTalkedPowerGiftEndMsgIds[];
extern u16 sTalkPowerShareTargetMsgIds[];
extern const u16 sTalkPowerShareAsTargetMsgIds[];
extern const u16 sTalkedPowerShareAchieveMsgIdsA[];
extern const u16 sTalkedPowerShareAchieveMsgIdsB[];
extern u16 sTalkedPowerShareTargetMsgIds[];
extern const u16 sBattleRequestMsgIds[];
extern const u16 sBattleRequestTalkedMsgIds[];
extern const u16 sBattleRequestAcceptedMsgIds[];
extern const u16 sBattleRequestEndMsgIds[];
extern const u16 sBattleRequestRefusedMsgIds[];
extern const u16 sBattleAnswerMsgIds[];
extern const u16 sBattleAnswerTalkedMsgIds[];
extern const u16 sBattleAnswerAcceptedMsgIds[];
extern const u16 sBattleAnswerEndMsgIds[];
extern const u16 sBattleAnswerRefusedMsgIds[];
extern unsigned short sTalkSearchTargetMsgIds[];
extern unsigned short sTalkSearchAsTargetMsgIds[];
extern unsigned short sTalkedSearchAsTargetMsgIds[];
extern unsigned short sTalkedSearchTargetMsgIds[];
extern const u16 sSearchFoundMsgIdsA[];
extern const u16 sSearchFoundMsgIdsB[];
extern const u16 sSearchFoundOtherMsgIds[];
extern unsigned short sTalkGreetingTargetMsgIds[];
extern unsigned short sTalkGreetingAsTargetMsgIds[];
extern u16 sTalkedGreetingAsTargetMsgIds[];
extern u16 sTalkedGreetingTargetMsgIds[];
extern const u16 sOfferAnswerMsgIds[];
extern const u16 sItemSaleMsgIds[5][5];
extern const u16 sItemPurchaseMsgIds[6][5];
extern const char sEmptyTextA[];
extern u16 sMsgIds95[];
extern u16 sMsgIds105[];
extern u16 sMsgIds110ByKindA[][5];
extern u16 sMsgIds110ByKindB[][5];
extern u16 sMsgIds110[];
extern u16 sMsgIds110Alt[];
extern const char sEmptyTextB[];
extern u16 sMsgIds125[];


void EVENT_COMM_COMMON_InitMsgBox(EventCommMsgBox *msgBox, struct GameSystem *gameSystem)
{
    void *fieldMsgbg;

    fieldMsgbg = FIELDMAP_GetMsgBg(ICA_ANIME_GetField20(gameSystem));
    if (msgBox->wordSet == 0) {
        msgBox->wordSet = WORDSET_Create(6, 0x20, 4);
        msgBox->text = STRBUF_Create(0x1F0, 4);
        msgBox->templateText = STRBUF_Create(0x1D0, 4);
        msgBox->msgData = FIELD_MSGBG_CreateMsgData(fieldMsgbg, 0x44);
        msgBox->msgDataB = FIELD_MSGBG_CreateMsgData(fieldMsgbg, 0x42);
        msgBox->msgDataC = FIELD_MSGBG_CreateMsgData(fieldMsgbg, 0x43);
        msgBox->fieldMsgbg = fieldMsgbg;
        msgBox->printing = 0;
    }
}



void EVENT_COMM_COMMON_ExitMsgBox(EventCommMsgBox *msgBox)
{
    EVENT_COMM_COMMON_DeletePrintWin(msgBox);
    EVENT_COMM_COMMON_DeleteListWindowB(msgBox);
    EVENT_COMM_COMMON_DeleteListWindow(msgBox);
    if (msgBox->wordSet != 0) {
        if (msgBox->printer != 0) {
            FIELD_MSGBG_DeleteSysWin(msgBox->printer);
            msgBox->printer = 0;
        }
        FIELD_MSGBG_DeleteMsgData(msgBox->msgData);
        FIELD_MSGBG_DeleteMsgData(msgBox->msgDataB);
        FIELD_MSGBG_DeleteMsgData(msgBox->msgDataC);
        STRBUF_Delete(msgBox->templateText);
        STRBUF_Delete(msgBox->text);
        WORDSET_DeleteStrbufED04(msgBox->wordSet);
        msgBox->wordSet = 0;
    }
}



void EVENT_COMM_COMMON_SetupPrintWin(EventCommMsgBox *msgBox)
{
    if (msgBox->printer != 0) {
        if (msgBox->printing == 1) {
            EVENT_COMM_COMMON_ClearPrintWin(msgBox);
        }
    } else {
        msgBox->printer = FIELD_MSGBG_CreateBottomSysWin(msgBox->fieldMsgbg, msgBox->msgData);
    }
}



void EVENT_COMM_COMMON_DeletePrintWin(EventCommMsgBox *msgBox)
{
    if (msgBox->printer != 0) {
        FIELD_MSGBG_DeleteSysWin(msgBox->printer);
        msgBox->printer = 0;
    }
}



void EVENT_COMM_COMMON_PrintText(EventCommMsgBox *msgBox, void *text)
{
    EVENT_COMM_COMMON_SetupPrintWin(msgBox);
    FIELD_MSGBG_SysWinPrintStr(msgBox->printer, 0, 0, text);
    msgBox->printing = 1;
}



void EVENT_COMM_COMMON_PrintMsg(EventCommMsgBox *msgBox, u16 msgId)
{
    func_02045CAC(msgBox->msgData, msgId, msgBox->templateText);
    WORDSET_CopyTaggedText(msgBox->wordSet, msgBox->text, msgBox->templateText);
    EVENT_COMM_COMMON_PrintText(msgBox, msgBox->text);
}



void EVENT_COMM_COMMON_ClearPrintWin(EventCommMsgBox *msgBox)
{
    if (msgBox->printer == 0) {
        func_02034714(sEmptyTextMsgBox, 0, sEmptyTextMsgBox);
    }
    FIELD_MSGBG_ClearSysWin(msgBox->printer);
    msgBox->printing = 0;
}



int EVENT_COMM_COMMON_IsPrintFinished(EventCommMsgBox *msgBox)
{
    if (msgBox->printer == 0) {
        return 1;
    }
    return FIELD_MSGBG_SysWinMain(msgBox->printer);
}



int EVENT_COMM_COMMON_IsKeyTrg(void)
{
    if (KEY_GetTrg() & 0xf3) return 1;
    return 0;
}



/*
 * extent: Two bytes of alignment padding at 0x0217F45A.
 */
void EVENT_COMM_COMMON_SetupListWindow(EventCommMsgBox *msgBox)
{
    if (msgBox->listWindow == 0) msgBox->listWindow = FIELD_MSGBG_CreateMsgWin(msgBox->fieldMsgbg, msgBox->msgData, 1, 0x13, 0x1e, 4);
}



void EVENT_COMM_COMMON_DeleteListWindow(EventCommMsgBox *msgBox)
{
    if (msgBox->listWindow != 0) {
        FIELD_MSGBG_DeleteMsgWin(msgBox->listWindow);
        msgBox->listWindow = 0;
    }
}



void EVENT_COMM_COMMON_PrintToWindow(EventCommMsgBox *msgBox, void *msgData, void *window, unsigned int msgId, int x, int y)
{
    func_02045CAC(msgData, msgId, msgBox->templateText);
    WORDSET_CopyTaggedText(msgBox->wordSet, msgBox->text, msgBox->templateText);
    FIELD_MSGBG_MsgWinPrintStr(window, (u16)x, (u16)y, msgBox->text);
}



void EVENT_COMM_COMMON_PrintListWindow(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y)
{
    EVENT_COMM_COMMON_SetupListWindow(msgBox);
    EVENT_COMM_COMMON_PrintToWindow(msgBox, msgBox->msgData, msgBox->listWindow, msgId, x, y);
}



void EVENT_COMM_COMMON_DeleteChoice(EventCommMsgBox *msgBox)
{
    if (msgBox->choiceHandle != 0) {
        FIELD_MSGBG_DeleteMenuFunc(msgBox->choiceHandle);
        msgBox->choiceHandle = 0;
    }
}



void EVENT_COMM_COMMON_StartChoice(EventCommMsgBox *msgBox, struct GameSystem *gameSystem)
{
    ICA_ANIME_GetField20(gameSystem);
    if (msgBox->choiceHandle != 0 || msgBox->msgData == 0) func_02034714(sEmptyTextMsgBox, 0, sEmptyTextMsgBox);
    msgBox->choiceHandle = FIELD_MSGBG_CreateYesNoMenu(msgBox->fieldMsgbg, 0);
}



int EVENT_COMM_COMMON_PollChoice(EventCommMsgBox *msgBox)
{
    if (msgBox->choiceHandle == 0) func_02034714(sEmptyTextMsgBox, 0, sEmptyTextMsgBox);
    return FIELD_MSGBG_YesNoMenuMain(msgBox->choiceHandle);
}



void EVENT_COMM_COMMON_SetupListWindowB(EventCommMsgBox *msgBox, struct GameSystem *gameSystem, int x, int y, int width, int height)
{
    ICA_ANIME_GetField20(gameSystem);
    if (msgBox->listWindowB != 0) {
        func_02034714(sEmptyTextMsgBox, 0, sEmptyTextMsgBox);
    }
    msgBox->listWindowB = FIELD_MSGBG_CreateMsgWin(msgBox->fieldMsgbg, msgBox->msgData, (u16)x, (u16)y, width, height);
}



void EVENT_COMM_COMMON_PrintListWindowB(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y)
{
    EVENT_COMM_COMMON_PrintToWindow(msgBox, msgBox->msgDataC, msgBox->listWindowB, msgId, x, y);
}



void EVENT_COMM_COMMON_DeleteListWindowB(EventCommMsgBox *msgBox)
{
    if (msgBox->listWindowB != 0) {
        FIELD_MSGBG_DeleteMsgWin(msgBox->listWindowB);
        msgBox->listWindowB = 0;
    }
}



int EVENT_COMM_COMMON_GetMissionState(IntrudeSession *session)
{
    IntrudeMemberRecord *offer;

    if (INTRUDE_COMM_HasResult(session) == 1) {
        return 4;
    }
    offer = INTRUDE_COMM_GetActiveSessionRequest(session);
    if (offer == 0) {
        return 0;
    }
    if (offer->ticksLeft == 0) {
        if (session->accepted == 1) {
            return 3;
        }
        return 1;
    }
    if (session->accepted == 1) {
        return 2;
    }
    return 1;
}



/*
 * lever: a switch with empty sentinel and default arms retains the dead
 * comparison before the shared bitfield return.
 */
int EVENT_COMM_COMMON_GetPeerTalkStatus(IntrudeCommSys *sys, u8 netId)
{
    IntrudePeer *peer;
    enum Guard { ZERO, INVALID = 0xFFFF } objCode;

    struct GameData *gameData;

    gameData = GAME_COMM_GetGameData(sys->gameComm);
    if (netId == GAME_DATA_GetOwnNetId(gameData)) {
        peer = &sys->localPeer;
    } else {
        peer = &sys->peers[netId];
    }
    objCode = peer->objCode;
    switch (objCode) {
    case 0:
        if (func_02008550(GAME_DATA_GetPlayerStatusById(GAME_COMM_GetGameData(sys->gameComm), netId)) == 0) {
            return 3;
        }
        return 4;
    case 0xFFFF:
        break;
    default:
        break;
    }
    return peer->lookKind;
}



/*
 * extent: Two bytes of alignment padding at 0x0217F67A.
 */
int EVENT_COMM_COMMON_CmdCallExitSyncEvent(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    void *scriptSys = SCRCMD_WORK_GetScriptWork(scriptWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem(scriptWork);
    SCRIPT_SYS_CallEvent(scriptSys, EVENT_COMM_COMMON_CreateExitSyncEvent(gameSystem, SCRIPT_WORK_ReadWorkPointer(vm, scriptWork)));
    return 1;
}



struct GameEvent *EVENT_COMM_COMMON_CreateExitSyncEvent(struct GameSystem *gameSystem, u16 *result)
{
    struct GameEvent *event;
    EventCommExitSyncWork *work;
    int zero;
    zero = 0;
    event = func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_ExitSyncEventMain, 0x10);
    work = func_020124E8(event);
    work->result = result;
    *result = zero;
    return event;
}



int EVENT_COMM_COMMON_ExitSyncEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommExitSyncWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct GameComm *gameComm;
    IntrudeCommSys *sys;
    struct FieldMap *fieldMap;
    int alone;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    gameComm = ICA_ANIME_GetField24(gameSystem);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    alone = 0;
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (sys == 0 && *seq > 0 && *seq < 5) {
        *seq = 5;
    }
    switch (*seq) {
    case 0: {
        void *fieldMsgbg;
        void *text;
        void *templateText;

        if (func_0200FB24() != 0 || (sys == 0 && GAME_DATA_GetIntrudeId(gameData) != GAME_DATA_GetOwnNetId(gameData))) {
            *seq = 7;
            break;
        }
        if (sys != 0) {
            INTRUDE_COMM_ClearSessionEntries(&sys->session);
            INTRUDE_FIELD_InitStartParam(&sys->remoteRecord);
        }
        fieldMsgbg = FIELDMAP_GetMsgBg(fieldMap);
        work->msgData = FIELD_MSGBG_CreateMsgData(fieldMsgbg, 0x2D);
        work->window = FIELD_MSGBG_CreateBottomMsgWin(fieldMsgbg, work->msgData);
        work->wordSet = WORDSET_CreateDefault(4);
        GFL_USE_PlaySeDefaultVolume(0x547);
        if (sys == 0 || GAME_DATA_GetIntrudeIdByte(gameData) == GAME_DATA_GetOwnNetId(gameData)) {
            FIELD_MSGBG_MsgWinPrintMsg(work->window, 0, 0, 0x49);
            alone = 1;
        } else {
            text = STRBUF_Create(0x100, 0x15);
            templateText = func_02045EC0(work->msgData, 0x4A);
            WORDSET_SetSlotMyStatus(work->wordSet, 0, GAME_DATA_GetMyStatusByNetId(gameData, GAME_DATA_GetIntrudeIdByte(gameData)));
            WORDSET_CopyTaggedText(work->wordSet, text, templateText);
            FIELD_MSGBG_MsgWinPrintStr(work->window, 0, 0, text);
            STRBUF_Delete(templateText);
            STRBUF_Delete(text);
        }
        if (GFL_NET_GetNegotiationNum() <= 1) {
            if (alone == 0) {
                *work->result = 0;
            } else {
                *work->result = 1;
            }
            *seq = 5;
            break;
        }
        (*seq)++;
    }
    case 1:
        if (INTRUDE_CMD_SendEntryIndex(sys, GAME_DATA_GetIntrudeIdByte(gameData)) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        if (INTRUDE_COMM_GetMemberNameNetId(&sys->session.members[GAME_DATA_GetIntrudeIdByte(gameData)]) == 1) {
            (*seq)++;
        }
        break;
    case 3:
        if (INTRUDE_COMM_SendReady(sys, GAME_DATA_GetIntrudeIdByte(gameData)) == 1) {
            (*seq)++;
        }
        break;
    case 4:
        if (INTRUDE_FIELD_GetStartKind(&sys->remoteRecord) == 1) {
            *work->result = 1;
            *seq = 5;
        }
        break;
    case 5:
        if (FIELD_MSGBG_IsMsgWinTransDone(work->window) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (KEY_GetTrg() & 0xF3) {
            WORDSET_DeleteStrbufED04(work->wordSet);
            FIELD_MSGBG_DeleteMsgWin(work->window);
            MSGDATA_Delete(work->msgData);
            (*seq)++;
        }
        break;
    case 7:
        return 1;
    }
    return 0;
}



/*
 * extent: two bytes of zero alignment padding follow at 0x0217F8CE.
 * lever: stores in both arms keep the branch to the shared store.
 */
int EVENT_COMM_COMMON_CmdGetObjCode(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *result;
    IntrudeCommSys *sys;
    int unused;
    result = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(SCRCMD_WORK_GetGameSystem(scriptWork)));
    if (sys == 0 || sys->localPeer.objCode == 0) {
        *result = 0;
    } else {
        *result = sys->localPeer.objCode;
    }
    return 0;
}



int EVENT_COMM_COMMON_CmdCheckMissionInfoPending(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *result;
    IntrudeCommSys *sys;
    int value;

    result = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(SCRCMD_WORK_GetGameSystem(scriptWork)));
    if (sys != 0 && sys->infoShown == 0 && INTRUDE_COMM_IsSessionAccepted(&sys->session) == 1) {
        value = 1;
    } else {
        value = 0;
    }
    *result = value;
    return 0;
}



int EVENT_COMM_COMMON_CmdCallMissionInfoEvent(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    void *scriptSys;
    scriptSys = SCRCMD_WORK_GetScriptWork(scriptWork);
    SCRIPT_SYS_CallEvent(scriptSys, EVENT_COMM_COMMON_CreateMissionInfoEvent(SCRCMD_WORK_GetGameSystem(scriptWork)));
    return 1;
}



struct GameEvent *EVENT_COMM_COMMON_CreateMissionInfoEvent(struct GameSystem *gameSystem)
{
    struct GameEvent *event;
    event = func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_MissionInfoEventMain, 0x30);
    MI_CpuFill8(func_020124E8(event), 0, 0x30);
    return event;
}



int EVENT_COMM_COMMON_MissionInfoEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommMsgBox *msgBox = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    struct GameEvent *next;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    if (sys == 0 && *seq < 3) {
        *seq = 3;
    }
    switch (*seq) {
    case 0:
        sys->infoShown = 1;
        EVENT_COMM_COMMON_InitMsgBox(msgBox, gameSystem);
        if (EVENT_COMM_COMMON_GetMissionState(&sys->session) == 3) {
            *seq = 2;
        } else {
            EVENT_COMM_COMMON_PrintListWindow(msgBox, 0x1A, 0, 0);
            (*seq)++;
        }
        break;
    case 1:
        switch (EVENT_COMM_COMMON_GetMissionState(&sys->session)) {
        case 2:
            break;
        case 3:
        default:
            (*seq)++;
            break;
        }
        break;
    case 2:
        next = INTRUDE_FIELD_CreateOfferInfoEvent(gameSystem, ICA_ANIME_GetField20(gameSystem), sys, 0x15);
        EVENT_COMM_COMMON_FreeMissionInfoWork(msgBox);
        GAME_EVENT_ChangeEvent(event, next);
        return 0;
    case 3:
        EVENT_COMM_COMMON_FreeMissionInfoWork(msgBox);
        return 1;
    }
    return 0;
}



void EVENT_COMM_COMMON_FreeMissionInfoWork(EventCommMsgBox *msgBox)
{
    EVENT_COMM_COMMON_ExitMsgBox(msgBox);
}



struct GameEvent *EVENT_COMM_COMMON_CreateReturnPalaceEvent(struct GameSystem *gameSystem)
{
    return func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_ReturnPalaceEventMain, 0);
}



int EVENT_COMM_COMMON_ReturnPalaceEventMain(struct GameEvent *event, int *seq, void *wk)
{
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    IntrudeCommSys *sys;
    struct GameEvent *next;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameComm = ICA_ANIME_GetField24(gameSystem);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    switch (*seq) {
    case 0:
        if (sys == 0) {
            GAME_DATA_GetOwnNetId(gameData);
        } else {
            INTRUDE_COMM_GetRequesterNetId(sys, &sys->session);
        }
        next = INTRUDE_SUBDISP_CreateTownWarpEvent(gameSystem, fieldMap, 0x117, 1);
        if (next == 0) {
            return 1;
        }
        GAME_EVENT_CallEvent(event, next);
        (*seq)++;
        break;
    case 1:
        if (ZONEDATA_IsZone117(GAME_DATA_GetPlayerZoneId(ICA_ANIME_GetField114(gameSystem))) == 1) {
            GAME_EVENT_CallEvent(event, EVENT_COMM_COMMON_CreateMissionInfoEvent(gameSystem));
        }
        (*seq)++;
        break;
    case 2:
        return 1;
    }
    return 0;
}



/*
 * What closed it: the store through `out` is written in each arm of the
 * if/else (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md)
 * rather than once after it through a shared `v`; the single store made
 * `v` live across the join and coloured out/q/temp as r6/r4/r5 instead of
 * r5/r6/r4 (docs/notes/pkt_ov018_0217FAE0.c.txt has the earlier miss).
 */
int EVENT_COMM_COMMON_CmdGetIntrudeDistance(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *result;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    int distance;

    result = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    gameSystem = SCRCMD_WORK_GetGameSystem(scriptWork);
    ICA_ANIME_GetField24(gameSystem);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    if (GAME_DATA_GetIntrudeIdByte(gameData) == GAME_DATA_GetOwnNetId(gameData)) {
        *result = 0;
    } else {
        distance = GAME_DATA_GetIntrudeIdByte(gameData) - GAME_DATA_GetOwnNetId(gameData);
        if (distance < 0) {
            distance += 3;
        }
        *result = distance;
    }
    return 0;
}



int EVENT_COMM_COMMON_CmdCheckBattleRecState(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *result;
    int value;
    result = SCRIPT_WORK_ReadWorkPointer(vm, scriptWork);
    if (INTRUDE_GetMonolithLevel(INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(ICA_ANIME_GetField1C(SCRCMD_WORK_GetGameSystem(scriptWork))))) != 0x30) {
        value = 1;
    } else {
        value = 0;
    }
    *result = value;
    return 0;
}



struct GameEvent *EVENT_COMM_COMMON_CreateTalkStartEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, void *unused, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    EventCommTalkParam *param;
    struct GameEvent *event;
    event = func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_TalkStartEventMain, 0x10);
    param = func_020124E8(event);
    MI_CpuFill8(param, 0, 0x10);
    param->fieldMap = fieldMap;
    param->playerMmdl = playerMmdl;
    param->netId = netId;
    param->heapId = heapId;
    return event;
}



int EVENT_COMM_COMMON_TalkStartEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommTalkParam *param = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    switch (*seq) {
    case 0:
        if (sys == 0) {
            return 1;
        }
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(param->fieldMap));
        GAME_EVENT_CallEvent(event, EVENT_COMM_COMMON_CreateTalkEvent(gameSystem, param->fieldMap, sys, param->playerMmdl, param->netId, param->heapId));
        (*seq)++;
        break;
    case 1:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(param->fieldMap));
        return 1;
    }
    return 0;
}



struct GameEvent *EVENT_COMM_COMMON_CreateTalkEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_TalkEventMain, 0x9c);
    EventCommCommonWork *work = func_020124E8(event);

    MI_CpuFill8(work, 0, 0x9c);
    EVENT_COMM_COMMON_InitCommonWork(gameSystem, sys, work, fieldMap, playerMmdl, netId, heapId);
    INTRUDE_COMM_InitRequest(sys, netId);
    INTRUDE_COMM_ClearNotice(sys);
    work->talkType = EVENT_COMM_COMMON_GetTalkType(work, sys);
    return event;
}



struct GameEvent *EVENT_COMM_COMMON_CreateTalkedStartEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_TalkedStartEventMain, 0x10);
    EventCommTalkParam *param = func_020124E8(event);

    MI_CpuFill8(param, 0, 0x10);
    param->fieldMap = fieldMap;
    param->playerMmdl = playerMmdl;
    param->netId = netId;
    param->heapId = heapId;
    INTRUDE_COMM_ClearRequestOpen(sys);
    return event;
}



int EVENT_COMM_COMMON_TalkedStartEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommTalkParam *param = wk;
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    switch (*seq) {
    case 0:
        if (sys == 0) {
            return 1;
        }
        if (COMM_PLAYER_CheckActive(sys->commPlayer, param->netId) == 0) {
            return 1;
        }
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(param->fieldMap));
        GAME_EVENT_CallEvent(event, EVENT_COMM_COMMON_CreateTalkedEvent(gameSystem, param->fieldMap, sys, param->playerMmdl, param->netId, param->heapId));
        *seq = *seq + 1;
        break;
    case 1:
        FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(param->fieldMap));
        return 1;
    }
    return 0;
}



struct GameEvent *EVENT_COMM_COMMON_CreateTalkedEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_TalkedEventMain, 0x9c);
    EventCommCommonWork *work = func_020124E8(event);

    MI_CpuFill8(work, 0, 0x9c);
    EVENT_COMM_COMMON_InitCommonWork(gameSystem, sys, work, fieldMap, playerMmdl, netId, heapId);
    work->talkType = sys->receivedRequest.type;
    work->member = sys->receivedRequest.data;
    return event;
}



void EVENT_COMM_COMMON_InitCommonWork(struct GameSystem *gameSystem, IntrudeCommSys *sys, EventCommCommonWork *work, struct FieldMap *fieldMap, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    enum Local { LOCAL_ZERO } partnerNetId;

    work->heapId = heapId;
    work->playerMmdl = playerMmdl;
    partnerNetId = netId;
    work->partnerMmdl = COMM_PLAYER_GetPlayerModel(sys->commPlayer, partnerNetId);
    work->fieldMap = fieldMap;
    work->peerSlot = (u8)netId;
    work->msgIndex = EVENT_COMM_COMMON_GetPeerTalkStatus(sys, (u8)netId);
    MYSTATUS_Copy(GAME_DATA_GetMyStatusByNetId(ICA_ANIME_GetField1C(gameSystem), partnerNetId), work->myStatus);
    if (INTRUDE_COMM_IsSessionActive(&sys->session) == 1) {
        MI_CpuCopy8(INTRUDE_COMM_GetActiveSessionRequest(&sys->session), &work->member, 0x34);
    }
    EVENT_COMM_COMMON_InitMsgBox(&work->msgBox, gameSystem);
    INTRUDE_COMM_SetState(sys, 1);
    INTRUDE_COMM_ClearNotice(sys);
    sys->peerFlags = 0;
}



void EVENT_COMM_COMMON_ExitCommonWork(IntrudeCommSys *sys, EventCommCommonWork *work)
{
    EVENT_COMM_COMMON_DeleteChoice(&work->msgBox);
    EVENT_COMM_COMMON_ExitMsgBox(&work->msgBox);
    if (sys != 0) {
        INTRUDE_COMM_SetState(sys, 0);
        INTRUDE_COMM_InitRequest(sys, 4);
        INTRUDE_COMM_ClearNotice(sys);
    }
}



/*
 * Talk event: the player talked to the partner. State 0 hands a copy of the
 * common work (lines 493 and 517) to the event of the partner's state; else
 * it sends the talk request and waits for the answer.
 */
int EVENT_COMM_COMMON_TalkEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommTalkWork *work = wk;
    IntrudeCommSys *sys;
    u8 *signal;
    void *copy;
    int requestKind;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(GAME_EVENT_GetGameSystem(event)));
    if (sys == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq <= 6) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 8;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        requestKind = INTRUDE_COMM_GetRequestKind(&sys->session);
        if (sys->peers[work->common.peerSlot].lidClosed == 1) {
            copy = func_02030734((u16)((work->common.heapId & 0x7FFF) | 0x8000), 0x98, 1, sEventCommCommonFile, 493);
            MI_CpuCopy8(work, copy, 0x98);
            if (INTRUDE_COMM_GetSessionResult(&sys->session) == 0 && INTRUDE_COMM_IsSessionActive(&sys->session) == 1
                && INTRUDE_COMM_IsSessionAccepted(&sys->session) == 1 && INTRUDE_COMM_IsRequestFromNetId(&sys->session, work->common.peerSlot) == 1) {
                EVENT_COMM_COMMON_StartMsgScriptEvent(event, copy);
            } else {
                EVENT_COMM_COMMON_StartMsgEvent105(event, copy);
            }
            func_020307B0(copy);
        } else if (sys->peers[work->common.peerSlot].state != 0) {
            copy = func_02030734((u16)((work->common.heapId & 0x7FFF) | 0x8000), 0x98, 1, sEventCommCommonFile, 517);
            MI_CpuCopy8(work, copy, 0x98);
            if (sys->peers[work->common.peerSlot].state == 2) {
                if (requestKind == 5) {
                    EVENT_COMM_COMMON_ChangeSearchFoundEvent(event, copy);
                } else {
                    EVENT_COMM_COMMON_StartMsgEvent95(event, copy);
                }
            } else {
                EVENT_COMM_COMMON_StartMsgEvent105(event, copy);
            }
            func_020307B0(copy);
        } else {
            (*seq)++;
        }
        break;
    case 1:
        if (INTRUDE_CMD_SendReadyNotice(sys) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        switch (INTRUDE_COMM_TakeNoticeState(&sys->session)) {
        case 1:
            work->answer = 1;
            (*seq)++;
            break;
        case 2:
            (*seq)++;
            break;
        }
        break;
    case 3:
        switch (INTRUDE_SUBDISP_MainRequestAnswerSeq(sys, (EventCommCommonWork *)work, &work->answerSeq)) {
        case 1:
            INTRUDE_COMM_ClearRequestResult(sys);
            *seq = 4;
            break;
        case 2:
            *seq = 9;
            break;
        case 3:
            *seq = 7;
            break;
        }
        break;
    case 4:
        if (INTRUDE_COMM_SendNoticeBytes(work->common.peerSlot, work->answer) == 1) {
            (*seq)++;
        }
        break;
    case 5:
        signal = INTRUDE_COMM_GetNotice(sys);
        if (signal != 0) {
            if (signal[1] != work->answer || work->answer == 1) {
                work->common.talkType = 0;
            }
            (*seq)++;
        }
        break;
    case 6:
        EVENT_COMM_COMMON_ChangeTalkTypeEvent(event, &work->common, sys);
        return 0;
    case 7:
        *seq = 9;
        break;
    case 8:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 9;
        }
        break;
    case 9:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        return 1;
    }
    return 0;
}



/*
 * Talked event: the partner talked to this player. Answers the request and
 * changes to the talked type event; skips to state 10 when the visit ends.
 */
int EVENT_COMM_COMMON_TalkedEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommTalkWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    struct GameData *gameData;
    IntrudeCommSys *sys;
    u8 *signal;
    int dir;
    int acmd;
    int failed;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameComm = ICA_ANIME_GetField24(gameSystem);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (sys == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 10) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 10;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        INTRUDE_COMM_ClearRequestResult(sys);
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(work->common.fieldMap));
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 0, GAME_DATA_GetPlayerStatusById(gameData, sys->requestTarget));
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 1);
        (*seq)++;
        break;
    case 1:
        if (FLDMMDL_CheckPossibleAcmd(work->common.playerMmdl) == 1) {
            dir = sys->peers[work->common.peerSlot].package.zoneId;
            if (dir == 2) {
                acmd = 3;
            } else if (dir == 3) {
                acmd = 2;
            } else {
                acmd = 0;
                if (dir != 1) {
                    acmd = 1;
                }
            }
            FLDMMDL_SetAcmd(work->common.playerMmdl, acmd);
            (*seq)++;
        }
        break;
    case 2:
        if (FLDMMDL_EndAcmd(work->common.playerMmdl) == 1) {
            (*seq)++;
        }
        break;
    case 3:
        if (INTRUDE_CMD_SendReadyNotice(sys) == 1) {
            (*seq)++;
        }
        break;
    case 4:
        switch (INTRUDE_COMM_TakeNoticeState(&sys->session)) {
        case 1:
            work->answer = 1;
            (*seq)++;
            break;
        case 2:
            (*seq)++;
            break;
        }
        break;
    case 5:
        if (INTRUDE_COMM_SendReply(sys, sys->requestTarget, sys->requestActive, sys->sentRequestSeq) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            dir = INTRUDE_COMM_TakeRequestResult(sys);
            failed = 0;
            switch (dir) {
            case 0:
                break;
            case 1:
                *seq = 7;
                break;
            case 2:
            case 3:
            default:
                failed = 1;
                break;
            }
            if (failed == 1) {
                EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
                *seq = 10;
            }
        }
        break;
    case 7:
        if (INTRUDE_COMM_SendNoticeBytes(sys->requestTarget, work->answer) == 1) {
            (*seq)++;
        }
        break;
    case 8:
        signal = INTRUDE_COMM_GetNotice(sys);
        if (signal != 0) {
            if (signal[1] != work->answer || work->answer == 1) {
                work->common.talkType = 0;
            }
            *seq = 9;
        }
        break;
    case 9:
        EVENT_COMM_COMMON_ChangeTalkedTypeEvent(event, &work->common, sys);
        return 0;
    case 10:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 11;
        }
        break;
    case 11:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(work->common.fieldMap));
            EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
            return 1;
        }
        break;
    }
    return 0;
}



extern void (*sTalkEventTable[])(struct GameEvent *event, EventCommCommonWork *work);



void EVENT_COMM_COMMON_ChangeTalkTypeEvent(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys)
{
    EventCommCommonWork *copy = func_02030734((u16)((work->heapId & 0x7fff) | 0x8000), 0x98, 1, sEventCommCommonFile, 0x329);
    unsigned int talkType;

    MI_CpuCopy8(work, copy, 0x98);
    talkType = work->talkType;
    if (talkType == 0) {
        EVENT_COMM_COMMON_ChangeTalkMsgEvent(event, copy);
    } else if (talkType == 1) {
        EVENT_COMM_COMMON_StartMsgEvent110Alt(event, copy);
    } else if (talkType == 2) {
        EVENT_COMM_COMMON_ChangeTalkMsgEvent(event, copy);
    } else if (talkType >= 3) {
        if (sTalkEventTable[talkType - 8] == 0) {
            func_02034714(sEmptyTextTalkTable, 0, sEmptyTextTalkTable);
        }
        sTalkEventTable[work->talkType - 8](event, copy);
    } else {
        EVENT_COMM_COMMON_ChangeTalkMsgEvent(event, copy);
    }
    func_020307B0(copy);
}



extern void (*sTalkedEventTable[])(struct GameEvent *event, EventCommCommonWork *work);



void EVENT_COMM_COMMON_ChangeTalkedTypeEvent(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys)
{
    EventCommCommonWork *copy = func_02030734((u16)((work->heapId & 0x7fff) | 0x8000), 0x98, 1, sEventCommCommonFile, 0x354);
    unsigned int talkType;

    MI_CpuCopy8(work, copy, 0x98);
    talkType = work->talkType;
    if (talkType == 0) {
        EVENT_COMM_COMMON_ChangeTalkedMsgEvent(event, copy);
    } else if (talkType == 1) {
        EVENT_COMM_COMMON_StartMsgEvent110Alt(event, copy);
    } else if (talkType == 2) {
        EVENT_COMM_COMMON_ChangeTalkedMsgEvent(event, copy);
    } else if (talkType >= 3) {
        if (sTalkedEventTable[talkType - 8] == 0) {
            func_02034714(sEmptyTextTalkTable, 0, sEmptyTextTalkTable);
        }
        sTalkedEventTable[work->talkType - 8](event, copy);
    } else {
        EVENT_COMM_COMMON_ChangeTalkedMsgEvent(event, copy);
    }
    func_020307B0(copy);
}



static inline int EVENT_COMM_COMMON_GetTalkCase(EventCommCommonWork *work, IntrudeCommSys *sys, u8 myNetId)
{
    if (INTRUDE_COMM_GetSessionResult(&sys->session) == 0 && INTRUDE_COMM_IsSessionActive(&sys->session) == 1) {
        if (INTRUDE_COMM_IsSessionAccepted(&sys->session) == 1) {
            if (INTRUDE_COMM_IsRequestFromNetId(&sys->session, work->peerSlot) == 1)
                return 3;
            if (sys->peers[work->peerSlot].eventJoined == 1)
                return 4;
            return 5;
        }
        if (INTRUDE_COMM_IsRequestFromNetId(&sys->session, myNetId) == 1) {
            if (sys->peers[work->peerSlot].eventJoined == 1)
                return 6;
            return 7;
        }
        if (sys->peers[work->peerSlot].eventJoined == 1)
            return 1;
        if (INTRUDE_COMM_IsRequestFromNetId(&sys->session, work->peerSlot) == 1)
            return 2;
        return 0;
    }
    return 0;
}



int EVENT_COMM_COMMON_GetTalkType(EventCommCommonWork *work, IntrudeCommSys *sys)
{
    u8 myNetId;
    int requestKind;
    int talkType;

    myNetId = (int)GAME_DATA_GetOwnNetId(ICA_ANIME_GetField1C(FIELDMAP_GetGameSystem(work->fieldMap)));
    requestKind = INTRUDE_COMM_GetRequestKind(&sys->session);
    talkType = EVENT_COMM_COMMON_GetTalkCase(work, sys, myNetId);
    if (talkType >= 3) {
        switch (requestKind) {
        case 0: talkType += 8; break;
        case 1: talkType += 13; break;
        case 2: talkType += 18; break;
        case 3: talkType += 23; break;
        case 4: talkType += 28; break;
        case 5: talkType += 33; break;
        }
        talkType -= 3;
    }
    return talkType;
}




struct GameEvent *EVENT_COMM_COMMON_CreateMissionResultEvent(struct GameSystem *gameSystem, int showResult)
{
    struct FieldMap *fieldMap = ICA_ANIME_GetField20(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_MissionResultEventMain, sizeof(EventCommMissionResultWork));
    EventCommMissionResultWork *work = func_020124E8(event);

    MI_CpuFill8(work, 0, sizeof(EventCommMissionResultWork));
    work->heapId = FIELDMAP_GetHeapId(fieldMap);
    work->showResult = showResult;
    return event;
}


/*
 * Mission result event: waits for the result of the visit, shows the
 * mission and the reward, and gives the reward items.
 */
int EVENT_COMM_COMMON_MissionResultEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommMissionResultWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    struct GameData *gameData;
    IntrudeCommSys *sys;
    IntrudeResultRecord *result;
    void *battleRec;
    void *myItem;
    u32 count;
    u32 reward;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameComm = ICA_ANIME_GetField24(gameSystem);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    ICA_ANIME_GetField20(gameSystem);
    switch (*seq) {
    case 0:
        sys = 0;
        if (GAME_COMM_GetKind(gameComm) == 2) {
            sys = GAME_COMM_GetWork(gameComm);
        }
        if (work->showResult == 0) {
            if (sys != 0 && func_0200FB24() == 0 && INTRUDE_COMM_HasResultReward(sys, &sys->session) == 1) {
                sys->abortFlag = 1;
            }
            return 1;
        }
        if (sys != 0 && INTRUDE_COMM_HasResult(&sys->session) == 1 && INTRUDE_COMM_GetPartnerTallyValid(sys) == 1) {
            if (INTRUDE_COMM_HasResultReward(sys, &sys->session) == 0) {
                return 1;
            }
            work->tallyCountA = sys->partnerTally.countA;
            work->tallyCountB = sys->partnerTally.countB;
            EVENT_COMM_COMMON_InitMsgBox(&work->msgBox, gameSystem);
            result = INTRUDE_COMM_GetSessionResult(&sys->session);
            battleRec = GAME_DATA_GetLastBattleRecSlot(gameData);
            if (result == 0) {
                func_02034714(sEmptyTextResult, 0, sEmptyTextResult);
            }
            work->result = *result;
            work->missionKind = result->record.head.kind;
            work->missionPoint = result->record.head.pointIndex;
            work->hasReward = INTRUDE_COMM_HasResultReward(sys, &sys->session);
            work->rewardCount = INTRUDE_COMM_GetResultCount(sys, &sys->session);
            INTRUDE_AddMissionBonusScore(battleRec, work->tallyCountB);
            INTRUDE_AddMissionScore(battleRec, work->tallyCountA);
            (*seq)++;
            break;
        }
        if (sys == 0 || func_0200FB24() != 0) {
            return 1;
        }
        break;
    case 1:
        INTRUDE_COMM_SetWordSetRequest(&work->result.record, &work->result.record.name, work->msgBox.wordSet, work->heapId);
        EVENT_COMM_COMMON_SetupListWindowB(&work->msgBox, gameSystem, 1, 4, 0x1E, 0x10);
        EVENT_COMM_COMMON_PrintListWindowB(&work->msgBox, work->missionKind, 8, 0);
        EVENT_COMM_COMMON_PrintListWindowB(&work->msgBox, work->missionPoint, 8, 0x10);
        (*seq)++;
        break;
    case 2:
        work->waitFrames++;
        if (work->waitFrames > 60) {
            EVENT_COMM_COMMON_DeleteListWindowB(&work->msgBox);
            *seq = 3;
        }
        break;
    case 3:
        if (work->hasReward == 1) {
            EVENT_COMM_COMMON_PrintListWindow(&work->msgBox, 0x19, 0, 0);
            GAME_EVENT_CallEvent(event, func_02029830(gameSystem, 0x52C));
            *seq = 4;
        } else {
            EVENT_COMM_COMMON_PrintListWindow(&work->msgBox, 0x17, 0, 0);
            GAME_EVENT_CallEvent(event, func_02029830(gameSystem, 0x52D));
            *seq = 11;
        }
        break;
    case 4:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GAME_EVENT_CallEvent(event, func_02029620(gameSystem, 0, 6));
            myItem = GAME_DATA_GetMyItem(gameData);
            count = func_02007FB8(myItem, 0x23F, work->heapId);
            reward = work->rewardCount;
            if (func_0200823C(0x23F) < count + reward) {
                reward = func_0200823C(0x23F) - count;
            }
            func_02007E50(myItem, 0x23F, reward, work->heapId);
            INTRUDE_IncrementMissionClearCount(INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(gameData)));
            WORDSET_SetSlotNumber(work->msgBox.wordSet, 0, work->rewardCount, 3, 0, 1);
            EVENT_COMM_COMMON_PrintMsg(&work->msgBox, 0x18);
            (*seq)++;
        }
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (work->tallyCountB != 0) {
            WORDSET_SetSlotNumber(work->msgBox.wordSet, 0, work->tallyCountB, 3, 0, 1);
            EVENT_COMM_COMMON_PrintMsg(&work->msgBox, 0x30);
            (*seq)++;
        } else {
            *seq = 8;
        }
        break;
    case 7:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 8:
        if (work->tallyCountA != 0) {
            WORDSET_SetSlotNumber(work->msgBox.wordSet, 0, work->tallyCountA, 3, 0, 1);
            EVENT_COMM_COMMON_PrintMsg(&work->msgBox, 0x31);
            (*seq)++;
        } else {
            *seq = 10;
        }
        break;
    case 9:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 10;
        }
        break;
    case 10:
        *seq = 12;
        break;
    case 11:
        if (GFL_USE_IsBgmPlaying() == 0) {
            GAME_EVENT_CallEvent(event, func_02029620(gameSystem, 0, 6));
            *seq = 12;
        }
        break;
    case 12:
        EVENT_COMM_COMMON_ExitMsgBox(&work->msgBox);
        GAME_EVENT_ChangeEvent(event, INTRUDE_SUBDISP_CreateDisconnectEvent(gameSystem, 0));
        return 0;
    }
    return 0;
}

void EVENT_COMM_COMMON_ChangeTalkMsgEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkMsgEventMain, 0xA8);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkMsgEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    struct GameData *gameData = ICA_ANIME_GetField1C(gameSystem);
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, GAME_DATA_GetPlayerStatusById(gameData, work->peerSlot));
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkMsgIds[work->msgIndex]);
        *seq = *seq + 1;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = *seq + 1;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = *seq + 1;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedMsgEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    EVENT_COMM_COMMON_ChangeTalkMsgEvent(event, src);
}


void EVENT_COMM_COMMON_ChangeTalkPowerGiftTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkPowerGiftTargetEventMain, 0xA4);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


/*
 * Mission achieve event: the player talked to the target of the mission.
 * Reports the achievement, then starts the mission result event.
 */
int EVENT_COMM_COMMON_TalkPowerGiftTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommMissionTalkWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    if (sys == 0 && *seq <= 1) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 5) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 5;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        if (INTRUDE_CMD_SendProposal(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 1:
        if (INTRUDE_COMM_GetJoinStatus(sys, &sys->session) != 0) {
            work->achieved = 1;
            (*seq)++;
        }
        break;
    case 2:
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 0, work->common.myStatus);
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 1, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem)));
        WORDSET_SetSlotFromMsgA0(work->common.msgBox.wordSet, 2, work->common.member.head.param.x);
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sMissionAchieveMsgIdsA[work->common.msgIndex]);
        (*seq)++;
        break;
    case 3:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sMissionAchieveMsgIdsB[work->common.msgIndex]);
            (*seq)++;
        }
        break;
    case 4:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sMissionAchieveMsgIdsC[work->common.msgIndex]);
            GFL_USE_PlaySeDefaultVolume(0x5E0);
            (*seq)++;
        }
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            *seq = 6;
        }
        break;
    case 6:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 7;
        }
        break;
    case 7:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        GAME_EVENT_ChangeEvent(event, EVENT_COMM_COMMON_CreateMissionResultEvent(gameSystem, work->achieved));
        return 0;
    }
    return 0;
}

void EVENT_COMM_COMMON_ChangeTalkPowerGiftAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkPowerGiftAsTargetEventMain, 0xA4);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkPowerGiftAsTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 1, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem)));
        WORDSET_SetSlotFromMsgA0(work->msgBox.wordSet, 2, work->member.head.param.x);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkPowerGiftAsTargetMsgIds[work->msgIndex]);
        *seq = *seq + 1;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedPowerGiftAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkedPowerGiftAsTargetEventMain, 0xA4);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkedPowerGiftAsTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 1, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem)));
        WORDSET_SetSlotFromMsgA0(work->msgBox.wordSet, 2, work->member.head.param.x);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkedPowerGiftAsTargetMsgIds[work->msgIndex]);
        *seq = *seq + 1;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedPowerGiftTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkedPowerGiftTargetEventMain, 0xA4);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


/*
 * Talked event: shows the notice, activates the G-Power of the mission
 * argument (overlay 83), then reopens the text box for the closing message.
 */
int EVENT_COMM_COMMON_TalkedPowerGiftTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommGPowerTalkWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    EventCommGPowerParam param;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 0, work->common.myStatus);
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 1, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem)));
        WORDSET_SetSlotFromMsgA0(work->common.msgBox.wordSet, 2, work->common.member.head.param.x);
        work->msgIndex = work->common.msgIndex;
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sTalkedPowerGiftTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        EVENT_COMM_COMMON_ExitMsgBox(&work->common.msgBox);
        param.powerId = work->common.member.head.param.x;
        param.arg = 0;
        GAME_EVENT_CallEvent(event, GAME_EVENT_CreateOverlayEvent(gameSystem, (u32)ov083_id, GPOWER_EVENT_CreateActivateEvent, &param));
        (*seq)++;
        break;
    case 3:
        *seq = 4;
        break;
    case 4:
        EVENT_COMM_COMMON_InitMsgBox(&work->common.msgBox, gameSystem);
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 0, work->common.myStatus);
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sTalkedPowerGiftEndMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1 && EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            (*seq)++;
        }
        break;
    case 6:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkPowerShareTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkPowerShareTargetEventMain, 0xA0);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkPowerShareTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 1, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem)));
        WORDSET_SetSlotFromMsgA0(work->msgBox.wordSet, 2, work->member.head.param.x);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkPowerShareTargetMsgIds[work->msgIndex]);
        *seq = *seq + 1;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkPowerShareAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkPowerShareAsTargetEventMain, 0xA0);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


/* Talk event: shows the notice, then activates the G-Power of the mission argument (overlay 83). */
int EVENT_COMM_COMMON_TalkPowerShareAsTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    EventCommGPowerParam param;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 1, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem)));
        WORDSET_SetSlotFromMsgA0(work->msgBox.wordSet, 2, work->member.head.param.x);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkPowerShareAsTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        EVENT_COMM_COMMON_ExitMsgBox(&work->msgBox);
        param.powerId = work->member.head.param.x;
        param.arg = 0;
        GAME_EVENT_CallEvent(event, GAME_EVENT_CreateOverlayEvent(gameSystem, (u32)ov083_id, GPOWER_EVENT_CreateActivateEvent, &param));
        (*seq)++;
        break;
    case 3:
        *seq = 4;
        break;
    case 4:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedPowerShareAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkedPowerShareAsTargetEventMain, 0xA0);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


/* Talked event: the mission is achieved; reports it, then starts the mission result event. */
int EVENT_COMM_COMMON_TalkedPowerShareAsTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommMissionTalkWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    if (sys == 0 && *seq <= 1) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 4) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 4;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        if (INTRUDE_CMD_SendProposal(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 1:
        if (INTRUDE_COMM_GetJoinStatus(sys, &sys->session) != 0) {
            work->achieved = 1;
            (*seq)++;
        }
        break;
    case 2:
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 0, work->common.myStatus);
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 1, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem)));
        WORDSET_SetSlotFromMsgA0(work->common.msgBox.wordSet, 2, work->common.member.head.param.x);
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sTalkedPowerShareAchieveMsgIdsA[work->common.msgIndex]);
        (*seq)++;
        break;
    case 3:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sTalkedPowerShareAchieveMsgIdsB[work->common.msgIndex]);
            GFL_USE_PlaySeDefaultVolume(0x5E0);
            (*seq)++;
        }
        break;
    case 4:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            *seq = 5;
        }
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 6;
        }
        break;
    case 6:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        GAME_EVENT_ChangeEvent(event, EVENT_COMM_COMMON_CreateMissionResultEvent(gameSystem, work->achieved));
        return 0;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedPowerShareTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkedPowerShareTargetEventMain, 0xA0);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkedPowerShareTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem = GAME_EVENT_GetGameSystem(event);
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 1, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem)));
        WORDSET_SetSlotFromMsgA0(work->msgBox.wordSet, 2, work->member.head.param.x);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkedPowerShareTargetMsgIds[work->msgIndex]);
        *seq = *seq + 1;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}

void EVENT_COMM_COMMON_ChangeTalkBattleTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    struct GameSystem *gameSystem;
    EventCommBattleTalkWork *work;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_BattleRequestEventMain, sizeof(EventCommBattleTalkWork));
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
    work->battle.isTalked = 0;
    work->battle.gameSystem = gameSystem;
    work->battle.partnerNetId = src->peerSlot;
    work->battle.battleArg = src->member.head.param.x;
    work->battle.linkMode = 2;
}


/*
 * Battle request event: asks the partner for a battle, waits for both
 * players to be ready, runs the link battle, then starts the mission
 * result event or the disconnect event.
 */
int EVENT_COMM_COMMON_BattleRequestEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommBattleTalkWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    IntrudeCommSys *sys;
    struct GameEvent *next;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameComm = ICA_ANIME_GetField24(gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (sys == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 13) {
            EVENT_COMM_COMMON_InitMsgBox(&work->common.msgBox, gameSystem);
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 13;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 0, work->common.myStatus);
        WORDSET_SetSlotNumber(work->common.msgBox.wordSet, 1, work->battle.battleArg, 3, 0, 1);
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, work->battle.isTalked == 0 ? sBattleRequestMsgIds[work->common.msgIndex] : sBattleRequestTalkedMsgIds[work->common.msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            switch (INTRUDE_COMM_TakeRequestResult(sys)) {
            case 4:
                *seq = 2;
                break;
            case 2:
            case 3:
                *seq = 11;
                break;
            default:
                if ((KEY_GetTrg() & 2) && INTRUDE_COMM_SendAnswer(sys->requestTarget, sys->sentRequestSeq) == 1) {
                    INTRUDE_COMM_NextRequestToken(sys);
                    *seq = 12;
                }
                break;
            }
        }
        break;
    case 2:
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sBattleRequestAcceptedMsgIds[work->common.msgIndex]);
        *seq = 3;
        break;
    case 3:
        if (INTRUDE_CMD_SendProposal(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 4:
        if (INTRUDE_COMM_GetJoinStatus(sys, &sys->session) != 0) {
            INTRUDE_COMM_SetLock(sys, 1);
            *seq = 5;
        }
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1 && INTRUDE_COMM_SendPeerFlags(sys, work->common.peerSlot, 1) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (func_0215839C(sys, 1, work->common.peerSlot) == 1) {
            *seq = 7;
        } else if ((KEY_GetTrg() & 2) && INTRUDE_COMM_SendAnswer(sys->requestTarget, sys->sentRequestSeq) == 1) {
            INTRUDE_COMM_NextRequestToken(sys);
            *seq = 12;
        }
        break;
    case 7:
        if (INTRUDE_COMM_SendPeerFlags(sys, work->common.peerSlot, 2) == 1) {
            (*seq)++;
        }
        break;
    case 8:
        if (func_0215839C(sys, 2, work->common.peerSlot) == 1) {
            EVENT_COMM_COMMON_ExitMsgBox(&work->common.msgBox);
            *seq = 9;
        } else if (INTRUDE_COMM_TakeRequestResult(sys) == 3) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 13;
        }
        break;
    case 9:
        work->battleDone = 1;
        GAME_EVENT_CallEvent(event, INTRUDE_LINK_CreateEvent(gameSystem, &work->battle));
        (*seq)++;
        break;
    case 10:
        EVENT_COMM_COMMON_InitMsgBox(&work->common.msgBox, gameSystem);
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sBattleRequestEndMsgIds[work->common.msgIndex]);
        *seq = 13;
        break;
    case 11:
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sBattleRequestRefusedMsgIds[work->common.msgIndex]);
        *seq = 13;
        break;
    case 12:
        work->canceled = 1;
        *seq = 15;
        break;
    case 13:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            *seq = 14;
        }
        break;
    case 14:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 15;
        }
        break;
    case 15:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        if (GAME_COMM_GetKind(gameComm) == 2 && GAME_COMM_GetWork(gameComm) != 0) {
            INTRUDE_COMM_SetLock(GAME_COMM_GetWork(gameComm), 0);
        }
        if (work->battleDone == 1) {
            next = EVENT_COMM_COMMON_CreateMissionResultEvent(gameSystem, work->battleDone);
        } else if (work->canceled == 0) {
            next = INTRUDE_SUBDISP_CreateDisconnectEvent(gameSystem, 1);
        } else {
            next = INTRUDE_SUBDISP_CreateDisconnectEvent(gameSystem, 0);
        }
        GAME_EVENT_ChangeEvent(event, next);
        return 0;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkBattleAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    struct GameSystem *gameSystem;
    EventCommBattleTalkWork *work;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_BattleAnswerEventMain, sizeof(EventCommBattleTalkWork));
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
    work->battle.isTalked = 0;
    work->battle.gameSystem = gameSystem;
    work->battle.partnerNetId = work->common.peerSlot;
    work->battle.battleArg = src->member.head.param.x;
    work->battle.linkMode = 2;
}


/*
 * Battle answer event: the partner asked for a battle; asks the player yes
 * or no, sends the answer and on yes runs the link battle.
 */
int EVENT_COMM_COMMON_BattleAnswerEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommBattleTalkWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    IntrudeCommSys *sys;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameComm = ICA_ANIME_GetField24(gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (sys == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 14 && *seq != 1 && *seq != 2) {
            EVENT_COMM_COMMON_InitMsgBox(&work->common.msgBox, gameSystem);
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 14;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 0, work->common.myStatus);
        WORDSET_SetSlotNumber(work->common.msgBox.wordSet, 1, work->battle.battleArg, 3, 0, 1);
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, work->battle.isTalked == 0 ? sBattleAnswerMsgIds[work->common.msgIndex] : sBattleAnswerTalkedMsgIds[work->common.msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            EVENT_COMM_COMMON_StartChoice(&work->common.msgBox, gameSystem);
            (*seq)++;
        }
        break;
    case 2:
        switch (EVENT_COMM_COMMON_PollChoice(&work->common.msgBox)) {
        case 0:
            EVENT_COMM_COMMON_DeleteChoice(&work->common.msgBox);
            *seq = 3;
            break;
        case 1:
            EVENT_COMM_COMMON_DeleteChoice(&work->common.msgBox);
            *seq = 11;
            break;
        }
        break;
    case 3:
        if (INTRUDE_COMM_SendReply(sys, sys->requestTarget, 4, sys->sentRequestSeq) == 1) {
            INTRUDE_COMM_SetLock(sys, 1);
            *seq = 4;
        }
        break;
    case 4:
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sBattleAnswerAcceptedMsgIds[work->common.msgIndex]);
        (*seq)++;
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1 && INTRUDE_COMM_SendPeerFlags(sys, work->common.peerSlot, 1) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (func_0215839C(sys, 1, work->common.peerSlot) == 1) {
            *seq = 7;
        } else if (KEY_GetTrg() & 2) {
            if (INTRUDE_COMM_SendAnswer(sys->requestTarget, sys->sentRequestSeq) == 1) {
                INTRUDE_COMM_NextRequestToken(sys);
                *seq = 13;
                GAME_COMM_RequestExitNoCallback(gameComm);
            }
        } else if (INTRUDE_COMM_TakeRequestResult(sys) == 3) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 14;
        }
        break;
    case 7:
        if (INTRUDE_COMM_SendPeerFlags(sys, work->common.peerSlot, 2) == 1) {
            (*seq)++;
        }
        break;
    case 8:
        if (func_0215839C(sys, 2, work->common.peerSlot) == 1) {
            EVENT_COMM_COMMON_ExitMsgBox(&work->common.msgBox);
            *seq = 9;
        } else if (INTRUDE_COMM_TakeRequestResult(sys) == 3) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 14;
        }
        break;
    case 9:
        GAME_EVENT_CallEvent(event, INTRUDE_LINK_CreateEvent(gameSystem, &work->battle));
        (*seq)++;
        break;
    case 10:
        EVENT_COMM_COMMON_InitMsgBox(&work->common.msgBox, gameSystem);
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sBattleAnswerEndMsgIds[work->common.msgIndex]);
        *seq = 14;
        break;
    case 11:
        if (INTRUDE_COMM_SendReply(sys, sys->requestTarget, 2, sys->sentRequestSeq) == 1) {
            INTRUDE_COMM_PickEntryForKind(GAME_DATA_GetLastBattleRecSlot(ICA_ANIME_GetField1C(gameSystem)), 0);
            *seq = 12;
        }
        break;
    case 12:
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sBattleAnswerRefusedMsgIds[work->common.msgIndex]);
        *seq = 14;
        break;
    case 13:
        *seq = 16;
        break;
    case 14:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            *seq = 15;
        }
        break;
    case 15:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 16;
        }
        break;
    case 16:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        if (GAME_COMM_GetKind(gameComm) == 2 && GAME_COMM_GetWork(gameComm) != 0) {
            INTRUDE_COMM_SetLock(GAME_COMM_GetWork(gameComm), 0);
        }
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedBattleAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    struct GameSystem *gameSystem;
    EventCommBattleTalkWork *work;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_BattleRequestEventMain, sizeof(EventCommBattleTalkWork));
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
    work->battle.isTalked = 1;
    work->battle.gameSystem = gameSystem;
    work->battle.partnerNetId = work->common.peerSlot;
    work->battle.battleArg = src->member.head.param.x;
    work->battle.linkMode = 2;
}


void EVENT_COMM_COMMON_ChangeTalkedBattleTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    struct GameSystem *gameSystem;
    EventCommBattleTalkWork *work;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_BattleAnswerEventMain, sizeof(EventCommBattleTalkWork));
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
    work->battle.isTalked = 1;
    work->battle.gameSystem = gameSystem;
    work->battle.partnerNetId = work->common.peerSlot;
    work->battle.battleArg = src->member.head.param.x;
    work->battle.linkMode = 2;
}

void EVENT_COMM_COMMON_ChangeTalkSearchTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkSearchTargetEventMain, 0xA4);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkSearchTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(GAME_EVENT_GetGameSystem(event)));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkSearchTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 3;
        }
        break;
    case 3:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 4;
        }
        break;
    case 4:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkSearchAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkSearchAsTargetEventMain, 0xA4);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkSearchAsTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(GAME_EVENT_GetGameSystem(event)));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkSearchAsTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedSearchAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkedSearchAsTargetEventMain, 0xA4);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


/* Talked event: shows the notice; when the visit is still running, warps back to the palace. */
int EVENT_COMM_COMMON_TalkedSearchAsTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    IntrudeCommSys *sys;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameComm = ICA_ANIME_GetField24(gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkedSearchAsTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        if (INTRUDE_COMM_GetWorkIfRunning(gameComm) != 0) {
            GFL_USE_PlaySeDefaultVolume(0x737);
            GAME_EVENT_ChangeEvent(event, INTRUDE_SUBDISP_CreatePalaceWarpEvent(gameSystem));
            return 0;
        }
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedSearchTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkedSearchTargetEventMain, 0xA4);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkedSearchTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(GAME_EVENT_GetGameSystem(event)));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkedSearchTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeSearchFoundEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_SearchFoundEventMain, 0xA4);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


/*
 * Talk event of the found partner: waits for the session answer, reports
 * the mission, then starts the mission result event.
 */
int EVENT_COMM_COMMON_SearchFoundEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommMissionTalkWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    int joinStatus;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    if (sys == 0 && *seq <= 2 && *seq < 6) {
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
        *seq = 6;
        work->disconnected = 1;
        return 0;
    }
    switch (*seq) {
    case 0:
        if (INTRUDE_CMD_SendProposal(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 1:
        joinStatus = work->joinStatus = INTRUDE_COMM_GetJoinStatus(sys, &sys->session);
        switch (joinStatus) {
        case 1:
            *seq = 2;
            break;
        case 2:
            *seq = 5;
            break;
        }
        break;
    case 2:
        if (INTRUDE_COMM_SendSupportMode(sys, work->common.peerSlot, 2) == 1) {
            (*seq)++;
        }
        break;
    case 3:
        work->achieved = 1;
        INTRUDE_COMM_SetWordSetRequest(&work->common.member, &work->common.member.name, work->common.msgBox.wordSet, work->common.heapId);
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sSearchFoundMsgIdsA[work->common.msgIndex]);
        (*seq)++;
        break;
    case 4:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sSearchFoundMsgIdsB[work->common.msgIndex]);
            GFL_USE_PlaySeDefaultVolume(0x5E0);
            *seq = 6;
        }
        break;
    case 5:
        work->achieved = 1;
        INTRUDE_COMM_SetWordSetRequest(&work->common.member, &work->common.member.name, work->common.msgBox.wordSet, work->common.heapId);
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sSearchFoundOtherMsgIds[work->common.msgIndex]);
        *seq = 6;
        break;
    case 6:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            *seq = 7;
        }
        break;
    case 7:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 8;
        }
        break;
    case 8:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        if (work->joinStatus == 1) {
            GAME_EVENT_ChangeEvent(event, EVENT_COMM_COMMON_CreateMissionResultEvent(gameSystem, work->achieved));
            return 0;
        }
        return 1;
    }
    return 0;
}


/* Message event after a link battle: thanks the player whose support record is active. */
struct GameEvent *EVENT_COMM_COMMON_CreateSupportMsgEvent(struct GameSystem *gameSystem, u32 heapId)
{
    void *pmsWork;
    struct GameEvent *event;
    EventCommSupportMsgWork *work;

    pmsWork = GAME_DATA_GetPmsWork(ICA_ANIME_GetField1C(gameSystem));
    event = func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_SupportMsgEventMain, sizeof(EventCommSupportMsgWork));
    work = func_020124E8(event);
    work->myStatus = MYSTATUS_Create(heapId);
    MYSTATUS_Copy(COMM_PLAYER_SUPPORT_GetActiveRecord(pmsWork), work->myStatus);
    EVENT_COMM_COMMON_InitMsgBox(&work->msgBox, gameSystem);
    return event;
}


int EVENT_COMM_COMMON_SupportMsgEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommSupportMsgWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameEvent *script;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, 0x1C);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        EVENT_COMM_COMMON_ExitMsgBox(&work->msgBox);
        script = SCRIPT_SYS_CreateScriptEventSimple(gameSystem, 0xAFD, 0, 4);
        SCRIPT_WORK_SetParams(SCRIPT_SYS_GetEventScriptWork(script), 0x1C, 1, 0, 0);
        GAME_EVENT_CallEvent(event, script);
        (*seq)++;
        break;
    case 3:
        *seq = 4;
        break;
    case 4:
        func_020307B0(work->myStatus);
        return 1;
    }
    return 0;
}

void EVENT_COMM_COMMON_ChangeTalkGreetingTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkGreetingTargetEventMain, 0x9C);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkGreetingTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(GAME_EVENT_GetGameSystem(event)));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkGreetingTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkGreetingAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkGreetingAsTargetEventMain, 0x9C);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkGreetingAsTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(GAME_EVENT_GetGameSystem(event)));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkGreetingAsTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedGreetingAsTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkedGreetingAsTargetEventMain, 0x9C);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
}


/* Talked event: shows the notice; when the visit is still running, warps back to the palace. */
int EVENT_COMM_COMMON_TalkedGreetingAsTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkedGreetingAsTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        if (sys != 0) {
            GFL_USE_PlaySeDefaultVolume(0x737);
            GAME_EVENT_ChangeEvent(event, INTRUDE_SUBDISP_CreatePalaceWarpEvent(gameSystem));
            return 0;
        }
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedGreetingTargetEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_TalkedGreetingTargetEventMain, 0x9C);
    MI_CpuCopy8(src, func_020124E8(event), sizeof(EventCommCommonWork));
}


int EVENT_COMM_COMMON_TalkedGreetingTargetEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(GAME_EVENT_GetGameSystem(event)));
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, work->myStatus);
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, sTalkedGreetingTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, work);
        return 1;
    }
    return 0;
}


/* Offer event: keeps the field objects still while the offer answer event runs. */
struct GameEvent *EVENT_COMM_COMMON_CreateOfferEvent(struct GameSystem *gameSystem, IntrudeCommSys *sys, IntrudeMemberRecord *offer)
{
    struct GameEvent *event;
    event = func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_OfferEventMain, sizeof(IntrudeMemberRecord));
    *(IntrudeMemberRecord *)func_020124E8(event) = *offer;
    return event;
}


int EVENT_COMM_COMMON_OfferEventMain(struct GameEvent *event, int *seq, void *wk)
{
    IntrudeMemberRecord *offer = wk;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    fieldMap = ICA_ANIME_GetField20(gameSystem);
    switch (*seq) {
    case 0:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(fieldMap));
        GAME_EVENT_CallEvent(event, EVENT_COMM_COMMON_CreateOfferAnswerEvent(gameSystem, offer));
        (*seq)++;
        break;
    case 1:
        if (fieldMap != 0 && FIELDMAP_IsReady(fieldMap) == 1) {
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(fieldMap));
            return 1;
        }
        break;
    }
    return 0;
}


struct GameEvent *EVENT_COMM_COMMON_CreateOfferAnswerEvent(struct GameSystem *gameSystem, IntrudeMemberRecord *offer)
{
    void *myStatus;
    struct GameEvent *event;
    EventCommOfferWork *work;
    struct GameData *gameData;
    IntrudeParamPair *param;

    gameData = ICA_ANIME_GetField1C(gameSystem);
    param = &offer->head.param;
    myStatus = GAME_DATA_GetMyStatus(gameData);
    event = func_020122C0(gameSystem, 0, EVENT_COMM_COMMON_OfferAnswerEventMain, sizeof(EventCommOfferWork));
    work = func_020124E8(event);
    func_020084F8(myStatus, work->myName, 8);
    work->itemId = param->y;
    work->offerArg = param->x;
    work->senderNetId = offer->name.netId;
    EVENT_COMM_COMMON_InitMsgBox(&work->msgBox, gameSystem);
    return event;
}


/*
 * Offer answer event: accepts the offer of another player, sends this
 * player's name to the sender, then starts the mission result event.
 */
int EVENT_COMM_COMMON_OfferAnswerEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommOfferWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    struct GameData *gameData;
    IntrudeCommSys *sys;
    int msgId;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameComm = ICA_ANIME_GetField24(gameSystem);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    ICA_ANIME_GetField20(gameSystem);
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (sys == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 0) {
            return 0;
        }
        if (*seq < 4) {
            EVENT_COMM_COMMON_PrintMsg(&work->msgBox, 6);
            *seq = 4;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        if (INTRUDE_CMD_SendProposal(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 1:
        if ((work->joinStatus = INTRUDE_COMM_GetJoinStatus(sys, &sys->session)) != 0) {
            (*seq)++;
        }
        break;
    case 2:
        WORDSET_SetSlotMyStatus(work->msgBox.wordSet, 0, GAME_DATA_GetMyStatus(gameData));
        WORDSET_Callback_EF40(work->msgBox.wordSet, 1, work->itemId);
        if (work->joinStatus == 1) {
            msgId = sOfferAnswerMsgIds[EVENT_COMM_COMMON_GetPeerTalkStatus(sys, (int)GAME_DATA_GetOwnNetId(gameData))];
            work->accepted = 1;
        } else {
            msgId = 5;
        }
        EVENT_COMM_COMMON_PrintMsg(&work->msgBox, msgId);
        (*seq)++;
        break;
    case 3:
        if (work->accepted == 1) {
            if (INTRUDE_COMM_SendProfile((u8)work->senderNetId, work->myName) == 1) {
                (*seq)++;
            }
        } else {
            (*seq)++;
        }
        break;
    case 4:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->msgBox) == 1) {
            *seq = 5;
        }
        break;
    case 5:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 6;
        }
        break;
    case 6:
        EVENT_COMM_COMMON_ExitMsgBox(&work->msgBox);
        GAME_EVENT_ChangeEvent(event, EVENT_COMM_COMMON_CreateMissionResultEvent(gameSystem, work->accepted));
        return 0;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkItemSaleEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    EventCommCommonWork *work;
    u16 *itemId;
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_ItemSaleEventMain, sizeof(EventCommItemSaleWork));
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
    itemId = &work->member.head.param.x;
    if (INTRUDE_COMM_IsValidProfileCode(*itemId) == 0) {
        *itemId = 17;
    }
}


/*
 * Item sale event: offers the item to the partner for the price and waits
 * for the answer, then starts the mission result event or the disconnect
 * event.
 */
int EVENT_COMM_COMMON_ItemSaleEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommItemSaleWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    IntrudeParamPair *sale;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(ICA_ANIME_GetField24(gameSystem));
    if (sys == 0 && *seq <= 4) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 9) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 9;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 0, work->common.myStatus);
        sale = &work->common.member.head.param;
        WORDSET_Callback_EF40(work->common.msgBox.wordSet, 1, sale->x);
        WORDSET_SetSlotNumber(work->common.msgBox.wordSet, 2, sale->y, 5, 0, 1);
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 3, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem)));
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemSaleMsgIds[0][work->common.msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            switch (INTRUDE_COMM_TakeRequestResult(sys)) {
            case 7:
                *seq = 2;
                break;
            case 3:
            case 8:
                *seq = 5;
                break;
            case 9:
                *seq = 6;
                break;
            case 10:
                *seq = 7;
                break;
            default:
                if ((KEY_GetTrg() & 2) && INTRUDE_COMM_SendAnswer(sys->requestTarget, sys->sentRequestSeq) == 1) {
                    INTRUDE_COMM_NextRequestToken(sys);
                    work->canceled = 1;
                    *seq = 8;
                }
                break;
            }
        }
        break;
    case 2:
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemSaleMsgIds[4][work->common.msgIndex]);
        (*seq)++;
        break;
    case 3:
        if (INTRUDE_CMD_SendProposal(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 4:
        if (INTRUDE_COMM_GetJoinStatus(sys, &sys->session) != 0) {
            work->sold = 1;
            *seq = 9;
        }
        break;
    case 5:
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemSaleMsgIds[1][work->common.msgIndex]);
        *seq = 9;
        break;
    case 6:
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemSaleMsgIds[2][work->common.msgIndex]);
        *seq = 9;
        break;
    case 7:
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemSaleMsgIds[3][work->common.msgIndex]);
        *seq = 9;
        break;
    case 8:
        *seq = 11;
        break;
    case 9:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            *seq = 10;
        }
        break;
    case 10:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 11;
        }
        break;
    case 11:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        if (work->sold == 1) {
            GAME_EVENT_ChangeEvent(event, EVENT_COMM_COMMON_CreateMissionResultEvent(gameSystem, work->sold));
            return 0;
        }
        if (work->canceled == 0) {
            GAME_EVENT_ChangeEvent(event, INTRUDE_SUBDISP_CreateDisconnectEvent(gameSystem, 2));
            return 0;
        }
        GAME_EVENT_ChangeEvent(event, INTRUDE_SUBDISP_CreateDisconnectEvent(gameSystem, 0));
        return 0;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkItemPurchaseEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_ItemPurchaseEventMain, sizeof(EventCommItemSaleWork));
    MI_CpuCopy8(src, func_020124E8(event), sizeof(EventCommCommonWork));
}


/*
 * Item purchase event: the partner offers an item for a price; asks the
 * player, checks money and bag space, sends the answer and on yes pays and
 * takes the item.
 */
int EVENT_COMM_COMMON_ItemPurchaseEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommItemSaleWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct GameComm *gameComm;
    IntrudeCommSys *sys;
    IntrudeParamPair *sale;
    int refused;
    int answer;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    gameData = ICA_ANIME_GetField1C(gameSystem);
    gameComm = ICA_ANIME_GetField24(gameSystem);
    sale = &work->common.member.head.param;
    sys = INTRUDE_COMM_GetWorkIfRunning(gameComm);
    if (sys == 0) {
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 8 && *seq != 2 && *seq != 3) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 4);
            *seq = 8;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 0, work->common.myStatus);
        WORDSET_Callback_EF40(work->common.msgBox.wordSet, 1, sale->x);
        WORDSET_SetSlotNumber(work->common.msgBox.wordSet, 2, sale->y, 5, 0, 1);
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 3, GAME_DATA_GetMyStatus(ICA_ANIME_GetField1C(gameSystem)));
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemPurchaseMsgIds[0][work->common.msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemPurchaseMsgIds[1][work->common.msgIndex]);
            (*seq)++;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            EVENT_COMM_COMMON_StartChoice(&work->common.msgBox, gameSystem);
            (*seq)++;
        }
        break;
    case 3:
        answer = EVENT_COMM_COMMON_PollChoice(&work->common.msgBox);
        refused = 0;
        switch (answer) {
        case 0:
            EVENT_COMM_COMMON_DeleteChoice(&work->common.msgBox);
            if (sale->y > BEACON_GetPoints(GAME_DATA_GetMiscSave(gameData))) {
                refused = 1;
                *seq = 5;
            } else if (func_02007E3C(GAME_DATA_GetMyItem(gameData), sale->x, 1, 0x15) == 0) {
                refused = 1;
                *seq = 6;
            } else {
                *seq = 4;
            }
            break;
        case 1:
            EVENT_COMM_COMMON_DeleteChoice(&work->common.msgBox);
            refused = 1;
            *seq = 7;
            break;
        }
        if (refused == 1) {
            INTRUDE_COMM_PickEntryForKind(GAME_DATA_GetLastBattleRecSlot(gameData), 3);
        }
        break;
    case 4:
        if (INTRUDE_COMM_SendReply(sys, sys->requestTarget, 7, sys->sentRequestSeq) == 1) {
            BEACON_SubPoints(GAME_DATA_GetMiscSave(gameData), sale->y);
            func_02007E50(GAME_DATA_GetMyItem(gameData), sale->x, 1, 0x15);
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemPurchaseMsgIds[5][work->common.msgIndex]);
            *seq = 8;
        }
        break;
    case 5:
        if (INTRUDE_COMM_SendReply(sys, sys->requestTarget, 9, sys->sentRequestSeq) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemPurchaseMsgIds[3][work->common.msgIndex]);
            *seq = 8;
        }
        break;
    case 6:
        if (INTRUDE_COMM_SendReply(sys, sys->requestTarget, 10, sys->sentRequestSeq) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemPurchaseMsgIds[4][work->common.msgIndex]);
            *seq = 8;
        }
        break;
    case 7:
        if (INTRUDE_COMM_SendReply(sys, sys->requestTarget, 8, sys->sentRequestSeq) == 1) {
            EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, sItemPurchaseMsgIds[2][work->common.msgIndex]);
            *seq = 8;
        }
        break;
    case 8:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            *seq = 9;
        }
        break;
    case 9:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 10;
        }
        break;
    case 10:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        return 1;
    }
    return 0;
}


void EVENT_COMM_COMMON_ChangeTalkedItemSaleEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    EVENT_COMM_COMMON_ChangeTalkItemSaleEvent(event, src);
}


void EVENT_COMM_COMMON_ChangeTalkedItemPurchaseEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    EVENT_COMM_COMMON_ChangeTalkItemPurchaseEvent(event, src);
}




/*
 * Turns the running event into the message event: the event work is
 * 0xAC bytes, takes the 0x98-byte block of the caller and shows the message
 * msgIds[msgIndex] with the player name in word slot 0.
 */
void EVENT_COMM_COMMON_StartMsgEvent(struct GameEvent *event, EventCommCommonWork *src, u16 *msgIds)
{
    IntrudeCommSys *sys;
    EventCommMsgWork *work;

    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(event)));
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_MsgEventMain, 0xAC);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, 0x98);
    if (sys != 0) {
        work->msgId = msgIds[src->msgIndex];
        WORDSET_SetSlotMyStatus(src->msgBox.wordSet, 0, src->myStatus);
    } else {
        func_02034714(sEmptyTextA, 0, sEmptyTextA);
    }
}




/*
 * Event callback of the message event, in the shape of EVENT_COMM_COMMON_TalkPowerGiftTargetEventMain: print
 * the message, wait for the print to end, wait for a key press, then close
 * the box and end the event.
 */
int EVENT_COMM_COMMON_MsgEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    IntrudeCommSys *sys;
    EventCommMsgWork *work = eventWork;

    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(event)));
    switch (*seq) {
    case 0:
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, work->msgId);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        if (EVENT_COMM_COMMON_IsKeyTrg() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        return 1;
    }
    return 0;
}




/*
 * Leaf (no lr save): tail call to EVENT_COMM_COMMON_StartMsgEvent with the message IDs 95 to 99.
 */
void EVENT_COMM_COMMON_StartMsgEvent95(struct GameEvent *event, EventCommCommonWork *src)
{
    EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds95);
}




/*
 * Leaf (no lr save): tail call to EVENT_COMM_COMMON_StartMsgEvent with the message IDs 105 to 109.
 */
void EVENT_COMM_COMMON_StartMsgEvent105(struct GameEvent *event, EventCommCommonWork *src)
{
    EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds105);
}



/* Message IDs 110 to 114; the table row is the request kind (all rows hold the same IDs). */
void EVENT_COMM_COMMON_StartMsgEvent110ByKindA(struct GameEvent *event, EventCommCommonWork *src)
{
    int kind;

    kind = src->member.head.kind;
    if (kind >= 6) kind = 0;
    EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds110ByKindA[kind]);
}



/* Same as EVENT_COMM_COMMON_StartMsgEvent110ByKindA with a second copy of the table. */
void EVENT_COMM_COMMON_StartMsgEvent110ByKindB(struct GameEvent *event, EventCommCommonWork *src)
{
    int kind;

    kind = src->member.head.kind;
    if (kind >= 6) kind = 0;
    EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds110ByKindB[kind]);
}



void EVENT_COMM_COMMON_StartMsgEvent110(struct GameEvent *event, EventCommCommonWork *src) { EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds110); }



void EVENT_COMM_COMMON_StartMsgEvent110Alt(struct GameEvent *event, EventCommCommonWork *src) { EVENT_COMM_COMMON_StartMsgEvent(event, src, sMsgIds110Alt); }




/*
 * Like EVENT_COMM_COMMON_StartMsgEvent for the script variant (event work 0xA0 bytes, message
 * IDs 125 to 129). It also stores the opposite facing of the local player
 * in the package of the peer: 0 and 1 swap, 2 and 3 swap.
 */
void EVENT_COMM_COMMON_StartMsgScriptEvent(struct GameEvent *event, EventCommCommonWork *src)
{
    IntrudeCommSys *sys;
    EventCommMsgWork *work;
    int facing;

    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(event)));
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_MsgScriptEventMain, 0xA0);
    work = func_020124E8(event);
    MI_CpuCopy8(src, work, 0x98);
    if (sys != 0) {
        facing = 0;
        work->msgId = sMsgIds125[src->msgIndex];
        WORDSET_SetSlotMyStatus(src->msgBox.wordSet, 0, src->myStatus);
    } else {
        func_02034714(sEmptyTextB, 0, sEmptyTextB);
        return;
    }
    if (sys->localPeer.package.zoneId == 2)
        facing = 3;
    else if (sys->localPeer.package.zoneId == 3)
        facing = 2;
    else if (sys->localPeer.package.zoneId != 1)
        facing = 1;
    sys->peers[work->common.peerSlot].package.zoneId = facing;
}


/*
 * Event callback of the script variant of the message event (work set by
 * EVENT_COMM_COMMON_StartMsgScriptEvent): print the message, wait for the print to end, run the
 * script event 0xAFD with the work variables set, close the box and change
 * to the event that INTRUDE_SUBDISP_CreateDisconnectEvent returns.
 */
int EVENT_COMM_COMMON_MsgScriptEventMain(struct GameEvent *event, int *seq, void *eventWork)
{
    EventCommMsgWork *work = eventWork;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    struct GameEvent *scriptEvent;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
    switch (*seq) {
    case 0:
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, work->msgId);
        (*seq)++;
        break;
    case 1:
        if (EVENT_COMM_COMMON_IsPrintFinished(&work->common.msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        EVENT_COMM_COMMON_ExitMsgBox(&work->common.msgBox);
        scriptEvent = SCRIPT_SYS_CreateScriptEventSimple(gameSystem, 0xAFD, 0, 4);
        SCRIPT_WORK_SetParams(SCRIPT_SYS_GetEventScriptWork(scriptEvent), 0x23F, 1, 0, 0);
        GAME_EVENT_CallEvent(event, scriptEvent);
        (*seq)++;
        break;
    case 3:
        *seq = 4;
        break;
    case 4:
        EVENT_COMM_COMMON_ExitCommonWork(sys, &work->common);
        GAME_EVENT_ChangeEvent(event, INTRUDE_SUBDISP_CreateDisconnectEvent(gameSystem, 0));
        return 0;
    }
    return 0;
}
