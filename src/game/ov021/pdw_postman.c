/*
 * file:     pdw_postman.c
 * unit:     yes
 * function: func_021B7400, func_021B7494, func_021B74CC, func_021B7574, func_021B7640, func_021B76B4, func_021B76F8, func_021B7740, func_021B7794, func_021B77E4, func_021B7834, func_021B785C, func_021B7864
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
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188C54  0x02188C54  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02045B38  0x02045B38  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02190708  0x02190708  thumb  ov021
 *   d_021DE288     0x021DE288  data   ov021  a1
 *   func_02190788  0x02190788  thumb  ov021
 *   func_02190728  0x02190728  thumb  ov021
 *   func_020409B4  0x020409B4  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02190758  0x02190758  thumb  ov021
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_021907C0  0x021907C0  thumb  ov021
 *   func_02045730  0x02045730  arm
 *   func_02192788  0x02192788  thumb  ov021
 *   func_0219077C  0x0219077C  thumb  ov021
 *   func_02045770  0x02045770  arm
 *   func_021928C0  0x021928C0  thumb  ov021
 *   func_02045334  0x02045334  arm
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_021927B0  0x021927B0  thumb  ov021
 *   func_0201292C  0x0201292C  thumb
 *   func_02009310  0x02009310  thumb
 *   func_02009330  0x02009330  thumb
 *   func_02007E3C  0x02007E3C  thumb
 *   func_02007E50  0x02007E50  thumb
 *   func_02009364  0x02009364  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02009448  0x02009448  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0200A0E4  0x0200A0E4  thumb
 *   func_0200A104  0x0200A104  thumb
 *   func_0200A000  0x0200A000  thumb
 *   func_0200A13C  0x0200A13C  thumb
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

extern u16 func_02188C84(struct FieldMap *fieldMap);
extern struct FieldMsgBg *func_02188C54(struct FieldMap *fieldMap);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 func_02045C04(struct MsgBank *msgData);
extern void func_02045CAC(struct MsgBank *msgData, u32 strId, struct StrBuf *dest);
extern struct WordSet *func_0201EC64(u32 heapId);
extern u32 func_0201ED04(struct WordSet *wordSet);
extern void func_0201EFA4(struct WordSet *wordSet, u32 bufId, u32 number, u32 digits, u32 dispType, u32 code);
extern void func_0201F250(struct WordSet *wordSet, struct StrBuf *dest, struct StrBuf *src);
extern struct StrBuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct StrBuf *strBuf);
extern u8 func_02045730(struct BmpWin *bmpWin);
extern struct Bitmap *func_02045770(struct BmpWin *bmpWin);
extern void func_02045334(struct BmpWin *bmpWin);
extern void func_020409B4(u32 bgFrame);
extern struct FieldMsgWin *func_02190708(struct FieldMsgBg *msgBg, struct MsgBank *msgData, u16 x, u16 y, u16 width, u16 height);
extern int func_02190728(struct FieldMsgWin *msgWin);
extern void func_02190758(struct FieldMsgWin *msgWin, int x, u16 y, struct StrBuf *str);
extern int func_0219077C(struct FieldMsgWin *msgWin);
extern void func_02190788(struct FieldMsgWin *msgWin);
extern struct BmpWin *func_021907C0(struct FieldMsgWin *msgWin);
extern struct FieldMsgCursor *func_02192788(struct FieldMsgBg *msgBg);
extern void func_021927B0(struct FieldMsgCursor *cursor);
extern void func_021928C0(struct FieldMsgCursor *cursor, struct Bitmap *bmp, u32 color);
extern u32 func_020362DC(void);
extern void func_020061E4(u32 seNo);
extern struct MyItem *func_0201292C(const struct GameData *gameData);
extern u16 func_02009310(const struct PdwPostmanSave *save, int slot);
extern u8 func_02009330(const struct PdwPostmanSave *save, int slot);
extern void func_02009364(struct PdwPostmanSave *save, int slot);
extern int func_02007E3C(struct MyItem *bag, u32 itemId, u32 count, u32 heapId);
extern int func_02007E50(struct MyItem *bag, int itemId, int count, int heapId);
extern struct GameData *func_020120F4(const struct GameSystem *gameSystem);
extern struct FieldMap *func_0201210C(const struct GameSystem *gameSystem);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern struct PdwPostmanSave *func_02009448(struct SaveControl *save);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, struct GameEvent *parent, GameEventFunc func, u32 workSize);
extern void *func_020124E8(struct GameEvent *event);
extern u32 func_0200A0E4(struct MysteryData *data, u32 slot);
extern int func_0200A104(struct MysteryData *data, unsigned int slot);
extern int func_0200A000(struct MysteryData *data, int slot, MysteryCard *card);
extern void func_0200A13C(struct MysteryData *data, u32 slot);

PdwPostmanListWin *func_021B7400(struct FieldMap *fieldMap, PdwPostmanItem *items, int itemCount);
int func_021B7494(PdwPostmanListWin *listWin);
void func_021B74CC(PdwPostmanListWin *listWin);
int func_021B7574(struct GameEvent *event, int *seq, void *eventWork);
PdwPostmanItem *func_021B7640(struct GameData *gameData, u32 heapId, struct PdwPostmanSave *save, int *outCount);
void func_021B76B4(struct GameData *gameData, int heapId, struct PdwPostmanSave *save);
int func_021B76F8(struct GameData *gameData, int heapId, struct PdwPostmanSave *save);
u32 func_021B7740(struct GameData *gameData, int heapId, struct PdwPostmanSave *save, int index);
struct GameEvent *func_021B7794(struct GameSystem *gameSystem);
MysteryCard *func_021B77E4(struct MysteryData *data, int slot, MysteryCard *card);
MysteryCard *func_021B7834(struct MysteryData *data, int *outSlot, MysteryCard *card);
void func_021B785C(struct MysteryData *data, u32 slot);
u8 func_021B7864(struct MysteryData *data);

extern const char d_021DE288[];

PdwPostmanListWin *func_021B7400(struct FieldMap *fieldMap, PdwPostmanItem *items, int itemCount)
{
    u32 heapId;
    PdwPostmanListWin *listWin;
    int height;

    heapId = func_02188C84(fieldMap);
    listWin = func_02030734(heapId, sizeof(PdwPostmanListWin), 1, d_021DE288, 0x73);
    listWin->heapId = heapId;
    listWin->fieldMap = fieldMap;
    listWin->items = items;
    listWin->itemCount = itemCount;
    listWin->msgData = func_02045B38(0, 3, 0x13B, heapId);
    listWin->wordSet = func_0201EC64(heapId);
    listWin->strBuf = func_020457B0(0x80, heapId);
    listWin->expandBuf = func_020457B0(0x80, heapId);
    height = (itemCount * PDW_POSTMAN_LINE_HEIGHT + 7) & ~7;
    listWin->msgWin = func_02190708(func_02188C54(fieldMap), listWin->msgData, 1, 1, 0x15, (u16)(height / 8));
    return listWin;
}

/* Addresses are Black-image addresses. */
int func_021B7494(PdwPostmanListWin *listWin)
{
    func_02190788(listWin->msgWin);
    func_02190728(listWin->msgWin);
    func_020409B4(1);
    func_02045808(listWin->strBuf);
    func_02045808(listWin->expandBuf);
    func_0201ED04(listWin->wordSet);
    func_02045C04(listWin->msgData);
    return func_020307B0(listWin);
}

/* Print one line per gift: the item name, then its quantity. */
void func_021B74CC(PdwPostmanListWin *listWin)
{
    struct MsgBank *itemNames;
    int i;

    itemNames = func_02045B38(0, 2, 0x36, (u16)((listWin->heapId & 0x7fff) | 0x8000));
    for (i = 0; i < listWin->itemCount; i++) {
        func_02045CAC(itemNames, listWin->items[i].itemId, listWin->strBuf);
        func_02190758(listWin->msgWin, 0, i * PDW_POSTMAN_LINE_HEIGHT, listWin->strBuf);
        func_02045CAC(listWin->msgData, 5, listWin->strBuf);
        func_0201EFA4(listWin->wordSet, 0, listWin->items[i].count, 2, 1, 1);
        func_0201F250(listWin->wordSet, listWin->expandBuf, listWin->strBuf);
        func_02190758(listWin->msgWin, 0x6c, i * PDW_POSTMAN_LINE_HEIGHT, listWin->expandBuf);
    }
    func_02045C04(itemNames);
    func_020409B4(func_02045730(func_021907C0(listWin->msgWin)));
}

/*
 * Gift list event: show the gifts a page of seven at a time, wait for the A
 * button on each page.
 * Addresses are Black-image addresses.
 */
int func_021B7574(struct GameEvent *event, int *seq, void *eventWork)
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
        work->listWin = func_021B7400(work->fieldMap, work->items + work->pageTop, count);
        func_021B74CC(work->listWin);
        work->listWin->cursor = func_02192788(func_02188C54(work->fieldMap));
        (*seq)++;
        break;
    case 1:
        if (func_0219077C(work->listWin->msgWin) == 1) {
            (*seq)++;
        }
        break;
    case 2:
        bmpWin = func_021907C0(work->listWin->msgWin);
        func_021928C0(work->listWin->cursor, func_02045770(bmpWin), 15);
        func_02045334(bmpWin);
        if (func_020362DC() & 1) {
            func_020061E4(0x547);
            (*seq)++;
        }
        break;
    case 3:
        func_021927B0(work->listWin->cursor);
        func_021B7494(work->listWin);
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
PdwPostmanItem *func_021B7640(struct GameData *gameData, u32 heapId, struct PdwPostmanSave *save, int *outCount)
{
    PdwPostmanItem *items;
    struct MyItem *bag;
    int count;
    int i;
    u16 itemId;
    u16 itemCount;

    bag = func_0201292C(gameData);
    items = func_02030734(heapId, sizeof(PdwPostmanItem) * PDW_POSTMAN_ITEM_MAX, 1, d_021DE288, 0x14d);
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
void func_021B76B4(struct GameData *gameData, int heapId, struct PdwPostmanSave *save)
{
    struct MyItem *bag = func_0201292C(gameData);
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
int func_021B76F8(struct GameData *gameData, int heapId, struct PdwPostmanSave *save)
{
    struct MyItem *bag;
    u32 i;
    int count;
    u32 itemId;
    int itemCount;

    bag = func_0201292C(gameData);
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
u32 func_021B7740(struct GameData *gameData, int heapId, struct PdwPostmanSave *save, int index)
{
    struct MyItem *bag;
    int i;
    int count;
    u32 itemId;
    int itemCount;

    bag = func_0201292C(gameData);
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
struct GameEvent *func_021B7794(struct GameSystem *gameSystem)
{
    struct GameData *gameData;
    struct PdwPostmanSave *save;
    struct GameEvent *event;
    PdwPostmanEventWork *work;

    gameData = func_020120F4(gameSystem);
    save = func_02009448(func_02012EBC(gameData));
    event = func_020122C0(gameSystem, 0, func_021B7574, sizeof(PdwPostmanEventWork));
    work = func_020124E8(event);
    work->fieldMap = func_0201210C(gameSystem);
    work->pageTop = 0;
    work->items = func_021B7640(gameData, func_02188C84(work->fieldMap), save, (int *)&work->itemCount);
    return event;
}

/* The mystery gift card of the slot when it waits for delivery (gift type 1..3). */
MysteryCard *func_021B77E4(struct MysteryData *data, int slot, MysteryCard *card)
{
    u8 giftType;

    if (func_0200A0E4(data, slot) == 0)
        return 0;
    if (func_0200A104(data, slot) == 1)
        return 0;
    if (func_0200A000(data, slot, card) == 0)
        return 0;
    giftType = card->giftType;
    if (giftType == 0)
        return 0;
    if (giftType > 3)
        card = 0;
    return card;
}

/* First mystery gift waiting for delivery; its slot goes to outSlot. */
MysteryCard *func_021B7834(struct MysteryData *data, int *outSlot, MysteryCard *card)
{
    int i;

    for (i = 0; i < PDW_POSTMAN_MYSTERY_SLOTS; i++) {
        if (func_021B77E4(data, i, card)) {
            *outSlot = i;
            return card;
        }
    }
    return 0;
}

/* Mark the mystery gift of the slot as delivered. */
void func_021B785C(struct MysteryData *data, u32 slot)
{
    func_0200A13C(data, slot);
}

/* Gift type of the first mystery gift waiting for delivery, 0 when none. */
u8 func_021B7864(struct MysteryData *data)
{
    int slot;
    MysteryCard card;
    MysteryCard *found;

    found = func_021B7834(data, &slot, &card);
    if (found == 0) {
        return 0;
    }
    return found->giftType;
}
