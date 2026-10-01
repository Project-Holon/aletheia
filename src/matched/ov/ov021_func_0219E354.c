/*
 * function: func_0219E354
 * address:  0x0219E354
 * packet:   pkt_ov021_0219E354
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_021B810C  0x021B810C  thumb  ov021
 *   func_0219EA78  0x0219EA78  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern u32 *func_0216D69C(u32);
extern void func_021B810C(void *p);
extern int func_0219EA78(u32 *, u32);

void func_0219E354(u32 a)
{
    u32 *p = func_0216D69C(a);
    func_021B810C((void *)*p);
    func_0219EA78(p, a);
}
