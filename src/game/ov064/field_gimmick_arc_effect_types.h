#ifndef GAME_OV064_FIELD_GIMMICK_ARC_EFFECT_TYPES_H
#define GAME_OV064_FIELD_GIMMICK_ARC_EFFECT_TYPES_H

/* ov064: field gimmick with two effect models that scripts start. Model 0
 * (four animes) plays at the player with sounds and a screen fade; model 1
 * (three animes) plays at a given position or flies along an arc between two
 * positions. The special power ID picks which model resource table is used. */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

#define FIELD_GIMMICK_ARC_EFFECT_WORK_ID           1       /* field map common work slot */
#define FIELD_GIMMICK_ARC_EFFECT_PLAYER_MODEL      0
#define FIELD_GIMMICK_ARC_EFFECT_PLAYER_ANIME_COUNT 4
#define FIELD_GIMMICK_ARC_EFFECT_ARC_MODEL         1
#define FIELD_GIMMICK_ARC_EFFECT_ARC_ANIME_COUNT   3
#define FIELD_GIMMICK_ARC_EFFECT_SPECIAL_POWER_ID  0x14    /* selects the second resource table */

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

/* Field map common work (0x38 bytes), allocated in the setup function. */
typedef struct Gimmick64Work {
    int fadeTarget;         /* 0x00 screen argument of the fades, 4 */
    int fadeWait;           /* 0x04 frames left between fade out and fade in */
    int seDone[4];          /* 0x08 sounds already played in the player effect */
    VecFx32 arcStart;       /* 0x18 arc effect: first position */
    VecFx32 arcEnd;         /* 0x24 arc effect: last position */
    int arcHeight;          /* 0x30 arc effect: extra height at the middle */
    u16 arcFrameCount;      /* 0x34 arc effect: frames of the whole flight */
    u16 arcFrame;           /* 0x36 arc effect: frames done */
} Gimmick64Work;

#endif
