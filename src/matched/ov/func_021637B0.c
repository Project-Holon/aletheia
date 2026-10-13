/*
 * function: FLDMMDL_MOVE_AttrEffectSplashNowPos
 * address:  0x021637B0
 * packet:   pkt_021637B0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MAP_ATTR_IsRippleWater  0x021AB2F8  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb  ov010
 *   FLDEFF_RIPPLE_Start  0x021C484C  thumb
 */
#include "../include/Obj00110.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int MAP_ATTR_IsRippleWater();
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern u32 FLDMMDL_GetPosY(void *p);
extern int FLDEFF_RIPPLE_Start();

int FLDMMDL_MOVE_AttrEffectSplashNowPos(int a0, int a1, int a2, int a3)
{
    int t4;
    int t5;
    int t6;
    int t7;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = MAP_ATTR_IsRippleWater(a0);
loc_021637BC:
    if (a0 != 1) goto loc_021637E2;
loc_021637C0:
a0 = t5 + 0;
    a0 = FLDMMDL_GetGridNowX((void *)a0);
loc_021637C6:
t6 = a0 + 0;
a0 = t5 + 0;
    a0 = FLDMMDL_GetGridNowZ((void *)a0);
loc_021637CE:
t7 = a0 + 0;
a0 = t5 + 0;
    a0 = FLDMMDL_GetPosY((void *)a0);
loc_021637D6:
a3 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t6 + 0;
a2 = t7 + 0;
    a0 = FLDEFF_RIPPLE_Start(a0, a1, a2, a3);
loc_021637E2:
    return a0;}
