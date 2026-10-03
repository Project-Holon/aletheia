/*
 * function: func_021FC810
 * address:  0x021FC810
 * packet:   pkt_021FC810
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201EE84  0x0201EE84  thumb
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
 * The two-parameter member of the 021F7538 family: an extra 0201EE84 call
 * keyed by the sixth argument, the same 0xb6c/0xb88 fields and the same
 * p+0xd40 window group in the other order.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct WordSet;
extern void func_0201EE84(struct WordSet *p, u32 i, void *mon);
extern u32 sub_02045EC0(u32 a, u32 b);
extern void func_0201F250(u32 a, u32 b, u32 c);
extern u32 sub_02045770(u32 a);
extern void sub_02043B5C(u32 a, u32 b);
extern void sub_02045334(u32 a);
extern void sub_02045374(u32 a);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern void func_0201F73C(u32 h, u32 a, u32 b, u32 c);
extern void sub_02045808(u32 a);
extern void func_02202858(u32 a, u32 b, u32 c, u32 d, u32 e, u8 *f);

void func_021FC810(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel)
{
    u32 v;
    u32 h;

    func_0201EE84(*(void **)(p + 0xb68), 0, (void *)sel);
    v = sub_02045EC0(*(u32 *)(p + 0xb6c), b);
    func_0201F250(*(u32 *)(p + 0xb68), *(u32 *)(p + 0xb88), v);
    sub_02043B5C(sub_02045770(*(u32 *)(p + 0xd40)), 0xf);
    func_0201F73C(*(u32 *)(p + 0xd40), 0, 1, 0xe);
    h = *(u32 *)(p + 0xd40);
    sub_02045334(h);
    sub_02045374(h);
    sub_020409B4(unit_02045730(h));
    func_02202858(*(u32 *)(p + 0xd40), 0, *(u32 *)(p + 0xb88), 0, 0, p + 0xfa0);
    sub_02045808(v);
}
