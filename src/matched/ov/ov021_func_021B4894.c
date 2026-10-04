/*
 * function: func_021B4894
 * address:  0x021B4894
 * packet:   pkt_ov021_021B4894
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045808 0x02045808 arm
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CD10 0x0201CD10 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

typedef signed int     s32;
typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern signed char func_02012FFC(void);
extern struct Rec *func_0201CD10(u32 a0, s16 a1, s16 a2, u32 a3, u32 a4, s32 a5, u32 a6, u32 a7, u32 a8, u16 a9, u32 a10);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);

void func_021B4894(char *w, u32 b)
{
    u32 t;
    u32 win;

    t = (u32)func_02045EC0((struct MsgBank *)(*(u32 *)(w + 0x188)), b);
    func_0201F250((struct WordSet *)(*(u32 *)(w + 0x190)), (void *)(*(u32 *)(w + 0x198)), (void *)t);
    func_02045808((struct U16Vec *)t);
    *(u32 *)(w + 0x1B8) = (u32)func_0201CD10(*(u32 *)(w + 0x17C), 0, 0, *(u32 *)(w + 0x198),
                                        *(u32 *)(w + 8), func_02012FFC(), *(u32 *)(w + 0x1B4), 0,
                                        *(u16 *)(w + 4), 0xFFFF, 0);
    win = *(u32 *)(w + 0x17C);
    func_02045334((struct Descriptor *)win);
    func_02045374((struct Cfg *)win);
    func_020409B4(func_02045730((struct Descriptor *)win));
}
