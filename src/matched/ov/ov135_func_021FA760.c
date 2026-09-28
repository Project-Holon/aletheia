/*
 * function: func_021FA760
 * address:  0x021FA760
 * packet:   pkt_021FA760
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021FA7C4  0x021FA7C4  thumb
 *   func_020061E4  0x020061E4  thumb
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

extern void func_021FA7C4(Menu *m, int dir);
extern void func_020061E4(u32 se);

int func_021FA760(Menu *m, int key)
{
    int idx;

    switch (key) {
    case 5:
        func_020061E4(0x551);
        return -2;
    case 6:
        func_021FA7C4(m, -1);
        return -1;
    case 7:
        func_021FA7C4(m, 1);
        return -1;
    }
    idx = key + m->page * 5;
    if (idx < m->total) {
        func_020061E4(0x54C);
        return m->items[idx].val;
    }
    return -1;
}
