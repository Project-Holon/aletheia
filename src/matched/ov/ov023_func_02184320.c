/*
 * function: func_02184320
 * address:  0x02184320
 * packet:   pkt_ov023_02184320
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02185AB0  0x02185AB0  thumb  ov023
 *   func_02082AC0  0x02082AC0  arm
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_021841A0  0x021841A0  thumb  ov022
 */
#include "../include/Obj06117.h"

typedef unsigned int u32;

extern void func_02185AB0(char *p, int a, int b);
extern void func_02082AC0(int v, char *dst, u32 n);
extern int func_021841A4(unsigned char *p);
extern unsigned char func_021841A0(unsigned char *p);

void func_02184320(int a0, int a1, int a2, char *p)
{
    func_02185AB0(p, 3, 0);
    func_02082AC0(0, p + 0x4290, 0x3840);
    ((struct Obj06117 *)p)->f1AC = func_021841A4((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj06117 *)p)->f4));
    ((struct Obj06117 *)p)->f1B0 = func_021841A0((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj06117 *)p)->f4));
    ((struct Obj06117 *)p)->f9E6C = 1;
}
