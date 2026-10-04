/*
 * function: func_021B252C
 * address:  0x021B252C
 * packet:   pkt_ov021_021B252C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F4184  0x021F4184  thumb  ov039
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u16 *func_02159AE8(void *a0, void *a1);
extern u32 func_021F4184(void *, u16);
extern void func_0215897C(void *vm, void *task);

int func_021B252C(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u32 r = func_021F4184(d, *func_02159AE8((void *)a, (void *)b));

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, (void *)r);
    return 1;
}
