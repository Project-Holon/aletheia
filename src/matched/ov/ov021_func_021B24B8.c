/*
 * function: func_021B24B8
 * address:  0x021B24B8
 * packet:   pkt_ov021_021B24B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011330  0x02011330  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F3834  0x021F3834  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern u32 func_02011330(u32);
extern u32 func_021F3834(void *, u8, u32);
extern void func_0215897C(void *, u32);

int func_021B24B8(u32 a, u32 b)
{
    void *s = func_0215A5F4((void *)b);
    void *d = func_0215A5DC((void *)b);
    u8 k = func_02011330(a);
    u32 r = func_021F3834(d, k, 0);

    if (r == 0) {
        return 1;
    }
    func_0215897C(s, r);
    return 1;
}
