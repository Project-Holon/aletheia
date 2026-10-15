#ifndef ARROW_H
#define ARROW_H

#include "research_clact.h"

#define ARROW_MAX_PARTS 26

/* Kinds of arrow part, in the order of the animation sequence table. */
#define ARROW_PART_HORIZONTAL 0
#define ARROW_PART_VERTICAL 1
#define ARROW_PART_CORNER_TOP 2
#define ARROW_PART_CORNER_BOTTOM 3

/* States of the arrow animation. */
#define ARROW_STATE_IDLE 0
#define ARROW_STATE_DRAWING 1
#define ARROW_STATE_DONE 2

/* Actor resources and animation sequences, copied into the arrow when it is created. */
struct ArrowResources {
    u32 charId;
    u32 paletteId;
    u32 cellId;
    u16 space;
    u16 animSeq[4];                     /* one per part kind */
    u16 animSeqExtra;                   /* copied with the record, never read, see open_items */
};

/* One segment of the arrow: an actor shown when the timer reaches startTime. */
struct ArrowPart {
    u32 shown;
    u16 startTime;
    u16 pad6;                           /* alignment before the word */
    u32 stopEnabled;
    u16 stopTime;
    u8 x;
    u8 y;
    u32 kind;
    struct ClactActor *actor;
};

/* Arrow drawn segment by segment between two points, 0x29C bytes. */
struct Arrow {
    u16 heapId;
    u16 pad2;                           /* alignment before the pointer */
    struct ClactUnit *unit;
    struct ArrowResources resources;
    u32 state;
    u32 timer;
    struct ArrowPart parts[ARROW_MAX_PARTS];
    u8 partCount;
    u8 pad299[3];                       /* struct size rounded to a word */
};

#endif
