#ifndef BTLV_B_GAUGE_TYPES_H
#define BTLV_B_GAUGE_TYPES_H

#include "../types.h"
#include "../arm9/clact.h"

/* Opaque types owned by other files. */
struct ClactActor;
struct Unit;
struct BtlPokeParam;
struct Strbuf;
struct BmpData;
struct TcblTask;

/* Sound numbers. */
#define BTLV_GAUGE_SE_BALL_BAR_START 0x570
#define BTLV_GAUGE_SE_BALL_SETTLE 0x571
#define BTLV_GAUGE_SE_BALL_ALT 0x572

/* Start and frame positions of the party ball bar per side. */
typedef struct BtlvPartyBallOrigin {
    s16 ballX;
    s16 ballY;
    s16 frameX;
    s16 frameY;
} BtlvPartyBallOrigin;

/* Argument of the party ball bar: side and the ball icon of each party member. */
typedef struct BtlvPartyBallBarParam {
    int side;
    int ballKind[6];
} BtlvPartyBallBarParam;

typedef struct BtlvPartyBallEntry {
    struct ClactActor *actor;
    int goalX;
    int homeX;
    int stepX;
    int finalAnim;
    int wait;
    struct ClactVec2 pos;
} BtlvPartyBallEntry;

/* Party ball bar (0xe4 bytes): six balls and the frame slide in. */
typedef struct BtlvPartyBallBar {
    struct Unit *unit;
    u32 charRes;
    u32 cellRes;
    u32 palRes;
    BtlvPartyBallEntry entries[7];      /* 0..5 balls, 6 frame */
    int state;
    int active;
    int sound;
    u16 heapId;
} BtlvPartyBallBar;

typedef struct BtlvPartyBallTaskArg {
    BtlvPartyBallBar *bar;
} BtlvPartyBallTaskArg;

#endif
