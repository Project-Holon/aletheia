/*
 * function: POKETRADE_PROC_StartRequest8
 * address: 0x021DCCB8
 * packet: pkt_ov119_021DCCB8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_AllocTradeWork 0x021DC854 thumb ov119
 *   POKETRADE_PROC_InitTradeWork 0x021DC894 thumb ov119
 *   POKETRADE_PROC_SetupMcssPokemon 0x021DCBA4 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_DEMO_MIDDLE_StepStartCompare 0x021D6F2C thumb ov118
 */
#include "../include/Obj01728.h"
extern void *POKETRADE_PROC_AllocTradeWork(void *, int);
extern int POKETRADE_PROC_InitTradeWork(int a, int b, char *q, char *p, int n);
extern void POKETRADE_PROC_SetupMcssPokemon(char *a, char *p);
extern void POKETRADE_PROC_SetStep(void *, int);
extern void POKETRADE_DEMO_MIDDLE_StepStartCompare(unsigned char *);
int POKETRADE_PROC_StartRequest8(void *a, int b, char *c)
{
    void *p;
    int r;
    p = POKETRADE_PROC_AllocTradeWork(a, 0x96000);
    ((struct Obj01728 *)c)->f14 = ((struct Obj01728 *)c)->f30;
    r = POKETRADE_PROC_InitTradeWork((int)a, b, c, p, 8);
    POKETRADE_PROC_SetupMcssPokemon(c, p);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_StepStartCompare);
    return r;
}
