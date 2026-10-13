#ifndef GAME_OV065_FIELD_GIMMICK_TIME_EFFECT_TYPES_H
#define GAME_OV065_FIELD_GIMMICK_TIME_EFFECT_TYPES_H

/* ov065: field gimmick with one animated effect model (model 0 of expansion
 * object unit 0). A script starts it: the model is shown, its two animations
 * run once with sound effects, then the model is hidden again and the save
 * flag is cleared. The model set differs between day and night. */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

#define GIMMICK65_SAVE_BLOCK     0x36   /* field save gimmick block id */
#define GIMMICK65_ANIME_COUNT    2
#define GIMMICK65_FIRST_NIGHT_TIME_ZONE 3   /* time zones 3 and 4 use the night models */
#define GIMMICK65_SE_START_NIGHT 0x7F7
#define GIMMICK65_SE_START_DAY   0x7F8
#define GIMMICK65_SE_DAY_PEAK    0x7F9   /* day variant, played at the peak frame */
#define GIMMICK65_PEAK_FRAME     0x3C000 /* fx32 frame 60 of animation 0 */

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

/* Gimmick block of the field save (one word). */
typedef struct Gimmick65Save {
    int isEffectPending;   /* nonzero: effect model shown and its animations enabled */
} Gimmick65Save;

/* Field map common work (8 bytes), allocated in the setup function. */
typedef struct Gimmick65Work {
    int isPlaying;   /* the effect runs; cleared when animation 0 stops */
    int isNight;     /* night model set and sound effects */
} Gimmick65Work;

#endif
