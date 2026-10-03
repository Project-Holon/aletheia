/*
 * function: func_021B997C
 * address:  0x021B997C
 * packet:   pkt_ov088_021B997C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_02045088  0x02045088  arm
 *   func_02046440  0x02046440  arm
 *   func_0201DD60  0x0201DD60  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_020056A0  0x020056A0  thumb
 *   func_021B9954  0x021B9954  thumb  ov088
 *   func_0204363C  0x0204363C  arm
 *   func_0204361C  0x0204361C  arm
 */

extern void func_0203F8F4(int);
extern void func_02045088(int);
extern void func_02046440(int, int, int, int, int, int, int);
extern void func_0201DD60(void);
extern void *func_0203101C(int, int, int, int);
extern void *func_020056A0(void *, void *, int);
typedef unsigned int   u32;
extern void func_021B9954(void *task, short *p);
extern void func_0204363C(u32 swap);
extern void func_0204361C(void);

void func_021B997C(int *p, int heap)
{
    func_0203F8F4(heap);
    func_02045088(heap);
    func_02046440(0, 2, 0, 2, 0x1000, heap, 0);
    func_0201DD60();
    p[0] = (int)func_0203101C(heap, heap, 4, 0x20);
    p[1] = (int)func_020056A0((void *)func_021B9954, p, 5);
    func_0204363C(0);
    func_0204361C();
    ((unsigned short *)p)[4] = 12;
    ((unsigned short *)p)[5] = 4;
}
