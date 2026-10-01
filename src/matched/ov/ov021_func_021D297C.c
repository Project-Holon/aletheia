/*
 * function: func_021D297C
 * address:  0x021D297C
 * packet:   pkt_ov021_021D297C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201210C  0x0201210C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_021D29A8  0x021D29A8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_020122C0(void *a, u32 b, void (*fn)(void *, void *), u32 size);
extern u32 *func_020124E8(void *task);
extern u32 func_0201210C(void *p);
extern u32 func_02188CCC(u32 a);
extern void func_021D29A8(void *task, void *work);

void *func_021D297C(void *a)
{
    void *task = func_020122C0(a, 0, func_021D29A8, 8);
    u32 *w = func_020124E8(task);

    w[0] = func_0201210C(a);
    w[1] = func_02188CCC(w[0]);
    return task;
}
