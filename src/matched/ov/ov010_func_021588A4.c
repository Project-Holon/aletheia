/*
 * function: func_021588A4
 * address: 0x021588A4
 * packet: pkt_ov010_021588A4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * lever: Callback-field assignment before argument-field assignment hoists
 *        the callback pool load before both stores, preserving argument first.
 * symbols:
 *   func_0215889C 0x0215889C thumb ov010
 */
typedef unsigned int u32;
extern void func_0215889C(void *, u32 *);
void func_021588A4(void *p, int a)
{
    void (*callback)(void *, u32 *) = func_0215889C;
    *(void (**)(void *, u32 *))((u32)p + 0x10) = callback;
    *(int *)((u32)p + 0x14) = a;
}
