/*
 * function: func_021B4714
 * address:  0x021B4714
 * packet:   pkt_ov021_021B4714
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201EF6C  0x0201EF6C  thumb
 *   func_02020FE4  0x02020FE4  thumb
 *   func_0201F14C  0x0201F14C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CD10  0x0201CD10  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021B4710  0x021B4710  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
typedef signed short   s16;
typedef signed int     s32;
struct Cfg;
struct CharBuf;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern void func_0201F14C(struct WordSet *p, u32 i, u32 v);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern int func_021B4710();

void func_021B4714(u8 *p, u32 sel, u32 c, u32 d)
{
    u32 flag;
    u32 v;
    u32 h;

    if (sel == 9 && d != 0)
        flag = 1;
    else
        flag = 0;
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + 0x17c))), 0xf);
    func_0201F73C((void *)(*(u32 *)(p + 0x17c)), 0, 0xe4, 9);
    func_0201EF6C((struct WordSet *)(*(u32 *)(p + 0x190)), 0, c, flag, 0);
    func_0201F14C((struct WordSet *)(*(u32 *)(p + 0x190)), 1, func_02020FE4((void *)c, 5, *(u16 *)(p + 4)));
    v = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)(p + 0x188)), sel);
    func_0201F250((struct WordSet *)(*(u32 *)(p + 0x190)), (void *)(*(u32 *)(p + 0x198)), (void *)v);
    func_02045808((struct U16Vec *)v);
    *(u32 *)(p + 0x1b8) = (u32)func_0201CD10(*(u32 *)(p + 0x17c), 0, 0, *(u32 *)(p + 0x198),
                                        *(u32 *)(p + 8), func_02012FFC(),
                                        *(u32 *)(p + 0x1b4), 0, *(u16 *)(p + 4), 0xffff,
                                        (u32)func_021B4710);
    h = *(u32 *)(p + 0x17c);
    func_02045334((struct Descriptor *)h);
    func_02045374((struct Cfg *)h);
    func_020409B4(func_02045730((struct Descriptor *)h));
}
