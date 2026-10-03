/*
 * function: func_022028C8
 * address:  0x022028C8
 * packet:   pkt_022028C8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034714  0x02034714  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 */

typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win;
    u8 busy;
    u8 pad5[3];
    u32 used;
} Slot;

typedef struct {
    u32 font;
    u8 pad4[0xC - 0x4];
    u32 print;
    u8 pad10[0x18 - 0x10];
    Slot slots[24];
} Ctx;

extern void func_02034714(const char *expr, u32 line, const char *file);
extern u32 func_02045770(void *win);
extern void func_0201C724(u32 print, u32 bmp, s16 x, s16 y, u32 str, u32 font, u16 color);

u32 func_022028C8(void *win, u32 z, u32 str, u32 x, u32 y, u32 z2, u16 color, Ctx *g)
{
    Slot *found = 0;
    int i;
    u32 print;

    for (i = 0; i < 24; i++) {
        if (g->slots[i].used == 0) {
            found = &g->slots[i];
        }
    }
    if (found == 0) {
        func_02034714((void *)0x02203F74, 0, (void *)0x02203F74);
    }
    found->win = win;
    found->busy = 0;
    print = g->print;
    func_0201C724(print, func_02045770(win), x, y, str, g->font, color);
    found->busy = 1;
    found->used = 1;
    return 1;
}
