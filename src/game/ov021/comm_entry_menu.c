/*
 * file:     comm_entry_menu.c
 * unit:     yes
 * function: COMM_ENTRY_MENU_Create, COMM_ENTRY_MENU_Delete, COMM_ENTRY_MENU_SetCallbacks, COMM_ENTRY_MENU_AddMember, COMM_ENTRY_MENU_Main, COMM_ENTRY_MENU_MainRecruit, COMM_ENTRY_MENU_MainMode1, COMM_ENTRY_MENU_MainMode2, COMM_ENTRY_MENU_MainMode3, COMM_ENTRY_MENU_ProcessMemberQueues, COMM_ENTRY_MENU_CollectMemberNames, COMM_ENTRY_MENU_CheckDisconnects, COMM_ENTRY_MENU_UpdateMemberList, COMM_ENTRY_MENU_AdvanceMemberStates, COMM_ENTRY_MENU_ClearMember, COMM_ENTRY_MENU_LatchRequest, COMM_ENTRY_MENU_ProcessRequest, COMM_ENTRY_MENU_ProcessCancel, COMM_ENTRY_MENU_ProcessStartConfirm, COMM_ENTRY_MENU_MarkMemberReady, COMM_ENTRY_MENU_SetAcceptFlag, COMM_ENTRY_MENU_SetCancelFlag, COMM_ENTRY_MENU_SetBusyFlags, COMM_ENTRY_MENU_CountAcceptedMembers, COMM_ENTRY_MENU_GetAcceptedMask, COMM_ENTRY_MENU_IsIdle, COMM_ENTRY_MENU_OpenWindows, COMM_ENTRY_MENU_CloseWindows, COMM_ENTRY_MENU_PrintRemaining, COMM_ENTRY_MENU_UpdateMemberName, COMM_ENTRY_MENU_ClearMemberName, COMM_ENTRY_MENU_PrintMemberName, COMM_ENTRY_MENU_EraseMemberName, COMM_ENTRY_MENU_RefreshNames, COMM_ENTRY_MENU_PrintMessage, COMM_ENTRY_MENU_SnapshotStates, COMM_ENTRY_MENU_StatesUnchanged, COMM_ENTRY_MENU_ClearPendingBits, COMM_ENTRY_MENU_QueueSend, COMM_ENTRY_MENU_AckSend, COMM_ENTRY_MENU_GetNameBuffer, COMM_ENTRY_MENU_SetNameBuffer, COMM_ENTRY_MENU_StartYesNo, COMM_ENTRY_MENU_EndYesNo, COMM_ENTRY_MENU_MainYesNo, COMM_ENTRY_PollParentList, COMM_ENTRY_TickParentTimeouts, COMM_ENTRY_ScanParents, COMM_ENTRY_AddParent, COMM_ENTRY_ClearParentSlot, COMM_ENTRY_BuildParentItems, COMM_ENTRY_RunLeaveConfirm, COMM_ENTRY_ResetLeaveConfirm, COMM_ENTRY_StoreJoinReply, COMM_ENTRY_GetRosterSize, COMM_ENTRY_IsOtherMemberConnected, COMM_ENTRY_StartNetCommands, COMM_ENTRY_EndNetCommands, COMM_ENTRY_GetRosterBuffer, COMM_ENTRY_RecvJoinRequest, COMM_ENTRY_SendJoinRequest, COMM_ENTRY_RecvJoinAccept, COMM_ENTRY_SendJoinAccept, COMM_ENTRY_RecvJoinRedirect, COMM_ENTRY_SendJoinRedirect, COMM_ENTRY_RecvSessionLock, COMM_ENTRY_SendSessionLock, COMM_ENTRY_RecvReady, COMM_ENTRY_SendReady, COMM_ENTRY_RecvAccept, COMM_ENTRY_SendAccept, COMM_ENTRY_RecvCancel, COMM_ENTRY_SendCancel, COMM_ENTRY_RecvRoster, COMM_ENTRY_SendRoster
 * address:  0x021CD48C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from fld_trade_p01.c and fld_trade_p02.c (lane CL125b): __FILE__ anchor 021CD590 (d_021DE5E8 "comm_entry_menu.c").
 *
 * symbols:
 *   STRBUF_Create  0x020457B0  arm
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_MsgWinPrintMsg  0x02190740  thumb  ov021
 *   STRBUF_Delete  0x02045808  arm
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomSysWin  0x02190F64  thumb  ov021
 *   MSGDATA_AllocString  0x02045EC0  arm
 *   MYSTATUS_Copy  0x02008494  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 *   GFL_NET_SetLoginOption  0x0203D7BC  arm
 *   COMM_ENTRY_StartNetCommands  0x021CF164  thumb  ov021
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_GetUserArg  0x0203D650  arm
 *   d_021DE5E8     0x021DE5E8  data   ov021  a1
 *   FIELD_MSGBG_DeleteMenuFunc  0x021909BC  thumb  ov021
 *   FIELD_MSGBG_DeleteSysWin  0x02190E40  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgData  0x021904C8  thumb  ov021
 *   WORDSET_Delete  0x0201ED04  thumb
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   COMM_ENTRY_EndNetCommands  0x021CF17C  thumb  ov021
 *   gCommEntryMsgTable  0x021DB498  data
 *   COMM_ENTRY_SendJoinRequest  0x021CF1AC  thumb  ov021
 *   COMM_ENTRY_SendSessionLock  0x021CF2F0  thumb  ov021
 *   COMM_ENTRY_SendCancel  0x021CF3B0  thumb  ov021
 *   COMM_ENTRY_SendAccept  0x021CF378  thumb  ov021
 *   FIELD_MSGBG_SysWinMain  0x02190EF0  thumb  ov021
 *   COMM_ENTRY_IsOtherMemberConnected  0x021CF12C  thumb  ov021
 *   GFL_NET_ERR_GetErrorLevel  0x0200FB24  thumb
 *   GFL_NET_StartByNetType  0x0203D01C  arm
 *   GFL_NET_SYSTEM_GetConnectNum  0x020392B8  arm
 *   GFL_NET_HANDLE_CheckNegotiation  0x02039ACC  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_SetAcceptConnection  0x0203D1E8  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   GFL_NET_IsConnectMember  0x0203D1C0  arm
 *   MATH_CountPopulation  0x02080D24  arm
 *   GFL_NET_HANDLE_SetTimingSyncRange  0x02039C68  arm
 *   GFL_NET_HANDLE_IsTimingSyncRange  0x02039CB4  arm
 *   GFL_NET_BeaconScanStart  0x0203D010  arm
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb
 *   COMM_ENTRY_RunLeaveConfirm  0x021CF068  thumb  ov021
 *   COMM_ENTRY_ResetLeaveConfirm  0x021CF0F4  thumb  ov021
 *   COMM_ENTRY_SendReady  0x021CF32C  thumb  ov021
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   GFL_NET_StartSession  0x0203CBAC  arm
 *   COMM_ENTRY_SendJoinAccept  0x021CF220  thumb  ov021
 *   COMM_ENTRY_SendJoinRedirect  0x021CF288  thumb  ov021
 *   COMM_ENTRY_SendRoster  0x021CF3FC  thumb  ov021
 *   FIELD_MSGBG_CreateYesNoMenu  0x02190BE4  thumb  ov021
 *   FIELD_MSGBG_YesNoMenuMain  0x02190C78  thumb  ov021
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
 *   FIELD_MSGBG_ClearPrintQue  0x02190490  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   FIELD_MSGBG_FillMsgWin  0x02190794  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   gCommEntryEmptyMac     0x021DB470  data  a4
 *   MYSTATUS_GetIdLow16  0x02008534  thumb
 *   FIELD_MSGBG_ClearSysWin  0x02190F7C  thumb  ov021
 *   FIELD_MSGBG_SysWinPrintStr  0x02190EB8  thumb  ov021
 *   FIELD_MSGBG_CreateMenuItems  0x02190A20  thumb  ov021
 *   COMM_ENTRY_BuildParentItems  0x021CEF1C  thumb  ov021
 *   FIELD_MSGBG_CreateMenuFunc  0x0219097C  thumb  ov021
 *   gCommEntryParentListHeader     0x021DB478  data  a4
 *   COMM_ENTRY_TickParentTimeouts  0x021CEE00  thumb  ov021
 *   COMM_ENTRY_ScanParents  0x021CEE48  thumb  ov021
 *   COMM_ENTRY_PollParentList  0x021CEDA0  thumb  ov021
 *   FIELD_MSGBG_RewriteMenuFunc  0x02190A14  thumb  ov021
 *   FIELD_MSGBG_IsPrintQueFinished  0x0219049C  thumb  ov021
 *   FIELD_MSGBG_DrawMenuFuncFrame  0x02190B1C  thumb  ov021
 *   FIELD_MSGBG_MenuFuncMain  0x021909E4  thumb  ov021
 *   GFL_NET_ConnectMacAddressChild  0x0203D000  arm
 *   COMM_ENTRY_MENU_PrintMessage  0x021CE9E4  thumb  ov021
 *   GFL_NET_GetScanResult  0x0203CF10  arm
 *   STRBUF_GetEosChar  0x02045A98  arm
 *   FIELD_MSGBG_DeleteMenuItems  0x02190A6C  thumb  ov021
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   STRBUF_SetString  0x02045924  arm
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 *   FIELD_MSGBG_AddMenuItemStr  0x02190A64  thumb  ov021
 *   GFL_NET_COMMAND_AddCommandTable  0x0203A574  arm
 *   data_021DB4BC  0x021DB4BC  data
 *   GFL_NET_COMMAND_DeleteCommandTable  0x0203A5E4  arm
 *   COMM_ENTRY_MENU_GetNameBuffer  0x021CEAF8  thumb  ov021
 *   COMM_ENTRY_MENU_AddMember  0x021CD624  thumb  ov021
 *   MI_CpuFill8  0x02082BCC  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 *   GFL_NET_SendData  0x0203D3F8  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   MYSTATUS_GetSize  0x02008468  thumb
 *   COMM_ENTRY_MENU_SetBusyFlags  0x021CE724  thumb  ov021
 *   GFL_NET_SendToHandle  0x0203D3A8  arm
 *   COMM_ENTRY_MENU_MarkMemberReady  0x021CE6F0  thumb  ov021
 *   COMM_ENTRY_MENU_SetAcceptFlag  0x021CE70C  thumb  ov021
 *   COMM_ENTRY_MENU_SetCancelFlag  0x021CE718  thumb  ov021
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   COMM_ENTRY_MENU_AckSend  0x021CEADC  thumb  ov021
 *   COMM_ENTRY_MENU_SetNameBuffer  0x021CEB04  thumb  ov021
 *   GFL_NET_SendDataMask  0x0203D4D0  arm
 */

#include "field_msgbg_types.h"
#include "../arm9/net_types.h"

struct FieldMap;
struct MyStatus;
struct WordSet;
struct Strbuf;
struct MsgData;

typedef signed char s8;

/* Callback of the owner: a member joined or left. */
typedef void (*CommEntryMemberFunc)(void *work, const void *myStatus, const u8 *mac);

/* Value of menuMode: which entry flow the menu runs. */
enum {
    COMM_ENTRY_MODE_RECRUIT = 0, /* gather members for a session this player leads */
    COMM_ENTRY_MODE_CHOOSE = 1,  /* pick a leader from the list, or stay and recruit */
    COMM_ENTRY_MODE_HOST = 2,    /* open a session and wait for members */
    COMM_ENTRY_MODE_JOIN = 3     /* join a session found by scan */
};

/* Value of result, returned by COMM_ENTRY_MENU_Main when it is not 0. */
enum {
    COMM_ENTRY_RESULT_NONE = 0,
    COMM_ENTRY_RESULT_START = 1,      /* members gathered, go on */
    COMM_ENTRY_RESULT_CANCEL = 2,     /* the player backed out */
    COMM_ENTRY_RESULT_SWITCHED = 3,   /* the player joined another session instead */
    COMM_ENTRY_RESULT_NET_ERROR = 4   /* the network layer reported an error */
};

/* Member.state */
enum {
    COMM_ENTRY_MEMBER_EMPTY = 0,
    COMM_ENTRY_MEMBER_JOINED = 1,    /* entered, not yet judged */
    COMM_ENTRY_MEMBER_QUEUED = 2,    /* waits for the player to answer its request */
    COMM_ENTRY_MEMBER_ASKING = 3,    /* its request is being asked */
    COMM_ENTRY_MEMBER_ACCEPTED = 4,
    COMM_ENTRY_MEMBER_REFUSED = 5
};

/* States of COMM_ENTRY_MODE_RECRUIT (20 states). */
enum {
    RECRUIT_OPEN = 0,
    RECRUIT_CHECK_ROLE = 1,
    RECRUIT_WAIT_CONNECT = 2,
    RECRUIT_WAIT_NEGOTIATION = 3,
    RECRUIT_REGISTER_SELF = 4,
    RECRUIT_COLLECT = 5,
    RECRUIT_CONFIRM_START = 6,
    RECRUIT_CONFIRM_QUIT = 7,
    RECRUIT_WAIT_START_SYNC = 8,
    RECRUIT_SEND_READY_REQUEST = 9,
    RECRUIT_WAIT_READY = 10,
    RECRUIT_SEND_ABORT = 11,
    RECRUIT_SEND_START = 12,
    RECRUIT_SEND_QUIT = 13,
    RECRUIT_SHOW_ABORT_MESSAGE = 14,
    RECRUIT_WAIT_ABORT_MESSAGE = 15,
    RECRUIT_WAIT_QUIT_SENT = 16,
    RECRUIT_SHOW_ALONE_MESSAGE = 17,
    RECRUIT_WAIT_ALONE_MESSAGE = 18,
    RECRUIT_DONE = 19
};

/* States of COMM_ENTRY_MODE_CHOOSE. */
enum {
    CHOOSE_SHOW_OPEN_MESSAGE = 0,
    CHOOSE_WAIT_OPEN_MESSAGE = 1,
    CHOOSE_OPEN_LIST = 2,
    CHOOSE_RUN_LIST = 3,
    CHOOSE_WAIT_JOINED_MESSAGE = 4,
    CHOOSE_COLLECT = 5,
    CHOOSE_ACCEPTED = 6,
    CHOOSE_WAIT_SYNC = 7,
    CHOOSE_SHOW_CANCEL_MESSAGE = 8,
    CHOOSE_WAIT_CANCEL_MESSAGE = 9,
    CHOOSE_SWITCH_BEGIN = 10,
    CHOOSE_SWITCH_WAIT_EXIT = 11,
    CHOOSE_SWITCH_START_SESSION = 12,
    CHOOSE_SWITCH_WAIT_SESSION = 13,
    CHOOSE_CANCELLED = 14,
    CHOOSE_DONE = 15
};

/* States of COMM_ENTRY_MODE_HOST. */
enum {
    HOST_SHOW_CONNECT_MESSAGE = 0,
    HOST_REGISTER_SELF = 1,
    HOST_OPEN_WINDOWS = 2,
    HOST_COLLECT = 3,
    HOST_ACCEPTED = 4,
    HOST_WAIT_SYNC = 5,
    HOST_SHOW_CANCEL_MESSAGE = 6,
    HOST_WAIT_CANCEL_MESSAGE = 7,
    HOST_SWITCH_SHOW_MESSAGE = 8,
    HOST_SWITCH_WAIT_MESSAGE = 9,
    HOST_CANCELLED = 10,
    HOST_DONE = 11
};

/* States of COMM_ENTRY_MODE_JOIN. */
enum {
    JOIN_SHOW_CONNECT_MESSAGE = 0,
    JOIN_REGISTER_SELF = 1,
    JOIN_WAIT_REPLY = 2,
    JOIN_OPEN_WINDOWS = 3,
    JOIN_COLLECT = 4,
    JOIN_ACCEPTED = 5,
    JOIN_WAIT_SYNC = 6,
    JOIN_SHOW_CANCEL_MESSAGE = 7,
    JOIN_WAIT_CANCEL_MESSAGE = 8,
    JOIN_SWITCH_SHOW_MESSAGE = 9,
    JOIN_SWITCH_WAIT_MESSAGE = 10,
    JOIN_CANCELLED = 11,
    JOIN_DONE = 12
};

/* States of the three-step confirm dialogs (Confirm.state). */
enum {
    CONFIRM_ASK = 0,
    CONFIRM_OPEN_MENU = 1,
    CONFIRM_WAIT_ANSWER = 2,
    CONFIRM_FINISH_REQUEST = 3,   /* ProcessJoinRequest only */
    CONFIRM_OPEN_MENU_AGAIN = 3,  /* ProcessQuitConfirm: second question */
    CONFIRM_WAIT_ANSWER_AGAIN = 4,
    CONFIRM_NOTIFY_ALONE = 5,
    CONFIRM_ABORTED = 100,
    CONFIRM_FINISHED = 0xff
};

/* States of the parent list (ParentList.state). */
enum {
    LIST_BROWSE = 0,
    LIST_WAIT_NEGOTIATION = 1,
    LIST_WAIT_REPLY = 2,
    LIST_FINISHED = 3,
    LIST_ASK_LEAVE = 4,
    LIST_WAIT_LEAVE_ANSWER = 5,
    LIST_SHOW_TIMEOUT = 6
};

/* Result of the parent list (ParentList.result). */
enum {
    LIST_RESULT_JOINED = 1,
    LIST_RESULT_REDIRECTED = 2,
    LIST_RESULT_LEFT = 3
};

/* Message ids of the entry menu message file; most are guesses from use. */
enum {
    COMM_ENTRY_MSG_ASK_JOIN_REQUEST = 10,
    COMM_ENTRY_MSG_WAIT_FOR_MEMBERS = 8,
    COMM_ENTRY_MSG_MEMBERS_CAN_START = 9,
    COMM_ENTRY_MSG_CONFIRM_START = 0xb,
    COMM_ENTRY_MSG_CONFIRM_QUIT_MEMBERS = 0xf,
    COMM_ENTRY_MSG_NO_MEMBERS = 0x14,
    COMM_ENTRY_MSG_CONNECTING = 0x15,
    COMM_ENTRY_MSG_STARTING = 0x1e,
    COMM_ENTRY_MSG_SWITCHING = 0x1f,
    COMM_ENTRY_MSG_LEAVE_REFUSED = 0x20,
    COMM_ENTRY_MSG_JOINED = 0x21,
    COMM_ENTRY_MSG_WAIT_IN_LOBBY = 0x22,
    COMM_ENTRY_MSG_ASK_LEAVE = 0x23,
    COMM_ENTRY_MSG_LIST_TIMEOUT = 0x24
};

/* Columns of the message table gCommEntryMsgTable, one row per isChild value. */
enum {
    COMM_ENTRY_MSGCOL_TITLE = 0,       /* header window text */
    COMM_ENTRY_MSGCOL_QUIT_ASK = 1,    /* first question when the player quits */
    COMM_ENTRY_MSGCOL_QUIT_ALONE = 2,  /* text when nobody else is in the group */
    COMM_ENTRY_MSGCOL_RESERVED = 3,
    COMM_ENTRY_MSGCOL_ABORT = 4,       /* text when the entry is cancelled */
    COMM_ENTRY_MSGCOL_OPEN = 5         /* first text of the choose flow */
};

/*
 * Message id of column `col` for the isChild row. Kept as byte arithmetic on
 * the table: gCommEntryMsgTable[isChild][col] folds the column into the pool address
 * and changes the bytes.
 */
#define COMM_ENTRY_MSG(isChild, col) (*(const u16 *)((const u8 *)gCommEntryMsgTable + (isChild) * 12 + (col) * 2))

/* Network commands of the entry menu (command table data_021DB4BC). */
enum {
    COMM_ENTRY_CMD_JOIN_REQUEST = 0x2700,
    COMM_ENTRY_CMD_JOIN_ACCEPT = 0x2701,
    COMM_ENTRY_CMD_JOIN_REDIRECT = 0x2702,
    COMM_ENTRY_CMD_SESSION_LOCK = 0x2703,
    COMM_ENTRY_CMD_READY = 0x2704,
    COMM_ENTRY_CMD_ACCEPT = 0x2705,
    COMM_ENTRY_CMD_CANCEL = 0x2706,
    COMM_ENTRY_CMD_ROSTER = 0x2707,
    COMM_ENTRY_CMD_COUNT = 8
};

enum {
    COMM_ENTRY_NET_HEAP = 0x2700,
    COMM_ENTRY_PARENT_SLOTS = 16,
    COMM_ENTRY_PARENT_TIMEOUT_FRAMES = 150,
    COMM_ENTRY_MAX_MEMBERS = 4,
    COMM_ENTRY_NET_ALL = 0xff
};

typedef struct MacAddress {
    u8 b[6];
} MacAddress;

/* Own record advertised by the beacon: MyStatus, MAC and the join id. */
typedef struct CommEntryBeaconData {
    u8 myStatus[0x20];
    u8 mac[6];
    u16 advertiseId;     /* 0x3A0B while the session takes members, 0 once it started */
} CommEntryBeaconData;

#define COMM_ENTRY_ADVERTISE_ID 0x3a0b

/* Payload of COMM_ENTRY_CMD_JOIN_REQUEST (0x28 bytes). */
typedef struct CommEntryJoinRequest {
    u8 myStatus[0x20];
    u8 mac[6];
    u8 isChild;
    u8 pad27;
} CommEntryJoinRequest;

/* One player of the group (0x2C bytes). */
typedef struct CommEntryMember {
    u32 myStatus[8];     /* MyStatus copy */
    u8 state;            /* COMM_ENTRY_MEMBER_* */
    u8 autoAccept;       /* 1: accepted without asking */
    u8 pad22;
    u8 mac[6];
    u8 pad29[3];
} CommEntryMember;

/* Dialog state of the join request and quit confirm dialogs. */
typedef struct CommEntryConfirm {
    FieldMenuFunc *menu;
    u32 result;
    u8 state;
    u8 pad9[3];
} CommEntryConfirm;

/* One leader found by the scan (0x2C bytes). */
typedef struct CommEntryParentSlot {
    u8 myStatus[0x20];
    u8 mac[6];
    u8 used;
    u8 pad27;
    s16 timeout;
    u8 pad2A[2];
} CommEntryParentSlot;

/* The list of leaders the player can join (0x2D8 bytes at 0x13C). */
typedef struct CommEntryParentList {
    struct BmpMenuWork *items;
    FieldMenuFunc *menu;
    CommEntryParentSlot slots[16];
    CommEntryParentSlot *selected;
    u32 result;          /* LIST_RESULT_* */
    u8 state;            /* LIST_* */
    u8 listDirty;        /* 1: items must be rebuilt */
    u8 itemsBuilt;
    u8 returnState;      /* state to go back to after the leave dialog */
    u16 waitFrames;
    u8 pad12[2];
} CommEntryParentList;

/* The names of the members sent to the other players (0x84 bytes). */
typedef struct CommEntryRoster {
    u8 myStatus[4][0x20];
    u8 mask;             /* one bit per member */
    u8 pad[3];
} CommEntryRoster;

/* Work of the entry menu (0x580 bytes). */
typedef struct CommEntryMenu {
    struct FieldMap *fieldMap;           /* 0x000 */
    struct WordSet *wordSet;             /* 0x004 */
    struct MsgData *msgData;             /* 0x008 */
    FieldMsgWin *memberWin;              /* 0x00C: member names */
    FieldMsgWin *titleWin;               /* 0x010 */
    FieldSysWin *sysWin;                 /* 0x014: message window */
    struct Strbuf *msgStr;               /* 0x018 */
    struct Strbuf *nameFormat;           /* 0x01C */
    struct Strbuf *nameStr;              /* 0x020 */
    struct Strbuf *remainingFormat;      /* 0x024 */
    struct Strbuf *remainingStr;         /* 0x028 */
    u32 result;                          /* 0x02C: COMM_ENTRY_RESULT_* */
    u32 myStatus[8];                     /* 0x030: own MyStatus */
    CommEntryMember members[4];          /* 0x050 */
    u32 requestPending;                  /* 0x100 */
    CommEntryMember request;             /* 0x104 */
    CommEntryConfirm confirm;            /* 0x130 */
    CommEntryParentList parentList;      /* 0x13C */
    GFLNetInitializeStruct netInitBackup; /* 0x414 */
    u32 savedUserArg;                    /* 0x484 */
    void *callbackWork;                  /* 0x488 */
    CommEntryMemberFunc onAdd;           /* 0x48C */
    CommEntryMemberFunc onRemove;        /* 0x490 */
    CommEntryRoster roster;              /* 0x494 */
    u8 namesDirty;
    u8 acceptFlag;
    u8 cancelFlag;
    u8 netMode;
    u8 minMembers;
    u8 maxMembers;
    u8 state;
    u8 menuMode;
    u8 isChild;
    u8 pendingAddBits;
    u8 pendingRemoveBits;
    u8 sendPending;
    u8 sendQueued;
    u8 sendBusy;
    u8 readyMask;
    u8 pad527;
    u16 heapId;
    u8 pad52A[2];
    u32 joinReply;
    u8 parentMyStatus[0x20];
    u8 stateSnapshot[4];
    u8 ownMac[6];
    MacAddress memberMacs[4];
    s8 memberCount;
    u8 readyCount;
    u16 nextMessage;
    u8 sessionLocked;
    u8 lockNotifyPending;
    u8 readyBits;
    u8 refreshPending;
    u16 lastMessageId;
    u8 pad57C[4];
} CommEntryMenu;

extern struct Strbuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *ws, u32 slot, u32 number, u32 digits, u32 dispType, u32 charCode);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, struct Strbuf *dst, struct Strbuf *format);
extern int FIELD_MSGBG_MsgWinPrintMsg(FieldMsgWin *msgWin, int x, int y, u32 msgId);
extern void STRBUF_Delete(struct Strbuf *str);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 GFL_HEAP_Free(void *p);
extern FieldMsgBg *FIELDMAP_GetMsgBg(struct FieldMap *fieldMap);
extern struct WordSet *WORDSET_CreateDefault(u32 heapId);
extern struct MsgData *FIELD_MSGBG_CreateMsgData(FieldMsgBg *msgBg, u32 fileId);
extern FieldSysWin *FIELD_MSGBG_CreateBottomSysWin(FieldMsgBg *msgBg, struct MsgData *msgData);
struct MsgBank;
extern struct Strbuf *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void MYSTATUS_Copy(struct MyStatus *src, struct MyStatus *dest);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern void GFL_NET_SetLoginOption(u8 loginOption);
extern GFLNetInitializeStruct *GFL_NET_GetInitParam(void);
extern u32 GFL_NET_GetUserArg(void);
extern int FIELD_MSGBG_DeleteMenuFunc(FieldMenuFunc *menu);
extern int FIELD_MSGBG_DeleteSysWin(FieldSysWin *sysWin);
extern u32 FIELD_MSGBG_DeleteMsgData(struct MsgData *msgData);
extern u32 WORDSET_Delete(struct WordSet *ws);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_StartByNetType(void);
extern int GFL_NET_SYSTEM_GetConnectNum(void);
extern int GFL_NET_HANDLE_CheckNegotiation(void);
extern u32 KEY_GetTrg(void);
extern GFLNetHandle *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(GFLNetHandle *handle);
extern int GFL_NET_GetNegotiationNum(void);
extern void GFL_NET_SetAcceptConnection(u32 unusedArg, void *eventArg);
extern u32 GFL_NET_GetHandleNetID(GFLNetHandle *handle);
extern u32 GFL_NET_IsConnectMember(u32 netId);
extern u8 MATH_CountPopulation(u32 x);
extern void GFL_NET_HANDLE_SetTimingSyncRange(GFLNetHandle *handle, unsigned int timingNo, unsigned int range);
extern unsigned int GFL_NET_HANDLE_IsTimingSyncRange(GFLNetHandle *handle, unsigned int timingNo, unsigned int range);
extern u32 FIELD_MSGBG_SysWinMain(FieldSysWin *sysWin);
extern u32 GFL_NET_ERR_GetErrorLevel(void);
extern void GFL_NET_BeaconScanStart(void);
extern void WORDSET_SetSlotMyStatus(struct WordSet *ws, u32 slot, const void *myStatus);
extern int GFL_NET_Exit(int exitCallback);
extern int GFL_NET_IsSessionNull(void);
extern void GFL_NET_StartSession(GFLNetInitializeStruct *init, u32 transportArg, u32 userArg);
extern FieldMenuFunc *FIELD_MSGBG_CreateYesNoMenu(FieldMsgBg *msgBg, u32 cursorPos);
extern int FIELD_MSGBG_YesNoMenuMain(FieldMenuFunc *menu);
extern FieldMsgWin *FIELD_MSGBG_CreateMsgWin(FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height);
extern int FIELD_MSGBG_DeleteMsgWin(FieldMsgWin *msgWin);
extern void FIELD_MSGBG_ClearPrintQue(FieldMsgBg *msgBg);
extern int FIELD_MSGBG_IsMsgWinTransDone(FieldMsgWin *msgWin);
extern void FIELD_MSGBG_FillMsgWin(FieldMsgWin *msgWin, int x, int y, int width, int height);
extern void FIELD_MSGBG_MsgWinPrintStr(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str);
extern int GF_STANDARD_CompareBytes(u8 *a, u8 *b, u32 n);
extern u16 MYSTATUS_GetIdLow16(struct MyStatus *mystatus);
extern void FIELD_MSGBG_ClearSysWin(FieldSysWin *sysWin);
extern void FIELD_MSGBG_SysWinPrintStr(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str);
extern struct BmpMenuWork *FIELD_MSGBG_CreateMenuItems(int count, u16 heapId);
extern u32 FIELD_MSGBG_CreateMenuFunc(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items);
extern void FIELD_MSGBG_RewriteMenuFunc(FieldMenuFunc *menu);
extern int FIELD_MSGBG_IsPrintQueFinished(FieldMsgBg *msgBg);
extern int FIELD_MSGBG_DrawMenuFuncFrame(FieldMenuFunc *menu);
extern u16 STRBUF_GetEosChar(void);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern void WORDSET_SetSlotTag(struct WordSet *words, u32 slot, struct Strbuf *src, u32 grammarCase, u32 isPlural, u32 gender);
extern void GFL_NET_COMMAND_DeleteCommandTable(u32 v);
extern int MYSTATUS_GetSize(void);
extern u32 GFL_NET_IsParentAid(void);
extern int FIELD_MSGBG_MenuFuncMain(FieldMenuFunc *menu);
extern void GFL_NET_ConnectMacAddressChild(void *context);
extern u32 GFL_NET_GetScanResult(u32 index);
extern void FIELD_MSGBG_DeleteMenuItems(struct BmpMenuWork *items);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, struct Strbuf *dest);
extern int FIELD_MSGBG_AddMenuItemStr(struct BmpMenuWork *items, struct Strbuf *text, u32 value, u32 heapId);
extern GFLNetHandle *GFL_NET_HANDLE_GetNetHandle(s32 id);
extern void GFL_NET_COMMAND_AddCommandTable(u32 groupKey, u32 commandList, u32 listNum, u32 userData);
extern void MI_CpuFill8();
extern void OS_GetMacAddress(u8 *macAddress);
extern u32 GFL_NET_SendData(GFLNetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 a, u32 b, u32 c);
extern u32 GFL_NET_SendDataMask(GFLNetHandle *handle, u32 recipients, u32 command, u32 size, const void *data, u32 a, u32 b, u32 c);
struct GFLNetHandle;
extern int GFL_NET_SendToHandle(struct GFLNetHandle *handle, u32 command, u32 size, void *data);

CommEntryMenu *COMM_ENTRY_MENU_Create(struct MyStatus *myStatus, struct FieldMap *fieldMap, u32 minMembers, u32 maxMembers, u32 heapId, u32 menuMode, u32 isChild, const u8 *mac);
u32 COMM_ENTRY_MENU_Delete(CommEntryMenu *menu);
void COMM_ENTRY_MENU_SetCallbacks(CommEntryMenu *menu, void *work, CommEntryMemberFunc onAdd, CommEntryMemberFunc onRemove);
void COMM_ENTRY_MENU_AddMember(CommEntryMenu *menu, int netId, const void *myStatus, u32 autoAccept, const u8 *mac);
u32 COMM_ENTRY_MENU_Main(CommEntryMenu *menu);
int COMM_ENTRY_MENU_MainRecruit(CommEntryMenu *menu);
int COMM_ENTRY_MENU_MainMode1(CommEntryMenu *menu);
int COMM_ENTRY_MENU_MainMode2(CommEntryMenu *menu);
int COMM_ENTRY_MENU_MainMode3(CommEntryMenu *menu);
void COMM_ENTRY_MENU_ProcessMemberQueues(CommEntryMenu *menu);
u8 COMM_ENTRY_MENU_CollectMemberNames(CommEntryMenu *menu);
void COMM_ENTRY_MENU_CheckDisconnects(CommEntryMenu *menu);
void COMM_ENTRY_MENU_UpdateMemberList(CommEntryMenu *menu);
void COMM_ENTRY_MENU_AdvanceMemberStates(CommEntryMenu *menu);
void COMM_ENTRY_MENU_ClearMember(CommEntryMenu *menu, int index);
int COMM_ENTRY_MENU_LatchRequest(CommEntryMenu *menu, CommEntryMember *member);
void COMM_ENTRY_MENU_ProcessRequest(CommEntryMenu *menu);
int COMM_ENTRY_MENU_ProcessCancel(CommEntryMenu *menu);
u32 COMM_ENTRY_MENU_ProcessStartConfirm(CommEntryMenu *menu);
void COMM_ENTRY_MENU_MarkMemberReady(CommEntryMenu *menu, int netId);
void COMM_ENTRY_MENU_SetAcceptFlag(CommEntryMenu *menu);
void COMM_ENTRY_MENU_SetCancelFlag(CommEntryMenu *menu);
void COMM_ENTRY_MENU_SetBusyFlags(CommEntryMenu *menu);
int COMM_ENTRY_MENU_CountAcceptedMembers(CommEntryMenu *menu);
u32 COMM_ENTRY_MENU_GetAcceptedMask(CommEntryMenu *menu);
int COMM_ENTRY_MENU_IsIdle(CommEntryMenu *menu);
void COMM_ENTRY_MENU_OpenWindows(CommEntryMenu *menu);
void COMM_ENTRY_MENU_CloseWindows(CommEntryMenu *menu);
int COMM_ENTRY_MENU_PrintRemaining(CommEntryMenu *menu, int count);
void COMM_ENTRY_MENU_UpdateMemberName(CommEntryMenu *menu, CommEntryMember *member, int index);
void COMM_ENTRY_MENU_ClearMemberName(CommEntryMenu *menu, CommEntryMember *member, int index);
void COMM_ENTRY_MENU_PrintMemberName(CommEntryMenu *menu, const void *myStatus, u32 row);
void COMM_ENTRY_MENU_EraseMemberName(CommEntryMenu *menu, u32 row);
void COMM_ENTRY_MENU_RefreshNames(CommEntryMenu *menu);
void COMM_ENTRY_MENU_PrintMessage(CommEntryMenu *menu, u32 msgId);
void COMM_ENTRY_MENU_SnapshotStates(CommEntryMenu *menu);
int COMM_ENTRY_MENU_StatesUnchanged(CommEntryMenu *menu);
void COMM_ENTRY_MENU_ClearPendingBits(CommEntryMenu *menu, int index);
void COMM_ENTRY_MENU_QueueSend(CommEntryMenu *menu);
CommEntryMenu *COMM_ENTRY_MENU_AckSend(CommEntryMenu *menu);
CommEntryRoster *COMM_ENTRY_MENU_GetNameBuffer(CommEntryMenu *menu);
void COMM_ENTRY_MENU_SetNameBuffer(CommEntryMenu *menu, const CommEntryRoster *roster);
void COMM_ENTRY_MENU_StartYesNo(CommEntryMenu *menu);
void COMM_ENTRY_MENU_EndYesNo(CommEntryMenu *menu);
u32 COMM_ENTRY_MENU_MainYesNo(CommEntryMenu *menu);
int COMM_ENTRY_PollParentList(CommEntryMenu *menu);
void COMM_ENTRY_TickParentTimeouts(CommEntryMenu *menu);
void COMM_ENTRY_ScanParents(CommEntryMenu *menu);
void COMM_ENTRY_AddParent(CommEntryMenu *menu, u8 *mac, CommEntryBeaconData *beacon);
void COMM_ENTRY_ClearParentSlot(CommEntryMenu *menu, int slotIndex);
void COMM_ENTRY_BuildParentItems(CommEntryMenu *menu);
int COMM_ENTRY_RunLeaveConfirm(CommEntryMenu *menu);
void COMM_ENTRY_ResetLeaveConfirm(CommEntryMenu *menu);
void COMM_ENTRY_StoreJoinReply(CommEntryMenu *menu, u32 reply, const void *parentMyStatus);
u32 COMM_ENTRY_GetRosterSize(void);
int COMM_ENTRY_IsOtherMemberConnected(int mask);
void COMM_ENTRY_StartNetCommands(CommEntryMenu *menu);
void COMM_ENTRY_EndNetCommands(void);
CommEntryRoster *COMM_ENTRY_GetRosterBuffer(u32 netId, CommEntryMenu *menu);
int COMM_ENTRY_RecvJoinRequest(u32 netId, u32 size, CommEntryJoinRequest *request, CommEntryMenu *menu);
u32 COMM_ENTRY_SendJoinRequest(const void *myStatus, u32 isChild, u32 netMode);
void COMM_ENTRY_RecvJoinAccept(u32 netId, u32 size, const void *parentMyStatus, CommEntryMenu *menu);
u32 COMM_ENTRY_SendJoinAccept(u32 index, u32 netMode, const void *myStatus);
void COMM_ENTRY_RecvJoinRedirect(u32 netId, u32 size, const void *parentMyStatus, CommEntryMenu *menu);
u32 COMM_ENTRY_SendJoinRedirect(u32 index, u32 netMode, const void *myStatus);
void COMM_ENTRY_RecvSessionLock(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
int COMM_ENTRY_SendSessionLock(int netMode);
void COMM_ENTRY_RecvReady(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
u32 COMM_ENTRY_SendReady(u32 netMode);
void COMM_ENTRY_RecvAccept(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
int COMM_ENTRY_SendAccept(int netMode);
void COMM_ENTRY_RecvCancel(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
int COMM_ENTRY_SendCancel(int netMode);
int COMM_ENTRY_RecvRoster(u32 netId, u32 size, const CommEntryRoster *roster, CommEntryMenu *menu);
u32 COMM_ENTRY_SendRoster(const CommEntryRoster *roster, u32 recipients, int netMode);

extern const char d_021DE5E8[];
extern const u8 data_021DB4BC[];
extern const u16 gCommEntryMsgTable[2][6];
extern const u8 gCommEntryEmptyMac[6];
extern const FieldMenuHeader gCommEntryParentListHeader;


CommEntryMenu *COMM_ENTRY_MENU_Create(struct MyStatus *myStatus, struct FieldMap *fieldMap, u32 minMembers, u32 maxMembers, u32 heapId, u32 menuMode, u32 isChild, const u8 *mac)
{
    FieldMsgBg *msgBg;
    CommEntryMenu *menu;
    GFLNetInitializeStruct *netInit;

    msgBg = FIELDMAP_GetMsgBg(fieldMap);
    menu = GFL_HEAP_Alloc(heapId, sizeof(CommEntryMenu), 1, d_021DE5E8, 0x179);
    menu->wordSet = WORDSET_CreateDefault(heapId);
    menu->msgData = FIELD_MSGBG_CreateMsgData(msgBg, 0x1e);
    menu->sysWin = FIELD_MSGBG_CreateBottomSysWin(msgBg, menu->msgData);
    menu->msgStr = STRBUF_Create(0x64, heapId);
    menu->nameFormat = MSGDATA_AllocString((struct MsgBank *)menu->msgData, 7);
    menu->nameStr = STRBUF_Create(0x40, heapId);
    if (isChild == 1) {
        menu->remainingFormat = MSGDATA_AllocString((struct MsgBank *)menu->msgData, 3);
    } else {
        menu->remainingFormat = MSGDATA_AllocString((struct MsgBank *)menu->msgData, 2);
    }
    menu->remainingStr = STRBUF_Create(0x20, heapId);
    menu->minMembers = minMembers;
    menu->maxMembers = maxMembers;
    menu->fieldMap = fieldMap;
    menu->menuMode = menuMode;
    menu->isChild = isChild;
    menu->heapId = heapId;
    menu->memberCount = -1;
    menu->nextMessage = 0xffff;
    MYSTATUS_Copy((struct MyStatus *)myStatus, (struct MyStatus *)menu->myStatus);
    if (mac != 0) {
        MI_CpuCopy8(mac, menu->ownMac, 6);
    }
    GFL_NET_SetLoginOption(0);
    COMM_ENTRY_StartNetCommands(menu);
    if (isChild == 1) {
        menu->netMode = 1;
    }
    netInit = GFL_NET_GetInitParam();
    ((CommEntryBeaconData *)netInit->getBeaconDataFunc((void *)GFL_NET_GetUserArg()))->advertiseId = COMM_ENTRY_ADVERTISE_ID;
    return menu;
}


u32 COMM_ENTRY_MENU_Delete(CommEntryMenu *menu)
{
    u32 acceptedMask;

    acceptedMask = COMM_ENTRY_MENU_GetAcceptedMask(menu);
    COMM_ENTRY_MENU_CloseWindows(menu);
    if (menu->confirm.menu) {
        FIELD_MSGBG_DeleteMenuFunc(menu->confirm.menu);
        menu->confirm.menu = 0;
    }
    STRBUF_Delete(menu->remainingStr);
    STRBUF_Delete(menu->remainingFormat);
    STRBUF_Delete(menu->nameStr);
    STRBUF_Delete(menu->nameFormat);
    STRBUF_Delete(menu->msgStr);
    FIELD_MSGBG_DeleteSysWin(menu->sysWin);
    FIELD_MSGBG_DeleteMsgData(menu->msgData);
    WORDSET_Delete(menu->wordSet);
    if (GFL_NET_GetRunState() == 1) {
        COMM_ENTRY_EndNetCommands();
    }
    GFL_HEAP_Free(menu);
    return acceptedMask;
}


void COMM_ENTRY_MENU_SetCallbacks(CommEntryMenu *menu, void *work, CommEntryMemberFunc onAdd, CommEntryMemberFunc onRemove)
{
    menu->callbackWork = work;
    menu->onAdd = onAdd;
    menu->onRemove = onRemove;
}


void COMM_ENTRY_MENU_AddMember(CommEntryMenu *menu, int netId, const void *myStatus, u32 autoAccept, const u8 *mac)
{
    CommEntryMember *member;

    member = &menu->members[netId];
    MYSTATUS_Copy((struct MyStatus *)myStatus, (struct MyStatus *)member);
    member->state = COMM_ENTRY_MEMBER_JOINED;
    member->autoAccept = autoAccept;
    MI_CpuCopy8(mac, member->mac, 6);
    COMM_ENTRY_MENU_ClearPendingBits(menu, (u8)netId);
    COMM_ENTRY_MENU_QueueSend(menu);
    if (menu->onAdd) {
        menu->onAdd(menu->callbackWork, myStatus, mac);
    }
}


u32 COMM_ENTRY_MENU_Main(CommEntryMenu *menu)
{
    int done;

    switch (menu->menuMode) {
    case COMM_ENTRY_MODE_RECRUIT:
        done = COMM_ENTRY_MENU_MainRecruit(menu);
        break;
    case COMM_ENTRY_MODE_CHOOSE:
        done = COMM_ENTRY_MENU_MainMode1(menu);
        break;
    case COMM_ENTRY_MODE_HOST:
        done = COMM_ENTRY_MENU_MainMode2(menu);
        break;
    case COMM_ENTRY_MODE_JOIN:
        done = COMM_ENTRY_MENU_MainMode3(menu);
        break;
    }
    if (done == 1) {
        return menu->result;
    }
    return 0;
}


/*
 * Per-frame state machine of the recruit flow (RECRUIT_* states). Scheduling
 * levers: case WAIT_START_SYNC is placed after SEND_START (image layout), case
 * CHECK_ROLE tests `== 0` first, the member loop condition is
 * `(i < 4) ? 1 : 0` (branch to the bottom test), `1u << i` is used only in the
 * readyMask test (an identical `1 << i` is CSEd across the call and spills the
 * mask), and the readyBits test shifts by `(u32)i`: with the plain int
 * promotion the shift is evaluated before the readyBits load, so `movs r0,#1`
 * is live across the reload of the spilled offset and the reload lands in r1.
 */
int COMM_ENTRY_MENU_MainRecruit(CommEntryMenu *menu)
{
    int count;
    u16 pendingMessage;
    u8 repliedMask;
    u8 netId;

    if (menu->state != 0) {
        COMM_ENTRY_MENU_CheckDisconnects(menu);
        COMM_ENTRY_MENU_UpdateMemberList(menu);
        COMM_ENTRY_MENU_ProcessMemberQueues(menu);
    }

    switch (menu->state) {
    case RECRUIT_OPEN:
        COMM_ENTRY_MENU_OpenWindows(menu);
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_WAIT_FOR_MEMBERS);
        menu->state++;
        break;
    case RECRUIT_CHECK_ROLE:
        if (menu->isChild == 0) {
            menu->state = RECRUIT_REGISTER_SELF;
        } else {
            GFL_NET_StartByNetType();
            menu->state++;
        }
        break;
    case RECRUIT_WAIT_CONNECT:
        if (GFL_NET_SYSTEM_GetConnectNum() > 1) {
            if (GFL_NET_HANDLE_CheckNegotiation() == 1) {
                menu->state++;
            }
        } else if (KEY_GetTrg() & 2) {
            menu->state = RECRUIT_CONFIRM_QUIT;
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = RECRUIT_DONE;
        }
        break;
    case RECRUIT_WAIT_NEGOTIATION:
        if (GFL_NET_HANDLE_IsNegotiationDone(GFL_NET_HANDLE_GetCurrentHandle()) == 1) {
            menu->state = RECRUIT_REGISTER_SELF;
        }
        break;
    case RECRUIT_REGISTER_SELF:
        if (COMM_ENTRY_SendJoinRequest(menu->myStatus, 1, menu->netMode) == 1) {
            menu->state++;
        }
        break;
    case RECRUIT_COLLECT:
        COMM_ENTRY_MENU_AdvanceMemberStates(menu);
        COMM_ENTRY_MENU_ProcessRequest(menu);
        if (COMM_ENTRY_MENU_IsIdle(menu) == 1) {
            count = COMM_ENTRY_MENU_CountAcceptedMembers(menu);
            pendingMessage = menu->nextMessage;
            menu->nextMessage = 0xFFFF;
            if (count >= menu->maxMembers || (count >= menu->minMembers && (KEY_GetTrg() & 1))) {
                COMM_ENTRY_MENU_SnapshotStates(menu);
                menu->state = RECRUIT_CONFIRM_START;
            } else if (KEY_GetTrg() & 2) {
                menu->state = RECRUIT_CONFIRM_QUIT;
            } else if (menu->isChild == 0 && GFL_NET_GetNegotiationNum() <= 1) {
                menu->state = RECRUIT_SHOW_ALONE_MESSAGE;
            } else if (pendingMessage != 0xFFFF) {
                COMM_ENTRY_MENU_PrintMessage(menu, pendingMessage);
            }
        }
        break;
    case RECRUIT_CONFIRM_START:
        count = COMM_ENTRY_MENU_ProcessCancel(menu);
        if (count == 1) {
            GFL_NET_SetAcceptConnection((u32)(GFL_NET_HANDLE_GetCurrentHandle()), 0);
            menu->state = RECRUIT_SEND_READY_REQUEST;
        } else if (count == 2) {
            if (COMM_ENTRY_MENU_CountAcceptedMembers(menu) >= menu->maxMembers) {
                menu->state = RECRUIT_CONFIRM_QUIT;
            } else {
                menu->state = RECRUIT_COLLECT;
                if (COMM_ENTRY_MENU_CountAcceptedMembers(menu) > 1 && menu->isChild == 1) {
                    menu->nextMessage = COMM_ENTRY_MSG_MEMBERS_CAN_START;
                } else {
                    menu->nextMessage = COMM_ENTRY_MSG_WAIT_FOR_MEMBERS;
                }
            }
        }
        break;
    case RECRUIT_CONFIRM_QUIT:
        count = COMM_ENTRY_MENU_ProcessStartConfirm(menu);
        if (count == 1) {
            GFL_NET_SetAcceptConnection((u32)(GFL_NET_HANDLE_GetCurrentHandle()), 0);
            menu->state = RECRUIT_SEND_QUIT;
        } else if (count == 2) {
            menu->state = RECRUIT_COLLECT;
        }
        break;
    case RECRUIT_SEND_READY_REQUEST:
        if (COMM_ENTRY_SendSessionLock(menu->netMode) == 1) {
            COMM_ENTRY_MENU_MarkMemberReady(menu, GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()));
            menu->readyMask = menu->roster.mask;
            GFL_NET_SetLoginOption(1);
            menu->state = RECRUIT_WAIT_READY;
        }
        break;
    case RECRUIT_WAIT_READY:
        repliedMask = 1 << GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle());
        for (netId = 0; (netId < 4) ? 1 : 0; netId++) {
            if (netId != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) && (menu->readyMask & (1u << netId))) {
                if (GFL_NET_IsConnectMember(netId) == 1) {
                    if (menu->readyBits & (1 << (u32)netId)) {
                        repliedMask |= (u8)(1 << netId);
                    }
                } else {
                    menu->state = RECRUIT_SEND_ABORT;
                    break;
                }
            }
        }
        if (menu->readyMask == repliedMask) {
            if (MATH_CountPopulation(menu->readyBits) < menu->minMembers) {
                menu->state = RECRUIT_SEND_ABORT;
            } else {
                menu->state = RECRUIT_SEND_START;
            }
        }
        break;
    case RECRUIT_SEND_ABORT:
        if (COMM_ENTRY_SendCancel(menu->netMode) == 1) {
            menu->readyMask = menu->roster.mask;
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = RECRUIT_SHOW_ABORT_MESSAGE;
        }
        break;
    case RECRUIT_SEND_START:
        if (COMM_ENTRY_SendAccept(menu->netMode) == 1) {
            menu->result = COMM_ENTRY_RESULT_START;
            menu->state = RECRUIT_WAIT_START_SYNC;
            menu->readyCount = MATH_CountPopulation(menu->readyBits);
            GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27);
        }
        break;
    case RECRUIT_WAIT_START_SYNC:
        if (menu->readyCount != GFL_NET_SYSTEM_GetConnectNum() || menu->minMembers > GFL_NET_SYSTEM_GetConnectNum()) {
            if (COMM_ENTRY_SendCancel(menu->netMode) == 1) {
                menu->readyMask = menu->roster.mask;
                menu->result = COMM_ENTRY_RESULT_CANCEL;
                menu->state = RECRUIT_SHOW_ABORT_MESSAGE;
            }
        } else if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27) == 1) {
            GFLNetInitializeStruct *netInit;

            menu->result = COMM_ENTRY_RESULT_START;
            menu->state = RECRUIT_DONE;
            netInit = GFL_NET_GetInitParam();
            ((CommEntryBeaconData *)netInit->getBeaconDataFunc((void *)GFL_NET_GetUserArg()))->advertiseId = 0;
        }
        break;
    case RECRUIT_SEND_QUIT:
        if (COMM_ENTRY_SendCancel(menu->netMode) == 1) {
            menu->readyMask = menu->roster.mask;
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = RECRUIT_WAIT_QUIT_SENT;
        }
        break;
    case RECRUIT_SHOW_ABORT_MESSAGE:
        {
            const u16 *row = gCommEntryMsgTable[menu->isChild];

            COMM_ENTRY_MENU_PrintMessage(menu, row[COMM_ENTRY_MSGCOL_ABORT]);
        }
        menu->state = RECRUIT_WAIT_ABORT_MESSAGE;
        break;
    case RECRUIT_WAIT_ABORT_MESSAGE:
        if (FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            menu->state = RECRUIT_WAIT_QUIT_SENT;
        }
        break;
    case RECRUIT_WAIT_QUIT_SENT:
        if (COMM_ENTRY_IsOtherMemberConnected(menu->readyMask) == 0) {
            menu->state = RECRUIT_DONE;
        }
        break;
    case RECRUIT_SHOW_ALONE_MESSAGE:
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_NO_MEMBERS);
        menu->state = RECRUIT_WAIT_ALONE_MESSAGE;
        break;
    case RECRUIT_WAIT_ALONE_MESSAGE:
        if (FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = RECRUIT_DONE;
        }
        break;
    case RECRUIT_DONE:
        COMM_ENTRY_MENU_CloseWindows(menu);
        return 1;
    }

    if (GFL_NET_ERR_GetErrorLevel() != 0) {
        menu->result = COMM_ENTRY_RESULT_NET_ERROR;
        return 1;
    }
    return 0;
}


int COMM_ENTRY_MENU_MainMode1(CommEntryMenu *menu)
{
    switch (menu->state) {
    case CHOOSE_SHOW_OPEN_MESSAGE:
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_OPEN));
        menu->state++;
        break;
    case CHOOSE_WAIT_OPEN_MESSAGE:
        if (FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            menu->state++;
        }
        break;
    case CHOOSE_OPEN_LIST:
        COMM_ENTRY_MENU_EndYesNo(menu);
        COMM_ENTRY_MENU_CloseWindows(menu);
        menu->parentList.selected = 0;
        COMM_ENTRY_MENU_StartYesNo(menu);
        GFL_NET_BeaconScanStart();
        menu->state++;
        break;
    case CHOOSE_RUN_LIST:
        switch (COMM_ENTRY_MENU_MainYesNo(menu)) {
        case LIST_RESULT_JOINED:
            COMM_ENTRY_MENU_EndYesNo(menu);
            if (menu->acceptFlag == 1) {
                menu->state = CHOOSE_ACCEPTED;
            } else if (menu->cancelFlag == 1) {
                menu->state = CHOOSE_SHOW_CANCEL_MESSAGE;
            } else {
                WORDSET_SetSlotMyStatus(menu->wordSet, 0, menu->parentList.selected);
                COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_JOINED);
                menu->state = CHOOSE_WAIT_JOINED_MESSAGE;
            }
            break;
        case LIST_RESULT_REDIRECTED:
            COMM_ENTRY_MENU_EndYesNo(menu);
            menu->state = CHOOSE_SWITCH_BEGIN;
            break;
        case LIST_RESULT_LEFT:
            COMM_ENTRY_MENU_EndYesNo(menu);
            menu->state = CHOOSE_CANCELLED;
            break;
        }
        break;
    case CHOOSE_WAIT_JOINED_MESSAGE:
        if (FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_WAIT_IN_LOBBY);
            COMM_ENTRY_MENU_OpenWindows(menu);
            menu->state++;
        }
        break;
    case CHOOSE_COLLECT:
        if (COMM_ENTRY_RunLeaveConfirm(menu) == 2) {
            COMM_ENTRY_MENU_CloseWindows(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            menu->state = CHOOSE_CANCELLED;
            break;
        }
        if (menu->lockNotifyPending == 1) {
            if (COMM_ENTRY_SendReady(menu->netMode) == 1) {
                menu->lockNotifyPending = 0;
            }
        }
        COMM_ENTRY_MENU_RefreshNames(menu);
        if (menu->acceptFlag == 1) {
            COMM_ENTRY_MENU_CloseWindows(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            menu->state = CHOOSE_ACCEPTED;
        } else if (menu->cancelFlag == 1) {
            COMM_ENTRY_MENU_CloseWindows(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            menu->state = CHOOSE_SHOW_CANCEL_MESSAGE;
        }
        break;
    case CHOOSE_ACCEPTED:
        if (menu->isChild == 0) {
            COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_STARTING);
        }
        menu->state = CHOOSE_WAIT_SYNC;
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27);
        break;
    case CHOOSE_WAIT_SYNC:
        if (menu->isChild != 0 || FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27) == 1) {
                menu->result = COMM_ENTRY_RESULT_START;
                menu->state = CHOOSE_DONE;
            } else if (menu->cancelFlag == 1) {
                menu->state = CHOOSE_SHOW_CANCEL_MESSAGE;
            }
        }
        break;
    case CHOOSE_SHOW_CANCEL_MESSAGE:
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_ABORT));
        menu->state = CHOOSE_WAIT_CANCEL_MESSAGE;
        break;
    case CHOOSE_WAIT_CANCEL_MESSAGE:
        if (FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            menu->state = CHOOSE_CANCELLED;
        }
        break;
    case CHOOSE_SWITCH_BEGIN:
        menu->savedUserArg = GFL_NET_GetUserArg();
        MI_CpuCopy8(GFL_NET_GetInitParam(), &menu->netInitBackup, sizeof(GFLNetInitializeStruct));
        COMM_ENTRY_EndNetCommands();
        GFL_NET_Exit(0);
        WORDSET_SetSlotMyStatus(menu->wordSet, 0, menu->parentMyStatus);
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_SWITCHING);
        menu->state = CHOOSE_SWITCH_WAIT_EXIT;
        break;
    case CHOOSE_SWITCH_WAIT_EXIT:
        if (GFL_NET_IsSessionNull() == 1 && FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            menu->state = CHOOSE_SWITCH_START_SESSION;
        }
        break;
    case CHOOSE_SWITCH_START_SESSION:
        GFL_NET_StartSession(&menu->netInitBackup, 0, menu->savedUserArg);
        menu->state = CHOOSE_SWITCH_WAIT_SESSION;
        break;
    case CHOOSE_SWITCH_WAIT_SESSION:
        if (GFL_NET_GetRunState() == 1) {
            COMM_ENTRY_StartNetCommands(menu);
            menu->state = CHOOSE_SHOW_OPEN_MESSAGE;
        }
        break;
    case CHOOSE_CANCELLED:
        menu->result = COMM_ENTRY_RESULT_CANCEL;
        menu->state = CHOOSE_DONE;
        break;
    case CHOOSE_DONE:
        COMM_ENTRY_MENU_EndYesNo(menu);
        COMM_ENTRY_MENU_CloseWindows(menu);
        return 1;
    }
    if (GFL_NET_ERR_GetErrorLevel() != 0) {
        COMM_ENTRY_ResetLeaveConfirm(menu);
        COMM_ENTRY_MENU_EndYesNo(menu);
        menu->result = COMM_ENTRY_RESULT_NET_ERROR;
        return 1;
    }
    return 0;
}


int COMM_ENTRY_MENU_MainMode2(CommEntryMenu *menu)
{
    switch (menu->state) {
    case HOST_SHOW_CONNECT_MESSAGE:
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_CONNECTING);
        menu->state++;
        break;
    case HOST_REGISTER_SELF:
        if (COMM_ENTRY_SendJoinRequest(menu->myStatus, 1, menu->netMode) == 1) {
            menu->state++;
        }
        break;
    case HOST_OPEN_WINDOWS:
        COMM_ENTRY_MENU_OpenWindows(menu);
        menu->state++;
        break;
    case HOST_COLLECT:
        if (COMM_ENTRY_RunLeaveConfirm(menu) == 2) {
            COMM_ENTRY_MENU_CloseWindows(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            menu->state = HOST_CANCELLED;
            break;
        }
        if (menu->lockNotifyPending == 1) {
            if (COMM_ENTRY_SendReady(menu->netMode) == 1) {
                menu->lockNotifyPending = 0;
            }
        }
        COMM_ENTRY_MENU_RefreshNames(menu);
        if (menu->acceptFlag == 1) {
            COMM_ENTRY_MENU_CloseWindows(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            menu->state = HOST_ACCEPTED;
        } else if (menu->cancelFlag == 1) {
            COMM_ENTRY_MENU_CloseWindows(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            menu->state = HOST_SHOW_CANCEL_MESSAGE;
        }
        break;
    case HOST_ACCEPTED:
        if (menu->isChild == 0) {
            COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_STARTING);
        }
        menu->state = HOST_WAIT_SYNC;
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27);
        break;
    case HOST_WAIT_SYNC:
        if (menu->isChild != 0 || FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27) == 1) {
                menu->result = COMM_ENTRY_RESULT_START;
                menu->state = HOST_DONE;
            } else if (menu->cancelFlag == 1) {
                menu->state = HOST_SHOW_CANCEL_MESSAGE;
            }
        }
        break;
    case HOST_SHOW_CANCEL_MESSAGE:
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_ABORT));
        menu->state = HOST_WAIT_CANCEL_MESSAGE;
        break;
    case HOST_WAIT_CANCEL_MESSAGE:
        if (FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = HOST_DONE;
        }
        break;
    case HOST_SWITCH_SHOW_MESSAGE:
        GFL_NET_Exit(0);
        WORDSET_SetSlotMyStatus(menu->wordSet, 0, menu->parentList.selected);
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_SWITCHING);
        menu->state = HOST_SWITCH_WAIT_MESSAGE;
        break;
    case HOST_SWITCH_WAIT_MESSAGE:
        if (GFL_NET_IsSessionNull() == 1 && FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            menu->result = COMM_ENTRY_RESULT_SWITCHED;
            menu->state = HOST_DONE;
        }
        break;
    case HOST_CANCELLED:
        menu->result = COMM_ENTRY_RESULT_CANCEL;
        menu->state = HOST_DONE;
        break;
    case HOST_DONE:
        COMM_ENTRY_MENU_CloseWindows(menu);
        return 1;
    }
    if (GFL_NET_ERR_GetErrorLevel() != 0) {
        COMM_ENTRY_ResetLeaveConfirm(menu);
        menu->result = COMM_ENTRY_RESULT_NET_ERROR;
        return 1;
    }
    return 0;
}


/*
 * In WAIT_REPLY the refused arm calls COMM_ENTRY_ResetLeaveConfirm twice: the original's
 * branch lands on COLLECT's second-call tail after its own call.
 */
int COMM_ENTRY_MENU_MainMode3(CommEntryMenu *menu)
{
    switch (menu->state) {
    case JOIN_SHOW_CONNECT_MESSAGE:
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_CONNECTING);
        menu->state++;
        break;
    case JOIN_REGISTER_SELF:
        menu->joinReply = 0;
        if (COMM_ENTRY_SendJoinRequest(menu->myStatus, 0, menu->netMode) == 1) {
            menu->state = JOIN_WAIT_REPLY;
        }
        break;
    case JOIN_WAIT_REPLY:
        if (COMM_ENTRY_RunLeaveConfirm(menu) == 2) {
            COMM_ENTRY_MENU_CloseWindows(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            menu->state = JOIN_CANCELLED;
            break;
        }
        if (menu->joinReply == 1) {
            menu->state = JOIN_OPEN_WINDOWS;
            COMM_ENTRY_ResetLeaveConfirm(menu);
        } else if (menu->joinReply == 2) {
            menu->state = JOIN_SWITCH_SHOW_MESSAGE;
            COMM_ENTRY_ResetLeaveConfirm(menu);
        } else if (menu->acceptFlag == 1) {
            menu->state = JOIN_ACCEPTED;
            COMM_ENTRY_ResetLeaveConfirm(menu);
        } else if (menu->cancelFlag == 1) {
            menu->state = JOIN_CANCELLED;
            COMM_ENTRY_ResetLeaveConfirm(menu);
        }
        break;
    case JOIN_OPEN_WINDOWS:
        COMM_ENTRY_MENU_OpenWindows(menu);
        menu->state++;
        break;
    case JOIN_COLLECT:
        if (COMM_ENTRY_RunLeaveConfirm(menu) == 2) {
            COMM_ENTRY_MENU_CloseWindows(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            menu->state = JOIN_CANCELLED;
            break;
        }
        if (menu->lockNotifyPending == 1) {
            if (COMM_ENTRY_SendReady(menu->netMode) == 1) {
                menu->lockNotifyPending = 0;
            }
        }
        COMM_ENTRY_MENU_RefreshNames(menu);
        if (menu->acceptFlag == 1) {
            COMM_ENTRY_MENU_CloseWindows(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            menu->state = JOIN_ACCEPTED;
        } else if (menu->cancelFlag == 1) {
            COMM_ENTRY_MENU_CloseWindows(menu);
            COMM_ENTRY_ResetLeaveConfirm(menu);
            menu->state = JOIN_SHOW_CANCEL_MESSAGE;
        }
        break;
    case JOIN_ACCEPTED:
        if (menu->isChild == 0) {
            COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_STARTING);
        }
        menu->state = JOIN_WAIT_SYNC;
        GFL_NET_HANDLE_SetTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27);
        break;
    case JOIN_WAIT_SYNC:
        if (menu->isChild != 0 || FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            if (GFL_NET_HANDLE_IsTimingSyncRange(GFL_NET_HANDLE_GetCurrentHandle(), 1, 0x27) == 1) {
                menu->result = COMM_ENTRY_RESULT_START;
                menu->state = JOIN_DONE;
            } else if (menu->cancelFlag == 1) {
                menu->state = JOIN_SHOW_CANCEL_MESSAGE;
            }
        }
        break;
    case JOIN_SHOW_CANCEL_MESSAGE:
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_ABORT));
        menu->state = JOIN_WAIT_CANCEL_MESSAGE;
        break;
    case JOIN_WAIT_CANCEL_MESSAGE:
        if (FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = JOIN_DONE;
        }
        break;
    case JOIN_SWITCH_SHOW_MESSAGE:
        GFL_NET_Exit(0);
        WORDSET_SetSlotMyStatus(menu->wordSet, 0, menu->parentMyStatus);
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_SWITCHING);
        menu->state = JOIN_SWITCH_WAIT_MESSAGE;
        break;
    case JOIN_SWITCH_WAIT_MESSAGE:
        if (GFL_NET_IsSessionNull() == 1 && FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            menu->result = COMM_ENTRY_RESULT_SWITCHED;
            menu->state = JOIN_DONE;
        }
        break;
    case JOIN_CANCELLED:
        menu->result = COMM_ENTRY_RESULT_CANCEL;
        menu->state = JOIN_DONE;
        break;
    case JOIN_DONE:
        COMM_ENTRY_MENU_CloseWindows(menu);
        return 1;
    }
    if (GFL_NET_ERR_GetErrorLevel() != 0) {
        COMM_ENTRY_ResetLeaveConfirm(menu);
        menu->result = COMM_ENTRY_RESULT_NET_ERROR;
        return 1;
    }
    return 0;
}


void COMM_ENTRY_MENU_ProcessMemberQueues(CommEntryMenu *menu)
{
    u8 netId;
    int bit;
    u8 memberCount;

    for (netId = 0; netId < 4; netId++) {
        bit = 1 << netId;
        if (menu->pendingAddBits & bit) {
            if (COMM_ENTRY_SendJoinAccept(netId, menu->netMode, menu->myStatus) == 1)
                menu->pendingAddBits ^= (u8)bit;
        } else if (menu->pendingRemoveBits & bit) {
            if (COMM_ENTRY_SendJoinRedirect(netId, menu->netMode, menu->myStatus) == 1)
                menu->pendingRemoveBits ^= (u8)bit;
        }
    }
    if (menu->sendPending == 1 && menu->sendBusy == 0) {
        memberCount = COMM_ENTRY_MENU_CollectMemberNames(menu);
        if (memberCount > 1) {
            if (COMM_ENTRY_SendRoster(&menu->roster, memberCount, menu->netMode) == 1) {
                menu->sendPending = 0;
                menu->sendBusy = 1;
            }
        }
    }
}


/* Copies the accepted members' names into the roster; returns 1 | mask. */
u8 COMM_ENTRY_MENU_CollectMemberNames(CommEntryMenu *menu)
{
    u8 netId;
    u8 mask;
    CommEntryRoster *roster;
    CommEntryMember *members;

    mask = 0;
    netId = 0;
    members = menu->members;
    roster = &menu->roster;
    for (; netId < 4; netId++) {
        if (menu->members[netId].state) {
            MYSTATUS_Copy((struct MyStatus *)(members + netId), (struct MyStatus *)roster->myStatus[netId]);
            mask |= 1 << netId;
        }
    }
    menu->roster.mask = mask;
    return 1 | mask;
}


void COMM_ENTRY_MENU_CheckDisconnects(CommEntryMenu *menu)
{
    u8 netId;

    for (netId = 0; netId < 4; netId++) {
        if (menu->members[netId].state && !GFL_NET_IsConnectMember(netId)) {
            CommEntryMemberFunc onRemove = menu->onRemove;

            if (onRemove) {
                onRemove(menu->callbackWork, &menu->members[netId], menu->members[netId].mac);
            }
            COMM_ENTRY_MENU_ClearMember(menu, netId);
            COMM_ENTRY_MENU_ClearPendingBits(menu, netId);
            COMM_ENTRY_MENU_QueueSend(menu);
        }
    }
}


void COMM_ENTRY_MENU_UpdateMemberList(CommEntryMenu *menu)
{
    CommEntryMember *members;
    int index;
    int count;

    count = 0;
    index = 0;
    members = menu->members;
    for (; index < 4; index++) {
        if (menu->members[index].state) {
            COMM_ENTRY_MENU_UpdateMemberName(menu, members + index, index);
            count++;
        } else {
            COMM_ENTRY_MENU_ClearMemberName(menu, members + index, index);
        }
    }
    if (count == 0) {
        COMM_ENTRY_MENU_PrintMemberName(menu, menu->myStatus, 0);
        count++;
    }
    if (menu->memberCount != count) {
        if (COMM_ENTRY_MENU_PrintRemaining(menu, count) == 1) {
            menu->memberCount = count;
            if (menu->isChild == 1 && count == 1) {
                menu->refreshPending = 1;
            }
        }
    }
    if (menu->refreshPending == 1) {
        if (COMM_ENTRY_MENU_IsIdle(menu) == 1 && menu->confirm.menu == 0) {
            if (count == 1) {
                COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_WAIT_FOR_MEMBERS);
            }
            menu->refreshPending = 0;
        }
    }
}


void COMM_ENTRY_MENU_AdvanceMemberStates(CommEntryMenu *menu)
{
    CommEntryMember *member;
    u8 netId;

    member = menu->members;
    for (netId = 0; netId < 4; netId++, member++) {
        switch (member->state) {
        case COMM_ENTRY_MEMBER_JOINED:
            if (member->autoAccept == 1) {
                member->state = COMM_ENTRY_MEMBER_ACCEPTED;
                menu->pendingAddBits |= 1 << netId;
            } else {
                member->state = COMM_ENTRY_MEMBER_QUEUED;
            }
            break;
        case COMM_ENTRY_MEMBER_QUEUED:
            if (COMM_ENTRY_MENU_LatchRequest(menu, member) == 1) {
                member->state = COMM_ENTRY_MEMBER_ASKING;
            }
            break;
        }
    }
}


void COMM_ENTRY_MENU_ClearMember(CommEntryMenu *menu, int index)
{
    menu->members[index].state = COMM_ENTRY_MEMBER_EMPTY;
}


/* Latches a join request when none is pending; returns whether it did. */
int COMM_ENTRY_MENU_LatchRequest(CommEntryMenu *menu, CommEntryMember *member)
{
    if (menu->requestPending == 0) {
        menu->request = *member;
        menu->requestPending = 1;
        return 1;
    }
    return 0;
}


/*
 * The request base kept in r6 comes from `request` being assigned first.
 */
void COMM_ENTRY_MENU_ProcessRequest(CommEntryMenu *menu)
{
    CommEntryConfirm *confirm;
    CommEntryMember *request;
    u32 answer;
    u8 netId;
    u8 newState;

    request = &menu->request;
    confirm = &menu->confirm;
    if (menu->requestPending == 0) {
        return;
    }
    if (!FIELD_MSGBG_SysWinMain(menu->sysWin)) {
        return;
    }
    switch (confirm->state) {
    case CONFIRM_ASK:
        WORDSET_SetSlotMyStatus(menu->wordSet, 0, request);
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_ASK_JOIN_REQUEST);
        confirm->state++;
        break;
    case CONFIRM_OPEN_MENU:
        confirm->menu = FIELD_MSGBG_CreateYesNoMenu(FIELDMAP_GetMsgBg(menu->fieldMap), 0);
        confirm->state++;
        break;
    case CONFIRM_WAIT_ANSWER:
        answer = FIELD_MSGBG_YesNoMenuMain(confirm->menu);
        if (answer == 2) {
            break;
        }
        newState = COMM_ENTRY_MEMBER_ACCEPTED;
        if (answer != 0) {
            newState = COMM_ENTRY_MEMBER_REFUSED;
        }
        for (netId = 0; netId < 4; netId++) {
            if (menu->members[netId].state == COMM_ENTRY_MEMBER_ASKING) {
                menu->members[netId].state = newState;
                if (newState == COMM_ENTRY_MEMBER_ACCEPTED) {
                    menu->pendingAddBits |= 1 << netId;
                } else {
                    menu->pendingRemoveBits |= 1 << netId;
                }
                break;
            }
        }
        FIELD_MSGBG_DeleteMenuFunc(confirm->menu);
        confirm->menu = 0;
        confirm->state++;
        break;
    case CONFIRM_FINISH_REQUEST:
        menu->requestPending = 0;
        confirm->state = CONFIRM_ASK;
        COMM_ENTRY_MENU_AdvanceMemberStates(menu);
        if (menu->requestPending == 0) {
            if (COMM_ENTRY_MENU_CountAcceptedMembers(menu) > 1 && menu->isChild == 1) {
                menu->nextMessage = COMM_ENTRY_MSG_MEMBERS_CAN_START;
            } else {
                menu->nextMessage = COMM_ENTRY_MSG_WAIT_FOR_MEMBERS;
            }
        }
        break;
    }
}


/* Asks whether to start with the members present; returns 1 for yes, 2 for no, else 0. */
int COMM_ENTRY_MENU_ProcessCancel(CommEntryMenu *menu)
{
    CommEntryConfirm *confirm;
    u32 answer;

    confirm = &menu->confirm;
    if (!FIELD_MSGBG_SysWinMain(menu->sysWin)) {
        return 0;
    }
    switch (confirm->state) {
    case CONFIRM_ASK:
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_CONFIRM_START);
        confirm->state++;
        break;
    case CONFIRM_OPEN_MENU:
        confirm->menu = FIELD_MSGBG_CreateYesNoMenu(FIELDMAP_GetMsgBg(menu->fieldMap), 0);
        confirm->state++;
        break;
    case CONFIRM_WAIT_ANSWER:
        if (!COMM_ENTRY_MENU_StatesUnchanged(menu)) {
            answer = 1;
        } else {
            answer = FIELD_MSGBG_YesNoMenuMain(confirm->menu);
            if (answer == 2) {
                break;
            }
        }
        FIELD_MSGBG_DeleteMenuFunc(confirm->menu);
        confirm->menu = 0;
        confirm->state = CONFIRM_ASK;
        if (answer == 0) {
            return 1;
        }
        return 2;
    }
    return 0;
}


/*
 * Asks whether to quit; returns 1 to quit, 2 to stay, else 0. The two
 * question steps (3 and 1) are identical bodies the compiler tail-merged.
 */
u32 COMM_ENTRY_MENU_ProcessStartConfirm(CommEntryMenu *menu)
{
    CommEntryConfirm *confirm;
    u32 answer;

    confirm = &menu->confirm;
    if (!FIELD_MSGBG_SysWinMain(menu->sysWin)) {
        return 0;
    }
    switch (confirm->state) {
    case CONFIRM_ASK:
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_QUIT_ASK));
        confirm->state++;
        break;
    case CONFIRM_OPEN_MENU:
        confirm->menu = FIELD_MSGBG_CreateYesNoMenu(FIELDMAP_GetMsgBg(menu->fieldMap), 0);
        confirm->state++;
        break;
    case CONFIRM_WAIT_ANSWER:
        answer = FIELD_MSGBG_YesNoMenuMain(confirm->menu);
        if (answer == 2) {
            break;
        }
        FIELD_MSGBG_DeleteMenuFunc(confirm->menu);
        confirm->menu = 0;
        if (answer == 1) {
            confirm->result = 2;
            confirm->state = CONFIRM_ABORTED;
        } else if (COMM_ENTRY_MENU_CountAcceptedMembers(menu) <= 1) {
            COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_QUIT_ALONE));
            confirm->state = CONFIRM_NOTIFY_ALONE;
        } else {
            COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_CONFIRM_QUIT_MEMBERS);
            confirm->state++;
        }
        break;
    case CONFIRM_OPEN_MENU_AGAIN:
        confirm->menu = FIELD_MSGBG_CreateYesNoMenu(FIELDMAP_GetMsgBg(menu->fieldMap), 0);
        confirm->state++;
        break;
    case CONFIRM_WAIT_ANSWER_AGAIN:
        answer = FIELD_MSGBG_YesNoMenuMain(confirm->menu);
        if (answer == 2) {
            break;
        }
        FIELD_MSGBG_DeleteMenuFunc(confirm->menu);
        confirm->menu = 0;
        if (answer == 0) {
            COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_QUIT_ALONE));
            confirm->state++;
        } else {
            confirm->result = 2;
            confirm->state = CONFIRM_ABORTED;
        }
        break;
    case CONFIRM_NOTIFY_ALONE:
        confirm->state = CONFIRM_FINISHED;
        confirm->result = 1;
        break;
    case CONFIRM_ABORTED:
        if (COMM_ENTRY_MENU_CountAcceptedMembers(menu) > 1 && menu->isChild == 1) {
            menu->nextMessage = COMM_ENTRY_MSG_MEMBERS_CAN_START;
        } else {
            menu->nextMessage = COMM_ENTRY_MSG_WAIT_FOR_MEMBERS;
        }
        confirm->state = CONFIRM_FINISHED;
        break;
    case CONFIRM_FINISHED:
        if (confirm->menu) {
            FIELD_MSGBG_DeleteMenuFunc(confirm->menu);
            confirm->menu = 0;
        }
        confirm->state = CONFIRM_ASK;
        return confirm->result;
    }
    return 0;
}


void COMM_ENTRY_MENU_MarkMemberReady(CommEntryMenu *menu, int netId)
{
    menu->readyBits |= 1 << netId;
}


void COMM_ENTRY_MENU_SetAcceptFlag(CommEntryMenu *menu)
{
    menu->acceptFlag = 1;
}


void COMM_ENTRY_MENU_SetCancelFlag(CommEntryMenu *menu)
{
    menu->cancelFlag = 1;
}


/* Marks the session as locked and the lock as not yet broadcast. */
void COMM_ENTRY_MENU_SetBusyFlags(CommEntryMenu *menu)
{
    menu->sessionLocked = 1;
    menu->lockNotifyPending = 1;
    GFL_NET_SetLoginOption(1);
}


int COMM_ENTRY_MENU_CountAcceptedMembers(CommEntryMenu *menu)
{
    int netId;
    int count = 0;
    for (netId = 0; netId < 4; netId++) {
        if (menu->members[netId].state == COMM_ENTRY_MEMBER_ACCEPTED)
            count++;
    }
    return count;
}


u32 COMM_ENTRY_MENU_GetAcceptedMask(CommEntryMenu *menu)
{
    u32 mask = 0;
    int netId;
    for (netId = 0; netId < 4; netId++) {
        if (menu->members[netId].state == COMM_ENTRY_MEMBER_ACCEPTED) {
            mask |= 1 << netId;
        }
    }
    return mask;
}


/* Emitted from the ov021 instruction shape. */
int COMM_ENTRY_MENU_IsIdle(CommEntryMenu *menu)
{
    if (menu->requestPending == 0) {
        if (FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            return 1;
        }
    }
    return 0;
}


void COMM_ENTRY_MENU_OpenWindows(CommEntryMenu *menu)
{
    FieldMsgBg *msgBg;
    int height;

    msgBg = FIELDMAP_GetMsgBg(menu->fieldMap);
    height = 0x10;
    if (menu->menuMode) {
        height = 0xe;
    }
    menu->memberWin = FIELD_MSGBG_CreateMsgWin(msgBg, menu->msgData, 2, 6, 0x12, height - 6);
    menu->titleWin = FIELD_MSGBG_CreateMsgWin(msgBg, menu->msgData, 2, 1, 0x1c, 2);
    FIELD_MSGBG_MsgWinPrintMsg(menu->titleWin, 0, 0, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_TITLE));
}


void COMM_ENTRY_MENU_CloseWindows(CommEntryMenu *menu)
{
    FieldMsgBg *msgBg = FIELDMAP_GetMsgBg(menu->fieldMap);
    if (menu->titleWin != 0) {
        FIELD_MSGBG_DeleteMsgWin(menu->titleWin);
        menu->titleWin = 0;
    }
    if (menu->memberWin != 0) {
        FIELD_MSGBG_DeleteMsgWin(menu->memberWin);
        menu->memberWin = 0;
    }
    FIELD_MSGBG_ClearPrintQue(msgBg);
}


int COMM_ENTRY_MENU_PrintRemaining(CommEntryMenu *menu, int count)
{
    if (menu->memberWin && FIELD_MSGBG_IsMsgWinTransDone(menu->memberWin) == 1) {
        FIELD_MSGBG_FillMsgWin(menu->memberWin, 0, 0x40, 0x90, 0x50);
        WORDSET_SetSlotNumber(menu->wordSet, 0, menu->maxMembers - count, 1, 0, 1);
        WORDSET_CopyTaggedText(menu->wordSet, menu->remainingStr, menu->remainingFormat);
        FIELD_MSGBG_MsgWinPrintStr(menu->memberWin, 0, 0x40, menu->remainingStr);
        return 1;
    }
    return 0;
}


void COMM_ENTRY_MENU_UpdateMemberName(CommEntryMenu *menu, CommEntryMember *member, int index)
{
    MacAddress *macs;
    macs = menu->memberMacs;
    if (GF_STANDARD_CompareBytes(member->mac, macs[index].b, 6)) {
        COMM_ENTRY_MENU_PrintMemberName(menu, member, (u8)index);
        MI_CpuCopy8(member->mac, macs[index].b, 6);
    }
}


void COMM_ENTRY_MENU_ClearMemberName(CommEntryMenu *menu, CommEntryMember *member, int index)
{
    if (GF_STANDARD_CompareBytes((u8 *)menu->memberMacs + index * 6, (u8 *)gCommEntryEmptyMac, 6)) {
        COMM_ENTRY_MENU_EraseMemberName(menu, index);
        MI_CpuCopy8(gCommEntryEmptyMac, menu->memberMacs[index].b, 6);
    }
}


/* Prints the name and trainer id of a member on row `row` of the member window. */
void COMM_ENTRY_MENU_PrintMemberName(CommEntryMenu *menu, const void *myStatus, u32 row)
{
    u32 trainerId;
    if (menu->memberWin != 0) {
        WORDSET_SetSlotMyStatus(menu->wordSet, 0, myStatus);
        trainerId = MYSTATUS_GetIdLow16((struct MyStatus *)myStatus);
        WORDSET_SetSlotNumber(menu->wordSet, 1, trainerId, 5, 2, 1);
        WORDSET_CopyTaggedText(menu->wordSet, menu->nameStr, menu->nameFormat);
        FIELD_MSGBG_MsgWinPrintStr(menu->memberWin, 0, (row & 0xfff) << 4, menu->nameStr);
    }
}


void COMM_ENTRY_MENU_EraseMemberName(CommEntryMenu *menu, u32 row)
{
    if (menu->memberWin != 0) {
        FIELD_MSGBG_FillMsgWin(menu->memberWin, 0, row << 4, 0x90, 0x10);
    }
}


void COMM_ENTRY_MENU_RefreshNames(CommEntryMenu *menu)
{
    int row;
    if (menu->namesDirty != 0) {
        menu->namesDirty = 0;
        for (row = 0; row < 4; row++) {
            COMM_ENTRY_MENU_EraseMemberName(menu, row);
            if (menu->roster.mask & (1 << row))
                COMM_ENTRY_MENU_PrintMemberName(menu, menu->roster.myStatus[row], (u8)row);
        }
    }
}


void COMM_ENTRY_MENU_PrintMessage(CommEntryMenu *menu, u32 msgId)
{
    struct Strbuf *format;
    if (msgId == COMM_ENTRY_MSG_WAIT_FOR_MEMBERS && menu->lastMessageId == COMM_ENTRY_MSG_WAIT_FOR_MEMBERS)
        return;
    menu->lastMessageId = msgId;
    format = MSGDATA_AllocString((struct MsgBank *)menu->msgData, msgId);
    WORDSET_CopyTaggedText(menu->wordSet, menu->msgStr, format);
    STRBUF_Delete(format);
    FIELD_MSGBG_ClearSysWin(menu->sysWin);
    FIELD_MSGBG_SysWinPrintStr(menu->sysWin, 0, 0, menu->msgStr);
}


void COMM_ENTRY_MENU_SnapshotStates(CommEntryMenu *menu)
{
    u8 netId;
    for (netId = 0; netId < 4; netId++) {
        menu->stateSnapshot[netId] = menu->members[netId].state;
    }
}


int COMM_ENTRY_MENU_StatesUnchanged(CommEntryMenu *menu)
{
    u8 netId;
    for (netId = 0; netId < 4; netId++) {
        if (menu->stateSnapshot[netId] != menu->members[netId].state) {
            return 0;
        }
    }
    return 1;
}


void COMM_ENTRY_MENU_ClearPendingBits(CommEntryMenu *menu, int index)
{
    menu->pendingAddBits &= 0xff ^ (1 << index);
    menu->pendingRemoveBits &= 0xff ^ (1 << index);
}


void COMM_ENTRY_MENU_QueueSend(CommEntryMenu *menu)
{
    if (menu->sendPending == 1 || menu->sendBusy == 1) {
        menu->sendQueued = 1;
    } else {
        menu->sendPending = 1;
        menu->sendQueued = 0;
    }
}


CommEntryMenu *COMM_ENTRY_MENU_AckSend(CommEntryMenu *menu)
{
    menu->sendBusy = 0;
    menu->sendPending = menu->sendQueued;
    menu->sendQueued = 0;
    return menu;
}


CommEntryRoster *COMM_ENTRY_MENU_GetNameBuffer(CommEntryMenu *menu)
{
    return &menu->roster;
}


void COMM_ENTRY_MENU_SetNameBuffer(CommEntryMenu *menu, const CommEntryRoster *roster)
{
    MI_CpuCopy8(roster, &menu->roster, sizeof(CommEntryRoster));
    menu->namesDirty = 1;
}


void COMM_ENTRY_MENU_StartYesNo(CommEntryMenu *menu)
{
    FieldMsgBg *msgBg;
    msgBg = FIELDMAP_GetMsgBg(menu->fieldMap);
    menu->parentList.items = FIELD_MSGBG_CreateMenuItems(0x10, menu->heapId);
    COMM_ENTRY_BuildParentItems(menu);
    menu->parentList.menu = (FieldMenuFunc *)FIELD_MSGBG_CreateMenuFunc(msgBg, &gCommEntryParentListHeader, menu->parentList.items);
    menu->parentList.state = 0;
}


void COMM_ENTRY_MENU_EndYesNo(CommEntryMenu *menu)
{
    if (menu->parentList.menu != 0) {
        FIELD_MSGBG_DeleteMenuFunc(menu->parentList.menu);
        menu->parentList.menu = 0;
        menu->parentList.itemsBuilt = 0;
    }
}


u32 COMM_ENTRY_MENU_MainYesNo(CommEntryMenu *menu)
{
    FieldMenuFunc **confirmMenu = &menu->confirm.menu;
    CommEntryParentList *list = &menu->parentList;
    u32 answer;
    switch (list->state) {
    case LIST_BROWSE:
        if (list->selected == 0) {
            COMM_ENTRY_TickParentTimeouts(menu);
            COMM_ENTRY_ScanParents(menu);
            if (COMM_ENTRY_PollParentList(menu) == 0) {
                list->result = LIST_RESULT_LEFT;
                list->state = LIST_FINISHED;
            } else if (menu->parentList.listDirty == 1) {
                COMM_ENTRY_BuildParentItems(menu);
                FIELD_MSGBG_RewriteMenuFunc(menu->parentList.menu);
                menu->parentList.listDirty = 0;
            }
        } else if (GFL_NET_SYSTEM_GetConnectNum() > 1) {
            if (GFL_NET_HANDLE_CheckNegotiation() == 1) {
                list->state++;
            }
        } else {
            if (KEY_GetTrg() & 2) {
                list->returnState = list->state;
                list->state = LIST_ASK_LEAVE;
            }
            (list->waitFrames)++;
            if (list->waitFrames >= 300) {
                list->state = LIST_SHOW_TIMEOUT;
                COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_LIST_TIMEOUT);
            }
        }
        break;
    case LIST_WAIT_NEGOTIATION:
        if (GFL_NET_HANDLE_IsNegotiationDone(GFL_NET_HANDLE_GetCurrentHandle()) == 1) {
            menu->joinReply = 0;
            if (COMM_ENTRY_SendJoinRequest(menu->myStatus, 0, menu->netMode) == 1) {
                list->state = LIST_WAIT_REPLY;
            }
        } else if (KEY_GetTrg() & 2) {
            list->returnState = list->state;
            list->state = LIST_ASK_LEAVE;
        }
        if (menu->cancelFlag == 1) {
            list->result = LIST_RESULT_JOINED;
            list->state = LIST_FINISHED;
        }
        break;
    case LIST_WAIT_REPLY:
        if (menu->joinReply == 1) {
            list->result = LIST_RESULT_JOINED;
            list->state = LIST_FINISHED;
        } else if (menu->joinReply == 2) {
            list->result = LIST_RESULT_REDIRECTED;
            list->state = LIST_FINISHED;
        } else if (KEY_GetTrg() & 2) {
            list->returnState = list->state;
            list->state = LIST_ASK_LEAVE;
        }
        if (menu->cancelFlag == 1) {
            list->result = LIST_RESULT_JOINED;
            list->state = LIST_FINISHED;
        }
        break;
    case LIST_FINISHED:
        return list->result;
    case LIST_ASK_LEAVE:
        COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_ASK_LEAVE);
        *confirmMenu = FIELD_MSGBG_CreateYesNoMenu(FIELDMAP_GetMsgBg(menu->fieldMap), 0);
        list->state = LIST_WAIT_LEAVE_ANSWER;
        break;
    case LIST_WAIT_LEAVE_ANSWER:
        answer = FIELD_MSGBG_YesNoMenuMain(*confirmMenu);
        if (FIELD_MSGBG_IsPrintQueFinished(FIELDMAP_GetMsgBg(menu->fieldMap)) == 1 && menu->sessionLocked == 1) {
            answer = 1;
        }
        if (answer == 2 && FIELD_MSGBG_IsPrintQueFinished(FIELDMAP_GetMsgBg(menu->fieldMap)) == 1) {
            if (menu->acceptFlag == 1 || menu->cancelFlag == 1) {
                FIELD_MSGBG_DeleteMenuFunc(*confirmMenu);
                *confirmMenu = 0;
                list->result = LIST_RESULT_JOINED;
                list->state = LIST_FINISHED;
            }
        } else {
            FIELD_MSGBG_DeleteMenuFunc(*confirmMenu);
            *confirmMenu = 0;
            if (answer == 1) {
                list->state = list->returnState;
                COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_LEAVE_REFUSED);
                if (menu->parentList.menu != 0) {
                    FIELD_MSGBG_DrawMenuFuncFrame(menu->parentList.menu);
                }
            } else {
                list->result = LIST_RESULT_LEFT;
                list->state = LIST_FINISHED;
            }
        }
        break;
    case LIST_SHOW_TIMEOUT:
        if (FIELD_MSGBG_SysWinMain(menu->sysWin) == 1) {
            list->result = LIST_RESULT_LEFT;
            list->state = LIST_FINISHED;
        }
        break;
    }
    return 0;
}

/* Polls the parent list menu; a chosen used slot becomes the selected parent. */
int COMM_ENTRY_PollParentList(CommEntryMenu *menu)
{
    CommEntryParentList *list = &menu->parentList;
    int choice;

    choice = FIELD_MSGBG_MenuFuncMain(list->menu);
    switch (choice) {
    case -2:
        return 0;
    case -1:
        break;
    default:
        if (list->slots[choice].used == 1) {
            list->selected = &list->slots[choice];
            GFL_NET_ConnectMacAddressChild(list->selected->mac);
            WORDSET_SetSlotMyStatus(menu->wordSet, 0, list->selected);
            COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_LEAVE_REFUSED);
            list->waitFrames = 0;
        }
        break;
    }
    return 1;
}

/* Counts the timeouts down; an expired parent slot is cleared. */
void COMM_ENTRY_TickParentTimeouts(CommEntryMenu *menu)
{
    CommEntryParentList *list = &menu->parentList;
    int i;

    for (i = 0; i < COMM_ENTRY_PARENT_SLOTS; i++) {
        if (list->slots[i].used == 1) {
            list->slots[i].timeout -= 1;
            if (list->slots[i].timeout <= 0) {
                COMM_ENTRY_ClearParentSlot(menu, i);
                list->listDirty = 1;
            }
        }
    }
}

/* Registers every beacon that advertises an open session as a parent. */
void COMM_ENTRY_ScanParents(CommEntryMenu *menu)
{
    int i;
    CommEntryBeaconData *beacon;

    for (i = 0; i < 0x10; i++) {
        beacon = (struct CommEntryBeaconData *)GFL_NET_GetScanResult(i);
        if (beacon != 0 && beacon->advertiseId == COMM_ENTRY_ADVERTISE_ID) {
            COMM_ENTRY_AddParent(menu, beacon->mac, beacon);
        }
    }
}

/* Refreshes the timeout of a known parent, or stores a new one in a free slot. */
void COMM_ENTRY_AddParent(CommEntryMenu *menu, u8 *mac, CommEntryBeaconData *beacon)
{
    CommEntryParentList *list = &menu->parentList;
    int i;

    for (i = 0; i < COMM_ENTRY_PARENT_SLOTS; i++) {
        if (list->slots[i].used == 1 && GF_STANDARD_CompareBytes(list->slots[i].mac, mac, 6) == 0) {
            list->slots[i].timeout = COMM_ENTRY_PARENT_TIMEOUT_FRAMES;
            return;
        }
    }
    for (i = 0; i < COMM_ENTRY_PARENT_SLOTS; i++) {
        if (list->slots[i].used == 0) {
            MI_CpuCopy8(mac, list->slots[i].mac, 6);
            MYSTATUS_Copy((struct MyStatus *)beacon, (struct MyStatus *)list->slots[i].myStatus);
            list->slots[i].timeout = COMM_ENTRY_PARENT_TIMEOUT_FRAMES;
            list->slots[i].used = 1;
            list->listDirty = 1;
            return;
        }
    }
}

void COMM_ENTRY_ClearParentSlot(CommEntryMenu *menu, int slotIndex)
{
    menu->parentList.slots[slotIndex].used = 0;
}

/* Rebuilds the item list of the parent menu from the 16 slots. */
void COMM_ENTRY_BuildParentItems(CommEntryMenu *menu)
{
    u16 emptyChar;
    struct Strbuf *line, *emptyFormat, *nameFormat, *emptyStr;
    int i;

    emptyChar = STRBUF_GetEosChar();
    if (menu->parentList.itemsBuilt == 1) {
        FIELD_MSGBG_DeleteMenuItems(menu->parentList.items);
    }
    emptyFormat = STRBUF_Create(0x40, menu->heapId);
    nameFormat = STRBUF_Create(0x40, menu->heapId);
    line = STRBUF_Create(0x40, menu->heapId);
    emptyStr = STRBUF_Create(4, menu->heapId);
    MSGDATA_ReadString((struct MsgBank *)menu->msgData, 0x1a, emptyFormat);
    MSGDATA_ReadString((struct MsgBank *)menu->msgData, 0x1b, nameFormat);
    for (i = 0; i < COMM_ENTRY_PARENT_SLOTS; i++) {
        WORDSET_SetSlotNumber(menu->wordSet, 0, i + 1, 2, 2, 1);
        if (menu->parentList.slots[i].used == 1) {
            WORDSET_SetSlotMyStatus(menu->wordSet, 1, &menu->parentList.slots[i]);
            WORDSET_SetSlotNumber(menu->wordSet, 2, MYSTATUS_GetIdLow16((struct MyStatus *)(&menu->parentList.slots[i])), 5, 2, 1);
            WORDSET_CopyTaggedText(menu->wordSet, line, nameFormat);
        } else {
            STRBUF_SetString(emptyStr, &emptyChar);
            WORDSET_SetSlotTag(menu->wordSet, 1, emptyStr, 0, 1, 2);
            WORDSET_SetSlotTag(menu->wordSet, 2, emptyStr, 0, 1, 2);
            WORDSET_CopyTaggedText(menu->wordSet, line, emptyFormat);
        }
        FIELD_MSGBG_AddMenuItemStr(menu->parentList.items, line, i, menu->heapId);
    }
    STRBUF_Delete(nameFormat);
    STRBUF_Delete(emptyFormat);
    STRBUF_Delete(line);
    STRBUF_Delete(emptyStr);
    menu->parentList.itemsBuilt = 1;
}

/* Runs the "leave the group?" dialog. Returns 2 when the player leaves, 1 while it is open, else 0. */
int COMM_ENTRY_RunLeaveConfirm(CommEntryMenu *menu)
{
    CommEntryConfirm *confirm = &menu->confirm;
    u32 answer;

    switch (confirm->state) {
    case 0:
        if (KEY_GetTrg() & 2) {
            confirm->menu = FIELD_MSGBG_CreateYesNoMenu(FIELDMAP_GetMsgBg(menu->fieldMap), 0);
            COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_ASK_LEAVE);
            confirm->state = 1;
        }
        break;
    case 1:
        answer = FIELD_MSGBG_YesNoMenuMain(confirm->menu);
        if (FIELD_MSGBG_IsPrintQueFinished(FIELDMAP_GetMsgBg(menu->fieldMap)) == 1 && menu->sessionLocked == 1)
            answer = 1;
        if (answer != 2) {
            FIELD_MSGBG_DeleteMenuFunc(confirm->menu);
            confirm->menu = 0;
            if (answer == 1) {
                confirm->state = 0;
                COMM_ENTRY_MENU_PrintMessage(menu, COMM_ENTRY_MSG_WAIT_IN_LOBBY);
            } else {
                return 2;
            }
        }
        return 1;
    }
    return 0;
}

void COMM_ENTRY_ResetLeaveConfirm(CommEntryMenu *menu)
{
    CommEntryConfirm *confirm = &menu->confirm;

    if (confirm->menu != 0) {
        FIELD_MSGBG_DeleteMenuFunc(confirm->menu);
        confirm->menu = 0;
    }
    confirm->state = 0;
}

/* Stores the join reply (1 accepted, 2 redirected) and the parent's MyStatus. */
void COMM_ENTRY_StoreJoinReply(CommEntryMenu *menu, u32 reply, const void *parentMyStatus)
{
    menu->joinReply = reply;
    MYSTATUS_Copy((struct MyStatus *)parentMyStatus, (struct MyStatus *)menu->parentMyStatus);
}

/* Size of the roster packet. */
u32 COMM_ENTRY_GetRosterSize(void)
{
    return sizeof(CommEntryRoster);
}

/* Returns 1 when a member other than this machine is set in mask and connected. */
int COMM_ENTRY_IsOtherMemberConnected(int mask)
{
    u8 i;
    for (i = 0; i < COMM_ENTRY_MAX_MEMBERS; i++) {
        if (i != GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle()) && ((1 << i) & mask) && GFL_NET_IsConnectMember(i) == 1) {
            return 1;
        }
    }
    return 0;
}

/* Starts the network command handling for the entry menu commands. */
void COMM_ENTRY_StartNetCommands(CommEntryMenu *menu)
{
    GFL_NET_COMMAND_AddCommandTable((u32)COMM_ENTRY_NET_HEAP, (u32)data_021DB4BC, (u32)COMM_ENTRY_CMD_COUNT, (u32)menu);
}

void COMM_ENTRY_EndNetCommands(void)
{
    GFL_NET_COMMAND_DeleteCommandTable(COMM_ENTRY_NET_HEAP);
}

/* Receive buffer of the roster command. */
CommEntryRoster *COMM_ENTRY_GetRosterBuffer(u32 netId, CommEntryMenu *menu)
{
    return COMM_ENTRY_MENU_GetNameBuffer(menu);
}

/* Receive of the join request: the packet holds MyStatus, MAC and the child flag. */
int COMM_ENTRY_RecvJoinRequest(u32 netId, u32 size, CommEntryJoinRequest *request, CommEntryMenu *menu)
{
    COMM_ENTRY_MENU_AddMember(menu, netId, request, request->isChild, request->mac);
}

/* Sends MyStatus to every machine (netMode 1) or to the parent; returns the send result when not netMode 1. */
u32 COMM_ENTRY_SendJoinRequest(const void *myStatus, u32 isChild, u32 netMode)
{
    CommEntryJoinRequest packet;

    MI_CpuFill8(&packet, 0, sizeof(CommEntryJoinRequest));
    MYSTATUS_Copy((struct MyStatus *)myStatus, (struct MyStatus *)(&packet));
    OS_GetMacAddress(packet.mac);
    packet.isChild = isChild;
    if (netMode == 1)
        GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), COMM_ENTRY_NET_ALL, COMM_ENTRY_CMD_JOIN_REQUEST, sizeof(CommEntryJoinRequest), &packet, 0, 0, 0);
    else
        return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, COMM_ENTRY_CMD_JOIN_REQUEST, sizeof(CommEntryJoinRequest), &packet, 0, 0, 0);
}

/* Receive of the join accept. */
void COMM_ENTRY_RecvJoinAccept(u32 netId, u32 size, const void *parentMyStatus, CommEntryMenu *menu)
{
    COMM_ENTRY_StoreJoinReply(menu, 1, parentMyStatus);
}

/* Sends the join accept with the parent's MyStatus to member index. */
u32 COMM_ENTRY_SendJoinAccept(u32 index, u32 netMode, const void *myStatus)
{
    GFLNetHandle *handle;

    if (netMode == 1) {
        handle = GFL_NET_HANDLE_GetNetHandle(COMM_ENTRY_NET_ALL);
        GFL_NET_SendData(handle, index, COMM_ENTRY_CMD_JOIN_ACCEPT, MYSTATUS_GetSize(), myStatus, 0, 0, 0);
    } else {
        handle = GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_SendData(handle, index, COMM_ENTRY_CMD_JOIN_ACCEPT, MYSTATUS_GetSize(), myStatus, 0, 0, 0);
    }
}

/* Receive of the join redirect. */
void COMM_ENTRY_RecvJoinRedirect(u32 netId, u32 size, const void *parentMyStatus, CommEntryMenu *menu)
{
    COMM_ENTRY_StoreJoinReply(menu, 2, parentMyStatus);
}

/* Sends the join redirect with the parent's MyStatus to member index. */
u32 COMM_ENTRY_SendJoinRedirect(u32 index, u32 netMode, const void *myStatus)
{
    GFLNetHandle *handle;

    if (netMode == 1) {
        handle = GFL_NET_HANDLE_GetNetHandle(COMM_ENTRY_NET_ALL);
        GFL_NET_SendData(handle, index, COMM_ENTRY_CMD_JOIN_REDIRECT, MYSTATUS_GetSize(), myStatus, 0, 0, 0);
    } else {
        handle = GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_SendData(handle, index, COMM_ENTRY_CMD_JOIN_REDIRECT, MYSTATUS_GetSize(), myStatus, 0, 0, 0);
    }
}

/* Receive of the session lock. */
void COMM_ENTRY_RecvSessionLock(u32 netId, u32 size, const void *data, CommEntryMenu *menu)
{
    COMM_ENTRY_MENU_SetBusyFlags(menu);
}

int COMM_ENTRY_SendSessionLock(int netMode)
{
    if (netMode == 1) {
        return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetNetHandle(COMM_ENTRY_NET_ALL), COMM_ENTRY_CMD_SESSION_LOCK, 0, 0);
    } else {
        return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), COMM_ENTRY_CMD_SESSION_LOCK, 0, 0);
    }
}

/* Receive of the ready message: marks the sender in readyBits. */
void COMM_ENTRY_RecvReady(u32 netId, u32 size, const void *data, CommEntryMenu *menu)
{
    COMM_ENTRY_MENU_MarkMemberReady(menu, (u8)netId);
}

u32 COMM_ENTRY_SendReady(u32 netMode)
{
    if (netMode == 1)
        GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), COMM_ENTRY_NET_ALL, COMM_ENTRY_CMD_READY, 0, 0, 0, 0, 0);
    else
        return GFL_NET_SendData(GFL_NET_HANDLE_GetCurrentHandle(), 0, COMM_ENTRY_CMD_READY, 0, 0, 0, 0, 0);
}

/* Receive of the accept message. */
void COMM_ENTRY_RecvAccept(u32 netId, u32 size, const void *data, CommEntryMenu *menu)
{
    COMM_ENTRY_MENU_SetAcceptFlag(menu);
}

int COMM_ENTRY_SendAccept(int netMode)
{
    if (netMode == 1) {
        return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetNetHandle(COMM_ENTRY_NET_ALL), COMM_ENTRY_CMD_ACCEPT, 0, 0);
    } else {
        return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), COMM_ENTRY_CMD_ACCEPT, 0, 0);
    }
}

/* Receive of the cancel message. */
void COMM_ENTRY_RecvCancel(u32 netId, u32 size, const void *data, CommEntryMenu *menu)
{
    COMM_ENTRY_MENU_SetCancelFlag(menu);
}

int COMM_ENTRY_SendCancel(int netMode)
{
    if (netMode == 1) {
        return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetNetHandle(COMM_ENTRY_NET_ALL), COMM_ENTRY_CMD_CANCEL, 0, 0);
    } else {
        return GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(), COMM_ENTRY_CMD_CANCEL, 0, 0);
    }
}

/* Receive of the roster: the parent only returns the menu, a child stores the roster. */
int COMM_ENTRY_RecvRoster(u32 netId, u32 size, const CommEntryRoster *roster, CommEntryMenu *menu)
{
    if (GFL_NET_IsParentAid() == 1) {
        return (int)COMM_ENTRY_MENU_AckSend(menu);
    }
    COMM_ENTRY_MENU_SetNameBuffer(menu, roster);
}

/* Sends the roster to every machine (netMode 1) or to the parent. */
u32 COMM_ENTRY_SendRoster(const CommEntryRoster *roster, u32 recipients, int netMode)
{
    GFLNetHandle *handle;

    if (netMode == 1) {
        handle = GFL_NET_HANDLE_GetNetHandle(COMM_ENTRY_NET_ALL);
        GFL_NET_SendDataMask(handle, recipients, COMM_ENTRY_CMD_ROSTER, COMM_ENTRY_GetRosterSize(), roster, 0, 0, 1);
    } else {
        handle = GFL_NET_HANDLE_GetCurrentHandle();
        GFL_NET_SendDataMask(handle, recipients, COMM_ENTRY_CMD_ROSTER, COMM_ENTRY_GetRosterSize(), roster, 0, 0, 1);
    }
}
