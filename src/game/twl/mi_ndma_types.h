#ifndef GAME_TWL_MI_NDMA_TYPES_H
#define GAME_TWL_MI_NDMA_TYPES_H

/* per-channel NDMA configuration, 16 bytes */
typedef struct {
    int intervalTimer;
    int prescaler;
    int blockSize;
    int blockWordCount;
} NdmaConfig;

#endif
