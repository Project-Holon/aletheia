/*
 * function: FLDMMDL_MOVE_AttrProcMoveStartFirst
 * address:  0x02163230
 * packet:   pkt_02163230
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
 *   FLDMMDL_MOVE_AttrEffectFootMark  0x021634D8  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectReflect  0x02163618  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectShadowStart  0x021636F0  thumb  ov010
 *   FLDMMDL_MOVE_AttrSetDrawOffset  0x02163418  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectLongGrassStart  0x021637E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_MOVE_UpdateMapAttr(int a);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern int FLDMMDL_CheckDrawInitComp(int a0);
extern int FLDMMDL_MOVE_InitAttrInfo();
extern int FLDMMDL_MOVE_AttrEffectFootMark();
extern int FLDMMDL_MOVE_AttrEffectReflect(int a0, int a1);
extern int FLDMMDL_MOVE_AttrEffectShadowStart();
extern int FLDMMDL_MOVE_AttrSetDrawOffset();
extern int FLDMMDL_MOVE_AttrEffectLongGrassStart();

void FLDMMDL_MOVE_AttrProcMoveStartFirst(int a0)
{
    int a1;
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = FLDMMDL_MOVE_UpdateMapAttr(a0);
loc_0216323A:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = FLDMMDL_CheckMoveBit((void *)a0, a1);
loc_02163244:
    if (a0 != 0) goto loc_02163284;
loc_02163248:
a0 = t5 + 0;
    a0 = FLDMMDL_CheckDrawInitComp(a0);
loc_0216324E:
    if (a0 != 1) goto loc_02163284;
loc_02163252:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_InitAttrInfo(a0, a1);
loc_0216325C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectFootMark(a0, a1);
loc_02163264:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectReflect(a0, a1);
loc_0216326C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectShadowStart(a0, a1);
loc_02163274:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrSetDrawOffset(a0, a1);
loc_0216327C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectLongGrassStart(a0, a1);
loc_02163284:
    return;
}
