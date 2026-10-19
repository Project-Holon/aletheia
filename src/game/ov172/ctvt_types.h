#ifndef CTVT_TYPES_H
#define CTVT_TYPES_H

/*
 * Owner header of the C-Gear video chat overlay (ov172): the screen work
 * record CtvtWork and the records its sub-systems keep behind pointers.
 */

#include "ctvt_camera_types.h"

#include "../types.h"

/* Opaque library objects. */
struct ClActor;
struct BmpWin;
struct PrintQue;
struct MsgData;
struct StrBuf;
struct TaskMenu;
struct TimeIcon;
struct ArcHandle;
struct ClActUnit;
struct GameData;
struct Bmp;
struct Obj;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct Actor;
struct PrintSys;
struct MsgBank;
struct U16Vec;
struct Vec2;
struct CtvtCamView;
struct StrObj;
struct Sub0200852CObj;

/* Screen and window parameter records shared by the overlay files. */
typedef struct { u16 heap; u8 kind, pad; u16 count, a, b, c, d; } Params;

/* One 0xE byte cell actor sprite placement. */
struct Desc {
    s16 x;
    s16 y;
    s16 z;
    u8  a;
    u8  b;
};

struct SpritePos {
    s16 x;
    s16 y;
};

/* Window descriptor handed to the BMP_WIN and PRINTSYS helpers. */
typedef struct { unsigned int heap; u8 count; u8 pad[3]; void *items; unsigned int zero; u8 a, b, c, d; } Descriptor;

/* Sub-system records behind the CtvtWork pointers. */
struct CtvtComm;
struct CtvtTalk;
struct CtvtCall;
struct CtvtSprites;

/* Screen numbers of the CtvtWork state machine. */
#define CTVT_SCREEN_TALK       1
#define CTVT_SCREEN_CALL       2
#define CTVT_SCREEN_DRAW       3
#define CTVT_SCREEN_CAM_SETUP  4
#define CTVT_SCREEN_CAM_WIPE   5

/* Launch parameters handed to the overlay (16 bytes). */
typedef struct CtvtLaunchParams {
    struct GameData *gameData;
    u32 mode;               /* 0 and 1: start from the menu, 2: invited, 3: call from the field */
    u8 peerParam[8];        /* copied into the comm record when mode is 2 */
} CtvtLaunchParams;

/* Work record of the video chat overlay, allocated by the process init.
 * Size 0x1FC. */
typedef struct CtvtWork {
    u16 heapId;
    u8 pad2[2];                 /* alignment before the task pointer */
    void *vblankTask;           /* per-frame task, runs the palette fade */
    s32 screen;                 /* CTVT_SCREEN_* now running */
    s32 nextScreen;             /* CTVT_SCREEN_* requested by the running screen */
    s32 returnedFromChild;      /* 1: wipe differs when a child screen returns */
    s32 netErrorPending;        /* 1: the network error screen was requested */
    u8 memberCount;
    u8 selfSlot;
    u8 pad1A[2];                /* alignment before the next word */
    s32 halfRes;                /* 1: camera frames are half resolution */
    s32 messageActive;          /* 1: a message panel is on the lower screen */
    s32 viewSwapped;            /* toggled by Select/Start: swaps the camera layout */
    s32 inputLocked;            /* 1: touch input is ignored */
    s32 endRequested;           /* 1: the player asked to leave the chat */
    s32 hostBusy;               /* set at init when the wireless stack reports a busy state */
    s32 cameraBusy;             /* 1 while a camera frame is being copied */
    u16 fadePhase;              /* angle of the palette fade sine, +0x200 per frame */
    u16 fadeIndex;              /* palette row currently loaded, 0..9 */
    u8 fadePalette[10][32];     /* palette rows of the fade */
    struct ArcHandle *arc;      /* graphics archive */
    u32 resId[11];              /* cell actor resource ids: 3 groups of char, palette, cell, anim */
    struct ClActUnit *clactUnit;
    struct ClActor *marker;     /* slot marker sprite */
    signed char slotFlagA;
    signed char slotFlagB;
    u8 pad1B6[2];               /* alignment before the window array */
    struct BmpWin *bmpWin[4];   /* one name window per member slot */
    u32 font;
    struct MsgData *msgData;
    struct PrintQue *printQue;
    struct TaskMenu *taskMenu;
    void *timeIconSrc;          /* source handed to TIME_ICON_CreateNode */
    struct TimeIcon *timeIcon;
    CtvtCamView *camView;
    struct CtvtComm *comm;
    struct CtvtTalk *talk;
    struct CtvtDrawScene *draw;
    struct CtvtCall *call;
    struct CtvtSprites *sprites;
    CtvtLaunchParams *launch;
} CtvtWork;

typedef char CtvtWorkSizeCheck[(sizeof(CtvtWork) == 0x1FC) ? 1 : -1];

/* Connection flags of the comm record (+0x2D). */
typedef struct CtvtCommFlags {
    u8 netIdle : 1;             /* bit 0: the wireless stack reports idle */
    u8 nameMatchActive : 1;     /* bit 1: the peer name probe is running */
    u8 rest : 6;
} CtvtCommFlags;

/* One member slot of the comm record, stride 0x40 (ctvt_comm.c). */
typedef struct CtvtPeerSlot {
    u32 active;                 /* +0x00: 1: the slot is connected */
    u32 connected;              /* +0x04: 1: the connect reply was sent */
    u32 reported;               /* +0x08: 1: the slot was reported to the menu */
    u32 isSelf;                 /* +0x0C: 1: this slot is the local player */
    u32 hit;                    /* +0x10: 1: the slot was touched */
    u8 postIndex;               /* +0x14: post work index, 0xFF = none */
    u8 pad15[3];
    u32 state;                  /* +0x18: receive post state */
    u8 peerParam[8];            /* +0x1C: peer parameter copied to the menu */
    u8 pad24[0x18];             /* +0x24: unused middle of the slot */
    u8 readyFlag;               /* +0x3C: per slot flag read by the camera view */
    u8 pad3D[3];                /* +0x3D: unused tail of the slot */
} CtvtPeerSlot;

/* A received comm message (ctvt_comm.c CTVT_COMM_HandleMessage). */
typedef struct CtvtCommMsg {
    u32 value;                  /* +0x00: payload word */
    u8 command;                 /* +0x04: message id */
} CtvtCommMsg;

/* Network side of the video chat overlay (ctvt_comm.c). Size 0x3E0. */
typedef struct CtvtComm {
    u32 state;                  /* +0x00: 1 once the session started */
    u8 memberCount;             /* +0x04: connected member count */
    u8 pad05[3];
    u32 netState;               /* +0x08: network state machine state */
    u8 myStatus[0x20];          /* +0x0C: local MYSTATUS copy */
    u8 prevMemberCount;         /* +0x2C: member count at the last change */
    CtvtCommFlags flags;        /* +0x2D: connect flags */
    u8 peerName[18];            /* +0x2E: three six byte peer name records */
    u8 peerStatus[0x20];        /* +0x40: peer status block sent with 0x2003 */
    u8 netIdle;                 /* +0x60: the wireless stack reports idle */
    u8 pad61[3];
    CtvtPeerSlot peers[4];      /* +0x64: one slot per member, stride 0x40 */
    void *postWork[3];          /* +0x164: post work buffers */
    u8 postWorkMask;            /* +0x170: bit per used post work buffer */
    u8 pad171[3];
    u32 netMode;                /* +0x174: negotiated network mode */
    u32 requestedMode;          /* +0x178: requested network mode */
    u8 connectMac[6];           /* +0x17C: parent MAC address for the connect */
    u8 sendMask;                /* +0x182: peers with a pending frame send */
    u8 voiceMask;               /* +0x183: peers that sent a voice packet */
    u32 sendBusy;               /* +0x184: 1: a frame send is in flight */
    void *jpegWork;             /* +0x188: JPEG encoder work buffer */
    void *frameBuf;             /* +0x18C: camera frame buffer */
    void *jpegOut;              /* +0x190: JPEG output buffer */
    u32 postBusy;               /* +0x194: 1: a post receive is in flight */
    u32 playPending;            /* +0x198: 1: a voice sample was received */
    u16 playLength;             /* +0x19C: received sample length */
    u8 pad19E[2];
    s32 playFreq;               /* +0x1A0: received sample frequency */
    void *voiceRec;             /* +0x1A4: 0x208 byte voice record */
    char *decodeBuf;            /* +0x1A8: 0xC800 byte ADPCM decode buffer */
    u8 writeCursor;             /* +0x1AC: slot buffer write cursor, mod 0x40 */
    u8 readCursor;              /* +0x1AD: slot buffer read cursor, mod 0x40 */
    u8 slotBuf[0x200];          /* +0x1AE: 0x40 slots of eight bytes */
    u8 markerSlot;              /* +0x3AE: slot of the placed marker, 0xFF none */
    u8 pad3AF[1];
    u32 markerDirty;            /* +0x3B0: 1: a slot hit state changed */
    u32 statusDirty;            /* +0x3B4: 1: the peer status must be sent */
    u32 memberDirty;            /* +0x3B8: 1: the member count must be sent */
    u32 halfResSync;            /* +0x3BC: half resolution value to send */
    u32 strokeSendPending;      /* +0x3C0: 1: strokes must be sent */
    u32 cmd4Pending;            /* +0x3C4: 1: message 4 must be sent */
    u32 voiceStatePending;      /* +0x3C8: 1: message 5 was received */
    u32 cmd5Pending;            /* +0x3CC: 1: message 5 must be sent */
    u16 slotTimer;              /* +0x3D0: countdown after a slot change */
    u8 pad3D2[2];
    u32 slotMarkerDirty;        /* +0x3D4: 1: the slot marker must be sent */
    u8 currentSlot;             /* +0x3D8: slot of the last hit, 0xFF none */
    u8 pad3D9[3];
    void *work;                 /* +0x3DC: back pointer to CtvtWork */
} CtvtComm;

typedef char CtvtCommSizeCheck[(sizeof(CtvtComm) == 0x3E0) ? 1 : -1];

/* Drawing board screen ("Draw"): record of the pen tool screen. Size 0x98. */
typedef struct CtvtDrawScene {
    s32 state;
    u8 panelTarget;             /* tool panel slide target, 0x18 = hidden */
    u8 panelPos;                /* tool panel slide position */
    u8 pad6[2];                 /* alignment before the next word */
    s32 uiHandled;              /* 1: a button took the touch this frame */
    s32 penDown;                /* 1: the pen is dragging */
    s32 sizePickerOpen;         /* pen size picker is open */
    s32 stampPickerOpen;        /* stamp picker is open */
    s32 touchEnabled;           /* 1 after the wipe in */
    s32 exitKind;               /* 0: leave with 1, else leave with 4 */
    s32 cameraHidden;           /* 1: the camera view was hidden for a message */
    s32 drawTool;               /* 0: pen, 1: stamp, remembered across the color pick */
    s32 toolMode;               /* 0: pen, 1: color pick, 2: eraser, 3: stamp */
    u32 lastX;                  /* previous touch point, 0xFFFF = none */
    u32 lastY;
    u16 penColor;               /* 15 bit color, bit 15 set = valid */
    u8 penSize;                 /* index into the size table */
    u8 stampKind;               /* index into the stamp table */
    s32 helpPending;            /* help window needs its transfer */
    s32 helpPage;               /* 1: second page of the help text */
    s32 titlePending;           /* title window needs its transfer */
    s32 messagePending;         /* message window needs its transfer */
    struct BmpWin *helpWin;
    struct BmpWin *titleWin;
    struct BmpWin *messageWin;
    u16 messageTimer;           /* frames since the message appeared */
    u8 pad56[2];                /* alignment before the actor array */
    struct ClActor *button[6];  /* pen, pick, eraser, stamp, grid, panel arrow */
    struct ClActor *helpIcon[5];
    struct ClActor *penPicker;
    struct ClActor *stampPicker;
    struct ClActor *pickMarker;
    struct ClActor *cursor;
    u16 fadeColor;              /* backdrop color written to the palette */
    u16 fadePhase;
} CtvtDrawScene;

typedef char CtvtDrawSceneSizeCheck[(sizeof(CtvtDrawScene) == 0x98) ? 1 : -1];

/* One stroke segment of the drawing board, in a list of 8 byte records. */
typedef struct CtvtStroke {
    u8 x0;
    u8 y0;
    u8 x1;
    u8 y1;
    u16 color;              /* 15 bit color, 0 = eraser */
    u8 kind;                /* pen size or stamp index, 2 = eraser */
    u8 pad7;                /* never read or written by the code seen so far */
} CtvtStroke;

/* Microphone capture and voice playback record (ctvt_mic.c). Size 0x24.
 * The same record drives the microphone capture and the NNS wave out channel:
 * capture uses capturedBytes/capturing/captureTicks, playback uses
 * playing/playPos/length/freq/channel. */
struct NnsWaveOutSlot;
typedef struct CtvtMic {
    u32 capturedBytes;              /* +0x00: valid bytes in buffer */
    void *buffer;                   /* +0x04: 51200 byte sample buffer */
    u32 capturing;                  /* +0x08: 1 while the microphone records */
    u32 playing;                    /* +0x0C: 1 while a sample plays */
    u8 captureTicks;                /* +0x10: capture frame counter, saturates at 180 */
    u8 pad11[3];                    /* alignment before the playback position */
    u32 playPos;                    /* +0x14: playback position counter */
    u32 length;                     /* +0x18: sample length in bytes */
    u32 freq;                       /* +0x1C: sample frequency */
    struct NnsWaveOutSlot *channel; /* +0x20: NNS wave out channel */
} CtvtMic;

typedef char CtvtMicSizeCheck[(sizeof(CtvtMic) == 0x24) ? 1 : -1];

/* One voice packet of the talk screen: a 6 byte header in front of the ADPCM
 * payload (ctvt_talk.c). */
typedef struct CtvtTalkPacket {
    u16 length;             /* +0x00: payload length in bytes */
    u16 position;           /* +0x02: sample position when the packet was cut */
    u8 last;                /* +0x04: 1: final packet of the sample */
    u8 index;               /* +0x05: packet counter */
    u8 level;               /* +0x06: voice level index sent with the packet */
} CtvtTalkPacket;

/* Talk screen record (ctvt_talk.c). Size 0xAC. */
typedef struct CtvtTalk {
    s32 state;                      /* +0x00: screen state */
    s32 substate;                   /* +0x04: voice send substate */
    s32 shutterPending;             /* +0x08: 1: waiting for the shutter to go idle */
    u8 sendCooldown;                /* +0x0C: frames before another send is allowed */
    u8 levelIndex;                  /* +0x0D: voice level, 0..8, 4 = center */
    u8 sliderChoice;                /* +0x0E: voice level slider choice, 0xFF = none */
    u8 sliderHold;                  /* +0x0F: frames the slider choice has been held */
    struct CtvtMic *mic;            /* +0x10: microphone and voice playback record */
    u32 packetReady;                /* +0x14: 1: a packet was built and is being sent */
    u8 packetCount;                 /* +0x18: packets sent so far */
    u8 pad19[3];                    /* alignment before the packet pool */
    void *packetPool;               /* +0x1C: 0x808 byte packet buffer */
    CtvtTalkPacket *packet;         /* +0x20: packet being filled (= packetPool) */
    void *packetPayload;            /* +0x24: payload pointer (= packetPool + 8) */
    s32 messagePending;             /* +0x28: 1: the message window needs its transfer */
    struct BmpWin *waveformWin;     /* +0x2C: voice waveform window */
    u8 waveX;                       /* +0x30: waveform pen x */
    u8 waveY;                       /* +0x31: waveform pen y */
    s32 flashActive;                /* +0x34: 1: the palette flash is running */
    u8 flashCounter;                /* +0x38: frames of the flash */
    u8 pad39;                       /* alignment before the palettes */
    u16 flashPalette[16];           /* +0x3A: white palette written on flash frames */
    u16 savedPalette[16];           /* +0x5A: palette saved at init */
    struct BmpWin *messageWin;      /* +0x7C: message and time icon window */
    struct TaskMenu *confirmMenu;   /* +0x80: confirm menu */
    s32 timeIconPending;            /* +0x84: 1: the time icon follows the transfer */
    u16 promptTimer;                /* +0x88: frames spent on the leave prompt */
    u8 pad8A[2];                    /* alignment before the voice state */
    s32 voiceActive;                /* +0x8C: 1: a voice sample is playing */
    struct ClActor *levelActor;     /* +0x90: voice level indicator */
    struct ClActor *swapActor;      /* +0x94: view swap button */
    struct ClActor *cancelActor;    /* +0x98: leave button */
    struct ClActor *backActor;      /* +0x9C: back to talk button */
    struct ClActor *voiceActor;     /* +0xA0: voice icon */
    u32 voiceIconState;             /* +0xA4: voice icon state, 0, 1 or 2 */
    u32 voiceIconPrev;              /* +0xA8: voice icon state already shown */
} CtvtTalk;

typedef char CtvtTalkSizeCheck[(sizeof(CtvtTalk) == 0xAC) ? 1 : -1];

/* One row of the call list: the three cursor sprites and the name window of a
 * single friend row (ctvt_call.c). Stride 0x1C, first row at +0x40. */
typedef struct CtvtCallRow {
    u32 active;                 /* +0x00: 1: the row shows an entry */
    u32 pending;                /* +0x04: 1: the name window must be transferred */
    void *actorA;               /* +0x08: left cursor sprite */
    void *actorB;               /* +0x0C: middle cursor sprite */
    void *actorC;               /* +0x10: right cursor sprite */
    void *win;                  /* +0x14: name window of the row */
    u8 slot;                    /* +0x18: entry index shown on the row, 0xFF none */
} CtvtCallRow;

/* One entry of the call list: the peer a row can show (ctvt_call.c). Stride
 * 0x24, first entry at +0x1E4. */
typedef struct CtvtCallEntry {
    u32 active;                 /* +0x00: 1: the entry holds a peer */
    u32 unseen;                 /* +0x04: 1: the peer was missing from the last scan */
    u32 selected;               /* +0x08: 1: the player selected the entry */
    u32 available;              /* +0x0C: 1: the peer record reports the peer available */
    u32 dirty;                  /* +0x10: 1: the entry text must be rebuilt */
    u8 *peer;                   /* +0x14: 0x64 byte peer record buffer */
    u8 kind;                    /* +0x18: beacon kind, 0x20 or 3 */
    u8 mac[6];                  /* +0x19: peer MAC address */
    u8 level;                   /* +0x1F: signal level read from the peer record */
    u8 row;                     /* +0x20: row index the entry is shown on, 0xFF none */
    u8 pad21[3];
} CtvtCallEntry;

/* Call list screen ("Call"): the friend list of the video chat overlay
 * (ctvt_call.c). Size 0x408. */
typedef struct CtvtCall {
    u8 slotSel[3];              /* +0x00: chosen entry per member slot, 0xFF none */
    u8 selEntry;                /* +0x03: chosen entry of the last slot, 0xFF none */
    u16 scroll;                 /* +0x04: list scroll offset */
    u16 scrollPos;              /* +0x06: scroll slider position */
    u32 state;                  /* +0x08: screen state */
    u32 refresh;                /* +0x0C: 1: the rows must refresh */
    u32 sliderDrag;             /* +0x10: 1: the scroll slider is held */
    u8 rowCount;                /* +0x14: rows that show an entry */
    u8 prevRowCount;            /* +0x15: row count at the last slider update */
    u8 pad16[2];
    u32 substate;               /* +0x18: prompt and leave substate */
    u32 menuWin;                /* +0x1C: task menu window */
    u32 msgDirty;               /* +0x20: 1: the message window must transfer */
    u32 timeDirty;              /* +0x24: 1: the time window must transfer */
    u32 soundPlayed;            /* +0x28: 1: the join sound was played */
    u32 msgWin;                 /* +0x2C: message window */
    u32 timeWin;                /* +0x30: time icon window */
    u16 timerA;                 /* +0x34: connect wait timer */
    u16 timerB;                 /* +0x36: slot timer display */
    u32 timePending;            /* +0x38: 1: the time icon must be created */
    u8 pad3C[4];
    CtvtCallRow rows[15];       /* +0x40: one row per friend, stride 0x1C */
    CtvtCallEntry entries[15];  /* +0x1E4: one entry per friend, stride 0x24 */
    void *actorBack;            /* +0x400: back arrow sprite */
    void *actorSlider;          /* +0x404: scroll slider sprite */
} CtvtCall;

typedef char CtvtCallSizeCheck[(sizeof(CtvtCall) == 0x408) ? 1 : -1];

/* Accessors of CtvtWork fields and helpers (comm_tvt_sys.c). */
extern CtvtCamView *COMM_TVT_SYS_GetCamView(CtvtWork *work);
extern struct CtvtComm *COMM_TVT_SYS_GetComm(CtvtWork *work);
extern int COMM_TVT_SYS_GetTalkStatus(CtvtWork *work);
extern struct CtvtSprites *COMM_TVT_SYS_GetSprites(CtvtWork *work);
extern CtvtLaunchParams *COMM_TVT_SYS_GetLaunchParams(CtvtWork *work);
extern u16 COMM_TVT_SYS_GetHeapId(CtvtWork *work);
extern struct ArcHandle *COMM_TVT_SYS_GetArc(CtvtWork *work);
extern u32 COMM_TVT_SYS_GetResId(CtvtWork *work, int index);
extern struct ClActUnit *COMM_TVT_SYS_GetClactUnit(CtvtWork *work);
extern s32 COMM_TVT_SYS_GetReturnedFromChild(CtvtWork *work);
extern void COMM_TVT_SYS_SetReturnedFromChild(CtvtWork *work, s32 value);
extern u32 COMM_TVT_SYS_GetFont(CtvtWork *work);
extern struct MsgData *COMM_TVT_SYS_GetMsgData(CtvtWork *work);
extern struct PrintQue *COMM_TVT_SYS_GetPrintQue(CtvtWork *work);
extern struct TaskMenu *COMM_TVT_SYS_GetTaskMenu(CtvtWork *work);
extern u8 COMM_TVT_SYS_GetMemberCount(CtvtWork *work);
extern void COMM_TVT_SYS_SetMemberCount(CtvtWork *work, u32 count);
extern int COMM_TVT_SYS_GetLayoutMode(CtvtWork *work);
extern s32 COMM_TVT_SYS_GetHalfRes(CtvtWork *work);
extern void COMM_TVT_SYS_ApplyHalfRes(CtvtWork *work, s32 halfRes);
extern void COMM_TVT_SYS_ToggleHalfRes(CtvtWork *work);
extern void COMM_TVT_SYS_SetHalfRes(CtvtWork *work, s32 halfRes);
extern u8 COMM_TVT_SYS_GetSelfSlot(CtvtWork *work);
extern void COMM_TVT_SYS_SetSelfSlot(CtvtWork *work, u32 slot);
extern s32 COMM_TVT_SYS_GetMessageActive(CtvtWork *work);
extern void COMM_TVT_SYS_SetMessageActive(CtvtWork *work, s32 value);
extern s32 COMM_TVT_SYS_GetViewSwapped(CtvtWork *work);
extern void COMM_TVT_SYS_ToggleViewSwapped(CtvtWork *work);
extern s32 COMM_TVT_SYS_GetInputLocked(CtvtWork *work);
extern void COMM_TVT_SYS_SetInputLocked(CtvtWork *work, s32 value);
extern s32 COMM_TVT_SYS_GetEndRequested(CtvtWork *work);
extern void COMM_TVT_SYS_SetEndRequested(CtvtWork *work, s32 value);
extern int COMM_TVT_SYS_IsLaunchModeCall(CtvtWork *work);
extern s32 COMM_TVT_SYS_GetHostBusy(CtvtWork *work);
extern void COMM_TVT_SYS_ClearHostBusy(CtvtWork *work);
extern s32 COMM_TVT_SYS_GetCameraBusy(CtvtWork *work);
extern void COMM_TVT_SYS_SetCameraBusy(CtvtWork *work, s32 value);
extern int COMM_TVT_SYS_IsNetIdle(void);
extern struct TaskMenu *COMM_TVT_SYS_OpenConfirmMenu(CtvtWork *work);
extern void COMM_TVT_SYS_ClearNameWindows(CtvtWork *work);
extern void COMM_TVT_SYS_ClearAndTransferNameWindows(CtvtWork *work);
extern void COMM_TVT_SYS_PlaceSlotMarker(CtvtWork *work, u8 slot);
extern void COMM_TVT_SYS_HideSlotMarker(CtvtWork *work);
extern void COMM_TVT_SYS_CreateTimeIcon(CtvtWork *work, void *arg);
extern void COMM_TVT_SYS_DeleteTimeIcon(CtvtWork *work);

#endif
