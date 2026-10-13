/*
 * function: FLDMMDL_MOVE_AttrProcMoveStartSecond
 * address:  0x02163288
 * packet:   pkt_02163288
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVE_UpdateMapAttr  0x021640B0  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_CheckDrawInitComp  0x0216DB24  thumb  ov010
 *   FLDMMDL_MOVE_InitAttrInfo  0x021631C0  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectFootMarkIfFlag  0x021634FC  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectGround  0x02163580  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectReflectOrBridge  0x02163650  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectShadowStart  0x021636F0  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectSplashOldPos  0x0216377C  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectLongGrassStart  0x021637E4  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectNone  0x021638C8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_MOVE_UpdateMapAttr(int a);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern int FLDMMDL_CheckDrawInitComp(int a0);
extern int FLDMMDL_MOVE_InitAttrInfo();
extern int FLDMMDL_MOVE_AttrEffectFootMarkIfFlag();
extern int FLDMMDL_MOVE_AttrEffectGround();
extern int FLDMMDL_MOVE_AttrEffectReflectOrBridge(int a0, int a1);
extern int FLDMMDL_MOVE_AttrEffectShadowStart();
extern int FLDMMDL_MOVE_AttrEffectSplashOldPos();
extern int FLDMMDL_MOVE_AttrEffectLongGrassStart();
extern int FLDMMDL_MOVE_AttrEffectNone();

void FLDMMDL_MOVE_AttrProcMoveStartSecond(int a0)
{
    int a1;
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = FLDMMDL_MOVE_UpdateMapAttr(a0);
loc_02163292:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = FLDMMDL_CheckMoveBit((void *)a0, a1);
loc_0216329C:
    if (a0 != 0) goto loc_021632EC;
loc_021632A0:
a0 = t5 + 0;
    a0 = FLDMMDL_CheckDrawInitComp(a0);
loc_021632A6:
    if (a0 != 1) goto loc_021632EC;
loc_021632AA:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_InitAttrInfo(a0, a1);
loc_021632B4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectFootMarkIfFlag(a0, a1);
loc_021632BC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectGround(a0, a1);
loc_021632C4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectReflectOrBridge(a0, a1);
loc_021632CC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectShadowStart(a0, a1);
loc_021632D4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectSplashOldPos(a0, a1);
loc_021632DC:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectLongGrassStart(a0, a1);
loc_021632E4:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectNone(a0, a1);
loc_021632EC:
    return;
}
