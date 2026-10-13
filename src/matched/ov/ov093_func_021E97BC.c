/*
 * function: BTLV_CORE_StartMoveMenu
 * address:  0x021E97BC
 * packet:   pkt_ov093_021E97BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   func_021E97F8  0x021E97F8  thumb  ov093
 *   BTLV_CORE_SetStep  0x021E9728  thumb  ov093
 *   BTLV_CORE_StepMoveMenu  0x021E9884  thumb  ov093
 */
#include "../include/Obj06280.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void func_021E97F8(void *a, u8 *b, int c);
struct QU;
extern void BTLV_CORE_SetStep(struct QU *p, u32 v);
extern int BTLV_CORE_StepMoveMenu(void *p);

void BTLV_CORE_StartMoveMenu(char *p, u8 *a, int b)
{
    *(u8 * *)&((struct Obj06280 *)p)->fBC = a;
    ((struct Obj06280 *)p)->fC0 = BTL_POKEPARAM_GetPokeId(a);
    ((struct Obj06280 *)p)->fB8 = b;
    func_021E97F8(((struct Obj06280 *)p)->f180, *(u8 * *)&((struct Obj06280 *)p)->fBC, b);
    BTLV_CORE_SetStep((struct QU *)p, (u32)BTLV_CORE_StepMoveMenu);
}
