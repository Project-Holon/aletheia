/*
 * function: func_021B5BFC
 * address:  0x021B5BFC
 * packet:   pkt_ov021_021B5BFC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C2B0  0x0200C2B0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5E4(void *a0);
extern u32 func_02159B10(u32 a, u32 b);
extern void *func_02012934(void *p);
extern int func_0201AA18(u32 a);
extern u32 func_0201AB28(u32 a, int i);
extern u32 func_02017E1C(u32 a, int b, int c);
extern u32 func_02012F08(u32 a);
extern void func_0200C2B0(u32 a, u32 b, u16 *c);

int func_021B5BFC(u32 a, u32 b)
{
    u16 buf[6];
    void *sav;
    u32 r;
    void *bag;
    u32 mon;
    int i;
    int j;
    int n;

    sav = func_0215A5E4((void *)b);
    bag = func_02012934((void *)sav);
    r = func_02159B10(a, b);
    for (i = 0; i < 6; i++)
        buf[i] = 0;

    for (j = 0, n = 0; j < func_0201AA18(bag); j++) {
        mon = func_0201AB28(bag, j);
        if (func_02017E1C(mon, 0x4C, 0) == 0)
            buf[n++] = func_02017E1C(mon, 5, 0);
    }
    func_0200C2B0(func_02012F08(sav), r, buf);
    return 0;
}
