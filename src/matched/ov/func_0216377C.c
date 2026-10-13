/*
 * function: FLDMMDL_MOVE_AttrEffectSplashOldPos
 * address:  0x0216377C
 * packet:   pkt_0216377C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAP_ATTR_IsRippleWater  0x021AB2F8  thumb
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 *   FLDEFF_RIPPLE_Start  0x021C484C  thumb
 */
#include "../include/Obj00110.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int MAP_ATTR_IsRippleWater();
extern int FLDMMDL_GetGridOldX(void *p);
extern int FLDMMDL_GetGridOldZ(void *p);
extern u32 FLDMMDL_GetPosY(void *p);
extern int FLDEFF_RIPPLE_Start();

int FLDMMDL_MOVE_AttrEffectSplashOldPos(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    int t7;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->f8;
    a0 = MAP_ATTR_IsRippleWater(a0);
loc_02163788:
    if (a0 != 1) goto loc_021637AE;
loc_0216378C:
a0 = t5 + 0;
    a0 = FLDMMDL_GetGridOldX((void *)a0);
loc_02163792:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = FLDMMDL_GetGridOldZ((void *)a0);
loc_0216379A:
t7 = a0 + 0;
a0 = t5 + 0;
    a0 = FLDMMDL_GetPosY((void *)a0);
loc_021637A2:
a3 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t6 + 0;
a2 = t7 + 0;
    a0 = FLDEFF_RIPPLE_Start(a0, a1, a2, a3);
loc_021637AE:
    return a0;}
