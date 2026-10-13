#ifndef BTLV_B_GAUGE_TYPES_H
#define BTLV_B_GAUGE_TYPES_H

#ifndef OV093_BASIC_TYPES
#define OV093_BASIC_TYPES
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
#endif

/* Opaque types owned by other files. */
struct ClActor;
struct ClUnit;
struct BtlPokeParam;
struct Strbuf;
struct BmpData;
struct PalAnmSlot;
struct TcblTask;

/* Sound numbers. */
#define BTLV_GAUGE_SE_BALL_BAR_START 0x570
#define BTLV_GAUGE_SE_BALL_SETTLE 0x571
#define BTLV_GAUGE_SE_BALL_ALT 0x572

typedef struct BtlvGaugePoint {
    s16 x;
    s16 y;
} BtlvGaugePoint;

/* Initial values for CLACT_CreateActor (first 8 bytes of the actor init record). */
typedef struct BtlvGaugeActorInit {
    s16 x;
    s16 y;
    u16 animSeq;
    u8 drawPriority;
    u8 bgPriority;
} BtlvGaugeActorInit;

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
    struct ClActor *actor;
    int goalX;
    int homeX;
    int stepX;
    int finalAnim;
    int wait;
    BtlvGaugePoint pos;
} BtlvPartyBallEntry;

/* Party ball bar (0xe4 bytes): six balls and the frame slide in. */
typedef struct BtlvPartyBallBar {
    struct ClUnit *unit;
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
