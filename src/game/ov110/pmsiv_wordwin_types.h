#ifndef PMSIV_WORDWIN_TYPES_H
#define PMSIV_WORDWIN_TYPES_H

/* The word list window of the easy chat (PMS) input screen, overlay 110:
 * the scrolling two column list of words the player picks from, with its
 * scroll bar and the window effect used while the list opens and closes. */

#include "pmsiv_edit_shared_types.h"

struct PmsInput;
struct PmsInputView;
struct PmsInputData;
struct Descriptor;
struct ClactActor;
struct U16Vec;

#define PMSIV_WORDWIN_ITEM_COUNT 10

struct PmsivWordwin {
    /* 0x00 */ struct PmsInputView *view;
    /* 0x04 */ struct PmsInput *input;
    /* 0x08 */ struct PmsInputData *wordData;
    /* 0x0C */ struct Descriptor *listWindow;
    /* 0x10 */ struct Descriptor *wrapWindow;
    /* 0x14 */ struct ClactActor *cursor;
    /* 0x18 */ unsigned int cursorWasVisible;
    /* 0x1C */ struct ClactActor *scrollThumb;
    /* 0x20 */ struct ClactActor *items[PMSIV_WORDWIN_ITEM_COUNT];
    /* 0x48 */ struct U16Vec *wordText;
    /* 0x4C */ struct PmsivFade fade;
    /* 0x6C */ struct PmsivBgScroll scroll;
    /* 0x88 */ unsigned int fadeBusy;
    /* 0x8C */ union {
        unsigned char raw;
        struct {
            unsigned char plane:5;
            unsigned char effect:1;
            unsigned char rest:2;
        } bits;
    } savedWinOut;
    /* 0x90 */ unsigned int savedDispWindows;
    /* 0x94 */ unsigned int originY;
    /* 0x98 */ int firstShown;
    /* 0x9C */ unsigned int *uiInputMode;
};

#endif
