/*
 * function: func_021DBC08
 * address:  0x021DBC08
 * packet:   pkt_ov121_021DBC08
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Rebuild every entry from the list, free slot idx, then pull each later
 * slot down one place (swap into an empty slot), and mark the table dirty.
 *
 * symbols:
 *   MYSTERY_DATA_DeleteCard  0x0200A094  thumb
 *   MYSTERY_DATA_GetCardSlotNum  0x0200A348  thumb
 *   func_0200A0E4  0x0200A0E4  thumb
 *   func_0200A000  0x0200A000  thumb
 *   func_021DBEE4  0x021DBEE4  thumb  ov121
 *   func_021DBDF4  0x021DBDF4  thumb  ov121
 *   MYSTERY_ALBUM_Delete  0x021DD980  thumb  ov121
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Item {
    unsigned char raw[0xDC];
} Item;

typedef struct Obj {
    unsigned char pad00[0xC];
    void *list;
    unsigned char pad10[0x14];
    u16 f24;
    unsigned char pad26[2];
    Item items[12];
    unsigned char pad[0xA7C - 0x28 - 12 * 0xDC];
    void *slots[12];
    unsigned char padAAC[0xAD4 - 0xAAC];
    int dirty;
} Obj;

extern void MYSTERY_DATA_DeleteCard(void *list, u32 idx);
extern u32 MYSTERY_DATA_GetCardSlotNum(struct Obj *list);
typedef unsigned char  u8;
extern u32 func_0200A0E4(u8 *p, u32 a);
extern int func_0200A000(char *p, int idx, void *buf);
extern void func_021DBEE4(u32 p);
extern void func_021DBDF4(Item *it, void *data, Obj *o, u16 f);
extern void MYSTERY_ALBUM_Delete(char *p);

void func_021DBC08(Obj *o, int idx)
{
    unsigned char buf[0xCC];
    u32 i;

    MYSTERY_DATA_DeleteCard(o->list, idx);
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->list); i++)
        func_021DBEE4((u32)(&o->items[i]));
    for (i = 0; i < MYSTERY_DATA_GetCardSlotNum(o->list); i++) {
        if (func_0200A0E4(o->list, i)) {
            func_0200A000(o->list, i, buf);
            func_021DBDF4(&o->items[i], buf, o, o->f24);
        }
    }
    if (o->slots[idx] != 0) {
        MYSTERY_ALBUM_Delete(o->slots[idx]);
        o->slots[idx] = 0;
    }
    for (; idx < 11; idx++) {
        void *tmp = o->slots[idx];
        if (tmp == 0) {
            o->slots[idx] = o->slots[idx + 1];
            o->slots[idx + 1] = tmp;
        }
    }
    o->dirty = 1;
}
