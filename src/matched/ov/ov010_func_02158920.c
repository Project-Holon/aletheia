/*
 * function: func_02158920
 * address:  0x02158920
 * packet:   pkt_ov010_02158920
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02158804  0x02158804  thumb
 *   func_02158E7C  0x02158E7C  thumb
 *   func_02158F94  0x02158F94  thumb
 *   func_021588D0  0x021588D0  thumb
 *   func_021589A0  0x021589A0  thumb
 *   func_021588DC  0x021588DC  thumb
 */

struct Desc;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, unsigned int size);
extern void *func_020124E8(struct Desc *p);
typedef unsigned int   u32;
extern void *func_02158804(u32 heap);
extern int *func_02158E7C(int, int, struct Desc *, int, int, int);
extern void func_02158F94(void *, int);
extern int func_021588D0(int);
extern int func_021589A0(int a, int b, int c);
extern int func_021588DC(int a0, int a1, int a2);

struct Desc *func_02158920(int a, int b, int c, int d, int e)
{
    struct Desc *h = func_020122C0((void *)a, 0, (void *)func_021588DC, 8);
    void **w = func_020124E8(h);
    w[1] = func_02158804(4);
    w[0] = func_02158E7C(4, a, h, c, e, 0);
    func_02158F94(w[0], d);
    func_021589A0((int)w[0], func_021588D0(a), c);
    return h;
}
