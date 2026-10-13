/*
 * function: BTLV_CORE_StartActionMenu
 * address:  0x021E9760
 * packet:   pkt_ov093_021E9760
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTLV_CORE_SetStep  0x021E9728  thumb  ov093
 *   BTLV_CORE_StepActionMenu  0x021E964C  thumb  ov093
 */
#include "../include/Obj06279.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
struct QU;
extern void BTLV_CORE_SetStep(struct QU *p, u32 v);
extern int BTLV_CORE_StepActionMenu(char *p, int *st);

void BTLV_CORE_StartActionMenu(char *p, u8 *a, int b, int c)
{
    *(u8 * *)&((struct Obj06279 *)p)->fBC = a;
    ((struct Obj06279 *)p)->fC0 = BTL_POKEPARAM_GetPokeId(a);
    ((struct Obj06279 *)p)->fB8 = c;
    ((struct Obj06279 *)p)->fC4 = 0;
    ((struct Obj06279 *)p)->f175 = b;
    BTLV_CORE_SetStep((struct QU *)p, (u32)BTLV_CORE_StepActionMenu);
}
