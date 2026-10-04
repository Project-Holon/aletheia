/*
 * function: func_021B41AC
 * address:  0x021B41AC
 * packet:   pkt_ov021_021B41AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The spilled second parameter is a u16 (func_021B3370 passes a u16 field
 * to func_02007FB8 in the same slot): as u32 its entry spill
 * `str r1, [sp, #8]` lands after the `lsls` instead of before it.
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   func_02007FB8 0x02007FB8 thumb
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
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern u32 func_02045EC0(u32 a, u32 b);
extern u32 func_020457B0(u32 n, u32 heap);
extern void func_0201F73C(u32 a, u32 b, u32 c, u32 d);
extern u16 func_02007FB8(u32 a, u32 b, u32 c);
extern void func_0201EFA4(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern void func_0201F250(u32 a, u32 b, u32 c);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(u32 a, u32 b);
extern void func_0201C7D0(u32 a, s16 b, s16 c, u32 d, u32 e, u32 f);
extern void func_02045334(u32 a);
extern void func_02045374(u32 a);
extern u32 func_02045730(u32 a);
extern void func_020409B4(u32 a);
extern void func_02045808(u32 a);

void func_021B41AC(char *w, u16 b)
{
    u32 t7, t6, s, bg;

    t7 = func_02045EC0(*(u32 *)(w + 0x188), 0x17);
    t6 = func_020457B0(0x14, *(u16 *)(w + 4));
    func_0201F73C(*(u32 *)(w + 0x170), 2, 0xE4, 9);
    func_0201EFA4(*(u32 *)(w + 0x190), 0, func_02007FB8(*(u32 *)(w + 0x10), b, *(u16 *)(w + 4)), 3, 0, 1);
    func_0201F250(*(u32 *)(w + 0x190), t6, t7);
    s = (u32)func_02045770((struct Descriptor *)*(u32 *)(w + 0x170));
    func_02043B5C(s, 0xF);
    func_0201C7D0(s, 0, 0, t6, *(u32 *)(w + 8), 0x44F);
    bg = *(u32 *)(w + 0x170);
    func_02045334(bg);
    func_02045374(bg);
    func_020409B4(func_02045730(bg));
    func_02045808(t6);
    func_02045808(t7);
}
