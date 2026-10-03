/*
 * function: func_0215D0D4
 * address: 0x0215D0D4
 * packet: pkt_ov010_0215D0D4
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0201210C 0x0201210C thumb
 *   func_02188D50 0x02188D50 thumb ov021
 *   func_021C34F8 0x021C34F8 thumb ov021
 *   func_021C3490 0x021C3490 thumb ov021
 */
typedef unsigned short u16;
extern u16 *func_02159AE8(void *a0, void *a1);
struct Ctx;
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188D50(unsigned char *);
extern void *func_021C34F8(void *,unsigned int);
extern int func_021C3490(void **,int);
int func_0215D0D4(void *a,void *b)
{
 u16 *p = func_02159AE8(a,b);
 int i = func_02159B10(a,b);
 void **q = func_02188D50(func_0201210C(func_0215A5DC(b)));
 func_021C34F8(q,i);
 *p = func_021C3490(q,i);
 return 0;
}
