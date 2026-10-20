#ifndef GAME_OV105_IRC_RESULT_TYPES_H
#define GAME_OV105_IRC_RESULT_TYPES_H

/* Types of the infrared compatibility result screen (irc_result.c).  The text
 * system, text window and profile types are the display kit that the rhythm
 * game (ov104/irc_rhythm.c) also carries. */

#include "../ov104/irc_rhythm_types.h"

#define IRC_RESULT_ACTOR_COUNT 38
#define IRC_RESULT_ACTOR_DIGIT 0      /* three digit sprites, hundreds first */
#define IRC_RESULT_ACTOR_EFFECT 37    /* full screen effect sprite */

typedef struct IrcResultActorSystem {
    struct Unit *unit;
    int paletteId;
    int characterId;
    int cellAnimId;
    struct ClactActor *actors[IRC_RESULT_ACTOR_COUNT];
} IrcResultActorSystem;

typedef struct IrcResultScreen {
    u32 bgCharRegion;        /* low half: offset, high half: size of the loaded background characters */
    IrcResultActorSystem actorSystem;
    void *vblankTask;
} IrcResultScreen;

/* The three score digits. */
typedef struct IrcResultScoreDisplay {
    struct ClactActor *digitActors[3];   /* hundreds, tens, ones */
    u16 animFrame[3];
    u16 animLength[3];
    int animStep[3];
    u8 reserved[12];
    u8 digits[3];                 /* ones, tens, hundreds */
    u8 reserved33;
    int digitState[3];            /* 0 hidden, 1 shown */
} IrcResultScoreDisplay;

/* Lights the rank bars of the score by blending palette entries. */
typedef struct IrcResultRankFade {
    u16 id;
    u8 reserved2[6];
    u16 targetColors[16];
    u16 workColors[16];
    u32 frame;
    u32 finished;
    u32 running;
    u16 phaseCount;
    u16 phase;
    u32 step;
    int nearNextRank;
} IrcResultRankFade;

typedef struct IrcResultContext {
    void *gameSystem;
    IrcSys *ircSys;
    IrcCompatibleProfile *partner;
    u8 score;
} IrcResultContext;

struct IrcResult;
typedef void (*IrcResultStateFn)(struct IrcResult *work, u16 *step);

typedef struct IrcResult {
    IrcResultScreen screen;
    IrcTextSystem text;
    IrcTextWindow messageWindow;
    IrcTextWindow captionWindow;
    IrcResultScoreDisplay scoreDisplay;
    IrcResultRankFade rankFade;
    IrcAppBar *appBar;
    IrcResultStateFn stateFn;
    u16 stateStep;
    u16 reserved192;
    u32 finished;
    u32 waitFrames;
    int bonusDay;
    u32 rewardQuantity;
    IrcResultContext *context;
} IrcResult;

#endif
