/*
 * function: WORLDTRADE_INPUT_HandlePagedKey4
 * address:  0x021F9F00
 * packet:   pkt_021F9F00
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_INPUT_ScrollPage4  0x021F9F58  thumb
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
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

extern void WORLDTRADE_INPUT_ScrollPage4(Menu *m, int dir);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);

int WORLDTRADE_INPUT_HandlePagedKey4(Menu *m, int key)
{
    int idx;

    switch (key) {
    case 4:
        return -2;
    case 5:
        WORLDTRADE_INPUT_ScrollPage4(m, -1);
        return -1;
    case 6:
        WORLDTRADE_INPUT_ScrollPage4(m, 1);
        return -1;
    }
    idx = key + m->page * 4;
    if (idx < m->total) {
        GFL_USE_PlaySeDefaultVolume(0x54C);
        return m->items[idx].val;
    }
    return -1;
}
