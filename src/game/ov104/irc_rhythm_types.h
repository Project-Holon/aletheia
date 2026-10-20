#ifndef GAME_OV104_IRC_RHYTHM_TYPES_H
#define GAME_OV104_IRC_RHYTHM_TYPES_H

/* Types of the infrared compatibility rhythm game (irc_rhythm.c).  The first
 * block (screen, actor system, text system, text window) is the display kit
 * that every game of the infrared compatibility check carries as its own
 * copy; the result screen (ov105/irc_result.c) includes this header for it. */

#include "../types.h"

#include "../ov101/compatible_irc_sys_types.h"
#include "../ov101/irc_appbar.h"

#include "../sdk_fx.h"

typedef struct IrcPoint { int x, y; } IrcPoint;

#define IRC_PALETTE_TARGET 15          /* destination selector of the palette write helper */
#define IRC_GRAPHICS_ARCHIVE_ID 0x5e   /* archive with the backgrounds, sprites and windows of the infrared games */

/* ---- display kit shared with the other infrared games ---- */

/* Placement record passed to CLACT_CreateActor: screen position and depth. */
typedef struct IrcActorPlacement {
    u16 x;
    u16 y;
    u16 depth;
    u16 reserved;
} IrcActorPlacement;

#define IRC_ACTOR_SYSTEM_ACTOR_COUNT 35

/* Sprite system: one actor unit, three registered resource sets and the
 * actors created from them. */
typedef struct IrcActorSystem {
    struct Unit *unit;
    int particlePalette;
    int particleCharacter;
    int particleCellAnim;
    int subParticlePalette;
    int subParticleCharacter;
    int subParticleCellAnim;
    int countdownPalette;
    int countdownCharacter;
    int countdownCellAnim;
    struct ClactActor *actors[IRC_ACTOR_SYSTEM_ACTOR_COUNT];
} IrcActorSystem;

/* Background and sprite state of one game screen. */
typedef struct IrcScreen {
    u32 bgCharRegion;        /* low half: offset, high half: size of the loaded background characters */
    IrcActorSystem actorSystem;
    void *vblankTask;
} IrcScreen;

#include "../ov102/irc_text_system_types.h"

/* A text window: the window, the bitmap it prints into, the print state and
 * the string buffer. */
typedef struct IrcTextWindow {
    void *window;
    void *printTarget;
    u8 isPrinting;
    u8 reserved9[3];
    void *buffer;
    u16 clearColor;
} IrcTextWindow;

/* ---- rhythm game ---- */

#define IRC_RHYTHM_TAP_COUNT 10

/* One tap: time since the start and time since the previous tap, in
 * milliseconds. */
typedef struct IrcRhythmTap {
    u32 time;
    u32 interval;
} IrcRhythmTap;

/* The taps of one player; also the record the two players exchange. */
typedef struct IrcRhythmRecord {
    IrcRhythmTap taps[15];   /* only IRC_RHYTHM_TAP_COUNT are used */
    u16 tapCount;
    u16 extraTaps;           /* taps after the last counted one, capped at 99 */
    u32 startTime[2];        /* 64-bit millisecond tick, low word first */
} IrcRhythmRecord;

/* Exchange of the two records over the infrared link. */
typedef struct IrcRhythmNetSync {
    IrcSys *ircSys;
    u32 sendStep;
    IrcRhythmRecord received[2];   /* [0] partner, [1] own echo */
    IrcRhythmRecord sendBuffer;
    u32 receivedFlag;
} IrcRhythmNetSync;

typedef struct IrcRhythmParticle {
    struct ClactActor *actor;
    u32 surface;
    u32 active;
    VecFx32 start;
    VecFx32 end;
    u32 counter;
    u32 lifetime;
} IrcRhythmParticle;

#define IRC_RHYTHM_PARTICLE_COUNT 30

typedef struct IrcRhythmParticles {
    IrcRhythmParticle particles[IRC_RHYTHM_PARTICLE_COUNT];
    u32 mode;
    u32 spawnTimer;
    u32 spawnInterval;
} IrcRhythmParticles;

/* The 3, 2, 1 countdown sprite. */
typedef struct IrcRhythmCountdown {
    struct ClactActor *actor;
    u32 reserved4[2];
    u32 frames;
    u32 step;
    u32 running;
    u32 finished;
} IrcRhythmCountdown;

/* Pulsing background colour. */
typedef struct IrcRhythmPulse {
    u16 color;
    u16 phase;
    u32 enabled;
    u32 reserved8;
    u32 running;
} IrcRhythmPulse;

/* Caller data of the game. */
typedef struct IrcRhythmContext {
    void *gameSystem;
    IrcSys *ircSys;
    IrcCompatibleProfile *partner;
    u32 status;
    u8 score;
    u8 reserved11[3];
    int tapCountDifference;
} IrcRhythmContext;

struct IrcRhythm;
typedef void (*IrcRhythmStateFn)(struct IrcRhythm *work, u16 *step);

typedef struct IrcRhythm {
    IrcScreen screen;
    IrcTextSystem text;
    IrcTextWindow messageWindow;
    IrcRhythmNetSync netSync;
    IrcRhythmParticles particles;
    IrcAppBar *appBar;
    IrcRhythmCountdown countdown;
    IrcRhythmPulse pulse;
    IrcTextWindow timerWindow;
    IrcTextWindow captionWindow;
    IrcRhythmStateFn stateFn;
    u16 stateStep;
    u16 waitFrames;
    u32 finished;
    u32 reserved810;
    IrcRhythmRecord record;
    u32 reserved898;
    u32 resultStarted;
    u16 resultStep;
    u16 resultTimer;
    void *blendTask;
    u32 blendResetPending;
    u32 tappedThisFrame;
    IrcRhythmContext *context;
} IrcRhythm;

#endif
