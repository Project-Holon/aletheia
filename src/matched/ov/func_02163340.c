/*
 * function: FLDMMDL_MOVE_AttrProcMoveEnd
 * address:  0x02163340
 * packet:   pkt_02163340
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
 *   FLDMMDL_MOVE_AttrSetDrawOffset  0x02163418  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectFootMarkIfNoFlag  0x0216352C  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectSplashNowPos  0x021637B0  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectReflectOrBridge  0x02163650  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectLongGrassEnd  0x02163868  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectShadowUpdate  0x0216372C  thumb  ov010
 *   FLDMMDL_MOVE_AttrEffectSpecial  0x021638AC  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_MOVE_UpdateMapAttr(int a);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern int FLDMMDL_CheckDrawInitComp(int a0);
extern int FLDMMDL_MOVE_InitAttrInfo();
extern int FLDMMDL_MOVE_AttrSetDrawOffset();
extern int FLDMMDL_MOVE_AttrEffectFootMarkIfNoFlag();
extern int FLDMMDL_MOVE_AttrEffectSplashNowPos();
extern int FLDMMDL_MOVE_AttrEffectReflectOrBridge(int a0, int a1);
extern int FLDMMDL_MOVE_AttrEffectLongGrassEnd();
extern int FLDMMDL_MOVE_AttrEffectShadowUpdate();
extern int FLDMMDL_MOVE_AttrEffectSpecial(int a0, int a1);

void FLDMMDL_MOVE_AttrProcMoveEnd(int a0)
{
    int a1;
    unsigned char fr[28];
    int t4;
    int t5;
t5 = a0 + 0;
    a0 = FLDMMDL_MOVE_UpdateMapAttr(a0);
loc_0216334A:
a1 = 2;
a0 = t5 + 0;
a1 = a1 << 0xa;
    a0 = FLDMMDL_CheckMoveBit((void *)a0, a1);
loc_02163354:
    if (a0 != 0) goto loc_021633A4;
loc_02163358:
a0 = t5 + 0;
    a0 = FLDMMDL_CheckDrawInitComp(a0);
loc_0216335E:
    if (a0 != 1) goto loc_021633A4;
loc_02163362:
t4 = (int)(fr + 0);
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_InitAttrInfo(a0, a1);
loc_0216336C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrSetDrawOffset(a0, a1);
loc_02163374:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectFootMarkIfNoFlag(a0, a1);
loc_0216337C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectSplashNowPos(a0, a1);
loc_02163384:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectReflectOrBridge(a0, a1);
loc_0216338C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectLongGrassEnd(a0, a1);
loc_02163394:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectShadowUpdate(a0, a1);
loc_0216339C:
a0 = t5 + 0;
a1 = t4 + 0;
    a0 = FLDMMDL_MOVE_AttrEffectSpecial(a0, a1);
loc_021633A4:
    return;
}
