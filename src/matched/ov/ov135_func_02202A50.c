/*
 * function: func_02202A50
 * address:  0x02202A50
 * packet:   pkt_02202A50
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02045770  0x02045770  arm
 *   func_0201C724  0x0201C724  thumb
 *   func_02045808  0x02045808  arm
 *   func_02034714  0x02034714  arm
 */

typedef signed char s8;
typedef signed short s16;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *win;
    u8 shown;
    u8 pad5[3];
} Slot;

typedef struct {
    void *font;
    void *print;
    void *words;
    void *bank;
    Slot slot[8];
    u32 used[8];
    u16 heap;
} Ctx;

struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C724(void *print, void *bmp, s16 x, s16 y, void *str, void *font, u16 color);
extern void func_02045808(struct U16Vec *vec);
extern void func_02034714(const char *expr, u32 line, const char *file);

void func_02202A50(Ctx *ctx, u32 num, u32 digits, u32 mode, void *win, int x, int y)
{
    void *str;
    void *fmt;
    void *print;
    int i;

    str = func_020457B0(0x20, ctx->heap);
    fmt = func_020457B0(0x20, ctx->heap);
    func_02045CAC(ctx->bank, 0xFD, fmt);
    func_0201EFA4(ctx->words, 0, num, digits, mode, 1);
    func_0201F250(ctx->words, str, fmt);
    for (i = 0; i < 8; i++) {
        if (ctx->used[i] == 0) {
            ctx->slot[i].win = win;
            ctx->slot[i].shown = 0;
            print = ctx->print;
            func_0201C724(print, func_02045770(ctx->slot[i].win), x, y, str, ctx->font, 0x3DC8);
            ctx->slot[i].shown = 1;
            ctx->used[i] = 1;
            func_02045808(fmt);
            func_02045808(str);
            return;
        }
    }
    func_02034714((void *)0x02203F74, 0, (void *)0x02203F74);
}
