/*
 * function: func_021B7F54
 * address:  0x021B7F54
 * packet:   pkt_ov070_021B7F54
 * region:   ov070
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Sort the saved (id, count) list by a key read from each id's record:
 * copy the list out, build 8-byte (item, key) entries, MATH_QSort them
 * with func_021B7F38, write the list back.
 *
 * Levers: the copy-back loop is a 4-byte struct assignment of the nested
 * Item (two field stores allocate r2/r3 the other way round); `e = &ents[i]`
 * taken before the first func_02021014 call places the i*8 spill there.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   sub_02007CC8   0x02007CC8  thumb
 *   func_021B61C8  0x021B61C8  thumb  ov070
 *   func_02020F14  0x02020F14  thumb
 *   func_02020F20  0x02020F20  thumb
 *   func_02021014  0x02021014  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   MATH_QSort     0x02081BE4  arm
 *   func_021B7F38  0x021B7F38  thumb  ov070
 *   d_021BBBC0     0x021BBBC0  data  ov070  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Obj {
    u8 pad000[0x18];
    void *save;
    u8 pad01C[0x544 - 0x1C];
    u16 heap;
    u8 pad546[0x80C - 0x546];
    u32 pocket;
} Obj;

typedef struct Item {
    u16 id;
    u16 count;
} Item;

typedef struct Ent {
    Item item;
    u32 key;
} Ent;

extern char d_021BBBC0[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void sub_02007CC8(u8 *base, void *buf, u32 id, int save);
extern int func_021B61C8(u8 *p);
extern int func_02020F14(u32 heap);
extern int func_02020F20(int h, int id, u16 heap);
struct Rec;
extern u32 func_02021014(struct Rec *p, u32 sel);
extern void func_020307B0(void *p);
extern void func_02049238(int h);
extern void MATH_QSort(void *head, u32 num, u32 width, int (*comp)(Ent *, Ent *), void *buf);
extern int func_021B7F38(Ent *a, Ent *b);

void func_021B7F54(Obj *o)
{
    int i;
    Ent *ents;
    Item *items;
    int n;
    int h;
    int rec;
    u32 x;
    Ent *e;

    ents = func_02030734(o->heap, 0x9B0, 0, d_021BBBC0, 0xB35);
    items = func_02030734(o->heap, 0x4D8, 0, d_021BBBC0, 0xB36);
    sub_02007CC8(o->save, items, o->pocket, 1);
    n = func_021B61C8((u8 *)o);
    h = func_02020F14(o->heap);
    for (i = 0; i < n; i++) {
        rec = func_02020F20(h, items[i].id, o->heap);
        e = &ents[i];
        x = func_02021014((struct Rec *)rec, 0xF);
        e->key = (x << 28) + (func_02021014((struct Rec *)rec, 0x11) << 16) + items[i].id;
        e->item = items[i];
        func_020307B0((void *)rec);
    }
    func_02049238(h);
    MATH_QSort(ents, n, 8, func_021B7F38, 0);
    for (i = 0; i < n; i++) {
        items[i] = ents[i].item;
    }
    sub_02007CC8(o->save, items, o->pocket, 0);
    func_020307B0(items);
    func_020307B0(ents);
}
