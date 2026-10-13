/*
 * file:     event_comm_common.c
 * unit:     yes
 * function: func_0217F2B4, func_0217F318, func_0217F36C, func_0217F390, func_0217F3A4, func_0217F3C4, func_0217F3E4, func_0217F40C, func_0217F420, func_0217F434, func_0217F45C, func_0217F470, func_0217F4A0, func_0217F4C4, func_0217F4D8, func_0217F508, func_0217F528, func_0217F574, func_0217F58C, func_0217F5A0, func_0217F5F0, func_0217F648, func_0217F67C, func_0217F6A0, func_0217F8A0, func_0217F8D0, func_0217F914, func_0217F938, func_0217F95C, func_0217FA1C, func_0217FA24, func_0217FA38, func_0217FAE0, func_0217FB2C, func_0217FB5C, func_0217FB94, func_0217FC08, func_0217FC6C, func_0217FCAC, func_0217FD34, func_0217FDA0, func_0217FE38, func_0217FE6C, func_021800A4, func_021802A8, func_0218034C, func_021803F0, func_021804F8, func_02180538, func_021808C4, func_021808E8, func_02180978, func_02180980, func_021809A4, func_02180B14, func_02180B38, func_02180BDC, func_02180C00, func_02180CA4, func_02180CC8, func_02180DE8, func_02180E0C, func_02180EB0, func_02180ED4, func_02180FA8, func_02180FCC, func_0218111C, func_02181140, func_021811E4, func_0218123C, func_0218152C, func_02181584, func_0218186C, func_021818C4, func_0218191C, func_02181940, func_021819D0, func_021819F4, func_02181A74, func_02181A98, func_02181B44, func_02181B68, func_02181BE8, func_02181C0C, func_02181D8C, func_02181DD4, func_02181E6C, func_02181E90, func_02181F10, func_02181F34, func_02181FB4, func_02181FD8, func_02182080, func_021820A4, func_02182124, func_02182150, func_021821B0, func_02182214, func_0218236C, func_021823A8, func_021825F8, func_0218261C, func_021828A8, func_021828B0
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
 *   func_02082BCC  0x02082BCC  arm
 *   func_020120F4  0x020120F4  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_02175514  0x02175514  thumb  ov011
 *   func_020362DC  0x020362DC  arm
 *   func_02173B9C  0x02173B9C  thumb  ov011
 *   func_021753B8  0x021753B8  thumb  ov011
 *   func_02173AE0  0x02173AE0  thumb  ov011
 *   func_02012138  0x02012138  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_02012374  0x02012374  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02026400  0x02026400  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188BE8  0x02188BE8  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02029830  0x02029830  thumb
 *   func_02005F38  0x02005F38  thumb
 *   func_02029620  0x02029620  thumb
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_02045C04  0x02045C04  arm
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_02030734  0x02030734  arm
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0215841C            0x0215841C  thumb  ov010
 *   func_02034714            0x02034714  arm
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_020127B8  0x020127B8  thumb
 *   func_02012950  0x02012950  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_021583EC  0x021583EC  thumb  ov010
 *   func_021762D8  0x021762D8  thumb  ov011
 *   func_02175B34  0x02175B34  thumb  ov011
 *   func_0201EC74  0x0201EC74  thumb
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_02190EB8  0x02190EB8  thumb  ov021
 *   func_02190F7C  0x02190F7C  thumb  ov021
 *   sEmptyTextMsgBox     0x02183B2C  data
 *   func_02190708 0x02190708 thumb ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_02190758 0x02190758 thumb ov021
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02190BE4 0x02190BE4 thumb ov021
 *   func_02190C78 0x02190C78 thumb ov021
 *   func_02026478 0x02026478 thumb
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215897C 0x0215897C thumb ov010
 *   func_02012B80  0x02012B80  thumb
 *   func_021757A8  0x021757A8  thumb  ov011
 *   func_0217BF1C  0x0217BF1C  thumb  ov018
 *   func_021907A8  0x021907A8  thumb  ov021
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02173D2C  0x02173D2C  thumb  ov011
 *   func_02175FB4  0x02175FB4  thumb  ov011
 *   func_02173C6C  0x02173C6C  thumb  ov011
 *   func_0217BF28  0x0217BF28  thumb  ov018
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_0217C458  0x0217C458  thumb  ov018
 *   func_0201235C  0x0201235C  thumb
 *   func_02176230  0x02176230  thumb  ov011
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0200BF10 0x0200BF10 thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0217538C  0x0217538C  thumb  ov011
 *   func_02175368  0x02175368  thumb  ov011
 *   func_0217545C  0x0217545C  thumb ov011
 *   func_02167A54  0x02167A54  thumb ov010
 *   func_02167A14 0x02167A14 thumb ov010
 *   func_02008494 0x02008494 thumb
 *   func_02175B14 0x02175B14 thumb ov011
 *   func_02082D44 0x02082D44 arm
 *   func_02174E14 0x02174E14 thumb ov011
 *   func_02175DCC  0x02175DCC  thumb  ov011
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_0217620C  0x0217620C  thumb  ov011
 *   func_02182A08  0x02182A08  thumb  ov018
 *   func_02182998  0x02182998  thumb  ov018
 *   func_02182988  0x02182988  thumb  ov018
 *   func_02174258  0x02174258  thumb  ov011
 *   func_02175C40  0x02175C40  thumb  ov011
 *   func_0217553C  0x0217553C  thumb  ov011
 *   func_02173C04  0x02173C04  thumb  ov011
 *   func_0217537C  0x0217537C  thumb  ov011
 *   sEventCommCommonFile   0x02183B30  data   a1
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_021829F8  0x021829F8  thumb ov018
 *   sEmptyTextTalkTable  0x02183B44  data ov018 a1
 *   sTalkEventTable  0x0218374C  data ov018 a4
 *   sTalkedEventTable  0x021837C4  data ov018 a4
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_02188C84  0x02188C84  thumb ov021
 *   func_02175E90  0x02175E90  thumb  ov011
 *   func_021756A4  0x021756A4  thumb  ov011
 *   func_02175DE4  0x02175DE4  thumb  ov011
 *   func_0200BE24  0x0200BE24  thumb
 *   func_0200BE00  0x0200BE00  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_02007FB8  0x02007FB8  thumb
 *   func_0200823C  0x0200823C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_0200BF78  0x0200BF78  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   sEmptyTextResult   0x02183B48  data   ov018  a1
 *   func_0201232C 0x0201232C thumb
 *   sTalkMsgIds     0x0218383C  data ov018 a2
 *   func_0217405C  0x0217405C  thumb  ov011
 *   func_02175CF4  0x02175CF4  thumb  ov011
 *   func_0201F184  0x0201F184  thumb
 *   sMissionAchieveMsgIdsA     0x02183870  data   a2
 *   sMissionAchieveMsgIdsB     0x0218387A  data   a2
 *   sMissionAchieveMsgIdsC     0x02183884  data   a2
 *   sTalkPowerGiftAsTargetMsgIds     0x02183848  data ov018 a2
 *   sTalkedPowerGiftAsTargetMsgIds     0x02183866  data ov018 a2
 *   func_020124AC  0x020124AC  thumb
 *   func_021F5260  0x021F5260  thumb  ov083
 *   ov083_id       0x00000053  data
 *   sTalkedPowerGiftTargetMsgIds     0x02183852  data   a2
 *   sTalkedPowerGiftEndMsgIds     0x0218385C  data   a2
 *   sTalkPowerShareTargetMsgIds     0x021838B8  data ov018 a2
 *   sTalkPowerShareAsTargetMsgIds     0x02183890  data  a2
 *   sTalkedPowerShareAchieveMsgIdsA     0x021838A4  data  a2
 *   sTalkedPowerShareAchieveMsgIdsB     0x021838AE  data  a2
 *   sTalkedPowerShareTargetMsgIds     0x0218389A  data ov018 a2
 *   func_0215839C  0x0215839C  thumb  ov010
 *   func_021756F0  0x021756F0  thumb
 *   func_021744D0  0x021744D0  thumb
 *   func_021766CC  0x021766CC  thumb
 *   sBattleRequestMsgIds     0x021838F6  data  a2
 *   sBattleRequestTalkedMsgIds     0x02183900  data  a2
 *   sBattleRequestAcceptedMsgIds     0x0218390A  data  a2
 *   sBattleRequestEndMsgIds     0x02183914  data  a2
 *   sBattleRequestRefusedMsgIds     0x0218391E  data  a2
 *   func_021763D8  0x021763D8  thumb  ov011
 *   sBattleAnswerMsgIds     0x021838C4  data  a2
 *   sBattleAnswerTalkedMsgIds     0x021838CE  data  a2
 *   sBattleAnswerAcceptedMsgIds     0x021838D8  data  a2
 *   sBattleAnswerEndMsgIds     0x021838E2  data  a2
 *   sBattleAnswerRefusedMsgIds     0x021838EC  data  a2
 *   sTalkSearchTargetMsgIds     0x02183928  data  a2
 *   sTalkSearchAsTargetMsgIds     0x0218393C  data  a2
 *   sTalkedSearchAsTargetMsgIds     0x02183932  data  a2
 *   sTalkedSearchTargetMsgIds     0x02183946  data  a2
 *   func_0217456C  0x0217456C  thumb  ov011
 *   sSearchFoundMsgIdsA     0x02183950  data  a2
 *   sSearchFoundMsgIdsB     0x0218395A  data  a2
 *   sSearchFoundOtherMsgIds     0x02183964  data  a2
 *   func_02012F20  0x02012F20  thumb
 *   func_0200846C  0x0200846C  thumb
 *   func_0202E82C  0x0202E82C  thumb
 *   func_02158768  0x02158768  thumb  ov010
 *   func_021589D0  0x021589D0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   sTalkGreetingTargetMsgIds     0x02183970  data  a2
 *   sTalkGreetingAsTargetMsgIds     0x02183984  data  a2
 *   sTalkedGreetingAsTargetMsgIds     0x0218397A  data   a2
 *   sTalkedGreetingTargetMsgIds     0x0218398E  data   a2
 *   func_020084F8  0x020084F8  thumb
 *   func_021745F8  0x021745F8  thumb  ov011
 *   func_0201EF40  0x0201EF40  thumb
 *   sOfferAnswerMsgIds     0x02183998  data  a2
 *   func_021756D0 0x021756D0 thumb ov011
 *   sItemSaleMsgIds     0x021839E0  data  a2
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_0200C29C  0x0200C29C  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   sItemPurchaseMsgIds     0x021839A4  data  a2
 *   func_0218236C  0x0218236C  thumb  ov018
 *   func_021825F8  0x021825F8  thumb  ov018
 *   func_0217C914  0x0217C914  thumb  ov018
 *   func_0217CA1C  0x0217CA1C  thumb  ov018
 *   func_0217CA84  0x0217CA84  thumb  ov018
 *   func_0217CE08  0x0217CE08  thumb  ov018
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

#include "../ov011/intrude_comm_types.h"
#include "unit_021828B8_types.h"
#include "../arm9/script_vm_types.h"

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
 * Common head of the talk events (0x98 bytes). The talk and talked events
 * fill it; each follow-up event gets a copy at the start of its own work.
 */
typedef struct EventCommCommonWork {
    u16 heapId;                     /* 0x00 */
    u16 pad02;
    struct FldMmdl *playerMmdl;     /* 0x04: field object of this player */
    struct FldMmdl *partnerMmdl;    /* 0x08: field object of the partner */
    struct FieldMap *fieldMap;      /* 0x0C */
    EventCommMsgBox msgBox;         /* 0x10 */
    u8 peerSlot;                    /* 0x40: net ID of the partner */
    u8 talkType;                    /* 0x41: selects the follow-up event */
    u8 msgIndex;                    /* 0x42: talk status of the partner, index into the message ID tables */
    u8 pad43;
    IntrudeMemberRecord member;     /* 0x44: mission record of the partner */
    u8 myStatus[0x20];              /* 0x78: MyStatus of the partner */
} EventCommCommonWork;

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

/* Parameter of the G-Power activation event of overlay 83 (func_021F5260). */
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

extern void func_02082BCC(void *dest, int value, int size);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern void func_0216D410(struct FldMmdl *mmdl, int acmd);
extern void func_020061E4(u32 seId);
extern int func_0216D480(struct FldMmdl *mmdl);
extern int func_02175514(IntrudeCommSys *sys);
extern u32 func_020362DC(void);
extern int func_02173B9C(int netId, int seq);
extern void func_021753B8(IntrudeCommSys *sys);
extern int func_02173AE0(IntrudeCommSys *sys, int netId, int requestActive, int seq);
extern struct GameComm *func_02012138(struct GameSystem *gameSystem);
extern u8 func_02012B58(struct GameData *gameData);
extern IntrudeCommSys *func_02158344(struct GameComm *gameComm);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, unsigned int workSize);
extern void *func_020124E8(struct GameEvent *event);
u32 func_02026454(struct GameComm *gameComm);
IntrudeCommSys *func_02026474(struct GameComm *gameComm);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern void func_02012374(struct GameEvent *event, struct GameEvent *child);
u32 func_0200FB24(void);
void func_02026400(struct GameComm *gameComm);
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
int func_02188BE8(struct FieldMap *fieldMap);
extern void *func_02188C54(struct FieldMap *fieldMap);
extern void *func_021904B0(void *fieldMsgbg, u32 arcDatId);
extern void *func_02190F64(void *fieldMsgbg, void *msgData);
void *func_02029830(struct GameSystem *gameSystem, u32 soundId);
int func_02005F38(void);
void *func_02029620(struct GameSystem *gameSystem, u32 popMode, u32 fadeFrames);
extern int func_02190EF0(void *printer);
extern void func_02190E40(void *printer);
extern u32 func_02045C04(void *msgData);
extern struct GameSystem *func_0215A5DC(struct ScriptWork *scriptWork);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void *func_020120F8(struct GameSystem *gameSystem);
extern u16 func_02012AC8(void *playerWork);
extern u32 func_020307B0(void *memory);
extern u8 func_0215841C(struct GameData *gameData);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_02013D5C(u32 zoneId);
extern int func_02175DA8(IntrudeSession *session);
extern int func_02175B8C(IntrudeSession *session);
extern struct WordSet *func_0201EC64(u32 heapId);
extern void *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(void *strbuf);
extern unsigned int func_0201ED04(void *wordSet);
extern void *func_02012944(struct GameData *gameData);
extern u8 func_02008550(void *myStatus);
extern void *func_02045EC0(void *msgData, u32 msgId);
extern void *func_020127B8(struct GameData *gameData);
extern void *func_02012950(struct GameData *gameData, u32 netId);
extern void func_0201F02C(void *wordSet, u32 index, void *myStatus);
extern void func_02045CAC(void *msgData, u32 msgId, void *dest);
extern void func_0201F250(void *wordSet, void *dest, void *src);
int func_0203D1B4(void);
extern void *func_021583EC(struct GameData *gameData, int netId);
void func_021762D8(IntrudeMemberRecord *record, IntrudeMemberName *name, void *wordSet, u16 heapId);
extern IntrudeMemberRecord *func_02175B34(IntrudeSession *session);
extern struct WordSet *func_0201EC74(u32 count, u32 length, u16 heapId);
extern void func_021904C8(void *msgData);
extern void func_02190EB8(void *printer, u32 x, u16 y, void *text);
extern void func_02190F7C(void *printer);
extern void *func_02190708(void *fieldMsgbg, void *msgData, u16 x, u16 y, u16 width, u16 height);
extern int func_02190728(void *window);
extern void func_02190758(void *window, u16 x, u16 y, void *text);
extern int func_021909BC(void *menu);
extern void *func_02190BE4(void *fieldMsgbg, u32 cursorPos);
extern int func_02190C78(void *menu);
extern struct GameData *func_02026478(struct GameComm *gameComm);
extern void *func_0215A5F4(struct ScriptWork *scriptWork);
extern u16 *func_02159AE8(ScriptVm *vm, struct ScriptWork *scriptWork);
extern void func_0215897C(void *scriptSys, struct GameEvent *event);
extern u8 func_02012B80(struct GameData *gameData);
extern void func_021757A8(IntrudeSession *session);
extern void func_0217BF1C(IntrudeRemoteRecord *startParam);
extern void *func_021907A8(void *fieldMsgbg, void *msgData);
extern int func_02190740(void *window, u32 x, u32 y, u32 msgId);
extern int func_02173D2C(IntrudeCommSys *sys, int netId);
extern int func_02175FB4(IntrudeMemberEntry *entry);
extern int func_02173C6C(IntrudeCommSys *sys, int netId);
extern u8 func_0217BF28(IntrudeRemoteRecord *startParam);
extern int func_0219077C(void *window);
extern struct GameEvent *func_0217C458(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, u16 senderNetId);
extern void func_0201235C(struct GameEvent *event, struct GameEvent *next);
extern u8 func_02176230(IntrudeCommSys *sys, IntrudeSession *session);
extern void *func_02012EBC(struct GameData *gameData);
extern void *func_0200BE48(void *saveControl);
extern u8 func_0200BF10(void *battleRec);
extern void *func_02188C7C(struct FieldMap *fieldMap);
extern void func_0216D9A0(void *mmdlSys);
extern u32 *func_0216D9E4(void *mmdlSys);
extern void func_0217538C(IntrudeCommSys *sys, int netId);
extern void func_02175368(IntrudeCommSys *sys);
extern void func_0217545C(IntrudeCommSys *sys);
extern int func_02167A54(struct CommPlayerWork *commPlayer, int netId);
extern struct FldMmdl *func_02167A14(struct CommPlayerWork *commPlayer, int netId);
extern void func_02008494(void *src, void *dest);
extern int func_02175B14(IntrudeSession *session);
extern void func_02082D44(const void *src, void *dest, int size);
extern void func_02174E14(IntrudeCommSys *sys, int state);
extern int func_02175DCC(IntrudeSession *session);
extern IntrudeResultRecord *func_02175BCC(IntrudeSession *session);
extern int func_0217620C(IntrudeSession *session, int netId);
extern void func_02182A08(struct GameEvent *event, EventCommCommonWork *work);
extern void func_02182998(struct GameEvent *event, EventCommCommonWork *work);
extern void func_02182988(struct GameEvent *event, EventCommCommonWork *work);
extern int func_02174258(IntrudeCommSys *sys);
extern int func_02175C40(IntrudeSession *session);
extern void func_0217553C(IntrudeCommSys *sys);
extern int func_02173C04(int netId, int answer);
extern u8 *func_0217537C(IntrudeCommSys *sys);
extern int func_0216D3CC(struct FldMmdl *mmdl);
void MI_CpuCopy8(const void *src, void *dst, unsigned int size);
extern void func_021829F8(struct GameEvent *event, EventCommCommonWork *work);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
u16 func_02188C84(struct FieldMap *fieldMap);
int func_02175E90(IntrudeCommSys *sys, IntrudeSession *session);
u8 func_021756A4(IntrudeCommSys *sys);
int func_02175DE4(IntrudeCommSys *sys, IntrudeSession *session);
void func_0200BE24(void *battleRec, s32 count);
void func_0200BE00(void *battleRec, s32 count);
void *func_0201292C(struct GameData *gameData);
u32 func_02007FB8(void *myItem, u16 itemId, u16 heapId);
u32 func_0200823C(u32 itemId);
u32 func_02007E50(void *myItem, u16 itemId, u16 count, u16 heapId);
u32 func_0200BF78(void *record);
void func_0201EFA4(void *wordSet, u32 index, u32 number, u32 digits, u32 dispType, u32 codeType);
extern void func_0201232C(struct GameEvent *event, GameEventFunc func, int workSize);
int func_0217405C(IntrudeCommSys *sys, IntrudeSession *session);
int func_02175CF4(IntrudeCommSys *sys, IntrudeSession *session);
void func_0201F184(void *wordSet, u32 index, s32 value);
struct GameEvent *func_020124AC(struct GameSystem *gameSystem, u32 overlayId, struct GameEvent *(*createFunc)(struct GameSystem *gameSystem, void *param), void *param);
struct GameEvent *func_021F5260(struct GameSystem *gameSystem, void *param);
int func_0215839C(IntrudeCommSys *sys, int flags, int netId);
void func_021756F0(IntrudeCommSys *sys, int locked);
int func_021744D0(IntrudeCommSys *sys, int netId, int flags);
struct GameEvent *func_021766CC(struct GameSystem *gameSystem, EventCommBattleParam *param);
void func_021763D8(void *battleRec, u32 key);
int func_0217456C(IntrudeCommSys *sys, int netId, int mode);
void *func_02012F20(struct GameData *gameData);
void *func_0200846C(u32 heapId);
void *func_0202E82C(void *pmsWork);
struct GameEvent *func_02158768(struct GameSystem *gameSystem, int scriptId, int param, int heapId);
void *func_021589D0(struct GameEvent *event);
int func_02159058(void *scriptWork, int param0, int param1, int param2, u16 param3);
extern u32 func_020084F8(void *myStatus, void *dest, u32 size);
int func_021745F8(u32 netId, void *name);
void func_0201EF40(void *wordSet, u32 index, u32 itemId);
extern int func_021756D0(u32 itemId);
extern void *func_02012F08(struct GameData *gameData);
extern u32 func_0200C274(void *miscSave);
extern u32 func_0200C29C(void *miscSave, u32 amount);
extern u32 func_02007E3C(void *myItem, u16 itemId, u16 count, u16 heapId);
extern int func_0217C914(IntrudeCommSys *sys, EventCommTalkWork *work, u8 *answerSeq);
struct GameEvent *func_0217CA1C(struct GameSystem *gameSystem);
struct GameEvent *func_0217CA84(struct GameSystem *gameSystem, int mode);
extern struct GameEvent *func_0217CE08(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u16 zoneId, int mode);
void func_0217F2B4(EventCommMsgBox *msgBox, struct GameSystem *gameSystem);
void func_0217F318(EventCommMsgBox *msgBox);
void func_0217F36C(EventCommMsgBox *msgBox);
void func_0217F390(EventCommMsgBox *msgBox);
void func_0217F3A4(EventCommMsgBox *msgBox, void *text);
void func_0217F3C4(EventCommMsgBox *msgBox, u16 msgId);
void func_0217F3E4(EventCommMsgBox *msgBox);
int func_0217F40C(EventCommMsgBox *msgBox);
int func_0217F420(void);
void func_0217F434(EventCommMsgBox *msgBox);
void func_0217F45C(EventCommMsgBox *msgBox);
void func_0217F470(EventCommMsgBox *msgBox, void *msgData, void *window, unsigned int msgId, int x, int y);
void func_0217F4A0(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y);
void func_0217F4C4(EventCommMsgBox *msgBox);
void func_0217F4D8(EventCommMsgBox *msgBox, struct GameSystem *gameSystem);
int func_0217F508(EventCommMsgBox *msgBox);
void func_0217F528(EventCommMsgBox *msgBox, struct GameSystem *gameSystem, int x, int y, int width, int height);
void func_0217F574(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y);
void func_0217F58C(EventCommMsgBox *msgBox);
int func_0217F5A0(IntrudeSession *session);
int func_0217F5F0(IntrudeCommSys *sys, u8 netId);
int func_0217F648(ScriptVm *vm, struct ScriptWork *scriptWork);
struct GameEvent *func_0217F67C(struct GameSystem *gameSystem, u16 *result);
int func_0217F6A0(struct GameEvent *event, int *seq, void *wk);
int func_0217F8A0(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0217F8D0(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0217F914(ScriptVm *vm, struct ScriptWork *scriptWork);
struct GameEvent *func_0217F938(struct GameSystem *gameSystem);
int func_0217F95C(struct GameEvent *event, int *seq, void *wk);
void func_0217FA1C(EventCommMsgBox *msgBox);
struct GameEvent *func_0217FA24(struct GameSystem *gameSystem);
int func_0217FA38(struct GameEvent *event, int *seq, void *wk);
int func_0217FAE0(ScriptVm *vm, struct ScriptWork *scriptWork);
int func_0217FB2C(ScriptVm *vm, struct ScriptWork *scriptWork);
struct GameEvent *func_0217FB5C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, void *unused, struct FldMmdl *playerMmdl, int netId, u16 heapId);
int func_0217FB94(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *func_0217FC08(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId);
struct GameEvent *func_0217FC6C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId);
int func_0217FCAC(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *func_0217FD34(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId);
void func_0217FDA0(struct GameSystem *gameSystem, IntrudeCommSys *sys, EventCommCommonWork *work, struct FieldMap *fieldMap, struct FldMmdl *playerMmdl, int netId, u16 heapId);
void func_0217FE38(IntrudeCommSys *sys, EventCommCommonWork *work);
int func_0217FE6C(struct GameEvent *event, int *seq, void *wk);
int func_021800A4(struct GameEvent *event, int *seq, void *wk);
void func_021802A8(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys);
void func_0218034C(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys);
int func_021803F0(EventCommCommonWork *work, IntrudeCommSys *sys);
struct GameEvent *func_021804F8(struct GameSystem *gameSystem, int showResult);
int func_02180538(struct GameEvent *event, int *seq, void *wk);
void func_021808C4(struct GameEvent *event, EventCommCommonWork *src);
int func_021808E8(struct GameEvent *event, int *seq, void *wk);
void func_02180978(struct GameEvent *event, EventCommCommonWork *src);
void func_02180980(struct GameEvent *event, EventCommCommonWork *src);
int func_021809A4(struct GameEvent *event, int *seq, void *wk);
void func_02180B14(struct GameEvent *event, EventCommCommonWork *src);
int func_02180B38(struct GameEvent *event, int *seq, void *wk);
void func_02180BDC(struct GameEvent *event, EventCommCommonWork *src);
int func_02180C00(struct GameEvent *event, int *seq, void *wk);
void func_02180CA4(struct GameEvent *event, EventCommCommonWork *src);
int func_02180CC8(struct GameEvent *event, int *seq, void *wk);
void func_02180DE8(struct GameEvent *event, EventCommCommonWork *src);
int func_02180E0C(struct GameEvent *event, int *seq, void *wk);
void func_02180EB0(struct GameEvent *event, EventCommCommonWork *src);
int func_02180ED4(struct GameEvent *event, int *seq, void *wk);
void func_02180FA8(struct GameEvent *event, EventCommCommonWork *src);
int func_02180FCC(struct GameEvent *event, int *seq, void *wk);
void func_0218111C(struct GameEvent *event, EventCommCommonWork *src);
int func_02181140(struct GameEvent *event, int *seq, void *wk);
void func_021811E4(struct GameEvent *event, EventCommCommonWork *src);
int func_0218123C(struct GameEvent *event, int *seq, void *wk);
void func_0218152C(struct GameEvent *event, EventCommCommonWork *src);
int func_02181584(struct GameEvent *event, int *seq, void *wk);
void func_0218186C(struct GameEvent *event, EventCommCommonWork *src);
void func_021818C4(struct GameEvent *event, EventCommCommonWork *src);
void func_0218191C(struct GameEvent *event, EventCommCommonWork *src);
int func_02181940(struct GameEvent *event, int *seq, void *wk);
void func_021819D0(struct GameEvent *event, EventCommCommonWork *src);
int func_021819F4(struct GameEvent *event, int *seq, void *wk);
void func_02181A74(struct GameEvent *event, EventCommCommonWork *src);
int func_02181A98(struct GameEvent *event, int *seq, void *wk);
void func_02181B44(struct GameEvent *event, EventCommCommonWork *src);
int func_02181B68(struct GameEvent *event, int *seq, void *wk);
void func_02181BE8(struct GameEvent *event, EventCommCommonWork *src);
int func_02181C0C(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *func_02181D8C(struct GameSystem *gameSystem, u32 heapId);
int func_02181DD4(struct GameEvent *event, int *seq, void *wk);
void func_02181E6C(struct GameEvent *event, EventCommCommonWork *src);
int func_02181E90(struct GameEvent *event, int *seq, void *wk);
void func_02181F10(struct GameEvent *event, EventCommCommonWork *src);
int func_02181F34(struct GameEvent *event, int *seq, void *wk);
void func_02181FB4(struct GameEvent *event, EventCommCommonWork *src);
int func_02181FD8(struct GameEvent *event, int *seq, void *wk);
void func_02182080(struct GameEvent *event, EventCommCommonWork *src);
int func_021820A4(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *func_02182124(struct GameSystem *gameSystem, IntrudeCommSys *sys, IntrudeMemberRecord *offer);
int func_02182150(struct GameEvent *event, int *seq, void *wk);
struct GameEvent *func_021821B0(struct GameSystem *gameSystem, IntrudeMemberRecord *offer);
int func_02182214(struct GameEvent *event, int *seq, void *wk);
void func_0218236C(struct GameEvent *event, EventCommCommonWork *src);
int func_021823A8(struct GameEvent *event, int *seq, void *wk);
void func_021825F8(struct GameEvent *event, EventCommCommonWork *src);
int func_0218261C(struct GameEvent *event, int *seq, void *wk);
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

void func_0217F2B4(EventCommMsgBox *msgBox, struct GameSystem *gameSystem)
{
    void *fieldMsgbg;

    fieldMsgbg = func_02188C54(func_0201210C(gameSystem));
    if (msgBox->wordSet == 0) {
        msgBox->wordSet = func_0201EC74(6, 0x20, 4);
        msgBox->text = func_020457B0(0x1F0, 4);
        msgBox->templateText = func_020457B0(0x1D0, 4);
        msgBox->msgData = func_021904B0(fieldMsgbg, 0x44);
        msgBox->msgDataB = func_021904B0(fieldMsgbg, 0x42);
        msgBox->msgDataC = func_021904B0(fieldMsgbg, 0x43);
        msgBox->fieldMsgbg = fieldMsgbg;
        msgBox->printing = 0;
    }
}


void func_0217F318(EventCommMsgBox *msgBox)
{
    func_0217F390(msgBox);
    func_0217F58C(msgBox);
    func_0217F45C(msgBox);
    if (msgBox->wordSet != 0) {
        if (msgBox->printer != 0) {
            func_02190E40(msgBox->printer);
            msgBox->printer = 0;
        }
        func_021904C8(msgBox->msgData);
        func_021904C8(msgBox->msgDataB);
        func_021904C8(msgBox->msgDataC);
        func_02045808(msgBox->templateText);
        func_02045808(msgBox->text);
        func_0201ED04(msgBox->wordSet);
        msgBox->wordSet = 0;
    }
}


void func_0217F36C(EventCommMsgBox *msgBox)
{
    if (msgBox->printer != 0) {
        if (msgBox->printing == 1) {
            func_0217F3E4(msgBox);
        }
    } else {
        msgBox->printer = func_02190F64(msgBox->fieldMsgbg, msgBox->msgData);
    }
}


void func_0217F390(EventCommMsgBox *msgBox)
{
    if (msgBox->printer != 0) {
        func_02190E40(msgBox->printer);
        msgBox->printer = 0;
    }
}


void func_0217F3A4(EventCommMsgBox *msgBox, void *text)
{
    func_0217F36C(msgBox);
    func_02190EB8(msgBox->printer, 0, 0, text);
    msgBox->printing = 1;
}


void func_0217F3C4(EventCommMsgBox *msgBox, u16 msgId)
{
    func_02045CAC(msgBox->msgData, msgId, msgBox->templateText);
    func_0201F250(msgBox->wordSet, msgBox->text, msgBox->templateText);
    func_0217F3A4(msgBox, msgBox->text);
}


void func_0217F3E4(EventCommMsgBox *msgBox)
{
    if (msgBox->printer == 0) {
        func_02034714(sEmptyTextMsgBox, 0, sEmptyTextMsgBox);
    }
    func_02190F7C(msgBox->printer);
    msgBox->printing = 0;
}


int func_0217F40C(EventCommMsgBox *msgBox)
{
    if (msgBox->printer == 0) {
        return 1;
    }
    return func_02190EF0(msgBox->printer);
}


int func_0217F420(void)
{
    if (func_020362DC() & 0xf3) return 1;
    return 0;
}


/*
 * extent: Two bytes of alignment padding at 0x0217F45A.
 */
void func_0217F434(EventCommMsgBox *msgBox)
{
    if (msgBox->listWindow == 0) msgBox->listWindow = func_02190708(msgBox->fieldMsgbg, msgBox->msgData, 1, 0x13, 0x1e, 4);
}


void func_0217F45C(EventCommMsgBox *msgBox)
{
    if (msgBox->listWindow != 0) {
        func_02190728(msgBox->listWindow);
        msgBox->listWindow = 0;
    }
}


void func_0217F470(EventCommMsgBox *msgBox, void *msgData, void *window, unsigned int msgId, int x, int y)
{
    func_02045CAC(msgData, msgId, msgBox->templateText);
    func_0201F250(msgBox->wordSet, msgBox->text, msgBox->templateText);
    func_02190758(window, (u16)x, (u16)y, msgBox->text);
}


void func_0217F4A0(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y)
{
    func_0217F434(msgBox);
    func_0217F470(msgBox, msgBox->msgData, msgBox->listWindow, msgId, x, y);
}


void func_0217F4C4(EventCommMsgBox *msgBox)
{
    if (msgBox->choiceHandle != 0) {
        func_021909BC(msgBox->choiceHandle);
        msgBox->choiceHandle = 0;
    }
}


void func_0217F4D8(EventCommMsgBox *msgBox, struct GameSystem *gameSystem)
{
    func_0201210C(gameSystem);
    if (msgBox->choiceHandle != 0 || msgBox->msgData == 0) func_02034714(sEmptyTextMsgBox, 0, sEmptyTextMsgBox);
    msgBox->choiceHandle = func_02190BE4(msgBox->fieldMsgbg, 0);
}


int func_0217F508(EventCommMsgBox *msgBox)
{
    if (msgBox->choiceHandle == 0) func_02034714(sEmptyTextMsgBox, 0, sEmptyTextMsgBox);
    return func_02190C78(msgBox->choiceHandle);
}


void func_0217F528(EventCommMsgBox *msgBox, struct GameSystem *gameSystem, int x, int y, int width, int height)
{
    func_0201210C(gameSystem);
    if (msgBox->listWindowB != 0) {
        func_02034714(sEmptyTextMsgBox, 0, sEmptyTextMsgBox);
    }
    msgBox->listWindowB = func_02190708(msgBox->fieldMsgbg, msgBox->msgData, (u16)x, (u16)y, width, height);
}


void func_0217F574(EventCommMsgBox *msgBox, unsigned int msgId, int x, int y)
{
    func_0217F470(msgBox, msgBox->msgDataC, msgBox->listWindowB, msgId, x, y);
}


void func_0217F58C(EventCommMsgBox *msgBox)
{
    if (msgBox->listWindowB != 0) {
        func_02190728(msgBox->listWindowB);
        msgBox->listWindowB = 0;
    }
}


int func_0217F5A0(IntrudeSession *session)
{
    IntrudeMemberRecord *offer;

    if (func_02175DA8(session) == 1) {
        return 4;
    }
    offer = func_02175B34(session);
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
int func_0217F5F0(IntrudeCommSys *sys, u8 netId)
{
    IntrudePeer *peer;
    enum Guard { ZERO, INVALID = 0xFFFF } objCode;

    struct GameData *gameData;

    gameData = func_02026478(sys->gameComm);
    if (netId == func_02012B58(gameData)) {
        peer = &sys->localPeer;
    } else {
        peer = &sys->peers[netId];
    }
    objCode = peer->objCode;
    switch (objCode) {
    case 0:
        if (func_02008550(func_02012950(func_02026478(sys->gameComm), netId)) == 0) {
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
int func_0217F648(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    void *scriptSys = func_0215A5F4(scriptWork);
    struct GameSystem *gameSystem = func_0215A5DC(scriptWork);
    func_0215897C(scriptSys, func_0217F67C(gameSystem, func_02159AE8(vm, scriptWork)));
    return 1;
}


struct GameEvent *func_0217F67C(struct GameSystem *gameSystem, u16 *result)
{
    struct GameEvent *event;
    EventCommExitSyncWork *work;
    int zero;
    zero = 0;
    event = func_020122C0(gameSystem, 0, func_0217F6A0, 0x10);
    work = func_020124E8(event);
    work->result = result;
    *result = zero;
    return event;
}


int func_0217F6A0(struct GameEvent *event, int *seq, void *wk)
{
    EventCommExitSyncWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct GameComm *gameComm;
    IntrudeCommSys *sys;
    struct FieldMap *fieldMap;
    int alone;

    gameSystem = func_020124E4(event);
    gameData = func_020120F4(gameSystem);
    gameComm = func_02012138(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    alone = 0;
    sys = func_02158344(gameComm);
    if (sys == 0 && *seq > 0 && *seq < 5) {
        *seq = 5;
    }
    switch (*seq) {
    case 0: {
        void *fieldMsgbg;
        void *text;
        void *templateText;

        if (func_0200FB24() != 0 || (sys == 0 && func_02012B80(gameData) != func_02012B58(gameData))) {
            *seq = 7;
            break;
        }
        if (sys != 0) {
            func_021757A8(&sys->session);
            func_0217BF1C(&sys->remoteRecord);
        }
        fieldMsgbg = func_02188C54(fieldMap);
        work->msgData = func_021904B0(fieldMsgbg, 0x2D);
        work->window = func_021907A8(fieldMsgbg, work->msgData);
        work->wordSet = func_0201EC64(4);
        func_020061E4(0x547);
        if (sys == 0 || func_0215841C(gameData) == func_02012B58(gameData)) {
            func_02190740(work->window, 0, 0, 0x49);
            alone = 1;
        } else {
            text = func_020457B0(0x100, 0x15);
            templateText = func_02045EC0(work->msgData, 0x4A);
            func_0201F02C(work->wordSet, 0, func_021583EC(gameData, func_0215841C(gameData)));
            func_0201F250(work->wordSet, text, templateText);
            func_02190758(work->window, 0, 0, text);
            func_02045808(templateText);
            func_02045808(text);
        }
        if (func_0203D1B4() <= 1) {
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
        if (func_02173D2C(sys, func_0215841C(gameData)) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        if (func_02175FB4(&sys->session.members[func_0215841C(gameData)]) == 1) {
            (*seq)++;
        }
        break;
    case 3:
        if (func_02173C6C(sys, func_0215841C(gameData)) == 1) {
            (*seq)++;
        }
        break;
    case 4:
        if (func_0217BF28(&sys->remoteRecord) == 1) {
            *work->result = 1;
            *seq = 5;
        }
        break;
    case 5:
        if (func_0219077C(work->window) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (func_020362DC() & 0xF3) {
            func_0201ED04(work->wordSet);
            func_02190728(work->window);
            func_02045C04(work->msgData);
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
int func_0217F8A0(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *result;
    IntrudeCommSys *sys;
    int unused;
    result = func_02159AE8(vm, scriptWork);
    sys = func_02158344(func_02012138(func_0215A5DC(scriptWork)));
    if (sys == 0 || sys->localPeer.objCode == 0) {
        *result = 0;
    } else {
        *result = sys->localPeer.objCode;
    }
    return 0;
}


int func_0217F8D0(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *result;
    IntrudeCommSys *sys;
    int value;

    result = func_02159AE8(vm, scriptWork);
    sys = func_02158344(func_02012138(func_0215A5DC(scriptWork)));
    if (sys != 0 && sys->infoShown == 0 && func_02175B8C(&sys->session) == 1) {
        value = 1;
    } else {
        value = 0;
    }
    *result = value;
    return 0;
}


int func_0217F914(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    void *scriptSys;
    scriptSys = func_0215A5F4(scriptWork);
    func_0215897C(scriptSys, func_0217F938(func_0215A5DC(scriptWork)));
    return 1;
}


struct GameEvent *func_0217F938(struct GameSystem *gameSystem)
{
    struct GameEvent *event;
    event = func_020122C0(gameSystem, 0, func_0217F95C, 0x30);
    func_02082BCC(func_020124E8(event), 0, 0x30);
    return event;
}


int func_0217F95C(struct GameEvent *event, int *seq, void *wk)
{
    EventCommMsgBox *msgBox = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    struct GameEvent *next;

    gameSystem = func_020124E4(event);
    sys = func_02158344(func_02012138(gameSystem));
    if (sys == 0 && *seq < 3) {
        *seq = 3;
    }
    switch (*seq) {
    case 0:
        sys->infoShown = 1;
        func_0217F2B4(msgBox, gameSystem);
        if (func_0217F5A0(&sys->session) == 3) {
            *seq = 2;
        } else {
            func_0217F4A0(msgBox, 0x1A, 0, 0);
            (*seq)++;
        }
        break;
    case 1:
        switch (func_0217F5A0(&sys->session)) {
        case 2:
            break;
        case 3:
        default:
            (*seq)++;
            break;
        }
        break;
    case 2:
        next = func_0217C458(gameSystem, func_0201210C(gameSystem), sys, 0x15);
        func_0217FA1C(msgBox);
        func_0201235C(event, next);
        return 0;
    case 3:
        func_0217FA1C(msgBox);
        return 1;
    }
    return 0;
}


void func_0217FA1C(EventCommMsgBox *msgBox)
{
    func_0217F318(msgBox);
}


struct GameEvent *func_0217FA24(struct GameSystem *gameSystem)
{
    return func_020122C0(gameSystem, 0, func_0217FA38, 0);
}


int func_0217FA38(struct GameEvent *event, int *seq, void *wk)
{
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    struct GameData *gameData;
    struct FieldMap *fieldMap;
    IntrudeCommSys *sys;
    struct GameEvent *next;

    gameSystem = func_020124E4(event);
    gameComm = func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    sys = func_02158344(gameComm);
    switch (*seq) {
    case 0:
        if (sys == 0) {
            func_02012B58(gameData);
        } else {
            func_02176230(sys, &sys->session);
        }
        next = func_0217CE08(gameSystem, fieldMap, 0x117, 1);
        if (next == 0) {
            return 1;
        }
        func_02012374(event, next);
        (*seq)++;
        break;
    case 1:
        if (func_02013D5C(func_02012AC8(func_020120F8(gameSystem))) == 1) {
            func_02012374(event, func_0217F938(gameSystem));
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
int func_0217FAE0(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *result;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    int distance;

    result = func_02159AE8(vm, scriptWork);
    gameSystem = func_0215A5DC(scriptWork);
    func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    if (func_0215841C(gameData) == func_02012B58(gameData)) {
        *result = 0;
    } else {
        distance = func_0215841C(gameData) - func_02012B58(gameData);
        if (distance < 0) {
            distance += 3;
        }
        *result = distance;
    }
    return 0;
}


int func_0217FB2C(ScriptVm *vm, struct ScriptWork *scriptWork)
{
    u16 *result;
    int value;
    result = func_02159AE8(vm, scriptWork);
    if (func_0200BF10(func_0200BE48(func_02012EBC(func_020120F4(func_0215A5DC(scriptWork))))) != 0x30) {
        value = 1;
    } else {
        value = 0;
    }
    *result = value;
    return 0;
}


struct GameEvent *func_0217FB5C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, void *unused, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    EventCommTalkParam *param;
    struct GameEvent *event;
    event = func_020122C0(gameSystem, 0, func_0217FB94, 0x10);
    param = func_020124E8(event);
    func_02082BCC(param, 0, 0x10);
    param->fieldMap = fieldMap;
    param->playerMmdl = playerMmdl;
    param->netId = netId;
    param->heapId = heapId;
    return event;
}


int func_0217FB94(struct GameEvent *event, int *seq, void *wk)
{
    EventCommTalkParam *param = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;

    gameSystem = func_020124E4(event);
    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        if (sys == 0) {
            return 1;
        }
        func_0216D9A0(func_02188C7C(param->fieldMap));
        func_02012374(event, func_0217FC08(gameSystem, param->fieldMap, sys, param->playerMmdl, param->netId, param->heapId));
        (*seq)++;
        break;
    case 1:
        func_0216D9E4(func_02188C7C(param->fieldMap));
        return 1;
    }
    return 0;
}


struct GameEvent *func_0217FC08(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, func_0217FE6C, 0x9c);
    EventCommCommonWork *work = func_020124E8(event);

    func_02082BCC(work, 0, 0x9c);
    func_0217FDA0(gameSystem, sys, work, fieldMap, playerMmdl, netId, heapId);
    func_0217538C(sys, netId);
    func_02175368(sys);
    work->talkType = func_021803F0(work, sys);
    return event;
}


struct GameEvent *func_0217FC6C(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, func_0217FCAC, 0x10);
    EventCommTalkParam *param = func_020124E8(event);

    func_02082BCC(param, 0, 0x10);
    param->fieldMap = fieldMap;
    param->playerMmdl = playerMmdl;
    param->netId = netId;
    param->heapId = heapId;
    func_0217545C(sys);
    return event;
}


int func_0217FCAC(struct GameEvent *event, int *seq, void *wk)
{
    EventCommTalkParam *param = wk;
    struct GameSystem *gameSystem = func_020124E4(event);
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        if (sys == 0) {
            return 1;
        }
        if (func_02167A54(sys->commPlayer, param->netId) == 0) {
            return 1;
        }
        func_0216D9A0(func_02188C7C(param->fieldMap));
        func_02012374(event, func_0217FD34(gameSystem, param->fieldMap, sys, param->playerMmdl, param->netId, param->heapId));
        *seq = *seq + 1;
        break;
    case 1:
        func_0216D9E4(func_02188C7C(param->fieldMap));
        return 1;
    }
    return 0;
}


struct GameEvent *func_0217FD34(struct GameSystem *gameSystem, struct FieldMap *fieldMap, IntrudeCommSys *sys, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    struct GameEvent *event = func_020122C0(gameSystem, 0, func_021800A4, 0x9c);
    EventCommCommonWork *work = func_020124E8(event);

    func_02082BCC(work, 0, 0x9c);
    func_0217FDA0(gameSystem, sys, work, fieldMap, playerMmdl, netId, heapId);
    work->talkType = sys->receivedRequest.type;
    work->member = sys->receivedRequest.data;
    return event;
}


void func_0217FDA0(struct GameSystem *gameSystem, IntrudeCommSys *sys, EventCommCommonWork *work, struct FieldMap *fieldMap, struct FldMmdl *playerMmdl, int netId, u16 heapId)
{
    enum Local { LOCAL_ZERO } partnerNetId;

    work->heapId = heapId;
    work->playerMmdl = playerMmdl;
    partnerNetId = netId;
    work->partnerMmdl = func_02167A14(sys->commPlayer, partnerNetId);
    work->fieldMap = fieldMap;
    work->peerSlot = (u8)netId;
    work->msgIndex = func_0217F5F0(sys, (u8)netId);
    func_02008494(func_021583EC(func_020120F4(gameSystem), partnerNetId), work->myStatus);
    if (func_02175B14(&sys->session) == 1) {
        func_02082D44(func_02175B34(&sys->session), &work->member, 0x34);
    }
    func_0217F2B4(&work->msgBox, gameSystem);
    func_02174E14(sys, 1);
    func_02175368(sys);
    sys->peerFlags = 0;
}


void func_0217FE38(IntrudeCommSys *sys, EventCommCommonWork *work)
{
    func_0217F4C4(&work->msgBox);
    func_0217F318(&work->msgBox);
    if (sys != 0) {
        func_02174E14(sys, 0);
        func_0217538C(sys, 4);
        func_02175368(sys);
    }
}


/*
 * Talk event: the player talked to the partner. State 0 hands a copy of the
 * common work (lines 493 and 517) to the event of the partner's state; else
 * it sends the talk request and waits for the answer.
 */
int func_0217FE6C(struct GameEvent *event, int *seq, void *wk)
{
    EventCommTalkWork *work = wk;
    IntrudeCommSys *sys;
    u8 *signal;
    void *copy;
    int requestKind;

    sys = func_02158344(func_02012138(func_020124E4(event)));
    if (sys == 0) {
        if (func_0217F40C(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq <= 6) {
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 8;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        requestKind = func_02175DCC(&sys->session);
        if (sys->peers[work->common.peerSlot].lidClosed == 1) {
            copy = func_02030734((u16)((work->common.heapId & 0x7FFF) | 0x8000), 0x98, 1, sEventCommCommonFile, 493);
            func_02082D44(work, copy, 0x98);
            if (func_02175BCC(&sys->session) == 0 && func_02175B14(&sys->session) == 1
                && func_02175B8C(&sys->session) == 1 && func_0217620C(&sys->session, work->common.peerSlot) == 1) {
                func_02182A08(event, copy);
            } else {
                func_02182998(event, copy);
            }
            func_020307B0(copy);
        } else if (sys->peers[work->common.peerSlot].state != 0) {
            copy = func_02030734((u16)((work->common.heapId & 0x7FFF) | 0x8000), 0x98, 1, sEventCommCommonFile, 517);
            func_02082D44(work, copy, 0x98);
            if (sys->peers[work->common.peerSlot].state == 2) {
                if (requestKind == 5) {
                    func_02181BE8(event, copy);
                } else {
                    func_02182988(event, copy);
                }
            } else {
                func_02182998(event, copy);
            }
            func_020307B0(copy);
        } else {
            (*seq)++;
        }
        break;
    case 1:
        if (func_02174258(sys) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        switch (func_02175C40(&sys->session)) {
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
        switch (func_0217C914(sys, work, &work->answerSeq)) {
        case 1:
            func_0217553C(sys);
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
        if (func_02173C04(work->common.peerSlot, work->answer) == 1) {
            (*seq)++;
        }
        break;
    case 5:
        signal = func_0217537C(sys);
        if (signal != 0) {
            if (signal[1] != work->answer || work->answer == 1) {
                work->common.talkType = 0;
            }
            (*seq)++;
        }
        break;
    case 6:
        func_021802A8(event, &work->common, sys);
        return 0;
    case 7:
        *seq = 9;
        break;
    case 8:
        if (func_0217F420() == 1) {
            *seq = 9;
        }
        break;
    case 9:
        func_0217FE38(sys, &work->common);
        return 1;
    }
    return 0;
}


/*
 * Talked event: the partner talked to this player. Answers the request and
 * changes to the talked type event; skips to state 10 when the visit ends.
 */
int func_021800A4(struct GameEvent *event, int *seq, void *wk)
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

    gameSystem = func_020124E4(event);
    gameComm = func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    sys = func_02158344(gameComm);
    if (sys == 0) {
        if (func_0217F40C(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 10) {
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 10;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        func_0217553C(sys);
        func_0216D9A0(func_02188C7C(work->common.fieldMap));
        func_0201F02C(work->common.msgBox.wordSet, 0, func_02012950(gameData, sys->requestTarget));
        func_0217F3C4(&work->common.msgBox, 1);
        (*seq)++;
        break;
    case 1:
        if (func_0216D3CC(work->common.playerMmdl) == 1) {
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
            func_0216D410(work->common.playerMmdl, acmd);
            (*seq)++;
        }
        break;
    case 2:
        if (func_0216D480(work->common.playerMmdl) == 1) {
            (*seq)++;
        }
        break;
    case 3:
        if (func_02174258(sys) == 1) {
            (*seq)++;
        }
        break;
    case 4:
        switch (func_02175C40(&sys->session)) {
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
        if (func_02173AE0(sys, sys->requestTarget, sys->requestActive, sys->sentRequestSeq) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            dir = func_02175514(sys);
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
                func_0217F3C4(&work->common.msgBox, 4);
                *seq = 10;
            }
        }
        break;
    case 7:
        if (func_02173C04(sys->requestTarget, work->answer) == 1) {
            (*seq)++;
        }
        break;
    case 8:
        signal = func_0217537C(sys);
        if (signal != 0) {
            if (signal[1] != work->answer || work->answer == 1) {
                work->common.talkType = 0;
            }
            *seq = 9;
        }
        break;
    case 9:
        func_0218034C(event, &work->common, sys);
        return 0;
    case 10:
        if (func_0217F420() == 1) {
            *seq = 11;
        }
        break;
    case 11:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            func_0216D9E4(func_02188C7C(work->common.fieldMap));
            func_0217FE38(sys, &work->common);
            return 1;
        }
        break;
    }
    return 0;
}


extern void (*sTalkEventTable[])(struct GameEvent *event, EventCommCommonWork *work);


void func_021802A8(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys)
{
    EventCommCommonWork *copy = func_02030734((u16)((work->heapId & 0x7fff) | 0x8000), 0x98, 1, sEventCommCommonFile, 0x329);
    unsigned int talkType;

    MI_CpuCopy8(work, copy, 0x98);
    talkType = work->talkType;
    if (talkType == 0) {
        func_021808C4(event, copy);
    } else if (talkType == 1) {
        func_021829F8(event, copy);
    } else if (talkType == 2) {
        func_021808C4(event, copy);
    } else if (talkType >= 3) {
        if (sTalkEventTable[talkType - 8] == 0) {
            func_02034714(sEmptyTextTalkTable, 0, sEmptyTextTalkTable);
        }
        sTalkEventTable[work->talkType - 8](event, copy);
    } else {
        func_021808C4(event, copy);
    }
    func_020307B0(copy);
}


extern void (*sTalkedEventTable[])(struct GameEvent *event, EventCommCommonWork *work);


void func_0218034C(struct GameEvent *event, EventCommCommonWork *work, IntrudeCommSys *sys)
{
    EventCommCommonWork *copy = func_02030734((u16)((work->heapId & 0x7fff) | 0x8000), 0x98, 1, sEventCommCommonFile, 0x354);
    unsigned int talkType;

    MI_CpuCopy8(work, copy, 0x98);
    talkType = work->talkType;
    if (talkType == 0) {
        func_02180978(event, copy);
    } else if (talkType == 1) {
        func_021829F8(event, copy);
    } else if (talkType == 2) {
        func_02180978(event, copy);
    } else if (talkType >= 3) {
        if (sTalkedEventTable[talkType - 8] == 0) {
            func_02034714(sEmptyTextTalkTable, 0, sEmptyTextTalkTable);
        }
        sTalkedEventTable[work->talkType - 8](event, copy);
    } else {
        func_02180978(event, copy);
    }
    func_020307B0(copy);
}


static inline int EVENT_COMM_COMMON_GetTalkCase(EventCommCommonWork *work, IntrudeCommSys *sys, u8 myNetId)
{
    if (func_02175BCC(&sys->session) == 0 && func_02175B14(&sys->session) == 1) {
        if (func_02175B8C(&sys->session) == 1) {
            if (func_0217620C(&sys->session, work->peerSlot) == 1)
                return 3;
            if (sys->peers[work->peerSlot].eventJoined == 1)
                return 4;
            return 5;
        }
        if (func_0217620C(&sys->session, myNetId) == 1) {
            if (sys->peers[work->peerSlot].eventJoined == 1)
                return 6;
            return 7;
        }
        if (sys->peers[work->peerSlot].eventJoined == 1)
            return 1;
        if (func_0217620C(&sys->session, work->peerSlot) == 1)
            return 2;
        return 0;
    }
    return 0;
}


int func_021803F0(EventCommCommonWork *work, IntrudeCommSys *sys)
{
    u8 myNetId;
    int requestKind;
    int talkType;

    myNetId = (int)func_02012B58(func_020120F4(func_02188C80(work->fieldMap)));
    requestKind = func_02175DCC(&sys->session);
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



struct GameEvent *func_021804F8(struct GameSystem *gameSystem, int showResult)
{
    struct FieldMap *fieldMap = func_0201210C(gameSystem);
    struct GameEvent *event = func_020122C0(gameSystem, 0, func_02180538, sizeof(EventCommMissionResultWork));
    EventCommMissionResultWork *work = func_020124E8(event);

    func_02082BCC(work, 0, sizeof(EventCommMissionResultWork));
    work->heapId = func_02188C84(fieldMap);
    work->showResult = showResult;
    return event;
}

/*
 * Mission result event: waits for the result of the visit, shows the
 * mission and the reward, and gives the reward items.
 */
int func_02180538(struct GameEvent *event, int *seq, void *wk)
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

    gameSystem = func_020124E4(event);
    gameComm = func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    func_0201210C(gameSystem);
    switch (*seq) {
    case 0:
        sys = 0;
        if (func_02026454(gameComm) == 2) {
            sys = func_02026474(gameComm);
        }
        if (work->showResult == 0) {
            if (sys != 0 && func_0200FB24() == 0 && func_02175E90(sys, &sys->session) == 1) {
                sys->abortFlag = 1;
            }
            return 1;
        }
        if (sys != 0 && func_02175DA8(&sys->session) == 1 && func_021756A4(sys) == 1) {
            if (func_02175E90(sys, &sys->session) == 0) {
                return 1;
            }
            work->tallyCountA = sys->partnerTally.countA;
            work->tallyCountB = sys->partnerTally.countB;
            func_0217F2B4(&work->msgBox, gameSystem);
            result = func_02175BCC(&sys->session);
            battleRec = func_020127B8(gameData);
            if (result == 0) {
                func_02034714(sEmptyTextResult, 0, sEmptyTextResult);
            }
            work->result = *result;
            work->missionKind = result->record.head.kind;
            work->missionPoint = result->record.head.pointIndex;
            work->hasReward = func_02175E90(sys, &sys->session);
            work->rewardCount = func_02175DE4(sys, &sys->session);
            func_0200BE24(battleRec, work->tallyCountB);
            func_0200BE00(battleRec, work->tallyCountA);
            (*seq)++;
            break;
        }
        if (sys == 0 || func_0200FB24() != 0) {
            return 1;
        }
        break;
    case 1:
        func_021762D8(&work->result.record, &work->result.record.name, work->msgBox.wordSet, work->heapId);
        func_0217F528(&work->msgBox, gameSystem, 1, 4, 0x1E, 0x10);
        func_0217F574(&work->msgBox, work->missionKind, 8, 0);
        func_0217F574(&work->msgBox, work->missionPoint, 8, 0x10);
        (*seq)++;
        break;
    case 2:
        work->waitFrames++;
        if (work->waitFrames > 60) {
            func_0217F58C(&work->msgBox);
            *seq = 3;
        }
        break;
    case 3:
        if (work->hasReward == 1) {
            func_0217F4A0(&work->msgBox, 0x19, 0, 0);
            func_02012374(event, func_02029830(gameSystem, 0x52C));
            *seq = 4;
        } else {
            func_0217F4A0(&work->msgBox, 0x17, 0, 0);
            func_02012374(event, func_02029830(gameSystem, 0x52D));
            *seq = 11;
        }
        break;
    case 4:
        if (func_02005F38() == 0) {
            func_02012374(event, func_02029620(gameSystem, 0, 6));
            myItem = func_0201292C(gameData);
            count = func_02007FB8(myItem, 0x23F, work->heapId);
            reward = work->rewardCount;
            if (func_0200823C(0x23F) < count + reward) {
                reward = func_0200823C(0x23F) - count;
            }
            func_02007E50(myItem, 0x23F, reward, work->heapId);
            func_0200BF78(func_0200BE48(func_02012EBC(gameData)));
            func_0201EFA4(work->msgBox.wordSet, 0, work->rewardCount, 3, 0, 1);
            func_0217F3C4(&work->msgBox, 0x18);
            (*seq)++;
        }
        break;
    case 5:
        if (func_0217F40C(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (work->tallyCountB != 0) {
            func_0201EFA4(work->msgBox.wordSet, 0, work->tallyCountB, 3, 0, 1);
            func_0217F3C4(&work->msgBox, 0x30);
            (*seq)++;
        } else {
            *seq = 8;
        }
        break;
    case 7:
        if (func_0217F40C(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 8:
        if (work->tallyCountA != 0) {
            func_0201EFA4(work->msgBox.wordSet, 0, work->tallyCountA, 3, 0, 1);
            func_0217F3C4(&work->msgBox, 0x31);
            (*seq)++;
        } else {
            *seq = 10;
        }
        break;
    case 9:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 10;
        }
        break;
    case 10:
        *seq = 12;
        break;
    case 11:
        if (func_02005F38() == 0) {
            func_02012374(event, func_02029620(gameSystem, 0, 6));
            *seq = 12;
        }
        break;
    case 12:
        func_0217F318(&work->msgBox);
        func_0201235C(event, func_0217CA84(gameSystem, 0));
        return 0;
    }
    return 0;
}
void func_021808C4(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_021808E8, 0xA8);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

int func_021808E8(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem = func_020124E4(event);
    struct GameData *gameData = func_020120F4(gameSystem);
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, func_02012950(gameData, work->peerSlot));
        func_0217F3C4(&work->msgBox, sTalkMsgIds[work->msgIndex]);
        *seq = *seq + 1;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = *seq + 1;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = *seq + 1;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

void func_02180978(struct GameEvent *event, EventCommCommonWork *src)
{
    func_021808C4(event, src);
}

void func_02180980(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_021809A4, 0xA4);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

/*
 * Mission achieve event: the player talked to the target of the mission.
 * Reports the achievement, then starts the mission result event.
 */
int func_021809A4(struct GameEvent *event, int *seq, void *wk)
{
    EventCommMissionTalkWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;

    gameSystem = func_020124E4(event);
    sys = func_02158344(func_02012138(gameSystem));
    if (sys == 0 && *seq <= 1) {
        if (func_0217F40C(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 5) {
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 5;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        if (func_0217405C(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 1:
        if (func_02175CF4(sys, &sys->session) != 0) {
            work->achieved = 1;
            (*seq)++;
        }
        break;
    case 2:
        func_0201F02C(work->common.msgBox.wordSet, 0, work->common.myStatus);
        func_0201F02C(work->common.msgBox.wordSet, 1, func_02012944(func_020120F4(gameSystem)));
        func_0201F184(work->common.msgBox.wordSet, 2, work->common.member.head.param.x);
        func_0217F3C4(&work->common.msgBox, sMissionAchieveMsgIdsA[work->common.msgIndex]);
        (*seq)++;
        break;
    case 3:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            func_0217F3C4(&work->common.msgBox, sMissionAchieveMsgIdsB[work->common.msgIndex]);
            (*seq)++;
        }
        break;
    case 4:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            func_0217F3C4(&work->common.msgBox, sMissionAchieveMsgIdsC[work->common.msgIndex]);
            func_020061E4(0x5E0);
            (*seq)++;
        }
        break;
    case 5:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            *seq = 6;
        }
        break;
    case 6:
        if (func_0217F420() == 1) {
            *seq = 7;
        }
        break;
    case 7:
        func_0217FE38(sys, &work->common);
        func_0201235C(event, func_021804F8(gameSystem, work->achieved));
        return 0;
    }
    return 0;
}
void func_02180B14(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02180B38, 0xA4);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

int func_02180B38(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem = func_020124E4(event);
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0201F02C(work->msgBox.wordSet, 1, func_02012944(func_020120F4(gameSystem)));
        func_0201F184(work->msgBox.wordSet, 2, work->member.head.param.x);
        func_0217F3C4(&work->msgBox, sTalkPowerGiftAsTargetMsgIds[work->msgIndex]);
        *seq = *seq + 1;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

void func_02180BDC(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02180C00, 0xA4);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

int func_02180C00(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem = func_020124E4(event);
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0201F02C(work->msgBox.wordSet, 1, func_02012944(func_020120F4(gameSystem)));
        func_0201F184(work->msgBox.wordSet, 2, work->member.head.param.x);
        func_0217F3C4(&work->msgBox, sTalkedPowerGiftAsTargetMsgIds[work->msgIndex]);
        *seq = *seq + 1;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

void func_02180CA4(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02180CC8, 0xA4);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

/*
 * Talked event: shows the notice, activates the G-Power of the mission
 * argument (overlay 83), then reopens the text box for the closing message.
 */
int func_02180CC8(struct GameEvent *event, int *seq, void *wk)
{
    EventCommGPowerTalkWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    EventCommGPowerParam param;

    gameSystem = func_020124E4(event);
    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        func_0201F02C(work->common.msgBox.wordSet, 0, work->common.myStatus);
        func_0201F02C(work->common.msgBox.wordSet, 1, func_02012944(func_020120F4(gameSystem)));
        func_0201F184(work->common.msgBox.wordSet, 2, work->common.member.head.param.x);
        work->msgIndex = work->common.msgIndex;
        func_0217F3C4(&work->common.msgBox, sTalkedPowerGiftTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        func_0217F318(&work->common.msgBox);
        param.powerId = work->common.member.head.param.x;
        param.arg = 0;
        func_02012374(event, func_020124AC(gameSystem, (u32)ov083_id, func_021F5260, &param));
        (*seq)++;
        break;
    case 3:
        *seq = 4;
        break;
    case 4:
        func_0217F2B4(&work->common.msgBox, gameSystem);
        func_0201F02C(work->common.msgBox.wordSet, 0, work->common.myStatus);
        func_0217F3C4(&work->common.msgBox, sTalkedPowerGiftEndMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 5:
        if (func_0217F40C(&work->common.msgBox) == 1 && func_0217F420() == 1) {
            (*seq)++;
        }
        break;
    case 6:
        func_0217FE38(sys, &work->common);
        return 1;
    }
    return 0;
}

void func_02180DE8(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02180E0C, 0xA0);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

int func_02180E0C(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem = func_020124E4(event);
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0201F02C(work->msgBox.wordSet, 1, func_02012944(func_020120F4(gameSystem)));
        func_0201F184(work->msgBox.wordSet, 2, work->member.head.param.x);
        func_0217F3C4(&work->msgBox, sTalkPowerShareTargetMsgIds[work->msgIndex]);
        *seq = *seq + 1;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

void func_02180EB0(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02180ED4, 0xA0);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

/* Talk event: shows the notice, then activates the G-Power of the mission argument (overlay 83). */
int func_02180ED4(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    EventCommGPowerParam param;

    gameSystem = func_020124E4(event);
    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0201F02C(work->msgBox.wordSet, 1, func_02012944(func_020120F4(gameSystem)));
        func_0201F184(work->msgBox.wordSet, 2, work->member.head.param.x);
        func_0217F3C4(&work->msgBox, sTalkPowerShareAsTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        func_0217F318(&work->msgBox);
        param.powerId = work->member.head.param.x;
        param.arg = 0;
        func_02012374(event, func_020124AC(gameSystem, (u32)ov083_id, func_021F5260, &param));
        (*seq)++;
        break;
    case 3:
        *seq = 4;
        break;
    case 4:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

void func_02180FA8(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02180FCC, 0xA0);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

/* Talked event: the mission is achieved; reports it, then starts the mission result event. */
int func_02180FCC(struct GameEvent *event, int *seq, void *wk)
{
    EventCommMissionTalkWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;

    gameSystem = func_020124E4(event);
    sys = func_02158344(func_02012138(gameSystem));
    if (sys == 0 && *seq <= 1) {
        if (func_0217F40C(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 4) {
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 4;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        if (func_0217405C(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 1:
        if (func_02175CF4(sys, &sys->session) != 0) {
            work->achieved = 1;
            (*seq)++;
        }
        break;
    case 2:
        func_0201F02C(work->common.msgBox.wordSet, 0, work->common.myStatus);
        func_0201F02C(work->common.msgBox.wordSet, 1, func_02012944(func_020120F4(gameSystem)));
        func_0201F184(work->common.msgBox.wordSet, 2, work->common.member.head.param.x);
        func_0217F3C4(&work->common.msgBox, sTalkedPowerShareAchieveMsgIdsA[work->common.msgIndex]);
        (*seq)++;
        break;
    case 3:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            func_0217F3C4(&work->common.msgBox, sTalkedPowerShareAchieveMsgIdsB[work->common.msgIndex]);
            func_020061E4(0x5E0);
            (*seq)++;
        }
        break;
    case 4:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            *seq = 5;
        }
        break;
    case 5:
        if (func_0217F420() == 1) {
            *seq = 6;
        }
        break;
    case 6:
        func_0217FE38(sys, &work->common);
        func_0201235C(event, func_021804F8(gameSystem, work->achieved));
        return 0;
    }
    return 0;
}

void func_0218111C(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02181140, 0xA0);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

int func_02181140(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem = func_020124E4(event);
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0201F02C(work->msgBox.wordSet, 1, func_02012944(func_020120F4(gameSystem)));
        func_0201F184(work->msgBox.wordSet, 2, work->member.head.param.x);
        func_0217F3C4(&work->msgBox, sTalkedPowerShareTargetMsgIds[work->msgIndex]);
        *seq = *seq + 1;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}
void func_021811E4(struct GameEvent *event, EventCommCommonWork *src)
{
    struct GameSystem *gameSystem;
    EventCommBattleTalkWork *work;

    gameSystem = func_020124E4(event);
    func_0201232C(event, func_0218123C, sizeof(EventCommBattleTalkWork));
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
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
int func_0218123C(struct GameEvent *event, int *seq, void *wk)
{
    EventCommBattleTalkWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    IntrudeCommSys *sys;
    struct GameEvent *next;

    gameSystem = func_020124E4(event);
    gameComm = func_02012138(gameSystem);
    sys = func_02158344(gameComm);
    if (sys == 0) {
        if (func_0217F40C(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 13) {
            func_0217F2B4(&work->common.msgBox, gameSystem);
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 13;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        func_0201F02C(work->common.msgBox.wordSet, 0, work->common.myStatus);
        func_0201EFA4(work->common.msgBox.wordSet, 1, work->battle.battleArg, 3, 0, 1);
        func_0217F3C4(&work->common.msgBox, work->battle.isTalked == 0 ? sBattleRequestMsgIds[work->common.msgIndex] : sBattleRequestTalkedMsgIds[work->common.msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            switch (func_02175514(sys)) {
            case 4:
                *seq = 2;
                break;
            case 2:
            case 3:
                *seq = 11;
                break;
            default:
                if ((func_020362DC() & 2) && func_02173B9C(sys->requestTarget, sys->sentRequestSeq) == 1) {
                    func_021753B8(sys);
                    *seq = 12;
                }
                break;
            }
        }
        break;
    case 2:
        func_0217F3C4(&work->common.msgBox, sBattleRequestAcceptedMsgIds[work->common.msgIndex]);
        *seq = 3;
        break;
    case 3:
        if (func_0217405C(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 4:
        if (func_02175CF4(sys, &sys->session) != 0) {
            func_021756F0(sys, 1);
            *seq = 5;
        }
        break;
    case 5:
        if (func_0217F40C(&work->common.msgBox) == 1 && func_021744D0(sys, work->common.peerSlot, 1) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (func_0215839C(sys, 1, work->common.peerSlot) == 1) {
            *seq = 7;
        } else if ((func_020362DC() & 2) && func_02173B9C(sys->requestTarget, sys->sentRequestSeq) == 1) {
            func_021753B8(sys);
            *seq = 12;
        }
        break;
    case 7:
        if (func_021744D0(sys, work->common.peerSlot, 2) == 1) {
            (*seq)++;
        }
        break;
    case 8:
        if (func_0215839C(sys, 2, work->common.peerSlot) == 1) {
            func_0217F318(&work->common.msgBox);
            *seq = 9;
        } else if (func_02175514(sys) == 3) {
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 13;
        }
        break;
    case 9:
        work->battleDone = 1;
        func_02012374(event, func_021766CC(gameSystem, &work->battle));
        (*seq)++;
        break;
    case 10:
        func_0217F2B4(&work->common.msgBox, gameSystem);
        func_0217F3C4(&work->common.msgBox, sBattleRequestEndMsgIds[work->common.msgIndex]);
        *seq = 13;
        break;
    case 11:
        func_0217F3C4(&work->common.msgBox, sBattleRequestRefusedMsgIds[work->common.msgIndex]);
        *seq = 13;
        break;
    case 12:
        work->canceled = 1;
        *seq = 15;
        break;
    case 13:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            *seq = 14;
        }
        break;
    case 14:
        if (func_0217F420() == 1) {
            *seq = 15;
        }
        break;
    case 15:
        func_0217FE38(sys, &work->common);
        if (func_02026454(gameComm) == 2 && func_02026474(gameComm) != 0) {
            func_021756F0(func_02026474(gameComm), 0);
        }
        if (work->battleDone == 1) {
            next = func_021804F8(gameSystem, work->battleDone);
        } else if (work->canceled == 0) {
            next = func_0217CA84(gameSystem, 1);
        } else {
            next = func_0217CA84(gameSystem, 0);
        }
        func_0201235C(event, next);
        return 0;
    }
    return 0;
}

void func_0218152C(struct GameEvent *event, EventCommCommonWork *src)
{
    struct GameSystem *gameSystem;
    EventCommBattleTalkWork *work;

    gameSystem = func_020124E4(event);
    func_0201232C(event, func_02181584, sizeof(EventCommBattleTalkWork));
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
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
int func_02181584(struct GameEvent *event, int *seq, void *wk)
{
    EventCommBattleTalkWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    IntrudeCommSys *sys;

    gameSystem = func_020124E4(event);
    gameComm = func_02012138(gameSystem);
    sys = func_02158344(gameComm);
    if (sys == 0) {
        if (func_0217F40C(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 14 && *seq != 1 && *seq != 2) {
            func_0217F2B4(&work->common.msgBox, gameSystem);
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 14;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        func_0201F02C(work->common.msgBox.wordSet, 0, work->common.myStatus);
        func_0201EFA4(work->common.msgBox.wordSet, 1, work->battle.battleArg, 3, 0, 1);
        func_0217F3C4(&work->common.msgBox, work->battle.isTalked == 0 ? sBattleAnswerMsgIds[work->common.msgIndex] : sBattleAnswerTalkedMsgIds[work->common.msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            func_0217F4D8(&work->common.msgBox, gameSystem);
            (*seq)++;
        }
        break;
    case 2:
        switch (func_0217F508(&work->common.msgBox)) {
        case 0:
            func_0217F4C4(&work->common.msgBox);
            *seq = 3;
            break;
        case 1:
            func_0217F4C4(&work->common.msgBox);
            *seq = 11;
            break;
        }
        break;
    case 3:
        if (func_02173AE0(sys, sys->requestTarget, 4, sys->sentRequestSeq) == 1) {
            func_021756F0(sys, 1);
            *seq = 4;
        }
        break;
    case 4:
        func_0217F3C4(&work->common.msgBox, sBattleAnswerAcceptedMsgIds[work->common.msgIndex]);
        (*seq)++;
        break;
    case 5:
        if (func_0217F40C(&work->common.msgBox) == 1 && func_021744D0(sys, work->common.peerSlot, 1) == 1) {
            (*seq)++;
        }
        break;
    case 6:
        if (func_0215839C(sys, 1, work->common.peerSlot) == 1) {
            *seq = 7;
        } else if (func_020362DC() & 2) {
            if (func_02173B9C(sys->requestTarget, sys->sentRequestSeq) == 1) {
                func_021753B8(sys);
                *seq = 13;
                func_02026400(gameComm);
            }
        } else if (func_02175514(sys) == 3) {
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 14;
        }
        break;
    case 7:
        if (func_021744D0(sys, work->common.peerSlot, 2) == 1) {
            (*seq)++;
        }
        break;
    case 8:
        if (func_0215839C(sys, 2, work->common.peerSlot) == 1) {
            func_0217F318(&work->common.msgBox);
            *seq = 9;
        } else if (func_02175514(sys) == 3) {
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 14;
        }
        break;
    case 9:
        func_02012374(event, func_021766CC(gameSystem, &work->battle));
        (*seq)++;
        break;
    case 10:
        func_0217F2B4(&work->common.msgBox, gameSystem);
        func_0217F3C4(&work->common.msgBox, sBattleAnswerEndMsgIds[work->common.msgIndex]);
        *seq = 14;
        break;
    case 11:
        if (func_02173AE0(sys, sys->requestTarget, 2, sys->sentRequestSeq) == 1) {
            func_021763D8(func_020127B8(func_020120F4(gameSystem)), 0);
            *seq = 12;
        }
        break;
    case 12:
        func_0217F3C4(&work->common.msgBox, sBattleAnswerRefusedMsgIds[work->common.msgIndex]);
        *seq = 14;
        break;
    case 13:
        *seq = 16;
        break;
    case 14:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            *seq = 15;
        }
        break;
    case 15:
        if (func_0217F420() == 1) {
            *seq = 16;
        }
        break;
    case 16:
        func_0217FE38(sys, &work->common);
        if (func_02026454(gameComm) == 2 && func_02026474(gameComm) != 0) {
            func_021756F0(func_02026474(gameComm), 0);
        }
        return 1;
    }
    return 0;
}

void func_0218186C(struct GameEvent *event, EventCommCommonWork *src)
{
    struct GameSystem *gameSystem;
    EventCommBattleTalkWork *work;

    gameSystem = func_020124E4(event);
    func_0201232C(event, func_0218123C, sizeof(EventCommBattleTalkWork));
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
    work->battle.isTalked = 1;
    work->battle.gameSystem = gameSystem;
    work->battle.partnerNetId = work->common.peerSlot;
    work->battle.battleArg = src->member.head.param.x;
    work->battle.linkMode = 2;
}

void func_021818C4(struct GameEvent *event, EventCommCommonWork *src)
{
    struct GameSystem *gameSystem;
    EventCommBattleTalkWork *work;

    gameSystem = func_020124E4(event);
    func_0201232C(event, func_02181584, sizeof(EventCommBattleTalkWork));
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
    work->battle.isTalked = 1;
    work->battle.gameSystem = gameSystem;
    work->battle.partnerNetId = work->common.peerSlot;
    work->battle.battleArg = src->member.head.param.x;
    work->battle.linkMode = 2;
}
void func_0218191C(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02181940, 0xA4);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

int func_02181940(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(func_020124E4(event)));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0217F3C4(&work->msgBox, sTalkSearchTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 3;
        }
        break;
    case 3:
        if (func_0217F420() == 1) {
            *seq = 4;
        }
        break;
    case 4:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

void func_021819D0(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_021819F4, 0xA4);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

int func_021819F4(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(func_020124E4(event)));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0217F3C4(&work->msgBox, sTalkSearchAsTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

void func_02181A74(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02181A98, 0xA4);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

/* Talked event: shows the notice; when the visit is still running, warps back to the palace. */
int func_02181A98(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    IntrudeCommSys *sys;

    gameSystem = func_020124E4(event);
    gameComm = func_02012138(gameSystem);
    sys = func_02158344(gameComm);
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0217F3C4(&work->msgBox, sTalkedSearchAsTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        if (func_02158344(gameComm) != 0) {
            func_020061E4(0x737);
            func_0201235C(event, func_0217CA1C(gameSystem));
            return 0;
        }
        return 1;
    }
    return 0;
}

void func_02181B44(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02181B68, 0xA4);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

int func_02181B68(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(func_020124E4(event)));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0217F3C4(&work->msgBox, sTalkedSearchTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

void func_02181BE8(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02181C0C, 0xA4);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

/*
 * Talk event of the found partner: waits for the session answer, reports
 * the mission, then starts the mission result event.
 */
int func_02181C0C(struct GameEvent *event, int *seq, void *wk)
{
    EventCommMissionTalkWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    int joinStatus;

    gameSystem = func_020124E4(event);
    sys = func_02158344(func_02012138(gameSystem));
    if (sys == 0 && *seq <= 2 && *seq < 6) {
        func_0217F3C4(&work->common.msgBox, 4);
        *seq = 6;
        work->disconnected = 1;
        return 0;
    }
    switch (*seq) {
    case 0:
        if (func_0217405C(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 1:
        joinStatus = work->joinStatus = func_02175CF4(sys, &sys->session);
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
        if (func_0217456C(sys, work->common.peerSlot, 2) == 1) {
            (*seq)++;
        }
        break;
    case 3:
        work->achieved = 1;
        func_021762D8(&work->common.member, &work->common.member.name, work->common.msgBox.wordSet, work->common.heapId);
        func_0217F3C4(&work->common.msgBox, sSearchFoundMsgIdsA[work->common.msgIndex]);
        (*seq)++;
        break;
    case 4:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            func_0217F3C4(&work->common.msgBox, sSearchFoundMsgIdsB[work->common.msgIndex]);
            func_020061E4(0x5E0);
            *seq = 6;
        }
        break;
    case 5:
        work->achieved = 1;
        func_021762D8(&work->common.member, &work->common.member.name, work->common.msgBox.wordSet, work->common.heapId);
        func_0217F3C4(&work->common.msgBox, sSearchFoundOtherMsgIds[work->common.msgIndex]);
        *seq = 6;
        break;
    case 6:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            *seq = 7;
        }
        break;
    case 7:
        if (func_0217F420() == 1) {
            *seq = 8;
        }
        break;
    case 8:
        func_0217FE38(sys, &work->common);
        if (work->joinStatus == 1) {
            func_0201235C(event, func_021804F8(gameSystem, work->achieved));
            return 0;
        }
        return 1;
    }
    return 0;
}

/* Message event after a link battle: thanks the player whose support record is active. */
struct GameEvent *func_02181D8C(struct GameSystem *gameSystem, u32 heapId)
{
    void *pmsWork;
    struct GameEvent *event;
    EventCommSupportMsgWork *work;

    pmsWork = func_02012F20(func_020120F4(gameSystem));
    event = func_020122C0(gameSystem, 0, func_02181DD4, sizeof(EventCommSupportMsgWork));
    work = func_020124E8(event);
    work->myStatus = func_0200846C(heapId);
    func_02008494(func_0202E82C(pmsWork), work->myStatus);
    func_0217F2B4(&work->msgBox, gameSystem);
    return event;
}

int func_02181DD4(struct GameEvent *event, int *seq, void *wk)
{
    EventCommSupportMsgWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameEvent *script;

    gameSystem = func_020124E4(event);
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0217F3C4(&work->msgBox, 0x1C);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        func_0217F318(&work->msgBox);
        script = func_02158768(gameSystem, 0xAFD, 0, 4);
        func_02159058(func_021589D0(script), 0x1C, 1, 0, 0);
        func_02012374(event, script);
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
void func_02181E6C(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02181E90, 0x9C);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

int func_02181E90(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(func_020124E4(event)));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0217F3C4(&work->msgBox, sTalkGreetingTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

void func_02181F10(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02181F34, 0x9C);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

int func_02181F34(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(func_020124E4(event)));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0217F3C4(&work->msgBox, sTalkGreetingAsTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

void func_02181FB4(struct GameEvent *event, EventCommCommonWork *src)
{
    void *work;
    func_0201232C(event, func_02181FD8, 0x9C);
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
}

/* Talked event: shows the notice; when the visit is still running, warps back to the palace. */
int func_02181FD8(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;

    gameSystem = func_020124E4(event);
    sys = func_02158344(func_02012138(gameSystem));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0217F3C4(&work->msgBox, sTalkedGreetingAsTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        if (sys != 0) {
            func_020061E4(0x737);
            func_0201235C(event, func_0217CA1C(gameSystem));
            return 0;
        }
        return 1;
    }
    return 0;
}

void func_02182080(struct GameEvent *event, EventCommCommonWork *src)
{
    func_0201232C(event, func_021820A4, 0x9C);
    func_02082D44(src, func_020124E8(event), sizeof(EventCommCommonWork));
}

int func_021820A4(struct GameEvent *event, int *seq, void *wk)
{
    EventCommCommonWork *work = wk;
    IntrudeCommSys *sys;

    sys = func_02158344(func_02012138(func_020124E4(event)));
    switch (*seq) {
    case 0:
        func_0201F02C(work->msgBox.wordSet, 0, work->myStatus);
        func_0217F3C4(&work->msgBox, sTalkedGreetingTargetMsgIds[work->msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 2;
        }
        break;
    case 2:
        if (func_0217F420() == 1) {
            *seq = 3;
        }
        break;
    case 3:
        func_0217FE38(sys, work);
        return 1;
    }
    return 0;
}

/* Offer event: keeps the field objects still while the offer answer event runs. */
struct GameEvent *func_02182124(struct GameSystem *gameSystem, IntrudeCommSys *sys, IntrudeMemberRecord *offer)
{
    struct GameEvent *event;
    event = func_020122C0(gameSystem, 0, func_02182150, sizeof(IntrudeMemberRecord));
    *(IntrudeMemberRecord *)func_020124E8(event) = *offer;
    return event;
}

int func_02182150(struct GameEvent *event, int *seq, void *wk)
{
    IntrudeMemberRecord *offer = wk;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap;

    gameSystem = func_020124E4(event);
    fieldMap = func_0201210C(gameSystem);
    switch (*seq) {
    case 0:
        func_0216D9A0(func_02188C7C(fieldMap));
        func_02012374(event, func_021821B0(gameSystem, offer));
        (*seq)++;
        break;
    case 1:
        if (fieldMap != 0 && func_02188BE8(fieldMap) == 1) {
            func_0216D9E4(func_02188C7C(fieldMap));
            return 1;
        }
        break;
    }
    return 0;
}

struct GameEvent *func_021821B0(struct GameSystem *gameSystem, IntrudeMemberRecord *offer)
{
    void *myStatus;
    struct GameEvent *event;
    EventCommOfferWork *work;
    struct GameData *gameData;
    IntrudeParamPair *param;

    gameData = func_020120F4(gameSystem);
    param = &offer->head.param;
    myStatus = func_02012944(gameData);
    event = func_020122C0(gameSystem, 0, func_02182214, sizeof(EventCommOfferWork));
    work = func_020124E8(event);
    func_020084F8(myStatus, work->myName, 8);
    work->itemId = param->y;
    work->offerArg = param->x;
    work->senderNetId = offer->name.netId;
    func_0217F2B4(&work->msgBox, gameSystem);
    return event;
}

/*
 * Offer answer event: accepts the offer of another player, sends this
 * player's name to the sender, then starts the mission result event.
 */
int func_02182214(struct GameEvent *event, int *seq, void *wk)
{
    EventCommOfferWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameComm *gameComm;
    struct GameData *gameData;
    IntrudeCommSys *sys;
    int msgId;

    gameSystem = func_020124E4(event);
    gameComm = func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    func_0201210C(gameSystem);
    sys = func_02158344(gameComm);
    if (sys == 0) {
        if (func_0217F40C(&work->msgBox) == 0) {
            return 0;
        }
        if (*seq < 4) {
            func_0217F3C4(&work->msgBox, 6);
            *seq = 4;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        if (func_0217405C(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 1:
        if ((work->joinStatus = func_02175CF4(sys, &sys->session)) != 0) {
            (*seq)++;
        }
        break;
    case 2:
        func_0201F02C(work->msgBox.wordSet, 0, func_02012944(gameData));
        func_0201EF40(work->msgBox.wordSet, 1, work->itemId);
        if (work->joinStatus == 1) {
            msgId = sOfferAnswerMsgIds[func_0217F5F0(sys, (int)func_02012B58(gameData))];
            work->accepted = 1;
        } else {
            msgId = 5;
        }
        func_0217F3C4(&work->msgBox, msgId);
        (*seq)++;
        break;
    case 3:
        if (work->accepted == 1) {
            if (func_021745F8((u8)work->senderNetId, work->myName) == 1) {
                (*seq)++;
            }
        } else {
            (*seq)++;
        }
        break;
    case 4:
        if (func_0217F40C(&work->msgBox) == 1) {
            *seq = 5;
        }
        break;
    case 5:
        if (func_0217F420() == 1) {
            *seq = 6;
        }
        break;
    case 6:
        func_0217F318(&work->msgBox);
        func_0201235C(event, func_021804F8(gameSystem, work->accepted));
        return 0;
    }
    return 0;
}

void func_0218236C(struct GameEvent *event, EventCommCommonWork *src)
{
    EventCommCommonWork *work;
    u16 *itemId;
    func_0201232C(event, func_021823A8, sizeof(EventCommItemSaleWork));
    work = func_020124E8(event);
    func_02082D44(src, work, sizeof(EventCommCommonWork));
    itemId = &work->member.head.param.x;
    if (func_021756D0(*itemId) == 0) {
        *itemId = 17;
    }
}

/*
 * Item sale event: offers the item to the partner for the price and waits
 * for the answer, then starts the mission result event or the disconnect
 * event.
 */
int func_021823A8(struct GameEvent *event, int *seq, void *wk)
{
    EventCommItemSaleWork *work = wk;
    struct GameSystem *gameSystem;
    IntrudeCommSys *sys;
    IntrudeParamPair *sale;

    gameSystem = func_020124E4(event);
    sys = func_02158344(func_02012138(gameSystem));
    if (sys == 0 && *seq <= 4) {
        if (func_0217F40C(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 9) {
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 9;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        func_0201F02C(work->common.msgBox.wordSet, 0, work->common.myStatus);
        sale = &work->common.member.head.param;
        func_0201EF40(work->common.msgBox.wordSet, 1, sale->x);
        func_0201EFA4(work->common.msgBox.wordSet, 2, sale->y, 5, 0, 1);
        func_0201F02C(work->common.msgBox.wordSet, 3, func_02012944(func_020120F4(gameSystem)));
        func_0217F3C4(&work->common.msgBox, sItemSaleMsgIds[0][work->common.msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            switch (func_02175514(sys)) {
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
                if ((func_020362DC() & 2) && func_02173B9C(sys->requestTarget, sys->sentRequestSeq) == 1) {
                    func_021753B8(sys);
                    work->canceled = 1;
                    *seq = 8;
                }
                break;
            }
        }
        break;
    case 2:
        func_0217F3C4(&work->common.msgBox, sItemSaleMsgIds[4][work->common.msgIndex]);
        (*seq)++;
        break;
    case 3:
        if (func_0217405C(sys, &sys->session) == 1) {
            (*seq)++;
        }
        break;
    case 4:
        if (func_02175CF4(sys, &sys->session) != 0) {
            work->sold = 1;
            *seq = 9;
        }
        break;
    case 5:
        func_0217F3C4(&work->common.msgBox, sItemSaleMsgIds[1][work->common.msgIndex]);
        *seq = 9;
        break;
    case 6:
        func_0217F3C4(&work->common.msgBox, sItemSaleMsgIds[2][work->common.msgIndex]);
        *seq = 9;
        break;
    case 7:
        func_0217F3C4(&work->common.msgBox, sItemSaleMsgIds[3][work->common.msgIndex]);
        *seq = 9;
        break;
    case 8:
        *seq = 11;
        break;
    case 9:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            *seq = 10;
        }
        break;
    case 10:
        if (func_0217F420() == 1) {
            *seq = 11;
        }
        break;
    case 11:
        func_0217FE38(sys, &work->common);
        if (work->sold == 1) {
            func_0201235C(event, func_021804F8(gameSystem, work->sold));
            return 0;
        }
        if (work->canceled == 0) {
            func_0201235C(event, func_0217CA84(gameSystem, 2));
            return 0;
        }
        func_0201235C(event, func_0217CA84(gameSystem, 0));
        return 0;
    }
    return 0;
}

void func_021825F8(struct GameEvent *event, EventCommCommonWork *src)
{
    func_0201232C(event, func_0218261C, sizeof(EventCommItemSaleWork));
    func_02082D44(src, func_020124E8(event), sizeof(EventCommCommonWork));
}

/*
 * Item purchase event: the partner offers an item for a price; asks the
 * player, checks money and bag space, sends the answer and on yes pays and
 * takes the item.
 */
int func_0218261C(struct GameEvent *event, int *seq, void *wk)
{
    EventCommItemSaleWork *work = wk;
    struct GameSystem *gameSystem;
    struct GameData *gameData;
    struct GameComm *gameComm;
    IntrudeCommSys *sys;
    IntrudeParamPair *sale;
    int refused;
    int answer;

    gameSystem = func_020124E4(event);
    gameData = func_020120F4(gameSystem);
    gameComm = func_02012138(gameSystem);
    sale = &work->common.member.head.param;
    sys = func_02158344(gameComm);
    if (sys == 0) {
        if (func_0217F40C(&work->common.msgBox) == 0) {
            return 0;
        }
        if (*seq < 8 && *seq != 2 && *seq != 3) {
            func_0217F3C4(&work->common.msgBox, 4);
            *seq = 8;
            work->disconnected = 1;
            return 0;
        }
    }
    switch (*seq) {
    case 0:
        func_0201F02C(work->common.msgBox.wordSet, 0, work->common.myStatus);
        func_0201EF40(work->common.msgBox.wordSet, 1, sale->x);
        func_0201EFA4(work->common.msgBox.wordSet, 2, sale->y, 5, 0, 1);
        func_0201F02C(work->common.msgBox.wordSet, 3, func_02012944(func_020120F4(gameSystem)));
        func_0217F3C4(&work->common.msgBox, sItemPurchaseMsgIds[0][work->common.msgIndex]);
        (*seq)++;
        break;
    case 1:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            func_0217F3C4(&work->common.msgBox, sItemPurchaseMsgIds[1][work->common.msgIndex]);
            (*seq)++;
        }
        break;
    case 2:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            func_0217F4D8(&work->common.msgBox, gameSystem);
            (*seq)++;
        }
        break;
    case 3:
        answer = func_0217F508(&work->common.msgBox);
        refused = 0;
        switch (answer) {
        case 0:
            func_0217F4C4(&work->common.msgBox);
            if (sale->y > func_0200C274(func_02012F08(gameData))) {
                refused = 1;
                *seq = 5;
            } else if (func_02007E3C(func_0201292C(gameData), sale->x, 1, 0x15) == 0) {
                refused = 1;
                *seq = 6;
            } else {
                *seq = 4;
            }
            break;
        case 1:
            func_0217F4C4(&work->common.msgBox);
            refused = 1;
            *seq = 7;
            break;
        }
        if (refused == 1) {
            func_021763D8(func_020127B8(gameData), 3);
        }
        break;
    case 4:
        if (func_02173AE0(sys, sys->requestTarget, 7, sys->sentRequestSeq) == 1) {
            func_0200C29C(func_02012F08(gameData), sale->y);
            func_02007E50(func_0201292C(gameData), sale->x, 1, 0x15);
            func_0217F3C4(&work->common.msgBox, sItemPurchaseMsgIds[5][work->common.msgIndex]);
            *seq = 8;
        }
        break;
    case 5:
        if (func_02173AE0(sys, sys->requestTarget, 9, sys->sentRequestSeq) == 1) {
            func_0217F3C4(&work->common.msgBox, sItemPurchaseMsgIds[3][work->common.msgIndex]);
            *seq = 8;
        }
        break;
    case 6:
        if (func_02173AE0(sys, sys->requestTarget, 10, sys->sentRequestSeq) == 1) {
            func_0217F3C4(&work->common.msgBox, sItemPurchaseMsgIds[4][work->common.msgIndex]);
            *seq = 8;
        }
        break;
    case 7:
        if (func_02173AE0(sys, sys->requestTarget, 8, sys->sentRequestSeq) == 1) {
            func_0217F3C4(&work->common.msgBox, sItemPurchaseMsgIds[2][work->common.msgIndex]);
            *seq = 8;
        }
        break;
    case 8:
        if (func_0217F40C(&work->common.msgBox) == 1) {
            *seq = 9;
        }
        break;
    case 9:
        if (func_0217F420() == 1) {
            *seq = 10;
        }
        break;
    case 10:
        func_0217FE38(sys, &work->common);
        return 1;
    }
    return 0;
}

void func_021828A8(struct GameEvent *event, EventCommCommonWork *src)
{
    func_0218236C(event, src);
}

void func_021828B0(struct GameEvent *event, EventCommCommonWork *src)
{
    func_021825F8(event, src);
}
