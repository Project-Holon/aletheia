/*
 * function: func_0219B8E8
 * address:  0x0219B8E8
 * packet:   pkt_ov021_0219B8E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D69C  0x0216D69C  thumb  ov010
 *   func_0219B984  0x0219B984  thumb  ov021
 *   func_0216DAE0  0x0216DAE0  thumb  ov010
 *   d_021D5374  0x021D5374  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef int (*Step)(u32, u8 *);
extern void *func_0216D69C(void *p);
extern int func_0219B984(u32 a, u32 b);
extern void func_0216DAE0(unsigned int *p, unsigned int v);
extern Step d_021D5374[];

void func_0219B8E8(u32 a)
{
    u8 *p = func_0216D69C((void *)a);
    if (func_0219B984(a, (u32)p)) {
        func_0216DAE0((unsigned int *)a, 0);
        while (d_021D5374[p[0]](a, p) == 1) {
        }
    }
}
