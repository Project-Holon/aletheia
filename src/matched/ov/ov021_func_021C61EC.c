/*
 * function: func_021C61EC
 * address:  0x021C61EC
 * packet:   pkt_ov021_021C61EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C622C  0x021C622C  thumb  ov021
 */

typedef unsigned char u8;

extern void *func_020122C0(void *a, int b, void *cb, int size);
extern u8 *func_020124E8(void *task);
extern int func_02188E30(void *p);
extern void func_02012374(void *a, void *t);
extern void func_021C622C(void);

void func_021C61EC(void *a, void *b, void *c)
{
    void *task;
    u8 *w;

    task = func_020122C0(b, 0, func_021C622C, 8);
    w = func_020124E8(task);
    w[0] = 3;
    w[1] = 0;
    w[2] = 2;
    w[3] = 0;
    *(int *)(w + 4) = func_02188E30(c);
    func_02012374(a, task);
}
