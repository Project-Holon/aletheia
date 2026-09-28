/*
 * function: func_021BD038
 * address:  0x021BD038
 * packet:   pkt_ov172_021BD038
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD134  0x021BD134  thumb  ov172
 *   func_020456F8  0x020456F8  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_021BD0C4  0x021BD0C4  thumb  ov172
 *   func_021BE34C  0x021BE34C  thumb  ov172
 *   func_020409B4  0x020409B4  arm
 *
 * Follows the mode byte at +0x14 against its last seen value (+0x15): entering mode 0 prints message 0x1c in the text window and switches the display to the window at +0x2c; leaving mode 0 prints message 0x11 in the window at +0x30 and switches back.
 */

typedef unsigned char u8;
typedef unsigned long u32;

extern void func_021BD134(void *ctx, char *st, u32 msgId);
extern void func_020456F8(u32 win);
extern void func_02045730(u32 win);
extern void func_02041B6C(void);
extern void func_0201F7A8(u32 win, u32 kind);
extern void func_021BD0C4(void *ctx, char *st, int msgId);
extern void func_021BE34C(void *p);
extern void func_020409B4(void);

static inline void func_021BD038_show(u32 win)
{
    func_020456F8(win);
    func_02045730(win);
}

void func_021BD038(void *ctx, char *st)
{
    if (*(u8 *)(st + 0x14) == *(u8 *)(st + 0x15))
        return;
    if (*(u8 *)(st + 0x14) == 0) {
        func_021BD134(ctx, st, 0x1c);
        *(u32 *)(st + 0x38) = 1;
        func_021BD038_show(*(u32 *)(st + 0x2c));
        func_02041B6C();
        func_0201F7A8(*(u32 *)(st + 0x2c), 1);
    } else if (*(u8 *)(st + 0x15) == 0 && *(u8 *)(st + 0x14) != 0) {
        func_021BD0C4(ctx, st, 0x11);
        func_021BE34C(ctx);
        func_0201F7A8(*(u32 *)(st + 0x30), 1);
        func_021BD038_show(*(u32 *)(st + 0x30));
        func_020409B4();
    }
    *(u8 *)(st + 0x15) = *(u8 *)(st + 0x14);
}
