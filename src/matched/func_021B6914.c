/*
 * function: func_021B6914
 * address:  0x021B6914
 * packet:   pkt_021B6914
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B6984  0x021B6984  thumb  ov180
 *   func_02048AC4  0x02048AC4  arm
 *   func_02014BA8  0x02014BA8  thumb
 */

extern void func_021B6984(int *);
extern void func_02048AC4(int);
extern void func_02014BA8(int);

void func_021B6914(int *p)
{
    func_021B6984(p);
    func_02048AC4(*(int *)((char *)p + 0x20));
    func_02014BA8(*(int *)((char *)p + 0x18));
}
