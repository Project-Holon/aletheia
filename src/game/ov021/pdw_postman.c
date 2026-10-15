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
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   GF_FONT_Create_EC64  0x0201EC64  thumb
 *   STRBUF_Create  0x020457B0  arm
 *   FIELD_MSGBG_CreateMsgWin  0x02190708  thumb  ov021
 *   sPdwPostmanFileName     0x021DE288  data   ov021  a1
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 *   STRBUF_Delete  0x02045808  arm
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
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
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02009364  0x02009364  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   MYSTERY_DATA_IsCardExist  0x0200A0E4  thumb
 *   MYSTERY_DATA_IsCardReceived  0x0200A104  thumb
 *   MYSTERY_DATA_GetCard  0x0200A000  thumb
 *   MYSTERY_DATA_SetCardReceived  0x0200A13C  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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
struct StrBuf;
struct BmpWin;
struct Bitmap;
struct MyItem;
struct PdwPostmanSave;
struct MysteryData;

typedef int (*GameEventFunc)(struct GameEvent *event, int *seq, void *work);

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
    struct StrBuf *strBuf;
    struct StrBuf *expandBuf;
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

extern u16 FIELDMAP_GetHeapId(struct FieldMap *fieldMap);
extern struct FieldMsgBg *FIELDMAP_GetMsgBg(struct FieldMap *fieldMap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 MSGDATA_Delete(struct MsgBank *msgData);
extern void MSGDATA_ReadString(struct MsgBank *msgData, u32 strId, struct StrBuf *dest);
extern struct WordSet *GF_FONT_Create_EC64(u32 heapId);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *wordSet);
extern void WORDSET_SetSlotNumber(struct WordSet *wordSet, u32 bufId, u32 number, u32 digits, u32 dispType, u32 code);
extern void WORDSET_CopyTaggedText(struct WordSet *wordSet, struct StrBuf *dest, struct StrBuf *src);
extern struct StrBuf *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_Delete(struct StrBuf *strBuf);
extern u8 BMP_WIN_GetBgLayer(struct BmpWin *bmpWin);
extern struct Bitmap *BMP_WIN_GetBmp(struct BmpWin *bmpWin);
extern void BMP_WIN_TransferChars(struct BmpWin *bmpWin);
extern void func_020409B4(u32 bgFrame);
extern struct FieldMsgWin *FIELD_MSGBG_CreateMsgWin(struct FieldMsgBg *msgBg, struct MsgBank *msgData, u16 x, u16 y, u16 width, u16 height);
extern int FIELD_MSGBG_DeleteMsgWin(struct FieldMsgWin *msgWin);
extern void FIELD_MSGBG_MsgWinPrintStr(struct FieldMsgWin *msgWin, int x, u16 y, struct StrBuf *str);
extern int FIELD_MSGBG_IsMsgWinTransDone(struct FieldMsgWin *msgWin);
extern void FIELD_MSGBG_ClearMsgWin(struct FieldMsgWin *msgWin);
extern struct BmpWin *FIELD_MSGBG_GetMsgWinBmpWin(struct FieldMsgWin *msgWin);
extern struct FieldMsgCursor *FIELD_MSGBG_CreateCursor(struct FieldMsgBg *msgBg);
extern void FIELD_MSGBG_DeleteCursor(struct FieldMsgCursor *cursor);
extern void FIELD_MSGBG_AnimateCursor(struct FieldMsgCursor *cursor, struct Bitmap *bmp, u32 color);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 seNo);
extern struct MyItem *GAME_DATA_GetMyItem(const struct GameData *gameData);
extern u16 func_02009310(const struct PdwPostmanSave *save, int slot);
extern u8 func_02009330(const struct PdwPostmanSave *save, int slot);
extern void func_02009364(struct PdwPostmanSave *save, int slot);
extern int func_02007E3C(struct MyItem *bag, u32 itemId, u32 count, u32 heapId);
extern int func_02007E50(struct MyItem *bag, int itemId, int count, int heapId);
extern struct GameData *GAMESYSTEM_GetGameData(const struct GameSystem *gameSystem);
extern struct FieldMap *GAMESYSTEM_GetFieldMap(const struct GameSystem *gameSystem);
extern struct SaveControl *GAME_DATA_GetSaveControl(struct GameData *gameData);
extern struct PdwPostmanSave *func_02009448(struct SaveControl *save);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern u32 MYSTERY_DATA_IsCardExist(struct MysteryData *data, u32 slot);
extern int MYSTERY_DATA_IsCardReceived(struct MysteryData *data, unsigned int slot);
extern int MYSTERY_DATA_GetCard(struct MysteryData *data, int slot, MysteryCard *card);
extern void MYSTERY_DATA_SetCardReceived(struct MysteryData *data, u32 slot);

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
    listWin = func_02030734(heapId, sizeof(PdwPostmanListWin), 1, sPdwPostmanFileName, 0x73);
    listWin->heapId = heapId;
    listWin->fieldMap = fieldMap;
    listWin->items = items;
    listWin->itemCount = itemCount;
    listWin->msgData = func_02045B38(0, 3, 0x13B, heapId);
    listWin->wordSet = GF_FONT_Create_EC64(heapId);
    listWin->strBuf = STRBUF_Create(0x80, heapId);
    listWin->expandBuf = STRBUF_Create(0x80, heapId);
    height = (itemCount * PDW_POSTMAN_LINE_HEIGHT + 7) & ~7;
    listWin->msgWin = FIELD_MSGBG_CreateMsgWin(FIELDMAP_GetMsgBg(fieldMap), listWin->msgData, 1, 1, 0x15, (u16)(height / 8));
    return listWin;
}

/* Addresses are Black-image addresses. */
int PDW_POSTMAN_DeleteListWin(PdwPostmanListWin *listWin)
{
    FIELD_MSGBG_ClearMsgWin(listWin->msgWin);
    FIELD_MSGBG_DeleteMsgWin(listWin->msgWin);
    func_020409B4(1);
    STRBUF_Delete(listWin->strBuf);
    STRBUF_Delete(listWin->expandBuf);
    WORDSET_DeleteStrbufED04(listWin->wordSet);
    MSGDATA_Delete(listWin->msgData);
    return func_020307B0(listWin);
}

/* Print one line per gift: the item name, then its quantity. */
void PDW_POSTMAN_PrintListWin(PdwPostmanListWin *listWin)
{
    struct MsgBank *itemNames;
    int i;

    itemNames = func_02045B38(0, 2, 0x36, (u16)((listWin->heapId & 0x7fff) | 0x8000));
    for (i = 0; i < listWin->itemCount; i++) {
        MSGDATA_ReadString(itemNames, listWin->items[i].itemId, listWin->strBuf);
        FIELD_MSGBG_MsgWinPrintStr(listWin->msgWin, 0, i * PDW_POSTMAN_LINE_HEIGHT, listWin->strBuf);
        MSGDATA_ReadString(listWin->msgData, 5, listWin->strBuf);
        WORDSET_SetSlotNumber(listWin->wordSet, 0, listWin->items[i].count, 2, 1, 1);
        WORDSET_CopyTaggedText(listWin->wordSet, listWin->expandBuf, listWin->strBuf);
        FIELD_MSGBG_MsgWinPrintStr(listWin->msgWin, 0x6c, i * PDW_POSTMAN_LINE_HEIGHT, listWin->expandBuf);
    }
    MSGDATA_Delete(itemNames);
    func_020409B4(BMP_WIN_GetBgLayer(FIELD_MSGBG_GetMsgWinBmpWin(listWin->msgWin)));
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
            func_020307B0(work->items);
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
    items = func_02030734(heapId, sizeof(PdwPostmanItem) * PDW_POSTMAN_ITEM_MAX, 1, sPdwPostmanFileName, 0x14d);
    i = 0;
    count = 0;
    for (; i < PDW_POSTMAN_ITEM_MAX; i++) {
        itemId = func_02009310(save, i);
        itemCount = func_02009330(save, i);
        if (itemId != 0 && func_02007E3C(bag, itemId, itemCount, heapId) == 1) {
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
        int itemId = func_02009310(save, i);
        int count = func_02009330(save, i);
        if (itemId != 0) {
            if (func_02007E50(bag, itemId, count, heapId) == 1)
                func_02009364(save, i);
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
        itemId = func_02009310(save, i);
        itemCount = func_02009330(save, i);
        if (itemId != 0) {
            if (func_02007E3C(bag, itemId, itemCount, heapId) == 0)
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
        itemId = func_02009310(save, i);
        itemCount = func_02009330(save, i);
        if (itemId != 0) {
            if (func_02007E3C(bag, itemId, itemCount, heapId) == 0) {
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
    save = func_02009448(GAME_DATA_GetSaveControl(gameData));
    event = func_020122C0(gameSystem, 0, PDW_POSTMAN_ListEvent, sizeof(PdwPostmanEventWork));
    work = func_020124E8(event);
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
