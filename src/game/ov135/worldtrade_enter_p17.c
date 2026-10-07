/*
 * file:     worldtrade_enter_p17.c
 * unit:     yes
 * function: func_021FB240, func_021FB26C, func_021FB2F0
 * address:  0x021FB240
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200D064  0x0200D064  thumb
 *   func_021F8498  0x021F8498  thumb
 *   func_021F84BC  0x021F84BC  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021FAC50  0x021FAC50  thumb
 *   func_02045334  0x02045334  arm
 *   func_0202CEBC  0x0202CEBC  thumb
 */
struct Blk37;
struct Slot;
struct WinMgr;
struct CharBuf;
struct Descriptor;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16;

typedef signed char s8;

typedef struct {
    void *str;
    int val;
} Item;

typedef struct {
    void **wins;
    u8 pad4[0xC - 4];
    u32 up;
    u32 down;
    u8 pad14[0x18 - 0x14];
    void *mgr;
    u8 pad1C[0x30 - 0x1C];
    Item *items;
    void *num;
    u8 pad38[0x56 - 0x38];
    s16 page;
    int total;
    u8 pad5C[0x7C - 0x5C];
    u8 g[4];
} Menu;

extern u32 func_0200D064(struct Blk37 *p, u16 id);
extern u16 *func_021F8498(u32 heap, u32 unused, u32 *count);
extern void func_021F84BC(u32 i, int *start, int *end);
extern void *func_0201F81C(u32 n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u32 func_020307B0(void *p);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
extern void func_02045334(struct Descriptor *d);
extern void func_0202CEBC(struct WinMgr *mgr, u32 idx, void *a);
int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end);
int func_021FB26C(void **menu, void *msg, void *bank, u32 x, u32 kind, void *bag);
void func_021FB2F0(Menu *m, int page, int total);


/*
 * Count the entries of a u16 table that the query accepts.
 */
int func_021FB240(u32 unused, u32 item, u32 c, u16 *list, int start, int end)
{
    int i;
    int n = 0;

    for (i = start; i < end; i++) {
        if (func_0200D064((struct Blk37 *)item, list[i]) != 0) {
            n++;
        }
    }
    return n;
}


int func_021FB26C(void **menu, void *msg, void *bank, u32 x, u32 kind, void *bag)
{
    u32 count;
    int start;
    int end;
    int n;
    int i;
    u16 *list;

    list = func_021F8498(0x48, 0, &count);
    func_021F84BC(kind, &start, &end);
    count = end - start;
    n = func_021FB240(x, (u32)bag, count, list, start, end);
    *menu = func_0201F81C(n + 1, 0x48);
    for (i = start; i < end; i++) {
        if (func_0200D064(bag, list[i]) != 0) {
            func_0201F878(*menu, (u32)msg, list[i], list[i], 0x48);
        }
    }
    func_020307B0(list);
    return n;
}


void func_021FB2F0(Menu *m, int page, int total)
{
    int i;

    for (i = 0; i < 4; i++) {
        func_02043B5C(func_02045770(m->wins[i]), 0xA);
        if (i + page * 4 < total) {
            func_021FAC50(m->mgr, m->wins[i], m->items[page * 4 + i].str, 0, 0x3DC2, m->g);
        } else {
            func_02045334(m->wins[i]);
            func_0202CEBC(m->mgr, 0, m->wins[i]);
        }
    }
}
