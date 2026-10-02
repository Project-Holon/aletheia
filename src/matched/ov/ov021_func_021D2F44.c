/*
 * function: func_021D2F44
 * address:  0x021D2F44
 * packet:   pkt_ov021_021D2F44
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_021F37B8 resolves in ov064 (2026-10-02, lane gA2). Starts exist at
 * 0x021F37B8 in ov041, ov050, ov060 and ov064. ov050 is void(void) and ov060
 * takes two arguments. ov041 is out on two counts: its body ends in a tail
 * call to func_021BE418, which is void (src/matched/ov/ov021_func_021BE418.c,
 * EXACT), so it returns no value for the `t == 0` test; and it hands its
 * argument straight to func_02188D2C and func_021897A0, the type that
 * func_0201210C returns, while this call passes func_0215A5DC(b), which the
 * sibling func_021D2F6C feeds to func_0201210C. ov064's function applies
 * func_0201210C to its argument and returns func_020122C0(arg, 0, cb, 0), a
 * task, which is what func_0215897C(x, t) receives here and in the same-shape
 * siblings func_021D3068 (ov064-only func_021F3ADC) and func_021D3090
 * (func_021F3AC0, ov064). func_021D2F6C and func_021D3018 also call ov064.
 *
 * symbols:
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021F37B8  0x021F37B8  thumb  ov064
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_021F37B8(u32 a);
extern void func_0215897C(u32, void *);

int func_021D2F44(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *t = func_021F37B8(func_0215A5DC((void *)b));

    if (t == 0) {
        return 1;
    }
    func_0215897C(x, t);
    return 1;
}
