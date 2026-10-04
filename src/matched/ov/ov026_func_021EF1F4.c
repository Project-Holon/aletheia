/*
 * function: func_021EF1F4
 * address: 0x021EF1F4
 * packet: pkt_ov026_021EF1F4
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A2630 0x021A2630 thumb ov021
 *   func_021A2638 0x021A2638 thumb ov021
 *   d_021EFDCC 0x021EFDCC data ov026 a4
 */
#include "../include/Obj20382.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021A2630(u8 *);
extern u32 func_021A2638(u8 *);
extern void (*d_021EFDCC[])(u8 *, int, u8 *, u32);
void func_021EF1F4(u8 *a)
{
    u8 *p;
    u32 q;
    p = func_021A2630(a);
    q = func_021A2638(a);
    d_021EFDCC[*(int *)p](a, ((struct Obj20382 *)p)->f4, p + 8, q);
}
