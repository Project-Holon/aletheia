/*
 * function: func_021F663C
 * address:  0x021F663C
 * packet:   pkt_021F663C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02045EC0   0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   sub_02045770   0x02045770  arm
 *   sub_02043B5C   0x02043B5C  arm
 *   sub_02045334   0x02045334  arm
 *   sub_02045374   0x02045374  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   sub_02045808   0x02045808  arm
 *   func_02202858  0x02202858  thumb  ov135
 *
 * Window teardown: the handle is the 0xd40 or 0xdd0 window selected by the
 * sixth argument, and that one handle is used by every call in the body.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *sub_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Descriptor;
extern void *sub_02045770(struct Descriptor *p);
extern void sub_02043B5C(struct CharBuf *buf, u8 value);
extern void sub_02045334(struct Descriptor *a);
extern void sub_02045374(struct Cfg *cfg);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void sub_02045808(struct U16Vec *vec);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);

void func_021F663C(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel)
{
    u32 v = (u32)sub_02045EC0((struct MsgBank *)(*(u32 *)(p + 0xb6c)), b);
    u32 h;

    func_0201F250((struct WordSet *)(*(u32 *)(p + 0xb68)), (void *)(*(u32 *)(p + 0xb88)), (void *)v);
    h = *(u32 *)(p + (sel == 0 ? 0xd40 : 0xdd0));
    sub_02043B5C((struct CharBuf *)((u32)sub_02045770((struct Descriptor *)h)), 0xf);
    sub_02045334((struct Descriptor *)h);
    sub_02045374((struct Cfg *)h);
    sub_020409B4(unit_02045730(h));
    func_0201F73C((void *)h, 0, 1, 0xe);
    func_02202858((void *)h, 0, (void *)(*(u32 *)(p + 0xb88)), 0, 0, p + 0xfa0);
    sub_02045808((struct U16Vec *)v);
}
