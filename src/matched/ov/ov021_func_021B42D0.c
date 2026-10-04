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

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C7D0(void *x, s16 y, s16 z, void *s, void *w, u16 v);
extern void func_02045334(struct Descriptor *a);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void func_02045808(struct U16Vec *vec);

void func_021B42D0(char *w, u32 a, u32 b)
{
    u32 t1, t2, t3, s, bg;

    t1 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)(w + 0x188)), 0x18);
    t2 = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)(w + 0x188)), d_021D945C[*(u8 *)(w + 0x163)]);
    t3 = (u32)func_020457B0(0x14, *(u16 *)(w + 4));
    s = (u32)func_02045770((struct Descriptor *)*(u32 *)(w + 0x174));
    func_02043B5C((struct CharBuf *)s, 0xF);
    func_0201F73C((void *)(*(u32 *)(w + 0x174)), 2, 0xE4, 9);
    func_0201EFA4((struct WordSet *)(*(u32 *)(w + 0x190)), 0, a, 2, 0, 1);
    func_0201F250((struct WordSet *)(*(u32 *)(w + 0x190)), (void *)t3, (void *)t1);
    func_0201C7D0((void *)s, 0, 0, (void *)t3, (void *)(*(u32 *)(w + 8)), 0x44F);
    func_0201EFA4((struct WordSet *)(*(u32 *)(w + 0x190)), 0, a * b, 7, 1, 1);
    func_0201F250((struct WordSet *)(*(u32 *)(w + 0x190)), (void *)t3, (void *)t2);
    if (*(u8 *)(w + 0x163) == 0) {
        func_0201C7D0((void *)s, 0x23, 0, (void *)t3, (void *)(*(u32 *)(w + 8)), 0x44F);
    } else {
        func_0201C7D0((void *)s, 0x1D, 0, (void *)t3, (void *)(*(u32 *)(w + 8)), 0x44F);
    }
    bg = *(u32 *)(w + 0x174);
    func_02045334((struct Descriptor *)bg);
    func_02045374((struct Cfg *)bg);
    func_020409B4(func_02045730((struct Descriptor *)bg));
    func_02045808((struct U16Vec *)t3);
    func_02045808((struct U16Vec *)t2);
    func_02045808((struct U16Vec *)t1);
}
