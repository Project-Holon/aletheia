/*
 * Types of the intrude sub screen (ov018): the touch screen of the Palace
 * visit. One work block of 0x170 bytes holds the graphics, the text, the
 * 21 actors and the state of the screen. Needs u8, u16, u32, s8, s16 and s32
 * and ../ov011/intrude_comm_types.h from the including file.
 */
#ifndef INTRUDE_SUBDISP_TYPES_H
#define INTRUDE_SUBDISP_TYPES_H

#include "../types.h"

struct GameSystem;
struct GfFont;
struct Tcbl;
struct WordSet;
struct PrintQue;
struct MsgBank;
struct Strbuf;
struct BmpWin;
struct Bmp;
struct BmpOam;
struct BmpOamSys;
struct Unit;
struct ClactRenderer;
struct ClactActor;
struct ClactRes;
struct TcbTask;
struct IntrudeZonePos;

enum {
    INTRUDE_SUBDISP_TOWN_COUNT = 8,         /* actors 0..7 */
    INTRUDE_SUBDISP_ACTOR_PALACE = 8,
    INTRUDE_SUBDISP_ACTOR_COUNT = 21
};

/* Row of the town table d_02176AA0: where a town icon sits and which zones it stands for. */
typedef struct IntrudeTownEntry {
    u16 zoneA;
    u16 zoneB;
    u8 x;
    u8 y;
} IntrudeTownEntry;

/* Record of the session that decides which message the info line prints (0x29 bytes at least). */
typedef struct IntrudeSubdispSel {
    u8 pad00[4];
    u32 kind : 4;               /* 0x04: 4 = none */
    u32 mode : 3;
    u32 msgId : 11;
    u32 rest : 14;
    u8 pad08[0x10];
    u8 words[0x10];             /* 0x18: word set arguments of the message */
    u8 peerIndex;               /* 0x28 */
} IntrudeSubdispSel;

/* Copy of the visit state that decides what the screen shows (0x14 bytes, at 0xD8 in the work). */
typedef struct IntrudeSubdispTownState {
    u8 homeSlot;                /* 0x00: own player index; the page that is shown */
    u8 peerMask;                /* 0x01: one bit per player in the visit */
    u8 peerCount;               /* 0x02 */
    u8 specialZone;             /* 0x03 */
    int sessionState;           /* 0x04: 2 to 4 = the info panel is shown */
    int number;                 /* 0x08: value shown on the info icon */
    IntrudeSubdispSel *selection; /* 0x0C: record the session reports for the touched peer, 0 = none */
    u8 partnerHome;             /* 0x10: home slot of the touched peer */
    u8 busyFlag;                /* 0x11 */
    u8 sameHomeFlag;           /* 0x12: another peer has the same home slot */
} IntrudeSubdispTownState;

/* One remembered town of a peer: zone table entry and the zone it was looked up for. */
typedef struct IntrudeSubdispPeerTown {
    struct IntrudeZonePos *town; /* 0x00: entry of the shared zone table */
    u16 zoneId;                 /* 0x04 */
    u16 pad06;
} IntrudeSubdispPeerTown;

/* Graphics data of the number sprite (tile data at 0x14). */
typedef struct IntrudeSubdispGfx {
    u8 pad00[0x14];
    u8 *tiles;                  /* 0x14 */
} IntrudeSubdispGfx;

#include "../arm9/clact.h"

/* A screen position: the clact vector. */
typedef struct ClactVec2 IntrudeSubdispPos;

/* Where a slot icon goes: its own position and the position of the marker beside it. */
typedef struct IntrudeSubdispPosPair {
    IntrudeSubdispPos marker;
    IntrudeSubdispPos pos;
} IntrudeSubdispPosPair;

/* Slots of the mark actors that are shown: slot[] holds the page numbers, pos the screen position. */
typedef struct IntrudeSubdispMarkLayout {
    u8 slot[4];
    IntrudeSubdispPos pos;
} IntrudeSubdispMarkLayout;

typedef struct IntrudeSubdispRect {
    int left;
    int top;
    int right;
    int bottom;
} IntrudeSubdispRect;

/* Message request filled by the session: the message ID and up to two words for the word set. */
struct Strbuf;
typedef struct IntrudeSubdispMsgReq {
    struct Strbuf *words[2];
    u8 slot[2];
    u8 param[2];
    u16 msgId;
} IntrudeSubdispMsgReq;

/* Geometry of one actor, as the clact add function reads it. */
typedef struct ActorInitParam IntrudeSubdispActorParam;

#include "../arm9/bmp_oam.h"

/* Template of the bmp oam of a button. */
typedef struct BmpOamParam IntrudeSubdispBmpOamTmpl;

typedef struct IntrudeSubdispWork {
    struct GameSystem *gameSystem;              /* 0x00 */
    s32 charRes;                   /* 0x04: town and mark icons */
    s32 palRes;                    /* 0x08 */
    s32 bmpOamPalRes;              /* 0x0C: palette of the button bitmaps */
    s32 cellRes;                   /* 0x10 */
    s32 infoCharRes;               /* 0x14: number sprite */
    s32 infoCellRes;               /* 0x18 */
    struct GfFont *font;                        /* 0x1C */
    struct Tcbl *tcbl;                          /* 0x20 */
    struct WordSet *wordSet;                    /* 0x24 */
    struct PrintQue *printQue;                  /* 0x28 */
    struct MsgBank *msgData;                    /* 0x2C: message file 0x2D */
    struct MsgBank *msgDataDetail;              /* 0x30: message file 0x42 */
    struct TcbTask *vblankTask;                 /* 0x34 */
    struct Strbuf *strbufMsg;                   /* 0x38 */
    struct Strbuf *strbufText;                  /* 0x3C */
    struct Strbuf *strbufTitle;                 /* 0x40 */
    struct BmpWin *titleWin;                    /* 0x44 */
    u8 titlePending;                            /* 0x48: title transfer to VRAM not done yet */
    u8 pad49[3];
    struct BmpWin *infoWin;                     /* 0x4C */
    u8 infoPending;                             /* 0x50 */
    u8 pad51[3];
    struct Unit *clactUnit;                   /* 0x54 */
    struct ClactRenderer *renderer;             /* 0x58 */
    struct ClactActor *actors[INTRUDE_SUBDISP_ACTOR_COUNT]; /* 0x5C: 0..7 towns, 8 palace, 9..11 player marks, 12..14 town marks, 15 own player, 16 button, 17..19 player icons, 20 info icon */
    struct BmpOamSys *bmpOamSys;                /* 0xB0 */
    struct Bmp *buttonBitmaps[2];               /* 0xB4 */
    u8 padBC[4];
    struct BmpOam *buttonOams[2];               /* 0xC0 */
    void *numberRes;               /* 0xC8 */
    IntrudeSubdispGfx *numberGfx;               /* 0xCC */
    u8 *numberBuf;                              /* 0xD0: 0x200 bytes, three digits of two tiles */
    u32 numberVram;                             /* 0xD4: where the digits are copied to */
    IntrudeSubdispTownState town;               /* 0xD8 */
    IntrudeSubdispPeerTown peerTowns[3];        /* 0xEC */
    u8 lastPalette;                             /* 0x104 */
    u8 lastBgPalette;                           /* 0x105: 0xFF = none yet */
    u8 warpPending;                             /* 0x106: Palace icon touched, wait for the warp */
    u8 warpStep;                                /* 0x107 */
    s16 msgTimer;                               /* 0x108: frames the info message stays */
    s16 digitsValue;                            /* 0x10A: number shown, -1 = none */
    u8 titleMode;                               /* 0x10C */
    u8 msgState;                                /* 0x10D */
    u8 msgToggle;                               /* 0x10E */
    u8 digitsDirty;                             /* 0x10F: numberBuf has to be copied */
    u16 targetZone;                             /* 0x110: zone of the touched town */
    u8 selectionKind;                           /* 0x112: 0 none, 1 town, 2 peer */
    u8 selectedActor;                           /* 0x113: index in actors of the touched town */
    u8 blinkActive;                             /* 0x114: town icon blinks */
    u8 blinkCount;                              /* 0x115 */
    u8 buttonBlinkActive;                       /* 0x116 */
    u8 buttonBlinkCount;                        /* 0x117 */
    s16 cursorPulse;                            /* 0x118 */
    s8 cursorPulseDir;                          /* 0x11A */
    u8 cursorActor;                             /* 0x11B: index of the highlighted actor, 0xFF = none */
    u8 paletteDirty;                            /* 0x11C */
    u8 vblankPhase;                             /* 0x11D */
    u8 lastPeerCount;                           /* 0x11E */
    u8 bgLayerVariant;                          /* 0x11F */
    u16 palBase[4];                          /* 0x120 */
    u16 palTarget[4];                         /* 0x128 */
    u16 palOut[4];                          /* 0x130 */
    u16 infoPalette[0x18];                      /* 0x138: 0x30 bytes */
    u8 noIntrude;                               /* 0x168: touched, no intrusion wanted */
    u8 pendingPeer;                             /* 0x169: peer touched, 4 = none */
    u8 lastPeer;                                /* 0x16A */
    u8 peerBlinkCount;                          /* 0x16B */
    u8 infoShown;                               /* 0x16C */
    u8 pad16D[3];
} IntrudeSubdispWork;

#endif
