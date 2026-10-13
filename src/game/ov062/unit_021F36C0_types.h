#ifndef GAME_OV062_UNIT_021F36C0_TYPES_H
#define GAME_OV062_UNIT_021F36C0_TYPES_H

/* ov062: field gimmick with one animated model at a fixed position. The model
 * is hidden once the flag in gimmick work slot 0x34 is set. */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

#define GIMMICK62_WORK_SLOT    0x34   /* gimmick work slot that holds the hide flag */

typedef struct VecFx32 {
    int x;
    int y;
    int z;
} VecFx32;

#endif
