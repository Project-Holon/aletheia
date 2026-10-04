/*
 * function: func_021B42D0
 * address:  0x021B42D0
 * packet:   pkt_ov021_021B42D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021D945C    0x021D945C data a4
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
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

extern u32 d_021D945C[];

extern u32 func_02045EC0(u32 a, u32 b);
extern u32 func_020457B0(u32 n, u32 heap);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 a, u32 b);
extern void func_0201F73C(u32 a, u32 b, u32 c, u32 d);
extern void func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern void func_0201C7D0(u32 a, s16 b, s16 c, u32 d, u32 e, u32 f);
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(u32 a);
extern u32 func_02045730(u32 a);
extern void func_020409B4(u32 a);
extern void func_02045808(u32 a);

void func_021B42D0(char *w, u32 a, u32 b)
{
    u32 t1, t2, t3, s, bg;

    t1 = func_02045EC0(*(u32 *)(w + 0x188), 0x18);
    t2 = func_02045EC0(*(u32 *)(w + 0x188), d_021D945C[*(u8 *)(w + 0x163)]);
    t3 = func_020457B0(0x14, *(u16 *)(w + 4));
    s = (u32)func_02045770((struct Descriptor *)*(u32 *)(w + 0x174));
    func_02043B5C(s, 0xF);
    func_0201F73C(*(u32 *)(w + 0x174), 2, 0xE4, 9);
    func_0201EFA4(*(u32 *)(w + 0x190), 0, a, 2, 0, 1);
    func_0201F250(*(u32 *)(w + 0x190), t3, t1);
    func_0201C7D0(s, 0, 0, t3, *(u32 *)(w + 8), 0x44F);
    func_0201EFA4(*(u32 *)(w + 0x190), 0, a * b, 7, 1, 1);
    func_0201F250(*(u32 *)(w + 0x190), t3, t2);
    if (*(u8 *)(w + 0x163) == 0) {
        func_0201C7D0(s, 0x23, 0, t3, *(u32 *)(w + 8), 0x44F);
    } else {
        func_0201C7D0(s, 0x1D, 0, t3, *(u32 *)(w + 8), 0x44F);
    }
    bg = *(u32 *)(w + 0x174);
    func_02045334((struct Descriptor *)bg);
    func_02045374(bg);
    func_020409B4(func_02045730(bg));
    func_02045808(t3);
    func_02045808(t2);
    func_02045808(t1);
}
