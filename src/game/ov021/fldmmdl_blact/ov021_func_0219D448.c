/*
 * function: func_0219D448
 * address:  0x0219D448
 * packet:   pkt_ov021_0219D448
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D4F8  0x0216D4F8  thumb  ov010
 *   func_0216D4F0  0x0216D4F0  thumb  ov010
 *   func_0216D524  0x0216D524  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_0219D4AC  0x0219D4AC  thumb  ov021
 *   d_021DDD80     0x021DDD80  data ov021 a4
 */
#include "../../../matched/include/Obj04226.h"

typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 func_0216D4F8(u8 *p);
extern u16 func_0216D4F0(void *p);
extern void func_0216D524(void *p, void *v);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void func_0219D4AC(int *obj, int a);
extern unsigned char d_021DDD80[];

void func_0219D448(int a, int b)
{
    int h;
    int *p;

    h = func_0216D4F8((u8 *)a);
    p = (int *)func_02030734(h, 0x10, 1, (const char *)d_021DDD80, 0x48);
    p[0] = a;
    p[1] = b;
    ((struct Obj04226 *)p)->f8 = func_0216D4F0((void *)a);
    func_0219D4AC(p, h);
    func_0216D524((void *)a, p);
}
