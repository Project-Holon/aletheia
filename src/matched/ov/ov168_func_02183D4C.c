/*
 * function: func_02183D4C
 * address:  0x02183D4C
 * packet:   pkt_02183D4C
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02183D3C   0x02183D3C  thumb
 *   func_02183D34   0x02183D34  thumb
 *   func_02183DAC   0x02183DAC  thumb
 *   WIPE_SYS_Start   0x0202208C  thumb
 *   WIPE_SYS_EndCheck   0x020221A4  thumb
 *
 * Step a two-slot state machine: publish through WIPE_SYS_Start on state 0,
 *   poll WIPE_SYS_EndCheck on 1, install func_02183D34 on 2.
 */
#include "../include/Obj23817.h"


extern unsigned int func_02183D3C(unsigned int *p);
extern void func_02183D34(unsigned int *p, unsigned int v);
typedef unsigned int   u32;
extern void func_02183DAC(int a, int *state);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 WIPE_SYS_EndCheck(void);

void func_02183D4C(int a, int *state)
{
    int x = func_02183D3C((unsigned int *)a);
    switch (*state) {
    case 0:
        WIPE_SYS_Start(0, 1, 1, 0, 6, 1, ((struct Obj23817 *)x)->f14C);
        *state = 1;
        break;
    case 1:
        if (WIPE_SYS_EndCheck())
            *state = 2;
        break;
    case 2:
        func_02183D34((unsigned int *)a, (unsigned int)func_02183DAC);
        break;
    }
}
