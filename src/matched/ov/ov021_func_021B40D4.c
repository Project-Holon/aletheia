/*
 * function: func_021B40D4
 * address:  0x021B40D4
 * packet:   pkt_ov021_021B40D4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0200DABC 0x0200DABC thumb
 *   func_0200C274 0x0200C274 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7D0 0x0201C7D0 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02045808 0x02045808 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern u32 func_02045EC0(u32 a, u32 b);
extern u32 func_020457B0(u32 n, u32 heap);
extern u16 func_0200DABC(u32 a);
extern u32 func_0200C274(u32 a);
extern void func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0201F250(u32 a, u32 b, u32 c);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 a, u32 b);
extern void func_0201C7D0(u32 a, s16 b, s16 c, u32 d, u32 e, u32 f);
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(u32 a);
extern u32 func_02045730(u32 a);
extern void func_020409B4(u32 a);
extern void func_02045808(u32 a);

void func_021B40D4(char *w)
{
    u32 t7, t6, s, bg;

    if (*(u8 *)(w + 0x163) == 1) {
        t7 = func_02045EC0(*(u32 *)(w + 0x188), 0x16);
        t6 = func_020457B0(10, *(u16 *)(w + 4));
        func_0201EFA4(*(u32 *)(w + 0x190), 0, func_0200DABC(*(u32 *)(w + 0x18)), 4, 1, 1);
    } else {
        t7 = func_02045EC0(*(u32 *)(w + 0x188), 0x15);
        t6 = func_020457B0(10, *(u16 *)(w + 4));
        func_0201EFA4(*(u32 *)(w + 0x190), 0, func_0200C274(*(u32 *)(w + 0xC)), 7, 1, 1);
    }
    func_0201F250(*(u32 *)(w + 0x190), t6, t7);
    s = (u32)func_02045770((struct Descriptor *)*(u32 *)(w + 0x168));
    func_02043B5C(s, 0);
    func_0201C7D0(s, 0, 0, t6, *(u32 *)(w + 8), 0x3C4F);
    bg = *(u32 *)(w + 0x168);
    func_02045334((struct Descriptor *)bg);
    func_02045374(bg);
    func_020409B4(func_02045730(bg));
    func_02045808(t6);
    func_02045808(t7);
}
