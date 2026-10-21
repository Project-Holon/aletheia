#ifndef SCRCMD_PROC_FLD_TYPES_H
#define SCRCMD_PROC_FLD_TYPES_H

/*
 * Field shop screen (scrcmd_proc_fld.c): the work block of the shop state
 * machine, its item rows, window templates and list menu template.
 */

#include "../types.h"

/* Indexes into ShopWork.windows. */
#define SHOP_WIN_HEADER 0
#define SHOP_WIN_MONEY 1
#define SHOP_WIN_LIST 2
#define SHOP_WIN_OWNED 3
#define SHOP_WIN_QUANTITY 4
#define SHOP_WIN_DESCRIPTION 5
#define SHOP_WIN_MESSAGE 6
#define SHOP_WIN_COUNT 7

/* Shop state machine values (ShopWork.state). */
#define SHOP_STATE_INIT 0
#define SHOP_STATE_LIST_POLL 1
#define SHOP_STATE_QUANTITY_ENTER 2
#define SHOP_STATE_QUANTITY_STEP 3
#define SHOP_STATE_LIST_RESUME 4
#define SHOP_STATE_YESNO_OPEN 5
#define SHOP_STATE_YESNO_OPEN_NOICON 6
#define SHOP_STATE_YESNO_POLL 7
#define SHOP_STATE_PURCHASE 8
#define SHOP_STATE_BONUS_ITEM 9
#define SHOP_STATE_MESSAGE_WAIT 10
#define SHOP_STATE_EXIT 11

/* One row of the item table: item id and its price (8 bytes). */
typedef struct ShopItem {
    u16 itemId;
    u16 pad02;
    s32 price;
} ShopItem;

/* One window description of the shop window tables (0xC bytes). */
typedef struct ShopWindowTemplate {
    u32 bgId;
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    u16 paletteNum;
} ShopWindowTemplate;

/* Rectangle (tile units) of the quantity-select mask. */
typedef struct ShopMaskRect {
    u32 x;
    u32 y;
    u32 w;
    u32 h;
} ShopMaskRect;

/* List menu template built by ShopWork list setup (0x34 bytes). */
typedef struct ShopListTemplate {
    void *items;
    void *cursorMoveFunc;
    void *printFunc;
    u32 window;
    u16 count;
    u16 visibleRows;
    u8 headerX;
    u8 itemX;
    u8 cursorX;
    u8 fgColor : 4;
    u8 shadowColor : 4;
    u8 bgColor : 4;
    u8 cursorColor : 4;
    u8 fontId;
    u16 lineSpacing : 3;
    u16 cursorType : 4;
    u16 reservedBits : 2;
    u16 flagBits : 6;
    u16 cancelable : 1;
    void *userData;
    u16 cursorSpriteX;
    u16 cursorSpriteY;
    u32 reserved24;
    void *activeWindowRef;
    void *printSys;
    u32 fontInfo;
} ShopListTemplate;

/*
 * Shop screen work block (0x20C bytes). It sits at offset 8 of the task
 * work (ShopTask) that the shop script command allocates.
 */
typedef struct ShopWork {
    u8 state;                       /* 0x000 */
    u8 nextState;                   /* 0x001: state after the message ends */
    u8 pad02[2];
    u16 heapId;                     /* 0x004 */
    u8 pad06[2];
    u32 fontInfo;                   /* 0x008: print parameter block */
    u32 moneyData;                  /* 0x00C */
    u32 bagData;                    /* 0x010 */
    struct RecordBlock *recordData; /* 0x014 */
    u32 battlePointData;            /* 0x018 */
    void *shopTable;                /* 0x01C */
    ShopItem items[40];             /* 0x020 */
    u16 itemCount;                  /* 0x160 */
    u8 isTmShop;                    /* 0x162 */
    u8 usesBattlePoints;            /* 0x163 */
    u32 windows[SHOP_WIN_COUNT];    /* 0x164 */
    struct BmpMenuWork *itemSlots;  /* 0x180: list menu entries */
    struct BmpMenu *yesNoMenu;      /* 0x184 */
    void *shopMsgBank;              /* 0x188 */
    void *itemMsgBank;              /* 0x18C */
    void *wordSet;                  /* 0x190 */
    void *priceFormat;               /* 0x194 */
    void *textBuffer;               /* 0x198 */
    void *cancelText;               /* 0x19C */
    void *soldOutText;               /* 0x1A0 */
    struct BmpMenuList *listMenu;   /* 0x1A4 */
    u32 listWindow;                 /* 0x1A8 */
    u8 printerBusy;                 /* 0x1AC */
    u8 pad1AD[3];
    void *printSys;                 /* 0x1B0 */
    void *tcbList;                  /* 0x1B4 */
    void *messagePrinter;            /* 0x1B8 */
    void *cellSystem;                /* 0x1BC */
    struct ClactActor *cursorActor;                /* 0x1C0 */
    struct ClactActor *arrowUpActor;               /* 0x1C4 */
    struct ClactActor *arrowDownActor;             /* 0x1C8 */
    struct ClactActor *quantityArrowActor;         /* 0x1CC */
    struct ClactActor *iconActor;                  /* 0x1D0 */
    u32 arrowCharRes;             /* 0x1D4 */
    u32 cursorPlttRes;            /* 0x1D8 */
    u32 cursorCellRes;            /* 0x1DC */
    u8 pad1E0[4];
    u32 arrowPlttRes;             /* 0x1E4 */
    u32 arrowCellRes;             /* 0x1E8 */
    u32 iconCharRes;             /* 0x1EC */
    u32 iconPlttRes;             /* 0x1F0 */
    u32 iconCellRes;              /* 0x1F4 */
    void *iconArchive;              /* 0x1F8 */
    u16 itemId;                     /* 0x1FC: item under the cursor */
    u8 pad1FE[2];
    u32 price;                      /* 0x200 */
    u32 maxQuantity;                /* 0x204 */
    u16 quantity;                   /* 0x208 */
    u16 introShown;                 /* 0x20A */
} ShopWork;

/* Task work (0x214 bytes) of the shop script command. */
typedef struct ShopTask {
    u8 state;
    u8 subState;
    u8 shopKind;
    u8 shopVariant;
    u32 fieldRegionArg;
    ShopWork shop;
} ShopTask;

#endif
