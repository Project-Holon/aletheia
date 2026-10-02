/*
 * function: func_0215D06C
 * address: 0x0215D06C
 * packet: pkt_ov010_0215D06C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * interface: func_021C34F8 has two observed inputs. Its full ov021 body
 * and 0200BCA8/0200BC2C read r0/r1 only; legacy trailing r2/r3 are omitted.
 * status: EXACT
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0201210C 0x0201210C thumb
 *   func_02188D50 0x02188D50 thumb ov021
 *   func_021C34F8 0x021C34F8 thumb ov021
 *   func_02017E1C 0x02017E1C thumb
 */
typedef unsigned short u16;
extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02159B10(void *, void *);
extern void *func_0215A5DC(void *a0);
extern void *func_0201210C(void *p);
extern unsigned int func_02188D50(unsigned char *);
extern int func_021C34F8(unsigned int, unsigned int);
extern unsigned int func_02017E1C(void *, unsigned int, unsigned int);

int func_0215D06C(void *a, void *b)
{
    u16 *p = func_02159AE8(a, b);
    int v = func_02159B10(a, b);
    void *q = (void *)func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(b))), v);
    *p = func_02017E1C(q, 110, 0);

    return 0;
}
