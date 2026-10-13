#ifndef OV045_GIMMICK_TYPES_H
#define OV045_GIMMICK_TYPES_H

/* Types of the ov045 field gimmick: three floor switches. Each switch is
 * drawn by two expansion-object models (index 0..2 and index 3..5) that each
 * have an "off" animation (0) and an "on" animation (1). */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

#define GIMMICK45_SWITCH_COUNT 3
#define GIMMICK45_SECONDARY_MODEL_OFFSET 3
#define GIMMICK45_REQUIREMENT_COUNT 8

#define GIMMICK45_SAVE_BLOCK_ID 9
#define GIMMICK45_CTRL_TYPE_HYBRID 2

#define GIMMICK45_SE_SWITCH_PRESS 0x6d0
#define GIMMICK45_SE_SWITCH_DONE 0x6f0

/* Gimmick block of the field save (block 9). */
typedef struct Gimmick45Save {
    int switchOn[GIMMICK45_SWITCH_COUNT];  /* nonzero: the switch is on */
} Gimmick45Save;

/* Common work of the gimmick (allocated by the setup function). */
typedef struct Gimmick45Work {
    int switchIndex;  /* switch that the running event animates */
} Gimmick45Work;

/* Fixed-point position of a model. */
typedef struct Vec3Fx {
    int x;
    int y;
    int z;
} Vec3Fx;

#endif
