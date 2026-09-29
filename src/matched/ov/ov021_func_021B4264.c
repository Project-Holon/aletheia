/*
 * function: func_021B4264
 * address:  0x021B4264
 * packet:   pkt_ov021_021B4264
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */

typedef unsigned int u32;
typedef short s16;

extern u32 func_02045770(u32 a);
extern void func_02043B5C(u32 a, u32 b);
extern u32 func_02045EC0(u32 a, u32 b);
extern void func_0201C7D0(u32 a, s16 b, s16 c, u32 d, u32 e, u32 f);
extern void func_02045808(u32 a);
extern void func_02045334(u32 a);
extern void func_02045374(u32 a);
extern u32 func_02045730(u32 a);
extern void func_020409B4(u32 a);

void func_021B4264(char *w, u32 b)
{
    u32 win;
    u32 t;
    u32 bg;

    win = func_02045770(*(u32 *)(w + 0x178));
    func_02043B5C(win, 0);
    if (b <= 0x272) {
        t = func_02045EC0(*(u32 *)(w + 0x18C), b);
        func_0201C7D0(win, 0, 0, t, *(u32 *)(w + 8), 0x3C40);
        func_02045808(t);
    }
    bg = *(u32 *)(w + 0x178);
    func_02045334(bg);
    func_02045374(bg);
    func_020409B4(func_02045730(bg));
}
