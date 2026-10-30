/*
 * file:     event_comm_common.c
 * unit:     yes
 * function: EVENT_COMM_COMMON_GetTalkCase, EVENT_COMM_COMMON_GetMissionState, EVENT_COMM_COMMON_GetPeerTalkStatus, EVENT_COMM_COMMON_CmdCallExitSyncEvent, EVENT_COMM_COMMON_CreateExitSyncEvent, EVENT_COMM_COMMON_ExitSyncEventMain, EVENT_COMM_COMMON_CmdGetObjCode, EVENT_COMM_COMMON_CmdCheckMissionInfoPending, EVENT_COMM_COMMON_CmdCallMissionInfoEvent, EVENT_COMM_COMMON_CreateMissionInfoEvent, EVENT_COMM_COMMON_MissionInfoEventMain, EVENT_COMM_COMMON_FreeMissionInfoWork, EVENT_COMM_COMMON_CreateReturnPalaceEvent, EVENT_COMM_COMMON_ReturnPalaceEventMain, EVENT_COMM_COMMON_CmdGetIntrudeDistance, EVENT_COMM_COMMON_CmdCheckBattleRecState, EVENT_COMM_COMMON_CreateTalkStartEvent, EVENT_COMM_COMMON_TalkStartEventMain, EVENT_COMM_COMMON_CreateTalkEvent, EVENT_COMM_COMMON_CreateTalkedStartEvent, EVENT_COMM_COMMON_TalkedStartEventMain, EVENT_COMM_COMMON_CreateTalkedEvent, EVENT_COMM_COMMON_InitCommonWork, EVENT_COMM_COMMON_ExitCommonWork, EVENT_COMM_COMMON_TalkEventMain, EVENT_COMM_COMMON_TalkedEventMain, EVENT_COMM_COMMON_ChangeTalkTypeEvent, EVENT_COMM_COMMON_ChangeTalkedTypeEvent, EVENT_COMM_COMMON_GetTalkType
 * address:  0x0217F5A0
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
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   INTRUDE_COMM_TakeRequestResult  0x02175514  thumb  ov011
 *   KEY_GetTrg  0x020362DC  arm
 *   INTRUDE_COMM_SendAnswer  0x02173B9C  thumb  ov011
 *   INTRUDE_COMM_NextRequestToken  0x021753B8  thumb  ov011
 *   INTRUDE_COMM_SendReply  0x02173AE0  thumb  ov011
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_DATA_GetOwnNetId  0x02012B58  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_GetWork  0x02026474  thumb
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAME_EVENT_CallEvent  0x02012374  thumb
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_IsReady  0x02188BE8  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   FIELD_SOUND_SYSTEM_StartPushAndPlayTask  0x02029830  thumb
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb
 *   FIELD_SOUND_SYSTEM_StartPopAndWaitTask  0x02029620  thumb
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   MSGDATA_Delete  0x02045C04  arm
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GFL_HEAP_Free  0x020307B0  arm
 *   GAME_DATA_GetIntrudeIdByte            0x0215841C  thumb  ov010
 *   GF_PANIC_Fail            0x02034714  arm
 *   ZONEDATA_IsEntralink  0x02013D5C  thumb
 *   INTRUDE_COMM_HasResult  0x02175DA8  thumb  ov011
 *   INTRUDE_COMM_IsSessionAccepted  0x02175B8C  thumb  ov011
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_Delete  0x0201ED04  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   MYSTATUS_GetSex  0x02008550  thumb
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   GAME_DATA_GetLastBattleRecSlot  0x020127B8  thumb
 *   GAME_DATA_GetMyStatusPlayer  0x02012950  thumb
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   MSGDATA_ReadString  0x02045CAC  arm
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
 *   COMM_PLAYER_GetMmdl 0x02167A14 thumb ov010
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
 *   MYITEM_SAVEDATA_GetItemQuantity  0x02007FB8  thumb
 *   MYITEM_SAVEDATA_GetMaxStack  0x0200823C  thumb
 *   MYITEM_SAVEDATA_AddItem  0x02007E50  thumb
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
 *   INTRUDE_COMM_TogglePeerFlags  0x0215839C  thumb  ov010
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
 *   MYSTATUS_CopyNameChars  0x020084F8  thumb
 *   INTRUDE_COMM_SendProfile  0x021745F8  thumb  ov011
 *   WORDSET_SetSlotFromMsg36  0x0201EF40  thumb
 *   sOfferAnswerMsgIds     0x02183998  data  a2
 *   INTRUDE_COMM_IsValidProfileCode 0x021756D0 thumb ov011
 *   sItemSaleMsgIds     0x021839E0  data  a2
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   MISC_GetMoney  0x0200C274  thumb
 *   MISC_SubMoney  0x0200C29C  thumb
 *   MYITEM_SAVEDATA_CanAddItem  0x02007E3C  thumb
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
 *   EVENT_COMM_COMMON_InitMsgBox  0x0217F2B4  thumb  ov018
 *   EVENT_COMM_COMMON_ExitMsgBox  0x0217F318  thumb  ov018
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb  ov018
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb  ov018
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb  ov018
 *   EVENT_COMM_COMMON_PrintListWindow  0x0217F4A0  thumb  ov018
 *   EVENT_COMM_COMMON_DeleteChoice  0x0217F4C4  thumb  ov018
 *   EVENT_COMM_COMMON_ChangeTalkMsgEvent  0x021808C4  thumb  ov018
 *   EVENT_COMM_COMMON_ChangeTalkedMsgEvent  0x02180978  thumb  ov018
 *   EVENT_COMM_COMMON_ChangeSearchFoundEvent  0x02181BE8  thumb  ov018
 *   EVENT_COMM_COMMON_StartMsgEvent95  0x02182988  thumb  ov018
 *   EVENT_COMM_COMMON_StartMsgEvent105  0x02182998  thumb  ov018
 *   EVENT_COMM_COMMON_StartMsgEvent110Alt  0x021829F8  thumb  ov018
 *   EVENT_COMM_COMMON_StartMsgScriptEvent  0x02182A08  thumb  ov018
 */
#include "../arm9/script_vm_types.h"
#include "../types.h"
#include "../arm9/ica_anime_shared_types.h"

#include "../ov011/intrude_comm_types.h"
#include "event_comm_common_types.h"
#include "../ov083/gpower_event.h"

struct GameSystem;
struct GameData;
struct GameEvent;
struct FieldMap;
struct FldMmdl;
struct ScriptWork;
struct GameComm;
struct CommPlayerWork;
struct WordSet;

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

#include "../arm9/mi_memory.h"
#include "../arm9/gamesystem.h"
#ifdef __MWERKS__
extern void FLDMMDL_SetAcmd(struct FldMmdl *mmdl, int acmd); /* original prototype; the definition differs in pointer type, argument width */
#else
#include "../ov010/fldmmdl.h"
#endif
#include "../arm9/gfl_use.h"
struct Mmdl;
#include "../ov011/intrude_comm.h"
#include "../ov011/intrude_battle.h"
#include "../arm9/key.h"
#include "../arm9/game_data.h"
#include "../ov010/intrude_comm_query.h"
#include "../arm9/game_event.h"
#include "../arm9/game_comm.h"
#include "../arm9/net_err.h"
#include "../ov021/fieldmap.h"
#include "../ov021/field_msgbg.h"
struct MsgBank;
struct FieldMsgBg;
struct FieldSysWin;
#include "../arm9/field_sound_system.h"
struct MsgBank;
#include "../arm9/msgdata.h"
struct ScrcmdWork;
#include "../ov010/scrcmd_work.h"
#include "../arm9/gfl_heap_wrap.h"
struct PlayerWork;
#include "../arm9/gf_panic.h"
#include "../arm9/zonedata.h"
#include "../arm9/gf_font.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/wordset.h"
struct MyStatus;
#include "../arm9/mystatus.h"
#include "../arm9/net.h"
struct IntrudeMemberName;
struct IntrudeRequestHead;
struct FieldMsgWin;
struct FieldMenuFunc;
struct ScriptVm;
#include "../ov010/script_work_cmd.h"
#include "../ov010/script_sys.h"
struct IntrudeStartParam;
#include "intrude_field.h"
struct IntrudeCommSys;
struct SaveControl;
struct IntrudeSave;
#include "../arm9/intrude.h"
struct MmdlSys;
#include "../ov010/comm_player.h"
struct MyItem;
#include "../arm9/myitem_savedata.h"
struct IntrudeCommSys;
struct IntrudeSaveSlot;
struct CommPlayerSupport;
#include "../arm9/comm_player_support.h"
struct GameEvent *SCRIPT_SYS_CreateScriptEventSimple(void *fieldSys, u16 scriptId, void *target, s32 reserved);
void *SCRIPT_SYS_GetEventScriptWork(struct GameEvent *event);
#include "../ov010/script_work.h"
struct MiscSave;
#include "../arm9/beacon.h"
#include "intrude_subdisp.h"
#include "../version.h"
#if LANGUAGE == LANGUAGE_JAPANESE
extern const char str_ja_02183A8C[];
extern const char str_ja_02183AA0[];
extern const char str_ja_02183ABC[];
extern const char str_ja_02183AF0[];
extern const char str_ja_02183B0C[];
extern const char str_ja_02183B40[];
extern u16 msgIds_ja_0218397C[];
extern u16 msgIds_ja_02183994[];
extern u16 msgIds_ja_02183988[];
extern u16 msgIds_ja_02183970[];
extern const char str_ja_02183BA8[];
extern const char str_ja_02183C10[];
extern const char str_ja_02183C24[];
extern const char str_ja_02183C34[];
extern const char str_ja_02183C4C[];
extern const char str_ja_02183C50[];
extern const char str_ja_02183C64[];
#endif
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
        if (MYSTATUS_GetSex(GAME_DATA_GetMyStatusPlayer(GAME_COMM_GetGameData(sys->gameComm), netId)) == 0) {
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
    void *scriptSys = (struct ScrcmdWork *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork);
    struct GameSystem *gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork);
    SCRIPT_SYS_CallEvent(scriptSys, EVENT_COMM_COMMON_CreateExitSyncEvent(gameSystem, SCRIPT_WORK_ReadWorkPointer(vm, (struct ScrcmdWork *)scriptWork)));
    return 1;
}

struct GameEvent *EVENT_COMM_COMMON_CreateExitSyncEvent(struct GameSystem *gameSystem, u16 *result)
{
    struct GameEvent *event;
    EventCommExitSyncWork *work;
    int zero;
    zero = 0;
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_COMM_COMMON_ExitSyncEventMain, sizeof(EventCommExitSyncWork));
    work = GAME_EVENT_GetWork(event);
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
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
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

        if (GFL_NET_ERR_GetErrorLevel() != 0 || (sys == 0 && GAME_DATA_GetIntrudeId(gameData) != GAME_DATA_GetOwnNetId(gameData))) {
            *seq = 7;
            break;
        }
        if (sys != 0) {
            INTRUDE_COMM_ClearSessionEntries(&sys->session);
            INTRUDE_FIELD_InitStartParam((struct IntrudeStartParam *)(&sys->remoteRecord));
        }
        fieldMsgbg = (void *)FIELDMAP_GetMsgBg(fieldMap);
        work->msgData = (void *)FIELD_MSGBG_CreateMsgData(fieldMsgbg, 0x2D);
        work->window = FIELD_MSGBG_CreateBottomMsgWin(fieldMsgbg, work->msgData);
        work->wordSet = WORDSET_CreateDefault(4);
        GFL_USE_PlaySeDefaultVolume(0x547);
        if (sys == 0 || GAME_DATA_GetIntrudeIdByte(gameData) == GAME_DATA_GetOwnNetId(gameData)) {
            FIELD_MSGBG_MsgWinPrintMsg(work->window, 0, 0, 0x49);
            alone = 1;
        } else {
            text = STRBUF_Create(0x100, 0x15);
            templateText = MSGDATA_AllocString(work->msgData, 0x4A);
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
        if (INTRUDE_COMM_GetMemberNameNetId((struct IntrudeMemberName *)(&sys->session.members[GAME_DATA_GetIntrudeIdByte(gameData)])) == 1) {
            (*seq)++;
        }
        break;
    case 3:
        if (INTRUDE_COMM_SendReady(sys, GAME_DATA_GetIntrudeIdByte(gameData)) == 1) {
            (*seq)++;
        }
        break;
    case 4:
        if (INTRUDE_FIELD_GetStartKind((struct IntrudeStartParam *)(&sys->remoteRecord)) == 1) {
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
            WORDSET_Delete(work->wordSet);
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
    result = SCRIPT_WORK_ReadWorkPointer(vm, (struct ScrcmdWork *)scriptWork);
    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork)));
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

    result = SCRIPT_WORK_ReadWorkPointer(vm, (struct ScrcmdWork *)scriptWork);
    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork)));
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
    scriptSys = (struct ScrcmdWork *)SCRCMD_WORK_GetScriptWork((struct ScrcmdWork *)scriptWork);
    SCRIPT_SYS_CallEvent(scriptSys, EVENT_COMM_COMMON_CreateMissionInfoEvent(SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork)));
    return 1;
}

struct GameEvent *EVENT_COMM_COMMON_CreateMissionInfoEvent(struct GameSystem *gameSystem)
{
    struct GameEvent *event;
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_COMM_COMMON_MissionInfoEventMain, sizeof(EventCommMsgBox));
    MI_CpuFill8(GAME_EVENT_GetWork(event), 0, 0x30);
    return event;
}

int EVENT_COMM_COMMON_MissionInfoEventMain(struct GameEvent *event, int *seq, void *wk)
{
    EventCommMsgBox *msgBox = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    struct GameEvent *next;

    gameSystem = GAME_EVENT_GetGameSystem(event);
    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
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
        next = INTRUDE_FIELD_CreateOfferInfoEvent(gameSystem, GAMESYSTEM_GetFieldMap(gameSystem), sys, 0x15);
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
    return GAME_EVENT_Create(gameSystem, 0, EVENT_COMM_COMMON_ReturnPalaceEventMain, 0);
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
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
    fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
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
        if (ZONEDATA_IsEntralink(GAME_DATA_GetPlayerZoneId(GAMESYSTEM_GetMyPlayerWork(gameSystem))) == 1) {
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

    result = SCRIPT_WORK_ReadWorkPointer(vm, (struct ScrcmdWork *)scriptWork);
    gameSystem = SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork);
    GAMESYSTEM_GetGameComm(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
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
    result = SCRIPT_WORK_ReadWorkPointer(vm, (struct ScrcmdWork *)scriptWork);
    if (INTRUDE_GetMonolithLevel(INTRUDE_GetFromSave(GAME_DATA_GetSaveControl(GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem((struct ScrcmdWork *)scriptWork))))) != 0x30) {
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
    event = GAME_EVENT_Create(gameSystem, 0, EVENT_COMM_COMMON_TalkStartEventMain, sizeof(EventCommTalkParam));
    param = GAME_EVENT_GetWork(event);
    MI_CpuFill8(param, 0, sizeof(EventCommTalkParam));
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
    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
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
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_COMM_COMMON_TalkEventMain, sizeof(EventCommTalkWork));
    EventCommCommonWork *work = GAME_EVENT_GetWork(event);

    MI_CpuFill8(work, 0, sizeof(EventCommTalkWork));
    EVENT_COMM_COMMON_InitCommonWork(gameSystem, sys, work, fieldMap, playerMmdl, netId, heapId);
    INTRUDE_COMM_InitRequest(sys, netId);
    INTRUDE_COMM_ClearNotice(sys);
    work->talkType = EVENT_COMM_COMMON_GetTalkType(work, sys);
    return event;
}

struct GameEvent *EVENT_COMM_COMMON_CreateTalkedStartEvent(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_COMM_COMMON_TalkedStartEventMain, sizeof(EventCommTalkParam));
    EventCommTalkParam *param = GAME_EVENT_GetWork(event);

    MI_CpuFill8(param, 0, sizeof(EventCommTalkParam));
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

    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(gameSystem));
    switch (*seq) {
    case 0:
        if (sys == 0) {
            return 1;
        }
#if LANGUAGE != LANGUAGE_JAPANESE
        if (COMM_PLAYER_CheckActive(sys->commPlayer, param->netId) == 0) {
            return 1;
        }
#endif
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
    struct GameEvent *event = GAME_EVENT_Create(gameSystem, 0, EVENT_COMM_COMMON_TalkedEventMain, sizeof(EventCommTalkWork));
    EventCommCommonWork *work = GAME_EVENT_GetWork(event);

    MI_CpuFill8(work, 0, sizeof(EventCommTalkWork));
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
    work->partnerMmdl = (struct FldMmdl *)COMM_PLAYER_GetMmdl(sys->commPlayer, partnerNetId);
    work->fieldMap = fieldMap;
    work->peerSlot = (u8)netId;
    work->msgIndex = EVENT_COMM_COMMON_GetPeerTalkStatus(sys, (u8)netId);
    MYSTATUS_Copy((struct MyStatus *)(GAME_DATA_GetMyStatusByNetId(GAMESYSTEM_GetGameData(gameSystem), partnerNetId)), (struct MyStatus *)work->myStatus);
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

    sys = INTRUDE_COMM_GetWorkIfRunning(GAMESYSTEM_GetGameComm(GAME_EVENT_GetGameSystem(event)));
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
            copy = GFL_HEAP_Alloc((u16)((work->common.heapId & 0x7FFF) | 0x8000), sizeof(EventCommCommonWork), 1, sEventCommCommonFile, PM_SRC_LINE(493, 488));
            MI_CpuCopy8(work, copy, sizeof(EventCommCommonWork));
            if (INTRUDE_COMM_GetSessionResult(&sys->session) == 0 && INTRUDE_COMM_IsSessionActive(&sys->session) == 1
                && INTRUDE_COMM_IsSessionAccepted(&sys->session) == 1 && INTRUDE_COMM_IsRequestFromNetId(&sys->session, work->common.peerSlot) == 1) {
                EVENT_COMM_COMMON_StartMsgScriptEvent(event, copy);
            } else {
                EVENT_COMM_COMMON_StartMsgEvent105(event, copy);
            }
            GFL_HEAP_Free(copy);
        } else if (sys->peers[work->common.peerSlot].state != 0) {
            copy = GFL_HEAP_Alloc((u16)((work->common.heapId & 0x7FFF) | 0x8000), sizeof(EventCommCommonWork), 1, sEventCommCommonFile, PM_SRC_LINE(517, 512));
            MI_CpuCopy8(work, copy, sizeof(EventCommCommonWork));
            if (sys->peers[work->common.peerSlot].state == 2) {
                if (requestKind == 5) {
                    EVENT_COMM_COMMON_ChangeSearchFoundEvent(event, copy);
                } else {
                    EVENT_COMM_COMMON_StartMsgEvent95(event, copy);
                }
            } else {
                EVENT_COMM_COMMON_StartMsgEvent105(event, copy);
            }
            GFL_HEAP_Free(copy);
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
    gameComm = GAMESYSTEM_GetGameComm(gameSystem);
    gameData = GAMESYSTEM_GetGameData(gameSystem);
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
        WORDSET_SetSlotMyStatus(work->common.msgBox.wordSet, 0, GAME_DATA_GetMyStatusPlayer(gameData, sys->requestTarget));
        EVENT_COMM_COMMON_PrintMsg(&work->common.msgBox, 1);
        (*seq)++;
        break;
    case 1:
        if (FLDMMDL_CheckPossibleAcmd((struct Mmdl *)work->common.playerMmdl) == 1) {
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
            FLDMMDL_SetAcmd((void *)work->common.playerMmdl, acmd);
            (*seq)++;
        }
        break;
    case 2:
        if (FLDMMDL_EndAcmd((struct Mmdl *)work->common.playerMmdl) == 1) {
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
    EventCommCommonWork *copy = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), sizeof(EventCommCommonWork), 1, sEventCommCommonFile, PM_SRC_LINE(0x329, 0x324));
    unsigned int talkType;

    MI_CpuCopy8(work, copy, sizeof(EventCommCommonWork));
    talkType = work->talkType;
    if (talkType == 0) {
        EVENT_COMM_COMMON_ChangeTalkMsgEvent(event, copy);
    } else if (talkType == 1) {
        EVENT_COMM_COMMON_StartMsgEvent110Alt(event, copy);
    } else if (talkType == 2) {
        EVENT_COMM_COMMON_ChangeTalkMsgEvent(event, copy);
    } else if (talkType >= 3) {
        if (sTalkEventTable[talkType - 8] == 0) {
            GF_PANIC_Fail(PM_LANG_JA(sEmptyTextTalkTable, sEventCommCommonFile), PM_SRC_LINE(0, 0x333), PM_LANG_JA(sEmptyTextTalkTable, str_ja_02183B40));
        }
        sTalkEventTable[work->talkType - 8](event, copy);
    } else {
        EVENT_COMM_COMMON_ChangeTalkMsgEvent(event, copy);
    }
    GFL_HEAP_Free(copy);
}

extern void (*sTalkedEventTable[])(struct GameEvent *event, EventCommCommonWork *work);

void EVENT_COMM_COMMON_ChangeTalkedTypeEvent(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys)
{
    EventCommCommonWork *copy = GFL_HEAP_Alloc((u16)((work->heapId & 0x7fff) | 0x8000), sizeof(EventCommCommonWork), 1, sEventCommCommonFile, PM_SRC_LINE(0x354, 0x34F));
    unsigned int talkType;

    MI_CpuCopy8(work, copy, sizeof(EventCommCommonWork));
    talkType = work->talkType;
    if (talkType == 0) {
        EVENT_COMM_COMMON_ChangeTalkedMsgEvent(event, copy);
    } else if (talkType == 1) {
        EVENT_COMM_COMMON_StartMsgEvent110Alt(event, copy);
    } else if (talkType == 2) {
        EVENT_COMM_COMMON_ChangeTalkedMsgEvent(event, copy);
    } else if (talkType >= 3) {
        if (sTalkedEventTable[talkType - 8] == 0) {
            GF_PANIC_Fail(PM_LANG_JA(sEmptyTextTalkTable, sEventCommCommonFile), PM_SRC_LINE(0, 0x35E), PM_LANG_JA(sEmptyTextTalkTable, str_ja_02183BA8));
        }
        sTalkedEventTable[work->talkType - 8](event, copy);
    } else {
        EVENT_COMM_COMMON_ChangeTalkedMsgEvent(event, copy);
    }
    GFL_HEAP_Free(copy);
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

    myNetId = (int)GAME_DATA_GetOwnNetId(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(work->fieldMap)));
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


