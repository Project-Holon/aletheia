/*
 * function: func_021D1AB0
 * address:  0x021D1AB0
 * packet:   pkt_ov021_021D1AB0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_0215910C  0x0215910C  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_021D1A9C  0x021D1A9C  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern u32 func_0215910C(u32 a);
extern void *func_0215A5DC(void *a0);
extern void *func_020122C0(void *a, u32 b, void (*fn)(void *, void *), u32 size);
extern void *func_020124E8(void *task);
extern void func_0215897C(u32, void *);
extern void func_021D1A9C(void *task, void *work);

int func_021D1AB0(u32 a, u32 b)
{
    void *x = func_0215A5F4((void *)b);
    void *task = func_020122C0((void *)func_0215A5DC((void *)b), 0, func_021D1A9C, 4);
    u32 *w = func_020124E8(task);

    *w = func_0215910C(x);
    func_0215897C(x, task);
    return 1;
}
