#ifndef ALETHEIA_OV077_ENCEFF_BASE_TYPES_H
#define ALETHEIA_OV077_ENCEFF_BASE_TYPES_H

/* Integer types shared by the encounter effect headers of ov077 and ov078. */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;
typedef volatile u32   vu32;
typedef s32 fx32;
typedef s16 fx16;


typedef struct VecFx32 {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

typedef struct Mtx33 {
    fx32 m[9];
} Mtx33;

#endif
