/*
 * file:     pdw_postman.c
 * unit:     yes
 * function: PDW_POSTMAN_CreateListWin, PDW_POSTMAN_DeleteListWin, PDW_POSTMAN_PrintListWin, PDW_POSTMAN_ListEvent, PDW_POSTMAN_CreateReceivableList, PDW_POSTMAN_ReceiveItems, PDW_POSTMAN_CountUnreceivable, PDW_POSTMAN_GetUnreceivableItem, PDW_POSTMAN_CreateListEvent, PDW_POSTMAN_GetMysteryCard, PDW_POSTMAN_FindMysteryCard, PDW_POSTMAN_SetMysteryReceived, PDW_POSTMAN_GetMysteryGiftType
 * address:  0x021B7400
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   MSGDATA_CreateFromArchive  0x02045B38  arm
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
 *   sPdwPostmanFileName     0x021DE288  data   ov021  a1
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   BG_SYS_PushTile  0x020409B4  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_Delete  0x0201ED04  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   FIELD_MSGBG_MsgWinPrintStr  0x02190758  thumb  ov021
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   FIELD_MSGBG_GetMsgWinBmpWin  0x021907C0  thumb  ov021
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   FIELD_MSGBG_CreateCursor  0x02192788  thumb  ov021
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   FIELD_MSGBG_AnimateCursor  0x021928C0  thumb  ov021
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FIELD_MSGBG_DeleteCursor  0x021927B0  thumb  ov021
 *   GAME_DATA_GetMyItem  0x0201292C  thumb
 *   BLOCK20_SAVEDATA_GetEntryId  0x02009310  thumb
 *   BLOCK20_SAVEDATA_GetEntryValue  0x02009330  thumb
 *   MYITEM_SAVEDATA_CanAddItem  0x02007E3C  thumb
 *   MYITEM_SAVEDATA_AddItem  0x02007E50  thumb
 *   BLOCK20_SAVEDATA_ClearEntry  0x02009364  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_SYNC_GetBlock  0x02009448  thumb
 *   GAME_EVENT_Create  0x020122C0  thumb
 *   GAME_EVENT_GetWork  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   MYSTERY_DATA_IsCardExist  0x0200A0E4  thumb
 *   MYSTERY_DATA_IsCardReceived  0x0200A104  thumb
 *   MYSTERY_DATA_GetCard  0x0200A000  thumb
 *   MYSTERY_DATA_SetCardReceived  0x0200A13C  thumb
 */
#include "../types.h"

struct GameSystem;
struct GameData;
struct GameEvent;
struct SaveControl;
struct FieldMap;
struct FieldMsgBg;
struct FieldMsgWin;
struct FieldMsgCursor;
struct MsgBank;
struct WordSet;
struct Strbuf;
struct BmpWin;
struct Bitmap;
struct MyItem;
struct PdwPostmanSave;
struct MysteryData;

#include "../arm9/game_event.h"

/* Mystery gift card (0xCC); layout and field names as in arm9 mystery_data.c. */
typedef struct MysteryCard {
    u8 body[0xB3];
    u8 giftType;                          /* 1..3 when the slot holds a card */
    u8 flags;                             /* bit 1: gift received */
    u8 tail[0x17];
} MysteryCard;

/* One gift waiting at the postman: item and quantity. */
typedef struct PdwPostmanItem {
    u16 itemId;
    u16 count;
} PdwPostmanItem;

/* The window that lists the gifts (0x28). */
typedef struct PdwPostmanListWin {
    u16 heapId;
    u16 pad02;
    struct FieldMap *fieldMap;
    struct MsgBank *msgData;
    struct FieldMsgWin *msgWin;
    struct FieldMsgCursor *cursor;
    struct WordSet *wordSet;
    struct Strbuf *strBuf;
    struct Strbuf *expandBuf;
    int itemCount;
    PdwPostmanItem *items;
} PdwPostmanListWin;

/* Work of the gift list event (0x14). */
typedef struct PdwPostmanEventWork {
    struct FieldMap *fieldMap;
    PdwPostmanListWin *listWin;
    PdwPostmanItem *items;
    u32 itemCount;
    u16 pageTop;
} PdwPostmanEventWork;

#define PDW_POSTMAN_ITEM_MAX     20
#define PDW_POSTMAN_PAGE_ITEMS   7
#define PDW_POSTMAN_LINE_HEIGHT  14
#define PDW_POSTMAN_MYSTERY_SLOTS 12

#include "fieldmap.h"
#include "../arm9/gfl_heap_wrap.h"
#include "../arm9/msgdata.h"
struct Strbuf;
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define WORDSET_CreateDefault WORDSET_CreateDefault_header
#endif
#include "../arm9/gf_font.h"
#ifdef __MWERKS__
#undef WORDSET_CreateDefault
extern struct WordSet * WORDSET_CreateDefault(u32);
#endif
#include "../arm9/wordset.h"
struct Strbuf;
#include "../arm9/strbuf.h"
#include "../arm9/bmp_win.h"
struct Bmp;
#include "../arm9/bg_sys.h"
struct MsgBank;
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define FIELD_MSGBG_MsgWinPrintStr FIELD_MSGBG_MsgWinPrintStr_header
#endif
#include "field_msgbg.h"
#ifdef __MWERKS__
#undef FIELD_MSGBG_MsgWinPrintStr
extern void FIELD_MSGBG_MsgWinPrintStr(FieldMsgWin *, int, u16, struct Strbuf *);
#endif
#include "../arm9/key.h"
#include "../arm9/gfl_use.h"
#include "../arm9/game_data.h"
struct CgearSaveBlock;
#include "../arm9/block20_savedata.h"
/* DS-original prototypes: the DS code was built against narrower or wider integer parameters than the header; the host build uses the header. */
#ifdef __MWERKS__
#define MYITEM_SAVEDATA_AddItem MYITEM_SAVEDATA_AddItem_header
#define MYITEM_SAVEDATA_CanAddItem MYITEM_SAVEDATA_CanAddItem_header
#endif
#include "../arm9/myitem_savedata.h"
#ifdef __MWERKS__
#undef MYITEM_SAVEDATA_AddItem
#undef MYITEM_SAVEDATA_CanAddItem
extern int MYITEM_SAVEDATA_AddItem(struct MyItem *, int, int, int);
extern int MYITEM_SAVEDATA_CanAddItem(struct MyItem *, u32, u32, u32);
#endif
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern void *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
struct GameSyncData;
#include "../arm9/game_sync.h"
extern void *GAME_EVENT_GetWork(struct GameEvent *event);
#include "../arm9/mystery_data.h"

PdwPostmanListWin *PDW_POSTMAN_CreateListWin(struct FieldMap *fieldMap, PdwPostmanItem *items, int itemCount);
int PDW_POSTMAN_DeleteListWin(PdwPostmanListWin *listWin);
void PDW_POSTMAN_PrintListWin(PdwPostmanListWin *listWin);
int PDW_POSTMAN_ListEvent(struct GameEvent *event, int *seq, void *eventWork);
PdwPostmanItem *PDW_POSTMAN_CreateReceivableList(struct GameData *gameData, u32 heapId, struct PdwPostmanSave *save, int *outCount);
void PDW_POSTMAN_ReceiveItems(struct GameData *gameData, int heapId, struct PdwPostmanSave *save);
int PDW_POSTMAN_CountUnreceivable(struct GameData *gameData, int heapId, struct PdwPostmanSave *save);
u32 PDW_POSTMAN_GetUnreceivableItem(struct GameData *gameData, int heapId, struct PdwPostmanSave *save, int index);
struct GameEvent *PDW_POSTMAN_CreateListEvent(struct GameSystem *gameSystem);
MysteryCard *PDW_POSTMAN_GetMysteryCard(struct MysteryData *data, int slot, MysteryCard *card);
MysteryCard *PDW_POSTMAN_FindMysteryCard(struct MysteryData *data, int *outSlot, MysteryCard *card);
void PDW_POSTMAN_SetMysteryReceived(struct MysteryData *data, u32 slot);
u8 PDW_POSTMAN_GetMysteryGiftType(struct MysteryData *data);

extern const char sPdwPostmanFileName[];

PdwPostmanListWin *PDW_POSTMAN_CreateListWin(struct FieldMap *fieldMap, PdwPostmanItem *items, int itemCount)
{
    u32 heapId;
    PdwPostmanListWin *listWin;
    int height;

    heapId = FIELDMAP_GetHeapId(fieldMap);
    listWin = GFL_HEAP_Alloc(heapId, sizeof(PdwPostmanListWin), 1, sPdwPostmanFileName, 0x73);
    listWin->heapId = heapId;
    listWin->fieldMap = fieldMap;
    listWin->items = items;
    listWin->itemCount = itemCount;
    listWin->msgData = MSGDATA_CreateFromArchive(0, 3, 0x13B, heapId);
    listWin->wordSet = WORDSET_CreateDefault(heapId);
    listWin->strBuf = STRBUF_Create(0x80, heapId);
    listWin->expandBuf = STRBUF_Create(0x80, heapId);
    height = (itemCount * PDW_POSTMAN_LINE_HEIGHT + 7) & ~7;
    listWin->msgWin = FIELD_MSGBG_CreateMsgWin(FIELDMAP_GetMsgBg(fieldMap), (struct MsgBank *)listWin->msgData, 1, 1, 0x15, (u16)(height / 8));
    return listWin;
}

/* Addresses are Black-image addresses. */
int PDW_POSTMAN_DeleteListWin(PdwPostmanListWin *listWin)
{
    FIELD_MSGBG_ClearMsgWin(listWin->msgWin);
    FIELD_MSGBG_DeleteMsgWin(listWin->msgWin);
    BG_SYS_PushTile(1);
    STRBUF_Delete((struct Strbuf *)listWin->strBuf);
    STRBUF_Delete((struct Strbuf *)listWin->expandBuf);
    WORDSET_Delete(listWin->wordSet);
    MSGDATA_Delete(listWin->msgData);
    return GFL_HEAP_Free(listWin);
}

/* Print one line per gift: the item name, then its quantity. */
void PDW_POSTMAN_PrintListWin(PdwPostmanListWin *listWin)
{
    struct MsgBank *itemNames;
    int i;

    itemNames = MSGDATA_CreateFromArchive(0, 2, 0x36, (u16)((listWin->heapId & 0x7fff) | 0x8000));
    for (i = 0; i < listWin->itemCount; i++) {
        MSGDATA_ReadString(itemNames, listWin->items[i].itemId, (struct Strbuf *)listWin->strBuf);
        FIELD_MSGBG_MsgWinPrintStr(listWin->msgWin, 0, i * PDW_POSTMAN_LINE_HEIGHT, listWin->strBuf);
        MSGDATA_ReadString(listWin->msgData, 5, (struct Strbuf *)listWin->strBuf);
        WORDSET_SetSlotNumber(listWin->wordSet, 0, listWin->items[i].count, 2, 1, 1);
        WORDSET_CopyTaggedText(listWin->wordSet, (struct Strbuf *)listWin->expandBuf, (struct Strbuf *)listWin->strBuf);
        FIELD_MSGBG_MsgWinPrintStr(listWin->msgWin, 0x6c, i * PDW_POSTMAN_LINE_HEIGHT, listWin->expandBuf);
    }
    MSGDATA_Delete(itemNames);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer(FIELD_MSGBG_GetMsgWinBmpWin(listWin->msgWin)));
}

/*
 * Gift list event: show the gifts a page of seven at a time, wait for the A
 * button on each page.
 * Addresses are Black-image addresses.
 */
int PDW_POSTMAN_ListEvent(struct GameEvent *event, int *seq, void *eventWork)
{
    PdwPostmanEventWork *work = eventWork;
    u16 count;
    struct BmpWin *bmpWin;

    switch (*seq) {
    case 0:
        count = work->itemCount - work->pageTop;
        if (count > PDW_POSTMAN_PAGE_ITEMS) {
            count = PDW_POSTMAN_PAGE_ITEMS;
        }
        work->listWin = PDW_POSTMAN_CreateListWin(work->fieldMap, work->items + work->pageTop, count);
        PDW_POSTMAN_PrintListWin(work->listWin);
        work->listWin->cursor = FIELD_MSGBG_CreateCursor(FIELDMAP_GetMsgBg(work->fieldMap));
        (*seq)++;
        break;
    case 1:
        if (FIELD_MSGBG_IsMsgWinTransDone(work->listWin->msgWin) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        bmpWin = FIELD_MSGBG_GetMsgWinBmpWin(work->listWin->msgWin);
        FIELD_MSGBG_AnimateCursor(work->listWin->cursor, BMP_WIN_GetBmp(bmpWin), 15);
        BMP_WIN_TransferChars(bmpWin);
        if (KEY_GetTrg() & 1) {
            GFL_USE_PlaySeDefaultVolume(0x547);
            (*seq)++;
        }
        break;
    case 3:
        FIELD_MSGBG_DeleteCursor(work->listWin->cursor);
        PDW_POSTMAN_DeleteListWin(work->listWin);
        (*seq)++;
        break;
    case 4:
        if (work->pageTop + PDW_POSTMAN_PAGE_ITEMS >= work->itemCount) {
            GFL_HEAP_Free(work->items);
            return 1;
        }
        work->pageTop += PDW_POSTMAN_PAGE_ITEMS;
        *seq = 0;
        break;
    }
    return 0;
}

/* List the gifts that fit in the bag; the count goes to outCount. */
PdwPostmanItem *PDW_POSTMAN_CreateReceivableList(struct GameData *gameData, u32 heapId, struct PdwPostmanSave *save, int *outCount)
{
    PdwPostmanItem *items;
    struct MyItem *bag;
    int count;
    int i;
    u16 itemId;
    u16 itemCount;

    bag = GAME_DATA_GetMyItem(gameData);
    items = GFL_HEAP_Alloc(heapId, sizeof(PdwPostmanItem) * PDW_POSTMAN_ITEM_MAX, 1, sPdwPostmanFileName, 0x14d);
    i = 0;
    count = 0;
    for (; i < PDW_POSTMAN_ITEM_MAX; i++) {
        itemId = BLOCK20_SAVEDATA_GetEntryId((struct CgearSaveBlock *)save, i);
        itemCount = BLOCK20_SAVEDATA_GetEntryValue((struct CgearSaveBlock *)save, i);
        if (itemId != 0 && MYITEM_SAVEDATA_CanAddItem(bag, itemId, itemCount, heapId) == 1) {
            items[count].itemId = itemId;
            items[count].count = itemCount;
            count++;
        }
    }
    *outCount = count;
    return items;
}

/* Put every gift that fits into the bag and clear its slot. */
void PDW_POSTMAN_ReceiveItems(struct GameData *gameData, int heapId, struct PdwPostmanSave *save)
{
    struct MyItem *bag = GAME_DATA_GetMyItem(gameData);
    u32 i;

    for (i = 0; i < PDW_POSTMAN_ITEM_MAX; i++) {
        int itemId = BLOCK20_SAVEDATA_GetEntryId((struct CgearSaveBlock *)save, i);
        int count = BLOCK20_SAVEDATA_GetEntryValue((struct CgearSaveBlock *)save, i);
        if (itemId != 0) {
            if (MYITEM_SAVEDATA_AddItem(bag, itemId, count, heapId) == 1)
                BLOCK20_SAVEDATA_ClearEntry((struct CgearSaveBlock *)save, i);
        }
    }
}

/*
 * Count the gifts that do not fit in the bag.
 * Addresses are Black-image addresses.
 */
int PDW_POSTMAN_CountUnreceivable(struct GameData *gameData, int heapId, struct PdwPostmanSave *save)
{
    struct MyItem *bag;
    u32 i;
    int count;
    u32 itemId;
    int itemCount;

    bag = GAME_DATA_GetMyItem(gameData);
    i = 0;
    count = 0;
    for (; i < PDW_POSTMAN_ITEM_MAX; i++) {
        itemId = BLOCK20_SAVEDATA_GetEntryId((struct CgearSaveBlock *)save, i);
        itemCount = BLOCK20_SAVEDATA_GetEntryValue((struct CgearSaveBlock *)save, i);
        if (itemId != 0) {
            if (MYITEM_SAVEDATA_CanAddItem(bag, itemId, itemCount, heapId) == 0)
                count++;
        }
    }
    return count;
}

/* Item id of the index-th gift that does not fit in the bag, 0 when none. */
u32 PDW_POSTMAN_GetUnreceivableItem(struct GameData *gameData, int heapId, struct PdwPostmanSave *save, int index)
{
    struct MyItem *bag;
    int i;
    int count;
    u32 itemId;
    int itemCount;

    bag = GAME_DATA_GetMyItem(gameData);
    i = 0;
    count = 0;
    for (; i < PDW_POSTMAN_ITEM_MAX; i++) {
        itemId = BLOCK20_SAVEDATA_GetEntryId((struct CgearSaveBlock *)save, i);
        itemCount = BLOCK20_SAVEDATA_GetEntryValue((struct CgearSaveBlock *)save, i);
        if (itemId != 0) {
            if (MYITEM_SAVEDATA_CanAddItem(bag, itemId, itemCount, heapId) == 0) {
                if (count == index)
                    return itemId;
                count++;
            }
        }
    }
    return 0;
}

/* Create the gift list event for the gifts that fit in the bag. */
struct GameEvent *PDW_POSTMAN_CreateListEvent(struct GameSystem *gameSystem)
{
    struct GameData *gameData;
    struct PdwPostmanSave *save;
    struct GameEvent *event;
    PdwPostmanEventWork *work;

    gameData = GAMESYSTEM_GetGameData(gameSystem);
    save = (struct PdwPostmanSave *)GAME_SYNC_GetBlock(GAME_DATA_GetSaveControl(gameData));
    event = GAME_EVENT_Create(gameSystem, 0, PDW_POSTMAN_ListEvent, sizeof(PdwPostmanEventWork));
    work = GAME_EVENT_GetWork(event);
    work->fieldMap = GAMESYSTEM_GetFieldMap(gameSystem);
    work->pageTop = 0;
    work->items = PDW_POSTMAN_CreateReceivableList(gameData, FIELDMAP_GetHeapId(work->fieldMap), save, (int *)&work->itemCount);
    return event;
}

/* The mystery gift card of the slot when it waits for delivery (gift type 1..3). */
MysteryCard *PDW_POSTMAN_GetMysteryCard(struct MysteryData *data, int slot, MysteryCard *card)
{
    u8 giftType;

    if (MYSTERY_DATA_IsCardExist(data, slot) == 0)
        return 0;
    if (MYSTERY_DATA_IsCardReceived(data, slot) == 1)
        return 0;
    if (MYSTERY_DATA_GetCard(data, slot, card) == 0)
        return 0;
    giftType = card->giftType;
    if (giftType == 0)
        return 0;
    if (giftType > 3)
        card = 0;
    return card;
}

/* First mystery gift waiting for delivery; its slot goes to outSlot. */
MysteryCard *PDW_POSTMAN_FindMysteryCard(struct MysteryData *data, int *outSlot, MysteryCard *card)
{
    int i;

    for (i = 0; i < PDW_POSTMAN_MYSTERY_SLOTS; i++) {
        if (PDW_POSTMAN_GetMysteryCard(data, i, card)) {
            *outSlot = i;
            return card;
        }
    }
    return 0;
}

/* Mark the mystery gift of the slot as delivered. */
void PDW_POSTMAN_SetMysteryReceived(struct MysteryData *data, u32 slot)
{
    MYSTERY_DATA_SetCardReceived(data, slot);
}

/* Gift type of the first mystery gift waiting for delivery, 0 when none. */
u8 PDW_POSTMAN_GetMysteryGiftType(struct MysteryData *data)
{
    int slot;
    MysteryCard card;
    MysteryCard *found;

    found = PDW_POSTMAN_FindMysteryCard(data, &slot, &card);
    if (found == 0) {
        return 0;
    }
    return found->giftType;
}
