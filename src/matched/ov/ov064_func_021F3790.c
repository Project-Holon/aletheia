/*
 * function: FIELD_GIMMICK_ARC_EFFECT_Exit
 * address:  0x021F3790
 * packet:   pkt_ov064_021F3790
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb  ov021
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 */

extern int FIELDMAP_GetExpObj(int *p);
extern void FIELDMAP_FreeCommonWork(unsigned char *p, int id);
extern void FLD_EXP_OBJ_RemoveUnit(unsigned char *p, unsigned short i);

void FIELD_GIMMICK_ARC_EFFECT_Exit(unsigned char *p)
{
    void *s;
    s = (void *)FIELDMAP_GetExpObj((int *)p);
    FIELDMAP_FreeCommonWork(p, 1);
    FLD_EXP_OBJ_RemoveUnit(s, 0);
}
