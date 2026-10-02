/*
 * function: func_021B5B4C
 * address:  0x021B5B4C
 * packet:   pkt_ov021_021B5B4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A07C  0x0215A07C  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 *func_02159AE8(void *a0, void *a1);
extern int func_02159B10();
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A07C(int a, unsigned short *b, unsigned short *c);
extern int func_0215897C();

int func_021B5B4C(int a0, int a1)
{
    u16 *a = func_02159AE8((void *)a0, (void *)a1);
    u16 *b = func_02159AE8((void *)a0, (void *)a1);
    void *r4;

    func_02159B10(a0, a1);
    r4 = func_0215A5F4((void *)a1);
    func_0215897C(r4, func_0215A07C(func_0215A5DC((void *)a1), (int)a, (int)b));
    return 1;
}
