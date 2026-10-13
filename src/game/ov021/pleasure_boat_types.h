#ifndef OV021_PLEASURE_BOAT_TYPES_H
#define OV021_PLEASURE_BOAT_TYPES_H

/* One passenger record of the pleasure boat (0x1C bytes). */
typedef struct BoatPassenger {
    u32 id;           /* 0x00, not read by the accessors */
    u32 type;         /* 0x04, script query 6 */
    u32 value;        /* 0x08, script query 4 (10 when the boat has no work) */
    u32 param;        /* 0x0C, script query 5 */
    u32 extra[2];     /* 0x10, script query 7 (second operand picks the word) */
    int occupied;     /* 0x18, nonzero when the passenger slot is in use */
} BoatPassenger;

/* Pleasure boat work (0x1B8), allocated by PLEASURE_BOAT_Create (field_flash.c). */
typedef struct PleasureBoatWork {
    int eventPending;             /* 0x000, set at each period end, consumed by the arrival jingle */
    short timeTicks;              /* 0x004, 30 ticks per second, 1350 per period */
    u16 visitorCount;             /* 0x006 */
    int periodCount;              /* 0x008 */
    BoatPassenger passengers[15]; /* 0x00C */
    u8 groupCount[4];             /* 0x1B0 */
    int locked;                   /* 0x1B4 */
} PleasureBoatWork;

/* The slot in the event state (game data + 0x680) that holds the boat work pointer. */
typedef struct PleasureBoatHolder {
    PleasureBoatWork *boat;
} PleasureBoatHolder;

#endif
