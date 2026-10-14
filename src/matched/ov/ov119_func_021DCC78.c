/*
 * function: func_021DCC78
 * address: 0x021DCC78
 * packet: pkt_ov119_021DCC78
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DC854 0x021DC854 thumb ov119
 *   func_021DC894 0x021DC894 thumb ov119
 *   func_021DCBA4 0x021DCBA4 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021D59B0 0x021D59B0 thumb ov118
 */
#include "../include/Obj01728.h"
extern void *func_021DC854(void *, int);
extern int func_021DC894(int a, int b, char *q, char *p, int n);
extern void func_021DCBA4(char *a, char *p);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void func_021D59B0(unsigned char *);
int func_021DCC78(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0x96000);
    ((struct Obj01728 *)c)->f14 = ((struct Obj01728 *)c)->f30;
    r = func_021DC894((int)a, b, c, p, 7);
    func_021DCBA4(c, p);
    POKETRADE_PROC_SetStep(p, (int)func_021D59B0);
    return r;
}
