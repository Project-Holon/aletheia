/*
 * file:     comm_entry_menu.c
 * unit:     yes
 * function: func_021CD48C, func_021CD5A4, func_021CD60C, func_021CD624, func_021CD688, func_021CD6D0, func_021CDAB8, func_021CDD5C, func_021CDF18, func_021CE12C, func_021CE1F4, func_021CE24C, func_021CE2BC, func_021CE36C, func_021CE3D8, func_021CE3E8, func_021CE41C, func_021CE52C, func_021CE5AC, func_021CE6F0, func_021CE70C, func_021CE718, func_021CE724, func_021CE73C, func_021CE760, func_021CE78C, func_021CE7AC, func_021CE81C, func_021CE84C, func_021CE8B0, func_021CE8F4, func_021CE934, func_021CE984, func_021CE9A0, func_021CE9E4, func_021CEA28, func_021CEA50, func_021CEA84, func_021CEAB0, func_021CEADC, func_021CEAF8, func_021CEB04, func_021CEB20, func_021CEB64, func_021CEB84, func_021CEDA0, func_021CEE00, func_021CEE48, func_021CEE78, func_021CEF08, func_021CEF1C, func_021CF068, func_021CF0F4, func_021CF110, func_021CF128, func_021CF12C, func_021CF164, func_021CF17C, func_021CF188, func_021CF194, func_021CF1AC, func_021CF214, func_021CF220, func_021CF27C, func_021CF288, func_021CF2E4, func_021CF2F0, func_021CF31C, func_021CF32C, func_021CF36C, func_021CF378, func_021CF3A4, func_021CF3B0, func_021CF3DC, func_021CF3FC
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
 *   func_020457B0  0x020457B0  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02190740  0x02190740  thumb  ov021
 *   func_02045808  0x02045808  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_0201EC64  0x0201EC64  thumb
 *   func_021904B0  0x021904B0  thumb  ov021
 *   func_02190F64  0x02190F64  thumb  ov021
 *   func_02045EC0  0x02045EC0  arm
 *   func_02008494  0x02008494  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_021CF164  0x021CF164  thumb  ov021
 *   func_0203D798  0x0203D798  arm
 *   func_0203D650  0x0203D650  arm
 *   d_021DE5E8     0x021DE5E8  data   ov021  a1
 *   func_021909BC  0x021909BC  thumb  ov021
 *   func_02190E40  0x02190E40  thumb  ov021
 *   func_021904C8  0x021904C8  thumb  ov021
 *   func_0201ED04  0x0201ED04  thumb
 *   func_0203CD98  0x0203CD98  arm
 *   func_021CF17C  0x021CF17C  thumb  ov021
 *   d_021DB498  0x021DB498  data
 *   func_021CF1AC  0x021CF1AC  thumb  ov021
 *   func_021CF2F0  0x021CF2F0  thumb  ov021
 *   func_021CF3B0  0x021CF3B0  thumb  ov021
 *   func_021CF378  0x021CF378  thumb  ov021
 *   func_02190EF0  0x02190EF0  thumb  ov021
 *   func_021CF12C  0x021CF12C  thumb  ov021
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0203D01C  0x0203D01C  arm
 *   func_020392B8  0x020392B8  arm
 *   func_02039ACC  0x02039ACC  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_020399B8  0x020399B8  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_02080D24  0x02080D24  arm
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_0203D010  0x0203D010  arm
 *   func_0201F02C  0x0201F02C  thumb
 *   func_021CF068  0x021CF068  thumb  ov021
 *   func_021CF0F4  0x021CF0F4  thumb  ov021
 *   func_021CF32C  0x021CF32C  thumb  ov021
 *   func_0203CEAC  0x0203CEAC  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   func_021CF220  0x021CF220  thumb  ov021
 *   func_021CF288  0x021CF288  thumb  ov021
 *   func_021CF3FC  0x021CF3FC  thumb  ov021
 *   func_02190BE4  0x02190BE4  thumb  ov021
 *   func_02190C78  0x02190C78  thumb  ov021
 *   func_02190708  0x02190708  thumb  ov021
 *   func_02190490  0x02190490  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02190794  0x02190794  thumb  ov021
 *   func_02190758  0x02190758  thumb  ov021
 *   func_0203EFC8  0x0203EFC8  arm
 *   d_021DB470     0x021DB470  data  a4
 *   func_02008534  0x02008534  thumb
 *   func_02190F7C  0x02190F7C  thumb  ov021
 *   func_02190EB8  0x02190EB8  thumb  ov021
 *   func_02190A20  0x02190A20  thumb  ov021
 *   func_021CEF1C  0x021CEF1C  thumb  ov021
 *   func_0219097C  0x0219097C  thumb  ov021
 *   d_021DB478     0x021DB478  data  a4
 *   func_021CEE00  0x021CEE00  thumb  ov021
 *   func_021CEE48  0x021CEE48  thumb  ov021
 *   func_021CEDA0  0x021CEDA0  thumb  ov021
 *   func_02190A14  0x02190A14  thumb  ov021
 *   func_0219049C  0x0219049C  thumb  ov021
 *   func_02190B1C  0x02190B1C  thumb  ov021
 *   func_021909E4  0x021909E4  thumb  ov021
 *   func_0203D000  0x0203D000  arm
 *   func_021CE9E4  0x021CE9E4  thumb  ov021
 *   func_0203CF10  0x0203CF10  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02190A6C  0x02190A6C  thumb  ov021
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045924  0x02045924  arm
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02190A64  0x02190A64  thumb  ov021
 *   func_0203A574  0x0203A574  arm
 *   data_021DB4BC  0x021DB4BC  data
 *   func_0203A5E4  0x0203A5E4  arm
 *   func_021CEAF8  0x021CEAF8  thumb  ov021
 *   func_021CD624  0x021CD624  thumb  ov021
 *   func_02082BCC  0x02082BCC  arm
 *   func_02087C6C  0x02087C6C  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_0203996C  0x0203996C  arm
 *   func_02008468  0x02008468  thumb
 *   func_021CE724  0x021CE724  thumb  ov021
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_021CE6F0  0x021CE6F0  thumb  ov021
 *   func_021CE70C  0x021CE70C  thumb  ov021
 *   func_021CE718  0x021CE718  thumb  ov021
 *   func_0203D378  0x0203D378  arm
 *   func_021CEADC  0x021CEADC  thumb  ov021
 *   func_021CEB04  0x021CEB04  thumb  ov021
 *   func_0203D4D0  0x0203D4D0  arm
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

/* Columns of the message table d_021DB498, one row per isChild value. */
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
 * the table: d_021DB498[isChild][col] folds the column into the pool address
 * and changes the bytes.
 */
#define COMM_ENTRY_MSG(isChild, col) (*(const u16 *)((const u8 *)d_021DB498 + (isChild) * 12 + (col) * 2))

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

extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *ws, u32 slot, u32 number, u32 digits, u32 dispType, u32 charCode);
extern void func_0201F250(struct WordSet *ws, struct Strbuf *dst, struct Strbuf *format);
extern int func_02190740(FieldMsgWin *msgWin, int x, int y, u32 msgId);
extern void func_02045808(struct Strbuf *str);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern FieldMsgBg *func_02188C54(struct FieldMap *fieldMap);
extern struct WordSet *func_0201EC64(u32 heapId);
extern struct MsgData *func_021904B0(FieldMsgBg *msgBg, u32 fileId);
extern FieldSysWin *func_02190F64(FieldMsgBg *msgBg, struct MsgData *msgData);
extern struct Strbuf *func_02045EC0(struct MsgData *msgData, u32 msgId);
extern void func_02008494(const void *myStatus, void *dst);
extern void func_02082D44(const void *src, void *dst, u32 n);
extern void func_0203D7BC(u8 a0);
extern GFLNetInitializeStruct *func_0203D798(void);
extern u32 func_0203D650(void);
extern int func_021909BC(FieldMenuFunc *menu);
extern int func_02190E40(FieldSysWin *sysWin);
extern u32 func_021904C8(struct MsgData *msgData);
extern u32 func_0201ED04(struct WordSet *ws);
extern int func_0203CD98(void);
extern void func_0203D01C(void);
extern int func_020392B8(void);
extern int func_02039ACC(void);
extern u32 func_020362DC(void);
extern GFLNetHandle *func_020399A8(void);
extern u32 func_020399B8(GFLNetHandle *handle);
extern int func_0203D1B4(void);
extern void func_0203D1E8(GFLNetHandle *handle, void *arg);
extern u32 func_0203D1A4(GFLNetHandle *handle);
extern u32 func_0203D1C0(u32 netId);
extern u32 func_02080D24(int bits);
extern void func_02039C68(GFLNetHandle *handle, unsigned int timingNo, unsigned int range);
extern unsigned int func_02039CB4(GFLNetHandle *handle, unsigned int timingNo, unsigned int range);
extern u32 func_02190EF0(FieldSysWin *sysWin);
extern u32 func_0200FB24(void);
extern void func_0203D010(void);
extern void func_0201F02C(struct WordSet *ws, u32 slot, const void *myStatus);
extern int func_0203CEAC(int a0);
extern int func_0203CDBC(void);
extern void func_0203CBAC(GFLNetInitializeStruct *init, u32 a2, u32 userArg);
extern FieldMenuFunc *func_02190BE4(FieldMsgBg *msgBg, u32 cursorPos);
extern int func_02190C78(FieldMenuFunc *menu);
extern FieldMsgWin *func_02190708(FieldMsgBg *msgBg, struct MsgData *msgData, u16 x, u16 y, u16 width, u16 height);
extern int func_02190728(FieldMsgWin *msgWin);
extern void func_02190490(FieldMsgBg *msgBg);
extern int func_0219077C(FieldMsgWin *msgWin);
extern void func_02190794(FieldMsgWin *msgWin, int x, int y, int width, int height);
extern void func_02190758(FieldMsgWin *msgWin, int x, int y, struct Strbuf *str);
extern int func_0203EFC8(const void *a, const void *b, int n);
extern u16 func_02008534(const void *myStatus);
extern void func_02190F7C(FieldSysWin *sysWin);
extern void func_02190EB8(FieldSysWin *sysWin, u32 x, u16 y, struct Strbuf *str);
extern struct BmpMenuWork *func_02190A20(int count, u16 heapId);
extern u32 func_0219097C(FieldMsgBg *msgBg, const FieldMenuHeader *header, struct BmpMenuWork *items);
extern void func_02190A14(FieldMenuFunc *menu);
extern int func_0219049C(FieldMsgBg *msgBg);
extern int func_02190B1C(FieldMenuFunc *menu);
extern u16 func_02045A98(void);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0203A5E4(u32 v);
extern int func_02008468(void);
extern u32 func_0203D378(void);
extern int func_021909E4(FieldMenuFunc *menu);
extern void func_0203D000(const u8 *mac);
extern CommEntryBeaconData *func_0203CF10(u32 index);
extern void func_02190A6C(struct BmpMenuWork *items);
extern void func_02045CAC(struct MsgData *msgData, u32 messageId, struct Strbuf *dest);
extern int func_02190A64(struct BmpMenuWork *items, struct Strbuf *text, u32 value, u32 heapId);
extern GFLNetHandle *func_0203996C(s32 id);
extern void func_0203A574(u32 heapId, const void *commandTable, u32 commandCount, void *work);
extern void func_02082BCC();
extern void func_02087C6C(void *p);
extern u32 func_0203D3F8(GFLNetHandle *handle, u32 sendId, u32 command, u32 size, const void *data, u32 a, u32 b, u32 c);
extern u32 func_0203D4D0(GFLNetHandle *handle, u32 recipients, u32 command, u32 size, const void *data, u32 a, u32 b, u32 c);
extern int func_0203D3A8(GFLNetHandle *handle, u32 command, u32 a, u32 b);

CommEntryMenu *func_021CD48C(struct MyStatus *myStatus, struct FieldMap *fieldMap, u32 minMembers, u32 maxMembers, u32 heapId, u32 menuMode, u32 isChild, const u8 *mac);
u32 func_021CD5A4(CommEntryMenu *menu);
void func_021CD60C(CommEntryMenu *menu, void *work, CommEntryMemberFunc onAdd, CommEntryMemberFunc onRemove);
void func_021CD624(CommEntryMenu *menu, int netId, const void *myStatus, u32 autoAccept, const u8 *mac);
u32 func_021CD688(CommEntryMenu *menu);
int func_021CD6D0(CommEntryMenu *menu);
int func_021CDAB8(CommEntryMenu *menu);
int func_021CDD5C(CommEntryMenu *menu);
int func_021CDF18(CommEntryMenu *menu);
void func_021CE12C(CommEntryMenu *menu);
u8 func_021CE1F4(CommEntryMenu *menu);
void func_021CE24C(CommEntryMenu *menu);
void func_021CE2BC(CommEntryMenu *menu);
void func_021CE36C(CommEntryMenu *menu);
void func_021CE3D8(CommEntryMenu *menu, int index);
int func_021CE3E8(CommEntryMenu *menu, CommEntryMember *member);
void func_021CE41C(CommEntryMenu *menu);
int func_021CE52C(CommEntryMenu *menu);
u32 func_021CE5AC(CommEntryMenu *menu);
void func_021CE6F0(CommEntryMenu *menu, int netId);
void func_021CE70C(CommEntryMenu *menu);
void func_021CE718(CommEntryMenu *menu);
void func_021CE724(CommEntryMenu *menu);
int func_021CE73C(CommEntryMenu *menu);
u32 func_021CE760(CommEntryMenu *menu);
int func_021CE78C(CommEntryMenu *menu);
void func_021CE7AC(CommEntryMenu *menu);
void func_021CE81C(CommEntryMenu *menu);
int func_021CE84C(CommEntryMenu *menu, int count);
void func_021CE8B0(CommEntryMenu *menu, CommEntryMember *member, int index);
void func_021CE8F4(CommEntryMenu *menu, CommEntryMember *member, int index);
void func_021CE934(CommEntryMenu *menu, const void *myStatus, u32 row);
void func_021CE984(CommEntryMenu *menu, u32 row);
void func_021CE9A0(CommEntryMenu *menu);
void func_021CE9E4(CommEntryMenu *menu, u32 msgId);
void func_021CEA28(CommEntryMenu *menu);
int func_021CEA50(CommEntryMenu *menu);
void func_021CEA84(CommEntryMenu *menu, int index);
void func_021CEAB0(CommEntryMenu *menu);
CommEntryMenu *func_021CEADC(CommEntryMenu *menu);
CommEntryRoster *func_021CEAF8(CommEntryMenu *menu);
void func_021CEB04(CommEntryMenu *menu, const CommEntryRoster *roster);
void func_021CEB20(CommEntryMenu *menu);
void func_021CEB64(CommEntryMenu *menu);
u32 func_021CEB84(CommEntryMenu *menu);
int func_021CEDA0(CommEntryMenu *menu);
void func_021CEE00(CommEntryMenu *menu);
void func_021CEE48(CommEntryMenu *menu);
void func_021CEE78(CommEntryMenu *menu, u8 *mac, CommEntryBeaconData *beacon);
void func_021CEF08(CommEntryMenu *menu, int slotIndex);
void func_021CEF1C(CommEntryMenu *menu);
int func_021CF068(CommEntryMenu *menu);
void func_021CF0F4(CommEntryMenu *menu);
void func_021CF110(CommEntryMenu *menu, u32 reply, const void *parentMyStatus);
u32 func_021CF128(void);
int func_021CF12C(int mask);
void func_021CF164(CommEntryMenu *menu);
void func_021CF17C(void);
CommEntryRoster *func_021CF188(u32 netId, CommEntryMenu *menu);
int func_021CF194(u32 netId, u32 size, CommEntryJoinRequest *request, CommEntryMenu *menu);
u32 func_021CF1AC(const void *myStatus, u32 isChild, u32 netMode);
void func_021CF214(u32 netId, u32 size, const void *parentMyStatus, CommEntryMenu *menu);
u32 func_021CF220(u32 index, u32 netMode, const void *myStatus);
void func_021CF27C(u32 netId, u32 size, const void *parentMyStatus, CommEntryMenu *menu);
u32 func_021CF288(u32 index, u32 netMode, const void *myStatus);
void func_021CF2E4(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
int func_021CF2F0(int netMode);
void func_021CF31C(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
u32 func_021CF32C(u32 netMode);
void func_021CF36C(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
int func_021CF378(int netMode);
void func_021CF3A4(u32 netId, u32 size, const void *data, CommEntryMenu *menu);
int func_021CF3B0(int netMode);
int func_021CF3DC(u32 netId, u32 size, const CommEntryRoster *roster, CommEntryMenu *menu);
u32 func_021CF3FC(const CommEntryRoster *roster, u32 recipients, int netMode);

extern const char d_021DE5E8[];
extern const u8 data_021DB4BC[];
extern const u16 d_021DB498[2][6];
extern const u8 d_021DB470[6];
extern const FieldMenuHeader d_021DB478;


CommEntryMenu *func_021CD48C(struct MyStatus *myStatus, struct FieldMap *fieldMap, u32 minMembers, u32 maxMembers, u32 heapId, u32 menuMode, u32 isChild, const u8 *mac)
{
    FieldMsgBg *msgBg;
    CommEntryMenu *menu;
    GFLNetInitializeStruct *netInit;

    msgBg = func_02188C54(fieldMap);
    menu = func_02030734(heapId, sizeof(CommEntryMenu), 1, d_021DE5E8, 0x179);
    menu->wordSet = func_0201EC64(heapId);
    menu->msgData = func_021904B0(msgBg, 0x1e);
    menu->sysWin = func_02190F64(msgBg, menu->msgData);
    menu->msgStr = func_020457B0(0x64, heapId);
    menu->nameFormat = func_02045EC0(menu->msgData, 7);
    menu->nameStr = func_020457B0(0x40, heapId);
    if (isChild == 1) {
        menu->remainingFormat = func_02045EC0(menu->msgData, 3);
    } else {
        menu->remainingFormat = func_02045EC0(menu->msgData, 2);
    }
    menu->remainingStr = func_020457B0(0x20, heapId);
    menu->minMembers = minMembers;
    menu->maxMembers = maxMembers;
    menu->fieldMap = fieldMap;
    menu->menuMode = menuMode;
    menu->isChild = isChild;
    menu->heapId = heapId;
    menu->memberCount = -1;
    menu->nextMessage = 0xffff;
    func_02008494(myStatus, menu->myStatus);
    if (mac != 0) {
        func_02082D44(mac, menu->ownMac, 6);
    }
    func_0203D7BC(0);
    func_021CF164(menu);
    if (isChild == 1) {
        menu->netMode = 1;
    }
    netInit = func_0203D798();
    ((CommEntryBeaconData *)netInit->getBeaconDataFunc((void *)func_0203D650()))->advertiseId = COMM_ENTRY_ADVERTISE_ID;
    return menu;
}


u32 func_021CD5A4(CommEntryMenu *menu)
{
    u32 acceptedMask;

    acceptedMask = func_021CE760(menu);
    func_021CE81C(menu);
    if (menu->confirm.menu) {
        func_021909BC(menu->confirm.menu);
        menu->confirm.menu = 0;
    }
    func_02045808(menu->remainingStr);
    func_02045808(menu->remainingFormat);
    func_02045808(menu->nameStr);
    func_02045808(menu->nameFormat);
    func_02045808(menu->msgStr);
    func_02190E40(menu->sysWin);
    func_021904C8(menu->msgData);
    func_0201ED04(menu->wordSet);
    if (func_0203CD98() == 1) {
        func_021CF17C();
    }
    func_020307B0(menu);
    return acceptedMask;
}


void func_021CD60C(CommEntryMenu *menu, void *work, CommEntryMemberFunc onAdd, CommEntryMemberFunc onRemove)
{
    menu->callbackWork = work;
    menu->onAdd = onAdd;
    menu->onRemove = onRemove;
}


void func_021CD624(CommEntryMenu *menu, int netId, const void *myStatus, u32 autoAccept, const u8 *mac)
{
    CommEntryMember *member;

    member = &menu->members[netId];
    func_02008494(myStatus, member);
    member->state = COMM_ENTRY_MEMBER_JOINED;
    member->autoAccept = autoAccept;
    func_02082D44(mac, member->mac, 6);
    func_021CEA84(menu, (u8)netId);
    func_021CEAB0(menu);
    if (menu->onAdd) {
        menu->onAdd(menu->callbackWork, myStatus, mac);
    }
}


u32 func_021CD688(CommEntryMenu *menu)
{
    int done;

    switch (menu->menuMode) {
    case COMM_ENTRY_MODE_RECRUIT:
        done = func_021CD6D0(menu);
        break;
    case COMM_ENTRY_MODE_CHOOSE:
        done = func_021CDAB8(menu);
        break;
    case COMM_ENTRY_MODE_HOST:
        done = func_021CDD5C(menu);
        break;
    case COMM_ENTRY_MODE_JOIN:
        done = func_021CDF18(menu);
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
int func_021CD6D0(CommEntryMenu *menu)
{
    int count;
    u16 pendingMessage;
    u8 repliedMask;
    u8 netId;

    if (menu->state != 0) {
        func_021CE24C(menu);
        func_021CE2BC(menu);
        func_021CE12C(menu);
    }

    switch (menu->state) {
    case RECRUIT_OPEN:
        func_021CE7AC(menu);
        func_021CE9E4(menu, COMM_ENTRY_MSG_WAIT_FOR_MEMBERS);
        menu->state++;
        break;
    case RECRUIT_CHECK_ROLE:
        if (menu->isChild == 0) {
            menu->state = RECRUIT_REGISTER_SELF;
        } else {
            func_0203D01C();
            menu->state++;
        }
        break;
    case RECRUIT_WAIT_CONNECT:
        if (func_020392B8() > 1) {
            if (func_02039ACC() == 1) {
                menu->state++;
            }
        } else if (func_020362DC() & 2) {
            menu->state = RECRUIT_CONFIRM_QUIT;
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = RECRUIT_DONE;
        }
        break;
    case RECRUIT_WAIT_NEGOTIATION:
        if (func_020399B8(func_020399A8()) == 1) {
            menu->state = RECRUIT_REGISTER_SELF;
        }
        break;
    case RECRUIT_REGISTER_SELF:
        if (func_021CF1AC(menu->myStatus, 1, menu->netMode) == 1) {
            menu->state++;
        }
        break;
    case RECRUIT_COLLECT:
        func_021CE36C(menu);
        func_021CE41C(menu);
        if (func_021CE78C(menu) == 1) {
            count = func_021CE73C(menu);
            pendingMessage = menu->nextMessage;
            menu->nextMessage = 0xFFFF;
            if (count >= menu->maxMembers || (count >= menu->minMembers && (func_020362DC() & 1))) {
                func_021CEA28(menu);
                menu->state = RECRUIT_CONFIRM_START;
            } else if (func_020362DC() & 2) {
                menu->state = RECRUIT_CONFIRM_QUIT;
            } else if (menu->isChild == 0 && func_0203D1B4() <= 1) {
                menu->state = RECRUIT_SHOW_ALONE_MESSAGE;
            } else if (pendingMessage != 0xFFFF) {
                func_021CE9E4(menu, pendingMessage);
            }
        }
        break;
    case RECRUIT_CONFIRM_START:
        count = func_021CE52C(menu);
        if (count == 1) {
            func_0203D1E8(func_020399A8(), 0);
            menu->state = RECRUIT_SEND_READY_REQUEST;
        } else if (count == 2) {
            if (func_021CE73C(menu) >= menu->maxMembers) {
                menu->state = RECRUIT_CONFIRM_QUIT;
            } else {
                menu->state = RECRUIT_COLLECT;
                if (func_021CE73C(menu) > 1 && menu->isChild == 1) {
                    menu->nextMessage = COMM_ENTRY_MSG_MEMBERS_CAN_START;
                } else {
                    menu->nextMessage = COMM_ENTRY_MSG_WAIT_FOR_MEMBERS;
                }
            }
        }
        break;
    case RECRUIT_CONFIRM_QUIT:
        count = func_021CE5AC(menu);
        if (count == 1) {
            func_0203D1E8(func_020399A8(), 0);
            menu->state = RECRUIT_SEND_QUIT;
        } else if (count == 2) {
            menu->state = RECRUIT_COLLECT;
        }
        break;
    case RECRUIT_SEND_READY_REQUEST:
        if (func_021CF2F0(menu->netMode) == 1) {
            func_021CE6F0(menu, func_0203D1A4(func_020399A8()));
            menu->readyMask = menu->roster.mask;
            func_0203D7BC(1);
            menu->state = RECRUIT_WAIT_READY;
        }
        break;
    case RECRUIT_WAIT_READY:
        repliedMask = 1 << func_0203D1A4(func_020399A8());
        for (netId = 0; (netId < 4) ? 1 : 0; netId++) {
            if (netId != func_0203D1A4(func_020399A8()) && (menu->readyMask & (1u << netId))) {
                if (func_0203D1C0(netId) == 1) {
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
            if (func_02080D24(menu->readyBits) < menu->minMembers) {
                menu->state = RECRUIT_SEND_ABORT;
            } else {
                menu->state = RECRUIT_SEND_START;
            }
        }
        break;
    case RECRUIT_SEND_ABORT:
        if (func_021CF3B0(menu->netMode) == 1) {
            menu->readyMask = menu->roster.mask;
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = RECRUIT_SHOW_ABORT_MESSAGE;
        }
        break;
    case RECRUIT_SEND_START:
        if (func_021CF378(menu->netMode) == 1) {
            menu->result = COMM_ENTRY_RESULT_START;
            menu->state = RECRUIT_WAIT_START_SYNC;
            menu->readyCount = func_02080D24(menu->readyBits);
            func_02039C68(func_020399A8(), 1, 0x27);
        }
        break;
    case RECRUIT_WAIT_START_SYNC:
        if (menu->readyCount != func_020392B8() || menu->minMembers > func_020392B8()) {
            if (func_021CF3B0(menu->netMode) == 1) {
                menu->readyMask = menu->roster.mask;
                menu->result = COMM_ENTRY_RESULT_CANCEL;
                menu->state = RECRUIT_SHOW_ABORT_MESSAGE;
            }
        } else if (func_02039CB4(func_020399A8(), 1, 0x27) == 1) {
            GFLNetInitializeStruct *netInit;

            menu->result = COMM_ENTRY_RESULT_START;
            menu->state = RECRUIT_DONE;
            netInit = func_0203D798();
            ((CommEntryBeaconData *)netInit->getBeaconDataFunc((void *)func_0203D650()))->advertiseId = 0;
        }
        break;
    case RECRUIT_SEND_QUIT:
        if (func_021CF3B0(menu->netMode) == 1) {
            menu->readyMask = menu->roster.mask;
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = RECRUIT_WAIT_QUIT_SENT;
        }
        break;
    case RECRUIT_SHOW_ABORT_MESSAGE:
        {
            const u16 *row = d_021DB498[menu->isChild];

            func_021CE9E4(menu, row[COMM_ENTRY_MSGCOL_ABORT]);
        }
        menu->state = RECRUIT_WAIT_ABORT_MESSAGE;
        break;
    case RECRUIT_WAIT_ABORT_MESSAGE:
        if (func_02190EF0(menu->sysWin) == 1) {
            menu->state = RECRUIT_WAIT_QUIT_SENT;
        }
        break;
    case RECRUIT_WAIT_QUIT_SENT:
        if (func_021CF12C(menu->readyMask) == 0) {
            menu->state = RECRUIT_DONE;
        }
        break;
    case RECRUIT_SHOW_ALONE_MESSAGE:
        func_021CE9E4(menu, COMM_ENTRY_MSG_NO_MEMBERS);
        menu->state = RECRUIT_WAIT_ALONE_MESSAGE;
        break;
    case RECRUIT_WAIT_ALONE_MESSAGE:
        if (func_02190EF0(menu->sysWin) == 1) {
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = RECRUIT_DONE;
        }
        break;
    case RECRUIT_DONE:
        func_021CE81C(menu);
        return 1;
    }

    if (func_0200FB24() != 0) {
        menu->result = COMM_ENTRY_RESULT_NET_ERROR;
        return 1;
    }
    return 0;
}


int func_021CDAB8(CommEntryMenu *menu)
{
    switch (menu->state) {
    case CHOOSE_SHOW_OPEN_MESSAGE:
        func_021CE9E4(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_OPEN));
        menu->state++;
        break;
    case CHOOSE_WAIT_OPEN_MESSAGE:
        if (func_02190EF0(menu->sysWin) == 1) {
            menu->state++;
        }
        break;
    case CHOOSE_OPEN_LIST:
        func_021CEB64(menu);
        func_021CE81C(menu);
        menu->parentList.selected = 0;
        func_021CEB20(menu);
        func_0203D010();
        menu->state++;
        break;
    case CHOOSE_RUN_LIST:
        switch (func_021CEB84(menu)) {
        case LIST_RESULT_JOINED:
            func_021CEB64(menu);
            if (menu->acceptFlag == 1) {
                menu->state = CHOOSE_ACCEPTED;
            } else if (menu->cancelFlag == 1) {
                menu->state = CHOOSE_SHOW_CANCEL_MESSAGE;
            } else {
                func_0201F02C(menu->wordSet, 0, menu->parentList.selected);
                func_021CE9E4(menu, COMM_ENTRY_MSG_JOINED);
                menu->state = CHOOSE_WAIT_JOINED_MESSAGE;
            }
            break;
        case LIST_RESULT_REDIRECTED:
            func_021CEB64(menu);
            menu->state = CHOOSE_SWITCH_BEGIN;
            break;
        case LIST_RESULT_LEFT:
            func_021CEB64(menu);
            menu->state = CHOOSE_CANCELLED;
            break;
        }
        break;
    case CHOOSE_WAIT_JOINED_MESSAGE:
        if (func_02190EF0(menu->sysWin) == 1) {
            func_021CE9E4(menu, COMM_ENTRY_MSG_WAIT_IN_LOBBY);
            func_021CE7AC(menu);
            menu->state++;
        }
        break;
    case CHOOSE_COLLECT:
        if (func_021CF068(menu) == 2) {
            func_021CE81C(menu);
            func_021CF0F4(menu);
            menu->state = CHOOSE_CANCELLED;
            break;
        }
        if (menu->lockNotifyPending == 1) {
            if (func_021CF32C(menu->netMode) == 1) {
                menu->lockNotifyPending = 0;
            }
        }
        func_021CE9A0(menu);
        if (menu->acceptFlag == 1) {
            func_021CE81C(menu);
            func_021CF0F4(menu);
            menu->state = CHOOSE_ACCEPTED;
        } else if (menu->cancelFlag == 1) {
            func_021CE81C(menu);
            func_021CF0F4(menu);
            menu->state = CHOOSE_SHOW_CANCEL_MESSAGE;
        }
        break;
    case CHOOSE_ACCEPTED:
        if (menu->isChild == 0) {
            func_021CE9E4(menu, COMM_ENTRY_MSG_STARTING);
        }
        menu->state = CHOOSE_WAIT_SYNC;
        func_02039C68(func_020399A8(), 1, 0x27);
        break;
    case CHOOSE_WAIT_SYNC:
        if (menu->isChild != 0 || func_02190EF0(menu->sysWin) == 1) {
            if (func_02039CB4(func_020399A8(), 1, 0x27) == 1) {
                menu->result = COMM_ENTRY_RESULT_START;
                menu->state = CHOOSE_DONE;
            } else if (menu->cancelFlag == 1) {
                menu->state = CHOOSE_SHOW_CANCEL_MESSAGE;
            }
        }
        break;
    case CHOOSE_SHOW_CANCEL_MESSAGE:
        func_021CE9E4(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_ABORT));
        menu->state = CHOOSE_WAIT_CANCEL_MESSAGE;
        break;
    case CHOOSE_WAIT_CANCEL_MESSAGE:
        if (func_02190EF0(menu->sysWin) == 1) {
            menu->state = CHOOSE_CANCELLED;
        }
        break;
    case CHOOSE_SWITCH_BEGIN:
        menu->savedUserArg = func_0203D650();
        func_02082D44(func_0203D798(), &menu->netInitBackup, sizeof(GFLNetInitializeStruct));
        func_021CF17C();
        func_0203CEAC(0);
        func_0201F02C(menu->wordSet, 0, menu->parentMyStatus);
        func_021CE9E4(menu, COMM_ENTRY_MSG_SWITCHING);
        menu->state = CHOOSE_SWITCH_WAIT_EXIT;
        break;
    case CHOOSE_SWITCH_WAIT_EXIT:
        if (func_0203CDBC() == 1 && func_02190EF0(menu->sysWin) == 1) {
            menu->state = CHOOSE_SWITCH_START_SESSION;
        }
        break;
    case CHOOSE_SWITCH_START_SESSION:
        func_0203CBAC(&menu->netInitBackup, 0, menu->savedUserArg);
        menu->state = CHOOSE_SWITCH_WAIT_SESSION;
        break;
    case CHOOSE_SWITCH_WAIT_SESSION:
        if (func_0203CD98() == 1) {
            func_021CF164(menu);
            menu->state = CHOOSE_SHOW_OPEN_MESSAGE;
        }
        break;
    case CHOOSE_CANCELLED:
        menu->result = COMM_ENTRY_RESULT_CANCEL;
        menu->state = CHOOSE_DONE;
        break;
    case CHOOSE_DONE:
        func_021CEB64(menu);
        func_021CE81C(menu);
        return 1;
    }
    if (func_0200FB24() != 0) {
        func_021CF0F4(menu);
        func_021CEB64(menu);
        menu->result = COMM_ENTRY_RESULT_NET_ERROR;
        return 1;
    }
    return 0;
}


int func_021CDD5C(CommEntryMenu *menu)
{
    switch (menu->state) {
    case HOST_SHOW_CONNECT_MESSAGE:
        func_021CE9E4(menu, COMM_ENTRY_MSG_CONNECTING);
        menu->state++;
        break;
    case HOST_REGISTER_SELF:
        if (func_021CF1AC(menu->myStatus, 1, menu->netMode) == 1) {
            menu->state++;
        }
        break;
    case HOST_OPEN_WINDOWS:
        func_021CE7AC(menu);
        menu->state++;
        break;
    case HOST_COLLECT:
        if (func_021CF068(menu) == 2) {
            func_021CE81C(menu);
            func_021CF0F4(menu);
            menu->state = HOST_CANCELLED;
            break;
        }
        if (menu->lockNotifyPending == 1) {
            if (func_021CF32C(menu->netMode) == 1) {
                menu->lockNotifyPending = 0;
            }
        }
        func_021CE9A0(menu);
        if (menu->acceptFlag == 1) {
            func_021CE81C(menu);
            func_021CF0F4(menu);
            menu->state = HOST_ACCEPTED;
        } else if (menu->cancelFlag == 1) {
            func_021CE81C(menu);
            func_021CF0F4(menu);
            menu->state = HOST_SHOW_CANCEL_MESSAGE;
        }
        break;
    case HOST_ACCEPTED:
        if (menu->isChild == 0) {
            func_021CE9E4(menu, COMM_ENTRY_MSG_STARTING);
        }
        menu->state = HOST_WAIT_SYNC;
        func_02039C68(func_020399A8(), 1, 0x27);
        break;
    case HOST_WAIT_SYNC:
        if (menu->isChild != 0 || func_02190EF0(menu->sysWin) == 1) {
            if (func_02039CB4(func_020399A8(), 1, 0x27) == 1) {
                menu->result = COMM_ENTRY_RESULT_START;
                menu->state = HOST_DONE;
            } else if (menu->cancelFlag == 1) {
                menu->state = HOST_SHOW_CANCEL_MESSAGE;
            }
        }
        break;
    case HOST_SHOW_CANCEL_MESSAGE:
        func_021CE9E4(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_ABORT));
        menu->state = HOST_WAIT_CANCEL_MESSAGE;
        break;
    case HOST_WAIT_CANCEL_MESSAGE:
        if (func_02190EF0(menu->sysWin) == 1) {
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = HOST_DONE;
        }
        break;
    case HOST_SWITCH_SHOW_MESSAGE:
        func_0203CEAC(0);
        func_0201F02C(menu->wordSet, 0, menu->parentList.selected);
        func_021CE9E4(menu, COMM_ENTRY_MSG_SWITCHING);
        menu->state = HOST_SWITCH_WAIT_MESSAGE;
        break;
    case HOST_SWITCH_WAIT_MESSAGE:
        if (func_0203CDBC() == 1 && func_02190EF0(menu->sysWin) == 1) {
            menu->result = COMM_ENTRY_RESULT_SWITCHED;
            menu->state = HOST_DONE;
        }
        break;
    case HOST_CANCELLED:
        menu->result = COMM_ENTRY_RESULT_CANCEL;
        menu->state = HOST_DONE;
        break;
    case HOST_DONE:
        func_021CE81C(menu);
        return 1;
    }
    if (func_0200FB24() != 0) {
        func_021CF0F4(menu);
        menu->result = COMM_ENTRY_RESULT_NET_ERROR;
        return 1;
    }
    return 0;
}


/*
 * In WAIT_REPLY the refused arm calls func_021CF0F4 twice: the original's
 * branch lands on COLLECT's second-call tail after its own call.
 */
int func_021CDF18(CommEntryMenu *menu)
{
    switch (menu->state) {
    case JOIN_SHOW_CONNECT_MESSAGE:
        func_021CE9E4(menu, COMM_ENTRY_MSG_CONNECTING);
        menu->state++;
        break;
    case JOIN_REGISTER_SELF:
        menu->joinReply = 0;
        if (func_021CF1AC(menu->myStatus, 0, menu->netMode) == 1) {
            menu->state = JOIN_WAIT_REPLY;
        }
        break;
    case JOIN_WAIT_REPLY:
        if (func_021CF068(menu) == 2) {
            func_021CE81C(menu);
            func_021CF0F4(menu);
            func_021CF0F4(menu);
            menu->state = JOIN_CANCELLED;
            break;
        }
        if (menu->joinReply == 1) {
            menu->state = JOIN_OPEN_WINDOWS;
            func_021CF0F4(menu);
        } else if (menu->joinReply == 2) {
            menu->state = JOIN_SWITCH_SHOW_MESSAGE;
            func_021CF0F4(menu);
        } else if (menu->acceptFlag == 1) {
            menu->state = JOIN_ACCEPTED;
            func_021CF0F4(menu);
        } else if (menu->cancelFlag == 1) {
            menu->state = JOIN_CANCELLED;
            func_021CF0F4(menu);
        }
        break;
    case JOIN_OPEN_WINDOWS:
        func_021CE7AC(menu);
        menu->state++;
        break;
    case JOIN_COLLECT:
        if (func_021CF068(menu) == 2) {
            func_021CE81C(menu);
            func_021CF0F4(menu);
            menu->state = JOIN_CANCELLED;
            break;
        }
        if (menu->lockNotifyPending == 1) {
            if (func_021CF32C(menu->netMode) == 1) {
                menu->lockNotifyPending = 0;
            }
        }
        func_021CE9A0(menu);
        if (menu->acceptFlag == 1) {
            func_021CE81C(menu);
            func_021CF0F4(menu);
            menu->state = JOIN_ACCEPTED;
        } else if (menu->cancelFlag == 1) {
            func_021CE81C(menu);
            func_021CF0F4(menu);
            menu->state = JOIN_SHOW_CANCEL_MESSAGE;
        }
        break;
    case JOIN_ACCEPTED:
        if (menu->isChild == 0) {
            func_021CE9E4(menu, COMM_ENTRY_MSG_STARTING);
        }
        menu->state = JOIN_WAIT_SYNC;
        func_02039C68(func_020399A8(), 1, 0x27);
        break;
    case JOIN_WAIT_SYNC:
        if (menu->isChild != 0 || func_02190EF0(menu->sysWin) == 1) {
            if (func_02039CB4(func_020399A8(), 1, 0x27) == 1) {
                menu->result = COMM_ENTRY_RESULT_START;
                menu->state = JOIN_DONE;
            } else if (menu->cancelFlag == 1) {
                menu->state = JOIN_SHOW_CANCEL_MESSAGE;
            }
        }
        break;
    case JOIN_SHOW_CANCEL_MESSAGE:
        func_021CE9E4(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_ABORT));
        menu->state = JOIN_WAIT_CANCEL_MESSAGE;
        break;
    case JOIN_WAIT_CANCEL_MESSAGE:
        if (func_02190EF0(menu->sysWin) == 1) {
            menu->result = COMM_ENTRY_RESULT_CANCEL;
            menu->state = JOIN_DONE;
        }
        break;
    case JOIN_SWITCH_SHOW_MESSAGE:
        func_0203CEAC(0);
        func_0201F02C(menu->wordSet, 0, menu->parentMyStatus);
        func_021CE9E4(menu, COMM_ENTRY_MSG_SWITCHING);
        menu->state = JOIN_SWITCH_WAIT_MESSAGE;
        break;
    case JOIN_SWITCH_WAIT_MESSAGE:
        if (func_0203CDBC() == 1 && func_02190EF0(menu->sysWin) == 1) {
            menu->result = COMM_ENTRY_RESULT_SWITCHED;
            menu->state = JOIN_DONE;
        }
        break;
    case JOIN_CANCELLED:
        menu->result = COMM_ENTRY_RESULT_CANCEL;
        menu->state = JOIN_DONE;
        break;
    case JOIN_DONE:
        func_021CE81C(menu);
        return 1;
    }
    if (func_0200FB24() != 0) {
        func_021CF0F4(menu);
        menu->result = COMM_ENTRY_RESULT_NET_ERROR;
        return 1;
    }
    return 0;
}


void func_021CE12C(CommEntryMenu *menu)
{
    u8 netId;
    int bit;
    u8 memberCount;

    for (netId = 0; netId < 4; netId++) {
        bit = 1 << netId;
        if (menu->pendingAddBits & bit) {
            if (func_021CF220(netId, menu->netMode, menu->myStatus) == 1)
                menu->pendingAddBits ^= (u8)bit;
        } else if (menu->pendingRemoveBits & bit) {
            if (func_021CF288(netId, menu->netMode, menu->myStatus) == 1)
                menu->pendingRemoveBits ^= (u8)bit;
        }
    }
    if (menu->sendPending == 1 && menu->sendBusy == 0) {
        memberCount = func_021CE1F4(menu);
        if (memberCount > 1) {
            if (func_021CF3FC(&menu->roster, memberCount, menu->netMode) == 1) {
                menu->sendPending = 0;
                menu->sendBusy = 1;
            }
        }
    }
}


/* Copies the accepted members' names into the roster; returns 1 | mask. */
u8 func_021CE1F4(CommEntryMenu *menu)
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
            func_02008494(members + netId, roster->myStatus[netId]);
            mask |= 1 << netId;
        }
    }
    menu->roster.mask = mask;
    return 1 | mask;
}


void func_021CE24C(CommEntryMenu *menu)
{
    u8 netId;

    for (netId = 0; netId < 4; netId++) {
        if (menu->members[netId].state && !func_0203D1C0(netId)) {
            CommEntryMemberFunc onRemove = menu->onRemove;

            if (onRemove) {
                onRemove(menu->callbackWork, &menu->members[netId], menu->members[netId].mac);
            }
            func_021CE3D8(menu, netId);
            func_021CEA84(menu, netId);
            func_021CEAB0(menu);
        }
    }
}


void func_021CE2BC(CommEntryMenu *menu)
{
    CommEntryMember *members;
    int index;
    int count;

    count = 0;
    index = 0;
    members = menu->members;
    for (; index < 4; index++) {
        if (menu->members[index].state) {
            func_021CE8B0(menu, members + index, index);
            count++;
        } else {
            func_021CE8F4(menu, members + index, index);
        }
    }
    if (count == 0) {
        func_021CE934(menu, menu->myStatus, 0);
        count++;
    }
    if (menu->memberCount != count) {
        if (func_021CE84C(menu, count) == 1) {
            menu->memberCount = count;
            if (menu->isChild == 1 && count == 1) {
                menu->refreshPending = 1;
            }
        }
    }
    if (menu->refreshPending == 1) {
        if (func_021CE78C(menu) == 1 && menu->confirm.menu == 0) {
            if (count == 1) {
                func_021CE9E4(menu, COMM_ENTRY_MSG_WAIT_FOR_MEMBERS);
            }
            menu->refreshPending = 0;
        }
    }
}


void func_021CE36C(CommEntryMenu *menu)
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
            if (func_021CE3E8(menu, member) == 1) {
                member->state = COMM_ENTRY_MEMBER_ASKING;
            }
            break;
        }
    }
}


void func_021CE3D8(CommEntryMenu *menu, int index)
{
    menu->members[index].state = COMM_ENTRY_MEMBER_EMPTY;
}


/* Latches a join request when none is pending; returns whether it did. */
int func_021CE3E8(CommEntryMenu *menu, CommEntryMember *member)
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
void func_021CE41C(CommEntryMenu *menu)
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
    if (!func_02190EF0(menu->sysWin)) {
        return;
    }
    switch (confirm->state) {
    case CONFIRM_ASK:
        func_0201F02C(menu->wordSet, 0, request);
        func_021CE9E4(menu, COMM_ENTRY_MSG_ASK_JOIN_REQUEST);
        confirm->state++;
        break;
    case CONFIRM_OPEN_MENU:
        confirm->menu = func_02190BE4(func_02188C54(menu->fieldMap), 0);
        confirm->state++;
        break;
    case CONFIRM_WAIT_ANSWER:
        answer = func_02190C78(confirm->menu);
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
        func_021909BC(confirm->menu);
        confirm->menu = 0;
        confirm->state++;
        break;
    case CONFIRM_FINISH_REQUEST:
        menu->requestPending = 0;
        confirm->state = CONFIRM_ASK;
        func_021CE36C(menu);
        if (menu->requestPending == 0) {
            if (func_021CE73C(menu) > 1 && menu->isChild == 1) {
                menu->nextMessage = COMM_ENTRY_MSG_MEMBERS_CAN_START;
            } else {
                menu->nextMessage = COMM_ENTRY_MSG_WAIT_FOR_MEMBERS;
            }
        }
        break;
    }
}


/* Asks whether to start with the members present; returns 1 for yes, 2 for no, else 0. */
int func_021CE52C(CommEntryMenu *menu)
{
    CommEntryConfirm *confirm;
    u32 answer;

    confirm = &menu->confirm;
    if (!func_02190EF0(menu->sysWin)) {
        return 0;
    }
    switch (confirm->state) {
    case CONFIRM_ASK:
        func_021CE9E4(menu, COMM_ENTRY_MSG_CONFIRM_START);
        confirm->state++;
        break;
    case CONFIRM_OPEN_MENU:
        confirm->menu = func_02190BE4(func_02188C54(menu->fieldMap), 0);
        confirm->state++;
        break;
    case CONFIRM_WAIT_ANSWER:
        if (!func_021CEA50(menu)) {
            answer = 1;
        } else {
            answer = func_02190C78(confirm->menu);
            if (answer == 2) {
                break;
            }
        }
        func_021909BC(confirm->menu);
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
u32 func_021CE5AC(CommEntryMenu *menu)
{
    CommEntryConfirm *confirm;
    u32 answer;

    confirm = &menu->confirm;
    if (!func_02190EF0(menu->sysWin)) {
        return 0;
    }
    switch (confirm->state) {
    case CONFIRM_ASK:
        func_021CE9E4(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_QUIT_ASK));
        confirm->state++;
        break;
    case CONFIRM_OPEN_MENU:
        confirm->menu = func_02190BE4(func_02188C54(menu->fieldMap), 0);
        confirm->state++;
        break;
    case CONFIRM_WAIT_ANSWER:
        answer = func_02190C78(confirm->menu);
        if (answer == 2) {
            break;
        }
        func_021909BC(confirm->menu);
        confirm->menu = 0;
        if (answer == 1) {
            confirm->result = 2;
            confirm->state = CONFIRM_ABORTED;
        } else if (func_021CE73C(menu) <= 1) {
            func_021CE9E4(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_QUIT_ALONE));
            confirm->state = CONFIRM_NOTIFY_ALONE;
        } else {
            func_021CE9E4(menu, COMM_ENTRY_MSG_CONFIRM_QUIT_MEMBERS);
            confirm->state++;
        }
        break;
    case CONFIRM_OPEN_MENU_AGAIN:
        confirm->menu = func_02190BE4(func_02188C54(menu->fieldMap), 0);
        confirm->state++;
        break;
    case CONFIRM_WAIT_ANSWER_AGAIN:
        answer = func_02190C78(confirm->menu);
        if (answer == 2) {
            break;
        }
        func_021909BC(confirm->menu);
        confirm->menu = 0;
        if (answer == 0) {
            func_021CE9E4(menu, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_QUIT_ALONE));
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
        if (func_021CE73C(menu) > 1 && menu->isChild == 1) {
            menu->nextMessage = COMM_ENTRY_MSG_MEMBERS_CAN_START;
        } else {
            menu->nextMessage = COMM_ENTRY_MSG_WAIT_FOR_MEMBERS;
        }
        confirm->state = CONFIRM_FINISHED;
        break;
    case CONFIRM_FINISHED:
        if (confirm->menu) {
            func_021909BC(confirm->menu);
            confirm->menu = 0;
        }
        confirm->state = CONFIRM_ASK;
        return confirm->result;
    }
    return 0;
}


void func_021CE6F0(CommEntryMenu *menu, int netId)
{
    menu->readyBits |= 1 << netId;
}


void func_021CE70C(CommEntryMenu *menu)
{
    menu->acceptFlag = 1;
}


void func_021CE718(CommEntryMenu *menu)
{
    menu->cancelFlag = 1;
}


/* Marks the session as locked and the lock as not yet broadcast. */
void func_021CE724(CommEntryMenu *menu)
{
    menu->sessionLocked = 1;
    menu->lockNotifyPending = 1;
    func_0203D7BC(1);
}


int func_021CE73C(CommEntryMenu *menu)
{
    int netId;
    int count = 0;
    for (netId = 0; netId < 4; netId++) {
        if (menu->members[netId].state == COMM_ENTRY_MEMBER_ACCEPTED)
            count++;
    }
    return count;
}


u32 func_021CE760(CommEntryMenu *menu)
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
int func_021CE78C(CommEntryMenu *menu)
{
    if (menu->requestPending == 0) {
        if (func_02190EF0(menu->sysWin) == 1) {
            return 1;
        }
    }
    return 0;
}


void func_021CE7AC(CommEntryMenu *menu)
{
    FieldMsgBg *msgBg;
    int height;

    msgBg = func_02188C54(menu->fieldMap);
    height = 0x10;
    if (menu->menuMode) {
        height = 0xe;
    }
    menu->memberWin = func_02190708(msgBg, menu->msgData, 2, 6, 0x12, height - 6);
    menu->titleWin = func_02190708(msgBg, menu->msgData, 2, 1, 0x1c, 2);
    func_02190740(menu->titleWin, 0, 0, COMM_ENTRY_MSG(menu->isChild, COMM_ENTRY_MSGCOL_TITLE));
}


void func_021CE81C(CommEntryMenu *menu)
{
    FieldMsgBg *msgBg = func_02188C54(menu->fieldMap);
    if (menu->titleWin != 0) {
        func_02190728(menu->titleWin);
        menu->titleWin = 0;
    }
    if (menu->memberWin != 0) {
        func_02190728(menu->memberWin);
        menu->memberWin = 0;
    }
    func_02190490(msgBg);
}


int func_021CE84C(CommEntryMenu *menu, int count)
{
    if (menu->memberWin && func_0219077C(menu->memberWin) == 1) {
        func_02190794(menu->memberWin, 0, 0x40, 0x90, 0x50);
        func_0201EFA4(menu->wordSet, 0, menu->maxMembers - count, 1, 0, 1);
        func_0201F250(menu->wordSet, menu->remainingStr, menu->remainingFormat);
        func_02190758(menu->memberWin, 0, 0x40, menu->remainingStr);
        return 1;
    }
    return 0;
}


void func_021CE8B0(CommEntryMenu *menu, CommEntryMember *member, int index)
{
    MacAddress *macs;
    macs = menu->memberMacs;
    if (func_0203EFC8(member->mac, macs[index].b, 6)) {
        func_021CE934(menu, member, (u8)index);
        func_02082D44(member->mac, macs[index].b, 6);
    }
}


void func_021CE8F4(CommEntryMenu *menu, CommEntryMember *member, int index)
{
    if (func_0203EFC8((u8 *)menu->memberMacs + index * 6, d_021DB470, 6)) {
        func_021CE984(menu, index);
        func_02082D44(d_021DB470, menu->memberMacs[index].b, 6);
    }
}


/* Prints the name and trainer id of a member on row `row` of the member window. */
void func_021CE934(CommEntryMenu *menu, const void *myStatus, u32 row)
{
    u32 trainerId;
    if (menu->memberWin != 0) {
        func_0201F02C(menu->wordSet, 0, myStatus);
        trainerId = func_02008534(myStatus);
        func_0201EFA4(menu->wordSet, 1, trainerId, 5, 2, 1);
        func_0201F250(menu->wordSet, menu->nameStr, menu->nameFormat);
        func_02190758(menu->memberWin, 0, (row & 0xfff) << 4, menu->nameStr);
    }
}


void func_021CE984(CommEntryMenu *menu, u32 row)
{
    if (menu->memberWin != 0) {
        func_02190794(menu->memberWin, 0, row << 4, 0x90, 0x10);
    }
}


void func_021CE9A0(CommEntryMenu *menu)
{
    int row;
    if (menu->namesDirty != 0) {
        menu->namesDirty = 0;
        for (row = 0; row < 4; row++) {
            func_021CE984(menu, row);
            if (menu->roster.mask & (1 << row))
                func_021CE934(menu, menu->roster.myStatus[row], (u8)row);
        }
    }
}


void func_021CE9E4(CommEntryMenu *menu, u32 msgId)
{
    struct Strbuf *format;
    if (msgId == COMM_ENTRY_MSG_WAIT_FOR_MEMBERS && menu->lastMessageId == COMM_ENTRY_MSG_WAIT_FOR_MEMBERS)
        return;
    menu->lastMessageId = msgId;
    format = func_02045EC0(menu->msgData, msgId);
    func_0201F250(menu->wordSet, menu->msgStr, format);
    func_02045808(format);
    func_02190F7C(menu->sysWin);
    func_02190EB8(menu->sysWin, 0, 0, menu->msgStr);
}


void func_021CEA28(CommEntryMenu *menu)
{
    u8 netId;
    for (netId = 0; netId < 4; netId++) {
        menu->stateSnapshot[netId] = menu->members[netId].state;
    }
}


int func_021CEA50(CommEntryMenu *menu)
{
    u8 netId;
    for (netId = 0; netId < 4; netId++) {
        if (menu->stateSnapshot[netId] != menu->members[netId].state) {
            return 0;
        }
    }
    return 1;
}


void func_021CEA84(CommEntryMenu *menu, int index)
{
    menu->pendingAddBits &= 0xff ^ (1 << index);
    menu->pendingRemoveBits &= 0xff ^ (1 << index);
}


void func_021CEAB0(CommEntryMenu *menu)
{
    if (menu->sendPending == 1 || menu->sendBusy == 1) {
        menu->sendQueued = 1;
    } else {
        menu->sendPending = 1;
        menu->sendQueued = 0;
    }
}


CommEntryMenu *func_021CEADC(CommEntryMenu *menu)
{
    menu->sendBusy = 0;
    menu->sendPending = menu->sendQueued;
    menu->sendQueued = 0;
    return menu;
}


CommEntryRoster *func_021CEAF8(CommEntryMenu *menu)
{
    return &menu->roster;
}


void func_021CEB04(CommEntryMenu *menu, const CommEntryRoster *roster)
{
    func_02082D44(roster, &menu->roster, sizeof(CommEntryRoster));
    menu->namesDirty = 1;
}


void func_021CEB20(CommEntryMenu *menu)
{
    FieldMsgBg *msgBg;
    msgBg = func_02188C54(menu->fieldMap);
    menu->parentList.items = func_02190A20(0x10, menu->heapId);
    func_021CEF1C(menu);
    menu->parentList.menu = (FieldMenuFunc *)func_0219097C(msgBg, &d_021DB478, menu->parentList.items);
    menu->parentList.state = 0;
}


void func_021CEB64(CommEntryMenu *menu)
{
    if (menu->parentList.menu != 0) {
        func_021909BC(menu->parentList.menu);
        menu->parentList.menu = 0;
        menu->parentList.itemsBuilt = 0;
    }
}


u32 func_021CEB84(CommEntryMenu *menu)
{
    FieldMenuFunc **confirmMenu = &menu->confirm.menu;
    CommEntryParentList *list = &menu->parentList;
    u32 answer;
    switch (list->state) {
    case LIST_BROWSE:
        if (list->selected == 0) {
            func_021CEE00(menu);
            func_021CEE48(menu);
            if (func_021CEDA0(menu) == 0) {
                list->result = LIST_RESULT_LEFT;
                list->state = LIST_FINISHED;
            } else if (menu->parentList.listDirty == 1) {
                func_021CEF1C(menu);
                func_02190A14(menu->parentList.menu);
                menu->parentList.listDirty = 0;
            }
        } else if (func_020392B8() > 1) {
            if (func_02039ACC() == 1) {
                list->state++;
            }
        } else {
            if (func_020362DC() & 2) {
                list->returnState = list->state;
                list->state = LIST_ASK_LEAVE;
            }
            (list->waitFrames)++;
            if (list->waitFrames >= 300) {
                list->state = LIST_SHOW_TIMEOUT;
                func_021CE9E4(menu, COMM_ENTRY_MSG_LIST_TIMEOUT);
            }
        }
        break;
    case LIST_WAIT_NEGOTIATION:
        if (func_020399B8(func_020399A8()) == 1) {
            menu->joinReply = 0;
            if (func_021CF1AC(menu->myStatus, 0, menu->netMode) == 1) {
                list->state = LIST_WAIT_REPLY;
            }
        } else if (func_020362DC() & 2) {
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
        } else if (func_020362DC() & 2) {
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
        func_021CE9E4(menu, COMM_ENTRY_MSG_ASK_LEAVE);
        *confirmMenu = func_02190BE4(func_02188C54(menu->fieldMap), 0);
        list->state = LIST_WAIT_LEAVE_ANSWER;
        break;
    case LIST_WAIT_LEAVE_ANSWER:
        answer = func_02190C78(*confirmMenu);
        if (func_0219049C(func_02188C54(menu->fieldMap)) == 1 && menu->sessionLocked == 1) {
            answer = 1;
        }
        if (answer == 2 && func_0219049C(func_02188C54(menu->fieldMap)) == 1) {
            if (menu->acceptFlag == 1 || menu->cancelFlag == 1) {
                func_021909BC(*confirmMenu);
                *confirmMenu = 0;
                list->result = LIST_RESULT_JOINED;
                list->state = LIST_FINISHED;
            }
        } else {
            func_021909BC(*confirmMenu);
            *confirmMenu = 0;
            if (answer == 1) {
                list->state = list->returnState;
                func_021CE9E4(menu, COMM_ENTRY_MSG_LEAVE_REFUSED);
                if (menu->parentList.menu != 0) {
                    func_02190B1C(menu->parentList.menu);
                }
            } else {
                list->result = LIST_RESULT_LEFT;
                list->state = LIST_FINISHED;
            }
        }
        break;
    case LIST_SHOW_TIMEOUT:
        if (func_02190EF0(menu->sysWin) == 1) {
            list->result = LIST_RESULT_LEFT;
            list->state = LIST_FINISHED;
        }
        break;
    }
    return 0;
}

/* Polls the parent list menu; a chosen used slot becomes the selected parent. */
int func_021CEDA0(CommEntryMenu *menu)
{
    CommEntryParentList *list = &menu->parentList;
    int choice;

    choice = func_021909E4(list->menu);
    switch (choice) {
    case -2:
        return 0;
    case -1:
        break;
    default:
        if (list->slots[choice].used == 1) {
            list->selected = &list->slots[choice];
            func_0203D000(list->selected->mac);
            func_0201F02C(menu->wordSet, 0, list->selected);
            func_021CE9E4(menu, COMM_ENTRY_MSG_LEAVE_REFUSED);
            list->waitFrames = 0;
        }
        break;
    }
    return 1;
}

/* Counts the timeouts down; an expired parent slot is cleared. */
void func_021CEE00(CommEntryMenu *menu)
{
    CommEntryParentList *list = &menu->parentList;
    int i;

    for (i = 0; i < COMM_ENTRY_PARENT_SLOTS; i++) {
        if (list->slots[i].used == 1) {
            list->slots[i].timeout -= 1;
            if (list->slots[i].timeout <= 0) {
                func_021CEF08(menu, i);
                list->listDirty = 1;
            }
        }
    }
}

/* Registers every beacon that advertises an open session as a parent. */
void func_021CEE48(CommEntryMenu *menu)
{
    int i;
    CommEntryBeaconData *beacon;

    for (i = 0; i < 0x10; i++) {
        beacon = func_0203CF10(i);
        if (beacon != 0 && beacon->advertiseId == COMM_ENTRY_ADVERTISE_ID) {
            func_021CEE78(menu, beacon->mac, beacon);
        }
    }
}

/* Refreshes the timeout of a known parent, or stores a new one in a free slot. */
void func_021CEE78(CommEntryMenu *menu, u8 *mac, CommEntryBeaconData *beacon)
{
    CommEntryParentList *list = &menu->parentList;
    int i;

    for (i = 0; i < COMM_ENTRY_PARENT_SLOTS; i++) {
        if (list->slots[i].used == 1 && func_0203EFC8(list->slots[i].mac, mac, 6) == 0) {
            list->slots[i].timeout = COMM_ENTRY_PARENT_TIMEOUT_FRAMES;
            return;
        }
    }
    for (i = 0; i < COMM_ENTRY_PARENT_SLOTS; i++) {
        if (list->slots[i].used == 0) {
            func_02082D44(mac, list->slots[i].mac, 6);
            func_02008494(beacon, list->slots[i].myStatus);
            list->slots[i].timeout = COMM_ENTRY_PARENT_TIMEOUT_FRAMES;
            list->slots[i].used = 1;
            list->listDirty = 1;
            return;
        }
    }
}

void func_021CEF08(CommEntryMenu *menu, int slotIndex)
{
    menu->parentList.slots[slotIndex].used = 0;
}

/* Rebuilds the item list of the parent menu from the 16 slots. */
void func_021CEF1C(CommEntryMenu *menu)
{
    u16 emptyChar;
    struct Strbuf *line, *emptyFormat, *nameFormat, *emptyStr;
    int i;

    emptyChar = func_02045A98();
    if (menu->parentList.itemsBuilt == 1) {
        func_02190A6C(menu->parentList.items);
    }
    emptyFormat = func_020457B0(0x40, menu->heapId);
    nameFormat = func_020457B0(0x40, menu->heapId);
    line = func_020457B0(0x40, menu->heapId);
    emptyStr = func_020457B0(4, menu->heapId);
    func_02045CAC(menu->msgData, 0x1a, emptyFormat);
    func_02045CAC(menu->msgData, 0x1b, nameFormat);
    for (i = 0; i < COMM_ENTRY_PARENT_SLOTS; i++) {
        func_0201EFA4(menu->wordSet, 0, i + 1, 2, 2, 1);
        if (menu->parentList.slots[i].used == 1) {
            func_0201F02C(menu->wordSet, 1, &menu->parentList.slots[i]);
            func_0201EFA4(menu->wordSet, 2, func_02008534(&menu->parentList.slots[i]), 5, 2, 1);
            func_0201F250(menu->wordSet, line, nameFormat);
        } else {
            func_02045924(emptyStr, &emptyChar);
            func_0201EE0C(menu->wordSet, 1, emptyStr, 0, 1, 2);
            func_0201EE0C(menu->wordSet, 2, emptyStr, 0, 1, 2);
            func_0201F250(menu->wordSet, line, emptyFormat);
        }
        func_02190A64(menu->parentList.items, line, i, menu->heapId);
    }
    func_02045808(nameFormat);
    func_02045808(emptyFormat);
    func_02045808(line);
    func_02045808(emptyStr);
    menu->parentList.itemsBuilt = 1;
}

/* Runs the "leave the group?" dialog. Returns 2 when the player leaves, 1 while it is open, else 0. */
int func_021CF068(CommEntryMenu *menu)
{
    CommEntryConfirm *confirm = &menu->confirm;
    u32 answer;

    switch (confirm->state) {
    case 0:
        if (func_020362DC() & 2) {
            confirm->menu = func_02190BE4(func_02188C54(menu->fieldMap), 0);
            func_021CE9E4(menu, COMM_ENTRY_MSG_ASK_LEAVE);
            confirm->state = 1;
        }
        break;
    case 1:
        answer = func_02190C78(confirm->menu);
        if (func_0219049C(func_02188C54(menu->fieldMap)) == 1 && menu->sessionLocked == 1)
            answer = 1;
        if (answer != 2) {
            func_021909BC(confirm->menu);
            confirm->menu = 0;
            if (answer == 1) {
                confirm->state = 0;
                func_021CE9E4(menu, COMM_ENTRY_MSG_WAIT_IN_LOBBY);
            } else {
                return 2;
            }
        }
        return 1;
    }
    return 0;
}

void func_021CF0F4(CommEntryMenu *menu)
{
    CommEntryConfirm *confirm = &menu->confirm;

    if (confirm->menu != 0) {
        func_021909BC(confirm->menu);
        confirm->menu = 0;
    }
    confirm->state = 0;
}

/* Stores the join reply (1 accepted, 2 redirected) and the parent's MyStatus. */
void func_021CF110(CommEntryMenu *menu, u32 reply, const void *parentMyStatus)
{
    menu->joinReply = reply;
    func_02008494(parentMyStatus, menu->parentMyStatus);
}

/* Size of the roster packet. */
u32 func_021CF128(void)
{
    return sizeof(CommEntryRoster);
}

/* Returns 1 when a member other than this machine is set in mask and connected. */
int func_021CF12C(int mask)
{
    u8 i;
    for (i = 0; i < COMM_ENTRY_MAX_MEMBERS; i++) {
        if (i != func_0203D1A4(func_020399A8()) && ((1 << i) & mask) && func_0203D1C0(i) == 1) {
            return 1;
        }
    }
    return 0;
}

/* Starts the network command handling for the entry menu commands. */
void func_021CF164(CommEntryMenu *menu)
{
    func_0203A574(COMM_ENTRY_NET_HEAP, data_021DB4BC, COMM_ENTRY_CMD_COUNT, menu);
}

void func_021CF17C(void)
{
    func_0203A5E4(COMM_ENTRY_NET_HEAP);
}

/* Receive buffer of the roster command. */
CommEntryRoster *func_021CF188(u32 netId, CommEntryMenu *menu)
{
    return func_021CEAF8(menu);
}

/* Receive of the join request: the packet holds MyStatus, MAC and the child flag. */
int func_021CF194(u32 netId, u32 size, CommEntryJoinRequest *request, CommEntryMenu *menu)
{
    func_021CD624(menu, netId, request, request->isChild, request->mac);
}

/* Sends MyStatus to every machine (netMode 1) or to the parent; returns the send result when not netMode 1. */
u32 func_021CF1AC(const void *myStatus, u32 isChild, u32 netMode)
{
    CommEntryJoinRequest packet;

    func_02082BCC(&packet, 0, sizeof(CommEntryJoinRequest));
    func_02008494(myStatus, &packet);
    func_02087C6C(packet.mac);
    packet.isChild = isChild;
    if (netMode == 1)
        func_0203D3F8(func_020399A8(), COMM_ENTRY_NET_ALL, COMM_ENTRY_CMD_JOIN_REQUEST, sizeof(CommEntryJoinRequest), &packet, 0, 0, 0);
    else
        return func_0203D3F8(func_020399A8(), 0, COMM_ENTRY_CMD_JOIN_REQUEST, sizeof(CommEntryJoinRequest), &packet, 0, 0, 0);
}

/* Receive of the join accept. */
void func_021CF214(u32 netId, u32 size, const void *parentMyStatus, CommEntryMenu *menu)
{
    func_021CF110(menu, 1, parentMyStatus);
}

/* Sends the join accept with the parent's MyStatus to member index. */
u32 func_021CF220(u32 index, u32 netMode, const void *myStatus)
{
    GFLNetHandle *handle;

    if (netMode == 1) {
        handle = func_0203996C(COMM_ENTRY_NET_ALL);
        func_0203D3F8(handle, index, COMM_ENTRY_CMD_JOIN_ACCEPT, func_02008468(), myStatus, 0, 0, 0);
    } else {
        handle = func_020399A8();
        func_0203D3F8(handle, index, COMM_ENTRY_CMD_JOIN_ACCEPT, func_02008468(), myStatus, 0, 0, 0);
    }
}

/* Receive of the join redirect. */
void func_021CF27C(u32 netId, u32 size, const void *parentMyStatus, CommEntryMenu *menu)
{
    func_021CF110(menu, 2, parentMyStatus);
}

/* Sends the join redirect with the parent's MyStatus to member index. */
u32 func_021CF288(u32 index, u32 netMode, const void *myStatus)
{
    GFLNetHandle *handle;

    if (netMode == 1) {
        handle = func_0203996C(COMM_ENTRY_NET_ALL);
        func_0203D3F8(handle, index, COMM_ENTRY_CMD_JOIN_REDIRECT, func_02008468(), myStatus, 0, 0, 0);
    } else {
        handle = func_020399A8();
        func_0203D3F8(handle, index, COMM_ENTRY_CMD_JOIN_REDIRECT, func_02008468(), myStatus, 0, 0, 0);
    }
}

/* Receive of the session lock. */
void func_021CF2E4(u32 netId, u32 size, const void *data, CommEntryMenu *menu)
{
    func_021CE724(menu);
}

int func_021CF2F0(int netMode)
{
    if (netMode == 1) {
        return func_0203D3A8(func_0203996C(COMM_ENTRY_NET_ALL), COMM_ENTRY_CMD_SESSION_LOCK, 0, 0);
    } else {
        return func_0203D3A8(func_020399A8(), COMM_ENTRY_CMD_SESSION_LOCK, 0, 0);
    }
}

/* Receive of the ready message: marks the sender in readyBits. */
void func_021CF31C(u32 netId, u32 size, const void *data, CommEntryMenu *menu)
{
    func_021CE6F0(menu, (u8)netId);
}

u32 func_021CF32C(u32 netMode)
{
    if (netMode == 1)
        func_0203D3F8(func_020399A8(), COMM_ENTRY_NET_ALL, COMM_ENTRY_CMD_READY, 0, 0, 0, 0, 0);
    else
        return func_0203D3F8(func_020399A8(), 0, COMM_ENTRY_CMD_READY, 0, 0, 0, 0, 0);
}

/* Receive of the accept message. */
void func_021CF36C(u32 netId, u32 size, const void *data, CommEntryMenu *menu)
{
    func_021CE70C(menu);
}

int func_021CF378(int netMode)
{
    if (netMode == 1) {
        return func_0203D3A8(func_0203996C(COMM_ENTRY_NET_ALL), COMM_ENTRY_CMD_ACCEPT, 0, 0);
    } else {
        return func_0203D3A8(func_020399A8(), COMM_ENTRY_CMD_ACCEPT, 0, 0);
    }
}

/* Receive of the cancel message. */
void func_021CF3A4(u32 netId, u32 size, const void *data, CommEntryMenu *menu)
{
    func_021CE718(menu);
}

int func_021CF3B0(int netMode)
{
    if (netMode == 1) {
        return func_0203D3A8(func_0203996C(COMM_ENTRY_NET_ALL), COMM_ENTRY_CMD_CANCEL, 0, 0);
    } else {
        return func_0203D3A8(func_020399A8(), COMM_ENTRY_CMD_CANCEL, 0, 0);
    }
}

/* Receive of the roster: the parent only returns the menu, a child stores the roster. */
int func_021CF3DC(u32 netId, u32 size, const CommEntryRoster *roster, CommEntryMenu *menu)
{
    if (func_0203D378() == 1) {
        return (int)func_021CEADC(menu);
    }
    func_021CEB04(menu, roster);
}

/* Sends the roster to every machine (netMode 1) or to the parent. */
u32 func_021CF3FC(const CommEntryRoster *roster, u32 recipients, int netMode)
{
    GFLNetHandle *handle;

    if (netMode == 1) {
        handle = func_0203996C(COMM_ENTRY_NET_ALL);
        func_0203D4D0(handle, recipients, COMM_ENTRY_CMD_ROSTER, func_021CF128(), roster, 0, 0, 1);
    } else {
        handle = func_020399A8();
        func_0203D4D0(handle, recipients, COMM_ENTRY_CMD_ROSTER, func_021CF128(), roster, 0, 0, 1);
    }
}
