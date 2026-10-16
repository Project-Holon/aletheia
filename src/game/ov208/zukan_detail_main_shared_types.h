#ifndef ZUKAN_DETAIL_MAIN_SHARED_TYPES_H
#define ZUKAN_DETAIL_MAIN_SHARED_TYPES_H

#include "zukan_detail_shared_types.h"

/*
 * Arguments of one zukan detail session, owned by the caller that opens the
 * screen. src is the save-data blob, mode selects the screen (1 info, 2 area,
 * 3 voice, 4 form). extra/formNo/shiny are handed to the context constructor
 * and speciesStep is written back when the left/right buttons are pressed.
 */
struct Ov208Args {
    void *src;
    int mode;
    int extra;
    u16 formNo;
    u16 shiny;
    int speciesStep;
};

/*
 * Work object of the whole zukan detail screen, allocated with size 0x2c by
 * ZUKAN_DETAIL_MAIN_Init. node is the procsys state node of the active screen
 * and context the shared context built by ZUKAN_DETAIL_COMMON_CreateContext.
 */
struct Ov208Main {
    u16 heap;
    u16 pad;
    void *display;
    void *font;
    void *printer;
    void *task;
    void *touchbar;
    void *headbar;
    void *context;
    void *node;
    void *mem;
    int pendingMode;
};

#endif
