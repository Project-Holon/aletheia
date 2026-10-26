#ifndef GAME_ARM9_BMP_MENULIST_TYPES_H
#define GAME_ARM9_BMP_MENULIST_TYPES_H

#include "../types.h"

struct BmpMenuList;
struct Strbuf;
struct BmpWin;
struct MenuTarget;
struct PrintQueue;
struct GfFont;

struct BmpMenuListItem {
    struct Strbuf *text;
    u32   value;
};

typedef void (*MenuDrawHook)(struct BmpMenuList *menu, u32 value, u8 y);

typedef void (*MenuCursorNotify)(struct BmpMenuList *menu, u32 value, void *arg);

/* The halfword at +0x1A. */
struct MenuFlags {
    u16 mode3 : 3;
    u16 lineGap : 4;
    u16 pageKeys : 2;
    u16 mode6 : 6;
    u16 cursorOff : 1;
};

/*
 * The template the caller hands to BMP_MENULIST_Create.  It is copied over the first 0x34 bytes of
 * BmpMenuList, so the two share this layout up to the font.
 */
struct BmpMenuListTemplate {
    struct BmpMenuListItem *items;
    MenuCursorNotify onCursor;
    MenuDrawHook     drawHook;
    struct BmpWin   *win;
    u16 count;
    u16 rows;
    u8 sepX;
    u8 itemX;
    u8 cursorX;
    u8 originY : 4;
    u8 letterColor : 4;
    u8 bgColor : 4;
    u8 shadowColor : 4;
    u8 reserved19;
    struct MenuFlags flags;
    void *userData;
    u16 cursorW;
    u16 rowH;
    u8 reserved24[0x28 - 0x24];
    struct MenuTarget *target;
    struct PrintQueue *printer;
    struct GfFont *font;
};

#endif
