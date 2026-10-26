#ifndef GAME_OV010_TRCARD_VIEW_TYPES_H
#define GAME_OV010_TRCARD_VIEW_TYPES_H

#include "../types.h"

/* Work of the trainer card view screen (0x18 bytes), made by TRCARD_SYS_CreateViewWork. */
typedef struct ViewWork {
    void *bmpWin;                   /* 0x00 */
    void *cardData;                 /* 0x04 */
    void *profile;                  /* 0x08 */
    u32 phase;                      /* 0x0C */
    int result;                     /* 0x10: 1 when the view closed with the confirm choice */
    int startPage;                  /* 0x14: page shown first */
} ViewWork;

#endif
