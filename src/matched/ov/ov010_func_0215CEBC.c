/*
 * function: func_0215CEBC
 * address: 0x0215CEBC
 * packet: pkt_ov010_0215CEBC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_02012934 0x02012934 thumb
 *   func_0201210C 0x0201210C thumb
 *   func_02188D50 0x02188D50 thumb ov021
 *   func_021C32F4 0x021C32F4 thumb ov021
 */
typedef unsigned short u16;
extern void * func_0215A5DC(void *);
extern void * func_0215A5E4(void *);
extern void * func_02012934(void *);
extern void * func_0201210C(void *);
extern unsigned int func_02188D50(unsigned char *);
extern void func_021C32F4(unsigned int *, unsigned int);

int func_0215CEBC(void *a, void *b)
{
    void *p = func_0215A5DC(b);
    void *q = func_02012934(func_0215A5E4(b));
    func_021C32F4((unsigned int *)func_02188D50(func_0201210C(p)), (unsigned int)q);
    return 0;
}
