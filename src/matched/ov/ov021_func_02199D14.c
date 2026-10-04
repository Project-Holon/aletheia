/*
 * function: func_02199D14
 * address:  0x02199D14
 * packet:   pkt_ov021_02199D14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_02163E7C  0x02163E7C  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; u32 c; u32 d; } S12;
extern S12 *func_0216D6BC(u32, u32);
extern void func_02163E7C(u32, u16);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u32);

int func_02199D14(u32 a)
{
    S12 *p = func_0216D6BC(a, 12);
    p->a = 12;
    p->b = 2;
    p->c = 2;
    p->d = 0x8000;
    func_02163E7C(a, p->c);
    func_0216D674((void *)a, p->a);
    func_0216D7CC(a);
    return 1;
}
