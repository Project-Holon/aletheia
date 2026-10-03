/*
 * function: func_022054E8
 * address:  0x022054E8
 * packet:   pkt_ov195_022040E0
 * region:   ov195
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Leaf of the func_022040E0 dependency tree: either build the +0x6c render
 * node from the +0x74 id (and flush the +0x104/+0x108 stage), or arm the
 * +0x88 transition word with 2.
 *
 * symbols:
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */
extern int func_0201F73C(int, int, int, int);
extern int func_02045770(int);
extern void func_02043B5C(int, int);
extern void func_02045334(int);
extern void func_02045374(int);
extern unsigned char func_02045730(int);
typedef unsigned int   u32;
extern void func_020409B4(u32 index);

void func_022054E8(int a, int *p, int flag)
{
    if (flag != 0) {
        int *q;

        func_0201F73C(p[0x1b], 0, (unsigned short)p[0x1d], 2);
        func_02043B5C(func_02045770(p[0x1b]), 0xf);
        q = (int *)p[0x1b];
        func_02045334((int)q);
        func_02045374((int)q);
        func_020409B4(func_02045730((int)q));
    } else {
        p[0x22] = 2;
    }
}
