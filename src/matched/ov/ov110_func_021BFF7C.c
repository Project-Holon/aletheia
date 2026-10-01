/*
 * function: func_021BFF7C
 * address: 0x021BFF7C
 * packet: pkt_ov110_021BFF7C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: retain scaled actor index and wrapped blit x across calls.
 * symbols:
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BF734 0x021BF734 thumb ov110
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BF724 0x021BF724 thumb ov110
 *   func_0204B528 0x0204B528 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF758 0x021BF758 thumb ov110
 *   func_0201DD68 0x0201DD68 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_020439A0 0x020439A0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Pt { u16 x, y; };
struct Actor;
struct Obj;
struct Descriptor;
struct CharBuf;
struct Bmp;
extern u32 func_021BAC44(u8 *);
extern u32 func_021BF734(u8 *);
extern u8 func_021BF6DC(u8 *);
extern u16 func_021BF724(u8 *);
extern void func_0204B528(struct Actor *, const struct Pt *);
extern void func_0204B3DC(struct Obj *, u32);
extern void func_021BF758(u8 *, u32, void *);
extern void func_0201DD68(void);
extern void *func_02045770(struct Descriptor *);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_020439A0(struct Bmp *, struct Bmp *, u32, u32, int, int, u32, u32, u32);
void func_021BFF7C(u8 *p, u32 n, u32 y)
{
    u32 font;
    struct Pt pos;
    u32 wrap, x;
    struct Bmp *dest;
    font = func_021BAC44(*(u8 **)p);
    if (n < 2 || n >= func_021BF734(*(u8 **)(p + 4))) return;
    if (!func_021BF6DC(*(u8 **)(p + 4)) && func_021BF724(*(u8 **)(p + 4)) == 11) {
        x = 24 + 112 * ((n - 2) & 1);
        n = (n - 2) * 4;
        pos.x = x;
        pos.y = y - 8;
        p += 32;
        func_0204B528(*(struct Actor **)(p + n), &pos);
        func_0204B3DC(*(struct Obj **)(p + n), 1);
        return;
    }
    func_021BF758(*(u8 **)(p + 4), n - 2, *(void **)(p + 72));
    func_0201DD68();
    if (y <= 240) {
        func_0201C7A4(func_02045770(*(struct Descriptor **)(p + 12)), 112 * ((n - 2) & 1), y, *(void **)(p + 72), (void *)font);
    } else {
        wrap = 256 - y;
        func_02043B5C(func_02045770(*(struct Descriptor **)(p + 16)), 0);
        func_0201C7A4(func_02045770(*(struct Descriptor **)(p + 16)), 0, 0, *(void **)(p + 72), (void *)font);
        n = 112 * ((n - 2) & 1);
        dest = func_02045770(*(struct Descriptor **)(p + 16));
        func_020439A0(dest, func_02045770(*(struct Descriptor **)(p + 12)), 0, 0, n, y, 96, wrap, 65535);
        dest = func_02045770(*(struct Descriptor **)(p + 16));
        func_020439A0(dest, func_02045770(*(struct Descriptor **)(p + 12)), 0, wrap, n, 0, 96, 16 - wrap, 65535);
    }
}
