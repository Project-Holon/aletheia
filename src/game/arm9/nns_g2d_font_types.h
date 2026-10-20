#ifndef GAME_ARM9_NNS_G2D_FONT_TYPES_H
#define GAME_ARM9_NNS_G2D_FONT_TYPES_H

#include "../types.h"

typedef struct NNSG2dCharWidths {
    s8 left;            /* +0 */
    u8 glyphWidth;      /* +1 */
    s8 charWidth;       /* +2  ldrsb */
} NNSG2dCharWidths;

typedef struct Step {
    signed char dx;
    signed char dy;
} Step;

#endif
