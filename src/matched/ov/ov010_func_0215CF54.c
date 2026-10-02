/*
 * function: func_0215CF54
 * address: 0x0215CF54
 * packet: pkt_ov010_0215CF54
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_02012934 0x02012934 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D50 0x02188D50 thumb ov021
 *   func_021C3204 0x021C3204 thumb ov021
 */
typedef unsigned short u16;
extern int func_02159B10(void *, void *);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A5E4(void *a0);
extern void *func_02012934(void *p);
extern void *func_0201210C(void *p);
extern unsigned int func_02188D50(unsigned char *);
extern void func_021C3204(unsigned int *, unsigned int, unsigned int);

int func_0215CF54(void *a, void *b)
{
    int v = func_02159B10(a, b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C3204((unsigned int *)func_02188D50(func_0201210C(func_0215A5DC(b))), (unsigned int)q, v);
    return 0;
}
