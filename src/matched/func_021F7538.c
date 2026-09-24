/*
 * function: func_021F7538
 * address:  0x021F7538
 * packet:   pkt_021F7538
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
 * Handle walk: 02045EC0 over the 0xb6c field, the 0xb68/0xb88 pair through
 * 0201F250, then the p+0xd40 window through the 02045334/02045374/
 * 02045730/020409B4 group and a 02202858 redraw with the p+0xfa0 block.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 sub_02045EC0(u32 a);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern u32 sub_02045770(u32 a);
extern void sub_02043B5C(u32 a, u32 b);
extern void sub_02045334(u32 a);
extern void sub_02045374(u32 a);
extern void unit_02045730(u32 a);
extern void sub_020409B4(void);
extern void func_0201F73C(u32 h, u32 a, u32 b, u32 c);
extern void sub_02045808(u32 a);
extern void func_02202858(u32 a, u32 b, u32 c, u32 d, u32 e, u8 *f);

void func_021F7538(u8 *p)
{
    u32 v = sub_02045EC0(*(u32 *)(p + 0xb6c));
    u32 h;

    func_0201F250(*(u32 *)(p + 0xb68), *(u32 *)(p + 0xb88), v);
    sub_02043B5C(sub_02045770(*(u32 *)(p + 0xd40)), 0xf);
    h = *(u32 *)(p + 0xd40);
    sub_02045334(h);
    sub_02045374(h);
    unit_02045730(h);
    sub_020409B4();
    func_0201F73C(*(u32 *)(p + 0xd40), 0, 1, 0xe);
    func_02202858(*(u32 *)(p + 0xd40), 0, *(u32 *)(p + 0xb88), 0, 0, p + 0xfa0);
    sub_02045808(v);
}
