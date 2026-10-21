#ifndef PLIST_MENU_TYPES_H
#define PLIST_MENU_TYPES_H

/* Party list context menu (the command list that opens after a Pokemon is chosen).
   Needs pokelist_types.h and the u8/u16/u32 typedefs before it. */

struct Strbuf;
struct TaskMenu;
struct Unit;

#define PLIST_MENU_MAX_ENTRIES 8

/* One task menu button, stride 12; also the button description passed to the
   single-button window helper. */
typedef struct PlistMenuEntry {
    struct Strbuf *label;       /* 0x00: message string, freed when the menu closes */
    u16 color;                  /* 0x04 */
    u8 pad06[2];
    int disabled;               /* 0x08 */
} PlistMenuEntry;

/* Layout record handed to the task menu constructor. */
typedef struct PlistTaskMenuTemplate {
    u32 heapId;
    u8 count;
    PlistMenuEntry *entries;
    u32 kind;
    u8 x;
    u8 y;
    u8 width;
    u8 bgFrame;
} PlistTaskMenuTemplate;

/* Command list built by the menu (0x84 bytes, allocated in the menu create function). */
typedef struct PlistMenu {
    u8 count;                                   /* 0x00 */
    u8 pad01;
    u16 ids[PLIST_MENU_MAX_ENTRIES];            /* 0x02: command id per entry */
    u8 pad12[2];
    PlistMenuEntry entries[PLIST_MENU_MAX_ENTRIES]; /* 0x14 */
    struct TaskMenu *taskMenu;                  /* 0x74 */
    u8 pad78[4];
    u32 windowOut;                              /* 0x7C: out value of the window setup call */
    void *windowRes;                            /* 0x80: freed with the menu */
} PlistMenu;
typedef char PlistMenu_SizeCheck[(sizeof(PlistMenu) == 0x84) ? 1 : -1];

/* Fixed command list (terminated by 16). */
typedef struct PlistMenuItemList {
    int item[3];
} PlistMenuItemList;

#endif
