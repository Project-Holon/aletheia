#ifndef ALETHEIA_OV078_ENCEFF_RIPPLE_TYPES_H
#define ALETHEIA_OV078_ENCEFF_RIPPLE_TYPES_H

#include "../types.h"

/*
 * Encounter effect of overlay 0x4E: a water surface of 33 x 25 vertices on
 * which drops make ripples (a spring model: each vertex is pulled to the
 * mean of its four neighbours), then the screen fades out. Kinds 2 and 36 of
 * the effect table in enceff.c; kind 36 is the same effect with other
 * constants. The includer must include ../ov077/enceff_base_types.h first.
 */

#define RIPPLE_COLS         33
#define RIPPLE_ROWS         25
#define RIPPLE_VERTEX_COUNT (RIPPLE_COLS * RIPPLE_ROWS)
#define RIPPLE_CENTER       412     /* vertex that a drop hits: column 16, row 12 */

typedef struct EncEffRippleVertex {
    fx16 x;
    fx16 y;
    fx16 z;                     /* height of the water at this vertex */
} EncEffRippleVertex;

/* Work of the ripple effect, 0x19E0 bytes. */
typedef struct EncEffRipple {
    EncEffRippleVertex vertex[RIPPLE_VERTEX_COUNT];  /* 0x0000 */
    s16 velocityZ[RIPPLE_VERTEX_COUNT];              /* 0x1356 vertical speed of each vertex */
    s16 wait;                   /* 0x19C8 frames to the next drop; 6 frames pause after the last one */
    s16 count;                  /* 0x19CA drops left */
    u16 period;                 /* 0x19CC frames between two drops */
    u16 next;                   /* 0x19CE wait after the last drop before the effect ends */
    int height;                 /* 0x19D0 height that a drop gives the centre vertex */
    int fadeScreens;            /* 0x19D4 screens of the closing fade (0xC or 3) */
    int startDelay;             /* 0x19D8 frames before the closing fade may start */
    int fadeStarted;            /* 0x19DC */
} EncEffRipple;

#endif
