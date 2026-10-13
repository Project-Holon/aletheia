#ifndef GAME_OV061_UNIT_021F36C0_TYPES_H
#define GAME_OV061_UNIT_021F36C0_TYPES_H

/* ov061: field gimmick that marks map connections. Model 0 is a one-shot
 * effect that plays at the tile in front of the player when an automatic
 * position event lies there. Models 1..8 are placed at the map connections
 * whose exit type is 6 (the connection list of the event data), rebuilt when
 * the zone changes. */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define GIMMICK61_MARKER_MAX        8       /* models 1..8 */
#define GIMMICK61_MODEL_COUNT       9
#define GIMMICK61_EFFECT_MODEL      0
#define GIMMICK61_MARKER_EXIT_TYPE  6       /* connection exit type that gets a marker model */
#define GIMMICK61_LOWERED_ZONE_ID   0x12E   /* markers of this zone sit 0x2000 lower */
#define GIMMICK61_STEP_PHASE_READY  3

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

/* Field map common work (0xC bytes), allocated in the setup function. */
typedef struct Gimmick61Work {
    int effectActive;       /* 0x00 nonzero while the effect model plays */
    VecFx32 *effectPos;     /* 0x04 position of the effect model in the expansion object */
    int zoneId;             /* 0x08 zone the markers were built for */
} Gimmick61Work;

#endif
