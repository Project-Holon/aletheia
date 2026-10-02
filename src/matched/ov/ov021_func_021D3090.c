/*
 * function: func_021D3090
 * address:  0x021D3090
 * packet:   pkt_ov021_021D3090
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021F3AC0 resolves in ov064: the only Thumb function starting there
 * that takes one argument (ov043's takes two), and the neighbouring ov021
 * functions func_021D2F6C and func_021D3018 already call ov064 code.
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F3AC0  0x021F3AC0  thumb  ov064
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_021F3AC0(void *a);
extern void func_0215897C(void *, void *);

int func_021D3090(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *t = func_021F3AC0(func_0215A5DC((void *)b));

    if (t == 0) {
        return 1;
    }
    func_0215897C(x, t);
    return 1;
}
