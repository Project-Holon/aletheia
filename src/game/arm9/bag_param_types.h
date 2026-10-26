#ifndef GAME_ARM9_BAG_PARAM_TYPES_H
#define GAME_ARM9_BAG_PARAM_TYPES_H

#include "../types.h"

struct BagCursor;

/* Bag screen parameter (0x3C bytes), made by BAG_PARAM_Create. The bag screen writes the result into the last two words. */
typedef struct BagParam {
    void *gameData;                 /* 0x00 */
    void *myStatus;                 /* 0x04 */
    void *myItem;                   /* 0x08 */
    struct BagCursor *saveWork;     /* 0x0C */
    void *config;                   /* 0x10 */
    u8 itemCheck[0x18];             /* 0x14 */
    int mode;                       /* 0x2C */
    int cycleFlag;                  /* 0x30 */
    u32 selected;                   /* 0x34: 0 when the screen closed without a choice */
    u32 itemId;                     /* 0x38: chosen item */
} BagParam;

#endif
