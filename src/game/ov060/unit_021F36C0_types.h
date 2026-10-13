#ifndef GAME_OV060_UNIT_021F36C0_TYPES_H
#define GAME_OV060_UNIT_021F36C0_TYPES_H

/* ov060: field gimmick of the intrude (visit) field. It keeps 21 field
 * expansion models: models 0..9 and 10..19 are two rows of ten gauge steps
 * (one row per record value of the visited player), model 20 is a one-shot
 * effect that the intrude sub display can show at a position. The gauges sit
 * in the column of the visited player, relative to the own net ID. */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

#define GIMMICK60_GAUGE_MODEL_COUNT  0x14   /* models 0..0x13 */
#define GIMMICK60_GAUGE_STEP_COUNT   10     /* steps per gauge row */
#define GIMMICK60_EFFECT_MODEL       0x14
#define GIMMICK60_MODEL_COUNT        0x15
#define GIMMICK60_EFFECT_ANIME_COUNT 3

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

/* Field map common work (4 bytes), allocated in the setup function. */
typedef struct Gimmick60Work {
    u8 shownIntrudeId;      /* 0x00 intrude ID whose gauges are on show */
    u8 effectActive;        /* 0x01 nonzero while the effect model plays */
    u8 reserved02[2];
} Gimmick60Work;

#endif
