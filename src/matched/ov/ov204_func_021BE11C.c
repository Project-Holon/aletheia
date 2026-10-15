/*
 * function: INTRO_GRAPHIC_CmdSetScenario
 * address:  0x021BE11C
 * packet:   pkt_021BE11C
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   INTRO_GRAPHIC_SetScenario  0x021BE10C  thumb  ov204
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10870.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int INTRO_GRAPHIC_SetScenario(char *p, u32 b, int *c);

u32 INTRO_GRAPHIC_CmdSetScenario(u8 *p)
{
    u32 t = *(u32 *)(((struct Obj10870 *)p)->f4 + 8);

    if (t == 0) {
        t = t + 1;
    }
    INTRO_GRAPHIC_SetScenario((char *)p, 0, (int *)(&t));
    return 1;
}

