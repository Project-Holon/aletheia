/*
 * function: func_021CA1D0
 * address:  0x021CA1D0
 * packet:   pkt_ov093_021CA1D0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9934  0x021B9934  thumb  ov093
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C2CA8  0x021C2CA8  thumb  ov093
 *   func_021D65C8  0x021D65C8  thumb  ov093
 *   func_021D6D7C  0x021D6D7C  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021CA238  0x021CA238  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Cmd {
    u32 pad;
    u8 b4;
    u8 b5;
};

extern u8 *func_021B9934(char *p, int i);
extern int func_021D62C4(void *p, int i);
extern void func_021C2CA8(void *w, u8 *x);
extern void func_021D65C8(u8 *x, u8 *y);
extern void func_021CD4B0(void *w, u32 id, ...);
extern int func_021D6D7C(u8 *x);
extern int func_021CA238(void *p, u8 i);

int func_021CA1D0(u8 *w, const struct Cmd *c)
{
    u8 *a = func_021B9934(*(char **)(w + 8), c->b4);
    u8 *b = func_021B9934(*(char **)(w + 8), c->b5);
    if (func_021D62C4(a, 0x10) != 0) func_021C2CA8(w, b);
    func_021D65C8(b, a);
    func_021CD4B0(*(void **)(w + 0xC), 0x26, c->b4, c->b5);
    if (func_021D6D7C(b) != 0) {
        int r = func_021CA238(w + 0x1AB8, c->b5);
        func_021CD4B0(*(void **)(w + 0xC), 0x51, r);
    }
    return 1;
}
