/*
 * function: MYSTERY_ALBUM_SwapCards
 * address: 0x021DBCC8
 * packet: pkt_ov121_021DBCC8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (lane Y6): no source existed. Same shape as matched sibling
 *   MYSTERY_ALBUM_RemoveCard (rebuild entries from the list), then two slot teardowns and rebuilds from
 *   the descriptor. EXACT on the first compile with plain struct fields.
 * symbols:
 *   MYSTERY_DATA_SwapCards  0x0200A254  thumb
 *   MYSTERY_DATA_GetCardSlotNum  0x0200A348  thumb
 *   MYSTERY_DATA_IsCardExist  0x0200A0E4  thumb
 *   MYSTERY_DATA_GetCard  0x0200A000  thumb
 *   MYSTERY_ALBUM_ClearEntry  0x021DBEE4  thumb  ov121
 *   MYSTERY_ALBUM_SetupEntry  0x021DBDF4  thumb  ov121
 *   MYSTERY_ALBUM_Delete  0x021DD980  thumb  ov121
 *   MYSTERY_ALBUM_GetEntryCard  0x021DC02C  thumb  ov121
 *   MYSTERY_ALBUM_CreateAlbumView  0x021DD24C  thumb  ov121
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Item { unsigned char raw[0xDC]; } Item;
typedef struct Obj {
    unsigned char pad00[0xC];
    void *list;
    unsigned char pad10[0x10];
    void *ctx;
    u16 f24;
    unsigned char pad26[2];
    Item items[12];
    unsigned char pad[0xA7C - 0x28 - 12 * 0xDC];
    void *slots[12];
    unsigned char padAAC[4];
    void *desc;
    unsigned char padAB4[0xAD4 - 0xAB4];
    int dirty;
} Obj;
extern void MYSTERY_DATA_SwapCards(void *, u32, u32);
extern u32 MYSTERY_DATA_GetCardSlotNum(struct Obj *list);
typedef unsigned char u8;
extern u32 MYSTERY_DATA_IsCardExist(u8 *p, u32 a);
extern int MYSTERY_DATA_GetCard(char *p, int idx, void *buf);
extern void MYSTERY_ALBUM_ClearEntry(u32 p);
extern void MYSTERY_ALBUM_SetupEntry(Item *it, void *data, Obj *o, u16 f);
extern void MYSTERY_ALBUM_Delete(char *p);
extern char *MYSTERY_ALBUM_GetEntryCard(void *);
extern void *MYSTERY_ALBUM_CreateAlbumView(void *,void *,void *,u16);

void MYSTERY_ALBUM_SwapCards(Obj *o, u32 a, u32 b)
{
    unsigned char buf[0xCC];
    u32 i;

    MYSTERY_DATA_SwapCards(o->list, a, b);
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->list); i++)
        MYSTERY_ALBUM_ClearEntry((u32)(&o->items[i]));
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->list); i++) {
        if (MYSTERY_DATA_IsCardExist(o->list, i)) {
            MYSTERY_DATA_GetCard(o->list, i, buf);
            MYSTERY_ALBUM_SetupEntry(&o->items[i], buf, o, o->f24);
        }
    }
    MYSTERY_ALBUM_Delete(o->slots[a]);
    MYSTERY_ALBUM_Delete(o->slots[b]);
    o->slots[a] = MYSTERY_ALBUM_CreateAlbumView(MYSTERY_ALBUM_GetEntryCard(&o->items[a]), o->desc, o->ctx, o->f24);
    o->slots[b] = MYSTERY_ALBUM_CreateAlbumView(MYSTERY_ALBUM_GetEntryCard(&o->items[b]), o->desc, o->ctx, o->f24);
    o->dirty = 1;
}
