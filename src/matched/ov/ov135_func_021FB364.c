/*
 * function: func_021FB364
 * address:  0x021FB364
 * packet:   pkt_021FB364
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021FAC50  0x021FAC50  thumb
 *   func_02045334  0x02045334  arm
 *   func_0202CEBC  0x0202CEBC  thumb
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

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

extern void *func_02045770(void *win);
extern void func_02043B5C(void *bmp, u32 color);
extern void func_021FAC50(void *mgr, void *win, void *str, u32 x, u16 color, void *g);
extern void func_02045334(void *win);
extern void func_0202CEBC(void *mgr, u32 idx, void *win);

void func_021FB364(Menu *m, int page, int total)
{
    int i;

    for (i = 0; i < 5; i++) {
        func_02043B5C(func_02045770(m->wins[i]), 0xA);
        if (i + page * 5 < total) {
            func_021FAC50(m->mgr, m->wins[i], m->items[page * 5 + i].str, 0, 0x3DC2, m->g);
        } else {
            func_02045334(m->wins[i]);
            func_0202CEBC(m->mgr, 0, m->wins[i]);
        }
    }
}
