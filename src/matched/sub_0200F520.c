/*
 * function: sub_0200F520
 * address:  0x0200F520
 * packet:   pkt_0200F38C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02008510   0x02008510  thumb
 *   sub_02008530   0x02008530  thumb
 *   sub_0200853C   0x0200853C  thumb
 *   sub_02008550   0x02008550  thumb
 *   sub_02008554   0x02008554  thumb
 *   sub_02009918   0x02009918  thumb
 *   sub_02009A00   0x02009A00  thumb
 *   func_02045808  0x02045808  arm
 */

extern void *sub_02008510(void *a, int b);
extern int   sub_02008530(void *a);
extern int   sub_0200853C(void *a);
extern int   sub_02008550(void *a);
extern int   sub_02008554(void *a);
extern void  sub_02009918(void *obj, int i, int field, int value);
extern void  sub_02009A00(void *obj, int i, void *dest);
extern void  func_02045808(void *p);

void sub_0200F520(void *obj, void *src, int i, int sel, int flag)
{
    if (flag != 0) {
        void *data = sub_02008510(src, sel);
        sub_02009A00(obj, i, data);
        func_02045808(data);
    }
    sub_02009918(obj, i, 9, sub_02008550(src));
    sub_02009918(obj, i, 0, sub_02008530(src));
    sub_02009918(obj, i, 1, sub_0200853C(src));
    sub_02009918(obj, i, 8, sub_02008554(src));
}
