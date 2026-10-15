#ifndef OV099_WIFI_CLUB_WORK_H
#define OV099_WIFI_CLUB_WORK_H
/* Work object of the Wi-Fi club proc (size 0x1360). It is allocated in WIFICLUB_ProcInit with
 * PROCSYS_AllocProcWork(obj, 0x1360, 0x21) and handed to every state handler. */
#include "wifi_club_actor_types.h"

/* Opaque handle types (never dereferenced here). */
typedef struct BmpWin BmpWin;
typedef struct PrintQue PrintQue;
typedef struct PrintStream PrintStream;
typedef struct StrBuf StrBuf;
typedef struct WordSet WordSet;
typedef struct MsgData MsgData;

/* Values of WifiClubWork.state: index into the handler table gWifiClubStateHandlers (0xAE entries).
 * Each name follows the handler that runs in that state. */
typedef enum WifiClubState {
    WIFICLUB_STATE_ENTER_CLUB = 0x0,
    WIFICLUB_STATE_WAIT_INTRO_MESSAGE = 0x1,
    WIFICLUB_STATE_OPEN_EXIT_PROMPT = 0x2,
    WIFICLUB_STATE_POLL_EXIT_PROMPT = 0x3,
    WIFICLUB_STATE_RESTART_MATCH = 0x4,
    WIFICLUB_STATE_RESET_BG_SCROLL = 0x5,
    WIFICLUB_STATE_WATCH_LOGIN = 0x6,
    WIFICLUB_STATE_SHOW_SAVE_NOTICE = 0x7,
    WIFICLUB_STATE_WAIT_SAVE_NOTICE = 0x8,
    WIFICLUB_STATE_HANDLE_NET_ERROR = 0x9,
    WIFICLUB_STATE_RETURN_TO_CLUB = 0xA,
    WIFICLUB_STATE_LOBBY_MAIN = 0xB,
    WIFICLUB_STATE_WAIT_KEY_RETURN_TO_LOBBY = 0xC,
    WIFICLUB_STATE_WAIT_PEER_REPLY = 0xD,
    WIFICLUB_STATE_START_MESSAGE_DISMISS = 0xE,
    WIFICLUB_STATE_WAIT_MESSAGE = 0xF,
    WIFICLUB_STATE_SYNC_TIMING_START = 0x10,
    WIFICLUB_STATE_VCHAT_ANSWER_WAIT = 0x11,
    WIFICLUB_STATE_VCHAT_YES_NO = 0x12,
    WIFICLUB_STATE_ERROR_MESSAGE_WAIT = 0x13,
    WIFICLUB_STATE_DISCONNECT_ACK_WAIT = 0x14,
    WIFICLUB_STATE_LEAVE_CANCEL = 0x15,
    WIFICLUB_STATE_UNUSED_A = 0x16,
    WIFICLUB_STATE_UNUSED_B = 0x17,
    WIFICLUB_STATE_UNUSED_C = 0x18,
    WIFICLUB_STATE_BEGIN_IDLE_AFTER_NET = 0x19,
    WIFICLUB_STATE_WIFICLUB_RESOLVE_NET_RUN_STATE = 0x1A,
    WIFICLUB_STATE_COUNTDOWN_THEN_CONFIRM = 0x1B,
    WIFICLUB_STATE_OPEN_PARTNER_MENU = 0x1C,
    WIFICLUB_STATE_PARTNER_MENU = 0x1D,
    WIFICLUB_STATE_SELECTION_MENU = 0x1E,
    WIFICLUB_STATE_START_PROMPT = 0x1F,
    WIFICLUB_STATE_WAIT_PROMPT = 0x20,
    WIFICLUB_STATE_POLL_PROMPT = 0x21,
    WIFICLUB_STATE_SHOW_PARTNER_STATUS_MESSAGE = 0x22,
    WIFICLUB_STATE_OPEN_ANSWER_MENU = 0x23,
    WIFICLUB_STATE_PARTNER_MENU_RESULT = 0x24,
    WIFICLUB_STATE_WAIT_JOIN_ANSWER = 0x25,
    WIFICLUB_STATE_UNUSED_D = 0x26,
    WIFICLUB_STATE_UNUSED_E = 0x27,
    WIFICLUB_STATE_ON_PARTNER_CONNECTED = 0x28,
    WIFICLUB_STATE_WAIT_NEGOTIATION = 0x29,
    WIFICLUB_STATE_SEND_TRAINER_CARD = 0x2A,
    WIFICLUB_STATE_CHECK_PEER_PHASE = 0x2B,
    WIFICLUB_STATE_WAIT_SYNC_ENABLE_AUTO_EXIT = 0x2C,
    WIFICLUB_STATE_BRANCH_ON_PARTNER_PHASE = 0x2D,
    WIFICLUB_STATE_GOTO_WAIT_KEY = 0x2E,
    WIFICLUB_STATE_WAIT_KEY_OR_NET_UP = 0x2F,
    WIFICLUB_STATE_CLEAR_TALK_TO_LOBBY = 0x30,
    WIFICLUB_STATE_OPEN_QUIT_YES_NO = 0x31,
    WIFICLUB_STATE_POLL_QUIT_YES_NO = 0x32,
    WIFICLUB_STATE_EXIT_NETWORK = 0x33,
    WIFICLUB_STATE_COUNTDOWN_TO_LOBBY = 0x34,
    WIFICLUB_STATE_OPEN_RETRY_YES_NO = 0x35,
    WIFICLUB_STATE_POLL_RETRY_YES_NO = 0x36,
    WIFICLUB_STATE_OPEN_SEAT_YES_NO = 0x37,
    WIFICLUB_STATE_POLL_SEAT_YES_NO = 0x38,
    WIFICLUB_STATE_WATCH_CONNECTION = 0x39,
    WIFICLUB_STATE_WIFICLUB_RETURN_SECOND_ARG_A = 0x3A,
    WIFICLUB_STATE_WIFICLUB_RETURN_SECOND_ARG_B = 0x3B,
    WIFICLUB_STATE_WATCH_LOGIN_AND_SAVE = 0x3C,
    WIFICLUB_STATE_LEAVE_LINK_TO_LOBBY = 0x3D,
    WIFICLUB_STATE_WAIT_SAVE = 0x3E,
    WIFICLUB_STATE_CHECK_PEER_SELECTION = 0x3F,
    WIFICLUB_STATE_ANSWER_MENU = 0x40,
    WIFICLUB_STATE_START_INVITE = 0x41,
    WIFICLUB_STATE_OPEN_INVITE_YES_NO = 0x42,
    WIFICLUB_STATE_INVITE_YES_NO = 0x43,
    WIFICLUB_STATE_RESTART_INVITE = 0x44,
    WIFICLUB_STATE_OPEN_MAIN_MENU = 0x45,
    WIFICLUB_STATE_MAIN_MENU = 0x46,
    WIFICLUB_STATE_WAIT_KEY_RETRY = 0x47,
    WIFICLUB_STATE_WAIT_SYNC_AND_RESUME = 0x48,
    WIFICLUB_STATE_WAIT_SYNC_AND_RETURN_TO_IDLE = 0x49,
    WIFICLUB_STATE_DISABLE_AUTO_EXIT_B = 0x4A,
    WIFICLUB_STATE_PICK_SCENE4 = 0x4B,
    WIFICLUB_STATE_PICK_SCENE5 = 0x4C,
    WIFICLUB_STATE_PICK_SCENE6 = 0x4D,
    WIFICLUB_STATE_OPEN_RULE_MENU = 0x4E,
    WIFICLUB_STATE_OPEN_SCENE_YES_NO = 0x4F,
    WIFICLUB_STATE_SCENE_YES_NO = 0x50,
    WIFICLUB_STATE_START_SCENE = 0x51,
    WIFICLUB_STATE_EXIT_ACCEPTED = 0x52,
    WIFICLUB_STATE_EXIT_DECLINED = 0x53,
    WIFICLUB_STATE_RULE_MENU = 0x54,
    WIFICLUB_STATE_OPEN_KIND_MENU = 0x55,
    WIFICLUB_STATE_KIND_MENU = 0x56,
    WIFICLUB_STATE_OPEN_LEVEL_MENU = 0x57,
    WIFICLUB_STATE_LEVEL_MENU = 0x58,
    WIFICLUB_STATE_OPEN_OPTION_MENU = 0x59,
    WIFICLUB_STATE_OPTION_MENU = 0x5A,
    WIFICLUB_STATE_CHECK_RULES = 0x5B,
    WIFICLUB_STATE_SHOW_RULE_SET = 0x5C,
    WIFICLUB_STATE_RULE_SET_KEY = 0x5D,
    WIFICLUB_STATE_SHOW_RULE_PREVIEW = 0x5E,
    WIFICLUB_STATE_IDLE = 0x5F,
    WIFICLUB_STATE_OPEN_ENTRY_PROMPT = 0x60,
    WIFICLUB_STATE_POLL_ENTRY_PROMPT = 0x61,
    WIFICLUB_STATE_CHECK_ENTRY_RULES = 0x62,
    WIFICLUB_STATE_RULE_VIOLATION_KEY = 0x63,
    WIFICLUB_STATE_REGISTER_ENTRY_PARTY = 0x64,
    WIFICLUB_STATE_OPEN_PARTY_MENU = 0x65,
    WIFICLUB_STATE_UPDATE_PARTY_MENU = 0x66,
    WIFICLUB_STATE_SEND_REGISTERED_PARTY = 0x67,
    WIFICLUB_STATE_SHOW_RULE_MATCH_MESSAGE = 0x68,
    WIFICLUB_STATE_WAIT_RULE_MESSAGE_TIMER = 0x69,
    WIFICLUB_STATE_WIFICLUB_APPLY_CHOSEN_RULE = 0x6A,
    WIFICLUB_STATE_SHOW_PARTY_VIOLATIONS = 0x6B,
    WIFICLUB_STATE_SHOW_BOX_PARTY_VIOLATIONS = 0x6C,
    WIFICLUB_STATE_CLOSE_VIOLATION_LIST = 0x6D,
    WIFICLUB_STATE_BRANCH_ON_SEAT = 0x6E,
    WIFICLUB_STATE_OPEN_WAIT_PROMPT = 0x6F,
    WIFICLUB_STATE_POLL_WAIT_PROMPT = 0x70,
    WIFICLUB_STATE_WAIT_KEY_DISCONNECT_TO_LOBBY = 0x71,
    WIFICLUB_STATE_DISCONNECT_TO_LOBBY = 0x72,
    WIFICLUB_STATE_HANDLE_PEER_PHASE = 0x73,
    WIFICLUB_STATE_CLOSE_MESSAGE_ON_KEY = 0x74,
    WIFICLUB_STATE_APPLY_RULE_SELECTION = 0x75,
    WIFICLUB_STATE_REQUEST_JOIN_PARTNER = 0x76,
    WIFICLUB_STATE_VIOLATION_LIST_KEY = 0x77,
    WIFICLUB_STATE_RULE_TEXT_KEY = 0x78,
    WIFICLUB_STATE_BRANCH_ON_SEAT_AFTER_NOTIFY = 0x79,
    WIFICLUB_STATE_RULE_PREVIEW_DONE = 0x7A,
    WIFICLUB_STATE_RULE_PREVIEW_KEY = 0x7B,
    WIFICLUB_STATE_RULE_PREVIEW_CLOSE = 0x7C,
    WIFICLUB_STATE_SHOW_RULE_CHOICE_MESSAGE = 0x7D,
    WIFICLUB_STATE_OPEN_RULE_CHOICE_PROMPT = 0x7E,
    WIFICLUB_STATE_POLL_RULE_CHOICE_PROMPT = 0x7F,
    WIFICLUB_STATE_SEND_SEAT_REQUEST = 0x80,
    WIFICLUB_STATE_SEND_MODE_TO_PEER = 0x81,
    WIFICLUB_STATE_SHOW_DECLINE_MESSAGE = 0x82,
    WIFICLUB_STATE_SHOW_PARTNER_MENU_MESSAGE = 0x83,
    WIFICLUB_STATE_SHOW_LEAVE_MESSAGE_BY_SEAT = 0x84,
    WIFICLUB_STATE_EXIT_RULE_FAIL = 0x85,
    WIFICLUB_STATE_SHOW_MENU_REJECT = 0x86,
    WIFICLUB_STATE_SEND_CHOICE_MESSAGE = 0x87,
    WIFICLUB_STATE_WAIT_PARTNER_RESPONSE = 0x88,
    WIFICLUB_STATE_POLL_CANCEL_REQUEST_PROMPT = 0x89,
    WIFICLUB_STATE_START_REPLY_SYNC = 0x8A,
    WIFICLUB_STATE_SEND_REPLY_CODE = 0x8B,
    WIFICLUB_STATE_CANCEL_ON_KEY = 0x8C,
    WIFICLUB_STATE_RETURN_TO_IDLE = 0x8D,
    WIFICLUB_STATE_RESET_NET_OPTIONS = 0x8E,
    WIFICLUB_STATE_COUNTDOWN_EXIT = 0x8F,
    WIFICLUB_STATE_SYNC_AS_GUEST = 0x90,
    WIFICLUB_STATE_LEAVE_TIMEOUT = 0x91,
    WIFICLUB_STATE_SEND_VCHAT_READY = 0x92,
    WIFICLUB_STATE_LEAVE_SYNC_WAIT = 0x93,
    WIFICLUB_STATE_LEAVE_DELAY = 0x94,
    WIFICLUB_STATE_VCHAT_INVITE = 0x95,
    WIFICLUB_STATE_KEY_THEN_EXIT = 0x96,
    WIFICLUB_STATE_SHOW_DISCONNECT_NOTICE = 0x97,
    WIFICLUB_STATE_SYNC_AFTER_PARTY_SEND = 0x98,
    WIFICLUB_STATE_SHOW_LEAVE_MESSAGE_BY_ROLE_B = 0x99,
    WIFICLUB_STATE_WAIT_VCHAT_END = 0x9A,
    WIFICLUB_STATE_START_LEAVE_SYNC = 0x9B,
    WIFICLUB_STATE_SHOW_LEAVE_MESSAGE_PARENT = 0x9C,
    WIFICLUB_STATE_CANCEL_ON_KEY_AFTER_MESSAGE = 0x9D,
    WIFICLUB_STATE_LOBBY_CONNECTED = 0x9E,
    WIFICLUB_STATE_DISCONNECT_SYNC = 0x9F,
    WIFICLUB_STATE_OPEN_MENU_CHOICE_PROMPT = 0xA0,
    WIFICLUB_STATE_POLL_MENU_CHOICE_PROMPT = 0xA1,
    WIFICLUB_STATE_OPEN_REQUEST_PROMPT = 0xA2,
    WIFICLUB_STATE_POLL_REQUEST_PROMPT = 0xA3,
    WIFICLUB_STATE_OPEN_NOTICE_YES_NO = 0xA4,
    WIFICLUB_STATE_NOTICE_YES_NO = 0xA5,
    WIFICLUB_STATE_OPEN_VOICE_YES_NO = 0xA6,
    WIFICLUB_STATE_VOICE_YES_NO = 0xA7,
    WIFICLUB_STATE_DISABLE_AUTO_EXIT_A = 0xA8,
    WIFICLUB_STATE_SHOW_LEAVE_MESSAGE_BY_ROLE_A = 0xA9,
    WIFICLUB_STATE_OPEN_LEAVE_PROMPT = 0xAA,
    WIFICLUB_STATE_POLL_LEAVE_PROMPT = 0xAB,
    WIFICLUB_STATE_WAIT_SYNC_AND_CONTINUE = 0xAC,
    WIFICLUB_STATE_SEND_CHOICE_AFTER_DELAY = 0xAD,
    WIFICLUB_STATE_COUNT = 0xAE
} WifiClubState;

/* Session record the work object points to (WifiClubWork.session). */
typedef struct WifiClubSession {
    struct WifiClubPlayerStatus *localStatus;  /* 0x00 */
    void *gameData;                /* 0x04 */
    void *saveData;                /* 0x08 */
    int isFriendMatch;             /* 0x0C: nonzero when the visit started from a friend match */
    int targetFriendIndex;         /* 0x10: friend picked by the network layer when the visit ends */
    void *seatParty[2];            /* 0x14: party snapshot sent for the parent and child seat */
    void *regulation;              /* 0x1C: regulation data copied out when the visit ends */
    u8 ruleOption;                 /* 0x20: option picked in the rule menu (stored as 1 - choice) */
    u8 ruleKind;                   /* 0x21: rule kind picked in the rule menu */
    u8 ruleLevel;                  /* 0x22: rule level picked in the rule menu */
    u8 pad23;
    u8 memberChangeCount[32];      /* 0x24: changeCount last seen for each member slot */
    u8 voiceChat[2];               /* 0x44: voice chat flag per seat (index 0 = local console) */
    u8 ownSeat;                    /* 0x46: seat index of this console (0 or 1) */
    u8 visitedSeat;                /* 0x47: seat copied into WifiClubWork.selectedPlusOne on return */
    u8 regulationId;               /* 0x48: rule set shown in the violation list */
    u8 connectionMode;             /* 0x49 */
} WifiClubSession;

/* Map and sprite resources the club screen loads (lives at WifiClubWork.bgLoad). */
typedef struct WifiClubBgLoad {
    void *screenHandle;            /* 0x00: loaded screen resource */
    void *screenData;              /* 0x04: its data, first halfword is the width in pixels */
    void *cellHandle;              /* 0x08: loaded cell resource */
    void *cellData;                /* 0x0C */
    u32 mainRegion;                /* 0x10: tile region of layer 1, offset in the low half, size in the high half */
    u32 subRegion;                 /* 0x14: tile region of layer 6, same packing */
} WifiClubBgLoad;

/* Status record of one visitor (the local one at WifiClubWork.localStatus, peers in the actor table). */
typedef struct WifiClubPlayerStatus {
    u32 idA;                       /* 0x00 */
    u32 idB;                       /* 0x04 */
    u8 deviceAddr[6];              /* 0x08 */
    u8 peerAddr[6];                /* 0x0E */
    u8 avatarStyle;                /* 0x14 */
    u8 iconKind;                   /* 0x15 */
    u8 visitorKind;                /* 0x16 */
    u8 actionArg;                  /* 0x17 */
    u8 actionState;                /* 0x18 */
    u8 colorA;                     /* 0x19 */
    u8 colorB;                     /* 0x1A */
    u8 flagBit0 : 1;               /* 0x1B */
    u8 seatFlag : 1;
    u8 gender : 2;
    u8 modeFlag : 1;
    u8 flagBits567 : 3;
    u8 changeCount;                /* 0x1C: bumped each time the record is republished */
    u8 pad1D[3];
} WifiClubPlayerStatus;

struct WifiClubWork;

/* Header word block BMP_MENULIST_Create reads (13 words). */
typedef struct WifiClubMenuListHeader {
    void *menuWork;                /* 0x00: BMP_MENUWORK holding the items */
    u32 reserved04;
    u32 reserved08;
    BmpWin *win;                   /* 0x0C */
    u16 count;                     /* 0x10: item count */
    u16 rows;                      /* 0x12: visible rows */
    u32 reserved14;
    u32 reserved18;
    struct WifiClubWork *owner;    /* 0x1C */
    u32 reserved20;
    u32 reserved24;
    void *pending;                 /* 0x28: points at WifiClubWork.menuPending */
    PrintQue *printQueue;          /* 0x2C */
    void *font;                    /* 0x30 */
} WifiClubMenuListHeader;

/* One message-and-value row of a menu list. */
typedef struct WifiClubMenuItem {
    u32 messageId;
    u32 value;
} WifiClubMenuItem;

/* Screen data of the detail panel (only the size field is read). */
typedef struct WifiClubPanelScreen {
    u8 pad00[8];
    u32 dataSize;                  /* 0x08 */
    u8 data[1];                    /* 0x0C */
} WifiClubPanelScreen;

/* Handed to the menu list as header word 10. */
typedef struct WifiClubMenuPending { BmpWin *win; u8 pending; u8 pad05[3]; } WifiClubMenuPending;

typedef struct WifiClubWork {
    /* 0x000 */ void *updateTask;            /* task running WIFICLUB_VBlankTask, deleted with func_02030EAC */
    /* 0x004 */ void *friendList;            /* func_02009864(list, idx, field): 8 trainer id, 9 sex, 2..7 stats */
    /* 0x008 */ WifiClubPlayerStatus *localStatus;
    u8 pad0C[4];
    /* 0x010 */ u8 visibleList[32];          /* five tables of 32 bytes, one byte per member slot: +0x10 .. +0xB0 */
    u8 pendingList[32];
    u8 shownActorState[32];
    u8 shownActorFlags[32];
    u8 shownActorExtra[32];
    /* 0x0B0 */ void *subMenuWork; void *subMenuList; void *menuWork; void *menuList;   /* BMP_MENUWORK / BMP_MENULIST pairs */
    /* 0x0C0 */ void *saveData;              /* args+8; func_02008730(saveData) = my status */
    /* 0x0C4 */ void *gameData;              /* args+4 */
    /* 0x0C8 */ void *party;                 /* GAME_DATA_GetMyParty(gameData) */
    /* 0x0CC */ void *savedRegulation;       /* WIFICLUB_LoadSavedRegulation(gameData); nonzero = custom regulation present */
    u8 padD0[8];
    /* 0x0D8 */ void *myStatus;              /* func_0200873C(saveData) */
    /* 0x0DC */ WordSet *wordSet;
    /* 0x0E0 */ MsgData *msgBank; MsgData *msgBankAlt;
    /* 0x0E8 */ void *textFont; void *nameFont;
    /* 0x0F0 */ StrBuf *rawText; StrBuf *printText; StrBuf *shortText; StrBuf *extraText; /* F0,F4,F8(0xB4 bytes),FC; created in WIFICLUB_CreateTextBuffers */
    /* 0x100 */ u8 *timeIcon;
    u8 pad104[4];
    /* 0x108 */ void *yesNoMenu;
    u8 pad10C[4];
    /* 0x110 */ void *clactUnit; void *clactRenderer;
    /* 0x118 */ s32 partyIconChar[12];
    /* 0x148 */ s32 partyIconPalette; s32 partyIconCellAnim;
    /* 0x150 */ void *partyIconActor[12];
    /* 0x180 */ void *trainerActor; s32 trainerChar; s32 trainerPalette; s32 trainerCellAnim;
    /* 0x190 */ BmpWin *talkWin, *playerInfoWin, *headerWin, *noticeWin, *partyWin, *menuWin, *extraWin;
    /* 0x1AC */ WifiClubMenuPending menuPending;
    /* 0x1B4 */ PrintQue *menuPrintQueue; PrintQue *msgPrintQueue; PrintStream *printStream; void *tcbl;
    /* 0x1C4 */ int idleTimer;               /* reset to 0xE10 */
    /* 0x1C8 */ int waitFrames;              /* counts up; > 0xE10 raises net error 0x3F1 */
    /* 0x1CC */ int state;                   /* index into handler table gWifiClubStateHandlers (0xAE entries) */
    /* 0x1D0 */ int sceneKind;               /* 4, 5, 6 */
    u8 pad1D4[4];
    /* 0x1D8 */ u32 entryMode;               /* args+0xC */
    u8 pad1DC[4];
    /* 0x1E0 */ int counter;
    u8 pad1E4[4];
    /* 0x1E8 */ int busyFlag;
    u8 pad1EC[4];
    /* 0x1F0 */ int partnerIndex;            /* -1 = none */
    /* 0x1F4 */ u16 memberIds[32];
    /* 0x234 */ u16 menuCursor[6];           /* 0x234 + kind*2 */
    /* 0x240 */ u16 menuKind;
    /* 0x242 */ u16 selectedPlusOne;         /* index of the picked member + 1 */
    /* 0x244 */ u16 pendingFlag;
    /* 0x246 */ u16 choice;
    /* 0x248 */ WifiClubSession *session;    /* the proc args */
    /* 0x24C */ WifiClubPlayerStatus ownStatus;   /* record published to the peers, 0x20 bytes */
    /* 0x26C */ u8 streamWait[8];            /* wait-for-key state of the message stream */
    /* 0x274 */ WifiClubActorSys actorSys;   /* 0x5A0 bytes */
    /* 0x814 */ void *peerSlots[33];
    /* 0x898 */ WifiClubBgLoad bgLoad;       /* 0x18 bytes */
    /* 0x8B0 */ WordSet *detailWordSet; void *panelCharFile; void *panelCharData; void *panelScreenFile; void *panelScreenData;
    u8 pad8C4[4];
    /* 0x8C8 */ void *buttonMan;
    /* 0x8CC */ u8 buttonState[4][8];
    /* 0x8EC */ u8 page; u8 selectedSlotPlusOne; u8 cursorSlot; u8 touchPhase; u8 pad8F0; u8 pageRedraw; u8 blinkStep; u8 hoverSlotPlusOne;
    /* 0x8F4 */ int touchDirty;
    /* 0x8F8 */ BmpWin *slotWin[8];
    /* 0x918 */ BmpWin *pairWin[8][2];
    /* 0x958 */ BmpWin *nameWin; BmpWin *statWin;
    u8 pad960[0x48];
    /* 0x9A8 */ int fileIndex;
    /* 0x9AC */ void *touchBar; void *keyCursor; u32 touchBarOn;
    u8 pad9B8[0x1328 - 0x9B8];
    /* 0x1328 */ u16 ready; u16 mapIndexPlusOne; u16 menuAction; u8 pad132E[2];
    /* 0x1330 */ u32 menuFrameBase; u32 windowFrameBase;
    void *textBufferC;               /* 0x1338: word buffer created with func_0201F5DC */
    u8 pad133C[4];
    /* 0x1340 */ u8 bgmVolume, bgmVolumeFrom, bgmVolumeTarget, bgmFadeFrames;
    /* 0x1344 */ StrBuf **regulationText;     /* POKE_REGULATION_CreateText result: 12 rule strings from index 1 */
    /* 0x1348 */ void *regulationData;       /* POKE_REGULATION_Load result */
    /* 0x134C */ u16 ruleKind; u16 ruleLevel;
    /* 0x1350 */ u8 lastPicked, sceneReady, noticeKind, exitCode, menuPosition, sceneResult, seatReply, resumeState, closeFlag; u8 pad1359[3];
    /* 0x135C */ int connectionMode;         /* 1..4; 3 and 4 = parent/child seat */
} WifiClubWork;
#endif
