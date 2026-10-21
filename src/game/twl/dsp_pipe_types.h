#ifndef GAME_TWL_DSP_PIPE_TYPES_H
#define GAME_TWL_DSP_PIPE_TYPES_H

#include "../types.h"

/* Pipe control block of the DSP data RAM, 10 bytes. */
typedef struct DspRing {
    u16 base;
    u16 size;
    u16 rd;
    u16 wr;
    u16 id;
} DspRing;

#endif
