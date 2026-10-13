/*
 * function: GIMMICK62_Exit
 * address:  0x021F3738
 * packet:   pkt_ov062_021F3738
 * region:   ov062
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FLD_EXP_OBJ_RemoveUnit  0x021BE418  thumb  ov021
 */

extern int FIELDMAP_GetExpObj(int *p);
extern void FLD_EXP_OBJ_RemoveUnit(unsigned char *p, unsigned short i);

void GIMMICK62_Exit(void *p)
{
    FLD_EXP_OBJ_RemoveUnit((unsigned char *)FIELDMAP_GetExpObj(p), 0);
}
