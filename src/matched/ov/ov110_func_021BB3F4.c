/*
 * function: func_021BB3F4
 * address: 0x021BB3F4
 * packet: pkt_ov110_021BB3F4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: declare x,y before bank,font to place the four spilled locals.
 * symbols:
 *   d_021C38C4 0x021C38C4 data ov110 a1
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021B999C 0x021B999C thumb ov110
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern const u8 d_021C38C4[];
extern u32 func_021BAC44(u8 *);
extern u32 func_021B999C(u8 *, int);
extern void *func_02045B38(u32, u32, u32, u32);
extern void *func_02045EC0(void *, u32);
extern void func_0201DD78(u32, u32, u32);
extern u32 func_020450F0(u32, u8, u8, u32, u8, u8, u8);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, u8);
extern u32 func_0201D304(void *, u32, u32);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void func_02045374(void *);
extern void func_02045334(void *);
extern void func_02045808(void *);
extern void func_02045C04(void *);
u8 *func_021BB3F4(u8 *p, u8 *q)
{
    int x, y;
    void *bank;
    u32 font;
    int i;
    void *str, *win;
    u32 width;
    font = func_021BAC44(*(u8 **)p);
    bank = func_02045B38(0, 2, 145, 42);
    x = 1;
    y = 9;
    for (i = 0; i < 12; i++) {
        if (i != 0 && i % 3 == 0) { x = 1; y += 3; }
        if (func_021B999C(*(u8 **)(p + 8), i)) {
            str = func_02045EC0(bank, d_021C38C4[i]);
            func_0201DD78(1, 2, 15);
        } else {
            str = func_02045EC0(bank, 13);
            func_0201DD78(3, 4, 15);
        }
        win = (void *)func_020450F0(1, x, y, 9, 2, 12, 1);
        func_02043B5C(func_02045770(win), 15);
        width = 72 - func_0201D304(str, font, 0);
        func_0201C7A4(func_02045770(win), width >> 1, 0, str, (void *)font);
        func_02045374(win);
        func_02045334(win);
        func_02045808(str);
        *(void **)(p + i * 4 + 0x60) = win;
        q += 18;
        x += 10;
    }
    func_02045C04(bank);
    return q;
}
