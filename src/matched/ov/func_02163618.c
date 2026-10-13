/*
 * function: FLDMMDL_MOVE_AttrEffectReflect
 * address:  0x02163618
 * packet:   pkt_02163618
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB304  0x021AB304  thumb
 *   FLDMMDL_CheckMoveBitSplash  0x0216DBE8  thumb  ov010
 *   FLDEFF_SPLASH_AddModel  0x021C4BE0  thumb
 *   FLDMMDL_SetMoveBitSplash  0x0216DBCC  thumb  ov010
 */
#include "../include/Obj00110.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021AB304();
extern int FLDMMDL_CheckMoveBitSplash(void *a0);
extern int FLDEFF_SPLASH_AddModel();
extern int FLDMMDL_SetMoveBitSplash();

int FLDMMDL_MOVE_AttrEffectReflect(int a0, int a1)
{
    int t4;
    int t5;

t4 = a1 + 0;
t5 = a0 + 0;
a0 = ((struct Obj00110 *)t4)->fA;
    a0 = func_021AB304(a0);
loc_02163624:
    if (a0 != 1) goto loc_02163644;
loc_02163628:
a0 = t5 + 0;
    a0 = FLDMMDL_CheckMoveBitSplash((void *)a0);
loc_0216362E:
    if (a0 != 0) goto loc_0216364C;
loc_02163632:
a0 = ((struct Obj00110 *)t4)->f14;
a1 = t5 + 0;
    a0 = FLDEFF_SPLASH_AddModel(a0, a1);
loc_0216363A:
a0 = t5 + 0;
a1 = 1;
    a0 = FLDMMDL_SetMoveBitSplash(a0, a1);
loc_02163642:
    return a0;
loc_02163644:
a0 = t5 + 0;
a1 = 0;
    a0 = FLDMMDL_SetMoveBitSplash(a0, a1);
loc_0216364C:
    return a0;}
