/*
 * function: func_021A5014
 * address:  0x021A5014
 * packet:   pkt_ov021_021A5014
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02197E7C  0x02197E7C  thumb  ov021
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_021A3964  0x021A3964  thumb  ov021
 */
#include "../include/Obj19797.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u16 func_0216D5F8(void *p);
int func_02197E7C(int k, int a);
void func_0216D410(int b, int v);
void func_021A3964(u8 *p, u32 v);

void func_021A5014(u32 *p, int b, u8 *c)
{
    int k = ((struct Obj19797 *)c)->f8;

    if (k == 9)
        k = func_0216D5F8((void *)b);
    func_0216D410(b, func_02197E7C(k, 0));
    p[0] = 0;
    func_021A3964((u8 *)p[3], 0);
}
