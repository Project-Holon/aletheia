/*
 * function: BTLV_CORE_StartTargetMenu
 * address:  0x021E98BC
 * packet:   pkt_ov093_021E98BC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTLV_CORE_SetStep  0x021E9728  thumb  ov093
 *   BTLV_CORE_StepTargetMenu  0x021E96C4  thumb  ov093
 */
#include "../include/Obj10105.h"
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct QU;
extern void BTLV_CORE_SetStep(struct QU *p, u32 v);
extern int BTLV_CORE_StepTargetMenu(char *p, int *st);

void BTLV_CORE_StartTargetMenu(char *p, u8 *a, int b)
{
    *(u8 * *)&((struct Obj10105 *)p)->fBC = a;
    ((struct Obj10105 *)p)->fC0 = BTL_POKEPARAM_GetPokeId(a);
    ((struct Obj10105 *)p)->fB8 = b;
    BTLV_CORE_SetStep((struct QU *)p, (u32)BTLV_CORE_StepTargetMenu);
}
