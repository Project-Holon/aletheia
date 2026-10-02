/*
 * function: func_021DF708
 * address:  0x021DF708
 * packet:   pkt_021D8B54
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8A24  0x021D8A24  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DD34C  0x021DD34C  thumb  ov119
 *   func_021DD4F4  0x021DD4F4  thumb  ov119
 *   func_021E62D4  0x021E62D4  thumb  ov119
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 */

extern int func_021D8A24(void *p);
extern void func_021D8E84(void *p, int v);
extern int func_021DD34C(void *p, int a, int b);
extern void func_021DD4F4(void *p, int a, int b);
extern void func_021E62D4(void *p, int a, int b);
extern unsigned int func_020399A8(void);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, void *d);

void func_021DF708(void *p)
{
    int v = func_021DD34C(p, *(int *)((char *)p + 0xf98),
                          *(int *)((char *)p + 0xf94));

    if (func_021D8A24(p) == 0 ||
        func_0203D3A8(func_020399A8(), 0xc0b, 4, &v) != 0) {
        *(int *)((char *)p + 0xf84) = -1;
        *(int *)((char *)p + 0xf88) = -1;
        *(int *)((char *)p + 0xf7c) = -1;
        *(int *)((char *)p + 0xf80) = -1;
        *(int *)((char *)p + 0xf94) = -1;
        *(int *)((char *)p + 0xf98) = -1;
        if (v != -1) {
            func_021DD4F4(p, 0, v);
            func_021E62D4(p, 0, v);
        }
        func_021D8E84(p, 0x021DF6ED);
    }
}
