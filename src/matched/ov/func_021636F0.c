/*
 * function: FLDMMDL_MOVE_AttrEffectShadowStart
 * address:  0x021636F0
 * packet:   pkt_021636F0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_MOVE_CanShowShadow  0x021636A8  thumb  ov010
 *   FLDMMDL_MOVE_IsShadowAttr  0x021636C8  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDEFF_SHADOW_Start  0x021AC2C0  thumb
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 */
#include "../include/Obj07203.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_MOVE_CanShowShadow(int a0, int a1);
extern int FLDMMDL_MOVE_IsShadowAttr();
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern int FLDEFF_SHADOW_Start();
extern int FLDMMDL_SetMoveBit();

void FLDMMDL_MOVE_AttrEffectShadowStart(int a0, int a1)
{
    int t4;
    int t5;
    int t6;

t5 = a0 + 0;
t4 = a1 + 0;
    a0 = FLDMMDL_MOVE_CanShowShadow(a0, a1);
loc_021636FA:
    if (a0 != 1) goto loc_02163728;
loc_021636FE:
a0 = t4 + 0;
    a0 = FLDMMDL_MOVE_IsShadowAttr(a0);
loc_02163704:
    if (a0 != 1) goto loc_02163728;
loc_02163708:
t6 = 1;
t6 = t6 << 0xe;
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = FLDMMDL_CheckMoveBit((void *)a0, a1);
loc_02163714:
    if (a0 != 0) goto loc_02163728;
loc_02163718:
a1 = ((struct Obj07203 *)t4)->f14;
a0 = t5 + 0;
    a0 = FLDEFF_SHADOW_Start(a0, a1);
loc_02163720:
a0 = t5 + 0;
a1 = t6 + 0;
    a0 = FLDMMDL_SetMoveBit(a0, a1);
loc_02163728:
    return;}
