/*
 * function: FIELD_GIMMICK_CONNECT_MARKERS_Exit
 * address:  0x021F3754
 * packet:   pkt_ov061_021F3754
 * region:   ov061
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 *   FIELDMAP_FreeCommonWork  0x021897A0  thumb  ov021
 */

extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_RemoveUnit(unsigned char *p, unsigned short i);
extern void FIELDMAP_FreeCommonWork(unsigned char *p, int id);

void FIELD_GIMMICK_CONNECT_MARKERS_Exit(unsigned char *p)
{
    FLD_EXP_OBJ_RemoveUnit((unsigned char *)FIELDMAP_GetExpObj((int *)p), 0);
    FIELDMAP_FreeCommonWork(p, 0);
}
