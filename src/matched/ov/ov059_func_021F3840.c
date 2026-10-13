/*
 * function: SP_POKE_GIMMICK_ExitPairB
 * address:  0x021F3840
 * packet:   pkt_ov059_021F3840
 * region:   ov059
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

void SP_POKE_GIMMICK_ExitPairB(unsigned char *p)
{
    void *s;
    s = (void *)FIELDMAP_GetExpObj((int *)p);
    FIELDMAP_FreeCommonWork(p, 1);
    FLD_EXP_OBJ_RemoveUnit(s, 0);
}
