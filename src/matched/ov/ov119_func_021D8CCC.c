/*
 * function: func_021D8CCC
 * address:  0x021D8CCC
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B454  0x0204B454  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_021E4AB8  0x021E4AB8  thumb  ov119
 *   func_021E64DC  0x021E64DC  thumb  ov119
 */

typedef signed short s16;

struct Actor;
struct PtS;
extern void func_0204B454(struct Actor *, struct PtS *, unsigned int);
extern unsigned int func_02035CB8(int *a, int *b);
extern void func_021E4AB8(void *p, int a, int b);
extern void func_021E64DC(void *p, int a, int b, int c, int d, int e);

void func_021D8CCC(void *p, int x, int y, int z, int a4)
{
    int o1, o2;

    *(int *)((char *)p + 0xf60) = x;
    func_0204B454((struct Actor *)x, (struct PtS *)((char *)p + 0xf64), 1);
    func_021E4AB8(p, *(int *)((char *)p + 0xf60), 1);
    if (func_02035CB8(&o1, &o2) == 0)
        return;
    *(s16 *)((char *)p + 0xf68) = (s16)*(short *)((char *)p + 0xf64) - o1;
    *(s16 *)((char *)p + 0xf6a) = (s16)*(short *)((char *)p + 0xf66) - o2;
    func_021E64DC(p, y, z,
                  o1 + (s16)*(short *)((char *)p + 0xf68),
                  o2 + (s16)*(short *)((char *)p + 0xf6a),
                  a4);
    *(int *)((char *)p + 0xf60) = *(int *)((char *)p + 0xf20);
}
