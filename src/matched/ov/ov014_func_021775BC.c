/*
 * function: func_021775BC
 * address:  0x021775BC
 * packet:   pkt_ov014_021775BC
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data   a4
 *   func_0217758C  0x0217758C  thumb  ov014
 *   func_02177560  0x02177560  thumb  ov014
 *   func_0217933C  0x0217933C  thumb  ov014
 *   func_021775AC  0x021775AC  thumb  ov014
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_021785B4  0x021785B4  thumb  ov014
 *   func_021773E0  0x021773E0  thumb  ov014
 */

#include "../include/G_W.h"

typedef unsigned char u8;

extern struct W *g_021797A4;
extern void func_0217758C(u8 *w);
extern void func_02177560(void);
extern void func_0217933C(void *cb);
extern int func_021775AC(int a, int b, int c);
extern int func_02178E4C(void);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_021785B4(u32 a, u16 *b, u32 c);
extern int func_021773E0(u8 *p);

int func_021775BC(int arg)
{
    u8 *w = ((u8 *)g_021797A4);

    if (w == 0)
        return 0;
    func_0217758C(w);
    if (arg != 0)
        func_02177560();
    func_0217933C(func_021775AC);
    w[0xCE8] = 1;
    if (func_02178E4C() == 1 && func_021785B4((u32)func_021773E0, 0, 0) != 0)
        return 1;
    return 0;
}
