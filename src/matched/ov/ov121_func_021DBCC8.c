/*
 * function: func_021DBCC8
 * address: 0x021DBCC8
 * packet: pkt_ov121_021DBCC8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note 2026-10-05 (lane Y6): no source existed. Same shape as matched sibling
 *   func_021DBC08 (rebuild entries from the list), then two slot teardowns and rebuilds from
 *   the descriptor. EXACT on the first compile with plain struct fields.
 * symbols:
 *   MYSTERY_DATA_SwapCards  0x0200A254  thumb
 *   MYSTERY_DATA_GetCardSlotNum  0x0200A348  thumb
 *   MYSTERY_DATA_IsCardExist  0x0200A0E4  thumb
 *   MYSTERY_DATA_GetCard  0x0200A000  thumb
 *   func_021DBEE4  0x021DBEE4  thumb  ov121
 *   func_021DBDF4  0x021DBDF4  thumb  ov121
 *   MYSTERY_ALBUM_Delete  0x021DD980  thumb  ov121
 *   func_021DC02C  0x021DC02C  thumb  ov121
 *   func_021DD24C  0x021DD24C  thumb  ov121
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
extern void func_021DBEE4(u32 p);
extern void func_021DBDF4(Item *it, void *data, Obj *o, u16 f);
extern void MYSTERY_ALBUM_Delete(char *p);
extern char *func_021DC02C(void *);
extern void *func_021DD24C(void *,void *,void *,u16);

void func_021DBCC8(Obj *o, u32 a, u32 b)
{
    unsigned char buf[0xCC];
    u32 i;

    MYSTERY_DATA_SwapCards(o->list, a, b);
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->list); i++)
        func_021DBEE4((u32)(&o->items[i]));
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->list); i++) {
        if (MYSTERY_DATA_IsCardExist(o->list, i)) {
            MYSTERY_DATA_GetCard(o->list, i, buf);
            func_021DBDF4(&o->items[i], buf, o, o->f24);
        }
    }
    MYSTERY_ALBUM_Delete(o->slots[a]);
    MYSTERY_ALBUM_Delete(o->slots[b]);
    o->slots[a] = func_021DD24C(func_021DC02C(&o->items[a]), o->desc, o->ctx, o->f24);
    o->slots[b] = func_021DD24C(func_021DC02C(&o->items[b]), o->desc, o->ctx, o->f24);
    o->dirty = 1;
}
