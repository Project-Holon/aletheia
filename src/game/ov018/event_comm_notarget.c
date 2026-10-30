/*
 * file:     event_comm_notarget.c
 * unit:     yes
 * function: EVENT_COMM_COMMON_StartMsgEvent, EVENT_COMM_COMMON_MsgEventMain, EVENT_COMM_COMMON_StartMsgEvent95, EVENT_COMM_COMMON_StartMsgEvent105, EVENT_COMM_COMMON_StartMsgEvent110ByKindA, EVENT_COMM_COMMON_StartMsgEvent110ByKindB, EVENT_COMM_COMMON_StartMsgEvent110, EVENT_COMM_COMMON_StartMsgEvent110Alt
 * address:  0x021828B8
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
 *   EVENT_COMM_COMMON_PrintMsg  0x0217F3C4  thumb  ov018
 *   EVENT_COMM_COMMON_IsPrintFinished  0x0217F40C  thumb  ov018
 *   EVENT_COMM_COMMON_IsKeyTrg  0x0217F420  thumb  ov018
 *   EVENT_COMM_COMMON_ExitCommonWork  0x0217FE38  thumb  ov018
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


extern void (*sTalkEventTable[])(struct GameEvent *event, EventCommCommonWork *work);


extern void (*sTalkedEventTable[])(struct GameEvent *event, EventCommCommonWork *work);


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
    GAME_EVENT_Change(event, EVENT_COMM_COMMON_MsgEventMain, sizeof(EventCommMsgWork) + 0xc);
    work = GAME_EVENT_GetWork(event);
    MI_CpuCopy8(src, work, sizeof(EventCommCommonWork));
    if (sys != 0) {
        work->msgId = msgIds[src->msgIndex];
        WORDSET_SetSlotMyStatus(src->msgBox.wordSet, 0, src->myStatus);
    } else {
        GF_PANIC_Fail(PM_LANG_JA(sEmptyTextA, str_ja_02183C34), PM_SRC_LINE(0, 0xE3), PM_LANG_JA(sEmptyTextA, str_ja_02183C4C));
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
    EVENT_COMM_COMMON_StartMsgEvent(event, src, PM_LANG_JA(sMsgIds95, msgIds_ja_0218397C));
}

/*
 * Leaf (no lr save): tail call to EVENT_COMM_COMMON_StartMsgEvent with the message IDs 105 to 109.
 */
void EVENT_COMM_COMMON_StartMsgEvent105(struct GameEvent *event, EventCommCommonWork *src)
{
    EVENT_COMM_COMMON_StartMsgEvent(event, src, PM_LANG_JA(sMsgIds105, msgIds_ja_02183994));
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

void EVENT_COMM_COMMON_StartMsgEvent110(struct GameEvent *event, EventCommCommonWork *src) { EVENT_COMM_COMMON_StartMsgEvent(event, src, PM_LANG_JA(sMsgIds110, msgIds_ja_02183988)); }

void EVENT_COMM_COMMON_StartMsgEvent110Alt(struct GameEvent *event, EventCommCommonWork *src) { EVENT_COMM_COMMON_StartMsgEvent(event, src, PM_LANG_JA(sMsgIds110Alt, msgIds_ja_02183970)); }


